from __future__ import annotations

from typing import Protocol, runtime_checkable

from ..ByteUtils import clean_hex
from ..Result import Result
from ..State import State
from ..Types import HexString


OPT_RETRIABLE = 3

_NRC_TO_STATE: dict[int, int] = {
    0x10: State.OBD2_GENERAL_REJECT,
    0x11: State.OBD2_SERVICE_NOT_SUPPORTED,
    0x12: State.OBD2_SUBFUNCTION_NOT_SUPPORTED,
    0x13: State.OBD2_INCORRECT_MESSAGE_LENGTH_OR_FORMAT,
    0x21: State.OBD2_BUSY_REPEAT_REQUEST,
    0x22: State.OBD2_CONDITIONS_NOT_CORRECT,
    0x24: State.OBD2_REQUEST_SEQUENCE_ERROR,
    0x31: State.OBD2_REQUEST_OUT_OF_RANGE,
    0x33: State.OBD2_SECURITY_ACCESS_DENIED,
    0x35: State.OBD2_INVALID_KEY,
    0x36: State.OBD2_EXCEEDED_NUMBER_OF_ATTEMPTS,
    0x37: State.OBD2_REQUIRED_TIME_DELAY_NOT_EXPIRED,
    0x78: State.RESPONSE_PENDING,
    0x7E: State.OBD2_SUBFUNCTION_NOT_SUPPORTED_IN_ACTIVE_SESSION,
    0x7F: State.OBD2_SUBFUNCTION_NOT_SUPPORTED_IN_ACTIVE_SESSION,
    0x80: State.OBD2_UPLOAD_DOWNLOAD_NOT_ACCEPTED,
    0x81: -29,
    0x83: -29,
    0x84: State.OBD2_RESPONSE_TOO_LONG,
    0x88: -30,
}

_NRC_TO_NAME: dict[int, str] = {
    0x10: "generalReject",
    0x11: "serviceNotSupported",
    0x12: "subFunctionNotSupported",
    0x13: "incorrectMessageLengthOrInvalidFormat",
    0x21: "busyRepeatRequest",
    0x22: "conditionsNotCorrect",
    0x24: "requestSequenceError",
    0x31: "requestOutOfRange",
    0x33: "securityAccessDenied",
    0x35: "invalidKey",
    0x36: "exceededNumberOfAttempts",
    0x37: "requiredTimeDelayNotExpired",
    0x78: "responsePending",
    0x7E: "subFunctionNotSupportedInActiveSession",
    0x7F: "subFunctionNotSupportedInActiveSession",
    0x80: "uploadDownloadNotAccepted",
    0x84: "responseTooLong",
}


@runtime_checkable
class BaseCommand(Protocol):
    def getRequest(self) -> HexString:
        ...


def response_marker(command: HexString) -> HexString:
    normalized = clean_hex(command, "command")
    service = int(normalized[:2], 16)
    return f"{service + 0x40:02X}{normalized[2:]}"


def BaseCommand_extractState(payload: HexString) -> int:
    payload = clean_hex(payload, "response payload")
    raw = bytes.fromhex(payload)
    if len(raw) < 3 or raw[0] != 0x7F:
        return State.DONE
    return _NRC_TO_STATE.get(raw[2], -10)


def BaseCommand_describeNegativePayload(payload: HexString) -> str:
    payload = clean_hex(payload, "response payload")
    if not payload.startswith("7F") or len(payload) < 6:
        return payload
    service = payload[2:4]
    code = int(payload[4:6], 16)
    code_text = _NRC_TO_NAME.get(code, "unknownNegativeResponse")
    return f"{payload} service=0x{service} nrc=0x{code:02X} ({code_text})"


def BaseCommand_filterOutErrors(payloads: list[HexString]) -> Result[list[HexString]]:
    clean_payloads: list[HexString] = []
    state = State.EMPTY_OR_INVALID_RESPONSE
    for payload in payloads:
        extracted_state = BaseCommand_extractState(payload)
        if extracted_state == State.DONE:
            clean_payloads.append(clean_hex(payload, "response payload"))
        elif state != State.OBD2_BUSY_REPEAT_REQUEST:
            state = extracted_state
    if not clean_payloads:
        return Result.fail(state)
    return Result.done(clean_payloads)


def BaseCommand_isPositiveUSDTResponse(request: HexString, response: HexString, echo_len: int) -> bool:
    request = clean_hex(request, "request")
    response = clean_hex(response, "response")
    if echo_len < 1:
        raise ValueError("echo_len must be positive")
    request_bytes = bytes.fromhex(request)
    expected = bytes((request_bytes[0] + 0x40,)) + request_bytes[1:echo_len]
    return response.startswith(expected.hex().upper())


def BaseCommand_isPositiveResponse(request: HexString, response: HexString, echo_len: int) -> bool:
    return BaseCommand_isPositiveUSDTResponse(request, response, echo_len)


def BaseCommand_removeEcho(request: HexString, response: HexString, echo_len: int) -> Result[HexString]:
    response = clean_hex(response, "response")
    if not BaseCommand_isPositiveResponse(request, response, echo_len):
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    return Result.done(response[echo_len * 2:])
