# PQ25 BCM Current Settings and Carista Mapping Report

Date: 2026-04-27

## Controller

```text
Vehicle focus: VW Polo 6R / PQ25
Module:        09 Central Electronics / BCM / J519
Part:          6R0937087K
Component:     BCM PQ25 H+4
Software:      0254
```

The useful live path is still TP2.0 unit `20` through the Carista adapter.
The latest stable coding read used direct TP2.0 `220600`, not the failing
post-`1089` KWP `1A9A` path.

## Current Coding

Latest live direct-read coding:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Known-good coding from when cornering lights worked:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Only two bytes differ:

```text
byte 12: 2C -> 6C
byte 21: A2 -> A6
```

Only two bits differ:

```text
byte 12 bit 6: clear -> set
byte 21 bit 2: clear -> set
```

## Current Setting View

| Setting / group | Source | Location | Current | Known-good | Confidence | Meaning |
|---|---|---:|---|---|---|---|
| Fog-light cornering base function | coding delta + Carista labels | byte 12 bit 6 | off | on | high | Main cornering-light enable using front fog lights |
| Turn-signal cornering trigger | coding delta + Carista labels | byte 21 bit 2 | off | on | high | Enables cornering light when turn signal is active at low speed |
| Coming/Leaving Home fog-vs-low-beam selector | older PQ25 docs | byte 13 bit 6 | on | on | medium | Public docs say CH/LH fog selection, but this conflicts with observed Carista UI |
| Parking-light behavior group | older PQ25 docs | byte 13 bits 0/1/3 | `0/0/1` | `0/0/1` | medium | Parking-light related group, not fully mapped one-to-one to Carista |
| Fog-related capability/install bit | older PQ25 references | byte 21 bit 7 | on | on | medium | Fog-related, exact label still uncertain |
| Probable ADL bit | older PQ25 references | byte 22 bit 5 | off | off | medium | Probably ADL-related, not central to cornering fix |

Practical interpretation:

```text
Current car state:
  base fog-light cornering = disabled
  turn-signal cornering    = disabled

Target known-good state:
  base fog-light cornering = enabled
  turn-signal cornering    = enabled
```

## Carista Label Mapping

The relevant Carista resource keys exist in the decoded Android resources and
inside `libCarista.so`.

A broader regenerated app-visible settings map is available here:

```text
../carista_apk_analysis/carista_supported_settings_map.md
../carista_apk_analysis/carista_supported_settings_map.csv
../carista_apk_analysis/carista_supported_settings_map.json
```

That generated map is intentionally conservative: it marks the two cornering
chunks as pending write targets, while CH/LH and ADL rows remain context only.

| Carista key | App label | Current mapped bit | Current state | Known-good state | Confidence |
|---|---|---:|---|---|---|
| `car_setting_cornering_lights_via_fogs` | Cornering lights (using fog lights) | byte 12 bit 6 | clear | set | high practical / medium static |
| `car_setting_cornering_lights_via_fogs_experimental` | Cornering lights (using fog lights) (experimental) | byte 12 bit 6 | clear | set | medium |
| `car_setting_use_cornering_lights` | Use cornering lights... | byte 12 bit 6 | clear | set | medium |
| `car_setting_cornerig_lights_with_turn_signal` | Activate cornering lights with turn signal | byte 21 bit 2 | clear | set | high practical / medium static |
| `car_setting_cornering_lights_with_turn_signals` | Turn on cornering lights when turn signal is on | byte 21 bit 2 | clear | set | high practical / medium static |
| `car_setting_cornering_lights_via_fogs_left` | Left cornering light (using fog light) | not mapped | unknown | unknown | no distinct delta on this BCM |
| `car_setting_cornering_lights_via_fogs_right` | Right cornering light (using fog light) | not mapped | unknown | unknown | no distinct delta on this BCM |

Static boundary:

```text
The native strings are present, but no direct code xrefs were found from these
resource keys into VagCanSettings::getSettings().
```

That means the app-label-to-bit mapping is strong in practice because it matches
the observed working/non-working coding delta, but it is not yet the exact
native Carista setting object.

## VCDS Reference

VCDS confirms the correct label family:

```text
Labels\6R-09.lbl
REDIRECT,6R0-937-08x-09.CLB,6R0-937-087-???   ; High+
```

That matches `6R0937087K`. The actual long-coding labels are inside
`6R0-937-08x-09.CLB`, which is a binary/encrypted VCDS CLB file. It confirms the
controller family, but it does not expose a full plaintext bit map.

## Byte Table

| Byte | Current | Binary | Notes |
|---:|---|---|---|
| 00 | `3A` | `00111010` | unknown |
| 01 | `B8` | `10111000` | unknown |
| 02 | `2B` | `00101011` | unknown |
| 03 | `9F` | `10011111` | unknown |
| 04 | `08` | `00001000` | unknown |
| 05 | `A1` | `10100001` | unknown |
| 06 | `00` | `00000000` | unknown |
| 07 | `00` | `00000000` | unknown |
| 08 | `00` | `00000000` | unknown |
| 09 | `30` | `00110000` | unknown |
| 10 | `08` | `00001000` | unknown |
| 11 | `00` | `00000000` | unknown |
| 12 | `2C` | `00101100` | bit 6 is clear; should be set for base fog-light cornering |
| 13 | `68` | `01101000` | parking-light group and CH/LH selector bits match known-good |
| 14 | `0E` | `00001110` | unknown |
| 15 | `D0` | `11010000` | unknown |
| 16 | `00` | `00000000` | unknown |
| 17 | `C8` | `11001000` | unknown |
| 18 | `41` | `01000001` | unknown |
| 19 | `2F` | `00101111` | unknown |
| 20 | `60` | `01100000` | unknown |
| 21 | `A2` | `10100010` | bit 2 is clear; should be set for turn-signal cornering trigger; bit 7 already set |
| 22 | `00` | `00000000` | probable ADL bit 5 is off and matches known-good |
| 23 | `00` | `00000000` | unknown |
| 24 | `20` | `00100000` | unknown |
| 25 | `00` | `00000000` | unknown |
| 26 | `00` | `00000000` | unknown |
| 27 | `00` | `00000000` | unknown |
| 28 | `00` | `00000000` | unknown |
| 29 | `00` | `00000000` | unknown |

## Write-Tuple Implications

Carista's native `WriteVagCodingCommand` does not write:

```text
3B9A + full 30-byte long coding
```

Static reverse engineering shows this shape instead:

```text
3B9A
+ 6-byte coding value vector
+ 4-byte coding raw-address vector
+ coding-type-dependent tail
```

The constructor enforces:

```text
value vector length       = 6
raw-address vector length = 4
coding type 2 tail length = 3
```

If the 30-byte coding is split into five 6-byte Carista coding chunks, the two
changed chunks are:

| Chunk | Bytes | Current value | Target value | Changed setting |
|---:|---:|---|---|---|
| 2 | 12-17 | `2C680ED000C8` | `6C680ED000C8` | byte 12 bit 6, base fog-light cornering |
| 3 | 18-23 | `412F60A20000` | `412F60A60000` | byte 21 bit 2, turn-signal cornering |

That gives likely value-vector targets:

```text
base fog-light cornering value vector: 6C680ED000C8
turn-signal cornering value vector:   412F60A60000
```

This is not yet a complete write tuple. Still missing:

```text
4-byte raw-address vector for chunk 2
4-byte raw-address vector for chunk 3
coding type for each write
tail bytes for each write
session/state requirements before the write
```

Latest Carista writer-flow finding:

```text
Carista does not pass a 30-byte BCM coding blob into the final writer.
It passes a 64-bit raw-value key plus compact value bytes.
The writer resolves ECU metadata, normalizes the coding type, and then builds
the final 3B9A command with a 6-byte value, 4-byte raw address, and tail bytes.
```

That makes the current blocker narrower:

```text
resource/SettingRef/native Setting entry
-> 64-bit raw-value key
-> 4-byte raw-address vector and tail bytes
-> final 3B9A tuple
```

An offline composer was added for the final assembly step after those missing
bytes are recovered:

```text
compose_carista_3b9a_tuple.py
```

Example with placeholders only:

```powershell
python compose_carista_3b9a_tuple.py --value6 6C680ED000C8 --raw-address4 00000000 --coding-type 3
```

Do not use placeholder raw-address bytes as a real write.

## What Is Known About Carista's Value Insertion

`VagSetting::insertValue` delegates to `ByteUtils::insertValue`.

Recovered model:

```text
result = copy(current_raw_value)
result[offset + i] = (current[offset + i] & ~mask[i]) | masked_requested_value[i]
```

Recovered object fields:

```text
VagSetting + 0x18 = byte offset inside the raw value
VagSetting + 0x1C = mask/vector object
```

For a one-bit long-coding setting, the mask is expected to be:

```text
byte 12 bit 6 -> 0x40
byte 21 bit 2 -> 0x04
```

## Current Decision

Do not treat a full `3B9A` command as solved yet.

The next complete tuple must be proven as:

```text
3B9A + value6 + rawAddress4 + tail
```

where `value6` is likely one of:

```text
6C680ED000C8
412F60A60000
```

but `rawAddress4` and `tail` are still unknown.

## Next Work Items

1. Recover the native `VagCanLongCodingSetting` catalog entries for byte 12 bit
   6 and byte 21 bit 2.
2. Recover their raw-address/coding-address keys.
3. Recover the coding-type/tail bytes passed into `WriteVagCodingCommand`.
4. If static recovery stalls, capture a real Carista UI toggle when a phone is
   available again.
5. In the car, keep the first step read-only:

```powershell
.\run_next_car_probe.ps1 -Port COM10
```

That confirms whether the two bits are still clear before any write decision.
