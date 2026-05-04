from __future__ import annotations

import argparse
import subprocess
import sys
from datetime import datetime
from pathlib import Path

WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
if str(WORKSPACE_ROOT) not in sys.path:
    sys.path.insert(0, str(WORKSPACE_ROOT))

from CaristaReproduction.VagCanCommunicator import CARISTA_CHANNEL_REOPEN_DELAY_MS, CARISTA_NATIVE_T3_MS
from CaristaReproduction.VagCoding import changed_coding_bytes, normalize_coding


SCRIPT_DIR = Path(__file__).resolve().parent
WRITER = SCRIPT_DIR / "write_carista_uds_coding.py"

RESTORED_BASELINE = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
PREVIOUS_CORNERING_REFERENCE = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"
EXPERT_HISTORICAL_BACKUP = "3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000"
DIAGNOSTICS_OFF_CORNERING = "3AB82B9F08A10000003008006C680ED000C8410F60860000200000000000"

CODING_PROFILES = {
    "diagnostics-off-cornering": DIAGNOSTICS_OFF_CORNERING,
    "expert-historical-backup": EXPERT_HISTORICAL_BACKUP,
    "restored-baseline": RESTORED_BASELINE,
    "previous-cornering-reference": PREVIOUS_CORNERING_REFERENCE,
}

BIT_LABELS = {
    (12, 6): "Turn/Cornering Lights installed/active",
    (13, 0): "Parking Lights ON only without ignition ON possible",
    (13, 1): "Parking Lights Function active",
    (13, 3): "Brake Light Activation via BCM",
    (13, 5): "Interior Light Enabling via Rear Lid",
    (13, 6): "Coming-Home/Leaving-Home variant",
    (16, 5): "Lamp Diagnostics for Rear Fog Light(s) active",
    (19, 5): "Lamp diagnostics for fog/cornering/turn lights active",
    (21, 2): "Cornering/Turn Lights via turn signal active",
    (21, 5): "Fog lights inactive with high beams active",
    (21, 7): "Front fog lights with turn/cornering lights installed",
    (22, 5): "Assistant Driving Light (ADL) active",
}


def bit_state(value: int, bit_index: int) -> str:
    return "set" if value & (1 << bit_index) else "clear"


def print_diff(expected: str, target: str) -> None:
    expected_bytes = bytes.fromhex(normalize_coding(expected))
    target_bytes = bytes.fromhex(normalize_coding(target))

    print("Changed bytes:")
    for byte_index, (old_hex, new_hex) in changed_coding_bytes(expected, target).items():
        old = expected_bytes[byte_index]
        new = target_bytes[byte_index]
        print(f"  byte {byte_index:02d}: {old_hex} -> {new_hex}")
        for bit_index in range(8):
            if (old ^ new) & (1 << bit_index):
                label = BIT_LABELS.get((byte_index, bit_index), "unlabelled bit")
                print(f"    bit {bit_index}: {bit_state(old, bit_index)} -> {bit_state(new, bit_index)} ({label})")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Guarded PQ25 lighting long-coding profile write wrapper.")
    parser.add_argument("--port", default="COM10")
    parser.add_argument("--baud", type=int, default=38400)
    parser.add_argument("--timeout", type=float, default=1.8)
    parser.add_argument("--unit", default="20")
    parser.add_argument(
        "--parameter-profile",
        choices=("minimal", "carista", "carista_exact", "carista_then_minimal"),
        default="carista_then_minimal",
    )
    parser.add_argument("--final-listen-ms", type=int, default=1200)
    parser.add_argument("--minimum-inter-frame-delay-ms", type=int, default=CARISTA_NATIVE_T3_MS)
    parser.add_argument("--channel-open-attempts", type=int, default=2)
    parser.add_argument("--channel-reopen-delay-ms", type=int, default=CARISTA_CHANNEL_REOPEN_DELAY_MS)
    parser.add_argument("--allow-default-channel-parameters", action="store_true")
    parser.add_argument("--date", dest="date_value", help="Date for F199 as YYYY-MM-DD. Defaults to today.")
    parser.add_argument("--workshop-code", help="Optional 6-byte workshop-code payload from 22F1A5.")
    parser.add_argument("--workshop-code-file", type=Path, help="Optional JSON summary containing a positive 22F1A5 read.")
    parser.add_argument("--expected-profile", choices=tuple(CODING_PROFILES), default="diagnostics-off-cornering")
    parser.add_argument("--expected-current", help="Override expected current coding. Live 220600 must match this exactly.")
    parser.add_argument("--target-profile", choices=tuple(CODING_PROFILES), default="previous-cornering-reference")
    parser.add_argument("--target-coding", help="Override target coding. Use only after manually verifying the byte diff.")
    parser.add_argument("--run-id", default=datetime.now().strftime("pq25_lighting_profile_write_%Y%m%d_%H%M%S"))
    parser.add_argument("--output-dir", type=Path, default=SCRIPT_DIR / "logs")
    parser.add_argument("--execute", action="store_true")
    parser.add_argument("--i-understand-this-writes-bcm-coding", action="store_true")
    return parser


def expected_current(args: argparse.Namespace) -> str:
    if args.expected_current:
        return normalize_coding(args.expected_current)
    return CODING_PROFILES[args.expected_profile]


def target_coding(args: argparse.Namespace) -> str:
    if args.target_coding:
        return normalize_coding(args.target_coding)
    return CODING_PROFILES[args.target_profile]


def build_writer_command(args: argparse.Namespace, expected: str, target: str) -> list[str]:
    command = [
        sys.executable,
        str(WRITER),
        "--coding",
        expected,
        "--target-coding",
        target,
        "--port",
        args.port,
        "--baud",
        str(args.baud),
        "--timeout",
        str(args.timeout),
        "--unit",
        args.unit,
        "--parameter-profile",
        args.parameter_profile,
        "--final-listen-ms",
        str(args.final_listen_ms),
        "--minimum-inter-frame-delay-ms",
        str(args.minimum_inter_frame_delay_ms),
        "--channel-open-attempts",
        str(args.channel_open_attempts),
        "--channel-reopen-delay-ms",
        str(args.channel_reopen_delay_ms),
        "--run-id",
        args.run_id,
        "--output-dir",
        str(args.output_dir),
    ]
    if args.date_value:
        command.extend(["--date", args.date_value])
    if args.workshop_code:
        command.extend(["--workshop-code", args.workshop_code])
    if args.workshop_code_file:
        command.extend(["--workshop-code-file", str(args.workshop_code_file)])
    if args.allow_default_channel_parameters:
        command.append("--allow-default-channel-parameters")
    if args.execute:
        command.extend(["--execute", "--confirm-target", target])
        if args.i_understand_this_writes_bcm_coding:
            command.append("--i-understand-this-writes-bcm-coding")
    return command


def main() -> int:
    args = build_parser().parse_args()
    expected = expected_current(args)
    target = target_coding(args)

    print("PQ25 lighting long-coding profile write")
    print()
    print(f"Expected profile:        {args.expected_profile}")
    print(f"Target profile:          {args.target_profile if not args.target_coding else 'custom'}")
    print(f"Expected current coding: {expected}")
    print(f"Target coding:           {target}")
    print()

    if expected == target:
        print("Nothing to write: expected current coding and target coding are identical.")
        return 0

    print_diff(expected, target)
    print()
    print("Guards:")
    print("  - fresh 220600 must exactly match the expected current coding")
    print("  - final 2E0600 must return positive")
    print("  - fresh verification 220600 must exactly match the target coding")
    print()

    writer_command = build_writer_command(args, expected, target)
    print("Underlying writer command:")
    print("  " + " ".join(writer_command))
    print()

    if not args.execute:
        if args.workshop_code or args.workshop_code_file:
            sys.stdout.flush()
            return subprocess.call(writer_command, cwd=SCRIPT_DIR)
        print("Dry plan only. Add --execute --i-understand-this-writes-bcm-coding in the car to write.")
        print("For a full dry-run frame plan, also provide --workshop-code or --workshop-code-file.")
        return 0

    if not args.i_understand_this_writes_bcm_coding:
        print("Execution blocked: add --i-understand-this-writes-bcm-coding.")
        return 2
    sys.stdout.flush()
    return subprocess.call(writer_command, cwd=SCRIPT_DIR)


if __name__ == "__main__":
    raise SystemExit(main())