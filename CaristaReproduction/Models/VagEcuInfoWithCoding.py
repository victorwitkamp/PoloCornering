from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString


@dataclass(frozen=True)
class VagEcuInfoWithCoding:
    response: HexString
    stripped_payload: HexString
    part_number: str
    raw_address4: HexString
    coding_type_selector: HexString
    coding_type: int
    tail: HexString
    initial_value6: HexString
    suffix: HexString
    submodule_payloads: tuple[HexString, ...] = ()