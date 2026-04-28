from __future__ import annotations

from dataclasses import dataclass

from .Constants import CARISTA_LONG_CODING_DID
from .Types import HexString


@dataclass(frozen=True)
class VagUdsCodingSetting:
    raw_address: int = CARISTA_LONG_CODING_DID
    setting_type: int = 8
    value: HexString = ""


def VagUdsCodingSetting_ctor_ecu_vector(value: HexString) -> VagUdsCodingSetting:
    return VagUdsCodingSetting(value=value)


def VagUdsCodingSetting_ctor_ecu_byte(value: int) -> VagUdsCodingSetting:
    if not 0 <= value <= 0xFF:
        raise ValueError("VagUdsCodingSetting byte value must fit in one byte")
    return VagUdsCodingSetting(value=f"{value:02X}")