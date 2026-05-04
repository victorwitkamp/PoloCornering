from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any

from .Models.CaristaCustomization import (
    CaristaCustomizationScanReport,
    CaristaCustomizationSetting,
    CaristaSettingValueOption,
)
from .Types import HexString
from .VagCanSettings import VagCanSettings_getPq25SettingRecoveries, VagCanSettingsSettingRecovery
from .VagCoding import bit_state, normalize_coding


DEFAULT_PQ25_CATALOG_PATH = Path(__file__).resolve().parents[1] / "carista_apk_analysis" / "pq25_carista_setting_catalog.json"
PQ25_BIT_RE = re.compile(r"byte\s+(?P<byte>\d+)\s+bit\s+(?P<bit>\d+)", re.IGNORECASE)
CARISTA_INSTRUCTION_CHOICE_LABELS: dict[str, tuple[str, ...]] = {
    "car_setting_fog_when": ("Cornering lights", "Use DRL via fog and cornering lights"),
    "car_setting_left_fog_light_as": ("Cornering lights", "Use DRL via fog and cornering lights"),
    "car_setting_right_fog_light_as": ("Cornering lights", "Use DRL via fog and cornering lights"),
}
VAG_CAN_SETTINGS_RECOVERIES = {recovery.key: recovery for recovery in VagCanSettings_getPq25SettingRecoveries()}


def _catalog_settings(path: Path) -> list[dict[str, Any]]:
    data = json.loads(path.read_text(encoding="utf-8"))
    settings = data.get("settings")
    if not isinstance(settings, list):
        raise ValueError(f"{path} does not contain a settings list")
    return [setting for setting in settings if isinstance(setting, dict)]


def _boolish(value: object) -> bool:
    return value is True or (isinstance(value, str) and value.lower() == "true")


def _text(setting: dict[str, Any], key: str) -> str:
    value = setting.get(key, "")
    return value if isinstance(value, str) else ""


def _setting_priority(setting: dict[str, Any]) -> tuple[int, str]:
    priority = _text(setting, "priority")
    rank = {
        "highest_recovery_target": 0,
        "medium_recovery_target": 1,
        "resolved_for_current_symptom": 2,
        "review_if_lighting_related": 3,
        "low_context": 4,
        "not_current_focus": 5,
    }.get(priority, 6)
    return rank, _text(setting, "key")


def _is_relevant(setting: dict[str, Any]) -> bool:
    priority = _text(setting, "priority")
    mapping_status = _text(setting, "mapping_status")
    key = _text(setting, "key")
    return (
        priority in {
            "highest_recovery_target",
            "medium_recovery_target",
            "resolved_for_current_symptom",
            "review_if_lighting_related",
            "low_context",
        }
        or mapping_status.startswith("mapped_")
        or "corner" in key
        or "fog_when" in key
        or "fog_light_as" in key
    )


def _current_value_from_coding(setting: dict[str, Any], coding: HexString) -> str:
    match = PQ25_BIT_RE.search(_text(setting, "pq25_bits"))
    if not match:
        return _text(setting, "current_value") or "unknown"
    byte_index = int(match.group("byte"))
    bit_index = int(match.group("bit"))
    return bit_state(coding, byte_index, bit_index)


def _setting_recovery(setting: dict[str, Any]) -> VagCanSettingsSettingRecovery | None:
    return VAG_CAN_SETTINGS_RECOVERIES.get(_text(setting, "key"))


def _possible_values(setting: dict[str, Any]) -> tuple[CaristaSettingValueOption, ...]:
    key = _text(setting, "key")
    setting_recovery = _setting_recovery(setting)
    if setting_recovery and setting_recovery.choices:
        return tuple(
            CaristaSettingValueOption(
                label=choice.key,
                requested_value=choice.requested_value,
                coding_effect="unknown until Carista raw payload/readback is recovered",
                evidence=choice.evidence,
            )
            for choice in setting_recovery.choices
        )

    if key in CARISTA_INSTRUCTION_CHOICE_LABELS:
        return tuple(
            CaristaSettingValueOption(
                label=label,
                requested_value=None,
                coding_effect="unknown",
                evidence="Carista instruction text names this choice; native requested byte[] and coding/adaptation effect are not recovered.",
            )
            for label in CARISTA_INSTRUCTION_CHOICE_LABELS[key]
        )

    bits = _text(setting, "pq25_bits")
    if PQ25_BIT_RE.search(bits):
        return (
            CaristaSettingValueOption(
                label="clear",
                requested_value=None,
                coding_effect=f"{bits} clear",
                evidence="Derived from the mapped long-coding bit only; Carista requested byte[] is not recovered.",
            ),
            CaristaSettingValueOption(
                label="set",
                requested_value=None,
                coding_effect=f"{bits} set",
                evidence="Derived from the mapped long-coding bit only; Carista requested byte[] is not recovered.",
            ),
        )

    return (
        CaristaSettingValueOption(
            label="unknown",
            requested_value=None,
            coding_effect="unknown",
            evidence="Native Setting interpretation/value enum is not recovered for this setting.",
        ),
    )


def _unresolved(setting: dict[str, Any]) -> tuple[str, ...]:
    unresolved = [
        _text(setting, "value_model"),
        _text(setting, "read_method"),
        _text(setting, "write_method"),
    ]
    setting_recovery = _setting_recovery(setting)
    if setting_recovery:
        unresolved.append(setting_recovery.next_re_step)
    return tuple(
        item
        for item in unresolved
        if item and ("not recovered" in item.lower() or "unknown" in item.lower() or "unresolved" in item.lower())
    )


def _value_model(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    if setting_recovery and setting_recovery.choices:
        labels = ", ".join(
            f"{choice.requested_value or '?'}={choice.key}" for choice in setting_recovery.choices
        )
        return f"native choices recovered: {labels}"
    return _text(setting, "value_model")


def _read_method(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    return setting_recovery.read_method if setting_recovery else _text(setting, "read_method")


def _write_method(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    return setting_recovery.write_method if setting_recovery else _text(setting, "write_method")


def _proof_status(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    if not setting_recovery:
        return _text(setting, "proof_status")
    evidence = "; ".join(setting_recovery.evidence)
    return f"{setting_recovery.constructor_status}: {evidence}"


def _mapping_status(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    return setting_recovery.constructor_status if setting_recovery else _text(setting, "mapping_status")


def build_pq25_customization_scan_report(
    coding: HexString,
    catalog_path: Path = DEFAULT_PQ25_CATALOG_PATH,
) -> CaristaCustomizationScanReport:
    normalized = normalize_coding(coding)
    settings = [
        CaristaCustomizationSetting(
            key=_text(setting, "key"),
            label=_text(setting, "label"),
            category=_text(setting, "category"),
            pq25_bits=_text(setting, "pq25_bits"),
            current_value=_current_value_from_coding(setting, normalized),
            possible_values=_possible_values(setting),
            value_model=_value_model(setting),
            read_method=_read_method(setting),
            write_method=_write_method(setting),
            proof_status=_proof_status(setting),
            priority=_text(setting, "priority"),
            mapping_status=_mapping_status(setting),
            native_string_found=_boolish(setting.get("native_string_found")),
            unresolved=_unresolved(setting),
        )
        for setting in sorted(_catalog_settings(catalog_path), key=_setting_priority)
        if _is_relevant(setting)
    ]
    unresolved_priority = tuple(
        setting
        for setting in settings
        if setting.priority in {"highest_recovery_target", "medium_recovery_target"}
    )
    return CaristaCustomizationScanReport(
        coding=normalized,
        ecu_name="PQ25 BCM / unit 09 / 6R0937087K",
        source=str(catalog_path),
        settings=tuple(settings),
        unresolved_priority_settings=unresolved_priority,
        warning="Offline Carista catalog view. It is not a live ReadValuesOperation.getAvailableItems() dump.",
    )
