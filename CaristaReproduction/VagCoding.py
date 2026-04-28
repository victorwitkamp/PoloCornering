from __future__ import annotations

from pathlib import Path

from .ByteUtils import clean_hex
from .Constants import CORNERING_FIXES
from .JsonUtils import json_objects_from_text
from .Models.DerivedValue import DerivedValue
from .Types import BitAction, BitState, CorneringFixKey, HexString


def normalize_coding(value: str) -> HexString:
    cleaned = clean_hex(value, "coding")
    for prefix in ("620600", "5A9A"):
        if cleaned.startswith(prefix):
            cleaned = cleaned[len(prefix):]
            break
    if not cleaned:
        raise ValueError("coding is empty")
    return cleaned


def read_coding(coding: str | None, coding_file: str | None) -> HexString | None:
    if coding_file:
        path = Path(coding_file)
        text = path.read_text(encoding="utf-8")
        if path.suffix.lower() == ".json":
            for entry in json_objects_from_text(text):
                read_result = entry.get("read_result")
                if not isinstance(read_result, str):
                    continue
                candidate = clean_hex(read_result, "read_result")
                if candidate.startswith(("620600", "5A9A")):
                    return normalize_coding(candidate)
            raise ValueError(f"no 620600 or 5A9A read_result found in {coding_file}")
        return normalize_coding(text)
    if coding:
        return normalize_coding(coding)
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


def ReadVagCanLongCodingCommand_processLongCoding(response: HexString) -> HexString | None:
    cleaned = clean_hex(response, "long-coding response")
    if cleaned.startswith(("5A9A", "620600")):
        return normalize_coding(cleaned)
    return None


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