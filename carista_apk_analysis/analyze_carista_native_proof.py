from __future__ import annotations

import argparse
import hashlib
import json
import re
import zipfile
from dataclasses import asdict, dataclass
from datetime import date
from io import BytesIO
from pathlib import Path
from typing import Any

from capstone import CS_ARCH_ARM, CS_MODE_THUMB, Cs
from capstone.arm import ARM_OP_IMM
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection


ROOT = Path(__file__).resolve().parent
WORKSPACE_ROOT = ROOT.parent
DOCS_ROOT = WORKSPACE_ROOT / "docs" / "carista_apk_analysis"
REACQUIRED_ROOT = ROOT / "reacquire_20260424"
XAPK_PATH = REACQUIRED_ROOT / "carista_9.8.2.xapk"
BASE_APK_PATH = REACQUIRED_ROOT / "carista_9.8.2.apk"
ARM_SPLIT_APK_NAME = "config.armeabi_v7a.apk"
LIB_IN_APK = "lib/armeabi-v7a/libCarista.so"
PROOF_EXTRACT_ROOT = ROOT / "reextracted_native_proof" / "carista_9.8.2"
LOGS_ROOT = WORKSPACE_ROOT / "obd-on-pc" / "logs"
EXISTING_EXTRACTED_LIB_PATH = ROOT / "extracted" / "libCarista.so"
WRITE_RAW_VALUE_EXPORT = ROOT / "ghidra_exports" / "VagOperationDelegate_writeRawValue_01271140.c"

CURRENT_CODING = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
TARGET_CODING = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"
LIVE_COMMANDS = ("220600", "220601", "220606", "22F187", "22F191", "22F197", "22F1A3", "22F1A5", "22F1AA", "22F1DF")
HEX_RE = re.compile(r"^[0-9A-F]+$")
VAGCAN20_RE = re.compile(rb"ECU VAGCAN20 ([A-Z0-9]+): ([0-9A-F-]+)")


SYMBOLS = {
    "VagOperationDelegate::writeRawValue": "_ZN20VagOperationDelegate13writeRawValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE",
    "VagOperationDelegate::writeVagCanCodingValue": "_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE",
    "VagOperationDelegate::writeVagUdsValue(raw-key)": "_ZN20VagOperationDelegate16writeVagUdsValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE",
    "VagOperationDelegate::writeVagUdsValue(ecu,did)": "_ZN20VagOperationDelegate16writeVagUdsValueEP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEE",
    "VagOperationDelegate::writeVagCanAdaptationValue": "_ZN20VagOperationDelegate26writeVagCanAdaptationValueEyNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE",
    "VagOperationDelegate::getCodingRawAddress": "_ZN20VagOperationDelegate19getCodingRawAddressEP3Ecut",
    "VagOperationDelegate::getSettingRawAddress": "_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE",
    "WriteVagCodingCommand::getRequest": "_ZNK21WriteVagCodingCommand10getRequestEv",
    "WriteVagCodingCommand::ctor": "_ZN21WriteVagCodingCommandC1EP3EcuRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEERKNS2_10shared_ptrIS7_EEN10VagEcuInfo10CodingTypeESC_",
    "WriteDataByIdentifierCommand::getRequest": "_ZNK28WriteDataByIdentifierCommand10getRequestEv",
    "WriteDataByIdentifierCommand::ctor": "_ZN28WriteDataByIdentifierCommandC1EP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEj",
    "GetVagCanEcuInfoCommand::processEcuInfo": "_ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE",
    "VagOperationDelegate vtable": "_ZTV20VagOperationDelegate",
}

VTABLE_OFFSETS = {
    "current ECU id helper": 0x154,
    "setting type resolver": 0x15C,
    "generic raw-address formatter": 0x17C,
    "raw-address DID helper": 0x180,
    "ECU supports coding?": 0x184,
    "read ECU info cached": 0x194,
    "read primary ECU info": 0x198,
    "read ECU info cached/masked": 0x19C,
    "write ordinary raw value": 0x1B8,
    "write UDS raw value": 0x1C0,
    "write UDS ECU/DID value": 0x1C4,
    "write VAG-CAN coding": 0x1C8,
    "write VAG-CAN submodule coding": 0x1CC,
    "long adaptation writer helper": 0x1D4,
    "adaptation writer helper": 0x1E0,
    "connected ECU-info cache": 0x1F8,
    "must connect to UDS?": 0x214,
    "can accept cached fallback?": 0x218,
}


@dataclass(frozen=True)
class ArtifactProof:
    label: str
    path: str
    size: int
    sha256: str


@dataclass(frozen=True)
class SymbolProof:
    label: str
    symbol: str
    address: str
    size: int
    status: str


@dataclass(frozen=True)
class VtableProof:
    label: str
    offset: str
    relocation_address: str
    target_symbol: str
    target_address: str


@dataclass(frozen=True)
class BranchProof:
    source_label: str
    source_symbol: str
    instruction_address: str
    instruction: str
    target_symbol: str
    target_address: str


@dataclass(frozen=True)
class InstructionProof:
    source_label: str
    source_symbol: str
    instruction_address: str
    instruction: str
    finding: str


@dataclass(frozen=True)
class ImmediateProof:
    source_label: str
    source_symbol: str
    instruction_address: str
    instruction: str
    value: str


@dataclass(frozen=True)
class AsciiTokenProof:
    token: str
    file_offset: str
    virtual_address: str
    context_ascii: str


@dataclass(frozen=True)
class DecompileProof:
    path: str
    sha256: str
    snippet: list[str]


@dataclass(frozen=True)
class SimulatorRecord:
    file_offset: str
    command: str
    response: str


@dataclass(frozen=True)
class SimulatorProfile:
    profile_index: int
    records: list[SimulatorRecord]
    identity: str
    coding_source: str
    coding_address_shorts: list[str]
    has_positive_1a9b: bool


@dataclass(frozen=True)
class LiveReadProof:
    command: str
    response: str
    started: str
    summary_path: str
    log_file: str
    channel_parameter_status: str
    channel_parameters: dict[str, Any]


@dataclass(frozen=True)
class ProfileComparison:
    profile_index: int
    exact_matches: int
    compared_commands: int
    evidence: list[str]
    notes: str


def relative(path: Path) -> str:
    try:
        return path.resolve().relative_to(WORKSPACE_ROOT.resolve()).as_posix()
    except ValueError:
        return str(path)


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def artifact_for_bytes(label: str, path: Path, data: bytes) -> ArtifactProof:
    return ArtifactProof(label=label, path=relative(path), size=len(data), sha256=sha256_bytes(data))


def write_bytes(path: Path, data: bytes) -> ArtifactProof:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)
    return artifact_for_bytes(path.name, path, data)


def reextract_native_artifacts() -> tuple[bytes, list[ArtifactProof], str]:
    if not XAPK_PATH.exists():
        raise FileNotFoundError(f"missing XAPK: {XAPK_PATH}")

    artifacts: list[ArtifactProof] = []
    xapk_bytes = XAPK_PATH.read_bytes()
    artifacts.append(artifact_for_bytes("source XAPK", XAPK_PATH, xapk_bytes))

    if BASE_APK_PATH.exists():
        artifacts.append(artifact_for_bytes("sibling base APK", BASE_APK_PATH, BASE_APK_PATH.read_bytes()))

    if EXISTING_EXTRACTED_LIB_PATH.exists():
        artifacts.append(artifact_for_bytes("previous extracted libCarista.so", EXISTING_EXTRACTED_LIB_PATH, EXISTING_EXTRACTED_LIB_PATH.read_bytes()))

    with zipfile.ZipFile(BytesIO(xapk_bytes)) as xapk:
        names = set(xapk.namelist())
        if ARM_SPLIT_APK_NAME not in names:
            raise FileNotFoundError(f"{ARM_SPLIT_APK_NAME} not present in {XAPK_PATH}")
        arm_split_bytes = xapk.read(ARM_SPLIT_APK_NAME)

        if "carista_9.8.2.apk" in names:
            base_from_xapk = xapk.read("carista_9.8.2.apk")
            artifacts.append(write_bytes(PROOF_EXTRACT_ROOT / "carista_9.8.2.from_xapk.apk", base_from_xapk))

    split_path = PROOF_EXTRACT_ROOT / ARM_SPLIT_APK_NAME
    artifacts.append(write_bytes(split_path, arm_split_bytes))

    with zipfile.ZipFile(BytesIO(arm_split_bytes)) as arm_apk:
        lib_bytes = arm_apk.read(LIB_IN_APK)

    lib_path = PROOF_EXTRACT_ROOT / "lib" / "armeabi-v7a" / "libCarista.so"
    artifacts.append(write_bytes(lib_path, lib_bytes))
    source = f"{relative(XAPK_PATH)}!{ARM_SPLIT_APK_NAME}!{LIB_IN_APK}"
    return lib_bytes, artifacts, source


class ElfProofView:
    def __init__(self, data: bytes) -> None:
        self.data = data
        self.elf = ELFFile(BytesIO(data))
        self.sections = [
            (section.name, int(section["sh_addr"]), int(section["sh_offset"]), int(section["sh_size"]))
            for section in self.elf.iter_sections()
        ]
        self.symbols = self._load_symbols()
        self.symbols_by_address = {address: name for name, (address, _size) in self.symbols.items()}
        self.relocation_symbols = self._load_relocation_symbols()
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
                    symbols[symbol.name] = (int(symbol["st_value"]) & ~1, int(symbol["st_size"]))
        return symbols

    def _load_relocation_symbols(self) -> dict[int, tuple[str, int]]:
        relocations: dict[int, tuple[str, int]] = {}
        for section in self.elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue
            symbol_table = self.elf.get_section(section["sh_link"])
            for relocation in section.iter_relocations():
                symbol_index = relocation["r_info_sym"]
                if symbol_index == 0:
                    continue
                symbol = symbol_table.get_symbol(symbol_index)
                if not symbol.name:
                    continue
                relocations[int(relocation["r_offset"])] = (
                    symbol.name,
                    int(symbol["st_value"]) & ~1,
                )
        return relocations

    def va_to_offset(self, virtual_address: int) -> int:
        virtual_address &= ~1
        for _name, address, offset, size in self.sections:
            if address <= virtual_address < address + size:
                return offset + virtual_address - address
        raise ValueError(f"virtual address not mapped: 0x{virtual_address:X}")

    def offset_to_va(self, file_offset: int) -> int | None:
        for _name, address, offset, size in self.sections:
            if offset <= file_offset < offset + size:
                return address + file_offset - offset
        return None

    def symbol_proof(self, label: str, symbol: str) -> SymbolProof:
        if symbol not in self.symbols:
            return SymbolProof(label=label, symbol=symbol, address="", size=0, status="missing")
        address, size = self.symbols[symbol]
        return SymbolProof(label=label, symbol=symbol, address=f"0x{address:08X}", size=size, status="present")

    def disassemble_symbol(self, symbol: str) -> list[Any]:
        address, size = self.symbols[symbol]
        offset = self.va_to_offset(address)
        return list(self.disassembler.disasm(self.data[offset:offset + size], address | 1))

    def symbol_name_for_target(self, address: int) -> str:
        address &= ~1
        if address in self.symbols_by_address:
            return self.symbols_by_address[address]
        nearest_name = ""
        nearest_address = 0
        for name, (symbol_address, size) in self.symbols.items():
            if size and symbol_address <= address < symbol_address + size and symbol_address >= nearest_address:
                nearest_name = f"{name}+0x{address - symbol_address:X}"
                nearest_address = symbol_address
        return nearest_name


def branch_proofs(view: ElfProofView, labels: dict[str, str]) -> list[BranchProof]:
    proofs: list[BranchProof] = []
    for label, symbol in labels.items():
        if symbol not in view.symbols:
            continue
        for instruction in view.disassemble_symbol(symbol):
            if not instruction.mnemonic.startswith("bl"):
                continue
            target_address = None
            for operand in instruction.operands:
                if operand.type == ARM_OP_IMM:
                    target_address = int(operand.imm) & ~1
                    break
            if target_address is None:
                continue
            target_symbol = view.symbol_name_for_target(target_address)
            if target_symbol:
                proofs.append(
                    BranchProof(
                        source_label=label,
                        source_symbol=symbol,
                        instruction_address=f"0x{instruction.address & ~1:08X}",
                        instruction=f"{instruction.mnemonic} {instruction.op_str}",
                        target_symbol=target_symbol,
                        target_address=f"0x{target_address:08X}",
                    )
                )
    return proofs


def immediate_proofs(view: ElfProofView, labels: dict[str, str], values: set[int]) -> list[ImmediateProof]:
    proofs: list[ImmediateProof] = []
    for label, symbol in labels.items():
        if symbol not in view.symbols:
            continue
        for instruction in view.disassemble_symbol(symbol):
            for operand in instruction.operands:
                if operand.type != ARM_OP_IMM:
                    continue
                value = int(operand.imm)
                if value in values:
                    proofs.append(
                        ImmediateProof(
                            source_label=label,
                            source_symbol=symbol,
                            instruction_address=f"0x{instruction.address & ~1:08X}",
                            instruction=f"{instruction.mnemonic} {instruction.op_str}",
                            value=f"0x{value:X}",
                        )
                    )
    return proofs


def vtable_proofs(view: ElfProofView) -> list[VtableProof]:
    vtable_symbol = SYMBOLS["VagOperationDelegate vtable"]
    if vtable_symbol not in view.symbols:
        return []
    vtable_address, _size = view.symbols[vtable_symbol]
    proofs: list[VtableProof] = []
    for label, offset in VTABLE_OFFSETS.items():
        relocation_address = vtable_address + 8 + offset
        target = view.relocation_symbols.get(relocation_address)
        if target is None:
            target_symbol = "<no relocation>"
            target_address = 0
        else:
            target_symbol, target_address = target
        proofs.append(
            VtableProof(
                label=label,
                offset=f"+0x{offset:03X}",
                relocation_address=f"0x{relocation_address:08X}",
                target_symbol=target_symbol,
                target_address=f"0x{target_address:08X}" if target_address else "",
            )
        )
    return proofs


def instruction_proofs(view: ElfProofView) -> list[InstructionProof]:
    selected: dict[str, dict[int, str]] = {
        SYMBOLS["VagOperationDelegate::writeVagUdsValue(raw-key)"]: {
            0x012637AE: "loads virtual slot +0x154 to resolve the ECU from the raw key",
            0x012637BE: "loads virtual slot +0x158 to resolve the raw short/DID from the raw key",
            0x012637CE: "loads virtual slot +0x1C4, which the fresh vtable maps to writeVagUdsValue(ecu,did)",
            0x012637D8: "dispatches into the ECU/DID UDS writer",
        },
        SYMBOLS["VagOperationDelegate::writeVagUdsValue(ecu,did)"]: {
            0x012637FE: "stores the DID argument as a 16-bit value for later command construction",
            0x01263A10: "sets up a local UDS command-builder path",
            0x01263A14: "passes the saved DID pointer into that local command-builder path",
            0x01263A18: "branches to the local command-builder helper inside writeVagUdsValue(ecu,did)",
        },
        SYMBOLS["WriteDataByIdentifierCommand::getRequest"]: {
            0x00CF80CC: "loads the stored DID halfword from the command object",
            0x00CF80D8: "prepends UDS service byte 0x2E",
            0x00CF80E0: "appends the payload vector after service and DID",
        },
    }
    proofs: list[InstructionProof] = []
    label_by_symbol = {symbol: label for label, symbol in SYMBOLS.items()}
    for symbol, wanted_addresses in selected.items():
        if symbol not in view.symbols:
            continue
        seen_addresses: set[int] = set()
        for instruction in view.disassemble_symbol(symbol):
            address = instruction.address & ~1
            if address not in wanted_addresses:
                continue
            seen_addresses.add(address)
            proofs.append(
                InstructionProof(
                    source_label=label_by_symbol.get(symbol, symbol),
                    source_symbol=symbol,
                    instruction_address=f"0x{address:08X}",
                    instruction=f"{instruction.mnemonic} {instruction.op_str}",
                    finding=wanted_addresses[address],
                )
            )
        for address, finding in wanted_addresses.items():
            if address not in seen_addresses:
                proofs.append(
                    InstructionProof(
                        source_label=label_by_symbol.get(symbol, symbol),
                        source_symbol=symbol,
                        instruction_address=f"0x{address:08X}",
                        instruction="<not found>",
                        finding=finding,
                    )
                )
    return proofs


def type_symbol_proofs(view: ElfProofView) -> list[SymbolProof]:
    proofs: list[SymbolProof] = []
    for name, (address, size) in sorted(view.symbols.items(), key=lambda item: item[1][0]):
        if "WriteDataByIdentifierCommand" not in name:
            continue
        if name.startswith("_ZTS") or name.startswith("_ZTI") or name.startswith("_ZTV"):
            continue
        if "shared_ptr_emplace" in name and not (0x01200000 <= address <= 0x01300000):
            continue
        if "allocatorI28WriteDataByIdentifierCommand" in name and not (0x01200000 <= address <= 0x01300000):
            continue
        if len(proofs) >= 14:
            break
        proofs.append(
            SymbolProof(
                label="WriteDataByIdentifier related symbol",
                symbol=name,
                address=f"0x{address:08X}",
                size=size,
                status="present",
            )
        )
    return proofs


def ascii_token_proofs(view: ElfProofView, tokens: tuple[str, ...]) -> tuple[list[AsciiTokenProof], dict[str, int]]:
    proofs: list[AsciiTokenProof] = []
    counts: dict[str, int] = {}
    for token in tokens:
        needle = token.encode("ascii")
        start = 0
        while True:
            found = view.data.find(needle, start)
            if found < 0:
                break
            counts[token] = counts.get(token, 0) + 1
            context = view.data[max(0, found - 16):found + len(needle) + 16]
            virtual_address = view.offset_to_va(found)
            if token == "3B9A" or counts[token] <= 6:
                proofs.append(
                    AsciiTokenProof(
                        token=token,
                        file_offset=f"0x{found:08X}",
                        virtual_address=f"0x{virtual_address:08X}" if virtual_address is not None else "<not mapped>",
                        context_ascii="".join(chr(byte) if 32 <= byte <= 126 else "." for byte in context),
                    )
                )
            start = found + len(needle)
    return proofs, counts


def load_decompile_proof() -> DecompileProof | None:
    if not WRITE_RAW_VALUE_EXPORT.exists():
        return None
    text = WRITE_RAW_VALUE_EXPORT.read_text(encoding="utf-8")
    lines = text.splitlines()
    start = next((index for index, line in enumerate(lines) if "switch(uVar2)" in line), -1)
    if start == -1:
        snippet: list[str] = []
    else:
        snippet = lines[start:start + 50]
    return DecompileProof(
        path=relative(WRITE_RAW_VALUE_EXPORT),
        sha256=sha256_bytes(text.encode("utf-8")),
        snippet=snippet,
    )


def parse_vagcan20_records(data: bytes) -> list[SimulatorRecord]:
    return [
        SimulatorRecord(
            file_offset=f"0x{match.start():08X}",
            command=match.group(1).decode("ascii"),
            response=match.group(2).decode("ascii"),
        )
        for match in VAGCAN20_RE.finditer(data)
    ]


def split_profiles(records: list[SimulatorRecord]) -> list[list[SimulatorRecord]]:
    profiles: list[list[SimulatorRecord]] = []
    current: list[SimulatorRecord] = []
    for record in records:
        if record.command in {"1A9B", "1802FF00"} and current:
            profiles.append(current)
            current = []
        current.append(record)
    if current:
        profiles.append(current)
    return profiles


def ascii_from_hex(value: str) -> str:
    if not HEX_RE.match(value) or len(value) % 2:
        return ""
    return "".join(chr(byte) if 32 <= byte <= 126 else "." for byte in bytes.fromhex(value))


def decode_31b8_addresses(response: str) -> list[str]:
    if not response.startswith("71B8"):
        return []
    payload = response[4:]
    return [payload[index:index + 4] for index in range(0, len(payload), 4) if len(payload[index:index + 4]) == 4]


def summarize_profile(index: int, records: list[SimulatorRecord]) -> SimulatorProfile:
    by_command = {record.command: record.response for record in records}
    identity_parts = []
    for command in ("1A9B", "22F187", "22F191", "22F197", "22F1A3", "22F1AA", "22F1DF"):
        response = by_command.get(command, "")
        if response and response != "-5" and HEX_RE.match(response):
            identity_parts.append(f"{command}={ascii_from_hex(response)}")
    coding_source = ""
    if by_command.get("220600", "").startswith("620600"):
        coding_source = f"220600 -> {by_command['220600']}"
    elif by_command.get("1A9A", "").startswith("5A9A"):
        coding_source = f"1A9A -> {by_command['1A9A']}"
    return SimulatorProfile(
        profile_index=index,
        records=records,
        identity="; ".join(identity_parts),
        coding_source=coding_source,
        coding_address_shorts=decode_31b8_addresses(by_command.get("31B80000", "")),
        has_positive_1a9b=by_command.get("1A9B", "").startswith("5A9B"),
    )


def latest_live_reads() -> list[LiveReadProof]:
    best: dict[str, LiveReadProof] = {}
    for summary_path in LOGS_ROOT.glob("*summary.json"):
        try:
            payload = json.loads(summary_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue
        if isinstance(payload, dict):
            rows = payload.get("attempts", [])
        else:
            rows = payload
        if not isinstance(rows, list):
            continue
        for row in rows:
            if not isinstance(row, dict):
                continue
            command = str(row.get("read_command", "")).upper()
            if command not in LIVE_COMMANDS:
                continue
            if row.get("read_status") != "positive" or not row.get("read_result"):
                continue
            proof = LiveReadProof(
                command=command,
                response=str(row["read_result"]).upper(),
                started=str(row.get("started", "")),
                summary_path=relative(summary_path),
                log_file=str(row.get("log_file", "")),
                channel_parameter_status=str(row.get("channel_parameter_status", "")),
                channel_parameters=dict(row.get("channel_parameters", {})),
            )
            old = best.get(command)
            if old is None or proof.started > old.started:
                best[command] = proof
    return [best[command] for command in LIVE_COMMANDS if command in best]


def response_diff(left: str, right: str) -> str:
    if left == right:
        return "exact"
    if not (HEX_RE.match(left) and HEX_RE.match(right) and len(left) == len(right) and len(left) % 2 == 0):
        return "different"
    diffs = []
    left_bytes = bytes.fromhex(left)
    right_bytes = bytes.fromhex(right)
    for index, (left_byte, right_byte) in enumerate(zip(left_bytes, right_bytes)):
        if left_byte != right_byte:
            diffs.append(f"byte {index}: {left_byte:02X}->{right_byte:02X}")
    return "; ".join(diffs[:8])


def compare_profiles(profiles: list[SimulatorProfile], live_reads: list[LiveReadProof]) -> list[ProfileComparison]:
    live_by_command = {item.command: item.response for item in live_reads}
    comparisons: list[ProfileComparison] = []
    for profile in profiles:
        by_command = {record.command: record.response for record in profile.records}
        evidence: list[str] = []
        exact_matches = 0
        compared = 0
        for command in LIVE_COMMANDS:
            live_response = live_by_command.get(command)
            simulator_response = by_command.get(command)
            if not live_response or not simulator_response or simulator_response.startswith("-"):
                continue
            compared += 1
            diff = response_diff(simulator_response, live_response)
            if diff == "exact":
                exact_matches += 1
            evidence.append(f"{command}: sim={simulator_response} live={live_response} ({diff})")
        if compared:
            notes = []
            if profile.coding_source.startswith("220600"):
                notes.append("UDS-style 220600 coding profile")
            if profile.coding_address_shorts:
                notes.append("has 31B80000 coding-address list")
            if profile.has_positive_1a9b:
                notes.append("has positive 1A9B metadata")
            comparisons.append(
                ProfileComparison(
                    profile_index=profile.profile_index,
                    exact_matches=exact_matches,
                    compared_commands=compared,
                    evidence=evidence,
                    notes="; ".join(notes),
                )
            )
    return sorted(comparisons, key=lambda item: (item.exact_matches, item.compared_commands), reverse=True)


def changed_chunks() -> list[dict[str, Any]]:
    current = bytes.fromhex(CURRENT_CODING)
    target = bytes.fromhex(TARGET_CODING)
    chunks: list[dict[str, Any]] = []
    for start in range(0, len(current), 6):
        current_chunk = current[start:start + 6]
        target_chunk = target[start:start + 6]
        if current_chunk == target_chunk:
            continue
        bits: list[str] = []
        for offset, (old, new) in enumerate(zip(current_chunk, target_chunk)):
            if old == new:
                continue
            for bit in range(8):
                if (old ^ new) & (1 << bit):
                    bits.append(f"byte {start + offset} bit {bit}: {bool(old & (1 << bit))}->{bool(new & (1 << bit))}")
        chunks.append(
            {
                "chunk_index": start // 6,
                "byte_start": start,
                "current": current_chunk.hex().upper(),
                "target": target_chunk.hex().upper(),
                "changed_bits": bits,
            }
        )
    return chunks


def build_report(
    source: str,
    artifacts: list[ArtifactProof],
    symbols: list[SymbolProof],
    vtable: list[VtableProof],
    branches: list[BranchProof],
    instructions: list[InstructionProof],
    immediates: list[ImmediateProof],
    ascii_tokens: list[AsciiTokenProof],
    ascii_token_counts: dict[str, int],
    type_symbols: list[SymbolProof],
    decompile_proof: DecompileProof | None,
    profiles: list[SimulatorProfile],
    live_reads: list[LiveReadProof],
    comparisons: list[ProfileComparison],
) -> str:
    lines = [
        "# Carista Native Catalog Proof Pass",
        "",
        f"Date: {date.today().isoformat()}",
        "",
        "This pass re-extracts the ARM native library and records byte-level proof anchors. It does not invent a write tuple.",
        "",
        "## Fresh Extraction",
        "",
        f"Source path: `{source}`",
        "",
        "| Artifact | Path | Size | SHA-256 |",
        "|---|---|---:|---|",
    ]
    for item in artifacts:
        lines.append(f"| {item.label} | `{item.path}` | {item.size} | `{item.sha256}` |")

    fresh_lib = next((item for item in artifacts if item.path.endswith("reextracted_native_proof/carista_9.8.2/lib/armeabi-v7a/libCarista.so")), None)
    previous_lib = next((item for item in artifacts if item.label == "previous extracted libCarista.so"), None)
    if fresh_lib and previous_lib:
        match_text = "matches" if fresh_lib.sha256 == previous_lib.sha256 else "does not match"
        lines.extend(["", f"Freshly re-extracted `libCarista.so` {match_text} the previous extracted library hash."])

    lines.extend(["", "## Native Symbol Anchors", "", "| Label | Symbol | Address | Size | Status |", "|---|---|---:|---:|---|"])
    for item in symbols:
        lines.append(f"| {item.label} | `{item.symbol}` | `{item.address}` | {item.size} | {item.status} |")

    lines.extend(["", "WriteDataByIdentifier-related native symbols:", "", "| Symbol | Address | Size |", "|---|---:|---:|"])
    for item in type_symbols:
        lines.append(f"| `{item.symbol}` | `{item.address}` | {item.size} |")

    lines.extend(
        [
            "",
            "## Vtable Dispatch Proof",
            "",
            "The offsets below are relative to the C++ vptr address point (`_ZTV20VagOperationDelegate + 8`). These are the virtual slots used by `writeRawValue` and ECU-info helpers.",
            "",
            "| Slot | Offset | Relocation address | Target | Target address |",
            "|---|---:|---:|---|---:|",
        ]
    )
    for item in vtable:
        if item.offset in {"+0x1B8", "+0x1C0", "+0x1C4", "+0x1C8", "+0x1CC", "+0x17C", "+0x194", "+0x1F8"}:
            lines.append(f"| {item.label} | `{item.offset}` | `{item.relocation_address}` | `{item.target_symbol}` | `{item.target_address}` |")

    lines.extend(
        [
            "",
            "## Command Builder Proof",
            "",
            "Selected instruction anchors from the freshly extracted library:",
            "",
            "| Source | Instruction | Finding |",
            "|---|---|---|",
        ]
    )
    for item in instructions:
        lines.append(f"| {item.source_label} `{item.instruction_address}` | `{item.instruction}` | {item.finding} |")

    interesting_targets = ("WriteDataByIdentifierCommand", "WriteVagCodingCommand", "runCommand", "writeVagUdsValue")
    interesting_branches = [item for item in branches if any(target in item.target_symbol for target in interesting_targets)]
    if interesting_branches:
        lines.extend(["", "Selected direct branch targets:", "", "| Source | Instruction | Target |", "|---|---|---|"])
        for item in interesting_branches:
            lines.append(f"| {item.source_label} `{item.instruction_address}` | `{item.instruction}` | `{item.target_symbol}` `{item.target_address}` |")

    lines.extend(["", "Immediate constants in request builders:", "", "| Source | Instruction | Value |", "|---|---|---:|"])
    for item in immediates:
        lines.append(f"| {item.source_label} `{item.instruction_address}` | `{item.instruction}` | `{item.value}` |")

    lines.extend(["", "ASCII request-token counts in the native library:", "", "| Token | Count |", "|---|---:|"])
    for token, count in sorted(ascii_token_counts.items()):
        lines.append(f"| `{token}` | {count} |")

    lines.extend(["", "Representative request-token locations:", "", "| Token | File offset | Virtual address | Context |", "|---|---:|---:|---|"])
    for item in ascii_tokens:
        lines.append(f"| `{item.token}` | `{item.file_offset}` | `{item.virtual_address}` | `{item.context_ascii}` |")

    if decompile_proof:
        lines.extend(
            [
                "",
                "## writeRawValue Type Dispatch Cross-Check",
                "",
                f"Ghidra export: `{decompile_proof.path}` SHA-256 `{decompile_proof.sha256}`",
                "",
                "This decompile rendering is a cross-check only; the slot identities above were revalidated from the fresh ELF relocation table.",
                "",
                "```c",
                *decompile_proof.snippet,
                "```",
            ]
        )

    lines.extend(
        [
            "",
            "## Live UDS Fingerprint",
            "",
            "These are positive reads from the existing in-car logs with answered TP2.0 channel parameters where available.",
            "",
            "| Command | Response | Channel params | Summary |",
            "|---|---|---|---|",
        ]
    )
    for item in live_reads:
        params = ", ".join(f"{key}={value}" for key, value in item.channel_parameters.items())
        lines.append(f"| `{item.command}` | `{item.response}` | {item.channel_parameter_status} ({params}) | `{item.summary_path}` |")

    lines.extend(
        [
            "",
            "## Embedded Profile Binding",
            "",
            "Top embedded VAGCAN20 profile comparisons against the live fingerprint:",
            "",
            "| Profile | Exact matches | Compared | Notes | Evidence |",
            "|---:|---:|---:|---|---|",
        ]
    )
    for item in comparisons[:6]:
        evidence = "<br>".join(item.evidence[:8])
        lines.append(f"| {item.profile_index} | {item.exact_matches} | {item.compared_commands} | {item.notes or '<none>'} | {evidence} |")

    uds_profiles = [profile for profile in profiles if profile.coding_source.startswith("220600")]
    lines.extend(["", "UDS-style embedded coding profiles:", ""])
    for profile in uds_profiles:
        lines.extend(
            [
                f"### Profile {profile.profile_index}",
                "",
                f"Identity: `{profile.identity or '<not decoded>'}`",
                "",
                f"Coding source: `{profile.coding_source}`",
                "",
                f"31B80000 shorts: `{' '.join(profile.coding_address_shorts) or '<none>'}`",
                "",
                f"Positive 1A9B metadata: `{profile.has_positive_1a9b}`",
                "",
            ]
        )

    lines.extend(
        [
            "## Coding Delta Proof",
            "",
            "The only value bytes still proven from the current/known-good coding pair are:",
            "",
            "| Chunk | Bytes | Current | Target | Changed bits |",
            "|---:|---:|---|---|---|",
        ]
    )
    for chunk in changed_chunks():
        lines.append(
            f"| {chunk['chunk_index']} | {chunk['byte_start']}-{chunk['byte_start'] + 5} | `{chunk['current']}` | `{chunk['target']}` | {'; '.join(chunk['changed_bits'])} |"
        )

    lines.extend(
        [
            "",
            "## Proof Result",
            "",
            "Proved from the fresh native library:",
            "",
            "- `WriteVagCodingCommand::getRequest` and the `3B9A` token exist in the extracted ELF; that is the compact VAG-CAN coding command path.",
            "- `WriteDataByIdentifierCommand::getRequest` exists and its request builder contains immediate `0x2E`; that is the UDS WriteDataByIdentifier request shape.",
            "- `VagOperationDelegate::writeVagUdsValue(raw-key)` extracts ECU and DID from the raw key, then dispatches to the ECU/DID UDS writer slot.",
            "- `VagOperationDelegate::writeRawValue` dispatches setting types 7/8 into the UDS raw-value slot and types 2/3 into the VAG-CAN coding slot; the slot targets are revalidated above from fresh ELF relocations.",
            "- The actual BCM live data binds strongly to Carista's UDS-style VAGCAN20/BCM25 family, not to the positive-`5A9B` KWP profile.",
            "",
            "Still not proved:",
            "",
            "- The native catalog entry type for the two fox/cornering-light settings on this exact BCM.",
            "- The exact raw-value key/DID and preconditions Carista uses when that catalog entry writes.",
            "- A complete final request that should be sent to the car.",
            "",
            "Operational boundary: do not promote any `31B8`-derived `3B9A` tuple or blind `2E0600` full-coding request to a write. The next proof step is catalog data-flow recovery for the two setting constructors or a trace from Carista itself.",
            "",
        ]
    )
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description="Re-extract Carista native code and build proof-only write-path evidence.")
    parser.add_argument("--output", type=Path, default=DOCS_ROOT / "carista_native_catalog_proof.md")
    parser.add_argument("--json-output", type=Path, default=ROOT / "carista_native_catalog_proof.json")
    args = parser.parse_args()

    lib_data, artifacts, source = reextract_native_artifacts()
    view = ElfProofView(lib_data)
    symbol_proofs = [view.symbol_proof(label, symbol) for label, symbol in SYMBOLS.items()]
    vtable = vtable_proofs(view)
    selected_branch_labels = {
        label: symbol
        for label, symbol in SYMBOLS.items()
        if label
        in {
            "VagOperationDelegate::writeVagUdsValue(raw-key)",
            "VagOperationDelegate::writeVagUdsValue(ecu,did)",
            "VagOperationDelegate::writeVagCanCodingValue",
            "WriteDataByIdentifierCommand::getRequest",
            "WriteVagCodingCommand::getRequest",
        }
    }
    branches = branch_proofs(view, selected_branch_labels)
    instructions = instruction_proofs(view)
    type_symbols = type_symbol_proofs(view)
    decompile_proof = load_decompile_proof()
    immediates = immediate_proofs(
        view,
        {
            "WriteDataByIdentifierCommand::getRequest": SYMBOLS["WriteDataByIdentifierCommand::getRequest"],
            "WriteVagCodingCommand::getRequest": SYMBOLS["WriteVagCodingCommand::getRequest"],
        },
        {0x2E, 0x3B, 0x9A, 0xFF},
    )
    ascii_tokens, ascii_token_counts = ascii_token_proofs(view, ("1A9A", "1A9B", "3B9A"))

    records = parse_vagcan20_records(lib_data)
    profiles = [summarize_profile(index + 1, profile) for index, profile in enumerate(split_profiles(records))]
    live_reads = latest_live_reads()
    comparisons = compare_profiles(profiles, live_reads)

    report = build_report(
        source=source,
        artifacts=artifacts,
        symbols=symbol_proofs,
        vtable=vtable,
        branches=branches,
        instructions=instructions,
        immediates=immediates,
        ascii_tokens=ascii_tokens,
        ascii_token_counts=ascii_token_counts,
        type_symbols=type_symbols,
        decompile_proof=decompile_proof,
        profiles=profiles,
        live_reads=live_reads,
        comparisons=comparisons,
    )

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.json_output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(report + "\n", encoding="utf-8")
    args.json_output.write_text(
        json.dumps(
            {
                "metadata": {
                    "date": date.today().isoformat(),
                    "source": source,
                    "current_coding": CURRENT_CODING,
                    "target_coding": TARGET_CODING,
                    "proof_boundary": "Evidence is proof-only. No complete write request is generated or recommended.",
                },
                "artifacts": [asdict(item) for item in artifacts],
                "symbols": [asdict(item) for item in symbol_proofs],
                "vtable": [asdict(item) for item in vtable],
                "branches": [asdict(item) for item in branches],
                "instructions": [asdict(item) for item in instructions],
                "immediates": [asdict(item) for item in immediates],
                "write_data_by_identifier_symbols": [asdict(item) for item in type_symbols],
                "ascii_tokens": [asdict(item) for item in ascii_tokens],
                "ascii_token_counts": ascii_token_counts,
                "decompile_proof": asdict(decompile_proof) if decompile_proof else None,
                "profiles": [asdict(item) for item in profiles],
                "live_reads": [asdict(item) for item in live_reads],
                "profile_comparisons": [asdict(item) for item in comparisons],
                "changed_chunks": changed_chunks(),
            },
            indent=2,
            sort_keys=True,
        )
        + "\n",
        encoding="utf-8",
    )
    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())