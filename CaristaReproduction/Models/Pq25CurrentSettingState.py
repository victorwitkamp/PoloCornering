from __future__ import annotations

from dataclasses import dataclass

from ..Types import BitState, HexString


@dataclass(frozen=True)
class Pq25CurrentSettingState:
    key: str
    label: str
    byte_index: int
    bit_index: int
    state: BitState
    current_byte: HexString
    confidence: str
    unresolved: tuple[str, ...]