# Needle Sweep And Fog RE Update

Date: 2026-04-29

## Needle Sweep

Public VCDS-style references for Polo 6R describe needle sweep as an Instruments/Cluster adaptation, not a BCM long-coding bit:

- Control unit `17 - Instruments`
- Adaptation
- `Staging` / sometimes `indicator_celebration`
- set active

Reference: https://www.vag-coding.net/vw/polo-5-6r/polo-5-6r-needle-check/

That means the Carista adapter is a plausible transport because we can already talk UDS to the cluster on `714 -> 77E`, but the target is the cluster, not PQ25 BCM unit 09.

## Local Cluster Evidence

The latest read-only scan found the cluster on UDS 11-bit CAN:

```text
request header: 714
response header: 77E
22F189 -> 62F18930353035  software 0505
22F197 -> 62F1974B4F4D   component prefix KOM
22F1A5 -> 62F1A50007FD
```

`220600` and the nearby `22060x` coding reads did not return a useful long-coding-style response for this cluster in that scan. That supports treating needle sweep as adaptation, not long coding.

## Carista Native Evidence

Carista contains two generic cluster settings:

```text
car_setting_instr_needle_sweep
car_setting_instr_needle_sweep_method_b
```

Ghidra string-reference export:

```text
car_setting_instr_needle_sweep          -> FUN_0105f6c0 refs at 0106830a, 0106839c, 01068406, 01068466
car_setting_instr_needle_sweep_method_b -> FUN_0105f6c0 ref  at 010684b6
```

Disassembly around those references shows `movw r0, #0x22a2` before the Carista setting constructors.

The exported constructors show the native shape:

```text
FullByteVagUdsAdaptationSetting -> VagUdsAdaptationSetting
VagUdsAdaptationSetting         -> VagSetting type 7
Full-byte mask                  -> FF
raw address                     -> 22A2
```

The Python reproduction now models this in `CaristaReproduction/VagUdsAdaptationSetting.py`.

Run:

```powershell
python -m CaristaReproduction --needle-sweep-settings
```

Output:

```text
car_setting_instr_needle_sweep          ecu=INSTRUMENT_CLUSTER raw address=22A2 mask=FF type=7
car_setting_instr_needle_sweep_method_b ecu=INSTRUMENT_CLUSTER raw address=22A2 mask=FF type=7
```

## Safe Next Car Test

The next test is read-only:

```powershell
.\obd-on-pc\run_next_cluster_needle_probe.ps1 -Port COM10 -Baud 38400
```

That probes cluster header `714` and sends only:

```text
2222A2
22F187
22F189
22F197
22F1A5
```

The important result is whether `2222A2` returns a positive `6222A2...` response, a negative UDS response, or no response.

Do not write needle sweep yet. We do not yet know whether Carista writes this as `2E22A2 <byte>`, through another adaptation helper, or through a method-B fallback. The local `22A2` evidence is strong enough for a read, not for a write.

## Current Fog/Corners RE State

The two long-coding bits we changed successfully are not the visible fix:

```text
byte 12 bit 6 = cornering via fogs candidate
byte 21 bit 2 = turn-signal-triggered cornering candidate
```

Both are still useful mapping evidence, but they are ruled out as the complete symptom fix.

The current highest-value user-facing Carista settings remain:

```text
car_setting_fog_when
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

The first direct native string references for those keys landed in Ford UDS setting constructors:

```text
car_setting_fog_when          -> FUN_00e314fe -> FordUdsSetting helper
car_setting_left_fog_light_as -> FUN_00e314fe -> FordUdsSetting helper
car_setting_right_fog_light_as -> FUN_00e314fe -> FordUdsSetting helper
```

That means those resource keys are reused cross-brand. The VW/PQ25 path must be recovered by following VAG setting constructors, supported-setting predicates, and choice labels, not by assuming the first key string reference is the VW implementation.

The widened string-reference export found the useful VAG path under related keys:

```text
car_setting_cornering_lights_via_fogs_left  -> FUN_0105f6c0 -> VagUdsAdaptationSetting
car_setting_cornering_lights_via_fogs_right -> FUN_0105f6c0 -> VagUdsAdaptationSetting
```

Disassembly around those constructors shows:

```text
left fog cornering  raw address 055C, value offset 5, mask FF
right fog cornering raw address 055D, value offset 5, mask FF
```

The focused instruction-window export also recovered the choice enum attached to
the left and right constructors. They are not identical:

```text
left  055C: 00 = car_setting_off, 16 = car_setting_on, 1E = car_setting_enabled_coming_home_or_leaving_home
right 055D: 00 = car_setting_off, 17 = car_setting_on, 1E = car_setting_enabled_coming_home_or_leaving_home
```

Those values are inserted into byte offset `5` under mask `FF`. Native dispatch
for these raw type `7` settings goes through `readVagUdsValue` and
`ReadRawDataByIdentifierCommand`, so the direct Carista-shaped read requests are
`22055C` and `22055D`. Both returned `7F2231` live on this BCM/session, so the
raw payload length is not known and there is no safe seed for a `2E055C` /
`2E055D` write.

The separate native VAG CAN adaptation routine path is now recovered as
`31B8 + id`, `31BA + id`, `31B9 + id + channel`, `31BA + id`, then
`32B8 + id`, with short adaptation basic id `0103` and long basic id `010A`.
That path is real Carista code for raw types `0/1`; it is not proof that the
`055C` / `055D` type `7` settings should be forced down that routine path.

The Python reproduction now models these candidates:

```powershell
python -m CaristaReproduction --fog-setting-candidates
```

Output:

```text
car_setting_cornering_lights_via_fogs_left  ecu=BCM raw address=055C offset=5 mask=FF type=7
car_setting_cornering_lights_via_fogs_right ecu=BCM raw address=055D offset=5 mask=FF type=7
	left choices:  00 off, 16 on, 1E enabled_coming_home_or_leaving_home
	right choices: 00 off, 17 on, 1E enabled_coming_home_or_leaving_home
```

This is not a live write plan. The native raw type `7` read path for these settings is the already-tested `22055C` / `22055D`, and both were rejected by the BCM. Do not attempt any `2E055C` / `2E055D` write unless a new positive raw-payload read is found for these specific settings.
ECU
native setting type
raw address / DID / adaptation id
current raw value length
positive read method for 055C/055D on this BCM, if one exists outside the rejected type 7 RDBI path
VagUdsCodingSetting
VagUdsAdaptationSetting
FullByteVagUdsAdaptationSetting
VagCanShortAdaptationSetting
FullByteVagCanShortAdaptationSetting
ReadValuesOperation.getAvailableItems
ReadValuesOperation.getSettingValue
```

The goal is to find the VW/PQ25 instances for `left_fog_light_as`, `right_fog_light_as`, and `fog_when`, then recover:

```text
ECU
native setting type
raw address / DID / adaptation id
value mask or byte vector
possible value labels
write helper path
availability predicate for 6R0937087K / BCM PQ25 H+4 SW 0254
```
