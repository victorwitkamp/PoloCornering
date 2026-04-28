from __future__ import annotations

import re

from .Constants import HEX_RE
from .Types import HexString


def normalize_hex(value: str) -> HexString:
    return re.sub(r"[^0-9A-Fa-f]", "", value).upper()


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
    raw_bytes = bytes.fromhex(cleaned)
    return "".join(chr(byte) if 32 <= byte <= 126 else "." for byte in raw_bytes)


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


class ByteUtils:
    normalizeHex = staticmethod(normalize_hex)
    cleanHex = staticmethod(clean_hex)
    requireLen = staticmethod(require_len)
    getAsciiString = staticmethod(ascii_from_hex)
    insertValue = staticmethod(ByteUtils_insertValue)