from __future__ import annotations

import argparse
import json
import sys
from dataclasses import asdict
from pathlib import Path
from typing import cast

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from CaristaReproduction.CaristaClock import parse_iso_date
from CaristaReproduction.CaristaReadValuesOperation import CaristaReadValuesOperation_buildPq25BcmPlan
from CaristaReproduction.Commands.GetVagCanEcuInfoCommand import GetVagCanEcuInfoCommand_processEcuInfo, read_first_positive_ecu_info
from CaristaReproduction.Commands.GetVagCanEcuInfoCommand import GetVagCanEcuInfoCommand_getRequest
from CaristaReproduction.Commands.GetVagCanEcuListCommand import GetVagCanEcuListCommand_getRequest
from CaristaReproduction.Commands.GetVagUdsEcuWorkshopCodeCommand import GetVagUdsEcuWorkshopCodeCommand_getRequest
from CaristaReproduction.Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from CaristaReproduction.Commands.ReadVagCanLongCodingCommand import ReadVagCanLongCodingCommand_getRequest
from CaristaReproduction.Commands.VagCanAdaptationCommands import (
    READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID,
    PreReadVagCanAdaptationDataCommand_getRequest,
    ReadVagCanShortAdaptationDataCommand_getRequest,
    SetVagCanAdaptationChannelCommand_getRequest,
    StartReadVagCanRoutineCommand_getRequest,
    StopReadVagCanRoutineCommand_getRequest,
)
from CaristaReproduction.Constants import CORNERING_FIXES
from CaristaReproduction.JniBridge import build_jni_bridge_summary
from CaristaReproduction.Pq25CaristaCatalog import build_pq25_customization_scan_report
from CaristaReproduction.Renderers import (
    render_carista_process_validation,
    render_carista_read_values_plan,
    render_carista_uds_coding_write_plan,
    render_fog_setting_candidates,
    render_jni_bridge_summary,
    render_needle_sweep_settings,
    render_pq25_current_settings,
    render_pq25_customization_scan,
    render_vag_can_settings_setting_recoveries,
    render_vag_can_ecu_scan_plan,
)
from CaristaReproduction.Types import CorneringFixKey
from CaristaReproduction.VagCanEcu import VagCanEcu_buildPq25ScanPlan
from CaristaReproduction.VagCanSettings import VagCanSettings_getPq25SettingRecoveries
from CaristaReproduction.VagCoding import apply_cornering_fixes, normalize_coding, read_coding
from CaristaReproduction.VagOperationDelegate import build_carista_uds_coding_write_plan, validate_carista_process
from CaristaReproduction.VagUdsAdaptationSetting import (
    car_setting_cornering_lights_via_fogs_left,
    car_setting_cornering_lights_via_fogs_right,
    car_setting_instr_needle_sweep,
    car_setting_instr_needle_sweep_method_b,
)


def _print_request(function_name: str) -> int:
    if function_name == "GetVagCanEcuInfoCommand_getRequest":
        print(GetVagCanEcuInfoCommand_getRequest())
        return 0
    if function_name == "ReadVagCanLongCodingCommand_getRequest":
        print(ReadVagCanLongCodingCommand_getRequest())
        return 0
    if function_name == "GetVagCanEcuListCommand_getRequest":
        print(GetVagCanEcuListCommand_getRequest())
        return 0
    if function_name == "ReadDataByIdentifierCommand_getRequest_F1A5":
        print(ReadDataByIdentifierCommand_getRequest(0xF1A5))
        return 0
    if function_name == "GetVagUdsEcuWorkshopCodeCommand_getRequest":
        print(GetVagUdsEcuWorkshopCodeCommand_getRequest())
        return 0
    if function_name == "StartReadVagCanRoutineCommand_getRequest_0103":
        print(StartReadVagCanRoutineCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID))
        return 0
    if function_name == "PreReadVagCanAdaptationDataCommand_getRequest_0103":
        print(PreReadVagCanAdaptationDataCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID))
        return 0
    if function_name == "SetVagCanAdaptationChannelCommand_getRequest_0103_5C":
        print(SetVagCanAdaptationChannelCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID, 0x5C))
        return 0
    if function_name == "ReadVagCanShortAdaptationDataCommand_getRequest_0103":
        print(ReadVagCanShortAdaptationDataCommand_getRequest())
        return 0
    if function_name == "StopReadVagCanRoutineCommand_getRequest_0103":
        print(StopReadVagCanRoutineCommand_getRequest(READ_VAG_CAN_SHORT_ADAPTATION_BASIC_ID))
        return 0
    raise ValueError(f"unknown request builder {function_name}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Python reproduction of recovered Carista VAGCAN coding helpers.")
    parser.add_argument(
        "--print-request",
        choices=(
            "GetVagCanEcuInfoCommand_getRequest",
            "GetVagCanEcuListCommand_getRequest",
            "ReadVagCanLongCodingCommand_getRequest",
            "ReadDataByIdentifierCommand_getRequest_F1A5",
            "GetVagUdsEcuWorkshopCodeCommand_getRequest",
            "StartReadVagCanRoutineCommand_getRequest_0103",
            "PreReadVagCanAdaptationDataCommand_getRequest_0103",
            "SetVagCanAdaptationChannelCommand_getRequest_0103_5C",
            "ReadVagCanShortAdaptationDataCommand_getRequest_0103",
            "StopReadVagCanRoutineCommand_getRequest_0103",
        ),
        help="Print a recovered read request literal and exit.",
    )
    parser.add_argument("--decode-ecu-info", help="Decode a positive 5A9B ECU-info response using Carista offsets.")
    parser.add_argument("--validate-workflow", action="store_true", help="Validate the full recovered Carista-like PQ25 workflow.")
    parser.add_argument("--coding", help="Current long-coding hex or raw 620600/5A9A response for workflow validation.")
    parser.add_argument("--coding-file", help="File containing current long coding or direct-read JSON summary.")
    parser.add_argument("--ecu-info-response", help="Optional positive 5A9B response for workflow validation.")
    parser.add_argument("--ecu-info-file", action="append", type=Path, default=[], help="JSON/text file to scan for a positive 5A9B response. Can be repeated.")
    parser.add_argument("--json-output", type=Path, help="Optional JSON output path.")
    parser.add_argument("--jni-bridge-summary", action="store_true", help="Print recovered JNI/native bridge evidence and unresolved ReadValuesOperation slots.")
    parser.add_argument("--jni-export-dir", type=Path, help="Override exact-flow JNI export directory for --jni-bridge-summary.")
    parser.add_argument("--ecu-scan-plan", action="store_true", help="Print the current Carista-shaped PQ25 ECU scan plan.")
    parser.add_argument("--read-values-plan", action="store_true", help="Print the recovered Carista ReadValuesOperation PQ25 BCM read plan.")
    parser.add_argument(
        "--needle-sweep-settings",
        action="store_true",
        help="Print recovered Carista-shaped cluster needle-sweep setting candidates.",
    )
    parser.add_argument(
        "--fog-setting-candidates",
        action="store_true",
        help="Print recovered Carista-shaped VAG fog/cornering setting candidates.",
    )
    parser.add_argument(
        "--vag-can-settings-recoveries",
        action="store_true",
        help="Print the current VagCanSettings recovery map, including unresolved fog/high-beam/CH-LH settings.",
    )
    parser.add_argument("--current-settings", action="store_true", help="Print evidence-backed Carista-style current setting states for the supplied coding.")
    parser.add_argument("--customization-scan", action="store_true", help="Print the offline Carista-style supported customization/current-value view.")
    parser.add_argument("--catalog-file", type=Path, help="Override pq25_carista_setting_catalog.json for --customization-scan.")
    parser.add_argument("--uds-write-plan", action="store_true", help="Print the recovered Carista UDS DID 0600 write plan.")
    parser.add_argument("--target-coding", help="Explicit target long coding for --uds-write-plan.")
    parser.add_argument(
        "--apply-cornering-fix",
        action="append",
        choices=sorted(CORNERING_FIXES),
        help="For --uds-write-plan, derive target coding by setting a known cornering bit. Can be repeated.",
    )
    parser.add_argument("--workshop-code", help="6-byte workshop-code payload, usually from 22F1A5 without the 62F1A5 prefix.")
    parser.add_argument("--date", dest="date_value", help="Date for F199 payload as YYYY-MM-DD. Defaults to today.")
    args = parser.parse_args()

    if args.print_request:
        return _print_request(args.print_request)
    if args.decode_ecu_info:
        metadata = GetVagCanEcuInfoCommand_processEcuInfo(args.decode_ecu_info)
        if metadata is None:
            print("No positive 5A9B metadata decoded.")
            return 1
        print(json.dumps(asdict(metadata), indent=2, sort_keys=True))
        return 0
    if args.jni_bridge_summary:
        summary = build_jni_bridge_summary(args.jni_export_dir) if args.jni_export_dir else build_jni_bridge_summary()
        print(render_jni_bridge_summary(summary), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(summary), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0
    if args.ecu_scan_plan:
        ecu_scan_plan = VagCanEcu_buildPq25ScanPlan()
        print(render_vag_can_ecu_scan_plan(ecu_scan_plan), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(ecu_scan_plan), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0
    if args.read_values_plan:
        read_values_plan = CaristaReadValuesOperation_buildPq25BcmPlan()
        print(render_carista_read_values_plan(read_values_plan), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(read_values_plan), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0
    if args.needle_sweep_settings:
        settings = (car_setting_instr_needle_sweep(), car_setting_instr_needle_sweep_method_b())
        print(render_needle_sweep_settings(settings), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            payload = json.dumps([asdict(setting) for setting in settings], indent=2) + "\n"
            args.json_output.write_text(payload, encoding="utf-8")
        return 0
    if args.fog_setting_candidates:
        settings = (car_setting_cornering_lights_via_fogs_left(), car_setting_cornering_lights_via_fogs_right())
        print(render_fog_setting_candidates(settings), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            payload = json.dumps([asdict(setting) for setting in settings], indent=2) + "\n"
            args.json_output.write_text(payload, encoding="utf-8")
        return 0
    if args.vag_can_settings_recoveries:
        recoveries = VagCanSettings_getPq25SettingRecoveries()
        print(render_vag_can_settings_setting_recoveries(recoveries), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            payload = json.dumps([asdict(recovery) for recovery in recoveries], indent=2) + "\n"
            args.json_output.write_text(payload, encoding="utf-8")
        return 0
    if args.current_settings:
        coding = read_coding(args.coding, args.coding_file)
        if coding is None:
            raise ValueError("--current-settings requires --coding or --coding-file")
        print(render_pq25_current_settings(coding), end="")
        return 0
    if args.customization_scan:
        coding = read_coding(args.coding, args.coding_file)
        if coding is None:
            raise ValueError("--customization-scan requires --coding or --coding-file")
        report = (
            build_pq25_customization_scan_report(coding, catalog_path=args.catalog_file)
            if args.catalog_file
            else build_pq25_customization_scan_report(coding)
        )
        print(render_pq25_customization_scan(report), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(report), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0
    if args.validate_workflow:
        coding = read_coding(args.coding, args.coding_file)
        if coding is None:
            raise ValueError("--validate-workflow requires --coding or --coding-file")
        ecu_info = None
        if args.ecu_info_response:
            ecu_info = GetVagCanEcuInfoCommand_processEcuInfo(args.ecu_info_response)
            if ecu_info is None:
                raise ValueError("--ecu-info-response did not contain positive 5A9B metadata")
        if ecu_info is None and args.ecu_info_file:
            ecu_info = read_first_positive_ecu_info(args.ecu_info_file)
        result = validate_carista_process(coding, ecu_info)
        print(render_carista_process_validation(result), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(result), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0
    if args.uds_write_plan:
        coding = read_coding(args.coding, args.coding_file)
        if coding is None:
            raise ValueError("--uds-write-plan requires --coding or --coding-file")
        if args.target_coding:
            target = normalize_coding(args.target_coding)
        else:
            fixes = tuple(args.apply_cornering_fix or ("base-fog", "turn-signal"))
            target = apply_cornering_fixes(coding, cast(tuple[CorneringFixKey, ...], fixes))
        if not args.workshop_code:
            raise ValueError("--uds-write-plan requires --workshop-code from a positive 22F1A5 read")
        uds_write_plan = build_carista_uds_coding_write_plan(
            coding,
            target,
            workshop_code_payload=args.workshop_code,
            date_value=parse_iso_date(args.date_value),
        )
        print(render_carista_uds_coding_write_plan(uds_write_plan), end="")
        if args.json_output:
            args.json_output.parent.mkdir(parents=True, exist_ok=True)
            args.json_output.write_text(json.dumps(asdict(uds_write_plan), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return 0

    parser.print_help()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
