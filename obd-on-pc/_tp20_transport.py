"""
Shared ELM327/TP2.0 transport layer for PQ25 BCM live sessions.

Reusable functions used by both the read-only monitor and the write session.
All protocol framing and packet logic comes from CaristaReproduction.
"""
from __future__ import annotations

import re
import time
from pathlib import Path

import serial

from CaristaReproduction.VagCanCommunicator import (
    CARISTA_CHANNEL_PARAMETER_ATTEMPTS,
    CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS,
    CARISTA_FINAL_FRAME_ST,
    CARISTA_NON_FINAL_FRAME_ST,
    CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT,
    CARISTA_TP20_OPEN_REQUEST_ATTEMPTS,
    ackForReceivedPacket,
    expectedTransmitAck,
    findTransmitAcks,
    generateOutgoingPackets,
    interFramePauseSeconds,
    isTransmitAck,
    next_counter_after_request,
    readResponses,
)
from CaristaReproduction.ReadValuesOperationBuilder import (
    CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
    CARISTA_TP20_EXPECTED_LISTEN_HEADER,
    CARISTA_TP20_EXPECTED_SEND_HEADER,
    CARISTA_TP20_UNIT_09_OPEN_REQUEST,
    POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST,
)

LISTEN_HEADER = CARISTA_TP20_EXPECTED_LISTEN_HEADER
SEND_HEADER = CARISTA_TP20_EXPECTED_SEND_HEADER
TP20_INTER_FRAME_MINIMUM_MS = 130
TP20_LIVE_RESPONSE_FRAME_ST = "ATST32"
_HEX_RE = re.compile(r"^[0-9A-Fa-f]+$")


def read_until_prompt(ser: serial.Serial, timeout: float) -> str:
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


def elm_send(ser: serial.Serial, cmd: str, timeout: float = 2.0, pause: float = 0.05) -> str:
    ser.reset_input_buffer()
    ser.write((cmd + "\r").encode("ascii"))
    time.sleep(pause)
    return read_until_prompt(ser, timeout)


def init_elm(ser: serial.Serial) -> None:
    print("[elm] initializing adapter")
    for cmd in ("ATZ", "ATE0", "ATL0", "ATS0", "ATH1", "ATCAF0", "ATV1", "ATAL", "ATSP6"):
        raw = elm_send(ser, cmd, timeout=3.0, pause=0.25)
        print(f"  {cmd}: {raw.strip()!r}")
    print()


def parse_frames(raw: str, header: str) -> list[str]:
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


def is_data_frame(frame: str) -> bool:
    return not isTransmitAck(frame) and frame.upper() not in ("A3", "A8")


def has_final_data_frame(frames: list[str]) -> bool:
    return any(frame.startswith("1") for frame in frames)


def collect_more_frames(ser: serial.Serial, request: str, timeout: float = 2.0) -> list[str]:
    elm_send(ser, f"ATSH{SEND_HEADER}", pause=0.05)
    raw = elm_send(ser, request, timeout=timeout)
    frames = parse_frames(raw, LISTEN_HEADER)
    return [frame for frame in frames if is_data_frame(frame)]


def tp20_open(ser: serial.Serial) -> tuple[str, int | None]:
    """
    Open a TP2.0 channel to BCM unit 20.
    Returns (channel_param_used, t3_ms_or_None).
    Raises RuntimeError if channel cannot be opened.
    """
    print("[tp20] opening channel to unit 20")

    def configure_for_open() -> None:
        for cmd in ("ATSP6", "ATCAF0", "ATV1", "ATAR", "ATSH200", "ATST0A"):
            elm_send(ser, cmd, pause=0.1)

    def try_channel_parameters(param_request: str) -> tuple[str, int | None] | None:
        for param_attempt in range(CARISTA_CHANNEL_PARAMETER_ATTEMPTS):
            for cmd in ("ATST32", f"ATSH{SEND_HEADER}"):
                elm_send(ser, cmd, pause=0.1)
            raw = elm_send(ser, param_request, timeout=2.0)
            frames = parse_frames(raw, LISTEN_HEADER)
            a1_frames = [f for f in frames if f.upper().startswith("A1")]
            if a1_frames:
                a1 = a1_frames[0]
                parsed_t3_ms = int(a1[8:10], 16) if len(a1) >= 12 else None
                print(
                    "  channel params ok: "
                    f"{a1}  T3={parsed_t3_ms}ms  request={param_request}  attempt={param_attempt + 1}"
                )
                return param_request, parsed_t3_ms
            print(f"  channel params miss: request={param_request} attempt={param_attempt + 1}")
            time.sleep(0.05)
        return None

    used_param: str | None = None
    t3_ms: int | None = None
    last_open_raw = ""
    for outer_attempt in range(CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS):
        configure_for_open()
        opened = False
        for open_attempt in range(CARISTA_TP20_OPEN_REQUEST_ATTEMPTS):
            raw = elm_send(ser, CARISTA_TP20_UNIT_09_OPEN_REQUEST, timeout=3.0)
            last_open_raw = raw
            frames = parse_frames(raw, "220")
            if any(f.startswith("00D") for f in frames):
                opened = True
                print(
                    "  channel open: "
                    f"send={SEND_HEADER} listen={LISTEN_HEADER} "
                    f"outer_attempt={outer_attempt + 1} open_attempt={open_attempt + 1}"
                )
                break
            print(f"  channel open miss: outer_attempt={outer_attempt + 1} open_attempt={open_attempt + 1}")
            time.sleep(0.05)
        if not opened:
            continue

        for param_request in (POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST, CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST):
            result = try_channel_parameters(param_request)
            if result is None:
                continue
            used_param, t3_ms = result
            break
        if used_param is not None:
            break

        elm_send(ser, f"ATSH{SEND_HEADER}", pause=0.05)
        elm_send(ser, "A8", timeout=1.0)
        time.sleep(0.1)

    if used_param is None:
        raise RuntimeError(f"TP2.0 channel setup failed after Carista-shaped retries; last open response: {last_open_raw!r}")

    elm_send(ser, f"ATCRA{LISTEN_HEADER}", pause=0.1)

    pause_s = interFramePauseSeconds(t3_ms, TP20_INTER_FRAME_MINIMUM_MS)
    print(f"  inter-frame pause: {pause_s*1000:.0f}ms")
    return used_param, t3_ms


def tp20_close(ser: serial.Serial) -> None:
    elm_send(ser, f"ATSH{SEND_HEADER}", pause=0.05)
    elm_send(ser, "A8", timeout=1.0)
    for cmd in ("ATSP6", "ATCAF1", "ATV0"):
        elm_send(ser, cmd, pause=0.05)
    print("[tp20] channel closed")


def tp20_request(
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

    for packet in packets[:-1]:
        elm_send(ser, CARISTA_NON_FINAL_FRAME_ST, pause=0.05)
        elm_send(ser, packet.raw, timeout=0.5)
        time.sleep(pause_s)

    elm_send(ser, TP20_LIVE_RESPONSE_FRAME_ST, pause=0.05)
    raw = elm_send(ser, packets[-1].raw, timeout=3.0)
    frames = parse_frames(raw, LISTEN_HEADER)

    tx_acks = findTransmitAcks(frames)
    if expected_ack.upper() in [a.upper() for a in tx_acks]:
        print(f"{tag}transmit ACK matched {expected_ack}")
    else:
        print(f"{tag}WARNING: transmit ACK {expected_ack} not seen in {frames}")

    data_frames = [f for f in frames if is_data_frame(f)]

    receive_more_attempts = 0
    while data_frames and not has_final_data_frame(data_frames):
        last = data_frames[-1]
        ack = ackForReceivedPacket(last)
        if ack is None:
            break
        more_data = collect_more_frames(ser, ack)
        if not more_data and receive_more_attempts < CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT:
            receive_more_attempts += 1
            more_data = collect_more_frames(ser, "A3")
        if not more_data:
            break
        data_frames.extend(more_data)

    final_ack: str | None = None
    for frame in reversed(data_frames):
        candidate = ackForReceivedPacket(frame)
        if candidate is not None:
            final_ack = candidate
            break

    if final_ack:
        elm_send(ser, f"ATSH{SEND_HEADER}", pause=0.05)
        elm_send(ser, final_ack, timeout=1.5)
        print(f"{tag}sent inbound ACK {final_ack}")

    payload = readResponses(data_frames)
    print(f"{tag}payload={payload or '(none)'}")
    return payload, next_counter


def read_did_one_shot(ser: serial.Serial, did: int) -> str | None:
    """Read one DID by opening a fresh TP2.0 channel, reading, and closing."""
    from CaristaReproduction.Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
    _, t3_ms = tp20_open(ser)
    try:
        request = ReadDataByIdentifierCommand_getRequest(did)
        payload, _ = tp20_request(ser, 0, request, t3_ms, label=request)
        return payload
    finally:
        tp20_close(ser)
