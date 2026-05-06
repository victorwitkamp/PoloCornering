# OBD On PC

This folder contains the PC-side tooling for the Polo 6R / PQ25 BCM work.

Core rule: recovered Carista behavior belongs in `CaristaReproduction/`.
Files in this folder may open COM ports, call package APIs, launch PowerShell
wrappers, and store logs, but they must not grow new Carista protocol/session/
operation logic.

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

## Historical Write Evidence

The previous live long-coding runner was removed. Future live write/read runners
must be temporary thin scripts that call recovered `CaristaReproduction` symbols
and must be cleaned up after the session.

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
- There is no default-channel fallback flag; if the Carista parameter setup does not answer, stop.
```

This keeps the live writer close to Carista where proven: Carista-shaped write
sequence, native frame timing, exact transmit-ACK expectation, and fresh channel
boundaries after ECU disconnects.

## Active Lead

Carista's instruction for cornering/fog behavior names three settings:

```text
Use fog lights when...
Use the left fog light as...
Use the right fog light as...
```

The first family maps to the already-tested byte `12` / byte `21` long-coding
bits. The preferred x86 static pass also proved the direct visible fog-role
labels are not VW/PQ25 setting objects:

```text
car_setting_fog_when               -> FordSettings::getSettings
car_setting_left_fog_light_as      -> FordSettings::getSettings
car_setting_right_fog_light_as     -> FordSettings::getSettings
```

Do not flip unknown long-coding bits for those labels. The current target is an
alternate VAG key, availability object, or ReadValuesOperation value path behind
equivalent fog-role behavior.

## Read-Only Carista Procedure

Persistent live read runners were removed. To inspect the recovered
`ReadValuesOperation` flow, use:

```text
python -m CaristaReproduction --read-values-plan
```

Any future adapter run must be implemented as a short-lived wrapper outside
`CaristaReproduction/`, then removed after use.

The old direct probe/capture runners were removed. If a future live capture
needs Carista behavior, add it under `CaristaReproduction` first and keep any
file in this folder as a thin wrapper.

Existing guided-capture logs can still be analyzed offline:

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

For broader read-only UDS module discovery, use:

```text
python scan_vag_uds_headers.py --port COM10 --baud 38400 --run-id uds_scan
```

This scanner uses normal UDS ELM setup (`ATCAF1`, `ATV0`) and only sends safe
read services by default.
The terminal output is intentionally concise: adapter open/init, discovery
progress, detail-read progress, responder hits, and output paths. The full text
log records every ELM command and response, including `ATSH`, `ATCRA`, all read
commands, no-response reads, and raw payloads. Use `--verbose` only when you
want the adapter init responses printed in the terminal too.

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
scan_vag_uds_headers.py
analyze_bcm_light_capture.py
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

Read-only live guardrail for any temporary runner:

```text
Do not send 27..., 2E..., 31..., or 3B... unless explicitly doing a confirmed write/routine operation.
```

Historical compact `3B9A` research remains useful as background for Carista's
setting-write model, but it is not the live-proven writer for this BCM. The
working writer is the Carista-shaped UDS DID `0600` sequence above.
