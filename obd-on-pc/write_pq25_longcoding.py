from __future__ import annotations

import argparse
from datetime import datetime
from pathlib import Path
from typing import Literal

import serial

from prepare_pq25_coding_change import normalize_hex
from vw_tp20_readonly_probe import (
    ApplicationStatus,
    CanFrame,
    DEFAULT_BAUD,
    DEFAULT_PORT,
    DEFAULT_UNIT,
    HexString,
    Logger,
    classify_application_payload,
    close_channel,
    collect_passive_frames,
    configure_data_channel,
    extract_tp20_application_payload,
    get_channel_parameters,
    has_disconnect_frame,
    init_elm,
    open_tp20_channel,
    parse_counters,
    parse_pre_read_sequence,
    send,
    send_pre_read_sequence,
    send_tp20_application_request,
)


WRITE_METHODS = {
    "carista-3b9a": {
        "command_prefix": "3B9A",
        "positive_prefix": "7B9A",
        "label": "obsolete simple 3B9A + full coding hypothesis; latest Carista analysis suggests this is not the real builder",
    },
    "did-0600": {
        "command_prefix": "2E0600",
        "positive_prefix": "6E0600",
        "label": "Direct counterpart to live 220600 read, 2E0600 + coding",
    },
}
EXPECTED_LENGTH = 30
NEGATIVE_RESPONSE_CODES = {
    "11": "serviceNotSupported",
    "12": "subFunctionNotSupported",
    "22": "conditionsNotCorrect",
    "31": "requestOutOfRange",
    "33": "securityAccessDenied",
}

CARISTA_EVIDENCE = (
    "Carista opens PQ25 unit 09 as VAGCAN20/TP2.0 unit 20, matching the live BCM channel.",
    "Carista's ReadVagCanLongCodingCommand read request is 1A9A and returns 5A9A... in simulator data.",
    "Carista also exports getCodingRawAddress plus supportsSingleCoding/supportsMultiCoding, so the real write path is ECU-specific.",
    "WriteVagCodingCommand::getRequest starts with 3B9A, but it does not build simple 3B9A + complete long coding.",
    "The native builder appends setting value, coding raw address, coding-type byte, length/data, and sometimes FF.",
    "The live simple 3B9A + full-coding attempt produced no response and should not be repeated as the main path.",
    "The live 2E0600 + full-coding attempt was parsed by the BCM but rejected with 7F2E22 (conditions not correct).",
    "The live 1089 -> 2E0600 attempt caused an immediate A8 disconnect on the first write frame and should not be the default retry path.",
)


WriteStatus = ApplicationStatus | Literal["disconnect"]


def read_hex(value: str | None, file_path: str | None, label: str) -> HexString:
    if file_path:
        return normalize_hex(Path(file_path).read_text(encoding="utf-8"))
    if value:
        return normalize_hex(value)
    raise ValueError(f"provide --{label} or --{label}-file")


def changed_byte_indexes(current_hex: HexString, target_hex: HexString) -> list[int]:
    current = bytes.fromhex(current_hex)
    target = bytes.fromhex(target_hex)
    return [index for index, (old, new) in enumerate(zip(current, target)) if old != new]


def build_write_command(target_hex: HexString, method: str) -> HexString:
    return f"{WRITE_METHODS[method]['command_prefix']}{target_hex}"


def build_tp20_application_frames(counter: int, command: HexString) -> list[HexString]:
    payload = bytes.fromhex(command)
    if not payload:
        raise ValueError("empty application payload")
    if len(payload) <= 5:
        return [f"1{counter:X}{len(payload):04X}{payload.hex().upper()}"]

    # TP2.0 long payloads observed live on this BCM use 2n frames while more
    # data follows and a 1n frame for the final chunk.
    frames = [f"2{counter:X}{len(payload):04X}{payload[:5].hex().upper()}"]
    sequence = (counter + 1) & 0xF
    chunks = [payload[offset:offset + 7] for offset in range(5, len(payload), 7)]
    for index, chunk in enumerate(chunks):
        opcode = "1" if index == len(chunks) - 1 else "2"
        frames.append(f"{opcode}{sequence:X}{chunk.hex().upper()}")
        sequence = (sequence + 1) & 0xF
    return frames


def classify_write_response(method: str, payload: HexString, frames: list[CanFrame], listen_header: str) -> ApplicationStatus:
    if payload.startswith("7F"):
        return "negative"
    if payload.startswith(WRITE_METHODS[method]["positive_prefix"]):
        return "positive"
    return classify_application_payload(WRITE_METHODS[method]["command_prefix"], payload, frames, listen_header)


def describe_negative_payload(payload: HexString) -> str:
    if not payload.startswith("7F") or len(payload) < 6:
        return payload
    service = payload[2:4]
    code = payload[4:6]
    code_text = NEGATIVE_RESPONSE_CODES.get(code, "unknownNegativeResponse")
    return f"{payload} service=0x{service} nrc=0x{code} ({code_text})"


def describe_write_outcome(status: WriteStatus, payload: HexString) -> str:
    if status == "negative":
        return f"Write status: {status} payload={describe_negative_payload(payload)}"
    if status == "disconnect":
        return (
            "Write status: disconnect payload="
            f"{payload} (A8 disconnect after session/write transition; the current 1089 path is not viable)"
        )
    return f"Write status: {status} payload={payload}"


def send_write_request(
    ser: serial.Serial,
    logger: Logger,
    command: HexString,
    method: str,
    counter: int,
    listen_header: str,
    timeout: float,
    final_listen_ms: int,
) -> tuple[WriteStatus, HexString, list[CanFrame]]:
    frames_to_send = build_tp20_application_frames(counter, command)
    logger.write("TP2.0 write frame plan:")
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
            return "disconnect", payload, received_frames

    final_frames = collect_passive_frames(ser, logger, final_listen_ms, "post_write", listen_header)
    received_frames.extend(final_frames)
    payload = extract_tp20_application_payload(received_frames, listen_header)
    return classify_write_response(method, payload, received_frames, listen_header), payload, received_frames


def validate_inputs(args: argparse.Namespace, expected_current: HexString, target: HexString) -> None:
    if len(expected_current) != len(target):
        raise ValueError(f"expected-current length {len(expected_current) // 2} does not match target length {len(target) // 2}")
    if len(target) // 2 != EXPECTED_LENGTH and not args.allow_non_30_byte_coding:
        raise ValueError(f"target is {len(target) // 2} bytes; expected {EXPECTED_LENGTH}. Use --allow-non-30-byte-coding to override.")
    if expected_current == target:
        raise ValueError("target coding is identical to expected-current; refusing no-op write")

    changed = changed_byte_indexes(expected_current, target)
    if len(changed) > 4 and not args.allow_many_byte_changes:
        changed_text = ", ".join(f"{index:02d}" for index in changed)
        raise ValueError(f"target changes {len(changed)} bytes ({changed_text}); use --allow-many-byte-changes to override")

    if args.execute:
        if not args.i_understand_this_writes_bcm_coding:
            raise ValueError("execution requires --i-understand-this-writes-bcm-coding")
        if (
            args.write_method == "did-0600"
            and not args.skip_session
            and args.session.upper() == "1089"
            and not args.allow_known_bad_session_1089
        ):
            raise ValueError(
                "live logs show session 1089 causes an immediate A8 disconnect before the first did-0600 write frame. "
                "Use --skip-session for the parsed-but-rejected 7F2E22 path, or add --allow-known-bad-session-1089 only for deliberate retesting."
            )
        if args.write_method == "carista-3b9a" and not args.allow_obsolete_3b9a_full:
            raise ValueError(
                "carista-3b9a is the obsolete simple full-coding hypothesis. "
                "The latest native analysis indicates Carista uses a structured setting write. "
                "Use --allow-obsolete-3b9a-full only for deliberate retesting."
            )
        confirmed = normalize_hex(args.confirm_target or "")
        if confirmed != target:
            raise ValueError("--confirm-target must exactly match --target/--target-file for execution")


def dry_run(args: argparse.Namespace, expected_current: HexString, target: HexString) -> None:
    command = build_write_command(target, args.write_method)
    counter = args.write_counter if args.write_counter is not None else (0 if args.skip_session else 1)
    print("PQ25 BCM long-coding writer dry run")
    print()
    print("Safety:")
    print("  Nothing was sent to the car.")
    print("  Execute requires --execute, --confirm-target, and --i-understand-this-writes-bcm-coding.")
    print()
    print("Carista-derived evidence:")
    for line in CARISTA_EVIDENCE:
        print(f"  {line}")
    print()
    print(f"Expected current: {expected_current}")
    print(f"Target:           {target}")
    print(f"Write method:     {args.write_method} ({WRITE_METHODS[args.write_method]['label']})")
    print()
    print("Changed bytes:")
    for index in changed_byte_indexes(expected_current, target):
        print(f"  byte {index:02d}: {expected_current[index * 2:index * 2 + 2]} -> {target[index * 2:index * 2 + 2]}")
    print()
    print(f"Application write command hypothesis: {command}")
    print("TP2.0 frames with current default write counter:")
    for frame in build_tp20_application_frames(counter, command):
        print(f"  {frame}")
    if args.write_method == "did-0600" and not args.skip_session and args.session.upper() == "1089":
        print()
        print("Known live outcome:")
        print("  session 1089 became positive, then the BCM immediately sent A8 on the first did-0600 write frame.")
        print("  Treat this as a retest-only path, not the default next attempt.")


def execute_write(args: argparse.Namespace, expected_current: HexString, target: HexString) -> int:
    log_path = args.output_dir / f"{args.run_id}_write_pq25_longcoding.txt"
    logger = Logger(log_path)
    write_command = build_write_command(target, args.write_method)

    logger.write("VW PQ25 TP2.0 long-coding write attempt")
    logger.write(f"Started: {datetime.now().isoformat(timespec='milliseconds')}")
    logger.write(f"Port: {args.port}")
    logger.write(f"Baud: {args.baud}")
    logger.write(f"Unit TP2.0 address: {args.unit}")
    logger.write(f"WARNING: this sends {WRITE_METHODS[args.write_method]['label']}.")
    logger.write("Carista-derived evidence:")
    for line in CARISTA_EVIDENCE:
        logger.write(f"  {line}")
    logger.write(f"Expected current: {expected_current}")
    logger.write(f"Target: {target}")
    logger.write(f"Write method: {args.write_method} ({WRITE_METHODS[args.write_method]['label']})")

    send_header = ""
    try:
        with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
            logger.section("ELM initialization")
            init_elm(ser, logger, args.timeout)

            channel = open_tp20_channel(ser, logger, args.unit, args.timeout)
            if channel is None:
                raise RuntimeError(f"Could not open VW TP2.0 channel to unit address {args.unit}")
            send_header, listen_header, _open_frames = channel

            if not args.skip_channel_parameters:
                get_channel_parameters(ser, logger, send_header, listen_header, args.timeout, args.parameter_profile)
            configure_data_channel(ser, logger, send_header, listen_header, args.timeout)

            if args.skip_session:
                logger.section("Diagnostic session skipped")
                pre_write_frames = send_pre_read_sequence(ser, logger, args.pre_write_sequence, args.timeout)
                if has_disconnect_frame(pre_write_frames, listen_header):
                    raise RuntimeError("channel disconnected before write")
                write_counter = args.write_counter if args.write_counter is not None else 0
            else:
                logger.section("Diagnostic session")
                session_status, session_payload, session_frames, next_counter = send_tp20_application_request(
                    ser,
                    logger,
                    args.session,
                    counter=args.session_counter,
                    listen_header=listen_header,
                    timeout=args.timeout,
                    auto_ack=False,
                )
                logger.write(f"Session status: {session_status} payload={session_payload}")
                if session_status != "positive":
                    raise RuntimeError(f"session {args.session} did not become positive")

                pre_write_frames = send_pre_read_sequence(ser, logger, args.pre_write_sequence, args.timeout)
                if has_disconnect_frame(session_frames + pre_write_frames, listen_header):
                    raise RuntimeError("channel disconnected before write")
                write_counter = args.write_counter if args.write_counter is not None else next_counter
            logger.section(f"Long-coding write using counter {write_counter:X}")
            status, payload, _frames = send_write_request(
                ser,
                logger,
                write_command,
                args.write_method,
                counter=write_counter,
                listen_header=listen_header,
                timeout=args.timeout,
                final_listen_ms=args.final_listen_ms,
            )
            logger.write(describe_write_outcome(status, payload))
            close_channel(ser, logger, send_header, args.timeout)
            return 0 if status == "positive" else 3
    except (RuntimeError, ValueError, serial.SerialException) as exc:
        logger.write(f"ERROR: {exc}")
        if send_header:
            logger.write("Channel may need an ignition cycle or adapter reconnect before retrying.")
        return 2
    finally:
        logger.save()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Guarded PQ25 BCM long-coding writer. Defaults to dry-run and never weakens the read-only probe."
    )
    parser.add_argument("--port", default=DEFAULT_PORT)
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD)
    parser.add_argument("--timeout", type=float, default=1.8)
    parser.add_argument("--unit", default=DEFAULT_UNIT)
    parser.add_argument("--parameter-profile", choices=("minimal", "legacy", "carista", "all"), default="minimal")
    parser.add_argument("--skip-channel-parameters", action="store_true")
    parser.add_argument("--session", default="1089")
    parser.add_argument(
        "--skip-session",
        action="store_true",
        help="Write directly after TP2.0 channel setup. Current BCM coding was read this way with 220600.",
    )
    parser.add_argument("--session-counter", type=lambda value: parse_counters(value)[0], default=0)
    parser.add_argument("--write-counter", type=lambda value: parse_counters(value)[0])
    parser.add_argument(
        "--write-method",
        choices=tuple(WRITE_METHODS),
        default="did-0600",
        help="Write command builder. did-0600 is the only full-coding write shape that the BCM parsed live.",
    )
    parser.add_argument(
        "--allow-obsolete-3b9a-full",
        action="store_true",
        help="Permit execution of the old simple 3B9A + full-coding hypothesis. Normally leave this off.",
    )
    parser.add_argument(
        "--allow-known-bad-session-1089",
        action="store_true",
        help="Permit execution with session 1089 even though the current live result is an immediate A8 disconnect on the first did-0600 write frame.",
    )
    parser.add_argument("--pre-write-sequence", type=parse_pre_read_sequence, default=())
    parser.add_argument("--final-listen-ms", type=int, default=1500)
    parser.add_argument("--expected-current", help="Current long-coding hex string or raw 5A9A response.")
    parser.add_argument("--expected-current-file", help="File containing current long coding or raw 5A9A response.")
    parser.add_argument("--target", help="Target long-coding hex string or raw 5A9A response.")
    parser.add_argument("--target-file", help="File containing target long coding or raw 5A9A response.")
    parser.add_argument("--confirm-target", help="Must exactly match target when --execute is used.")
    parser.add_argument("--allow-many-byte-changes", action="store_true")
    parser.add_argument("--allow-non-30-byte-coding", action="store_true")
    parser.add_argument("--execute", action="store_true")
    parser.add_argument("--i-understand-this-writes-bcm-coding", action="store_true")
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--run-id", default=datetime.now().strftime("pq25_write_%Y%m%d_%H%M%S"))
    return parser


def main() -> int:
    args = build_parser().parse_args()
    expected_current = read_hex(args.expected_current, args.expected_current_file, "expected-current")
    target = read_hex(args.target, args.target_file, "target")
    validate_inputs(args, expected_current, target)

    if not args.execute:
        dry_run(args, expected_current, target)
        return 0
    return execute_write(args, expected_current, target)


if __name__ == "__main__":
    raise SystemExit(main())
