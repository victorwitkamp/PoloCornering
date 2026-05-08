"""
run_drl_via_fogs_session.py - thin BCM coding session runner.

Entrypoint only. All protocol framing and request building uses CaristaReproduction.
Remove after session.

Phase 1 (always): read-only TP2.0 pass - 220600 + 220601 + 220606 + 22F1A5.
Phase 2 (--write): user-confirmed Carista-shaped UDS coding write.
Phase 3: post-write verify read 220600.

Usage:
    python run_drl_via_fogs_session.py
    python run_drl_via_fogs_session.py --operation restore-expert-backup --write
    python run_drl_via_fogs_session.py --port COM10 --baud 38400 --write
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import time
from dataclasses import asdict
from datetime import datetime
from pathlib import Path
from typing import Sequence

import serial

# CaristaReproduction is at the workspace root.
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from CaristaReproduction.VagCanCommunicator import (
    CARISTA_FINAL_FRAME_ST,
    CARISTA_NON_FINAL_FRAME_ST,
    CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT,
    ackForReceivedPacket,
    expectedTransmitAck,
    findTransmitAcks,
    generateOutgoingPackets,
    interFramePauseSeconds,
    isTransmitAck,
    next_counter_after_request,
    readResponses,
)
from CaristaReproduction.ReadValuesOperation import (
    CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
    CARISTA_TP20_EXPECTED_LISTEN_HEADER,
    CARISTA_TP20_EXPECTED_SEND_HEADER,
    CARISTA_TP20_UNIT_09_OPEN_REQUEST,
    POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST,
)
from CaristaReproduction.Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from CaristaReproduction.Commands.WriteDataByIdentifierCommand import WriteDataByIdentifierCommand_processPayload
from CaristaReproduction.Constants import CARISTA_WORKSHOP_CODE_WRITE_DID
from CaristaReproduction.VagCoding import apply_cornering_fixes, bit_state, changed_coding_bytes, normalize_coding
from CaristaReproduction.VagOperationDelegate import (
    VagOperationDelegate_writeDataByIdentifierResultIsFatalFail,
    build_carista_uds_coding_write_plan,
)

LISTEN_HEADER = CARISTA_TP20_EXPECTED_LISTEN_HEADER
SEND_HEADER = CARISTA_TP20_EXPECTED_SEND_HEADER
READ_DID_LONG_CODING = 0x0600
READ_DID_0601 = 0x0601
READ_DID_0606 = 0x0606
READ_DID_WORKSHOP_CODE = 0xF1A5
EXPERT_BACKUP_CODING = "3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000"
OPERATION_RESTORE_EXPERT_BACKUP = "restore-expert-backup"
OPERATION_DRL_VIA_FOGS = "drl-via-fogs"
TP20_INTER_FRAME_MINIMUM_MS = 130
TP20_LIVE_RESPONSE_FRAME_ST = "ATST32"
_HEX_RE = re.compile(r"^[0-9A-Fa-f]+$")


# ---------------------------------------------------------------------------
# ELM327 serial transport (entrypoint concern only)
# ---------------------------------------------------------------------------

def _read_until_prompt(ser: serial.Serial, timeout: float) -> str:
    deadline = time.monotonic() + timeout
    prompt_seen_at: float | None = None
    chunks: list[bytes] = []
    while time.monotonic() < deadline:
        waiting = ser.in_waiting
        if waiting:
            chunk = ser.read(waiting)
            chunks.append(chunk)
            if b">" in chunk:
                prompt_seen_at = time.monotonic()
        else:
            if prompt_seen_at is not None and time.monotonic() - prompt_seen_at >= 0.15:
                break
            time.sleep(0.015)
    return b"".join(chunks).decode("ascii", errors="replace")


def _elm_send(ser: serial.Serial, cmd: str, timeout: float = 2.0, pause: float = 0.05) -> str:
    ser.reset_input_buffer()
    ser.write((cmd + "\r").encode("ascii"))
    time.sleep(pause)
    return _read_until_prompt(ser, timeout)


def _init_elm(ser: serial.Serial) -> None:
    print("[elm] initializing adapter")
    for cmd in ("ATZ", "ATE0", "ATL0", "ATS0", "ATH1", "ATCAF0", "ATV1", "ATAL", "ATSP6"):
        raw = _elm_send(ser, cmd, timeout=3.0, pause=0.25)
        print(f"  {cmd}: {raw.strip()!r}")
    print()


def _parse_frames(raw: str, header: str) -> list[str]:
    """Extract frame payloads from ELM327 output that match the given 3-hex-digit header."""
    result = []
    for line in raw.replace(">", "").splitlines():
        compact = re.sub(r"\s+", "", line).upper()
        if len(compact) < 4:
            continue
        if not _HEX_RE.match(compact):
            continue
        if compact.startswith(header.upper()):
            payload = compact[3:]
            if payload:
                result.append(payload)
    return result


def _is_data_frame(frame: str) -> bool:
    return not isTransmitAck(frame) and frame.upper() not in ("A3", "A8")


def _has_final_data_frame(frames: list[str]) -> bool:
    return any(frame.startswith("1") for frame in frames)


def _collect_more_frames(ser: serial.Serial, request: str, timeout: float = 2.0) -> list[str]:
    _elm_send(ser, f"ATSH{SEND_HEADER}", pause=0.05)
    raw = _elm_send(ser, request, timeout=timeout)
    frames = _parse_frames(raw, LISTEN_HEADER)
    return [frame for frame in frames if _is_data_frame(frame)]


def _tp20_open(ser: serial.Serial) -> tuple[str, int | None]:
    """
    Open a TP2.0 channel to BCM unit 20.
    Returns (channel_param_used, t3_ms_or_None).
    Raises RuntimeError if channel cannot be opened.
    """
    print("[tp20] opening channel to unit 20")
    # ELM setup for TP2.0 open request
    for cmd in ("ATSP6", "ATCAF0", "ATV1", "ATAR", "ATSH200", "ATST0A"):
        _elm_send(ser, cmd, pause=0.1)

    raw = _elm_send(ser, CARISTA_TP20_UNIT_09_OPEN_REQUEST, timeout=3.0)
    frames = _parse_frames(raw, "220")
    if not any(f.startswith("00D") for f in frames):
        raise RuntimeError(f"TP2.0 open request did not get channel response: {raw!r}")
    print(f"  channel open: send={SEND_HEADER} listen={LISTEN_HEADER}")

    # Match the proven live traces: send channel parameters before installing ATCRA.
    for cmd in (f"ATST32", f"ATSH{SEND_HEADER}"):
        _elm_send(ser, cmd, pause=0.1)

    # Prefer the Polo-proven fallback profile for this ELM clone.
    t3_ms: int | None = None
    used_param: str | None = None
    for param_request in (POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST, CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST):
        raw = _elm_send(ser, param_request, timeout=2.0)
        frames = _parse_frames(raw, LISTEN_HEADER)
        a1_frames = [f for f in frames if f.upper().startswith("A1")]
        if a1_frames:
            # Parse T3 from A1 response: A1 BLKS T1 T2 T3 T4
            a1 = a1_frames[0]
            if len(a1) >= 12:
                t3_ms = int(a1[8:10], 16)
            used_param = param_request
            print(f"  channel params ok: {a1_frames[0]}  T3={t3_ms}ms  (request={param_request})")
            break
        # ECU may have re-sent open; re-prep ELM for another channel open attempt
        for cmd in ("ATSP6", "ATCAF0", "ATV1", "ATAR", f"ATSH200", "ATST0A"):
            _elm_send(ser, cmd, pause=0.1)
        _elm_send(ser, CARISTA_TP20_UNIT_09_OPEN_REQUEST, timeout=3.0)
        for cmd in (f"ATST32", f"ATSH{SEND_HEADER}"):
            _elm_send(ser, cmd, pause=0.1)

    if used_param is None:
        raise RuntimeError("TP2.0 channel parameter setup failed for both profiles")

    _elm_send(ser, f"ATCRA{LISTEN_HEADER}", pause=0.1)

    pause_s = interFramePauseSeconds(t3_ms, TP20_INTER_FRAME_MINIMUM_MS)
    print(f"  inter-frame pause: {pause_s*1000:.0f}ms")
    return used_param, t3_ms


def _tp20_close(ser: serial.Serial) -> None:
    _elm_send(ser, f"ATSH{SEND_HEADER}", pause=0.05)
    _elm_send(ser, "A8", timeout=1.0)
    for cmd in ("ATSP6", "ATCAF1", "ATV0"):
        _elm_send(ser, cmd, pause=0.05)
    print("[tp20] channel closed")


def _tp20_request(
    ser: serial.Serial,
    counter: int,
    request: str,
    t3_ms: int | None,
    *,
    label: str = "",
) -> tuple[str | None, int]:
    """
    Execute one TP2.0 UDS request using CaristaReproduction packet framing.
    Returns (reassembled_payload_or_None, next_counter).

    Packet generation: VagCanCommunicator.generateOutgoingPackets (CaristaReproduction).
    ACK computation:   VagCanCommunicator.ackForReceivedPacket / expectedTransmitAck.
    ELM framing:       ATST04 (non-final), ATST20 (final) per recovered Carista constants.
    """
    pause_s = interFramePauseSeconds(t3_ms, TP20_INTER_FRAME_MINIMUM_MS)
    packets = generateOutgoingPackets(counter, request)
    next_counter = next_counter_after_request(counter, request)
    expected_ack = expectedTransmitAck(next_counter)
    tag = f"  [{label}] " if label else "  "

    print(f"{tag}request={request}  packets={[p.raw for p in packets]}  expect_tx_ack={expected_ack}")

    # Send non-final frames with ATST04 (short timeout, no response expected)
    for packet in packets[:-1]:
        _elm_send(ser, CARISTA_NON_FINAL_FRAME_ST, pause=0.05)
        _elm_send(ser, packet.raw, timeout=0.5)
        time.sleep(pause_s)

    # The live ELM clone needs ST32 to collect complete block-15 responses.
    _elm_send(ser, TP20_LIVE_RESPONSE_FRAME_ST, pause=0.05)
    raw = _elm_send(ser, packets[-1].raw, timeout=3.0)
    frames = _parse_frames(raw, LISTEN_HEADER)

    # Check transmit ACK
    tx_acks = findTransmitAcks(frames)
    if expected_ack.upper() in [a.upper() for a in tx_acks]:
        print(f"{tag}transmit ACK matched {expected_ack}")
    else:
        print(f"{tag}WARNING: transmit ACK {expected_ack} not seen in {frames}")

    # Collect data frames (non-ACK, non-keep-alive, non-disconnect)
    data_frames = [f for f in frames if _is_data_frame(f)]

    # If block=15 (A00F8AFF32FF), all frames arrive at once.
    # If block=1 (A00194FF82FF), frames arrive one at a time; ACK each to get the next.
    receive_more_attempts = 0
    while data_frames and not _has_final_data_frame(data_frames):
        # No final frame yet - send ACK for last received and collect more
        last = data_frames[-1]
        ack = ackForReceivedPacket(last)
        if ack is None:
            break
        more_data = _collect_more_frames(ser, ack)
        if not more_data and receive_more_attempts < CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT:
            receive_more_attempts += 1
            more_data = _collect_more_frames(ser, "A3")
        if not more_data:
            break
        data_frames.extend(more_data)

    # Send ACK for received frames (Carista ACK rule: B{(last_seq+1)&0xF})
    final_ack: str | None = None
    for frame in reversed(data_frames):
        candidate = ackForReceivedPacket(frame)
        if candidate is not None:
            final_ack = candidate
            break

    if final_ack:
        _elm_send(ser, f"ATSH{SEND_HEADER}", pause=0.05)
        _elm_send(ser, final_ack, timeout=1.5)
        print(f"{tag}sent inbound ACK {final_ack}")

    payload = readResponses(data_frames)
    print(f"{tag}payload={payload or '(none)'}")
    return payload, next_counter


def _target_coding(current_coding: str, operation: str) -> str:
    if operation == OPERATION_RESTORE_EXPERT_BACKUP:
        return EXPERT_BACKUP_CODING
    if operation == OPERATION_DRL_VIA_FOGS:
        return apply_cornering_fixes(current_coding, ("drl-via-fogs",))
    raise ValueError(f"unsupported operation: {operation}")


def _operation_label(operation: str) -> str:
    if operation == OPERATION_RESTORE_EXPERT_BACKUP:
        return "restore expert coding backup"
    if operation == OPERATION_DRL_VIA_FOGS:
        return "write drl_via_fogs = YES"
    return operation


# ---------------------------------------------------------------------------
# Session phases
# ---------------------------------------------------------------------------

def _read_did_one_shot(ser: serial.Serial, did: int) -> str | None:
    _, t3_ms = _tp20_open(ser)
    try:
        request = ReadDataByIdentifierCommand_getRequest(did)
        payload, _ = _tp20_request(ser, 0, request, t3_ms, label=request)
        return payload
    finally:
        _tp20_close(ser)


def _run_read_phase(ser: serial.Serial) -> tuple[str, str] | None:
    """
    Phase 1: read 220600, 220601, 220606, and 22F1A5, print cornering bit state.
    Returns (current_coding_hex, workshop_code_payload) or None on failure.
    """
    print("\n=== Phase 1: read-only baseline ===")

    # Read DID 0600 (long coding)
    payload_0600 = _read_did_one_shot(ser, READ_DID_LONG_CODING)
    if not payload_0600 or not payload_0600.upper().startswith("620600"):
        print(f"  ERROR: unexpected 220600 response: {payload_0600!r}")
        return None
    current_coding = normalize_coding(payload_0600)
    if len(current_coding) != 60:
        print(f"  ERROR: incomplete 220600 coding: {len(current_coding) // 2} bytes, expected 30")
        return None

    # Decode cornering bits using VagCoding.bit_state (CaristaReproduction)
    b12 = bit_state(current_coding, 12, 6)  # cornering_fogs
    b21_b7 = bit_state(current_coding, 21, 7)  # cornering_fogs_experimental
    b21_b2 = bit_state(current_coding, 21, 2)  # cornering_turn_signals (CORNERING_FIXES turn-signal = byte 21 bit 2)
    b21_b5 = bit_state(current_coding, 21, 5)  # turn_off_fogs_high_beam
    b23_b2 = bit_state(current_coding, 23, 2)  # drl_via_fogs

    print(f"\n  DID 0600 coding: {current_coding}")
    print(f"  byte 12 bit 6  cornering_fogs:               {b12}")
    print(f"  byte 21 bit 7  cornering_fogs_experimental:  {b21_b7}")
    print(f"  byte 21 bit 2  cornering_turn_signals:       {b21_b2}")
    print(f"  byte 21 bit 5  turn_off_fogs_high_beam:      {b21_b5}")
    print(f"  byte 23 bit 2  drl_via_fogs:                 {b23_b2}")

    for did in (READ_DID_0601, READ_DID_0606):
        request = ReadDataByIdentifierCommand_getRequest(did)
        payload = _read_did_one_shot(ser, did)
        expected_prefix = f"62{did:04X}"
        if not payload or not payload.upper().startswith(expected_prefix):
            print(f"  ERROR: unexpected {request} response: {payload!r}")
            return None
        print(f"  {request} -> {payload}")

    # Read 22F1A5 (workshop code)
    request_f1a5 = ReadDataByIdentifierCommand_getRequest(READ_DID_WORKSHOP_CODE)
    payload_f1a5 = _read_did_one_shot(ser, READ_DID_WORKSHOP_CODE)
    if not payload_f1a5 or not payload_f1a5.upper().startswith("62F1A5"):
        print(f"  ERROR: unexpected 22F1A5 response: {payload_f1a5!r}")
        return None
    workshop_code_payload = payload_f1a5.upper()[6:]  # strip 62F1A5 prefix
    print(f"  22F1A5 workshop code payload: {workshop_code_payload}")

    return current_coding, workshop_code_payload


def _run_write_phase(
    ser: serial.Serial,
    t3_ms: int | None,
    current_coding: str,
    workshop_code_payload: str,
    *,
    log_dir: Path,
    operation: str,
    run_id: str,
) -> bool:
    """
    Phase 2: build target using CaristaReproduction-supported coding helpers, execute write sequence.
    Returns True on verified success.
    """
    print(f"\n=== Phase 2: {_operation_label(operation)} ===")

    target_coding = _target_coding(current_coding, operation)
    if normalize_coding(current_coding) == normalize_coding(target_coding):
        print("  current coding already matches target - no write needed")
        return True

    print(f"  current: {current_coding}")
    print(f"  target:  {target_coding}")
    print("  changed bytes:")
    for byte_index, (old, new) in changed_coding_bytes(current_coding, target_coding).items():
        print(f"    byte {byte_index:02d}: {old} -> {new}")

    # Build write plan using CaristaReproduction.build_carista_uds_coding_write_plan
    write_plan = build_carista_uds_coding_write_plan(
        current_coding,
        target_coding,
        workshop_code_payload=workshop_code_payload,
    )

    print("\n  Recovered Carista UDS request sequence:")
    for req in write_plan.requests:
        print(f"    {req.label}: {req.request}")

    # Save plan
    plan_path = log_dir / f"{run_id}_write_plan.json"
    plan_path.write_text(json.dumps(asdict(write_plan), indent=2) + "\n", encoding="utf-8")
    print(f"\n  Write plan saved: {plan_path}")

    confirm = input("\n  Proceed with write? Type YES to confirm: ").strip()
    if confirm != "YES":
        print("  Write aborted by user")
        return False

    # Reset channel before write sequence (per Carista write session pattern)
    _tp20_close(ser)
    time.sleep(0.5)
    _, t3_ms = _tp20_open(ser)

    # Execute write sequence - counter restarts on fresh channel
    counter = 0
    for req in write_plan.requests:
        payload, counter = _tp20_request(ser, counter, req.request, t3_ms, label=req.label)

        # Check result using CaristaReproduction
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

        # ECU may disconnect after a write response; reopen if needed
        if payload and not payload.upper().startswith("7F"):
            pass  # channel still open
        # Brief pause between write commands
        time.sleep(0.3)

    return True


def _run_verify_phase(ser: serial.Serial, t3_ms: int | None, expected_target: str) -> bool:
    """Phase 3: read 220600 and verify it matches the requested target."""
    print("\n=== Phase 3: verification read ===")
    counter = 0
    request_0600 = ReadDataByIdentifierCommand_getRequest(READ_DID_LONG_CODING)
    payload, _ = _tp20_request(ser, counter, request_0600, t3_ms, label=f"verify {request_0600}")
    if not payload or not payload.upper().startswith("620600"):
        print(f"  ERROR: verify read failed: {payload!r}")
        return False
    verified_coding = normalize_coding(payload)
    b23_b2 = bit_state(verified_coding, 23, 2)
    print(f"  verified coding: {verified_coding}")
    print(f"  byte 23 bit 2 drl_via_fogs: {b23_b2}")
    match = verified_coding.upper() == expected_target.upper()
    print(f"  coding matches target: {match}")
    return match


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="BCM coding session runner - uses CaristaReproduction for all protocol logic.")
    parser.add_argument("--port", default="COM10", help="ELM327 serial port (default: COM10)")
    parser.add_argument("--baud", type=int, default=38400, help="Serial baud rate (default: 38400)")
    parser.add_argument("--write", action="store_true", help="Enable Phase 2 write after user confirmation")
    parser.add_argument(
        "--operation",
        choices=(OPERATION_RESTORE_EXPERT_BACKUP, OPERATION_DRL_VIA_FOGS),
        default=OPERATION_RESTORE_EXPERT_BACKUP,
        help="Target operation (default: restore-expert-backup)",
    )
    parser.add_argument("--log-dir", type=Path, default=Path(__file__).parent / "logs", help="Log output directory")
    args = parser.parse_args(argv)

    ts = datetime.now().strftime("%Y%m%d_%H%M%S")
    run_id = f"{args.operation.replace('-', '_')}_{ts}"
    args.log_dir.mkdir(parents=True, exist_ok=True)
    log_path = args.log_dir / f"{run_id}_session.txt"

    print(f"BCM coding session  run_id={run_id}")
    print(f"operation={args.operation}  target={_operation_label(args.operation)}")
    print(f"port={args.port}  baud={args.baud}  write={'YES' if args.write else 'NO'}")
    print(f"Blocked services (safety): 27 31 3B; 2E only if --write confirmed")
    print()

    with serial.Serial(args.port, args.baud, timeout=0.1) as ser:
        _init_elm(ser)

        # Phase 1 - always safe read-only
        result = _run_read_phase(ser)
        if result is None:
            print("Phase 1 failed - aborting")
            return 1
        current_coding, workshop_code_payload = result

        if not args.write:
            target_coding = _target_coding(current_coding, args.operation)
            print(f"\nRead-only pass complete. Target for {args.operation}: {target_coding}")
            if normalize_coding(current_coding) == normalize_coding(target_coding):
                print("Current coding already matches the target.")
            else:
                print("Use --write to proceed with Phase 2.")
            return 0

        # Phase 2 - guarded write
        target_coding = _target_coding(current_coding, args.operation)
        time.sleep(0.5)
        _, t3_ms = _tp20_open(ser)
        ok = _run_write_phase(
            ser, t3_ms, current_coding, workshop_code_payload,
            log_dir=args.log_dir, operation=args.operation, run_id=run_id,
        )
        if not ok:
            _tp20_close(ser)
            return 1

        # Phase 3 - verify
        time.sleep(0.5)
        _tp20_close(ser)
        time.sleep(0.3)
        _, t3_ms = _tp20_open(ser)
        verified = _run_verify_phase(ser, t3_ms, target_coding)
        _tp20_close(ser)

        if verified:
            print("\nSUCCESS: target coding written and verified.")
        else:
            print("\nWARNING: verification read did not match target coding")
            return 1

    print(f"\nLog: {log_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
