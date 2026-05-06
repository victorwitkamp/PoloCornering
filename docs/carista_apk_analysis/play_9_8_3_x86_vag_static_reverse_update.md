# Carista 9.8.3 Play x86 VAG Static Reverse Update

Date: 2026-05-04

This note records the static reverse-engineering pass over the official Google
Play installed Carista `9.8.3` x86 build. It supersedes older PairIP-bypass
attempts for this branch: the current useful target is the licensed Play build,
with PairIP left intact and the APKs pulled only for local static analysis.

## Source Build

Pulled APK splits:

```text
carista_apk_analysis/play_9.8.3/pulled_apks/00_base.apk
carista_apk_analysis/play_9.8.3/pulled_apks/01_split_config.x86.apk
carista_apk_analysis/play_9.8.3/pulled_apks/02_split_config.xxhdpi.apk
```

Extracted native target:

```text
carista_apk_analysis/play_9.8.3/extracted/lib/x86/libCarista.so
```

Package facts from the emulator pull:

```text
package: com.prizmos.carista
versionName: 9.8.3
versionCode: 983099
primaryCpuAbi: x86
installerPackageName: com.android.vending
```

## Native Catalog Anchor

The official x86 library keeps a rich dynamic symbol table. The VAG settings
catalog entry point is:

```text
_ZN14VagCanSettings11getSettingsEv
address: 0x012a20c0
size:    0x984fd
```

The x86 PIC prologue establishes the string/data base through `call/pop ebx`:

```text
call 0x12a20d1
pop ebx
add ebx, 0x793547
```

Resolved base:

```text
ebx_base = 0x01a35618
```

Using that base, the static pass found `1568` `car_setting_*` references inside
`VagCanSettings::getSettings()`, including all high-value lighting targets
below.

## Target Setting References

| Callsite | Setting key |
|---:|---|
| `0x012c88d0` | `car_setting_coming_leaving_home_output` |
| `0x012c8a55` | `car_setting_coming_home_via_low_beams` |
| `0x012c929b` | `car_setting_coming_home_via_fogs` |
| `0x012cde7b` | `car_setting_drl_via_fogs` |
| `0x012d4db5` | `car_setting_turn_off_fogs_with_high_beam` |
| `0x012d9b78` | `car_setting_assist_dr_lights` |
| `0x012da210` | `car_setting_cornering_lights_via_fogs_left` |
| `0x012da55f` | `car_setting_cornering_lights_via_fogs_right` |

## Constructor Helper Classification

The helper-call targets land in compiler-generated `shared_ptr_emplace` wrappers,
so the dynamic-symbol sizes under-report the true wrapper boundary. Disassembling
the helper prologues still exposes the template class family:

| Helper target | Wrapper class family |
|---:|---|
| `0x0133fdf0` | `VagUdsCodingSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x01340190` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x01358fd0` | `FullByteVagCanShortAdaptationSetting`, `VagCanEcu`, `MultipleChoiceInterpretation` |
| `0x01356f90` | `VagUdsCodingSetting`, `VagCanEcu`, `MultipleChoiceInterpretation` |
| `0x01368690` | `VagCanLongCodingSetting`, `VagCanEcu`, `NumericalInterpretation` |
| `0x0136c910` | `VagCanShortAdaptationSetting`, `VagCanEcu`, `MultipleChoiceInterpretation` |
| `0x0136caf0` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |

## Constructor Evidence

The focused constructor windows prove these immediate values in the official
Play build. The rows now separate the x86 6R/PQ25 whitelist matches from
non-6R same-key variants where that evidence is recovered.

| Setting key | Recovered static shape |
|---|---|
| `car_setting_coming_leaving_home_output` | official x86 direct branches call helper `0x0133fdf0` with raw/address `0x110e`, offset `2`, field/mask `1`, but the whitelists are `CENTRAL_ELEC_MK8` or `UDS_CAN_GATEWAY_MEB`, not 6R/PQ25 |
| `car_setting_coming_home_via_low_beams` | official x86 direct branch is B8-scoped `0x012c8a8a -> 0x01358fd0`, immediate pair byte `0x06` / mask `0x10`; no x86 6R/PQ25 direct branch recovered |
| `car_setting_coming_home_via_fogs` | official x86 direct branch is B8-scoped `0x012c92d0 -> 0x01340190`, immediate pair byte `0x06` / mask `0x20`; nearby turn-signal/reverse CH/LH blocks are MK7/MQB scoped |
| `car_setting_drl_via_fogs` | x86 6R/PQ25 branch `0x012cdeb6 -> 0x01361520`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x17` / mask `0x04`; other variants include `0x11/0x10`, `0x0e/0x02`, `0x02/0x08`, and rejected `055C` adaptation branches |
| `car_setting_turn_off_fogs_with_high_beam` | x86 6R/PQ25 branch `0x012d4dea -> 0x0135e580`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x15` / mask `0x20`; non-6R variants include `0x0e/0x04`, `0x04/0x02`, and rejected adaptation raw `0x0d01` |
| `car_setting_assist_dr_lights` | x86 6R/PQ25 branch `0x012d9bad -> 0x013625a0`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x16` / mask `0x20` |
| `car_setting_cornering_lights_via_fogs` | x86 6R/PQ25 branch `0x012d9f7b -> 0x01358fd0`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x0c` / mask `0x40`; current coding already has this bit set and behavior testing disproved it as the missing fix |
| `car_setting_cornering_lights_via_fogs_experimental` | x86 6R/PQ25 branch `0x012da0f2 -> 0x0135eaf0`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x15` / mask `0x80`; current coding byte `0x15` is `0x86`, so this bit is already set |
| `car_setting_cornering_lights_with_turn_signals` | x86 explicit turn-signal branch `0x012da761 -> 0x0135e920`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, byte `0x15` / mask `0x04`; current coding byte `0x15` is `0x86`, so this bit is already set |
| `car_setting_cornering_lights_via_fogs_left` | mixed same-key helpers: x86 `VagCanShortAdaptationSetting` and `VagUdsCodingSetting`; older ARM type-7 `0x055c`, offset `5`, mask `0xff`, choices include `0x00`, `0x16`, `0x1e` |
| `car_setting_cornering_lights_via_fogs_right` | mixed same-key helpers: x86 `VagCanLongCodingSetting` and `VagUdsAdaptationSetting`; older ARM type-7 `0x055d`, offset `5`, mask `0xff`, choices include `0x00`, `0x17`, `0x1e` |

## Safety Boundary

The official Play `9.8.3` build confirms the `055C` / `055D` per-side
cornering-fog settings are real Carista VAG catalog entries. That is a static
catalog fact, not a live write candidate for this Polo BCM.

Live adapter evidence for `6R0937087K` already returned:

```text
22055C -> 7F2231
22055D -> 7F2231
```

So do not blindly send `2E055C` or `2E055D`. For this car, those addresses are
read-negative until a Carista-equivalent runtime branch proves otherwise.

## Current Interpretation

The official x86 catalog still carries multiple VAG variants for the same user
settings. The static constructor rows above prove that Carista knows
`VagCanShortAdaptationSetting`, `VagCanLongCodingSetting`,
`VagUdsCodingSetting`, `VagUdsAdaptationSetting`, and
`FullByteVagCanShortAdaptationSetting` lighting paths. For the rows whose
constructor whitelist is `CENTRAL_ELEC_6R_5C_7E_7H` or
`CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, the normal `AvailBy=2` route now identifies
the likely `6R0937087K` branch unless the unresolved special predicate path
overrides it.

The availability path is now narrower than the previous "mixed branch" wording:
`VagOperationDelegate::getVagSettingAvailabilityForEcu` reads `AvailBy` from
`Setting/VagSetting + 0x5C`. Constructor disassembly proves the normal
no-`AvailBy` `VagCanShortAdaptationSetting`, `VagCanLongCodingSetting`,
`VagUdsCodingSetting`, and `VagUdsAdaptationSetting` branches pass
`AvailBy=2`, which makes availability a `StringWhitelist::itemMatches` check
against the ECU tag from `VagEcuInfo + 0x08`. The remaining selection target is
therefore the constructor whitelist contents or the still-unresolved special
vtable-slot `+0x3C` predicate path, not the raw DID/type itself.

The older ARM `055C` / `055D` type-7 branches are now negative for PQ25
availability rather than positive 6R evidence: the first per-side branch uses
`VagUdsEcu::CENTRAL_ELEC` with a `CENTRAL_ELEC_MQB_ALL` /
`CENTRAL_ELEC_MK8`-derived whitelist, while the second per-side branch uses
`VagUdsEcu::CAN_GATEWAY` with `UDS_CAN_GATEWAY_MEB`. No recovered per-side
`055C` / `055D` branch is currently guarded by `CENTRAL_ELEC_6R`,
`CENTRAL_ELEC_6R_5C_7E_7H`, or `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`.

The Play x86 ELF now proves the same negative whitelist selection directly,
without relying on ARM call windows:

| Branch | x86 evidence |
|---|---|
| Left first helper `0x012da25a -> 0x0136c910` | Local helper calls PLT `0x0197e2f0`, whose relocation is `VagCanShortAdaptationSetting`. The whitelist source is GOT `[EBX-0x2AA4]` relocation `VagWhitelists::CENTRAL_ELEC_MQB_ALL`, combined through vtable slot `+0x14` with GOT `[EBX-0x2C9C]` relocation `VagWhitelists::CENTRAL_ELEC_MK8`. |
| Left second helper `0x012da39a -> 0x01356f90` | Local helper calls PLT `0x0197d6f0`, whose relocation is `VagUdsCodingSetting`. The branch pushes GOT `[EBX-0x2C94]` relocation `VagWhitelists::UDS_CAN_GATEWAY_MEB` and GOT `[EBX-0x5DF4]` relocation `VagUdsEcu::CAN_GATEWAY`. |
| Right first helper `0x012da5a9 -> 0x01368690` | Local helper calls PLT `0x0197e0a0`, whose relocation is `VagCanLongCodingSetting`. It uses the same `CENTRAL_ELEC_MQB_ALL` plus `CENTRAL_ELEC_MK8` whitelist derivation as the left first helper. |
| Right second helper `0x012da6e9 -> 0x0136caf0` | Local helper calls PLT `0x0197e300`, whose relocation is `VagUdsAdaptationSetting`. It uses the same `UDS_CAN_GATEWAY_MEB` plus `CAN_GATEWAY` guard as the left second helper. |

This means the preferred x86 evidence also excludes the known per-side role
branches for the actual Polo `6R0937087K` path unless a separate special
predicate later proves otherwise.

The most useful negative finding for the next car visit is the explicit
turn-signal setting: `car_setting_cornering_lights_with_turn_signals` maps to
byte `0x15` mask `0x04` on the x86 6R/PQ25 branch, and the current live coding
byte `0x15` is `0x86`. That bit is already set, as is the experimental
cornering-fogs bit at byte `0x15` mask `0x80`; both therefore look like ruled-out
standalone fixes for the observed missing turn-signal cornering behavior.

The direct visible fog-role labels are now negative for VW/PQ25 on x86:

```text
car_setting_fog_when
car_setting_left_fog_light_as
car_setting_right_fog_light_as
car_setting_use_cornering_lights
car_setting_cornerig_lights_with_turn_signal
car_setting_cornering_lights_with_turn_signals_one_touch
```

`fog_when`, `left_fog_light_as`, `right_fog_light_as`,
`use_cornering_lights`, and typo-preserved
`cornerig_lights_with_turn_signal` all reference inside
`_ZN12FordSettings11getSettingsEv`, with Ford constructor symbols. The
one-touch turn-signal label references inside `_ZN12BmwESettings11getSettingsEv`
with `BmwESetting` constructor symbols. No official x86 reference to those exact
keys was found inside `_ZN14VagCanSettings11getSettingsEv`.

So the remaining target is no longer those direct resource keys as VAG settings;
it is any alternate VW/PQ25 VAG key, availability sub-object, or
`ReadValuesOperation` value path that Carista uses to expose equivalent fog-role
behavior.

## Next Static Steps

1. Build a persistent extractor for `VagCanSettings::getSettings()` that emits
   `key -> callsite -> constructor immediates -> helper-call target` records.
2. Use Ghidra or more precise function-boundary recovery to attach each target
   setting key to the exact helper family listed above, then dump the associated
   constructor `StringWhitelist` contents for the `AvailBy=2` path.
3. Continue tracing the special `getVagSettingAvailabilityForEcu` vtable-slot
   `+0x3C` predicate path so non-whitelist branches can be distinguished from
   ordinary ECU-tag matching.
4. Only consider runtime instrumentation on the official licensed install, and
   avoid early PairIP hooks because prior spawn-time instrumentation crashed in
   `libpairipcore.so`.
