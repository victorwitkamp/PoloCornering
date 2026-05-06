from __future__ import annotations

import argparse
import csv
import json
import re
from dataclasses import asdict, dataclass
from datetime import date
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parent
WORKSPACE_ROOT = ROOT.parent
DOCS_ROOT = WORKSPACE_ROOT / "docs" / "carista_apk_analysis"
SUPPORTED_SETTINGS_JSON = ROOT / "carista_supported_settings_map.json"
DEFAULT_XPL = WORKSPACE_ROOT / "obd-on-pc" / "lcode" / "pq25_6r0_937_08x_cornering_candidates.xpl"

CURRENT_CODING = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
SUPPLIED_REFERENCE_CODING = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"

READ_LONG_CODING_METHOD = "TP2.0 unit 20 direct read 220600; positive response is 620600 + 30-byte coding"
UDS_FULL_CODING_WRITE_METHOD = (
    "Validated guarded path: 2EF199 date, inline 22F1A5, 2EF198 workshop code, "
    "then 2E0600 + full 30-byte coding. The former live runner was removed after use."
)
COMPACT_CARISTA_WRITE_METHOD = (
    "Native Carista setting path appears to build 3B9A + 6-byte value + 4-byte rawAddress4 + tail; "
    "rawAddress4/coding type/tail are not recovered for this BCM"
)
UDS_RAW_VALUE_WRITE_METHOD = (
    "Native Carista type 7/8 raw-value settings dispatch to WriteDataByIdentifier 2E<DID> after F199/F198; "
    "055C/055D type 7 direct reads returned 7F2231 live, so no safe raw payload seed is available for those settings"
)
ADAPTATION_WRITE_METHOD = (
    "Carista VAG CAN adaptation/routine path is 31B8/31BA/31B9/31BA/32B8 with short id 0103 and long id 010A; "
    "native proof applies to raw types 0/1, not the recovered 055C/055D raw type 7 settings"
)


@dataclass(frozen=True)
class Candidate:
    byte_index: int
    bit_index: int
    label: str
    confidence: str
    source: str


@dataclass(frozen=True)
class SettingHint:
    bit_refs: tuple[tuple[int, int], ...]
    mapping_status: str
    value_model: str
    write_method: str
    proof_status: str
    priority: str
    notes: str


@dataclass(frozen=True)
class LongCodingBitRow:
    byte_index: int
    bit_index: int
    current_byte: str
    current_state: str
    supplied_reference_byte: str
    supplied_reference_state: str
    differs_from_supplied_reference: bool
    candidate_label: str
    candidate_confidence: str
    candidate_source: str
    carista_keys: str
    carista_labels: str
    mapping_status: str
    read_method: str
    write_method: str
    tested_status: str
    notes: str


@dataclass(frozen=True)
class SettingCatalogRow:
    key: str
    label: str
    category: str
    value_hint: str
    resource_id: str
    native_va: str
    native_string_found: bool
    pq25_bits: str
    current_value: str
    supplied_reference_value: str
    mapping_status: str
    value_model: str
    read_method: str
    write_method: str
    proof_status: str
    priority: str
    notes: str


CONFIDENCE_PREFIX = re.compile(r"^\[(?P<confidence>[^\]]+)\]\s*(?P<label>.*)$")


EXTRA_CANDIDATES: tuple[Candidate, ...] = (
    Candidate(0, 0, "Front fog lights installed; weak cross-platform reference only", "low", "docs cross-platform note"),
    Candidate(18, 2, "Cold diagnosis front fog lights active; weak cross-platform reference only", "low", "docs cross-platform note"),
    Candidate(18, 3, "Cold diagnosis rear fog lights active; weak cross-platform reference only", "low", "docs cross-platform note"),
)


SETTING_HINTS: dict[str, SettingHint] = {
    "car_setting_cornering_lights_via_fogs": SettingHint(
        bit_refs=((12, 6),),
        mapping_status="mapped_to_long_coding_candidate_but_live_behavior_ruled_out",
        value_model="boolean; clear/off in baseline, set/on in supplied reference; target value6 6C680ED000C8",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Carista string/native resource plus supplied-reference delta; live writes showed no visible behavior change",
        priority="resolved_for_current_symptom",
        notes="Base fog/cornering enable family. It alone does not explain the delayed front-fog indicator behavior.",
    ),
    "car_setting_cornering_lights_via_fogs_experimental": SettingHint(
        bit_refs=((12, 6),),
        mapping_status="mapped_to_same_bit_as_cornering_lights_via_fogs",
        value_model="boolean; clear/off in baseline, set/on in supplied reference; target value6 6C680ED000C8",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Resource alias for the base fog/cornering setting; live behavior ruled out for visible symptom",
        priority="resolved_for_current_symptom",
        notes="Older/experimental label for the same base fog-cornering function.",
    ),
    "car_setting_use_cornering_lights": SettingHint(
        bit_refs=((12, 6),),
        mapping_status="mapped_to_same_bit_as_cornering_lights_via_fogs",
        value_model="boolean; clear/off in baseline, set/on in supplied reference; target value6 6C680ED000C8",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Generic label family points at byte 12 bit 6, but preferred x86 direct ref is a Ford choice label; live behavior ruled out for visible symptom",
        priority="resolved_for_current_symptom",
        notes="Use the recovered VAG car_setting_cornering_lights_via_fogs branch for PQ25 evidence, not this direct label.",
    ),
    "car_setting_cornering_lights_via_fogs_left": SettingHint(
        bit_refs=(),
        mapping_status="native_vag_uds_adaptation_candidate",
        value_model="choice enum recovered: 00=off, 16=on, 1E=enabled coming-home/leaving-home; inserted at byte offset 5 with mask FF",
        write_method="Native type 7 dispatch reads raw address 055C with ReadRawDataByIdentifierCommand (22055C), but live BCM response was 7F2231; no safe write seed is available",
        proof_status="Ghidra windows show the 055C type-7 branch, but preferred x86 branch selection scopes same-key per-side branches to MQB/MK8 or gateway/MEB, not 6R/PQ25; live 22055C returned 7F2231",
        priority="alternate_vag_path_recovery_target",
        notes="Keep as negative evidence; do not use as the current PQ25 write lead unless a new positive branch path is recovered.",
    ),
    "car_setting_cornering_lights_via_fogs_right": SettingHint(
        bit_refs=(),
        mapping_status="native_vag_uds_adaptation_candidate",
        value_model="choice enum recovered: 00=off, 17=on, 1E=enabled coming-home/leaving-home; inserted at byte offset 5 with mask FF",
        write_method="Native type 7 dispatch reads raw address 055D with ReadRawDataByIdentifierCommand (22055D), but live BCM response was 7F2231; no safe write seed is available",
        proof_status="Ghidra windows show the 055D type-7 branch, but preferred x86 branch selection scopes same-key per-side branches to MQB/MK8 or gateway/MEB, not 6R/PQ25; live 22055D returned 7F2231",
        priority="alternate_vag_path_recovery_target",
        notes="Keep as negative evidence; do not use as the current PQ25 write lead unless a new positive branch path is recovered.",
    ),
    "car_setting_cornerig_lights_with_turn_signal": SettingHint(
        bit_refs=((21, 2),),
        mapping_status="mapped_to_long_coding_candidate_but_live_behavior_ruled_out",
        value_model="boolean; clear/off in baseline, set/on in supplied reference; target value6 412F60A60000",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Typo-preserved Carista string/native resource plus supplied-reference delta; live writes showed no visible behavior change",
        priority="resolved_for_current_symptom",
        notes="Turn-signal-triggered cornering family.",
    ),
    "car_setting_cornering_lights_with_turn_signals": SettingHint(
        bit_refs=((21, 2),),
        mapping_status="mapped_to_same_bit_as_turn_signal_cornering",
        value_model="boolean; clear/off in baseline, set/on in supplied reference; target value6 412F60A60000",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Carista string/native resource plus supplied-reference delta; live behavior ruled out for visible symptom",
        priority="resolved_for_current_symptom",
        notes="Turn-signal-triggered cornering family.",
    ),
    "car_setting_cornering_lights_with_turn_signals_one_touch": SettingHint(
        bit_refs=(),
        mapping_status="direct_label_resolved_non_vag_bmw",
        value_model="not a recovered PQ25 value; preferred x86 direct ref is BMW-only",
        write_method="No VW/PQ25 write method recovered; direct x86 path is BmwESetting",
        proof_status="Official x86 0x00d39204 is in BmwESettings::getSettings with BmwESetting constructor calls, not VagCanSettings::getSettings",
        priority="resolved_non_pq25_direct_label",
        notes="Search for an alternate VAG key only if one-touch behavior becomes relevant.",
    ),
    "car_setting_coming_home_via_fogs": SettingHint(
        bit_refs=((13, 6),),
        mapping_status="mapped_to_external_pq25_candidate",
        value_model="boolean/choice; external labels say 0=fog lights, 1=low beam; baseline and supplied reference are set",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Public PQ25 label evidence; not central to current cornering symptom",
        priority="low_context",
        notes="Coming/leaving-home output selector, not front-fog command timing.",
    ),
    "car_setting_coming_home_via_low_beams": SettingHint(
        bit_refs=((13, 6),),
        mapping_status="mapped_to_external_pq25_candidate",
        value_model="boolean/choice; external labels say 0=fog lights, 1=low beam; baseline and supplied reference are set",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Public PQ25 label evidence; not central to current cornering symptom",
        priority="low_context",
        notes="Same candidate bit as coming-home via fogs, interpreted as the alternate choice.",
    ),
    "car_setting_coming_leaving_home_output": SettingHint(
        bit_refs=((13, 6),),
        mapping_status="mapped_to_external_pq25_candidate",
        value_model="choice setting; exact Carista value enum unresolved",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Public PQ25 label evidence; not central to current cornering symptom",
        priority="low_context",
        notes="Coming/leaving-home output selector.",
    ),
    "car_setting_assist_dr_lights": SettingHint(
        bit_refs=((22, 5),),
        mapping_status="mapped_to_external_pq25_candidate",
        value_model="boolean; baseline and supplied reference are clear",
        write_method=UDS_FULL_CODING_WRITE_METHOD,
        proof_status="Candidate-only ADL mapping; not changed by supplied reference",
        priority="low_context",
        notes="Assistant Driving Light / ADL candidate.",
    ),
    "car_setting_left_fog_light_as": SettingHint(
        bit_refs=(),
        mapping_status="direct_label_resolved_non_vag_ford",
        value_model="not a recovered PQ25 value; preferred x86 direct ref is Ford-only",
        write_method="No VW/PQ25 write method recovered; direct x86 path is FordUdsSetting",
        proof_status="Official x86 0x00e73135 is in FordSettings::getSettings with a FordUdsSetting constructor, not VagCanSettings::getSettings",
        priority="alternate_vag_path_recovery_target",
        notes="The visible label still describes the symptom area, but the direct key is not the VW implementation.",
    ),
    "car_setting_right_fog_light_as": SettingHint(
        bit_refs=(),
        mapping_status="direct_label_resolved_non_vag_ford",
        value_model="not a recovered PQ25 value; preferred x86 direct ref is Ford-only",
        write_method="No VW/PQ25 write method recovered; direct x86 path is FordUdsSetting",
        proof_status="Official x86 0x00e7376f is in FordSettings::getSettings with a FordUdsSetting constructor, not VagCanSettings::getSettings",
        priority="alternate_vag_path_recovery_target",
        notes="The visible label still describes the symptom area, but the direct key is not the VW implementation.",
    ),
    "car_setting_left_fog_light": SettingHint(
        bit_refs=(),
        mapping_status="app_visible_group_label_unmapped",
        value_model="group/label; not itself a proven write target",
        write_method="none recovered",
        proof_status="Resource/native string exists only",
        priority="context",
        notes="Parent/group label for left fog-light settings.",
    ),
    "car_setting_right_fog_light": SettingHint(
        bit_refs=(),
        mapping_status="app_visible_group_label_unmapped",
        value_model="group/label; not itself a proven write target",
        write_method="none recovered",
        proof_status="Resource/native string exists only",
        priority="context",
        notes="Parent/group label for right fog-light settings.",
    ),
}


POSSIBLE_RELATED_KEY_HINTS: tuple[tuple[str, SettingHint], ...] = (
    (
        "bulb_check_front_left_fog_lights",
        SettingHint(
            bit_refs=(),
            mapping_status="lighting_diagnostic_setting_unmapped",
            value_model="unknown; likely boolean diagnostic/cold-check setting",
            write_method=UDS_RAW_VALUE_WRITE_METHOD,
            proof_status="Carista resource/native string exists, but no PQ25 bit or DID recovered",
            priority="medium_if_diagnostics_are_suspect",
            notes="May relate to low-confidence lamp-diagnostic candidates, but no exact bit proof.",
        ),
    ),
    (
        "bulb_check_front_right_fog_lights",
        SettingHint(
            bit_refs=(),
            mapping_status="lighting_diagnostic_setting_unmapped",
            value_model="unknown; likely boolean diagnostic/cold-check setting",
            write_method=UDS_RAW_VALUE_WRITE_METHOD,
            proof_status="Carista resource/native string exists, but no PQ25 bit or DID recovered",
            priority="medium_if_diagnostics_are_suspect",
            notes="May relate to low-confidence lamp-diagnostic candidates, but no exact bit proof.",
        ),
    ),
)


def clean_label(label: str) -> str:
    return " ".join(label.replace("\n", " ").split())


def state(coding: bytes, byte_index: int, bit_index: int) -> str:
    return "set" if coding[byte_index] & (1 << bit_index) else "clear"


def chunk_value(coding: bytes, byte_index: int, chunk_size: int = 6) -> str:
    start = byte_index - (byte_index % chunk_size)
    return coding[start:start + chunk_size].hex().upper()


def bit_ref_text(bit_refs: tuple[tuple[int, int], ...]) -> str:
    return "; ".join(f"byte {byte_index} bit {bit_index}" for byte_index, bit_index in bit_refs)


def parse_xpl(path: Path) -> dict[tuple[int, int], Candidate]:
    candidates: dict[tuple[int, int], Candidate] = {}
    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith(";") or not line.startswith("LC,"):
            continue
        parts = [part.strip() for part in line.split(",")]
        if len(parts) < 4 or "~" in parts[2] or "-" in parts[2]:
            continue
        description = ",".join(parts[3:]).strip()
        confidence = "unknown"
        match = CONFIDENCE_PREFIX.match(description)
        if match:
            confidence = match.group("confidence")
            description = match.group("label").strip()
        candidate = Candidate(
            byte_index=int(parts[1], 10),
            bit_index=int(parts[2], 10),
            label=description,
            confidence=confidence,
            source=str(path.relative_to(WORKSPACE_ROOT)),
        )
        candidates[(candidate.byte_index, candidate.bit_index)] = candidate
    for candidate in EXTRA_CANDIDATES:
        candidates.setdefault((candidate.byte_index, candidate.bit_index), candidate)
    return candidates


def load_supported_settings(path: Path) -> list[dict[str, Any]]:
    payload = json.loads(path.read_text(encoding="utf-8"))
    rows = payload.get("rows")
    if not isinstance(rows, list):
        raise ValueError(f"expected rows list in {path}")
    return [row for row in rows if isinstance(row, dict)]


def hint_for_key(key: str) -> SettingHint | None:
    if key in SETTING_HINTS:
        return SETTING_HINTS[key]
    short_key = key.removeprefix("car_setting_")
    for needle, hint in POSSIBLE_RELATED_KEY_HINTS:
        if needle in short_key:
            return hint
    return None


def build_setting_rows(settings: list[dict[str, Any]], current: bytes, supplied_reference: bytes) -> list[SettingCatalogRow]:
    rows: list[SettingCatalogRow] = []
    for setting in sorted(settings, key=lambda item: str(item.get("key", ""))):
        key = str(setting.get("key", ""))
        label = clean_label(str(setting.get("label", "")))
        hint = hint_for_key(key)
        bit_refs = hint.bit_refs if hint else ()
        current_value = "; ".join(
            f"{state(current, byte_index, bit_index)} ({chunk_value(current, byte_index)})"
            for byte_index, bit_index in bit_refs
        )
        supplied_reference_value = "; ".join(
            f"{state(supplied_reference, byte_index, bit_index)} ({chunk_value(supplied_reference, byte_index)})"
            for byte_index, bit_index in bit_refs
        )
        category = str(setting.get("category", ""))
        is_lighting = category.startswith("lighting_")
        rows.append(
            SettingCatalogRow(
                key=key,
                label=label,
                category=category,
                value_hint=str(setting.get("value_hint", "")),
                resource_id=str(setting.get("resource_id", "")),
                native_va=str(setting.get("native_va", "")),
                native_string_found=bool(setting.get("native_string_found")),
                pq25_bits=bit_ref_text(bit_refs),
                current_value=current_value,
                supplied_reference_value=supplied_reference_value,
                mapping_status=hint.mapping_status if hint else ("app_visible_lighting_unmapped" if is_lighting else "app_visible_unmapped"),
                value_model=hint.value_model if hint else "unknown; runtime Setting object/value enum not recovered",
                read_method=READ_LONG_CODING_METHOD if bit_refs else "Runtime ReadValuesOperation support/value method not recovered offline",
                write_method=hint.write_method if hint else "unknown; native Setting object/raw key not recovered",
                proof_status=hint.proof_status if hint else "Carista resource/native string inventory only; not proved supported on this BCM",
                priority=hint.priority if hint else ("review_if_lighting_related" if is_lighting else "not_current_focus"),
                notes=hint.notes if hint else "Included for completeness because it is app-visible in Carista resources.",
            )
        )
    return rows


def build_bit_rows(
    candidates: dict[tuple[int, int], Candidate],
    settings: list[SettingCatalogRow],
    current: bytes,
    supplied_reference: bytes,
) -> list[LongCodingBitRow]:
    settings_by_bit: dict[tuple[int, int], list[SettingCatalogRow]] = {}
    for setting in settings:
        for match in re.finditer(r"byte (\d+) bit (\d+)", setting.pq25_bits):
            key = (int(match.group(1)), int(match.group(2)))
            settings_by_bit.setdefault(key, []).append(setting)

    rows: list[LongCodingBitRow] = []
    for byte_index in range(len(current)):
        for bit_index in range(8):
            key = (byte_index, bit_index)
            candidate = candidates.get(key)
            mapped_settings = settings_by_bit.get(key, [])
            current_state = state(current, byte_index, bit_index)
            reference_state = state(supplied_reference, byte_index, bit_index)
            differs = current_state != reference_state
            if key in {(12, 6), (21, 2)}:
                tested_status = "live written both ways and behavior unchanged; do not retest blindly"
            elif candidate:
                tested_status = "not live-isolated"
            else:
                tested_status = "not a candidate"

            if mapped_settings:
                mapping_status = "; ".join(sorted({setting.mapping_status for setting in mapped_settings}))
                write_method = UDS_FULL_CODING_WRITE_METHOD
                notes = "; ".join(sorted({setting.notes for setting in mapped_settings}))
            elif candidate:
                mapping_status = "long_coding_candidate_without_recovered_carista_setting"
                write_method = UDS_FULL_CODING_WRITE_METHOD
                notes = "Candidate label exists, but no exact Carista Setting object/key is recovered."
            else:
                mapping_status = "unknown_long_coding_bit"
                write_method = "not recommended; no label or Carista evidence"
                notes = "No current evidence maps this bit to a Carista setting."

            rows.append(
                LongCodingBitRow(
                    byte_index=byte_index,
                    bit_index=bit_index,
                    current_byte=f"{current[byte_index]:02X}",
                    current_state=current_state,
                    supplied_reference_byte=f"{supplied_reference[byte_index]:02X}",
                    supplied_reference_state=reference_state,
                    differs_from_supplied_reference=differs,
                    candidate_label=candidate.label if candidate else "",
                    candidate_confidence=candidate.confidence if candidate else "",
                    candidate_source=candidate.source if candidate else "",
                    carista_keys="; ".join(setting.key for setting in mapped_settings),
                    carista_labels="; ".join(setting.label for setting in mapped_settings),
                    mapping_status=mapping_status,
                    read_method=READ_LONG_CODING_METHOD,
                    write_method=write_method,
                    tested_status=tested_status,
                    notes=notes,
                )
            )
    return rows


def setting_table(rows: list[SettingCatalogRow]) -> list[str]:
    lines = [
        "| Key | Label | Bits | Current | Reference | Status | Priority |",
        "|---|---|---|---|---|---|---|",
    ]
    for row in rows:
        lines.append(
            "| "
            + " | ".join(
                [
                    f"`{row.key}`",
                    row.label.replace("|", "\\|"),
                    row.pq25_bits or "-",
                    row.current_value or "-",
                    row.supplied_reference_value or "-",
                    row.mapping_status.replace("|", "\\|"),
                    row.priority,
                ]
            )
            + " |"
        )
    return lines


def bit_table(rows: list[LongCodingBitRow]) -> list[str]:
    lines = [
        "| Byte | Bit | Current | Reference | Candidate | Carista keys | Status | Tested |",
        "|---:|---:|---|---|---|---|---|---|",
    ]
    for row in rows:
        lines.append(
            "| "
            + " | ".join(
                [
                    str(row.byte_index),
                    str(row.bit_index),
                    f"{row.current_byte} {row.current_state}",
                    f"{row.supplied_reference_byte} {row.supplied_reference_state}",
                    (f"[{row.candidate_confidence}] {row.candidate_label}" if row.candidate_label else "-"),
                    row.carista_keys or "-",
                    row.mapping_status,
                    row.tested_status,
                ]
            )
            + " |"
        )
    return lines


def write_csv(path: Path, rows: list[Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    if not rows:
        path.write_text("", encoding="utf-8")
        return
    with path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(asdict(rows[0]).keys()))
        writer.writeheader()
        for row in rows:
            writer.writerow(asdict(row))


def build_report(setting_rows: list[SettingCatalogRow], bit_rows: list[LongCodingBitRow]) -> str:
    mapped_settings = [row for row in setting_rows if row.pq25_bits]
    priority_settings = [
        row
        for row in setting_rows
        if row.priority in {
            "highest_recovery_target",
            "high_recovery_target_read_first",
            "medium_recovery_target",
            "alternate_vag_path_recovery_target",
        }
    ]
    lighting_settings = [row for row in setting_rows if row.category.startswith("lighting_")]
    candidate_bits = [row for row in bit_rows if row.candidate_label or row.carista_keys]
    changed_bits = [row for row in bit_rows if row.differs_from_supplied_reference]

    lines = [
        "# PQ25 Carista Setting Catalog",
        "",
        f"Date: {date.today().isoformat()}",
        "",
        "This is an offline catalog for the Polo/PQ25 BCM work. It joins Carista app resources/native strings, the current 30-byte long coding, the supplied/reference coding, and the local PQ25 candidate bit map.",
        "",
        "It is not a Carista live `ReadValuesOperation.getAvailableItems()` dump. Rows marked unmapped are visible in the app resources but not proved supported on this exact BCM.",
        "",
        "## Outputs",
        "",
        "```text",
        "carista_apk_analysis/pq25_carista_settings_catalog.csv",
        "carista_apk_analysis/pq25_carista_longcoding_bits.csv",
        "carista_apk_analysis/pq25_carista_setting_catalog.json",
        "docs/carista_apk_analysis/pq25_carista_setting_catalog.md",
        "```",
        "",
        "## Summary",
        "",
        f"- App-visible Carista setting/resource rows: `{len(setting_rows)}`",
        f"- Lighting-related rows: `{len(lighting_settings)}`",
        f"- Rows mapped to PQ25 long-coding bits: `{len(mapped_settings)}`",
        f"- Long-coding bits emitted: `{len(bit_rows)}`",
        f"- Candidate/mapped long-coding bits: `{len(candidate_bits)}`",
        f"- Bits differing from supplied/reference coding: `{len(changed_bits)}`",
        "",
        "## Current Read/Write Method Boundary",
        "",
        f"- Long coding read: {READ_LONG_CODING_METHOD}.",
        f"- Guarded full-coding write: {UDS_FULL_CODING_WRITE_METHOD}.",
        f"- Native compact Carista setting write: {COMPACT_CARISTA_WRITE_METHOD}.",
        f"- Native UDS raw-value setting write: {UDS_RAW_VALUE_WRITE_METHOD}.",
        f"- Native adaptation/routine path: {ADAPTATION_WRITE_METHOD}.",
        "",
        "## Highest-Value Unresolved Settings",
        "",
        "These are the settings to recover before more in-car writes.",
        "",
        *setting_table(priority_settings),
        "",
        "## Settings Mapped To PQ25 Bits",
        "",
        *setting_table(mapped_settings),
        "",
        "## Candidate Long-Coding Bits",
        "",
        *bit_table(candidate_bits),
        "",
        "## Bits That Differ From The Supplied/Reference Coding",
        "",
        *bit_table(changed_bits),
        "",
        "## Interpretation",
        "",
        "The two bits that differ from the supplied/reference coding are already live-tested and did not visibly change the reported fog/indicator behavior. The best current lead is therefore not another blind flip of byte 12/21, nor the direct `left_fog_light_as` / `right_fog_light_as` resource keys now proven Ford-only on x86. The remaining target is an alternate VW/PQ25 VAG key, availability sub-object, or ReadValuesOperation value path behind equivalent fog-role behavior.",
        "",
        "For every other long-coding bit, this catalog intentionally says `unknown_long_coding_bit` unless there is a local candidate label or a Carista setting key tied to it. That keeps the map useful without turning resource strings into false proof.",
        "",
    ]
    return "\n".join(lines)


def write_outputs(
    setting_rows: list[SettingCatalogRow],
    bit_rows: list[LongCodingBitRow],
    md_output: Path,
    settings_csv: Path,
    bits_csv: Path,
    json_output: Path,
) -> None:
    md_output.parent.mkdir(parents=True, exist_ok=True)
    md_output.write_text(build_report(setting_rows, bit_rows), encoding="utf-8")
    write_csv(settings_csv, setting_rows)
    write_csv(bits_csv, bit_rows)
    payload = {
        "metadata": {
            "date": date.today().isoformat(),
            "current_coding": CURRENT_CODING,
            "supplied_reference_coding": SUPPLIED_REFERENCE_CODING,
            "supported_settings_source": str(SUPPORTED_SETTINGS_JSON.relative_to(WORKSPACE_ROOT)),
            "candidate_xpl_source": str(DEFAULT_XPL.relative_to(WORKSPACE_ROOT)),
            "warning": "Offline catalog; not a live Carista supported-settings dump.",
        },
        "methods": {
            "read_long_coding": READ_LONG_CODING_METHOD,
            "uds_full_coding_write": UDS_FULL_CODING_WRITE_METHOD,
            "compact_carista_write": COMPACT_CARISTA_WRITE_METHOD,
            "uds_raw_value_write": UDS_RAW_VALUE_WRITE_METHOD,
            "adaptation_write": ADAPTATION_WRITE_METHOD,
        },
        "settings": [asdict(row) for row in setting_rows],
        "long_coding_bits": [asdict(row) for row in bit_rows],
    }
    json_output.write_text(json.dumps(payload, indent=2, ensure_ascii=False), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description="Build a PQ25-specific Carista setting and long-coding catalog.")
    parser.add_argument("--supported-settings", type=Path, default=SUPPORTED_SETTINGS_JSON)
    parser.add_argument("--xpl", type=Path, default=DEFAULT_XPL)
    parser.add_argument("--md-output", type=Path, default=DOCS_ROOT / "pq25_carista_setting_catalog.md")
    parser.add_argument("--settings-csv", type=Path, default=ROOT / "pq25_carista_settings_catalog.csv")
    parser.add_argument("--bits-csv", type=Path, default=ROOT / "pq25_carista_longcoding_bits.csv")
    parser.add_argument("--json-output", type=Path, default=ROOT / "pq25_carista_setting_catalog.json")
    args = parser.parse_args()

    current = bytes.fromhex(CURRENT_CODING)
    supplied_reference = bytes.fromhex(SUPPLIED_REFERENCE_CODING)
    if len(current) != len(supplied_reference):
        raise ValueError("current and supplied/reference coding lengths differ")

    source_settings = load_supported_settings(args.supported_settings)
    setting_rows = build_setting_rows(source_settings, current, supplied_reference)
    candidates = parse_xpl(args.xpl)
    bit_rows = build_bit_rows(candidates, setting_rows, current, supplied_reference)
    write_outputs(setting_rows, bit_rows, args.md_output, args.settings_csv, args.bits_csv, args.json_output)

    mapped = sum(1 for row in setting_rows if row.pq25_bits)
    priority = sum(1 for row in setting_rows if row.priority == "highest_recovery_target")
    candidates_count = sum(1 for row in bit_rows if row.candidate_label or row.carista_keys)
    print(f"Wrote {len(setting_rows)} setting rows ({mapped} mapped, {priority} highest-priority unresolved).")
    print(f"Wrote {len(bit_rows)} long-coding bit rows ({candidates_count} candidate/mapped).")
    print(args.md_output)
    print(args.settings_csv)
    print(args.bits_csv)
    print(args.json_output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
