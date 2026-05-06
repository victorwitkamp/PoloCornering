# CaristaReproduction

This package is the local, proof-first Python reproduction of recovered Carista
native concepts. It is not a generic VW coding helper. Keep it shaped like the
native Carista code whenever the evidence is known, and mark gaps explicitly
when it is not.

## Rules

- Use original Carista function/class name shapes for recovered behavior.
- Keep all recovered Carista behavior, protocol, session, transport, and
  operation logic under `CaristaReproduction/`.
- `obd-on-pc/` is only for live adapter entrypoints, PowerShell helpers, and
  logs. Do not add new Carista protocol logic there; wrappers must import the
  package implementation.
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
| `ReadValuesOperation.py` / `Models/ReadValuesOperation.py` | ReadValuesOperation plan/report logic vs dataclasses. |
| `CheckSettingsOperation.py` / `Models/CheckSettingsOperation.py` | CheckSettingsOperation operation-flow composition vs dataclasses. |
| `JniBridge.py` / `Models/JniBridge.py` | JNI bridge evidence/validation logic vs dataclasses. |
| `VagCanEcu.py` / `Models/VagCanEcu.py` | PQ25 ECU scan-plan registry vs dataclasses. |

Current-setting derivation belongs to `VagCanSettings.py` because it is derived
from recovered `VagCanSettings` definitions; there is no separate
`Pq25CurrentSettings` source-shaped module.

## Commands

Run from the workspace root:

```powershell
python -m CaristaReproduction --ecu-scan-plan
python -m CaristaReproduction --check-settings-operation --coding <30-byte-coding>
python -m CaristaReproduction --customization-scan --coding <30-byte-coding>
python -m CaristaReproduction --current-settings --coding <30-byte-coding>
python -m CaristaReproduction --needle-sweep-settings
python -m CaristaReproduction --fog-setting-candidates
python -m CaristaReproduction --vag-can-settings-recoveries
python -m CaristaReproduction --jni-bridge-summary
python carista_apk_analysis/validate_carista_reproduction.py
```

The process-oriented CLI views now print concise progress/status output by
default and save the full evidence text under `logs/`:

```powershell
python -m CaristaReproduction --check-settings-operation --coding <30-byte-coding>
python -m CaristaReproduction --check-settings-operation --coding <30-byte-coding> --verbose
```

Use `--verbose` to print the full evidence in the terminal, `--full-log <path>`
to choose the saved text log path, or `--no-full-log` for a one-off no-log run.

Persistent live-runner code has been removed from this package. To inspect the
recovered `ReadValuesOperation` procedure, use:

```powershell
python -m CaristaReproduction --read-values-plan
```

To inspect the app-shaped adapter-connected scan sequence as recovered native
symbols, use:

```powershell
python -m CaristaReproduction --check-settings-operation --coding <30-byte-coding>
```

That output composes `ConnectionManager::runCommand` /
`Communicator::runCommand`, `CheckSettingsOperation.initNative(Operation)`,
`GetEcuInfoOperation.initNative(Ecu, Operation)`, and
`ReadValuesOperation::readItemAvailabilityAndValues` into the same high-level
process the app shows as adapter connection, ECU scan, and available
customizations. It remains an offline reproduction/evidence view, not a live
adapter runner.

Current gaps shown by the concise scan output are deliberate and narrower than
before: native command retry/timeout handling, VAG CAN post-initialize wrapper
call order, TP2.0 channel open retry/header extraction, keep-alive `A3`, ACK,
NACK, and the high-level ECU-list path are now statically recovered. The
remaining connection-side unknown is the exact human-readable AT command
mapping behind recovered adapter wrapper offsets. The executable ECU discovery
surface is intentionally limited to the current PQ25 BCM target for now;
broader Carista all-ECU branches are preserved as evidence only. Carista's
fallback decision for the Polo-proven channel-parameter payload and per-setting
availability predicate objects are still not fully recovered.

Any future adapter runner must be a temporary thin script outside
`CaristaReproduction/`, and must be removed after the live session.

Any `obd-on-pc` live command that needs this behavior should be a thin wrapper
around `CaristaReproduction`, not a new implementation.

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

## ECU Discovery Anchors

Recovered native ECU-list symbols now represented in the scan plan:

- `VagOperationDelegate::getEcuList(bool)` is a wrapper around
  `VagOperationDelegate::readCachedEcuList(bool)`.
- `VagOperationDelegate::readCachedEcuList(bool)` returns the cached
  `Result<EcuList const>` when usable; otherwise it refreshes through the
  delegate path that reaches `VagOperationDelegate::getVagEcuList(bool)`.
- `GetVagCanEcuListCommand::getRequest` returns the VAGCAN20 list request
  `1A9F`.
- `VagOperationDelegate::getVagEcuList(bool)` runs `EcuListModel` commands,
  retries an alternate list command on `obd2RequestNotSupported`, calls
  `addBatteryRegulToEcuList`, and has a UDS/MK8 gateway branch that uses
  `runBroadcastCommand` plus `mergeMk8EcuList`.
- `VagOperationDelegate::sortEcuList(EcuList const&)` orders by
  `VagEcu::values()`.

By current project scope, `VagCanEcu_buildPq25ScanPlan()` exposes only one
discoverable ECU:

```text
PQ25_BCM_UNIT_09 / TP2.0 unit 20 / expected 6R0937087K
```

Do not expand the executable discoverable set until additional recovered
symbols/data are available and the scope is explicitly widened.

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
- `VagCanCommunicator::sendAck(seq, bool)` dispatches
  `sendAck(0xB0, (seq + 1) & 0x0F, bool)`.
- `VagCanCommunicator::sendNack(seq)` dispatches `sendAck(0x90, seq, true)`,
  which sends `9N`, sets timeout/spec `0x200`, and calls `receive()`.
- `VagCanCommunicator::receiveMore()` sets timeout/spec `0x200`, sends `A3`,
  then calls `receive()`.
- `VagCanCommunicator::receive()` calls `Communicator::readResponses` and
  appends returned packets to the native `receivedPackets` list at `this+0x1C`.
- `VagCanCommunicator::parsePacket` reads a three-hex-digit CAN header, one
  TP2.0 opcode byte, and then payload bytes. Sequenced opcodes use the low
  nibble as the sequence number; invalid opcode classes set
  `TRANSPORT_LAYER_ERROR`.
- `VagCanCommunicator::readResponses` starts with an empty `receivedPackets`
  list, receives packets, ignores `A3`, treats `A8` as channel disconnect,
  sends `sendNack(expectedSeq)` on unexpected next sequence, calls
  `receiveMore()` up to two times when the buffer does not grow, and extracts
  DONE payloads from the 12-bit TP2.0 length prefix.
- Offline replay with `carista_apk_analysis/analyze_vag_can_readresponses_evidence.py`
  found 95/95 positive saved reads reassembled exactly to `read_result`, with
  95/95 expected inbound `B{counter+1}` transmit ACKs.
- Native-style write timing uses `ATST04` for non-final outgoing frames and
  `ATST20` for final/response waits in the live writer.
- Package-owned live reads use the same `VagCanCommunicator::sendRequest` style
  and close/reopen suspect channels instead of continuing after defaulted
  channel-parameter setup.

Recovered connection/setup anchors:

- `VagCanCommunicator::postInitialize` skips extra setup for defective adapter
  info, then calls wrapper offsets `0x30(1)`, `0x90(0)`, and `0x98(0)`. For
  adapter versions at least `0x8C`, it also calls `0x38(6)`, `0xF4(0)`,
  `0xF0(1)`, `0x8C()`, and then branches through wrapper offsets selected by
  `0x124()` / `0x128()`.
- `VagCanCommunicator::establishEcuComm` uses two outer attempts, sends the
  unit-derived TP2.0 open request up to four times per outer attempt, derives
  data-channel send/listen headers from the open response, sends channel
  parameters up to four times, accepts parsed opcode `A1`, and sends
  `sendDisconnect` when parameter setup fails.
- `Communicator::runCommand<EmptyModel>` initializes if needed, retries up to
  four attempts through `RETRY_COMMAND_STATES`, sleeps `300 ms` for no-data/busy
  retries, adjusts timeout after response-pending, stops after two consecutive
  `-0x0B` no-data states, and tracks final/recovered CAN error state `-0x2E`.
- `Communicator::internalExecuteCommand<EmptyModel>` sends the command request,
  validates status-1 hex responses, checks ECU deadlock, extracts first errors
  with default `-0x0B`, filters to positive responses, and then calls
  `processResponses<EmptyModel>`.
- `ConnectionManager::runCommand<EmptyModel>` branches through native vtable
  offset `0x14`: one path calls `internalRunCommand<EmptyModel>` and extracts a
  broadcast result, the other path calls vtable offset `0x18` with the command
  and `EmptyModel` typeinfo before wrapping the returned model result.

The exact native `getTimeoutSpec()` object is only represented at the useful
static shape recovered from native code: `Communicator::TimeoutSpec(0,
vector{0}, 0)`.

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

Important boundary: the previous live long-coding runner was removed. The
persistent reproduction here is the recovered Carista request plan, not a
standing adapter script.

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
- `CheckSettingsOperation.initNative(Operation)` (`00CC93C8`) is the native
  availability operation entry point recovered from the Java bridge. The local
  `CheckSettingsOperation.py` composes this bridge with `VagCanEcu` and
  `ReadValuesOperation`; it does not create a separate invented scan/profile
  abstraction.
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
| `car_setting_coming_home_req_rls` | Mixed: `010B6B3C -> 010D8FE4 -> VagUdsAdaptationSetting`, `010B6B90 -> 010D917C -> VagCanLongCodingSetting`, plus UDS coding DID `0600` byte/mask `11/20` and `0A/04` | `220A57 -> 7F2231`; coding packing is typed, but branch selection and requested-choice encoding are unresolved. |
| `car_setting_coming_home` | Mixed: `010B6BDC -> 010D92EC -> VagUdsAdaptationSetting`, `010B2040 -> 010C2700 -> VagUdsCodingSetting` DID `0600` byte/mask `06/02`, `010B3AF0 -> 010CA958 -> VagUdsCodingSetting` DID `0600` byte/mask `07/01` | `220A57 -> 7F2231`; coding packing is typed, but branch selection and requested-choice encoding are unresolved. |
| `car_setting_coming_home_mode` | Mixed: `010B6C30 -> 010D9484 -> VagUdsAdaptationSetting`, `010B6C84 -> 010D9608 -> VagCanLongCodingSetting`; adaptation table uses DID `0A57`, offset `2`, mask/count `03` | Runtime branch unresolved. |
| `car_setting_coming_home_duration` | Mixed: `010B704C -> 010DA7BC -> FullByteVagCanShortAdaptationSetting`, `010B7094 -> 010DA910 -> VagUdsAdaptationSetting`; duration values include `0A` through `3C` seconds table | Runtime branch unresolved; do not infer a write path. |
| `car_setting_coming_leaving_home_output` | Mixed: `010B1930 -> 010C0418 -> VagUdsAdaptationSetting`, DID `110E`, offset `2`, mask `01`; second path `010B4218 -> 010CCBC8 -> VagUdsCodingSetting`, DID `0600`, byte/mask `0D/40` and `11/08` | `22110E -> 7F2231`; coding path packing is typed, but branch selection and requested-choice encoding are unresolved. |
| `car_setting_coming_home_via_low_beams` | `010B5A98 -> 010D4140 -> VagUdsCodingSetting`, DID `0600`, byte/mask `06/10` | Constructor and packing typed; branch selection unresolved. |
| `car_setting_coming_home_via_fogs` | `010B19D0 -> 010C0708 -> VagUdsCodingSetting`, DID `0600`, byte/mask `06/20` | Constructor and packing typed; branch selection unresolved. |
| `car_setting_leaving_home_req_rls` | Mixed: `010B7184 -> 010DAD6C -> VagCanLongCodingSetting` byte/mask `00/20`, plus `010B19D0 -> 010C0708 -> VagUdsCodingSetting` DID `0600` byte/mask `0A/02` | Branch selection and requested-choice encoding unresolved. |
| `car_setting_leaving_home` | `010B71D0 -> 010DAEDC -> VagUdsCodingSetting` DID `0600` byte/mask `06/04`, `010B0C78 -> 010BC404 -> VagUdsCodingSetting` DID `0600` byte/mask `07/08` | Constructor and packing typed; branch selection unresolved. |
| `car_setting_leaving_home_duration` | Mixed: `010B1708 -> 010BF9DC -> FullByteVagCanShortAdaptationSetting`; `010B72C4/010B7318/010B7368` lead to UDS adaptation constructors; DID `0A57`, offset `5`, mask `FF` appears in one branch | Runtime branch unresolved; do not infer a write path. |
| `car_setting_drl_via_fogs` | Mixed: UDS coding, long-coding, and `055C` offset-6 adaptation branch (`00/14`) | Runtime branch unknown; `055C` branch blocked by `22055C -> 7F2231`. |
| `car_setting_turn_off_fogs_with_high_beam` | Mixed: UDS coding DID `0600` byte/mask `15/20`, `0E/04`, `04/02`; long-coding `11/20`; adaptation branches at `0D01` / `0A58` | `220D01` / `220A58 -> 7F2231`; coding packing is typed, but branch selection and requested-choice encoding are unresolved. |
| `car_setting_assist_dr_lights` | `010B74A0 -> 010DBC4C -> VagUdsCodingSetting`, DID `0600`, byte/mask `16/20` | Constructor and packing typed; not a write plan. |

Recovered direct refs that are not VAG/PQ25 write paths:

| Setting | Native status | Safety status |
|---|---|---|
| `car_setting_front_fogs_with_low_beams` | `FUN_00E314FE`; `00E82930 -> 00E8FBE4 -> FordUdsSetting`; visible choice label `car_setting_low_beams` | Ford-only direct path; no PQ25 read/write method recovered. |
| `car_setting_fogs_with_high_beam_restriction` | `FUN_00E314FE`; `00E820A8 -> 00E8D43C -> FordCodingSetting` | Ford-only direct path; use the separate VAG `turn_off_fogs_with_high_beam` recovery instead. |
| `car_setting_turn_on_fogs_with_high_beam` | `FUN_00E314FE`; `00E820A8 -> 00E8D43C -> FordCodingSetting` | Ford-only direct path; no PQ25 read/write method recovered. |

Catalog-only unresolved VAG/PQ25 lighting keys:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
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

- `OperationDelegate` is still not a complete native reproduction; enough
  delegate callsites are modeled for the current PQ25 ReadValuesOperation and
  UDS coding work.
- `ConnectionManager::runCommand`, `Communicator::runCommand`, and
  `Communicator::internalExecuteCommand` now have recovered control-flow
  anchors, but the local functions remain evidence views rather than live
  adapter executors.
- `VagCanCommunicator` now models packet splitting, ACK, NACK, receiveMore,
  postInitialize, and establishEcuComm anchors. The full branch-by-branch
  `Communicator::readResponses` parser is still not rebuilt offline.
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
2. Resolve requested-choice encoding and runtime branch selection for the typed
  DID `0600` coding variants, especially `coming_leaving_home_output`,
  `coming_home_via_fogs`, and `turn_off_fogs_with_high_beam`.
3. Resolve the concrete availability predicate/sub-object behind mixed PQ25
  lighting settings in `VagOperationDelegate::getVagSettingAvailabilityForEcu`.
4. Trace how `car_setting_left_fog_light_as` and `car_setting_right_fog_light_as`
   become available on VW/PQ25, since direct key refs only found the non-VAG
   constructor path.
5. Runtime-select the active branches for mixed keys (`drl_via_fogs`,
   `turn_off_fogs_with_high_beam`) before any live plan.
6. Do not repeat the known-rejected direct reads (`220A57`, `22110E`, `220D01`,
  `220A58`, `22055C`, `22055D`, `22056D`, `220550`, `220551`) unless a recovered
  Carista precondition changes the read path.

External markdown files under `docs/` and `carista_apk_analysis/` are retained as
raw evidence/history. This README is the authoritative reproduction-status doc
for the Python package.