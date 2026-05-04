from __future__ import annotations

from dataclasses import dataclass
from enum import IntEnum
from typing import Iterable

from .ByteUtils import clean_hex
from .Types import HexString


CARISTA_NON_FINAL_FRAME_ST = "ATST04"
CARISTA_FINAL_FRAME_ST = "ATST20"
CARISTA_TX_ACK_RETRIES = 2
CARISTA_TX_ACK_RETRY_DELAY_SECONDS = 0.05
CARISTA_NATIVE_T3_MS = 0x82
CARISTA_CHANNEL_REOPEN_DELAY_MS = 1000


class VagCanCommunicator:
    class OpCode(IntEnum):
        CONTINUATION = 0x20
        FINAL = 0x10
        ACK = 0xB0
        ACK_WAIT = 0x90
        KEEP_ALIVE = 0xA3
        DISCONNECT = 0xA8

    @dataclass(frozen=True)
    class VagCanPacket:
        raw: HexString
        sequence: int
        op_code: "VagCanCommunicator.OpCode"

        @property
        def is_final(self) -> bool:
            return self.op_code == VagCanCommunicator.OpCode.FINAL

    @staticmethod
    def generateOutgoingPackets(counter: int, request: HexString) -> list["VagCanCommunicator.VagCanPacket"]:
        return generateOutgoingPackets(counter, request)

    @staticmethod
    def getSeqNum(counter: int, packet_count: int) -> int:
        return nextSeqNum(counter, packet_count)

    @staticmethod
    def expectedTransmitAck(next_counter: int) -> HexString:
        return expectedTransmitAck(next_counter)

    @staticmethod
    def ackForReceivedPacket(raw_packet: HexString) -> HexString | None:
        return ackForReceivedPacket(raw_packet)

    @staticmethod
    def isTransmitAck(raw_packet: HexString) -> bool:
        return isTransmitAck(raw_packet)

    @staticmethod
    def findTransmitAcks(raw_packets: Iterable[HexString]) -> list[HexString]:
        return findTransmitAcks(raw_packets)

    @staticmethod
    def interFramePauseSeconds(t3_ms: int | None, minimum_ms: int) -> float:
        return interFramePauseSeconds(t3_ms, minimum_ms)


def generateOutgoingPackets(counter: int, request: HexString) -> list[VagCanCommunicator.VagCanPacket]:
    payload = bytes.fromhex(clean_hex(request, "application command"))
    if not payload:
        raise ValueError("empty application payload")
    if len(payload) <= 5:
        return [
            VagCanCommunicator.VagCanPacket(
                raw=f"1{counter:X}{len(payload):04X}{payload.hex().upper()}",
                sequence=counter & 0xF,
                op_code=VagCanCommunicator.OpCode.FINAL,
            )
        ]

    packets = [
        VagCanCommunicator.VagCanPacket(
            raw=f"2{counter:X}{len(payload):04X}{payload[:5].hex().upper()}",
            sequence=counter & 0xF,
            op_code=VagCanCommunicator.OpCode.CONTINUATION,
        )
    ]
    sequence = (counter + 1) & 0xF
    chunks = [payload[offset:offset + 7] for offset in range(5, len(payload), 7)]
    for index, chunk in enumerate(chunks):
        is_final = index == len(chunks) - 1
        opcode = "1" if is_final else "2"
        packets.append(
            VagCanCommunicator.VagCanPacket(
                raw=f"{opcode}{sequence:X}{chunk.hex().upper()}",
                sequence=sequence,
                op_code=VagCanCommunicator.OpCode.FINAL if is_final else VagCanCommunicator.OpCode.CONTINUATION,
            )
        )
        sequence = (sequence + 1) & 0xF
    return packets


def nextSeqNum(counter: int, packet_count: int) -> int:
    return (counter + packet_count) & 0xF


def next_counter_after_packets(counter: int, packets: list[VagCanCommunicator.VagCanPacket]) -> int:
    return nextSeqNum(counter, len(packets))


def next_counter_after_request(counter: int, request: HexString) -> int:
    return next_counter_after_packets(counter, generateOutgoingPackets(counter, request))


def expectedTransmitAck(next_counter: int) -> HexString:
    return f"B{next_counter & 0xF:X}"


def ackForReceivedPacket(raw_packet: HexString) -> HexString | None:
    packet = clean_hex(raw_packet, "VagCanPacket")
    if len(packet) < 2:
        return None
    frame_type = packet[0]
    if frame_type not in {"0", "1"}:
        return None
    try:
        sequence = int(packet[1], 16)
    except ValueError:
        return None
    return f"B{(sequence + 1) & 0xF:X}"


def isTransmitAck(raw_packet: HexString) -> bool:
    packet = clean_hex(raw_packet, "VagCanPacket")
    return len(packet) == 2 and packet[0] == "B" and packet[1] in "0123456789ABCDEF"


def findTransmitAcks(raw_packets: Iterable[HexString]) -> list[HexString]:
    return [clean_hex(packet, "VagCanPacket") for packet in raw_packets if isTransmitAck(packet)]


def interFramePauseSeconds(t3_ms: int | None, minimum_ms: int) -> float:
    candidates = [minimum_ms]
    if t3_ms is not None and 0 < t3_ms < 0xFF:
        candidates.append(t3_ms)
    return max(candidates) / 1000.0