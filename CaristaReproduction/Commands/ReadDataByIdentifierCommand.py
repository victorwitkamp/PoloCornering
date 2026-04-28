from __future__ import annotations

from dataclasses import dataclass

from ..ByteUtils import clean_hex
from ..Result import Result
from ..State import State
from ..Types import HexString, UdsDid


def validate_did(did: int) -> UdsDid:
    if not 0 <= did <= 0xFFFF:
        raise ValueError("DID must fit in two bytes")
    return did


@dataclass(frozen=True)
class ReadDataByIdentifierCommand:
    did: UdsDid

    def getRequest(self) -> HexString:
        return ReadDataByIdentifierCommand_getRequest(self.did)

    @staticmethod
    def processPayload(payload: HexString) -> Result[HexString]:
        return ReadDataByIdentifierCommand_processPayload(payload)


def ReadDataByIdentifierCommand_getRequest(did: int) -> HexString:
    did = validate_did(did)
    return f"22{did:04X}"


def ReadDataByIdentifierCommand_processPayload(payload: HexString) -> Result[HexString]:
    payload = clean_hex(payload, "ReadDataByIdentifier payload")
    if not payload:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    return Result.done(payload)


ReadDataByIdentifierCommand_Bytes_getRequest = ReadDataByIdentifierCommand_getRequest