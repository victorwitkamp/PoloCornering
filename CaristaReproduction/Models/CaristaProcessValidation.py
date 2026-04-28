from __future__ import annotations

from dataclasses import dataclass

from .CodingValidation import CodingValidation
from .Pq25SupportedSetting import Pq25SupportedSetting
from .RecoveredRequestBuilders import RecoveredRequestBuilders
from .TupleCandidate import TupleCandidate
from .VagEcuInfoWithCoding import VagEcuInfoWithCoding
from .ValidationGate import ValidationGate


@dataclass(frozen=True)
class CaristaProcessValidation:
    requests: RecoveredRequestBuilders
    coding: CodingValidation
    ecu_info: VagEcuInfoWithCoding | None
    supported_settings: list[Pq25SupportedSetting]
    tuple_candidates: list[TupleCandidate]
    gates: list[ValidationGate]