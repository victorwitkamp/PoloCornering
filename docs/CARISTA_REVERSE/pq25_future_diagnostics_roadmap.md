# PQ25 Carista Future Diagnostics Roadmap

Date: 2026-05-14

This is the current roadmap for continuing the Carista reverse-engineering work
after the original Polo 6R fog-light issue was resolved. The target is local,
reproducible diagnostics for VW PQ25 / Polo 6R without depending on a Carista
subscription for routine troubleshooting.

This is not a plan to bypass Carista accounts, cloud authentication, payment, or
server-side services. The useful path is to reproduce locally observed protocol
behavior, recovered native request builders, and retained car logs.

## Current Safe Baseline

All future in-car reads and writes should keep using these entrypoints:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1
.\obd-on-pc\pq25_write_session.ps1
```

The wrappers must stay thin. Request construction, coding edits, Carista-shaped
write plans, VAG CAN adaptation routines, and response interpretation belong in
`CaristaReproduction/`.

Useful offline views:

```powershell
.\.venv\Scripts\python.exe -m CaristaReproduction --ecu-scan-plan --no-full-log
.\.venv\Scripts\python.exe -m CaristaReproduction --read-values-plan --no-full-log
.\.venv\Scripts\python.exe -m CaristaReproduction --diagnostics-plan --no-full-log
.\.venv\Scripts\python.exe -m CaristaReproduction --check-settings-operation --coding 3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000 --no-full-log
.\.venv\Scripts\python.exe -m CaristaReproduction --jni-bridge-summary
```

Currently allowed read-only scan families in `pq25_read_monitor.py` are narrow:

```text
18, 19, 1A, 21, 22, and exact 24 requests
```

The only supported routine-style read today is the recovered Carista VAG CAN
adaptation sequence:

```text
31B8 + basic id
31BA + basic id
31B9 + basic id + channel
31BA + basic id
32B8 + basic id
```

Do not broad-scan service `27`, `2E`, `31`, `32`, `33`, `3B`, or clear-DTC
services from a generic loop.

## Highest Value Open Paths

| Priority | Path | Evidence in repo | Why it matters | Next local implementation |
|---:|---|---|---|---|
| P0 | Carista DTC scan operation | `VagOperationDelegate::runCheckFaultsDebugCommands`, `GetVagCanTroubleCodesCommand`, `GetVagCanPowertrainTroubleCodesCommand`, `GetVagUdsTroubleCodesCommand` in `carista_apk_analysis/ghidra_adaptation_probe/` | Gives a Carista-like fault scan across modules, the most useful future troubleshooting feature. | Implemented locally as `CaristaReproduction/VagDiagnosticsOperation.py`, `--diagnostics-plan`, and read-only `carista-dtc` profiles for BCM TP2.0 and UDS headers. Remaining work is dynamic per-DTC detail follow-up. |
| P0 | Freeze-frame and DTC detail reads | `VagOperationDelegate::runFreezeFrameDebugCommands`, `ReadVagUdsExtRecordByDtcCommand`, retained UDS `1906...` positives | Gives context for stored faults instead of only DTC numbers. | Initial command builders and decoder support for UDS `59 04`/`59 06` are implemented. Remaining work is decoding the exact Carista debug labels and running detail reads per discovered module/header. |
| P1 | Live-data / dynamic data tools | `VagOperationDelegate::getDetectableLiveData`, `VagLiveData::getTools`, `ReadLiveDataOperation`, `LiveDataOperation`, `VagOperationDelegate::readRawValuesMulti`, `DynamicDataModel` | Likely exposes sensor streams and measuring values Carista uses behind the app UI. | Recover `VagLiveData::getTools()` tables and `LiveDataTool` params; generate a read-only live-data plan before adding a live profile. |
| P1 | Debug-data request catalog | `VagOperationDelegate::getDebugDataRequests(Ecu*)`, `runDebugCommands`, `ADAPT`, `LONGADAPT`, module branches for gateway, engine, ABS, cluster, central electronics, infotainment, doors, battery regulator | Carista contains a large prebuilt diagnostic request table beyond the fog investigation. | Decode the static request strings and emit `docs/CARISTA_REVERSE/generated/pq25_debug_data_requests.json`; only promote entries that route through known safe read builders. |
| P1 | Full ECU discovery and capability model | `GetEcuInfoOperation`, `supportsDiagnostics`, `supportsAdaptation`, `supportsSingleCoding`, `supportsMultiCoding`, `getCodingRawAddress`, `getAdaptationRawAddress` | Current modeled scan is BCM-centric; future troubleshooting needs module-level capabilities. | Expand `VagCanEcu_buildPq25ScanPlan` from only BCM to all Polo modules proven by logs or recovered ECU tables. |
| P2 | ReadValues availability/current-value model | `ReadValuesOperation.getAvailableItems`, `ReadValuesOperation.getSettingValue`, existing `--check-settings-operation` gaps | Helps distinguish settings Carista really supports on this Polo from app-visible catalog noise. | Reconstruct the runtime availability/value object model or capture a live Java/native dump; keep writes blocked until value choice bytes are proven. |
| P2 | VAG adaptation read catalog | `ReadVagCanShortAdaptationDataCommand`, `ReadVagCanLongAdaptationDataCommand`, `readVagCanAdaptationValueInternal` | Adaptation channels are useful for diagnostics when named and bounded. | Use the debug-data/adaptation tables to build named read-only channel manifests; do not broad-scan routines. |
| P3 | Basic settings and actuator controls | Symbols for `VagCanSingleActuatorOperation`, `VagCanComplexBasicSettingOperation`, `VagCanSimpleBasicSettingOperation`, `VagUdsBasicSettingOperation`, `VagUdsActuatorControlOperation` | Useful for future repair workflows, but can move hardware. | Only document candidates until exact UI operation, preconditions, command sequence, and stop sequence are recovered. No default live runner. |
| P3 | Local DTC descriptions | `requestTroubleCodeDescriptions`, `getUpdatedTroubleCodesWithCachedDescriptions` | Carista likely enriches DTCs through cached/cloud descriptions. | Prefer a local decoder and offline description table. Do not depend on Carista cloud/API access. |

## Log Validation So Far

The retained car logs already prove that generic DTC work is worth pursuing, but
the best path is not only the BCM TP2.0 session:

| Area | Retained evidence | Meaning |
|---|---|---|
| BCM KWP DTC read | `1802FF00 -> 5800` in `docs/OBD_DIAGNOSTICS/session_artifacts/bcm_all_safe_reads_20260508_083940.json` | The current BCM path returned zero records in the latest captured state. |
| BCM UDS DTC variant | `1902FF -> 7F1911` in the same artifact | UDS `19/02` is not supported in that BCM TP2.0 session. |
| Other UDS module DTCs | `711->77B 1902FF -> 590299D20000` in `drive_20260429_1055_dtc_detail_711_714_uds_header_scan.json` | Another module responded positively to UDS DTC status reads. |
| Other UDS module DTCs | `714->77E 1902FF -> 590299C4010008` in the same artifact | A complete `C40100` record with status `08` was captured. |
| UDS DTC extended record | `714->77E 1906C40100FF -> 5906C4010008` in the same artifact | DTC-specific detail service works on at least one module/header pair. |

This means the next Carista diagnostics work should model module/header-aware DTC
scans, not just add more BCM-only commands.

## Implemented 2026-05-14

The first Carista diagnostics recovery slice is now coded and validated:

```powershell
.\.venv\Scripts\python.exe -m CaristaReproduction --diagnostics-plan --no-full-log
.\.venv\Scripts\python.exe .\obd-on-pc\pq25_read_monitor.py --list-profiles
.\.venv\Scripts\python.exe .\obd-on-pc\scan_vag_uds_headers.py --list-profiles
.\.venv\Scripts\python.exe .\obd-on-pc\decode_diagnostic_payload.py 77E07590299C4010008 77E10145906C4010008
```

Generated artifact:

```text
docs/CARISTA_REVERSE/generated/diagnostics_plan.json
```

New read-only live profiles:

| Profile | Requests | Use |
|---|---|---|
| `carista-dtc` | `1802FF00`, `1902FF` | BCM-safe Carista-shaped DTC status read set. |
| `carista-dtc-detail-known` | `1802FF00`, `1902FF`, `1906C40100FF`, `1904C40100FF` | Known retained DTC detail probes only; in `pq25_read_monitor.py` this remains BCM/TP2.0-limited. |

`scan_vag_uds_headers.py` also has `carista-dtc` and
`carista-dtc-detail-known` profiles for module-aware ISO-TP UDS header work.
Its built-in identity and Carista DTC commands now use `CaristaReproduction`
request builders, and the scanner retries read-only requests after `7F xx 78`
response-pending before classifying the result.

The decoder now translates:

```text
58010C9820       -> KWP/VAG DTC candidate 03224, raw status 0x20
590299C4010008   -> UDS DTC C40100, SAE candidate U0401:00, confirmedDTC
590299D20000     -> UDS DTC status response with incomplete trailing D20000
5906C4010008     -> UDS extended-data response for C40100 with no extra data bytes
62F187...        -> UDS DID F187 part-number responses
62F1A5...        -> UDS DID F1A5 workshop/programming fingerprint responses
5A9A...          -> KWP 1A9A Carista VAG CAN long-coding responses
7F1978           -> UDS responsePending
```

No-response/reset finding: the recovered Carista prevention pattern is not a
single reset command. It is a transport policy: reopen half-open TP2.0 channels,
retry open and channel-parameter setup, send ACK plus `A3` receive-more before
giving up on a partial sequence, tolerate `7F xx 78`, drop stale sequence
frames, and close with `A8` before a fresh adapter reset/reopen.

## Recommended Implementation Order

1. Add a read-only diagnostics model in `CaristaReproduction`.

   Suggested files:

   ```text
   CaristaReproduction/VagDiagnosticsOperation.py
   CaristaReproduction/Commands/VagDiagnosticCommands.py
   ```

   Initial scope:

   ```text
   GetVagCanTroubleCodesCommand candidate: 1802FF00
   GetVagUdsTroubleCodesCommand candidate: 1902FF
   ReadVagUdsExtRecordByDtcCommand candidate: 1906 + dtc + status_mask_or_record
   ```

   These candidates are already present in live logs, but the implementation
   should label them as candidates until the concrete Carista command builders
   are recovered from native code.

2. Extend the offline decoder before adding more live scan profiles.

   `obd-on-pc/decode_diagnostic_payload.py` should decode:

   ```text
   58 KWP DTC response
   59 02 UDS reportDTCByStatusMask
   59 04 UDS reportDTCSnapshotRecordByDTCNumber
   59 06 UDS reportDTCExtDataRecordByDTCNumber
   7F negative responses, including 11, 31, 78
   ```

3. Add a guarded read-only live profile only after step 1 exists.

   The live profile should call request builders from
   `CaristaReproduction.Commands.VagDiagnosticCommands`, not inline raw strings
   in `pq25_read_monitor.py`.

   Suggested profiles:

   ```text
   carista-dtc
   carista-dtc-detail-known
   ```

4. Decode `getDebugDataRequests(Ecu*)` into a generated manifest.

   First output should be data, not live execution:

   ```text
   docs/CARISTA_REVERSE/generated/pq25_debug_data_requests.json
   ```

   Each row should capture:

   ```text
   module / ECU family
   request bytes or decoded request string
   request kind: raw, ADAPT, LONGADAPT, live-data
   recovered function/source address
   safety class: read-only, routine-read, guarded, blocked
   current validation status
   ```

5. Recover live-data tools as a separate path.

   Do not mix live-data recovery into DTC scan work. The dynamic-data path has
   its own batching, availability, and result model:

   ```text
   VagOperationDelegate::readRawValuesMulti
   chunk limit: 6
   OperationDelegate::runCommand<DynamicDataModel>
   ```

6. Keep write and clear paths out of default diagnostics.

   `resetCodes`, `ClearEngineDiagnosticInformationCommand`, actuator controls,
   basic settings, DPF regen, battery registration, and auxiliary-heater
   operations should remain blocked unless a future tool adds explicit
   operation-specific preflight, confirmation, and post-checks.

## Specific Static Targets To Continue

These are the next native/static artifacts worth reading before writing more
live tooling:

```text
carista_apk_analysis/ghidra_adaptation_probe/functions/0127AC80_runCheckFaultsDebugCommands.c
carista_apk_analysis/ghidra_adaptation_probe/functions/0127AE84_runFreezeFrameDebugCommands.c
carista_apk_analysis/ghidra_adaptation_probe/functions/0127B630_getUpdatedTroubleCodesWithCachedDescriptions.c
carista_apk_analysis/ghidra_adaptation_probe/functions/0126EFD0_requestTroubleCodeDescriptions.c
carista_apk_analysis/ghidra_adaptation_probe/functions/0126C384_getDebugDataRequests.c
carista_apk_analysis/ghidra_adaptation_probe/functions/0126FBE2_getDetectableLiveData.c
carista_apk_analysis/ghidra_adaptation_probe/functions/01270CF8_readRawValuesMulti.c
carista_apk_analysis/ghidra_adaptation_probe/functions/012BC260_LiveDataOperation.c
carista_apk_analysis/ghidra_adaptation_probe/functions/012CA1CC_ReadLiveDataOperation.c
carista_apk_analysis/ghidra_adaptation_probe/functions/012CD298_readObd2LiveDataToolAvailability.c
```

Blocked or guarded-only targets:

```text
carista_apk_analysis/ghidra_adaptation_probe/functions/0126ECAC_resetCodes.c
ClearEngineDiagnosticInformationCommand
VagCanSingleActuatorOperation
VagUdsActuatorControlOperation
VagCanSimpleBasicSettingOperation
VagCanComplexBasicSettingOperation
VagUdsBasicSettingOperation
VagUdsDpfRegenOperation
VagCanBatteryRegOperation
VagUdsBatteryRegOperation
```

## Practical Next Task

The next concrete task is dynamic module-aware DTC detail:

1. Seed the UDS header scanner only with headers proven in retained logs,
   starting with `711->77B`
   and `714->77E`.
2. For each module, read `1902FF`; only issue `1906<dtc>FF` or `1904<dtc>FF`
   for complete DTCs found in that same run.
3. Add generated JSON output that groups DTCs, detail records, decoded payloads,
   request header, and response header per module.
4. Keep clear-DTC, actuator, basic-setting, security, and write services out of
   the default runner.

The older P0 BCM-only DTC slice and static module-aware profiles are
implemented. The open value is now dynamic detail follow-up per DTC found in the
same module run.
