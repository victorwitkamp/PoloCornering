from __future__ import annotations

from dataclasses import dataclass

from .ByteUtils import ByteUtils_insertValue, require_len
from .Types import HexString


WORKSHOP_CODE_DEFAULT_INSERTS: tuple[tuple[int, HexString, int], ...] = (
    (0, "FFFFF8", 0x3039),
    (2, "FE07", 0x7B),
    (3, "01FFFF", 0x3039),
)


@dataclass(frozen=True)
class VagEcuInfo:
    workshop_code: HexString | None = None

    def getWorkshopCodeForWriting(self) -> HexString:
        return VagEcuInfo_getWorkshopCodeForWriting(self.workshop_code)


def _masked_field_is_zero(current: bytes, offset: int, mask: bytes) -> bool:
    return all((current[offset + index] & mask_byte) == 0 for index, mask_byte in enumerate(mask))


def _value_bytes(value: int, width: int) -> HexString:
    return value.to_bytes(width, byteorder="big").hex().upper()


def VagEcuInfo_getWorkshopCodeForWriting(workshop_code: HexString | None = None) -> HexString:
    if workshop_code is None:
        current = "000000000000"
    else:
        current = require_len(workshop_code, "VagEcuInfo workshop code", 6)

    for offset, mask_hex, default_value in WORKSHOP_CODE_DEFAULT_INSERTS:
        current_bytes = bytes.fromhex(current)
        mask = bytes.fromhex(mask_hex)
        if _masked_field_is_zero(current_bytes, offset, mask):
            current = ByteUtils_insertValue(current, offset, mask_hex, _value_bytes(default_value, len(mask)))
    return current