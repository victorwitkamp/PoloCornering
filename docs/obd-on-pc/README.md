# OBD On PC

This folder mirrors the PC-side status for the Polo 6R / PQ25 BCM work.

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
obd-on-pc/write_carista_uds_coding.py
```

For the next prepared lighting write, use the profile wrapper:

```text
obd-on-pc/run_next_pq25_lighting_write.ps1
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

## Read-Only Light Debug

The adapter-only light-state snapshot command is:

```text
python obd-on-pc/vw_tp20_readonly_probe.py --mode direct_sequence --port COM10 --parameter-profile carista_then_minimal --read-profile bcm_light_debug --timeout 2.5 --run-id pq25_light_debug_baseline
```

This stays on the recovered Carista TP2.0 path, tries Carista's exact channel
parameters before the Polo-proven fallback, and sends only Carista-recovered
reads plus read-only status/DTC reads. It does not attempt VCDS-only measuring
blocks or blocked routine/write services.

For broader read-only UDS module discovery, use:

```text
python obd-on-pc/scan_vag_uds_headers.py --port COM10 --baud 38400 --run-id uds_scan
```

That scanner uses normal UDS ELM setup (`ATCAF1`, `ATV0`) and only sends safe
read services by default.

## Useful Files

Current reports:

```text
obd-on-pc/next_car_attempt_plan.md
docs/obd-on-pc/pq25_current_settings_carista_report.md
docs/obd-on-pc/pq25_last_known_settings_and_light_debug_plan.md
docs/obd-on-pc/drive_20260429_diagnostic_collection_report.md
docs/obd-on-pc/pq25_latest_live_longcoding_decode.md
docs/obd-on-pc/pq25_bcm_6R0937087K_longcoding_report.md
```

Core scripts to keep:

```text
obd-on-pc/vw_tp20_readonly_probe.py
obd-on-pc/scan_vag_uds_headers.py
obd-on-pc/collect_drive_diagnostics.ps1
obd-on-pc/write_carista_uds_coding.py
obd-on-pc/write_pq25_lighting_profile.py
obd-on-pc/decode_pq25_longcoding.py
```

Current Carista/PQ25 catalog outputs:

```text
docs/carista_apk_analysis/pq25_carista_setting_catalog.md
carista_apk_analysis/pq25_carista_settings_catalog.csv
carista_apk_analysis/pq25_carista_longcoding_bits.csv
carista_apk_analysis/pq25_carista_setting_catalog.json
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
obd-on-pc/vw_tp20_readonly_probe.py blocks 27..., 2E..., 31..., and 3B... services
```

Historical compact `3B9A` research remains useful as background for Carista's
setting-write model, but it is not the live-proven writer for this BCM. The
working writer is the Carista-shaped UDS DID `0600` sequence above.
