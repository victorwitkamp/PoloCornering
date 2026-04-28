from __future__ import annotations

from .Models.CaristaProcessValidation import CaristaProcessValidation
from .Models.CaristaUdsCodingWritePlan import CaristaUdsCodingWritePlan


def render_carista_process_validation(result: CaristaProcessValidation) -> str:
    lines = [
        "Carista VAGCAN reproduction validation",
        "",
        "Recovered request builders:",
        f"  GetVagCanEcuInfoCommand_getRequest: {result.requests.GetVagCanEcuInfoCommand_getRequest}",
        f"  ReadVagCanLongCodingCommand_getRequest: {result.requests.ReadVagCanLongCodingCommand_getRequest}",
        f"  ReadDataByIdentifierCommand_getRequest(F1A5): {result.requests.ReadDataByIdentifierCommand_getRequest_F1A5}",
        f"  GetVagUdsEcuWorkshopCodeCommand_getRequest: {result.requests.GetVagUdsEcuWorkshopCodeCommand_getRequest}",
        f"  WriteVagCodingCommand prefix: {result.requests.WriteVagCodingCommand_prefix}",
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

    lines.extend(["", "ECU metadata:"])
    if result.ecu_info:
        lines.append(
            f"  rawAddress4={result.ecu_info.raw_address4} selector={result.ecu_info.coding_type_selector} "
            f"codingType={result.ecu_info.coding_type} tail={result.ecu_info.tail or '<empty>'}"
        )
    else:
        lines.append("  missing positive 5A9B; do not build or execute complete tuples yet")

    lines.extend(["", "Tuple candidates:"])
    for candidate in result.tuple_candidates:
        if candidate.request:
            lines.append(f"  {candidate.cornering_fix}: {candidate.request} ({candidate.status})")
        else:
            lines.append(f"  {candidate.cornering_fix}: value6 {candidate.value6} ({candidate.status})")

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