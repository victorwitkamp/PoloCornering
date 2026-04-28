from __future__ import annotations

from dataclasses import dataclass

from ..ByteUtils import clean_hex
from ..Result import Result
from ..Types import HexString, UdsDid


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


def WriteDataByIdentifierCommand_processPayload(payload: HexString) -> Result[None]:
    clean_hex(payload, "WriteDataByIdentifier response payload")
    return Result.done()