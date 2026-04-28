from __future__ import annotations

from dataclasses import dataclass

from ..Types import HexString


@dataclass(frozen=True)
class DerivedValue:
    value6: HexString
    chunk_index: int
    byte_start: int
    byte_index: int | None = None
    bit_index: int | None = None
    bit_action: str | None = None
    label: str | None = None