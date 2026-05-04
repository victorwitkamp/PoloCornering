# CaristaReproduction

This package is the local, proof-first Python reproduction of recovered Carista
native concepts. It is not a generic VW coding helper. Keep it shaped like the
native Carista code whenever the evidence is known, and mark gaps explicitly
when it is not.

## Rules

- Use original Carista function/class name shapes for recovered behavior.
- Keep source modules under `CaristaReproduction/`; live adapter tooling stays
  under `obd-on-pc/`.
- Do not create a write plan for a raw setting unless the matching positive raw
  read payload is known and its length is proven.
- Rejected or untested reads are read-only leads, not write seeds.
- Prefer exact request builders and validated constants over inferred wrappers.

## Python Layout

The native C++ symbols do not show a top-level namespace such as `Carista::` or
`Vag::`. Symbols point to global C++ classes with class-owned methods:

```text
BaseCommand::extractState
GetVagCanEcuInfoCommand::getRequest
WriteVagCodingCommand::getRequest
WriteDataByIdentifierCommand::getRequest
VagOperationDelegate::writeVagUdsValue
VagCanCommunicator::readResponses
ByteUtils::insertValue
```

Layout conventions:

- `Commands/` groups recovered command request builders.
- `Models/` contains dataclasses/value objects only.
- Root modules contain recovered behavior, registries, and source-shaped helper
  logic.
- `Android/com/prizmos/carista/library/...` mirrors the Java package path found
  in `classes2.dex`.

Duplicate-looking files are intentional unless listed otherwise:

| Pair | Meaning |
|---|---|
| `JniBridge.py` / `Models/JniBridge.py` | JNI bridge evidence/validation logic vs dataclasses. |
| `VagCanEcu.py` / `Models/VagCanEcu.py` | PQ25 ECU scan-plan registry vs dataclasses. |
| `Pq25CurrentSettings.py` / `Models/Pq25CurrentSettingState.py` | Current-setting derivation logic vs the single state dataclass. |

The old duplicate-looking `Models/Pq25CurrentSettings.py` filename was renamed
to `Models/Pq25CurrentSettingState.py` to make that split explicit.

## Commands

Run from the workspace root:

```powershell
python -m CaristaReproduction --ecu-scan-plan
python -m CaristaReproduction --customization-scan --coding <30-byte-coding>
python -m CaristaReproduction --current-settings --coding <30-byte-coding>
python -m CaristaReproduction --needle-sweep-settings
python -m CaristaReproduction --fog-setting-candidates
python -m CaristaReproduction --vag-can-settings-recoveries
python -m CaristaReproduction --jni-bridge-summary
python carista_apk_analysis/validate_carista_reproduction.py
```

Live adapter commands are outside this package. The read-only scan path is:

```powershell
python obd-on-pc/vw_tp20_readonly_probe.py --mode carista_ecu_scan --port COM10 --parameter-profile minimal
```

## Native-Exact Anchors

Request builders currently modeled and proof-checked:

| Native shape | Local behavior |
|---|---|
| `ReadDataByIdentifierCommand::getRequest` | `22 + DID` |
| `WriteDataByIdentifierCommand::getRequest` | `2E + DID + payload` |
| `GetVagCanEcuInfoCommand::getRequest` | `1A9B` |
| `GetVagCanEcuListCommand::getRequest` | `1A9F` |
| `ReadVagCanLongCodingCommand::getRequest` | `1A9A` |
| VAG short adaptation routine | `31B80103`, `31BA0103`, `31B90103xx`, `31BA0103`, `32B80103` |

Native state/result behavior reflected locally:

- `7F xx 24` maps to request-sequence-error.
- `7F xx 33` maps to security-access-denied.
- `7F xx 78` response-pending is filtered when a later positive response exists.
- Metadata pre-writes `F199` and `F198` are gated with `isFatalFail`, not plain
  `isFail`.

## TP2.0 / Communicator Anchors

Known live Carista-adapter path for this car:

```text
Vehicle: VW Polo 6R / PQ25
BCM: 6R0937087K / BCM PQ25 H+4 / SW 0254
TP2.0 unit: 20
Open request: 20C00010000301
Send header: 338
Listen header: 300
Working parameters: A00F8AFF32FF -> A10F8AFF4FFF
```

Modeled communicator behavior:

- Outgoing TP2.0 application packets start with a two-byte payload length.
- Multi-frame requests use 5 bytes in the first frame, then 7-byte chunks.
- Outgoing sequence advances once per generated TP2.0 frame.
- ECU response sequence `N` is ACKed with `B0 | ((N + 1) & 0x0F)`.
- Native-style write timing uses `ATST04` for non-final outgoing frames and
  `ATST20` for final/response waits in the live writer.

The exact native `getTimeoutSpec()` object is not fully reconstructed in Python;
the package only exposes the currently useful constants and frame helpers.

## UDS DID 0600 Writer

The live-proven Carista-shaped long-coding writer sequence is:

```text
2EF199 + YYMMDD
22F1A5 inline workshop-code read
2EF198 + workshop-code payload
2E0600 + full 30-byte coding
```

The reproduction builds this plan with:

```powershell
python -m CaristaReproduction --uds-write-plan --coding <current> --target-coding <target> --workshop-code <6-byte-F1A5-payload>
```

Important boundary: the working long-coding writer lives in
`obd-on-pc/write_carista_uds_coding.py`. That script has changed BCM long-coding
bytes on the car, but it is still separate from reproducing Carista's per-setting
customization path.

## Android / JNI Bridge

The base APK has two DEX files. The Java/native bridge classes are in
`classes2.dex` under:

```text
com.prizmos.carista.library.model.Setting
com.prizmos.carista.library.model.SettingRef
com.prizmos.carista.library.model.SettingCategory
com.prizmos.carista.library.operation.ReadValuesOperation
com.prizmos.carista.library.operation.ChangeSettingOperation
com.prizmos.carista.library.operation.CheckSettingsOperation
com.prizmos.carista.library.operation.GetEcuInfoOperation
```

JNI exports prove these boundaries:

- `ChangeSettingOperation.initNative(setting, valueBytes, readValuesOperation)`
  converts Java objects to native pointers and creates the native change
  operation.
- `ReadValuesOperation.getAvailableItems()` dispatches through native vtable
  slot `0x7c`, which maps to base `ReadValuesOperation::getAvailableItems`
  at `012CD520`; that method returns the native map stored at `this + 0x68`.
- `ReadValuesOperation.getSettingValue(setting)` dispatches through native
  vtable slot `0x8c` after converting the Java `Setting` back to native; the
  base slot maps to `ReadValuesOperation::getSettingValue` at `012CD694`.

Focused exports now prove the runtime availability/value route:

- `ReadValuesOperation::readItemAvailabilityAndValues` (`012CDE08`) builds the
  runtime map. It calls delegate slot `0xE0` for availability, stores
  availability at `this + 0x7C`, then uses raw-address slot `0x148` and raw
  read slots for value-bearing settings.
- `VagOperationDelegate::getSettingAvailability` (`012703D0`) rejects absent or
  wrong-type ECUs before calling `getVagSettingAvailabilityForEcu`.
- `VagOperationDelegate::getVagSettingAvailabilityForEcu` (`0127075C`) is the
  branch-selection choke point: it uses the setting type byte, VIN-derived PDX
  file identifiers, and ECU ASAM/revision data before invoking the setting's
  availability predicate object.
- `VagOperationDelegate::readRawValue` (`01270A10`) switches by raw type. Type
  `7` routes to `readVagUdsValue`, type `8` to `readVagUdsCodingValue`, and
  types `5/9` to `readVagUdsSubmoduleValue` after submodule-id resolution.

The important remaining gap is no longer the Java vtable slot target; it is the
per-setting availability predicate/sub-object that selects which mixed native
constructor branch applies to `6R0937087K`.

## Lighting Recovery Status

Current typed `VagCanSettings` recoveries:

| Setting | Native status | Safety status |
|---|---|---|
| `car_setting_cornering_lights_via_fogs_left` | `VagUdsAdaptationSetting`, DID `055C`, offset `5`, mask `FF`, choices `00/16/1E` | `22055C -> 7F2231`; not a write seed. |
| `car_setting_cornering_lights_via_fogs_right` | `VagUdsAdaptationSetting`, DID `055D`, offset `5`, mask `FF`, choices `00/17/1E` | `22055D -> 7F2231`; not a write seed. |
| `car_setting_coming_home_req_rls` | Mixed: `010B6B3C -> 010D8FE4 -> VagUdsAdaptationSetting`, `010B6B90 -> 010D917C -> VagCanLongCodingSetting`, plus UDS coding helpers | `220A57` only belongs to one adaptation branch; runtime branch unresolved. |
| `car_setting_coming_home` | Mixed: `010B6BDC -> 010D92EC -> VagUdsAdaptationSetting`, `010B2040 -> 010C2700 -> VagUdsCodingSetting`, `010B3AF0 -> 010CA958 -> VagUdsCodingSetting` | `220A57` only belongs to one adaptation branch; coding packing and branch unresolved. |
| `car_setting_coming_home_mode` | Mixed: `010B6C30 -> 010D9484 -> VagUdsAdaptationSetting`, `010B6C84 -> 010D9608 -> VagCanLongCodingSetting`; adaptation table uses DID `0A57`, offset `2`, mask/count `03` | Runtime branch unresolved. |
| `car_setting_coming_home_duration` | Mixed: `010B704C -> 010DA7BC -> FullByteVagCanShortAdaptationSetting`, `010B7094 -> 010DA910 -> VagUdsAdaptationSetting`; duration values include `0A` through `3C` seconds table | Runtime branch unresolved; do not infer a write path. |
| `car_setting_coming_leaving_home_output` | Mixed: `010B1930 -> 010C0418 -> VagUdsAdaptationSetting`, DID `110E`, offset `2`, mask `01`; second path `010B4218 -> 010CCBC8 -> VagUdsCodingSetting` | `22110E` only belongs to the adaptation path and is not live-proven; coding path packing/branch selection unresolved. |
| `car_setting_coming_home_via_low_beams` | `010B5A98 -> 010D4140 -> VagUdsCodingSetting`, immediate `10/06` | Constructor typed, exact DID/byte/mask packing unresolved. |
| `car_setting_coming_home_via_fogs` | `010B19D0 -> 010C0708 -> VagUdsCodingSetting`, immediate `20/06` | Constructor typed, exact DID/byte/mask packing unresolved. |
| `car_setting_leaving_home_req_rls` | Mixed: `010B7184 -> 010DAD6C -> VagCanLongCodingSetting`, plus `010B19D0 -> 010C0708 -> VagUdsCodingSetting` | Coding packing and runtime branch unresolved. |
| `car_setting_leaving_home` | `010B71D0 -> 010DAEDC -> VagUdsCodingSetting`, `010B0C78 -> 010BC404 -> VagUdsCodingSetting` | Constructor typed, exact DID/byte/mask packing unresolved. |
| `car_setting_leaving_home_duration` | Mixed: `010B1708 -> 010BF9DC -> FullByteVagCanShortAdaptationSetting`; `010B72C4/010B7318/010B7368` lead to UDS adaptation constructors; DID `0A57`, offset `5`, mask `FF` appears in one branch | Runtime branch unresolved; do not infer a write path. |
| `car_setting_drl_via_fogs` | Mixed: UDS coding, long-coding, and `055C` offset-6 adaptation branch (`00/14`) | Runtime branch unknown; `055C` branch blocked by `22055C -> 7F2231`. |
| `car_setting_turn_off_fogs_with_high_beam` | Mixed: UDS coding, long-coding, and adaptation branches at `0D01` / `0A58` | `220D01` / `220A58` are read-only candidates only. |
| `car_setting_assist_dr_lights` | `010B74A0 -> 010DBC4C -> VagUdsCodingSetting`, immediate `20/16` | Constructor typed; not a write plan. |

Catalog-only unresolved VAG/PQ25 lighting keys:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
car_setting_front_fogs_with_low_beams
car_setting_fogs_with_high_beam_restriction
car_setting_turn_on_fogs_with_high_beam
car_setting_pl_via_front_fog_lights
```

The first direct string refs for `left_fog_light_as` and `right_fog_light_as`
land in the non-VAG/Ford constructor zone (`FUN_00E314FE`), not the VAG
`FUN_0105F6C0` path. The VW/PQ25 implementation must be reached through a
different path, likely availability/read-value objects or a sub-object behind
`ReadValuesOperation`.

## Dynamic Emulator Status

The official Google emulator path is partially proven but not currently enough
to dump runtime whitelist objects on this Windows host.

- API 28 x86 and wiped API 30 x86 Google APIs images expose
  `x86,armeabi-v7a,armeabi` and `libndk_translation.so`.
- PairIP-bypassed emulator splits install on API 30 only after rebuilding all
  splits with true stored ZIP entries for `resources.arsc` and native `.so`
  files, followed by `zipalign` and signing. Android then records
  `primaryCpuAbi=armeabi-v7a`.
- Normal API 30 launch starts ARMv7 native translation, then crashes before the
  whitelist probe can dump `VagWhitelists`: `SIGSEGV SEGV_ACCERR` at guest
  address `0x013EA300`, with `libndk_translation_HandleNoExec` in the backtrace.
- `0x013EA300` is the first byte of `libCarista.so` `.plt` / PLT0, inside an
  executable `PT_LOAD` segment. The ELF already has `DT_FLAGS=BIND_NOW` and
  `DT_FLAGS_1=NOW`, so this is not just a missing eager-binding flag.
- Frida 17 on API 30 can attach and install `dlopen`/`android_dlopen_ext` hooks,
  but the process terminates before `libCarista.so` returns from load. No
  `VagWhitelists` storage is initialized or dumped on API 28/30 x86.
- API 35 Google APIs x86_64 has a newer native bridge but exposes only
  `x86_64,arm64-v8a`; `ro.product.cpu.abilist32` is empty. Installing the
  patched Carista split set fails with `INSTALL_FAILED_NO_MATCHING_ABIS` because
  the available Carista native split is `armeabi-v7a`.

Dynamic recovery on this PC is therefore blocked through the official Google
emulator route: the 32-bit x86 images accept the APK but crash in the ARM bridge
at PLT0, while newer x86_64 images do not accept the 32-bit ARM split. Continue
through static constructor recovery unless an actual ARM Android device/runtime
becomes available.

## Not Native-Exact Yet

- `OperationDelegate`, `ConnectionManager`, and `Communicator` are source-shaped
  shells, not complete native retry/timeout/run-command reproductions.
- `VagCanCommunicator` models packet splitting and ACK helpers, not the full
  native `readResponses`, `receiveMore`, keep-alive, NACK, or response-pending
  state machine.
- `GetVagCanEcuInfoCommand.processPayloads` exposes the recovered multi-payload
  path but does not rebuild every native submodule object.
- `VagOperationDelegate.readEcuInfoCached`, `readVagCanEcuInfo`,
  `validateVagCanEcuInfo`, and exact coding/submodule packing are not fully
  modeled.
- Android bridge modules are descriptors, not an executable Java VM model.
- The runtime branch selection for mixed lighting keys is unresolved.

## Open RE Actions

Highest-value static actions:

1. Runtime-select the active branches for mixed CH/LH keys on `6R0937087K`,
  especially `coming_home`, `coming_home_mode`, `coming_home_duration`,
  `leaving_home_duration`, and `coming_leaving_home_output`.
2. Resolve the coding raw address/index packing in the second
  `coming_leaving_home_output` path now that `010B4218 -> 010CCBC8` proves a
  `VagUdsCodingSetting` constructor and the window shows immediate pairs
  `40/0D` and `08/11`.
3. Resolve the concrete availability predicate/sub-object behind mixed PQ25
  lighting settings in `VagOperationDelegate::getVagSettingAvailabilityForEcu`.
4. Trace how `car_setting_left_fog_light_as` and `car_setting_right_fog_light_as`
   become available on VW/PQ25, since direct key refs only found the non-VAG
   constructor path.
5. Runtime-select the active branches for mixed keys (`drl_via_fogs`,
   `turn_off_fogs_with_high_beam`) before any live plan.
6. Keep read-only probes limited to proof candidates such as `220A57`, `22110E`,
  `220D01`, and `220A58`; never promote them to writes without positive raw
  payloads.

External markdown files under `docs/` and `carista_apk_analysis/` are retained as
raw evidence/history. This README is the authoritative reproduction-status doc
for the Python package.