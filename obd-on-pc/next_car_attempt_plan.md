# Next Car Attempt Plan

Purpose: keep the next live session short and evidence-driven.

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
carista_apk_analysis/carista_supported_settings_map.md
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

The offline composer for the final shape is `compose_carista_3b9a_tuple.py`,
but it must only be used with recovered real raw-address and tail bytes.

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

## Carista-Only Next Step

Because the phone is currently unavailable, the traced Carista UI-toggle path is
prepared but not actionable for the next car visit. Keep it as the fastest route
when the phone is available again.

Use the capture workflow documented here:

```text
carista_apk_analysis/next_carista_cornering_capture.md
```

The new capture tooling is:

```text
carista_apk_analysis/run_carista_cornering_trace.py
carista_apk_analysis/carista_cornering_trace.js
carista_apk_analysis/summarize_carista_cornering_trace.py
```

What that trace must recover from one real cornering setting change:

```text
- setting name/event string
- nativeId / native Setting pointer
- insertValue bytes
- getSettingRawAddress raw key
- WriteVagCodingCommand ctor value
- 4-byte raw-address vector
- coding type and tail bytes
```

That is the shortest path to a correctly shaped adapter-only write.

Without the phone, the next car step is adapter-only verification: read the
current long coding, decode it, and confirm whether byte 12 bit 6 and byte 21
bit 2 are still clear before deciding anything about writes.

## In-Car First Step

From `obd-on-pc`:

```powershell
.\run_next_car_probe.ps1 -Port COM10
```

This only performs a fresh read-only direct `220600` coding read and writes a
timestamped log plus JSON/CSV summary. It then runs the decoder and writes:

```text
logs/pq25_next_baseline_220600_settings_report.txt
```

That report compares the fresh read against the known-good cornering-enabled
coding, shows the high-confidence cornering bits, and includes a full bit table
with unknown values labelled as unknown.

Optional direct KWP comparison, still read-only:

```powershell
.\run_next_car_probe.ps1 -Port COM10 -IncludeKwpReads
```

Do not automatically send `31B80000` yet. Carista's simulator uses it as a
VAGCAN20 capability/metadata query, but it starts with `31`, which this project
previously blocked from scripted read-only sweeps. Treat it as a deliberate
manual diagnostic probe only after we decide the risk is acceptable.

Only retest the older `1089` branch as a negative-control comparison:

```powershell
.\run_next_car_probe.ps1 -Port COM10 -IncludeOldSessionBranch
```

## Write Decision Gate

Do not execute another write unless one of these is true:

```text
1. The structured Carista 3B9A value/address/tail is derived for the real cornering setting from a traced Carista toggle.
2. The exact same tuple has been reviewed offline and mapped back to the two missing long-coding bits.
3. A deliberate manual full-coding write is chosen with the latest readback as
   baseline, accepting that this is not yet the proven Carista-shaped route.
```

If using the Python writer anyway, the only parsed full-coding baseline is
direct `2E0600`, and it must start from a fresh `220600` readback and end with
another immediate `220600` verification.
