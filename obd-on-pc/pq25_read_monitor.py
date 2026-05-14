"""
pq25_read_monitor.py - active read-only PQ25 BCM monitor using TP2.0 one-shot reads.

Replaces: run_bcm_active_monitor.py

All protocol framing and request building uses CaristaReproduction.
ELM327/TP2.0 transport is shared from _tp20_transport.py.

Read-only guardrail: blocks 27, 2E, 31, 3B. Only accepts 18, 19, 1A, 21, 22, 24.

Usage:
    python obd-on-pc/pq25_read_monitor.py
    python obd-on-pc/pq25_read_monitor.py --profile switch --cycles 8 --label fog_switch_toggle
    python obd-on-pc/pq25_read_monitor.py --profile carista-dtc --cycles 1
    python obd-on-pc/pq25_read_monitor.py --profile fog-role-candidates
    python obd-on-pc/pq25_read_monitor.py --kwp21-range 10 1F --cycles 1 --label kwp21_10_1f
    python obd-on-pc/pq25_read_monitor.py --did22-range 0550 056F --cycles 1
    python obd-on-pc/pq25_read_monitor.py --vag-adaptation-channel 2F --label ch2f
    python obd-on-pc/pq25_read_monitor.py --commands 220601 --commands 220606 --cycles 3
    python obd-on-pc/pq25_read_monitor.py --list-profiles
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import time
from datetime import datetime
from pathlib import Path
from typing import Sequence

import serial

# CaristaReproduction is at the workspace root.
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from CaristaReproduction.ReadValuesOperation import ReadValuesOperation_pq25BcmRequests
from CaristaReproduction.VagDiagnosticsOperation import VagDiagnosticsOperation_pq25BcmReadOnlyRequests
from CaristaReproduction.Commands.VagCanAdaptationCommands import (
    READ_VAG_CAN_LONG_ADAPTATION_BASIC_ID,
    READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID,
    PreReadVagCanAdaptationDataCommand_getRequest,
    PreReadVagCanAdaptationDataCommand_processPayload,
    ReadVagCanLongAdaptationDataCommand_getRequest,
    ReadVagCanLongAdaptationDataCommand_processPayload,
    ReadVagCanShortAdaptationDataCommand_getRequest,
    ReadVagCanShortAdaptationDataCommand_processPayload,
    SetVagCanAdaptationChannelCommand_getRequest,
    StartReadVagCanRoutineCommand_getRequest,
    StopReadVagCanRoutineCommand_getRequest,
)

# Shared ELM327/TP2.0 transport
sys.path.insert(0, str(Path(__file__).resolve().parent))
from _tp20_transport import (
    elm_send,
    init_elm,
    tp20_close,
    tp20_open,
    tp20_request,
)

READ_ONLY_BLOCKED_PREFIXES = ("27", "2E", "31", "3B")
READ_ONLY_ALLOWED_PREFIXES = ("18", "19", "1A", "21", "22", "24")
READ_ONLY_SETUP_PREFIXES = ("10", "3E")
DEFAULT_COMMANDS = ("220601", "220606", "1802FF00")
VAG_ADAPTATION_KINDS = ("short", "long")
_HEX_RE = re.compile(r"^[0-9A-Fa-f]+$")

MONITOR_PROFILES: dict[str, tuple[str, ...]] = {
    "switch": DEFAULT_COMMANDS,
    "dtc": ("1802FF00", "1902FF"),
    "carista-dtc": VagDiagnosticsOperation_pq25BcmReadOnlyRequests(),
    "carista-dtc-detail-known": VagDiagnosticsOperation_pq25BcmReadOnlyRequests(include_known_detail=True),
    "identity": ("22F187", "22F189", "22F197", "22F1A5"),
    "coding": ("220600",),
    "carista-core": ReadValuesOperation_pq25BcmRequests(include_live_companions=True),
    "fog-role-candidates": (
        "220554",
        "220555",
        "220556",
        "220557",
        "22055C",
        "22055D",
        "22056C",
        "22110E",
        "220D04",
        "220D1D",
    ),
    "scaling-known-dids": (
        "240600",
        "240601",
        "240606",
        "24055C",
        "24055D",
        "240D04",
        "240D1D",
        "24110E",
    ),
    "kwp21-early": tuple(f"21{index:02X}" for index in range(1, 0x10)),
}
MONITOR_PROFILES["all-safe"] = tuple(
    dict.fromkeys(
        command
        for profile in ("switch", "dtc", "identity", "coding", "carista-core")
        for command in MONITOR_PROFILES[profile]
    )
)


def _normalize_hex(value: str) -> str:
    command = value.strip().replace(" ", "").upper()
    if not command or len(command) % 2 or not _HEX_RE.match(command):
        raise ValueError(f"invalid hex command: {value!r}")
    if command.startswith(READ_ONLY_BLOCKED_PREFIXES):
        raise ValueError(f"blocked non-read-only command: {command}")
    return command


def _normalize_command(value: str) -> str:
    command = _normalize_hex(value)
    if not command.startswith(READ_ONLY_ALLOWED_PREFIXES):
        allowed = ", ".join(READ_ONLY_ALLOWED_PREFIXES)
        raise ValueError(f"command is outside active-monitor read prefixes ({allowed}): {command}")
    return command


def _normalize_setup_command(value: str) -> str:
    command = _normalize_hex(value)
    if not command.startswith(READ_ONLY_SETUP_PREFIXES):
        allowed = ", ".join(READ_ONLY_SETUP_PREFIXES)
        raise ValueError(f"setup command is outside active-monitor setup prefixes ({allowed}): {command}")
    return command


def _commands_from_profiles(profile_names: Sequence[str], explicit_commands: Sequence[str]) -> tuple[str, ...]:
    commands: list[str] = []
    for profile_name in profile_names:
        commands.extend(MONITOR_PROFILES[profile_name])
    commands.extend(explicit_commands)
    return tuple(dict.fromkeys(_normalize_command(command) for command in commands))


def _parse_kwp21_id(value: str) -> int:
    raw = value.strip().upper()
    if raw.startswith("21"):
        raw = raw[2:]
    if raw.startswith("0X"):
        raw = raw[2:]
    if not raw or len(raw) > 2 or not _HEX_RE.match(raw):
        raise ValueError(f"invalid KWP21 local identifier: {value!r}")
    index = int(raw, 16)
    if not 0 <= index <= 0xFF:
        raise ValueError(f"KWP21 local identifier out of range: {value!r}")
    return index


def _kwp21_range_commands(range_values: Sequence[str]) -> tuple[str, ...]:
    if not range_values:
        return ()
    if len(range_values) != 2:
        raise ValueError("--kwp21-range requires exactly START END")
    start = _parse_kwp21_id(range_values[0])
    end = _parse_kwp21_id(range_values[1])
    if start > end:
        raise ValueError(f"KWP21 range start must be <= end: {range_values[0]} {range_values[1]}")
    return tuple(f"21{index:02X}" for index in range(start, end + 1))


def _parse_did22_id(value: str) -> int:
    raw = value.strip().upper()
    if raw.startswith("22"):
        raw = raw[2:]
    if raw.startswith("0X"):
        raw = raw[2:]
    if not raw or len(raw) > 4 or not _HEX_RE.match(raw):
        raise ValueError(f"invalid DID: {value!r}")
    did = int(raw, 16)
    if not 0 <= did <= 0xFFFF:
        raise ValueError(f"DID out of range: {value!r}")
    return did


def _did22_range_commands(range_values: Sequence[str]) -> tuple[str, ...]:
    if not range_values:
        return ()
    if len(range_values) != 2:
        raise ValueError("--did22-range requires exactly START END")
    start = _parse_did22_id(range_values[0])
    end = _parse_did22_id(range_values[1])
    if start > end:
        raise ValueError(f"DID range start must be <= end: {range_values[0]} {range_values[1]}")
    return tuple(f"22{did:04X}" for did in range(start, end + 1))


def _parse_service1a_id(value: str) -> int:
    raw = value.strip().upper()
    if raw.startswith("1A"):
        raw = raw[2:]
    if raw.startswith("0X"):
        raw = raw[2:]
    if not raw or len(raw) > 2 or not _HEX_RE.match(raw):
        raise ValueError(f"invalid service 1A local identifier: {value!r}")
    index = int(raw, 16)
    if not 0 <= index <= 0xFF:
        raise ValueError(f"service 1A local identifier out of range: {value!r}")
    return index


def _service1a_range_commands(range_values: Sequence[str]) -> tuple[str, ...]:
    if not range_values:
        return ()
    if len(range_values) != 2:
        raise ValueError("--service1a-range requires exactly START END")
    start = _parse_service1a_id(range_values[0])
    end = _parse_service1a_id(range_values[1])
    if start > end:
        raise ValueError(f"service 1A range start must be <= end: {range_values[0]} {range_values[1]}")
    return tuple(f"1A{index:02X}" for index in range(start, end + 1))


def _parse_channel_byte(value: str) -> int:
    raw = value.strip().upper()
    if raw.startswith("0X"):
        raw = raw[2:]
    if not raw or len(raw) > 2 or not _HEX_RE.match(raw):
        raise ValueError(f"invalid adaptation channel: {value!r}")
    channel = int(raw, 16)
    if not 0 <= channel <= 0xFF:
        raise ValueError(f"adaptation channel out of range: {value!r}")
    return channel


def _vag_adaptation_read_plan(kind: str, channel: int) -> tuple[dict[str, str], ...]:
    if kind not in VAG_ADAPTATION_KINDS:
        valid = ", ".join(VAG_ADAPTATION_KINDS)
        raise ValueError(f"VAG adaptation kind must be one of {valid}: {kind!r}")
    basic_id = READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID if kind == "short" else READ_VAG_CAN_LONG_ADAPTATION_BASIC_ID
    data_request = (
        ReadVagCanShortAdaptationDataCommand_getRequest()
        if kind == "short"
        else ReadVagCanLongAdaptationDataCommand_getRequest()
    )
    return (
        {
            "step": "start-read-routine",
            "command": StartReadVagCanRoutineCommand_getRequest(basic_id),
            "parser": "done",
        },
        {
            "step": "pre-read",
            "command": PreReadVagCanAdaptationDataCommand_getRequest(basic_id),
            "parser": "pre-read",
        },
        {
            "step": "set-channel",
            "command": SetVagCanAdaptationChannelCommand_getRequest(basic_id, channel),
            "parser": "done",
        },
        {
            "step": "read-data",
            "command": data_request,
            "parser": "short-data" if kind == "short" else "long-data",
        },
        {
            "step": "stop-read-routine",
            "command": StopReadVagCanRoutineCommand_getRequest(basic_id),
            "parser": "done",
        },
    )


def _parse_vag_adaptation_step(kind: str, parser_name: str, payload: str | None) -> dict[str, object]:
    if payload is None:
        return {"state": "no-payload"}
    if parser_name == "pre-read":
        result = PreReadVagCanAdaptationDataCommand_processPayload(payload)
    elif parser_name == "short-data":
        result = ReadVagCanShortAdaptationDataCommand_processPayload(payload)
    elif parser_name == "long-data":
        result = ReadVagCanLongAdaptationDataCommand_processPayload(payload)
    else:
        return {"state": "not-parsed"}
    parsed: dict[str, object] = {"state": result.state, "ok": not result.isFail()}
    if result.value is not None:
        parsed["value"] = result.value
    parsed["kind"] = kind
    return parsed


def _read_once(ser: serial.Serial, command: str, setup_commands: Sequence[str]) -> tuple[str | None, list[dict[str, str | None]]]:
    _, t3_ms = tp20_open(ser)
    counter = 0
    setup_observations: list[dict[str, str | None]] = []
    try:
        for setup_command in setup_commands:
            setup_payload, counter = tp20_request(
                ser,
                counter,
                setup_command,
                t3_ms,
                label=f"setup {setup_command}",
            )
            setup_observations.append({"command": setup_command, "payload": setup_payload})
        payload, _next_counter = tp20_request(ser, counter, command, t3_ms, label=command)
        return payload, setup_observations
    finally:
        tp20_close(ser)


def _read_vag_adaptation_once(
    ser: serial.Serial,
    kind: str,
    channel: int,
    plan: Sequence[dict[str, str]],
    setup_commands: Sequence[str],
) -> tuple[list[dict[str, object]], list[dict[str, str | None]]]:
    _, t3_ms = tp20_open(ser)
    counter = 0
    setup_observations: list[dict[str, str | None]] = []
    step_observations: list[dict[str, object]] = []
    try:
        for setup_command in setup_commands:
            setup_payload, counter = tp20_request(
                ser,
                counter,
                setup_command,
                t3_ms,
                label=f"setup {setup_command}",
            )
            setup_observations.append({"command": setup_command, "payload": setup_payload})
        for step in plan:
            payload, counter = tp20_request(
                ser,
                counter,
                step["command"],
                t3_ms,
                label=f"vag-adaptation {kind} channel {channel:02X} {step['step']}",
            )
            step_observations.append(
                {
                    "step": step["step"],
                    "command": step["command"],
                    "payload": payload,
                    "parsed": _parse_vag_adaptation_step(kind, step["parser"], payload),
                }
            )
        return step_observations, setup_observations
    finally:
        tp20_close(ser)


def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Active read-only BCM monitor using TP2.0 one-shot reads.")
    parser.add_argument("--port", default="COM10")
    parser.add_argument("--baud", type=int, default=38400)
    parser.add_argument(
        "--profile",
        choices=tuple(MONITOR_PROFILES),
        action="append",
        default=[],
        help="Named read-only command profile. Can be repeated.",
    )
    parser.add_argument("--commands", nargs="+", default=[])
    parser.add_argument(
        "--kwp21-range",
        nargs=2,
        metavar=("START", "END"),
        default=[],
        help="Add a read-only KWP service-21 local-identifier range, e.g. 10 1F or 2110 211F.",
    )
    parser.add_argument(
        "--did22-range",
        nargs=2,
        metavar=("START", "END"),
        default=[],
        help="Add a read-only UDS/KWP ReadDataByIdentifier range, e.g. 0550 056F or 220550 22056F.",
    )
    parser.add_argument(
        "--service1a-range",
        nargs=2,
        metavar=("START", "END"),
        default=[],
        help="Add a read-only KWP service-1A local-identifier range, e.g. 80 9F or 1A80 1A9F.",
    )
    parser.add_argument(
        "--vag-adaptation-kind",
        choices=VAG_ADAPTATION_KINDS,
        default="short",
        help="Carista VAG CAN adaptation routine kind for --vag-adaptation-channel.",
    )
    parser.add_argument(
        "--vag-adaptation-channel",
        help="Run one exact Carista VAG CAN adaptation read routine for this hex channel, e.g. 2F or 30.",
    )
    parser.add_argument("--cycles", type=int, default=6)
    parser.add_argument("--pause", type=float, default=1.0, help="Pause between cycles in seconds.")
    parser.add_argument(
        "--setup-command",
        action="append",
        default=[],
        help="Optional per-read setup command. Restricted to 10.. and 3E..; can be repeated.",
    )
    parser.add_argument("--label", default="active_monitor")
    parser.add_argument("--log-dir", type=Path, default=Path(__file__).parent / "logs")
    parser.add_argument("--list-profiles", action="store_true")
    args = parser.parse_args(argv)

    if args.list_profiles:
        for name, commands in MONITOR_PROFILES.items():
            print(f"{name}: {' '.join(commands)}")
        return 0

    adaptation_channel = _parse_channel_byte(args.vag_adaptation_channel) if args.vag_adaptation_channel else None
    adaptation_plan = (
        _vag_adaptation_read_plan(args.vag_adaptation_kind, adaptation_channel)
        if adaptation_channel is not None
        else ()
    )
    profile_names = args.profile or ([] if args.commands or adaptation_plan else ["switch"])
    setup_commands = tuple(_normalize_setup_command(cmd) for cmd in args.setup_command)

    # Build the full command list
    all_commands = list(_commands_from_profiles(profile_names, args.commands))
    all_commands.extend(_kwp21_range_commands(args.kwp21_range))
    all_commands.extend(_did22_range_commands(args.did22_range))
    all_commands.extend(_service1a_range_commands(args.service1a_range))

    if not all_commands and not adaptation_plan:
        print("No commands or adaptation plan to execute.")
        return 0

    ts = datetime.now().strftime("%Y%m%d_%H%M%S")
    run_id = f"{args.label}_{ts}"
    args.log_dir.mkdir(parents=True, exist_ok=True)
    log_path = args.log_dir / f"{run_id}.json"

    print(f"BCM active read monitor  run_id={run_id}")
    print(f"profiles={profile_names or None}  commands={all_commands or None}")
    print(f"vag adaptation: kind={args.vag_adaptation_kind} channel={adaptation_channel or 'none'}")
    print(f"cycles={args.cycles}  pause={args.pause}s  label={args.label}")
    print(f"Blocked services (safety): {' '.join(READ_ONLY_BLOCKED_PREFIXES)}")
    print()

    if all_commands:
        print(f"Commands: {' '.join(all_commands)}")
    print()

    with serial.Serial(args.port, args.baud, timeout=0.1) as ser:
        init_elm(ser)

        observations: list[dict[str, object]] = []

        for cycle in range(args.cycles):
            print(f"\n--- cycle {cycle + 1}/{args.cycles} ---")

            for command in all_commands:
                payload, setup_observations = _read_once(ser, command, setup_commands)
                observations.append({
                    "cycle": cycle + 1,
                    "command": command,
                    "payload": payload,
                    "setup_observations": setup_observations,
                })
                if payload:
                    print(f"  {command} -> {payload}")
                else:
                    print(f"  {command} -> (no payload)")

            if adaptation_plan:
                adapt_observations, adapt_setup = _read_vag_adaptation_once(
                    ser, args.vag_adaptation_kind, adaptation_channel,
                    adaptation_plan, setup_commands,
                )
                observations.append({
                    "cycle": cycle + 1,
                    "type": "vag-adaptation",
                    "kind": args.vag_adaptation_kind,
                    "channel": adaptation_channel,
                    "steps": adapt_observations,
                    "setup_observations": adapt_setup,
                })

            if cycle < args.cycles - 1:
                time.sleep(args.pause)

    # Save observations
    log_path.write_text(json.dumps(observations, indent=2) + "\n", encoding="utf-8")
    print(f"\nObservations saved: {log_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
