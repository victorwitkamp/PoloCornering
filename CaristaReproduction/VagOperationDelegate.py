from __future__ import annotations

from datetime import date
from dataclasses import dataclass

from .CaristaClock import carista_date_payload
from .Constants import CARISTA_DATE_WRITE_DID, CARISTA_LONG_CODING_DID, CARISTA_WORKSHOP_CODE_WRITE_DID
from .Commands.GetVagCanEcuInfoCommand import GetVagCanEcuInfoCommand_getRequest
from .Commands.GetVagUdsEcuWorkshopCodeCommand import GetVagUdsEcuWorkshopCodeCommand_getRequest
from .Models.CaristaUdsCodingWritePlan import CaristaUdsCodingWritePlan
from .Models.CodingValidation import CodingValidation
from .Models.CaristaProcessValidation import CaristaProcessValidation
from .Models.Pq25SupportedSetting import Pq25SupportedSetting
from .Models.RecoveredRequestBuilders import RecoveredRequestBuilders
from .Models.TupleCandidate import TupleCandidate
from .Models.VagEcuInfoWithCoding import VagEcuInfoWithCoding
from .Models.ValidationGate import ValidationGate
from .Models.WriteDataByIdentifierRequest import WriteDataByIdentifierRequest
from .Commands.ReadVagCanLongCodingCommand import ReadVagCanLongCodingCommand_getRequest
from .Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from .Types import HexString
from .VagCanSettings import VagCanSettings_getPq25SupportedSettings
from .VagCoding import changed_coding_bytes, normalize_coding
from .Commands.WriteDataByIdentifierCommand import WriteDataByIdentifierCommand_getRequest
from .Commands.WriteVagCodingCommand import WriteVagCodingCommand, WriteVagCodingCommand_ctor, WriteVagCodingCommand_getRequest
from .VagEcuInfo import VagEcuInfo_getWorkshopCodeForWriting


@dataclass(frozen=True)
class VagOperationDelegateStep:
    name: str
    native_call: str
    gate: str


def normalize_workshop_code_payload(value: str) -> HexString:
    return VagEcuInfo_getWorkshopCodeForWriting(value)


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


def build_tuple_candidates(
    settings: list[Pq25SupportedSetting],
    ecu_info: VagEcuInfoWithCoding | None,
) -> list[TupleCandidate]:
    candidates: list[TupleCandidate] = []
    for setting in settings:
        if ecu_info is None:
            candidates.append(
                TupleCandidate(
                    key=setting.key,
                    label=setting.label,
                    cornering_fix=setting.cornering_fix,
                    value6=setting.target_value6,
                    status="blocked_missing_5A9B_metadata",
                    reason="Need positive GetVagCanEcuInfoCommand / 5A9B metadata for rawAddress4, coding type, and tail.",
                )
            )
            continue

        command = VagOperationDelegate_writeVagCanCodingValue(ecu_info, setting.target_value6)
        candidates.append(
            TupleCandidate(
                key=setting.key,
                label=setting.label,
                cornering_fix=setting.cornering_fix,
                value6=setting.target_value6,
                status="ready_for_review",
                request=WriteVagCodingCommand_getRequest(command),
                raw_address4=command.raw_address4,
                coding_type=command.coding_type,
                tail=command.tail,
            )
        )
    return candidates


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
    settings = VagCanSettings_getPq25SupportedSettings(normalized_coding)
    tuple_candidates = build_tuple_candidates(settings, ecu_info)
    tuple_ready = bool(tuple_candidates) and all(candidate.status == "ready_for_review" for candidate in tuple_candidates)
    return CaristaProcessValidation(
        requests=RecoveredRequestBuilders(
            GetVagCanEcuInfoCommand_getRequest=GetVagCanEcuInfoCommand_getRequest(),
            ReadVagCanLongCodingCommand_getRequest=ReadVagCanLongCodingCommand_getRequest(),
            ReadDataByIdentifierCommand_getRequest_F1A5=ReadDataByIdentifierCommand_getRequest(0xF1A5),
            GetVagUdsEcuWorkshopCodeCommand_getRequest=GetVagUdsEcuWorkshopCodeCommand_getRequest(),
            WriteVagCodingCommand_prefix="3B9A",
        ),
        coding=CodingValidation(length_bytes=len(normalized_coding) // 2, value=normalized_coding),
        ecu_info=ecu_info,
        supported_settings=settings,
        tuple_candidates=tuple_candidates,
        gates=[
            ValidationGate(
                name="read_long_coding",
                status="pass",
                detail="Current coding is loaded from direct 220600 or Carista 5A9A long-coding data.",
            ),
            ValidationGate(
                name="map_supported_settings_for_car",
                status="pass" if settings else "block",
                detail="PQ25 cornering settings are mapped from Carista labels to byte 12 bit 6 and byte 21 bit 2.",
            ),
            ValidationGate(
                name="get_vag_can_ecu_info",
                status="pass" if ecu_info else "block",
                detail="Need positive 5A9B to recover rawAddress4, coding selector, and tail." if ecu_info is None else "Positive 5A9B metadata decoded.",
            ),
            ValidationGate(
                name="build_write_tuples",
                status="pass" if tuple_ready else "block",
                detail="WriteVagCodingCommand requests are review-ready." if tuple_ready else "Tuple bytes are blocked until ECU metadata is present.",
            ),
        ],
    )