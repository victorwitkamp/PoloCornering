from __future__ import annotations

import argparse
import sys
from pathlib import Path

WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
if str(WORKSPACE_ROOT) not in sys.path:
    sys.path.insert(0, str(WORKSPACE_ROOT))

from CaristaReproduction.ByteUtils import clean_hex, require_len
from CaristaReproduction.Commands.WriteVagCodingCommand import build_request
from CaristaReproduction.Constants import CODING_TYPE_LOOKUP, CORNERING_FIXES
from CaristaReproduction.Models.DerivedValue import DerivedValue
from CaristaReproduction.Types import BitAction
from CaristaReproduction.VagCoding import derive_value6, read_coding


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
        bit_action: BitAction | None = None
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
    if raw_address4 is None and args.coding_type is not None:
        raise ValueError("--raw-address4 is required when --coding-type is supplied")
    if raw_address4 is not None and args.coding_type is None:
        raise ValueError("--coding-type is required when --raw-address4 is supplied")
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
