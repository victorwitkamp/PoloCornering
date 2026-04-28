from __future__ import annotations

import argparse
import json
import struct
import zipfile
from dataclasses import dataclass
from io import BytesIO
from pathlib import Path

from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parent
DOCS_ROOT = ROOT.parent / "docs" / "carista_apk_analysis"
LIB_PATH = ROOT / "reacquire_20260424" / "split_armv7_unpacked" / "lib" / "armeabi-v7a" / "libCarista.so"
ARM_SPLIT_APK = ROOT / "reacquire_20260424" / "config.armeabi_v7a.apk"
XAPK_PATH = ROOT / "reacquire_20260424" / "carista_9.8.2.xapk"
LIB_IN_APK = "lib/armeabi-v7a/libCarista.so"

CURRENT_CODING = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
TARGET_CODING = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"

READ_REQUEST_SYMBOL = "_ZNK27ReadVagCanLongCodingCommand10getRequestEv"
WRITE_REQUEST_SYMBOL = "_ZNK21WriteVagCodingCommand10getRequestEv"
WRITE_CONSTRUCTOR_SYMBOL = (
    "_ZN21WriteVagCodingCommandC1EP3EcuRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEERKNS2_10shared_ptrIS7_EEN10VagEcuInfo10CodingTypeESC_"
)
VAG_SETTING_INSERT_SYMBOL = "_ZNK10VagSetting11insertValueERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_"
BYTE_INSERT_SYMBOL = "_ZN9ByteUtils11insertValueERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEEjS6_S6_"
VAG_GET_SETTING_RAW_ADDRESS_SYMBOL = (
    "_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE"
)
VAG_WRITE_CODING_VALUE_SYMBOL = (
    "_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"
)
VAG_CAN_LONG_CODING_BIT_SYMBOL = (
    "_ZN23VagCanLongCodingSettingC1EP9VagCanEcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEihPKcRKNS3_I14InterpretationEE"
)
VAG_CAN_LONG_CODING_VECTOR_SYMBOL = (
    "_ZN23VagCanLongCodingSettingC1EP9VagCanEcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEiRKNS2_6vectorIhNS2_9allocatorIhEEEEPKcRKNS3_I14InterpretationEE"
)

SYMBOLS = {
    "ReadVagCanLongCodingCommand::getRequest": READ_REQUEST_SYMBOL,
    "WriteVagCodingCommand::getRequest": WRITE_REQUEST_SYMBOL,
    "WriteVagCodingCommand::ctor": WRITE_CONSTRUCTOR_SYMBOL,
    "VagSetting::insertValue": VAG_SETTING_INSERT_SYMBOL,
    "ByteUtils::insertValue": BYTE_INSERT_SYMBOL,
    "VagOperationDelegate::getSettingRawAddress": VAG_GET_SETTING_RAW_ADDRESS_SYMBOL,
    "VagOperationDelegate::writeVagCanCodingValue": VAG_WRITE_CODING_VALUE_SYMBOL,
    "VagCanLongCodingSetting::ctor_bit": VAG_CAN_LONG_CODING_BIT_SYMBOL,
    "VagCanLongCodingSetting::ctor_vector": VAG_CAN_LONG_CODING_VECTOR_SYMBOL,
}


@dataclass(frozen=True)
class SymbolInfo:
    label: str
    address: int
    size: int


@dataclass(frozen=True)
class CodingChunk:
    chunk_index: int
    byte_start: int
    current: str
    target: str
    changed_bits: list[str]


def thumb_pc(address: int) -> int:
    return (address + 4) & ~3


class ElfInspector:
    def __init__(self, data: bytes, source: str) -> None:
        self.source = source
        self.data = data
        self.elf = ELFFile(BytesIO(data))
        self.sections = [
            (section.name, int(section["sh_addr"]), int(section["sh_offset"]), int(section["sh_size"]))
            for section in self.elf.iter_sections()
        ]
        self.symbols = self._load_symbols()

    def _load_symbols(self) -> dict[str, tuple[int, int]]:
        symbols: dict[str, tuple[int, int]] = {}
        for section_name in (".symtab", ".dynsym"):
            section = self.elf.get_section_by_name(section_name)
            if section is None:
                continue
            for symbol in section.iter_symbols():
                if symbol.name:
                    symbols[symbol.name] = (int(symbol["st_value"]) & ~1, int(symbol["st_size"]))
        return symbols

    def va_to_offset(self, virtual_address: int) -> int:
        virtual_address &= ~1
        for _name, address, offset, size in self.sections:
            if address <= virtual_address < address + size:
                return offset + virtual_address - address
        raise ValueError(f"virtual address not mapped: 0x{virtual_address:X}")

    def read_u32(self, virtual_address: int) -> int:
        return struct.unpack_from("<I", self.data, self.va_to_offset(virtual_address))[0]

    def read_bytes(self, virtual_address: int, size: int) -> bytes:
        offset = self.va_to_offset(virtual_address)
        return self.data[offset:offset + size]

    def symbol_info(self, label: str, symbol_name: str) -> SymbolInfo:
        address, size = self.symbols[symbol_name]
        return SymbolInfo(label=label, address=address, size=size)


def load_lib_bytes() -> tuple[bytes, str]:
    if LIB_PATH.exists():
        return LIB_PATH.read_bytes(), str(LIB_PATH)

    if ARM_SPLIT_APK.exists():
        with zipfile.ZipFile(ARM_SPLIT_APK) as archive:
            return archive.read(LIB_IN_APK), f"{ARM_SPLIT_APK}!{LIB_IN_APK}"

    if XAPK_PATH.exists():
        with zipfile.ZipFile(XAPK_PATH) as xapk:
            arm_split = xapk.read("config.armeabi_v7a.apk")
        with zipfile.ZipFile(BytesIO(arm_split)) as archive:
            return archive.read(LIB_IN_APK), f"{XAPK_PATH}!config.armeabi_v7a.apk!{LIB_IN_APK}"

    raise FileNotFoundError("could not find libCarista.so, config.armeabi_v7a.apk, or carista_9.8.2.xapk")


def literal_target(inspector: ElfInspector, ldr_address: int, immediate: int, add_address: int) -> int:
    literal_address = thumb_pc(ldr_address) + immediate
    relative = inspector.read_u32(literal_address)
    return (thumb_pc(add_address) + relative) & 0xFFFFFFFF


def ascii_at(inspector: ElfInspector, address: int, size: int = 24) -> str:
    return "".join(chr(byte) if 32 <= byte <= 126 else "." for byte in inspector.read_bytes(address, size))


def ascii_token_at(inspector: ElfInspector, address: int, expected: str, size: int = 16) -> str:
    window = ascii_at(inspector, address, size)
    return expected if expected in window else window


def changed_chunks(chunk_size: int = 6) -> list[CodingChunk]:
    current = bytes.fromhex(CURRENT_CODING)
    target = bytes.fromhex(TARGET_CODING)
    chunks: list[CodingChunk] = []
    for start in range(0, len(current), chunk_size):
        current_chunk = current[start:start + chunk_size]
        target_chunk = target[start:start + chunk_size]
        if current_chunk == target_chunk:
            continue
        changed_bits: list[str] = []
        for offset, (current_byte, target_byte) in enumerate(zip(current_chunk, target_chunk)):
            if current_byte == target_byte:
                continue
            absolute_byte = start + offset
            for bit_index in range(8):
                if (current_byte ^ target_byte) & (1 << bit_index):
                    before = "set" if current_byte & (1 << bit_index) else "clear"
                    after = "set" if target_byte & (1 << bit_index) else "clear"
                    changed_bits.append(f"byte {absolute_byte} bit {bit_index}: {before} -> {after}")
        chunks.append(
            CodingChunk(
                chunk_index=start // chunk_size,
                byte_start=start,
                current=current_chunk.hex().upper(),
                target=target_chunk.hex().upper(),
                changed_bits=changed_bits,
            )
        )
    return chunks


def build_report(inspector: ElfInspector) -> tuple[str, dict[str, object]]:
    symbols = [inspector.symbol_info(label, symbol_name) for label, symbol_name in SYMBOLS.items()]
    read_literal = literal_target(inspector, 0x00D024A1, 0x08, 0x00D024A5)
    write_lookup = literal_target(inspector, 0x00D032DB, 0xFC, 0x00D032DD)
    write_literal = literal_target(inspector, 0x00D032E7, 0xF4, 0x00D032EB)
    lookup_bytes = inspector.read_bytes(write_lookup, 6)
    read_request = ascii_token_at(inspector, read_literal, "1A9A")
    write_request = ascii_token_at(inspector, write_literal, "3B9A")
    chunks = changed_chunks()

    lines = [
        "# Carista Write Tuple Recovery",
        "",
        "This is an offline static report. It does not use a phone trace.",
        "",
        "## Resolved Native Anchors",
        "",
        "| Symbol | Address | Size |",
        "|---|---:|---:|",
    ]
    for item in symbols:
        lines.append(f"| {item.label} | `0x{item.address:08X}` | {item.size} |")

    lines.extend(
        [
            "",
            "## Request Builders",
            "",
            f"- Long-coding read literal resolves to `{read_request}` at `0x{read_literal:08X}`.",
            f"- Write-coding literal resolves to `{write_request}` at `0x{write_literal:08X}`.",
            f"- Coding-type lookup bytes are: `{' '.join(f'{byte:02X}' for byte in lookup_bytes)}`.",
            "",
            "Static request shape recovered from `WriteVagCodingCommand::getRequest`:",
            "",
            "```text",
            "3B9A",
            "+ 6-byte coding value vector",
            "+ 4-byte coding raw-address vector",
            "+ coding-type-dependent tail",
            "```",
            "",
            "The constructor enforces:",
            "",
            "```text",
            "value vector length       = 6",
            "raw-address vector length = 4",
            "coding type 2 tail length = 3",
            "```",
            "",
            "For non-type-2 coding, the builder appends a mapped coding-type byte, a length byte, the tail bytes, and `FF`.",
            "",
            "## Insert-Value Model",
            "",
            "`VagSetting::insertValue` forwards into `ByteUtils::insertValue`. The recovered model is:",
            "",
            "```text",
            "result = copy(current_raw_value)",
            "for each byte in setting mask:",
            "    result[offset + i] = (current[offset + i] & ~mask[i]) | masked_requested_value[i]",
            "```",
            "",
            "The important object fields used by that path are:",
            "",
            "```text",
            "VagSetting + 0x18 = byte offset inside the raw value",
            "VagSetting + 0x1C = mask/vector object used for the setting",
            "```",
            "",
            "For a one-bit long-coding setting, the mask vector is expected to contain the target bit mask.",
            "",
            "## Writer Flow Findings",
            "",
            "The lower writer path now looks like this:",
            "",
            "```text",
            "ChangeSettingOperation",
            "-> OperationDelegate::changeSettingInternal",
            "-> VagOperationDelegate::insertValue",
            "-> VagOperationDelegate::getSettingRawAddress",
            "-> VagOperationDelegate::writeRawValue",
            "-> VagOperationDelegate::writeVagCanCodingValue",
            "-> WriteVagCodingCommand",
            "```",
            "",
            "`writeVagCanCodingValue` does not receive a raw full-coding blob. It receives a 64-bit raw-value key plus the compact value vector. It then resolves ECU coding metadata before constructing `WriteVagCodingCommand`.",
            "",
            "Static disassembly of `writeVagCanCodingValue` shows:",
            "",
            "```text",
            "- the raw value is cached by the 64-bit key before the write command is built",
            "- ECU metadata is queried with that key to choose the coding type",
            "- coding type 2 is preserved",
            "- non-type-2 coding is normalized to type 3",
            "- a sentinel metadata path forces coding type 5",
            "- the final command still goes through the 6-byte value + 4-byte raw-address + tail constructor",
            "```",
            "",
            "The Java/Dex bridge confirms the same high-level boundary:",
            "",
            "```text",
            "SettingRef.nativeId exists on the Java side",
            "ChangeSettingOperation.initNative(Setting, byte[], ReadValuesOperation) creates the native operation",
            "GetEcuInfoOperation exposes getCodingRawAddress(short), supportsSingleCoding(), and supportsMultiCoding()",
            "```",
            "",
            "## Raw-Address Model",
            "",
            "`VagOperationDelegate::getSettingRawAddress` branches on `VagSetting::Type` from the setting object:",
            "",
            "```text",
            "type 9 or 5 -> submodule-aware raw-address helper",
            "type 4      -> alternate raw-address helper",
            "other types -> base raw-address/coding-address path",
            "```",
            "",
            "The long-coding constructors feed the VAG CAN coding-setting base with type `3`, so this BCM is expected to use the base coding-address path unless a catalog wrapper changes the type.",
            "",
            "Important implication: the missing `rawAddress4` is probably not just the visible DID `0600`. The live `2E0600 + full coding` attempt was parsed by the BCM but rejected with `7F2E22`, while the blind `3B9A + 30-byte coding` attempt produced no useful response. Those results fit the compact Carista tuple model.",
            "",
            "## Current Coding Chunks",
            "",
            "Carista's writer validates a 6-byte coding value. Splitting the 30-byte BCM coding into 6-byte chunks gives two changed chunks between current and known-good:",
            "",
            "| Chunk | Bytes | Current 6-byte value | Target 6-byte value | Changed bits |",
            "|---:|---:|---|---|---|",
        ]
    )
    for chunk in chunks:
        lines.append(
            f"| {chunk.chunk_index} | {chunk.byte_start}-{chunk.byte_start + 5} | "
            f"`{chunk.current}` | `{chunk.target}` | {'; '.join(chunk.changed_bits)} |"
        )

    lines.extend(
        [
            "",
            "## Tuple Candidates To Recover",
            "",
            "The value side is now narrow if the 6-byte chunk model is correct:",
            "",
            "```text",
            "base fog-cornering tuple value:  6C680ED000C8",
            "turn-signal tuple value:        412F60A60000",
            "```",
            "",
            "The still-missing pieces are the 4-byte raw-address vectors and exact tail bytes for those chunks. Those are derived from ECU metadata and Carista's setting catalog, not from the visible long-coding string alone.",
            "",
            "The latest offline-only VAGCAN20 simulator pass corrected the raw-address proof boundary. Static disassembly shows that `WriteVagCodingCommand` receives its 4-byte rawAddress4 and coding selector from positive `1A9B` / `5A9B` ECU-info parsing, not directly from the `31B80000` ECU-list response.",
            "",
            "Recovered `1A9B` parser offsets after stripping the positive `5A9B` prefix:",
            "",
            "```text",
            "payload[0x0c:0x10] -> rawAddress4",
            "payload[0x10]      -> coding selector",
            "payload[0x11:0x14] -> tail for type-2/type-4 selector branches",
            "payload[0x14:0x1a] -> stored 6-byte coding value",
            "```",
            "",
            "The embedded 1K0937049S-style simulator has a positive `1A9B` and proves the parser with rawAddress4 `B0373034`, selector `10`, coding type `3`, empty tail, and suffix `0301FF`. The BCM25/5C0937087E simulator has direct `220600` coding and a `31B80000` list, but its `1A9B` response is negative, so it does not prove the final rawAddress4 for that profile either.",
            "",
            "The actual `6R0937087K` workspace evidence has direct `220600` coding but no positive `1A9B` / `5A9B` response. Therefore the full `3B9A` tuple for this car is not proven offline; only the two target value6 chunks are proven.",
            "",
            "The dedicated offline report is generated by:",
            "",
            "```text",
            "carista_apk_analysis/analyze_carista_offline_tuple_candidates.py",
            "docs/carista_apk_analysis/carista_offline_tuple_candidate_report.md",
            "```",
            "",
            "## Next Static Target",
            "",
            "The next offline target is now narrower: recover a positive `1A9B` response for the actual `6R0937087K` or reconstruct the same bytes from a native catalog/data-flow path. In parallel, recover the `VagCanLongCodingSetting` catalog entries around byte 12 bit 6 and byte 21 bit 2. The fields to recover for each entry are:",
            "",
            "```text",
            "setting name key",
            "VagSetting type",
            "raw-address/coding-address key",
            "byte offset",
            "mask vector",
            "interpretation values",
            "coding tail bytes used by WriteVagCodingCommand",
            "```",
            "",
            "Without an actual positive `1A9B` metadata bridge, a native catalog equivalent, or a phone trace, do not treat any complete `3B9A` tuple as proven.",
            "",
            "## Static Catalog Boundary",
            "",
            "Additional static checks found no simple raw pointer table from the Carista resource strings or Android numeric resource ids into the native setting catalog. A branch scan from `VagCanSettings::getSettings()` to the named `VagCanLongCodingSetting` constructor/emplace wrappers also found no direct call sites.",
            "",
            "A broader `VagCanSettings::getSettings()` disassembly scan also found no direct `car_setting_*` C-string references. The `car_setting_*` names are present in `libCarista.so`, but the setting catalog does not expose them as a straightforward label -> constructor -> write tuple table.",
            "",
            "Practical meaning:",
            "",
            "```text",
            "The catalog is not exposed as an easy string -> constructor -> tuple table.",
            "The remaining tuple inputs likely require deeper data-flow reconstruction or a phone trace.",
            "```",
            "",
            "An offline composer exists for the final step once the missing bytes are recovered:",
            "",
            "```text",
            "obd-on-pc/compose_carista_3b9a_tuple.py",
            "```",
            "",
        ]
    )

    data: dict[str, object] = {
        "current_coding": CURRENT_CODING,
        "target_coding": TARGET_CODING,
        "read_literal": read_request,
        "write_literal": write_request,
        "coding_type_lookup": [f"{byte:02X}" for byte in lookup_bytes],
        "symbols": [item.__dict__ for item in symbols],
        "changed_chunks": [chunk.__dict__ for chunk in chunks],
        "known_builder_shape": {
            "prefix": "3B9A",
            "value_length": 6,
            "raw_address_length": 4,
            "type_2_tail_length": 3,
        },
        "offline_31b8_findings": {
            "kwp_profile_coding_address_shorts": ["0103", "0104", "0106", "0108", "0102", "0107"],
            "bcm25_profile_coding_address_shorts": ["0106", "0102", "0103", "0107", "0108", "0114"],
            "closest_static_address_short": "0106",
            "status": "31B8 exposes ECU-list coding-address shorts only; actual rawAddress4/coding selector/tail require positive 1A9B metadata",
        },
        "writer_flow_findings": {
            "input_shape": "64-bit raw-value key plus compact value vector",
            "coding_type_rules": [
                "type 2 preserved",
                "non-type-2 normalized to type 3",
                "sentinel metadata path forces type 5",
            ],
            "blind_full_coding_results": {
                "3B9A_plus_30_byte_coding": "no useful response",
                "2E0600_plus_30_byte_coding": "parsed negative response 7F2E22",
            },
        },
    }
    return "\n".join(lines), data


def main() -> int:
    parser = argparse.ArgumentParser(description="Analyze Carista's static write tuple inputs.")
    parser.add_argument("--output", type=Path, default=DOCS_ROOT / "carista_write_tuple_recovery_report.md")
    parser.add_argument("--json-output", type=Path, default=ROOT / "carista_write_tuple_recovery_report.json")
    args = parser.parse_args()

    lib_data, source = load_lib_bytes()
    inspector = ElfInspector(lib_data, source)
    report, data = build_report(inspector)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.json_output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(report, encoding="utf-8")
    args.json_output.write_text(json.dumps(data, indent=2, sort_keys=True), encoding="utf-8")
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
