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
CARISTA_RECEIVE_MORE_TIMEOUT_SPEC = 0x200
CARISTA_MIN_ELM_VERSION = 0x8C
CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS = 2
CARISTA_TP20_OPEN_REQUEST_ATTEMPTS = 4
CARISTA_CHANNEL_PARAMETER_ATTEMPTS = 4
CARISTA_CHANNEL_OPEN_WAIT_MS = 2000
CARISTA_READ_RESPONSES_NEGATIVE_RESPONSE_LIMIT = 0x1E
CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT = 2
CARISTA_READ_RESPONSES_OLD_SEQUENCE_DISTANCE = 7

VAG_CAN_COMMUNICATOR_RECEIVE_RECOVERED_FLOW = (
    "VagCanCommunicator::receive calls Communicator::readResponses and appends the returned packet list to receivedPackets at this+0x1C.",
)
VAG_CAN_COMMUNICATOR_RECEIVE_MORE_RECOVERED_FLOW = (
    "VagCanCommunicator::receiveMore sets adapter timeout/spec to 0x200.",
    "It sends one TP2.0 keep-alive/request-more packet A3 through the adapter send slot.",
    "It immediately calls VagCanCommunicator::receive to append any returned packets.",
)
VAG_CAN_COMMUNICATOR_PARSE_PACKET_RECOVERED_FLOW = (
    "VagCanCommunicator::parsePacket reads a three-hex-digit CAN header, then one TP2.0 opcode byte, then payload bytes.",
    "Sequenced opcodes use high nibbles 0x0, 0x1, 0x2, 0x3, 0x9, 0xA, and 0xB; the low nibble is the TP2.0 sequence.",
    "Unsequenced native branches accept high nibbles 0xC and 0xD with sequence zero; other opcode classes set TRANSPORT_LAYER_ERROR.",
    "The bool parameter enables an additional strict length-validation branch before constructing the parsed VagCanPacket.",
)
VAG_CAN_COMMUNICATOR_READ_RESPONSES_RECOVERED_FLOW = (
    "VagCanCommunicator::readResponses throws IllegalStateException if receivedPackets at this+0x1C is non-empty on entry.",
    "It calls receive(), then loops over status-1 Communicator packets and parses each packet through VagCanCommunicator::parsePacket.",
    "It gives up and terminates the connection when consecutive negative responses exceed 0x1E.",
    "When no new packets arrive and the assembled buffer has not grown, it calls receiveMore() up to two times before terminating.",
    "It ignores A3 keep-alives, handles A8 as channel-disconnected, and clears receivedPackets before ACK_WAIT/NACK or disconnect paths.",
    "Old sequence numbers are dropped using VagCanCommunicator::isOldSeqNum(seq, lastSeen) unless the 7F xx 78 hack is enabled.",
    "Unexpected next sequence logs the mismatch and sends sendNack(expectedSeq), which is the ACK_WAIT opcode 0x90 path.",
    "Application payload chunks are concatenated, the first two bytes provide a 12-bit length, and the DONE result is the subrange after that length prefix.",
)
VAG_CAN_COMMUNICATOR_READ_RESPONSES_DYNAMIC_EVIDENCE = (
    "Offline replay over 69 saved summary JSON files / 364 records found 95 positive read records.",
    "All 95 positive records reassemble exactly to read_result using the native length-prefixed TP2.0 payload rule.",
    "All 95 inbound transmit ACKs matched B{outgoingCounter+1}; saved text logs also contain 35 outbound B? ACK commands.",
    "Observed positive response sequence patterns were (0,1), (0,1,2), (0,1,2,3,4), and (0), matching native chunk concatenation before final extraction.",
)
VAG_CAN_COMMUNICATOR_POST_INITIALIZE_RECOVERED_FLOW = (
    "VagCanCommunicator::postInitialize skips extra VAG CAN setup when DeviceLatestInfo::isDefective is true.",
    "It logs additional ELM initialization, then calls adapter wrapper vtable offsets 0x30(1), 0x90(0), and 0x98(0).",
    "If adapter version is at least 0x8C, it also calls offsets 0x38(6), 0xF4(0), 0xF0(1), and 0x8C().",
    "It then branches on offsets 0x124()/0x128() to one of the wrapper slots 0xB0 or 0xC0 with argument 0.",
)
VAG_CAN_COMMUNICATOR_ESTABLISH_ECU_COMM_RECOVERED_FLOW = (
    "VagCanCommunicator::establishEcuComm aborts when DeviceLatestInfo::isDefective is true or ELM version is below 0x8C.",
    "It builds the TP2.0 open request from the ECU unit byte as unit C0 00 10 00 03 01 and stores T1/T3-related 0x0F00 state.",
    "It uses two outer channel-open attempts; each attempt sets adapter timeout/spec 0x40 and then 0x200 plus the unit-derived listen value.",
    "Each outer attempt sends the open request up to four times and filters readResponses to status 1 before parsing packets.",
    "Open-channel responses supply the data-channel send/listen headers from response bytes before channel-parameter setup.",
    "If the ECU asks to wait during open, Carista sleeps 2000 ms before continuing packet parsing.",
    "Channel parameters are sent up to four times and success is recognized by parsed opcode A1; failure sends VagCanCommunicator::sendDisconnect.",
)
VAG_CAN_COMMUNICATOR_GET_TIMEOUT_SPEC_RECOVERED_FLOW = (
    "VagCanCommunicator::getTimeoutSpec lazily constructs a static Communicator::TimeoutSpec(0, vector{0}, 0).",
)


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
    def incrementSeqNum(sequence: int) -> int:
        return incrementSeqNum(sequence)

    @staticmethod
    def isOldSeqNum(sequence: int, last_seen_sequence: int) -> bool:
        return isOldSeqNum(sequence, last_seen_sequence)

    @staticmethod
    def interFramePauseSeconds(t3_ms: int | None, minimum_ms: int) -> float:
        return interFramePauseSeconds(t3_ms, minimum_ms)

    @staticmethod
    def receive() -> tuple[str, ...]:
        return VAG_CAN_COMMUNICATOR_RECEIVE_RECOVERED_FLOW

    @staticmethod
    def receiveMore() -> tuple[str, ...]:
        return VAG_CAN_COMMUNICATOR_RECEIVE_MORE_RECOVERED_FLOW

    @staticmethod
    def parsePacket() -> tuple[str, ...]:
        return VAG_CAN_COMMUNICATOR_PARSE_PACKET_RECOVERED_FLOW

    @staticmethod
    def readResponses() -> tuple[str, ...]:
        return VAG_CAN_COMMUNICATOR_READ_RESPONSES_RECOVERED_FLOW

    @staticmethod
    def sendAck(sequence: int, receive_after_send: bool = False) -> HexString:
        return sendAck(sequence, receive_after_send)

    @staticmethod
    def sendNack(sequence: int) -> HexString:
        return sendNack(sequence)

    @staticmethod
    def postInitialize() -> tuple[str, ...]:
        return VAG_CAN_COMMUNICATOR_POST_INITIALIZE_RECOVERED_FLOW

    @staticmethod
    def establishEcuComm() -> tuple[str, ...]:
        return VAG_CAN_COMMUNICATOR_ESTABLISH_ECU_COMM_RECOVERED_FLOW

    @staticmethod
    def getTimeoutSpec() -> tuple[str, ...]:
        return VAG_CAN_COMMUNICATOR_GET_TIMEOUT_SPEC_RECOVERED_FLOW


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


def incrementSeqNum(sequence: int) -> int:
    return (sequence + 1) & 0xF


def isOldSeqNum(sequence: int, last_seen_sequence: int) -> bool:
    sequence &= 0xF
    last_seen_sequence &= 0xF
    if sequence <= last_seen_sequence:
        sequence += 0xF
    return sequence - last_seen_sequence > CARISTA_READ_RESPONSES_OLD_SEQUENCE_DISTANCE


def next_counter_after_packets(counter: int, packets: list[VagCanCommunicator.VagCanPacket]) -> int:
    return nextSeqNum(counter, len(packets))


def next_counter_after_request(counter: int, request: HexString) -> int:
    return next_counter_after_packets(counter, generateOutgoingPackets(counter, request))


def expectedTransmitAck(next_counter: int) -> HexString:
    return f"B{next_counter & 0xF:X}"


def sendAck(sequence: int, receive_after_send: bool = False) -> HexString:
    return f"B{(sequence + 1) & 0xF:X}"


def sendNack(sequence: int) -> HexString:
    return f"9{sequence & 0xF:X}"


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