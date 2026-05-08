from __future__ import annotations

import re
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

from capstone import CS_ARCH_X86, CS_MODE_32, CS_OP_IMM, CS_OP_MEM, Cs
from elftools.elf.elffile import ELFFile


WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
X86_LIBCARISTA = WORKSPACE_ROOT / "carista_apk_analysis" / "play_9.8.3" / "extracted" / "lib" / "x86" / "libCarista.so"
TARGET_VALUES = (0x0601, 0x0606, 0x220601, 0x220606, 0x620601, 0x620606)
RAW_PATTERNS = {
    "le16_0601": b"\x01\x06",
    "le32_0601": b"\x01\x06\x00\x00",
    "le16_0606": b"\x06\x06",
    "le32_0606": b"\x06\x06\x00\x00",
    "uds_220601": b"\x22\x06\x01",
    "uds_220606": b"\x22\x06\x06",
    "ascii_0601": b"0601",
    "ascii_0606": b"0606",
    "ascii_220601": b"220601",
    "ascii_220606": b"220606",
    "ascii_6206011E": b"6206011E",
    "ascii_62060118": b"62060118",
}
STRING_NEEDLES = (
    b"car_setting_enabled_coming_home_or_leaving_home",
    b"car_setting_cornering_lights_via_fogs_left",
    b"car_setting_cornering_lights_via_fogs_right",
)
NON_EVIDENCE_SECTIONS = {
    ".dynsym",
    ".dynstr",
    ".gnu.hash",
    ".hash",
    ".rel.dyn",
    ".rel.plt",
    ".strtab",
    ".symtab",
}


@dataclass(frozen=True)
class ElfSection:
    name: str
    flags: int
    address: int
    data: bytes


def _is_executable_section(section: ElfSection) -> bool:
    return bool(section.flags & 0x4)


def _section_hits(content: bytes, pattern: bytes) -> Iterable[int]:
    start = 0
    while True:
        index = content.find(pattern, start)
        if index < 0:
            return
        yield index
        start = index + 1


def _scan_instruction_operands(sections: Iterable[ElfSection]) -> list[tuple[str, int, str, str, str, int]]:
    disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
    disassembler.detail = True
    hits: list[tuple[str, int, str, str, str, int]] = []
    for section in sections:
        if not _is_executable_section(section):
            continue
        for instruction in disassembler.disasm(section.data, section.address):
            for operand in instruction.operands:
                value: int | None = None
                kind: str | None = None
                if operand.type == CS_OP_IMM:
                    value = operand.imm & 0xFFFFFFFF
                    kind = "imm"
                elif operand.type == CS_OP_MEM:
                    value = operand.mem.disp & 0xFFFFFFFF
                    kind = "disp"
                if value in TARGET_VALUES and kind is not None:
                    hits.append((section.name, instruction.address, instruction.mnemonic, instruction.op_str, kind, value))
    return hits


def _scan_instruction_refs_to_values(
    sections: Iterable[ElfSection],
    values: dict[int, str],
) -> dict[str, list[tuple[str, int, str, str, str]]]:
    disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
    disassembler.detail = True
    refs: dict[str, list[tuple[str, int, str, str, str]]] = {label: [] for label in values.values()}
    for section in sections:
        if not _is_executable_section(section):
            continue
        for instruction in disassembler.disasm(section.data, section.address):
            for operand in instruction.operands:
                value: int | None = None
                kind: str | None = None
                if operand.type == CS_OP_IMM:
                    value = operand.imm & 0xFFFFFFFF
                    kind = "imm"
                elif operand.type == CS_OP_MEM:
                    value = operand.mem.disp & 0xFFFFFFFF
                    kind = "disp"
                if value in values and kind is not None:
                    refs[values[value]].append((section.name, instruction.address, instruction.mnemonic, instruction.op_str, kind))
    return refs


def _scan_raw_patterns(sections: Iterable[ElfSection]) -> Counter[tuple[str, str]]:
    counts: Counter[tuple[str, str]] = Counter()
    for section in sections:
        content = section.data
        if not content:
            continue
        for label, pattern in RAW_PATTERNS.items():
            counts.update((section.name, label) for _ in _section_hits(content, pattern))
    return counts


def _preview_bytes(data: bytes) -> str:
    return "".join(chr(value) if 32 <= value < 127 else "." for value in data)


def _scan_raw_contexts(
    sections: Iterable[ElfSection],
    *,
    max_per_pattern: int = 3,
) -> list[tuple[str, str, int, str]]:
    contexts: list[tuple[str, str, int, str]] = []
    for section in sections:
        if section.name not in {".rodata", ".text", ".data.rel.ro"}:
            continue
        for label, pattern in RAW_PATTERNS.items():
            shown = 0
            start = 0
            while shown < max_per_pattern:
                index = section.data.find(pattern, start)
                if index < 0:
                    break
                start = index + 1
                shown += 1
                lo = max(0, index - 32)
                hi = min(len(section.data), index + len(pattern) + 32)
                contexts.append((section.name, label, section.address + index, _preview_bytes(section.data[lo:hi])))
    return contexts


def _scan_embedded_220601_responses(sections: Iterable[ElfSection]) -> Counter[str]:
    responses: Counter[str] = Counter()
    pattern = re.compile(rb"220601: ([0-9A-Fa-f-]+)")
    for section in sections:
        if section.name not in {".rodata", ".text", ".data.rel.ro"}:
            continue
        for match in pattern.finditer(section.data):
            responses[match.group(1).decode("ascii").upper()] += 1
    return responses


def _scan_string_locations(sections: Iterable[ElfSection]) -> list[tuple[str, str, int]]:
    locations: list[tuple[str, str, int]] = []
    for section in sections:
        content = section.data
        if not content:
            continue
        for needle in STRING_NEEDLES:
            for index in _section_hits(content, needle):
                locations.append((needle.decode("ascii"), section.name, section.address + index))
    return locations


def _scan_direct_string_refs(sections: Iterable[ElfSection], string_locations: Iterable[tuple[str, str, int]]) -> dict[str, list[tuple[str, int]]]:
    refs: dict[str, list[tuple[str, int]]] = {}
    for label, _section_name, address in string_locations:
        address_bytes = address.to_bytes(4, "little")
        label_refs: list[tuple[str, int]] = []
        for section in sections:
            content = section.data
            if not content:
                continue
            for index in _section_hits(content, address_bytes):
                label_refs.append((section.name, section.address + index))
        refs[label] = label_refs
    return refs


def _load_sections() -> tuple[str, tuple[ElfSection, ...]]:
    with X86_LIBCARISTA.open("rb") as stream:
        elf = ELFFile(stream)
        sections = tuple(
            ElfSection(
                name=section.name,
                flags=int(section["sh_flags"]),
                address=int(section["sh_addr"]),
                data=bytes(section.data()),
            )
            for section in elf.iter_sections()
        )
        return str(elf.header["e_machine"]), sections


def main() -> int:
    machine, sections = _load_sections()
    instruction_hits = _scan_instruction_operands(sections)
    raw_counts = _scan_raw_patterns(sections)
    raw_contexts = _scan_raw_contexts(sections)
    embedded_220601_responses = _scan_embedded_220601_responses(sections)
    string_locations = _scan_string_locations(sections)
    direct_string_refs = _scan_direct_string_refs(sections, string_locations)
    string_instruction_refs = _scan_instruction_refs_to_values(
        sections,
        {address: label for label, _section_name, address in string_locations},
    )

    print("Play 9.8.3 x86 DID 0601/0606 static scan")
    print(f"library: {X86_LIBCARISTA}")
    print(f"machine: {machine}")
    print(
        "instruction operand hits for 0x0601/0x0606/0x220601/0x220606/0x620601/0x620606: "
        f"{len(instruction_hits)}"
    )
    for section_name, address, mnemonic, operands, kind, value in instruction_hits[:40]:
        print(f"  {section_name} 0x{address:08X}: {mnemonic} {operands} {kind}=0x{value:X}")

    print("string locations:")
    for label, section_name, address in string_locations:
        print(f"  {label} {section_name} 0x{address:08X}")

    print("raw string-address byte refs:")
    for label in sorted(direct_string_refs):
        refs = direct_string_refs[label]
        if not refs:
            print(f"  {label}: none")
            continue
        preview = ", ".join(f"{section} 0x{address:08X}" for section, address in refs[:12])
        suffix = f" (+{len(refs) - 12} more)" if len(refs) > 12 else ""
        print(f"  {label}: {preview}{suffix}")

    print("decoded instruction refs to string addresses:")
    for label in sorted(string_instruction_refs):
        refs = string_instruction_refs[label]
        if not refs:
            print(f"  {label}: none")
            continue
        preview = ", ".join(
            f"{section} 0x{address:08X}: {mnemonic} {operands} {kind}"
            for section, address, mnemonic, operands, kind in refs[:12]
        )
        suffix = f" (+{len(refs) - 12} more)" if len(refs) > 12 else ""
        print(f"  {label}: {preview}{suffix}")

    print("raw pattern counts outside symbol/relocation sections:")
    for (section_name, label), count in sorted(raw_counts.items()):
        if section_name in NON_EVIDENCE_SECTIONS:
            continue
        print(f"  {section_name:18s} {label:14s} {count}")

    print("embedded 220601 response payloads in readable binary tables:")
    if not embedded_220601_responses:
        print("  none")
    else:
        for payload, count in embedded_220601_responses.most_common():
            print(f"  {payload:10s} {count}")
    print(f"embedded 6206011E present: {'YES' if embedded_220601_responses.get('6206011E') else 'NO'}")
    print(f"embedded 62060118 present: {'YES' if embedded_220601_responses.get('62060118') else 'NO'}")

    print("raw context previews:")
    for section_name, label, address, context in raw_contexts:
        print(f"  {section_name:12s} 0x{address:08X} {label:14s} {context}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())