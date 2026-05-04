from __future__ import annotations

from .Models.CaristaCustomization import CaristaCustomizationScanReport
from .Models.CaristaProcessValidation import CaristaProcessValidation
from .Models.CaristaReadValuesOperation import CaristaReadValuesPlan
from .Models.CaristaUdsCodingWritePlan import CaristaUdsCodingWritePlan
from .Models.JniBridge import JniBridgeSummary
from .Models.VagCanEcu import VagCanEcuScanPlan
from .Pq25CurrentSettings import UNMODELED_CARISTA_GROUPS, pq25_current_setting_states
from .Types import HexString
from .VagCanSettings import VagCanSettingsSettingRecovery
from .VagUdsAdaptationSetting import VagUdsAdaptationSetting


def render_carista_process_validation(result: CaristaProcessValidation) -> str:
    lines = [
        "Carista VAGCAN reproduction validation",
        "",
        "Recovered request builders:",
        f"  GetVagCanEcuInfoCommand_getRequest: {result.requests.GetVagCanEcuInfoCommand_getRequest}",
        f"  GetVagCanEcuListCommand_getRequest: {result.requests.GetVagCanEcuListCommand_getRequest}",
        f"  ReadVagCanLongCodingCommand_getRequest: {result.requests.ReadVagCanLongCodingCommand_getRequest}",
        f"  ReadDataByIdentifierCommand_getRequest(F1A5): {result.requests.ReadDataByIdentifierCommand_getRequest_F1A5}",
        f"  GetVagUdsEcuWorkshopCodeCommand_getRequest: {result.requests.GetVagUdsEcuWorkshopCodeCommand_getRequest}",
        f"  WriteDataByIdentifierCommand_getRequest(0600): {result.requests.WriteDataByIdentifierCommand_getRequest_0600}",
        f"  StartReadVagCanRoutineCommand_getRequest(0103): {result.requests.StartReadVagCanRoutineCommand_getRequest_0103}",
        f"  PreReadVagCanAdaptationDataCommand_getRequest(0103): {result.requests.PreReadVagCanAdaptationDataCommand_getRequest_0103}",
        f"  SetVagCanAdaptationChannelCommand_getRequest(0103, 5C): {result.requests.SetVagCanAdaptationChannelCommand_getRequest_0103_5C}",
        f"  ReadVagCanShortAdaptationDataCommand_getRequest(0103): {result.requests.ReadVagCanShortAdaptationDataCommand_getRequest_0103}",
        f"  StopReadVagCanRoutineCommand_getRequest(0103): {result.requests.StopReadVagCanRoutineCommand_getRequest_0103}",
        "",
        f"Current coding: {result.coding.value}",
        f"Coding length:  {result.coding.length_bytes} bytes",
        "",
        "Validation gates:",
    ]
    for gate in result.gates:
        lines.append(f"  {gate.status.upper():5} {gate.name}: {gate.detail}")

    lines.extend(["", "Mapped PQ25 supported settings:"])
    for setting in result.supported_settings:
        lines.append(
            f"  {setting.cornering_fix}: {setting.key} byte {setting.byte_index} bit {setting.bit_index} "
            f"{setting.current_state} -> {setting.desired_state}, value6 {setting.target_value6}"
        )

    lines.extend(["", "Compact 1A9B metadata:"])
    if result.ecu_info:
        lines.append(
            f"  rawAddress4={result.ecu_info.raw_address4} selector={result.ecu_info.coding_type_selector} "
            f"codingType={result.ecu_info.coding_type} tail={result.ecu_info.tail or '<empty>'}"
        )
    else:
        lines.append("  not required for the active UDS DID 0600 writer")

    return "\n".join(lines) + "\n"


def render_carista_uds_coding_write_plan(plan: CaristaUdsCodingWritePlan) -> str:
    lines = [
        "Carista UDS coding write plan",
        "",
        f"Current coding: {plan.current_coding}",
        f"Target coding:  {plan.target_coding}",
        "",
        "Changed bytes:",
    ]
    for index, (old, new) in plan.changed_bytes.items():
        lines.append(f"  byte {index}: {old} -> {new}")
    if not plan.changed_bytes:
        lines.append("  none")

    lines.extend(["", "Recovered Carista UDS request sequence:"])
    for request in plan.requests:
        lines.append(f"  {request.label}: {request.request}")

    lines.extend(
        [
            "",
            "Proof anchors:",
            "  VagUdsCodingSetting(ecu, vector) hardcodes DID 0600 and setting type 8.",
            "  writeRawValue dispatches type 8 into writeVagUdsValue.",
            "  writeVagUdsValue sends DATE_WRITE_ID F199, reads ECU info for workshop code, sends WORKSHOP_CODE_WRITE_ID F198, then target DID 0600.",
            "  F199/F198 are gated with isFatalFail; the final target result is returned after native state mapping.",
        ]
    )
    return "\n".join(lines) + "\n"


def render_jni_bridge_summary(summary: JniBridgeSummary) -> str:
    lines = ["Carista JNI bridge summary", "", "Validated native exports:"]
    for validation in summary.validations:
        lines.append(f"  {validation.status.upper():7} {validation.label}: {validation.export_file}")
        for missing in validation.missing_evidence:
            lines.append(f"    missing evidence: {missing}")

    lines.extend(["", "ChangeSettingOperation flow:"])
    for step in summary.operation_flow:
        lines.append(f"  {step.order}. {step.proven_call} [{step.source}]")
        lines.append(f"     evidence: {step.evidence}")
        if step.unresolved:
            lines.append(f"     unresolved: {step.unresolved}")

    lines.extend(["", "ReadValuesOperation virtual slots:"])
    for slot in summary.read_values_slots:
        lines.append(f"  {slot.java_method}: {slot.slot_offset}")
        lines.append(f"     input: {slot.proven_input}")
        lines.append(f"     output: {slot.proven_output}")
        lines.append(f"     unresolved: {slot.unresolved_target}")

    return "\n".join(lines) + "\n"


def render_pq25_current_settings(coding: HexString) -> str:
    states = pq25_current_setting_states(coding)
    lines = ["Carista-style PQ25 current settings", "", "Evidence-backed settings:"]
    for state in states:
        lines.append(
            f"  {state.label}: {state.state} (byte {state.byte_index} bit {state.bit_index}, current byte {state.current_byte})"
        )
        lines.append(f"     confidence: {state.confidence}")
        for unresolved in state.unresolved:
            lines.append(f"     unresolved: {unresolved}")

    lines.extend(["", "Not rendered as Carista settings yet:"])
    for group in UNMODELED_CARISTA_GROUPS:
        lines.append(f"  {group}: native Setting catalog entry not recovered")
    return "\n".join(lines) + "\n"


def render_vag_can_ecu_scan_plan(plan: VagCanEcuScanPlan) -> str:
    lines = [
        "Carista-style VAGCAN ECU scan plan",
        "",
        f"Adapter:  {plan.adapter}",
        f"Protocol: {plan.protocol}",
        "",
        "ECU probes:",
    ]
    for probe in plan.probes:
        lines.extend(
            [
                f"  {probe.ecu.ecu_id}: {probe.ecu.name}",
                f"     TP2.0 unit address: {probe.ecu.tp20_unit_address}",
                f"     TP2.0 open request: {probe.tp20_open_request}",
                f"     expected channel: send={probe.expected_send_header or '<unknown>'} listen={probe.expected_listen_header or '<unknown>'}",
                f"     channel parameters: {probe.channel_parameter_request}",
            ]
        )
        if probe.ecu.expected_part_number:
            lines.append(f"     expected part: {probe.ecu.expected_part_number}")
        if probe.ecu.expected_component:
            lines.append(f"     expected component: {probe.ecu.expected_component}")
        lines.append("     read-only probe commands:")
        for command in probe.commands:
            safety = "read-only" if command.read_only else "not read-only"
            lines.append(f"       {command.request}: {command.native_builder} ({safety})")
            lines.append(f"          {command.purpose}")

    lines.extend(["", "Unresolved:"])
    for item in plan.unresolved:
        lines.append(f"  {item}")
    return "\n".join(lines) + "\n"


def render_carista_read_values_plan(plan: CaristaReadValuesPlan) -> str:
    lines = [
        "Carista ReadValuesOperation plan",
        "",
        f"Name:    {plan.name}",
        f"Vehicle: {plan.vehicle_scope}",
        f"Source:  {plan.source}",
        "",
        "Transport profile:",
    ]
    for step in plan.transport:
        lines.append(f"  {step.order}. {step.name}: {step.value}")
        lines.append(f"     {step.purpose}")
        for evidence in step.evidence:
            lines.append(f"     evidence: {evidence}")

    lines.extend(["", "Native read/value flow:"])
    for step in plan.native_flow:
        lines.append(f"  {step.order}. {step.native_method} [{step.ghidra_address}]")
        lines.append(f"     dispatch: {step.dispatch}")
        lines.append(f"     purpose: {step.purpose}")
        for evidence in step.evidence:
            lines.append(f"     evidence: {evidence}")

    lines.extend(["", "Read requests:"])
    for request in plan.requests:
        default = "default" if request.included_by_default else "modeled-only"
        lines.append(f"  {request.order}. {request.request}: {request.setting_key} ({default}, {request.status})")
        lines.append(f"     builder: {request.native_builder}")
        lines.append(f"     path: {request.read_path}")
        for evidence in request.evidence:
            lines.append(f"     evidence: {evidence}")

    lines.extend(["", "Unresolved:"])
    for item in plan.unresolved:
        lines.append(f"  {item}")
    return "\n".join(lines) + "\n"


def render_needle_sweep_settings(settings: tuple[VagUdsAdaptationSetting, ...]) -> str:
    lines = [
        "Carista VAG UDS cluster needle-sweep candidates",
        "",
        "Recovered native shape:",
        "  FullByteVagUdsAdaptationSetting -> VagUdsAdaptationSetting type 7",
        "  full-byte mask: FF",
        "",
        "Settings:",
    ]
    for setting in settings:
        lines.extend(
            [
                f"  {setting.key}",
                f"     ecu: {setting.ecu}",
                f"     raw address: {setting.raw_address:04X}",
                f"     offset: {setting.value_offset}",
                f"     value mask: {setting.value_mask}",
                f"     setting type: {setting.setting_type}",
                f"     native constructor: {setting.native_constructor}",
                f"     native source: {setting.native_source}",
            ]
        )
        for note in setting.proof_notes:
            lines.append(f"     proof: {note}")
    lines.extend(
        [
            "",
            "Safety boundary:",
            "  Treat the raw address as a Carista adaptation raw address until a positive read confirms the protocol.",
            "  The next car-side step is read-only 2222A2 on cluster header 714, not a write.",
        ]
    )
    return "\n".join(lines) + "\n"


def render_fog_setting_candidates(settings: tuple[VagUdsAdaptationSetting, ...]) -> str:
    lines = [
        "Carista VAG UDS fog/cornering candidates",
        "",
        "Recovered native shape:",
        "  VAG-path keys hit VagUdsAdaptationSetting type 7 constructors",
        "  direct left_fog_light_as/right_fog_light_as string refs also exist, but those first refs are Ford-path",
        "  native type 7 dispatch is readVagUdsValue -> ReadRawDataByIdentifierCommand, not the 31B8/31BA routine path",
        "",
        "Settings:",
    ]
    for setting in settings:
        lines.extend(
            [
                f"  {setting.key}",
                f"     ecu: {setting.ecu}",
                f"     raw address: {setting.raw_address:04X}",
                f"     value offset: {setting.value_offset}",
                f"     value mask: {setting.value_mask}",
                f"     setting type: {setting.setting_type}",
                f"     native constructor: {setting.native_constructor}",
                f"     native source: {setting.native_source}",
            ]
        )
        for note in setting.proof_notes:
            lines.append(f"     proof: {note}")
        if setting.choices:
            lines.append("     recovered choices:")
            for choice in setting.choices:
                lines.append(f"       {choice.requested_value} = {choice.key}")
    lines.extend(
        [
            "",
            "Safety boundary:",
            "  055C/055D direct native reads are 22055C/22055D, and both were rejected live as 7F2231 on this BCM/session.",
            "  The recovered 31B8/31BA/31B9/32B8 sequence is a native VAG CAN adaptation path, but it is not proven to apply to these type 7 UDS settings.",
            "  Do not write these until a positive Carista-shaped read proves the current raw payload and byte length.",
        ]
    )
    return "\n".join(lines) + "\n"


def render_vag_can_settings_setting_recoveries(recoveries: tuple[VagCanSettingsSettingRecovery, ...]) -> str:
    lines = [
        "VagCanSettings setting recovery map",
        "",
        "Purpose:",
        "  Keep recovered native constructor facts separate from guessed write plans.",
        "  Anything marked constructor_partial, refs_only_unresolved, or catalog_only_unresolved is not write-safe.",
        "",
        "Settings:",
    ]
    for recovery in recoveries:
        lines.extend(
            [
                f"  {recovery.key}: {recovery.label}",
                f"     status: {recovery.constructor_status}",
                f"     ecu: {recovery.ecu}",
                f"     native function: {recovery.native_function}",
                f"     reference: {recovery.reference_address}",
                f"     constructor kind: {recovery.constructor_kind}",
                f"     helper: {recovery.native_helper or '<unrecovered>'}",
            ]
        )
        if recovery.instruction_window:
            lines.append(f"     instruction window: {recovery.instruction_window}")
        if recovery.raw_address is not None:
            lines.append(f"     raw address: {recovery.raw_address:04X}")
        if recovery.value_offset is not None:
            lines.append(f"     value offset: {recovery.value_offset}")
        if recovery.value_mask:
            lines.append(f"     value mask: {recovery.value_mask}")
        if recovery.immediate_value is not None:
            lines.append(f"     immediate value: 0x{recovery.immediate_value:02X}")
        if recovery.immediate_index is not None:
            lines.append(f"     immediate index/field: 0x{recovery.immediate_index:02X}")
        if recovery.choices:
            lines.append("     choices:")
            for choice in recovery.choices:
                value = choice.requested_value or "<unrecovered>"
                lines.append(f"       {choice.key}: {value} ({choice.evidence})")
        lines.append(f"     read: {recovery.read_method}")
        lines.append(f"     write: {recovery.write_method}")
        lines.append(f"     next RE: {recovery.next_re_step}")
        for item in recovery.evidence:
            lines.append(f"     evidence: {item}")

    return "\n".join(lines) + "\n"


def render_pq25_customization_scan(report: CaristaCustomizationScanReport) -> str:
    lines = [
        "Carista-style PQ25 customization scan",
        "",
        f"ECU:    {report.ecu_name}",
        f"Coding: {report.coding}",
        f"Source: {report.source}",
        f"Note:   {report.warning}",
        "",
        "Current settings and possible values:",
    ]
    for setting in report.settings:
        bits = f" [{setting.pq25_bits}]" if setting.pq25_bits else ""
        lines.append(f"  {setting.key}: {setting.label}{bits}")
        lines.append(f"     current: {setting.current_value or 'unknown'}")
        values = ", ".join(option.label for option in setting.possible_values)
        lines.append(f"     possible values: {values}")
        lines.append(f"     proof: {setting.proof_status}")
        if setting.priority in {"highest_recovery_target", "medium_recovery_target"}:
            lines.append(f"     priority: {setting.priority}")
        for item in setting.unresolved:
            lines.append(f"     unresolved: {item}")

    if report.unresolved_priority_settings:
        lines.extend(["", "Priority unresolved native Setting objects:"])
        for setting in report.unresolved_priority_settings:
            lines.append(f"  {setting.key}: {setting.label}")
            lines.append(f"     status: {setting.mapping_status}")
            lines.append(f"     write: {setting.write_method}")
    return "\n".join(lines) + "\n"
