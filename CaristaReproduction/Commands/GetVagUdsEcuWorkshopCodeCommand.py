from __future__ import annotations

from dataclasses import dataclass

from ..Constants import CARISTA_WORKSHOP_CODE_READ_DID
from ..ByteUtils import clean_hex
from ..Result import Result
from ..State import State
from ..Types import HexString
from .ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest


@dataclass(frozen=True)
class GetVagUdsEcuWorkshopCodeCommand:
    did: int = CARISTA_WORKSHOP_CODE_READ_DID

    def getRequest(self) -> HexString:
        return GetVagUdsEcuWorkshopCodeCommand_getRequest()

    @staticmethod
    def processPayload(payload: HexString) -> Result[HexString]:
        return GetVagUdsEcuWorkshopCodeCommand_processPayload(payload)


def GetVagUdsEcuWorkshopCodeCommand_getRequest() -> HexString:
    return ReadDataByIdentifierCommand_getRequest(CARISTA_WORKSHOP_CODE_READ_DID)


def GetVagUdsEcuWorkshopCodeCommand_processPayload(payload: HexString) -> Result[HexString]:
    payload = clean_hex(payload, "GetVagUdsEcuWorkshopCodeCommand payload")
    if len(payload) // 2 != 6:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    return Result.done(payload)