from __future__ import annotations

import argparse
import json
import re
from dataclasses import asdict, dataclass, field
from pathlib import Path
from typing import Any, Iterable


HexString = str

HEX_TOKEN_RE = re.compile(r"(?<![0-9A-Fa-f])(?:[0-9A-Fa-f]{2}){2,}(?![0-9A-Fa-f])")
INTERESTING_RESPONSE_PREFIXES = ("58", "59", "7F")

UDS_DTC_STATUS_BITS = (
    (0x01, "testFailed"),
    (0x02, "testFailedThisOperationCycle"),
    (0x04, "pendingDTC"),
    (0x08, "confirmedDTC"),
    (0x10, "testNotCompletedSinceLastClear"),
    (0x20, "testFailedSinceLastClear"),
    (0x40, "testNotCompletedThisOperationCycle"),
    (0x80, "warningIndicatorRequested"),
)

NEGATIVE_RESPONSE_CODES = {
    0x10: "generalReject",
    0x11: "serviceNotSupported",
    0x12: "subFunctionNotSupported",
    0x13: "incorrectMessageLengthOrInvalidFormat",
    0x22: "conditionsNotCorrect",
    0x31: "requestOutOfRange",
    0x33: "securityAccessDenied",
    0x35: "invalidKey",
    0x36: "exceededNumberOfAttempts",
    0x37: "requiredTimeDelayNotExpired",
    0x78: "requestCorrectlyReceivedResponsePending",
}

UDS_READ_DTC_SUBFUNCTIONS = {
    0x01: "reportNumberOfDTCByStatusMask",
    0x02: "reportDTCByStatusMask",
    0x03: "reportDTCSnapshotIdentification",
    0x04: "reportDTCSnapshotRecordByDTCNumber",
    0x05: "reportDTCSnapshotRecordByRecordNumber",
    0x06: "reportDTCExtendedDataRecordByDTCNumber",
    0x07: "reportNumberOfDTCBySeverityMaskRecord",
    0x08: "reportDTCBySeverityMaskRecord",
    0x09: "reportSeverityInformationOfDTC",
    0x0A: "reportSupportedDTCs",
    0x0B: "reportFirstTestFailedDTC",
    0x0C: "reportFirstConfirmedDTC",
    0x0D: "reportMostRecentTestFailedDTC",
    0x0E: "reportMostRecentConfirmedDTC",
    0x0F: "reportMirrorMemoryDTCByStatusMask",
    0x55: "reportDTCInformationByDTCReadinessGroupIdentifier",
}


@dataclass
class DiagnosticPayloadDecode:
    raw_input: str
    normalized_input: HexString
    application_payload: HexString
    protocol: str
    response: str
    details: dict[str, Any] = field(default_factory=dict)
    records: list[dict[str, Any]] = field(default_factory=list)
    notes: list[str] = field(default_factory=list)
    warnings: list[str] = field(default_factory=list)
    source: str = ""


def clean_hex(value: object) -> HexString:
    return re.sub(r"[^0-9A-Fa-f]", "", str(value or "")).upper()


def status_bit_names(value: int, bit_names: tuple[tuple[int, str], ...]) -> list[str]:
    return [name for mask, name in bit_names if value & mask]


def generic_bit_names(value: int) -> list[str]:
    return [f"b{bit}" for bit in range(8) if value & (1 << bit)]


def sae_dtc_candidate(raw_24bit: HexString) -> str:
    raw = bytes.fromhex(raw_24bit)
    if len(raw) != 3:
        return ""
    system = ("P", "C", "B", "U")[raw[0] >> 6]
    first_digit = (raw[0] >> 4) & 0x03
    return f"{system}{first_digit:X}{raw[0] & 0x0F:X}{raw[1]:02X}:{raw[2]:02X}"


def strip_can_header_if_present(value: HexString) -> tuple[HexString, list[str]]:
    if len(value) % 2 == 0:
        return value, []
    if len(value) > 3 and len(value[3:]) % 2 == 0:
        return value[3:], [f"stripped 11-bit CAN header prefix {value[:3]}"]
    return value, []


def strip_tp20_application_frame(value: HexString) -> tuple[HexString, list[str]]:
    if len(value) < 6 or len(value) % 2:
        return value, []
    data = bytes.fromhex(value)
    if data[0] >> 4 != 1 or len(data) < 3:
        return value, []
    length = (data[1] << 8) | data[2]
    if 0 < length <= len(data) - 3:
        payload = data[3 : 3 + length].hex().upper()
        return payload, [f"stripped TP2.0 first-frame prefix length={length}"]
    return value, []


def normalize_application_payload(raw: str) -> tuple[HexString, HexString, list[str], list[str]]:
    normalized = clean_hex(raw)
    notes: list[str] = []
    warnings: list[str] = []
    if not normalized:
        warnings.append("empty input")
        return "", "", notes, warnings

    candidate, new_notes = strip_can_header_if_present(normalized)
    notes.extend(new_notes)
    if len(candidate) % 2:
        warnings.append("hex payload has an odd number of nibbles")
        return normalized, "", notes, warnings

    application_payload, new_notes = strip_tp20_application_frame(candidate)
    notes.extend(new_notes)
    return normalized, application_payload, notes, warnings


def decode_negative_response(raw: str, normalized: HexString, payload: HexString, notes: list[str], source: str) -> DiagnosticPayloadDecode:
    warnings: list[str] = []
    data = bytes.fromhex(payload)
    details: dict[str, Any] = {"service": "7F"}
    if len(data) >= 3:
        details.update(
            {
                "rejected_service": f"{data[1]:02X}",
                "response_code": f"{data[2]:02X}",
                "response_code_name": NEGATIVE_RESPONSE_CODES.get(data[2], "unknown"),
            }
        )
    else:
        warnings.append("negative response is shorter than 3 bytes")
    return DiagnosticPayloadDecode(
        raw_input=raw,
        normalized_input=normalized,
        application_payload=payload,
        protocol="diagnostic",
        response="negative_response",
        details=details,
        notes=notes,
        warnings=warnings,
        source=source,
    )


def decode_kwp_read_dtc_by_status(raw: str, normalized: HexString, payload: HexString, notes: list[str], source: str) -> DiagnosticPayloadDecode:
    data = bytes.fromhex(payload)
    warnings: list[str] = []
    details: dict[str, Any] = {"service": "58", "request_service": "18"}
    records: list[dict[str, Any]] = []
    if len(data) < 2:
        warnings.append("KWP positive DTC response is shorter than 2 bytes")
    else:
        reported_count = data[1]
        details["reported_count"] = reported_count
        expected_length = 2 + reported_count * 3
        if len(data) < expected_length:
            warnings.append(f"response is truncated: expected {expected_length} bytes for {reported_count} records, got {len(data)}")
        if len(data) > expected_length:
            warnings.append(f"response has {len(data) - expected_length} trailing byte(s) beyond reported count")
        for index in range(min(reported_count, max(0, (len(data) - 2) // 3))):
            offset = 2 + index * 3
            dtc_bytes = data[offset : offset + 2]
            status = data[offset + 2]
            dtc_hex = dtc_bytes.hex().upper()
            records.append(
                {
                    "index": index + 1,
                    "dtc_hex": dtc_hex,
                    "vag_decimal_candidate": f"{int(dtc_hex, 16):05d}",
                    "status": f"{status:02X}",
                    "status_bits_raw": generic_bit_names(status),
                    "note": "KWP/VAG status byte kept as raw bits; do not apply UDS status names here.",
                }
            )
    return DiagnosticPayloadDecode(
        raw_input=raw,
        normalized_input=normalized,
        application_payload=payload,
        protocol="KWP2000",
        response="read_dtc_by_status_positive",
        details=details,
        records=records,
        notes=notes,
        warnings=warnings,
        source=source,
    )


def decode_uds_read_dtc_information(raw: str, normalized: HexString, payload: HexString, notes: list[str], source: str) -> DiagnosticPayloadDecode:
    data = bytes.fromhex(payload)
    warnings: list[str] = []
    details: dict[str, Any] = {"service": "59", "request_service": "19"}
    records: list[dict[str, Any]] = []
    if len(data) < 2:
        warnings.append("UDS positive DTC response is shorter than 2 bytes")
    else:
        subfunction = data[1]
        details["subfunction"] = f"{subfunction:02X}"
        details["subfunction_name"] = UDS_READ_DTC_SUBFUNCTIONS.get(subfunction, "unknown")
        if subfunction == 0x02:
            if len(data) < 3:
                warnings.append("reportDTCByStatusMask response is missing DTC status availability mask")
            else:
                availability_mask = data[2]
                details["dtc_status_availability_mask"] = f"{availability_mask:02X}"
                details["available_status_bits"] = status_bit_names(availability_mask, UDS_DTC_STATUS_BITS)
                record_bytes = data[3:]
                complete_records = len(record_bytes) // 4
                truncated = len(record_bytes) % 4
                if truncated:
                    warnings.append(
                        "incomplete DTCAndStatusRecord: "
                        f"{record_bytes[complete_records * 4 :].hex().upper()} has {truncated} trailing byte(s)"
                    )
                for index in range(complete_records):
                    offset = 3 + index * 4
                    dtc_hex = data[offset : offset + 3].hex().upper()
                    status = data[offset + 3]
                    records.append(
                        {
                            "index": index + 1,
                            "dtc_raw_24bit": dtc_hex,
                            "sae_format_candidate": sae_dtc_candidate(dtc_hex),
                            "status": f"{status:02X}",
                            "status_bits": status_bit_names(status, UDS_DTC_STATUS_BITS),
                        }
                    )
        else:
            warnings.append("UDS ReadDTCInformation subfunction is not decoded by this utility yet")
    return DiagnosticPayloadDecode(
        raw_input=raw,
        normalized_input=normalized,
        application_payload=payload,
        protocol="UDS",
        response="read_dtc_information_positive",
        details=details,
        records=records,
        notes=notes,
        warnings=warnings,
        source=source,
    )


def decode_payload(raw: str, *, source: str = "") -> DiagnosticPayloadDecode:
    normalized, payload, notes, warnings = normalize_application_payload(raw)
    if not payload:
        return DiagnosticPayloadDecode(
            raw_input=raw,
            normalized_input=normalized,
            application_payload="",
            protocol="unknown",
            response="invalid_input",
            warnings=warnings,
            source=source,
        )
    if payload.startswith("7F"):
        decoded = decode_negative_response(raw, normalized, payload, notes, source)
    elif payload.startswith("58"):
        decoded = decode_kwp_read_dtc_by_status(raw, normalized, payload, notes, source)
    elif payload.startswith("59"):
        decoded = decode_uds_read_dtc_information(raw, normalized, payload, notes, source)
    else:
        decoded = DiagnosticPayloadDecode(
            raw_input=raw,
            normalized_input=normalized,
            application_payload=payload,
            protocol="unknown",
            response="unrecognized_payload",
            notes=notes,
            warnings=["payload is not a supported DTC/status response"],
            source=source,
        )
    decoded.warnings = warnings + decoded.warnings
    return decoded


def payload_candidates_from_text(text: str) -> Iterable[HexString]:
    seen: set[HexString] = set()
    for match in HEX_TOKEN_RE.finditer(text):
        token = match.group(0)
        _, payload, _, warnings = normalize_application_payload(token)
        if warnings or not payload.startswith(INTERESTING_RESPONSE_PREFIXES):
            continue
        if payload in seen:
            continue
        seen.add(payload)
        yield token


def collect_decodes(payloads: Iterable[str], files: Iterable[Path]) -> list[DiagnosticPayloadDecode]:
    decodes: list[DiagnosticPayloadDecode] = []
    seen_payloads: set[tuple[str, str]] = set()
    for payload in payloads:
        decoded = decode_payload(payload)
        decodes.append(decoded)
        if decoded.application_payload:
            seen_payloads.add(("", decoded.application_payload))

    for path in files:
        text = path.read_text(encoding="utf-8", errors="replace")
        for candidate in payload_candidates_from_text(text):
            decoded = decode_payload(candidate, source=str(path))
            key = (decoded.source, decoded.application_payload)
            if not decoded.application_payload or key in seen_payloads:
                continue
            seen_payloads.add(key)
            decodes.append(decoded)
    return decodes


def format_flags(flags: list[str]) -> str:
    return ", ".join(flags) if flags else "none"


def render_decode(decoded: DiagnosticPayloadDecode) -> str:
    lines = [f"{decoded.raw_input} -> {decoded.protocol} {decoded.response}"]
    if decoded.source:
        lines.append(f"  source: {decoded.source}")
    if decoded.application_payload != decoded.normalized_input:
        lines.append(f"  application_payload: {decoded.application_payload or '<empty>'}")
    for note in decoded.notes:
        lines.append(f"  note: {note}")
    for key, value in decoded.details.items():
        if isinstance(value, list):
            rendered = format_flags(value)
        else:
            rendered = str(value)
        lines.append(f"  {key}: {rendered}")
    for record in decoded.records:
        if decoded.protocol == "KWP2000":
            lines.append(
                "  record {index}: DTC {vag_decimal_candidate} (0x{dtc_hex}), "
                "status=0x{status}, raw_bits={bits}".format(
                    index=record["index"],
                    vag_decimal_candidate=record["vag_decimal_candidate"],
                    dtc_hex=record["dtc_hex"],
                    status=record["status"],
                    bits=format_flags(record["status_bits_raw"]),
                )
            )
        elif decoded.protocol == "UDS":
            lines.append(
                "  record {index}: DTC {dtc_raw_24bit} ({sae_format_candidate}), "
                "status=0x{status} [{bits}]".format(
                    index=record["index"],
                    dtc_raw_24bit=record["dtc_raw_24bit"],
                    sae_format_candidate=record["sae_format_candidate"],
                    status=record["status"],
                    bits=format_flags(record["status_bits"]),
                )
            )
    for warning in decoded.warnings:
        lines.append(f"  warning: {warning}")
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description="Decode saved KWP/UDS DTC/status response payloads without touching the car.")
    parser.add_argument("payload", nargs="*", help="Raw response payload, optionally with TP2.0 first-frame wrapper.")
    parser.add_argument("--from-file", action="append", type=Path, default=[], help="Extract DTC/status payloads from a saved txt/csv/json/md log.")
    parser.add_argument("--json", action="store_true", help="Emit structured JSON instead of text.")
    args = parser.parse_args()

    decodes = collect_decodes(args.payload, args.from_file)
    if args.json:
        print(json.dumps([asdict(decoded) for decoded in decodes], indent=2))
    else:
        if not decodes:
            print("No DTC/status payloads were supplied or found.")
        for index, decoded in enumerate(decodes):
            if index:
                print()
            print(render_decode(decoded))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
