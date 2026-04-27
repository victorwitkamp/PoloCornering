from __future__ import annotations

import argparse
from datetime import datetime
from pathlib import Path

import serial

from compose_carista_3b9a_tuple import build_request, clean_hex, read_coding, require_len
from compose_carista_3b9a_tuple import CORNERING_FIXES, derive_value6
from vw_tp20_readonly_probe import (
    DEFAULT_BAUD,
    DEFAULT_PORT,
    DEFAULT_UNIT,
    Logger,
    close_channel,
    configure_data_channel,
    get_channel_parameters,
    init_elm,
    open_tp20_channel,
    parse_counters,
    parse_pre_read_sequence,
    send_pre_read_sequence,
)
from write_pq25_longcoding import (
    build_tp20_application_frames,
    describe_write_outcome,
    send_write_request,
)


def clean_request(request: str) -> str:
    cleaned = "".join(char for char in request.upper() if char in "0123456789ABCDEF")
    if len(cleaned) % 2:
        raise ValueError("request must contain whole bytes")
    if not cleaned.startswith("3B9A"):
        raise ValueError("structured tuple request must start with 3B9A")
    if len(cleaned) < 2 * (2 + 6 + 4 + 1):
        raise ValueError("request is too short for 3B9A + value6 + rawAddress4 + suffix")
    return cleaned


def build_structured_request(args: argparse.Namespace) -> str:
    if args.request:
        return clean_request(args.request)

    if args.value6:
        value6 = require_len(args.value6, "value6", 6)
    else:
        coding = read_coding(args.coding, args.coding_file)
        if coding is None or args.cornering_fix is None:
            raise ValueError("provide --request, --value6, or --coding/--coding-file with --cornering-fix")
        byte_index, bit_index, label = CORNERING_FIXES[args.cornering_fix]
        value6 = derive_value6(coding, 6, None, byte_index, bit_index, "set", label).value6

    raw_address4 = require_len(args.raw_address4 or "", "raw-address4", 4)
    return build_request(value6, raw_address4, args.coding_type, clean_hex(args.tail, "tail"))


def dry_run(args: argparse.Namespace, request: str) -> None:
    counter = args.write_counter if args.write_counter is not None else (0 if args.skip_session else 1)
    print("Structured Carista 3B9A tuple writer dry run")
    print()
    print("Safety:")
    print("  Nothing was sent to the car.")
    print("  Execute only after a real Carista trace has recovered rawAddress4/codingType/tail.")
    print("  Execute requires --execute, --confirm-request, and --i-understand-this-writes-bcm-coding.")
    print()
    print(f"Request:       {request}")
    print(f"Tuple length:  {len(request) // 2} bytes")
    print(f"TP2.0 counter: {counter:X}")
    print()
    print("TP2.0 frame plan:")
    for frame in build_tp20_application_frames(counter, request):
        print(f"  {frame}")


def execute(args: argparse.Namespace, request: str) -> int:
    log_path = args.output_dir / f"{args.run_id}_write_carista_3b9a_tuple.txt"
    logger = Logger(log_path)
    send_header = ""
    channel_opened = False
    try:
        with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
            logger.write("Structured Carista 3B9A tuple write attempt")
            logger.write(f"Started: {datetime.now().isoformat(timespec='milliseconds')}")
            logger.write(f"Port: {args.port}")
            logger.write(f"Baud: {args.baud}")
            logger.write(f"Unit TP2.0 address: {args.unit}")
            logger.write(f"Request: {request}")
            logger.write("WARNING: this sends a recovered structured Carista coding tuple.")

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

            if args.skip_session:
                logger.section("Diagnostic session skipped")
                pre_write_frames = send_pre_read_sequence(ser, logger, args.pre_write_sequence, args.timeout)
                if any(frame.header == listen_header and frame.payload.startswith("A8") for frame in pre_write_frames):
                    raise RuntimeError("channel disconnected before write")
                write_counter = args.write_counter if args.write_counter is not None else 0
            else:
                raise RuntimeError("structured tuple execution currently requires --skip-session until Carista trace proves a session path")

            logger.section(f"Structured 3B9A tuple write using counter {write_counter:X}")
            status, payload, _frames = send_write_request(
                ser,
                logger,
                request,
                "carista-3b9a",
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
        if channel_opened:
            logger.write("Channel may need an ignition cycle or adapter reconnect before retrying.")
        return 2
    finally:
        logger.save()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Guarded sender for a recovered structured Carista 3B9A write tuple. Defaults to dry-run."
    )
    parser.add_argument("--request", help="Complete recovered 3B9A request.")
    parser.add_argument("--value6", help="Explicit 6-byte tuple value.")
    parser.add_argument("--coding", help="Current long-coding hex or raw 620600/5A9A response.")
    parser.add_argument("--coding-file", help="File containing current long-coding hex or direct-read JSON summary.")
    parser.add_argument("--cornering-fix", choices=sorted(CORNERING_FIXES), help="Known PQ25 cornering fix to derive value6.")
    parser.add_argument("--raw-address4", help="Recovered 4-byte raw-address vector.")
    parser.add_argument("--coding-type", type=int, help="Recovered Carista/VagEcuInfo coding type.")
    parser.add_argument("--tail", default="", help="Recovered tail bytes.")
    parser.add_argument("--port", default=DEFAULT_PORT)
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD)
    parser.add_argument("--timeout", type=float, default=1.8)
    parser.add_argument("--unit", default=DEFAULT_UNIT)
    parser.add_argument("--parameter-profile", choices=("minimal", "legacy", "carista", "all"), default="minimal")
    parser.add_argument("--skip-channel-parameters", action="store_true")
    parser.add_argument("--skip-session", action="store_true")
    parser.add_argument("--pre-write-sequence", type=parse_pre_read_sequence, default=())
    parser.add_argument("--write-counter", type=lambda value: parse_counters(value)[0])
    parser.add_argument("--final-listen-ms", type=int, default=1500)
    parser.add_argument("--confirm-request", help="Must exactly match the complete 3B9A request when --execute is used.")
    parser.add_argument("--execute", action="store_true")
    parser.add_argument("--i-understand-this-writes-bcm-coding", action="store_true")
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--run-id", default=datetime.now().strftime("pq25_carista_tuple_%Y%m%d_%H%M%S"))
    return parser


def main() -> int:
    args = build_parser().parse_args()
    request = build_structured_request(args)

    if not args.execute:
        dry_run(args, request)
        return 0

    if not args.i_understand_this_writes_bcm_coding:
        raise ValueError("execution requires --i-understand-this-writes-bcm-coding")
    if clean_request(args.confirm_request or "") != request:
        raise ValueError("--confirm-request must exactly match the generated request")
    return execute(args, request)


if __name__ == "__main__":
    raise SystemExit(main())
