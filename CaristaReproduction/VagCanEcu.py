from __future__ import annotations

from .CaristaReadValuesOperation import (
    CARISTA_EXACT_CHANNEL_PARAMETER_REQUEST,
    CARISTA_TP20_UNIT_09_OPEN_REQUEST,
    CaristaReadValuesOperation_buildPq25BcmPlan,
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


def VagCanEcu_probeCommandsForPq25Bcm() -> tuple[VagCanEcuProbeCommand, ...]:
    read_values_plan = CaristaReadValuesOperation_buildPq25BcmPlan()
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
            "Only PQ25 BCM / unit 09 is first-class in this local reproduction right now.",
            "The exact Carista all-ECU discovery list is not fully recovered from native code yet.",
            "Native ReadValuesOperation availability objects are not reconstructed offline yet.",
        ),
    )


class VagCanEcuCatalog:
    pq25Bcm = PQ25_BCM
    buildPq25ScanPlan = staticmethod(VagCanEcu_buildPq25ScanPlan)
