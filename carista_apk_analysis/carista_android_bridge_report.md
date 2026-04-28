# Carista Android Ghidra Inputs And Bridge Scan

This report is generated from the Carista 9.8.2 XAPK without running the app or using a phone.

## Extracted Inputs

| Artifact | Path | Size |
|---|---|---:|
| com.prizmos.carista.apk | `carista_apk_analysis\extracted\android\com.prizmos.carista.apk` | 37999682 |
| config.armeabi_v7a.apk | `carista_apk_analysis\extracted\android\config.armeabi_v7a.apk` | 29344505 |
| classes.dex | `carista_apk_analysis\extracted\android\dex\classes.dex` | 9845356 |
| classes2.dex | `carista_apk_analysis\extracted\android\dex\classes2.dex` | 7628632 |
| libCarista.so | `carista_apk_analysis\extracted\android\lib\armeabi-v7a\libCarista.so` | 22611320 |

## Bridge Classes

These descriptors are the Java-side package/folder structure to use when connecting the DEX model to the native `libCarista.so` model.

### com.prizmos.carista.library.model.Ecu

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/model/Ecu;`
- Interesting methods:
  - `<init>(J)V` (public constructor)
  - `equals(Ljava/lang/Object;)Z` (public)
  - `getNameResId()Ljava/lang/String;` (public native) [native declaration]
  - `hashCode()I` (public)
  - `isObd2()Z` (public)
  - `isObd2Native()Z` (public native) [native declaration]

### com.prizmos.carista.library.model.Interpretation

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/model/Interpretation;`
- Interesting methods:

### com.prizmos.carista.library.model.Setting

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/model/Setting;`
- Interesting methods:
  - `<init>()V` (public constructor)
  - `getEcu()Lcom/prizmos/carista/library/model/Ecu;` (public abstract)
  - `getInstruction()Ljava/lang/String;` (public abstract)
  - `getInterpretation()Lcom/prizmos/carista/library/model/Interpretation;` (public abstract)
  - `getNameResId()Ljava/lang/String;` (public abstract)
  - `toEventString()Ljava/lang/String;` (public abstract)

### com.prizmos.carista.library.model.SettingCategory

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/model/SettingCategory;`
- Interesting methods:
  - `<init>(J)V` (public constructor)
  - `getValues()[Lcom/prizmos/carista/library/model/SettingCategory;` (public static)
  - `valuesNative()[Lcom/prizmos/carista/library/model/SettingCategory;` (private static native) [native declaration]
  - `equals(Ljava/lang/Object;)Z` (public)
  - `getNameResId()Ljava/lang/String;` (public)
  - `getNativeId()J` (public)
  - `hashCode()I` (public)

### com.prizmos.carista.library.model.SettingRef

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/model/SettingRef;`
- Interesting methods:
  - `<init>(J)V` (public constructor)
  - `getNameResIdNative()Ljava/lang/String;` (private native) [native declaration]
  - `toEventStringNative()Ljava/lang/String;` (private native) [native declaration]
  - `getEcu()Lcom/prizmos/carista/library/model/Ecu;` (public native) [native declaration]
  - `getInstruction()Ljava/lang/String;` (public native) [native declaration]
  - `getInterpretation()Lcom/prizmos/carista/library/model/Interpretation;` (public native) [native declaration]
  - `getNameResId()Ljava/lang/String;` (public)
  - `getNativeId()J` (public)
  - `toEventString()Ljava/lang/String;` (public)

### com.prizmos.carista.library.operation.ChangeSettingOperation

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/operation/ChangeSettingOperation;`
- Interesting methods:
  - `<init>()V` (public constructor)
  - `<init>(Lcom/prizmos/carista/library/model/Setting; [B Lcom/prizmos/carista/library/operation/ReadValuesOperation;)V` (public constructor)
  - `initNative(Lcom/prizmos/carista/library/model/Setting; [B Lcom/prizmos/carista/library/operation/ReadValuesOperation;)J` (private native) [native declaration]

### com.prizmos.carista.library.operation.CheckSettingsOperation

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/operation/CheckSettingsOperation;`
- Interesting methods:
  - `<init>(Lcom/prizmos/carista/library/operation/Operation;)V` (public constructor)
  - `initNative(Lcom/prizmos/carista/library/operation/Operation;)J` (private native) [native declaration]

### com.prizmos.carista.library.operation.GetEcuInfoOperation

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/operation/GetEcuInfoOperation;`
- Interesting methods:
  - `<init>(Lcom/prizmos/carista/library/model/Ecu; Lcom/prizmos/carista/library/operation/Operation;)V` (public constructor)
  - `initNative(Lcom/prizmos/carista/library/model/Ecu; Lcom/prizmos/carista/library/operation/Operation;)J` (private native) [native declaration]
  - `getAdaptationRawAddress(S)J` (public native) [native declaration]
  - `getCodingRawAddress(S)J` (public native) [native declaration]
  - `getEcu()Lcom/prizmos/carista/library/model/Ecu;` (public native) [native declaration]
  - `isValueInterpretedAsDecimal(J)Z` (public native) [native declaration]
  - `supportsAdaptation()Z` (public native) [native declaration]
  - `supportsDiagnostics()Z` (public native) [native declaration]
  - `supportsMultiCoding()Z` (public native) [native declaration]
  - `supportsSingleCoding()Z` (public native) [native declaration]

### com.prizmos.carista.library.operation.ReadValuesOperation

- DEX: `classes2.dex`
- Descriptor: `Lcom/prizmos/carista/library/operation/ReadValuesOperation;`
- Interesting methods:
  - `<init>()V` (public constructor)
  - `getAvailableItems()Ljava/util/Map;` (public native) [native declaration]
  - `getSettingValue(Lcom/prizmos/carista/library/model/Setting;)[B` (public native) [native declaration]

## Ghidra Workflow Note

The base APK contains both `classes.dex` and `classes2.dex`. For the richest Ghidra DEX output, import the APK from Code Browser, decline immediate analysis, set External Program associations for every `classes*.dex`, confirm both listings are open, then run Analyze All Open.

Native Java methods such as `initNative`, `getSettingValue`, and `getAvailableItems` are declarations in the DEX. Ghidra can show their call sites, but the implementation is in `libCarista.so` and must be followed through the native exports.
