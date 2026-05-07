from __future__ import annotations

from dataclasses import dataclass

from ..ByteUtils import clean_hex
from ..Result import Result
from ..State import State
from ..Types import HexString


@dataclass(frozen=True)
class GetSubmoduleIdsOverUdsCommand:
    @staticmethod
    def processPayload(payload: HexString) -> Result[tuple[int, ...]]:
        return GetSubmoduleIdsOverUdsCommand_processPayload(payload)


def GetSubmoduleIdsOverUdsCommand_addSubmodulesIdsToResult(
    result: list[int],
    submodule_id_bitmap: bytes,
    high_bank: bool,
) -> None:
    for bit_index in range(len(submodule_id_bitmap) * 8):
        byte_value = submodule_id_bitmap[bit_index >> 3]
        if (byte_value << (bit_index & 0x07)) & 0x80:
            result.append(bit_index | (0x80 if high_bank else 0x00))


def GetSubmoduleIdsOverUdsCommand_processPayload(payload: HexString) -> Result[tuple[int, ...]]:
    payload = clean_hex(payload, "GetSubmoduleIdsOverUdsCommand payload")
    data = bytes.fromhex(payload)
    if len(data) != 0x0C:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)

    submodule_ids: list[int] = []
    GetSubmoduleIdsOverUdsCommand_addSubmodulesIdsToResult(submodule_ids, data[:6], False)
    GetSubmoduleIdsOverUdsCommand_addSubmodulesIdsToResult(submodule_ids, data[6:], True)
    return Result.done(tuple(submodule_ids))