from __future__ import annotations

from dataclasses import dataclass

from ..Types import CorneringFixKey


@dataclass(frozen=True)
class Pq25SettingDefinition:
    key: str
    label: str
    cornering_fix: CorneringFixKey
    byte_index: int
    bit_index: int
    ecu_module: str
    java_bridge: str
    native_write_path: str
    confidence: str
    evidence: tuple[str, ...]
    unresolved: tuple[str, ...]