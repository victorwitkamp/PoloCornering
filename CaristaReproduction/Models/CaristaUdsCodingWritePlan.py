from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString
from .WriteDataByIdentifierRequest import WriteDataByIdentifierRequest


@dataclass(frozen=True)
class CaristaUdsCodingWritePlan:
    current_coding: HexString
    target_coding: HexString
    date_payload: HexString
    workshop_code_payload: HexString
    requests: list[WriteDataByIdentifierRequest]
    changed_bytes: dict[int, tuple[HexString, HexString]]