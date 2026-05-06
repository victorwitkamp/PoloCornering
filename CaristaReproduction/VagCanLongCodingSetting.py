from __future__ import annotations

from dataclasses import dataclass

from .ByteUtils import clean_hex, one_byte
from .Types import HexString
from .VagSetting import VagSetting_insertValue


@dataclass(frozen=True)
class VagCanLongCodingSetting:
    raw_address: int = 0
    setting_type: int = 3
    value_offset: int = 0
    value_mask: HexString = ""
    native_constructor: str = "VagCanLongCodingSetting"
    native_source: str = "recovered from libCarista.so target_0105F484/target_0105F500"
    proof_notes: tuple[str, ...] = (
        "VagCanLongCodingSetting(Ecu, int, vector) calls VagCanCodingSetting with type 3, raw address 0, offset=int, and mask=vector.",
        "The unsigned-char overload wraps the byte in a one-byte vector before calling the vector constructor.",
        "ByteUtils::insertValue shifts compact requested bytes left by getLsbOffset(mask) before merging masked fields.",
        "Constructor shape does not prove runtime branch selection or the branch-specific choice table.",
    )

    @property
    def value(self) -> HexString:
        return self.value_mask

    def insert_value(self, current_raw_value: HexString, requested_value: HexString) -> HexString:
        return VagSetting_insertValue(current_raw_value, self.value_offset, self.value_mask, requested_value)


def _validate_value_offset(value_offset: int) -> int:
    if value_offset < 0:
        raise ValueError("VagCanLongCodingSetting value offset must be non-negative")
    return value_offset


def VagCanLongCodingSetting_ctor_ecu_vector(value: HexString, value_offset: int = 0) -> VagCanLongCodingSetting:
    return VagCanLongCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=clean_hex(value, "VagCanLongCodingSetting value mask"),
        native_constructor="VagCanLongCodingSetting(Ecu*, StringWhitelist, int, vector<unsigned char>, key, Interpretation)",
    )


def VagCanLongCodingSetting_ctor_ecu_byte(value: int, value_offset: int = 0) -> VagCanLongCodingSetting:
    return VagCanLongCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=one_byte(value, "VagCanLongCodingSetting byte value mask"),
        native_constructor="VagCanLongCodingSetting(Ecu*, StringWhitelist, int, unsigned char, key, Interpretation)",
    )
