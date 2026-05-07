from __future__ import annotations

from dataclasses import dataclass

from ..ByteUtils import clean_hex
from ..Result import Result
from ..State import State
from ..Types import HexString


@dataclass(frozen=True)
class GetVagUdsSubmoduleIdsCommand:
    @staticmethod
    def processPayload(payload: HexString) -> Result[tuple[int, ...]]:
        return GetVagUdsSubmoduleIdsCommand_processPayload(payload)


def GetVagUdsSubmoduleIdsCommand_processPayload(payload: HexString) -> Result[tuple[int, ...]]:
    payload = clean_hex(payload, "GetVagUdsSubmoduleIdsCommand payload")
    data = bytes.fromhex(payload)
    if len(data) < 2 or len(data) % 2 != 0:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)

    submodule_ids: list[int] = []
    for index in range(1, len(data), 2):
        low_byte = data[index]
        if low_byte != 0 and data[index - 1] == 0:
            submodule_ids.append(low_byte)
    return Result.done(tuple(submodule_ids))