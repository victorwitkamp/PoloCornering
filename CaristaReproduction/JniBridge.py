from __future__ import annotations

from pathlib import Path

from .Models.JniBridge import (
    JniBridgeFunction,
    JniBridgeSummary,
    JniExportValidation,
    JniOperationFlowStep,
    ReadValuesNativeFlowStep,
    ReadValuesVtableSlot,
)

DEFAULT_EXACT_FLOW_EXPORT_DIR = Path(__file__).resolve().parents[1] / "carista_apk_analysis" / "ghidra_exports"
DEFAULT_ADDRESS_TARGET_EXPORT_DIR = Path(__file__).resolve().parents[1] / "carista_apk_analysis" / "ghidra_address_targets"


def recovered_jni_bridge_functions() -> tuple[JniBridgeFunction, ...]:
    return (
        JniBridgeFunction(
            java_class="com.prizmos.carista.library.operation.ChangeSettingOperation",
            java_method="initNative",
            descriptor="(Lcom/prizmos/carista/library/model/Setting;[BLcom/prizmos/carista/library/operation/ReadValuesOperation;)J",
            access_flags="private native",
            native_symbol="Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative",
            elf_address="0x00CB645C",
            ghidra_address="0x00CC645C",
            export_file="JNI_ChangeSettingOperation_initNative_00CC645C.c",
            required_evidence=(
                "JniHelper::getNativePointer<Setting>",
                "JniHelper::getNativePointer<ReadValuesOperation>",
                "ReadValuesOperation::shared_from_this",
                "JniHelper::convertArrToVector",
                "FUN_00cc674c",
            ),
            recovered_behavior=(
                "Converts Java Setting to native Setting.",
                "Converts requested byte[] to a native vector.",
                "Passes the current ReadValuesOperation through shared_from_this.",
                "Creates the native ChangeSettingOperation via helper FUN_00cc674c.",
            ),
        ),
        JniBridgeFunction(
            java_class="com.prizmos.carista.library.operation.CheckSettingsOperation",
            java_method="initNative",
            descriptor="(Lcom/prizmos/carista/library/operation/Operation;)J",
            access_flags="private native",
            native_symbol="Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative",
            elf_address="0x00CB93C8",
            ghidra_address="0x00CC93C8",
            export_file="JNI_CheckSettingsOperation_initNative_00CC93C8.c",
            required_evidence=(
                "JniHelper::getNativePointer<Operation>",
                "FUN_00cc9594",
            ),
            recovered_behavior=(
                "Converts the previous Java Operation to native Operation.",
                "Creates the native CheckSettingsOperation via helper FUN_00cc9594.",
            ),
        ),
        JniBridgeFunction(
            java_class="com.prizmos.carista.library.operation.GetEcuInfoOperation",
            java_method="initNative",
            descriptor="(Lcom/prizmos/carista/library/model/Ecu;Lcom/prizmos/carista/library/operation/Operation;)J",
            access_flags="private native",
            native_symbol="Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative",
            elf_address="0x00CBB01C",
            ghidra_address="0x00CCB01C",
            export_file="JNI_GetEcuInfoOperation_initNative_00CCB01C.c",
            required_evidence=(
                "JniHelper::getNativePointer<Ecu>",
                "JniHelper::getNativePointer<Operation>",
                "FUN_00ccb1f4",
            ),
            recovered_behavior=(
                "Converts Java Ecu and previous Operation to native pointers.",
                "Creates the native GetEcuInfoOperation via helper FUN_00ccb1f4.",
            ),
        ),
        JniBridgeFunction(
            java_class="com.prizmos.carista.library.operation.GetEcuInfoOperation",
            java_method="getCodingRawAddress",
            descriptor="(S)J",
            access_flags="public native",
            native_symbol="Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_getCodingRawAddress",
            elf_address="0x00CBB40C",
            ghidra_address="0x00CCB40C",
            export_file="JNI_GetEcuInfoOperation_getCodingRawAddress_00CCB40C.c",
            required_evidence=(
                "JniHelper::getNativePointer<GetEcuInfoOperation>",
                "+ 0x78",
            ),
            recovered_behavior=(
                "Dispatches to the native GetEcuInfoOperation vtable slot at offset 0x78.",
            ),
        ),
        JniBridgeFunction(
            java_class="com.prizmos.carista.library.operation.ReadValuesOperation",
            java_method="getAvailableItems",
            descriptor="()Ljava/util/Map;",
            access_flags="public native",
            native_symbol="Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems",
            elf_address="0x00CBDB9C",
            ghidra_address="0x00CCDB9C",
            export_file="JNI_ReadValuesOperation_getAvailableItems_00CCDB9C.c",
            required_evidence=(
                "JniHelper::getNativePointer<ReadValuesOperation>",
                "+ 0x7c",
                "FUN_00cce028",
                "java/util/HashMap",
                "com/prizmos/carista/library/model/SettingCategory",
                "com/prizmos/carista/library/model/SettingRef",
            ),
            recovered_behavior=(
                "Calls ReadValuesOperation vtable slot 0x7c.",
                "Copies the returned native category/settings map via FUN_00cce028.",
                "Wraps native SettingCategory and Setting pointers into Java bridge objects.",
            ),
        ),
        JniBridgeFunction(
            java_class="com.prizmos.carista.library.operation.ReadValuesOperation",
            java_method="getSettingValue",
            descriptor="(Lcom/prizmos/carista/library/model/Setting;)[B",
            access_flags="public native",
            native_symbol="Java_com_prizmos_carista_library_operation_ReadValuesOperation_getSettingValue",
            elf_address="0x00CBE1DC",
            ghidra_address="0x00CCE1DC",
            export_file="JNI_ReadValuesOperation_getSettingValue_00CCE1DC.c",
            required_evidence=(
                "JniHelper::getNativePointer<Setting>",
                "JniHelper::getNativePointer<ReadValuesOperation>",
                "+ 0x8c",
                "JniHelper::convertVectorToArr",
            ),
            recovered_behavior=(
                "Converts Java Setting to native shared_ptr<Setting>.",
                "Calls ReadValuesOperation vtable slot 0x8c.",
                "Converts the returned native vector to Java byte[].",
            ),
        ),
    )


def recovered_read_values_vtable_slots() -> tuple[ReadValuesVtableSlot, ...]:
    return (
        ReadValuesVtableSlot(
            java_method="ReadValuesOperation.getAvailableItems",
            slot_offset="0x7c",
            export_file="JNI_ReadValuesOperation_getAvailableItems_00CCDB9C.c",
            dispatch_expression="(**(code **)(*(int *)pRVar3 + 0x7c))()",
            proven_input="native ReadValuesOperation pointer from the Java object",
            proven_output="native category-to-settings map copied into Java HashMap<SettingCategory, SettingRef[]>",
            unresolved_target="Base _ZTV19ReadValuesOperation slot maps to ReadValuesOperation::getAvailableItems at 0x012CD520; no alternate subclass target is proven in the current symbol/export set.",
        ),
        ReadValuesVtableSlot(
            java_method="ReadValuesOperation.getSettingValue",
            slot_offset="0x8c",
            export_file="JNI_ReadValuesOperation_getSettingValue_00CCE1DC.c",
            dispatch_expression="(**(code **)(*(int *)pRVar2 + 0x8c))(a_Stack_28,pRVar2,auStack_34)",
            proven_input="native ReadValuesOperation pointer plus native shared_ptr<Setting>",
            proven_output="native byte vector converted to Java byte[]",
            unresolved_target="Base _ZTV19ReadValuesOperation slot maps to ReadValuesOperation::getSettingValue at 0x012CD694; no alternate subclass target is proven in the current symbol/export set.",
        ),
    )


def recovered_read_values_native_flow() -> tuple[ReadValuesNativeFlowStep, ...]:
    return (
        ReadValuesNativeFlowStep(
            order=1,
            native_method="ReadValuesOperation::getAvailableItems",
            ghidra_address="0x012CD520",
            export_file="target_012CD520.c",
            required_evidence=("return this + 0x68;",),
            recovered_behavior=(
                "Returns the native category/settings map stored at ReadValuesOperation + 0x68.",
                "The Java bridge converts this map into HashMap<SettingCategory, SettingRef[]>.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=2,
            native_method="ReadValuesOperation::readItemAvailabilityAndValues",
            ghidra_address="0x012CDE08",
            export_file="target_012CDE08.c",
            required_evidence=("0xe0", "0x148", "0xe4", "Item is present in configuration"),
            recovered_behavior=(
                "Builds the runtime availability map before Java asks for available items.",
                "Calls the operation delegate availability slot 0xE0 for each setting candidate.",
                "For value-bearing settings, calls delegate raw-address slot 0x148 and raw-value/multi-read slots before applying Setting value extraction.",
            ),
            unresolved="This proves where branch selection happens, but not which mixed constructor branch is chosen for 6R0937087K.",
        ),
        ReadValuesNativeFlowStep(
            order=3,
            native_method="ReadValuesOperation::getSettingValue",
            ghidra_address="0x012CD694",
            export_file="target_012CD694.c",
            required_evidence=("0xa8", "0x1c"),
            recovered_behavior=(
                "Obtains the operation delegate and calls its raw-value slot 0xA8.",
                "Passes the raw bytes through the native Setting extraction slot 0x1C before returning Java-visible bytes.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=4,
            native_method="ReadValuesOperation::isItemAvailable",
            ghidra_address="0x012CD820",
            export_file="target_012CD820.c",
            required_evidence=("this + 0x7c", "0xa8", "unrecognized value"),
            recovered_behavior=(
                "Checks the availability map at ReadValuesOperation + 0x7C.",
                "When a setting has a value parser, it validates the current raw value length and choice mapping before declaring the item available.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=5,
            native_method="VagOperationDelegate::getSettingAvailability",
            ghidra_address="0x012703D0",
            export_file="target_012703D0.c",
            required_evidence=("getVagSettingAvailabilityForEcu", "match ECU type", "is available for ECU w/ tag"),
            recovered_behavior=(
                "Rejects settings whose ECU is not present or whose setting type does not match the connected VAG ECU type.",
                "Delegates the VAG-specific per-ECU predicate to getVagSettingAvailabilityForEcu.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=6,
            native_method="VagOperationDelegate::getVagSettingAvailabilityForEcu",
            ghidra_address="0x0127075C",
            export_file="target_0127075C.c",
            required_evidence=("VagVin::getVagFileIdentifier", "Vehicle missing from PDX mapping", "0x5c"),
            recovered_behavior=(
                "Uses the setting type byte at Setting + 0x5C to choose a VAG availability route.",
                "For file/vehicle-specific settings, combines VIN-derived PDX/file identifiers with ECU ASAM/revision data before invoking the setting availability predicate object.",
            ),
            unresolved="The concrete setting predicate object for each mixed PQ25 lighting key still needs recovery.",
        ),
        ReadValuesNativeFlowStep(
            order=7,
            native_method="VagOperationDelegate::readRawValue",
            ghidra_address="0x01270A10",
            export_file="target_01270A10.c",
            required_evidence=("case 7:", "0x1ac", "case 8:", "Invalid VAG setting type"),
            recovered_behavior=(
                "Switches on native VAG setting type and routes type 7 to the UDS adaptation read path.",
                "Routes type 8 to the UDS coding read path, and rejects type 10 with state -10.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=8,
            native_method="VagOperationDelegate::readRawValuesMulti",
            ghidra_address="0x01270CF8",
            export_file="target_01270CF8.c",
            required_evidence=("DAT_014f8f5c = 6", "OperationDelegate::runCommand<DynamicDataModel>"),
            recovered_behavior=(
                "Batches raw-value reads after checking the setting-value cache.",
                "The recovered chunk limit is six raw address/value pairs per dynamic-data command batch.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=9,
            native_method="VagOperationDelegate::getSettingRawAddress",
            ghidra_address="0x012720EC",
            export_file="target_012720EC.c",
            required_evidence=("OperationDelegate::getSettingRawAddress", "0x1ec", "0x1f0"),
            recovered_behavior=(
                "Starts from the generic OperationDelegate raw address.",
                "Adds native VAG submodule handling for setting types 4, 5, and 9 before read/write dispatch.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=10,
            native_method="VagOperationDelegate::readVagCanAdaptationValue",
            ghidra_address="0x0127236C",
            export_file="target_0127236C.c",
            required_evidence=("readVagCanAdaptationValue", "Retrying to read adaptation channel", "0x1a8"),
            recovered_behavior=(
                "Reads VAG CAN adaptation values for raw types 0 and 1.",
                "Retries state -0x0B adaptation reads up to two times before returning the result.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=11,
            native_method="VagOperationDelegate::readVagUdsValue",
            ghidra_address="0x01272A1C",
            export_file="target_01272A1C.c",
            required_evidence=("readVagUdsValue", "FUN_012148e0", "OperationDelegate::runCommand<BytesModel>"),
            recovered_behavior=(
                "Builds and runs the UDS raw read command used by native raw type 7.",
                "This is the branch behind direct RDBI candidates such as 22055C, 22055D, 220A57, 22110E, 220D01, and 220A58.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=12,
            native_method="VagOperationDelegate::readVagUdsCodingValue",
            ghidra_address="0x01272AD0",
            export_file="target_01272AD0.c",
            required_evidence=("readVagUdsCodingValue", "0x1ac", "0x18c"),
            recovered_behavior=(
                "Reads UDS coding values for native raw type 8.",
                "Updates cached VAG ECU info/coding metadata after the UDS coding read succeeds.",
            ),
        ),
        ReadValuesNativeFlowStep(
            order=13,
            native_method="VagOperationDelegate::readVagUdsSubmoduleValue",
            ghidra_address="0x01272CE0",
            export_file="target_01272CE0.c",
            required_evidence=("readVagUdsSubmoduleValue", "FUN_01272d7c", "OperationDelegate::runCommand<BytesModel>"),
            recovered_behavior=(
                "Builds and runs the UDS submodule read command used after raw type 5/9 submodule-id resolution.",
            ),
        ),
    )


def recovered_change_setting_operation_flow() -> tuple[JniOperationFlowStep, ...]:
    return (
        JniOperationFlowStep(
            order=1,
            source="DEX classes2.dex",
            proven_call="ChangeSettingOperation(Setting, byte[], ReadValuesOperation)",
            evidence="com.prizmos.carista.library.operation.ChangeSettingOperation constructor descriptor",
            unresolved="The Java object is only the bridge; actual write behavior is native.",
        ),
        JniOperationFlowStep(
            order=2,
            source="JNI_ChangeSettingOperation_initNative_00CC645C.c",
            proven_call="JniHelper::getNativePointer<Setting>",
            evidence="native initNative converts Java Setting to native Setting/shared_ptr<Setting>",
        ),
        JniOperationFlowStep(
            order=3,
            source="JNI_ChangeSettingOperation_initNative_00CC645C.c",
            proven_call="JniHelper::convertArrToVector",
            evidence="requested Java byte[] is converted to native vector bytes",
        ),
        JniOperationFlowStep(
            order=4,
            source="JNI_ChangeSettingOperation_initNative_00CC645C.c",
            proven_call="ReadValuesOperation::shared_from_this",
            evidence="native ChangeSettingOperation receives the originating ReadValuesOperation",
        ),
        JniOperationFlowStep(
            order=5,
            source="JNI_ChangeSettingOperation_initNative_00CC645C.c",
            proven_call="FUN_00cc674c",
            evidence="helper constructs/stages the native ChangeSettingOperation shared_ptr",
            unresolved="Helper name is not recovered as a source symbol yet.",
        ),
        JniOperationFlowStep(
            order=6,
            source="VagOperationDelegate / write tuple exports",
            proven_call="VagOperationDelegate::writeRawValue",
            evidence="native operation flow reaches the delegate writer with a raw key and compact value vector",
            unresolved="The concrete ReadValuesOperation subclass and exact per-BCM Setting catalog entry are still unresolved.",
        ),
    )


def validate_jni_bridge_exports(export_dir: Path = DEFAULT_EXACT_FLOW_EXPORT_DIR) -> tuple[JniExportValidation, ...]:
    validations: list[JniExportValidation] = []
    for function in recovered_jni_bridge_functions():
        path = export_dir / function.export_file
        if not path.exists():
            validations.append(
                JniExportValidation(
                    label=f"{function.java_class}.{function.java_method}",
                    export_file=function.export_file,
                    status="missing",
                    matched_evidence=(),
                    missing_evidence=function.required_evidence,
                )
            )
            continue

        text = path.read_text(encoding="utf-8", errors="replace")
        matched = tuple(evidence for evidence in function.required_evidence if evidence in text)
        missing = tuple(evidence for evidence in function.required_evidence if evidence not in text)
        validations.append(
            JniExportValidation(
                label=f"{function.java_class}.{function.java_method}",
                export_file=function.export_file,
                status="found" if not missing else "partial",
                matched_evidence=matched,
                missing_evidence=missing,
            )
        )
    return tuple(validations)


def validate_read_values_native_flow_exports(
    export_dir: Path = DEFAULT_ADDRESS_TARGET_EXPORT_DIR,
) -> tuple[JniExportValidation, ...]:
    validations: list[JniExportValidation] = []
    for step in recovered_read_values_native_flow():
        path = export_dir / step.export_file
        if not path.exists():
            validations.append(
                JniExportValidation(
                    label=step.native_method,
                    export_file=step.export_file,
                    status="missing",
                    matched_evidence=(),
                    missing_evidence=step.required_evidence,
                )
            )
            continue

        text = path.read_text(encoding="utf-8", errors="replace")
        matched = tuple(evidence for evidence in step.required_evidence if evidence in text)
        missing = tuple(evidence for evidence in step.required_evidence if evidence not in text)
        validations.append(
            JniExportValidation(
                label=step.native_method,
                export_file=step.export_file,
                status="found" if not missing else "partial",
                matched_evidence=matched,
                missing_evidence=missing,
            )
        )
    return tuple(validations)


def build_jni_bridge_summary(export_dir: Path = DEFAULT_EXACT_FLOW_EXPORT_DIR) -> JniBridgeSummary:
    return JniBridgeSummary(
        functions=recovered_jni_bridge_functions(),
        read_values_slots=recovered_read_values_vtable_slots(),
        read_values_native_flow=recovered_read_values_native_flow(),
        operation_flow=recovered_change_setting_operation_flow(),
        validations=validate_jni_bridge_exports(export_dir),
        read_values_native_flow_validations=validate_read_values_native_flow_exports(),
    )
