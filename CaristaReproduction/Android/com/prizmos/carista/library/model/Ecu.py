from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class Ecu:
    native_id: int | None = None
    name_res_id: str | None = None
    is_obd2: bool | None = None