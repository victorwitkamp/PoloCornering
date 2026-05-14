from __future__ import annotations

from .Commands.VagDiagnosticCommands import (
    GetVagCanTroubleCodesCommand_getRequest,
    GetVagUdsTroubleCodesCommand_getRequest,
    ReadVagUdsExtRecordByDtcCommand_getRequest,
    ReadVagUdsSnapshotRecordByDtcCommand_getRequest,
)
from .Models.VagDiagnosticsOperation import (
    VagDiagnosticLogFinding,
    VagDiagnosticRequest,
    VagDiagnosticTransportFinding,
    VagDiagnosticsOperationPlan,
)
from .VagCanCommunicator import (
    CARISTA_CHANNEL_PARAMETER_ATTEMPTS,
    CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS,
    CARISTA_READ_RESPONSES_NEGATIVE_RESPONSE_LIMIT,
    CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT,
    CARISTA_TP20_OPEN_REQUEST_ATTEMPTS,
)


KNOWN_UDS_DTC_FROM_LOGS = "C40100"
INCOMPLETE_UDS_DTC_FROM_LOGS = "D20000"


def VagDiagnosticsOperation_pq25BcmReadOnlyRequests(*, include_known_detail: bool = False) -> tuple[str, ...]:
    requests = [
        GetVagCanTroubleCodesCommand_getRequest(),
        GetVagUdsTroubleCodesCommand_getRequest(),
    ]
    if include_known_detail:
        requests.extend(
            [
                ReadVagUdsExtRecordByDtcCommand_getRequest(KNOWN_UDS_DTC_FROM_LOGS),
                ReadVagUdsSnapshotRecordByDtcCommand_getRequest(KNOWN_UDS_DTC_FROM_LOGS),
            ]
        )
    return tuple(dict.fromkeys(requests))


def _diagnostic_requests() -> tuple[VagDiagnosticRequest, ...]:
    return (
        VagDiagnosticRequest(
            order=1,
            request=GetVagCanTroubleCodesCommand_getRequest(),
            command_name="GetVagCanTroubleCodesCommand",
            ecu_scope="VagCanEcu / PQ25 BCM TP2.0",
            purpose="Read KWP/VAG DTC records by status mask.",
            safety_class="read-only",
            status="candidate request bytes live-observed; native class recovered",
            included_in_bcm_profile=True,
            evidence=(
                "runCheckFaultsDebugCommands selects GetVagCanTroubleCodesCommand for VagCanEcu.",
                "Latest BCM all-safe capture returned 1802FF00 -> 5800.",
                "Earlier BCM fault-status capture returned 1802FF00 -> 58010C9820.",
            ),
        ),
        VagDiagnosticRequest(
            order=2,
            request=GetVagUdsTroubleCodesCommand_getRequest(),
            command_name="GetVagUdsTroubleCodesCommand",
            ecu_scope="VagUdsEcu and module-aware UDS header scans",
            purpose="Read UDS DTC records by status mask.",
            safety_class="read-only",
            status="candidate request bytes live-observed; rejected on BCM but positive on other UDS modules",
            included_in_bcm_profile=True,
            evidence=(
                "runCheckFaultsDebugCommands selects GetVagUdsTroubleCodesCommand for non-VagCanEcu/Uds path.",
                "BCM TP2.0 returned 1902FF -> 7F1911.",
                "UDS header scans returned 711->77B 1902FF -> 590299D20000 and 714->77E 1902FF -> 590299C4010008.",
            ),
            unresolved=(
                "Current pq25_read_monitor is BCM/TP2.0 only; a future module-aware UDS runner should use this request per UDS header.",
            ),
        ),
        VagDiagnosticRequest(
            order=3,
            request=ReadVagUdsExtRecordByDtcCommand_getRequest(KNOWN_UDS_DTC_FROM_LOGS),
            command_name="ReadVagUdsExtRecordByDtcCommand",
            ecu_scope="VagUdsEcu / DTC-specific detail",
            purpose="Read UDS extended data for a known DTC.",
            safety_class="read-only",
            status="candidate request bytes live-observed on UDS header 714/77E",
            included_in_bcm_profile=False,
            evidence=(
                "runFreezeFrameDebugCommands creates ReadVagUdsExtRecordByDtcCommand-style reads after DTC discovery.",
                "Retained scan returned 714->77E 1906C40100FF -> 5906C4010008.",
            ),
        ),
        VagDiagnosticRequest(
            order=4,
            request=ReadVagUdsSnapshotRecordByDtcCommand_getRequest(KNOWN_UDS_DTC_FROM_LOGS),
            command_name="UDS reportDTCSnapshotRecordByDTCNumber candidate",
            ecu_scope="VagUdsEcu / DTC-specific snapshot",
            purpose="Probe UDS snapshot record for a known DTC when Carista freeze-frame paths require it.",
            safety_class="read-only",
            status="adjacent candidate; retained log returned 7F1912 for C40100 on 711/77B",
            included_in_bcm_profile=False,
            evidence=(
                "runFreezeFrameDebugCommands has a separate freeze-frame/detail loop after DTC discovery.",
                "Retained scan contains 1904C40100FF -> 7F1912 on 711/77B and 1904D20000FF -> 7F1912 on 714/77E.",
            ),
            unresolved=(
                "The exact Carista string constants used to label snapshot vs extended detail are not decoded yet.",
            ),
        ),
    )


def _log_findings() -> tuple[VagDiagnosticLogFinding, ...]:
    return (
        VagDiagnosticLogFinding(
            response="58010C9820",
            translation="KWP positive DTC response with one VAG-style DTC candidate 03224, status 0x20 raw bit b5.",
            carista_symbol="GetVagCanTroubleCodesCommand / GetTroubleCodesModel",
            evidence=(
                "docs/OBD_DIAGNOSTICS/session_artifacts/bcm_fault_status_20260502_1905_direct_read_summary.json",
            ),
        ),
        VagDiagnosticLogFinding(
            response="590299D20000",
            translation="UDS reportDTCByStatusMask response; availability mask 0x99; trailing D20000 is an incomplete DTCAndStatusRecord without a status byte.",
            carista_symbol="GetVagUdsTroubleCodesCommand / GetTroubleCodesModel",
            evidence=(
                "docs/OBD_DIAGNOSTICS/session_artifacts/drive_20260429_1055_dtc_detail_711_714_uds_header_scan.json",
            ),
            unresolved=(
                "Treat D20000 as an incomplete record, not a confirmed DTC, until a complete status byte is captured.",
            ),
        ),
        VagDiagnosticLogFinding(
            response="590299C4010008",
            translation="UDS reportDTCByStatusMask response; DTC C40100, SAE-format candidate U0401:00, status 0x08 confirmedDTC.",
            carista_symbol="GetVagUdsTroubleCodesCommand / GetTroubleCodesModel",
            evidence=(
                "docs/OBD_DIAGNOSTICS/session_artifacts/drive_20260429_1055_dtc_detail_711_714_uds_header_scan.json",
            ),
        ),
        VagDiagnosticLogFinding(
            response="5906C4010008",
            translation="UDS reportDTCExtendedDataRecordByDTCNumber response; DTC C40100, status 0x08 confirmedDTC; no extended data bytes captured after status.",
            carista_symbol="ReadVagUdsExtRecordByDtcCommand / FreezeFrameModel path",
            evidence=(
                "docs/OBD_DIAGNOSTICS/session_artifacts/drive_20260429_1055_dtc_detail_711_714_uds_header_scan.json",
            ),
        ),
        VagDiagnosticLogFinding(
            response="7F1978",
            translation="UDS negative response: service 0x19 responsePending. Some retained raw logs show this before later multi-frame DTC payloads.",
            carista_symbol="BaseCommand::filterOutErrors plus VagCanCommunicator::readResponses response-pending handling",
            evidence=(
                "docs/OBD_DIAGNOSTICS/session_artifacts/drive_20260429_1050_pending_dtc_retry_uds_header_scan.txt",
                "carista_apk_analysis/validate_carista_reproduction.py asserts filterOutErrors(['7F2E78', positive]) keeps the positive.",
            ),
        ),
        VagDiagnosticLogFinding(
            response="001C1C50AAAAAA",
            translation="Transport artifact from an ISO-TP continuation/tail frame, not a standalone diagnostic payload.",
            carista_symbol="VagCanCommunicator::readResponses old-sequence drop / receive buffer cleanup",
            evidence=(
                "drive_20260429_1048_other_ecus_dtc_identity_uds_header_scan captures 7E824001C1C50AAAAAA adjacent to 7F1978 and buffered multi-frame DTC data.",
            ),
            unresolved=(
                "The original UDS header scanner was simpler than Carista's packet assembler, so this should not be promoted into a diagnostic command result.",
            ),
        ),
    )


def _transport_findings() -> tuple[VagDiagnosticTransportFinding, ...]:
    return (
        VagDiagnosticTransportFinding(
            topic="channel-open retry",
            carista_behavior=(
                f"establishEcuComm uses {CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS} outer attempts, "
                f"{CARISTA_TP20_OPEN_REQUEST_ATTEMPTS} TP2.0 open sends, and "
                f"{CARISTA_CHANNEL_PARAMETER_ATTEMPTS} channel-parameter sends before giving up."
            ),
            log_evidence=(
                "Early no-response logs often show defaulted channel parameters T1/T2/T3/T4=FF.",
                "Later positive logs show A10F8AFF4FFF with T1=0x8A and T3=0x4F after channel-parameter setup.",
            ),
            implementation_note="Keep reopening the TP2.0 channel when channel parameters are not acknowledged; do not reuse a half-open channel.",
        ),
        VagDiagnosticTransportFinding(
            topic="receive-more handling",
            carista_behavior=(
                f"readResponses calls receiveMore up to {CARISTA_READ_RESPONSES_RECEIVE_MORE_LIMIT} times; receiveMore sends A3 with timeout/spec 0x200."
            ),
            log_evidence=(
                "Several retained sessions have transmit ACK B1 but no immediate final payload.",
                "Carista's receive-more path explains why a one-shot ELM read can miss later frames.",
            ),
            implementation_note="When a frame sequence starts but no final frame arrives, send the computed ACK and then A3 receive-more before treating the read as empty.",
        ),
        VagDiagnosticTransportFinding(
            topic="response-pending and stale-frame handling",
            carista_behavior=(
                f"readResponses tolerates negative responses up to {CARISTA_READ_RESPONSES_NEGATIVE_RESPONSE_LIMIT}, "
                "drops old sequence numbers unless the 7F xx 78 response-pending hack is active, and sends NACK for unexpected next sequence."
            ),
            log_evidence=(
                "UDS scans captured 7F1978 followed by buffered positive DTC frames.",
                "Raw continuation payloads like 001C1C50AAAAAA appear when a simpler scanner treats stale continuation data as a standalone result.",
            ),
            implementation_note="Preserve Carista sequence-state rules in future module-aware UDS scanners instead of parsing line-by-line ELM output as independent responses.",
        ),
        VagDiagnosticTransportFinding(
            topic="disconnect cleanup",
            carista_behavior="A8 is the TP2.0 disconnect path; readResponses clears receivedPackets before ACK_WAIT/NACK or disconnect paths.",
            log_evidence=(
                "Successful one-shot sessions end with A8 and reset adapter formatting to ATCAF1/ATV0.",
                "Logs that required a restart recovered after a fresh ATZ plus channel reopen.",
            ),
            implementation_note="Close with A8 when possible, then reopen cleanly. If A8 gets NO DATA, reset the adapter before the next channel-open attempt.",
        ),
    )


def VagDiagnosticsOperation_buildPq25Plan() -> VagDiagnosticsOperationPlan:
    return VagDiagnosticsOperationPlan(
        name="Carista PQ25 diagnostics recovery plan",
        vehicle_scope="VW Polo 6R / PQ25 with BCM TP2.0 unit 20 plus retained UDS module header scans",
        source="Recovered Carista native diagnostic/debug functions and retained in-car logs.",
        requests=_diagnostic_requests(),
        log_findings=_log_findings(),
        transport_findings=_transport_findings(),
        unresolved=(
            "Concrete native getRequest bodies for GetVagCanTroubleCodesCommand and GetVagCanPowertrainTroubleCodesCommand are not separately exported yet; current bytes are candidate bytes from live logs and Carista call-site symbols.",
            "Debug-data string constants built through operator____b hashes are not decoded yet, so labels such as 0x762389/0x8050ac remain symbolic.",
            "Current live monitor is BCM/TP2.0 only; module-aware UDS headers need a separate guarded runner before the UDS findings become default live diagnostics.",
            "Clear-DTC/resetCodes is intentionally excluded from this read-only plan.",
        ),
    )
