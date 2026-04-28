from __future__ import annotations

from dataclasses import dataclass
from .Operation import Operation


@dataclass(frozen=True)
class CheckSettingsOperation:
    operation: Operation
    native_pointer: int | None = None