from __future__ import annotations

from dataclasses import dataclass
from ..Types import HexString


@dataclass(frozen=True)
class CodingValidation:
    length_bytes: int
    value: HexString