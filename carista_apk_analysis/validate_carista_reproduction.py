from __future__ import annotations

import sys
from pathlib import Path

WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
if str(WORKSPACE_ROOT) not in sys.path:
    sys.path.insert(0, str(WORKSPACE_ROOT))

from CaristaReproduction.Commands.WriteDataByIdentifierCommand import WriteDataByIdentifierCommand_getRequest
from CaristaReproduction.CaristaReadValuesOperation import (
    CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
    POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST,
    CaristaReadValuesOperation_buildPq25BcmPlan,
    CaristaReadValuesOperation_pq25BcmRequests,
)
from CaristaReproduction.Commands.BaseCommand import BaseCommand_describeNegativePayload, BaseCommand_extractState, BaseCommand_filterOutErrors
from CaristaReproduction.JniBridge import build_jni_bridge_summary
from CaristaReproduction.State import State
from CaristaReproduction.VagCanEcu import VagCanEcu_buildPq25ScanPlan
from CaristaReproduction.VagCanCommunicator import (
    CARISTA_FINAL_FRAME_ST,
    CARISTA_NATIVE_T3_MS,
    CARISTA_NON_FINAL_FRAME_ST,
    ackForReceivedPacket,
    expectedTransmitAck,
    generateOutgoingPackets,
    interFramePauseSeconds,
    next_counter_after_request,
)
from CaristaReproduction.VagCanSettings import VagCanSettings_getPq25SettingRecoveries
from CaristaReproduction.VagCanSettings import (
    VAG_CAN_SETTINGS_GET_SETTINGS_ADDRESS,
    VAG_CAN_SETTINGS_GET_SETTINGS_EBX_BASE,
    VAG_CAN_SETTINGS_GET_SETTINGS_SYMBOL,
    VagCanSettings_nativeSettingsByKey,
    VagCanSettings_readOnlyDidRequests,
)
from CaristaReproduction.VagEcuInfo import VagEcuInfo_getWorkshopCodeForWriting
from CaristaReproduction.VagOperationDelegate import (
    VagOperationDelegate_buildVagUdsAdaptationWriteRequests,
    VagOperationDelegate_readVagUdsAdaptationRawPlan,
    VagOperationDelegate_readRawValueDispatchCases,
    build_carista_uds_coding_write_plan,
)
from CaristaReproduction.VagUdsAdaptationSetting import (
    VagUdsAdaptationSetting,
    car_setting_cornering_lights_via_fogs_left,
    car_setting_cornering_lights_via_fogs_right,
)


CURRENT = "3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000"
TARGET = "3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000"


def assert_contains(haystack: str | None, needle: str) -> None:
    assert haystack is not None
    assert needle in haystack


def main() -> int:
    assert WriteDataByIdentifierCommand_getRequest(0xF198, "0005F3C7E719") == "2EF1980005F3C7E719"
    assert BaseCommand_extractState("7F2224") == State.OBD2_REQUEST_SEQUENCE_ERROR
    assert BaseCommand_extractState("7F2233") == State.OBD2_SECURITY_ACCESS_DENIED
    assert "responsePending" in BaseCommand_describeNegativePayload("7F2E78")
    pending_then_positive = BaseCommand_filterOutErrors(["7F2E78", "6EF198"])
    assert not pending_then_positive.isFail()
    assert pending_then_positive.value == ["6EF198"]

    plan = build_carista_uds_coding_write_plan(CURRENT, TARGET, workshop_code_payload="0005F3C7E719")
    assert [request.did for request in plan.requests] == [0xF199, 0xF198, 0x0600]
    assert plan.requests[1].request == "2EF1980005F3C7E719"
    assert plan.requests[-1].request == "2E0600" + TARGET
    assert VagEcuInfo_getWorkshopCodeForWriting("0005F3C7E719") == "0005F3C7E719"

    target_packets = generateOutgoingPackets(0, "2E0600" + TARGET)
    assert [packet.raw for packet in target_packets] == [
        "2000212E06003AB8",
        "212B9F08A1000000",
        "223008006C680ED0",
        "2300C8412F60A600",
        "1400200000000000",
    ]
    assert next_counter_after_request(0, "2E0600" + TARGET) == 5
    assert expectedTransmitAck(5) == "B5"
    assert ackForReceivedPacket("1400200000000000") == "B5"
    assert interFramePauseSeconds(CARISTA_NATIVE_T3_MS, 50) == 0.13

    left = car_setting_cornering_lights_via_fogs_left()
    right = car_setting_cornering_lights_via_fogs_right()
    assert (left.raw_address, left.value_offset, left.requested_value_for_choice("car_setting_on")) == (0x055C, 5, "16")
    assert (right.raw_address, right.value_offset, right.requested_value_for_choice("car_setting_on")) == (0x055D, 5, "17")
    left_read_plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(left)
    assert left_read_plan.native_request == "22055C"
    assert left_read_plan.live_rejected_response == "7F2231"
    assert not left_read_plan.safe_for_write_seed
    untested_setting = VagUdsAdaptationSetting(
        ecu="BCM",
        raw_address=0x110E,
        value_offset=2,
        value_mask="01",
        key="car_setting_coming_leaving_home_output_unverified_probe",
    )
    untested_read_plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(untested_setting)
    assert untested_read_plan.native_request == "22110E"
    assert untested_read_plan.status == "native_direct_read_unverified_live"
    assert not untested_read_plan.safe_for_write_seed
    raw_dispatch = {case.raw_type: case for case in VagOperationDelegate_readRawValueDispatchCases()}
    assert raw_dispatch[0].native_method == "VagOperationDelegate::readVagCanAdaptationValue"
    assert raw_dispatch[7].native_method == "VagOperationDelegate::readVagUdsValue"
    assert raw_dispatch[8].native_method == "VagOperationDelegate::readVagUdsCodingValue"
    assert raw_dispatch[9].native_method == "VagOperationDelegate::readVagUdsSubmoduleValue"
    assert raw_dispatch[10].write_seed_policy == "never a write seed"
    try:
        VagOperationDelegate_buildVagUdsAdaptationWriteRequests(
            left,
            "00000000000000",
            "car_setting_on",
            workshop_code_payload="0005F3C7E719",
        )
    except RuntimeError as exc:
        assert "cannot be written safely" in str(exc)
    else:
        raise AssertionError("blocked 055C write request unexpectedly built")

    setting_recoveries = {recovery.key: recovery for recovery in VagCanSettings_getPq25SettingRecoveries()}
    assert setting_recoveries["car_setting_cornering_lights_via_fogs_left"].raw_address == 0x055C
    assert setting_recoveries["car_setting_cornering_lights_via_fogs_right"].raw_address == 0x055D
    assert "0x012da210" in setting_recoveries["car_setting_cornering_lights_via_fogs_left"].reference_address
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_left"].native_helper, "0x0136c910")
    assert "0x012da55f" in setting_recoveries["car_setting_cornering_lights_via_fogs_right"].reference_address
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_right"].native_helper, "0x01368690")
    assert setting_recoveries["car_setting_coming_home_req_rls"].constructor_kind == "mixed"
    assert setting_recoveries["car_setting_coming_home_req_rls"].raw_address == 0x0A57
    assert_contains(setting_recoveries["car_setting_coming_home_req_rls"].native_helper, "010D8FE4")
    assert_contains(setting_recoveries["car_setting_coming_home_req_rls"].native_helper, "010D917C")
    assert setting_recoveries["car_setting_coming_home"].value_offset == 4
    assert_contains(setting_recoveries["car_setting_coming_home"].native_helper, "010D92EC")
    assert_contains(setting_recoveries["car_setting_coming_home"].native_helper, "010C2700")
    assert setting_recoveries["car_setting_coming_home_mode"].value_mask == "03"
    assert_contains(setting_recoveries["car_setting_coming_home_mode"].native_helper, "010D9484")
    assert_contains(setting_recoveries["car_setting_coming_home_mode"].native_helper, "010D9608")
    assert setting_recoveries["car_setting_coming_home_duration"].value_offset == 3
    assert_contains(setting_recoveries["car_setting_coming_home_duration"].native_helper, "010DA7BC")
    assert_contains(setting_recoveries["car_setting_coming_home_duration"].native_helper, "010DA910")
    assert setting_recoveries["car_setting_coming_home_via_fogs"].immediate_value == 0x20
    assert setting_recoveries["car_setting_coming_home_via_fogs"].constructor_kind == "mixed"
    assert "0x012c929b" in setting_recoveries["car_setting_coming_home_via_fogs"].reference_address
    assert_contains(setting_recoveries["car_setting_coming_home_via_fogs"].native_helper, "0x01340190")
    assert setting_recoveries["car_setting_coming_home_via_low_beams"].immediate_value == 0x10
    assert setting_recoveries["car_setting_coming_home_via_low_beams"].constructor_kind == "mixed"
    assert "0x012c8a55" in setting_recoveries["car_setting_coming_home_via_low_beams"].reference_address
    assert setting_recoveries["car_setting_coming_leaving_home_output"].raw_address == 0x110E
    assert setting_recoveries["car_setting_coming_leaving_home_output"].constructor_kind == "mixed"
    assert "0x012c88d0" in setting_recoveries["car_setting_coming_leaving_home_output"].reference_address
    assert_contains(setting_recoveries["car_setting_coming_leaving_home_output"].native_helper, "0x0133fdf0")
    assert_contains(setting_recoveries["car_setting_coming_leaving_home_output"].native_helper, "0x010CCBC8")
    assert "40/0D" in " ".join(setting_recoveries["car_setting_coming_leaving_home_output"].evidence)
    assert setting_recoveries["car_setting_leaving_home_req_rls"].constructor_kind == "mixed"
    assert_contains(setting_recoveries["car_setting_leaving_home_req_rls"].native_helper, "010DAD6C")
    assert setting_recoveries["car_setting_leaving_home"].constructor_kind == "VagUdsCodingSetting"
    assert_contains(setting_recoveries["car_setting_leaving_home"].native_helper, "010BC404")
    assert setting_recoveries["car_setting_leaving_home_duration"].raw_address == 0x0A57
    assert setting_recoveries["car_setting_leaving_home_duration"].value_offset == 5
    assert_contains(setting_recoveries["car_setting_leaving_home_duration"].native_helper, "010BF9DC")
    assert_contains(setting_recoveries["car_setting_leaving_home_duration"].native_helper, "010DB380")
    assert setting_recoveries["car_setting_drl_via_fogs"].raw_address == 0x055C
    assert setting_recoveries["car_setting_drl_via_fogs"].value_offset == 6
    assert setting_recoveries["car_setting_drl_via_fogs"].constructor_kind == "mixed"
    assert "0x012cde7b" in setting_recoveries["car_setting_drl_via_fogs"].reference_address
    assert_contains(setting_recoveries["car_setting_drl_via_fogs"].native_helper, "0x01361520")
    assert setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].raw_address == 0x0D01
    assert setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].constructor_kind == "mixed"
    assert "0x012d4db5" in setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].reference_address
    assert_contains(setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].native_helper, "0x0135e580")
    assert setting_recoveries["car_setting_assist_dr_lights"].constructor_kind == "mixed"
    assert setting_recoveries["car_setting_assist_dr_lights"].immediate_index == 0x16
    assert "0x012d9b78" in setting_recoveries["car_setting_assist_dr_lights"].reference_address
    assert_contains(setting_recoveries["car_setting_assist_dr_lights"].native_helper, "0x013625a0")
    assert setting_recoveries["car_setting_front_fogs_with_low_beams"].constructor_status == "catalog_only_unresolved"

    native_settings_by_key = VagCanSettings_nativeSettingsByKey()
    assert VAG_CAN_SETTINGS_GET_SETTINGS_SYMBOL == "_ZN14VagCanSettings11getSettingsEv"
    assert VAG_CAN_SETTINGS_GET_SETTINGS_ADDRESS == "0x012a20c0"
    assert VAG_CAN_SETTINGS_GET_SETTINGS_EBX_BASE == "0x01a35618"
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_left"].helpers[0].target == "0x0136c910"
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_right"].helpers[0].target == "0x01368690"
    assert native_settings_by_key["car_setting_coming_leaving_home_output"].read_candidate_dids == (0x110E,)
    default_vag_can_settings_requests = VagCanSettings_readOnlyDidRequests()
    assert "22110E" in default_vag_can_settings_requests
    assert "22056D" in default_vag_can_settings_requests
    assert "220D01" in default_vag_can_settings_requests
    assert "22055C" not in default_vag_can_settings_requests
    assert "22055C" in VagCanSettings_readOnlyDidRequests(include_known_rejected=True)

    read_values_plan = CaristaReadValuesOperation_buildPq25BcmPlan()
    transport = {step.name: step.value for step in read_values_plan.transport}
    assert transport["carista_exact_channel_parameters"] == CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST
    assert transport["polo_live_proven_channel_parameters"] == POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST
    assert transport["non_final_tp20_frame_timeout"] == CARISTA_NON_FINAL_FRAME_ST
    assert transport["final_tp20_frame_timeout"] == CARISTA_FINAL_FRAME_ST
    assert transport["native_t3_inter_frame_pause_ms"] == str(CARISTA_NATIVE_T3_MS)
    native_flow_methods = {step.native_method for step in read_values_plan.native_flow}
    assert "ReadValuesOperation::readItemAvailabilityAndValues" in native_flow_methods
    assert "VagOperationDelegate::readRawValuesMulti" in native_flow_methods
    assert "VagOperationDelegate::readRawValue" in native_flow_methods
    default_read_values_requests = CaristaReadValuesOperation_pq25BcmRequests()
    assert default_read_values_requests[:4] == ("1A9B", "1A9F", "1A9A", "220600")
    assert "22110E" in default_read_values_requests
    assert "220D01" in default_read_values_requests
    assert "22055C" not in default_read_values_requests
    assert "220601" not in default_read_values_requests
    companion_read_values_requests = CaristaReadValuesOperation_pq25BcmRequests(include_live_companions=True)
    assert "220601" in companion_read_values_requests

    scan_plan = VagCanEcu_buildPq25ScanPlan()
    assert scan_plan.probes[0].channel_parameter_request == CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST
    scan_requests = [command.request for command in scan_plan.probes[0].commands]
    assert scan_requests[:4] == ["1A9B", "1A9F", "1A9A", "220600"]
    assert "22110E" in scan_requests
    assert "220D01" in scan_requests
    assert "22055C" not in scan_requests

    summary = build_jni_bridge_summary()
    statuses = {validation.label: validation.status for validation in summary.validations}
    assert statuses["com.prizmos.carista.library.operation.ReadValuesOperation.getAvailableItems"] == "found"
    assert statuses["com.prizmos.carista.library.operation.ReadValuesOperation.getSettingValue"] == "found"
    assert {slot.slot_offset for slot in summary.read_values_slots} == {"0x7c", "0x8c"}
    native_flow_statuses = {validation.label: validation.status for validation in summary.read_values_native_flow_validations}
    assert all(status == "found" for status in native_flow_statuses.values())
    jni_native_flow_methods = {step.native_method for step in summary.read_values_native_flow}
    assert "ReadValuesOperation::readItemAvailabilityAndValues" in jni_native_flow_methods
    assert "VagOperationDelegate::getVagSettingAvailabilityForEcu" in jni_native_flow_methods
    assert "VagOperationDelegate::readRawValue" in jni_native_flow_methods

    print("Carista reproduction proof checks passed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
