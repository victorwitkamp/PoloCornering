# Native Audit Notes

Scope: static comparison of `CaristaReproduction/` against the current exact
Ghidra exports in `carista_apk_analysis/ghidra_exports_exact_flow/`. No live
vehicle or COM port command was run for this audit.

## Differences Fixed In The Python Reproduction

- Added native-shaped `State` and `Result` modules so process checks can model
  `isFail`, `isFatalFail`, and `isIn(State::Set)` instead of plain strings.
- Extended `BaseCommand` with native response-state mapping for `7F xx NRC`,
  plus positive USDT echo matching and echo removal helpers.
- Added `ReadDataByIdentifierCommand`; native `getRequest` is `22 + DID`.
- Added `GetVagUdsEcuWorkshopCodeCommand`; native constructor reads DID `F1A5`
  and `processPayload` only succeeds for a six-byte payload.
- Added `WriteDataByIdentifierCommand.processPayload`; native returns
  `Result<EmptyModel>::done` after the single-response layer has accepted the
  response.
- Added `VagEcuInfo.getWorkshopCodeForWriting`; native uses an existing six-byte
  workshop-code vector when present and fills zero workshop-code subfields with
  recovered default WSC/importer/equipment masks.
- Added `VagUdsCodingSetting`; native ECU/vector constructor hardcodes setting
  type `8` and DID `0600`.
- Added an explicit `VagOperationDelegate.writeVagUdsValue` step list showing the
  native order: F199 date write, optional readback, read ECU info/workshop code,
  F198 workshop write, optional gateway raw command, final target DID write.
- Added an Android/DEX bridge layer under the recovered Java package path
  `com.prizmos.carista.library`. The bridge classes live in `classes2.dex` and
  show that `ChangeSettingOperation` is created from `Setting`, requested
  `byte[]`, and `ReadValuesOperation` before crossing into native code. The
  same DEX scan recovered `GetEcuInfoOperation.getCodingRawAddress(short)`,
  `supportsSingleCoding()`, and `supportsMultiCoding()` as Java-side accessors
  for the native ECU-info/coding-address bridge.
- Added Ghidra export coverage for the JNI bridge functions that sit between
  those DEX declarations and the C++ operation graph:
  `ChangeSettingOperation.initNative`, `CheckSettingsOperation.initNative`,
  `GetEcuInfoOperation.initNative`, `ReadValuesOperation.getAvailableItems`,
  and `ReadValuesOperation.getSettingValue`.
- The JNI exports prove that `ReadValuesOperation.getAvailableItems()` calls the
  native read operation's vtable slot at offset `0x7c`, while
  `ReadValuesOperation.getSettingValue(setting)` calls vtable slot `0x8c` after
  converting the Java `Setting` back to a native `shared_ptr<Setting>`.

## Still Not Fully Native-Exact

- `OperationDelegate`, `ConnectionManager`, and `Communicator` are only source-
  shaped shells; native retry/timeout/run-command behavior is not implemented.
- `GetVagCanEcuInfoCommand.processPayloads` now exposes the native multi-payload
  path, but it does not fully rebuild the native merged submodule model.
- `VagCanCommunicator` still models packet generation and ACK helpers, not the
  full `readResponses`, `receiveMore`, `sendAck`, `sendNack`, keep-alive, or
  response-pending state machine.
- `VagEcuInfo.getWorkshopCodeForWriting` uses the recovered native default mask
  table. For the live nonzero `0005F3C7E719` payload it returns the proven same
  payload; zero-field default packing should still be verified against native
  `ByteUtils::insertValue` before relying on synthetic workshop-code bytes.
- `VagOperationDelegate.readEcuInfoCached`, `readVagCanEcuInfo`,
  `validateVagCanEcuInfo`, `getSettingRawAddress`, and `getCodingRawAddress`
  are not fully modeled yet.
- The Android bridge modules are source-shaped descriptors, not an executable
  Java VM model. They do not replace the native `VagCanSettings` catalog or
  prove a concrete `SettingRef.nativeId -> writeRawValue` raw-key mapping.
- The concrete native subclasses behind the `ReadValuesOperation` vtable slots
  are not named yet. That is now the main static RE target for mapping the
  exact supported setting/value bytes.
