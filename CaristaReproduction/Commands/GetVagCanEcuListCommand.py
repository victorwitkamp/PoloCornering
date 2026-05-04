from __future__ import annotations

from ..Types import HexString


class GetVagCanEcuListCommand:
    def getRequest(self) -> HexString:
        return GetVagCanEcuListCommand_getRequest()


def GetVagCanEcuListCommand_getRequest() -> HexString:
    return "1A9F"
