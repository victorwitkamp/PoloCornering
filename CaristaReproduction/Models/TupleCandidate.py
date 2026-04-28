from __future__ import annotations

from dataclasses import dataclass

from ..Types import CorneringFixKey, HexString, TupleStatus


@dataclass(frozen=True)
class TupleCandidate:
    key: str
    label: str
    cornering_fix: CorneringFixKey
    value6: HexString
    status: TupleStatus
    request: HexString | None = None
    raw_address4: HexString | None = None
    coding_type: int | None = None
    tail: HexString = ""
    reason: str = ""