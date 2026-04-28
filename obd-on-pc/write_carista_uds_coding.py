from __future__ import annotations

import argparse
import json
from dataclasses import asdict
from datetime import datetime
from pathlib import Path
from typing import Literal

import serial

from carista_vagcan_repro import (
    CARISTA_LONG_CODING_DID,
    HexString,
    apply_cornering_fixes,
    build_carista_uds_coding_write_plan,
    changed_coding_bytes,
    clean_hex,
    normalize_coding,
    normalize_workshop_code_payload,
    parse_iso_date,
    read_coding,
)
from vw_tp20_readonly_probe import (
    ApplicationStatus,
    CanFrame,
    DEFAULT_BAUD,
    DEFAULT_PORT,
    DEFAULT_UNIT,
    Logger,
    ack_needed_frames,
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
    response_marker,
    send,
)


WriteStatus = ApplicationStatus | Literal["disconnect"]

NEGATIVE_RESPONSE_CODES = {
    "11": "serviceNotSupported",
    "12": "subFunctionNotSupported",
    "13": "incorrectMessageLengthOrInvalidFormat",
    "22": "conditionsNotCorrect",
    "31": "requestOutOfRange",
    "33": "securityAccessDenied",
    "72": "generalProgrammingFailure",
}


def build_tp20_application_frames(counter: int, command: HexString) -> list[HexString]:
    payload = bytes.fromhex(clean_hex(command, "application command"))
    if not payload:
        raise ValueError("empty application payload")
    if len(payload) <= 5:
        return [f"1{counter:X}{len(payload):04X}{payload.hex().upper()}"]

    frames = [f"2{counter:X}{len(payload):04X}{payload[:5].hex().upper()}"]
    sequence = (counter + 1) & 0xF
    chunks = [payload[offset:offset + 7] for offset in range(5, len(payload), 7)]
    for index, chunk in enumerate(chunks):
        opcode = "1" if index == len(chunks) - 1 else "2"
        frames.append(f"{opcode}{sequence:X}{chunk.hex().upper()}")
        sequence = (sequence + 1) & 0xF
    return frames


def describe_negative_payload(payload: HexString) -> str:
    if not payload.startswith("7F") or len(payload) < 6:
        return payload
    service = payload[2:4]
    code = payload[4:6]
    code_text = NEGATIVE_RESPONSE_CODES.get(code, "unknownNegativeResponse")
    return f"{payload} service=0x{service} nrc=0x{code} ({code_text})"


def classify_write_response(command: HexString, payload: HexString, frames: list[CanFrame], listen_header: str) -> ApplicationStatus:
    if payload.startswith("7F"):
        return "negative"
    if payload.startswith(response_marker(command)):
        return "positive"
    return classify_application_payload(command, payload, frames, listen_header)


def describe_outcome(label: str, status: WriteStatus, payload: HexString) -> str:
    if status == "negative":
        return f"{label}: {status} payload={describe_negative_payload(payload)}"
    if status == "disconnect":
        return f"{label}: disconnect payload={payload} (A8 disconnect)"
    return f"{label}: {status} payload={payload}"


def send_application_request(
    ser: serial.Serial,
    logger: Logger,
    command: HexString,
    *,
    counter: int,
    listen_header: str,
    timeout: float,
    final_listen_ms: int,
) -> tuple[WriteStatus, HexString, list[CanFrame], int]:
    frames_to_send = build_tp20_application_frames(counter, command)
    logger.write(f"[{datetime.now().isoformat(timespec='milliseconds')}] TP2.0 command counter={counter:X} app={command}")
    logger.write("TP2.0 frame plan:")
    for frame in frames_to_send:
        logger.write(f"  {frame}")

    received_frames: list[CanFrame] = []
    if len(frames_to_send) > 1:
        send(ser, logger, "ATST01", timeout=timeout, pause=0.05, reset_input=False)

    for index, frame in enumerate(frames_to_send):
        is_final_frame = index == len(frames_to_send) - 1
        if is_final_frame:
            send(ser, logger, "ATST32", timeout=timeout, pause=0.05, reset_input=False)

        frame_timeout = 2.5 if is_final_frame else 0.25
        frame_pause = 0.45 if is_final_frame else 0.03
        result = send(ser, logger, frame, timeout=frame_timeout, pause=frame_pause, reset_input=False)
        received_frames.extend(result.frames)
        if has_disconnect_frame(result.frames, listen_header):
            payload = extract_tp20_application_payload(received_frames, listen_header)
            return "disconnect", payload, received_frames, (counter + 1) & 0xF

    new_frames = list(received_frames)
    for _ in range(8):
        if is_tp20_application_payload_complete(received_frames, listen_header):
            break
        pending_acks = ack_needed_frames(new_frames, listen_header)
        if not pending_acks:
            break
        new_frames = []
        for ack in pending_acks:
            ack_result = send(ser, logger, ack, timeout=1.5, pause=0.25, reset_input=False)
            received_frames.extend(ack_result.frames)
            new_frames.extend(ack_result.frames)

    final_frames = collect_passive_frames(ser, logger, final_listen_ms, "post_command", listen_header)
    received_frames.extend(final_frames)
    payload = extract_tp20_application_payload(received_frames, listen_header)
    status = classify_write_response(command, payload, received_frames, listen_header)
    return status, payload, received_frames, (counter + 1) & 0xF


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
    print("Application requests:")
    for request in plan.requests:
        print(f"  {request.label}: {request.request}")
    print()
    counter = args.write_counter if args.write_counter is not None else 0
    print(f"Write counter start: {counter:X}")
    for request in plan.requests:
        print(f"  {request.label}")
        for frame in build_tp20_application_frames(counter, request.request):
            print(f"    {frame}")
        counter = (counter + 1) & 0xF
    print()
    print("Execution requires --execute, --confirm-target, and --i-understand-this-writes-bcm-coding.")


def execute(args: argparse.Namespace, expected_current: HexString, target: HexString, workshop_code: HexString | None) -> int:
    log_path = args.output_dir / f"{args.run_id}_write_carista_uds_coding.txt"
    plan_path = args.output_dir / f"{args.run_id}_write_carista_uds_coding_plan.json"
    logger = Logger(log_path)
    channel_opened = False

    try:
        with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
            logger.write("Guarded Carista UDS DID 0600 coding write attempt")
            logger.write(f"Started: {datetime.now().isoformat(timespec='milliseconds')}")
            logger.write(f"Port: {args.port}")
            logger.write(f"Baud: {args.baud}")
            logger.write(f"Unit TP2.0 address: {args.unit}")
            logger.write("Sequence: 2EF199 date, 2EF198 workshop code, 2E0600 target coding")

            logger.section("ELM initialization")
            init_elm(ser, logger, args.timeout)

            channel = open_tp20_channel(ser, logger, args.unit, args.timeout)
            if channel is None:
                raise RuntimeError(f"Could not open VW TP2.0 channel to unit address {args.unit}")
            send_header, listen_header, _open_frames = channel
            channel_opened = True

            if not args.skip_channel_parameters:
                get_channel_parameters(ser, logger, send_header, listen_header, args.timeout, args.parameter_profile)
            configure_data_channel(ser, logger, send_header, listen_header, args.timeout)

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
                )
                logger.write(describe_outcome("workshop 22F1A5", status, payload))
                if status != "positive" or not payload.startswith("62F1A5"):
                    raise RuntimeError("22F1A5 did not return the 6-byte workshop-code payload")
                workshop_code = normalize_workshop_code_payload(payload[6:])

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

            logger.section("Write sequence")
            for request in plan.requests:
                status, payload, _frames, counter = send_application_request(
                    ser,
                    logger,
                    request.request,
                    counter=counter,
                    listen_header=listen_header,
                    timeout=args.timeout,
                    final_listen_ms=args.final_listen_ms,
                )
                logger.write(describe_outcome(request.label, status, payload))
                if status != "positive":
                    raise RuntimeError(f"{request.label} did not complete positively")

            logger.section("Verification read")
            status, payload, _frames, counter = send_application_request(
                ser,
                logger,
                "220600",
                counter=counter,
                listen_header=listen_header,
                timeout=args.timeout,
                final_listen_ms=args.final_listen_ms,
            )
            logger.write(describe_outcome("verify 220600", status, payload))
            if status != "positive" or normalize_coding(payload) != target:
                raise RuntimeError(f"verification did not match target; payload={payload}")

            close_channel(ser, logger, send_header, args.timeout)
            logger.write(f"Plan JSON: {plan_path}")
            return 0
    except (RuntimeError, ValueError, serial.SerialException) as exc:
        logger.write(f"ERROR: {exc}")
        if channel_opened:
            logger.write("Channel may need an ignition cycle or adapter reconnect before retrying.")
        return 2
    finally:
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
    parser.add_argument("--parameter-profile", choices=("minimal", "legacy", "carista", "all"), default="minimal")
    parser.add_argument("--skip-channel-parameters", action="store_true")
    parser.add_argument("--read-counter", type=lambda value: int(value, 0), default=0)
    parser.add_argument("--write-counter", type=lambda value: int(value, 0), default=None)
    parser.add_argument("--final-listen-ms", type=int, default=1200)
    parser.add_argument("--confirm-target", help="Must exactly match the target coding when --execute is used.")
    parser.add_argument("--execute", action="store_true")
    parser.add_argument("--i-understand-this-writes-bcm-coding", action="store_true")
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--run-id", default=datetime.now().strftime("pq25_carista_uds_%Y%m%d_%H%M%S"))
    return parser


def main() -> int:
    args = build_parser().parse_args()
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
