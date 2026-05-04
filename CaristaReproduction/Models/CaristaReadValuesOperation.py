from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString


@dataclass(frozen=True)
class CaristaTransportStep:
    order: int
    name: str
    value: str
    purpose: str
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class CaristaReadValuesFlowStep:
    order: int
    native_method: str
    ghidra_address: str
    dispatch: str
    purpose: str
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class CaristaReadValueRequest:
    order: int
    request: HexString
    native_builder: str
    read_path: str
    setting_key: str
    status: str
    included_by_default: bool
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class CaristaReadValuesPlan:
    name: str
    vehicle_scope: str
    source: str
    transport: tuple[CaristaTransportStep, ...]
    native_flow: tuple[CaristaReadValuesFlowStep, ...]
    requests: tuple[CaristaReadValueRequest, ...]
    unresolved: tuple[str, ...]
