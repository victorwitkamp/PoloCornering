from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString


@dataclass(frozen=True)
class ReadValuesOperationTransportStep:
    order: int
    name: str
    value: str
    purpose: str
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class ReadValuesOperationFlowStep:
    order: int
    native_method: str
    ghidra_address: str
    dispatch: str
    purpose: str
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class ReadValuesOperationGenericToolFlowStep:
    order: int
    native_method: str
    ghidra_address: str
    recovered_behavior: tuple[str, ...]
    evidence: tuple[str, ...]
    unresolved: str = ""


@dataclass(frozen=True)
class ReadValueRequest:
    order: int
    request: HexString
    native_builder: str
    read_path: str
    setting_key: str
    status: str
    included_by_default: bool
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class ReadValuesOperationPlan:
    name: str
    vehicle_scope: str
    source: str
    transport: tuple[ReadValuesOperationTransportStep, ...]
    native_flow: tuple[ReadValuesOperationFlowStep, ...]
    requests: tuple[ReadValueRequest, ...]
    unresolved: tuple[str, ...]


@dataclass(frozen=True)
class SettingValueOption:
    label: str
    requested_value: HexString | None
    coding_effect: str
    evidence: str


@dataclass(frozen=True)
class ReadValuesOperationSetting:
    key: str
    label: str
    category: str
    pq25_bits: str
    current_value: str
    possible_values: tuple[SettingValueOption, ...]
    value_model: str
    read_method: str
    write_method: str
    proof_status: str
    priority: str
    mapping_status: str
    native_string_found: bool
    unresolved: tuple[str, ...]


@dataclass(frozen=True)
class ReadValuesOperationSettingReport:
    coding: HexString
    ecu_name: str
    source: str
    settings: tuple[ReadValuesOperationSetting, ...]
    unresolved_priority_settings: tuple[ReadValuesOperationSetting, ...]
    warning: str
