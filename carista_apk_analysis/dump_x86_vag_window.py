from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path

from capstone import CS_ARCH_X86, CS_MODE_32, CS_OP_IMM, CS_OP_MEM, Cs
from capstone.x86_const import X86_REG_EBP, X86_REG_EBX
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
from elftools.elf.sections import SymbolTableSection


WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
X86_LIBCARISTA = WORKSPACE_ROOT / "carista_apk_analysis" / "play_9.8.3" / "extracted" / "lib" / "x86" / "libCarista.so"
GET_SETTINGS_EBX_BASE = 0x01A35618
GET_SETTINGS_SYMBOL = "_ZN14VagCanSettings11getSettingsEv"


@dataclass(frozen=True)
class ElfSection:
    name: str
    address: int
    data: bytes

    @property
    def size(self) -> int:
        return len(self.data)


@dataclass(frozen=True)
class ElfSymbol:
    name: str
    address: int
    size: int


@dataclass(frozen=True)
class ElfImage:
    sections: tuple[ElfSection, ...]
    symbols: tuple[ElfSymbol, ...]
    got_symbols: dict[int, str]


def _load_image() -> ElfImage:
    with X86_LIBCARISTA.open("rb") as stream:
        elf = ELFFile(stream)
        sections = tuple(
            ElfSection(section.name, int(section["sh_addr"]), bytes(section.data()))
            for section in elf.iter_sections()
            if int(section["sh_size"]) > 0
        )
        symbols = tuple(
            ElfSymbol(symbol.name, int(symbol["st_value"]), int(symbol["st_size"]))
            for section in elf.iter_sections()
            if isinstance(section, SymbolTableSection)
            for symbol in section.iter_symbols()
            if symbol.name and int(symbol["st_value"]) != 0
        )
        got_symbols: dict[int, str] = {}
        for section in elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue
            symbol_table = elf.get_section(section["sh_link"])
            if not isinstance(symbol_table, SymbolTableSection):
                continue
            for relocation in section.iter_relocations():
                symbol = symbol_table.get_symbol(relocation["r_info_sym"])
                if symbol.name:
                    got_symbols[int(relocation["r_offset"])] = symbol.name
        return ElfImage(sections, symbols, got_symbols)


def _section_containing(image: ElfImage, address: int) -> ElfSection:
    for section in image.sections:
        if section.address <= address < section.address + section.size:
            return section
    raise ValueError(f"no section for 0x{address:x}")


def _read_section_slice(image: ElfImage, address: int, size: int) -> bytes:
    section = _section_containing(image, address)
    offset = address - section.address
    return section.data[offset : offset + size]


def _ascii_strings(image: ElfImage) -> dict[int, str]:
    strings: dict[int, str] = {}
    for section in image.sections:
        content = section.data
        start = 0
        while start < len(content):
            end = content.find(b"\0", start)
            if end < 0:
                break
            raw = content[start:end]
            if len(raw) >= 4 and all(32 <= byte < 127 for byte in raw):
                strings[section.address + start] = raw.decode("ascii")
            start = end + 1
    return strings


def _symbols_by_address(image: ElfImage) -> dict[int, str]:
    symbols: dict[int, str] = {}
    for symbol in image.symbols:
        symbols.setdefault(symbol.address, symbol.name)
    return symbols


def _annotate(instruction, got_symbols: dict[int, str], strings: dict[int, str], symbols: dict[int, str]) -> str:
    notes: list[str] = []
    for operand in instruction.operands:
        if operand.type == CS_OP_MEM and operand.mem.base == X86_REG_EBX:
            absolute = (GET_SETTINGS_EBX_BASE + operand.mem.disp) & 0xFFFFFFFF
            if absolute in got_symbols:
                notes.append(f"got=0x{absolute:08X}:{got_symbols[absolute]}")
            elif absolute in strings:
                notes.append(f"str=0x{absolute:08X}:{strings[absolute]}")
        elif operand.type == CS_OP_IMM:
            target = operand.imm & 0xFFFFFFFF
            if target in symbols:
                notes.append(f"sym=0x{target:08X}:{symbols[target]}")
            elif target in strings:
                notes.append(f"str=0x{target:08X}:{strings[target]}")
    return " ; " + " | ".join(notes) if notes else ""


def _ebx_source(operand, got_symbols: dict[int, str], strings: dict[int, str]) -> str | None:
    if operand.type != CS_OP_MEM or operand.mem.base != X86_REG_EBX:
        return None
    absolute = (GET_SETTINGS_EBX_BASE + operand.mem.disp) & 0xFFFFFFFF
    if absolute in got_symbols:
        return f"got=0x{absolute:08X}:{got_symbols[absolute]}"
    if absolute in strings:
        return f"str=0x{absolute:08X}:{strings[absolute]}"
    return None


def _instruction_rows(image: ElfImage, start_address: int, end_address: int):
    symbol = next(symbol for symbol in image.symbols if symbol.name == GET_SETTINGS_SYMBOL)
    disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
    disassembler.detail = True

    if symbol.address <= start_address < symbol.address + symbol.size:
        size = min(symbol.size, max(end_address - symbol.address, 0))
        return list(disassembler.disasm(_read_section_slice(image, symbol.address, size), symbol.address))

    section = _section_containing(image, start_address)
    bounded_end = min(end_address, section.address + section.size)
    return list(disassembler.disasm(_read_section_slice(image, start_address, bounded_end - start_address), start_address))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("start", type=lambda value: int(value, 0))
    parser.add_argument("size", type=lambda value: int(value, 0))
    args = parser.parse_args()
    image = _load_image()
    strings = _ascii_strings(image)
    got_symbols = image.got_symbols
    symbols = _symbols_by_address(image)
    print(f"x86 libCarista window 0x{args.start:08X}..0x{args.start + args.size:08X}")
    register_sources: dict[int, str] = {}
    local_sources: dict[int, str] = {}
    for instruction in _instruction_rows(image, args.start, args.start + args.size):
        notes = _annotate(instruction, got_symbols, strings, symbols)
        if len(instruction.operands) >= 2 and instruction.mnemonic in {"lea", "mov"}:
            dest = instruction.operands[0]
            src = instruction.operands[1]
            if dest.type == CS_OP_IMM:
                pass
            elif hasattr(dest, "reg") and dest.reg and src.type == CS_OP_MEM:
                source = _ebx_source(src, got_symbols, strings)
                if source:
                    register_sources[dest.reg] = source
            if dest.type == CS_OP_MEM and dest.mem.base == X86_REG_EBP and hasattr(src, "reg") and src.reg in register_sources:
                local_sources[dest.mem.disp] = register_sources[src.reg]
        local_notes: list[str] = []
        for operand in instruction.operands:
            if operand.type == CS_OP_MEM and operand.mem.base == X86_REG_EBP and operand.mem.disp in local_sources:
                local_notes.append(f"local{operand.mem.disp:+#x}->{local_sources[operand.mem.disp]}")
        if local_notes:
            notes += (" ; " if not notes else " | ") + " | ".join(local_notes)
        if args.start <= instruction.address < args.start + args.size:
            print(f"0x{instruction.address:08X}: {instruction.mnemonic:<7} {instruction.op_str:<42}{notes}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())