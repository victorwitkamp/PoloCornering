from __future__ import annotations

import argparse
import json
import sys
import time
from dataclasses import asdict
from datetime import datetime
from pathlib import Path
from typing import Literal

import serial

WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
if str(WORKSPACE_ROOT) not in sys.path:
    sys.path.insert(0, str(WORKSPACE_ROOT))

from CaristaReproduction.ByteUtils import clean_hex
from CaristaReproduction.CaristaClock import parse_iso_date
from CaristaReproduction.Constants import CARISTA_DATE_WRITE_DID, CARISTA_LONG_CODING_DID, CARISTA_WORKSHOP_CODE_WRITE_DID
from CaristaReproduction.Commands.BaseCommand import BaseCommand_describeNegativePayload
from CaristaReproduction.Commands.GetVagUdsEcuWorkshopCodeCommand import GetVagUdsEcuWorkshopCodeCommand_getRequest
from CaristaReproduction.Commands.WriteDataByIdentifierCommand import WriteDataByIdentifierCommand_positiveResponseMarker
from CaristaReproduction.Types import HexString
from CaristaReproduction.VagCanCommunicator import (
    CARISTA_CHANNEL_REOPEN_DELAY_MS,
    CARISTA_FINAL_FRAME_ST,
    CARISTA_NATIVE_T3_MS,
    CARISTA_NON_FINAL_FRAME_ST,
    CARISTA_TX_ACK_RETRIES,
    CARISTA_TX_ACK_RETRY_DELAY_SECONDS,
    VagCanCommunicator,
    ackForReceivedPacket,
    expectedTransmitAck,
    findTransmitAcks,
    nextSeqNum,
)
from CaristaReproduction.VagCoding import apply_cornering_fixes, changed_coding_bytes, normalize_coding, read_coding
from CaristaReproduction.VagOperationDelegate import (
    VagOperationDelegate_isMetadataPreWriteDid,
    VagOperationDelegate_shouldContinueAfterMetadataPreWrite,
    build_carista_uds_coding_write_plan,
    normalize_workshop_code_payload,
)
from vw_tp20_readonly_probe import (
    ApplicationStatus,
    CanFrame,
    ControlFrame,
    DEFAULT_BAUD,
    DEFAULT_PORT,
    DEFAULT_UNIT,
    Logger,
    classify_application_payload,
    close_channel,
    collect_passive_frames,
    configure_data_channel,
    extract_tp20_application_payload,
    get_channel_parameters,
    has_disconnect_frame,
    init_elm,
    is_tp20_application_payload_complete,
    open_tp20_channel,
    send,
)


WriteStatus = ApplicationStatus | Literal["disconnect"]
CARISTA_WORKSHOP_CODE_READ_COMMAND = GetVagUdsEcuWorkshopCodeCommand_getRequest()


def build_tp20_application_frames(counter: int, command: HexString) -> list[HexString]:
    return [packet.raw for packet in VagCanCommunicator.generateOutgoingPackets(counter, command)]


def next_counter_after_frames(counter: int, frames: list[HexString]) -> int:
    return nextSeqNum(counter, len(frames))


def describe_negative_payload(payload: HexString) -> str:
    return BaseCommand_describeNegativePayload(payload)


def write_positive_marker(command: HexString) -> HexString:
    return WriteDataByIdentifierCommand_positiveResponseMarker(command)


def classify_write_response(command: HexString, payload: HexString, frames: list[CanFrame], listen_header: str) -> ApplicationStatus:
    positive_marker = write_positive_marker(command)
    if payload.startswith(positive_marker):
        return "positive"
    if payload.startswith("7F") and len(payload) >= 6:
        # Some BCM writes first return UDS NRC 0x78 (response pending), then
        # send the positive response after our TP2.0 ACK. The generic TP2.0
        # extractor concatenates both application payloads, so recognize the
        # later positive marker instead of treating the initial 7F...78 as a
        # terminal failure.
        if payload[4:6] == "78" and positive_marker in payload[6:]:
            return "positive"
        return "negative"
    return classify_application_payload(command, payload, frames, listen_header)


def describe_outcome(label: str, status: WriteStatus, payload: HexString) -> str:
    if status == "negative":
        return f"{label}: {status} payload={describe_negative_payload(payload)}"
    if status == "disconnect":
        return f"{label}: disconnect payload={payload} (A8 disconnect)"
    return f"{label}: {status} payload={payload}"


def is_nonfatal_metadata_prewrite(request_did: int, status: WriteStatus, payload: HexString) -> bool:
    return status in {"negative", "disconnect"} and VagOperationDelegate_shouldContinueAfterMetadataPreWrite(request_did, payload)


def carista_inter_frame_pause_seconds(t3_ms: int | None, minimum_ms: int) -> float:
    return VagCanCommunicator.interFramePauseSeconds(t3_ms, minimum_ms)


def expected_transmit_ack(next_counter: int) -> ControlFrame:
    return expectedTransmitAck(next_counter)


def find_transmit_acks(frames: list[CanFrame], listen_header: str) -> list[ControlFrame]:
    return findTransmitAcks(frame.payload for frame in frames if frame.header == listen_header)


def ack_needed_carista_frames(frames: list[CanFrame], listen_header: str) -> list[ControlFrame]:
    acks: list[ControlFrame] = []
    for frame in frames:
        if frame.header != listen_header:
            continue
        ack = ackForReceivedPacket(frame.payload)
        if ack:
            acks.append(ack)
    return acks


def classify_request_result(command: HexString, payload: HexString, frames: list[CanFrame], listen_header: str) -> WriteStatus:
    if not payload and has_disconnect_frame(frames, listen_header):
        return "disconnect"
    return classify_write_response(command, payload, frames, listen_header)


def send_application_request(
    ser: serial.Serial,
    logger: Logger,
    command: HexString,
    *,
    counter: int,
    listen_header: str,
    timeout: float,
    final_listen_ms: int,
    final_frame_st: str = CARISTA_FINAL_FRAME_ST,
    final_frame_timeout: float = 2.5,
    final_frame_pause: float = 0.45,
    inter_frame_pause: float = CARISTA_NATIVE_T3_MS / 1000.0,
) -> tuple[WriteStatus, HexString, list[CanFrame], int]:
    frames_to_send = build_tp20_application_frames(counter, command)
    next_counter = next_counter_after_frames(counter, frames_to_send)
    logger.write(f"[{datetime.now().isoformat(timespec='milliseconds')}] TP2.0 command counter={counter:X} app={command}")
    logger.write("TP2.0 frame plan:")
    for frame in frames_to_send:
        logger.write(f"  {frame}")

    received_frames: list[CanFrame] = []
    acked_response_frames: dict[HexString, int] = {}

    def ack_response_frames(new_frames: list[CanFrame]) -> list[CanFrame]:
        ack_frames: list[CanFrame] = []
        pending_acks: list[HexString] = []
        for ack in ack_needed_carista_frames(new_frames, listen_header):
            ack_count = acked_response_frames.get(ack, 0)
            if ack_count >= 2:
                continue
            acked_response_frames[ack] = ack_count + 1
            pending_acks.append(ack)

        for ack in pending_acks:
            ack_count = acked_response_frames[ack]
            repeat_note = f" repeat {ack_count}" if ack_count > 1 else ""
            logger.write(f"[{datetime.now().isoformat(timespec='milliseconds')}] TP2.0 ACK ECU response frame{repeat_note}: {ack}")
            ack_result = send(ser, logger, ack, timeout=1.5, pause=0.25, reset_input=False)
            received_frames.extend(ack_result.frames)
            ack_frames.extend(ack_result.frames)
        return ack_frames

    for attempt in range(1, CARISTA_TX_ACK_RETRIES + 1):
        if len(frames_to_send) > 1:
            send(ser, logger, CARISTA_NON_FINAL_FRAME_ST, timeout=timeout, pause=0.05, reset_input=False)

        for index, frame in enumerate(frames_to_send):
            is_final_frame = index == len(frames_to_send) - 1
            if is_final_frame:
                send(ser, logger, final_frame_st, timeout=timeout, pause=0.05, reset_input=False)

            frame_timeout = final_frame_timeout if is_final_frame else 0.25
            frame_pause = final_frame_pause if is_final_frame else inter_frame_pause
            result = send(ser, logger, frame, timeout=frame_timeout, pause=frame_pause, reset_input=False)
            received_frames.extend(result.frames)
            if has_disconnect_frame(result.frames, listen_header) and not ack_needed_carista_frames(result.frames, listen_header):
                payload = extract_tp20_application_payload(received_frames, listen_header)
                status = classify_request_result(command, payload, received_frames, listen_header)
                return status, payload, received_frames, next_counter

        expected_ack = expected_transmit_ack(next_counter)
        transmit_acks = find_transmit_acks(received_frames, listen_header)
        if expected_ack in transmit_acks:
            logger.write(
                f"[{datetime.now().isoformat(timespec='milliseconds')}] "
                f"TP2.0 transmit ACK matched {expected_ack}"
            )
            break

        if transmit_acks:
            logger.write(
                f"[{datetime.now().isoformat(timespec='milliseconds')}] "
                f"TP2.0 transmit ACK {expected_ack} not seen after attempt {attempt}; "
                f"saw unexpected ACK(s) {', '.join(transmit_acks)}"
            )
        else:
            logger.write(
                f"[{datetime.now().isoformat(timespec='milliseconds')}] "
                f"TP2.0 transmit ACK {expected_ack} not seen after attempt {attempt}"
            )
        if attempt < CARISTA_TX_ACK_RETRIES:
            time.sleep(CARISTA_TX_ACK_RETRY_DELAY_SECONDS)

    new_frames = list(received_frames)
    for _ in range(8):
        ack_frames = ack_response_frames(new_frames)
        if has_disconnect_frame(received_frames, listen_header):
            payload = extract_tp20_application_payload(received_frames, listen_header)
            status = classify_request_result(command, payload, received_frames, listen_header)
            return status, payload, received_frames, next_counter
        if is_tp20_application_payload_complete(received_frames, listen_header):
            break
        if not ack_frames:
            break
        new_frames = ack_frames

    if not is_tp20_application_payload_complete(received_frames, listen_header):
        final_frames = collect_passive_frames(ser, logger, final_listen_ms, "post_command", listen_header)
        received_frames.extend(final_frames)

        new_frames = list(final_frames)
        for _ in range(8):
            if not new_frames:
                break
            ack_frames = ack_response_frames(new_frames)
            if has_disconnect_frame(received_frames, listen_header):
                payload = extract_tp20_application_payload(received_frames, listen_header)
                status = classify_request_result(command, payload, received_frames, listen_header)
                return status, payload, received_frames, next_counter
            if is_tp20_application_payload_complete(received_frames, listen_header):
                break
            if not ack_frames:
                break
            new_frames = ack_frames

    payload = extract_tp20_application_payload(received_frames, listen_header)
    status = classify_request_result(command, payload, received_frames, listen_header)
    return status, payload, received_frames, next_counter


def extract_payload_from_summary(path: Path, command: HexString, positive_prefix: HexString) -> HexString | None:
    if not path.exists():
        return None
    data = json.loads(path.read_text(encoding="utf-8"))
    rows = data if isinstance(data, list) else [data]
    for row in rows:
        if not isinstance(row, dict):
            continue
        if str(row.get("read_command", "")).upper() != command:
            continue
        read_result = str(row.get("read_result", "")).upper()
        if read_result.startswith(positive_prefix):
            return read_result[len(positive_prefix):]
    return None


def read_workshop_code(value: str | None, summary_file: Path | None) -> HexString | None:
    if value:
        cleaned = clean_hex(value, "workshop-code")
        if cleaned.startswith("62F1A5"):
            cleaned = cleaned[6:]
        return normalize_workshop_code_payload(cleaned)
    if summary_file:
        payload = extract_payload_from_summary(summary_file, "22F1A5", "62F1A5")
        if payload:
            return normalize_workshop_code_payload(payload)
    return None


def render_dry_run(args: argparse.Namespace, current: HexString, target: HexString, workshop_code: HexString) -> None:
    plan = build_carista_uds_coding_write_plan(
        current,
        target,
        workshop_code_payload=workshop_code,
        date_value=parse_iso_date(args.date_value),
    )
    print("Guarded Carista UDS DID 0600 coding writer dry run")
    print()
    print(f"Current coding: {plan.current_coding}")
    print(f"Target coding:  {plan.target_coding}")
    print()
    print("Changed bytes:")
    for index, (old, new) in plan.changed_bytes.items():
        print(f"  byte {index}: {old} -> {new}")
    print()
    print("Application sequence:")
    for request in plan.requests:
        print(f"  {request.label}: {request.request}")
        if request.did == CARISTA_DATE_WRITE_DID and not args.skip_inline_workshop_code_read:
            print(f"  Carista inline workshop-code read: {CARISTA_WORKSHOP_CODE_READ_COMMAND}")
    print()
    counter = args.write_counter if args.write_counter is not None else 0
    print(f"Write counter start: {counter:X}")
    for request in plan.requests:
        print(f"  {request.label}")
        frames = build_tp20_application_frames(counter, request.request)
        for frame in frames:
            print(f"    {frame}")
        counter = next_counter_after_frames(counter, frames)
        if request.did == CARISTA_DATE_WRITE_DID and not args.skip_inline_workshop_code_read:
            print("  Carista inline workshop-code read")
            frames = build_tp20_application_frames(counter, CARISTA_WORKSHOP_CODE_READ_COMMAND)
            for frame in frames:
                print(f"    {frame}")
            counter = next_counter_after_frames(counter, frames)
    print()
    print("Execution requires --execute, --confirm-target, and --i-understand-this-writes-bcm-coding.")


def execute(args: argparse.Namespace, expected_current: HexString, target: HexString, workshop_code: HexString | None) -> int:
    log_path = args.output_dir / f"{args.run_id}_write_carista_uds_coding.txt"
    plan_path = args.output_dir / f"{args.run_id}_write_carista_uds_coding_plan.json"
    logger = Logger(log_path)
    channel_opened = False
    send_header: str | None = None
    listen_header: str | None = None
    ser: serial.Serial | None = None

    try:
        with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
            logger.write("Guarded Carista UDS DID 0600 coding write attempt")
            logger.write(f"Started: {datetime.now().isoformat(timespec='milliseconds')}")
            logger.write(f"Port: {args.port}")
            logger.write(f"Baud: {args.baud}")
            logger.write(f"Unit TP2.0 address: {args.unit}")
            if args.skip_inline_workshop_code_read:
                logger.write("Sequence: 2EF199 date, 2EF198 workshop code, 2E0600 target coding")
            else:
                logger.write("Sequence: 2EF199 date, 22F1A5 workshop-code refresh, 2EF198 workshop code, 2E0600 target coding")

            logger.section("ELM initialization")
            init_elm(ser, logger, args.timeout)

            def forget_channel() -> None:
                nonlocal channel_opened, send_header, listen_header
                channel_opened = False
                send_header = None
                listen_header = None

            def settle_before_reopen() -> None:
                if args.channel_reopen_delay_ms > 0:
                    logger.write(f"Waiting {args.channel_reopen_delay_ms} ms before reopening TP2.0 channel.")
                    time.sleep(args.channel_reopen_delay_ms / 1000.0)

            def close_active_channel(reason: str, *, settle: bool = True) -> None:
                nonlocal channel_opened, send_header
                logger.section(reason)
                if channel_opened and send_header is not None:
                    close_channel(ser, logger, send_header, args.timeout)
                else:
                    logger.write("No active TP2.0 channel handle to close.")
                forget_channel()
                if settle:
                    settle_before_reopen()

            def establish_data_channel(purpose: str) -> tuple[str, str, float]:
                nonlocal channel_opened, send_header, listen_header
                attempts = max(1, args.channel_open_attempts)
                last_error = "unknown channel setup failure"

                for attempt in range(1, attempts + 1):
                    logger.section(f"Establish TP2.0 data channel for {purpose} (attempt {attempt}/{attempts})")
                    channel = open_tp20_channel(ser, logger, args.unit, args.timeout)
                    if channel is None:
                        last_error = f"could not open VW TP2.0 channel to unit address {args.unit}"
                        logger.write(last_error)
                        forget_channel()
                        if attempt < attempts:
                            settle_before_reopen()
                            continue
                        break

                    send_header, listen_header, _open_frames = channel
                    channel_opened = True
                    t3_ms: int | None = None
                    parameter_status = "skipped" if args.skip_channel_parameters else "unknown"

                    if not args.skip_channel_parameters:
                        _max_block, _t1, _t2, t3_ms, _t4, _frames, parameter_status = get_channel_parameters(
                            ser,
                            logger,
                            send_header,
                            listen_header,
                            args.timeout,
                            args.parameter_profile,
                        )
                        if parameter_status != "answered" and not args.allow_default_channel_parameters:
                            last_error = (
                                f"TP2.0 channel parameters did not answer cleanly "
                                f"(status={parameter_status}); refusing to write on a defaulted channel"
                            )
                            logger.write(last_error)
                            close_active_channel("Close suspect TP2.0 channel after parameter setup failure", settle=attempt < attempts)
                            if attempt < attempts:
                                continue
                            break

                    configure_data_channel(ser, logger, send_header, listen_header, args.timeout)
                    inter_frame_pause = carista_inter_frame_pause_seconds(t3_ms, args.minimum_inter_frame_delay_ms)
                    logger.write(
                        "TP2.0 outgoing inter-frame pause: "
                        f"{inter_frame_pause * 1000:.0f} ms "
                        f"(negotiated T3={t3_ms if t3_ms is not None else 'unknown'} ms, "
                        f"minimum={args.minimum_inter_frame_delay_ms} ms, "
                        f"parameter_status={parameter_status})"
                    )
                    return send_header, listen_header, inter_frame_pause

                raise RuntimeError(
                    f"TP2.0 channel setup failed after {attempts} attempt(s): {last_error}. "
                    "Reset the adapter/ignition before retrying a write."
                )

            def reopen_data_channel_after_disconnect() -> tuple[str, str, float, int]:
                logger.write("TP2.0 channel closed after a completed response; reopening before next command.")
                forget_channel()
                settle_before_reopen()
                next_send_header, next_listen_header, next_inter_frame_pause = establish_data_channel("ECU disconnect recovery")
                return next_send_header, next_listen_header, next_inter_frame_pause, 0

            send_header, listen_header, inter_frame_pause = establish_data_channel("fresh baseline read")

            counter = args.read_counter
            logger.section("Fresh baseline read")
            status, payload, _frames, counter = send_application_request(
                ser,
                logger,
                "220600",
                counter=counter,
                listen_header=listen_header,
                timeout=args.timeout,
                final_listen_ms=args.final_listen_ms,
                inter_frame_pause=inter_frame_pause,
            )
            logger.write(describe_outcome("baseline 220600", status, payload))
            if status != "positive" or not payload.startswith("620600"):
                raise RuntimeError("fresh baseline 220600 did not return positive long coding")
            live_current = normalize_coding(payload)
            if live_current != expected_current:
                raise RuntimeError(
                    "fresh coding does not match expected-current; "
                    f"live={live_current} expected={expected_current}"
                )

            if workshop_code is None:
                logger.section("Read workshop code")
                status, payload, _frames, counter = send_application_request(
                    ser,
                    logger,
                    "22F1A5",
                    counter=counter,
                    listen_header=listen_header,
                    timeout=args.timeout,
                    final_listen_ms=args.final_listen_ms,
                    inter_frame_pause=inter_frame_pause,
                )
                logger.write(describe_outcome("workshop 22F1A5", status, payload))
                if status != "positive" or not payload.startswith("62F1A5"):
                    raise RuntimeError("22F1A5 did not return the 6-byte workshop-code payload")
                workshop_code = normalize_workshop_code_payload(payload[6:])

            close_active_channel("Reset channel before Carista write sequence")
            counter = 0
            send_header, listen_header, inter_frame_pause = establish_data_channel("Carista write sequence")

            plan = build_carista_uds_coding_write_plan(
                live_current,
                target,
                workshop_code_payload=workshop_code,
                date_value=parse_iso_date(args.date_value),
            )
            if args.write_counter is not None:
                logger.write(f"Overriding write counter start to {args.write_counter:X}")
                counter = args.write_counter
            args.output_dir.mkdir(parents=True, exist_ok=True)
            plan_path.write_text(json.dumps(asdict(plan), indent=2, sort_keys=True) + "\n", encoding="utf-8")

            def send_write_request(request) -> None:
                nonlocal channel_opened, counter, send_header, listen_header, inter_frame_pause
                if listen_header is None:
                    raise RuntimeError("TP2.0 listen header is not available")
                active_listen_header = listen_header
                quick_metadata_response = VagOperationDelegate_isMetadataPreWriteDid(request.did)
                status, payload, _frames, counter = send_application_request(
                    ser,
                    logger,
                    request.request,
                    counter=counter,
                    listen_header=active_listen_header,
                    timeout=args.timeout,
                    final_listen_ms=args.final_listen_ms,
                    final_frame_st=args.metadata_final_st if quick_metadata_response else CARISTA_FINAL_FRAME_ST,
                    final_frame_timeout=args.metadata_final_timeout if quick_metadata_response else 2.5,
                    final_frame_pause=0.45,
                    inter_frame_pause=inter_frame_pause,
                )
                channel_closed = has_disconnect_frame(_frames, active_listen_header)
                if channel_closed:
                    channel_opened = False
                logger.write(describe_outcome(request.label, status, payload))
                if status != "positive":
                    if is_nonfatal_metadata_prewrite(request.did, status, payload):
                        logger.write(
                            f"{request.label}: continuing after nonfatal metadata pre-write result "
                            "because native writeVagUdsValue gates metadata pre-writes with isFatalFail"
                        )
                        if channel_closed:
                            send_header, listen_header, inter_frame_pause, counter = reopen_data_channel_after_disconnect()
                        return
                    raise RuntimeError(f"{request.label} did not complete positively")
                if channel_closed:
                    send_header, listen_header, inter_frame_pause, counter = reopen_data_channel_after_disconnect()

            def read_inline_workshop_code() -> HexString | None:
                nonlocal channel_opened, counter, send_header, listen_header, inter_frame_pause
                if listen_header is None:
                    raise RuntimeError("TP2.0 listen header is not available")
                active_listen_header = listen_header
                logger.section("Carista inline workshop-code read")
                status, payload, _frames, counter = send_application_request(
                    ser,
                    logger,
                    CARISTA_WORKSHOP_CODE_READ_COMMAND,
                    counter=counter,
                    listen_header=active_listen_header,
                    timeout=args.timeout,
                    final_listen_ms=args.final_listen_ms,
                    inter_frame_pause=inter_frame_pause,
                )
                channel_closed = has_disconnect_frame(_frames, active_listen_header)
                if channel_closed:
                    channel_opened = False
                logger.write(describe_outcome("inline 22F1A5 workshop-code read", status, payload))
                refreshed_workshop_code: HexString | None = None
                if status == "positive" and payload.startswith("62F1A5"):
                    refreshed_workshop_code = normalize_workshop_code_payload(payload[6:])
                    logger.write(f"Refreshed F198 workshop-code payload: {refreshed_workshop_code}")
                else:
                    logger.write("Inline workshop-code read did not refresh F198; continuing with cached/pre-read workshop-code payload.")
                if channel_closed:
                    send_header, listen_header, inter_frame_pause, counter = reopen_data_channel_after_disconnect()
                return refreshed_workshop_code

            logger.section("Write sequence")
            send_write_request(plan.requests[0])
            if not args.skip_inline_workshop_code_read:
                refreshed_workshop_code = read_inline_workshop_code()
                if refreshed_workshop_code:
                    workshop_code = refreshed_workshop_code
                    plan = build_carista_uds_coding_write_plan(
                        live_current,
                        target,
                        workshop_code_payload=workshop_code,
                        date_value=parse_iso_date(args.date_value),
                    )
                    plan_path.write_text(json.dumps(asdict(plan), indent=2, sort_keys=True) + "\n", encoding="utf-8")
            for request in plan.requests[1:]:
                send_write_request(request)

            logger.section("Verification read")
            status, payload, _frames, counter = send_application_request(
                ser,
                logger,
                "220600",
                counter=counter,
                listen_header=listen_header,
                timeout=args.timeout,
                final_listen_ms=args.final_listen_ms,
                inter_frame_pause=inter_frame_pause,
            )
            logger.write(describe_outcome("verify 220600", status, payload))
            if status != "positive" or normalize_coding(payload) != target:
                raise RuntimeError(f"verification did not match target; payload={payload}")

            close_channel(ser, logger, send_header, args.timeout)
            channel_opened = False
            logger.write(f"Plan JSON: {plan_path}")
            return 0
    except (RuntimeError, ValueError, serial.SerialException) as exc:
        logger.write(f"ERROR: {exc}")
        if channel_opened:
            logger.write("Channel may need an ignition cycle or adapter reconnect before retrying.")
        return 2
    finally:
        if channel_opened and send_header is not None:
            try:
                if ser is not None and ser.is_open:
                    close_channel(ser, logger, send_header, args.timeout)
                else:
                    with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as close_ser:
                        close_channel(close_ser, logger, send_header, args.timeout)
            except (OSError, serial.SerialException) as close_exc:
                logger.write(f"Close TP2.0 channel after failure failed: {close_exc}")
        logger.save()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Guarded Carista UDS DID 0600 coding writer. Defaults to dry-run."
    )
    parser.add_argument("--coding", help="Expected current long-coding hex or raw 620600 response.")
    parser.add_argument("--coding-file", help="File containing expected current long coding or direct-read JSON summary.")
    parser.add_argument("--target-coding", help="Explicit target long coding. Defaults to setting both known cornering bits.")
    parser.add_argument("--workshop-code", help="6-byte workshop-code payload, usually from 22F1A5 without 62F1A5.")
    parser.add_argument("--workshop-code-file", type=Path, help="JSON summary containing a positive 22F1A5 read.")
    parser.add_argument("--date", dest="date_value", help="Date for F199 as YYYY-MM-DD. Defaults to today.")
    parser.add_argument("--port", default=DEFAULT_PORT)
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD)
    parser.add_argument("--timeout", type=float, default=1.8)
    parser.add_argument("--unit", default=DEFAULT_UNIT)
    parser.add_argument(
        "--parameter-profile",
        choices=("minimal", "legacy", "carista", "carista_exact", "carista_then_minimal", "all"),
        default="carista_then_minimal",
    )
    parser.add_argument("--skip-channel-parameters", action="store_true")
    parser.add_argument(
        "--allow-default-channel-parameters",
        action="store_true",
        help="Allow the older fallback that continues after TP2.0 channel-parameter setup does not answer. Not recommended for writes.",
    )
    parser.add_argument(
        "--channel-open-attempts",
        type=int,
        default=2,
        help="Fresh TP2.0 channel-open attempts before a write is abandoned. Defaults to 2.",
    )
    parser.add_argument(
        "--channel-reopen-delay-ms",
        type=int,
        default=CARISTA_CHANNEL_REOPEN_DELAY_MS,
        help="Delay after TP2.0 close/disconnect before reopening the channel. Defaults to 1000 ms.",
    )
    parser.add_argument("--read-counter", type=lambda value: int(value, 0), default=0)
    parser.add_argument("--write-counter", type=lambda value: int(value, 0), default=None)
    parser.add_argument("--final-listen-ms", type=int, default=1200)
    parser.add_argument(
        "--allow-unsupported-metadata-prewrite",
        action="store_true",
        help="Deprecated: F199/F198 7F2E31 metadata pre-writes are now treated as nonfatal to match Carista's isFatalFail gate.",
    )
    parser.add_argument(
        "--minimum-inter-frame-delay-ms",
        type=int,
        default=CARISTA_NATIVE_T3_MS,
        help="Minimum pause between outgoing TP2.0 data frames. Defaults to Carista's native 0x82 timing value.",
    )
    parser.add_argument(
        "--metadata-final-st",
        default=CARISTA_FINAL_FRAME_ST,
        help="ELM timeout command used before the final F199/F198 metadata frame.",
    )
    parser.add_argument(
        "--metadata-final-timeout",
        type=float,
        default=2.5,
        help="Host read timeout for the final F199/F198 metadata frame.",
    )
    parser.add_argument(
        "--skip-inline-workshop-code-read",
        action="store_true",
        help="Skip the Carista-shaped 22F1A5 getEcuInfo/workshop-code read between F199 and F198.",
    )
    parser.add_argument("--confirm-target", help="Must exactly match the target coding when --execute is used.")
    parser.add_argument("--execute", action="store_true")
    parser.add_argument("--i-understand-this-writes-bcm-coding", action="store_true")
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--run-id", default=datetime.now().strftime("pq25_carista_uds_%Y%m%d_%H%M%S"))
    return parser


def main() -> int:
    args = build_parser().parse_args()
    if args.minimum_inter_frame_delay_ms < 0:
        raise ValueError("--minimum-inter-frame-delay-ms must be >= 0")
    if args.channel_open_attempts < 1:
        raise ValueError("--channel-open-attempts must be >= 1")
    if args.channel_reopen_delay_ms < 0:
        raise ValueError("--channel-reopen-delay-ms must be >= 0")
    current = read_coding(args.coding, args.coding_file)
    if current is None:
        raise ValueError("provide --coding or --coding-file")
    current = normalize_coding(current)
    target = normalize_coding(args.target_coding) if args.target_coding else apply_cornering_fixes(current, ("base-fog", "turn-signal"))
    if not changed_coding_bytes(current, target):
        raise ValueError("target coding is identical to current coding")

    workshop_code = read_workshop_code(args.workshop_code, args.workshop_code_file)
    if not args.execute:
        if workshop_code is None:
            raise ValueError("dry-run requires --workshop-code or --workshop-code-file")
        render_dry_run(args, current, target, workshop_code)
        return 0

    if not args.i_understand_this_writes_bcm_coding:
        raise ValueError("execution requires --i-understand-this-writes-bcm-coding")
    if normalize_coding(args.confirm_target or "") != target:
        raise ValueError("--confirm-target must exactly match the generated target coding")
    if len(target) // 2 != 30:
        raise ValueError(f"target DID {CARISTA_LONG_CODING_DID:04X} coding should be 30 bytes")
    return execute(args, current, target, workshop_code)


if __name__ == "__main__":
    raise SystemExit(main())
