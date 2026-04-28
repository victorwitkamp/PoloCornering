from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString, UdsDid


@dataclass(frozen=True)
class WriteDataByIdentifierRequest:
    did: UdsDid
    payload: HexString
    request: HexString
    label: str