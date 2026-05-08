# PQ25 Live History Archive

Date: 2026-05-07

This archive combines the useful live-car facts that were previously split across
several older OBD notes. The active car-session instructions live in
`../../obd-on-pc/README.md`.

## Superseded Files

The following notes were folded into this archive or the active README:

```text
obd-on-pc/next_car_attempt_plan.md
docs/obd-on-pc/README.md
docs/obd-on-pc/pq25_current_settings_carista_report.md
docs/obd-on-pc/pq25_latest_live_longcoding_decode.md
docs/obd-on-pc/pq25_bcm_6R0937087K_longcoding_report.md
docs/obd-on-pc/pq25_last_known_settings_and_light_debug_plan.md
```

## Controller And Transport

```text
Vehicle: VW Polo 6R / PQ25
Module: 09 Central Electronics / BCM / J519
Part: 6R0937087K
Component: BCM PQ25 H+4
Software: 0254
TP2.0 unit address: 20
Adapter: Carista ELM327 on COM10 at 38400 baud
Open request: 20C00010000301
Data channel: send 338, listen 300
Carista exact params: A00194FF82FF
Polo-proven fallback params: A00F8AFF32FF
```

Safety boundary for read-only tooling:

```text
Do not send 27, 2E, 31, or 3B unless the session is explicitly a confirmed write/routine operation.
```

## Live Timeline

### 2026-04-28 Baseline And Reference

Earlier verified baseline:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Supplied/reference coding:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Only two bits differed:

```text
byte 12 bit 6
byte 21 bit 2
```

Both were live-written and verified. Physical fog/cornering behavior did not
change, so these bits are mapped but behavior-disproven as standalone fixes.

### 2026-04-29 Drive Diagnostics

Read-only drive collection through COM10 found stable BCM diagnostic payloads.
No known safe BCM read command exposed changing lamp-output state, lamp reason,
fog-switch state, or cornering trigger state.

Useful stable BCM reads included:

```text
220600 -> 620600 + 30-byte coding
220601 -> 6206011E
220606 -> 620606001800018000
22F187 -> 6R0937087K
22F189 -> 0254
22F197 -> BCM PQ25 H+4
```

Generic UDS scanning with normal UDS ELM setup found responders at `7E0`, `711`,
`714`, and `715`; it did not change the BCM cornering-light write path.

Later offline decoding of retained DTC/status payloads found:

```text
BCM TP2.0/KWP 1802FF00 -> 58020C9820038B20
   records: DTC candidates 03224 (0x0C98) and 00907 (0x038B), status 0x20 raw bit b5
BCM TP2.0/KWP 1802FF00 -> 58010C9820
   record: DTC candidate 03224 (0x0C98), status 0x20 raw bit b5
711->77B 1902FF -> 590299D20000
   UDS 19/02 response with availability mask 0x99 but incomplete DTC/status record D20000
714->77E 1902FF -> 590299C4010008
   UDS 19/02 response with DTC C40100, SAE-format candidate U0401:00, status 0x08 confirmedDTC
```

These are root-cause clues to correlate with module ownership and wiring, not
write seeds.

### 2026-05-01 / 2026-05-02 Backup Restore Context

Historical backup coding was restored and verified, then a post-restart read
showed byte 13 changed from `2B` to `6B`. This proved byte 13 is involved in a
CH/LH/parking-light context, but not a direct cornering-fog trigger.

Retained detailed reference notes:

```text
docs/obd-on-pc/polo_6r_vehicle_info_for_coding_expert.md
docs/obd-on-pc/vcds_pq25_reference_notes.md
docs/obd-on-pc/pq25_opendbc_light_context.md
docs/obd-on-pc/drive_20260429_diagnostic_collection_report.md
```

### 2026-05-05 DID 0600 Write-Proven Target

Fresh current read before write:

```text
220600 -> 6206003AB02BBF08A10000003008006C6A0CD000C0412F60860000200000000000
```

Guarded Carista-shaped write target:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Fresh verification read:

```text
220600 -> 6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Positive validation reads:

```text
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

The DID `0600` target write is proven, verified, persisted, and behavior-
disproven as a standalone fix.

### 2026-05-06 Engine-Running Context

Engine-running snapshot:

```text
220600 -> 6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

Physical behavior with the target persisted:

```text
front fogs behave as steady low-beam-linked outputs
front fogs turn off with high beam
left/right indicator does not create per-side cornering behavior
```

### 2026-05-07 Current Read And DRL-Via-Fogs Test

Current read-only confirmation with exact Carista channel params:

```text
220600 -> 6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

Recovered official 6R/PQ25 branch:

```text
car_setting_drl_via_fogs
DID 0600 byte 23 mask 0x04
whitelist CENTRAL_ELEC_6R_5C_7E_7H
interpretation YES_NO
```

Current byte 23 was `00`, so byte 23 bit 2 was clear. The test wrote the
DRL-via-fogs bit through the Carista-shaped `0600` path and verified the write,
but physical behavior did not change. DRL-via-fogs is therefore behavior-
disproven for this symptom.

The next action is restoring the expert coding backup:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

That value is the previous-coder backup and the correct target for returning the
car to the expert-backed baseline. It is not a proven cornering-light repair;
it is the known rollback state.

### 2026-05-08 In-Car Read-Only Troubleshooting

The live runner initially truncated `220600` because the ELM clone did not
reliably return all TP2.0 frames with the stricter response-timeout setup. The
live entrypoints were adjusted to match the older successful traces:

```text
send channel parameters before ATCRA300
prefer Polo-proven A00F8AFF32FF channel parameters
use ATST32 for live response collection on this ELM clone
fail cleanly if 220600 is shorter than 30 coding bytes
```

With that transport timing, the live read-only `220600` returned:

```text
220600 -> 6206003AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
```

Current zero-based byte facts:

```text
byte 12 = 6D: bit 6 set, base fog/cornering family still enabled; bit 0 set
byte 21 = 82: bit 7 set, bit 2 clear, bit 5 clear
byte 23 = 00: DRL-via-fogs clear
```

This is the expert-backup family with the turn-signal fog trigger cleared. It
is not the full expert `D2B` backup, which has byte 21 = `86`.

The only difference from the full expert backup is:

```text
current diagnostic coding: 3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
full expert D2B backup:   3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
byte 21 bit 2: clear -> set
```

Read-only companion one-shot reads, using a fresh TP2.0 channel per DID:

```text
1802FF00 -> 5800
1902FF -> 7F1911
22F187 -> 62F1873652303933373038374B20
22F189 -> 62F18930323534
22F197 -> 62F19742434D205051323520482B3420
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

The `1802FF00 -> 5800` response means no retained BCM DTC records were exposed
on this TP2.0/KWP status path during the still-on state. A short passive CAN
monitor attempt again retained no useful light-context frames with this ELM
clone, so live diagnosis remains dependent on diagnostic reads plus direct
physical observations.

The user then confirmed the green front-fog icon is lit while the unwanted fog
state is present. That is a high-value physical observation: the vehicle is not
merely powering the bulbs invisibly; it is also reporting a front-fog active
state to the driver. This pushes the suspected cause toward a front-fog request
input / light-switch path or BCM front-fog role ownership.

Additional passive monitor attempts:

```text
ATMA all frames, 10 seconds: no usable frames retained
ATMA after ATCM/ATCF reset, 10 seconds: no usable frames retained
ATCRA390 + ATMA: STOPPED, 0 frames
ATCRA392 + ATMA: STOPPED, 0 frames
ATCRA470 + ATMA: STOPPED, 0 frames
hard monitor probe: ATI/ATDP/ATCS OK, ATMR/ATMT unsupported, ATMA zero frames
interactive 20-second ATMA toggle window: zero parsed frames
monitor fix attempt: active 0100 diagnostic response OK, all ATMA profiles zero frames
protocol sweep: ATSP6/7/8/9/A/B all zero monitor frames
```

Monitor logs:

```text
obd-on-pc/logs/fog_icon_green_monitor_20260508_080718.txt
obd-on-pc/logs/fog_icon_green_filtered_monitor_20260508_080813.txt
obd-on-pc/logs/hard_monitor_probe_20260508_081033.txt
obd-on-pc/logs/interactive_monitor_toggle_20260508_081249.txt
obd-on-pc/logs/monitor_fix_attempt_20260508_081531.txt
obd-on-pc/logs/monitor_protocol_sweep_20260508_081741.txt
```

The monitor-fix attempt proved the adapter can still do active diagnostics:

```text
0100 -> 7E8 06 41 00 BE 3E A8 13
```

Therefore the limitation is specific to passive CAN monitoring through this
ELM/gateway path, not a dead adapter or wrong serial configuration. Treat
future in-car work with this adapter as active read-only TP2.0/UDS/KWP polling
plus confirmed writes only; do not rely on ATMA for comfort/light broadcast
state.

An active read-only monitor was added as the replacement path:

```powershell
.\obd-on-pc\run_bcm_active_monitor.ps1 -Label fog_switch_toggle
```

The monitor now has named read-only profiles:

```text
switch:       220601 220606 1802FF00
dtc:          1802FF00 1902FF
identity:     22F187 22F189 22F197 22F1A5
coding:       220600
carista-core: 1A9B 1A9F 1A9A 220600 220601 220606
kwp21-early: 2101 2102 2103 2104 2105 2106 2107 2108 2109 210A 210B 210C 210D 210E 210F
all-safe:     union of switch, dtc, identity, coding, and carista-core
```

The active monitor rejects `27`, `2E`, `31`, and `3B`, and it accepts only
read-service prefixes `18`, `19`, `1A`, `21`, and `22`.

The first six-cycle run during switch/fog-state troubleshooting produced no
payload changes:

```text
log: obd-on-pc/logs/fog_switch_toggle_active_20260508_082122.json
220601 -> 6206011E
220606 -> 620606001800018000
1802FF00 -> 5800
```

This proves the active monitor path is usable, but these known safe reads do not
expose the live fog-switch state on this BCM/session.

The first `all-safe` profile pass produced this result:

```text
log: obd-on-pc/logs/bcm_all_safe_reads_20260508_083940.json
220601 -> 6206011E
220606 -> 620606001800018000
1802FF00 -> 5800
1902FF -> 7F1911
22F187 -> 62F1873652303933373038374B20
22F189 -> 62F18930323534
22F197 -> 62F19742434D205051323520482B3420
22F1A5 -> 62F1A50005F3C7E719
220600 -> 6206003AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
1A9B -> 7F1A11
1A9F -> 7F1A11
1A9A -> 7F1A11
```

No new ELM/TP2.0 read-only monitor was found in that pass. The `1A9A`,
`1A9B`, and `1A9F` Carista-core native request builders are present in the
static model, but this live BCM rejects them in the current session.

Additional setup check:

```text
log: obd-on-pc/logs/carista_1a_after_1089_setup_20260508_084538.json
1089 -> 5089 before each 1A request
1A9B -> no payload
1A9F -> no payload
1A9A -> no payload
```

Earlier 2026-05-04 setup sweeps showed the reason: after `1089 -> 5089`, the
ECU sends `A8` when the tester ACKs the response. Reopening a fresh TP2.0
channel after `1089` still leaves `1A9B -> 7F1A11`. Conclusion: `1089` is a
valid KWP diagnostic-session command on this BCM, but it is not useful setup for
the current active monitor profiles or for the Carista-core `1A` requests.

KWP measuring-block/local-identifier probe:

```text
log: obd-on-pc/logs/kwp21_00_0f_probe_20260508_084738.json
2100 -> 7F2131
2101 -> 6101250087250034250087250031
2102 -> 610206807006806D25021C078000
2103 -> 61032500882500882500882501AB
2104 -> 61042500872500C12500A72500A7
2105 -> 61052500AD2500AD2500AD2500AD
2106 -> 61062500AB2500AB2500AB2500A7
2107 -> 61072500B22500B22500B22500B2
2108 -> 61082500A72500F82500F82500A7
2109 -> 61092500882500882500C0250000
210A -> 610A25021C25021C25021C25021C
210B -> 610B25021C25021C25021C2500C2
210C -> 610C2500A72500A72500A72500A7
210D -> 610D2500882500A72500A72500A7
210E -> 610E2500BF2500BF2500BF2500BF
210F -> 610F2500A72500BF3600002500F8
```

This is the first positive raw measuring-block monitor family found through the
Carista ELM/TP2.0 path. It did not require `1089`. The next useful live test is
state-snapshot comparison with `kwp21-early`: hold one switch/fog state for a
full cycle, change state for the next cycle, then compare changed payloads.

State comparison after the first `kwp21-early` captures:

```text
off: obd-on-pc/logs/kwp21_lights_off_20260508_085221.json
on:  obd-on-pc/logs/kwp21_lowbeam_fog_on_20260508_085416.json
on:  obd-on-pc/logs/kwp21_switch_compare_on_20260508_085624.json
```

Only `2102` changed:

```text
off 2102: 610206807006806D25021C078000
on1 2102: 610206807006806C25021C078000
on2 2102: 610206807106806D25021C078000
```

Decoded as VAG measuring-value triplets:

```text
block 1: 06 80 70/71 -> formula 6, supply voltage, 14.336/14.464 V
block 2: 06 80 6D/6C -> formula 6, supply voltage, 13.952/13.824 V
block 3: 25 02 1C -> decimal formula 37/raw value, stable
block 4: 07 80 00 -> formula 7, vehicle speed, stable 0.00 km/h
```

Conclusion: `2101` through `210F` are real measuring blocks, but this early
range did not expose the fog-switch bit. The only observed changes are voltage
drift/noise. Next live-search range should start at `2110`, preferably in
16-group chunks, with one known-off snapshot and one known-on snapshot per
chunk.

The aborted on-repeat run did not add state evidence:

```text
log: obd-on-pc/logs/kwp21_2102_on_repeat_20260508_085847.json
2102 -> no payload; TP2.0 open returned CAN ERROR in all six cycles
```

The active monitor now accepts generated KWP21 chunks:

```powershell
.\obd-on-pc\run_bcm_active_monitor.ps1 -Kwp21Range 10,1F -Cycles 1 -Label kwp21_10_1f_off
.\obd-on-pc\run_bcm_active_monitor.ps1 -Kwp21Range 10,1F -Cycles 1 -Label kwp21_10_1f_on
.\.venv\Scripts\python.exe .\obd-on-pc\analyze_kwp21_measurements.py .\obd-on-pc\logs\<off>.json .\obd-on-pc\logs\<on>.json
```

The active monitor also accepts generated read-only `22` DID ranges, generated
KWP `1A` local-ID ranges, and a non-default fog-role candidate profile:

```powershell
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile fog-role-candidates -Cycles 1 -Label fog_role_candidates
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile scaling-known-dids -Cycles 1 -Label scaling_known_dids
.\obd-on-pc\run_bcm_active_monitor.ps1 -Did22Range 0550,056F -Cycles 1 -Label did22_0550_056f
.\obd-on-pc\run_bcm_active_monitor.ps1 -Did22Range 0600,060F -Cycles 1 -Label did22_0600_060f
.\obd-on-pc\run_bcm_active_monitor.ps1 -Did22Range 0D00,0D1F -Cycles 1 -Label did22_0d00_0d1f
.\obd-on-pc\run_bcm_active_monitor.ps1 -Service1ARange 80,9F -Cycles 1 -Label service1a_80_9f
```

Use small ranges because each command opens a fresh TP2.0 channel. A positive
read is only a candidate current payload; it does not authorize a write unless
the matching Carista Setting object and requested-choice bytes are recovered.

Other service research, based on Carista code and public KWP/UDS service
references:

| Service | Meaning / local evidence | Scan decision |
|---:|---|---|
| `12`, `13`, `17` | KWP read freeze-frame / DTC status families; KWP references list them as read services alongside `18` | possible but low value for fog behavior; use only exact requests, not a broad identifier range |
| `18`, `19` | DTC reads; already used as `1802FF00` and `1902FF` | keep in safe monitor |
| `1A` | KWP read ECU identification; Carista builders recover `1A9A`, `1A9B`, `1A9F` | keep `-Service1ARange`; current BCM rejected the known Carista IDs in this session |
| `21` | KWP read data by local identifier | keep chunk scanning; this is the best ELM-side live measuring-block family found so far |
| `22` | ReadDataByIdentifier; Carista type-7/type-8 UDS paths use this | keep DID chunk scanning |
| `24` | UDS ReadScalingDataByIdentifier | allowed only as exact known-DID reads, via `scaling-known-dids` or `-Commands 240600`; useful metadata at best |
| `23` | ReadMemoryByAddress | do not blind scan; it needs an address/length map and can request arbitrary ECU memory |
| `2A` | ReadDataByPeriodicIdentifier | do not blind scan; it can start periodic traffic instead of a one-shot response |
| `2C` | DynamicallyDefineDataIdentifier / KWP dynamic local identifier | do not blind scan; it defines temporary identifiers in the ECU session |
| `2E` | WriteDataByIdentifier | only through guarded coding writes with fresh `220600` readback |
| `2F`, `30` | IO control by common/local identifier | do not blind scan; online VW examples use these for output tests and lamp forcing |
| `31`, `32`, `33` | Routine start/stop/results | do not broad scan; Carista has a precise VAG adaptation routine sequence, but routines can start arbitrary ECU actions |
| `34`-`37`, `38`-`3A`, `3B`, `3D` | upload/download/transfer/routine-by-address/write-memory/write-local-ID families | do not scan on the car |
| `3E` | TesterPresent | setup/keepalive only |
| `80`, `A0`-`BF` | KWP/VAG manufacturer-specific space | do not scan without a recovered Carista or VCDS payload |

Carista's recovered VAG CAN adaptation read path is:

```text
31B8 + basic id
31BA + basic id
31B9 + basic id + channel
31BA + basic id
32B8 + basic id
```

Basic id `0103` is short adaptation and `010A` is long adaptation. This is
native proof for Carista raw types 0/1. It is not the recovered path for the
`055C`/`055D` per-side fog candidates, because those are type-7 UDS adaptation
settings and dispatch through `22<DID>`, which returned `7F2231` live. A future
routine-control test should therefore target only a recovered short-adaptation
channel, with the exact five-step Carista sequence and a stop step, not a
`31xx` range sweep.

Sources used for the service matrix: ISO 14230/KWP service summaries list
`21`, `22`, `23`, `2C`, `2E`, `2F`, `30`, `31`, `32`, `33`, `3B`, `3D`, and
`3E`
([ISO 14230-3 sample](https://cdn.standards.iteh.ai/samples/iso/iso-14230-3-1999/d3588e9451af46f1917d23f75b9aea2e/iso-14230-3-1999.pdf));
UDS references list `23`, `24`, `2A`, `2C`, `2E`, `2F`, `31`, and `3E`
([py-uds service list](https://uds.readthedocs.io/en/latest/pages/knowledge_base/service.html),
[dissecto UDS notes](https://munich.dissec.to/kb/chapters/uds/uds.html));
VW output-test examples show service `31` routines and service `2F` IO control
being used to force lamp outputs
([CarHacking VW output-test thread](https://www.reddit.com/r/CarHacking/comments/1ldr4un/send_to_ecu_vw/));
Carista reproduction code recovers only the guarded `2E` coding write, the
read-only `1A`/`21`/`22` families, and the exact `31B8/31BA/31B9/32B8` VAG
adaptation sequence.

External tooling clue: VCDS/ODIS-style UDS Measuring Values are still the best
candidate monitor for live switch-state proof. UK-POLOS examples for a Polo 6R
BCM describe selecting BCM measurement values, filtering by a term, and watching
button/switch values change. That does not give us the raw local identifier or
DID for the Carista ELM path, but it suggests a real live monitor exists behind
named VCDS/ROD labels. If VCDS/ODIS is available, search module 09 measuring
values for `fog`, `front fog`, `light switch`, `terminal 58`, `turn signal`,
`cornering`, `steering angle`, and `G85`.

Interpretation: if the front fogs are still steady-on in the low-beam/rightmost
switch position while byte 21 bit 2 and byte 23 bit 2 are both clear, the
steady-fog symptom is not being produced by Carista's turn-signal-cornering
trigger or DRL-via-fogs setting. The next live check is physical/switch state:
whether the fog indicator is on without pulling the light switch and whether
the fog output changes when the switch is pulled once/twice.

## Known Bits

| Location | Recovered meaning | Current status |
|---:|---|---|
| byte 12 bit 0 | Scandinavian/Nordic parking/Standlicht behavior; exact PQ25 output impact still uncertain | set in latest 2026-05-08 diagnostic coding; guarded set/clear operation prepared |
| byte 12 bit 6 | base fog-light cornering / use-cornering family | set; behavior-disproven standalone; guarded set/clear operation prepared |
| byte 21 bit 2 | turn-signal-triggered cornering assist | clear in 2026-05-08 diagnostic coding; full expert backup would set it; guarded set/clear operation prepared |
| byte 21 bit 5 | turn off fogs with high beam | clear in 2026-05-08 diagnostic coding; previously matched observed high-beam cutoff when set; guarded set/clear operation prepared |
| byte 21 bit 7 | cornering/fog experimental capability | set; not sufficient standalone; guarded set/clear operation prepared |
| byte 23 bit 2 | DRL via fogs | clear after rollback; tested earlier and behavior-disproven for this symptom; guarded set/clear operation prepared |

The live runner has guarded current-coding set/clear operations for every
known relevant bit above. It reads fresh `220600`, changes only the selected
known bits, preserves every other byte, asks for literal `YES`, and verifies
with a fresh `220600` read.

| Bit | Set flag | Clear flag |
|---|---|---|
| byte 12 bit 0 | `-SetByte12Bit0` | `-ClearByte12Bit0` |
| byte 12 bit 6 | `-SetByte12Bit6` | `-ClearByte12Bit6` |
| byte 21 bit 2 | `-SetByte21Bit2` | `-ClearByte21Bit2` |
| byte 21 bit 5 | `-SetByte21Bit5` | `-ClearByte21Bit5` |
| byte 21 bit 7 | `-SetByte21Bit7` | `-ClearByte21Bit7` |
| byte 23 bit 2 | `-SetByte23Bit2` / `-SetDrlViaFogs` | `-ClearByte23Bit2` / `-ClearDrlViaFogs` |

Examples:

```powershell
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetByte21Bit2
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetByte21Bit2 -Write
.\obd-on-pc\run_restore_expert_backup_session.ps1 -ClearByte12Bit0 -ClearByte21Bit7
.\obd-on-pc\run_restore_expert_backup_session.ps1 -ClearByte12Bit0 -ClearByte21Bit7 -Write
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetDrlViaFogs -ClearByte21Bit7 -Write
```

The runner rejects contradictory set/clear requests for the same physical bit.
For example, do not combine `-SetByte23Bit2` with `-ClearDrlViaFogs`.

From the latest 2026-05-08 diagnostic state, the useful one-bit targets are:

```text
clear byte 12 bit 0: 3AB02BBF08A10000003008006C2B0CD000C0412F60820000200000000000
clear byte 12 bit 6: 3AB02BBF08A10000003008002D2B0CD000C0412F60820000200000000000
set byte 21 bit 2:   3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
set byte 21 bit 5:   3AB02BBF08A10000003008006D2B0CD000C0412F60A20000200000000000
clear byte 21 bit 7: 3AB02BBF08A10000003008006D2B0CD000C0412F60020000200000000000
set byte 23 bit 2:   3AB02BBF08A10000003008006D2B0CD000C0412F60820004200000000000
```

Requests that already match the fresh current coding become no-ops. For
example, the latest diagnostic state already has byte 23 bit 2 clear, so
`-ClearDrlViaFogs` is a no-op unless a later `220600` read shows byte 23 changed
back to `04`.

Research note for byte 21 bit 7: the recovered Play 9.8.3 x86 branch identifies
it as `car_setting_cornering_lights_via_fogs_experimental`, label
`Cornering lights (using fog lights) (experimental)`. The 6R/PQ25 branch pushes
`CENTRAL_ELEC_6R_5C_7E_7H`, DID `0600`, byte `0x15`/21, mask `0x80`, and the
YES/NO interpretation. It is an alternate experimental enable for cornering
lights using fogs. It is not a recovered per-side fog-role setting, not a
`0601` role owner, and not an output wiring assignment. Because the bit has
been set while physical cornering behavior was still absent, it is not
sufficient as a standalone fix; clearing it is only a controlled negative or
rollback test.

## Rejected Direct Reads

Do not repeat these by default; they already returned clean `7F2231` or other
negative evidence on this BCM/session:

```text
22055C, 22055D, 22110E, 22056D, 220550, 220551, 220D01, 220A58, 220A57
```

The per-side `055C` / `055D` branch remains static evidence only. No positive
current raw payload or payload length exists for a safe write seed.

## Unresolved Issues

The unresolved problem is now narrower than "which cornering bit is missing".
All recovered direct 6R/PQ25 cornering or DRL-via-fogs `0600` bits are either
already set or behavior-disproven. The remaining hypotheses are ordered below.

1. Paired front-fog request or switch input

   The visible behavior is both fogs steady in the low-beam/headlight switch
   position and off with high beam. That is consistent with an ordinary
   front-fog request plus the already-set high-beam fog cutoff bit, not with a
   missing blinker-trigger bit. The next car observation should check whether
   the front fog indicator is lit without pulling the switch and whether the
   switch changes the fog state independently.

2. Output wiring or unsupported per-side ownership

   One-bulb H8 lamps can be fog plus static-cornering only if the BCM has
   left/right ownership of the outputs. The unresolved physical proof is whether
   this car is wired through separate BCM outputs `T73b/9` and `T73b/10` with
   supply on `T73b/11`, or through an ordinary/bridged front-fog path where
   software cannot create visible per-side cornering.

3. `220601 -> 6206011E` role clue

   `1E` matches a recovered Carista per-side role enum value for
   `car_setting_enabled_coming_home_or_leaving_home`, but no official x86
   `0601` constructor or positive writable raw path is recovered for
   `6R0937087K`. Play 9.8.3 x86 does include a readable `ECU VAGCAN20 220601:
   6206011E` simulator/sample-response row, which reinforces the value as a
   real Carista-known role clue without making it a recovered write path. This
   remains the strongest software clue and is not a write seed.

4. Missing VAG/PQ25 equivalent for visible fog-role labels

   Direct visible labels such as `front_fogs_with_low_beams`, `fog_when`,
   `left_fog_light_as`, and `right_fog_light_as` resolve to non-VAG/Ford paths
   in the recovered code. The unresolved static target is an alternate VAG key,
   availability sub-object, or `ReadValuesOperation` value path that exposes the
   same role behavior for this BCM.

5. Runtime branch and requested-choice proof

   No write is justified until the selected runtime Setting object, current
   payload length, current bytes, and requested-choice bytes are recovered for
   the exact BCM. Do not promote static choice values like `1E`, `16`, or `17`
   into a live payload without that bridge.

## Active Restore Procedure

Use the active runner documented in `../../obd-on-pc/README.md`:

```powershell
.\obd-on-pc\run_restore_expert_backup_session.ps1
.\obd-on-pc\run_restore_expert_backup_session.ps1 -Write
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetByte21Bit2
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetByte21Bit2 -Write
.\obd-on-pc\run_restore_expert_backup_session.ps1 -ClearByte12Bit0 -ClearByte21Bit7
.\obd-on-pc\run_restore_expert_backup_session.ps1 -ClearByte12Bit0 -ClearByte21Bit7 -Write
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetDrlViaFogs -ClearByte21Bit7 -Write
```

The write path must remain Carista-shaped:

```text
2EF199 + YYMMDD
22F1A5 inline workshop-code read
2EF198 + workshop-code payload
2E0600 + full 30-byte coding
fresh 220600 verification
```

After the restore session, remove the temporary `run_bcm_coding_session.py` and
`run_restore_expert_backup_session.ps1` files unless they are still needed for
an immediate retry.
