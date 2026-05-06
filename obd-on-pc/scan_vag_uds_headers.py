from __future__ import annotations

import argparse
import csv
import json
import re
import time
from dataclasses import asdict, dataclass
from datetime import datetime
from pathlib import Path
from typing import TypeAlias

import serial


HexString: TypeAlias = str
BLOCKED_PREFIXES = ("27", "2E", "31", "3B")
DEFAULT_DISCOVERY_COMMANDS = ("22F190", "22F187")
DEFAULT_DETAIL_COMMANDS = ("22F190", "22F187", "22F189", "22F197", "220600")
DEFAULT_HEADERS = tuple(f"{value:03X}" for value in range(0x700, 0x720)) + tuple(
    f"{value:03X}" for value in range(0x7E0, 0x7E8)
)
HEX_RE = re.compile(r"^[0-9A-F]+$", re.IGNORECASE)


@dataclass(frozen=True)
class UdsReadResult:
    request_header: HexString
    response_header: HexString
    command: HexString
    status: str
    payload: HexString
    raw: str


@dataclass(frozen=True)
class ElmCommandLogEntry:
    order: int
    phase: str
    command: str
    raw: str


def normalize_hex(value: str) -> HexString:
    return re.sub(r"[^0-9A-Fa-f]", "", value).upper()


def parse_csv_hex(raw: str) -> tuple[HexString, ...]:
    values = tuple(normalize_hex(part) for part in raw.split(",") if part.strip())
    if not values:
        raise argparse.ArgumentTypeError("At least one hex value is required")
    for value in values:
        if len(value) % 2 or not HEX_RE.match(value):
            raise argparse.ArgumentTypeError(f"Invalid hex value: {value!r}")
        if value.startswith(BLOCKED_PREFIXES):
            raise argparse.ArgumentTypeError(f"Blocked command prefix in {value!r}")
    return values


def parse_headers(raw: str) -> tuple[HexString, ...]:
    headers = tuple(normalize_hex(part).zfill(3) for part in raw.split(",") if part.strip())
    for header in headers:
        if len(header) != 3 or not HEX_RE.match(header):
            raise argparse.ArgumentTypeError(f"Invalid 11-bit header: {header!r}")
    return headers


def expected_response_header(request_header: HexString) -> HexString:
    value = int(request_header, 16)
    if 0x7E0 <= value <= 0x7E7:
        return f"{value + 8:03X}"
    return f"{value + 0x6A:03X}"


def positive_marker(command: HexString) -> HexString:
    service = int(command[:2], 16)
    return f"{service + 0x40:02X}{command[2:]}"


def read_until_prompt(ser: serial.Serial, timeout: float) -> str:
    deadline = time.monotonic() + timeout
    chunks: list[bytes] = []
    while time.monotonic() < deadline:
        waiting = ser.in_waiting
        if waiting:
            chunk = ser.read(waiting)
            chunks.append(chunk)
            if b">" in chunk:
                break
        else:
            time.sleep(0.02)
    return b"".join(chunks).decode("ascii", errors="replace")


def clean_raw(raw: str) -> str:
    return raw.replace(">", "").strip()


def send_elm(
    ser: serial.Serial,
    command: str,
    timeout: float,
    pause: float = 0.1,
    *,
    phase: str = "command",
    command_log: list[ElmCommandLogEntry] | None = None,
) -> str:
    ser.reset_input_buffer()
    ser.write((command + "\r").encode("ascii"))
    time.sleep(pause)
    raw = read_until_prompt(ser, timeout)
    if command_log is not None:
        command_log.append(
            ElmCommandLogEntry(
                order=len(command_log) + 1,
                phase=phase,
                command=command,
                raw=clean_raw(raw),
            )
        )
    return raw


def init_elm(
    ser: serial.Serial,
    timeout: float,
    *,
    command_log: list[ElmCommandLogEntry] | None = None,
) -> list[tuple[str, str]]:
    commands = ("ATZ", "ATE0", "ATL0", "ATS0", "ATH1", "ATCAF1", "ATV0", "ATAL", "ATSP6", "ATDP", "ATRV")
    output: list[tuple[str, str]] = []
    for command in commands:
        output.append((command, send_elm(ser, command, timeout, pause=0.25, phase="elm_init", command_log=command_log)))
    return output


def extract_frames(raw: str, response_header: HexString) -> list[HexString]:
    frames: list[HexString] = []
    for line in raw.replace(">", "").splitlines():
        compact = normalize_hex(line)
        if len(compact) < 6 or not HEX_RE.match(compact):
            continue
        if not compact.startswith(response_header):
            continue
        payload = compact[3:]
        if len(payload) % 2 == 0:
            frames.append(payload)
    return frames


def reassemble_isotp(frames: list[HexString]) -> HexString:
    if not frames:
        return ""
    first = bytes.fromhex(frames[0])
    pci = first[0]
    frame_type = pci >> 4
    if frame_type == 0:
        length = pci & 0x0F
        return first[1 : 1 + length].hex().upper()
    if frame_type != 1:
        return first[1:].hex().upper()

    total_length = ((pci & 0x0F) << 8) | first[1]
    data = bytearray(first[2:])
    for frame in frames[1:]:
        raw = bytes.fromhex(frame)
        if raw and raw[0] >> 4 == 2:
            data.extend(raw[1:])
    return bytes(data[:total_length]).hex().upper()


def classify(command: HexString, raw: str, payload: HexString) -> str:
    cleaned = raw.upper()
    if payload.startswith(positive_marker(command)):
        return "positive"
    if payload.startswith("7F"):
        return "negative"
    if "NO DATA" in cleaned or not payload:
        return "no_response"
    if "?" in cleaned or "ERROR" in cleaned:
        return "error"
    return "other"


def probe(
    ser: serial.Serial,
    request_header: HexString,
    command: HexString,
    timeout: float,
    *,
    command_log: list[ElmCommandLogEntry] | None = None,
) -> UdsReadResult:
    response_header = expected_response_header(request_header)
    send_elm(ser, f"ATSH{request_header}", timeout, phase="set_header", command_log=command_log)
    send_elm(ser, f"ATCRA{response_header}", timeout, phase="set_response_filter", command_log=command_log)
    raw = send_elm(ser, command, timeout, pause=0.25, phase="uds_read", command_log=command_log)
    frames = extract_frames(raw, response_header)
    payload = reassemble_isotp(frames)
    return UdsReadResult(
        request_header=request_header,
        response_header=response_header,
        command=command,
        status=classify(command, raw, payload),
        payload=payload,
        raw=clean_raw(raw),
    )


def write_outputs(
    results: list[UdsReadResult],
    command_log: list[ElmCommandLogEntry],
    output_dir: Path,
    run_id: str,
) -> tuple[Path, Path, Path, Path]:
    output_dir.mkdir(parents=True, exist_ok=True)
    text_path = output_dir / f"{run_id}_uds_header_scan.txt"
    json_path = output_dir / f"{run_id}_uds_header_scan.json"
    csv_path = output_dir / f"{run_id}_uds_header_scan.csv"
    command_json_path = output_dir / f"{run_id}_uds_header_scan_commands.json"

    lines = [
        "VAG UDS read-only header scan",
        f"Started: {datetime.now().isoformat(timespec='seconds')}",
        "Blocked services: 27, 2E, 31, 3B",
        f"ELM command/response entries: {len(command_log)}",
        f"UDS read results: {len(results)}",
        "",
        "ELM command log:",
    ]
    for entry in command_log:
        lines.append(f"{entry.order:04d} [{entry.phase}] >>> {entry.command}")
        lines.append(entry.raw or "<empty>")
        lines.append("")

    lines.append("UDS read results:")
    for result in results:
        lines.append(
            f"{result.request_header}->{result.response_header} {result.command}: {result.status} {result.payload or '<empty>'}"
        )
        if result.raw:
            lines.append(result.raw)
        lines.append("")

    text_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    json_path.write_text(json.dumps([asdict(result) for result in results], indent=2), encoding="utf-8")
    command_json_path.write_text(json.dumps([asdict(entry) for entry in command_log], indent=2), encoding="utf-8")
    with csv_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=tuple(UdsReadResult.__dataclass_fields__))
        writer.writeheader()
        for result in results:
            writer.writerow(asdict(result))
    return text_path, json_path, csv_path, command_json_path


def count_statuses(results: list[UdsReadResult]) -> dict[str, int]:
    counts: dict[str, int] = {}
    for result in results:
        counts[result.status] = counts.get(result.status, 0) + 1
    return counts


def render_status_counts(results: list[UdsReadResult]) -> str:
    counts = count_statuses(results)
    return ", ".join(f"{status}={count}" for status, count in sorted(counts.items())) or "none"


def print_probe_result(result: UdsReadResult) -> None:
    payload = f" {result.payload}" if result.payload else ""
    print(f"  {result.request_header}->{result.response_header} {result.command}: {result.status}{payload}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Read-only VAG UDS 11-bit CAN header discovery over an ELM327 adapter.")
    parser.add_argument("--port", default="COM10")
    parser.add_argument("--baud", type=int, default=38400)
    parser.add_argument("--timeout", type=float, default=1.4)
    parser.add_argument("--headers", type=parse_headers, default=DEFAULT_HEADERS)
    parser.add_argument("--discovery-commands", type=parse_csv_hex, default=DEFAULT_DISCOVERY_COMMANDS)
    parser.add_argument("--detail-commands", type=parse_csv_hex, default=DEFAULT_DETAIL_COMMANDS)
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--run-id", default=datetime.now().strftime("vag_uds_scan_%Y%m%d_%H%M%S"))
    parser.add_argument("--verbose", action="store_true", help="Print ELM init responses and responder details to the terminal.")
    args = parser.parse_args()

    results: list[UdsReadResult] = []
    command_log: list[ElmCommandLogEntry] = []
    responders: set[HexString] = set()
    print(f"Adapter: opening {args.port} at {args.baud} baud")
    with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
        print("Adapter: initializing ELM327")
        init_output = init_elm(ser, args.timeout, command_log=command_log)
        if args.verbose:
            for command, raw in init_output:
                print(f">>> {command}\n{clean_raw(raw)}\n")
        else:
            print(f"Adapter: ELM initialization complete ({len(init_output)} commands)")

        header_count = len(args.headers)
        print(f"Discovery: scanning {header_count} header(s) x {len(args.discovery_commands)} read command(s)")
        for header_index, header in enumerate(args.headers, start=1):
            if not args.verbose:
                print(f"Discovery: header {header_index}/{header_count} {header}")
            for command in args.discovery_commands:
                result = probe(ser, header, command, args.timeout, command_log=command_log)
                results.append(result)
                if result.status in {"positive", "negative", "other"}:
                    responders.add(header)
                    print_probe_result(result)

        print(f"Discovery: complete, {len(responders)} responder header(s)")
        detail_headers = sorted(responders)
        if detail_headers:
            print(f"Detail: reading {len(detail_headers)} responder header(s) x {len(args.detail_commands)} command(s)")
        for detail_index, header in enumerate(detail_headers, start=1):
            if not args.verbose:
                print(f"Detail: header {detail_index}/{len(detail_headers)} {header}")
            for command in args.detail_commands:
                if any(result.request_header == header and result.command == command for result in results):
                    continue
                result = probe(ser, header, command, args.timeout, command_log=command_log)
                results.append(result)
                if result.status in {"positive", "negative", "other"}:
                    print_probe_result(result)

    text_path, json_path, csv_path, command_json_path = write_outputs(results, command_log, args.output_dir, args.run_id)
    print(f"Done: {len(results)} UDS read result(s), {len(responders)} responder header(s); {render_status_counts(results)}")
    print(f"Full command log: {text_path}")
    print(f"Results JSON: {json_path}")
    print(f"Results CSV: {csv_path}")
    print(f"Command JSON: {command_json_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
