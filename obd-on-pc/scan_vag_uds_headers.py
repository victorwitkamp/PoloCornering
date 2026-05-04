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


def send_elm(ser: serial.Serial, command: str, timeout: float, pause: float = 0.1) -> str:
    ser.reset_input_buffer()
    ser.write((command + "\r").encode("ascii"))
    time.sleep(pause)
    return read_until_prompt(ser, timeout)


def init_elm(ser: serial.Serial, timeout: float) -> list[tuple[str, str]]:
    commands = ("ATZ", "ATE0", "ATL0", "ATS0", "ATH1", "ATCAF1", "ATV0", "ATAL", "ATSP6", "ATDP", "ATRV")
    output: list[tuple[str, str]] = []
    for command in commands:
        output.append((command, send_elm(ser, command, timeout, pause=0.25)))
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
) -> UdsReadResult:
    response_header = expected_response_header(request_header)
    send_elm(ser, f"ATSH{request_header}", timeout)
    send_elm(ser, f"ATCRA{response_header}", timeout)
    raw = send_elm(ser, command, timeout, pause=0.25)
    frames = extract_frames(raw, response_header)
    payload = reassemble_isotp(frames)
    return UdsReadResult(
        request_header=request_header,
        response_header=response_header,
        command=command,
        status=classify(command, raw, payload),
        payload=payload,
        raw=raw.replace(">", "").strip(),
    )


def write_outputs(results: list[UdsReadResult], output_dir: Path, run_id: str) -> tuple[Path, Path, Path]:
    output_dir.mkdir(parents=True, exist_ok=True)
    text_path = output_dir / f"{run_id}_uds_header_scan.txt"
    json_path = output_dir / f"{run_id}_uds_header_scan.json"
    csv_path = output_dir / f"{run_id}_uds_header_scan.csv"

    lines = [
        "VAG UDS read-only header scan",
        f"Started: {datetime.now().isoformat(timespec='seconds')}",
        "Blocked services: 27, 2E, 31, 3B",
        "",
    ]
    for result in results:
        if result.status in {"positive", "negative", "other"}:
            lines.append(
                f"{result.request_header}->{result.response_header} {result.command}: {result.status} {result.payload}"
            )
            if result.raw:
                lines.append(result.raw)
                lines.append("")

    text_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    json_path.write_text(json.dumps([asdict(result) for result in results], indent=2), encoding="utf-8")
    with csv_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=tuple(UdsReadResult.__dataclass_fields__))
        writer.writeheader()
        for result in results:
            writer.writerow(asdict(result))
    return text_path, json_path, csv_path


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
    args = parser.parse_args()

    results: list[UdsReadResult] = []
    responders: set[HexString] = set()
    with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
        for command, raw in init_elm(ser, args.timeout):
            print(f">>> {command}\n{raw.replace('>', '').strip()}\n")

        for header in args.headers:
            for command in args.discovery_commands:
                result = probe(ser, header, command, args.timeout)
                results.append(result)
                if result.status in {"positive", "negative", "other"}:
                    responders.add(header)
                    print(f"{header}->{result.response_header} {command}: {result.status} {result.payload}")

        for header in sorted(responders):
            for command in args.detail_commands:
                if any(result.request_header == header and result.command == command for result in results):
                    continue
                result = probe(ser, header, command, args.timeout)
                results.append(result)
                if result.status in {"positive", "negative", "other"}:
                    print(f"{header}->{result.response_header} {command}: {result.status} {result.payload}")

    text_path, json_path, csv_path = write_outputs(results, args.output_dir, args.run_id)
    print(f"Wrote log: {text_path}")
    print(f"Wrote JSON: {json_path}")
    print(f"Wrote CSV: {csv_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
