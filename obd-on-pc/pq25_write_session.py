"""
pq25_write_session.py - consolidated PQ25 BCM coding write session runner.

Replaces: run_bcm_coding_session.py, run_drl_via_fogs_session.py,
          run_restore_expert_backup_session.ps1

All protocol framing and request building uses CaristaReproduction.
ELM327/TP2.0 transport is shared from _tp20_transport.py.

Phase 1 (always): read-only TP2.0 pass - 220600 + 220601 + 220606 + 22F1A5.
Phase 2 (--write): user-confirmed Carista-shaped UDS coding write.
Phase 3: post-write verify read 220600.

Write modes (choose one):
  1. --to-coding <hex>       Replace entire 30-byte coding
  2. --set-bit <name>        Set one or more known bits
  3. --clear-bit <name>      Clear one or more known bits
  4. --operation <name>      Predefined target coding (e.g. restore-expert-backup)

Usage:
    python obd-on-pc/pq25_write_session.py --operation restore-expert-backup
    python obd-on-pc/pq25_write_session.py --to-coding "<30-byte-hex>" --write
    python obd-on-pc/pq25_write_session.py --set-bit byte21-bit2 --clear-bit byte21-bit7 --write
    python obd-on-pc/pq25_write_session.py --operation restore-expert-backup --write
    python obd-on-pc/pq25_write_session.py --port COM10 --baud 38400 --operation restore-expert-backup --write
"""
from __future__ import annotations

import argparse
import json
import sys
import time
from dataclasses import asdict
from datetime import datetime
from pathlib import Path
from typing import Sequence

import serial

# CaristaReproduction is at the workspace root.
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from CaristaReproduction.Constants import CARISTA_WORKSHOP_CODE_WRITE_DID
from CaristaReproduction.Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from CaristaReproduction.Commands.WriteDataByIdentifierCommand import WriteDataByIdentifierCommand_processPayload
from CaristaReproduction.VagCoding import (
    apply_cornering_fixes,
    bit_state,
    changed_coding_bytes,
    clear_coding_bit,
    normalize_coding,
    set_coding_bit,
)
from CaristaReproduction.VagOperationDelegate import (
    VagOperationDelegate_writeDataByIdentifierResultIsFatalFail,
    build_carista_uds_coding_write_plan,
)

# Shared ELM327/TP2.0 transport
sys.path.insert(0, str(Path(__file__).resolve().parent))
from _tp20_transport import (
    elm_send,
    init_elm,
    read_did_one_shot,
    tp20_close,
    tp20_open,
    tp20_request,
)


READ_DID_LONG_CODING = 0x0600
READ_DID_0601 = 0x0601
READ_DID_0606 = 0x0606
READ_DID_WORKSHOP_CODE = 0xF1A5
EXPERT_BACKUP_CODING = "3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000"
EXPERT_BACKUP_NO_TURN_SIGNAL_FOGS_CODING = "3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000"
OPERATION_RESTORE_EXPERT_BACKUP = "restore-expert-backup"
OPERATION_RESTORE_EXPERT_BACKUP_NO_TURN_SIGNAL_FOGS = "restore-expert-backup-no-turn-signal-fogs"
OPERATION_CLEAR_BYTE12_BIT0 = "clear-byte12-bit0"
OPERATION_DRL_VIA_FOGS = "drl-via-fogs"
KNOWN_BIT_TARGETS = {
    "byte12-bit0": (12, 0, "byte 12 bit 0 Nordic/Standlicht"),
    "byte12-bit6": (12, 6, "byte 12 bit 6 base cornering via fogs"),
    "byte21-bit2": (21, 2, "byte 21 bit 2 turn-signal cornering assist"),
    "byte21-bit5": (21, 5, "byte 21 bit 5 turn off fogs with high beam"),
    "byte21-bit7": (21, 7, "byte 21 bit 7 cornering/fog experimental"),
    "byte23-bit2": (23, 2, "byte 23 bit 2 DRL via fogs"),
    "drl-via-fogs": (23, 2, "byte 23 bit 2 DRL via fogs"),
}


# ---------------------------------------------------------------------------
# Target derivation helpers
# ---------------------------------------------------------------------------

def _unique_bit_keys(bit_keys: Sequence[str]) -> tuple[str, ...]:
    return tuple(dict.fromkeys(bit_keys))


def _bit_identity(bit_key: str) -> tuple[int, int]:
    byte_index, bit_index, _description = KNOWN_BIT_TARGETS[bit_key]
    return byte_index, bit_index


def _bit_change_labels(set_bits: Sequence[str], clear_bits: Sequence[str]) -> list[str]:
    labels = []
    for key in _unique_bit_keys(set_bits):
        labels.append(f"set {KNOWN_BIT_TARGETS[key][2]}")
    for key in _unique_bit_keys(clear_bits):
        labels.append(f"clear {KNOWN_BIT_TARGETS[key][2]}")
    return labels


def _validate_bit_changes(set_bits: Sequence[str], clear_bits: Sequence[str]) -> None:
    set_identities = {_bit_identity(key): key for key in _unique_bit_keys(set_bits)}
    clear_identities = {_bit_identity(key): key for key in _unique_bit_keys(clear_bits)}
    conflicts = sorted(set(set_identities) & set(clear_identities))
    if conflicts:
        details = ", ".join(
            f"{set_identities[identity]} / {clear_identities[identity]} (byte {identity[0]} bit {identity[1]})"
            for identity in conflicts
        )
        raise ValueError(f"cannot set and clear the same bit in one target: {details}")


def _apply_selected_bits(current_coding: str, set_bits: Sequence[str], clear_bits: Sequence[str]) -> str:
    target = normalize_coding(current_coding)
    for key in _unique_bit_keys(set_bits):
        byte_index, bit_index, _description = KNOWN_BIT_TARGETS[key]
        target = set_coding_bit(target, byte_index, bit_index)
    for key in _unique_bit_keys(clear_bits):
        byte_index, bit_index, _description = KNOWN_BIT_TARGETS[key]
        target = clear_coding_bit(target, byte_index, bit_index)
    return target


def _bit_changes_run_id(set_bits: Sequence[str], clear_bits: Sequence[str]) -> str:
    parts = []
    parts.extend(f"set_{key.replace('-', '_')}" for key in _unique_bit_keys(set_bits))
    parts.extend(f"clear_{key.replace('-', '_')}" for key in _unique_bit_keys(clear_bits))
    return "_".join(parts)


def _derive_target_coding(
    current_coding: str,
    operation: str | None,
    set_bits: Sequence[str],
    clear_bits: Sequence[str],
    to_coding: str | None,
) -> str:
    """Derive the target coding from the current coding using the selected write mode."""
    if to_coding is not None:
        return normalize_coding(to_coding)
    if set_bits or clear_bits:
        return _apply_selected_bits(current_coding, set_bits, clear_bits)
    if operation == OPERATION_RESTORE_EXPERT_BACKUP:
        return EXPERT_BACKUP_CODING
    if operation == OPERATION_RESTORE_EXPERT_BACKUP_NO_TURN_SIGNAL_FOGS:
        return EXPERT_BACKUP_NO_TURN_SIGNAL_FOGS_CODING
    if operation == OPERATION_CLEAR_BYTE12_BIT0:
        return _apply_selected_bits(current_coding, (), ("byte12-bit0",))
    if operation == OPERATION_DRL_VIA_FOGS:
        return apply_cornering_fixes(current_coding, ("drl-via-fogs",))
    raise ValueError(f"unsupported target configuration: operation={operation}, to_coding={to_coding}, bits={set_bits}/{clear_bits}")


def _operation_label(operation: str | None, set_bits: Sequence[str] = (), clear_bits: Sequence[str] = ()) -> str:
    if set_bits or clear_bits:
        return ", ".join(_bit_change_labels(set_bits, clear_bits))
    if operation == OPERATION_RESTORE_EXPERT_BACKUP:
        return "restore expert coding backup"
    if operation == OPERATION_RESTORE_EXPERT_BACKUP_NO_TURN_SIGNAL_FOGS:
        return "restore expert backup and clear turn-signal fog trigger"
    if operation == OPERATION_CLEAR_BYTE12_BIT0:
        return "clear byte 12 bit 0 Nordic/Standlicht bit only"
    if operation == OPERATION_DRL_VIA_FOGS:
        return "write drl_via_fogs = YES"
    if operation:
        return operation
    return "full coding replace"


# ---------------------------------------------------------------------------
# Session phases
# ---------------------------------------------------------------------------

def _run_read_phase(ser: serial.Serial) -> tuple[str, str] | None:
    """
    Phase 1: read 220600, 220601, 220606, and 22F1A5, print cornering bit state.
    Returns (current_coding_hex, workshop_code_payload) or None on failure.
    """
    print("\n=== Phase 1: read-only baseline ===")

    payload_0600 = read_did_one_shot(ser, READ_DID_LONG_CODING)
    if not payload_0600 or not payload_0600.upper().startswith("620600"):
        print(f"  ERROR: unexpected 220600 response: {payload_0600!r}")
        return None
    current_coding = normalize_coding(payload_0600)
    if len(current_coding) != 60:
        print(f"  ERROR: incomplete 220600 coding: {len(current_coding) // 2} bytes, expected 30")
        return None

    b12_b0 = bit_state(current_coding, 12, 0)
    b12 = bit_state(current_coding, 12, 6)
    b21_b7 = bit_state(current_coding, 21, 7)
    b21_b2 = bit_state(current_coding, 21, 2)
    b21_b5 = bit_state(current_coding, 21, 5)
    b23_b2 = bit_state(current_coding, 23, 2)

    print(f"\n  DID 0600 coding: {current_coding}")
    print(f"  byte 12 bit 0  nordic_standlicht:            {b12_b0}")
    print(f"  byte 12 bit 6  cornering_fogs:               {b12}")
    print(f"  byte 21 bit 7  cornering_fogs_experimental:  {b21_b7}")
    print(f"  byte 21 bit 2  cornering_turn_signals:       {b21_b2}")
    print(f"  byte 21 bit 5  turn_off_fogs_high_beam:      {b21_b5}")
    print(f"  byte 23 bit 2  drl_via_fogs:                 {b23_b2}")

    for did in (READ_DID_0601, READ_DID_0606):
        request = ReadDataByIdentifierCommand_getRequest(did)
        payload = read_did_one_shot(ser, did)
        expected_prefix = f"62{did:04X}"
        if not payload or not payload.upper().startswith(expected_prefix):
            print(f"  ERROR: unexpected {request} response: {payload!r}")
            return None
        print(f"  {request} -> {payload}")

    request_f1a5 = ReadDataByIdentifierCommand_getRequest(READ_DID_WORKSHOP_CODE)
    payload_f1a5 = read_did_one_shot(ser, READ_DID_WORKSHOP_CODE)
    if not payload_f1a5 or not payload_f1a5.upper().startswith("62F1A5"):
        print(f"  ERROR: unexpected 22F1A5 response: {payload_f1a5!r}")
        return None
    workshop_code_payload = payload_f1a5.upper()[6:]
    print(f"  22F1A5 workshop code payload: {workshop_code_payload}")

    return current_coding, workshop_code_payload


def _run_write_phase(
    ser: serial.Serial,
    t3_ms: int | None,
    current_coding: str,
    workshop_code_payload: str,
    *,
    log_dir: Path,
    operation: str | None,
    set_bits: Sequence[str] = (),
    clear_bits: Sequence[str] = (),
    to_coding: str | None = None,
    run_id: str,
) -> bool:
    """
    Phase 2: build target using CaristaReproduction-supported coding helpers, execute write sequence.
    Returns True on verified success.
    """
    label = _operation_label(operation, set_bits, clear_bits)
    print(f"\n=== Phase 2: {label} ===")

    target_coding, write_plan = _prepare_write_plan(
        current_coding,
        workshop_code_payload,
        log_dir=log_dir,
        operation=operation,
        set_bits=set_bits,
        clear_bits=clear_bits,
        to_coding=to_coding,
        run_id=run_id,
    )
    if write_plan is None:
        return True

    confirm = input("\n  Proceed with write? Type YES to confirm: ").strip()
    if confirm != "YES":
        print("  Write aborted by user")
        return False

    tp20_close(ser)
    time.sleep(0.5)
    _, t3_ms = tp20_open(ser)

    counter = 0
    for req in write_plan.requests:
        payload, counter = tp20_request(ser, counter, req.request, t3_ms, label=req.label)

        if payload is None:
            payload = ""
        result = WriteDataByIdentifierCommand_processPayload(payload)
        is_fatal = VagOperationDelegate_writeDataByIdentifierResultIsFatalFail(req.did, payload)
        if is_fatal or (req.did == CARISTA_WORKSHOP_CODE_WRITE_DID and result.isFail()):
            print(f"  FATAL ERROR on {req.label}: payload={payload!r}")
            return False
        if result.isFail():
            print(f"  {req.label}: non-fatal Carista result state={result.state} payload={payload!r}")
        else:
            print(f"  {req.label}: OK (payload={payload!r})")

        time.sleep(0.3)

    return True


def _prepare_write_plan(
    current_coding: str,
    workshop_code_payload: str,
    *,
    log_dir: Path,
    operation: str | None,
    set_bits: Sequence[str] = (),
    clear_bits: Sequence[str] = (),
    to_coding: str | None = None,
    run_id: str,
):
    """Derive, print, and save the Carista-shaped coding write plan."""
    target_coding = _derive_target_coding(current_coding, operation, set_bits, clear_bits, to_coding)
    if normalize_coding(current_coding) == normalize_coding(target_coding):
        print("  current coding already matches target - no write needed")
        return target_coding, None

    print(f"  current: {current_coding}")
    print(f"  target:  {target_coding}")
    print("  changed bytes:")
    for byte_index, (old, new) in changed_coding_bytes(current_coding, target_coding).items():
        print(f"    byte {byte_index:02d}: {old} -> {new}")

    write_plan = build_carista_uds_coding_write_plan(
        current_coding,
        target_coding,
        workshop_code_payload=workshop_code_payload,
    )

    print("\n  Recovered Carista UDS request sequence:")
    for req in write_plan.requests:
        print(f"    {req.label}: {req.request}")

    plan_path = log_dir / f"{run_id}_write_plan.json"
    plan_path.write_text(json.dumps(asdict(write_plan), indent=2) + "\n", encoding="utf-8")
    print(f"\n  Write plan saved: {plan_path}")

    return target_coding, write_plan


def _run_verify_phase(ser: serial.Serial, t3_ms: int | None, expected_target: str) -> bool:
    """Phase 3: read 220600 and verify it matches the requested target."""
    print("\n=== Phase 3: verification read ===")
    counter = 0
    request_0600 = ReadDataByIdentifierCommand_getRequest(READ_DID_LONG_CODING)
    payload, _ = tp20_request(ser, counter, request_0600, t3_ms, label=f"verify {request_0600}")
    if not payload or not payload.upper().startswith("620600"):
        print(f"  ERROR: verify read failed: {payload!r}")
        return False
    verified_coding = normalize_coding(payload)
    b12_b0 = bit_state(verified_coding, 12, 0)
    b12_b6 = bit_state(verified_coding, 12, 6)
    b21_b7 = bit_state(verified_coding, 21, 7)
    b21_b2 = bit_state(verified_coding, 21, 2)
    b21_b5 = bit_state(verified_coding, 21, 5)
    b23_b2 = bit_state(verified_coding, 23, 2)
    print(f"  verified coding: {verified_coding}")
    print(f"  byte 12 bit 0 nordic_standlicht:            {b12_b0}")
    print(f"  byte 12 bit 6 cornering_fogs:               {b12_b6}")
    print(f"  byte 21 bit 7 cornering_fogs_experimental:  {b21_b7}")
    print(f"  byte 21 bit 2 cornering_turn_signals:       {b21_b2}")
    print(f"  byte 21 bit 5 turn_off_fogs_high_beam:      {b21_b5}")
    print(f"  byte 23 bit 2 drl_via_fogs:                 {b23_b2}")
    match = verified_coding.upper() == expected_target.upper()
    print(f"  coding matches target: {match}")
    return match


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def _parse_args(argv: Sequence[str] | None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="PQ25 BCM coding write session - uses CaristaReproduction for all protocol logic.",
    )
    parser.add_argument("--port", default="COM10", help="ELM327 serial port (default: COM10)")
    parser.add_argument("--baud", type=int, default=38400, help="Serial baud rate (default: 38400)")
    parser.add_argument("--write", action="store_true", help="Enable Phase 2 write after user confirmation")
    parser.add_argument(
        "--to-coding",
        type=str,
        default=None,
        help="Explicit 30-byte target coding hex (overrides --operation and --set-bit/--clear-bit)",
    )
    parser.add_argument(
        "--operation",
        choices=(
            OPERATION_RESTORE_EXPERT_BACKUP,
            OPERATION_RESTORE_EXPERT_BACKUP_NO_TURN_SIGNAL_FOGS,
            OPERATION_CLEAR_BYTE12_BIT0,
            OPERATION_DRL_VIA_FOGS,
        ),
        default=None,
        help="Target coding operation to prepare or write",
    )
    parser.add_argument(
        "--clear-bit",
        action="append",
        choices=tuple(KNOWN_BIT_TARGETS),
        default=None,
        help="Clear one known current-coding bit; can be repeated for a combined guarded target",
    )
    parser.add_argument(
        "--set-bit",
        action="append",
        choices=tuple(KNOWN_BIT_TARGETS),
        default=None,
        help="Set one known current-coding bit; can be repeated for a combined guarded target",
    )
    parser.add_argument("--log-dir", type=Path, default=Path(__file__).parent / "logs", help="Log output directory")
    args = parser.parse_args(argv)

    specified_modes = sum([
        1 if args.to_coding else 0,
        1 if args.operation else 0,
        1 if (args.set_bit or args.clear_bit) else 0,
    ])
    if specified_modes > 1:
        parser.error("only one of --to-coding, --operation, or --set-bit/--clear-bit may be specified")
    if specified_modes == 0:
        parser.error("specify one of --to-coding, --operation, or --set-bit/--clear-bit")

    return args


def main(argv: Sequence[str] | None = None) -> int:
    args = _parse_args(argv)
    operation = args.operation
    set_bits = _unique_bit_keys(args.set_bit or ())
    clear_bits = _unique_bit_keys(args.clear_bit or ())
    if args.set_bit or args.clear_bit:
        try:
            _validate_bit_changes(set_bits, clear_bits)
        except ValueError as exc:
            print(f"ERROR: {exc}")
            return 1

    ts = datetime.now().strftime("%Y%m%d_%H%M%S")
    if args.to_coding:
        run_id_base = "to_coding"
    elif set_bits or clear_bits:
        run_id_base = _bit_changes_run_id(set_bits, clear_bits)
    else:
        run_id_base = (operation or "unknown").replace("-", "_")
    run_id = f"{run_id_base}_{ts}"
    args.log_dir.mkdir(parents=True, exist_ok=True)

    write_method = args.to_coding or _operation_label(operation, set_bits, clear_bits)
    print(f"PQ25 write session  run_id={run_id}")
    print(f"target: {write_method}")
    if set_bits:
        print(f"set_bits: {', '.join(set_bits)}")
    if clear_bits:
        print(f"clear_bits: {', '.join(clear_bits)}")
    print(f"port={args.port}  baud={args.baud}  write={'YES' if args.write else 'NO'}")
    print(f"Blocked services (safety): 27 31 3B; 2E only if --write confirmed")
    print()

    with serial.Serial(args.port, args.baud, timeout=0.1) as ser:
        init_elm(ser)

        result = _run_read_phase(ser)
        if result is None:
            print("Phase 1 failed - aborting")
            return 1
        current_coding, workshop_code_payload = result

        if not args.write:
            print("\n=== Dry-run write plan ===")
            target_coding, write_plan = _prepare_write_plan(
                current_coding,
                workshop_code_payload,
                log_dir=args.log_dir,
                operation=operation,
                set_bits=set_bits,
                clear_bits=clear_bits,
                to_coding=args.to_coding,
                run_id=run_id,
            )
            print(f"\nRead-only pass complete. Target: {target_coding}")
            if write_plan is not None:
                print("Use --write to proceed with Phase 2.")
            return 0

        target_coding = _derive_target_coding(current_coding, operation, set_bits, clear_bits, args.to_coding)
        time.sleep(0.5)
        _, t3_ms = tp20_open(ser)
        ok = _run_write_phase(
            ser, t3_ms, current_coding, workshop_code_payload,
            log_dir=args.log_dir, operation=operation,
            set_bits=set_bits, clear_bits=clear_bits,
            to_coding=args.to_coding, run_id=run_id,
        )
        if not ok:
            tp20_close(ser)
            return 1

        time.sleep(0.5)
        tp20_close(ser)
        time.sleep(0.3)
        _, t3_ms = tp20_open(ser)
        verified = _run_verify_phase(ser, t3_ms, target_coding)
        tp20_close(ser)

        if verified:
            print("\nSUCCESS: target coding written and verified.")
        else:
            print("\nWARNING: verification read did not match target coding")
            return 1

    print(f"\nWrite-plan log directory: {args.log_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
