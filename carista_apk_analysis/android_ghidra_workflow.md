# Android Ghidra Workflow Notes

The Remy Hax Android-with-Ghidra workflow is directly relevant to this Carista
APK because the base APK contains both `classes.dex` and `classes2.dex`.

## Repeatable Prep

```powershell
c:/Users/victo/Downloads/PoloCornering/.venv/Scripts/python.exe carista_apk_analysis/extract_carista_android_ghidra_inputs.py
```

This extracts the base APK, both DEX files, the ARMv7 split APK, and
`libCarista.so` under the ignored `carista_apk_analysis/extracted/android/`
tree. It also writes `carista_android_bridge_report.md` and JSON with the
recovered Java bridge class descriptors.

## Ghidra UI Import

Use this when you want best cross-DEX navigation and references:

1. Launch Ghidra Code Browser directly.
2. `File -> Import File...`
3. Pick `carista_apk_analysis/extracted/android/com.prizmos.carista.apk`.
4. Use import mode `Single file` and let Ghidra detect `Android APK`.
5. When Ghidra asks whether to analyze immediately, choose `No`.
6. Open `Window -> External Programs`.
7. Set each external name association so `classes.dex` points to `classes.dex`
   and `classes2.dex` points to `classes2.dex`.
8. Open `Window -> Listings` and confirm both DEX listings are present.
9. Run `Analysis -> Analyze All Open...`.

That sequence preserves cross-DEX references better than importing the APK from
the project window and analyzing too early.

## Headless Fallback

The existing setup script can prepare the same inputs and import the extracted
DEX files as separate Ghidra programs:

```powershell
carista_apk_analysis/setup_ghidra_re.ps1 -PrepareAndroidDex
carista_apk_analysis/setup_ghidra_re.ps1 -RunAndroidDexHeadless -HeadlessMaxMem 8G
```

This is useful for batch exports, but it should not be treated as a full
replacement for the UI External Program association workflow above.

## Bridge Export Targets

After headless DEX import, export decompiler output for the Java/native bridge
classes with:

```powershell
carista_apk_analysis/setup_ghidra_re.ps1 -ExportAndroidBridge -HeadlessMaxMem 8G
```

This now writes per-DEX output under:

```text
carista_apk_analysis/ghidra_android_exports/classes.dex/
carista_apk_analysis/ghidra_android_exports/classes2.dex/
```

The exporter preserves the Ghidra `CaristaAndroid/dex` project folder, records
function signatures and parameters, and adds direct caller/callee references at
the top of each exported `.c` file.

The Ghidra script searches the current DEX program for these bridge classes:

```text
com.prizmos.carista.library.model.Setting
com.prizmos.carista.library.model.SettingRef
com.prizmos.carista.library.model.SettingCategory
com.prizmos.carista.library.model.Ecu
com.prizmos.carista.library.operation.ReadValuesOperation
com.prizmos.carista.library.operation.ChangeSettingOperation
com.prizmos.carista.library.operation.CheckSettingsOperation
com.prizmos.carista.library.operation.GetEcuInfoOperation
```

Those are the DEX-side bridge points that connect the UI-selected setting and
requested byte array to the native `Setting*`, `ReadValuesOperation*`, and final
`VagOperationDelegate::writeRawValue` path.

Important boundary: DEX-native methods such as
`ChangeSettingOperation.initNative(...)`,
`ReadValuesOperation.getAvailableItems()`, and
`ReadValuesOperation.getSettingValue(...)` are declarations only. Their DEX
constructors/call sites are exported, but the implementations live in
`libCarista.so`; follow those through `ghidra_exports_exact_flow/`.

## Native Export Improvements

The native target exporter now keeps exact existing Ghidra functions instead of
recreating them, so recovered C++ signatures are preserved. It only recreates a
function when Ghidra has merged a target into a containing function. Native
exports also include signatures, parameters, direct callers, and direct
callee/reference lists.
