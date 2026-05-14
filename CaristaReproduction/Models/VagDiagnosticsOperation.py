from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString


@dataclass(frozen=True)
class VagDiagnosticRequest:
    order: int
    request: HexString
    command_name: str
    ecu_scope: str
    purpose: str
    safety_class: str
    status: str
    included_in_bcm_profile: bool
    evidence: tuple[str, ...]
    unresolved: tuple[str, ...] = ()


@dataclass(frozen=True)
class VagDiagnosticLogFinding:
    response: HexString
    translation: str
    carista_symbol: str
    evidence: tuple[str, ...]
    unresolved: tuple[str, ...] = ()


@dataclass(frozen=True)
class VagDiagnosticTransportFinding:
    topic: str
    carista_behavior: str
    log_evidence: tuple[str, ...]
    implementation_note: str


@dataclass(frozen=True)
class VagDiagnosticsOperationPlan:
    name: str
    vehicle_scope: str
    source: str
    requests: tuple[VagDiagnosticRequest, ...]
    log_findings: tuple[VagDiagnosticLogFinding, ...]
    transport_findings: tuple[VagDiagnosticTransportFinding, ...]
    unresolved: tuple[str, ...]
