from __future__ import annotations

from dataclasses import dataclass

from ..ByteUtils import clean_hex
from ..Result import Result
from ..State import State
from ..Types import HexString, UdsDid
from .BaseCommand import BaseCommand_extractState, response_marker


def validate_did(did: int) -> UdsDid:
    if not 0 <= did <= 0xFFFF:
        raise ValueError(f"DID must fit in 16 bits, got {did}")
    return did


@dataclass(frozen=True)
class WriteDataByIdentifierCommand:
    did: UdsDid
    payload: HexString

    def getRequest(self) -> HexString:
        return WriteDataByIdentifierCommand_getRequest(self.did, self.payload)

    @staticmethod
    def processPayload(payload: HexString) -> Result[None]:
        return WriteDataByIdentifierCommand_processPayload(payload)


def WriteDataByIdentifierCommand_getRequest(did: int, payload: HexString) -> HexString:
    did = validate_did(did)
    payload = clean_hex(payload, "WriteDataByIdentifier payload")
    return f"2E{did:04X}{payload}"


def WriteDataByIdentifierCommand_positiveResponseMarker(request: HexString) -> HexString:
    request = clean_hex(request, "WriteDataByIdentifier request")
    if request.startswith("2E") and len(request) >= 6:
        return f"6E{request[2:6]}"
    return response_marker(request)


def WriteDataByIdentifierCommand_processPayload(payload: HexString) -> Result[None]:
    payload = clean_hex(payload, "WriteDataByIdentifier response payload")
    if not payload:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    state = BaseCommand_extractState(payload)
    if state != State.DONE:
        return Result.fail(state)
    return Result.done()