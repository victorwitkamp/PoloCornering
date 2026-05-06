from __future__ import annotations

import json
from collections import Counter
from pathlib import Path
from typing import Any


WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
LOG_DIR = WORKSPACE_ROOT / "obd-on-pc" / "logs"


def _summary_records() -> list[dict[str, Any]]:
    records: list[dict[str, Any]] = []
    for path in sorted(LOG_DIR.glob("*summary.json")):
        try:
            loaded = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue
        if not isinstance(loaded, list):
            continue
        for record in loaded:
            if isinstance(record, dict):
                record = dict(record)
                record["_summary_file"] = path.name
                records.append(record)
    return records


def _read_request_source(record: dict[str, Any]) -> str | None:
    counter = record.get("read_counter")
    command = record.get("read_command")
    if counter in (None, "") or not command:
        return None
    try:
        counter_int = int(str(counter), 16)
        payload = bytes.fromhex(str(command))
    except ValueError:
        return None
    return f"1{counter_int:X}{len(payload):04X}{str(command).upper()}"


def _reassemble_result(record: dict[str, Any]) -> tuple[str | None, tuple[int, ...], tuple[str, ...]]:
    source = _read_request_source(record)
    listen_header = record.get("listen_header") or "300"
    chunks: list[str] = []
    sequences: list[int] = []
    opcodes: list[str] = []
    for item in record.get("raw_payloads") or []:
        if not isinstance(item, dict):
            continue
        payload = str(item.get("payload") or "").strip().upper()
        if item.get("header") != listen_header or len(payload) < 2:
            continue
        if source is not None and item.get("source") != source:
            continue
        try:
            opcode = int(payload[:2], 16)
        except ValueError:
            continue
        opcode_high = opcode & 0xF0
        if opcode_high not in (0x00, 0x10, 0x20, 0x30):
            continue
        chunks.append(payload[2:])
        sequences.append(opcode & 0x0F)
        opcodes.append(payload[:2])

    joined = "".join(chunks)
    if len(joined) < 4:
        return None, tuple(sequences), tuple(opcodes)
    declared_length = int(joined[:4], 16) & 0x0FFF
    result = joined[4:4 + declared_length * 2]
    return result, tuple(sequences), tuple(opcodes)


def _outbound_ack_commands() -> Counter[str]:
    commands: Counter[str] = Counter()
    for path in sorted(LOG_DIR.glob("*.txt")):
        try:
            lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
        except OSError:
            continue
        for line in lines:
            marker = ">>> "
            if marker not in line:
                continue
            command = line.split(marker, 1)[1].split()[0].upper()
            if len(command) == 2 and command[0] == "B" and command[1] in "0123456789ABCDEF":
                commands[command] += 1
    return commands


def analyze() -> dict[str, Any]:
    records = _summary_records()
    positive_records = [record for record in records if record.get("read_status") == "positive"]

    command_counts: Counter[str] = Counter()
    sequence_patterns: Counter[tuple[int, ...]] = Counter()
    inbound_opcodes: Counter[str] = Counter()
    reassembly_matches = 0
    reassembly_mismatches: list[tuple[str, str, str | None, str | None, str | None]] = []
    inbound_ack_matches = 0
    inbound_ack_total = 0

    for record in positive_records:
        command_counts[str(record.get("read_command"))] += 1
        reassembled, sequences, _opcodes = _reassemble_result(record)
        if sequences:
            sequence_patterns[sequences] += 1
        if reassembled == record.get("read_result"):
            reassembly_matches += 1
        else:
            reassembly_mismatches.append(
                (
                    str(record.get("_summary_file")),
                    str(record.get("attempt_id")),
                    _read_request_source(record),
                    reassembled,
                    record.get("read_result"),
                )
            )

        expected_ack = None
        counter = record.get("read_counter")
        if counter not in (None, ""):
            try:
                expected_ack = f"B{(int(str(counter), 16) + 1) & 0x0F:X}"
            except ValueError:
                expected_ack = None
        for item in record.get("raw_payloads") or []:
            if not isinstance(item, dict):
                continue
            payload = str(item.get("payload") or "").strip().upper()
            if item.get("header") == (record.get("listen_header") or "300") and len(payload) >= 2:
                inbound_opcodes[payload[:2]] += 1
            if expected_ack and len(payload) == 2 and payload.startswith("B"):
                inbound_ack_total += 1
                if payload == expected_ack:
                    inbound_ack_matches += 1

    return {
        "summary_files": len(tuple(LOG_DIR.glob("*summary.json"))),
        "records": len(records),
        "positive_read_records": len(positive_records),
        "positive_command_counts": command_counts,
        "reassembly_matches": reassembly_matches,
        "reassembly_mismatches": reassembly_mismatches,
        "sequence_patterns": sequence_patterns,
        "inbound_ack_matches": inbound_ack_matches,
        "inbound_ack_total": inbound_ack_total,
        "inbound_opcodes": inbound_opcodes,
        "outbound_ack_commands": _outbound_ack_commands(),
    }


def _format_counter(counter: Counter[Any], limit: int = 12) -> str:
    return ", ".join(f"{key}:{value}" for key, value in counter.most_common(limit)) or "none"


def main() -> int:
    result = analyze()
    positive_total = result["positive_read_records"]
    print("Carista VagCanCommunicator::readResponses offline evidence")
    print(f"summary files: {result['summary_files']}")
    print(f"records: {result['records']}")
    print(f"positive read records: {positive_total}")
    print(f"positive reassembly matches: {result['reassembly_matches']}/{positive_total}")
    print(f"inbound transmit ACK matches: {result['inbound_ack_matches']}/{result['inbound_ack_total']}")
    print(f"positive commands: {_format_counter(result['positive_command_counts'])}")
    print(f"response sequence patterns: {_format_counter(result['sequence_patterns'])}")
    print(f"inbound opcodes: {_format_counter(result['inbound_opcodes'])}")
    print(f"outbound ACK commands in text logs: {_format_counter(result['outbound_ack_commands'])}")
    mismatches = result["reassembly_mismatches"]
    if mismatches:
        print("mismatches:")
        for summary_file, attempt_id, source, reassembled, expected in mismatches[:10]:
            print(f"  {summary_file} {attempt_id} source={source} reassembled={reassembled} expected={expected}")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())