from __future__ import annotations

import argparse
import csv
import json
import re
import time
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Callable, Literal, TypeAlias, TypedDict

import serial


DEFAULT_PORT = "COM10"
DEFAULT_BAUD = 38400
DEFAULT_UNIT = "20"  # VW TP2.0 address for VAG unit 09 / onboard supply control unit.

SESSION_SWEEP_COMMANDS = ("1089", "108B", "1085", "1001", "1002", "1003")
ACK_SWEEP_VARIANTS = ("none", "B1", "B10", "B0")
ACK_SWEEP_DELAYS_MS = (50, 100, 250, 500, 1000)
PRE_READ_SWEEP_SEQUENCES = ("none", "A3", "B1", "A3+B1", "B1+A3")
CARISTA_KWP_READS = ("1A9B", "1A9F", "1A91", "1A9A", "1A86")
LEGACY_KWP_READS = ("1A9B", "1A9A", "1A91", "1A90", "1A88", "1A8C", "1A8D", "1A94", "1A95")
CARISTA_UDS_READS = (
    "220600",
    "220601",
    "220606",
    "22F17E",
    "22F187",
    "22F189",
    "22F18C",
    "22F191",
    "22F197",
    "22F1A3",
    "22F1A5",
    "22F1AA",
    "22F1DF",
)
READ_PROFILES = {
    "carista_kwp": CARISTA_KWP_READS,
    "carista_uds": CARISTA_UDS_READS,
    "carista_all": CARISTA_KWP_READS + CARISTA_UDS_READS,
    "legacy": LEGACY_KWP_READS,
}
MAX_AUTO_ACK_ROUNDS = 8

BLOCKED_SERVICE_PREFIXES = ("27", "2E", "31", "3B")
HEX_RE = re.compile(r"^[0-9A-F]+$", re.IGNORECASE)
CONTROL_FRAME_RE = re.compile(r"^(A3|B[0-9A-F]+)$", re.IGNORECASE)

HexString: TypeAlias = str
CanHeader: TypeAlias = str
Tp20Counter: TypeAlias = int
ControlFrame: TypeAlias = HexString
PreReadSequence: TypeAlias = tuple[ControlFrame, ...]
ApplicationStatus: TypeAlias = Literal[
    "positive",
    "negative",
    "other",
    "disconnect",
    "keep_alive",
    "raw_frames",
    "no_response",
]
ChannelParameterStatus: TypeAlias = Literal["answered", "defaulted", "skipped"]

CARISTA_COMMAND_LABELS: dict[HexString, str] = {
    "1089": "diagnostic session observed by Carista/PQ25 flow; positive response is 5089",
    "220600": "direct long-coding read DID; latest live baseline returns 620600 + 30-byte coding",
    "1A9B": "GetVagCanEcuInfoCommand_getRequest / ECU component identity",
    "1A9F": "GetVagCanEcuListCommand / ECU list/info",
    "1A91": "Carista VAGCAN20 simulator identity/coding-related block",
    "1A9A": "ReadVagCanLongCodingCommand_getRequest / long coding",
    "1A86": "Carista VAGCAN20 simulator software/version dataset block",
    "A00194FF82FF": "Carista exact TP2.0 channel parameter setup from libCarista.so",
    "A00F8AFF32FF": "known-good minimal TP2.0 channel parameter request for this Polo",
    "A3": "TP2.0 keep-alive; Carista ignores it",
    "A8": "TP2.0 disconnect/close frame",
    "B0": "TP2.0 ACK/control variant",
    "B1": "TP2.0 ACK for ECU sequence 0 using Carista ACK rule",
    "3B9A": "probable long-coding write command; blocked in read-only probe",
    "31B8": "StartReadVagCanRoutineCommand; blocked in read-only probe",
    "31BA": "Pre/ReadVagCanAdaptationDataCommand; blocked in read-only probe",
    "31B9": "SetVagCanAdaptationChannelCommand; blocked in read-only probe",
    "32B8": "StopReadVagCanRoutineCommand; blocked in read-only probe",
}

SUMMARY_FIELDS = (
    "attempt_id",
    "mode",
    "started",
    "log_file",
    "unit",
    "send_header",
    "listen_header",
    "channel_parameter_profile",
    "channel_parameter_status",
    "channel_parameters",
    "session_command",
    "session_command_label",
    "session_counter",
    "session_status",
    "session_result",
    "pre_read_sequence",
    "post_session_extra_frames",
    "read_profile",
    "ack_variant",
    "delay_ms",
    "read_counter",
    "read_command",
    "read_command_label",
    "read_status",
    "read_result",
    "stopped_early",
    "raw_payloads",
    "error",
)


@dataclass(frozen=True)
class CanFrame:
    timestamp: str
    source: str
    header: CanHeader
    payload: HexString

    @property
    def tp20_label(self) -> str:
        return tp20_payload_label(self.payload)


@dataclass(frozen=True)
class CommandResult:
    cleaned: str
    frames: list[CanFrame]


class FrameDict(TypedDict):
    timestamp: str
    source: str
    header: CanHeader
    payload: HexString
    tp20_label: str


class Logger:
    def __init__(self, output: Path) -> None:
        self.output = output
        self.lines: list[str] = []

    def write(self, text: str = "") -> None:
        print(text)
        self.lines.append(text)

    def section(self, title: str) -> None:
        self.write()
        self.write("=" * 80)
        self.write(title)
        self.write("=" * 80)

    def save(self) -> None:
        self.output.parent.mkdir(parents=True, exist_ok=True)
        self.output.write_text("\n".join(self.lines) + "\n", encoding="utf-8")
        print(f"\nWrote log: {self.output}")


def now() -> str:
    return datetime.now().isoformat(timespec="milliseconds")


def normalize_command(value: str) -> str:
    return value.strip().replace(" ", "").upper()


def normalize_hex(value: str) -> str:
    return normalize_command(value)


def carista_command_label(command: str) -> str:
    command = normalize_hex(command)
    if command in CARISTA_COMMAND_LABELS:
        return CARISTA_COMMAND_LABELS[command]
    for prefix in ("3B9A", "31B8", "31BA", "31B9", "32B8"):
        if command.startswith(prefix):
            return CARISTA_COMMAND_LABELS[prefix]
    return ""


def tp20_payload_label(payload: str) -> str:
    payload = normalize_hex(payload)
    if not payload:
        return ""
    if payload.startswith("A1") and len(payload) >= 12:
        try:
            values = bytes.fromhex(payload[:12])
        except ValueError:
            return "TP2.0 channel parameter response"
        return f"TP2.0 channel parameters block={values[1]} T1={values[2]} T2={values[3]} T3={values[4]} T4={values[5]}"
    if payload.startswith("A3"):
        return CARISTA_COMMAND_LABELS["A3"]
    if payload.startswith("A8"):
        return CARISTA_COMMAND_LABELS["A8"]
    if payload.startswith("B"):
        return "TP2.0 ACK/control frame"
    if payload.startswith("9"):
        return "TP2.0 NACK/control frame"
    if payload[0] in {"0", "1", "2", "3"}:
        try:
            sequence = int(payload[1], 16)
        except (IndexError, ValueError):
            return "TP2.0 application frame"
        if payload[0] == "1" and len(payload) >= 6:
            try:
                byte_count = int(payload[2:6], 16)
            except ValueError:
                return f"TP2.0 application first frame seq={sequence:X}"
            return f"TP2.0 application first frame seq={sequence:X} len={byte_count}"
        if payload[0] == "2":
            return f"TP2.0 application continuation frame seq={sequence:X}"
        return f"TP2.0 application/control frame type={payload[0]} seq={sequence:X}"
    return ""


def validate_hex(value: str, label: str, even: bool = True) -> HexString:
    normalized = normalize_hex(value)
    if not normalized or not HEX_RE.match(normalized):
        raise argparse.ArgumentTypeError(f"{label} must be hex")
    if even and len(normalized) % 2:
        raise argparse.ArgumentTypeError(f"{label} must contain whole bytes")
    return normalized


def is_safe_application_command(command: str) -> bool:
    command = normalize_hex(command)
    return not command.startswith(BLOCKED_SERVICE_PREFIXES)


def parse_commands(raw: str) -> tuple[HexString, ...]:
    commands = tuple(validate_hex(part, "command") for part in raw.split(",") if part.strip())
    if not commands:
        raise argparse.ArgumentTypeError("At least one command is required")
    for command in commands:
        if not is_safe_application_command(command):
            raise argparse.ArgumentTypeError(f"Blocked non-read-only service: {command}")
    return commands


def parse_delays(raw: str) -> tuple[int, ...]:
    delays: list[int] = []
    for part in raw.split(","):
        part = part.strip()
        if not part:
            continue
        try:
            delay = int(part)
        except ValueError as exc:
            raise argparse.ArgumentTypeError(f"Invalid delay: {part}") from exc
        if delay < 0:
            raise argparse.ArgumentTypeError("Delays must be >= 0")
        delays.append(delay)
    if not delays:
        raise argparse.ArgumentTypeError("At least one delay is required")
    return tuple(delays)


def parse_counters(raw: str) -> tuple[int, ...]:
    counters: list[int] = []
    for part in raw.split(","):
        part = part.strip()
        if not part:
            continue
        try:
            counter = int(part, 0)
        except ValueError as exc:
            raise argparse.ArgumentTypeError(f"Invalid counter: {part}") from exc
        if not 0 <= counter <= 0xF:
            raise argparse.ArgumentTypeError("Counters must be between 0 and 15")
        counters.append(counter)
    if not counters:
        raise argparse.ArgumentTypeError("At least one counter is required")
    return tuple(counters)


def parse_ack_variant(raw: str) -> ControlFrame | Literal["none"]:
    ack = normalize_command(raw)
    if ack in {"", "NONE", "NOACK", "NO_ACK"}:
        return "none"
    if not HEX_RE.match(ack):
        raise argparse.ArgumentTypeError(f"Invalid ACK variant: {raw}")
    if ack.startswith(BLOCKED_SERVICE_PREFIXES):
        raise argparse.ArgumentTypeError(f"Blocked non-read-only service: {ack}")
    if not ack.startswith("B"):
        raise argparse.ArgumentTypeError(f"ACK variant must be none or a TP2.0 B-frame, got: {raw}")
    return ack


def parse_ack_variants(raw: str) -> tuple[ControlFrame | Literal["none"], ...]:
    variants = tuple(parse_ack_variant(part) for part in raw.split(",") if part.strip())
    if not variants:
        raise argparse.ArgumentTypeError("At least one ACK variant is required")
    return variants


def parse_control_frame(raw: str) -> ControlFrame:
    control = normalize_command(raw)
    if not CONTROL_FRAME_RE.match(control):
        raise argparse.ArgumentTypeError(f"Unsupported TP2.0 control frame: {raw}")
    return control


def parse_pre_read_sequence(raw: str) -> PreReadSequence:
    raw = raw.strip()
    if not raw or raw.lower() == "none":
        return ()
    sequence = tuple(parse_control_frame(part) for part in raw.split("+") if part.strip())
    if not sequence:
        raise argparse.ArgumentTypeError("At least one pre-read control frame is required")
    return sequence


def parse_pre_read_sequences(raw: str) -> tuple[PreReadSequence, ...]:
    sequences = tuple(parse_pre_read_sequence(part) for part in raw.split(",") if part.strip())
    if not sequences:
        raise argparse.ArgumentTypeError("At least one pre-read sequence is required")
    return sequences


def parse_read_profile(raw: str) -> str:
    profile = raw.strip().lower()
    if profile not in READ_PROFILES:
        choices = ", ".join(sorted(READ_PROFILES))
        raise argparse.ArgumentTypeError(f"Unknown read profile {raw!r}; choose one of: {choices}")
    return profile


def unique_commands(commands: list[HexString] | tuple[HexString, ...]) -> list[HexString]:
    seen: set[HexString] = set()
    unique: list[HexString] = []
    for command in commands:
        if command in seen:
            continue
        seen.add(command)
        unique.append(command)
    return unique


def selected_read_commands(args: argparse.Namespace) -> list[HexString]:
    commands = list(args.read_commands or READ_PROFILES[args.read_profile])
    return unique_commands(commands)


def format_pre_read_sequence(sequence: PreReadSequence) -> str:
    return "none" if not sequence else "+".join(sequence)


def response_marker(command: str) -> HexString:
    command = normalize_hex(command)
    service = int(command[:2], 16)
    return f"{service + 0x40:02X}{command[2:]}"


def read_until_prompt_or_timeout(ser: serial.Serial, timeout: float) -> str:
    deadline = time.monotonic() + timeout
    chunks: list[bytes] = []
    while time.monotonic() < deadline:
        waiting = ser.in_waiting
        if waiting:
            chunk = ser.read(waiting)
            chunks.append(chunk)
            if b">" in chunk:
                # The prompt means the ELM finished this command, not that only one frame was read.
                break
        else:
            time.sleep(0.02)
    return b"".join(chunks).decode("ascii", errors="replace")


def clean_response(raw: str, command: str) -> str:
    command = normalize_command(command)
    lines: list[str] = []
    for line in raw.replace(">", "").splitlines():
        line = line.strip()
        if not line:
            continue
        if normalize_command(line) == command:
            continue
        lines.append(line)
    return "\n".join(lines)


def parse_can_frames(text: str, source: str) -> list[CanFrame]:
    frames: list[CanFrame] = []
    for line in text.replace(">", "").splitlines():
        compact = normalize_hex(line)
        if not compact or compact in {"OK", "NODATA"} or compact.startswith("?"):
            continue
        if not HEX_RE.match(compact) or len(compact) < 5:
            continue
        header = compact[:3]
        payload = compact[3:]
        if len(payload) % 2:
            continue
        frames.append(CanFrame(timestamp=now(), source=source, header=header, payload=payload))
    return frames


def drain_available_input(
    ser: serial.Serial,
    logger: Logger,
    source: str,
) -> list[CanFrame]:
    chunks: list[bytes] = []
    while ser.in_waiting:
        chunks.append(ser.read(ser.in_waiting))

    if not chunks:
        return []

    raw = b"".join(chunks).decode("ascii", errors="replace")
    cleaned = raw.replace(">", "").strip()
    frames = parse_can_frames(cleaned, source)

    logger.write(f"[{now()}] buffered RX before command ({source})")
    logger.write(cleaned or "<buffered non-frame bytes>")
    for frame in frames:
        frame_label = f" [{frame.tp20_label}]" if frame.tp20_label else ""
        logger.write(f"BUFFERED_FRAME {frame.timestamp} {frame.header} {frame.payload}{frame_label}")
    logger.write("-" * 60)
    return frames


def send(
    ser: serial.Serial,
    logger: Logger,
    command: str,
    timeout: float,
    pause: float = 0.25,
    reset_input: bool = True,
) -> CommandResult:
    command = normalize_command(command)
    if reset_input:
        drain_available_input(ser, logger, f"pre_{command}")
    ser.write((command + "\r").encode("ascii"))
    ser.flush()
    time.sleep(pause)
    raw = read_until_prompt_or_timeout(ser, timeout)
    cleaned = clean_response(raw, command)
    frames = parse_can_frames(cleaned, command)
    label = carista_command_label(command)
    label_suffix = f" ({label})" if label else ""

    logger.write(f"[{now()}] >>> {command}{label_suffix}")
    logger.write(cleaned or "<no response>")
    for frame in frames:
        frame_label = f" [{frame.tp20_label}]" if frame.tp20_label else ""
        logger.write(f"FRAME {frame.timestamp} {frame.header} {frame.payload}{frame_label}")
    logger.write("-" * 60)
    return CommandResult(cleaned=cleaned, frames=frames)


def collect_passive_frames(
    ser: serial.Serial,
    logger: Logger,
    duration_ms: int,
    source: str,
    listen_header: str,
) -> list[CanFrame]:
    logger.write(f"[{now()}] passive listen {duration_ms} ms on {listen_header} ({source})")
    deadline = time.monotonic() + duration_ms / 1000.0
    chunks: list[bytes] = []
    while time.monotonic() < deadline:
        waiting = ser.in_waiting
        if waiting:
            chunks.append(ser.read(waiting))
        else:
            time.sleep(0.02)
    raw = b"".join(chunks).decode("ascii", errors="replace")
    cleaned = raw.replace(">", "").strip()
    frames = [frame for frame in parse_can_frames(cleaned, source) if frame.header == listen_header]

    if cleaned:
        logger.write(cleaned)
    else:
        logger.write("<no passive frames>")
    for frame in frames:
        frame_label = f" [{frame.tp20_label}]" if frame.tp20_label else ""
        logger.write(f"PASSIVE_FRAME {frame.timestamp} {frame.header} {frame.payload}{frame_label}")
    logger.write("-" * 60)
    return frames


def frame_dict(frame: CanFrame) -> FrameDict:
    return {
        "timestamp": frame.timestamp,
        "source": frame.source,
        "header": frame.header,
        "payload": frame.payload,
        "tp20_label": frame.tp20_label,
    }


def frame_dicts(frames: list[CanFrame]) -> list[FrameDict]:
    return [frame_dict(frame) for frame in frames]


def append_frames(row: dict[str, object], frames: list[CanFrame]) -> None:
    raw_payloads = row.get("raw_payloads")
    if isinstance(raw_payloads, list):
        raw_payloads.extend(frame_dicts(frames))
    else:
        row["raw_payloads"] = frame_dicts(frames)


def init_elm(ser: serial.Serial, logger: Logger, timeout: float) -> None:
    for command, pause in (
        ("ATZ", 1.0),
        ("ATE0", 0.25),
        ("ATL0", 0.25),
        ("ATS0", 0.25),
        ("ATH1", 0.25),
        ("ATCAF0", 0.25),
        ("ATV1", 0.25),
        ("ATAL", 0.25),
        ("ATSP6", 0.25),
        ("ATDP", 0.25),
        ("ATRV", 0.25),
    ):
        send(ser, logger, command, timeout, pause)


def open_tp20_channel(ser: serial.Serial, logger: Logger, unit: HexString, timeout: float) -> tuple[CanHeader, CanHeader, list[CanFrame]] | None:
    free_client_header = "300"
    open_frames = (
        # Older Car Scanner TP2.0 helper. This is the known-good one for this Polo.
        f"{unit}C00010000301",
        # Newer Car Scanner VWTPECU helper, using client response header 300.
        f"{unit}C00010{free_client_header[1:]}0{free_client_header[0]}01",
    )

    for open_frame in open_frames:
        logger.section(f"Open TP2.0 channel to unit address {unit}")
        for command in ("ATSP6", "ATCAF0", "ATV1", "ATAR", "ATSH200", "ATST0A"):
            send(ser, logger, command, timeout, pause=0.2)

        result = send(ser, logger, open_frame, timeout=2.5, pause=0.7)
        for frame in result.frames:
            data = bytes.fromhex(frame.payload)
            if len(data) < 6 or data[1] != 0xD0:
                continue
            listen_header = f"{data[3] * 256 + data[2]:03X}"
            send_header = f"{data[5] * 256 + data[4]:03X}"
            logger.write(f"Opened TP2.0 channel: send={send_header}, listen={listen_header}")
            return send_header, listen_header, result.frames

    return None


def get_channel_parameters(
    ser: serial.Serial,
    logger: Logger,
    send_header: str,
    listen_header: str,
    timeout: float,
    profile: str,
) -> tuple[int, int, int, int, int, list[CanFrame], ChannelParameterStatus]:
    minimal_attempts = (
        ("minimal-fast", listen_header, ("ATST32", f"ATSH{send_header}"), "A00F8AFF32FF"),
    )
    legacy_attempts = minimal_attempts + (
        ("automatic-receive", listen_header, ("ATST32", f"ATSH{send_header}", "ATAR"), "A00F8AFF32FF"),
        ("normal", listen_header, ("ATST32", f"ATSH{send_header}", f"ATCRA{listen_header}"), "A00F8AFF32FF"),
        ("car-scanner-short-timeout", listen_header, ("ATST18", f"ATSH{send_header}", f"ATCRA{listen_header}"), "A00F8AFF32FF"),
        ("reversed-test", send_header, ("ATST32", f"ATSH{listen_header}", f"ATCRA{send_header}"), "A00F8AFF32FF"),
    )
    carista_attempts = (
        # Decompiled Carista 9.8.2 builds this exact TP2.0 channel parameter setup.
        ("carista-exact", listen_header, ("ATST32", f"ATSH{send_header}", f"ATCRA{listen_header}"), "A00194FF82FF"),
        ("carista-exact-automatic-receive", listen_header, ("ATST32", f"ATSH{send_header}", "ATAR"), "A00194FF82FF"),
    )
    attempts = {
        "minimal": minimal_attempts,
        "legacy": legacy_attempts,
        "carista": carista_attempts,
        "all": legacy_attempts + carista_attempts,
    }[profile]

    all_frames: list[CanFrame] = []
    for name, expected_response, setup, payload in attempts:
        logger.write(f"Trying TP2.0 parameter setup: {name} payload={payload}")
        for command in setup:
            send(ser, logger, command, timeout, pause=0.2)
        result = send(ser, logger, payload, timeout=3.0, pause=0.9)
        all_frames.extend(result.frames)
        for frame in result.frames:
            data = bytes.fromhex(frame.payload)
            if frame.header == expected_response and len(data) >= 6 and data[0] == 0xA1:
                max_block, t1, t2, t3, t4 = data[1:6]
                logger.write(f"TP2.0 parameters: block={max_block}, T1={t1}, T2={t2}, T3={t3}, T4={t4}")
                return max_block, t1, t2, t3, t4, all_frames, "answered"

    logger.write("TP2.0 parameter read did not answer; continuing with conservative defaults.")
    return 15, 255, 255, 255, 255, all_frames, "defaulted"


def configure_data_channel(ser: serial.Serial, logger: Logger, send_header: CanHeader, listen_header: CanHeader, timeout: float) -> None:
    for command in ("ATST32", f"ATSH{send_header}", f"ATCRA{listen_header}"):
        send(ser, logger, command, timeout, pause=0.15)


def tp20_request_frame(counter: Tp20Counter, command: HexString) -> HexString:
    command = normalize_hex(command)
    byte_count = len(command) // 2
    if byte_count > 5:
        raise ValueError(f"This experiment runner only supports short TP2.0 requests, got {command}")
    return f"1{counter:X}{byte_count:04X}{command}"


def tp20_application_payload_state(frames: list[CanFrame], listen_header: CanHeader) -> tuple[HexString, int]:
    payloads = [frame.payload for frame in frames if frame.header == listen_header]
    if not payloads:
        return "", 0

    result = ""
    expected_length = 0
    for payload in payloads:
        if not payload:
            continue
        frame_type = payload[0]
        if frame_type in {"0", "1", "2", "3"}:
            if not result:
                if len(payload) >= 6:
                    try:
                        expected_length = int(payload[2:6], 16)
                    except ValueError:
                        expected_length = 0
                    result += payload[6:]
            else:
                result += payload[2:]

    if expected_length and len(result) > expected_length * 2:
        result = result[: expected_length * 2]
    return result, expected_length


def extract_tp20_application_payload(frames: list[CanFrame], listen_header: CanHeader) -> HexString:
    return tp20_application_payload_state(frames, listen_header)[0]


def is_tp20_application_payload_complete(frames: list[CanFrame], listen_header: CanHeader) -> bool:
    payload, expected_length = tp20_application_payload_state(frames, listen_header)
    return bool(expected_length and len(payload) >= expected_length * 2)


def classify_application_payload(command: HexString, payload: HexString, frames: list[CanFrame], listen_header: CanHeader) -> ApplicationStatus:
    if payload.startswith("7F"):
        return "negative"
    if payload.startswith(response_marker(command)):
        return "positive"
    if payload:
        return "other"
    if any(frame.header == listen_header and frame.payload.startswith("A8") for frame in frames):
        return "disconnect"
    if any(frame.header == listen_header and frame.payload.startswith("A3") for frame in frames):
        return "keep_alive"
    if any(frame.header == listen_header for frame in frames):
        return "raw_frames"
    return "no_response"


def ack_needed_frames(frames: list[CanFrame], listen_header: CanHeader) -> list[ControlFrame]:
    acks: list[ControlFrame] = []
    for frame in frames:
        if frame.header != listen_header or not frame.payload:
            continue
        frame_type = frame.payload[0]
        if frame_type not in {"0", "1"}:
            continue
        try:
            sequence = int(frame.payload[1], 16)
        except ValueError:
            continue
        acks.append(f"B{(sequence + 1) & 0xF:X}")
    return acks


def send_tp20_application_request(
    ser: serial.Serial,
    logger: Logger,
    command: HexString,
    counter: Tp20Counter,
    listen_header: CanHeader,
    timeout: float,
    auto_ack: bool,
    reset_input: bool = True,
) -> tuple[ApplicationStatus, HexString, list[CanFrame], Tp20Counter]:
    if not is_safe_application_command(command):
        raise ValueError(f"Blocked non-read-only service: {command}")

    label = carista_command_label(command)
    label_suffix = f" ({label})" if label else ""
    logger.write(f"[{now()}] TP2.0 application request counter={counter:X} command={command}{label_suffix}")
    request_frame = tp20_request_frame(counter, command)
    result = send(ser, logger, request_frame, timeout=2.5, pause=0.7, reset_input=reset_input)
    frames = list(result.frames)

    if auto_ack:
        new_frames = result.frames
        for _ in range(MAX_AUTO_ACK_ROUNDS):
            if is_tp20_application_payload_complete(frames, listen_header):
                break
            pending_acks = ack_needed_frames(new_frames, listen_header)
            if not pending_acks:
                break

            new_frames = []
            for ack in pending_acks:
                ack_result = send(ser, logger, ack, timeout=1.5, pause=0.25, reset_input=False)
                frames.extend(ack_result.frames)
                new_frames.extend(ack_result.frames)
            if not new_frames:
                break

    payload = extract_tp20_application_payload(frames, listen_header)
    status = classify_application_payload(command, payload, frames, listen_header)
    return status, payload, frames, (counter + 1) & 0xF


def send_ack_variant(ser: serial.Serial, logger: Logger, ack_variant: ControlFrame | Literal["none"], timeout: float) -> list[CanFrame]:
    ack_variant = parse_ack_variant(ack_variant)
    if ack_variant == "none":
        logger.write(f"[{now()}] ACK variant: none")
        return []
    result = send(ser, logger, ack_variant, timeout=1.5, pause=0.25, reset_input=False)
    return result.frames


def send_pre_read_sequence(
    ser: serial.Serial,
    logger: Logger,
    sequence: PreReadSequence,
    timeout: float,
) -> list[CanFrame]:
    label = format_pre_read_sequence(sequence)
    logger.write(f"[{now()}] pre-read sequence: {label}")
    if not sequence:
        return []

    frames: list[CanFrame] = []
    for control in sequence:
        result = send(ser, logger, control, timeout=1.5, pause=0.25, reset_input=False)
        frames.extend(result.frames)
    return frames


def has_disconnect_frame(frames: list[CanFrame], listen_header: CanHeader) -> bool:
    return any(frame.header == listen_header and frame.payload.startswith("A8") for frame in frames)


def set_session_command(row: dict[str, object], command: HexString) -> None:
    row["session_command"] = command
    row["session_command_label"] = carista_command_label(command)


def set_read_command(row: dict[str, object], command: HexString) -> None:
    row["read_command"] = command
    row["read_command_label"] = carista_command_label(command)


def close_channel(ser: serial.Serial, logger: Logger, send_header: CanHeader, timeout: float) -> None:
    logger.section("Close TP2.0 channel")
    send(ser, logger, f"ATSH{send_header}", timeout, pause=0.15)
    send(ser, logger, "A8", timeout=1.5, pause=0.3)
    for command in ("ATSP6", "ATCAF1", "ATV0"):
        send(ser, logger, command, timeout, pause=0.15)


def base_row(args: argparse.Namespace, mode: str, attempt_id: str, log_file: Path) -> dict[str, object]:
    return {
        "attempt_id": attempt_id,
        "mode": mode,
        "started": now(),
        "log_file": str(log_file),
        "unit": args.unit,
        "send_header": "",
        "listen_header": "",
        "channel_parameter_profile": args.parameter_profile,
        "channel_parameter_status": "",
        "channel_parameters": {},
        "session_command": "",
        "session_command_label": "",
        "session_counter": "",
        "session_status": "",
        "session_result": "",
        "pre_read_sequence": "",
        "post_session_extra_frames": [],
        "read_profile": args.read_profile,
        "ack_variant": "",
        "delay_ms": "",
        "read_counter": "",
        "read_command": "",
        "read_command_label": "",
        "read_status": "",
        "read_result": "",
        "stopped_early": "",
        "raw_payloads": [],
        "error": "",
    }


def clone_sequence_row(row: dict[str, object], attempt_id: str) -> dict[str, object]:
    sequence_row = dict(row)
    post_session_frames = row.get("post_session_extra_frames", [])
    raw_payloads = row.get("raw_payloads", [])
    sequence_row["attempt_id"] = attempt_id
    sequence_row["post_session_extra_frames"] = list(post_session_frames) if isinstance(post_session_frames, list) else []
    sequence_row["raw_payloads"] = list(raw_payloads) if isinstance(raw_payloads, list) else []
    sequence_row["read_counter"] = ""
    sequence_row["read_command"] = ""
    sequence_row["read_command_label"] = ""
    sequence_row["read_status"] = ""
    sequence_row["read_result"] = ""
    sequence_row["stopped_early"] = ""
    return sequence_row


AttemptOperation = Callable[[serial.Serial, Logger, dict[str, object], CanHeader, CanHeader], None]


def attempt_log_path(args: argparse.Namespace, mode: str, attempt_id: str) -> Path:
    safe_id = re.sub(r"[^A-Za-z0-9_.-]+", "_", attempt_id)
    return args.output_dir / f"{args.run_id}_{mode}_{safe_id}.txt"


def run_isolated_attempt(args: argparse.Namespace, mode: str, attempt_id: str, operation: AttemptOperation) -> dict[str, object]:
    log_file = attempt_log_path(args, mode, attempt_id)
    logger = Logger(log_file)
    row = base_row(args, mode, attempt_id, log_file)
    send_header = ""

    logger.write("VW PQ25 TP2.0 read-only sequencing experiment")
    logger.write(f"Started: {row['started']}")
    logger.write(f"Mode: {mode}")
    logger.write(f"Attempt: {attempt_id}")
    logger.write(f"Port: {args.port}")
    logger.write(f"Baud: {args.baud}")
    logger.write(f"Unit TP2.0 address: {args.unit}")
    logger.write(f"Channel parameter profile: {args.parameter_profile}")
    if args.skip_channel_parameters:
        logger.write("Channel parameter read: skipped")
    logger.write("Blocked services: 27, 2E, 31, 3B")

    try:
        with serial.Serial(args.port, args.baud, timeout=args.timeout, write_timeout=args.timeout) as ser:
            logger.section("ELM initialization")
            init_elm(ser, logger, args.timeout)

            channel = open_tp20_channel(ser, logger, args.unit, args.timeout)
            if channel is None:
                raise RuntimeError(f"Could not open VW TP2.0 channel to unit address {args.unit}")
            send_header, listen_header, open_frames = channel
            row["send_header"] = send_header
            row["listen_header"] = listen_header
            append_frames(row, open_frames)

            if args.skip_channel_parameters:
                logger.write("Skipping TP2.0 parameter read; using conservative defaults.")
                row["channel_parameter_status"] = "skipped"
                row["channel_parameters"] = {"block": 15, "T1": 255, "T2": 255, "T3": 255, "T4": 255}
            else:
                max_block, t1, t2, t3, t4, param_frames, param_status = get_channel_parameters(
                    ser,
                    logger,
                    send_header,
                    listen_header,
                    args.timeout,
                    args.parameter_profile,
                )
                row["channel_parameter_status"] = param_status
                row["channel_parameters"] = {"block": max_block, "T1": t1, "T2": t2, "T3": t3, "T4": t4}
                append_frames(row, param_frames)
            configure_data_channel(ser, logger, send_header, listen_header, args.timeout)

            operation(ser, logger, row, send_header, listen_header)
            close_channel(ser, logger, send_header, args.timeout)
    except (RuntimeError, ValueError, serial.SerialException) as exc:
        row["error"] = str(exc)
        logger.write(f"ERROR: {exc}")
    finally:
        logger.save()

    return row


def run_session_sweep(args: argparse.Namespace) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for session_command in args.sessions:
        attempt_id = f"session_{session_command}"

        def operation(
            ser: serial.Serial,
            logger: Logger,
            row: dict[str, object],
            _send_header: str,
            listen_header: str,
            session_command: str = session_command,
        ) -> None:
            logger.section(f"Session sweep: {session_command}")
            set_session_command(row, session_command)
            status, payload, frames, _ = send_tp20_application_request(
                ser,
                logger,
                session_command,
                counter=0,
                listen_header=listen_header,
                timeout=args.timeout,
                auto_ack=False,
            )
            row["session_status"] = status
            row["session_result"] = payload
            append_frames(row, frames)

            extra = collect_passive_frames(ser, logger, args.sniff_ms, f"post_session_{session_command}", listen_header)
            row["post_session_extra_frames"] = frame_dicts(extra)
            append_frames(row, extra)

        rows.append(run_isolated_attempt(args, "session_sweep", attempt_id, operation))
    return rows


def run_direct_read(args: argparse.Namespace) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    read_commands = selected_read_commands(args)
    read_counter = args.read_counter if args.read_counter is not None else 0

    for read_command in read_commands:
        attempt_id = f"direct_ctr{read_counter:X}_{read_command}"

        def operation(
            ser: serial.Serial,
            logger: Logger,
            row: dict[str, object],
            _send_header: str,
            listen_header: str,
            read_command: str = read_command,
            read_counter: int = read_counter,
        ) -> None:
            logger.section(f"Direct read: counter={read_counter:X}, read={read_command}")
            row["read_counter"] = f"{read_counter:X}"
            set_read_command(row, read_command)

            read_status, read_payload, read_frames, _ = send_tp20_application_request(
                ser,
                logger,
                read_command,
                counter=read_counter,
                listen_header=listen_header,
                timeout=args.timeout,
                auto_ack=True,
            )
            row["read_status"] = read_status
            row["read_result"] = read_payload
            append_frames(row, read_frames)

        rows.append(run_isolated_attempt(args, "direct_read", attempt_id, operation))
    return rows


def run_direct_sequence(args: argparse.Namespace) -> list[dict[str, object]]:
    sequence_rows: list[dict[str, object]] = []
    read_commands = selected_read_commands(args)
    start_counter = args.read_counter if args.read_counter is not None else 0
    attempt_id = f"sequence_ctr{start_counter:X}_{'_'.join(read_commands)}"

    def operation(
        ser: serial.Serial,
        logger: Logger,
        row: dict[str, object],
        _send_header: str,
        listen_header: str,
    ) -> None:
        logger.section(f"Direct same-channel sequence: counter={start_counter:X}, reads={','.join(read_commands)}")
        counter = start_counter
        for read_command in read_commands:
            sequence_attempt_id = f"sequence_ctr{counter:X}_{read_command}"
            sequence_row = clone_sequence_row(row, sequence_attempt_id)
            sequence_row["read_counter"] = f"{counter:X}"
            set_read_command(sequence_row, read_command)

            logger.section(f"Sequence read: counter={counter:X}, read={read_command}")
            read_status, read_payload, read_frames, counter = send_tp20_application_request(
                ser,
                logger,
                read_command,
                counter=counter,
                listen_header=listen_header,
                timeout=args.timeout,
                auto_ack=True,
            )
            sequence_row["read_status"] = read_status
            sequence_row["read_result"] = read_payload
            append_frames(sequence_row, read_frames)
            sequence_rows.append(sequence_row)

            if read_status == "disconnect":
                sequence_row["stopped_early"] = "true"
                logger.write("Stopping same-channel sequence after TP2.0 disconnect.")
                break

    base_result = run_isolated_attempt(args, "direct_sequence", attempt_id, operation)
    return sequence_rows if sequence_rows else [base_result]


def run_ack_sweep(args: argparse.Namespace) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for ack_variant in args.ack_variants:
        for delay_ms in args.delays_ms:
            attempt_id = f"ack_{args.session}_{ack_variant}_{delay_ms}ms_read_{args.read_command}"

            def operation(
                ser: serial.Serial,
                logger: Logger,
                row: dict[str, object],
                _send_header: str,
                listen_header: str,
                ack_variant: str = ack_variant,
                delay_ms: int = delay_ms,
            ) -> None:
                logger.section(f"ACK sweep: session={args.session}, ack={ack_variant}, delay={delay_ms} ms")
                set_session_command(row, args.session)
                row["session_counter"] = "0"
                row["ack_variant"] = ack_variant
                row["delay_ms"] = delay_ms
                set_read_command(row, args.read_command)

                status, payload, frames, counter = send_tp20_application_request(
                    ser,
                    logger,
                    args.session,
                    counter=0,
                    listen_header=listen_header,
                    timeout=args.timeout,
                    auto_ack=False,
                )
                row["session_status"] = status
                row["session_result"] = payload
                append_frames(row, frames)
                if status != "positive":
                    return

                ack_frames = send_ack_variant(ser, logger, ack_variant, args.timeout)
                wait_frames = collect_passive_frames(ser, logger, delay_ms, f"ack_wait_{ack_variant}_{delay_ms}ms", listen_header)
                post_frames = ack_frames + wait_frames
                row["post_session_extra_frames"] = frame_dicts(post_frames)
                append_frames(row, post_frames)

                read_status, read_payload, read_frames, _ = send_tp20_application_request(
                    ser,
                    logger,
                    args.read_command,
                    counter=counter,
                    listen_header=listen_header,
                    timeout=args.timeout,
                    auto_ack=True,
                )
                row["read_status"] = read_status
                row["read_result"] = read_payload
                append_frames(row, read_frames)

            rows.append(run_isolated_attempt(args, "ack_sweep", attempt_id, operation))
    return rows


def run_counter_sweep(args: argparse.Namespace) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for ack_variant in args.ack_variants:
        for delay_ms in args.delays_ms:
            for read_counter in args.read_counters:
                attempt_id = f"counter_{args.session}_{ack_variant}_{delay_ms}ms_ctr{read_counter:X}_read_{args.read_command}"

                def operation(
                    ser: serial.Serial,
                    logger: Logger,
                    row: dict[str, object],
                    _send_header: str,
                    listen_header: str,
                    ack_variant: str = ack_variant,
                    delay_ms: int = delay_ms,
                    read_counter: int = read_counter,
                ) -> None:
                    logger.section(
                        "Counter sweep: "
                        f"session={args.session}, ack={ack_variant}, delay={delay_ms} ms, "
                        f"read_counter={read_counter:X}, read={args.read_command}"
                    )
                    set_session_command(row, args.session)
                    row["session_counter"] = "0"
                    row["ack_variant"] = ack_variant
                    row["delay_ms"] = delay_ms
                    row["read_counter"] = f"{read_counter:X}"
                    set_read_command(row, args.read_command)

                    status, payload, frames, _ = send_tp20_application_request(
                        ser,
                        logger,
                        args.session,
                        counter=0,
                        listen_header=listen_header,
                        timeout=args.timeout,
                        auto_ack=False,
                    )
                    row["session_status"] = status
                    row["session_result"] = payload
                    append_frames(row, frames)
                    if status != "positive":
                        return

                    ack_frames = send_ack_variant(ser, logger, ack_variant, args.timeout)
                    wait_frames = collect_passive_frames(
                        ser,
                        logger,
                        delay_ms,
                        f"counter_wait_{ack_variant}_{delay_ms}ms",
                        listen_header,
                    )
                    post_frames = ack_frames + wait_frames
                    row["post_session_extra_frames"] = frame_dicts(post_frames)
                    append_frames(row, post_frames)

                    read_status, read_payload, read_frames, _ = send_tp20_application_request(
                        ser,
                        logger,
                        args.read_command,
                        counter=read_counter,
                        listen_header=listen_header,
                        timeout=args.timeout,
                        auto_ack=True,
                    )
                    row["read_status"] = read_status
                    row["read_result"] = read_payload
                    append_frames(row, read_frames)

                rows.append(run_isolated_attempt(args, "counter_sweep", attempt_id, operation))
    return rows


def run_read_sweep(args: argparse.Namespace) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    read_commands = selected_read_commands(args)

    for read_command in read_commands:
        attempt_id = f"read_{args.session}_{args.ack}_{args.delay_ms}ms_{read_command}"

        def operation(
            ser: serial.Serial,
            logger: Logger,
            row: dict[str, object],
            _send_header: str,
            listen_header: str,
            read_command: str = read_command,
        ) -> None:
            logger.section(
                f"Read sweep: session={args.session}, ack={args.ack}, delay={args.delay_ms} ms, read={read_command}"
            )
            set_session_command(row, args.session)
            row["session_counter"] = "0"
            row["ack_variant"] = args.ack
            row["delay_ms"] = args.delay_ms
            set_read_command(row, read_command)

            status, payload, frames, counter = send_tp20_application_request(
                ser,
                logger,
                args.session,
                counter=0,
                listen_header=listen_header,
                timeout=args.timeout,
                auto_ack=False,
            )
            row["session_status"] = status
            row["session_result"] = payload
            append_frames(row, frames)
            if status != "positive":
                return

            ack_frames = send_ack_variant(ser, logger, args.ack, args.timeout)
            wait_frames = collect_passive_frames(ser, logger, args.delay_ms, f"read_wait_{args.ack}_{args.delay_ms}ms", listen_header)
            post_frames = ack_frames + wait_frames
            row["post_session_extra_frames"] = frame_dicts(post_frames)
            append_frames(row, post_frames)

            read_counter = args.read_counter if args.read_counter is not None else counter
            row["read_counter"] = f"{read_counter:X}"
            counter_note = "override" if args.read_counter is not None else "derived"
            logger.write(f"[{now()}] read counter selected: {read_counter:X} ({counter_note})")
            logger.write(
                f"[{now()}] preserve input before first read: {'true' if args.preserve_input_before_read else 'false'}"
            )

            read_status, read_payload, read_frames, _ = send_tp20_application_request(
                ser,
                logger,
                read_command,
                counter=read_counter,
                listen_header=listen_header,
                timeout=args.timeout,
                auto_ack=True,
                reset_input=not args.preserve_input_before_read,
            )
            row["read_status"] = read_status
            row["read_result"] = read_payload
            append_frames(row, read_frames)

        rows.append(run_isolated_attempt(args, "read_sweep", attempt_id, operation))
    return rows


def run_passive_sniff(args: argparse.Namespace) -> list[dict[str, object]]:
    attempt_id = f"passive_{args.session}_{args.sniff_ms}ms"

    def operation(
        ser: serial.Serial,
        logger: Logger,
        row: dict[str, object],
        _send_header: str,
        listen_header: str,
    ) -> None:
        logger.section(f"Passive sniff after session={args.session}")
        set_session_command(row, args.session)
        row["session_counter"] = "0"

        status, payload, frames, _ = send_tp20_application_request(
            ser,
            logger,
            args.session,
            counter=0,
            listen_header=listen_header,
            timeout=args.timeout,
            auto_ack=False,
        )
        row["session_status"] = status
        row["session_result"] = payload
        append_frames(row, frames)
        if status != "positive":
            return

        extra = collect_passive_frames(ser, logger, args.sniff_ms, f"passive_after_{args.session}", listen_header)
        row["post_session_extra_frames"] = frame_dicts(extra)
        append_frames(row, extra)

    return [run_isolated_attempt(args, "passive_sniff", attempt_id, operation)]


def run_pre_read_sweep(args: argparse.Namespace) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for session_counter in args.session_counters:
        for pre_read_sequence in args.pre_read_sequences:
            for delay_ms in args.delays_ms:
                for read_counter in args.read_counters:
                    sequence_label = format_pre_read_sequence(pre_read_sequence)
                    attempt_id = (
                        f"pre_{args.session}_sctr{session_counter:X}_{sequence_label}_"
                        f"{delay_ms}ms_rctr{read_counter:X}_read_{args.read_command}"
                    )

                    def operation(
                        ser: serial.Serial,
                        logger: Logger,
                        row: dict[str, object],
                        _send_header: str,
                        listen_header: str,
                        session_counter: int = session_counter,
                        pre_read_sequence: tuple[str, ...] = pre_read_sequence,
                        delay_ms: int = delay_ms,
                        read_counter: int = read_counter,
                    ) -> None:
                        logger.section(
                            "Pre-read sweep: "
                            f"session={args.session}, session_counter={session_counter:X}, "
                            f"pre_read={format_pre_read_sequence(pre_read_sequence)}, "
                            f"delay={delay_ms} ms, read_counter={read_counter:X}, read={args.read_command}"
                        )
                        set_session_command(row, args.session)
                        row["session_counter"] = f"{session_counter:X}"
                        row["pre_read_sequence"] = format_pre_read_sequence(pre_read_sequence)
                        row["delay_ms"] = delay_ms
                        row["read_counter"] = f"{read_counter:X}"
                        set_read_command(row, args.read_command)

                        status, payload, frames, _ = send_tp20_application_request(
                            ser,
                            logger,
                            args.session,
                            counter=session_counter,
                            listen_header=listen_header,
                            timeout=args.timeout,
                            auto_ack=False,
                        )
                        row["session_status"] = status
                        row["session_result"] = payload
                        append_frames(row, frames)
                        if status != "positive":
                            return

                        control_frames = send_pre_read_sequence(ser, logger, pre_read_sequence, args.timeout)
                        wait_frames = collect_passive_frames(
                            ser,
                            logger,
                            delay_ms,
                            f"pre_read_wait_{format_pre_read_sequence(pre_read_sequence)}_{delay_ms}ms",
                            listen_header,
                        )
                        post_frames = control_frames + wait_frames
                        row["post_session_extra_frames"] = frame_dicts(post_frames)
                        append_frames(row, post_frames)

                        if has_disconnect_frame(post_frames, listen_header):
                            row["read_status"] = "disconnect"
                            return

                        read_status, read_payload, read_frames, _ = send_tp20_application_request(
                            ser,
                            logger,
                            args.read_command,
                            counter=read_counter,
                            listen_header=listen_header,
                            timeout=args.timeout,
                            auto_ack=True,
                        )
                        row["read_status"] = read_status
                        row["read_result"] = read_payload
                        append_frames(row, read_frames)

                    rows.append(run_isolated_attempt(args, "pre_read_sweep", attempt_id, operation))
                    last_status = rows[-1].get("read_status")
                    if args.stop_on_read_response and last_status not in {"", "disconnect", "no_response"}:
                        rows[-1]["stopped_early"] = "true"
                        return rows
    return rows


def csv_ready(row: dict[str, object]) -> dict[str, str]:
    ready: dict[str, str] = {}
    for field in SUMMARY_FIELDS:
        value = row.get(field, "")
        if isinstance(value, (list, dict)):
            ready[field] = json.dumps(value, separators=(",", ":"))
        else:
            ready[field] = str(value)
    return ready


def write_summary_files(args: argparse.Namespace, rows: list[dict[str, object]]) -> tuple[Path, Path]:
    args.output_dir.mkdir(parents=True, exist_ok=True)
    base = args.output_dir / f"{args.run_id}_{args.mode}_summary"
    json_path = base.with_suffix(".json")
    csv_path = base.with_suffix(".csv")

    json_path.write_text(json.dumps(rows, indent=2), encoding="utf-8")
    with csv_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=SUMMARY_FIELDS)
        writer.writeheader()
        for row in rows:
            writer.writerow(csv_ready(row))

    return json_path, csv_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Read-only VW TP2.0 sequencing experiments for PQ25 unit 09 / BCM.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python vw_tp20_readonly_probe.py --mode direct_read --port COM10 --read-commands 220600
    python vw_tp20_readonly_probe.py --mode direct_sequence --port COM10 --read-commands 220600,1A9B,1A9A
  python vw_tp20_readonly_probe.py --mode session_sweep --port COM10
  python vw_tp20_readonly_probe.py --mode passive_sniff --port COM10 --session 1089
  python vw_tp20_readonly_probe.py --mode ack_sweep --port COM10 --session 1089 --read-command 1A9B
  python vw_tp20_readonly_probe.py --mode counter_sweep --port COM10 --ack-variants none,B1 --delays-ms 100
  python vw_tp20_readonly_probe.py --mode pre_read_sweep --port COM10 --session 1089 --read-command 1A9B
  python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --session 1089 --ack none --delay-ms 100
    python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --session 1089 --ack none --delay-ms 100 --read-counter 3 --read-commands 1A9B
    python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --session 1089 --ack none --delay-ms 100 --preserve-input-before-read --read-commands 1A9B
  python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --read-profile carista_all
  python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --skip-channel-parameters --read-commands 1A9A
""",
    )
    parser.add_argument(
        "--mode",
        choices=(
            "direct_read",
            "direct_sequence",
            "session_sweep",
            "ack_sweep",
            "counter_sweep",
            "pre_read_sweep",
            "read_sweep",
            "passive_sniff",
        ),
        default="session_sweep",
    )
    parser.add_argument("--port", default=DEFAULT_PORT)
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD)
    parser.add_argument("--timeout", type=float, default=1.8)
    parser.add_argument("--unit", default=DEFAULT_UNIT, type=lambda value: validate_hex(value, "unit"))
    parser.add_argument(
        "--parameter-profile",
        choices=("minimal", "legacy", "carista", "all"),
        default="minimal",
        help="TP2.0 channel parameter attempts. minimal sends only the proven A00F8AFF32FF request.",
    )
    parser.add_argument(
        "--skip-channel-parameters",
        action="store_true",
        help="Open the TP2.0 channel and go straight to data-channel setup/session requests.",
    )
    parser.add_argument("--output-dir", type=Path, default=Path("logs"))
    parser.add_argument("--run-id", default=datetime.now().strftime("vw_tp20_%Y%m%d_%H%M%S"))

    parser.add_argument("--sessions", type=parse_commands, default=SESSION_SWEEP_COMMANDS)
    parser.add_argument("--session", type=lambda value: parse_commands(value)[0], default="1089")
    parser.add_argument("--session-counters", type=parse_counters, default=(0,))
    parser.add_argument("--ack-variants", type=parse_ack_variants, default=ACK_SWEEP_VARIANTS)
    parser.add_argument("--ack", type=parse_ack_variant, default="B1")
    parser.add_argument("--pre-read-sequences", type=parse_pre_read_sequences, default=tuple(parse_pre_read_sequence(value) for value in PRE_READ_SWEEP_SEQUENCES))
    parser.add_argument(
        "--stop-on-read-response",
        action="store_true",
        help="For pre_read_sweep, stop after the first read result that is not empty, no_response, or disconnect.",
    )
    parser.add_argument("--delays-ms", type=parse_delays, default=ACK_SWEEP_DELAYS_MS)
    parser.add_argument("--delay-ms", type=int, default=100)
    parser.add_argument("--read-counters", type=parse_counters, default=(0, 1, 2))
    parser.add_argument(
        "--read-counter",
        type=lambda value: parse_counters(value)[0],
        default=None,
        help="For direct_read, choose the TP2.0 request counter. For read_sweep, override the first post-session counter.",
    )
    parser.add_argument(
        "--preserve-input-before-read",
        action="store_true",
        help="For read_sweep, do not clear the serial input buffer before the first post-session read request.",
    )
    parser.add_argument("--read-command", type=lambda value: parse_commands(value)[0], default="1A9B")
    parser.add_argument(
        "--read-profile",
        type=parse_read_profile,
        choices=tuple(READ_PROFILES),
        default="carista_kwp",
        help="Named read list: carista_kwp, carista_uds, carista_all, or legacy.",
    )
    parser.add_argument("--read-commands", type=parse_commands, default=None, help="Comma-separated read commands; overrides --read-profile.")
    parser.add_argument("--sniff-ms", type=int, default=1000)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    if args.delay_ms < 0 or args.sniff_ms < 0:
        raise SystemExit("Delay and sniff values must be >= 0")

    runners: dict[str, Callable[[argparse.Namespace], list[dict[str, object]]]] = {
        "direct_read": run_direct_read,
        "direct_sequence": run_direct_sequence,
        "session_sweep": run_session_sweep,
        "ack_sweep": run_ack_sweep,
        "counter_sweep": run_counter_sweep,
        "pre_read_sweep": run_pre_read_sweep,
        "read_sweep": run_read_sweep,
        "passive_sniff": run_passive_sniff,
    }
    rows = runners[args.mode](args)
    json_path, csv_path = write_summary_files(args, rows)

    print()
    print(f"Wrote JSON summary: {json_path}")
    print(f"Wrote CSV summary: {csv_path}")
    return 0 if all(not row.get("error") for row in rows) else 2


if __name__ == "__main__":
    raise SystemExit(main())
