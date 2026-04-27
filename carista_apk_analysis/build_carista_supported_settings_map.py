from __future__ import annotations

import argparse
import csv
import json
import re
import xml.etree.ElementTree as ET
from dataclasses import asdict, dataclass
from datetime import date
from pathlib import Path
from typing import Any

from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parent
VALUES_DIR = ROOT / "reacquire_20260424" / "base_smali" / "res" / "values"
LIB_PATH = ROOT / "reacquire_20260424" / "split_armv7_unpacked" / "lib" / "armeabi-v7a" / "libCarista.so"

CURRENT_CODING = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
KNOWN_GOOD_CODING = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"

SETTING_RE = re.compile(rb"(car_setting_[A-Za-z0-9_]+)\x00")


@dataclass(frozen=True)
class Pq25Mapping:
    location: str
    current_state: str
    known_good_state: str
    current_value6: str
    target_value6: str
    pending_write_target: bool
    confidence: str
    notes: str


@dataclass(frozen=True)
class SettingRow:
    key: str
    label: str
    resource_id: str
    native_va: str
    native_string_found: bool
    category: str
    value_hint: str
    pq25_location: str
    current_state: str
    known_good_state: str
    current_value6: str
    target_value6: str
    pending_write_target: bool
    raw_value_key: str
    raw_address4: str
    coding_type: str
    tail_bytes: str
    write_tuple_status: str
    confidence: str
    notes: str


def normalize_text(text: str) -> str:
    return " ".join(text.replace("\\\"", '"').split())


def parse_strings(path: Path) -> dict[str, str]:
    root = ET.parse(path).getroot()
    labels: dict[str, str] = {}
    for item in root.findall("string"):
        name = item.attrib.get("name", "")
        if name.startswith("car_setting_"):
            labels[name] = normalize_text("".join(item.itertext()))
    return labels


def parse_public_ids(path: Path) -> dict[str, str]:
    root = ET.parse(path).getroot()
    ids: dict[str, str] = {}
    for item in root.findall("public"):
        if item.attrib.get("type") == "string":
            name = item.attrib.get("name", "")
            if name.startswith("car_setting_"):
                ids[name] = item.attrib.get("id", "")
    return ids


class NativeStringIndex:
    def __init__(self, lib_path: Path) -> None:
        self.path = lib_path
        self.data = lib_path.read_bytes()
        self.sections = self._sections()
        self.offset_by_key = self._scan_setting_strings()

    def _sections(self) -> list[tuple[int, int, int]]:
        with self.path.open("rb") as handle:
            elf = ELFFile(handle)
            return [
                (int(section["sh_offset"]), int(section["sh_size"]), int(section["sh_addr"]))
                for section in elf.iter_sections()
            ]

    def _scan_setting_strings(self) -> dict[str, int]:
        offsets: dict[str, int] = {}
        for match in SETTING_RE.finditer(self.data):
            key = match.group(1).decode("ascii")
            offsets.setdefault(key, match.start())
        return offsets

    def virtual_address(self, key: str) -> int | None:
        offset = self.offset_by_key.get(key)
        if offset is None:
            return None
        for section_offset, size, address in self.sections:
            if section_offset <= offset < section_offset + size:
                return address + offset - section_offset
        return None


def bit_state(coding: str, byte_index: int, bit_index: int) -> str:
    value = bytes.fromhex(coding)[byte_index]
    return "set" if value & (1 << bit_index) else "clear"


def chunk_value(coding: str, byte_index: int, chunk_size: int = 6) -> str:
    data = bytes.fromhex(coding)
    start = byte_index - (byte_index % chunk_size)
    return data[start:start + chunk_size].hex().upper()


def known_pq25_mappings() -> dict[str, Pq25Mapping]:
    base = Pq25Mapping(
        location="byte 12 bit 6",
        current_state=bit_state(CURRENT_CODING, 12, 6),
        known_good_state=bit_state(KNOWN_GOOD_CODING, 12, 6),
        current_value6=chunk_value(CURRENT_CODING, 12),
        target_value6=chunk_value(KNOWN_GOOD_CODING, 12),
        pending_write_target=True,
        confidence="high practical / medium static",
        notes="Base fog-light cornering function. The working/non-working coding delta is one bit.",
    )
    turn_signal = Pq25Mapping(
        location="byte 21 bit 2",
        current_state=bit_state(CURRENT_CODING, 21, 2),
        known_good_state=bit_state(KNOWN_GOOD_CODING, 21, 2),
        current_value6=chunk_value(CURRENT_CODING, 21),
        target_value6=chunk_value(KNOWN_GOOD_CODING, 21),
        pending_write_target=True,
        confidence="high practical / medium static",
        notes="Turn-signal-triggered cornering function. The working/non-working coding delta is one bit.",
    )
    ch_lh = Pq25Mapping(
        location="byte 13 bit 6",
        current_state=bit_state(CURRENT_CODING, 13, 6),
        known_good_state=bit_state(KNOWN_GOOD_CODING, 13, 6),
        current_value6=chunk_value(CURRENT_CODING, 13),
        target_value6=chunk_value(KNOWN_GOOD_CODING, 13),
        pending_write_target=False,
        confidence="medium / doc conflict",
        notes="Public PQ25 docs describe CH/LH fog-vs-low-beam selection, but observed Carista UI did not fully match.",
    )
    adl = Pq25Mapping(
        location="byte 22 bit 5",
        current_state=bit_state(CURRENT_CODING, 22, 5),
        known_good_state=bit_state(KNOWN_GOOD_CODING, 22, 5),
        current_value6=chunk_value(CURRENT_CODING, 22),
        target_value6=chunk_value(KNOWN_GOOD_CODING, 22),
        pending_write_target=False,
        confidence="medium-low",
        notes="Likely Assistant Driving Light / ADL related. It did not differ between current and known-good coding.",
    )
    return {
        "car_setting_cornering_lights_via_fogs": base,
        "car_setting_cornering_lights_via_fogs_experimental": base,
        "car_setting_use_cornering_lights": base,
        "car_setting_cornerig_lights_with_turn_signal": turn_signal,
        "car_setting_cornering_lights_with_turn_signals": turn_signal,
        "car_setting_coming_home_via_fogs": ch_lh,
        "car_setting_coming_home_via_low_beams": ch_lh,
        "car_setting_coming_leaving_home_output": ch_lh,
        "car_setting_assist_dr_lights": adl,
    }


def infer_category(key: str, label: str) -> str:
    haystack = f"{key} {label}".lower()
    checks = [
        ("lighting_cornering", ("cornering",)),
        ("lighting_coming_leaving_home", ("coming_home", "leaving_home", "coming/leaving")),
        ("lighting_fog", ("fog", "nebel", "fendinebbia")),
        ("lighting_drl_adl", ("drl", "daytime", "assist_dr", "adl")),
        ("lighting_parking", ("parking_light", "parking lights", "position light")),
        ("lighting_general", ("light", "headlamp", "headlight", "beam", "bulb")),
        ("locking", ("lock", "unlock", "door")),
        ("windows_mirrors", ("window", "mirror")),
        ("wipers", ("wiper", "washer", "rain")),
        ("instrument_cluster", ("cluster", "dashboard", "dash", "obc", "instrument")),
        ("parking_assist", ("parking_sensor", "park assist", "rear view", "camera")),
        ("comfort", ("seat", "comfort", "climate", "ac_", "air_conditioning")),
        ("driver_assistance", ("lane", "traffic", "collision", "cruise", "sign recognition")),
        ("engine_drivetrain", ("engine", "gearbox", "start_stop", "transmission")),
        ("service_tpms", ("service", "tpms", "tire", "tyre")),
        ("sound_chime", ("beep", "chime", "honk", "horn", "sound")),
    ]
    for category, needles in checks:
        if any(needle in haystack for needle in needles):
            return category
    return "app_catalog"


def infer_value_hint(key: str, label: str) -> str:
    simple_key = key.removeprefix("car_setting_")
    value_like = {
        "0",
        "1",
        "2",
        "3",
        "yes",
        "no",
        "on",
        "off",
        "enabled",
        "disabled",
        "active",
        "inactive",
        "low",
        "medium",
        "high",
        "variant_1",
        "variant_2",
        "variant_3",
    }
    if simple_key in value_like or simple_key.startswith(("yes_", "no_", "on_", "off_")):
        return "choice/value label"
    text = f"{key} {label}".lower()
    if any(word in text for word in ("duration", "brightness", "speed", "threshold", "angle", "volume")):
        return "numeric setting label"
    if "..." in label or label.endswith(" use"):
        return "choice setting label"
    return "setting/category label"


def build_rows(labels: dict[str, str], ids: dict[str, str], native: NativeStringIndex) -> list[SettingRow]:
    mappings = known_pq25_mappings()
    rows: list[SettingRow] = []
    for key in sorted(labels):
        mapping = mappings.get(key)
        native_va = native.virtual_address(key)
        if mapping:
            write_tuple_status = (
                "candidate value chunk known; rawAddress4/coding tail unknown"
                if mapping.pending_write_target
                else "mapped location only; not a pending write target"
            )
            confidence = mapping.confidence
            notes = mapping.notes
        else:
            write_tuple_status = "not mapped to this BCM"
            confidence = "unmapped"
            notes = "App-visible Carista resource string. Runtime vehicle support is selected by native availability checks."
        rows.append(
            SettingRow(
                key=key,
                label=labels[key],
                resource_id=ids.get(key, ""),
                native_va=f"0x{native_va:08X}" if native_va is not None else "",
                native_string_found=native_va is not None,
                category=infer_category(key, labels[key]),
                value_hint=infer_value_hint(key, labels[key]),
                pq25_location=mapping.location if mapping else "",
                current_state=mapping.current_state if mapping else "",
                known_good_state=mapping.known_good_state if mapping else "",
                current_value6=mapping.current_value6 if mapping else "",
                target_value6=mapping.target_value6 if mapping and mapping.pending_write_target else "",
                pending_write_target=mapping.pending_write_target if mapping else False,
                raw_value_key="unknown",
                raw_address4="unknown",
                coding_type="unknown",
                tail_bytes="unknown",
                write_tuple_status=write_tuple_status,
                confidence=confidence,
                notes=notes,
            )
        )
    return rows


def category_counts(rows: list[SettingRow]) -> dict[str, int]:
    counts: dict[str, int] = {}
    for row in rows:
        counts[row.category] = counts.get(row.category, 0) + 1
    return dict(sorted(counts.items(), key=lambda item: (-item[1], item[0])))


def markdown_table(rows: list[SettingRow]) -> list[str]:
    lines = [
        "| Key | Label | PQ25 mapping | Current | Target | Value chunk | Status |",
        "|---|---|---|---|---|---|---|",
    ]
    for row in rows:
        lines.append(
            "| "
            + " | ".join(
                [
                    f"`{row.key}`",
                    row.label.replace("|", "\\|"),
                    row.pq25_location or "-",
                    row.current_state or "-",
                    row.known_good_state or "-",
                    f"`{row.target_value6}`" if row.target_value6 else "-",
                    row.write_tuple_status.replace("|", "\\|"),
                ]
            )
            + " |"
        )
    return lines


def build_report(rows: list[SettingRow]) -> str:
    mapped = [row for row in rows if row.pq25_location]
    lighting = [row for row in rows if row.category.startswith("lighting_")]
    native_count = sum(1 for row in rows if row.native_string_found)
    counts = category_counts(rows)

    lines = [
        "# Carista Supported Settings Map",
        "",
        f"Date: {date.today().isoformat()}",
        "",
        "This is an offline map from the decoded Android resources and `libCarista.so` strings.",
        "It is not a live vehicle availability dump; Carista decides actual support at runtime through native checks.",
        "",
        "## Summary",
        "",
        f"- App resource settings: `{len(rows)}`",
        f"- Also present as native strings: `{native_count}`",
        f"- Lighting-related resource settings: `{len(lighting)}`",
        f"- PQ25 BCM settings mapped with practical confidence: `{len(mapped)}`",
        "",
        "Full searchable outputs:",
        "",
        "```text",
        "carista_supported_settings_map.csv",
        "carista_supported_settings_map.json",
        "```",
        "",
        "## Category Counts",
        "",
        "| Category | Count |",
        "|---|---:|",
    ]
    for category, count in counts.items():
        lines.append(f"| `{category}` | {count} |")

    lines.extend(
        [
            "",
            "## PQ25 BCM Mapped Settings",
            "",
            "These rows are the current useful map for BCM `6R0937087K`. They identify what the setting means in the long coding, but they do not yet contain the complete Carista write tuple.",
            "",
            *markdown_table(mapped),
            "",
            "## Current Tuple Boundary",
            "",
            "The Carista write shape is known:",
            "",
            "```text",
            "3B9A + 6-byte value + 4-byte rawAddress + coding-type-dependent tail",
            "```",
            "",
            "For the two cornering fixes, the likely 6-byte target values are:",
            "",
            "```text",
            "byte 12 bit 6 / base fog-cornering: 6C680ED000C8",
            "byte 21 bit 2 / turn-signal trigger: 412F60A60000",
            "```",
            "",
            "Still unknown for the final write tuple:",
            "",
            "- `raw_value_key`",
            "- `raw_address4`",
            "- `coding_type`",
            "- `tail_bytes`",
            "",
            "## Useful Search Examples",
            "",
            "```powershell",
            "Import-Csv .\\carista_supported_settings_map.csv | Where-Object category -like 'lighting*' | Format-Table key,label,pq25_location",
            "Import-Csv .\\carista_supported_settings_map.csv | Where-Object key -like '*cornering*' | Format-Table key,label,pq25_location,target_value6",
            "Import-Csv .\\carista_supported_settings_map.csv | Where-Object native_string_found -eq 'True' | Measure-Object",
            "```",
        ]
    )
    return "\n".join(lines) + "\n"


def write_outputs(rows: list[SettingRow], md_path: Path, csv_path: Path, json_path: Path) -> None:
    md_path.write_text(build_report(rows), encoding="utf-8")
    with csv_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(asdict(rows[0]).keys()))
        writer.writeheader()
        for row in rows:
            writer.writerow(asdict(row))

    payload: dict[str, Any] = {
        "metadata": {
            "date": date.today().isoformat(),
            "source_values_dir": str(VALUES_DIR),
            "source_native_library": str(LIB_PATH),
            "current_coding": CURRENT_CODING,
            "known_good_coding": KNOWN_GOOD_CODING,
            "note": "Offline app/resource/native-string map, not a live vehicle-supported settings dump.",
        },
        "category_counts": category_counts(rows),
        "rows": [asdict(row) for row in rows],
    }
    json_path.write_text(json.dumps(payload, indent=2, ensure_ascii=False), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description="Build an offline Carista app-visible settings map.")
    parser.add_argument("--values-dir", type=Path, default=VALUES_DIR)
    parser.add_argument("--lib", type=Path, default=LIB_PATH)
    parser.add_argument("--md-output", type=Path, default=ROOT / "carista_supported_settings_map.md")
    parser.add_argument("--csv-output", type=Path, default=ROOT / "carista_supported_settings_map.csv")
    parser.add_argument("--json-output", type=Path, default=ROOT / "carista_supported_settings_map.json")
    args = parser.parse_args()

    labels = parse_strings(args.values_dir / "strings.xml")
    ids = parse_public_ids(args.values_dir / "public.xml")
    native = NativeStringIndex(args.lib)
    rows = build_rows(labels, ids, native)
    write_outputs(rows, args.md_output, args.csv_output, args.json_output)

    mapped = sum(1 for row in rows if row.pq25_location)
    native_count = sum(1 for row in rows if row.native_string_found)
    print(f"Wrote {len(rows)} settings, {native_count} native strings, {mapped} PQ25 mapped rows.")
    print(args.md_output)
    print(args.csv_output)
    print(args.json_output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
