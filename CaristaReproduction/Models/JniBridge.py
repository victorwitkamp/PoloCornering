from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class JniBridgeFunction:
    java_class: str
    java_method: str
    descriptor: str
    access_flags: str
    native_symbol: str
    elf_address: str
    ghidra_address: str
    export_file: str
    required_evidence: tuple[str, ...]
    recovered_behavior: tuple[str, ...]


@dataclass(frozen=True)
class ReadValuesVtableSlot:
    java_method: str
    slot_offset: str
    export_file: str
    dispatch_expression: str
    proven_input: str
    proven_output: str
    unresolved_target: str


@dataclass(frozen=True)
class JniExportValidation:
    label: str
    export_file: str
    status: str
    matched_evidence: tuple[str, ...]
    missing_evidence: tuple[str, ...]


@dataclass(frozen=True)
class JniBridgeSummary:
    functions: tuple[JniBridgeFunction, ...]
    read_values_slots: tuple[ReadValuesVtableSlot, ...]
    validations: tuple[JniExportValidation, ...]
