from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString


@dataclass(frozen=True)
class CaristaSettingValueOption:
    label: str
    requested_value: HexString | None
    coding_effect: str
    evidence: str


@dataclass(frozen=True)
class CaristaCustomizationSetting:
    key: str
    label: str
    category: str
    pq25_bits: str
    current_value: str
    possible_values: tuple[CaristaSettingValueOption, ...]
    value_model: str
    read_method: str
    write_method: str
    proof_status: str
    priority: str
    mapping_status: str
    native_string_found: bool
    unresolved: tuple[str, ...]


@dataclass(frozen=True)
class CaristaCustomizationScanReport:
    coding: HexString
    ecu_name: str
    source: str
    settings: tuple[CaristaCustomizationSetting, ...]
    unresolved_priority_settings: tuple[CaristaCustomizationSetting, ...]
    warning: str
