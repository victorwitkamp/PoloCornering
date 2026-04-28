from __future__ import annotations

from ..Types import HexString
from ..VagCoding import ReadVagCanLongCodingCommand_processLongCoding


class ReadVagCanLongCodingCommand:
    def getRequest(self) -> HexString:
        return ReadVagCanLongCodingCommand_getRequest()

    @staticmethod
    def processLongCoding(response: HexString) -> HexString | None:
        return ReadVagCanLongCodingCommand_processLongCoding(response)


def ReadVagCanLongCodingCommand_getRequest() -> HexString:
    return "1A9A"