from __future__ import annotations

from .ByteUtils import ByteUtils_extractValue, ByteUtils_insertValue
from .Types import HexString


VAG_SETTING_IS_SUBMODULE_TYPE_MASK = 0x230
VAG_SETTING_IS_SUBMODULE_TYPES = (4, 5, 9)


def VagSetting_extractValue(current_raw_value: HexString, offset: int, mask: HexString) -> HexString:
    return ByteUtils_extractValue(current_raw_value, offset, mask)


def VagSetting_insertValue(current_raw_value: HexString, offset: int, mask: HexString, requested_value: HexString) -> HexString:
    return ByteUtils_insertValue(current_raw_value, offset, mask, requested_value)


def VagSetting_isSubmodule(vag_setting_type: int) -> bool:
    return vag_setting_type < 10 and ((VAG_SETTING_IS_SUBMODULE_TYPE_MASK >> (vag_setting_type & 0x1F)) & 1) != 0


class VagSetting:
    extractValue = staticmethod(VagSetting_extractValue)
    insertValue = staticmethod(VagSetting_insertValue)
    isSubmodule = staticmethod(VagSetting_isSubmodule)
