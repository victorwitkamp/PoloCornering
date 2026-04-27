from __future__ import annotations

import argparse
import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any


EVENT_TYPES = {
    "change_setting_java",
    "change_setting_native",
    "get_setting_raw_address",
    "write_vag_coding_ctor",
}

CORNERING_TERMS = (
    "corner",
    "fog",
    "turn_signal",
    "turn signal",
    "cornering",
    "drl",
)


@dataclass
class CandidateRecord:
    name: str
    entries: list[dict[str, Any]]


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Summarize a Carista Frida JSONL trace and extract candidate cornering-setting write tuples."
        )
    )
    parser.add_argument("trace_file", type=Path, help="JSONL output file from run_carista_cornering_trace.py --out")
    parser.add_argument(
        "--all",
        action="store_true",
        help="Show all setting groups, not only cornering/fog/turn-related candidates.",
    )
    parser.add_argument(
        "--output",
        type=Path,
        help="Optional text report path.",
    )
    return parser


def load_events(path: Path) -> list[dict[str, Any]]:
    events: list[dict[str, Any]] = []
    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line:
            continue
        try:
            payload = json.loads(line)
        except json.JSONDecodeError:
            continue
        if not isinstance(payload, dict):
            continue
        if payload.get("type") in EVENT_TYPES:
            events.append(payload)
    return events


def setting_name(setting: dict[str, Any] | None) -> str:
    if not setting:
        return "<unknown-setting>"
    for key in ("name_res_id", "event_string", "instruction", "native_id_hex"):
        value = setting.get(key)
        if value:
            return str(value)
    return "<unknown-setting>"


def is_cornering_candidate(name: str) -> bool:
    lowered = name.lower()
    return any(term in lowered for term in CORNERING_TERMS)


def gather_candidates(events: list[dict[str, Any]]) -> dict[str, CandidateRecord]:
    records: dict[str, CandidateRecord] = {}
    for event in events:
        setting = event.get("setting")
        if not isinstance(setting, dict):
            continue
        name = setting_name(setting)
        record = records.setdefault(name, CandidateRecord(name=name, entries=[]))
        record.entries.append(event)
    return records


def format_setting_block(record: CandidateRecord) -> list[str]:
    lines = [record.name]
    java_events = [event for event in record.entries if event.get("type") == "change_setting_java"]
    native_events = [event for event in record.entries if event.get("type") == "change_setting_native"]
    raw_events = [event for event in record.entries if event.get("type") == "get_setting_raw_address"]
    ctor_events = [event for event in record.entries if event.get("type") == "write_vag_coding_ctor"]

    if java_events:
        latest_java = java_events[-1]["setting"]
        lines.append(f"  nativeId:     {latest_java.get('native_id_hex') or latest_java.get('native_id') or '<unknown>'}")
        lines.append(f"  eventString:  {latest_java.get('event_string') or '<none>'}")
        lines.append(f"  instruction:  {latest_java.get('instruction') or '<none>'}")
        lines.append(f"  currentValue: {latest_java.get('current_value_hex') or '<unknown>'}")
        lines.append(f"  requested:    {latest_java.get('requested_value_hex') or '<unknown>'}")
        lines.append(f"  interpretation: {latest_java.get('interpretation') or latest_java.get('interpretation_class') or '<unknown>'}")

    if native_events:
        latest_native = native_events[-1]
        value = latest_native.get("value") or {}
        lines.append(f"  nativeSettingPtr: {latest_native.get('setting_ptr') or '<unknown>'}")
        lines.append(f"  insertValue bytes: {value.get('hex') or '<unknown>'}")

    if raw_events:
        latest_raw = raw_events[-1]
        lines.append(f"  rawKey:       {latest_raw.get('raw_key_u64') or '<unknown>'}")
        lines.append(
            f"  rawKey split: {latest_raw.get('raw_key_high32') or '<unknown>'} {latest_raw.get('raw_key_low32') or '<unknown>'}"
        )

    if ctor_events:
        latest_ctor = ctor_events[-1]
        ctor_value = latest_ctor.get("ctor_value") or {}
        raw_address = latest_ctor.get("raw_address") or {}
        trailing = latest_ctor.get("trailing_vector") or {}
        raw_vector = raw_address.get("vector") or {}
        trailing_vector = trailing.get("vector") or {}
        lines.append(f"  codingType:   {latest_ctor.get('coding_type')}")
        lines.append(f"  ctor value:   {ctor_value.get('hex') or '<unknown>'}")
        lines.append(f"  raw address:  {raw_vector.get('hex') or '<unknown>'}")
        lines.append(f"  tail bytes:   {trailing_vector.get('hex') or '<none>'}")

    lines.append(f"  event count:  {len(record.entries)}")
    return lines


def build_report(events: list[dict[str, Any]], include_all: bool) -> str:
    candidates = gather_candidates(events)
    ordered = sorted(candidates.values(), key=lambda item: item.name.lower())
    if not include_all:
        ordered = [record for record in ordered if is_cornering_candidate(record.name)]

    lines = [
        "Carista cornering trace summary",
        "",
        f"Events parsed: {len(events)}",
        f"Setting groups: {len(candidates)}",
        f"Displayed groups: {len(ordered)}",
        "",
        "Priority result:",
        "  The next real write tuple is whichever displayed setting shows all of these together:",
        "  requested value, raw key, WriteVagCodingCommand ctor value, 4-byte raw address, and coding type/tail.",
        "",
    ]

    if not ordered:
        lines.extend(
            [
                "No cornering/fog/turn-related settings were detected in this trace.",
                "Use --all to inspect every captured setting group.",
            ]
        )
        return "\n".join(lines)

    for record in ordered:
        lines.extend(format_setting_block(record))
        lines.append("")

    return "\n".join(lines).rstrip() + "\n"


def main() -> int:
    args = build_parser().parse_args()
    events = load_events(args.trace_file)
    report = build_report(events, include_all=args.all)
    print(report, end="")
    if args.output:
        args.output.write_text(report, encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())