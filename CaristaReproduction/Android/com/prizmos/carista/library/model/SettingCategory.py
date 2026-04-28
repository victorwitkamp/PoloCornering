from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class SettingCategory:
    native_id: int
    name_res_id: str | None = None