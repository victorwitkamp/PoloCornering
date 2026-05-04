# OBD On PC

This folder contains the PC-side tooling for the Polo 6R / PQ25 BCM work.

## Current State

Vehicle/controller focus:

```text
VW Polo 6R / PQ25
Module 09 / BCM / J519
Part: 6R0937087K
TP2.0 unit address: 20
Adapter: Carista on COM10 at 38400 baud
```

The working live path is TP2.0 unit `20` through the Carista adapter. The older
PQ26/MQB UDS path `70E -> 778` and the `055C` / `055D` lamp-channel reads did
not answer on this car and are not active targets.

Latest verified live coding after the 2026-05-01 diagnostics/high-beam test:

```text
3AB82B9F08A10000003008006C680ED000C8410F60860000200000000000
```

Earlier verified baseline coding:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Supplied/reference coding, not behavior-proven as the fix:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Only these bits differ between those two strings:

```text
byte 12 bit 6
byte 21 bit 2
```

Both bits were live-written and verified. The visible fog/cornering behavior was
unchanged, so they are mapped but behavior-ruled-out for the current symptom.

## Working Writer

Use the guarded Carista-shaped UDS writer for deliberate full long-coding writes:

```text
write_carista_uds_coding.py
```

For the next prepared lighting write, use the profile wrapper:

```text
.\run_next_pq25_lighting_write.ps1
```

Default dry plan:

```text
diagnostics-off-cornering -> previous-cornering-reference
```

That restores byte `19` bit `5` and byte `21` bit `5`, keeping the already
tested cornering-reference bits. Add `-Execute` only when connected in the car
and ready to write.

Recovered Carista-shaped sequence:

```text
2EF199 + YYMMDD
22F1A5 inline workshop-code read
2EF198 + workshop-code payload
2E0600 + full 30-byte coding
```

Final write success must be `6E0600`, followed by a fresh `220600` verification
read. The writer is dry-run by default and requires explicit confirmation flags
before any write.

Critical TP2.0 details:

```text
open request: 20C00010000301
open response: 22000D00003380301
send header: 338
listen header: 300
channel params used successfully: A00F8AFF32FF -> A10F8AFF4FFF
Carista exact parameter payload from libCarista.so: A00194FF82FF
ACK ECU response seq N with B((N + 1) & 0x0F)
advance outgoing counter per generated TP2.0 data frame
use ATST04 for non-final write frames and ATST20 for final/response frames
use about 130 ms between outgoing TP2.0 data frames
```

Write-channel recovery policy:

```text
- A write channel must answer TP2.0 channel parameters before any F199/F198/0600 write frame is sent.
- If parameter setup returns A8 or only NO DATA, close the suspect channel, wait, reopen, and retry once by default.
- If the retry still cannot negotiate parameters, stop and reset adapter/ignition before the next write attempt.
- Do not use --allow-default-channel-parameters for BCM coding writes unless deliberately reproducing old behavior.
```

This keeps the live writer close to Carista where proven: Carista-shaped write
sequence, native frame timing, exact transmit-ACK expectation, and fresh channel
boundaries after ECU disconnects. The exact Carista parameter payload exists in
the `carista` / `all` profiles, but this Polo has repeatedly answered the
known-good `A00F8AFF32FF` parameters instead.

## Active Lead

Carista's instruction for cornering/fog behavior names three settings:

```text
Use fog lights when...
Use the left fog light as...
Use the right fog light as...
```

The first family maps to the already-tested byte `12` / byte `21` long-coding
bits. The unresolved settings are now:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

Do not flip unknown long-coding bits for those settings without a recovered
Carista setting object, DID/adaptation key, raw tuple, or equivalent proof.

## Read-Only Carista Reads

The current read-only scan that best matches the recovered Carista
`ReadValuesOperation` flow is:

```text
python vw_tp20_readonly_probe.py --mode direct_sequence --port COM10 --parameter-profile carista_then_minimal --read-profile carista_read_values --timeout 2.5 --run-id pq25_carista_read_values
```

That opens TP2.0 unit `20`, tries Carista's exact `A00194FF82FF` channel
parameters first, falls back to the Polo-proven `A00F8AFF32FF` parameters, and
sends the read list generated from `CaristaReproduction`. It does not send
write/security/routine services.

For adapter-only light-state snapshots, use the Carista-shaped debug profile:

```text
python vw_tp20_readonly_probe.py --mode direct_sequence --port COM10 --parameter-profile carista_then_minimal --read-profile bcm_light_debug --timeout 2.5 --run-id pq25_light_debug_baseline
```

This stays on the Carista adapter path and sends only recovered Carista reads
plus read-only status/DTC reads. It does not attempt VCDS-only measuring blocks.

## Guided BCM Light-State Capture

Use the guided capture wrapper when you want comparable snapshots across driver
states without manually juggling run ids:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10
```

Before a long session, run the preflight check. It opens TP2.0 unit `20`, runs
one known-good read, writes normal capture outputs, and exits:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -PreflightOnly -RunId bcm_light_preflight
```

It prompts through these states by default:

```text
baseline_off
parking_fog_off
parking_fog_on
lowbeam_fog_off
lowbeam_fog_on
left_turn
right_turn
highbeam
reverse
```

At each prompt, press Enter to capture, type `s` to skip that state, or type
`q` to finish early and still write analyzer-ready outputs. The capture rewrites
the aggregate JSON/CSV/Markdown files after every completed state, so partial
in-car sessions are preserved.

Each state opens TP2.0 unit `20`, runs the `bcm_light_debug` read profile, closes
the channel, and writes JSON/CSV/Markdown reports under `logs/`. The Markdown
report highlights payload bytes that changed from the first captured payload for
the same command. That gives us a practical way to spot lamp/switch/live-data
deltas before guessing any more long-coding bits.

After a capture, run the offline analyzer against the generated JSON file:

```powershell
python .\analyze_bcm_light_capture.py .\logs\<run_id>_bcm_light_capture.json --output-prefix <run_id>
```

It writes a second Markdown report plus CSVs for diagnostic status/payload
summaries, diagnostic byte/bit deltas, repeat instability, raw CAN header
activity, and state-specific raw CAN payloads. Raw CAN rows are annotated with
the local PQ25 CAN reference in `obd-on-pc/pq25_can_reference.py` when the
header is known. The analyzer also reads the downloaded VW PQ DBC by default
and writes `<run_id>_raw_signal_deltas.csv`, which is usually the fastest way
to see which decoded raw CAN signals changed between states.

Optional raw CAN windows can be captured before each TP2.0 snapshot:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -RawCanSeconds 5
```

Raw ELM monitor-all output can drop frames on a busy bus, so treat it as a clue
source and repeat interesting states. For a tighter quick run:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -States "baseline_off,left_turn,right_turn,lowbeam_fog_on" -RawCanSeconds 5
```

For transient turn/cornering behavior, use the shorter `bcm_light_fast` read
profile so each state is sampled faster:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -ReadProfile bcm_light_fast -States "baseline_off,left_turn,right_turn,lowbeam_fog_on" -RawCanSeconds 5 -Repeats 2
```

The most useful focused raw-CAN pass is the openDBC-derived PQ25 light context
preset. It keeps BCM/comfort lamp state, steering angle, speed/brake context,
and cluster telltale messages:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -ReadProfile bcm_light_fast -States "baseline_off,left_turn,right_turn,lowbeam_fog_on,highbeam,reverse" -RawCanSeconds 5 -RawHeaders pq25_light_context -Repeats 2
```

If the ELM clone immediately returns only `STOPPED` for raw `ATMA`, retry with
an exact CAN hardware filter so the adapter does not have to stream the whole
500 kbit/s bus:

The Carista decompilation does not currently show a passive raw-CAN monitor path
(`ATMA`, `ATMR`, or `ATMT`). The recovered VAG CAN code uses active TP2.0
communication through ELM wrapper calls, so this filtered monitor pass is a
research fallback for our tooling rather than a copied Carista behavior.

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -ReadProfile bcm_light_fast -States "baseline_off,left_turn,right_turn" -RawCanSeconds 8 -RawHeaders pq25_light_context -RawCanMonitorMode atcf-atma -RawCanPerHeaderMs 1000 -Repeats 1
```

For the fastest proof-of-life check, target just `390` / `Gate_Komf_1` first:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -ReadProfile bcm_light_fast -States "baseline_off,left_turn,right_turn" -RawCanSeconds 5 -RawHeaders 390 -RawCanMonitorMode atcf-atma -RawCanPerHeaderMs 1500 -Repeats 1
```

That preset expands to headers `390,392,0D0,0C2,1A0,288,320,470`. Header
`390` / `Gate_Komf_1` is especially important: it carries decoded bits for
left/right blinkers, low beam, high beam, reverse, front fog switch/status, and
brake light. After analyzing this run, start with `_raw_signal_deltas.csv` and
look for rows such as `GK1_Blinker_li`, `GK1_Blinker_re`, `GK1_Abblendlicht`,
`GK1_Fernlicht`, `GK1_Nebel_ein`, `LH3_BLW`, or `LW1_LRW` changing from
`baseline_off`. If you specifically want TP2.0 transport noise instead, use:

```powershell
.\run_bcm_light_capture.ps1 -Port COM10 -ReadProfile bcm_light_fast -States "baseline_off,left_turn,right_turn" -RawCanSeconds 5 -RawHeaders tp20
```

For broader read-only UDS module discovery, use:

```text
python scan_vag_uds_headers.py --port COM10 --baud 38400 --run-id uds_scan
```

This scanner uses normal UDS ELM setup (`ATCAF1`, `ATV0`) and only sends safe
read services by default.

## Useful Files

Current reports:

```text
next_car_attempt_plan.md
../docs/obd-on-pc/pq25_current_settings_carista_report.md
../docs/obd-on-pc/pq25_last_known_settings_and_light_debug_plan.md
../docs/obd-on-pc/drive_20260429_diagnostic_collection_report.md
../docs/obd-on-pc/pq25_latest_live_longcoding_decode.md
../docs/obd-on-pc/pq25_bcm_6R0937087K_longcoding_report.md
```

Core scripts to keep:

```text
vw_tp20_readonly_probe.py
scan_vag_uds_headers.py
collect_drive_diagnostics.ps1
capture_bcm_light_state.py
analyze_bcm_light_capture.py
run_bcm_light_capture.ps1
write_carista_uds_coding.py
write_pq25_lighting_profile.py
decode_pq25_longcoding.py
```

Current Carista/PQ25 catalog outputs:

```text
../docs/carista_apk_analysis/pq25_carista_setting_catalog.md
../carista_apk_analysis/pq25_carista_settings_catalog.csv
../carista_apk_analysis/pq25_carista_longcoding_bits.csv
../carista_apk_analysis/pq25_carista_setting_catalog.json
```

## Background Facts

The Android Car Scanner backup contained engine and cluster coding only; it did
not contain unit `09` BCM coding.

Adapter findings:

```text
COM8 cheap ELM327 clone: engine only, unreliable for non-engine modules
COM10 Carista ELM327 v1.5: correct adapter for this workflow
```

Read-only script guardrail:

```text
vw_tp20_readonly_probe.py blocks 27..., 2E..., 31..., and 3B... services
```

Historical compact `3B9A` research remains useful as background for Carista's
setting-write model, but it is not the live-proven writer for this BCM. The
working writer is the Carista-shaped UDS DID `0600` sequence above.
