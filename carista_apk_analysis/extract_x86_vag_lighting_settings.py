from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any

from capstone import CS_ARCH_X86, CS_MODE_32, CS_OP_IMM, CS_OP_MEM, Cs
from capstone.x86_const import X86_REG_EBX
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
from elftools.elf.sections import SymbolTableSection


WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
X86_LIBCARISTA = WORKSPACE_ROOT / "carista_apk_analysis" / "play_9.8.3" / "extracted" / "lib" / "x86" / "libCarista.so"
GET_SETTINGS_SYMBOL = "_ZN14VagCanSettings11getSettingsEv"
GET_SETTINGS_EBX_BASE = 0x01A35618
TERMS = (
    "fog",
    "fogs",
    "corner",
    "cornerig",
    "coming_home",
    "leaving_home",
    "drl",
    "low_beam",
    "low_beams",
    "high_beam",
    "turn_signal",
)
HELPER_TERMS = (
    "VagCanShortAdaptationSetting",
    "FullByteVagCanShortAdaptationSetting",
    "VagCanLongCodingSetting",
    "VagUdsCodingSetting",
    "VagUdsAdaptationSetting",
    "VagCanLongAdaptationSetting",
    "VagCanLiveData",
    "VagUdsLiveData",
)


@dataclass(frozen=True)
class InstructionRecord:
    address: int
    mnemonic: str
    op_str: str
    operands: tuple[Any, ...]


@dataclass(frozen=True)
class ElfSection:
    name: str
    address: int
    flags: int
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
            ElfSection(section.name, int(section["sh_addr"]), int(section["sh_flags"]), bytes(section.data()))
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


def _symbol_by_address(image: ElfImage) -> dict[int, str]:
    symbols: dict[int, str] = {}
    for symbol in image.symbols:
        symbols.setdefault(symbol.address, symbol.name)
    return symbols


def _disassemble_get_settings(image: ElfImage) -> list[InstructionRecord]:
    symbol = next(symbol for symbol in image.symbols if symbol.name == GET_SETTINGS_SYMBOL)
    disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
    disassembler.detail = True
    code = _read_section_slice(image, symbol.address, symbol.size)
    return [InstructionRecord(ins.address, ins.mnemonic, ins.op_str, tuple(ins.operands)) for ins in disassembler.disasm(code, symbol.address)]


def _mem_ebx_targets(record: InstructionRecord, got_symbols: dict[int, str], strings: dict[int, str]) -> tuple[list[str], list[str], list[str]]:
    string_refs: list[str] = []
    whitelist_refs: list[str] = []
    ecu_refs: list[str] = []
    for operand in record.operands:
        if operand.type != CS_OP_MEM or operand.mem.base != X86_REG_EBX:
            continue
        absolute = (GET_SETTINGS_EBX_BASE + operand.mem.disp) & 0xFFFFFFFF
        if absolute in strings:
            string_refs.append(strings[absolute])
        symbol = got_symbols.get(absolute)
        if symbol and symbol.startswith("_ZN13VagWhitelists"):
            whitelist_refs.append(symbol)
        elif symbol and (symbol.startswith("_ZN9VagCanEcu") or symbol.startswith("_ZN9VagUdsEcu")):
            ecu_refs.append(symbol)
    return string_refs, whitelist_refs, ecu_refs


def _small_immediates(record: InstructionRecord) -> list[int]:
    values: list[int] = []
    for operand in record.operands:
        if operand.type == CS_OP_IMM:
            value = operand.imm & 0xFFFFFFFF
            if value <= 0x1200:
                values.append(value)
    return values


def _classify_helper(symbol_name: str) -> str | None:
    for term in HELPER_TERMS:
        if term in symbol_name:
            return term
    return None


def _short_symbol(symbol_name: str) -> str:
    for prefix in ("_ZN13VagWhitelists", "_ZN9VagCanEcu", "_ZN9VagUdsEcu"):
        if symbol_name.startswith(prefix):
            return symbol_name[len(prefix) :]
    helper = _classify_helper(symbol_name)
    return helper or symbol_name


def _plt_symbol_at(image: ElfImage, address: int, got_symbols: dict[int, str]) -> str | None:
    try:
        code = _read_section_slice(image, address, 24)
    except ValueError:
        return None
    disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
    disassembler.detail = True
    for instruction in disassembler.disasm(code, address):
        for operand in instruction.operands:
            if operand.type == CS_OP_MEM and operand.mem.base == X86_REG_EBX:
                absolute = (GET_SETTINGS_EBX_BASE + operand.mem.disp) & 0xFFFFFFFF
                symbol = got_symbols.get(absolute)
                if symbol:
                    return symbol
    return None


def _helper_from_target(image: ElfImage, target: int, got_symbols: dict[int, str], symbols_by_address: dict[int, str]) -> str | None:
    direct_symbol = symbols_by_address.get(target)
    if direct_symbol and _classify_helper(direct_symbol):
        return direct_symbol
    plt_symbol = _plt_symbol_at(image, target, got_symbols)
    if plt_symbol and _classify_helper(plt_symbol):
        return plt_symbol
    try:
        code = _read_section_slice(image, target, 0x180)
    except ValueError:
        return None
    disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
    disassembler.detail = True
    for instruction in disassembler.disasm(code, target):
        if instruction.mnemonic not in {"call", "jmp"}:
            continue
        for operand in instruction.operands:
            if operand.type != CS_OP_IMM:
                continue
            nested_target = operand.imm & 0xFFFFFFFF
            nested_symbol = symbols_by_address.get(nested_target) or _plt_symbol_at(image, nested_target, got_symbols)
            if nested_symbol and _classify_helper(nested_symbol):
                return nested_symbol
    return None


def main() -> int:
    image = _load_image()
    strings = _ascii_strings(image)
    key_addresses = {
        address: value
        for address, value in strings.items()
        if value.startswith("car_setting_") and any(term in value for term in TERMS)
    }
    got_symbols = image.got_symbols
    symbols_by_address = _symbol_by_address(image)
    records = _disassemble_get_settings(image)
    records_by_address = {record.address: index for index, record in enumerate(records)}

    callsites: list[tuple[int, str]] = []
    for record in records:
        string_refs, _whitelist_refs, _ecu_refs = _mem_ebx_targets(record, got_symbols, key_addresses)
        for key in string_refs:
            callsites.append((record.address, key))

    print("Play 9.8.3 x86 VagCanSettings lighting/fog setting refs")
    print(f"library: {X86_LIBCARISTA}")
    print(f"matching key strings in binary: {len(key_addresses)}")
    print(f"matching key refs inside VagCanSettings::getSettings: {len(callsites)}")
    print()

    for address, key in sorted(callsites):
        index = records_by_address[address]
        window = records[max(index - 28, 0) : min(index + 48, len(records))]
        whitelists: list[tuple[int, str]] = []
        ecus: list[tuple[int, str]] = []
        helpers: list[tuple[int, str]] = []
        immediates: list[tuple[int, int]] = []
        for record in window:
            _string_refs, whitelist_refs, ecu_refs = _mem_ebx_targets(record, got_symbols, strings)
            whitelists.extend((record.address, symbol) for symbol in whitelist_refs)
            ecus.extend((record.address, symbol) for symbol in ecu_refs)
            for value in _small_immediates(record):
                immediates.append((record.address, value))
            if record.mnemonic == "call":
                for operand in record.operands:
                    if operand.type != CS_OP_IMM:
                        continue
                    target = operand.imm & 0xFFFFFFFF
                    symbol = _helper_from_target(image, target, got_symbols, symbols_by_address)
                    if symbol and _classify_helper(symbol):
                        helpers.append((record.address, symbol))

        unique_whitelists = list(dict.fromkeys(_short_symbol(symbol) for _addr, symbol in whitelists))
        unique_ecus = list(dict.fromkeys(_short_symbol(symbol) for _addr, symbol in ecus))
        unique_helpers = list(dict.fromkeys(_short_symbol(symbol) for _addr, symbol in helpers))
        immediate_preview = list(dict.fromkeys(f"0x{value:X}@0x{addr:08X}" for addr, value in immediates))[:18]
        print(f"0x{address:08X} {key}")
        print(f"  whitelists: {', '.join(unique_whitelists) if unique_whitelists else 'none in +44 insns'}")
        print(f"  ecus:       {', '.join(unique_ecus) if unique_ecus else 'none in +44 insns'}")
        print(f"  helpers:    {', '.join(unique_helpers) if unique_helpers else 'none in +44 insns'}")
        print(f"  immediates: {', '.join(immediate_preview) if immediate_preview else 'none'}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except OSError as exc:
        if exc.errno == 22:
            raise SystemExit(0)
        raise