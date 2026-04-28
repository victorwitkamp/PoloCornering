from __future__ import annotations

from dataclasses import dataclass

from ..ByteUtils import clean_hex, one_byte, require_len
from ..Constants import CODING_TYPE_LOOKUP
from ..Types import HexString


@dataclass(frozen=True)
class WriteVagCodingCommand:
    value6: HexString
    raw_address4: HexString
    coding_type: int
    tail: HexString = ""

    def getRequest(self) -> HexString:
        return WriteVagCodingCommand_getRequest(self)


def WriteVagCodingCommand_suffix(coding_type: int, tail: HexString) -> HexString:
    if coding_type not in CODING_TYPE_LOOKUP:
        valid_types = ", ".join(str(key) for key in sorted(CODING_TYPE_LOOKUP))
        raise ValueError(f"coding type must be one of {valid_types}, got {coding_type}")
    mapped_type = CODING_TYPE_LOOKUP[coding_type]
    tail = clean_hex(tail, "tail")
    if coding_type == 2:
        if len(tail) // 2 != 3:
            raise ValueError("coding type 2 requires a 3-byte tail")
        return mapped_type + tail
    tail_len = len(tail) // 2
    return mapped_type + one_byte(tail_len + 1, "tail length + 1") + tail + "FF"


def WriteVagCodingCommand_ctor(
    value6: HexString,
    raw_address4: HexString,
    coding_type: int,
    tail: HexString = "",
) -> WriteVagCodingCommand:
    value6 = require_len(value6, "value6", 6)
    raw_address4 = require_len(raw_address4, "raw-address4", 4)
    tail = clean_hex(tail, "tail")
    if coding_type < 2:
        raise ValueError("Cannot write a coding value when type is NONE or UNKNOWN")
    if coding_type == 2 and len(tail) // 2 != 3:
        raise ValueError("Short coding value must be exactly 3 bytes")
    return WriteVagCodingCommand(value6=value6, raw_address4=raw_address4, coding_type=coding_type, tail=tail)


def WriteVagCodingCommand_getRequest(command: WriteVagCodingCommand) -> HexString:
    return "3B9A" + command.value6 + command.raw_address4 + WriteVagCodingCommand_suffix(command.coding_type, command.tail)


def build_request(value6: HexString, raw_address4: HexString, coding_type: int, tail: HexString) -> HexString:
    return WriteVagCodingCommand_ctor(value6, raw_address4, coding_type, tail).getRequest()