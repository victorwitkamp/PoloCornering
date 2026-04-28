from __future__ import annotations

from dataclasses import dataclass
from ..Types import HexString


@dataclass(frozen=True)
class RecoveredRequestBuilders:
    GetVagCanEcuInfoCommand_getRequest: HexString
    ReadVagCanLongCodingCommand_getRequest: HexString
    ReadDataByIdentifierCommand_getRequest_F1A5: HexString
    GetVagUdsEcuWorkshopCodeCommand_getRequest: HexString
    WriteVagCodingCommand_prefix: HexString