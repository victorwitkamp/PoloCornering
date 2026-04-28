from __future__ import annotations

from .ByteUtils import ByteUtils_insertValue
from .Types import HexString


def VagSetting_insertValue(current_raw_value: HexString, offset: int, mask: HexString, requested_value: HexString) -> HexString:
    return ByteUtils_insertValue(current_raw_value, offset, mask, requested_value)


class VagSetting:
    insertValue = staticmethod(VagSetting_insertValue)