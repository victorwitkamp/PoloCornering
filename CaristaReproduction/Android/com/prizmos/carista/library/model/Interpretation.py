from __future__ import annotations

from dataclasses import dataclass



@dataclass(frozen=True)
class Interpretation:
    descriptor: str | None = None