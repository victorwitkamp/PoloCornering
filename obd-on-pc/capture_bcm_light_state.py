from __future__ import annotations

import argparse
import csv
import json
import re
import sys
import time
from datetime import datetime
from pathlib import Path
from typing import Any

import serial

WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
if str(WORKSPACE_ROOT) not in sys.path:
    sys.path.insert(0, str(WORKSPACE_ROOT))

from pq25_can_reference import (  # noqa: E402
    decoded_summary,
    message_name,
    message_relevance,
    normalize_can_header,
    raw_header_preset,
    reference_metadata,
)

from vw_tp20_readonly_probe import (  # noqa: E402
    BCM_LIGHT_DEBUG_READS,
    DEFAULT_BAUD,
    DEFAULT_PORT,
    DEFAULT_UNIT,
    READ_PROFILES,
    CanFrame,
    Logger,
    carista_command_label,
    close_channel,
    configure_data_channel,
    frame_dicts,
    get_channel_parameters,
    init_elm,
    is_safe_application_command,
    normalize_hex,
    open_tp20_channel,
    parse_can_frames,
    parse_commands,
    read_until_prompt_or_timeout,
    send,
    send_tp20_application_request,
    validate_hex,
)


DEFAULT_STATES = (
    "baseline_off",
    "parking_fog_off",
    "parking_fog_on",
    "lowbeam_fog_off",
    "lowbeam_fog_on",
    "left_turn",
    "right_turn",
    "highbeam",
    "reverse",
)

FAST_LIGHT_DEBUG_READS = ("220600", "220601", "220606", "1A9A", "1A91", "1802FF00", "1902FF")
CH_LH_DEBUG_READS = (
    "220600",
    "220601",
    "220606",
    "22055C",
    "22055D",
    "1A9A",
    "1A91",
    "1802FF00",
    "1902FF",
)
CH_LH_ROLE_READS = (
    "220601",
    "22055C",
    "22055D",
    "220606",
    "1802FF00",
    "1902FF",
)
CARISTA_READ_VALUES_CAPTURE_READS = READ_PROFILES["carista_read_values"]
CAPTURE_READ_PROFILES = {
    **READ_PROFILES,
    "carista_read_values": CARISTA_READ_VALUES_CAPTURE_READS,
    "bcm_light_fast": FAST_LIGHT_DEBUG_READS,
    "bcm_ch_lh_debug": CH_LH_DEBUG_READS,
    "bcm_ch_lh_roles": CH_LH_ROLE_READS,
}
MAX_TP20_SHORT_REQUEST_BYTES = 5

STATE_HINTS = {
    "baseline_off": "ignition/engine on, exterior lights off, fog switch off",
    "parking_fog_off": "parking lights on, fog switch off",
    "parking_fog_on": "parking lights on, fog switch on",
    "lowbeam_fog_off": "low beams on, fog switch off",
    "lowbeam_fog_on": "low beams on, fog switch on",
    "left_turn": "low beams on, left turn signal active; hold steering left too if safe",
    "right_turn": "low beams on, right turn signal active; hold steering right too if safe",
    "highbeam": "low beams and high beams on",
    "reverse": "reverse selected if safe, otherwise type s at the prompt to skip this state",
}

SUMMARY_FIELDS = (
    "state",
    "repeat",
    "command",
    "command_label",
    "status",
    "payload",
    "payload_bytes",
    "changed_from_baseline",
    "error",
    "log_file",
    "send_header",
    "listen_header",
    "channel_parameter_status",
    "channel_parameters",
    "raw_payloads",
)

RAW_CAN_FIELDS = (
    "state",
    "repeat",
    "window_ms",
    "timestamp",
    "header",
    "payload",
    "known_message",
    "message_relevance",
    "decoded_signals",
    "source",
    "tp20_label",
)


def now_id() -> str:
    return datetime.now().strftime("bcm_light_capture_%Y%m%d_%H%M%S")


def now_text() -> str:
    return datetime.now().isoformat(timespec="milliseconds")


def parse_states(raw: str) -> tuple[str, ...]:
    values = tuple(slugify(part) for part in raw.split(",") if part.strip())
    if not values:
        raise argparse.ArgumentTypeError("At least one state is required")
    return values


def parse_raw_headers(raw: str) -> tuple[str, ...]:
    if not raw.strip():
        return ()
    headers: list[str] = []
    for part in raw.split(","):
        token = part.strip()
        if not token:
            continue
        preset = raw_header_preset(token)
        if preset:
            headers.extend(preset)
            continue
        headers.append(normalize_can_header(validate_hex(token, "raw CAN header", even=False)))
    return tuple(dict.fromkeys(headers))


def parse_raw_can_filter(raw: str) -> str:
    if not raw.strip():
        return ""
    return validate_hex(raw, "raw CAN filter", even=False)


def slugify(value: str) -> str:
    normalized = re.sub(r"[^A-Za-z0-9_.-]+", "_", value.strip().lower())
    return normalized.strip("_") or "state"


def selected_commands(args: argparse.Namespace) -> tuple[str, ...]:
    commands = tuple(args.read_commands or CAPTURE_READ_PROFILES[args.read_profile])
    blocked = [command for command in commands if not is_safe_application_command(command)]
    if blocked:
        raise ValueError(f"Blocked non-read-only service(s): {', '.join(blocked)}")
    too_long = [command for command in commands if len(normalize_hex(command)) // 2 > MAX_TP20_SHORT_REQUEST_BYTES]
    if too_long:
        details = ", ".join(f"{command} ({len(normalize_hex(command)) // 2} bytes)" for command in too_long)
        raise ValueError(
            "This capture transport supports short TP2.0 application requests only "
            f"(<= {MAX_TP20_SHORT_REQUEST_BYTES} bytes): {details}"
        )
    return commands


def preflight_commands(commands: tuple[str, ...]) -> tuple[str, ...]:
    for command in ("220600", "1A9A", "1A9B"):
        if command in commands:
            return (command,)
    return commands[:1]


def payload_byte_count(payload: str) -> str:
    payload = normalize_hex(payload)
    if not payload or len(payload) % 2:
        return ""
    return str(len(payload) // 2)


def byte_deltas(base: str, current: str) -> list[str]:
    base = normalize_hex(base)
    current = normalize_hex(current)
    if not base or not current or len(base) % 2 or len(current) % 2:
        return []
    base_bytes = bytes.fromhex(base)
    current_bytes = bytes.fromhex(current)
    deltas: list[str] = []
    for index in range(max(len(base_bytes), len(current_bytes))):
        old = f"{base_bytes[index]:02X}" if index < len(base_bytes) else "--"
        new = f"{current_bytes[index]:02X}" if index < len(current_bytes) else "--"
        if old != new:
            deltas.append(f"{index}:{old}->{new}")
    return deltas


def command_baselines(rows: list[dict[str, Any]]) -> dict[str, str]:
    baselines: dict[str, str] = {}
    for row in rows:
        command = str(row.get("command", ""))
        payload = str(row.get("payload", ""))
        if command and payload and command not in baselines:
            baselines[command] = payload
    return baselines


def annotate_deltas(rows: list[dict[str, Any]]) -> None:
    baselines = command_baselines(rows)
    for row in rows:
        command = str(row.get("command", ""))
        payload = str(row.get("payload", ""))
        baseline = baselines.get(command, "")
        if not baseline or payload == baseline:
            row["changed_from_baseline"] = ""
        else:
            deltas = byte_deltas(baseline, payload)
            row["changed_from_baseline"] = ", ".join(deltas) if deltas else "payload/status changed"


def csv_ready(row: dict[str, Any], fields: tuple[str, ...]) -> dict[str, str]:
    ready: dict[str, str] = {}
    for field in fields:
        value = row.get(field, "")
        if isinstance(value, (list, dict)):
            ready[field] = json.dumps(value, separators=(",", ":"))
        else:
            ready[field] = str(value)
    return ready


def raw_frame_row(frame: CanFrame, state: str, repeat: int, window_ms: int) -> dict[str, Any]:
    header = normalize_can_header(frame.header)
    return {
        "state": state,
        "repeat": repeat,
        "window_ms": window_ms,
        "timestamp": frame.timestamp,
        "header": header,
        "payload": frame.payload,
        "known_message": message_name(header),
        "message_relevance": message_relevance(header),
        "decoded_signals": decoded_summary(header, frame.payload),
        "source": frame.source,
        "tp20_label": frame.tp20_label,
    }


def capture_raw_can_text(
    ser: serial.Serial,
    logger: Logger,
    monitor_command: str,
    window_ms: int,
    label: str,
) -> str:
    if ser.in_waiting:
        ser.read(ser.in_waiting)
    ser.write(f"{monitor_command}\r".encode("ascii"))
    ser.flush()
    logger.write(f"[{now_text()}] >>> {monitor_command} ({label}, {window_ms} ms)")
    deadline = time.monotonic() + window_ms / 1000.0
    chunks: list[bytes] = []
    while time.monotonic() < deadline:
        waiting = ser.in_waiting
        if waiting:
            chunks.append(ser.read(waiting))
        else:
            time.sleep(0.01)
    ser.write(b"\r")
    ser.flush()
    chunks.append(read_until_prompt_or_timeout(ser, 1.0).encode("ascii", errors="replace"))
    return b"".join(chunks).decode("ascii", errors="replace").replace(">", "").strip()


def raw_can_monitor_targets(args: argparse.Namespace) -> list[str]:
    if args.raw_headers:
        return [normalize_can_header(header) for header in args.raw_headers]
    if args.raw_can_filter:
        return [normalize_can_header(args.raw_can_filter)]
    return []


def raw_can_window_ms(args: argparse.Namespace, target_count: int) -> int:
    if args.raw_can_per_header_ms > 0:
        return args.raw_can_per_header_ms
    if target_count > 1 and args.raw_can_monitor_mode in {"atcra-atma", "atcf-atma"}:
        return max(250, args.raw_can_ms // target_count)
    return args.raw_can_ms


def configure_raw_can_filter(
    ser: serial.Serial,
    logger: Logger,
    args: argparse.Namespace,
    header: str,
) -> str:
    if args.raw_can_monitor_mode == "atcra-atma":
        send(ser, logger, f"ATCRA{header}", args.timeout, pause=0.2)
        return "ATMA"
    if args.raw_can_monitor_mode == "atcf-atma":
        send(ser, logger, "ATCM7FF", args.timeout, pause=0.2)
        send(ser, logger, f"ATCF{header}", args.timeout, pause=0.2)
        return "ATMA"
    if args.raw_can_monitor_mode == "atmr":
        return f"ATMR{header}"
    if args.raw_can_monitor_mode == "atmt":
        return f"ATMT{header}"
    raise ValueError(f"raw CAN monitor mode {args.raw_can_monitor_mode} requires a target header")


def capture_raw_can_window(
    args: argparse.Namespace,
    state: str,
    repeat: int,
    logger: Logger,
) -> list[dict[str, Any]]:
    if args.raw_can_ms <= 0:
        return []

    logger.section(f"Raw CAN monitor: state={state} repeat={repeat} window={args.raw_can_ms} ms")
    frames: list[CanFrame] = []
    try:
        with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
            for command, pause in (
                ("ATZ", 1.0),
                ("ATE0", 0.2),
                ("ATL0", 0.2),
                ("ATS0", 0.2),
                ("ATH1", 0.2),
                ("ATCAF0", 0.2),
                ("ATAL", 0.2),
                ("ATSP6", 0.2),
                ("ATDP", 0.2),
            ):
                send(ser, logger, command, args.timeout, pause=pause)

            chunks: list[str] = []
            targets = raw_can_monitor_targets(args)
            if args.raw_can_monitor_mode == "atma" or not targets:
                if args.raw_can_filter:
                    send(ser, logger, f"ATCRA{args.raw_can_filter}", args.timeout, pause=0.2)
                chunks.append(capture_raw_can_text(ser, logger, "ATMA", args.raw_can_ms, "unfiltered"))
            else:
                window_ms = raw_can_window_ms(args, len(targets))
                logger.write(
                    "Raw CAN pre-filtered monitor mode: "
                    f"{args.raw_can_monitor_mode}; headers={','.join(targets)}; "
                    f"window_per_header={window_ms} ms"
                )
                for header in targets:
                    monitor_command = configure_raw_can_filter(ser, logger, args, header)
                    chunks.append(capture_raw_can_text(ser, logger, monitor_command, window_ms, f"header {header}"))

        cleaned = "\n".join(chunk for chunk in chunks if chunk).strip()
        if cleaned:
            logger.write(cleaned)
        else:
            logger.write("<no raw CAN monitor output>")
        frames = parse_can_frames(cleaned, f"raw_can_{state}_{repeat}")
        if args.raw_headers:
            wanted = {normalize_can_header(header) for header in args.raw_headers}
            frames = [frame for frame in frames if normalize_can_header(frame.header) in wanted]
        logger.write(f"Raw CAN frames retained: {len(frames)}")
    except serial.SerialException as exc:
        logger.write(f"Raw CAN monitor error: {exc}")

    return [raw_frame_row(frame, state, repeat, args.raw_can_ms) for frame in frames]


def capture_tp20_snapshot(
    args: argparse.Namespace,
    state: str,
    repeat: int,
    commands: tuple[str, ...],
    log_file: Path,
) -> list[dict[str, Any]]:
    logger = Logger(log_file)
    rows: list[dict[str, Any]] = []
    send_header = ""
    listen_header = ""
    channel_opened = False

    def base_row(command: str) -> dict[str, Any]:
        return {
            "state": state,
            "repeat": repeat,
            "command": command,
            "command_label": carista_command_label(command),
            "status": "",
            "payload": "",
            "payload_bytes": "",
            "changed_from_baseline": "",
            "error": "",
            "log_file": str(log_file),
            "send_header": send_header,
            "listen_header": listen_header,
            "channel_parameter_status": "",
            "channel_parameters": {},
            "raw_payloads": [],
        }

    try:
        logger.write("VW PQ25 BCM light-state capture")
        logger.write(f"Started: {now_text()}")
        logger.write(f"State: {state}")
        logger.write(f"Repeat: {repeat}")
        logger.write(f"Port: {args.port}")
        logger.write(f"Baud: {args.baud}")
        logger.write(f"Unit TP2.0 address: {args.unit}")
        logger.write("Read-only only. Blocked services: 27, 2E, 31, 3B")

        with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
            logger.section("ELM initialization")
            init_elm(ser, logger, args.timeout)

            channel = open_tp20_channel(ser, logger, args.unit, args.timeout)
            if channel is None:
                raise RuntimeError(f"Could not open VW TP2.0 channel to unit address {args.unit}")
            send_header, listen_header, open_frames = channel
            channel_opened = True

            if args.skip_channel_parameters:
                parameter_status = "skipped"
                parameters: dict[str, int] = {"block": 15, "T1": 255, "T2": 255, "T3": 255, "T4": 255}
                parameter_frames: list[CanFrame] = []
            else:
                max_block, t1, t2, t3, t4, parameter_frames, parameter_status = get_channel_parameters(
                    ser,
                    logger,
                    send_header,
                    listen_header,
                    args.timeout,
                    args.parameter_profile,
                )
                parameters = {"block": max_block, "T1": t1, "T2": t2, "T3": t3, "T4": t4}
                if parameter_status != "answered":
                    raise RuntimeError(
                        "TP2.0 channel parameters did not answer; aborting this state instead of logging misleading no_response rows. "
                        "Reset the adapter/channel and retry with --parameter-profile carista_then_minimal."
                    )
            configure_data_channel(ser, logger, send_header, listen_header, args.timeout)

            counter = args.read_counter
            for command in commands:
                row = base_row(command)
                row["send_header"] = send_header
                row["listen_header"] = listen_header
                row["channel_parameter_status"] = parameter_status
                row["channel_parameters"] = parameters
                row["raw_payloads"] = frame_dicts(open_frames + parameter_frames)

                logger.section(f"State read: {state} repeat={repeat} counter={counter:X} command={command}")
                status, payload, frames, counter = send_tp20_application_request(
                    ser,
                    logger,
                    command,
                    counter=counter,
                    listen_header=listen_header,
                    timeout=args.timeout,
                    auto_ack=True,
                )
                row["status"] = status
                row["payload"] = payload
                row["payload_bytes"] = payload_byte_count(payload)
                row["raw_payloads"] = frame_dicts(open_frames + parameter_frames + frames)
                rows.append(row)

                if status == "disconnect":
                    logger.write("Stopping this state after TP2.0 disconnect.")
                    break
                if args.inter_command_ms > 0:
                    time.sleep(args.inter_command_ms / 1000.0)

            close_channel(ser, logger, send_header, args.timeout)
            channel_opened = False
    except (RuntimeError, ValueError, serial.SerialException) as exc:
        logger.write(f"ERROR: {exc}")
        if not rows:
            row = base_row("<setup>")
            row["error"] = str(exc)
            row["send_header"] = send_header
            row["listen_header"] = listen_header
            rows.append(row)
        else:
            rows[-1]["error"] = str(exc)
    finally:
        if channel_opened and send_header:
            logger.write("Channel may still be open; adapter/ignition cycle may be needed before retrying.")
        logger.save()

    return rows


def prompt_for_state(args: argparse.Namespace, state: str, repeat: int) -> str:
    if args.no_prompts:
        return "capture"
    hint = STATE_HINTS.get(state, "set the requested driver/lamp state")
    print()
    print(f"Next capture: {state} repeat {repeat}")
    print(f"Set state: {hint}")
    answer = input("Press Enter to capture, s to skip this state, or q to finish and write outputs: ").strip().lower()
    if answer in {"s", "skip"}:
        return "skip"
    if answer in {"q", "quit", "done", "finish"}:
        return "finish"
    if args.settle_ms > 0:
        time.sleep(args.settle_ms / 1000.0)
    return "capture"


def write_outputs(
    args: argparse.Namespace,
    commands: tuple[str, ...],
    rows: list[dict[str, Any]],
    raw_rows: list[dict[str, Any]],
) -> dict[str, str]:
    annotate_deltas(rows)
    args.output_dir.mkdir(parents=True, exist_ok=True)
    base = args.output_dir / args.run_id
    json_path = base.with_name(base.name + "_bcm_light_capture.json")
    csv_path = base.with_name(base.name + "_bcm_light_capture.csv")
    raw_csv_path = base.with_name(base.name + "_raw_can.csv")
    report_path = base.with_name(base.name + "_bcm_light_capture.md")

    payload = {
        "metadata": {
            "started": args.started,
            "last_updated": now_text(),
            "run_id": args.run_id,
            "port": args.port,
            "baud": args.baud,
            "unit": args.unit,
            "read_profile": args.read_profile,
            "read_commands": list(commands),
            "states": list(args.states),
            "repeats": args.repeats,
            "raw_can_ms": args.raw_can_ms,
            "raw_can_filter": args.raw_can_filter,
            "raw_can_monitor_mode": args.raw_can_monitor_mode,
            "raw_can_per_header_ms": args.raw_can_per_header_ms,
            "raw_headers": list(args.raw_headers),
            "raw_can_reference": reference_metadata(),
            "completed": bool(getattr(args, "completed", False)),
            "interrupted": bool(getattr(args, "interrupted", False)),
            "ended_early": bool(getattr(args, "ended_early", False)),
            "skipped_states": list(getattr(args, "skipped_states", [])),
            "safety": "read-only; blocks 27, 2E, 31, and 3B service prefixes",
        },
        "captures": rows,
        "raw_can_frames": raw_rows,
    }
    json_path.write_text(json.dumps(payload, indent=2), encoding="utf-8")

    with csv_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=SUMMARY_FIELDS)
        writer.writeheader()
        for row in rows:
            writer.writerow(csv_ready(row, SUMMARY_FIELDS))

    with raw_csv_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=RAW_CAN_FIELDS)
        writer.writeheader()
        for row in raw_rows:
            writer.writerow(csv_ready(row, RAW_CAN_FIELDS))

    report_path.write_text(render_report(args, commands, rows, raw_rows), encoding="utf-8")
    return {
        "json": str(json_path),
        "csv": str(csv_path),
        "raw_csv": str(raw_csv_path),
        "report": str(report_path),
    }


def render_report(
    args: argparse.Namespace,
    commands: tuple[str, ...],
    rows: list[dict[str, Any]],
    raw_rows: list[dict[str, Any]],
) -> str:
    lines = [
        "# BCM Light-State Capture",
        "",
        f"Started: `{args.started}`",
        f"Last updated: `{now_text()}`",
        f"Run id: `{args.run_id}`",
        f"Completed: `{bool(getattr(args, 'completed', False))}`",
        f"Interrupted: `{bool(getattr(args, 'interrupted', False))}`",
        "",
        "This capture is read-only. It sends only the configured diagnostic read commands and blocks services `27`, `2E`, `31`, and `3B`.",
        "",
        "## Inputs",
        "",
        f"- Port: `{args.port}`",
        f"- Unit: `{args.unit}`",
        f"- Read profile: `{args.read_profile}`",
        f"- States: `{', '.join(args.states)}`",
        f"- Repeats: `{args.repeats}`",
        f"- Raw CAN window: `{args.raw_can_ms} ms`",
        "",
    ]

    skipped_states = list(getattr(args, "skipped_states", []))
    if skipped_states:
        lines.extend(["## Skipped States", ""])
        lines.extend(["| State | Repeat | Time |", "|---|---:|---|"])
        for skipped in skipped_states:
            lines.append(
                "| "
                + " | ".join(
                    [
                        f"`{skipped.get('state', '')}`",
                        str(skipped.get("repeat", "")),
                        f"`{skipped.get('time', '')}`",
                    ]
                )
                + " |"
            )
        lines.append("")

    lines.extend(["## Changed Diagnostic Payloads", ""])

    changed = [row for row in rows if row.get("changed_from_baseline")]
    if not changed:
        lines.append("No diagnostic read payload changed from the first captured payload for the same command.")
    else:
        lines.extend(["| Command | State | Repeat | Status | Byte deltas | Payload |", "|---|---|---:|---|---|---|"])
        for row in changed:
            lines.append(
                "| "
                + " | ".join(
                    [
                        f"`{row.get('command', '')}`",
                        f"`{row.get('state', '')}`",
                        str(row.get("repeat", "")),
                        f"`{row.get('status', '')}`",
                        str(row.get("changed_from_baseline", "")).replace("|", "\\|"),
                        f"`{row.get('payload', '')}`",
                    ]
                )
                + " |"
            )

    lines.extend(["", "## Command Matrix", ""])
    for command in commands:
        command_rows = [row for row in rows if row.get("command") == command]
        if not command_rows:
            continue
        label = carista_command_label(command)
        lines.append(f"### `{command}`")
        if label:
            lines.append(label)
        lines.append("")
        lines.extend(["| State | Repeat | Status | Payload bytes | Payload |", "|---|---:|---|---:|---|"])
        for row in command_rows:
            lines.append(
                "| "
                + " | ".join(
                    [
                        f"`{row.get('state', '')}`",
                        str(row.get("repeat", "")),
                        f"`{row.get('status', '')}`",
                        str(row.get("payload_bytes", "")),
                        f"`{row.get('payload', '')}`",
                    ]
                )
                + " |"
            )
        lines.append("")

    lines.extend(["## Raw CAN", ""])
    if raw_rows:
        by_state: dict[str, int] = {}
        for row in raw_rows:
            state = str(row.get("state", ""))
            by_state[state] = by_state.get(state, 0) + 1
        lines.extend(["| State | Frames retained |", "|---|---:|"])
        for state, count in sorted(by_state.items()):
            lines.append(f"| `{state}` | {count} |")
    else:
        lines.append("Raw CAN capture was disabled or retained no frames.")

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- A changed payload is a clue, not a decoded lamp state by itself.",
            "- Raw CAN monitor-all output from an ELM adapter can drop frames on a busy bus; use repeated captures for proof.",
            "- If no payload changes across lamp states, the missing lamp-state path is probably behind an unrecovered Carista `ReadValuesOperation` setting/value implementation.",
            "",
        ]
    )
    return "\n".join(lines)


def print_outputs(outputs: dict[str, str]) -> None:
    print()
    print("Capture outputs:")
    for label, path in outputs.items():
        print(f"  {label}: {path}")


def run(args: argparse.Namespace) -> int:
    commands = selected_commands(args)
    rows: list[dict[str, Any]] = []
    raw_rows: list[dict[str, Any]] = []
    args.completed = False
    args.interrupted = False
    args.ended_early = False
    args.skipped_states = []

    print("VW PQ25 BCM light-state capture")
    print("Read-only only. Blocked services: 27, 2E, 31, 3B")
    print(f"Run id: {args.run_id}")
    print(f"Commands: {', '.join(commands)}")

    try:
        if args.preflight_only:
            quick_commands = preflight_commands(commands)
            print(f"Preflight only. Command: {', '.join(quick_commands)}")
            log_file = args.output_dir / f"{args.run_id}_preflight_tp20_snapshot.txt"
            rows.extend(capture_tp20_snapshot(args, "preflight", 1, quick_commands, log_file))
            args.completed = True
            outputs = write_outputs(args, commands, rows, raw_rows)
            print_outputs(outputs)
            return 0 if any(row.get("status") in {"positive", "negative", "other"} for row in rows) else 2

        for repeat in range(1, args.repeats + 1):
            for state in args.states:
                action = prompt_for_state(args, state, repeat)
                if action == "skip":
                    args.skipped_states.append({"state": state, "repeat": repeat, "time": now_text()})
                    write_outputs(args, commands, rows, raw_rows)
                    continue
                if action == "finish":
                    args.ended_early = True
                    outputs = write_outputs(args, commands, rows, raw_rows)
                    print_outputs(outputs)
                    return 0

                state_id = f"{args.run_id}_{state}_r{repeat:02d}"
                raw_log_file = args.output_dir / f"{state_id}_raw_can.txt"
                raw_logger = Logger(raw_log_file)
                try:
                    raw_rows.extend(capture_raw_can_window(args, state, repeat, raw_logger))
                finally:
                    if args.raw_can_ms > 0:
                        raw_logger.save()

                log_file = args.output_dir / f"{state_id}_tp20_snapshot.txt"
                rows.extend(capture_tp20_snapshot(args, state, repeat, commands, log_file))
                write_outputs(args, commands, rows, raw_rows)

        args.completed = True
        outputs = write_outputs(args, commands, rows, raw_rows)
        print_outputs(outputs)
        return 0
    except KeyboardInterrupt:
        args.interrupted = True
        outputs = write_outputs(args, commands, rows, raw_rows)
        print("Capture interrupted by user; partial outputs were written.")
        print_outputs(outputs)
        return 130


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Guided read-only BCM light-state capture for PQ25 TP2.0 unit 20.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python capture_bcm_light_state.py --port COM10
  python capture_bcm_light_state.py --port COM10 --states baseline_off,left_turn,right_turn --raw-can-ms 5000
    python capture_bcm_light_state.py --port COM10 --preflight-only
    python capture_bcm_light_state.py --port COM10 --read-profile bcm_light_fast --states left_turn,right_turn --raw-can-ms 5000
    python capture_bcm_light_state.py --port COM10 --read-profile bcm_light_fast --raw-can-ms 5000 --raw-headers pq25_light_context
    python capture_bcm_light_state.py --port COM10 --read-profile bcm_ch_lh_debug --states baseline_off,parking_fog_off,lowbeam_fog_off,left_turn,right_turn
    python capture_bcm_light_state.py --port COM10 --parameter-profile carista_then_minimal --read-profile carista_read_values --states baseline_off,left_turn,right_turn
    python capture_bcm_light_state.py --port COM10 --parameter-profile carista_then_minimal --read-profile bcm_ch_lh_roles --states switch_left,switch_middle,switch_right,right_pull_once,right_pull_twice,middle_left_turn,middle_right_turn
    python capture_bcm_light_state.py --port COM10 --raw-can-ms 8000 --raw-headers 390,392 --raw-can-monitor-mode atcf-atma
  python capture_bcm_light_state.py --port COM10 --read-commands 220600,1802FF00,1902FF --no-prompts
""",
    )
    parser.add_argument("--port", default=DEFAULT_PORT)
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD)
    parser.add_argument("--timeout", type=float, default=2.5)
    parser.add_argument("--unit", default=DEFAULT_UNIT, type=lambda value: validate_hex(value, "unit"))
    parser.add_argument(
        "--parameter-profile",
        choices=("minimal", "legacy", "carista", "carista_exact", "carista_then_minimal", "all"),
        default="carista_then_minimal",
    )
    parser.add_argument("--skip-channel-parameters", action="store_true")
    parser.add_argument("--read-profile", choices=sorted(CAPTURE_READ_PROFILES), default="bcm_light_debug")
    parser.add_argument("--read-commands", type=parse_commands, default=None)
    parser.add_argument("--read-counter", type=lambda value: int(value, 0), default=0)
    parser.add_argument("--states", type=parse_states, default=DEFAULT_STATES)
    parser.add_argument("--repeats", type=int, default=1)
    parser.add_argument("--settle-ms", type=int, default=500)
    parser.add_argument("--inter-command-ms", type=int, default=100)
    parser.add_argument("--no-prompts", action="store_true")
    parser.add_argument("--raw-can-ms", type=int, default=0)
    parser.add_argument("--raw-can-filter", type=parse_raw_can_filter, default="")
    parser.add_argument(
        "--raw-can-monitor-mode",
        choices=("atma", "atcra-atma", "atcf-atma", "atmr", "atmt"),
        default="atma",
        help="ELM raw monitor command strategy. Use atcf-atma to pre-filter exact 11-bit headers on slow clones.",
    )
    parser.add_argument(
        "--raw-can-per-header-ms",
        type=int,
        default=0,
        help="Override per-header raw monitor window for pre-filtered raw CAN modes.",
    )
    parser.add_argument(
        "--raw-headers",
        type=parse_raw_headers,
        default=(),
        help="Comma-separated raw CAN headers or presets: pq25_light_context, light_context, tp20.",
    )
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--run-id", default=now_id())
    parser.add_argument("--preflight-only", action="store_true", help="Open TP2.0, run one known read, write outputs, and exit.")
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()
    if args.repeats < 1:
        parser.error("--repeats must be >= 1")
    if args.settle_ms < 0 or args.inter_command_ms < 0 or args.raw_can_ms < 0 or args.raw_can_per_header_ms < 0:
        parser.error("timing values must be >= 0")
    if args.raw_can_ms > 0 and args.raw_can_monitor_mode != "atma" and not args.raw_headers and not args.raw_can_filter:
        parser.error("--raw-can-monitor-mode other than atma requires --raw-headers or --raw-can-filter")
    args.started = now_text()
    try:
        return run(args)
    except ValueError as exc:
        parser.error(str(exc))
    except KeyboardInterrupt:
        print("Capture interrupted by user.")
        return 130


if __name__ == "__main__":
    raise SystemExit(main())