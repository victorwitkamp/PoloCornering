from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path


KNOWN_GOOD_PATH = Path(__file__).with_name("lcode") / "6R0937087K_cornering_enabled_longcoding.txt"
FOCUS_BYTES = (12, 13, 21, 22)


@dataclass(frozen=True)
class BitCandidate:
    byte_index: int
    bit_index: int
    confidence: str
    label: str


@dataclass(frozen=True)
class BitEdit:
    byte_index: int
    bit_index: int
    enabled: bool
    reason: str


CANDIDATES = (
    BitCandidate(12, 6, "high", "base fog-light cornering function"),
    BitCandidate(21, 2, "high", "turn-signal-triggered cornering assist"),
    BitCandidate(13, 6, "medium", "CH/LH fog-vs-low-beam selector"),
    BitCandidate(13, 0, "medium", "parking-light behavior group"),
    BitCandidate(13, 1, "medium", "parking-light behavior group"),
    BitCandidate(13, 3, "medium", "parking-light behavior group"),
    BitCandidate(21, 7, "medium", "fog-related capability/install bit"),
    BitCandidate(22, 5, "medium", "probable ADL-related bit"),
)


MINIMAL_CORNERING_EDITS = (
    BitEdit(12, 6, True, "enable base fog-light cornering"),
    BitEdit(21, 2, True, "enable turn-signal-triggered cornering"),
)


def normalize_hex(raw: str) -> str:
    cleaned = re.sub(r"[^0-9A-Fa-f]", "", raw).upper()
    if cleaned.startswith("5A9A") and len(cleaned) > 4:
        cleaned = cleaned[4:]
    if cleaned.startswith("620600") and len(cleaned) > 6:
        cleaned = cleaned[6:]
    if not cleaned:
        raise ValueError("no hex payload found")
    if len(cleaned) % 2:
        raise ValueError(f"hex length must be even, got {len(cleaned)}")
    return cleaned


def read_hex(value: str | None, file_path: str | None, label: str) -> str:
    if file_path:
        return normalize_hex(Path(file_path).read_text(encoding="utf-8"))
    if value:
        return normalize_hex(value)
    raise ValueError(f"provide --{label} or --{label}-file")


def set_bit(value: int, bit_index: int, enabled: bool) -> int:
    mask = 1 << bit_index
    return value | mask if enabled else value & ~mask


def apply_profile(current: bytes, reference: bytes, profile: str) -> bytes:
    proposed = bytearray(current)
    if profile == "report-only":
        return bytes(proposed)
    if profile == "cornering-minimal":
        for edit in MINIMAL_CORNERING_EDITS:
            proposed[edit.byte_index] = set_bit(proposed[edit.byte_index], edit.bit_index, edit.enabled)
        return bytes(proposed)
    if profile == "match-working-focus-bytes":
        for byte_index in FOCUS_BYTES:
            proposed[byte_index] = reference[byte_index]
        return bytes(proposed)
    raise ValueError(f"unknown profile: {profile}")


def bit_state(data: bytes, byte_index: int, bit_index: int) -> str:
    if byte_index >= len(data):
        return "out-of-range"
    return "set" if data[byte_index] & (1 << bit_index) else "clear"


def byte_text(data: bytes, byte_index: int) -> str:
    return "--" if byte_index >= len(data) else f"{data[byte_index]:02X}"


def diff_lines(current: bytes, proposed: bytes) -> list[str]:
    lines = []
    for index, (old, new) in enumerate(zip(current, proposed)):
        if old != new:
            lines.append(f"  byte {index:02d}: {old:02X} -> {new:02X}")
    if len(current) != len(proposed):
        lines.append(f"  length: {len(current)} -> {len(proposed)}")
    return lines or ["  no byte changes"]


def build_report(current_hex: str, reference_hex: str, profile: str) -> str:
    current = bytes.fromhex(current_hex)
    reference = bytes.fromhex(reference_hex)
    if len(current) != len(reference):
        raise ValueError(f"current length {len(current)} does not match reference length {len(reference)}")

    proposed = apply_profile(current, reference, profile)
    lines = [
        "PQ25 BCM long-coding change preparation",
        "",
        "Safety:",
        "  This is offline only. It does not send or generate a diagnostic write command.",
        "",
        f"Profile: {profile}",
        f"Bytes:   {len(current)}",
        "",
        "Current coding:",
        current.hex().upper(),
        "",
        "Known-good reference:",
        reference.hex().upper(),
        "",
        "Proposed coding:",
        proposed.hex().upper(),
        "",
        "Focus bytes:",
        "  byte  current  reference  proposed",
    ]
    for byte_index in FOCUS_BYTES:
        lines.append(
            f"  {byte_index:02d}    {byte_text(current, byte_index):>2}       "
            f"{byte_text(reference, byte_index):>2}        {byte_text(proposed, byte_index):>2}"
        )

    lines.extend(["", "Candidate states:", "  byte bit confidence current proposed label"])
    for candidate in CANDIDATES:
        lines.append(
            f"  {candidate.byte_index:02d}   {candidate.bit_index}   {candidate.confidence:<10} "
            f"{bit_state(current, candidate.byte_index, candidate.bit_index):<7} "
            f"{bit_state(proposed, candidate.byte_index, candidate.bit_index):<8} "
            f"{candidate.label}"
        )

    lines.extend(["", "Current -> proposed changes:"])
    lines.extend(diff_lines(current, proposed))

    lines.extend(["", "Current -> known-good reference differences:"])
    lines.extend(diff_lines(current, reference))
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Prepare an offline PQ25 BCM long-coding comparison/proposal. This never writes to the car."
    )
    parser.add_argument("--current", help="Current long-coding hex string or raw 5A9A response.")
    parser.add_argument("--current-file", help="Text file containing current long coding or raw 5A9A response.")
    parser.add_argument("--reference", help="Known-good reference long-coding hex string.")
    parser.add_argument("--reference-file", help="Known-good reference file. Defaults to the local 6R0937087K known-good file.")
    parser.add_argument(
        "--profile",
        choices=("report-only", "cornering-minimal", "match-working-focus-bytes"),
        default="report-only",
        help="report-only makes no change; cornering-minimal sets high-confidence bits; match-working-focus-bytes copies bytes 12, 13, 21, and 22 from the known-good coding.",
    )
    parser.add_argument("--output", help="Optional text report path.")
    args = parser.parse_args()

    current_hex = read_hex(args.current, args.current_file, "current")
    reference_file = args.reference_file or str(KNOWN_GOOD_PATH)
    reference_hex = read_hex(args.reference, None if args.reference else reference_file, "reference")
    report = build_report(current_hex, reference_hex, args.profile)
    print(report)
    if args.output:
        Path(args.output).write_text(report + "\n", encoding="utf-8")
        print()
        print(f"Wrote report: {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
