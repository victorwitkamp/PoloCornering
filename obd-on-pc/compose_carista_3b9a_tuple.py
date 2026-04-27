from __future__ import annotations

import argparse
import re


CODING_TYPE_LOOKUP = {
    0: "00",
    1: "10",
    2: "10",
    3: "03",
    4: "10",
    5: "10",
}


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


def build_request(value6: str, raw_address4: str, coding_type: int, tail: str) -> str:
    mapped_type = CODING_TYPE_LOOKUP.get(coding_type, "03")
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
    parser.add_argument("--value6", required=True, help="6-byte coding value vector, e.g. 6C680ED000C8")
    parser.add_argument("--raw-address4", required=True, help="4-byte raw-address vector recovered from Carista")
    parser.add_argument("--coding-type", type=int, required=True, help="Carista/VagEcuInfo coding type integer")
    parser.add_argument("--tail", default="", help="Tail bytes recovered from Carista/VagEcuInfo")
    args = parser.parse_args()

    value6 = require_len(args.value6, "value6", 6)
    raw_address4 = require_len(args.raw_address4, "raw-address4", 4)
    tail = clean_hex(args.tail, "tail")
    request = build_request(value6, raw_address4, args.coding_type, tail)

    print("Offline Carista-shaped 3B9A request")
    print()
    print("Nothing was sent to the car.")
    print(f"value6:       {value6}")
    print(f"rawAddress4:  {raw_address4}")
    print(f"codingType:   {args.coding_type}")
    print(f"mapped byte:  {CODING_TYPE_LOOKUP.get(args.coding_type, '03')}")
    print(f"tail:         {tail or '<empty>'}")
    print()
    print(request)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
