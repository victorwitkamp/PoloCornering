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
| `0x01368690` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `NumericalInterpretation` |
| `0x0136c910` | `VagCanLongCodingSetting`, `VagCanEcu`, `MultipleChoiceInterpretation` |

## Constructor Evidence

The focused constructor windows prove these immediate values in the official
Play build. The helper class families above are now classified, but the rows
below still avoid claiming a final runtime branch selection for this exact BCM.

| Setting key | Recovered static shape |
|---|---|
| `car_setting_coming_leaving_home_output` | `VagUdsCodingSetting`; raw/address `0x110e`, offset `2`, field/mask `1`, two-choice list, constructor helper `0x0133fdf0` |
| `car_setting_coming_home_via_fogs` | key constructor has coding-style pair `0x20` / `0x06`; nearby adaptation-style blocks include raw `0x056d`, offset `5`, mask `0xff`, value `0x1e`, plus `0x0550` / `0x0551` offset `0x0d`, mask `0xff` |
| `car_setting_drl_via_fogs` | variants include coding-style pairs `0x17` / `0x04`, `0x11` / `0x10`, and `0x0e` / `0x02` |
| `car_setting_turn_off_fogs_with_high_beam` | variants include coding-style pairs `0x20` / `0x15`, `0x20` / `0x11`, `0x04` / `0x0e`, plus adaptation raw `0x0d01` with fields `1` / `1` |
| `car_setting_assist_dr_lights` | coding-style pair `0x20` / `0x16` |
| `car_setting_cornering_lights_via_fogs_left` | raw/DID `0x055c`, offset `5`, mask `0xff`, choices include `0x00`, `0x16`, `0x1e` |
| `car_setting_cornering_lights_via_fogs_right` | raw/DID `0x055d`, offset `5`, mask `0xff`, choices include `0x00`, `0x17`, `0x1e` |

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
`VagCanLongCodingSetting`, `VagUdsCodingSetting`, `VagUdsAdaptationSetting`, and
`FullByteVagCanShortAdaptationSetting` lighting paths, but they do not yet prove
which branch Carista marks available for the exact BCM `6R0937087K`.

The unresolved settings remain:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

Prior scans placed those names outside the main VAG constructor region that
produced the rows above, so they are still the highest-value target for another
static pass or cautious licensed-runtime observation.

## Next Static Steps

1. Build a persistent extractor for `VagCanSettings::getSettings()` that emits
   `key -> callsite -> constructor immediates -> helper-call target` records.
2. Use Ghidra or more precise function-boundary recovery to attach each target
   setting key to the exact helper family listed above, then identify every
   alternate constructor for the same visible setting.
3. Trace availability checks from `ReadValuesOperation` / `CheckSettingsOperation`
   so the exact `6R0937087K` runtime branch can be selected without unsafe writes.
4. Only consider runtime instrumentation on the official licensed install, and
   avoid early PairIP hooks because prior spawn-time instrumentation crashed in
   `libpairipcore.so`.
