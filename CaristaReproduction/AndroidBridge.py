from __future__ import annotations

from .Models.AndroidBridgeClass import AndroidBridgeClass, AndroidBridgeMethod


def recovered_android_bridge_classes() -> tuple[AndroidBridgeClass, ...]:
    return (
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/model/Ecu;",
            java_name="com.prizmos.carista.library.model.Ecu",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(J)V"),
                AndroidBridgeMethod("getNameResId", "()Ljava/lang/String;"),
                AndroidBridgeMethod("isObd2", "()Z"),
                AndroidBridgeMethod("isObd2Native", "()Z"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/model/Interpretation;",
            java_name="com.prizmos.carista.library.model.Interpretation",
            dex_file="classes2.dex",
            methods=(),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/model/Setting;",
            java_name="com.prizmos.carista.library.model.Setting",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("getEcu", "()Lcom/prizmos/carista/library/model/Ecu;"),
                AndroidBridgeMethod("getInstruction", "()Ljava/lang/String;"),
                AndroidBridgeMethod("getInterpretation", "()Lcom/prizmos/carista/library/model/Interpretation;"),
                AndroidBridgeMethod("getNameResId", "()Ljava/lang/String;"),
                AndroidBridgeMethod("toEventString", "()Ljava/lang/String;"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/model/SettingRef;",
            java_name="com.prizmos.carista.library.model.SettingRef",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(J)V"),
                AndroidBridgeMethod("getNativeId", "()J"),
                AndroidBridgeMethod("getNameResIdNative", "()Ljava/lang/String;"),
                AndroidBridgeMethod("toEventStringNative", "()Ljava/lang/String;"),
                AndroidBridgeMethod("getEcu", "()Lcom/prizmos/carista/library/model/Ecu;"),
                AndroidBridgeMethod("getInstruction", "()Ljava/lang/String;"),
                AndroidBridgeMethod("getInterpretation", "()Lcom/prizmos/carista/library/model/Interpretation;"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/model/SettingCategory;",
            java_name="com.prizmos.carista.library.model.SettingCategory",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(J)V"),
                AndroidBridgeMethod("getValues", "()[Lcom/prizmos/carista/library/model/SettingCategory;"),
                AndroidBridgeMethod("valuesNative", "()[Lcom/prizmos/carista/library/model/SettingCategory;"),
                AndroidBridgeMethod("getNativeId", "()J"),
                AndroidBridgeMethod("getNameResId", "()Ljava/lang/String;"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/operation/ReadValuesOperation;",
            java_name="com.prizmos.carista.library.operation.ReadValuesOperation",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("getAvailableItems", "()Ljava/util/Map;"),
                AndroidBridgeMethod("getSettingValue", "(Lcom/prizmos/carista/library/model/Setting;)[B"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/operation/ChangeSettingOperation;",
            java_name="com.prizmos.carista.library.operation.ChangeSettingOperation",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Lcom/prizmos/carista/library/model/Setting; [B Lcom/prizmos/carista/library/operation/ReadValuesOperation;)V"),
                AndroidBridgeMethod("initNative", "(Lcom/prizmos/carista/library/model/Setting; [B Lcom/prizmos/carista/library/operation/ReadValuesOperation;)J"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/operation/CheckSettingsOperation;",
            java_name="com.prizmos.carista.library.operation.CheckSettingsOperation",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Lcom/prizmos/carista/library/operation/Operation;)V"),
                AndroidBridgeMethod("initNative", "(Lcom/prizmos/carista/library/operation/Operation;)J"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/operation/GetEcuInfoOperation;",
            java_name="com.prizmos.carista.library.operation.GetEcuInfoOperation",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Lcom/prizmos/carista/library/model/Ecu; Lcom/prizmos/carista/library/operation/Operation;)V"),
                AndroidBridgeMethod("initNative", "(Lcom/prizmos/carista/library/model/Ecu; Lcom/prizmos/carista/library/operation/Operation;)J"),
                AndroidBridgeMethod("getCodingRawAddress", "(S)J"),
                AndroidBridgeMethod("getAdaptationRawAddress", "(S)J"),
                AndroidBridgeMethod("supportsSingleCoding", "()Z"),
                AndroidBridgeMethod("supportsMultiCoding", "()Z"),
                AndroidBridgeMethod("supportsAdaptation", "()Z"),
                AndroidBridgeMethod("supportsDiagnostics", "()Z"),
                AndroidBridgeMethod("isValueInterpretedAsDecimal", "(J)Z"),
            ),
        ),
    )