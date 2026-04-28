from __future__ import annotations

from .VagCoding import bit_state, chunk_value6, derive_value6
from .Constants import CORNERING_FIXES, PQ25_SUPPORTED_SETTING_DEFINITIONS
from .Models.Pq25SupportedSetting import Pq25SupportedSetting
from .Types import HexString


def VagCanSettings_getPq25SupportedSettings(coding: HexString) -> list[Pq25SupportedSetting]:
    settings: list[Pq25SupportedSetting] = []
    for key, label, cornering_fix in PQ25_SUPPORTED_SETTING_DEFINITIONS:
        byte_index, bit_index, description = CORNERING_FIXES[cornering_fix]
        current_state = bit_state(coding, byte_index, bit_index)
        chunk_index, byte_start, current_value6 = chunk_value6(coding, byte_index)
        target = derive_value6(coding, 6, None, byte_index, bit_index, "set", description)
        settings.append(
            Pq25SupportedSetting(
                key=key,
                label=label,
                cornering_fix=cornering_fix,
                byte_index=byte_index,
                bit_index=bit_index,
                current_state=current_state,
                desired_state="set",
                chunk_index=chunk_index,
                byte_start=byte_start,
                current_value6=current_value6,
                target_value6=target.value6,
                status="already_enabled" if current_state == "set" else "pending_enable",
            )
        )
    return settings


class VagCanSettings:
    getPq25SupportedSettings = staticmethod(VagCanSettings_getPq25SupportedSettings)