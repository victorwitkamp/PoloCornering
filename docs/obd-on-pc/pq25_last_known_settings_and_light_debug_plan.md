# PQ25 Last Known Settings And Light Debug Plan

Date: 2026-05-04

## Scope

This report is for the current Polo 6R / PQ25 BCM work using only the Carista
Bluetooth adapter on the PC. It does not assume VCDS measuring blocks are
available through the adapter, and it does not add any write, security, or
routine commands.

Controller:

```text
Module: 09 Central Electronics / BCM / J519
Part: 6R0937087K
Component: BCM PQ25 H+4
Software: 0254
TP2.0 unit address: 20
Known TP2.0 open: 20C00010000301
Known channel: send 338, listen 300
Known channel params: A00F8AFF32FF -> A10F8AFF4FFF
```

## Last Known Coding

The last verified coding restored after the live write tests was:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

The older supplied/reference coding was:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Only two bits differ between those strings:

| Byte | Baseline | Reference | Difference | Current interpretation |
|---:|---|---|---|---|
| 12 | `2C` | `6C` | bit 6 clear -> set | Carista cornering/fog family, live-tested, not the visible fix by itself |
| 21 | `A2` | `A6` | bit 2 clear -> set | Carista turn-signal cornering family, live-tested, not the visible fix by itself |

Both bits were successfully changed and verified with the former live long-coding
runner, which has since been removed. The visible cornering/fog behavior did not
change, so these are no longer the main fix candidates.

## Current Carista Settings View

Generated detailed JSON:

```text
docs/obd-on-pc/pq25_last_known_settings_carista_scan.json
docs/obd-on-pc/pq25_read_values_plan.json
```

Current evidence-backed settings from long coding:

| Carista setting family | Location | Current value | Possible values | Status |
|---|---:|---|---|---|
| `car_setting_cornering_lights_via_fogs` / `car_setting_use_cornering_lights` | byte 12 bit 6 | clear | clear, set | mapped, but behavior-ruled-out for the visible symptom |
| `car_setting_cornering_lights_with_turn_signals` | byte 21 bit 2 | clear | clear, set | mapped, but behavior-ruled-out for the visible symptom |
| `car_setting_coming_leaving_home_output` | byte 13 bit 6 | set | clear, set | context only, exact Carista enum unresolved |
| `car_setting_assist_dr_lights` | byte 22 bit 5 | clear | clear, set | ADL candidate only |

Priority unresolved Carista settings:

| Carista key | Current value | Possible labels recovered from Carista text | What is missing |
|---|---|---|---|
| `car_setting_fog_when` | unknown | Cornering lights; Use DRL via fog and cornering lights | native Setting object, current-value read method, write bytes |
| `car_setting_left_fog_light_as` | unknown | Cornering lights; Use DRL via fog and cornering lights | native Setting object, current-value read method, write bytes |
| `car_setting_right_fog_light_as` | unknown | Cornering lights; Use DRL via fog and cornering lights | native Setting object, current-value read method, write bytes |
| `car_setting_cornering_lights_with_turn_signals_one_touch` | unknown | unknown | native Setting object and value enum |

2026-05-06 x86 follow-up narrows this table: the direct visible labels
`car_setting_fog_when`, `car_setting_left_fog_light_as`, and
`car_setting_right_fog_light_as` resolve to `FordSettings::getSettings`, not a
VAG/PQ25 constructor. The direct one-touch turn-signal label resolves to
`BmwESettings::getSettings`. Later verified coding snapshots also already have
the x86-selected fog-cornering and turn-signal-cornering bits set, so the next
car visit should start with a fresh `220600` confirmation and should not retest
those bits as standalone fixes.

Carista's own instruction says the cornering setup depends on three choices:

```text
Use fog lights when...
Use the left fog light as...
Use the right fog light as...
```

The first two long-coding bits we tested appear to be only part of that family.
The left/right fog-role settings remain the highest-value target because they
could explain why changing the global cornering bits did not fix the behavior.

## Other Potential Adjustments

These are investigation targets, not write targets:

| Area | Current coding evidence | Why it matters | Current action |
|---|---|---|---|
| Byte 13 parking/CH/LH group | byte 13 is `68` | Public PQ25/VCDS context says this byte carries coming-home/leaving-home and parking-light behavior | keep as context until Carista maps it to a setting |
| Byte 18 diagnostics group | byte 18 is `41` | Public references often put lamp diagnosis bits near this area | read/debug only |
| Byte 19 lamp diagnostics group | byte 19 is `2F` | May influence bulb-check behavior around front fog/cornering lamps | read/debug only |
| Byte 21 fog/high-beam/turn-light group | byte 21 is `A2` | bits 5 and 7 are already set and look fog-related in external notes | do not flip blindly |
| Byte 22 ADL candidate | byte 22 is `00` | Carista has ADL-like resources, but no current diff | do not flip blindly |

The VCDS label redirect for this BCM points to `6R0-937-08x-09.CLB`. That CLB
is binary/encrypted, and a narrow plain-text search for fog/corner/light and
measuring-value terms did not expose usable channel labels. So the next live
debug path should stay Carista-adapter based.

## Adapter-Only Live Debug Plan

The old guided capture wrapper was removed. Any future live debug procedure must
be a temporary thin `obd-on-pc` wrapper around recovered `CaristaReproduction`
symbols, and that wrapper must be removed after the session.

The current persistent Carista reproduction command is offline evidence output:

```powershell
cd C:\Users\victo\Downloads\PoloCornering
python -m CaristaReproduction --read-values-plan
```

After the drive, analyze the generated capture JSON:

```powershell
cd C:\Users\victo\Downloads\PoloCornering\obd-on-pc
python .\analyze_bcm_light_capture.py .\logs\<run_id>_bcm_light_capture.json --output-prefix <run_id>
```

The analyzer expands diagnostic payload differences into byte/bit deltas and
summarizes diagnostic status/payload variants plus raw CAN headers/payloads that
are state-specific. The analyzer now also annotates known VW PQ raw CAN headers
from the downloaded openDBC `vw_pq.dbc` reference and writes a signal-level
`_raw_signal_deltas.csv` report for decoded raw CAN changes.

For historical raw-CAN captures, inspect `_raw_signal_deltas.csv` first. Proof that the
BCM sees the physical inputs should show up as DBC-decoded signal changes such
as `GK1_Blinker_li`, `GK1_Blinker_re`, `GK1_Abblendlicht`, `GK1_Fernlicht`,
`GK1_Nebel_ein`, `LH3_BLW`, or `LW1_LRW` moving away from `baseline_off`.

That procedure sends the `CaristaReproduction` read-values plan:

```text
core Carista reads: 1A9B, 1A9F, 1A9A, 220600
known-rejected static candidates kept out of the default live request set:
  22110E, 22056D, 220550, 220551, 220D01, 220A58, 220A57, 22055C, 22055D
live companion reads from ReadValuesOperation:
  220601, 220606
Carista UDS identity/status reads: 22F17E, 22F187, 22F189, 22F18C, 22F191, 22F197, 22F1A3, 22F1A5, 22F1AA, 22F1DF
1802FF00, 1902FF
```

Recommended snapshot matrix:

| Run id suffix | Driver state |
|---|---|
| `baseline` | ignition/engine on, exterior lights off, fog switch off |
| `parking_off` | parking lights on, fog switch off |
| `parking_fog_on` | parking lights on, fog switch on |
| `lowbeam_off` | low beams on, fog switch off |
| `lowbeam_fog_on` | low beams on, fog switch on |
| `left_turn` | low beams on, left turn signal on |
| `right_turn` | low beams on, right turn signal on |
| `highbeam` | low beams and high beams on |

If one of the read payloads changes with fog switch, indicator, steering, or
high beam state, compare those payload deltas bit-by-bit before any write. If
nothing changes, the live-data reason path is probably behind Carista's
unrecovered `ReadValuesOperation` setting/value implementation rather than the
currently known read commands.

For the next focused car session, prefer fresh-channel single reads over one
long same-channel sequence. Positive 2026-05-04 evidence came from direct reads
after a fresh TP2.0 open, while same-channel follow-ups often disconnected after
the first multi-frame response.

Minimum next read set:

```text
220600, 220601, 220606, 22F1A5
```

Do not send `22055C`, `22055D`, `22110E`, `22056D`, `220550`, `220551`,
`220D01`, `220A58`, or `220A57` again unless a new recovered branch-selection
artifact explains why the previous `7F2231` result should change. Do not send
any `31` adaptation routine during this read pass; the recovered
`31B8/31BA/31B9` sequence belongs to raw types `0/1`, while the per-side
fog-role objects are currently recovered as raw type `7`.

## Next Reverse-Engineering Target

The remaining static target is still the native runtime link:

```text
ReadValuesOperation.getAvailableItems()
ReadValuesOperation.getSettingValue(setting)
ChangeSettingOperation(Setting, requested byte[], ReadValuesOperation)
```

The goal is to recover the concrete Setting object or current-value path for:

```text
car_setting_fog_when
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

Until that link is found, the safe live plan is to collect Carista-shaped
read-only snapshots and decode deltas, not to guess additional long-coding bits.
