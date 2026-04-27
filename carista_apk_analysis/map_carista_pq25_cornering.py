from __future__ import annotations

import argparse
import json
import re
import struct
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from pathlib import Path

from capstone import CS_ARCH_ARM, CS_MODE_THUMB, Cs
from capstone.arm import ARM_OP_MEM, ARM_OP_REG, ARM_REG_PC
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parent
APKTOOL_VALUES = ROOT / "apktool_base_decode" / "res" / "values"
LIB_PATH = ROOT / "reacquire_20260424" / "split_armv7_unpacked" / "lib" / "armeabi-v7a" / "libCarista.so"

CURRENT_CODING = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
KNOWN_GOOD_CODING = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"

CORNERING_KEYS = (
    "car_setting_cornerig_lights_with_turn_signal",
    "car_setting_cornering_lights",
    "car_setting_cornering_lights_activation",
    "car_setting_cornering_lights_via",
    "car_setting_cornering_lights_via_fogs",
    "car_setting_cornering_lights_via_fogs_experimental",
    "car_setting_cornering_lights_via_fogs_left",
    "car_setting_cornering_lights_via_fogs_right",
    "car_setting_cornering_lights_with_turn_signals",
    "car_setting_cornering_lights_with_turn_signals_one_touch",
    "car_setting_use_cornering_lights",
    "car_setting_instruction_activate_cornering_lights",
    "car_setting_instruction_requires_cornering_lights",
)


@dataclass(frozen=True)
class ResourceString:
    key: str
    label: str
    resource_id: str | None
    native_va: int | None
    native_refs: list[str]


@dataclass(frozen=True)
class MappingCandidate:
    key: str
    label: str
    byte_index: int | None
    bit_index: int | None
    confidence: str
    basis: str


def thumb_pc(address: int) -> int:
    return (address + 4) & ~3


class ElfInspector:
    def __init__(self, path: Path) -> None:
        self.path = path
        self.data = path.read_bytes()
        with path.open("rb") as handle:
            self.elf = ELFFile(handle)
            self.sections = [
                (section.name, int(section["sh_addr"]), int(section["sh_offset"]), int(section["sh_size"]))
                for section in self.elf.iter_sections()
            ]
            self.symbols = self._load_symbols()
        self.disassembler = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
        self.disassembler.detail = True

    def _load_symbols(self) -> list[tuple[int, int, str]]:
        symbols: list[tuple[int, int, str]] = []
        for section_name in (".symtab", ".dynsym"):
            section = self.elf.get_section_by_name(section_name)
            if section is None:
                continue
            for symbol in section.iter_symbols():
                if symbol.name and int(symbol["st_size"]) > 0:
                    symbols.append((int(symbol["st_value"]) & ~1, int(symbol["st_size"]), symbol.name))
        return symbols

    def va_to_offset(self, virtual_address: int) -> int:
        virtual_address &= ~1
        for _name, address, offset, size in self.sections:
            if address <= virtual_address < address + size:
                return offset + virtual_address - address
        raise ValueError(f"virtual address not mapped: 0x{virtual_address:X}")

    def offset_to_va(self, offset: int) -> int | None:
        for _name, address, section_offset, size in self.sections:
            if section_offset <= offset < section_offset + size:
                return address + offset - section_offset
        return None

    def read_u32(self, virtual_address: int) -> int:
        return struct.unpack_from("<I", self.data, self.va_to_offset(virtual_address))[0]

    def find_c_string_va(self, text: str) -> int | None:
        offset = self.data.find(text.encode("ascii") + b"\x00")
        if offset < 0:
            return None
        return self.offset_to_va(offset)

    def symbol_name_at(self, address: int) -> str:
        best: tuple[int, int, str] | None = None
        for start, size, name in self.symbols:
            if size and start <= address < start + size:
                return f"{name}+0x{address - start:X}"
            if start <= address and (best is None or start > best[0]):
                best = (start, size, name)
        if best:
            return f"after {best[2]}+0x{address - best[0]:X}"
        return "<unknown>"

    def find_pc_relative_refs(self, target: int) -> list[str]:
        refs: list[str] = []
        for address, size, name in self.symbols:
            if size > 600_000:
                continue
            try:
                code = self.data[self.va_to_offset(address):self.va_to_offset(address) + size]
            except ValueError:
                continue
            instructions = list(self.disassembler.disasm(code, address | 1))
            for index, instruction in enumerate(instructions):
                if instruction.mnemonic != "ldr" or len(instruction.operands) < 2:
                    continue
                first, second = instruction.operands[0], instruction.operands[1]
                if first.type != ARM_OP_REG or second.type != ARM_OP_MEM or second.mem.base != ARM_REG_PC:
                    continue
                destination = first.reg
                literal_address = thumb_pc(instruction.address) + second.mem.disp
                try:
                    relative = self.read_u32(literal_address)
                except ValueError:
                    continue
                for candidate in instructions[index + 1:index + 12]:
                    if not candidate.mnemonic.startswith("add"):
                        continue
                    if not candidate.operands or candidate.operands[0].type != ARM_OP_REG:
                        continue
                    if candidate.operands[0].reg != destination:
                        continue
                    resolved = (thumb_pc(candidate.address) + relative) & 0xFFFFFFFF
                    if resolved == target:
                        refs.append(f"0x{instruction.address:08X}->{candidate.address:08X} {name}")
                    break
        return refs


def parse_public_ids(path: Path) -> dict[str, str]:
    ids: dict[str, str] = {}
    root = ET.parse(path).getroot()
    for item in root.findall("public"):
        if item.attrib.get("type") == "string" and "name" in item.attrib:
            ids[item.attrib["name"]] = item.attrib.get("id", "")
    return ids


def parse_strings(path: Path) -> dict[str, str]:
    labels: dict[str, str] = {}
    root = ET.parse(path).getroot()
    for item in root.findall("string"):
        name = item.attrib.get("name")
        if name:
            labels[name] = "".join(item.itertext())
    return labels


def current_bit_state(byte_index: int, bit_index: int) -> str:
    value = bytes.fromhex(CURRENT_CODING)[byte_index]
    return "set" if value & (1 << bit_index) else "clear"


def known_good_bit_state(byte_index: int, bit_index: int) -> str:
    value = bytes.fromhex(KNOWN_GOOD_CODING)[byte_index]
    return "set" if value & (1 << bit_index) else "clear"


def build_resource_table(inspector: ElfInspector) -> list[ResourceString]:
    labels = parse_strings(APKTOOL_VALUES / "strings.xml")
    ids = parse_public_ids(APKTOOL_VALUES / "public.xml")
    rows: list[ResourceString] = []
    for key in CORNERING_KEYS:
        native_va = inspector.find_c_string_va(key)
        refs = inspector.find_pc_relative_refs(native_va) if native_va is not None else []
        rows.append(
            ResourceString(
                key=key,
                label=labels.get(key, "<missing>"),
                resource_id=ids.get(key),
                native_va=native_va,
                native_refs=refs,
            )
        )
    return rows


def build_mapping_candidates(resources: list[ResourceString]) -> list[MappingCandidate]:
    labels = {item.key: item.label for item in resources}
    return [
        MappingCandidate(
            key="car_setting_cornering_lights_via_fogs",
            label=labels.get("car_setting_cornering_lights_via_fogs", ""),
            byte_index=12,
            bit_index=6,
            confidence="high practical / medium static",
            basis=(
                "The UI label is the exact fog-light cornering wording, and the only working/non-working "
                "coding delta for that function is byte 12 bit 6. Static native analysis has not yet recovered "
                "the concrete Setting object."
            ),
        ),
        MappingCandidate(
            key="car_setting_cornering_lights_via_fogs_experimental",
            label=labels.get("car_setting_cornering_lights_via_fogs_experimental", ""),
            byte_index=12,
            bit_index=6,
            confidence="medium",
            basis="Likely older/alternate Carista key for the same fog-light cornering function.",
        ),
        MappingCandidate(
            key="car_setting_use_cornering_lights",
            label=labels.get("car_setting_use_cornering_lights", ""),
            byte_index=12,
            bit_index=6,
            confidence="medium",
            basis="High-level selector wording; may be a parent/multiple-choice setting rather than the direct bit.",
        ),
        MappingCandidate(
            key="car_setting_cornerig_lights_with_turn_signal",
            label=labels.get("car_setting_cornerig_lights_with_turn_signal", ""),
            byte_index=21,
            bit_index=2,
            confidence="high practical / medium static",
            basis=(
                "This typo-preserved key says 'Activate cornering lights with turn signal'; the known working "
                "delta for turn-signal-triggered cornering is byte 21 bit 2."
            ),
        ),
        MappingCandidate(
            key="car_setting_cornering_lights_with_turn_signals",
            label=labels.get("car_setting_cornering_lights_with_turn_signals", ""),
            byte_index=21,
            bit_index=2,
            confidence="high practical / medium static",
            basis="Clear newer key for the same turn-signal-triggered cornering behavior.",
        ),
        MappingCandidate(
            key="car_setting_cornering_lights",
            label=labels.get("car_setting_cornering_lights", ""),
            byte_index=None,
            bit_index=None,
            confidence="group label",
            basis="Likely category/umbrella label, not enough evidence for one direct byte/bit.",
        ),
        MappingCandidate(
            key="car_setting_cornering_lights_via_fogs_left",
            label=labels.get("car_setting_cornering_lights_via_fogs_left", ""),
            byte_index=None,
            bit_index=None,
            confidence="unknown for this BCM",
            basis="May apply to newer or per-side lamp-channel platforms; no observed distinct delta on this Polo coding.",
        ),
        MappingCandidate(
            key="car_setting_cornering_lights_via_fogs_right",
            label=labels.get("car_setting_cornering_lights_via_fogs_right", ""),
            byte_index=None,
            bit_index=None,
            confidence="unknown for this BCM",
            basis="May apply to newer or per-side lamp-channel platforms; no observed distinct delta on this Polo coding.",
        ),
    ]


def format_report(resources: list[ResourceString], candidates: list[MappingCandidate]) -> str:
    lines = [
        "# Carista PQ25 Cornering Static Map",
        "",
        "This is an offline-only map. No phone trace was used.",
        "",
        "## Current Coding Boundary",
        "",
        "```text",
        f"current     {CURRENT_CODING}",
        f"known-good  {KNOWN_GOOD_CODING}",
        "delta       byte 12 bit 6 clear -> set; byte 21 bit 2 clear -> set",
        "```",
        "",
        "## Carista Resource Keys",
        "",
        "| Key | English label | Resource id | Native string VA | Direct native xrefs |",
        "|---|---|---:|---:|---|",
    ]
    for row in resources:
        native_va = f"0x{row.native_va:08X}" if row.native_va is not None else ""
        refs = "<none found>" if not row.native_refs else "<br>".join(row.native_refs)
        lines.append(f"| `{row.key}` | {row.label} | `{row.resource_id or ''}` | `{native_va}` | {refs} |")

    lines.extend(
        [
            "",
            "## Practical Mapping Candidates",
            "",
            "| Carista key | BCM byte/bit | Current | Known-good | Confidence | Basis |",
            "|---|---|---|---|---|---|",
        ]
    )
    for item in candidates:
        if item.byte_index is None or item.bit_index is None:
            location = "<not mapped>"
            current = ""
            known_good = ""
        else:
            location = f"byte {item.byte_index} bit {item.bit_index}"
            current = current_bit_state(item.byte_index, item.bit_index)
            known_good = known_good_bit_state(item.byte_index, item.bit_index)
        lines.append(
            f"| `{item.key}` | {location} | {current} | {known_good} | {item.confidence} | {item.basis} |"
        )

    lines.extend(
        [
            "",
            "## Static Boundary",
            "",
            "The native library contains the relevant Carista resource keys, but this static pass did not find simple direct code xrefs from those keys into `VagCanSettings::getSettings`. That means the remaining exact bridge is still:",
            "",
            "```text",
            "resource key -> native Setting catalog entry -> insertValue value bytes -> 3B9A write tuple",
            "```",
            "",
            "Without a phone trace, the strongest safe conclusion is the practical byte/bit mapping above, not the exact Carista 6-byte value/raw-address write tuple.",
            "",
        ]
    )
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description="Build an offline Carista-to-PQ25 cornering setting map.")
    parser.add_argument("--output", type=Path, default=ROOT / "carista_pq25_cornering_static_map.md")
    parser.add_argument("--json-output", type=Path, default=ROOT / "carista_pq25_cornering_static_map.json")
    args = parser.parse_args()

    inspector = ElfInspector(LIB_PATH)
    resources = build_resource_table(inspector)
    candidates = build_mapping_candidates(resources)
    report = format_report(resources, candidates)

    args.output.write_text(report, encoding="utf-8")
    args.json_output.write_text(
        json.dumps(
            {
                "resources": [resource.__dict__ for resource in resources],
                "candidates": [candidate.__dict__ for candidate in candidates],
            },
            indent=2,
            sort_keys=True,
        ),
        encoding="utf-8",
    )
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
