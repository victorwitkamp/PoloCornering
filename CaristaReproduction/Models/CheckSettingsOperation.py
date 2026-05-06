from __future__ import annotations

from dataclasses import dataclass

from .ReadValuesOperation import ReadValuesOperationPlan, ReadValuesOperationSettingReport
from .VagCanEcu import VagCanEcuScanPlan


@dataclass(frozen=True)
class CheckSettingsOperationFlowStep:
    order: int
    native_method: str
    java_bridge: str
    ghidra_address: str
    recovered_call: str
    purpose: str
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class CheckSettingsOperationPlan:
    name: str
    vehicle_scope: str
    source: str
    native_flow: tuple[CheckSettingsOperationFlowStep, ...]
    vag_can_ecu_scan_plan: VagCanEcuScanPlan
    read_values_operation_plan: ReadValuesOperationPlan
    read_values_operation_setting_report: ReadValuesOperationSettingReport | None
    unresolved: tuple[str, ...]