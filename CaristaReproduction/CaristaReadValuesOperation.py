from __future__ import annotations

from .Commands.GetVagCanEcuInfoCommand import GetVagCanEcuInfoCommand_getRequest
from .Commands.GetVagCanEcuListCommand import GetVagCanEcuListCommand_getRequest
from .Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from .Commands.ReadVagCanLongCodingCommand import ReadVagCanLongCodingCommand_getRequest
from .Models.CaristaReadValuesOperation import (
    CaristaReadValueRequest,
    CaristaReadValuesFlowStep,
    CaristaReadValuesPlan,
    CaristaTransportStep,
)
from .Types import HexString
from .VagCanCommunicator import (
    CARISTA_FINAL_FRAME_ST,
    CARISTA_NATIVE_T3_MS,
    CARISTA_NON_FINAL_FRAME_ST,
    CARISTA_TX_ACK_RETRIES,
    CARISTA_TX_ACK_RETRY_DELAY_SECONDS,
)
from .VagCanSettings import VagCanSettings_readOnlyCandidates


CARISTA_TP20_UNIT_09_OPEN_REQUEST = "20C00010000301"
CARISTA_TP20_EXPECTED_SEND_HEADER = "338"
CARISTA_TP20_EXPECTED_LISTEN_HEADER = "300"
CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST = "A00194FF82FF"
POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST = "A00F8AFF32FF"

CARISTA_LIVE_COMPANION_READS: tuple[CaristaReadValueRequest, ...] = (
    CaristaReadValueRequest(
        order=400,
        request=ReadDataByIdentifierCommand_getRequest(0x0601),
        native_builder="live Carista/PQ25 companion DID; native Setting branch unresolved",
        read_path="UDS ReadDataByIdentifier on the same TP2.0 data channel",
        setting_key="pq25_live_companion_0601",
        status="live_positive_companion_observed",
        included_by_default=False,
        evidence=(
            "Live BCM reads returned 6206011E across several lamp-switch states.",
            "The native Setting branch that causes this companion read is not yet recovered, so this is a probe companion rather than a primary Carista read-values request.",
        ),
    ),
    CaristaReadValueRequest(
        order=410,
        request=ReadDataByIdentifierCommand_getRequest(0x0606),
        native_builder="live Carista/PQ25 companion DID; native Setting branch unresolved",
        read_path="UDS ReadDataByIdentifier on the same TP2.0 data channel",
        setting_key="pq25_live_companion_0606",
        status="live_positive_companion_observed",
        included_by_default=False,
        evidence=(
            "Previous live BCM read returned 620606001800018000.",
            "Kept separate from the primary ReadValuesOperation model until the native constructor/availability branch is recovered.",
        ),
    ),
)


def CaristaReadValuesOperation_transport() -> tuple[CaristaTransportStep, ...]:
    return (
        CaristaTransportStep(
            order=10,
            name="open_tp20_unit_09",
            value=CARISTA_TP20_UNIT_09_OPEN_REQUEST,
            purpose="Open VW TP2.0 channel to BCM/J519 unit address 20.",
            evidence=(
                "Live Polo channel open returns send header 338 and listen header 300.",
                "This is the standard unit-09 TP2.0 entry point used by the local Carista reproduction.",
            ),
        ),
        CaristaTransportStep(
            order=20,
            name="carista_exact_channel_parameters",
            value=CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
            purpose="Carista native TP2.0 channel-parameter request from libCarista.so.",
            evidence=(
                "Decompiled Carista 9.8.x native code builds A00194FF82FF for TP2.0 channel parameter setup.",
                "Live tools should try this before the Polo-specific fallback when the goal is matching Carista.",
            ),
        ),
        CaristaTransportStep(
            order=30,
            name="polo_live_proven_channel_parameters",
            value=POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST,
            purpose="Fallback channel-parameter request proven on this Polo when the exact Carista request does not answer.",
            evidence=(
                "Live response A10F8AFF4FFF established a stable data channel on 6R0937087K.",
                "This is intentionally modeled as a fallback, not as the primary Carista-native request.",
            ),
        ),
        CaristaTransportStep(
            order=40,
            name="non_final_tp20_frame_timeout",
            value=CARISTA_NON_FINAL_FRAME_ST,
            purpose="ELM timeout used by recovered Carista transport for non-final outbound TP2.0 frames.",
            evidence=("CaristaReproduction.VagCanCommunicator encodes this as CARISTA_NON_FINAL_FRAME_ST.",),
        ),
        CaristaTransportStep(
            order=50,
            name="final_tp20_frame_timeout",
            value=CARISTA_FINAL_FRAME_ST,
            purpose="ELM timeout used by recovered Carista transport for final outbound TP2.0 frames and responses.",
            evidence=("CaristaReproduction.VagCanCommunicator encodes this as CARISTA_FINAL_FRAME_ST.",),
        ),
        CaristaTransportStep(
            order=60,
            name="native_t3_inter_frame_pause_ms",
            value=str(CARISTA_NATIVE_T3_MS),
            purpose="Native T3 value used to space outgoing TP2.0 data frames.",
            evidence=("0x82 ms is recovered from Carista native transport and rendered as 130 ms.",),
        ),
        CaristaTransportStep(
            order=70,
            name="ack_rule",
            value="B((received_sequence + 1) & 0x0F)",
            purpose="ACK ECU application first/final frames using Carista's B-sequence rule.",
            evidence=(
                "VagCanCommunicator.ackForReceivedPacket returns B((sequence + 1) & 0xF) for frame types 0 and 1.",
                f"Transmit ACK retry policy is {CARISTA_TX_ACK_RETRIES} retries with {CARISTA_TX_ACK_RETRY_DELAY_SECONDS:.2f}s delay.",
            ),
        ),
    )


def CaristaReadValuesOperation_nativeFlow() -> tuple[CaristaReadValuesFlowStep, ...]:
    return (
        CaristaReadValuesFlowStep(
            order=10,
            native_method="ReadValuesOperation::readItemAvailabilityAndValues",
            ghidra_address="0x012CDE08",
            dispatch="operation setup before Java getAvailableItems/getSettingValue",
            purpose="Build the runtime availability map and prime raw current values.",
            evidence=(
                "Calls delegate slot 0xE0 for availability.",
                "Uses raw-address slot 0x148 and raw-value/multi-read slots for value-bearing settings.",
            ),
        ),
        CaristaReadValuesFlowStep(
            order=20,
            native_method="VagOperationDelegate::getSettingAvailability",
            ghidra_address="0x012703D0",
            dispatch="delegate slot 0xE0",
            purpose="Reject absent ECUs or settings that do not match the ECU type before raw reads.",
            evidence=("Calls getVagSettingAvailabilityForEcu after ECU/type checks.",),
        ),
        CaristaReadValuesFlowStep(
            order=30,
            native_method="VagOperationDelegate::getVagSettingAvailabilityForEcu",
            ghidra_address="0x0127075C",
            dispatch="availability predicate choke point",
            purpose="Select whether a mixed setting branch applies to this exact ECU/PDX/revision.",
            evidence=(
                "Uses setting type byte, VIN-derived PDX/file identifiers, and ECU ASAM/revision data.",
                "This is why a visible Carista key cannot be converted directly into one raw DID/write path.",
            ),
        ),
        CaristaReadValuesFlowStep(
            order=40,
            native_method="VagOperationDelegate::readRawValuesMulti",
            ghidra_address="0x01270CF8",
            dispatch="multi-read/cache path",
            purpose="Batch dynamic raw reads after cache checks.",
            evidence=("Static export notes show dynamic raw reads batched in chunks of six after cache checks.",),
        ),
        CaristaReadValuesFlowStep(
            order=50,
            native_method="VagOperationDelegate::readRawValue",
            ghidra_address="0x01270A10",
            dispatch="raw type switch",
            purpose="Dispatch each setting to the correct native read family.",
            evidence=(
                "Type 0/1 -> VAG CAN adaptation routine path.",
                "Type 7 -> readVagUdsValue / ReadDataByIdentifierCommand.",
                "Type 8 -> readVagUdsCodingValue and cached UDS coding bytes.",
                "Types 5/9 -> readVagUdsSubmoduleValue after submodule-id resolution.",
            ),
        ),
        CaristaReadValuesFlowStep(
            order=60,
            native_method="ReadValuesOperation::getSettingValue",
            ghidra_address="0x012CD694",
            dispatch="JNI ReadValuesOperation.getSettingValue slot 0x8C",
            purpose="Return the native setting's extracted Java-visible byte[] value.",
            evidence=(
                "Calls operation delegate raw-value slot 0xA8.",
                "Applies the setting extraction slot 0x1C before returning bytes to Java.",
            ),
        ),
    )


def _core_requests() -> tuple[CaristaReadValueRequest, ...]:
    return (
        CaristaReadValueRequest(
            order=10,
            request=GetVagCanEcuInfoCommand_getRequest(),
            native_builder="GetVagCanEcuInfoCommand::getRequest",
            read_path="VAGCAN20 ECU metadata/cache read",
            setting_key="<ecu_info>",
            status="native_builder_recovered",
            included_by_default=True,
            evidence=(
                "ReadValuesOperation availability and raw-value branches depend on ECU identity/coding metadata.",
                "Carista exposes GetEcuInfoOperation.getCodingRawAddress(short) in the Java/native bridge.",
            ),
        ),
        CaristaReadValueRequest(
            order=20,
            request=GetVagCanEcuListCommand_getRequest(),
            native_builder="GetVagCanEcuListCommand::getRequest",
            read_path="VAGCAN20 ECU list/info read",
            setting_key="<ecu_list>",
            status="native_builder_recovered",
            included_by_default=True,
            evidence=("Recovered from Carista native VAGCAN20 request builders.",),
        ),
        CaristaReadValueRequest(
            order=30,
            request=ReadVagCanLongCodingCommand_getRequest(),
            native_builder="ReadVagCanLongCodingCommand::getRequest",
            read_path="VAGCAN20 long-coding read/cache path",
            setting_key="<long_coding_cache>",
            status="native_builder_recovered",
            included_by_default=True,
            evidence=(
                "VagOperationDelegate raw types 2/4 can read cached ECU coding bytes.",
                "This command is retained because it is Carista-native even when the current BCM often answers better through DID 0600.",
            ),
        ),
        CaristaReadValueRequest(
            order=40,
            request=ReadDataByIdentifierCommand_getRequest(0x0600),
            native_builder="ReadDataByIdentifierCommand(0600) / readVagUdsCodingValue",
            read_path="UDS coding current-value read on TP2.0 unit 09",
            setting_key="<uds_coding_0600>",
            status="live_positive_primary_coding_read",
            included_by_default=True,
            evidence=(
                "Live BCM returns 620600 plus 30-byte coding for 6R0937087K.",
                "VagOperationDelegate raw type 8 dispatch is readVagUdsCodingValue.",
            ),
        ),
    )


def _vag_can_settings_requests() -> tuple[CaristaReadValueRequest, ...]:
    requests: list[CaristaReadValueRequest] = []
    for index, candidate in enumerate(VagCanSettings_readOnlyCandidates(include_known_rejected=True), start=100):
        rejected = candidate.status.startswith("live_rejected")
        requests.append(
            CaristaReadValueRequest(
                order=index,
                request=candidate.request,
                native_builder=f"VagCanSettings::getSettings/{candidate.key}",
                read_path="ReadValuesOperation raw-value candidate from recovered Play 9.8.3 x86 setting constructor",
                setting_key=candidate.key,
                status=candidate.status,
                included_by_default=not rejected,
                evidence=(
                    candidate.purpose,
                    "Known-rejected candidates stay in the model as Carista evidence but are excluded from default live probes.",
                ),
            )
        )
    return tuple(requests)


def CaristaReadValuesOperation_buildPq25BcmPlan() -> CaristaReadValuesPlan:
    return CaristaReadValuesPlan(
        name="Carista ReadValuesOperation PQ25 BCM plan",
        vehicle_scope="VW Polo 6R / PQ25 BCM J519 / 6R0937087K / TP2.0 unit 20",
        source="Official Play-installed Carista 9.8.3 x86 libCarista.so plus local live TP2.0 evidence",
        transport=CaristaReadValuesOperation_transport(),
        native_flow=CaristaReadValuesOperation_nativeFlow(),
        requests=tuple(sorted(_core_requests() + _vag_can_settings_requests() + CARISTA_LIVE_COMPANION_READS, key=lambda item: item.order)),
        unresolved=(
            "Runtime availability predicate objects are not fully reconstructed, so mixed settings remain branch-conditional.",
            "car_setting_left_fog_light_as and car_setting_right_fog_light_as still lack a proven VAG/PQ25 constructor path.",
            "22055C and 22055D are modeled as Carista static branches but excluded from default live probes because this BCM returned 7F2231.",
            "The Polo-proven A00F8AFF32FF channel parameter request is a fallback when the exact Carista A00194FF82FF setup does not answer.",
        ),
    )


def CaristaReadValuesOperation_pq25BcmRequests(
    *,
    include_live_companions: bool = False,
    include_known_rejected: bool = False,
) -> tuple[HexString, ...]:
    requests: list[HexString] = []
    for request in CaristaReadValuesOperation_buildPq25BcmPlan().requests:
        if request.status.startswith("live_rejected") and not include_known_rejected:
            continue
        if request.status.startswith("live_positive_companion") and not include_live_companions:
            continue
        if request.included_by_default or request.status.startswith("live_positive_companion"):
            requests.append(request.request)
    return tuple(dict.fromkeys(requests))


def CaristaReadValuesOperation_commandLabels(
    *,
    include_live_companions: bool = True,
    include_known_rejected: bool = True,
) -> dict[HexString, str]:
    labels: dict[HexString, str] = {}
    for request in CaristaReadValuesOperation_buildPq25BcmPlan().requests:
        if request.status.startswith("live_rejected") and not include_known_rejected:
            continue
        if request.status.startswith("live_positive_companion") and not include_live_companions:
            continue
        labels[request.request] = (
            f"Carista ReadValuesOperation {request.setting_key}: {request.native_builder}; "
            f"path={request.read_path}; status={request.status}"
        )
    return labels


class CaristaReadValuesOperation:
    buildPq25BcmPlan = staticmethod(CaristaReadValuesOperation_buildPq25BcmPlan)
    pq25BcmRequests = staticmethod(CaristaReadValuesOperation_pq25BcmRequests)
    commandLabels = staticmethod(CaristaReadValuesOperation_commandLabels)
