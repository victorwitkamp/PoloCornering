from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any

from .Commands.GetVagCanEcuInfoCommand import GetVagCanEcuInfoCommand_getRequest
from .Commands.GetVagCanEcuListCommand import GetVagCanEcuListCommand_getRequest
from .Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from .Commands.ReadVagCanLongCodingCommand import ReadVagCanLongCodingCommand_getRequest
from .Models.ReadValuesOperation import (
    ReadValueRequest,
    ReadValuesOperationFlowStep,
    ReadValuesOperationPlan,
    ReadValuesOperationSetting,
    ReadValuesOperationSettingReport,
    ReadValuesOperationTransportStep,
    SettingValueOption,
)
from .Types import HexString
from .VagCanCommunicator import (
    CARISTA_CHANNEL_PARAMETER_ATTEMPTS,
    CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS,
    CARISTA_FINAL_FRAME_ST,
    CARISTA_MIN_ELM_VERSION,
    CARISTA_NATIVE_T3_MS,
    CARISTA_NON_FINAL_FRAME_ST,
    CARISTA_RECEIVE_MORE_TIMEOUT_SPEC,
    CARISTA_TP20_OPEN_REQUEST_ATTEMPTS,
    CARISTA_TX_ACK_RETRIES,
    CARISTA_TX_ACK_RETRY_DELAY_SECONDS,
    sendNack,
)
from .VagCanSettings import (
    VagCanSettings_getPq25SettingRecoveries,
    VagCanSettings_readOnlyCandidates,
    VagCanSettingsSettingRecovery,
)
from .VagCoding import bit_state, normalize_coding


CARISTA_TP20_UNIT_09_OPEN_REQUEST = "20C00010000301"
CARISTA_TP20_EXPECTED_SEND_HEADER = "338"
CARISTA_TP20_EXPECTED_LISTEN_HEADER = "300"
CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST = "A00194FF82FF"
POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST = "A00F8AFF32FF"
DEFAULT_PQ25_CATALOG_PATH = Path(__file__).resolve().parents[1] / "carista_apk_analysis" / "pq25_carista_setting_catalog.json"
PQ25_BIT_RE = re.compile(r"byte\s+(?P<byte>\d+)\s+bit\s+(?P<bit>\d+)", re.IGNORECASE)
PQ25_MASK_RE = re.compile(r"byte\s+(?P<byte>0x[0-9a-f]+|\d+)\s+mask\s+0x(?P<mask>[0-9a-f]+)", re.IGNORECASE)
CARISTA_INSTRUCTION_CHOICE_LABELS: dict[str, tuple[str, ...]] = {
    "car_setting_fog_when": ("Cornering lights", "Use DRL via fog and cornering lights"),
    "car_setting_left_fog_light_as": ("Cornering lights", "Use DRL via fog and cornering lights"),
    "car_setting_right_fog_light_as": ("Cornering lights", "Use DRL via fog and cornering lights"),
}
VAG_CAN_SETTINGS_RECOVERIES = {recovery.key: recovery for recovery in VagCanSettings_getPq25SettingRecoveries()}


CARISTA_LIVE_COMPANION_READS: tuple[ReadValueRequest, ...] = (
    ReadValueRequest(
        order=400,
        request=ReadDataByIdentifierCommand_getRequest(0x0601),
        native_builder="live Carista/PQ25 companion DID; native Setting branch unresolved",
        read_path="UDS ReadDataByIdentifier on the same TP2.0 data channel",
        setting_key="pq25_live_companion_0601",
        status="live_positive_companion_observed",
        included_by_default=False,
        evidence=(
            "Live BCM reads returned 6206011E across switch-left, switch-middle, switch-right, pulled-fog, and turn-signal states, so 0601 behaves like stored configuration/status rather than live switch state.",
            "A 2026-05-07 current-state read-only TP2.0 pass on the exact Carista channel parameters A00194FF82FF again returned 6206011E.",
            "The 1E payload byte is byte-for-byte equal to the recovered car_setting_enabled_coming_home_or_leaving_home choice in the older ARM 055C/055D per-side fog-role tables, beside left-on 16 and right-on 17.",
            "Official Play 9.8.3 x86 contains car_setting_enabled_coming_home_or_leaving_home at 0x012D349A as a VagUdsAdaptationSetting branch using raw 0x0565, offset 5, mask 0x3F, and choice value 0x1E under CENTRAL_ELEC_MK7_ALL; this explains the reused enum but not DID 0601.",
            "Direct Play 9.8.3 x86 Capstone/pyelftools sweep found zero decoded instruction operands for 0x0601, 0x0606, 0x220601, 0x220606, 0x620601, or 0x620606; raw/ascii hits are PDX names, sample-response text, unwind/table bytes, and unrelated code bytes, not recovered VAG/PQ25 Setting constructors.",
            "The x86 binary contains car_setting_enabled_coming_home_or_leaving_home in .rodata, but the direct-reference sweep found no instruction or raw pointer tying that enum string to DID 0601.",
            "Because 055C/055D reject live and no 0601 native Setting branch is recovered, this is a high-priority role clue, not a write seed for 2E0601 or 1E->16/17.",
        ),
    ),
    ReadValueRequest(
        order=410,
        request=ReadDataByIdentifierCommand_getRequest(0x0606),
        native_builder="live Carista/PQ25 companion DID; native Setting branch unresolved",
        read_path="UDS ReadDataByIdentifier on the same TP2.0 data channel",
        setting_key="pq25_live_companion_0606",
        status="live_positive_companion_observed",
        included_by_default=False,
        evidence=(
            "Successful isolated live BCM reads on 2026-04-29 and 2026-05-04 reassembled to 620606001800018000.",
            "A 2026-05-07 current-state read-only TP2.0 pass on the exact Carista channel parameters A00194FF82FF again returned 620606001800018000.",
            "The retained switch-state sweeps did not produce usable 0606 variation; most rows are no_response or disconnect, so no lamp-state correlation is proven for this payload.",
            "Preferred x86 Capstone/pyelftools static sweep found no decoded instruction operand immediate 0x0606, 0x220606, or 0x620606 in libCarista.so; raw/ascii hits are sample-response text, table bytes, or unrelated code bytes, not recovered VAG/PQ25 setting constructors.",
            "Kept separate from the primary ReadValuesOperation model until the native constructor/availability branch is recovered.",
        ),
    ),
)


def ReadValuesOperation_transport() -> tuple[ReadValuesOperationTransportStep, ...]:
    return (
        ReadValuesOperationTransportStep(
            order=10,
            name="open_tp20_unit_09",
            value=CARISTA_TP20_UNIT_09_OPEN_REQUEST,
            purpose="Open VW TP2.0 channel to BCM/J519 unit address 20.",
            evidence=(
                "Live Polo channel open returns send header 338 and listen header 300.",
                "This is the standard unit-09 TP2.0 entry point used by the local Carista reproduction.",
            ),
        ),
        ReadValuesOperationTransportStep(
            order=20,
            name="carista_exact_channel_parameters",
            value=CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
            purpose="Carista native TP2.0 channel-parameter request from libCarista.so.",
            evidence=(
                "Decompiled Carista 9.8.x native code builds A00194FF82FF for TP2.0 channel parameter setup.",
                "Live tools should try this before the Polo-specific fallback when the goal is matching Carista.",
            ),
        ),
        ReadValuesOperationTransportStep(
            order=30,
            name="polo_live_proven_channel_parameters",
            value=POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST,
            purpose="Fallback channel-parameter request proven on this Polo when the exact Carista request does not answer.",
            evidence=(
                "Live response A10F8AFF4FFF established a stable data channel on 6R0937087K.",
                "This is intentionally modeled as a fallback, not as the primary Carista-native request.",
            ),
        ),
        ReadValuesOperationTransportStep(
            order=40,
            name="non_final_tp20_frame_timeout",
            value=CARISTA_NON_FINAL_FRAME_ST,
            purpose="ELM timeout used by recovered Carista transport for non-final outbound TP2.0 frames.",
            evidence=("CaristaReproduction.VagCanCommunicator encodes this as CARISTA_NON_FINAL_FRAME_ST.",),
        ),
        ReadValuesOperationTransportStep(
            order=50,
            name="final_tp20_frame_timeout",
            value=CARISTA_FINAL_FRAME_ST,
            purpose="ELM timeout used by recovered Carista transport for final outbound TP2.0 frames and responses.",
            evidence=("CaristaReproduction.VagCanCommunicator encodes this as CARISTA_FINAL_FRAME_ST.",),
        ),
        ReadValuesOperationTransportStep(
            order=60,
            name="native_t3_inter_frame_pause_ms",
            value=str(CARISTA_NATIVE_T3_MS),
            purpose="Native T3 value used to space outgoing TP2.0 data frames.",
            evidence=("0x82 ms is recovered from Carista native transport and rendered as 130 ms.",),
        ),
        ReadValuesOperationTransportStep(
            order=70,
            name="ack_rule",
            value="B((received_sequence + 1) & 0x0F)",
            purpose="ACK ECU application first/final frames using Carista's B-sequence rule.",
            evidence=(
                "VagCanCommunicator.ackForReceivedPacket returns B((sequence + 1) & 0xF) for frame types 0 and 1.",
                f"Transmit ACK retry policy is {CARISTA_TX_ACK_RETRIES} retries with {CARISTA_TX_ACK_RETRY_DELAY_SECONDS:.2f}s delay.",
            ),
        ),
        ReadValuesOperationTransportStep(
            order=80,
            name="receive_more_keep_alive",
            value=f"A3 with timeout/spec 0x{CARISTA_RECEIVE_MORE_TIMEOUT_SPEC:X}",
            purpose="Recovered VagCanCommunicator::receiveMore behavior for requesting/appending more TP2.0 packets.",
            evidence=(
                "VagCanCommunicator_receiveMore_00D2898C.c sets adapter timeout/spec 0x200, sends A3, then calls receive().",
                "VagCanCommunicator_receive_00D288A4.c calls Communicator::readResponses and appends returned packets to receivedPackets.",
            ),
        ),
        ReadValuesOperationTransportStep(
            order=90,
            name="send_nack_rule",
            value=f"{sendNack(0)}..{sendNack(15)} by sequence",
            purpose="Recovered VagCanCommunicator::sendNack behavior for requesting retransmission on sequence mismatch.",
            evidence=(
                "VagCanCommunicator::sendNack(seq) dispatches sendAck(0x90, seq, true).",
                "The bool true path in sendAck sets timeout/spec 0x200 before send, then calls receive().",
            ),
        ),
        ReadValuesOperationTransportStep(
            order=100,
            name="native_channel_open_retry_shape",
            value=(
                f"ELM>=0x{CARISTA_MIN_ELM_VERSION:X}; "
                f"outer={CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS}; "
                f"open_sends={CARISTA_TP20_OPEN_REQUEST_ATTEMPTS}; "
                f"param_sends={CARISTA_CHANNEL_PARAMETER_ATTEMPTS}"
            ),
            purpose="Recovered VagCanCommunicator::establishEcuComm retry/header/channel-parameter shape.",
            evidence=(
                "VagCanCommunicator_establishEcuComm_00D2765C.c gates on ELM version, sends the unit-derived open request, derives headers from the response, and accepts channel-parameter opcode A1.",
                "The raw adapter-wrapper offsets are recovered, but their human-readable AT command labels remain indirect.",
            ),
        ),
    )


def ReadValuesOperation_nativeFlow() -> tuple[ReadValuesOperationFlowStep, ...]:
    return (
        ReadValuesOperationFlowStep(
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
        ReadValuesOperationFlowStep(
            order=20,
            native_method="VagOperationDelegate::getSettingAvailability",
            ghidra_address="0x012703D0",
            dispatch="delegate slot 0xE0",
            purpose="Reject absent ECUs or settings that do not match the ECU type before raw reads.",
            evidence=("Calls getVagSettingAvailabilityForEcu after ECU/type checks.",),
        ),
        ReadValuesOperationFlowStep(
            order=30,
            native_method="VagOperationDelegate::getVagSettingAvailabilityForEcu",
            ghidra_address="0x0127075C",
            dispatch="availability predicate choke point",
            purpose="Select whether a mixed setting branch applies to this exact ECU/PDX/revision.",
            evidence=(
                "Uses the setting type byte first: type 4/5/9 enter the recovered VagSetting::isSubmodule path and call VagOperationDelegate::getVagSettingAvailabilityForSubmodule; types 0/3/7/8 fall through to AvailBy routing.",
                "The recovered submodule helper at x86 0x016c97d0 walks the VagEcuInfo +0x10 submodule vector and calls the setting StringWhitelist at VagSetting +0x54 against each non-null submodule VagEcuInfo full_scan_part_number value at +0x08.",
                "Normal no-AvailBy lighting branches use AvailBy=2, which checks the constructor StringWhitelist against the ECU tag string at VagEcuInfo+0x08.",
                "Other AvailBy routes use VIN-derived PDX/file identifiers and ECU ASAM/revision data.",
                "This is why a visible Carista key cannot be converted directly into one raw DID/write path.",
            ),
        ),
        ReadValuesOperationFlowStep(
            order=40,
            native_method="VagOperationDelegate::readRawValuesMulti",
            ghidra_address="0x01270CF8",
            dispatch="multi-read/cache path",
            purpose="Batch dynamic raw reads after cache checks.",
            evidence=("Static export notes show dynamic raw reads batched in chunks of six after cache checks.",),
        ),
        ReadValuesOperationFlowStep(
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
                "Play 9.8.3 x86 submodule-ID commands are now recovered: GetSubmoduleIdsOverUdsCommand::processPayload parses two 6-byte MSB-first bitmaps; GetVagUdsSubmoduleIdsCommand::processPayload parses even-length 16-bit entries with zero high byte.",
            ),
        ),
        ReadValuesOperationFlowStep(
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


def _core_requests() -> tuple[ReadValueRequest, ...]:
    return (
        ReadValueRequest(
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
                "Play 9.8.3 x86 GetVagCanEcuInfoCommand::processPayloads at 0x00c38ad0 allocates a shared_ptr<vector<shared_ptr<VagEcuInfo>>> and pushes successfully decoded secondary payloads into it for the submodule availability vector.",
                "The processPayloads tail calls allocator<VagEcuInfoWithCoding>::construct via 0x01971aa0; the VagEcuInfo constructor at 0x013c95b0 stores that vector shared_ptr at VagEcuInfo +0x10/+0x14.",
            ),
        ),
        ReadValueRequest(
            order=20,
            request=GetVagCanEcuListCommand_getRequest(),
            native_builder="GetVagCanEcuListCommand::getRequest",
            read_path="VAGCAN20 ECU list/info read",
            setting_key="<ecu_list>",
            status="native_builder_recovered",
            included_by_default=True,
            evidence=("Recovered from Carista native VAGCAN20 request builders.",),
        ),
        ReadValueRequest(
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
        ReadValueRequest(
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


def _vag_can_settings_requests() -> tuple[ReadValueRequest, ...]:
    requests: list[ReadValueRequest] = []
    for index, candidate in enumerate(VagCanSettings_readOnlyCandidates(include_known_rejected=True), start=100):
        rejected = candidate.status.startswith("live_rejected")
        requests.append(
            ReadValueRequest(
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


def ReadValuesOperation_buildPq25BcmPlan() -> ReadValuesOperationPlan:
    return ReadValuesOperationPlan(
        name="ReadValuesOperation PQ25 BCM plan",
        vehicle_scope="VW Polo 6R / PQ25 BCM J519 / 6R0937087K / TP2.0 unit 20",
        source="Official Play-installed Carista 9.8.3 x86 libCarista.so plus local live TP2.0 evidence",
        transport=ReadValuesOperation_transport(),
        native_flow=ReadValuesOperation_nativeFlow(),
        requests=tuple(sorted(_core_requests() + _vag_can_settings_requests() + CARISTA_LIVE_COMPANION_READS, key=lambda item: item.order)),
        unresolved=(
            "Runtime availability predicate objects are not fully reconstructed, so mixed settings remain branch-conditional.",
            "Official x86 direct refs for car_setting_fog_when, car_setting_left_fog_light_as, and car_setting_right_fog_light_as land in FordSettings::getSettings, not VagCanSettings::getSettings; any VW/PQ25 equivalent must come through another VAG key or ReadValuesOperation value path.",
            "Recovered direct lighting UDS-adaptation candidates are modeled as Carista static branches but excluded from default live probes when this BCM returned 7F2231.",
            "The Polo-proven A00F8AFF32FF channel parameter request is a fallback when the exact Carista A00194FF82FF setup does not answer.",
        ),
    )


def ReadValuesOperation_pq25BcmRequests(
    *,
    include_live_companions: bool = False,
    include_known_rejected: bool = False,
) -> tuple[HexString, ...]:
    requests: list[HexString] = []
    for request in ReadValuesOperation_buildPq25BcmPlan().requests:
        if request.status.startswith("live_rejected") and not include_known_rejected:
            continue
        if request.status.startswith("live_positive_companion") and not include_live_companions:
            continue
        if (
            request.included_by_default
            or request.status.startswith("live_positive_companion")
            or (include_known_rejected and request.status.startswith("live_rejected"))
        ):
            requests.append(request.request)
    return tuple(dict.fromkeys(requests))


def ReadValuesOperation_commandLabels(
    *,
    include_live_companions: bool = True,
    include_known_rejected: bool = True,
) -> dict[HexString, str]:
    labels: dict[HexString, str] = {}
    for request in ReadValuesOperation_buildPq25BcmPlan().requests:
        if request.status.startswith("live_rejected") and not include_known_rejected:
            continue
        if request.status.startswith("live_positive_companion") and not include_live_companions:
            continue
        labels[request.request] = (
            f"ReadValuesOperation {request.setting_key}: {request.native_builder}; "
            f"path={request.read_path}; status={request.status}"
        )
    return labels


def _catalog_settings(path: Path) -> list[dict[str, Any]]:
    data = json.loads(path.read_text(encoding="utf-8"))
    settings = data.get("settings")
    if not isinstance(settings, list):
        raise ValueError(f"{path} does not contain a settings list")
    return [setting for setting in settings if isinstance(setting, dict)]


def _boolish(value: object) -> bool:
    return value is True or (isinstance(value, str) and value.lower() == "true")


def _text(setting: dict[str, Any], key: str) -> str:
    value = setting.get(key, "")
    return value if isinstance(value, str) else ""


def _setting_priority(setting: dict[str, Any]) -> tuple[int, str]:
    priority = _text(setting, "priority")
    rank = {
        "highest_recovery_target": 0,
        "medium_recovery_target": 1,
        "resolved_for_current_symptom": 2,
        "review_if_lighting_related": 3,
        "low_context": 4,
        "not_current_focus": 5,
    }.get(priority, 6)
    return rank, _text(setting, "key")


def _is_relevant(setting: dict[str, Any]) -> bool:
    priority = _text(setting, "priority")
    mapping_status = _text(setting, "mapping_status")
    key = _text(setting, "key")
    return (
        priority in {
            "highest_recovery_target",
            "medium_recovery_target",
            "resolved_for_current_symptom",
            "review_if_lighting_related",
            "low_context",
        }
        or mapping_status.startswith("mapped_")
        or "corner" in key
        or "fog_when" in key
        or "fog_light_as" in key
    )


def _setting_recovery(setting: dict[str, Any]) -> VagCanSettingsSettingRecovery | None:
    return VAG_CAN_SETTINGS_RECOVERIES.get(_text(setting, "key"))


def _single_bit_index(mask: int) -> int | None:
    if mask <= 0 or mask & (mask - 1):
        return None
    return mask.bit_length() - 1


def _has_recovered_pq25_coding_evidence(setting_recovery: VagCanSettingsSettingRecovery) -> bool:
    evidence_text = " ".join(
        item
        for item in (
            setting_recovery.native_helper or "",
            setting_recovery.read_method,
            *setting_recovery.evidence,
        )
        if item
    )
    return "Official x86" in evidence_text and (
        "pushes CENTRAL_ELEC_6R_5C_7E_7H" in evidence_text
        or "pushes CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S" in evidence_text
        or "x86 6R/PQ25" in evidence_text
        or "6R/PQ25 byte" in evidence_text
    )


def _recovered_coding_mask(setting: dict[str, Any]) -> tuple[int, int] | None:
    setting_recovery = _setting_recovery(setting)
    if setting_recovery is None:
        return None
    if setting_recovery.immediate_index is None or setting_recovery.immediate_value is None:
        return None
    if not _has_recovered_pq25_coding_evidence(setting_recovery):
        return None
    if setting_recovery.constructor_status in {
        "recovered_non_vag_ford_setting",
        "recovered_non_vag_bmw_setting",
        "refs_only_unresolved",
        "catalog_only_unresolved",
    }:
        return None
    return setting_recovery.immediate_index, setting_recovery.immediate_value


def _pq25_bits(setting: dict[str, Any]) -> str:
    recovered_coding_mask = _recovered_coding_mask(setting)
    if recovered_coding_mask is None:
        return _text(setting, "pq25_bits")
    byte_index, mask = recovered_coding_mask
    bit_index = _single_bit_index(mask)
    if bit_index is None:
        return f"DID 0600 byte {byte_index} mask 0x{mask:02X}"
    return f"DID 0600 byte {byte_index} bit {bit_index} (mask 0x{mask:02X})"


def _coding_mask_state(coding: HexString, byte_index: int, mask: int) -> str:
    data = bytes.fromhex(normalize_coding(coding))
    if not 0 <= byte_index < len(data):
        raise ValueError(f"byte index {byte_index} is outside {len(data)} coding bytes")
    return "set" if data[byte_index] & mask else "clear"


def _has_branch_specific_recovered_choices(setting_recovery: VagCanSettingsSettingRecovery) -> bool:
    if not setting_recovery.choices:
        return False
    if not any(choice.requested_value is None for choice in setting_recovery.choices):
        return False
    evidence_text = " ".join(choice.evidence for choice in setting_recovery.choices)
    return "Branch-specific encoding" in evidence_text or "branch-specific" in evidence_text.lower()


def _current_value_from_coding(setting: dict[str, Any], coding: HexString) -> str:
    recovered_coding_mask = _recovered_coding_mask(setting)
    if recovered_coding_mask is not None:
        byte_index, mask = recovered_coding_mask
        return _coding_mask_state(coding, byte_index, mask)

    setting_recovery = _setting_recovery(setting)
    if setting_recovery is not None and _has_branch_specific_recovered_choices(setting_recovery):
        return "unknown"

    bits = _pq25_bits(setting)
    bit_match = PQ25_BIT_RE.search(bits)
    if bit_match:
        byte_index = int(bit_match.group("byte"))
        bit_index = int(bit_match.group("bit"))
        return bit_state(coding, byte_index, bit_index)
    mask_match = PQ25_MASK_RE.search(bits)
    if mask_match:
        byte_text = mask_match.group("byte")
        byte_index = int(byte_text, 16 if byte_text.lower().startswith("0x") else 10)
        mask = int(mask_match.group("mask"), 16)
        return _coding_mask_state(coding, byte_index, mask)
    return _text(setting, "current_value") or "unknown"


def _possible_values(setting: dict[str, Any]) -> tuple[SettingValueOption, ...]:
    key = _text(setting, "key")
    setting_recovery = _setting_recovery(setting)
    if setting_recovery and setting_recovery.choices:
        return tuple(
            SettingValueOption(
                label=choice.key,
                requested_value=choice.requested_value,
                coding_effect="unknown until Carista raw payload/readback is recovered",
                evidence=choice.evidence,
            )
            for choice in setting_recovery.choices
        )

    if key in CARISTA_INSTRUCTION_CHOICE_LABELS:
        return tuple(
            SettingValueOption(
                label=label,
                requested_value=None,
                coding_effect="unknown",
                evidence="Carista instruction text names this choice; native requested byte[] and coding/adaptation effect are not recovered.",
            )
            for label in CARISTA_INSTRUCTION_CHOICE_LABELS[key]
        )

    bits = _text(setting, "pq25_bits")
    if PQ25_BIT_RE.search(bits):
        return (
            SettingValueOption(
                label="clear",
                requested_value=None,
                coding_effect=f"{bits} clear",
                evidence="Derived from the mapped long-coding bit only; Carista requested byte[] is not recovered.",
            ),
            SettingValueOption(
                label="set",
                requested_value=None,
                coding_effect=f"{bits} set",
                evidence="Derived from the mapped long-coding bit only; Carista requested byte[] is not recovered.",
            ),
        )

    return (
        SettingValueOption(
            label="unknown",
            requested_value=None,
            coding_effect="unknown",
            evidence="Native Setting interpretation/value enum is not recovered for this setting.",
        ),
    )


def _unresolved(setting: dict[str, Any]) -> tuple[str, ...]:
    unresolved = [
        _text(setting, "value_model"),
        _text(setting, "read_method"),
        _text(setting, "write_method"),
    ]
    setting_recovery = _setting_recovery(setting)
    if setting_recovery:
        unresolved.append(setting_recovery.next_re_step)
    return tuple(
        item
        for item in unresolved
        if item and ("not recovered" in item.lower() or "unknown" in item.lower() or "unresolved" in item.lower())
    )


def _value_model(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    if setting_recovery and setting_recovery.choices:
        labels = ", ".join(
            f"{choice.requested_value or '?'}={choice.key}" for choice in setting_recovery.choices
        )
        return f"native choices recovered: {labels}"
    return _text(setting, "value_model")


def _read_method(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    return setting_recovery.read_method if setting_recovery else _text(setting, "read_method")


def _write_method(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    return setting_recovery.write_method if setting_recovery else _text(setting, "write_method")


def _proof_status(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    if not setting_recovery:
        return _text(setting, "proof_status")
    evidence = "; ".join(setting_recovery.evidence)
    return f"{setting_recovery.constructor_status}: {evidence}"


def _mapping_status(setting: dict[str, Any]) -> str:
    setting_recovery = _setting_recovery(setting)
    return setting_recovery.constructor_status if setting_recovery else _text(setting, "mapping_status")


def ReadValuesOperation_buildPq25SettingReport(
    coding: HexString,
    catalog_path: Path = DEFAULT_PQ25_CATALOG_PATH,
) -> ReadValuesOperationSettingReport:
    normalized = normalize_coding(coding)
    settings = [
        ReadValuesOperationSetting(
            key=_text(setting, "key"),
            label=_text(setting, "label"),
            category=_text(setting, "category"),
            pq25_bits=_pq25_bits(setting),
            current_value=_current_value_from_coding(setting, normalized),
            possible_values=_possible_values(setting),
            value_model=_value_model(setting),
            read_method=_read_method(setting),
            write_method=_write_method(setting),
            proof_status=_proof_status(setting),
            priority=_text(setting, "priority"),
            mapping_status=_mapping_status(setting),
            native_string_found=_boolish(setting.get("native_string_found")),
            unresolved=_unresolved(setting),
        )
        for setting in sorted(_catalog_settings(catalog_path), key=_setting_priority)
        if _is_relevant(setting)
    ]
    unresolved_priority = tuple(
        setting
        for setting in settings
        if setting.priority in {"highest_recovery_target", "medium_recovery_target"}
    )
    return ReadValuesOperationSettingReport(
        coding=normalized,
        ecu_name="PQ25 BCM / unit 09 / 6R0937087K",
        source=str(catalog_path),
        settings=tuple(settings),
        unresolved_priority_settings=unresolved_priority,
        warning="Offline ReadValuesOperation catalog view. It is not a live getAvailableItems() dump.",
    )


class ReadValuesOperation:
    buildPq25BcmPlan = staticmethod(ReadValuesOperation_buildPq25BcmPlan)
    pq25BcmRequests = staticmethod(ReadValuesOperation_pq25BcmRequests)
    commandLabels = staticmethod(ReadValuesOperation_commandLabels)
    buildPq25SettingReport = staticmethod(ReadValuesOperation_buildPq25SettingReport)
