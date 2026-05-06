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
                AndroidBridgeMethod("getAvailableItems", "()Ljava/util/Map;", access_flags="public native", is_native=True),
                AndroidBridgeMethod(
                    "getSettingValue",
                    "(Lcom/prizmos/carista/library/model/Setting;)[B",
                    access_flags="public native",
                    is_native=True,
                ),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/operation/ChangeSettingOperation;",
            java_name="com.prizmos.carista.library.operation.ChangeSettingOperation",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Lcom/prizmos/carista/library/model/Setting;[BLcom/prizmos/carista/library/operation/ReadValuesOperation;)V"),
                AndroidBridgeMethod(
                    "initNative",
                    "(Lcom/prizmos/carista/library/model/Setting;[BLcom/prizmos/carista/library/operation/ReadValuesOperation;)J",
                    access_flags="private native",
                    is_native=True,
                ),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/operation/CheckSettingsOperation;",
            java_name="com.prizmos.carista.library.operation.CheckSettingsOperation",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Lcom/prizmos/carista/library/operation/Operation;)V"),
                AndroidBridgeMethod("initNative", "(Lcom/prizmos/carista/library/operation/Operation;)J", access_flags="private native", is_native=True),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lcom/prizmos/carista/library/operation/GetEcuInfoOperation;",
            java_name="com.prizmos.carista.library.operation.GetEcuInfoOperation",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Lcom/prizmos/carista/library/model/Ecu;Lcom/prizmos/carista/library/operation/Operation;)V"),
                AndroidBridgeMethod("initNative", "(Lcom/prizmos/carista/library/model/Ecu;Lcom/prizmos/carista/library/operation/Operation;)J", access_flags="private native", is_native=True),
                AndroidBridgeMethod("getCodingRawAddress", "(S)J", access_flags="public native", is_native=True),
                AndroidBridgeMethod("getAdaptationRawAddress", "(S)J", access_flags="public native", is_native=True),
                AndroidBridgeMethod("supportsSingleCoding", "()Z", access_flags="public native", is_native=True),
                AndroidBridgeMethod("supportsMultiCoding", "()Z", access_flags="public native", is_native=True),
                AndroidBridgeMethod("supportsAdaptation", "()Z", access_flags="public native", is_native=True),
                AndroidBridgeMethod("supportsDiagnostics", "()Z", access_flags="public native", is_native=True),
                AndroidBridgeMethod("isValueInterpretedAsDecimal", "(J)Z", access_flags="public native", is_native=True),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lwr/f;",
            java_name="wr.f",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("invokeSuspend", "(Ljava/lang/Object;)Ljava/lang/Object;"),
                AndroidBridgeMethod("invoke", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lwr/j;",
            java_name="wr.j",
            dex_file="classes2.dex",
            methods=(AndroidBridgeMethod("O", "()V"),),
        ),
        AndroidBridgeClass(
            descriptor="Lwr/n;",
            java_name="wr.n",
            dex_file="classes2.dex",
            methods=(AndroidBridgeMethod("<init>", "(Ljava/lang/String;Ljt/j1;Z)V"),),
        ),
        AndroidBridgeClass(
            descriptor="Lwr/p;",
            java_name="wr.p",
            dex_file="classes2.dex",
            methods=(AndroidBridgeMethod("<init>", "(Ljava/lang/String;Ljava/util/List;)V"),),
        ),
        AndroidBridgeClass(
            descriptor="Lwr/q;",
            java_name="wr.q",
            dex_file="classes2.dex",
            methods=(AndroidBridgeMethod("<init>", "(IIILjava/lang/String;Ljava/lang/String;)V"),),
        ),
        AndroidBridgeClass(
            descriptor="Lwr/r;",
            java_name="wr.r",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Ljava/lang/String;Ljava/lang/String;Lwr/m;)V"),
                AndroidBridgeMethod("a", "(Lwr/r;Ljava/lang/String;Lwr/m;I)Lwr/r;"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lzr/f;",
            java_name="zr.f",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("<init>", "(Lcom/prizmos/carista/util/Log;Lzr/b;Lzr/d;Lzr/m;)V"),
                AndroidBridgeMethod("a", "(Lwr/s;)Lt2/x;"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Lmi/t1;",
            java_name="mi.t1",
            dex_file="classes2.dex",
            methods=(
                AndroidBridgeMethod("U", "(J)[B"),
                AndroidBridgeMethod("W", "([B)J"),
            ),
        ),
        AndroidBridgeClass(
            descriptor="Luc/d;",
            java_name="uc.d",
            dex_file="classes.dex",
            methods=(AndroidBridgeMethod("o", "([BII)[B"),),
        ),
    )
