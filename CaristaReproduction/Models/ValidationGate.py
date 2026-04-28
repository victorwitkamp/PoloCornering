from __future__ import annotations

from dataclasses import dataclass
from ..Types import GateName, GateStatus


@dataclass(frozen=True)
class ValidationGate:
    name: GateName
    status: GateStatus
    detail: str