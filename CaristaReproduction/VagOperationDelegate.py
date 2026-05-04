from __future__ import annotations

from datetime import date
from dataclasses import dataclass
from typing import Literal

from .CaristaClock import carista_date_payload
from .Constants import CARISTA_DATE_WRITE_DID, CARISTA_LONG_CODING_DID, CARISTA_WORKSHOP_CODE_WRITE_DID
from .Commands.VagCanAdaptationCommands import (
    READ_VAG_CAN_LONG_ADAPTATION_BASIC_ID,
    READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID,
    PreReadVagCanAdaptationDataCommand_getRequest,
    ReadVagCanLongAdaptationDataCommand_getRequest,
    ReadVagCanShortAdaptationDataCommand_getRequest,
    SetVagCanAdaptationChannelCommand_getRequest,
    StartReadVagCanRoutineCommand_getRequest,
    StopReadVagCanRoutineCommand_getRequest,
)
from .Commands.GetVagCanEcuInfoCommand import GetVagCanEcuInfoCommand_getRequest
from .Commands.GetVagCanEcuListCommand import GetVagCanEcuListCommand_getRequest
from .Commands.GetVagUdsEcuWorkshopCodeCommand import GetVagUdsEcuWorkshopCodeCommand_getRequest
from .Models.CaristaUdsCodingWritePlan import CaristaUdsCodingWritePlan
from .Models.CodingValidation import CodingValidation
from .Models.CaristaProcessValidation import CaristaProcessValidation
from .Models.RecoveredRequestBuilders import RecoveredRequestBuilders
from .Models.VagEcuInfoWithCoding import VagEcuInfoWithCoding
from .Models.ValidationGate import ValidationGate
from .Models.WriteDataByIdentifierRequest import WriteDataByIdentifierRequest
from .Commands.ReadVagCanLongCodingCommand import ReadVagCanLongCodingCommand_getRequest
from .Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from .Types import HexString
from .VagUdsAdaptationSetting import VagUdsAdaptationSetting
from .VagCanSettings import VagCanSettings_getPq25SupportedSettings
from .VagCoding import changed_coding_bytes, normalize_coding
from .Commands.WriteDataByIdentifierCommand import WriteDataByIdentifierCommand_getRequest, WriteDataByIdentifierCommand_processPayload
from .Commands.WriteVagCodingCommand import WriteVagCodingCommand, WriteVagCodingCommand_ctor
from .VagEcuInfo import VagEcuInfo_getWorkshopCodeForWriting


VAG_OPERATION_DELEGATE_METADATA_PREWRITE_DIDS = frozenset((CARISTA_DATE_WRITE_DID, CARISTA_WORKSHOP_CODE_WRITE_DID))
VAG_UDS_ADAPTATION_DIRECT_READ_LIVE_REJECTIONS: dict[int, HexString] = {
    0x055C: "7F2231",
    0x055D: "7F2231",
}
VAG_UDS_ADAPTATION_DIRECT_READ_LIVE_POSITIVES: dict[int, HexString] = {}


@dataclass(frozen=True)
class VagOperationDelegateStep:
    name: str
    native_call: str
    gate: str


@dataclass(frozen=True)
class VagOperationDelegateRawReadPlan:
    setting_key: str
    raw_address: int
    raw_type: int
    native_dispatch: str
    native_request: HexString
    live_rejected_response: HexString | None
    live_positive_response: HexString | None
    status: str
    safe_for_write_seed: bool
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class VagOperationDelegateRawValueDispatchCase:
    raw_type: int
    native_branch: str
    native_method: str
    evidence: tuple[str, ...]
    write_seed_policy: str


@dataclass(frozen=True)
class VagCanAdaptationReadStep:
    command_class: str
    native_builder: str
    request: HexString
    response_gate: str


@dataclass(frozen=True)
class VagCanAdaptationReadSequence:
    adaptation_kind: Literal["short", "long"]
    basic_id: int
    channel: int
    steps: tuple[VagCanAdaptationReadStep, ...]
    evidence: tuple[str, ...]


def VagOperationDelegate_readRawValueDispatchCases() -> tuple[VagOperationDelegateRawValueDispatchCase, ...]:
    return (
        VagOperationDelegateRawValueDispatchCase(
            raw_type=0,
            native_branch="case 0/1 -> vtable slot 0x1A4",
            native_method="VagOperationDelegate::readVagCanAdaptationValue",
            evidence=(
                "target_01270A10.c dispatches raw types 0 and 1 through vtable slot 0x1A4.",
                "target_0127236C.c names VagOperationDelegate::readVagCanAdaptationValue and retries state -0x0B reads up to two times.",
            ),
            write_seed_policy="requires native VAG CAN adaptation read sequence and positive live payload",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=1,
            native_branch="case 0/1 -> vtable slot 0x1A4",
            native_method="VagOperationDelegate::readVagCanAdaptationValue",
            evidence=(
                "target_01270A10.c dispatches raw types 0 and 1 through vtable slot 0x1A4.",
                "target_0127236C.c names VagOperationDelegate::readVagCanAdaptationValue and retries state -0x0B reads up to two times.",
            ),
            write_seed_policy="requires native VAG CAN adaptation read sequence and positive live payload",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=2,
            native_branch="case 2/4 -> cached VAG ECU info bytes",
            native_method="VagOperationDelegate::readRawValue cached coding branch",
            evidence=(
                "target_01270A10.c handles raw types 2 and 4 by reading VAG ECU info and returning cached bytes when present.",
            ),
            write_seed_policy="requires exact coding bytes from ECU info and constructor packing proof",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=3,
            native_branch="case 3 -> helper command FUN_01270CB0",
            native_method="OperationDelegate::runCommand<BytesModel>",
            evidence=(
                "target_01270A10.c builds a BytesModel command with FUN_01270CB0 for raw type 3.",
            ),
            write_seed_policy="requires command helper recovery and positive live payload",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=4,
            native_branch="case 2/4 -> cached VAG ECU info bytes",
            native_method="VagOperationDelegate::readRawValue cached coding branch",
            evidence=(
                "target_01270A10.c handles raw types 2 and 4 by reading VAG ECU info and returning cached bytes when present.",
                "target_012720EC.c adds submodule raw-address handling for type 4 through slot 0x1EC before dispatch.",
            ),
            write_seed_policy="requires exact submodule/coding bytes and constructor packing proof",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=5,
            native_branch="case 5 -> submodule id slot 0x1E4, then slot 0x1B4",
            native_method="VagOperationDelegate::readVagUdsSubmoduleValue",
            evidence=(
                "target_01270A10.c resolves a type-5 submodule id before dispatching through slot 0x1B4.",
                "target_01272CE0.c names VagOperationDelegate::readVagUdsSubmoduleValue.",
            ),
            write_seed_policy="requires exact submodule id and positive live payload",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=6,
            native_branch="case 6 -> helper command FUN_0124E338",
            native_method="OperationDelegate::runCommand<BytesModel>",
            evidence=(
                "target_01270A10.c builds a BytesModel command with raw address and an exact one-byte parameter for raw type 6.",
            ),
            write_seed_policy="requires command helper recovery and positive live payload",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=7,
            native_branch="case 7 -> vtable slot 0x1AC",
            native_method="VagOperationDelegate::readVagUdsValue",
            evidence=(
                "target_01270A10.c dispatches raw type 7 through vtable slot 0x1AC.",
                "target_01272A1C.c names VagOperationDelegate::readVagUdsValue and runs a BytesModel command from raw address plus DID.",
            ),
            write_seed_policy="requires positive direct UDS raw payload before any write seed can be built",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=8,
            native_branch="case 8 -> vtable slot 0x1B0",
            native_method="VagOperationDelegate::readVagUdsCodingValue",
            evidence=(
                "target_01270A10.c dispatches raw type 8 through vtable slot 0x1B0.",
                "target_01272AD0.c names VagOperationDelegate::readVagUdsCodingValue and updates cached VAG ECU info from the UDS coding read.",
            ),
            write_seed_policy="requires exact coding raw address/packing proof before writing",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=9,
            native_branch="case 9 -> submodule id slot 0x1D4, then slot 0x1B4",
            native_method="VagOperationDelegate::readVagUdsSubmoduleValue",
            evidence=(
                "target_01270A10.c resolves a type-9 submodule id before dispatching through slot 0x1B4.",
                "target_01272CE0.c names VagOperationDelegate::readVagUdsSubmoduleValue.",
                "target_012720EC.c adds submodule raw-address handling for type 9 through slot 0x1F0 before dispatch.",
            ),
            write_seed_policy="requires exact submodule id and positive live payload",
        ),
        VagOperationDelegateRawValueDispatchCase(
            raw_type=10,
            native_branch="case 10 -> Result<BytesModel,void>(-10)",
            native_method="no native read command",
            evidence=("target_01270A10.c returns state -10 for raw type 10.",),
            write_seed_policy="never a write seed",
        ),
    )


def normalize_workshop_code_payload(value: str) -> HexString:
    return VagEcuInfo_getWorkshopCodeForWriting(value)


def VagOperationDelegate_isMetadataPreWriteDid(did: int) -> bool:
    return did in VAG_OPERATION_DELEGATE_METADATA_PREWRITE_DIDS


def VagOperationDelegate_writeDataByIdentifierResultIsFatalFail(did: int, payload: HexString) -> bool:
    result = WriteDataByIdentifierCommand_processPayload(payload)
    if not VagOperationDelegate_isMetadataPreWriteDid(did):
        return result.isFail()
    return result.isFatalFail()


def VagOperationDelegate_shouldContinueAfterMetadataPreWrite(did: int, payload: HexString) -> bool:
    if not VagOperationDelegate_isMetadataPreWriteDid(did) or not payload:
        return False
    result = WriteDataByIdentifierCommand_processPayload(payload)
    return result.isFail() and not result.isFatalFail()


def VagOperationDelegate_writeVagUdsValue_native_steps(ecu: str = "target", did: int = CARISTA_LONG_CODING_DID) -> tuple[VagOperationDelegateStep, ...]:
    optional_readback = "optional infotainment/cluster ReadDataByIdentifierCommand when native ECU/DID special cases match"
    optional_gateway = "optional CAN gateway raw command when native CAN gateway/DID special case matches"
    return (
        VagOperationDelegateStep("date_prewrite", "WriteDataByIdentifierCommand(DATE_WRITE_ID F199)", "abort only on Result.isFatalFail"),
        VagOperationDelegateStep("optional_readback", optional_readback, "abort only on fatal readback result"),
        VagOperationDelegateStep("read_ecu_info", f"readEcuInfo({ecu})", "derive VagEcuInfo.getWorkshopCodeForWriting"),
        VagOperationDelegateStep("workshop_prewrite", "WriteDataByIdentifierCommand(WORKSHOP_CODE_WRITE_ID F198)", "abort only on Result.isFatalFail"),
        VagOperationDelegateStep("optional_gateway_raw", optional_gateway, "continue to target when raw command succeeds"),
        VagOperationDelegateStep("target_write", f"WriteDataByIdentifierCommand({did:04X})", "map final states -6 and -11 to -42, otherwise return final result"),
    )


def VagOperationDelegate_readVagUdsAdaptationRawPlan(setting: VagUdsAdaptationSetting) -> VagOperationDelegateRawReadPlan:
    native_request = ReadDataByIdentifierCommand_getRequest(setting.raw_address)
    live_rejection = VAG_UDS_ADAPTATION_DIRECT_READ_LIVE_REJECTIONS.get(setting.raw_address)
    live_positive = VAG_UDS_ADAPTATION_DIRECT_READ_LIVE_POSITIVES.get(setting.raw_address)
    if live_rejection:
        status = "native_direct_read_live_rejected"
    elif live_positive:
        status = "native_direct_read_live_positive"
    else:
        status = "native_direct_read_unverified_live"
    return VagOperationDelegateRawReadPlan(
        setting_key=setting.key,
        raw_address=setting.raw_address,
        raw_type=setting.setting_type,
        native_dispatch="VagOperationDelegate::readRawValue type 7 -> readVagUdsValue -> ReadRawDataByIdentifierCommand",
        native_request=native_request,
        live_rejected_response=live_rejection,
        live_positive_response=live_positive,
        status=status,
        safe_for_write_seed=live_positive is not None,
        evidence=(
            "VagOperationDelegate::readRawValue dispatches raw type 7 to readVagUdsValue.",
            "VagOperationDelegate::readVagUdsValue builds ReadRawDataByIdentifierCommand from the raw address.",
            "Only a positive live raw payload is a write seed; rejected or untested reads stay read-only.",
            "Live BCM probes returned 7F2231 for 22055C and 22055D, so those direct reads are not usable write seeds on this session.",
        ),
    )


def VagOperationDelegate_readVagUdsAdaptationRawRequest(setting: VagUdsAdaptationSetting) -> HexString:
    plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(setting)
    if plan.live_rejected_response:
        raise RuntimeError(
            f"{setting.key} native request {plan.native_request} was live-rejected as "
            f"{plan.live_rejected_response}; do not treat it as a readable raw payload"
        )
    return plan.native_request


def VagOperationDelegate_readVagCanAdaptationValueInternalSequence(
    channel: int,
    *,
    adaptation_kind: Literal["short", "long"] = "short",
) -> VagCanAdaptationReadSequence:
    basic_id = READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID if adaptation_kind == "short" else READ_VAG_CAN_LONG_ADAPTATION_BASIC_ID
    data_read_request = (
        ReadVagCanShortAdaptationDataCommand_getRequest()
        if adaptation_kind == "short"
        else ReadVagCanLongAdaptationDataCommand_getRequest()
    )
    return VagCanAdaptationReadSequence(
        adaptation_kind=adaptation_kind,
        basic_id=basic_id,
        channel=channel,
        steps=(
            VagCanAdaptationReadStep(
                "StartReadVagCanRoutineCommand",
                "StartReadVagCanRoutineCommand::getRequest",
                StartReadVagCanRoutineCommand_getRequest(basic_id),
                "processPayload returns done",
            ),
            VagCanAdaptationReadStep(
                "PreReadVagCanAdaptationDataCommand",
                "PreReadVagCanAdaptationDataCommand::getRequest",
                PreReadVagCanAdaptationDataCommand_getRequest(basic_id),
                "processPayload expects 81",
            ),
            VagCanAdaptationReadStep(
                "SetVagCanAdaptationChannelCommand",
                "SetVagCanAdaptationChannelCommand::getRequest",
                SetVagCanAdaptationChannelCommand_getRequest(basic_id, channel),
                "processPayload returns done unless the ECU negative response is surfaced by BaseCommand",
            ),
            VagCanAdaptationReadStep(
                "ReadVagCanShortAdaptationDataCommand" if adaptation_kind == "short" else "ReadVagCanLongAdaptationDataCommand",
                "ReadVagCanAdaptationDataCommand::getRequest",
                data_read_request,
                "short parser returns bytes 2..3; long parser returns payload length byte minus one from offset 3",
            ),
            VagCanAdaptationReadStep(
                "StopReadVagCanRoutineCommand",
                "StopReadVagCanRoutineCommand::getRequest",
                StopReadVagCanRoutineCommand_getRequest(basic_id),
                "nonfatal close failure is logged and ignored after a successful read",
            ),
        ),
        evidence=(
            "VagOperationDelegate::readVagCanAdaptationValueInternal selects basic id 0103 for short and 010A for long adaptation reads.",
            "Native byte literals dump: 31B8 start, 31BA adaptation data, 31B9 set channel, 32B8 stop.",
            "This VAG CAN adaptation sequence is proven native, but raw type 7 VagUdsAdaptationSetting objects dispatch to readVagUdsValue instead.",
        ),
    )


def VagOperationDelegate_buildVagUdsAdaptationInsertedPayload(
    setting: VagUdsAdaptationSetting,
    current_raw_value: HexString,
    choice_key: str,
) -> HexString:
    return setting.insert_choice(current_raw_value, choice_key)


def VagOperationDelegate_buildVagUdsAdaptationWriteRequests(
    setting: VagUdsAdaptationSetting,
    current_raw_value: HexString,
    choice_key: str,
    *,
    workshop_code_payload: HexString,
    date_value: date | None = None,
) -> tuple[WriteDataByIdentifierRequest, ...]:
    read_plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(setting)
    if not read_plan.safe_for_write_seed:
        reason = (
            f"native read {read_plan.native_request} returned {read_plan.live_rejected_response} live"
            if read_plan.live_rejected_response
            else f"native read {read_plan.native_request} has no positive live raw payload"
        )
        raise RuntimeError(
            f"{setting.key} cannot be written safely from a guessed raw value: {reason}"
        )
    date_payload = carista_date_payload(date_value)
    workshop_payload = normalize_workshop_code_payload(workshop_code_payload)
    target_payload = VagOperationDelegate_buildVagUdsAdaptationInsertedPayload(
        setting,
        current_raw_value,
        choice_key,
    )
    return (
        WriteDataByIdentifierRequest(
            did=CARISTA_DATE_WRITE_DID,
            payload=date_payload,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_DATE_WRITE_DID, date_payload),
            label="Carista DATE_WRITE_ID pre-write",
        ),
        WriteDataByIdentifierRequest(
            did=CARISTA_WORKSHOP_CODE_WRITE_DID,
            payload=workshop_payload,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_WORKSHOP_CODE_WRITE_DID, workshop_payload),
            label="Carista WORKSHOP_CODE_WRITE_ID pre-write",
        ),
        WriteDataByIdentifierRequest(
            did=setting.raw_address,
            payload=target_payload,
            request=WriteDataByIdentifierCommand_getRequest(setting.raw_address, target_payload),
            label=f"Carista VAG UDS adaptation write for {setting.key}",
        ),
    )


def VagOperationDelegate_writeVagCanCodingValue(
    ecu_info: VagEcuInfoWithCoding,
    value6: HexString,
    *,
    force_sentinel_type5: bool = False,
) -> WriteVagCodingCommand:
    if force_sentinel_type5:
        coding_type = 5
        tail = ""
    elif ecu_info.coding_type == 2:
        coding_type = 2
        tail = ecu_info.tail
    else:
        coding_type = 3
        tail = ""
    return WriteVagCodingCommand_ctor(value6, ecu_info.raw_address4, coding_type, tail)


def build_carista_uds_coding_write_plan(
    current_coding: HexString,
    target_coding: HexString,
    *,
    workshop_code_payload: HexString,
    date_value: date | None = None,
) -> CaristaUdsCodingWritePlan:
    current = normalize_coding(current_coding)
    target = normalize_coding(target_coding)
    if len(current) != len(target):
        raise ValueError("current and target coding must have the same byte length")
    if len(target) // 2 != 30:
        raise ValueError(f"PQ25 DID 0600 coding should be 30 bytes, got {len(target) // 2}")

    date_payload = carista_date_payload(date_value)
    workshop_payload = normalize_workshop_code_payload(workshop_code_payload)
    requests = [
        WriteDataByIdentifierRequest(
            did=CARISTA_DATE_WRITE_DID,
            payload=date_payload,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_DATE_WRITE_DID, date_payload),
            label="Carista DATE_WRITE_ID pre-write",
        ),
        WriteDataByIdentifierRequest(
            did=CARISTA_WORKSHOP_CODE_WRITE_DID,
            payload=workshop_payload,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_WORKSHOP_CODE_WRITE_DID, workshop_payload),
            label="Carista WORKSHOP_CODE_WRITE_ID pre-write",
        ),
        WriteDataByIdentifierRequest(
            did=CARISTA_LONG_CODING_DID,
            payload=target,
            request=WriteDataByIdentifierCommand_getRequest(CARISTA_LONG_CODING_DID, target),
            label="Carista UDS long-coding write",
        ),
    ]
    return CaristaUdsCodingWritePlan(
        current_coding=current,
        target_coding=target,
        date_payload=date_payload,
        workshop_code_payload=workshop_payload,
        requests=requests,
        changed_bytes=changed_coding_bytes(current, target),
    )


def validate_carista_process(
    coding: HexString,
    ecu_info: VagEcuInfoWithCoding | None,
) -> CaristaProcessValidation:
    normalized_coding = normalize_coding(coding)
    length_bytes = len(normalized_coding) // 2
    settings = VagCanSettings_getPq25SupportedSettings(normalized_coding)
    return CaristaProcessValidation(
        requests=RecoveredRequestBuilders(
            GetVagCanEcuInfoCommand_getRequest=GetVagCanEcuInfoCommand_getRequest(),
            GetVagCanEcuListCommand_getRequest=GetVagCanEcuListCommand_getRequest(),
            ReadVagCanLongCodingCommand_getRequest=ReadVagCanLongCodingCommand_getRequest(),
            ReadDataByIdentifierCommand_getRequest_F1A5=ReadDataByIdentifierCommand_getRequest(0xF1A5),
            GetVagUdsEcuWorkshopCodeCommand_getRequest=GetVagUdsEcuWorkshopCodeCommand_getRequest(),
            WriteDataByIdentifierCommand_getRequest_0600=WriteDataByIdentifierCommand_getRequest(CARISTA_LONG_CODING_DID, ""),
            StartReadVagCanRoutineCommand_getRequest_0103=StartReadVagCanRoutineCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID),
            PreReadVagCanAdaptationDataCommand_getRequest_0103=PreReadVagCanAdaptationDataCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID),
            SetVagCanAdaptationChannelCommand_getRequest_0103_5C=SetVagCanAdaptationChannelCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID, 0x5C),
            ReadVagCanShortAdaptationDataCommand_getRequest_0103=ReadVagCanShortAdaptationDataCommand_getRequest(),
            StopReadVagCanRoutineCommand_getRequest_0103=StopReadVagCanRoutineCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID),
        ),
        coding=CodingValidation(length_bytes=length_bytes, value=normalized_coding),
        ecu_info=ecu_info,
        supported_settings=settings,
        gates=[
            ValidationGate(
                name="read_long_coding",
                status="pass",
                detail="Current coding is loaded from direct 220600 or Carista 5A9A long-coding data.",
            ),
            ValidationGate(
                name="map_supported_settings_for_car",
                status="pass" if settings else "block",
                detail="PQ25 cornering labels are mapped to byte 12 bit 6 and byte 21 bit 2, but those two bits were live-tested and did not fix the visible symptom.",
            ),
            ValidationGate(
                name="build_uds_write_plan",
                status="pass" if length_bytes == 30 else "block",
                detail="DID 0600 writer is the active path; execution still requires a fresh 22F1A5 workshop-code payload.",
            ),
            ValidationGate(
                name="model_vag_can_adaptation_routine_builders",
                status="pass",
                detail="Recovered native routine builders produce 31B80103, 31BA0103, 31B901035C, 31BA0103, and 32B80103 for short adaptation channel 5C.",
            ),
            ValidationGate(
                name="block_055c_055d_type7_writes",
                status="block",
                detail="The recovered 055C/055D settings are raw type 7; native direct reads 22055C/22055D returned 7F2231, so no full raw payload is available for a safe write.",
            ),
        ],
    )
