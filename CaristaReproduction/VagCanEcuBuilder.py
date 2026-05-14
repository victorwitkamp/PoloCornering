from __future__ import annotations

from .Commands.GetVagCanEcuListCommand import GetVagCanEcuListCommand_getRequest
from .ReadValuesOperationBuilder import (
    CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
    CARISTA_TP20_UNIT_09_OPEN_REQUEST,
    ReadValuesOperation_buildPq25BcmPlan,
)
from .VagCanCommunicator import (
    CARISTA_CHANNEL_PARAMETER_ATTEMPTS,
    CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS,
    CARISTA_TP20_OPEN_REQUEST_ATTEMPTS,
)
from .Models.VagCanEcu import VagCanEcu, VagCanEcuProbe, VagCanEcuProbeCommand, VagCanEcuScanPlan


PQ25_BCM = VagCanEcu(
    name="Central electronics / BCM / J519",
    ecu_id="PQ25_BCM_UNIT_09",
    tp20_unit_address="20",
    expected_part_number="6R0937087K",
    expected_component="BCM PQ25 H+4",
    evidence=(
        "Live TP2.0 channel open to unit address 20 succeeds on this Polo.",
        "Direct 220600 returns 30-byte DID 0600 long coding on this BCM.",
        "Earlier scan identified part 6R0937087K / BCM PQ25 H+4 software 0254.",
    ),
)


VAG_OPERATION_DELEGATE_ECU_LIST_RECOVERED_FLOW = (
    "VagOperationDelegate::getEcuList(bool) is a direct wrapper around VagOperationDelegate::readCachedEcuList(bool).",
    "VagOperationDelegate::readCachedEcuList(bool) returns the cached Result<EcuList const> when finished, otherwise refreshes through the delegate vtable path that reaches VagOperationDelegate::getVagEcuList(bool).",
    f"GetVagCanEcuListCommand::getRequest is the recovered VAGCAN20 ECU-list request builder and returns {GetVagCanEcuListCommand_getRequest()}.",
    "VagOperationDelegate::getVagEcuList(bool) runs EcuListModel commands, retries an alternate command on obd2RequestNotSupported, calls addBatteryRegulToEcuList, and has a UDS/MK8 gateway branch using runBroadcastCommand plus mergeMk8EcuList.",
    "VagOperationDelegate::sortEcuList(EcuList const&) orders the returned list by VagEcu::values().",
    "This reproduction intentionally exposes only the current PQ25 target as discoverable for now: PQ25_BCM_UNIT_09 / TP2.0 unit 20.",
)

VAG_OPERATION_DELEGATE_PQ25_DISCOVERABLE_ECUS = (PQ25_BCM,)


def VagCanEcu_probeCommandsForPq25Bcm() -> tuple[VagCanEcuProbeCommand, ...]:
    read_values_plan = ReadValuesOperation_buildPq25BcmPlan()
    return tuple(
        VagCanEcuProbeCommand(
            request=request.request,
            native_builder=request.native_builder,
            purpose=f"{request.read_path}; status={request.status}; setting={request.setting_key}",
            read_only=True,
        )
        for request in read_values_plan.requests
        if request.included_by_default
    )


def VagCanEcu_buildPq25ScanPlan() -> VagCanEcuScanPlan:
    return VagCanEcuScanPlan(
        adapter="Carista Bluetooth ELM327-compatible adapter",
        protocol="VW TP2.0 over ISO 15765-4 CAN 11/500",
        discoverable_ecus=VAG_OPERATION_DELEGATE_PQ25_DISCOVERABLE_ECUS,
        discovery_flow=VAG_OPERATION_DELEGATE_ECU_LIST_RECOVERED_FLOW,
        probes=(
            VagCanEcuProbe(
                ecu=PQ25_BCM,
                tp20_open_request=CARISTA_TP20_UNIT_09_OPEN_REQUEST,
                expected_send_header="338",
                expected_listen_header="300",
                channel_parameter_request=CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
                commands=VagCanEcu_probeCommandsForPq25Bcm(),
            ),
        ),
        unresolved=(
            f"The raw wrapper-to-AT mapping is still indirect after recovering VagCanCommunicator::establishEcuComm's {CARISTA_ESTABLISH_ECU_COMM_ATTEMPTS} outer open attempts, {CARISTA_TP20_OPEN_REQUEST_ATTEMPTS} TP2.0 open sends, response-derived headers, and {CARISTA_CHANNEL_PARAMETER_ATTEMPTS} channel-parameter sends.",
            "The exact human-readable AT command names behind VagCanCommunicator::postInitialize wrapper offsets are not mapped yet, though the wrapper vtable call order is recovered.",
            "The live Polo fallback channel-parameter payload A00F8AFF32FF is evidence-backed, but not proven to be Carista's native first-choice payload.",
            "Native ReadValuesOperation availability objects are not reconstructed offline yet.",
        ),
    )


class VagCanEcuCatalog:
    pq25Bcm = PQ25_BCM
    pq25DiscoverableEcus = VAG_OPERATION_DELEGATE_PQ25_DISCOVERABLE_ECUS
    buildPq25ScanPlan = staticmethod(VagCanEcu_buildPq25ScanPlan)
