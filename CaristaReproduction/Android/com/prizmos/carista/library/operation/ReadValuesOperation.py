from __future__ import annotations

from dataclasses import dataclass, field
from typing import Mapping

from ..model.Setting import Setting
from ..model.SettingCategory import SettingCategory


@dataclass(frozen=True)
class ReadValuesOperation:
    available_items: Mapping[SettingCategory, tuple[Setting, ...]] = field(default_factory=dict)
    setting_values: Mapping[Setting, bytes] = field(default_factory=dict)

    def getAvailableItems(self) -> Mapping[SettingCategory, tuple[Setting, ...]]:
        return self.available_items

    def getSettingValue(self, setting: Setting) -> bytes | None:
        return self.setting_values.get(setting)