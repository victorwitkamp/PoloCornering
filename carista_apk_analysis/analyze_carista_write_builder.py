from __future__ import annotations

import re
import struct
from pathlib import Path

from capstone import CS_ARCH_ARM, CS_MODE_THUMB, Cs
from capstone.arm import ARM_OP_IMM
from elftools.elf.elffile import ELFFile


LIB_PATH = (
    Path(__file__).resolve().parent
    / "reacquire_20260424"
    / "split_armv7_unpacked"
    / "lib"
    / "armeabi-v7a"
    / "libCarista.so"
)

READ_REQUEST_SYMBOL = "_ZNK27ReadVagCanLongCodingCommand10getRequestEv"
WRITE_REQUEST_SYMBOL = "_ZNK21WriteVagCodingCommand10getRequestEv"
WRITE_CONSTRUCTOR_SYMBOL = (
    "_ZN21WriteVagCodingCommandC1EP3EcuRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEERKNS2_10shared_ptrIS7_EEN10VagEcuInfo10CodingTypeESC_"
)
CHANGE_SETTING_CONSTRUCTOR_SYMBOL = (
    "_ZN22ChangeSettingOperationC1ERKNSt6__ndk110shared_ptrI17ConnectionManagerEERKNS1_I7SettingEERKNS0_6vectorIhNS0_9allocatorIhEEEERKNS1_I9OperationEE"
)
WRITE_RAW_VALUES_CONSTRUCTOR_SYMBOL = (
    "_ZN23WriteRawValuesOperationC1ERKNSt6__ndk110shared_ptrI17ConnectionManagerEERKNS0_6vectorINS0_4pairIyNS6_IhNS0_9allocatorIhEEEEEENS8_ISB_EEEERKNS1_I9OperationEE"
)
CHANGE_SETTING_INTERNAL_SYMBOL = (
    "_ZN17OperationDelegate21changeSettingInternalERKNSt6__ndk110shared_ptrI7SettingEERKNS0_6vectorIhNS0_9allocatorIhEEEERKNS1_I8ProgressEE"
)
VAG_INSERT_VALUE_SYMBOL = (
    "_ZN20VagOperationDelegate11insertValueERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI7SettingEES6_"
)
VAG_GET_SETTING_RAW_ADDRESS_SYMBOL = (
    "_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE"
)
VAG_WRITE_RAW_VALUE_SYMBOL = (
    "_ZN20VagOperationDelegate13writeRawValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE"
)
VAG_WRITE_CODING_VALUE_SYMBOL = (
    "_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"
)
VAG_CAN_SETTINGS_SYMBOL = "_ZN14VagCanSettings11getSettingsEv"
SETTING_REF_NAME_SYMBOL = "Java_com_prizmos_carista_library_model_SettingRef_getNameResIdNative"
SETTING_REF_EVENT_SYMBOL = "Java_com_prizmos_carista_library_model_SettingRef_toEventStringNative"
SETTING_CATEGORY_VALUES_SYMBOL = "Java_com_prizmos_carista_library_model_SettingCategory_valuesNative"
JNI_GET_SETTING_POINTER_SYMBOL = "_ZN9JniHelper16getNativePointerI7SettingEEPT_P7_JNIEnvP8_jobject"
JNI_GET_READ_VALUES_POINTER_SYMBOL = "_ZN9JniHelper16getNativePointerI19ReadValuesOperationEEPT_P7_JNIEnvP8_jobject"
BYTE_INSERT_SYMBOL = "_ZN9ByteUtils11insertValueERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEEjS6_S6_"
VAG_SETTING_INSERT_SYMBOL = "_ZNK10VagSetting11insertValueERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_"
VAG_CAN_LONG_CODING_BYTE_SYMBOL = "_ZN23VagCanLongCodingSettingC1EP9VagCanEcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEihPKcRKNS3_I14InterpretationEE"
VAG_CAN_LONG_CODING_VECTOR_SYMBOL = "_ZN23VagCanLongCodingSettingC1EP9VagCanEcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEiRKNS2_6vectorIhNS2_9allocatorIhEEEEPKcRKNS3_I14InterpretationEE"

FRIENDLY_NAMES = {
    READ_REQUEST_SYMBOL: "ReadVagCanLongCodingCommand::getRequest",
    WRITE_REQUEST_SYMBOL: "WriteVagCodingCommand::getRequest",
    WRITE_CONSTRUCTOR_SYMBOL: "WriteVagCodingCommand::WriteVagCodingCommand",
    CHANGE_SETTING_CONSTRUCTOR_SYMBOL: "ChangeSettingOperation::ChangeSettingOperation",
    WRITE_RAW_VALUES_CONSTRUCTOR_SYMBOL: "WriteRawValuesOperation::WriteRawValuesOperation",
    CHANGE_SETTING_INTERNAL_SYMBOL: "OperationDelegate::changeSettingInternal",
    VAG_INSERT_VALUE_SYMBOL: "VagOperationDelegate::insertValue",
    VAG_GET_SETTING_RAW_ADDRESS_SYMBOL: "VagOperationDelegate::getSettingRawAddress",
    VAG_WRITE_RAW_VALUE_SYMBOL: "VagOperationDelegate::writeRawValue",
    VAG_WRITE_CODING_VALUE_SYMBOL: "VagOperationDelegate::writeVagCanCodingValue",
    VAG_CAN_SETTINGS_SYMBOL: "VagCanSettings::getSettings",
    SETTING_REF_NAME_SYMBOL: "SettingRef_getNameResIdNative",
    SETTING_REF_EVENT_SYMBOL: "SettingRef_toEventStringNative",
    SETTING_CATEGORY_VALUES_SYMBOL: "SettingCategory_valuesNative",
    JNI_GET_SETTING_POINTER_SYMBOL: "JniHelper::getNativePointer<Setting>",
    JNI_GET_READ_VALUES_POINTER_SYMBOL: "JniHelper::getNativePointer<ReadValuesOperation>",
    BYTE_INSERT_SYMBOL: "ByteUtils::insertValue",
    VAG_SETTING_INSERT_SYMBOL: "VagSetting::insertValue",
    VAG_CAN_LONG_CODING_BYTE_SYMBOL: "VagCanLongCodingSetting::VagCanLongCodingSetting(byte/bit)",
    VAG_CAN_LONG_CODING_VECTOR_SYMBOL: "VagCanLongCodingSetting::VagCanLongCodingSetting(vector mask)",
}

SETTING_KEY_RE = re.compile(rb"[ -~]{8,}")


def thumb_pc(address: int) -> int:
    return (address + 4) & ~3


class ElfInspector:
    def __init__(self, path: Path) -> None:
        self.path = path
        self.data = path.read_bytes()
        with path.open("rb") as handle:
            self.elf = ELFFile(handle)
            self.sections = list(self.elf.iter_sections())
            self.symbols = self._load_symbols()
        self.disassembler = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
        self.disassembler.detail = True

    def _load_symbols(self) -> dict[str, tuple[int, int]]:
        symbols: dict[str, tuple[int, int]] = {}
        for section_name in (".symtab", ".dynsym"):
            section = self.elf.get_section_by_name(section_name)
            if section is None:
                continue
            for symbol in section.iter_symbols():
                if symbol.name:
                    symbols[symbol.name] = (int(symbol["st_value"]), int(symbol["st_size"]))
        return symbols

    def va_to_offset(self, virtual_address: int) -> int:
        virtual_address &= ~1
        for section in self.sections:
            start = int(section["sh_addr"])
            size = int(section["sh_size"])
            if start <= virtual_address < start + size:
                return int(section["sh_offset"]) + virtual_address - start
        raise ValueError(f"virtual address not mapped: 0x{virtual_address:X}")

    def read_u32(self, virtual_address: int) -> int:
        return struct.unpack_from("<I", self.data, self.va_to_offset(virtual_address))[0]

    def read_bytes(self, virtual_address: int, size: int) -> bytes:
        offset = self.va_to_offset(virtual_address)
        return self.data[offset:offset + size]

    def symbol(self, name: str) -> tuple[int, int]:
        return self.symbols[name]

    def disassemble_symbol(self, name: str) -> list:
        virtual_address, size = self.symbol(name)
        code_address = virtual_address & ~1
        code = self.read_bytes(code_address, size)
        return list(self.disassembler.disasm(code, code_address | 1))


def literal_target(inspector: ElfInspector, ldr_address: int, immediate: int, add_address: int) -> int:
    literal_address = thumb_pc(ldr_address) + immediate
    relative = inspector.read_u32(literal_address)
    return (thumb_pc(add_address) + relative) & 0xFFFFFFFF


def ascii_at(inspector: ElfInspector, virtual_address: int, size: int = 24) -> str:
    chunk = inspector.read_bytes(virtual_address, size)
    return "".join(chr(byte) if 32 <= byte <= 126 else "." for byte in chunk)


def compare_immediates(instructions: list) -> list[tuple[int, int]]:
    matches: list[tuple[int, int]] = []
    for instruction in instructions:
        if instruction.mnemonic != "cmp" or len(instruction.operands) != 2:
            continue
        operand = instruction.operands[1]
        if operand.type == ARM_OP_IMM:
            matches.append((instruction.address, int(operand.imm)))
    return matches


def print_symbol(inspector: ElfInspector, symbol_name: str) -> None:
    address, size = inspector.symbol(symbol_name)
    print(f"  0x{address:08X} size={size:>6} {FRIENDLY_NAMES.get(symbol_name, symbol_name)}")


def relevant_setting_keys(inspector: ElfInspector) -> list[str]:
    keys: set[str] = set()
    for match in SETTING_KEY_RE.finditer(inspector.data):
        value = match.group(0).decode("ascii", errors="ignore")
        if not value.startswith("car_setting_"):
            continue
        lowered = value.lower()
        if "corner" in lowered or "cornerig" in lowered:
            keys.add(value)
    return sorted(keys)


def main() -> int:
    inspector = ElfInspector(LIB_PATH)

    read_literal = literal_target(inspector, 0x00D024A1, 0x08, 0x00D024A5)
    write_lookup = literal_target(inspector, 0x00D032DB, 0xFC, 0x00D032DD)
    write_literal = literal_target(inspector, 0x00D032E7, 0xF4, 0x00D032EB)

    constructor_instructions = inspector.disassemble_symbol(WRITE_CONSTRUCTOR_SYMBOL)
    constructor_checks = [
        (address, immediate)
        for address, immediate in compare_immediates(constructor_instructions)
        if immediate in {1, 2, 3, 4, 6}
    ]

    print("Carista write-builder inspection")
    print()
    print(f"Library: {LIB_PATH}")
    print()
    print("Resolved symbols:")
    for symbol_name in (
        READ_REQUEST_SYMBOL,
        WRITE_REQUEST_SYMBOL,
        WRITE_CONSTRUCTOR_SYMBOL,
        CHANGE_SETTING_CONSTRUCTOR_SYMBOL,
        WRITE_RAW_VALUES_CONSTRUCTOR_SYMBOL,
        CHANGE_SETTING_INTERNAL_SYMBOL,
        VAG_INSERT_VALUE_SYMBOL,
        VAG_GET_SETTING_RAW_ADDRESS_SYMBOL,
        VAG_WRITE_RAW_VALUE_SYMBOL,
        VAG_WRITE_CODING_VALUE_SYMBOL,
        BYTE_INSERT_SYMBOL,
        VAG_SETTING_INSERT_SYMBOL,
        VAG_CAN_LONG_CODING_BYTE_SYMBOL,
        VAG_CAN_LONG_CODING_VECTOR_SYMBOL,
        VAG_CAN_SETTINGS_SYMBOL,
        SETTING_REF_NAME_SYMBOL,
        SETTING_REF_EVENT_SYMBOL,
        SETTING_CATEGORY_VALUES_SYMBOL,
        JNI_GET_SETTING_POINTER_SYMBOL,
        JNI_GET_READ_VALUES_POINTER_SYMBOL,
    ):
        print_symbol(inspector, symbol_name)

    print()
    print("Request literals:")
    print(f"  Read literal target:  0x{read_literal:08X} {ascii_at(inspector, read_literal)}")
    print(f"  Write literal target: 0x{write_literal:08X} {ascii_at(inspector, write_literal)}")

    print()
    print("Coding-type lookup bytes:")
    lookup_bytes = inspector.read_bytes(write_lookup, 6)
    print("  " + " ".join(f"{byte:02X}" for byte in lookup_bytes))

    print()
    print("Constructor compare-immediate checks:")
    for address, immediate in constructor_checks:
        print(f"  0x{address:08X}: cmp ..., #{immediate}")

    print()
    print("Cornering-related Carista setting keys present in libCarista.so:")
    for key in relevant_setting_keys(inspector):
        print(f"  {key}")

    print()
    print("Confirmed from static reverse engineering:")
    print("  - Read builder resolves to 1A9A.")
    print("  - Write builder resolves to 3B9A.")
    print("  - WriteVagCodingCommand validates a 6-byte value vector.")
    print("  - WriteVagCodingCommand validates a 4-byte coding raw-address vector.")
    print("  - One coding-type branch validates a 3-byte trailing vector.")
    print("  - The request builder assembles: 3B9A + 6-byte value + 4-byte raw address + coding-type-dependent tail.")
    print("  - ChangeSettingOperation is built from shared_ptr<Setting> plus requested value bytes.")
    print("  - OperationDelegate::changeSettingInternal bridges high-level settings to brand-specific write logic.")
    print("  - VagOperationDelegate overrides insertValue, getSettingRawAddress, writeRawValue, and writeVagCanCodingValue.")
    print("  - VagCanLongCodingSetting has byte/bit and vector-mask constructors.")
    print("  - SettingRef native methods expose name/event lookups for native Setting handles.")
    print()
    print("Still not fully known without a phone trace or deeper catalog recovery:")
    print("  - Which concrete native Setting object Carista selects for this exact 6R0937087K BCM cornering toggle.")
    print("  - The exact 6-byte value vector Carista builds before WriteVagCodingCommand.")
    print("  - The exact 4-byte coding raw-address vector Carista reads from ECU metadata for this unit.")
    print("  - Whether this BCM uses only 3B9A or can fall back through WriteRawValuesOperation.")
    print("  - Any security/login or tester-present precondition before the final write.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
