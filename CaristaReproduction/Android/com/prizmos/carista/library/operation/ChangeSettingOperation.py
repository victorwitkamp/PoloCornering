from __future__ import annotations

from dataclasses import dataclass

from ..model.Setting import Setting
from .ReadValuesOperation import ReadValuesOperation


@dataclass(frozen=True)
class ChangeSettingOperation:
    setting: Setting
    value: bytes
    read_values_operation: ReadValuesOperation
    native_pointer: int | None = None