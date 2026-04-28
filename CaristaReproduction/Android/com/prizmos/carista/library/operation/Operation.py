from __future__ import annotations

from dataclasses import dataclass



@dataclass(frozen=True)
class Operation:
    native_pointer: int | None = None