from __future__ import annotations

from pathlib import Path

from .Models.JniBridge import JniBridgeFunction, JniBridgeSummary, JniExportValidation, ReadValuesVtableSlot

DEFAULT_EXACT_FLOW_EXPORT_DIR = Path(__file__).resolve().parents[1] / "carista_apk_analysis" / "ghidra_exports_exact_flow"


def recovered_jni_bridge_functions() -> tuple[JniBridgeFunction, ...]:
    return (
        JniBridgeFunction(
            java_class="com.prizmos.carista.library.operation.ChangeSettingOperation",
            java_method="initNative",
            descriptor="(Lcom/prizmos/carista/library/model/Setting; [B Lcom/prizmos/carista/library/operation/ReadValuesOperation;)J",
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
            descriptor="(Lcom/prizmos/carista/library/model/Ecu; Lcom/prizmos/carista/library/operation/Operation;)J",
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
            unresolved_target="Concrete native subclass and slot target function are not named yet.",
        ),
        ReadValuesVtableSlot(
            java_method="ReadValuesOperation.getSettingValue",
            slot_offset="0x8c",
            export_file="JNI_ReadValuesOperation_getSettingValue_00CCE1DC.c",
            dispatch_expression="(**(code **)(*(int *)pRVar2 + 0x8c))(a_Stack_28,pRVar2,auStack_34)",
            proven_input="native ReadValuesOperation pointer plus native shared_ptr<Setting>",
            proven_output="native byte vector converted to Java byte[]",
            unresolved_target="Concrete native subclass and slot target function are not named yet.",
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


def build_jni_bridge_summary(export_dir: Path = DEFAULT_EXACT_FLOW_EXPORT_DIR) -> JniBridgeSummary:
    return JniBridgeSummary(
        functions=recovered_jni_bridge_functions(),
        read_values_slots=recovered_read_values_vtable_slots(),
        validations=validate_jni_bridge_exports(export_dir),
    )
