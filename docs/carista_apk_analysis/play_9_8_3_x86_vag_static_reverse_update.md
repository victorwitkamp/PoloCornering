# Carista 9.8.3 Play x86 VAG Static Reverse Update

Date: 2026-05-04
Updated: 2026-05-07 with per-side helper correction and external TP2.0/PQ25 research.

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

## Ghidra Export Anchor

The durable Ghidra project/export path is now part of the recovered evidence:

```text
carista_apk_analysis/play_9.8.3/ghidra_x86_project
carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting
```

Regenerate it from the workspace root with:

```powershell
./carista_apk_analysis/setup_ghidra_re.ps1 -RunX86Headless -X86NoAnalysis -CleanProject -HeadlessMaxMem 8G
./carista_apk_analysis/setup_ghidra_re.ps1 -ExportX86VagLightingBranches -HeadlessMaxMem 8G
```

Ghidra imports the ELF with image base `0x10000`, so the exporter seeks Ghidra
addresses as `recovered x86 VA + image base` and prints recovered x86 VAs in the
generated Markdown. The exporter also tracks `EBX` string/GOT references and
stack-local copies, so branch files resolve setting keys, whitelists, ECUs,
access-code objects, and interpretation objects without rerunning the Python
Capstone dumper.

Using that base, the static pass found `1568` `car_setting_*` references inside
`VagCanSettings::getSettings()`, including all high-value lighting targets
below.

## Target Setting References

| Callsite | Setting key |
|---:|---|
| `0x012c71a3` | `car_setting_coming_home_req_rls` |
| `0x012c88d0` | `car_setting_coming_leaving_home_output` |
| `0x012c8a55` | `car_setting_coming_home_via_low_beams` |
| `0x012c929b` | `car_setting_coming_home_via_fogs` |
| `0x012cde7b` | `car_setting_drl_via_fogs` |
| `0x012d4db5` | `car_setting_turn_off_fogs_with_high_beam` |
| `0x012d62e6` | `car_setting_fog_lights_on_reverse` |
| `0x012d9b78` | `car_setting_assist_dr_lights` |
| `0x012da210` | `car_setting_cornering_lights_via_fogs_left` |
| `0x012da55f` | `car_setting_cornering_lights_via_fogs_right` |
| `0x012da8bd` | `car_setting_cornering_lights_activation` |
| `0x012daf54` | `car_setting_cornering_lights_min_activation_speed` |
| `0x012db176` | `car_setting_cornering_lights_max_activation_speed` |

## Constructor Helper Classification

The helper-call targets land in compiler-generated `shared_ptr_emplace` wrappers,
so the dynamic-symbol sizes under-report the true wrapper boundary. Disassembling
the helper prologues still exposes the template class family:

| Helper target | Wrapper class family |
|---:|---|
| `0x0133b390` | `VagUdsCodingSetting`, `VagCanEcu`, `MultipleChoiceInterpretation` |
| `0x01341200` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x0133fdf0` | `VagUdsCodingSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x01340190` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x01358fd0` | `FullByteVagCanShortAdaptationSetting`, `VagCanEcu`, `MultipleChoiceInterpretation` |
| `0x01356f90` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x01368690` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x0136c910` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x0136caf0` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x0133e9f0` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x013591a0` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x013691d0` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `MultipleChoiceInterpretation` |
| `0x0136ccc0` / `0x0136cea0` / `0x0136d080` | `VagUdsAdaptationSetting`, `VagUdsEcu`, `NumericalInterpretation` |

## Constructor Evidence

The focused constructor windows prove these immediate values in the official
Play build. The rows now separate the x86 6R/PQ25 whitelist matches from
non-6R same-key variants where that evidence is recovered.

| Setting key | Recovered static shape |
|---|---|
| `car_setting_coming_home_req_rls` | official x86 6R/PQ25 reused-key branch `0x012c74fe -> 0x0133b390`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, DID `0600` byte `0x0a` / mask `0x04`; the following direct `car_setting_coming_home_menu_default_req_rls` branch is a separate MK7/6C `0x0d04` adaptation path |
| `car_setting_coming_leaving_home_output` | official x86 direct branches call helper `0x0133fdf0` with raw/address `0x110e`, offset `2`, field/mask `1`, but the whitelists are `CENTRAL_ELEC_MK8` or `UDS_CAN_GATEWAY_MEB`, not 6R/PQ25 |
| `car_setting_coming_home_via_low_beams` | official x86 direct branch is B8-scoped `0x012c8a8a -> 0x01358fd0`, immediate pair byte `0x06` / mask `0x10`; no x86 6R/PQ25 direct branch recovered |
| `car_setting_coming_home_via_fogs` | official x86 direct branch is B8-scoped `0x012c92d0 -> 0x01340190`, immediate pair byte `0x06` / mask `0x20`; nearby turn-signal/reverse CH/LH blocks are MK7/MQB scoped |
| `car_setting_drl_via_fogs` | x86 6R/PQ25 branch `0x012cdeb6 -> 0x01361520`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x17` / mask `0x04`; 2026-05-07 write set this bit and behavior did not change; exact helper family remains unresolved because branch-export labels conflict with direct PLT/dynamic-symbol audit |
| `car_setting_turn_off_fogs_with_high_beam` | x86 6R/PQ25 branch `0x012d4dea -> 0x0135e580`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x15` / mask `0x20`; non-6R variants include `0x0e/0x04`, `0x04/0x02`, and rejected adaptation raw `0x0d01` |
| `car_setting_assist_dr_lights` | x86 6R/PQ25 branch `0x012d9bad -> 0x013625a0`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x16` / mask `0x20` |
| `car_setting_cornering_lights_via_fogs` | x86 6R/PQ25 branch `0x012d9f7b -> 0x01358fd0`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x0c` / mask `0x40`; current coding already has this bit set and behavior testing disproved it as the missing fix |
| `car_setting_cornering_lights_via_fogs_experimental` | x86 6R/PQ25 branch `0x012da0f2 -> 0x0135eaf0`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x15` / mask `0x80`; fresh engine-running coding byte `0x15` is `0xA6`, so this bit is already set |
| `car_setting_cornering_lights_with_turn_signals` | x86 explicit turn-signal branch `0x012da761 -> 0x0135e920`, whitelist `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, byte `0x15` / mask `0x04`; fresh engine-running coding byte `0x15` is `0xA6`, so this bit is already set; it is a blinker-trigger enable, not an output-role selector |
| `car_setting_cornering_lights_via_fogs_left` | x86 has two type-7 `VagUdsAdaptationSetting` same-key branches: `0x012da25a -> 0x0136c910` and `0x012da39a -> 0x01356f90`; older ARM type-7 evidence uses `0x055c`, offset `5`, mask `0xff`, choices include `0x00`, `0x16`, `0x1e` |
| `car_setting_cornering_lights_via_fogs_right` | x86 has two type-7 `VagUdsAdaptationSetting` same-key branches: `0x012da5a9 -> 0x01368690` and `0x012da6e9 -> 0x0136caf0`; older ARM type-7 evidence uses `0x055d`, offset `5`, mask `0xff`, choices include `0x00`, `0x17`, `0x1e` |
| `car_setting_fog_lights_on_reverse` | Ghidra x86 D1D branch `0x012d632e -> 0x013591a0`, raw/DID `0x0d1d`, offset `0`, mask `0x02`, guarded by `UDS_CENTRAL_ELEC_MK7`, `CENTRAL_ELEC_MK7_6C`, and `VagUdsEcu::CENTRAL_ELEC`; later same-key D1D variant uses `CENTRAL_ELEC_MK7_NEW_MQBA0` plus `CENTRAL_ELEC_MK8`-derived guard |
| `car_setting_cornering_lights_activation` | Ghidra x86 D1D branch `0x012da906 -> 0x0133e9f0`, raw/DID `0x0d1d`, offset `2`, mask `0x38`, choices include disabled and steering-wheel/blinker methods; D1D guards are `UDS_CENTRAL_ELEC_MK7`, `CENTRAL_ELEC_MK7_6C`, and `CENTRAL_ELEC_MK7_NEW_MQBA0`, while the nearby non-D1D branch is B8 long-coding |
| `car_setting_cornering_lights_min_activation_speed` | Ghidra x86 D1D numerical branch uses raw/DID `0x0d1d`, offset `3`, mask `0xff`, `Unit::KM_H`; observed guards are MK7/MK7_6C/MK7_NEW_MQBA0, not 6R/PQ25 |
| `car_setting_cornering_lights_max_activation_speed` | Ghidra x86 D1D numerical branch uses raw/DID `0x0d1d`, offset `4`, mask `0xff`, `Unit::KM_H`; observed guards are MK7_6C/MK7_NEW_MQBA0/MK8-derived, not 6R/PQ25 |

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

The newly recovered D1D branch family is also not a Polo write seed. The Ghidra
export proves `0x0D1D` is used by real VAG fog/cornering settings, but all
observed guards are MK7/6C/MQBA0/MK8/B8-shaped, not `CENTRAL_ELEC_6R`,
`CENTRAL_ELEC_6R_5C_7E_7H`, or `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`. Do not send
`2E0D1D` from these branches for `6R0937087K`.

## Current Interpretation

The official x86 catalog still carries multiple VAG variants for the same user
settings. The static constructor rows above prove that Carista knows
`VagCanShortAdaptationSetting`, `VagCanLongCodingSetting`,
`VagUdsCodingSetting`, `VagUdsAdaptationSetting`, and
`FullByteVagCanShortAdaptationSetting` lighting paths. For the rows whose
constructor whitelist is `CENTRAL_ELEC_6R_5C_7E_7H` or
`CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, the normal `AvailBy=2` route now identifies
the likely `6R0937087K` branch unless the recovered submodule path applies.

The availability path is now narrower than the previous "mixed branch" wording:
`VagOperationDelegate::getVagSettingAvailabilityForEcu` reads `AvailBy` from
`Setting/VagSetting + 0x5C`. Constructor disassembly proves the normal
no-`AvailBy` `VagCanShortAdaptationSetting`, `VagCanLongCodingSetting`,
`VagUdsCodingSetting`, and `VagUdsAdaptationSetting` branches pass
`AvailBy=2`, which makes availability a `StringWhitelist::itemMatches` check
against the ECU tag from `VagEcuInfo + 0x08`. Ghidra now decompiles the earlier
vtable-slot `+0x3C` predicate as `VagSetting::isSubmodule`: it reads the setting
type at `VagSetting + 0x0C`, tests mask `0x230`, and returns true only for types
`4`, `5`, and `9` under a `<10` guard. The remaining selection target is
therefore the constructor whitelist contents or the downstream submodule
availability helper, not the raw DID/type itself.

The recovered `StringWhitelist::itemMatches` implementation and
`VagWhitelists` initializers now make the 6R/PQ25 selection executable in the
Python reproduction. For ECU tag `6R0937087K`, the recovered matcher returns
true for `CENTRAL_ELEC_6R_EXCEPT_6RU`, `CENTRAL_ELEC_6R`,
`CENTRAL_ELEC_6R_5C_7E_7H`, and `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, and false
for the isolated `6RU`, `5C`, `7E`, and `7H` families. That confirms the x86
branches guarded by `CENTRAL_ELEC_6R_5C_7E_7H` / `_EXP_1S` are genuinely
selected by this BCM tag on the normal `AvailBy=2` path.

The older ARM `055C` / `055D` type-7 branches are now negative for PQ25
availability rather than positive 6R evidence: the first per-side branch uses
`VagUdsEcu::CENTRAL_ELEC` with a `CENTRAL_ELEC_MQB_ALL` /
`CENTRAL_ELEC_MK8`-derived whitelist, while the second per-side branch uses
`VagUdsEcu::CAN_GATEWAY` with `UDS_CAN_GATEWAY_MEB`. No recovered per-side
`055C` / `055D` branch is currently guarded by `CENTRAL_ELEC_6R`,
`CENTRAL_ELEC_6R_5C_7E_7H`, or `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`. The same
older ARM per-side region loads part-number patterns `5Q0937084*` and
`6C093708*`, but no `6R0937087K` / `6R0-937-08x` pattern was recovered for the
`055C` or `055D` role branches.

The Play x86 ELF now proves the same negative whitelist selection directly,
without relying on ARM call windows:

| Branch | x86 evidence |
|---|---|
| Left first helper `0x012da25a -> 0x0136c910` | Local helper calls PLT `0x0197e2f0`, whose relocation resolves to `VagUdsAdaptationSetting`. The whitelist source is GOT `[EBX-0x2AA4]` relocation `VagWhitelists::CENTRAL_ELEC_MQB_ALL`, combined through vtable slot `+0x14` with GOT `[EBX-0x2C9C]` relocation `VagWhitelists::CENTRAL_ELEC_MK8`. |
| Left second helper `0x012da39a -> 0x01356f90` | Local helper calls PLT `0x0197d6f0`, whose relocation resolves to `VagUdsAdaptationSetting`. The branch pushes GOT `[EBX-0x2C94]` relocation `VagWhitelists::UDS_CAN_GATEWAY_MEB` and GOT `[EBX-0x5DF4]` relocation `VagUdsEcu::CAN_GATEWAY`. |
| Right first helper `0x012da5a9 -> 0x01368690` | Local helper calls PLT `0x0197e0a0`, whose relocation resolves to `VagUdsAdaptationSetting`. It uses the same `CENTRAL_ELEC_MQB_ALL` plus `CENTRAL_ELEC_MK8` whitelist derivation as the left first helper. |
| Right second helper `0x012da6e9 -> 0x0136caf0` | Local helper calls PLT `0x0197e300`, whose relocation resolves to `VagUdsAdaptationSetting`. It uses the same `UDS_CAN_GATEWAY_MEB` plus `CAN_GATEWAY` guard as the left second helper. |

This means the preferred x86 evidence also excludes the known per-side role
branches for the actual Polo `6R0937087K` path unless a separate special
predicate later proves otherwise.

A separate live/static mismatch remains around `0601`. A 2026-05-07
current-state read-only TP2.0 pass on the exact Carista channel parameter
request `A00194FF82FF` returned `220601 -> 6206011E` and
`220606 -> 620606001800018000` again. The retained log is
`obd-on-pc/logs/readonly_tp20_20260507_075726_tp20_readonly_context.json`. The
x86 static sweep still finds no decoded `0x0601` / `0x220601` / `0x620601`
setting constructor path. The same x86 binary does carry a readable simulator
sample row for `ECU VAGCAN20` with `220601: 6206011E` and
`220606: 620606001800038000`, so the exact `1E` value is now confirmed in
static sample-response data too. That still makes `0601=1E` a high-priority
role clue, not a recovered write seed.

The 2026-05-07 live write also killed the DRL-via-fogs standalone hypothesis:
byte `0x17` mask `0x04` was changed from clear to set and persisted, but the
front fogs stayed as steady paired outputs in the headlight switch position and
still did not show useful left/right turn-signal ownership.

The most useful negative/clarifying finding for the next car visit is the
explicit turn-signal setting: `car_setting_cornering_lights_with_turn_signals`
maps to byte `0x15` mask `0x04` on the x86 6R/PQ25 branch, and the fresh
engine-running coding byte `0x15` is `0xA6`. That bit is already set, as is the
experimental cornering-fogs bit at byte `0x15` mask `0x80`; both therefore look
like prerequisites/triggers rather than the missing output-role fix.

External PQ25/VCDS references match the x86 interpretation of byte `0x15` mask
`0x04`: Byte 21 Bit 2 enables cornering lights via the turn signal/blinker when
cornering lights are active. It can keep a cornering lamp on while a blinker is
active at low speed, but it does not explain both front fogs staying steadily on
with the headlight switch and no per-side ownership. That symptom still points
toward fog-switch request, CH/LH/fog role, wiring, or unsupported per-side
outputs.

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

For current-value reporting, the `coming_leaving_home_output` row is now kept
unknown even though the external catalog has byte `13` bit `6`: the recovered
native evidence has branch-specific encodings (`110E`, DID `0600` byte
`0x0D`/mask `0x40`, and DID `0600` byte `0x11`/mask `0x08`) and the fog/low-beam
choice value flips between coding branches. That selector is output-role-shaped,
but not a safe PQ25 branch until the runtime branch is recovered.

## External Corroboration

These sources are useful clues only. They are not recovered Carista symbols and
must not be promoted into `CaristaReproduction/` behavior without a matching
Carista callsite.

- `jazdw.net/tp20` documents the public TP2.0 shape that matches the recovered
   Carista transport: channel setup on `0x200`, negotiated CAN IDs, `A0/A1`
   channel parameters, `A3` keepalive, `A8` disconnect, two-byte payload length,
   ACK opcode `B`, and not-ready/NACK opcode `9`.
- `I-CAN-hack/pq-flasher` independently implements VW TP2.0/KWP2000 for PQ-era
   EPS work. Its `tp20.py` opens channels with `module C0 00 10 00 03 01`, waits
   for `D0`, sends `A0 0F 8A FF 0A FF`, ACKs with `B(seq+1)`, and uses `A3` to
   keep a long transfer alive. This corroborates transport mechanics, not BCM
   setting selection.
- `dnoermann/car-tools` contains PQ25/PQ35 diagnostic tooling with UDS, TP2.0,
   KWP2000, diagnostic sessions, security access, service scanning, and generic
   DID reads including `0600`. It is a useful diagnostic reference but does not
   recover this Carista BCM branch.
- `phnahes/vw_ebc460_abs_decoder` and the linked Drive2/VCDS-label material are
   useful ABS/PQ25/PQ26 long-coding references, especially byte-count platform
   detection and reverse-bit checksum patterns. They do not describe BCM/J519
   fog or cornering Carista settings.
- `ConnorHowell/vag-uds-ids` lists newer UDS central-electrics CAN IDs such as
   `0x70E/0x778`; that remains an external clue only because this Polo path is
   proven through TP2.0 headers `338/300`.
- `bri3d/VW_Flash` is useful generic VW UDS context: DIDs such as `0600` coding
   value and `F1A5` coding fingerprint, workshop-code handling, and SA2/security
   workflows. It is flash/UDS infrastructure, not Carista PQ25 setting logic.
- `Korni22/VAG-Coding` provides MQB/Leuchte examples and access code `31347`.
   That is not PQ25 Carista evidence.

## Next Static Steps

1. Build a persistent extractor for `VagCanSettings::getSettings()` that emits
   `key -> callsite -> constructor immediates -> helper-call target` records.
2. Use Ghidra or more precise function-boundary recovery to attach each target
   setting key to the exact helper family listed above, then dump the associated
   constructor `StringWhitelist` contents for the `AvailBy=2` path.
3. Continue tracing the downstream submodule availability helper reached after
   `VagSetting::isSubmodule`, so type `4`/`5`/`9` settings can be separated from
   ordinary ECU-tag whitelist matching.
4. Only consider runtime instrumentation on the official licensed install, and
   avoid early PairIP hooks because prior spawn-time instrumentation crashed in
   `libpairipcore.so`.
