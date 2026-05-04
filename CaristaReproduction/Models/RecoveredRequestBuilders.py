from __future__ import annotations

from dataclasses import dataclass
from ..Types import HexString


@dataclass(frozen=True)
class RecoveredRequestBuilders:
    GetVagCanEcuInfoCommand_getRequest: HexString
    GetVagCanEcuListCommand_getRequest: HexString
    ReadVagCanLongCodingCommand_getRequest: HexString
    ReadDataByIdentifierCommand_getRequest_F1A5: HexString
    GetVagUdsEcuWorkshopCodeCommand_getRequest: HexString
    WriteDataByIdentifierCommand_getRequest_0600: HexString
    StartReadVagCanRoutineCommand_getRequest_0103: HexString
    PreReadVagCanAdaptationDataCommand_getRequest_0103: HexString
    SetVagCanAdaptationChannelCommand_getRequest_0103_5C: HexString
    ReadVagCanShortAdaptationDataCommand_getRequest_0103: HexString
    StopReadVagCanRoutineCommand_getRequest_0103: HexString
