from __future__ import annotations

from dataclasses import dataclass

from .ByteUtils import clean_hex, one_byte
from .Constants import CARISTA_LONG_CODING_DID
from .Types import HexString
from .VagSetting import VagSetting_insertValue


@dataclass(frozen=True)
class VagUdsCodingSetting:
    raw_address: int = CARISTA_LONG_CODING_DID
    setting_type: int = 8
    value_offset: int = 0
    value_mask: HexString = ""
    native_constructor: str = "VagUdsCodingSetting"
    native_source: str = "recovered from libCarista.so constructor exports"
    proof_notes: tuple[str, ...] = (
        "VagUdsCodingSetting(Ecu, vector) calls VagSetting with type 8 and raw address 0x0600.",
        "The constructor int is passed to VagSetting's offset field; the byte/vector argument is passed as the value mask vector used by VagSetting::insertValue.",
    )

    @property
    def value(self) -> HexString:
        return self.value_mask

    def insert_value(self, current_raw_value: HexString, requested_value: HexString) -> HexString:
        return VagSetting_insertValue(current_raw_value, self.value_offset, self.value_mask, requested_value)


def _validate_value_offset(value_offset: int) -> int:
    if value_offset < 0:
        raise ValueError("VagUdsCodingSetting value offset must be non-negative")
    return value_offset


def VagUdsCodingSetting_ctor_ecu_vector(value: HexString, value_offset: int = 0) -> VagUdsCodingSetting:
    return VagUdsCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=clean_hex(value, "VagUdsCodingSetting value mask"),
        native_constructor="VagUdsCodingSetting(Ecu*, StringWhitelist, int, vector<unsigned char>, key, Interpretation, AvailBy)",
    )


def VagUdsCodingSetting_ctor_ecu_byte(value: int, value_offset: int = 0) -> VagUdsCodingSetting:
    return VagUdsCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=one_byte(value, "VagUdsCodingSetting byte value mask"),
        native_constructor="VagUdsCodingSetting(Ecu*, StringWhitelist, int, unsigned char, key, Interpretation, AvailBy)",
    )


def VagUdsCodingSetting_ctor_ecu_byte_values(value: int, value_offset: int = 0) -> VagUdsCodingSetting:
    return VagUdsCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=one_byte(value, "VagUdsCodingSetting byte value mask"),
        native_constructor="VagUdsCodingSetting(Ecu*, StringWhitelist, int, unsigned char, key, Interpretation, values, AvailBy)",
    )