from __future__ import annotations

import argparse
import json
import re
import zipfile
from dataclasses import asdict, dataclass
from datetime import date
from io import BytesIO
from pathlib import Path
from typing import Any

from capstone import CS_ARCH_ARM, CS_MODE_THUMB, Cs
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parent
DOCS_ROOT = ROOT.parent / "docs" / "carista_apk_analysis"
EXTRACTED_LIB_PATH = ROOT / "reacquire_20260424" / "split_armv7_unpacked" / "lib" / "armeabi-v7a" / "libCarista.so"
ARM_SPLIT_APK = ROOT / "reacquire_20260424" / "config.armeabi_v7a.apk"
XAPK_PATH = ROOT / "reacquire_20260424" / "carista_9.8.2.xapk"
LIB_IN_APK = "lib/armeabi-v7a/libCarista.so"

CURRENT_CODING = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
TARGET_CODING = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"
BASE_FOG_VALUE6 = "6C680ED000C8"
TURN_SIGNAL_VALUE6 = "412F60A60000"
VAG_TP20_UNIT = 0x20

VAG_GET_SETTING_RAW_ADDRESS_SYMBOL = (
    "_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE"
)
VAG_WRITE_CODING_VALUE_SYMBOL = (
    "_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"
)
GENERIC_GET_RAW_ADDRESS_SYMBOL = "_ZN17OperationDelegate13getRawAddressEhP3Ecut"
VAG_GET_CODING_RAW_ADDRESS_SYMBOL = "_ZN20VagOperationDelegate19getCodingRawAddressEP3Ecut"
GET_VAGCAN_ECU_INFO_REQUEST_SYMBOL = "_ZNK23GetVagCanEcuInfoCommand10getRequestEv"
GET_VAGCAN_ECU_INFO_PROCESS_SYMBOL = (
    "_ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"
)
WRITE_VAG_CODING_GET_REQUEST_SYMBOL = "_ZNK21WriteVagCodingCommand10getRequestEv"

VAGCAN20_RE = re.compile(rb"ECU VAGCAN20 ([A-Z0-9]+): ([0-9A-F-]+)")
HEX_RE = re.compile(r"^[0-9A-F]+$")


@dataclass(frozen=True)
class SymbolFinding:
    symbol: str
    address: str
    size: int
    finding: str


@dataclass(frozen=True)
class SimulatorRecord:
    file_offset: str
    command: str
    response: str


@dataclass(frozen=True)
class EcuInfoMetadata:
    response: str
    stripped_payload: str
    part_number: str
    raw_address4: str
    coding_type_selector: str
    coding_type: int
    tail: str
    initial_value6: str
    suffix: str
    proof: str


@dataclass(frozen=True)
class SimulatorProfile:
    profile_index: int
    records: list[SimulatorRecord]
    identity: str
    long_coding_source: str
    coding_address_shorts: list[str]
    ecu_info_metadata: EcuInfoMetadata | None
    notes: str


@dataclass(frozen=True)
class TupleHypothesis:
    label: str
    value6: str
    raw_address_short: str
    raw_address4: str
    coding_type: int
    tail: str
    request: str
    confidence: str
    basis: str


def load_lib_bytes() -> tuple[bytes, str]:
    if EXTRACTED_LIB_PATH.exists():
        return EXTRACTED_LIB_PATH.read_bytes(), str(EXTRACTED_LIB_PATH)

    if ARM_SPLIT_APK.exists():
        with zipfile.ZipFile(ARM_SPLIT_APK) as archive:
            return archive.read(LIB_IN_APK), f"{ARM_SPLIT_APK}!{LIB_IN_APK}"

    if XAPK_PATH.exists():
        with zipfile.ZipFile(XAPK_PATH) as xapk:
            arm_apk_bytes = xapk.read("config.armeabi_v7a.apk")
        with zipfile.ZipFile(BytesIO(arm_apk_bytes)) as arm_apk:
            return arm_apk.read(LIB_IN_APK), f"{XAPK_PATH}!config.armeabi_v7a.apk!{LIB_IN_APK}"

    raise FileNotFoundError("could not find extracted libCarista.so, ARM split APK, or XAPK")


class ElfView:
    def __init__(self, data: bytes) -> None:
        self.data = data
        self.elf = ELFFile(BytesIO(data))
        self.sections = [
            (section.name, int(section["sh_addr"]), int(section["sh_offset"]), int(section["sh_size"]))
            for section in self.elf.iter_sections()
        ]
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
                    symbols[symbol.name] = (int(symbol["st_value"]) & ~1, int(symbol["st_size"]))
        return symbols

    def va_to_offset(self, virtual_address: int) -> int:
        virtual_address &= ~1
        for _name, address, offset, size in self.sections:
            if address <= virtual_address < address + size:
                return offset + virtual_address - address
        raise ValueError(f"virtual address not mapped: 0x{virtual_address:X}")

    def disassemble_symbol(self, symbol: str) -> list[Any]:
        address, size = self.symbols[symbol]
        offset = self.va_to_offset(address)
        return list(self.disassembler.disasm(self.data[offset:offset + size], address | 1))


def parse_vagcan20_records(data: bytes) -> list[SimulatorRecord]:
    records: list[SimulatorRecord] = []
    for match in VAGCAN20_RE.finditer(data):
        records.append(
            SimulatorRecord(
                file_offset=f"0x{match.start():08X}",
                command=match.group(1).decode("ascii"),
                response=match.group(2).decode("ascii"),
            )
        )
    return records


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
    raw = bytes.fromhex(value)
    return "".join(chr(byte) if 32 <= byte <= 126 else "." for byte in raw)


def decode_31b8_addresses(response: str) -> list[str]:
    if not response.startswith("71B8"):
        return []
    payload = response[4:]
    return [payload[index:index + 4] for index in range(0, len(payload), 4) if len(payload[index:index + 4]) == 4]


def decode_positive_1a9b_metadata(response: str) -> EcuInfoMetadata | None:
    if not response.startswith("5A9B") or not HEX_RE.match(response) or len(response) % 2:
        return None
    raw = bytes.fromhex(response)
    payload = raw[2:]
    if len(payload) <= 0x19:
        return None

    selector = payload[0x10]
    tail = ""
    if selector == 0x03:
        coding_type = 2
        tail = payload[0x11:0x14].hex().upper()
    elif selector == 0x10:
        coding_type = 3
    elif 0x21 <= selector <= 0x2F:
        coding_type = 4
        tail = payload[0x11:0x14].hex().upper()
    else:
        coding_type = 1

    return EcuInfoMetadata(
        response=response,
        stripped_payload=payload.hex().upper(),
        part_number=ascii_from_hex(payload[:12].hex().upper()).strip(),
        raw_address4=payload[0x0C:0x10].hex().upper(),
        coding_type_selector=f"{selector:02X}",
        coding_type=coding_type,
        tail=tail,
        initial_value6=payload[0x14:0x1A].hex().upper(),
        suffix=mapped_suffix(coding_type, tail),
        proof=(
            "Decoded from GetVagCanEcuInfoCommand::processEcuInfo: after stripping the positive "
            "5A9B response prefix, rawAddress4 is payload[0x0c:0x10], the coding selector "
            "is payload[0x10], type-2/type-4 tails are payload[0x11:0x14], and the "
            "stored 6-byte coding value is payload[0x14:0x1a]."
        ),
    )


def summarize_profile(index: int, records: list[SimulatorRecord]) -> SimulatorProfile:
    by_command = {record.command: record.response for record in records}
    identity_parts: list[str] = []
    for command in ("1A9B", "1A91", "22F187", "22F191", "22F197"):
        response = by_command.get(command)
        if response and response != "-5" and HEX_RE.match(response):
            identity_parts.append(f"{command}={ascii_from_hex(response)}")
    long_coding_source = ""
    if by_command.get("220600", "").startswith("620600"):
        long_coding_source = f"220600 -> {by_command['220600']}"
    elif by_command.get("1A9A", "").startswith("5A9A"):
        long_coding_source = f"1A9A -> {by_command['1A9A']}"
    coding_address_shorts = decode_31b8_addresses(by_command.get("31B80000", ""))
    ecu_info_metadata = decode_positive_1a9b_metadata(by_command.get("1A9B", ""))
    notes = []
    if ecu_info_metadata:
        notes.append("has positive 1A9B ECU-info coding metadata")
    if by_command.get("220600", "").startswith("620600"):
        notes.append("has direct UDS-style 220600 coding sample")
    if by_command.get("1A9A", "").startswith("5A9A"):
        notes.append("has KWP-style 1A9A long-coding sample")
    if coding_address_shorts:
        notes.append("has 31B80000 compact coding-address list")
    return SimulatorProfile(
        profile_index=index,
        records=records,
        identity="; ".join(identity_parts),
        long_coding_source=long_coding_source,
        coding_address_shorts=coding_address_shorts,
        ecu_info_metadata=ecu_info_metadata,
        notes="; ".join(notes),
    )


def mapped_suffix(coding_type: int, tail: str) -> str:
    lookup = {0: "00", 1: "10", 2: "10", 3: "03", 4: "10", 5: "10"}
    mapped = lookup[coding_type]
    if coding_type == 2:
        if len(tail) != 6:
            return "<type-2-tail-required>"
        return mapped + tail
    tail_len = len(tail) // 2
    return f"{mapped}{tail_len + 1:02X}{tail}FF"


def raw_address4_candidates(short_hex: str) -> list[tuple[str, str, str]]:
    short_hex = short_hex.upper()
    unit = f"{VAG_TP20_UNIT:02X}"
    return [
        ("short-left-padded", "0000" + short_hex, "4-byte big-endian short with leading zeros"),
        ("unit-plus-short", "00" + unit + short_hex, "generic raw key low32 shape: unit/address byte shifted above the 16-bit short"),
        ("short-plus-unit", short_hex + unit + "00", "alternate byte order check only; not preferred"),
    ]


def build_tuple_hypotheses(profiles: list[SimulatorProfile]) -> list[TupleHypothesis]:
    closest = next((profile for profile in profiles if any(record.command == "220600" and record.response.startswith("620600") for record in profile.records)), None)
    if closest is None:
        return []

    hypotheses: list[TupleHypothesis] = []
    for short_hex in closest.coding_address_shorts:
        for shape, raw_address4, shape_basis in raw_address4_candidates(short_hex):
            for label, value6 in (
                ("base-fog", BASE_FOG_VALUE6),
                ("turn-signal", TURN_SIGNAL_VALUE6),
            ):
                suffix = mapped_suffix(3, "")
                confidence = "unproven"
                basis = (
                    f"From closest embedded VAGCAN20 BCM25 simulator profile, 31B80000 lists {short_hex}; "
                    f"{shape_basis}; coding type 3 empty-tail suffix follows WriteVagCodingCommand rules. "
                    "The later parser proof shows 31B8 shorts are not the same thing as the "
                    "4-byte rawAddress4 vector consumed by WriteVagCodingCommand, so this remains "
                    "an address-family clue rather than a proven tuple."
                )
                hypotheses.append(
                    TupleHypothesis(
                        label=label,
                        value6=value6,
                        raw_address_short=short_hex,
                        raw_address4=raw_address4,
                        coding_type=3,
                        tail="",
                        request="3B9A" + value6 + raw_address4 + suffix,
                        confidence=confidence,
                        basis=basis,
                    )
                )
    return hypotheses


def find_symbol_findings(view: ElfView) -> list[SymbolFinding]:
    findings: list[SymbolFinding] = []
    symbol_notes = {
        GET_VAGCAN_ECU_INFO_REQUEST_SYMBOL: (
            "ECU-info request literal resolves to 1A9B; this is the command whose positive 5A9B response carries the rawAddress4/coding selector fields."
        ),
        GET_VAGCAN_ECU_INFO_PROCESS_SYMBOL: (
            "ECU-info parser strips the positive response prefix, reads rawAddress4 at payload offset 0x0c, coding selector at 0x10, optional tail at 0x11, and the stored 6-byte coding value at 0x14."
        ),
        WRITE_VAG_CODING_GET_REQUEST_SYMBOL: (
            "Request builder serializes 3B9A + 6-byte value + 4-byte rawAddress4 + coding-type-dependent suffix."
        ),
        GENERIC_GET_RAW_ADDRESS_SYMBOL: (
            "Generic formatter returns low32=(ecu_address << 16) | raw_short and carries setting/raw type in the second return register."
        ),
        VAG_GET_SETTING_RAW_ADDRESS_SYMBOL: (
            "VAG setting address path returns Ecu* plus a raw-address word; setting types 9/5 and 4 use special branches, ordinary long-coding settings use the base coding-address path."
        ),
        VAG_GET_CODING_RAW_ADDRESS_SYMBOL: (
            "VAG coding raw-address path queries ECU-info metadata, distinguishes coding families 2/3, and can fall back to alternate formatting paths."
        ),
        VAG_WRITE_CODING_VALUE_SYMBOL: (
            "Writer receives Ecu* + raw-address word + value vector, normalizes non-type-2 coding to type 3, has a sentinel type-5 path, then builds WriteVagCodingCommand."
        ),
    }
    for symbol, finding in symbol_notes.items():
        address, size = view.symbols.get(symbol, (0, 0))
        findings.append(SymbolFinding(symbol=symbol, address=f"0x{address:08X}" if address else "", size=size, finding=finding))
    return findings


def build_report(source: str, findings: list[SymbolFinding], profiles: list[SimulatorProfile], hypotheses: list[TupleHypothesis]) -> str:
    lines = [
        "# Carista Offline Tuple Candidate Analysis",
        "",
        f"Date: {date.today().isoformat()}",
        "",
        "This is a no-phone, no-Gadget static analysis pass over the reacquired Carista ARMv7 native library.",
        "It proves where the final `3B9A` tuple fields come from, then checks whether those fields exist for the actual `6R0937087K` evidence in this workspace.",
        "",
        "## Source",
        "",
        "```text",
        source,
        "```",
        "",
        "## Static Function Findings",
        "",
        "| Symbol | Address | Size | Finding |",
        "|---|---:|---:|---|",
    ]
    for finding in findings:
        lines.append(f"| `{finding.symbol}` | `{finding.address}` | {finding.size} | {finding.finding} |")

    lines.extend(
        [
            "",
            "## Embedded VAGCAN20 Simulator Profiles",
            "",
            "Carista carries canned VAGCAN20 responses in `libCarista.so`. These are not this exact car, but they reveal the metadata shape Carista expects.",
            "",
        ]
    )
    for profile in profiles:
        if not profile.coding_address_shorts and not profile.long_coding_source:
            continue
        lines.extend(
            [
                f"### Profile {profile.profile_index}",
                "",
                f"Identity: `{profile.identity or '<not decoded>'}`",
                "",
                f"Notes: {profile.notes or '<none>'}",
                "",
                "Coding source:",
                "",
                "```text",
                profile.long_coding_source or "<none>",
                "```",
                "",
                "`31B80000` coding-address shorts:",
                "",
                "```text",
                " ".join(profile.coding_address_shorts) or "<none>",
                "```",
                "",
            ]
        )
        if profile.ecu_info_metadata:
            metadata = profile.ecu_info_metadata
            lines.extend(
                [
                    "Positive `1A9B` ECU-info coding metadata:",
                    "",
                    "| Field | Value |",
                    "|---|---|",
                    f"| Part number payload | `{metadata.part_number}` |",
                    f"| RawAddress4 | `{metadata.raw_address4}` |",
                    f"| Coding selector byte | `{metadata.coding_type_selector}` |",
                    f"| Carista coding type | `{metadata.coding_type}` |",
                    f"| Tail | `{metadata.tail or '<empty>'}` |",
                    f"| Stored value6 | `{metadata.initial_value6}` |",
                    f"| Writer suffix | `{metadata.suffix}` |",
                    "",
                ]
            )

    lines.extend(
        [
            "## Tuple Proof Result",
            "",
            "The important correction from this pass is that `31B80000` is not the parser that fills the final `WriteVagCodingCommand` rawAddress4 vector. It is an ECU-list/coding-address-short query. The final tuple metadata comes from positive `1A9B` / `5A9B` ECU-info parsing.",
            "",
            "The static proof now supports these field origins:",
            "",
            "```text",
            "3B9A prefix        -> WriteVagCodingCommand::getRequest literal",
            "6-byte value       -> writer input value vector; for this car, derived from the two 6-byte coding chunks",
            "4-byte rawAddress4 -> positive 1A9B payload[0x0c:0x10] after stripping 5A9B",
            "coding selector    -> positive 1A9B payload[0x10]",
            "type-2/type-4 tail -> positive 1A9B payload[0x11:0x14] when that selector branch is used",
            "type-3 suffix      -> 0301FF when the selector is 0x10 / coding type 3 with empty tail",
            "```",
            "",
            "The embedded 1K0937049S-style simulator proves the parser with real bytes: `5A9B...` decodes to rawAddress4 `B0373034`, selector `10`, coding type `3`, empty tail, and suffix `0301FF`. That is proof of Carista's tuple construction, not proof that `6R0937087K` uses the same rawAddress4.",
            "",
            "For the actual Polo BCM evidence in this workspace, only the value vectors are proven:",
            "",
            "| Label | Proven value6 | Complete tuple status |",
            "|---|---:|---|",
            "| `base-fog` | `6C680ED000C8` | incomplete: missing actual positive-1A9B rawAddress4/coding selector/tail |",
            "| `turn-signal` | `412F60A60000` | incomplete: missing actual positive-1A9B rawAddress4/coding selector/tail |",
            "",
            "The earlier `31B8`-derived full requests are therefore retained only as rejected proof attempts:",
            "",
            "| Label | Value6 | Raw short | RawAddress4 hypothesis | Coding type | Request | Status |",
            "|---|---:|---:|---:|---:|---|---|",
        ]
    )
    for hypothesis in hypotheses:
        if hypothesis.raw_address_short != "0106" or hypothesis.raw_address4 not in {"00200106", "00000106"}:
            continue
        lines.append(
            f"| `{hypothesis.label}` | `{hypothesis.value6}` | `{hypothesis.raw_address_short}` | `{hypothesis.raw_address4}` | {hypothesis.coding_type} | `{hypothesis.request}` | {hypothesis.confidence} |"
        )

    lines.extend(
        [
            "",
            "## Current Boundary",
            "",
            "The deeper static pass proves the tuple parser and rejects `31B8 short -> rawAddress4` as a sufficient proof chain. The actual `6R0937087K` complete tuple cannot be proven from the current offline evidence because the workspace does not contain a positive `1A9B` / `5A9B` ECU-info response for that ECU.",
            "",
            "Still not proven offline:",
            "",
            "```text",
            "actual 6R0937087K rawAddress4 from positive 1A9B payload[0x0c:0x10]",
            "actual 6R0937087K coding selector from positive 1A9B payload[0x10]",
            "actual tail if the selector is a type-2/type-4 branch",
            "whether both byte-12 and byte-21 chunks share the same rawAddress4/tail",
            "required live precondition/session before 3B9A is accepted",
            "```",
            "",
            "So do not execute the `00200106` / `00000106` requests. The next non-phone proof step is a read-only in-car capture of a positive `1A9B`; once that exists, the tuple bytes can be filled deterministically from the offsets above.",
            "",
        ]
    )
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description="Build offline Carista 3B9A tuple candidates from native metadata.")
    parser.add_argument("--output", type=Path, default=DOCS_ROOT / "carista_offline_tuple_candidate_report.md")
    parser.add_argument("--json-output", type=Path, default=ROOT / "carista_offline_tuple_candidate_report.json")
    args = parser.parse_args()

    lib_data, source = load_lib_bytes()
    view = ElfView(lib_data)
    findings = find_symbol_findings(view)
    records = parse_vagcan20_records(lib_data)
    profiles = [summarize_profile(index + 1, profile) for index, profile in enumerate(split_profiles(records))]
    hypotheses = build_tuple_hypotheses(profiles)

    report = build_report(source, findings, profiles, hypotheses)
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
                    "note": "Parser proof: final rawAddress4/coding selector come from positive 1A9B ECU-info bytes. No positive 1A9B for the actual 6R0937087K is present, so complete requests remain unproven.",
                },
                "symbol_findings": [asdict(item) for item in findings],
                "profiles": [asdict(item) for item in profiles],
                "tuple_hypotheses": [asdict(item) for item in hypotheses],
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
