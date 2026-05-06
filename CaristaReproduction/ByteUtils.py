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


def ByteUtils_getLong(value: HexString) -> int:
    raw = bytes.fromhex(clean_hex(value, "ByteUtils long value"))
    if len(raw) > 8:
        raise ValueError("A long can fit a max of 8 bytes")
    return int.from_bytes(raw, "big")


def ByteUtils_getBytesFromLong(value: int) -> HexString:
    if not 0 <= value <= 0xFFFFFFFFFFFFFFFF:
        raise ValueError("ByteUtils long value must fit in 8 bytes")
    return value.to_bytes(8, "big").hex().upper()


def ByteUtils_getLsbOffset(mask: HexString) -> int:
    mask_value = ByteUtils_getLong(mask)
    if mask_value == 0:
        return 0
    return (mask_value & -mask_value).bit_length() - 1


def ByteUtils_extractValue(current_raw_value: HexString, offset: int, mask: HexString) -> HexString:
    current = bytes.fromhex(clean_hex(current_raw_value, "current raw value"))
    mask_bytes = bytes.fromhex(clean_hex(mask, "mask"))
    if offset < 0:
        raise ValueError("offset must be non-negative")
    if offset + len(mask_bytes) > len(current):
        raise ValueError("masked extract would extend past the current raw value")

    if len(mask_bytes) < 9:
        segment = current[offset : offset + len(mask_bytes)]
        masked = bytes(segment_byte & mask_byte for segment_byte, mask_byte in zip(segment, mask_bytes))
        shifted = ByteUtils_getLong(masked.hex()) >> ByteUtils_getLsbOffset(mask)
        return ByteUtils_getBytesFromLong(shifted)[-len(mask_bytes) * 2 :]

    return current[offset : offset + len(mask_bytes)].hex().upper()


def ByteUtils_insertValue(current_raw_value: HexString, offset: int, mask: HexString, requested_value: HexString) -> HexString:
    current = bytearray.fromhex(clean_hex(current_raw_value, "current raw value"))
    mask_bytes = bytes.fromhex(clean_hex(mask, "mask"))
    requested = bytes.fromhex(clean_hex(requested_value, "requested value"))
    if offset < 0:
        raise ValueError("offset must be non-negative")
    if offset + len(mask_bytes) > len(current):
        raise ValueError("masked insert would extend past the current raw value")

    if len(requested) < 9:
        shifted = ByteUtils_getLong(requested.hex()) << ByteUtils_getLsbOffset(mask)
        requested = bytes.fromhex(ByteUtils_getBytesFromLong(shifted))[-len(mask_bytes) :]
    elif len(requested) < len(mask_bytes):
        raise ValueError("requested value must cover the mask length for direct inserts")

    for index, mask_byte in enumerate(mask_bytes):
        current_index = offset + index
        current[current_index] = (current[current_index] & ~mask_byte) | requested[index]
    return current.hex().upper()


class ByteUtils:
    normalizeHex = staticmethod(normalize_hex)
    cleanHex = staticmethod(clean_hex)
    requireLen = staticmethod(require_len)
    getAsciiString = staticmethod(ascii_from_hex)
    getLong = staticmethod(ByteUtils_getLong)
    getBytesFromLong = staticmethod(ByteUtils_getBytesFromLong)
    getLsbOffset = staticmethod(ByteUtils_getLsbOffset)
    extractValue = staticmethod(ByteUtils_extractValue)
    insertValue = staticmethod(ByteUtils_insertValue)
