from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString


@dataclass(frozen=True)
class VagCanEcu:
    name: str
    ecu_id: str
    tp20_unit_address: HexString
    expected_part_number: str | None
    expected_component: str | None
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class VagCanEcuProbeCommand:
    request: HexString
    native_builder: str
    purpose: str
    read_only: bool


@dataclass(frozen=True)
class VagCanEcuProbe:
    ecu: VagCanEcu
    tp20_open_request: HexString
    expected_send_header: HexString | None
    expected_listen_header: HexString | None
    channel_parameter_request: HexString
    commands: tuple[VagCanEcuProbeCommand, ...]


@dataclass(frozen=True)
class VagCanEcuScanPlan:
    adapter: str
    protocol: str
    discoverable_ecus: tuple[VagCanEcu, ...]
    discovery_flow: tuple[str, ...]
    probes: tuple[VagCanEcuProbe, ...]
    unresolved: tuple[str, ...]
