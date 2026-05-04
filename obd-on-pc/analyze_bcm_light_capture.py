from __future__ import annotations

import argparse
import csv
import json
from collections import Counter, defaultdict
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable

from dbc_signal_decoder import DEFAULT_VW_PQ_DBC, DbcDatabase
from pq25_can_reference import decoded_summary, message_name, message_relevance, message_signal_names, normalize_can_header


@dataclass(frozen=True)
class CaptureRow:
    source: Path
    state: str
    repeat: int
    command: str
    status: str
    payload: str
    label: str


@dataclass(frozen=True)
class RawFrameRow:
    source: Path
    state: str
    repeat: int
    header: str
    payload: str
    timestamp: str


DIAGNOSTIC_STATUS_FIELDS = [
    "source",
    "command",
    "label",
    "state",
    "status",
    "payload_bytes",
    "observations",
    "payload",
]

DIAGNOSTIC_DELTA_FIELDS = [
    "source",
    "command",
    "label",
    "baseline_state",
    "state",
    "repeat",
    "status",
    "baseline_status",
    "byte_index",
    "baseline_byte",
    "state_byte",
    "bit_deltas",
    "baseline_payload",
    "state_payload",
]

REPEAT_INSTABILITY_FIELDS = ["command", "state", "variants", "observations", "payloads"]
RAW_HEADER_FIELDS = [
    "header",
    "known_message",
    "message_relevance",
    "signal_names",
    "total_frames",
    "states_seen",
    "state_counts",
    "unique_payloads",
    "top_payloads",
    "decoded_top_payloads",
]
RAW_STATE_SPECIFIC_FIELDS = [
    "header",
    "known_message",
    "payload",
    "decoded_signals",
    "total_frames",
    "states_seen",
    "state_counts",
]
RAW_SIGNAL_DELTA_FIELDS = [
    "header",
    "message",
    "signal",
    "unit",
    "baseline_state",
    "baseline_value",
    "state",
    "top_value",
    "observations",
    "variants",
    "all_values",
    "changed_from_baseline",
]


def clean_hex(value: object) -> str:
    return str(value or "").strip().replace(" ", "").upper()


def payload_byte_count(payload: str) -> str:
    payload = clean_hex(payload)
    if not payload or len(payload) % 2:
        return ""
    return str(len(payload) // 2)


def load_capture(path: Path) -> tuple[list[CaptureRow], list[RawFrameRow]]:
    payload = json.loads(path.read_text(encoding="utf-8"))
    captures: list[CaptureRow] = []
    raw_frames: list[RawFrameRow] = []

    for row in payload.get("captures", []):
        if not isinstance(row, dict):
            continue
        captures.append(
            CaptureRow(
                source=path,
                state=str(row.get("state", "")),
                repeat=int(row.get("repeat") or 0),
                command=clean_hex(row.get("command")),
                status=str(row.get("status", "")),
                payload=clean_hex(row.get("payload")),
                label=str(row.get("command_label", "")),
            )
        )

    for row in payload.get("raw_can_frames", []):
        if not isinstance(row, dict):
            continue
        raw_frames.append(
            RawFrameRow(
                source=path,
                state=str(row.get("state", "")),
                repeat=int(row.get("repeat") or 0),
                header=normalize_can_header(row.get("header")),
                payload=clean_hex(row.get("payload")),
                timestamp=str(row.get("timestamp", "")),
            )
        )
    return captures, raw_frames


def byte_deltas(base: str, current: str) -> list[tuple[int, str, str, list[str]]]:
    if not base or not current or len(base) % 2 or len(current) % 2:
        return []
    base_bytes = bytes.fromhex(base)
    current_bytes = bytes.fromhex(current)
    rows: list[tuple[int, str, str, list[str]]] = []
    for index in range(max(len(base_bytes), len(current_bytes))):
        old_int = base_bytes[index] if index < len(base_bytes) else None
        new_int = current_bytes[index] if index < len(current_bytes) else None
        old_hex = f"{old_int:02X}" if old_int is not None else "--"
        new_hex = f"{new_int:02X}" if new_int is not None else "--"
        if old_hex == new_hex:
            continue
        bit_notes: list[str] = []
        if old_int is not None and new_int is not None:
            changed = old_int ^ new_int
            for bit in range(8):
                if changed & (1 << bit):
                    bit_notes.append(f"b{bit}:{(old_int >> bit) & 1}->{(new_int >> bit) & 1}")
        rows.append((index, old_hex, new_hex, bit_notes))
    return rows


def group_captures(rows: Iterable[CaptureRow]) -> dict[str, list[CaptureRow]]:
    grouped: dict[str, list[CaptureRow]] = defaultdict(list)
    for row in rows:
        if row.command and not row.command.startswith("<"):
            grouped[row.command].append(row)
    return dict(sorted(grouped.items()))


def diagnostic_status_rows(captures: list[CaptureRow]) -> list[dict[str, object]]:
    grouped: Counter[tuple[str, str, str, str, str, str, str]] = Counter()
    for row in captures:
        if not row.command or row.command.startswith("<"):
            continue
        grouped[(str(row.source), row.command, row.label, row.state, row.status, payload_byte_count(row.payload), row.payload)] += 1

    out: list[dict[str, object]] = []
    for (source, command, label, state, status, payload_bytes, payload), count in sorted(grouped.items()):
        out.append(
            {
                "source": source,
                "command": command,
                "label": label,
                "state": state,
                "status": status,
                "payload_bytes": payload_bytes,
                "observations": count,
                "payload": payload,
            }
        )
    return out


def baseline_for(rows: list[CaptureRow], baseline_state: str | None) -> CaptureRow | None:
    candidates = [row for row in rows if row.payload]
    if baseline_state:
        for row in candidates:
            if row.state == baseline_state:
                return row
    return candidates[0] if candidates else None


def diagnostic_delta_rows(captures: list[CaptureRow], baseline_state: str | None) -> list[dict[str, object]]:
    out: list[dict[str, object]] = []
    for command, rows in group_captures(captures).items():
        baseline = baseline_for(rows, baseline_state)
        if baseline is None:
            continue
        for row in rows:
            if row is baseline or not row.payload:
                continue
            if row.status == baseline.status and row.payload == baseline.payload:
                continue
            deltas = byte_deltas(baseline.payload, row.payload)
            if deltas:
                for byte_index, old_hex, new_hex, bit_notes in deltas:
                    out.append(
                        {
                            "source": str(row.source),
                            "command": command,
                            "label": row.label,
                            "baseline_state": baseline.state,
                            "state": row.state,
                            "repeat": row.repeat,
                            "status": row.status,
                            "baseline_status": baseline.status,
                            "byte_index": byte_index,
                            "baseline_byte": old_hex,
                            "state_byte": new_hex,
                            "bit_deltas": ",".join(bit_notes),
                            "baseline_payload": baseline.payload,
                            "state_payload": row.payload,
                        }
                    )
            else:
                out.append(
                    {
                        "source": str(row.source),
                        "command": command,
                        "label": row.label,
                        "baseline_state": baseline.state,
                        "state": row.state,
                        "repeat": row.repeat,
                        "status": row.status,
                        "baseline_status": baseline.status,
                        "byte_index": "",
                        "baseline_byte": "",
                        "state_byte": "",
                        "bit_deltas": "payload/status changed",
                        "baseline_payload": baseline.payload,
                        "state_payload": row.payload,
                    }
                )
    return out


def instability_rows(captures: list[CaptureRow]) -> list[dict[str, object]]:
    grouped: dict[tuple[str, str], list[CaptureRow]] = defaultdict(list)
    for row in captures:
        if not row.command or row.command.startswith("<"):
            continue
        grouped[(row.command, row.state)].append(row)

    out: list[dict[str, object]] = []
    for (command, state), rows in sorted(grouped.items()):
        payloads = Counter((row.status, row.payload) for row in rows)
        if len(payloads) <= 1:
            continue
        out.append(
            {
                "command": command,
                "state": state,
                "variants": len(payloads),
                "observations": sum(payloads.values()),
                "payloads": "; ".join(f"{status}:{payload} x{count}" for (status, payload), count in payloads.items()),
            }
        )
    return out


def combined_message_name(header: str, dbc: DbcDatabase | None = None) -> str:
    return message_name(header) or (dbc.message_name(header) if dbc else "")


def combined_signal_names(header: str, dbc: DbcDatabase | None = None) -> str:
    return message_signal_names(header) or (dbc.signal_names(header) if dbc else "")


def combined_decoded_summary(header: str, payload: str, dbc: DbcDatabase | None = None, limit: int = 16) -> str:
    summary = decoded_summary(header, payload)
    if summary:
        return summary
    if dbc:
        return dbc.decoded_summary(header, payload, limit=limit)
    return ""


def raw_header_rows(raw_frames: list[RawFrameRow], dbc: DbcDatabase | None = None) -> list[dict[str, object]]:
    grouped: dict[str, list[RawFrameRow]] = defaultdict(list)
    for frame in raw_frames:
        if frame.header:
            grouped[frame.header].append(frame)

    out: list[dict[str, object]] = []
    for header, frames in sorted(grouped.items()):
        by_state = Counter(frame.state for frame in frames)
        payloads = Counter(frame.payload for frame in frames)
        top_payloads = payloads.most_common(8)
        decoded_top_payloads = []
        for payload, count in top_payloads:
            decoded = combined_decoded_summary(header, payload, dbc)
            if decoded:
                decoded_top_payloads.append(f"{payload}: {decoded} x{count}")
        out.append(
            {
                "header": header,
                "known_message": combined_message_name(header, dbc),
                "message_relevance": message_relevance(header),
                "signal_names": combined_signal_names(header, dbc),
                "total_frames": len(frames),
                "states_seen": len(by_state),
                "state_counts": "; ".join(f"{state}:{count}" for state, count in sorted(by_state.items())),
                "unique_payloads": len(payloads),
                "top_payloads": "; ".join(f"{payload} x{count}" for payload, count in top_payloads),
                "decoded_top_payloads": "; ".join(decoded_top_payloads),
            }
        )
    return sorted(out, key=lambda row: (-int(row["states_seen"]), -int(row["unique_payloads"]), str(row["header"])))


def raw_state_specific_rows(raw_frames: list[RawFrameRow], dbc: DbcDatabase | None = None) -> list[dict[str, object]]:
    state_count = len({frame.state for frame in raw_frames})
    grouped: dict[tuple[str, str], list[RawFrameRow]] = defaultdict(list)
    for frame in raw_frames:
        grouped[(frame.header, frame.payload)].append(frame)

    out: list[dict[str, object]] = []
    for (header, payload), frames in sorted(grouped.items()):
        by_state = Counter(frame.state for frame in frames)
        if state_count and len(by_state) == state_count:
            continue
        out.append(
            {
                "header": header,
                "known_message": combined_message_name(header, dbc),
                "payload": payload,
                "decoded_signals": combined_decoded_summary(header, payload, dbc),
                "total_frames": len(frames),
                "states_seen": len(by_state),
                "state_counts": "; ".join(f"{state}:{count}" for state, count in sorted(by_state.items())),
            }
        )
    return sorted(out, key=lambda row: (int(row["states_seen"]), -int(row["total_frames"]), str(row["header"])))


def top_counter_value(counter: Counter[str]) -> str:
    if not counter:
        return ""
    return counter.most_common(1)[0][0]


def raw_signal_delta_rows(
    raw_frames: list[RawFrameRow],
    dbc: DbcDatabase | None,
    baseline_state: str | None,
) -> list[dict[str, object]]:
    if dbc is None:
        return []

    state_order: list[str] = []
    grouped: dict[tuple[str, str, str, str], dict[str, Counter[str]]] = defaultdict(lambda: defaultdict(Counter))
    for frame in raw_frames:
        if frame.state not in state_order:
            state_order.append(frame.state)
        message = dbc.message(frame.header)
        if message is None:
            continue
        decoded = message.decode(frame.payload)
        if not decoded:
            continue
        for signal_name, signal in decoded.items():
            key = (frame.header, message.name, signal_name, signal.unit)
            grouped[key][frame.state][signal.text] += 1

    out: list[dict[str, object]] = []
    for (header, message, signal_name, unit), by_state in sorted(grouped.items()):
        candidate_baseline = baseline_state if baseline_state in by_state else next(
            (state for state in state_order if state in by_state),
            "",
        )
        baseline_value = top_counter_value(by_state.get(candidate_baseline, Counter()))
        if not baseline_value:
            continue

        state_top_values = {state: top_counter_value(counter) for state, counter in by_state.items()}
        changed = any(value != baseline_value for value in state_top_values.values())
        unstable = any(len(counter) > 1 for counter in by_state.values())
        if not changed and not unstable:
            continue

        for state in state_order:
            counter = by_state.get(state)
            if not counter:
                continue
            top_value = top_counter_value(counter)
            is_changed = top_value != baseline_value
            is_unstable = len(counter) > 1
            if not is_changed and not is_unstable:
                continue
            notes = []
            if is_changed:
                notes.append("yes")
            if is_unstable:
                notes.append("unstable")
            out.append(
                {
                    "header": header,
                    "message": message,
                    "signal": signal_name,
                    "unit": unit,
                    "baseline_state": candidate_baseline,
                    "baseline_value": baseline_value,
                    "state": state,
                    "top_value": top_value,
                    "observations": sum(counter.values()),
                    "variants": len(counter),
                    "all_values": "; ".join(f"{value} x{count}" for value, count in counter.most_common()),
                    "changed_from_baseline": ",".join(notes),
                }
            )
    return out


def write_csv(path: Path, rows: list[dict[str, object]], fieldnames: list[str]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


def markdown_table(rows: list[dict[str, object]], fields: list[str], limit: int = 40) -> list[str]:
    if not rows:
        return ["No rows."]
    lines = ["| " + " | ".join(fields) + " |", "|" + "|".join("---" for _ in fields) + "|"]
    for row in rows[:limit]:
        values = [str(row.get(field, "")).replace("|", "\\|") for field in fields]
        lines.append("| " + " | ".join(values) + " |")
    if len(rows) > limit:
        filler = " | ".join("" for _ in fields[2:])
        lines.append(f"| ... | {len(rows) - limit} more rows | {filler} |")
    return lines


def render_report(
    sources: list[Path],
    dbc_source: str,
    diagnostic_status: list[dict[str, object]],
    diagnostic_rows: list[dict[str, object]],
    unstable_rows: list[dict[str, object]],
    raw_headers: list[dict[str, object]],
    raw_specific: list[dict[str, object]],
    raw_signal_deltas: list[dict[str, object]],
) -> str:
    lines = [
        "# BCM Light Capture Analysis",
        "",
        "Sources:",
        "",
        *[f"- `{path}`" for path in sources],
        "",
        f"DBC signal reference: `{dbc_source or 'not used'}`",
        "",
        "## Diagnostic Status Summary",
        "",
        *markdown_table(
            diagnostic_status,
            ["command", "state", "status", "payload_bytes", "observations", "payload"],
            limit=80,
        ),
        "",
        "## Diagnostic Read Deltas",
        "",
        *markdown_table(
            diagnostic_rows,
            ["command", "baseline_state", "state", "repeat", "byte_index", "baseline_byte", "state_byte", "bit_deltas"],
            limit=80,
        ),
        "",
        "## Repeat Instability",
        "",
        *markdown_table(unstable_rows, ["command", "state", "variants", "observations", "payloads"], limit=40),
        "",
        "## Raw CAN Headers",
        "",
        *markdown_table(
            raw_headers,
            ["header", "known_message", "total_frames", "states_seen", "unique_payloads", "decoded_top_payloads"],
            limit=60,
        ),
        "",
        "## State-Specific Raw CAN Payloads",
        "",
        *markdown_table(
            raw_specific,
            ["header", "known_message", "payload", "decoded_signals", "total_frames", "states_seen", "state_counts"],
            limit=80,
        ),
        "",
        "## Raw CAN Signal Deltas",
        "",
        *markdown_table(
            raw_signal_deltas,
            ["header", "message", "signal", "baseline_state", "baseline_value", "state", "top_value", "changed_from_baseline"],
            limit=120,
        ),
        "",
        "## Reading This",
        "",
        "- Diagnostic deltas are the strongest clues because they are request/response scoped to the BCM TP2.0 channel.",
        "- Repeat instability means the same state did not reproduce cleanly; repeat before treating it as a lamp clue.",
        "- Raw CAN rows are weaker because ELM monitor-all can drop frames, but state-specific payloads are good targets for repeated captures.",
        "",
    ]
    return "\n".join(lines)


def analyze(args: argparse.Namespace) -> dict[str, Path]:
    captures: list[CaptureRow] = []
    raw_frames: list[RawFrameRow] = []
    for path in args.inputs:
        loaded_captures, loaded_raw_frames = load_capture(path)
        captures.extend(loaded_captures)
        raw_frames.extend(loaded_raw_frames)

    dbc: DbcDatabase | None = None
    dbc_source = ""
    if not args.no_dbc:
        dbc_path = Path(args.dbc_path)
        if dbc_path.exists():
            dbc = DbcDatabase.from_file(dbc_path)
            dbc_source = str(dbc_path)

    diagnostic_status = diagnostic_status_rows(captures)
    diagnostic_rows = diagnostic_delta_rows(captures, args.baseline_state)
    unstable_rows = instability_rows(captures)
    raw_headers = raw_header_rows(raw_frames, dbc)
    raw_specific = raw_state_specific_rows(raw_frames, dbc)
    raw_signal_deltas = raw_signal_delta_rows(raw_frames, dbc, args.baseline_state)

    args.output_dir.mkdir(parents=True, exist_ok=True)
    prefix = args.output_dir / args.output_prefix
    paths = {
        "report": prefix.with_name(prefix.name + "_analysis.md"),
        "diagnostic_status": prefix.with_name(prefix.name + "_diagnostic_status.csv"),
        "diagnostic_deltas": prefix.with_name(prefix.name + "_diagnostic_deltas.csv"),
        "repeat_instability": prefix.with_name(prefix.name + "_repeat_instability.csv"),
        "raw_headers": prefix.with_name(prefix.name + "_raw_headers.csv"),
        "raw_state_specific": prefix.with_name(prefix.name + "_raw_state_specific.csv"),
        "raw_signal_deltas": prefix.with_name(prefix.name + "_raw_signal_deltas.csv"),
    }
    write_csv(paths["diagnostic_status"], diagnostic_status, DIAGNOSTIC_STATUS_FIELDS)
    write_csv(paths["diagnostic_deltas"], diagnostic_rows, DIAGNOSTIC_DELTA_FIELDS)
    write_csv(paths["repeat_instability"], unstable_rows, REPEAT_INSTABILITY_FIELDS)
    write_csv(paths["raw_headers"], raw_headers, RAW_HEADER_FIELDS)
    write_csv(paths["raw_state_specific"], raw_specific, RAW_STATE_SPECIFIC_FIELDS)
    write_csv(paths["raw_signal_deltas"], raw_signal_deltas, RAW_SIGNAL_DELTA_FIELDS)
    paths["report"].write_text(
        render_report(
            args.inputs,
            dbc_source,
            diagnostic_status,
            diagnostic_rows,
            unstable_rows,
            raw_headers,
            raw_specific,
            raw_signal_deltas,
        ),
        encoding="utf-8",
    )
    return paths


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Analyze BCM light-state capture JSON files.")
    parser.add_argument("inputs", nargs="+", type=Path, help="*_bcm_light_capture.json files")
    parser.add_argument("--baseline-state", default="baseline_off")
    parser.add_argument("--dbc-path", type=Path, default=DEFAULT_VW_PQ_DBC, help="DBC used for raw CAN signal decoding.")
    parser.add_argument("--no-dbc", action="store_true", help="Disable DBC-backed raw CAN signal decoding.")
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--output-prefix", default="bcm_light_capture")
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()
    missing = [path for path in args.inputs if not path.exists()]
    if missing:
        parser.error("missing input file(s): " + ", ".join(str(path) for path in missing))
    paths = analyze(args)
    print("Analysis outputs:")
    for label, path in paths.items():
        print(f"  {label}: {path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
