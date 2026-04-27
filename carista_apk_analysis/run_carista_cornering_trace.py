from __future__ import annotations

import argparse
import json
import signal
import sys
import time
from pathlib import Path
from typing import Any, TextIO

import frida


DEFAULT_PACKAGE = "com.prizmos.carista"
DEFAULT_SCRIPT = Path(__file__).with_name("carista_cornering_trace.js")
DEFAULT_GADGET_HOST = "127.0.0.1:27042"


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Attach to Carista with Frida and trace ChangeSettingOperation plus "
            "the native VAG coding builder."
        )
    )
    parser.add_argument(
        "--package",
        default=DEFAULT_PACKAGE,
        help=f"Android package to trace (default: {DEFAULT_PACKAGE})",
    )
    parser.add_argument(
        "--script",
        type=Path,
        default=DEFAULT_SCRIPT,
        help="Path to the Frida JavaScript hook file.",
    )
    parser.add_argument(
        "--attach",
        action="store_true",
        help="Attach to an already running Carista process instead of spawning it.",
    )
    parser.add_argument(
        "--device-id",
        help="Specific Frida device ID to use. Defaults to the first USB device.",
    )
    parser.add_argument(
        "--host",
        help=(
            "Remote Frida host to use instead of USB discovery, for example "
            f"{DEFAULT_GADGET_HOST} after adb port-forwarding to Frida Gadget."
        ),
    )
    parser.add_argument(
        "--timeout-ms",
        type=int,
        default=5000,
        help="Frida device lookup timeout in milliseconds.",
    )
    parser.add_argument(
        "--out",
        type=Path,
        help="Optional JSONL file to append trace events to.",
    )
    parser.add_argument(
        "--check-only",
        action="store_true",
        help="Only test Frida device visibility and package visibility. Do not attach to Carista.",
    )
    return parser


def emit_json(payload: dict[str, Any], *, error: bool = False) -> None:
    target = sys.stderr if error else sys.stdout
    print(json.dumps(payload, sort_keys=True), file=target, flush=True)


def enumerate_devices() -> list[dict[str, str]]:
    manager = frida.get_device_manager()
    return [
        {
            "id": device.id,
            "name": device.name,
            "type": device.type,
        }
        for device in manager.enumerate_devices()
    ]


def resolve_device(args: argparse.Namespace) -> frida.core.Device:
    manager = frida.get_device_manager()
    if args.host:
        return manager.add_remote_device(args.host)

    if args.device_id:
        return manager.get_device(args.device_id, timeout=args.timeout_ms)

    for device in manager.enumerate_devices():
        if device.type == "usb":
            return device

    raise RuntimeError(
        "No Frida USB device is currently visible. Connect the phone over USB, enable USB debugging, and start frida-server on the phone."
    )


def format_message(message: dict[str, Any]) -> str:
    if message.get("type") == "send":
        return json.dumps(message.get("payload", {}), sort_keys=True)
    return json.dumps(message, sort_keys=True)


def make_message_handler(output_file: TextIO | None):
    def handle_message(message: dict[str, Any], data: bytes | None) -> None:
        line = format_message(message)
        target = sys.stderr if message.get("type") == "error" else sys.stdout
        print(line, file=target, flush=True)
        if output_file is not None:
            output_file.write(line + "\n")
            output_file.flush()

        if data:
            payload = data.hex().upper()
            print(payload, file=sys.stdout, flush=True)
            if output_file is not None:
                output_file.write(json.dumps({"type": "binary", "hex": payload}) + "\n")
                output_file.flush()

    return handle_message


def open_output(path: Path | None) -> TextIO | None:
    if path is None:
        return None
    path.parent.mkdir(parents=True, exist_ok=True)
    return path.open("a", encoding="utf-8")


def resolve_running_pid(device: frida.core.Device, package: str) -> int | None:
    for application in device.enumerate_applications():
        if application.identifier == package:
            if application.pid != 0:
                return application.pid
            return None
    return None


def resolve_remote_target_pid(device: frida.core.Device) -> int | None:
    for process in device.enumerate_processes():
        if process.pid != 0:
            return process.pid
    return None


def attach_or_spawn(
    device: frida.core.Device,
    package: str,
    attach: bool,
    *,
    host: str | None = None,
) -> tuple[frida.core.Session, int | None]:
    if host:
        running_pid = resolve_remote_target_pid(device)
        if running_pid is None:
            raise RuntimeError(
                f"remote Frida target at '{host}' is reachable but no Gadget-backed process is available yet"
            )
        return device.attach(running_pid), None

    if attach:
        running_pid = resolve_running_pid(device, package)
        if running_pid is None:
            raise RuntimeError(
                f"package '{package}' is installed but not currently running; launch the app first or use spawn mode"
            )
        return device.attach(running_pid), None

    pid = device.spawn([package])
    session = device.attach(pid)
    return session, pid


def check_environment(args: argparse.Namespace) -> int:
    emit_json(
        {
            "type": "status",
            "message": "frida_devices",
            "devices": enumerate_devices(),
        }
    )

    try:
        device = resolve_device(args)
    except Exception as exc:
        hint = (
            "Start Frida Gadget or frida-server and make sure the requested host is reachable."
            if args.host
            else "Start frida-server on the phone, enable USB debugging, and connect the phone over USB."
        )
        emit_json(
            {
                "type": "error",
                "message": "device_unavailable",
                "error": str(exc),
                "hint": hint,
                "host": args.host,
            },
            error=True,
        )
        return 2

    emit_json(
        {
            "type": "status",
            "message": "device_available",
            "device": {
                "id": device.id,
                "name": device.name,
                "type": device.type,
            },
            "host": args.host,
        }
    )

    try:
        applications = device.enumerate_applications()
    except Exception as exc:
        emit_json(
            {
                "type": "error",
                "message": "application_enumeration_failed",
                "error": str(exc),
            },
            error=True,
        )
        return 3

    if args.host:
        processes = [
            {
                "name": process.name,
                "pid": process.pid,
            }
            for process in device.enumerate_processes()
        ]
        emit_json(
            {
                "type": "status",
                "message": "remote_target_visibility",
                "host": args.host,
                "applications": [
                    {
                        "identifier": application.identifier,
                        "name": application.name,
                        "pid": application.pid,
                    }
                    for application in applications
                ],
                "processes": processes,
            }
        )
        return 0

    matching = [
        {
            "identifier": application.identifier,
            "name": application.name,
            "pid": application.pid,
        }
        for application in applications
        if application.identifier == args.package
    ]
    emit_json(
        {
            "type": "status",
            "message": "package_visibility",
            "package": args.package,
            "installed": bool(matching),
            "applications": matching,
        }
    )
    return 0


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()

    script_path = args.script.resolve()
    if not script_path.exists():
        parser.error(f"Frida hook script not found: {script_path}")

    output_file = open_output(args.out)
    if args.check_only:
        try:
            return check_environment(args)
        finally:
            if output_file is not None:
                output_file.close()

    stop_requested = False

    def request_stop(signum: int, frame: Any) -> None:
        nonlocal stop_requested
        stop_requested = True

    signal.signal(signal.SIGINT, request_stop)
    if hasattr(signal, "SIGTERM"):
        signal.signal(signal.SIGTERM, request_stop)

    try:
        device = resolve_device(args)
        session, spawned_pid = attach_or_spawn(device, args.package, args.attach, host=args.host)
    except frida.ServerNotRunningError as exc:
        emit_json(
            {
                "type": "error",
                "message": "frida_server_not_running",
                "package": args.package,
                "attach": args.attach,
                "error": str(exc),
                "hint": "This phone can talk to adb/Frida over USB, but no remote frida-server is running. On a non-root, non-debuggable Android app, live hooking is blocked unless you provide Frida Gadget or a rooted frida-server setup.",
                "host": args.host,
            },
            error=True,
        )
        if output_file is not None:
            output_file.close()
        return 4
    except Exception as exc:
        emit_json(
            {
                "type": "error",
                "message": "trace_attach_failed",
                "package": args.package,
                "attach": args.attach,
                "error": str(exc),
                "hint": (
                    "Run with --check-only first, make sure the Frida Gadget listener is reachable, then retry."
                    if args.host
                    else "Run with --check-only first, make sure frida-server is running on the phone, then retry."
                ),
                "host": args.host,
            },
            error=True,
        )
        if output_file is not None:
            output_file.close()
        return 4

    try:
        source = script_path.read_text(encoding="utf-8")
        script = session.create_script(source)
        script.on("message", make_message_handler(output_file))
        script.load()

        if spawned_pid is not None:
            device.resume(spawned_pid)

        emit_json(
            {
                "type": "status",
                "message": "trace_active",
                "package": args.package,
                "attach": args.attach,
                "script": str(script_path),
                "host": args.host,
            }
        )

        while not stop_requested:
            time.sleep(0.25)
    except Exception as exc:
        emit_json(
            {
                "type": "error",
                "message": "trace_runtime_failed",
                "package": args.package,
                "error": str(exc),
            },
            error=True,
        )
        return 5
    finally:
        try:
            session.detach()
        except frida.InvalidOperationError:
            pass
        if output_file is not None:
            output_file.close()

    return 0


if __name__ == "__main__":
    raise SystemExit(main())