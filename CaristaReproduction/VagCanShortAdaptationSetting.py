from __future__ import annotations

from dataclasses import dataclass

from .ByteUtils import clean_hex, one_byte
from .Types import HexString
from .VagSetting import VagSetting_insertValue


@dataclass(frozen=True)
class VagCanShortAdaptationSetting:
    raw_address: int
    value_offset: int
    value_mask: HexString
    setting_type: int = 0
    native_constructor: str = "VagCanShortAdaptationSetting"
    native_source: str = "recovered from libCarista.so ghidra_adaptation_probe constructor exports"
    proof_notes: tuple[str, ...] = (
        "VagCanShortAdaptationSetting passes type 0 to VagSetting, with raw address/channel from the unsigned-char constructor argument.",
        "Named constructors at 01100074/01100110/01100218/011003D0 confirm the raw-address parameter is uchar even when make_shared wrappers accept int lvalues.",
        "The constructor int is the value offset; the byte/vector argument is the mask vector used by VagSetting::insertValue.",
        "ByteUtils::insertValue shifts compact requested bytes left by getLsbOffset(mask) before merging masked fields.",
        "FullByteVagCanShortAdaptationSetting wraps this constructor with offset 0 and a two-byte FF FF mask.",
        "Type 0 dispatches through the VAG CAN adaptation routine; it is distinct from type 7 UDS adaptation.",
    )

    @property
    def value(self) -> HexString:
        return self.value_mask

    def insert_value(self, current_raw_value: HexString, requested_value: HexString) -> HexString:
        return VagSetting_insertValue(current_raw_value, self.value_offset, self.value_mask, requested_value)


def _validate_raw_address(raw_address: int) -> int:
    if not 0 <= raw_address <= 0xFF:
        raise ValueError("VagCanShortAdaptationSetting raw address/channel must fit in one byte")
    return raw_address


def _validate_value_offset(value_offset: int) -> int:
    if value_offset < 0:
        raise ValueError("VagCanShortAdaptationSetting value offset must be non-negative")
    return value_offset


def VagCanShortAdaptationSetting_generateBitmask(start_bit: int, num_bits: int) -> int:
    if not 0 <= start_bit <= 0x0F:
        raise ValueError(f"Invalid start bit: {start_bit}")
    if num_bits <= 0 or (start_bit & 0x07) + num_bits > 8:
        raise ValueError(f"Invalid numBits: {num_bits}")
    return (((1 << num_bits) - 1) << (start_bit & 0x07)) & 0xFF


def VagCanShortAdaptationSetting_ctor_ecu_vector(
    *,
    raw_address: int,
    value_offset: int,
    value: HexString,
) -> VagCanShortAdaptationSetting:
    return VagCanShortAdaptationSetting(
        raw_address=_validate_raw_address(raw_address),
        value_offset=_validate_value_offset(value_offset),
        value_mask=clean_hex(value, "VagCanShortAdaptationSetting value mask"),
        native_constructor="VagCanShortAdaptationSetting(Ecu*, StringWhitelist, unsigned char, int, vector<unsigned char>, key, Interpretation)",
    )


def VagCanShortAdaptationSetting_ctor_ecu_byte(
    *,
    raw_address: int,
    value_offset: int,
    value: int,
) -> VagCanShortAdaptationSetting:
    return VagCanShortAdaptationSetting(
        raw_address=_validate_raw_address(raw_address),
        value_offset=_validate_value_offset(value_offset),
        value_mask=one_byte(value, "VagCanShortAdaptationSetting byte value mask"),
        native_constructor="VagCanShortAdaptationSetting(Ecu*, StringWhitelist, unsigned char, int, unsigned char, key, Interpretation)",
    )


def VagCanShortAdaptationSetting_ctor_ecu_bitfield(
    *,
    raw_address: int,
    start_bit: int,
    num_bits: int,
) -> VagCanShortAdaptationSetting:
    mask = VagCanShortAdaptationSetting_generateBitmask(start_bit, num_bits)
    return VagCanShortAdaptationSetting(
        raw_address=_validate_raw_address(raw_address),
        value_offset=1 - (start_bit // 8),
        value_mask=one_byte(mask, "VagCanShortAdaptationSetting generated bitmask"),
        native_constructor="VagCanShortAdaptationSetting(Ecu*, StringWhitelist, unsigned char, int startBit, int numBits, key, Interpretation)",
    )


def FullByteVagCanShortAdaptationSetting_ctor(raw_address: int) -> VagCanShortAdaptationSetting:
    return VagCanShortAdaptationSetting(
        raw_address=_validate_raw_address(raw_address),
        value_offset=0,
        value_mask="FFFF",
        native_constructor="FullByteVagCanShortAdaptationSetting(Ecu*, StringWhitelist, unsigned char, key, Interpretation)",
    )
