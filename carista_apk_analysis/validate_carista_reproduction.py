from __future__ import annotations

import sys
from pathlib import Path

WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
if str(WORKSPACE_ROOT) not in sys.path:
    sys.path.insert(0, str(WORKSPACE_ROOT))

from CaristaReproduction.Commands.WriteDataByIdentifierCommand import WriteDataByIdentifierCommand_getRequest
from CaristaReproduction.CheckSettingsOperation import CheckSettingsOperation_buildPq25BcmPlan
from CaristaReproduction.ReadValuesOperation import (
    CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
    POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST,
    ReadValuesOperation_buildPq25BcmPlan,
    ReadValuesOperation_pq25BcmRequests,
)
from CaristaReproduction.Commands.BaseCommand import BaseCommand_describeNegativePayload, BaseCommand_extractState, BaseCommand_filterOutErrors
from CaristaReproduction.JniBridge import build_jni_bridge_summary
from CaristaReproduction.State import State
from CaristaReproduction.VagCanEcu import VagCanEcu_buildPq25ScanPlan
from CaristaReproduction.VagCanCommunicator import (
    CARISTA_CHANNEL_PARAMETER_ATTEMPTS,
    CARISTA_FINAL_FRAME_ST,
    CARISTA_RECEIVE_MORE_TIMEOUT_SPEC,
    CARISTA_READ_RESPONSES_NEGATIVE_RESPONSE_LIMIT,
    CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT,
    CARISTA_TP20_OPEN_REQUEST_ATTEMPTS,
    CARISTA_NATIVE_T3_MS,
    CARISTA_NON_FINAL_FRAME_ST,
    VAG_CAN_COMMUNICATOR_PARSE_PACKET_RECOVERED_FLOW,
    VAG_CAN_COMMUNICATOR_READ_RESPONSES_DYNAMIC_EVIDENCE,
    VAG_CAN_COMMUNICATOR_READ_RESPONSES_RECOVERED_FLOW,
    ackForReceivedPacket,
    expectedTransmitAck,
    generateOutgoingPackets,
    incrementSeqNum,
    interFramePauseSeconds,
    isOldSeqNum,
    next_counter_after_request,
    sendAck,
    sendNack,
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
    VagOperationDelegate_getVagSettingAvailabilityForEcuRoutes,
    VagOperationDelegate_readVagCanAdaptationValueInternalSequence,
    VagOperationDelegate_readVagUdsAdaptationRawPlan,
    VagOperationDelegate_readRawValueDispatchCases,
    VagOperationDelegate_recoveredConstructorAvailabilityDefaults,
    build_carista_uds_coding_write_plan,
)
from CaristaReproduction.VagCanLongCodingSetting import (
    VagCanLongCodingSetting_ctor_ecu_byte,
    VagCanLongCodingSetting_ctor_ecu_vector,
)
from CaristaReproduction.VagCanShortAdaptationSetting import (
    FullByteVagCanShortAdaptationSetting_ctor,
    VagCanShortAdaptationSetting_ctor_ecu_bitfield,
    VagCanShortAdaptationSetting_ctor_ecu_byte,
    VagCanShortAdaptationSetting_ctor_ecu_vector,
    VagCanShortAdaptationSetting_generateBitmask,
)
from CaristaReproduction.VagUdsAdaptationSetting import (
    VagUdsAdaptationSetting,
    car_setting_cornering_lights_via_fogs_left,
    car_setting_cornering_lights_via_fogs_right,
)
from CaristaReproduction.VagUdsCodingSetting import (
    VagUdsCodingSetting_ctor_ecu_byte,
    VagUdsCodingSetting_ctor_ecu_vector,
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
    assert sendAck(4) == "B5"
    assert sendNack(4) == "94"
    assert ackForReceivedPacket("1400200000000000") == "B5"
    assert incrementSeqNum(0xF) == 0
    assert not isOldSeqNum(1, 0)
    assert isOldSeqNum(8, 9)
    assert interFramePauseSeconds(CARISTA_NATIVE_T3_MS, 50) == 0.13
    assert CARISTA_READ_RESPONSES_NEGATIVE_RESPONSE_LIMIT == 0x1E
    assert CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT == 2
    assert any("three-hex-digit CAN header" in item for item in VAG_CAN_COMMUNICATOR_PARSE_PACKET_RECOVERED_FLOW)
    assert any("sendNack(expectedSeq)" in item for item in VAG_CAN_COMMUNICATOR_READ_RESPONSES_RECOVERED_FLOW)
    assert any("95 positive read records" in item for item in VAG_CAN_COMMUNICATOR_READ_RESPONSES_DYNAMIC_EVIDENCE)

    left = car_setting_cornering_lights_via_fogs_left()
    right = car_setting_cornering_lights_via_fogs_right()
    assert (left.raw_address, left.value_offset, left.requested_value_for_choice("car_setting_on")) == (0x055C, 5, "16")
    assert (right.raw_address, right.value_offset, right.requested_value_for_choice("car_setting_on")) == (0x055D, 5, "17")
    left_proof = " ".join(left.proof_notes)
    right_proof = " ".join(right.proof_notes)
    assert "0x012da25a -> 0x0136c910 -> PLT 0x0197e2f0 VagCanShortAdaptationSetting" in left_proof
    assert "0x012da39a -> 0x01356f90 -> PLT 0x0197d6f0 VagUdsCodingSetting" in left_proof
    assert "CENTRAL_ELEC_MQB_ALL plus [EBX-0x2C9C] CENTRAL_ELEC_MK8" in left_proof
    assert "[EBX-0x2C94] UDS_CAN_GATEWAY_MEB plus [EBX-0x5DF4] CAN_GATEWAY" in left_proof
    assert "0x0136c910 -> VagCanLongCodingSetting" not in left_proof
    assert "0x012da5a9 -> 0x01368690 -> PLT 0x0197e0a0 VagCanLongCodingSetting/NumericalInterpretation" in right_proof
    assert "0x012da6e9 -> 0x0136caf0 -> PLT 0x0197e300 VagUdsAdaptationSetting/MultipleChoiceInterpretation" in right_proof
    assert "CENTRAL_ELEC_MQB_ALL plus [EBX-0x2C9C] CENTRAL_ELEC_MK8" in right_proof
    assert "[EBX-0x2C94] UDS_CAN_GATEWAY_MEB plus [EBX-0x5DF4] CAN_GATEWAY" in right_proof
    assert "0x01368690 -> VagUdsAdaptationSetting/NumericalInterpretation" not in right_proof
    left_read_plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(left)
    assert left_read_plan.native_request == "22055C"
    assert left_read_plan.live_rejected_response == "7F2231"
    assert not left_read_plan.safe_for_write_seed
    right_read_plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(right)
    assert right_read_plan.native_request == "22055D"
    assert right_read_plan.live_rejected_response == "7F2231"
    assert not right_read_plan.safe_for_write_seed
    rejected_output_setting = VagUdsAdaptationSetting(
        ecu="BCM",
        raw_address=0x110E,
        value_offset=2,
        value_mask="01",
        key="car_setting_coming_leaving_home_output_direct_probe",
    )
    rejected_output_plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(rejected_output_setting)
    assert rejected_output_plan.native_request == "22110E"
    assert rejected_output_plan.status == "native_direct_read_live_rejected"
    assert rejected_output_plan.live_rejected_response == "7F2231"
    assert not rejected_output_plan.safe_for_write_seed
    untested_setting = VagUdsAdaptationSetting(
        ecu="BCM",
        raw_address=0x1234,
        value_offset=0,
        value_mask="FF",
        key="car_setting_unknown_unverified_probe",
    )
    untested_read_plan = VagOperationDelegate_readVagUdsAdaptationRawPlan(untested_setting)
    assert untested_read_plan.native_request == "221234"
    assert untested_read_plan.status == "native_direct_read_unverified_live"
    assert not untested_read_plan.safe_for_write_seed
    raw_dispatch = {case.raw_type: case for case in VagOperationDelegate_readRawValueDispatchCases()}
    assert raw_dispatch[0].native_method == "VagOperationDelegate::readVagCanAdaptationValue"
    assert raw_dispatch[7].native_method == "VagOperationDelegate::readVagUdsValue"
    assert raw_dispatch[8].native_method == "VagOperationDelegate::readVagUdsCodingValue"
    assert raw_dispatch[9].native_method == "VagOperationDelegate::readVagUdsSubmoduleValue"
    assert raw_dispatch[10].write_seed_policy == "never a write seed"
    availability_routes = VagOperationDelegate_getVagSettingAvailabilityForEcuRoutes()
    tag_route = next(route for route in availability_routes if route.avail_by_values == (2,))
    assert tag_route.predicate_input == "ECU tag string from VagEcuInfo + 0x08"
    assert "StringWhitelist::itemMatches" in tag_route.availability_result
    assert any(route.avail_by_values == (0, 1, 3, 4) for route in availability_routes)
    assert any(route.avail_by_values == (5,) for route in availability_routes)
    assert any(route.avail_by_values is None and "+0x3c" in route.native_route for route in availability_routes)
    availability_defaults = VagOperationDelegate_recoveredConstructorAvailabilityDefaults()
    assert {default.recovered_avail_by for default in availability_defaults} == {2}
    assert any(default.constructor_family == "VagUdsCodingSetting no-AvailBy VagCanEcu make_shared" for default in availability_defaults)
    assert any(default.constructor_family == "VagCanLongCodingSetting via VagCanCodingSetting" for default in availability_defaults)
    uds_coding_byte = VagUdsCodingSetting_ctor_ecu_byte(0x20, value_offset=0x06)
    assert uds_coding_byte.raw_address == 0x0600
    assert uds_coding_byte.setting_type == 8
    assert uds_coding_byte.value_offset == 0x06
    assert uds_coding_byte.value_mask == "20"
    assert uds_coding_byte.value == "20"
    assert uds_coding_byte.insert_value("00" * 30, "01") == "00" * 6 + "20" + "00" * 23
    assert uds_coding_byte.insert_value("FF" * 30, "00") == "FF" * 6 + "DF" + "FF" * 23
    uds_coding_vector = VagUdsCodingSetting_ctor_ecu_vector("2000", value_offset=0x15)
    assert uds_coding_vector.raw_address == 0x0600
    assert uds_coding_vector.setting_type == 8
    assert uds_coding_vector.value_offset == 0x15
    assert uds_coding_vector.value_mask == "2000"
    long_coding_byte = VagCanLongCodingSetting_ctor_ecu_byte(0x20, value_offset=0x11)
    assert long_coding_byte.raw_address == 0
    assert long_coding_byte.setting_type == 3
    assert long_coding_byte.value_offset == 0x11
    assert long_coding_byte.value_mask == "20"
    assert long_coding_byte.insert_value("00" * 30, "01") == "00" * 0x11 + "20" + "00" * 12
    assert long_coding_byte.insert_value("FF" * 30, "00") == "FF" * 0x11 + "DF" + "FF" * 12
    long_coding_vector = VagCanLongCodingSetting_ctor_ecu_vector("2000", value_offset=0)
    assert long_coding_vector.raw_address == 0
    assert long_coding_vector.setting_type == 3
    assert long_coding_vector.value_mask == "2000"
    assert long_coding_vector.insert_value("00" * 30, "01") == "2000" + "00" * 28
    assert long_coding_vector.insert_value("FF" * 30, "00") == "DFFF" + "FF" * 28
    short_adaptation_byte = VagCanShortAdaptationSetting_ctor_ecu_byte(
        raw_address=0x5C,
        value_offset=1,
        value=0x04,
    )
    assert short_adaptation_byte.raw_address == 0x5C
    assert short_adaptation_byte.setting_type == 0
    assert short_adaptation_byte.value_offset == 1
    assert short_adaptation_byte.value_mask == "04"
    assert short_adaptation_byte.insert_value("0000", "01") == "0004"
    assert short_adaptation_byte.insert_value("FFFF", "00") == "FFFB"
    short_adaptation_vector = VagCanShortAdaptationSetting_ctor_ecu_vector(
        raw_address=0x5C,
        value_offset=0,
        value="FFFF",
    )
    assert short_adaptation_vector.insert_value("0000", "1234") == "1234"
    full_byte_short_adaptation = FullByteVagCanShortAdaptationSetting_ctor(0x5C)
    assert full_byte_short_adaptation.raw_address == 0x5C
    assert full_byte_short_adaptation.value_offset == 0
    assert full_byte_short_adaptation.value_mask == "FFFF"
    assert full_byte_short_adaptation.insert_value("0000", "001E") == "001E"
    assert VagCanShortAdaptationSetting_generateBitmask(2, 3) == 0x1C
    short_adaptation_bitfield = VagCanShortAdaptationSetting_ctor_ecu_bitfield(
        raw_address=0x5C,
        start_bit=2,
        num_bits=3,
    )
    assert short_adaptation_bitfield.value_offset == 1
    assert short_adaptation_bitfield.value_mask == "1C"
    assert short_adaptation_bitfield.insert_value("0000", "05") == "0014"
    short_adaptation_sequence = VagOperationDelegate_readVagCanAdaptationValueInternalSequence(0x5C)
    assert [step.request for step in short_adaptation_sequence.steps] == [
        "31B80103",
        "31BA0103",
        "31B901035C",
        "31BA0103",
        "32B80103",
    ]
    assert "raw type 7" in short_adaptation_sequence.evidence[-1]
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
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_left"].native_helper, "VagCanShortAdaptationSetting")
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_left"].native_helper, "0x01356f90")
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_left"].native_helper, "VagUdsCodingSetting")
    assert "0x012da55f" in setting_recoveries["car_setting_cornering_lights_via_fogs_right"].reference_address
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_right"].native_helper, "0x01368690")
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_right"].native_helper, "VagCanLongCodingSetting")
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_right"].native_helper, "0x0136caf0")
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_right"].native_helper, "VagUdsAdaptationSetting")
    assert setting_recoveries["car_setting_cornering_lights_via_fogs"].value_offset == 0x0C
    assert setting_recoveries["car_setting_cornering_lights_via_fogs"].value_mask == "40"
    assert setting_recoveries["car_setting_cornering_lights_via_fogs"].immediate_value == 0x40
    assert setting_recoveries["car_setting_cornering_lights_via_fogs"].immediate_index == 0x0C
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs"].native_helper, "0x012d9f7b")
    assert "CENTRAL_ELEC_6R_5C_7E_7H" in " ".join(setting_recoveries["car_setting_cornering_lights_via_fogs"].evidence)
    assert setting_recoveries["car_setting_cornering_lights_via_fogs_experimental"].immediate_value == 0x80
    assert setting_recoveries["car_setting_cornering_lights_via_fogs_experimental"].immediate_index == 0x15
    assert_contains(setting_recoveries["car_setting_cornering_lights_via_fogs_experimental"].native_helper, "0x012da0f2")
    assert setting_recoveries["car_setting_cornering_lights_with_turn_signals"].immediate_value == 0x04
    assert setting_recoveries["car_setting_cornering_lights_with_turn_signals"].immediate_index == 0x15
    assert "0x012da72c" in setting_recoveries["car_setting_cornering_lights_with_turn_signals"].reference_address
    assert_contains(setting_recoveries["car_setting_cornering_lights_with_turn_signals"].native_helper, "0x012da761")
    assert "CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S" in " ".join(setting_recoveries["car_setting_cornering_lights_with_turn_signals"].evidence)
    assert setting_recoveries["car_setting_fog_when"].constructor_status == "recovered_non_vag_ford_setting"
    assert setting_recoveries["car_setting_fog_when"].constructor_kind == "FordCodingSetting"
    assert "_ZN12FordSettings11getSettingsEv" in setting_recoveries["car_setting_fog_when"].native_function
    assert_contains(setting_recoveries["car_setting_fog_when"].native_helper, "0x00ee30b0")
    assert setting_recoveries["car_setting_left_fog_light_as"].constructor_kind == "FordUdsSetting"
    assert_contains(setting_recoveries["car_setting_left_fog_light_as"].native_helper, "0x00ee03b0")
    assert setting_recoveries["car_setting_right_fog_light_as"].constructor_kind == "FordUdsSetting"
    assert_contains(setting_recoveries["car_setting_right_fog_light_as"].native_helper, "0x00ee59f0")
    assert setting_recoveries["car_setting_cornering_lights_with_turn_signals_one_touch"].constructor_kind == "BmwESetting"
    assert setting_recoveries["car_setting_cornering_lights_with_turn_signals_one_touch"].constructor_status == "recovered_non_vag_bmw_setting"
    assert_contains(setting_recoveries["car_setting_cornering_lights_with_turn_signals_one_touch"].native_helper, "0x00d7eec0")
    assert setting_recoveries["car_setting_coming_home_req_rls"].constructor_kind == "mixed"
    assert setting_recoveries["car_setting_coming_home_req_rls"].raw_address == 0x0A57
    assert_contains(setting_recoveries["car_setting_coming_home_req_rls"].native_helper, "010D8FE4")
    assert_contains(setting_recoveries["car_setting_coming_home_req_rls"].native_helper, "010D917C")
    assert setting_recoveries["car_setting_coming_home_req_rls"].immediate_value == 0x20
    assert setting_recoveries["car_setting_coming_home_req_rls"].immediate_index == 0x11
    assert setting_recoveries["car_setting_coming_home"].value_offset == 4
    assert setting_recoveries["car_setting_coming_home"].immediate_value == 0x02
    assert setting_recoveries["car_setting_coming_home"].immediate_index == 0x06
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
    low_beam_choices = {choice.key: choice.requested_value for choice in setting_recoveries["car_setting_coming_home_via_low_beams"].choices}
    assert low_beam_choices == {"car_setting_no": "00", "car_setting_yes": "01"}
    assert setting_recoveries["car_setting_coming_leaving_home_output"].raw_address == 0x110E
    assert setting_recoveries["car_setting_coming_leaving_home_output"].constructor_kind == "mixed"
    assert "0x012c88d0" in setting_recoveries["car_setting_coming_leaving_home_output"].reference_address
    assert_contains(setting_recoveries["car_setting_coming_leaving_home_output"].native_helper, "0x0133fdf0")
    assert_contains(setting_recoveries["car_setting_coming_leaving_home_output"].native_helper, "0x010CCBC8")
    assert "40/0D" in " ".join(setting_recoveries["car_setting_coming_leaving_home_output"].evidence)
    output_choices = {choice.key: choice for choice in setting_recoveries["car_setting_coming_leaving_home_output"].choices}
    assert output_choices["car_setting_fogs"].requested_value is None
    assert "byte 11/mask 08 table stores fogs=01" in output_choices["car_setting_fogs"].evidence
    assert output_choices["car_setting_low_beams"].requested_value is None
    assert "byte 11/mask 08 table stores low_beams=00" in output_choices["car_setting_low_beams"].evidence
    assert setting_recoveries["car_setting_leaving_home_req_rls"].constructor_kind == "mixed"
    assert setting_recoveries["car_setting_leaving_home_req_rls"].immediate_value == 0x02
    assert setting_recoveries["car_setting_leaving_home_req_rls"].immediate_index == 0x0A
    assert_contains(setting_recoveries["car_setting_leaving_home_req_rls"].native_helper, "010DAD6C")
    assert setting_recoveries["car_setting_leaving_home"].constructor_kind == "VagUdsCodingSetting"
    assert setting_recoveries["car_setting_leaving_home"].immediate_value == 0x04
    assert setting_recoveries["car_setting_leaving_home"].immediate_index == 0x06
    assert_contains(setting_recoveries["car_setting_leaving_home"].native_helper, "010BC404")
    leaving_home_choices = {choice.key: choice.requested_value for choice in setting_recoveries["car_setting_leaving_home"].choices}
    assert leaving_home_choices == {"car_setting_disabled": "00", "car_setting_enabled": "01"}
    assert setting_recoveries["car_setting_leaving_home_duration"].raw_address == 0x0A57
    assert setting_recoveries["car_setting_leaving_home_duration"].value_offset == 5
    assert_contains(setting_recoveries["car_setting_leaving_home_duration"].native_helper, "010BF9DC")
    assert_contains(setting_recoveries["car_setting_leaving_home_duration"].native_helper, "010DB380")
    assert setting_recoveries["car_setting_drl_via_fogs"].raw_address == 0x055C
    assert setting_recoveries["car_setting_drl_via_fogs"].value_offset == 6
    assert setting_recoveries["car_setting_drl_via_fogs"].constructor_kind == "mixed"
    assert setting_recoveries["car_setting_drl_via_fogs"].immediate_value == 0x04
    assert setting_recoveries["car_setting_drl_via_fogs"].immediate_index == 0x17
    assert "0x012cde7b" in setting_recoveries["car_setting_drl_via_fogs"].reference_address
    assert_contains(setting_recoveries["car_setting_drl_via_fogs"].native_helper, "0x01361520")
    assert setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].raw_address == 0x0D01
    assert setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].constructor_kind == "mixed"
    assert setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].immediate_value == 0x20
    assert setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].immediate_index == 0x15
    assert "0x012d4db5" in setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].reference_address
    assert_contains(setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].native_helper, "0x0135e580")
    high_beam_choices = {choice.key: choice.requested_value for choice in setting_recoveries["car_setting_turn_off_fogs_with_high_beam"].choices}
    assert high_beam_choices == {"car_setting_no": "00", "car_setting_yes": "01"}
    assert setting_recoveries["car_setting_assist_dr_lights"].constructor_kind == "mixed"
    assert setting_recoveries["car_setting_assist_dr_lights"].immediate_value == 0x20
    assert setting_recoveries["car_setting_assist_dr_lights"].immediate_index == 0x16
    assert "0x012d9b78" in setting_recoveries["car_setting_assist_dr_lights"].reference_address
    assert_contains(setting_recoveries["car_setting_assist_dr_lights"].native_helper, "0x013625a0")
    assert setting_recoveries["car_setting_front_fogs_with_low_beams"].constructor_status == "recovered_non_vag_ford_setting"
    assert setting_recoveries["car_setting_front_fogs_with_low_beams"].constructor_kind == "FordUdsSetting"
    assert_contains(setting_recoveries["car_setting_front_fogs_with_low_beams"].native_helper, "00E8FBE4")
    assert setting_recoveries["car_setting_fogs_with_high_beam_restriction"].constructor_kind == "FordCodingSetting"
    assert_contains(setting_recoveries["car_setting_fogs_with_high_beam_restriction"].native_helper, "00E8D43C")

    native_settings_by_key = VagCanSettings_nativeSettingsByKey()
    assert VAG_CAN_SETTINGS_GET_SETTINGS_SYMBOL == "_ZN14VagCanSettings11getSettingsEv"
    assert VAG_CAN_SETTINGS_GET_SETTINGS_ADDRESS == "0x012a20c0"
    assert VAG_CAN_SETTINGS_GET_SETTINGS_EBX_BASE == "0x01a35618"
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_left"].helpers[0].target == "0x0136c910"
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_left"].helpers[0].family.startswith("VagCanShortAdaptationSetting")
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_left"].helpers[1].target == "0x01356f90"
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_left"].helpers[1].family.startswith("VagUdsCodingSetting")
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_right"].helpers[0].target == "0x01368690"
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_right"].helpers[0].family.startswith("VagCanLongCodingSetting")
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_right"].helpers[1].target == "0x0136caf0"
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_right"].helpers[1].family.startswith("VagUdsAdaptationSetting")
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs"].helpers[1].callsite == "0x012d9f7b"
    assert any("byte 0x0c mask 0x40" in item for item in native_settings_by_key["car_setting_cornering_lights_via_fogs"].recovered_shape)
    assert native_settings_by_key["car_setting_cornering_lights_via_fogs_experimental"].helpers[0].callsite == "0x012da0f2"
    assert native_settings_by_key["car_setting_cornering_lights_with_turn_signals"].string_ref == "0x012da72c"
    assert native_settings_by_key["car_setting_cornering_lights_with_turn_signals"].helpers[0].callsite == "0x012da761"
    assert any("byte 0x17 mask 0x04" in item for item in native_settings_by_key["car_setting_drl_via_fogs"].recovered_shape)
    assert native_settings_by_key["car_setting_coming_leaving_home_output"].read_candidate_dids == (0x110E,)
    default_vag_can_settings_requests = VagCanSettings_readOnlyDidRequests()
    assert default_vag_can_settings_requests == ()
    known_rejected_vag_can_settings_requests = VagCanSettings_readOnlyDidRequests(include_known_rejected=True)
    assert "22110E" in known_rejected_vag_can_settings_requests
    assert "22056D" in known_rejected_vag_can_settings_requests
    assert "220D01" in known_rejected_vag_can_settings_requests
    assert "220A57" in known_rejected_vag_can_settings_requests
    assert "22055C" not in default_vag_can_settings_requests
    assert "22055C" in known_rejected_vag_can_settings_requests

    read_values_plan = ReadValuesOperation_buildPq25BcmPlan()
    transport = {step.name: step.value for step in read_values_plan.transport}
    assert transport["carista_exact_channel_parameters"] == CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST
    assert transport["polo_live_proven_channel_parameters"] == POLO_LIVE_PROVEN_CHANNEL_PARAMETER_REQUEST
    assert transport["non_final_tp20_frame_timeout"] == CARISTA_NON_FINAL_FRAME_ST
    assert transport["final_tp20_frame_timeout"] == CARISTA_FINAL_FRAME_ST
    assert transport["native_t3_inter_frame_pause_ms"] == str(CARISTA_NATIVE_T3_MS)
    assert transport["receive_more_keep_alive"] == f"A3 with timeout/spec 0x{CARISTA_RECEIVE_MORE_TIMEOUT_SPEC:X}"
    assert f"open_sends={CARISTA_TP20_OPEN_REQUEST_ATTEMPTS}" in transport["native_channel_open_retry_shape"]
    assert f"param_sends={CARISTA_CHANNEL_PARAMETER_ATTEMPTS}" in transport["native_channel_open_retry_shape"]
    native_flow_methods = {step.native_method for step in read_values_plan.native_flow}
    assert "ReadValuesOperation::readItemAvailabilityAndValues" in native_flow_methods
    assert "VagOperationDelegate::readRawValuesMulti" in native_flow_methods
    assert "VagOperationDelegate::readRawValue" in native_flow_methods
    default_read_values_requests = ReadValuesOperation_pq25BcmRequests()
    assert default_read_values_requests == (
        "1A9B",
        "1A9F",
        "1A9A",
        "220600",
    )
    assert "22055C" not in default_read_values_requests
    assert "220601" not in default_read_values_requests
    rejected_read_values_requests = ReadValuesOperation_pq25BcmRequests(include_known_rejected=True)
    assert "22055C" in rejected_read_values_requests
    assert "22055D" in rejected_read_values_requests
    assert "22110E" in rejected_read_values_requests
    assert "220A57" in rejected_read_values_requests
    companion_read_values_requests = ReadValuesOperation_pq25BcmRequests(include_live_companions=True)
    assert companion_read_values_requests == default_read_values_requests + ("220601", "220606")
    removed_obd_runners = (
        "run_carista_read_values.py",
        "vw_tp20_readonly_probe.py",
        "capture_bcm_light_state.py",
        "run_bcm_light_capture.ps1",
        "collect_drive_diagnostics.ps1",
        "write_pq25_lighting_profile.py",
        "run_next_pq25_lighting_write.ps1",
        "write_carista_uds_coding.py",
    )
    for runner in removed_obd_runners:
        assert not (WORKSPACE_ROOT / "obd-on-pc" / runner).exists()

    removed_package_runner_layers = (
        "ReadValuesOperationLive.py",
        "VagCanLiveTransport.py",
    )
    for module in removed_package_runner_layers:
        assert not (WORKSPACE_ROOT / "CaristaReproduction" / module).exists()

    scan_plan = VagCanEcu_buildPq25ScanPlan()
    assert tuple(ecu.ecu_id for ecu in scan_plan.discoverable_ecus) == ("PQ25_BCM_UNIT_09",)
    assert tuple(ecu.tp20_unit_address for ecu in scan_plan.discoverable_ecus) == ("20",)
    assert any("VagOperationDelegate::getEcuList(bool)" in item for item in scan_plan.discovery_flow)
    assert any("GetVagCanEcuListCommand::getRequest" in item and "1A9F" in item for item in scan_plan.discovery_flow)
    assert any("VagOperationDelegate::getVagEcuList(bool)" in item and "obd2RequestNotSupported" in item for item in scan_plan.discovery_flow)
    assert any("VagOperationDelegate::sortEcuList" in item and "VagEcu::values" in item for item in scan_plan.discovery_flow)
    assert scan_plan.probes[0].channel_parameter_request == CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST
    scan_requests = [command.request for command in scan_plan.probes[0].commands]
    assert scan_requests[:4] == ["1A9B", "1A9F", "1A9A", "220600"]
    assert "22110E" not in scan_requests
    assert "220D01" not in scan_requests
    assert "220A57" not in scan_requests
    assert "22055C" not in scan_requests
    assert any("establishEcuComm" in item and "response-derived headers" in item for item in scan_plan.unresolved)
    assert any("wrapper vtable call order is recovered" in item for item in scan_plan.unresolved)

    check_settings_plan = CheckSettingsOperation_buildPq25BcmPlan(CURRENT)
    check_settings_methods = {step.native_method for step in check_settings_plan.native_flow}
    assert "ConnectionManager::runCommand / Communicator::runCommand" in check_settings_methods
    assert "CheckSettingsOperation::initNative" in check_settings_methods
    assert "GetEcuInfoOperation::initNative" in check_settings_methods
    assert "VagCanCommunicator::postInitialize / VagCanCommunicator::establishEcuComm" in check_settings_methods
    assert "VagCanCommunicator::parsePacket / VagCanCommunicator::readResponses" in check_settings_methods
    assert "ReadValuesOperation::readItemAvailabilityAndValues" in check_settings_methods
    assert "ReadValuesOperation::getAvailableItems" in check_settings_methods
    assert "ReadValuesOperation::getSettingValue" in check_settings_methods
    assert check_settings_plan.vag_can_ecu_scan_plan.probes[0].tp20_open_request == "20C00010000301"
    assert tuple(ecu.ecu_id for ecu in check_settings_plan.vag_can_ecu_scan_plan.discoverable_ecus) == ("PQ25_BCM_UNIT_09",)
    check_settings_scan_requests = [command.request for command in check_settings_plan.vag_can_ecu_scan_plan.probes[0].commands]
    assert tuple(check_settings_scan_requests) == default_read_values_requests
    assert check_settings_plan.read_values_operation_setting_report is not None
    check_settings_setting_keys = {setting.key for setting in check_settings_plan.read_values_operation_setting_report.settings}
    assert "car_setting_cornering_lights_via_fogs_left" in check_settings_setting_keys
    assert "car_setting_coming_home_req_rls" in check_settings_setting_keys
    assert "22055C" not in check_settings_scan_requests
    first_step_evidence = " ".join(check_settings_plan.native_flow[0].evidence)
    assert "up to four attempts" in first_step_evidence
    assert "Two consecutive -0x0B no-data results" in first_step_evidence
    communicator_step = next(
        step
        for step in check_settings_plan.native_flow
        if step.native_method == "VagCanCommunicator::postInitialize / VagCanCommunicator::establishEcuComm"
    )
    communicator_evidence = " ".join(communicator_step.evidence)
    assert "sends the open request up to four times" in communicator_evidence
    assert "It sends one TP2.0 keep-alive/request-more packet A3" in communicator_evidence
    parser_step = next(
        step
        for step in check_settings_plan.native_flow
        if step.native_method == "VagCanCommunicator::parsePacket / VagCanCommunicator::readResponses"
    )
    parser_evidence = " ".join(parser_step.evidence)
    assert "95 positive read records" in parser_evidence
    assert any("Result/vector object model" in item for item in check_settings_plan.unresolved)
    assert not any("all-ECU discovery list" in item for item in check_settings_plan.unresolved)

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
