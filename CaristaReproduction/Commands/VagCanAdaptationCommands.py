from __future__ import annotations

from ..ByteUtils import clean_hex
from ..Result import Result
from ..State import State
from ..Types import HexString


READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID = 0x0103
READ_VAG_CAN_LONG_ADAPTATION_BASIC_ID = 0x010A


def _short_be(value: int, label: str) -> HexString:
    if not 0 <= value <= 0xFFFF:
        raise ValueError(f"{label} must fit in two bytes")
    return f"{value:04X}"


def _channel_byte(value: int) -> HexString:
    if not 0 <= value <= 0xFF:
        raise ValueError("adaptation channel must fit in one byte")
    return f"{value:02X}"


def _strip_adaptation_positive_prefix(payload: HexString) -> HexString:
    cleaned = clean_hex(payload, "adaptation response payload")
    if cleaned.startswith("71BA") and len(cleaned) >= 8:
        return cleaned[8:]
    return cleaned


def StartReadVagCanRoutineCommand_getRequest(basic_id: int) -> HexString:
    return "31B8" + _short_be(basic_id, "routine id")


def StopReadVagCanRoutineCommand_getRequest(basic_id: int) -> HexString:
    return "32B8" + _short_be(basic_id, "routine id")


def PreReadVagCanAdaptationDataCommand_getRequest(basic_id: int) -> HexString:
    return "31BA" + _short_be(basic_id, "adaptation basic id")


def ReadVagCanAdaptationDataCommand_getRequest(basic_id: int) -> HexString:
    return "31BA" + _short_be(basic_id, "adaptation basic id")


def SetVagCanAdaptationChannelCommand_getRequest(basic_id: int, channel: int) -> HexString:
    return "31B9" + _short_be(basic_id, "adaptation basic id") + _channel_byte(channel)


def ReadVagCanShortAdaptationDataCommand_getRequest() -> HexString:
    return ReadVagCanAdaptationDataCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID)


def ReadVagCanLongAdaptationDataCommand_getRequest() -> HexString:
    return ReadVagCanAdaptationDataCommand_getRequest(READ_VAG_CAN_LONG_ADAPTATION_BASIC_ID)


def PreReadVagCanAdaptationDataCommand_processPayload(payload: HexString) -> Result[None]:
    data = bytes.fromhex(_strip_adaptation_positive_prefix(payload))
    return Result.done() if data == b"\x81" else Result.fail(State.EMPTY_OR_INVALID_RESPONSE)


def ReadVagCanShortAdaptationDataCommand_processPayload(payload: HexString) -> Result[HexString]:
    data = bytes.fromhex(_strip_adaptation_positive_prefix(payload))
    if len(data) < 4 or data[0] not in (0x82, 0x05):
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    return Result.done(data[2:4].hex().upper())


def ReadVagCanLongAdaptationDataCommand_processPayload(payload: HexString) -> Result[HexString]:
    data = bytes.fromhex(_strip_adaptation_positive_prefix(payload))
    if len(data) <= 2:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    length = data[0]
    if length > len(data) - 3:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    return Result.done(data[3 : 3 + max(0, length - 1)].hex().upper())