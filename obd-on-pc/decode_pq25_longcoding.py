from __future__ import annotations

import argparse
import json
import re
from dataclasses import dataclass
from pathlib import Path


DEFAULT_XPL = Path(__file__).with_name("lcode") / "pq25_6r0_937_08x_cornering_candidates.xpl"
DEFAULT_REFERENCE = Path(__file__).with_name("lcode") / "6R0937087K_cornering_enabled_longcoding.txt"
CONFIDENCE_PREFIX = re.compile(r"^\[(?P<confidence>[^\]]+)\]\s*(?P<label>.*)$")


@dataclass(frozen=True)
class Candidate:
    byte_index: int
    bit_index: int
    label: str
    confidence: str = "unknown"

    def matches(self, value: int) -> bool:
        return bool(value & (1 << self.bit_index))

    @property
    def short_label(self) -> str:
        return f"[{self.confidence}] {self.label}"


def normalize_hex(raw: str) -> str:
    cleaned = re.sub(r"[^0-9A-Fa-f]", "", raw).upper()
    for prefix in ("5A9A", "620600"):
        if cleaned.startswith(prefix) and len(cleaned) > len(prefix):
            cleaned = cleaned[len(prefix):]
            break
    if len(cleaned) % 2:
        raise ValueError(f"hex length must be even, got {len(cleaned)}")
    if not cleaned:
        raise ValueError("no hex payload found")
    return cleaned


def read_coding_file(path: Path) -> str:
    text = path.read_text(encoding="utf-8")
    if path.suffix.lower() != ".json":
        return normalize_hex(text)

    data = json.loads(text)
    entries = data if isinstance(data, list) else [data]
    for entry in entries:
        if not isinstance(entry, dict):
            continue
        read_result = entry.get("read_result")
        if isinstance(read_result, str) and read_result:
            return normalize_hex(read_result)
    raise ValueError(f"no read_result found in {path}")


def parse_xpl(path: Path) -> list[Candidate]:
    candidates: list[Candidate] = []
    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith(";") or not line.startswith("LC,"):
            continue
        parts = [part.strip() for part in line.split(",")]
        if len(parts) < 4 or "~" in parts[2] or "-" in parts[2]:
            continue

        description = ",".join(parts[3:]).strip()
        confidence = "unknown"
        match = CONFIDENCE_PREFIX.match(description)
        if match:
            confidence = match.group("confidence")
            description = match.group("label").strip()

        candidates.append(
            Candidate(
                byte_index=int(parts[1], 10),
                bit_index=int(parts[2], 10),
                label=description,
                confidence=confidence,
            )
        )
    return candidates


def read_coding(coding: str | None, coding_file: str | None) -> str:
    if coding_file:
        return read_coding_file(Path(coding_file))
    if coding:
        return normalize_hex(coding)
    raise ValueError("provide --coding or --coding-file")


def read_reference(args: argparse.Namespace) -> str | None:
    if args.no_default_reference and not args.reference and not args.reference_file:
        return None
    if args.reference_file:
        return read_coding_file(Path(args.reference_file))
    if args.reference:
        return normalize_hex(args.reference)
    if DEFAULT_REFERENCE.exists():
        return read_coding_file(DEFAULT_REFERENCE)
    return None


def bit_state(value: int, bit_index: int) -> str:
    return "set" if value & (1 << bit_index) else "clear"


def candidate_map(candidates: list[Candidate]) -> dict[tuple[int, int], Candidate]:
    return {(candidate.byte_index, candidate.bit_index): candidate for candidate in candidates}


def format_deltas(
    values: bytes,
    reference_values: bytes | None,
    candidates: dict[tuple[int, int], Candidate],
) -> list[str]:
    lines: list[str] = []
    if reference_values is None:
        lines.append("No reference coding supplied.")
        return lines

    max_len = max(len(values), len(reference_values))
    for index in range(max_len):
        current = values[index] if index < len(values) else None
        reference = reference_values[index] if index < len(reference_values) else None
        if current == reference:
            continue
        if current is None or reference is None:
            lines.append(f"byte {index:02d}: length mismatch current={current!r} reference={reference!r}")
            continue

        changed_bits: list[str] = []
        for bit_index in range(8):
            if not ((current ^ reference) & (1 << bit_index)):
                continue
            candidate = candidates.get((index, bit_index))
            label = candidate.short_label if candidate else "unknown"
            changed_bits.append(
                f"bit {bit_index} {bit_state(current, bit_index)} -> {bit_state(reference, bit_index)} ({label})"
            )
        lines.append(f"byte {index:02d}: {current:02X} -> {reference:02X}; {'; '.join(changed_bits)}")

    if not lines:
        lines.append("Current coding matches the reference coding.")
    return lines


def format_known_states(
    values: bytes,
    reference_values: bytes | None,
    candidates: list[Candidate],
) -> list[str]:
    lines: list[str] = []
    for candidate in candidates:
        if candidate.byte_index >= len(values):
            lines.append(
                f"byte {candidate.byte_index:02d} bit {candidate.bit_index}: out-of-range {candidate.short_label}"
            )
            continue

        current_value = values[candidate.byte_index]
        state = bit_state(current_value, candidate.bit_index)
        reference_text = ""
        if reference_values is not None and candidate.byte_index < len(reference_values):
            reference_value = reference_values[candidate.byte_index]
            reference_state = bit_state(reference_value, candidate.bit_index)
            marker = "matches reference" if state == reference_state else f"reference {reference_state}"
            reference_text = f"; {marker}"

        lines.append(
            f"byte {candidate.byte_index:02d} bit {candidate.bit_index} [{current_value:02X}] "
            f"{state:<5} {candidate.short_label}{reference_text}"
        )
    return lines


def format_full_bit_table(values: bytes, candidates: dict[tuple[int, int], Candidate]) -> list[str]:
    lines: list[str] = []
    for byte_index, value in enumerate(values):
        lines.append(f"byte {byte_index:02d}: {value:02X} {value:08b}")
        for bit_index in range(8):
            candidate = candidates.get((byte_index, bit_index))
            label = candidate.short_label if candidate else "unknown"
            lines.append(f"  bit {bit_index}: {bit_state(value, bit_index):<5} {label}")
    return lines


def format_report(
    coding: str,
    values: bytes,
    candidates: list[Candidate],
    reference: str | None,
) -> str:
    reference_values = bytes.fromhex(reference) if reference else None
    candidates_by_bit = candidate_map(candidates)

    lines: list[str] = [
        "PQ25 BCM long-coding decode",
        "",
        f"Coding bytes: {len(values)}",
        f"Coding hex:   {coding}",
    ]
    if reference:
        lines.extend(
            [
                f"Reference:    {reference}",
                "",
                "Deltas versus known-good cornering-enabled reference:",
                *[f"  {line}" for line in format_deltas(values, reference_values, candidates_by_bit)],
            ]
        )

    lines.extend(
        [
            "",
            "Bytes:",
            *[f"  {index:02d}: {value:02X} {value:08b}" for index, value in enumerate(values)],
            "",
            "Known setting states:",
            *[f"  {line}" for line in format_known_states(values, reference_values, candidates)],
            "",
            "Full bit table:",
            *[f"  {line}" for line in format_full_bit_table(values, candidates_by_bit)],
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Decode PQ25 BCM cornering-light candidate bits from a long-coding hex string."
    )
    parser.add_argument("--coding", help="Long-coding hex string or raw 5A9A/620600 response.")
    parser.add_argument("--coding-file", help="Text/JSON file containing a long-coding read result.")
    parser.add_argument("--reference", help="Reference long-coding hex string.")
    parser.add_argument("--reference-file", help="Reference long-coding text/JSON file.")
    parser.add_argument(
        "--no-default-reference",
        action="store_true",
        help="Do not compare against lcode/6R0937087K_cornering_enabled_longcoding.txt.",
    )
    parser.add_argument("--xpl", default=str(DEFAULT_XPL), help="XPL candidate file to evaluate.")
    parser.add_argument("--output", help="Optional path to write the decoded report.")
    args = parser.parse_args()

    coding = read_coding(args.coding, args.coding_file)
    values = bytes.fromhex(coding)
    candidates = parse_xpl(Path(args.xpl))
    reference = read_reference(args)
    report = format_report(coding, values, candidates, reference)

    print(report, end="")
    if args.output:
        output_path = Path(args.output)
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(report, encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
