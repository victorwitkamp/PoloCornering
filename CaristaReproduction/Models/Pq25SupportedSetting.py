from __future__ import annotations

from dataclasses import dataclass

from ..Types import BitState, CorneringFixKey, HexString, SettingStatus


@dataclass(frozen=True)
class Pq25SupportedSetting:
    key: str
    label: str
    cornering_fix: CorneringFixKey
    byte_index: int
    bit_index: int
    current_state: BitState
    desired_state: BitState
    chunk_index: int
    byte_start: int
    current_value6: HexString
    target_value6: HexString
    status: SettingStatus