# Next Car Attempt Plan

Purpose: keep the next live session short and evidence-driven.

## In-Car Tuple-Proof Read Result - 2026-04-28

The no-phone tuple-proof read was run in the car on `COM10` and stayed
read-only.

Fresh direct `220600` baseline still matches the known broken coding:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Tuple-proof metadata result:

```text
direct 1A9B: one run returned 7F1A11; later broad KWP profile had no response
1089 + focused pre-read 1A9B variants: no 5A9B
fallback session-counter/pre-read variants: no 5A9B
skip-parameters 1089/read_sweep 1A9B: no 5A9B
direct carista_kwp profile: 1A9F/1A9A no response; 1A91/1A86 returned 7F1A11
```

Generated evidence:

```text
docs/obd-on-pc/logs/pq25_tuple_proof_read_report.md
logs/pq25_tuple_proof_read_report.json
logs/pq25_tuple_proof_direct_carista_kwp_direct_read_summary.json
```

Conclusion: the actual tuple is still not proven from in-car reads. Do not run
more `1A9B` sweeps in the car unless a new sequencing hypothesis is recovered
offline or a phone/Carista trace becomes available.

## Prepared Field Checklist - 2026-04-27

Goal for the next in-car session: confirm the BCM still has only the two
cornering/fog-light bits disabled, then capture the missing positive `1A9B`
metadata needed to prove the Carista-shaped tuple. Do not spend the visit on
new guessed writes.

Bring/confirm before starting:

```text
- laptop on power or high battery
- Carista adapter paired as COM10
- ignition stable; engine running or charger attached if the session will be long
- no phone is required for the tuple-proof read path
```

## Carista Reimplementation Validation Workflow - 2026-04-28

From `obd-on-pc`, run this as the primary no-phone proof workflow:

```powershell
.\run_next_carista_validation.ps1 -Port COM10
```

This is read-only and uses the recovered Carista function names as the live
validation boundary:

```text
GetVagCanEcuInfoCommand_getRequest      -> 1A9B
ReadVagCanLongCodingCommand_getRequest  -> 1A9A
GetVagCanEcuInfoCommand_processEcuInfo  -> positive 5A9B parser
VagOperationDelegate_writeVagCanCodingValue / WriteVagCodingCommand_getRequest -> dry-run only
```

`carista_vagcan_repro.py --validate-workflow` then checks the whole process:

```text
1. current long coding is loaded from 220600/5A9A data
2. the PQ25 cornering settings are mapped for this car
3. positive 5A9B ECU metadata is decoded if present
4. complete 3B9A tuples are built only when metadata is present
```

The wrapper performs:

```text
1. fresh direct 220600 baseline read
2. decoded baseline report
3. direct 1A9B/1A9A using the proven minimal TP2.0 parameter profile
4. same-channel 220600 -> 1A9B -> 1A9A using the proven minimal TP2.0 parameter profile
5. direct 1A9B/1A9A using Carista's decompiled A00194FF82FF parameter profile
6. automatic summary/decoder for any positive 5A9B response
```

Expected output files:

```text
logs/pq25_carista_validation_baseline_220600_direct_read_summary.json
docs/obd-on-pc/logs/pq25_carista_validation_baseline_220600_settings_report.txt
logs/pq25_carista_validation_carista_builders_minimal_direct_read_summary.json
logs/pq25_carista_validation_same_channel_minimal_direct_sequence_summary.json
logs/pq25_carista_validation_carista_builders_carista_params_direct_read_summary.json
docs/obd-on-pc/logs/pq25_carista_validation_report.md
docs/obd-on-pc/logs/pq25_carista_repro_workflow.json
logs/pq25_carista_validation_report.json
```

Success condition:

```text
docs/obd-on-pc/logs/pq25_carista_validation_report.md shows a positive 5A9B response and decodes:
- rawAddress4 = payload[0x0c:0x10]
- coding selector = payload[0x10]
- tail = payload[0x11:0x14] for type-2/type-4 selector branches
- initial value6 = payload[0x14:0x1a]

docs/obd-on-pc/logs/pq25_carista_repro_workflow.json then marks these gates as pass:
- read_long_coding
- map_supported_settings_for_car
- get_vag_can_ecu_info
- build_write_tuples
```

If successful, the report prints proof/dry-run tuple bytes generated through the
reimplemented Carista functions. Treat those as review material only; do not send
a write from the car session.

If the primary workflow does not find a positive `5A9B`, stop. The broad
fallback sweeps have already produced negative evidence and the old
`run_next_tuple_proof_read.ps1` wrapper was removed to avoid repeating them by
habit. Only add the optional session comparison when deliberately collecting a
single negative-control comparison:

```powershell
.\run_next_carista_validation.ps1 -Port COM10 -IncludeSessionComparison
```

For a short bench check without the car, print the command list only:

```powershell
.\run_next_carista_validation.ps1 -Port COM10 -DryRun
```

From `obd-on-pc`, run the safe prep wrapper first:

```powershell
.\run_next_cornering_write_prep.ps1 -Port COM10
```

This performs:

```text
1. direct TP2.0 220600 baseline read
2. decode against the known-good cornering-enabled coding
3. base-fog 3B9A value6 dry-run derivation
4. turn-signal 3B9A value6 dry-run derivation
```

Expected report if the car is still in the known broken state:

```text
current coding 3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
target coding  3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
byte 12 bit 6 clear -> set, base fog-light cornering
byte 21 bit 2 clear -> set, turn-signal-triggered cornering
base-fog value6    6C680ED000C8
turn-signal value6 412F60A60000
```

Decision gates:

```text
- If the fresh coding differs from the expected current coding in any extra byte, stop and decode that new state first.
- If the two-bit delta is still exact, prioritize `run_next_carista_validation.ps1` to capture positive `1A9B` metadata.
- If positive `1A9B` is not captured, keep the session read-only and leave with the fresh logs.
- Only run a write after real rawAddress4/codingType/tail metadata has been recovered and the complete generated request has been reviewed.
```

No-go list for this visit:

```text
- no placeholder rawAddress4 values
- no blind 3B9A + full 30-byte coding retry
- no default 1089 + did-0600 retry; that path caused A8 disconnect
- no broad sweeps of 27, 2E, 31, or 3B services
- no `31B80000` probe as a substitute for positive `1A9B` metadata
```

## Current State

Latest confirmed live coding:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Known-good working coding:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Only two bytes differ:

```text
byte 12: 2C -> 6C
byte 21: A2 -> A6
```

That sets:

```text
byte 12 bit 6 = base fog-light cornering function
byte 21 bit 2 = turn-signal-triggered cornering assist
```

VCDS reference check:

```text
C:\Users\victo\Downloads\VCDS-Release-26.3.0-Installer\Labels\6R-09.lbl
```

confirms this BCM family redirects to `6R0-937-08x-09.CLB` as `High+`, matching
`6R0937087K`. The actual CLB is binary/encrypted, so it confirms the right label
family but does not give this project a full plaintext bit map. Details are in:

```text
vcds_pq25_reference_notes.md
```

## Carista Write Finding

Do not repeat the old blind full-coding `3B9A` write. Carista's native builder
does not match that shape.

Current Carista-shaped model:

```text
3B9A + 6-byte value + 4-byte coding raw address + coding-type-dependent tail
```

Latest offline bridge result:

```text
ChangeSettingOperation uses shared_ptr<Setting> + value bytes.
WriteRawValuesOperation is the separate lower-level vector<pair<uint64, bytes>> path.
The next offline blocker is the compiled VagCanSettings catalog / SettingRef bridge for the cornering setting, not another guessed standalone raw key.
```

Offline Carista label mapping now points to the same two practical bits:

```text
Carista "Cornering lights (using fog lights)" / "Use cornering lights"
  -> byte 12 bit 6

Carista "Turn on cornering lights when turn signal is on"
  -> byte 21 bit 2
```

This maps the visible setting effect, but it still does not recover Carista's
exact compact write tuple.

The broader generated Carista settings map is now available for filtering and
handoff work:

```text
../carista_apk_analysis/carista_supported_settings_map.md
carista_apk_analysis/carista_supported_settings_map.csv
carista_apk_analysis/carista_supported_settings_map.json
```

It marks only the two cornering chunks as pending write targets. CH/LH and ADL
rows are context only because their mapped bits do not differ between the
current and known-good BCM coding.

The latest tuple recovery narrows the likely 6-byte value vectors if Carista is
writing 6-byte coding chunks:

```text
byte 12 bit 6 target chunk: 6C680ED000C8
byte 21 bit 2 target chunk: 412F60A60000
```

Still missing before a Carista-shaped write is complete:

```text
rawAddress4 for each chunk
coding type / tail bytes
required pre-write session/state
```

That means the remaining write work is now deliberately narrow:

```text
1. Confirm the car still reports the two cornering bits as clear with a fresh 220600 read.
2. Recover or trace the real Carista tuple metadata for each changed chunk:
   - base-fog:    value6 6C680ED000C8 + unknown rawAddress4/codingType/tail
   - turn-signal: value6 412F60A60000 + unknown rawAddress4/codingType/tail
3. Dry-run the exact structured 3B9A request and verify the TP2.0 frame split.
4. Only execute a write after the generated 3B9A request is reviewed and repeated
   exactly through --confirm-request.
5. Immediately re-read 220600 and compare the result with the known-good coding.
```

The shared Python reproduction module is `carista_vagcan_repro.py`. It contains
the recovered Carista-named request/parser/builder functions and is used by both
the composer and the tuple-proof summarizer.

The offline composer for the final shape is `compose_carista_3b9a_tuple.py`.
It can derive the two cornering `value6` chunks from a fresh long-coding read
with `--cornering-fix base-fog` or `--cornering-fix turn-signal`, but it must
only print a complete request when recovered real raw-address, coding type, and
tail bytes are supplied.

The direct `2E0600 + full coding` attempt was parsed by the BCM but rejected
with `7F2E22`, so it proves the address/service is meaningful but not that the
write path is complete.

New offline writer-flow finding:

```text
Carista's lower writer takes a 64-bit raw-value key plus compact value bytes.
writeVagCanCodingValue then resolves ECU coding metadata and builds:
3B9A + 6-byte value + 4-byte raw address + coding-type/tail.

The coding type path preserves type 2, normalizes most other coding to type 3,
and has a sentinel path that forces type 5.
```

This means the missing data is probably attached to the native Setting/catalog
entry or ECU metadata, not recoverable from `220600` alone.

## Adapter-Only Next Step

The phone/Frida trace route was removed from the active tree. Without a phone,
the next car step is adapter-only validation: read the current long coding,
decode it, and try the recovered Carista `1A9B`/`1A9A` read builders with the
minimal and Carista-exact TP2.0 parameter profiles.

## In-Car First Step

From `obd-on-pc`, use the Carista-shaped validation wrapper first:

```powershell
.\run_next_carista_validation.ps1 -Port COM10
```

This performs a fresh read-only direct `220600` coding read, runs the decoded
settings report, then tries the decompiled `1A9B`/`1A9A` builders with the two
most relevant TP2.0 parameter profiles. It writes:

```text
docs/obd-on-pc/logs/pq25_carista_validation_report.md
```

That report compares the fresh read against the known-good cornering-enabled
coding and decodes any positive `5A9B` response into the missing tuple metadata.

For the fuller next-visit workflow, use the prepared write-readiness wrapper:

```powershell
.\run_next_cornering_write_prep.ps1 -Port COM10
```

It still performs only read/dry-run work:

```text
1. fresh direct 220600 baseline read
2. decoded settings report
3. base-fog structured tuple dry-run/value6 plan
4. turn-signal structured tuple dry-run/value6 plan
```

If positive `1A9B` or later offline RE has recovered real tuple metadata,
include it to produce complete dry-run requests:

```powershell
.\run_next_cornering_write_prep.ps1 -Port COM10 `
  -BaseFogRawAddress4 <real-4-byte-hex> -BaseFogCodingType <real-type> -BaseFogTail <real-tail-if-any> `
  -TurnSignalRawAddress4 <real-4-byte-hex> -TurnSignalCodingType <real-type> -TurnSignalTail <real-tail-if-any>
```

The wrapper does not execute writes. It writes the dry-run plans to:

```text
docs/obd-on-pc/logs/pq25_next_base_fog_tuple_dry_run.txt
docs/obd-on-pc/logs/pq25_next_turn_signal_tuple_dry_run.txt
```

After reviewing one complete dry-run request, the guarded manual writer is:

```powershell
python .\write_carista_3b9a_tuple.py --request <reviewed-3B9A-request> --skip-session --execute --confirm-request <same-reviewed-3B9A-request> --i-understand-this-writes-bcm-coding
```

Do not run the manual writer with placeholders.

Optional direct KWP comparison is already included in `run_next_carista_validation.ps1`.
The most valuable result would be a positive `1A9B` / `5A9B` response from
`6R0937087K`; Carista's parser uses that response to fill the final
rawAddress4/coding selector/tail fields.

Do not treat `31B80000` / `71B8` shorts as the missing rawAddress4 proof.
The latest static pass shows they are ECU-list/coding-address-short metadata,
while the write tuple consumes fields from positive `1A9B`. Do not use the old
`00200106` or `00000106` tuple guesses as write candidates.

Only retest the older `1089` branch as a negative-control comparison:

```powershell
.\run_next_carista_validation.ps1 -Port COM10 -IncludeSessionComparison
```

## Write Decision Gate

Do not execute another write unless one of these is true:

```text
1. The structured Carista 3B9A value/address/tail is derived for the real cornering setting from a traced Carista toggle.
2. A positive `1A9B` for this exact BCM, or an equivalent native catalog record,
  proves the rawAddress4/coding selector/tail and the final tuple is mapped
  back to the two missing long-coding bits.
3. A deliberate manual full-coding write is chosen with the latest readback as
   baseline, accepting that this is not yet the proven Carista-shaped route.
```

If using the Python writer anyway, the only parsed full-coding baseline is
direct `2E0600`, and it must start from a fresh `220600` readback and end with
another immediate `220600` verification.
