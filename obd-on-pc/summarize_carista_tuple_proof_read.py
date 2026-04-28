from __future__ import annotations

import argparse
import json
import sys
from dataclasses import asdict, dataclass
from pathlib import Path

WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
if str(WORKSPACE_ROOT) not in sys.path:
    sys.path.insert(0, str(WORKSPACE_ROOT))

from CaristaReproduction.ByteUtils import normalize_hex
from CaristaReproduction.Commands.GetVagCanEcuInfoCommand import GetVagCanEcuInfoCommand_processEcuInfo
from CaristaReproduction.Commands.WriteVagCodingCommand import WriteVagCodingCommand_getRequest
from CaristaReproduction.Constants import CORNERING_FIXES
from CaristaReproduction.JsonUtils import json_objects_from_text
from CaristaReproduction.Models.VagEcuInfoWithCoding import VagEcuInfoWithCoding
from CaristaReproduction.Types import JsonObject
from CaristaReproduction.VagCoding import normalize_coding
from CaristaReproduction.VagOperationDelegate import VagOperationDelegate_writeVagCanCodingValue


@dataclass(frozen=True)
class ProofAttempt:
    source_file: str
    attempt_id: str
    mode: str
    session_command: str
    session_counter: str
    pre_read_sequence: str
    ack_variant: str
    delay_ms: str
    read_counter: str
    read_status: str
    read_result: str


@dataclass(frozen=True)
class ChunkMatch:
    chunk_index: int
    byte_start: int
    byte_end: int
    value6: str


@dataclass(frozen=True)
class TupleDryRun:
    label: str
    description: str
    value6: str
    raw_address4: str
    coding_type: int
    tail: str
    request: str
    composer_command: str


def load_rows(paths: list[Path]) -> list[tuple[Path, JsonObject]]:
    rows: list[tuple[Path, JsonObject]] = []
    for path in paths:
        for entry in json_objects_from_text(path.read_text(encoding="utf-8")):
            rows.append((path, entry))
    return rows


def find_fresh_coding(rows: list[tuple[Path, JsonObject]]) -> str | None:
    for _path, row in rows:
        if row.get("read_command") != "220600":
            continue
        read_result = row.get("read_result")
        if isinstance(read_result, str) and normalize_hex(read_result).startswith("620600"):
            return normalize_coding(read_result)
    return None


def apply_bit(value: int, bit_index: int) -> int:
    return value | (1 << bit_index)


def derive_target_value6(coding: str, byte_index: int, bit_index: int, chunk_size: int = 6) -> str:
    data = bytearray.fromhex(coding)
    if byte_index >= len(data):
        raise ValueError(f"byte index {byte_index} is outside {len(data)} coding bytes")
    data[byte_index] = apply_bit(data[byte_index], bit_index)
    chunk_index = byte_index // chunk_size
    byte_start = chunk_index * chunk_size
    return data[byte_start:byte_start + chunk_size].hex().upper()


def find_chunk_matches(coding: str, value6: str, chunk_size: int = 6) -> list[ChunkMatch]:
    chunks: list[ChunkMatch] = []
    data = bytes.fromhex(coding)
    for index in range(0, len(data), chunk_size):
        chunk = data[index:index + chunk_size]
        if len(chunk) == chunk_size and chunk.hex().upper() == value6:
            chunks.append(
                ChunkMatch(
                    chunk_index=index // chunk_size,
                    byte_start=index,
                    byte_end=index + chunk_size - 1,
                    value6=value6,
                )
            )
    return chunks


def collect_attempts(rows: list[tuple[Path, JsonObject]]) -> list[ProofAttempt]:
    attempts: list[ProofAttempt] = []
    for path, row in rows:
        if row.get("read_command") != "1A9B":
            continue
        read_result = row.get("read_result")
        attempts.append(
            ProofAttempt(
                source_file=str(path),
                attempt_id=str(row.get("attempt_id", "")),
                mode=str(row.get("mode", "")),
                session_command=str(row.get("session_command", "")),
                session_counter=str(row.get("session_counter", "")),
                pre_read_sequence=str(row.get("pre_read_sequence", "")),
                ack_variant=str(row.get("ack_variant", "")),
                delay_ms=str(row.get("delay_ms", "")),
                read_counter=str(row.get("read_counter", "")),
                read_status=str(row.get("read_status", "")),
                read_result=normalize_hex(read_result) if isinstance(read_result, str) else "",
            )
        )
    return attempts


def build_tuple_dry_runs(metadata: VagEcuInfoWithCoding, coding: str, baseline_summary: Path | None) -> list[TupleDryRun]:
    dry_runs: list[TupleDryRun] = []
    coding_arg = str(baseline_summary) if baseline_summary else "<fresh-220600-summary.json>"
    for label, (byte_index, bit_index, description) in CORNERING_FIXES.items():
        value6 = derive_target_value6(coding, byte_index, bit_index)
        command_object = VagOperationDelegate_writeVagCanCodingValue(metadata, value6)
        request = WriteVagCodingCommand_getRequest(command_object)
        command = (
            f"python .\\compose_carista_3b9a_tuple.py --coding-file {coding_arg} "
            f"--cornering-fix {label} --raw-address4 {metadata.raw_address4} "
            f"--coding-type {command_object.coding_type}"
        )
        if command_object.tail:
            command += f" --tail {command_object.tail}"
        dry_runs.append(
            TupleDryRun(
                label=label,
                description=description,
                value6=value6,
                raw_address4=metadata.raw_address4,
                coding_type=command_object.coding_type,
                tail=command_object.tail,
                request=request,
                composer_command=command,
            )
        )
    return dry_runs


def first_positive_metadata(attempts: list[ProofAttempt]) -> tuple[ProofAttempt, VagEcuInfoWithCoding] | None:
    for attempt in attempts:
        metadata = GetVagCanEcuInfoCommand_processEcuInfo(attempt.read_result)
        if metadata:
            return attempt, metadata
    return None


def render_report(
    summaries: list[Path],
    fresh_coding: str | None,
    attempts: list[ProofAttempt],
    positive: tuple[ProofAttempt, VagEcuInfoWithCoding] | None,
    chunk_matches: list[ChunkMatch],
    dry_runs: list[TupleDryRun],
) -> str:
    fallback_done = any("sctr" in path.name or "skip_params" in path.name for path in summaries)
    lines = [
        "# Carista Tuple-Proof Read Summary",
        "",
        "This report summarizes the read-only in-car proof attempt for Carista `3B9A` tuple metadata.",
        "",
        "## Inputs",
        "",
    ]
    for path in summaries:
        lines.append(f"- `{path}`")

    lines.extend(["", "## Fresh Coding", ""])
    if fresh_coding:
        lines.extend(["```text", fresh_coding, "```"])
    else:
        lines.append("No fresh positive `220600` baseline was found in the supplied summaries.")

    lines.extend([
        "",
        "## 1A9B Attempts",
        "",
        "| Attempt | Mode | Session | Pre-read | Read counter | Status | Result |",
        "|---|---|---|---|---:|---|---|",
    ])
    for attempt in attempts:
        result = attempt.read_result or "<empty>"
        if len(result) > 42:
            result = result[:42] + "..."
        session = attempt.session_command or "direct"
        pre_read = attempt.pre_read_sequence or "none"
        lines.append(
            f"| `{attempt.attempt_id}` | `{attempt.mode}` | `{session}` | `{pre_read}` | "
            f"`{attempt.read_counter}` | `{attempt.read_status}` | `{result}` |"
        )

    lines.extend(["", "## Tuple Metadata Proof", ""])
    if not positive:
        next_step = (
            "Fallback/session-counter reads were included and still did not produce `5A9B`. Stop the in-car tuple-proof read attempt and keep the logs as negative evidence."
            if fallback_done
            else "Do not run broad fallback sweeps again by default; use `run_next_carista_validation.ps1 -IncludeSessionComparison` only for a single deliberate negative-control comparison."
        )
        lines.extend(
            [
                "No positive `5A9B` response was found. The actual tuple is still not proven; do not use any placeholder rawAddress4.",
                "",
                next_step,
            ]
        )
        return "\n".join(lines) + "\n"

    attempt, metadata = positive
    lines.extend(
        [
            f"Positive source attempt: `{attempt.attempt_id}` from `{attempt.source_file}`",
            "",
            "| Field | Value |",
            "|---|---|",
            f"| Part number payload | `{metadata.part_number}` |",
            f"| rawAddress4 | `{metadata.raw_address4}` |",
            f"| coding selector | `{metadata.coding_type_selector}` |",
            f"| Carista coding type | `{metadata.coding_type}` |",
            f"| tail | `{metadata.tail or '<empty>'}` |",
            f"| initial value6 | `{metadata.initial_value6}` |",
            f"| writer suffix | `{metadata.suffix}` |",
            "",
        ]
    )

    if chunk_matches:
        lines.extend(["Fresh-coding chunk match for `initial value6`:", ""])
        for match in chunk_matches:
            lines.append(f"- chunk `{match.chunk_index}` bytes `{match.byte_start}-{match.byte_end}` = `{match.value6}`")
        lines.append("")
    else:
        lines.extend(
            [
                "The decoded `initial value6` did not match any 6-byte chunk in the supplied fresh coding. Review this before treating the generated dry-run requests as final.",
                "",
            ]
        )

    if dry_runs:
        lines.extend(
            [
                "Dry-run tuple bytes using the decoded metadata and fresh baseline-derived value6 chunks:",
                "",
                "| Label | Value6 | rawAddress4 | Type | Tail | Request |",
                "|---|---:|---:|---:|---:|---|",
            ]
        )
        for dry_run in dry_runs:
            lines.append(
                f"| `{dry_run.label}` | `{dry_run.value6}` | `{dry_run.raw_address4}` | "
                f"`{dry_run.coding_type}` | `{dry_run.tail or '<empty>'}` | `{dry_run.request}` |"
            )

        lines.extend(["", "Composer commands:", "", "```powershell"])
        for dry_run in dry_runs:
            lines.append(dry_run.composer_command)
        lines.extend(["```", "", "These are proof/dry-run bytes only. Keep the write gate closed until the generated request is reviewed against the full log."])

    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(description="Summarize read-only Carista tuple-proof 1A9B captures.")
    parser.add_argument("--summaries", nargs="+", type=Path, required=True, help="Probe summary JSON files to inspect")
    default_report = Path(__file__).resolve().parents[1] / "docs" / "obd-on-pc" / "logs" / "pq25_tuple_proof_read_report.md"
    parser.add_argument("--output", type=Path, default=default_report)
    parser.add_argument("--json-output", type=Path, default=Path("logs/pq25_tuple_proof_read_report.json"))
    args = parser.parse_args()

    rows = load_rows(args.summaries)
    fresh_coding = find_fresh_coding(rows)
    attempts = collect_attempts(rows)
    positive = first_positive_metadata(attempts)
    baseline_summary = next((path for path in args.summaries if "220600" in path.name), None)

    chunk_matches: list[ChunkMatch] = []
    dry_runs: list[TupleDryRun] = []
    if positive and fresh_coding:
        _attempt, metadata = positive
        chunk_matches = find_chunk_matches(fresh_coding, metadata.initial_value6)
        dry_runs = build_tuple_dry_runs(metadata, fresh_coding, baseline_summary)

    report = render_report(args.summaries, fresh_coding, attempts, positive, chunk_matches, dry_runs)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.json_output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(report, encoding="utf-8")
    args.json_output.write_text(
        json.dumps(
            {
                "summaries": [str(path) for path in args.summaries],
                "fresh_coding": fresh_coding,
                "attempts": [asdict(attempt) for attempt in attempts],
                "positive_metadata": asdict(positive[1]) if positive else None,
                "positive_attempt": asdict(positive[0]) if positive else None,
                "chunk_matches": [asdict(match) for match in chunk_matches],
                "tuple_dry_runs": [asdict(dry_run) for dry_run in dry_runs],
                "status": "positive_1a9b_found" if positive else "positive_1a9b_not_found",
            },
            indent=2,
            sort_keys=True,
        ),
        encoding="utf-8",
    )
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
