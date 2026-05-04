from __future__ import annotations

from .Models.Pq25CurrentSettingState import Pq25CurrentSettingState
from .Types import HexString
from .VagCanSettings import VagCanSettings_getPq25SettingDefinitions
from .VagCoding import bit_state, normalize_coding


UNMODELED_CARISTA_GROUPS: tuple[str, ...] = (
    "CH/LH fog/low-beam behavior",
    "parking-light group",
    "ADL-ish byte",
)


def pq25_current_setting_states(coding: HexString) -> tuple[Pq25CurrentSettingState, ...]:
    normalized = normalize_coding(coding)
    data = bytes.fromhex(normalized)
    states: list[Pq25CurrentSettingState] = []
    for definition in VagCanSettings_getPq25SettingDefinitions():
        states.append(
            Pq25CurrentSettingState(
                key=definition.key,
                label=definition.label,
                byte_index=definition.byte_index,
                bit_index=definition.bit_index,
                state=bit_state(normalized, definition.byte_index, definition.bit_index),
                current_byte=f"{data[definition.byte_index]:02X}",
                confidence=definition.confidence,
                unresolved=definition.unresolved,
            )
        )
    return tuple(states)