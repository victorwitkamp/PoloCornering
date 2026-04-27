from __future__ import annotations

import argparse
import json
import re
from dataclasses import dataclass
from pathlib import Path


CODING_TYPE_LOOKUP = {
    0: "00",
    1: "10",
    2: "10",
    3: "03",
    4: "10",
    5: "10",
}
CORNERING_FIXES = {
    "base-fog": (12, 6, "Base fog-light cornering function"),
    "turn-signal": (21, 2, "Turn-signal-triggered cornering assist"),
}


@dataclass(frozen=True)
class DerivedValue:
    value6: str
    chunk_index: int
    byte_start: int
    byte_index: int | None = None
    bit_index: int | None = None
    bit_action: str | None = None
    label: str | None = None


def clean_hex(value: str, label: str) -> str:
    cleaned = re.sub(r"[^0-9A-Fa-f]", "", value).upper()
    if len(cleaned) % 2:
        raise ValueError(f"{label} must have even hex length")
    return cleaned


def require_len(value: str, label: str, expected_bytes: int) -> str:
    cleaned = clean_hex(value, label)
    actual = len(cleaned) // 2
    if actual != expected_bytes:
        raise ValueError(f"{label} must be {expected_bytes} bytes, got {actual}")
    return cleaned


def one_byte(value: int, label: str) -> str:
    if not 0 <= value <= 0xFF:
        raise ValueError(f"{label} must fit in one byte")
    return f"{value:02X}"


def normalize_coding(value: str) -> str:
    cleaned = clean_hex(value, "coding")
    for prefix in ("620600", "5A9A"):
        if cleaned.startswith(prefix):
            cleaned = cleaned[len(prefix):]
            break
    if not cleaned:
        raise ValueError("coding is empty")
    return cleaned


def read_coding(coding: str | None, coding_file: str | None) -> str | None:
    if coding_file:
        text = Path(coding_file).read_text(encoding="utf-8")
        if Path(coding_file).suffix.lower() == ".json":
            data = json.loads(text)
            entries = data if isinstance(data, list) else [data]
            for entry in entries:
                if not isinstance(entry, dict):
                    continue
                read_result = entry.get("read_result")
                if isinstance(read_result, str) and read_result:
                    return normalize_coding(read_result)
            raise ValueError(f"no read_result found in {coding_file}")
        return normalize_coding(text)
    if coding:
        return normalize_coding(coding)
    return None


def apply_bit(value: int, bit_index: int, action: str) -> int:
    if not 0 <= bit_index <= 7:
        raise ValueError("bit index must be between 0 and 7 (inclusive)")
    mask = 1 << bit_index
    if action == "set":
        return value | mask
    if action == "clear":
        return value & ~mask
    raise ValueError(f"unsupported bit action {action!r}")


def derive_value6(
    coding: str,
    chunk_size: int,
    chunk_index: int | None,
    byte_index: int | None,
    bit_index: int | None,
    bit_action: str | None,
    label: str | None,
) -> DerivedValue:
    if chunk_size <= 0:
        raise ValueError("chunk size must be positive")
    data = bytearray.fromhex(coding)
    if byte_index is not None:
        if not 0 <= byte_index < len(data):
            raise ValueError(f"byte index {byte_index} is outside {len(data)} coding bytes")
        if bit_index is not None:
            if bit_action is None:
                raise ValueError("bit action is required when bit index is supplied")
            data[byte_index] = apply_bit(data[byte_index], bit_index, bit_action)
        derived_chunk_index = byte_index // chunk_size
    elif chunk_index is not None:
        derived_chunk_index = chunk_index
    else:
        raise ValueError("provide --value6, --cornering-fix, --byte-index, or --chunk-index")

    byte_start = derived_chunk_index * chunk_size
    chunk = data[byte_start:byte_start + chunk_size]
    if len(chunk) != chunk_size:
        raise ValueError(f"chunk {derived_chunk_index} is incomplete for {len(data)} coding bytes")
    return DerivedValue(
        value6=chunk.hex().upper(),
        chunk_index=derived_chunk_index,
        byte_start=byte_start,
        byte_index=byte_index,
        bit_index=bit_index,
        bit_action=bit_action,
        label=label,
    )


def build_request(value6: str, raw_address4: str, coding_type: int, tail: str) -> str:
    if coding_type not in CODING_TYPE_LOOKUP:
        valid_types = ", ".join(str(key) for key in sorted(CODING_TYPE_LOOKUP.keys()))
        raise ValueError(f"coding type must be one of {valid_types}, got {coding_type}")
    mapped_type = CODING_TYPE_LOOKUP[coding_type]
    if coding_type == 2:
        if len(tail) // 2 != 3:
            raise ValueError("coding type 2 requires a 3-byte tail")
        suffix = mapped_type + tail
    else:
        tail_len = len(tail) // 2
        suffix = mapped_type + one_byte(tail_len + 1, "tail length + 1") + tail + "FF"
    return "3B9A" + value6 + raw_address4 + suffix


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Offline composer for Carista-shaped 3B9A coding requests. Does not send anything."
    )
    parser.add_argument(
        "--value6",
        help="Optional explicit 6-byte coding value vector; alternatively derive it from --coding/--coding-file",
    )
    parser.add_argument("--coding", help="Long-coding hex string or raw 620600/5A9A response to derive a value chunk from")
    parser.add_argument("--coding-file", help="File containing long-coding hex or a raw 620600/5A9A response")
    parser.add_argument(
        "--cornering-fix",
        choices=sorted(CORNERING_FIXES),
        help="Derive the value chunk for a known PQ25 cornering-light fix from --coding/--coding-file",
    )
    parser.add_argument("--chunk-index", type=int, help="6-byte chunk index to extract when deriving from long coding")
    parser.add_argument("--chunk-size", type=int, default=6, help="Coding chunk size used by the Carista writer")
    parser.add_argument("--byte-index", type=int, help="Long-coding byte index to modify/extract when deriving a chunk")
    parser.add_argument("--set-bit", type=int, help="Set this bit in --byte-index before extracting the chunk")
    parser.add_argument("--clear-bit", type=int, help="Clear this bit in --byte-index before extracting the chunk")
    parser.add_argument("--raw-address4", help="4-byte raw-address vector recovered from Carista")
    parser.add_argument("--coding-type", type=int, help="Carista/VagEcuInfo coding type integer")
    parser.add_argument("--tail", default="", help="Tail bytes recovered from Carista/VagEcuInfo")
    args = parser.parse_args()

    if args.set_bit is not None and args.clear_bit is not None:
        raise ValueError("cannot specify both --set-bit and --clear-bit")

    coding = read_coding(args.coding, args.coding_file)
    derived: DerivedValue | None = None
    if args.cornering_fix:
        if coding is None:
            raise ValueError("--cornering-fix requires --coding or --coding-file")
        byte_index, bit_index, label = CORNERING_FIXES[args.cornering_fix]
        derived = derive_value6(coding, args.chunk_size, None, byte_index, bit_index, "set", label)
    elif args.value6:
        value6 = require_len(args.value6, "value6", 6)
    else:
        if coding is None:
            raise ValueError("provide --value6 or --coding/--coding-file")
        bit_index = None
        bit_action = None
        if args.set_bit is not None:
            bit_index = args.set_bit
            bit_action = "set"
        elif args.clear_bit is not None:
            bit_index = args.clear_bit
            bit_action = "clear"
        derived = derive_value6(coding, args.chunk_size, args.chunk_index, args.byte_index, bit_index, bit_action, None)

    if derived is not None:
        value6 = derived.value6

    tail = clean_hex(args.tail, "tail")
    raw_address4 = require_len(args.raw_address4, "raw-address4", 4) if args.raw_address4 else None
    if (raw_address4 is None) != (args.coding_type is None):
        raise ValueError("--raw-address4 and --coding-type must be supplied together or not at all")
    if raw_address4 is not None and args.coding_type is not None:
        request = build_request(value6, raw_address4, args.coding_type, tail)
    else:
        request = None

    print("Offline Carista-shaped 3B9A request")
    print()
    print("Nothing was sent to the car.")
    if derived:
        print(f"derived from:  chunk {derived.chunk_index} bytes {derived.byte_start}-{derived.byte_start + args.chunk_size - 1}")
        if derived.byte_index is not None and derived.bit_index is not None:
            label = f" ({derived.label})" if derived.label else ""
            print(f"bit change:    byte {derived.byte_index} bit {derived.bit_index} {derived.bit_action}{label}")
    print(f"value6:       {value6}")
    print(f"rawAddress4:  {raw_address4 or '<not supplied>'}")
    print(f"codingType:   {args.coding_type if args.coding_type is not None else '<not supplied>'}")
    print(f"mapped byte:  {CODING_TYPE_LOOKUP[args.coding_type] if args.coding_type is not None else '<not supplied>'}")
    print(f"tail:         {tail or '<empty>'}")
    print()
    if request:
        print(request)
    else:
        print("No complete 3B9A request printed because rawAddress4/codingType are still required.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
