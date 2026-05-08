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

Durable Play `9.8.3` x86 Ghidra evidence is generated outside the package under:

```text
carista_apk_analysis/play_9.8.3/ghidra_x86_project
carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting
```

Regenerate it with:

```powershell
./carista_apk_analysis/setup_ghidra_re.ps1 -RunX86Headless -X86NoAnalysis -CleanProject -HeadlessMaxMem 8G
./carista_apk_analysis/setup_ghidra_re.ps1 -ExportX86VagLightingBranches -HeadlessMaxMem 8G
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

External TP2.0/PQ references checked on 2026-05-07 are retained as corroboration
only: Jared Wiltshire's TP2.0 notes, `I-CAN-hack/pq-flasher`,
`dnoermann/car-tools`, `phnahes/vw_ebc460_abs_decoder`,
`ConnorHowell/vag-uds-ids`, `bri3d/VW_Flash`, and `Korni22/VAG-Coding` add
transport, ABS, UDS, or MQB context but no new recovered Carista PQ25 BCM
setting owner. The external TP2.0 material agrees with the local recovered
mechanics: `A0/A1` parameters, `A3` keepalive, `A8` disconnect, `B(seq+1)` ACK,
`9(seq)` not-ready/NACK, and a two-byte data length prefix.

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
- `VagSetting::isSubmodule` is recovered from Play `9.8.3` x86 at `0x01426dd0`:
  it reads the setting type at `VagSetting + 0x0C`, tests mask `0x230`, and is
  true for types `4`, `5`, and `9`.

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
- Deeper `0127075C` tracing recovered the `AvailBy` switch at
  `Setting/VagSetting + 0x5C`. The normal `AvailBy=2` route calls the setting's
  `StringWhitelist::itemMatches` with the ECU tag string from `VagEcuInfo+0x08`;
  `AvailBy` `0/1/3/4` use ASAM/revision-derived file identifiers, and
  `AvailBy=5` uses a VIN/PDX-derived identifier. A vtable-slot `+0x3C` special
  predicate path remains unresolved.
- Constructor disassembly now proves the normal no-`AvailBy` lighting branches
  for `VagCanShortAdaptationSetting`, `VagCanLongCodingSetting` via
  `VagCanCodingSetting`, `VagUdsCodingSetting`, and `VagUdsAdaptationSetting`
  pass `AvailBy=2`. For those branches, runtime selection depends on the
  constructor `StringWhitelist` matching the ECU tag, not on the raw DID or raw
  type alone.
- `VagOperationDelegate::readRawValue` (`01270A10`) switches by raw type. Type
  `7` routes to `readVagUdsValue`, type `8` to `readVagUdsCodingValue`, and
  types `5/9` to `readVagUdsSubmoduleValue` after submodule-id resolution.

The important remaining gap is no longer the Java vtable slot target; it is the
exact constructor whitelist contents or special predicate/sub-object that
selects which mixed native constructor branch applies to `6R0937087K`.

## Lighting Recovery Status

Current typed `VagCanSettings` recoveries:

| Setting | Native status | Safety status |
|---|---|---|
| `car_setting_cornering_lights_via_fogs_left` | Same-key evidence: x86 type-7 `VagUdsAdaptationSetting` helpers; x86 whitelists are `CENTRAL_ELEC_MQB_ALL + CENTRAL_ELEC_MK8` or `UDS_CAN_GATEWAY_MEB + CAN_GATEWAY`; older ARM type-7 DID `055C`, offset `5`, mask `FF`, choices `00/16/1E`; ARM part patterns include `5Q0937084*` and `6C093708*`, not `6R0937087K` | `22055C -> 7F2231`; no recovered 6R/PQ25 availability guard for any per-side branch. |
| `car_setting_cornering_lights_via_fogs_right` | Same-key evidence: x86 type-7 `VagUdsAdaptationSetting` helpers; x86 whitelists are `CENTRAL_ELEC_MQB_ALL + CENTRAL_ELEC_MK8` or `UDS_CAN_GATEWAY_MEB + CAN_GATEWAY`; older ARM type-7 DID `055D`, offset `5`, mask `FF`, choices `00/17/1E`; ARM part patterns include `5Q0937084*` and `6C093708*`, not `6R0937087K` | `22055D -> 7F2231`; no recovered 6R/PQ25 availability guard for any per-side branch. |
| `car_setting_cornering_lights_via_fogs` | Official x86 6R/PQ25 branch: `0x012d9f7b -> 0x01358fd0 FullByteVagCanShortAdaptationSetting`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte/mask `0C/40`; same key has 1S, MK6/B7, and B8 variants | Current live coding already has byte `0C` mask `40` set; standalone behavior test disproved this as the missing turn-signal-cornering fix. |
| `car_setting_cornering_lights_via_fogs_experimental` | Official x86 6R/PQ25 branch: `0x012da0f2 -> 0x0135eaf0 VagUdsCodingSetting`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte/mask `15/80`; `YES_NO` maps no=`00`, yes=`01` | Fresh engine-running coding byte `15` is `A6`, so mask `80` is already set while behavior is absent. |
| `car_setting_cornering_lights_with_turn_signals` | Official x86 explicit turn-signal key: `0x012da761 -> 0x0135e920 VagUdsCodingSetting`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, byte/mask `15/04`; `YES_NO` maps no=`00`, yes=`01` | Fresh engine-running coding byte `15` is `A6`, so mask `04` is already set. Treat it as the blinker-trigger enable, not as a front-fog/low-beam output-role selector. |
| `car_setting_coming_home_req_rls` | Mixed: `010B6B3C -> 010D8FE4 -> VagUdsAdaptationSetting`, `010B6B90 -> 010D917C -> VagCanLongCodingSetting`, plus UDS coding DID `0600` byte/mask `11/20` and `0A/04`; `ENABLED_DISABLED` maps disabled=`00`, enabled=`01` | `220A57 -> 7F2231`; coding packing and compact choice values are typed, but branch selection is unresolved. |
| `car_setting_coming_home` | Mixed: `010B6BDC -> 010D92EC -> VagUdsAdaptationSetting`, `010B2040 -> 010C2700 -> VagUdsCodingSetting` DID `0600` byte/mask `06/02`, `010B3AF0 -> 010CA958 -> VagUdsCodingSetting` DID `0600` byte/mask `07/01`; `ENABLED_DISABLED` maps disabled=`00`, enabled=`01` | `220A57 -> 7F2231`; coding packing and compact choice values are typed, but branch selection is unresolved. |
| `car_setting_coming_home_mode` | Mixed: `010B6C30 -> 010D9484 -> VagUdsAdaptationSetting`, `010B6C84 -> 010D9608 -> VagCanLongCodingSetting`; adaptation table uses DID `0A57`, offset `2`, mask/count `03` | Runtime branch unresolved. |
| `car_setting_coming_home_duration` | Mixed: `010B704C -> 010DA7BC -> FullByteVagCanShortAdaptationSetting`, `010B7094 -> 010DA910 -> VagUdsAdaptationSetting`; duration values include `0A` through `3C` seconds table | Runtime branch unresolved; do not infer a write path. |
| `car_setting_coming_leaving_home_output` | Official x86 direct branches are `CENTRAL_ELEC_MK8` or `UDS_CAN_GATEWAY_MEB`, not 6R/PQ25; older ARM branches include rejected DID `110E` and DID `0600` byte/mask `0D/40` and `11/08`, with inverted fogs/low-beams compact values | `22110E -> 7F2231`; report current value stays `unknown` until the runtime branch/enum is recovered. |
| `car_setting_coming_home_via_low_beams` | Official x86 direct branch is B8-scoped `FullByteVagCanShortAdaptationSetting`, byte/mask `06/10`; older ARM fallback shows DID `0600` byte/mask `06/10`; `YES_NO` maps no=`00`, yes=`01` | No recovered official x86 6R/PQ25 branch yet. |
| `car_setting_coming_home_via_fogs` | Official x86 direct branch is B8-scoped, byte/mask `06/20`; older ARM fallback shows DID `0600` byte/mask `06/20`; nearby adaptation reads `056D/0550/0551` rejected | No recovered official x86 6R/PQ25 branch yet. |
| `car_setting_leaving_home_req_rls` | Mixed: `010B7184 -> 010DAD6C -> VagCanLongCodingSetting` byte/mask `00/20`, plus `010B19D0 -> 010C0708 -> VagUdsCodingSetting` DID `0600` byte/mask `0A/02`; `ENABLED_DISABLED` maps disabled=`00`, enabled=`01` | Branch selection unresolved. |
| `car_setting_leaving_home` | `010B71D0 -> 010DAEDC -> VagUdsCodingSetting` DID `0600` byte/mask `06/04`, `010B0C78 -> 010BC404 -> VagUdsCodingSetting` DID `0600` byte/mask `07/08`; `ENABLED_DISABLED` maps disabled=`00`, enabled=`01` | Constructor and packing typed; branch selection unresolved. |
| `car_setting_leaving_home_duration` | Mixed: `010B1708 -> 010BF9DC -> FullByteVagCanShortAdaptationSetting`; `010B72C4/010B7318/010B7368` lead to UDS adaptation constructors; DID `0A57`, offset `5`, mask `FF` appears in one branch | Runtime branch unresolved; do not infer a write path. |
| `car_setting_drl_via_fogs` | Official x86 6R/PQ25 branch: `0x012cdeb6 -> 0x01361520`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte/mask `17/04`; exact helper family is unresolved because branch-export labels conflict with direct PLT/dynamic-symbol audit; other variants are MK5/MK6/B8 or rejected `055C` adaptation | 2026-05-07 write set byte `17` mask `04` and it persisted, but behavior did not change; behavior-disproven standalone. |
| `car_setting_turn_off_fogs_with_high_beam` | Official x86 6R/PQ25 branch: `0x012d4dea -> 0x0135e580 VagUdsCodingSetting`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte/mask `15/20`; `YES_NO` maps no=`00`, yes=`01` | Fresh engine-running coding byte `15` mask `20` is set and physical high-beam shutoff is already present; not a likely missing fix. |
| `car_setting_assist_dr_lights` | Official x86 6R/PQ25 branch: `0x012d9bad -> 0x013625a0 VagCanLongCodingSetting`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte/mask `16/20`; `ENABLED_DISABLED` maps disabled=`00`, enabled=`01` | Current live coding has byte `16` mask `20` clear; lower-priority ADL clue. |

Recovered direct refs that are not VAG/PQ25 write paths:

| Setting | Native status | Safety status |
|---|---|---|
| `car_setting_fog_when` | Official x86 direct ref `0x00e72b62` in `FordSettings::getSettings`; `0x00e72bc1 -> 0x00ee30b0 -> FordCodingSetting`; `car_setting_use_cornering_lights` appears as a Ford choice label at `0x00e72ab3` | Ford-only direct path; no PQ25 read/write method recovered for this label. |
| `car_setting_left_fog_light_as` | Official x86 direct ref `0x00e73135` in `FordSettings::getSettings`; `0x00e73194 -> 0x00ee03b0 -> FordUdsSetting`; typo label `car_setting_cornerig_lights_with_turn_signal` appears as a Ford choice label at `0x00e73334` | Ford-only direct path; no PQ25 read/write method recovered for this label. |
| `car_setting_right_fog_light_as` | Official x86 direct ref `0x00e7376f` in `FordSettings::getSettings`; `0x00e737ce -> 0x00ee59f0 -> FordUdsSetting` / `NumericalInterpretation` | Ford-only direct path; no PQ25 read/write method recovered for this label. |
| `car_setting_cornering_lights_with_turn_signals_one_touch` | Official x86 direct ref `0x00d39204` in `BmwESettings::getSettings`; `0x00d39240` / `0x00d392ba -> 0x00d7eec0 -> BmwESetting` | BMW-only direct path; no PQ25 read/write method recovered for this label. |
| `car_setting_front_fogs_with_low_beams` | `FUN_00E314FE`; `00E82930 -> 00E8FBE4 -> FordUdsSetting`; visible choice label `car_setting_low_beams` | Ford-only direct path; no PQ25 read/write method recovered. |
| `car_setting_fogs_with_high_beam_restriction` | `FUN_00E314FE`; `00E820A8 -> 00E8D43C -> FordCodingSetting` | Ford-only direct path; use the separate VAG `turn_off_fogs_with_high_beam` recovery instead. |
| `car_setting_turn_on_fogs_with_high_beam` | `FUN_00E314FE`; `00E820A8 -> 00E8D43C -> FordCodingSetting` | Ford-only direct path; no PQ25 read/write method recovered. |

Catalog-only unresolved VAG/PQ25 lighting keys:

```text
car_setting_pl_via_front_fog_lights
```

The direct x86 label refs for `fog_when`, `left_fog_light_as`,
`right_fog_light_as`, `use_cornering_lights`, and the typo turn-signal label
land in `FordSettings::getSettings`, not `VagCanSettings::getSettings`. The
one-touch turn-signal label lands in `BmwESettings::getSettings`. If VW/PQ25
has equivalent visible behavior, it must be reached through a different VAG key,
availability/read-value object, or sub-object behind `ReadValuesOperation`.

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
- The runtime branch selection for mixed lighting keys is unresolved where the
  remaining constructor `StringWhitelist` contents or downstream submodule
  availability helper are not fully recovered.

## Open RE Actions

Highest-value static actions:

1. Keep dumping constructor `StringWhitelist` contents for remaining mixed
  branches. The recovered 6R family already matches `6R0937087K` through
  `CENTRAL_ELEC_6R_EXCEPT_6RU`, `CENTRAL_ELEC_6R`,
  `CENTRAL_ELEC_6R_5C_7E_7H`, and `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S` on the
  normal `AvailBy=2` ECU-tag route.
2. Prioritize the unresolved live companion `220601 -> 6206011E`: the `1E`
  payload matches the recovered `car_setting_enabled_coming_home_or_leaving_home`
  choice in the older `055C`/`055D` fog-role tables, but no recovered 6R/PQ25
  Setting branch or write seed exists yet. The Play 9.8.3 x86 scan found zero
  decoded instruction operands for `0x0601`, `0x220601`, or `0x620601`, so this
  remains a live companion clue rather than an x86-owned setting path. A
  2026-05-07 current-state read-only TP2.0 pass on the exact Carista channel
  parameters `A00194FF82FF` confirmed `220601 -> 6206011E` again.
3. Finish branch-specific requested-choice encoding where the same visible key
  has multiple coding branches. `YES_NO` and `ENABLED_DISABLED` compact values
  are recovered; `coming_leaving_home_output` now has proven inverted values
  across its two DID `0600` byte/mask variants.
4. Resolve the special vtable-slot `+0x3C` predicate path in
  `VagOperationDelegate::getVagSettingAvailabilityForEcu`; it runs before the
  normal `AvailBy`/`StringWhitelist` switch and may be the selector for mixed
  branches.
5. Trace whether VW/PQ25 reaches fog-role behavior through a different VAG key
   or `ReadValuesOperation` value object, since the direct `fog_when`,
   `left_fog_light_as`, and `right_fog_light_as` refs are Ford-only.
6. Use the recovered availability route to runtime-select the active branches
   for mixed CH/LH and fog/high-beam keys before any live plan.
7. Do not repeat the known-rejected direct reads (`220A57`, `22110E`, `220D01`,
  `220A58`, `22055C`, `22055D`, `22056D`, `220550`, `220551`) unless a recovered
  Carista precondition changes the read path.
8. Treat external repos and online resources as search indexes for hypotheses,
  not source authority. Any new behavior added under `CaristaReproduction/` must
  still be backed by recovered Carista symbols, constructor callsites, or live
  Carista-equivalent evidence.

External markdown files under `docs/` and `carista_apk_analysis/` are retained as
raw evidence/history. This README is the authoritative reproduction-status doc
for the Python package.
