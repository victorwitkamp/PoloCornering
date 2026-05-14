from __future__ import annotations

from pathlib import Path

from .Communicator import COMMUNICATOR_INTERNAL_EXECUTE_COMMAND_RECOVERED_FLOW, COMMUNICATOR_RUN_COMMAND_RECOVERED_FLOW
from .ConnectionManager import CONNECTION_MANAGER_RUN_COMMAND_RECOVERED_FLOW
from .Models.CheckSettingsOperation import CheckSettingsOperationFlowStep, CheckSettingsOperationPlan
from .ReadValuesOperationBuilder import (
    ReadValuesOperation_buildPq25BcmPlan,
    ReadValuesOperation_buildPq25SettingReport,
)
from .Types import HexString
from .VagCanEcuBuilder import VagCanEcu_buildPq25ScanPlan
from .VagCanCommunicator import (
    VAG_CAN_COMMUNICATOR_ESTABLISH_ECU_COMM_RECOVERED_FLOW,
    VAG_CAN_COMMUNICATOR_PARSE_PACKET_RECOVERED_FLOW,
    VAG_CAN_COMMUNICATOR_POST_INITIALIZE_RECOVERED_FLOW,
    VAG_CAN_COMMUNICATOR_RECEIVE_MORE_RECOVERED_FLOW,
    VAG_CAN_COMMUNICATOR_READ_RESPONSES_DYNAMIC_EVIDENCE,
    VAG_CAN_COMMUNICATOR_READ_RESPONSES_RECOVERED_FLOW,
)


def CheckSettingsOperation_nativeFlow() -> tuple[CheckSettingsOperationFlowStep, ...]:
    return (
        CheckSettingsOperationFlowStep(
            order=10,
            native_method="ConnectionManager::runCommand / Communicator::runCommand",
            java_bridge="adapter connection accepted before operation execution",
            ghidra_address="0x011EBC98 / 0x011EC844 / 0x011ED384",
            recovered_call="ConnectionManager_runCommand -> Communicator_runCommand -> OperationDelegate::runCommand family",
            purpose="Represent the app stage where the selected adapter is connected and command execution is handed to the Carista operation stack.",
            evidence=CONNECTION_MANAGER_RUN_COMMAND_RECOVERED_FLOW
            + COMMUNICATOR_RUN_COMMAND_RECOVERED_FLOW
            + COMMUNICATOR_INTERNAL_EXECUTE_COMMAND_RECOVERED_FLOW,
        ),
        CheckSettingsOperationFlowStep(
            order=15,
            native_method="VagCanCommunicator::postInitialize / VagCanCommunicator::establishEcuComm",
            java_bridge="native communicator setup behind the selected adapter",
            ghidra_address="0x00D2759C / 0x00D2765C",
            recovered_call="postInitialize -> establishEcuComm -> Communicator::readResponses -> channel parameter A1 success",
            purpose="Recover the VAG CAN adapter setup and TP2.0 channel-open behavior that precedes BCM read commands.",
            evidence=VAG_CAN_COMMUNICATOR_POST_INITIALIZE_RECOVERED_FLOW
            + VAG_CAN_COMMUNICATOR_ESTABLISH_ECU_COMM_RECOVERED_FLOW
            + VAG_CAN_COMMUNICATOR_RECEIVE_MORE_RECOVERED_FLOW,
        ),
        CheckSettingsOperationFlowStep(
            order=16,
            native_method="VagCanCommunicator::parsePacket / VagCanCommunicator::readResponses",
            java_bridge="native TP2.0 response parser behind Communicator::readResponses",
            ghidra_address="0x00D27A68 / 0x00D282A8",
            recovered_call="readResponses -> parsePacket -> sendAck/sendNack/receiveMore -> DONE payload extraction",
            purpose="Recover the native TP2.0 receive loop that turns adapter packets into positive read results before ReadValuesOperation parsing.",
            evidence=VAG_CAN_COMMUNICATOR_PARSE_PACKET_RECOVERED_FLOW
            + VAG_CAN_COMMUNICATOR_READ_RESPONSES_RECOVERED_FLOW
            + VAG_CAN_COMMUNICATOR_READ_RESPONSES_DYNAMIC_EVIDENCE,
        ),
        CheckSettingsOperationFlowStep(
            order=20,
            native_method="CheckSettingsOperation::initNative",
            java_bridge="com.prizmos.carista.library.operation.CheckSettingsOperation.initNative(Operation)",
            ghidra_address="0x00CC93C8",
            recovered_call="JniHelper::getNativePointer<Operation> -> FUN_00cc9594 -> JniOperations::put",
            purpose="Create the native settings-check operation from the previous operation after adapter connection/initialization.",
            evidence=(
                "JNI_CheckSettingsOperation_initNative_00CC93C8.c logs Creating native CheckSettingsOperation.",
                "The JNI bridge converts the previous Java Operation to a native Operation shared_ptr before invoking FUN_00cc9594.",
                "The resulting native operation is stored with JniOperations::put.",
            ),
        ),
        CheckSettingsOperationFlowStep(
            order=30,
            native_method="GetEcuInfoOperation::initNative",
            java_bridge="com.prizmos.carista.library.operation.GetEcuInfoOperation.initNative(Ecu, Operation)",
            ghidra_address="0x00CCB01C",
            recovered_call="JniHelper::getNativePointer<Ecu> + JniHelper::getNativePointer<Operation> -> FUN_00ccb1f4",
            purpose="Bind a native Ecu object to the operation chain before ECU metadata/current-coding reads.",
            evidence=(
                "JNI_GetEcuInfoOperation_initNative_00CCB01C.c is recovered in the JNI bridge summary.",
                "GetEcuInfoOperation.getCodingRawAddress(short), supportsSingleCoding(), and supportsMultiCoding() are Java/native bridge points recovered from DEX/smali.",
                "The VAGCAN20 scan requests modeled for this BCM are GetVagCanEcuInfoCommand::getRequest, GetVagCanEcuListCommand::getRequest, and ReadVagCanLongCodingCommand::getRequest.",
            ),
        ),
        CheckSettingsOperationFlowStep(
            order=40,
            native_method="ReadValuesOperation::readItemAvailabilityAndValues",
            java_bridge="native setup before ReadValuesOperation.getAvailableItems/getSettingValue",
            ghidra_address="0x012CDE08",
            recovered_call="delegate slot 0xE0 availability, raw-address slot 0x148, raw-value/multi-read slots",
            purpose="Build the runtime availability map and current raw-value cache for visible customizations.",
            evidence=(
                "target_012CDE08.c proves ReadValuesOperation::readItemAvailabilityAndValues builds the runtime settings map.",
                "VagOperationDelegate::getSettingAvailability and getVagSettingAvailabilityForEcu are the native availability choke points.",
                "This is the native process behind the app's Scanning for available customizations screen.",
            ),
        ),
        CheckSettingsOperationFlowStep(
            order=50,
            native_method="ReadValuesOperation::getAvailableItems",
            java_bridge="com.prizmos.carista.library.operation.ReadValuesOperation.getAvailableItems()",
            ghidra_address="0x012CD520 / JNI 0x00CCDB9C",
            recovered_call="vtable slot 0x7c returns map at ReadValuesOperation + 0x68",
            purpose="Return the native category/settings map to Java after availability has been computed.",
            evidence=(
                "JNI_ReadValuesOperation_getAvailableItems_00CCDB9C.c dispatches through slot 0x7c.",
                "The Java bridge wraps native SettingCategory and Setting pointers into the app-facing map.",
            ),
        ),
        CheckSettingsOperationFlowStep(
            order=60,
            native_method="ReadValuesOperation::getSettingValue",
            java_bridge="com.prizmos.carista.library.operation.ReadValuesOperation.getSettingValue(Setting)",
            ghidra_address="0x012CD694 / JNI 0x00CCE1DC",
            recovered_call="vtable slot 0x8c -> delegate raw-value slot 0xA8 -> Setting extraction slot 0x1C",
            purpose="Return the Java-visible current byte[] value for each available customization setting.",
            evidence=(
                "JNI_ReadValuesOperation_getSettingValue_00CCE1DC.c converts Java Setting back to native before slot 0x8c dispatch.",
                "target_012CD694.c calls the operation delegate raw-value slot and the Setting extraction slot before returning bytes.",
            ),
        ),
    )


def CheckSettingsOperation_buildPq25BcmPlan(
    coding: HexString | None = None,
    *,
    catalog_path: Path | None = None,
) -> CheckSettingsOperationPlan:
    read_values_operation_plan = ReadValuesOperation_buildPq25BcmPlan()
    setting_report = None
    if coding is not None:
        setting_report = (
            ReadValuesOperation_buildPq25SettingReport(coding, catalog_path=catalog_path)
            if catalog_path
            else ReadValuesOperation_buildPq25SettingReport(coding)
        )
    return CheckSettingsOperationPlan(
        name="CheckSettingsOperation PQ25 BCM scan",
        vehicle_scope=read_values_operation_plan.vehicle_scope,
        source="DEX classes2.dex JNI bridge plus official Play-installed Carista 9.8.3 x86 libCarista.so exports",
        native_flow=CheckSettingsOperation_nativeFlow(),
        vag_can_ecu_scan_plan=VagCanEcu_buildPq25ScanPlan(),
        read_values_operation_plan=read_values_operation_plan,
        read_values_operation_setting_report=setting_report,
        unresolved=(
            "The exact Carista Bluetooth/ELM wrapper-offset-to-AT-command mapping remains indirect; live adapter entrypoints stay in obd-on-pc/.",
            "VagCanCommunicator::readResponses/parsePacket control flow is recovered and log-corroborated, but the full native Result/vector object model is not rebuilt offline.",
            "The Polo-proven A00F8AFF32FF channel parameter request is retained as live evidence, but Carista's exact fallback decision logic is not recovered.",
            "ReadValuesOperation.getAvailableItems() is modeled from static/native evidence; it is not a live Java map dump from Carista.",
            "Normal AvailBy=2 lighting selection is modeled through recovered StringWhitelist matching; the type 4/5/9 submodule route is now recovered as a VagEcuInfo+0x10 vector scan, but vector population and any separate 0601 owner path remain unresolved.",
        ),
    )


class CheckSettingsOperation:
    nativeFlow = staticmethod(CheckSettingsOperation_nativeFlow)
    buildPq25BcmPlan = staticmethod(CheckSettingsOperation_buildPq25BcmPlan)
