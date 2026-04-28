from __future__ import annotations

import argparse
import json
import re
from dataclasses import asdict, dataclass
from datetime import date, datetime, timezone
from pathlib import Path
from typing import Literal, TypeAlias, cast


HexString: TypeAlias = str
JsonObject: TypeAlias = dict[str, object]
BitAction: TypeAlias = Literal["set", "clear"]
BitState: TypeAlias = Literal["set", "clear"]
CorneringFixKey: TypeAlias = Literal["base-fog", "turn-signal"]
GateName: TypeAlias = Literal["read_long_coding", "map_supported_settings_for_car", "get_vag_can_ecu_info", "build_write_tuples"]
GateStatus: TypeAlias = Literal["pass", "block"]
SettingStatus: TypeAlias = Literal["already_enabled", "pending_enable"]
TupleStatus: TypeAlias = Literal["blocked_missing_5A9B_metadata", "ready_for_review"]
UdsDid: TypeAlias = int
HEX_RE = re.compile(r"^[0-9A-F]+$", re.IGNORECASE)

CODING_TYPE_LOOKUP: dict[int, HexString] = {
    0: "00",
    1: "10",
    2: "10",
    3: "03",
    4: "10",
    5: "10",
}
CORNERING_FIXES: dict[CorneringFixKey, tuple[int, int, str]] = {
    "base-fog": (12, 6, "Base fog-light cornering function"),
    "turn-signal": (21, 2, "Turn-signal-triggered cornering assist"),
}
PQ25_SUPPORTED_SETTING_DEFINITIONS: tuple[tuple[str, str, CorneringFixKey], ...] = (
    (
        "car_setting_cornering_lights_via_fogs",
        "Cornering lights using fog lights",
        "base-fog",
    ),
    (
        "car_setting_cornering_lights_with_turn_signals",
        "Turn on cornering lights when turn signal is on",
        "turn-signal",
    ),
)
CARISTA_DATE_WRITE_DID = 0xF199
CARISTA_WORKSHOP_CODE_WRITE_DID = 0xF198
CARISTA_LONG_CODING_DID = 0x0600


@dataclass(frozen=True)
class VagEcuInfoWithCoding:
    response: HexString
    stripped_payload: HexString
    part_number: str
    raw_address4: HexString
    coding_type_selector: HexString
    coding_type: int
    tail: HexString
    initial_value6: HexString
    suffix: HexString


@dataclass(frozen=True)
class WriteVagCodingCommand:
    value6: HexString
    raw_address4: HexString
    coding_type: int
    tail: HexString = ""


@dataclass(frozen=True)
class DerivedValue:
    value6: HexString
    chunk_index: int
    byte_start: int
    byte_index: int | None = None
    bit_index: int | None = None
    bit_action: str | None = None
    label: str | None = None


@dataclass(frozen=True)
class Pq25SupportedSetting:
    key: str
    label: str
    cornering_fix: CorneringFixKey
    byte_index: int
    bit_index: int
    current_state: BitState
    desired_state: BitState
    chunk_index: int
    byte_start: int
    current_value6: HexString
    target_value6: HexString
    status: SettingStatus


@dataclass(frozen=True)
class TupleCandidate:
    key: str
    label: str
    cornering_fix: CorneringFixKey
    value6: HexString
    status: TupleStatus
    request: HexString | None = None
    raw_address4: HexString | None = None
    coding_type: int | None = None
    tail: HexString = ""
    reason: str = ""


@dataclass(frozen=True)
class WriteDataByIdentifierRequest:
    did: UdsDid
    payload: HexString
    request: HexString
    label: str


@dataclass(frozen=True)
class CaristaUdsCodingWritePlan:
    current_coding: HexString
    target_coding: HexString
    date_payload: HexString
    workshop_code_payload: HexString
    requests: list[WriteDataByIdentifierRequest]
    changed_bytes: dict[int, tuple[HexString, HexString]]


@dataclass(frozen=True)
class RecoveredRequestBuilders:
    GetVagCanEcuInfoCommand_getRequest: HexString
    ReadVagCanLongCodingCommand_getRequest: HexString
    WriteVagCodingCommand_prefix: HexString


@dataclass(frozen=True)
class CodingValidation:
    length_bytes: int
    value: HexString


@dataclass(frozen=True)
class ValidationGate:
    name: GateName
    status: GateStatus
    detail: str


@dataclass(frozen=True)
class CaristaProcessValidation:
    requests: RecoveredRequestBuilders
    coding: CodingValidation
    ecu_info: VagEcuInfoWithCoding | None
    supported_settings: list[Pq25SupportedSetting]
    tuple_candidates: list[TupleCandidate]
    gates: list[ValidationGate]


def normalize_hex(value: str) -> HexString:
    return re.sub(r"[^0-9A-Fa-f]", "", value).upper()


def json_objects_from_text(text: str) -> list[JsonObject]:
    data: object = json.loads(text)
    entries: list[object] = data if isinstance(data, list) else [data]
    objects: list[JsonObject] = []
    for entry in entries:
        if isinstance(entry, dict):
            objects.append(cast(JsonObject, entry))
    return objects


def clean_hex(value: str, label: str) -> HexString:
    cleaned = normalize_hex(value)
    if len(cleaned) % 2:
        raise ValueError(f"{label} must have even hex length")
    return cleaned


def require_len(value: str, label: str, expected_bytes: int) -> HexString:
    cleaned = clean_hex(value, label)
    actual = len(cleaned) // 2
    if actual != expected_bytes:
        raise ValueError(f"{label} must be {expected_bytes} bytes, got {actual}")
    return cleaned


def one_byte(value: int, label: str) -> HexString:
    if not 0 <= value <= 0xFF:
        raise ValueError(f"{label} must fit in one byte")
    return f"{value:02X}"


def ascii_from_hex(value: str) -> str:
    cleaned = clean_hex(value, "ascii hex")
    if not HEX_RE.match(cleaned):
        return ""
    raw = bytes.fromhex(cleaned)
    return "".join(chr(byte) if 32 <= byte <= 126 else "." for byte in raw)


def normalize_coding(value: str) -> HexString:
    cleaned = clean_hex(value, "coding")
    for prefix in ("620600", "5A9A"):
        if cleaned.startswith(prefix):
            cleaned = cleaned[len(prefix):]
            break
    if not cleaned:
        raise ValueError("coding is empty")
    return cleaned


def parse_iso_date(value: str | None) -> date:
    if not value:
        return datetime.now(timezone.utc).date()
    return date.fromisoformat(value)


def validate_did(did: int) -> UdsDid:
    if not 0 <= did <= 0xFFFF:
        raise ValueError(f"DID must fit in 16 bits, got {did}")
    return did


def WriteDataByIdentifierCommand_getRequest(did: int, payload: HexString) -> HexString:
    did = validate_did(did)
    payload = clean_hex(payload, "WriteDataByIdentifier payload")
    return f"2E{did:04X}{payload}"


def carista_date_payload(value: date | None = None) -> HexString:
    # Carista formats UTC tm_year % 100, tm_mon + 1, tm_mday as "%02d" strings,
    # then parses those strings as bytes. The result is YYMMDD BCD-style bytes.
    value = value or datetime.now(timezone.utc).date()
    return f"{value.year % 100:02d}{value.month:02d}{value.day:02d}"


def normalize_workshop_code_payload(value: str) -> HexString:
    return require_len(value, "workshop-code payload", 6)


def set_coding_bit(coding: HexString, byte_index: int, bit_index: int) -> HexString:
    data = bytearray.fromhex(normalize_coding(coding))
    if not 0 <= byte_index < len(data):
        raise ValueError(f"byte index {byte_index} is outside {len(data)} coding bytes")
    data[byte_index] = apply_bit(data[byte_index], bit_index, "set")
    return data.hex().upper()


def apply_cornering_fixes(coding: HexString, fixes: tuple[CorneringFixKey, ...]) -> HexString:
    target = normalize_coding(coding)
    for fix in fixes:
        byte_index, bit_index, _description = CORNERING_FIXES[fix]
        target = set_coding_bit(target, byte_index, bit_index)
    return target


def changed_coding_bytes(current: HexString, target: HexString) -> dict[int, tuple[HexString, HexString]]:
    current_bytes = bytes.fromhex(normalize_coding(current))
    target_bytes = bytes.fromhex(normalize_coding(target))
    if len(current_bytes) != len(target_bytes):
        raise ValueError("current and target coding must have the same length")
    return {
        index: (f"{old:02X}", f"{new:02X}")
        for index, (old, new) in enumerate(zip(current_bytes, target_bytes, strict=True))
        if old != new
    }


def build_carista_uds_coding_write_plan(
    current_coding: HexString,
    target_coding: HexString,
    *,
    workshop_code_payload: HexString,
    date_value: date | None = None,
) -> CaristaUdsCodingWritePlan:
    current = normalize_coding(current_coding)
    target = normalize_coding(target_coding)
    if len(current) != len(target):
        raise ValueError("current and target coding must have the same byte length")
    if len(target) // 2 != 30:
        raise ValueError(f"PQ25 DID 0600 coding should be 30 bytes, got {len(target) // 2}")

    date_payload = carista_date_payload(date_value)
    workshop_payload = normalize_workshop_code_payload(workshop_code_payload)
    requests = [
        WriteDataByIdentifierRequest(
            did=CARISTA_DATE_WRITE_DID,
            payload=date_payload,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_DATE_WRITE_DID, date_payload),
            label="Carista DATE_WRITE_ID pre-write",
        ),
        WriteDataByIdentifierRequest(
            did=CARISTA_WORKSHOP_CODE_WRITE_DID,
            payload=workshop_payload,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_WORKSHOP_CODE_WRITE_DID, workshop_payload),
            label="Carista WORKSHOP_CODE_WRITE_ID pre-write",
        ),
        WriteDataByIdentifierRequest(
            did=CARISTA_LONG_CODING_DID,
            payload=target,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_LONG_CODING_DID, target),
            label="Carista UDS long-coding write",
        ),
    ]
    return CaristaUdsCodingWritePlan(
        current_coding=current,
        target_coding=target,
        date_payload=date_payload,
        workshop_code_payload=workshop_payload,
        requests=requests,
        changed_bytes=changed_coding_bytes(current, target),
    )


def read_coding(coding: str | None, coding_file: str | None) -> HexString | None:
    if coding_file:
        path = Path(coding_file)
        text = path.read_text(encoding="utf-8")
        if path.suffix.lower() == ".json":
            for entry in json_objects_from_text(text):
                read_result = entry.get("read_result")
                if not isinstance(read_result, str):
                    continue
                candidate = normalize_hex(read_result)
                if candidate.startswith(("620600", "5A9A")):
                    return normalize_coding(candidate)
            raise ValueError(f"no 620600 or 5A9A read_result found in {coding_file}")
        return normalize_coding(text)
    if coding:
        return normalize_coding(coding)
    return None


def ReadVagCanLongCodingCommand_processLongCoding(response: HexString) -> HexString | None:
    cleaned = clean_hex(response, "long-coding response")
    if cleaned.startswith(("5A9A", "620600")):
        return normalize_coding(cleaned)
    return None


def apply_bit(value: int, bit_index: int, action: BitAction) -> int:
    if not 0 <= bit_index <= 7:
        raise ValueError("bit index must be between 0 and 7 (inclusive)")
    mask = 1 << bit_index
    if action == "set":
        return value | mask
    if action == "clear":
        return value & ~mask
    raise ValueError(f"unsupported bit action {action!r}")


def derive_value6(
    coding: HexString,
    chunk_size: int,
    chunk_index: int | None,
    byte_index: int | None,
    bit_index: int | None,
    bit_action: BitAction | None,
    label: str | None,
) -> DerivedValue:
    if chunk_size <= 0:
        raise ValueError("chunk size must be positive")
    data = bytearray.fromhex(normalize_coding(coding))
    if byte_index is not None:
        if not 0 <= byte_index < len(data):
            raise ValueError(f"byte index {byte_index} is outside {len(data)} coding bytes")
        if bit_index is not None:
            if bit_action is None:
                raise ValueError("bit action is required when bit index is supplied")
            data[byte_index] = apply_bit(data[byte_index], bit_index, bit_action)
        derived_chunk_index = byte_index // chunk_size
    elif chunk_index is not None:
        derived_chunk_index = chunk_index
    else:
        raise ValueError("provide --value6, --cornering-fix, --byte-index, or --chunk-index")

    byte_start = derived_chunk_index * chunk_size
    chunk = data[byte_start:byte_start + chunk_size]
    if len(chunk) != chunk_size:
        raise ValueError(f"chunk {derived_chunk_index} is incomplete for {len(data)} coding bytes")
    return DerivedValue(
        value6=chunk.hex().upper(),
        chunk_index=derived_chunk_index,
        byte_start=byte_start,
        byte_index=byte_index,
        bit_index=bit_index,
        bit_action=bit_action,
        label=label,
    )


def chunk_value6(coding: HexString, byte_index: int, chunk_size: int = 6) -> tuple[int, int, HexString]:
    data = bytes.fromhex(normalize_coding(coding))
    chunk_index = byte_index // chunk_size
    byte_start = chunk_index * chunk_size
    chunk = data[byte_start:byte_start + chunk_size]
    if len(chunk) != chunk_size:
        raise ValueError(f"chunk {chunk_index} is incomplete for {len(data)} coding bytes")
    return chunk_index, byte_start, chunk.hex().upper()


def bit_state(coding: HexString, byte_index: int, bit_index: int) -> BitState:
    data = bytes.fromhex(normalize_coding(coding))
    if not 0 <= byte_index < len(data):
        raise ValueError(f"byte index {byte_index} is outside {len(data)} coding bytes")
    return "set" if data[byte_index] & (1 << bit_index) else "clear"


def VagCanSettings_getPq25SupportedSettings(coding: HexString) -> list[Pq25SupportedSetting]:
    settings: list[Pq25SupportedSetting] = []
    for key, label, cornering_fix in PQ25_SUPPORTED_SETTING_DEFINITIONS:
        byte_index, bit_index, description = CORNERING_FIXES[cornering_fix]
        current_state = bit_state(coding, byte_index, bit_index)
        chunk_index, byte_start, current_value6 = chunk_value6(coding, byte_index)
        target = derive_value6(coding, 6, None, byte_index, bit_index, "set", description)
        settings.append(
            Pq25SupportedSetting(
                key=key,
                label=label,
                cornering_fix=cornering_fix,
                byte_index=byte_index,
                bit_index=bit_index,
                current_state=current_state,
                desired_state="set",
                chunk_index=chunk_index,
                byte_start=byte_start,
                current_value6=current_value6,
                target_value6=target.value6,
                status="already_enabled" if current_state == "set" else "pending_enable",
            )
        )
    return settings


def ByteUtils_insertValue(current_raw_value: HexString, offset: int, mask: HexString, requested_value: HexString) -> HexString:
    current = bytearray.fromhex(clean_hex(current_raw_value, "current raw value"))
    mask_bytes = bytes.fromhex(clean_hex(mask, "mask"))
    requested = bytes.fromhex(clean_hex(requested_value, "requested value"))
    if offset < 0:
        raise ValueError("offset must be non-negative")
    if len(mask_bytes) != len(requested):
        raise ValueError("mask and requested value must be the same length")
    if offset + len(mask_bytes) > len(current):
        raise ValueError("masked insert would extend past the current raw value")

    for index, mask_byte in enumerate(mask_bytes):
        current_index = offset + index
        current[current_index] = (current[current_index] & ~mask_byte) | (requested[index] & mask_byte)
    return current.hex().upper()


def VagSetting_insertValue(current_raw_value: HexString, offset: int, mask: HexString, requested_value: HexString) -> HexString:
    return ByteUtils_insertValue(current_raw_value, offset, mask, requested_value)


def GetVagCanEcuInfoCommand_getRequest() -> HexString:
    return "1A9B"


def ReadVagCanLongCodingCommand_getRequest() -> HexString:
    return "1A9A"


def WriteVagCodingCommand_suffix(coding_type: int, tail: HexString) -> HexString:
    if coding_type not in CODING_TYPE_LOOKUP:
        valid_types = ", ".join(str(key) for key in sorted(CODING_TYPE_LOOKUP))
        raise ValueError(f"coding type must be one of {valid_types}, got {coding_type}")
    mapped_type = CODING_TYPE_LOOKUP[coding_type]
    tail = clean_hex(tail, "tail")
    if coding_type == 2:
        if len(tail) // 2 != 3:
            raise ValueError("coding type 2 requires a 3-byte tail")
        return mapped_type + tail
    tail_len = len(tail) // 2
    return mapped_type + one_byte(tail_len + 1, "tail length + 1") + tail + "FF"


def WriteVagCodingCommand_ctor(
    value6: HexString,
    raw_address4: HexString,
    coding_type: int,
    tail: HexString = "",
) -> WriteVagCodingCommand:
    value6 = require_len(value6, "value6", 6)
    raw_address4 = require_len(raw_address4, "raw-address4", 4)
    tail = clean_hex(tail, "tail")
    if coding_type < 2:
        raise ValueError("Cannot write a coding value when type is NONE or UNKNOWN")
    if coding_type == 2 and len(tail) // 2 != 3:
        raise ValueError("Short coding value must be exactly 3 bytes")
    return WriteVagCodingCommand(value6=value6, raw_address4=raw_address4, coding_type=coding_type, tail=tail)


def WriteVagCodingCommand_getRequest(command: WriteVagCodingCommand) -> HexString:
    return "3B9A" + command.value6 + command.raw_address4 + WriteVagCodingCommand_suffix(command.coding_type, command.tail)


def build_request(value6: HexString, raw_address4: HexString, coding_type: int, tail: HexString) -> HexString:
    return WriteVagCodingCommand_getRequest(WriteVagCodingCommand_ctor(value6, raw_address4, coding_type, tail))


def GetVagCanEcuInfoCommand_processEcuInfo(response: HexString) -> VagEcuInfoWithCoding | None:
    response = clean_hex(response, "1A9B response")
    if not response.startswith("5A9B"):
        return None
    payload = bytes.fromhex(response)[2:]
    if len(payload) < 0x1A:
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

    suffix = ""
    if coding_type >= 2:
        suffix = WriteVagCodingCommand_suffix(coding_type, tail)

    return VagEcuInfoWithCoding(
        response=response,
        stripped_payload=payload.hex().upper(),
        part_number=ascii_from_hex(payload[:12].hex()).strip().strip("\x00"),
        raw_address4=payload[0x0C:0x10].hex().upper(),
        coding_type_selector=f"{selector:02X}",
        coding_type=coding_type,
        tail=tail,
        initial_value6=payload[0x14:0x1A].hex().upper(),
        suffix=suffix,
    )


decode_positive_1a9b_metadata = GetVagCanEcuInfoCommand_processEcuInfo


def read_first_positive_ecu_info(paths: list[Path]) -> VagEcuInfoWithCoding | None:
    for path in paths:
        if not path.exists():
            continue
        text = path.read_text(encoding="utf-8")
        if path.suffix.lower() == ".json":
            for entry in json_objects_from_text(text):
                read_result = entry.get("read_result")
                if isinstance(read_result, str):
                    try:
                        metadata = GetVagCanEcuInfoCommand_processEcuInfo(read_result)
                    except ValueError:
                        metadata = None
                    if metadata:
                        return metadata
            continue
        for token in re.split(r"\s+", text):
            try:
                metadata = GetVagCanEcuInfoCommand_processEcuInfo(token)
            except ValueError:
                metadata = None
            if metadata:
                return metadata
    return None


def VagOperationDelegate_writeVagCanCodingValue(
    ecu_info: VagEcuInfoWithCoding,
    value6: HexString,
    *,
    force_sentinel_type5: bool = False,
) -> WriteVagCodingCommand:
    if force_sentinel_type5:
        coding_type = 5
        tail = ""
    elif ecu_info.coding_type == 2:
        coding_type = 2
        tail = ecu_info.tail
    else:
        coding_type = 3
        tail = ""
    return WriteVagCodingCommand_ctor(value6, ecu_info.raw_address4, coding_type, tail)


def build_tuple_candidates(
    settings: list[Pq25SupportedSetting],
    ecu_info: VagEcuInfoWithCoding | None,
) -> list[TupleCandidate]:
    candidates: list[TupleCandidate] = []
    for setting in settings:
        if ecu_info is None:
            candidates.append(
                TupleCandidate(
                    key=setting.key,
                    label=setting.label,
                    cornering_fix=setting.cornering_fix,
                    value6=setting.target_value6,
                    status="blocked_missing_5A9B_metadata",
                    reason="Need positive GetVagCanEcuInfoCommand / 5A9B metadata for rawAddress4, coding type, and tail.",
                )
            )
            continue

        command = VagOperationDelegate_writeVagCanCodingValue(ecu_info, setting.target_value6)
        candidates.append(
            TupleCandidate(
                key=setting.key,
                label=setting.label,
                cornering_fix=setting.cornering_fix,
                value6=setting.target_value6,
                status="ready_for_review",
                request=WriteVagCodingCommand_getRequest(command),
                raw_address4=command.raw_address4,
                coding_type=command.coding_type,
                tail=command.tail,
            )
        )
    return candidates


def validate_carista_process(
    coding: HexString,
    ecu_info: VagEcuInfoWithCoding | None,
) -> CaristaProcessValidation:
    normalized_coding = normalize_coding(coding)
    settings = VagCanSettings_getPq25SupportedSettings(normalized_coding)
    tuple_candidates = build_tuple_candidates(settings, ecu_info)
    tuple_ready = bool(tuple_candidates) and all(candidate.status == "ready_for_review" for candidate in tuple_candidates)
    return CaristaProcessValidation(
        requests=RecoveredRequestBuilders(
            GetVagCanEcuInfoCommand_getRequest=GetVagCanEcuInfoCommand_getRequest(),
            ReadVagCanLongCodingCommand_getRequest=ReadVagCanLongCodingCommand_getRequest(),
            WriteVagCodingCommand_prefix="3B9A",
        ),
        coding=CodingValidation(length_bytes=len(normalized_coding) // 2, value=normalized_coding),
        ecu_info=ecu_info,
        supported_settings=settings,
        tuple_candidates=tuple_candidates,
        gates=[
            ValidationGate(
                name="read_long_coding",
                status="pass",
                detail="Current coding is loaded from direct 220600 or Carista 5A9A long-coding data.",
            ),
            ValidationGate(
                name="map_supported_settings_for_car",
                status="pass" if settings else "block",
                detail="PQ25 cornering settings are mapped from Carista labels to byte 12 bit 6 and byte 21 bit 2.",
            ),
            ValidationGate(
                name="get_vag_can_ecu_info",
                status="pass" if ecu_info else "block",
                detail="Need positive 5A9B to recover rawAddress4, coding selector, and tail." if ecu_info is None else "Positive 5A9B metadata decoded.",
            ),
            ValidationGate(
                name="build_write_tuples",
                status="pass" if tuple_ready else "block",
                detail="WriteVagCodingCommand requests are review-ready." if tuple_ready else "Tuple bytes are blocked until ECU metadata is present.",
            ),
        ],
    )


def render_carista_process_validation(result: CaristaProcessValidation) -> str:
    lines = [
        "Carista VAGCAN reproduction validation",
        "",
        "Recovered request builders:",
        f"  GetVagCanEcuInfoCommand_getRequest: {result.requests.GetVagCanEcuInfoCommand_getRequest}",
        f"  ReadVagCanLongCodingCommand_getRequest: {result.requests.ReadVagCanLongCodingCommand_getRequest}",
        f"  WriteVagCodingCommand prefix: {result.requests.WriteVagCodingCommand_prefix}",
        "",
        f"Current coding: {result.coding.value}",
        f"Coding length:  {result.coding.length_bytes} bytes",
        "",
        "Validation gates:",
    ]
    for gate in result.gates:
        lines.append(f"  {gate.status.upper():5} {gate.name}: {gate.detail}")

    lines.extend(["", "Mapped PQ25 supported settings:"])
    for setting in result.supported_settings:
        lines.append(
            f"  {setting.cornering_fix}: {setting.key} byte {setting.byte_index} bit {setting.bit_index} "
            f"{setting.current_state} -> {setting.desired_state}, value6 {setting.target_value6}"
        )

    lines.extend(["", "ECU metadata:"])
    if result.ecu_info:
        lines.append(
            f"  rawAddress4={result.ecu_info.raw_address4} selector={result.ecu_info.coding_type_selector} "
            f"codingType={result.ecu_info.coding_type} tail={result.ecu_info.tail or '<empty>'}"
        )
    else:
        lines.append("  missing positive 5A9B; do not build or execute complete tuples yet")

    lines.extend(["", "Tuple candidates:"])
    for candidate in result.tuple_candidates:
        if candidate.request:
            lines.append(f"  {candidate.cornering_fix}: {candidate.request} ({candidate.status})")
        else:
            lines.append(f"  {candidate.cornering_fix}: value6 {candidate.value6} ({candidate.status})")

    return "\n".join(lines) + "\n"


def render_carista_uds_coding_write_plan(plan: CaristaUdsCodingWritePlan) -> str:
    lines = [
        "Carista UDS coding write plan",
        "",
        f"Current coding: {plan.current_coding}",
        f"Target coding:  {plan.target_coding}",
        "",
        "Changed bytes:",
    ]
    for index, (old, new) in plan.changed_bytes.items():
        lines.append(f"  byte {index}: {old} -> {new}")
    if not plan.changed_bytes:
        lines.append("  none")

    lines.extend(
        [
            "",
            "Recovered Carista UDS request sequence:",
        ]
    )
    for request in plan.requests:
        lines.append(f"  {request.label}: {request.request}")

    lines.extend(
        [
            "",
            "Proof anchors:",
            "  VagUdsCodingSetting(ecu, vector) hardcodes DID 0600 and setting type 8.",
            "  writeRawValue dispatches type 8 into writeVagUdsValue.",
            "  writeVagUdsValue sends DATE_WRITE_ID F199, WORKSHOP_CODE_WRITE_ID F198, then target DID 0600.",
        ]
    )
    return "\n".join(lines) + "\n"


def _print_request(function_name: str) -> int:
    if function_name == "GetVagCanEcuInfoCommand_getRequest":
        print(GetVagCanEcuInfoCommand_getRequest())
        return 0
    if function_name == "ReadVagCanLongCodingCommand_getRequest":
        print(ReadVagCanLongCodingCommand_getRequest())
        return 0
    raise ValueError(f"unknown request builder {function_name}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Python reproduction of the recovered Carista VAGCAN coding helpers.")
    parser.add_argument(
        "--print-request",
        choices=("GetVagCanEcuInfoCommand_getRequest", "ReadVagCanLongCodingCommand_getRequest"),
        help="Print a recovered read request literal and exit.",
    )
    parser.add_argument("--decode-ecu-info", help="Decode a positive 5A9B ECU-info response using Carista offsets.")
    parser.add_argument("--validate-workflow", action="store_true", help="Validate the full recovered Carista-like PQ25 workflow.")
    parser.add_argument("--coding", help="Current long-coding hex or raw 620600/5A9A response for workflow validation.")
    parser.add_argument("--coding-file", help="File containing current long coding or direct-read JSON summary.")
    parser.add_argument("--ecu-info-response", help="Optional positive 5A9B response for workflow validation.")
    parser.add_argument("--ecu-info-file", action="append", type=Path, default=[], help="JSON/text file to scan for a positive 5A9B response. Can be repeated.")
    parser.add_argument("--json-output", type=Path, help="Optional JSON output path.")
    parser.add_argument("--uds-write-plan", action="store_true", help="Print the recovered Carista UDS DID 0600 write plan.")
    parser.add_argument("--target-coding", help="Explicit target long coding for --uds-write-plan.")
    parser.add_argument(
        "--apply-cornering-fix",
        action="append",
        choices=sorted(CORNERING_FIXES),
        help="For --uds-write-plan, derive target coding by setting a known cornering bit. Can be repeated.",
    )
    parser.add_argument("--workshop-code", help="6-byte workshop-code payload, usually from 22F1A5 without the 62F1A5 prefix.")
    parser.add_argument("--date", dest="date_value", help="Date for F199 payload as YYYY-MM-DD. Defaults to today.")
    args = parser.parse_args()

    if args.print_request:
        return _print_request(args.print_request)
    if args.decode_ecu_info:
        metadata = GetVagCanEcuInfoCommand_processEcuInfo(args.decode_ecu_info)
        if metadata is None:
            print("No positive 5A9B metadata decoded.")
            return 1
        print(json.dumps(metadata.__dict__, indent=2, sort_keys=True))
        return 0
    if args.validate_workflow:
        coding = read_coding(args.coding, args.coding_file)
        if coding is None:
            raise ValueError("--validate-workflow requires --coding or --coding-file")
        ecu_info = None
        if args.ecu_info_response:
            ecu_info = GetVagCanEcuInfoCommand_processEcuInfo(args.ecu_info_response)
            if ecu_info is None:
                raise ValueError("--ecu-info-response did not contain positive 5A9B metadata")
        if ecu_info is None and args.ecu_info_file:
            ecu_info = read_first_positive_ecu_info(args.ecu_info_file)
        result = validate_carista_process(coding, ecu_info)
        print(render_carista_process_validation(result), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(result), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0
    if args.uds_write_plan:
        coding = read_coding(args.coding, args.coding_file)
        if coding is None:
            raise ValueError("--uds-write-plan requires --coding or --coding-file")
        if args.target_coding:
            target = normalize_coding(args.target_coding)
        else:
            fixes = tuple(args.apply_cornering_fix or ("base-fog", "turn-signal"))
            target = apply_cornering_fixes(coding, cast(tuple[CorneringFixKey, ...], fixes))
        if not args.workshop_code:
            raise ValueError("--uds-write-plan requires --workshop-code from a positive 22F1A5 read")
        plan = build_carista_uds_coding_write_plan(
            coding,
            target,
            workshop_code_payload=args.workshop_code,
            date_value=parse_iso_date(args.date_value),
        )
        print(render_carista_uds_coding_write_plan(plan), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(plan), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0

    parser.print_help()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
