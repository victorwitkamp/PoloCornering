from __future__ import annotations

from ..ByteUtils import clean_hex
from ..Types import HexString


def _validate_byte(value: int, label: str) -> int:
    if not 0 <= value <= 0xFF:
        raise ValueError(f"{label} must fit in one byte")
    return value


def _normalize_dtc_24bit(dtc: HexString | int) -> HexString:
    if isinstance(dtc, int):
        if not 0 <= dtc <= 0xFFFFFF:
            raise ValueError("DTC must fit in three bytes")
        return f"{dtc:06X}"
    normalized = clean_hex(dtc, "DTC")
    if len(normalized) != 6:
        raise ValueError(f"DTC must be exactly three bytes: {dtc!r}")
    return normalized


def GetVagCanTroubleCodesCommand_getRequest(status_mask: int = 0xFF, group: int = 0x00) -> HexString:
    """Candidate Carista VAG CAN/KWP DTC request seen live as 1802FF00."""

    status_mask = _validate_byte(status_mask, "status_mask")
    group = _validate_byte(group, "group")
    return f"1802{status_mask:02X}{group:02X}"


def GetVagUdsTroubleCodesCommand_getRequest(status_mask: int = 0xFF) -> HexString:
    """Candidate Carista UDS ReadDTCInformation request seen live as 1902FF."""

    status_mask = _validate_byte(status_mask, "status_mask")
    return f"1902{status_mask:02X}"


def ReadVagUdsExtRecordByDtcCommand_getRequest(dtc: HexString | int, record_number: int = 0xFF) -> HexString:
    """Candidate UDS extended-data read used by Carista freeze-frame/detail flow."""

    record_number = _validate_byte(record_number, "record_number")
    return f"1906{_normalize_dtc_24bit(dtc)}{record_number:02X}"


def ReadVagUdsSnapshotRecordByDtcCommand_getRequest(dtc: HexString | int, record_number: int = 0xFF) -> HexString:
    """Candidate UDS snapshot-record read adjacent to Carista freeze-frame/detail flow."""

    record_number = _validate_byte(record_number, "record_number")
    return f"1904{_normalize_dtc_24bit(dtc)}{record_number:02X}"
