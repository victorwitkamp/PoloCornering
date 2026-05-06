# Front Fogs With Low Beams Recovery - 2026-05-06

Purpose: document the exact Carista native evidence for
`car_setting_front_fogs_with_low_beams` after the Polo live result showed both
front fogs steady on with low beams and off with high beams.

## Result

`car_setting_front_fogs_with_low_beams` was decompiled far enough to identify
the direct native constructor path, but that path is Ford-only, not the VAG/PQ25
BCM path.

There is no recovered VW/PQ25 read or write method for this key yet. Do not send
a guessed UDS write for this setting.

## Direct String Reference

The exact key has one native string reference in the older ARM Carista native
library:

```text
key: car_setting_front_fogs_with_low_beams
string address: 00A5D168
reference: 00E4BCFA
function: FUN_00E314FE
```

Focused instruction window:

```text
carista_apk_analysis/ghidra_instruction_windows/front_fogs_with_low_beams_ref_00E4BCFA.txt
```

The window shows the key stored into the setting table:

```text
00E4BCF2 ldr r0,[0x00E4BD24]
00E4BCF4 str.w r1,[r10,#0xBB4]
00E4BCF8 add r0,pc
00E4BCFA str.w r0,[r10,#0xBBC] ; car_setting_front_fogs_with_low_beams
00E4BD02 str.w r2,[r10,#0xBB8]
```

The same local block passes `car_setting_low_beams` into the constructor path:

```text
00E4BD5C strd r0,r5,[sp,#0xC] ; car_setting_low_beams
00E4BD6A bl 0x00E82930
```

## Helper Chain

The call chain is:

```text
00E82930 -> 00E8FBE4 -> shared_ptr_emplace<FordUdsSetting, ..., RA22_Kc, MultipleChoiceInterpretation>
```

Decompiled target:

```text
carista_apk_analysis/ghidra_address_targets/target_00E8FBE4.c
```

Recovered constructor family:

```text
FordUdsSetting
```

This is not a `VagUdsAdaptationSetting`, `VagUdsCodingSetting`, or
`VagCanLongCodingSetting` path.

## Related High-Beam Fog Keys

Two nearby catalog keys were also decompiled through their direct references:

```text
car_setting_fogs_with_high_beam_restriction -> 00E4DE8A
car_setting_turn_on_fogs_with_high_beam     -> 00E4DE9A
```

Both are in the same Ford setting zone and use:

```text
00E820A8 -> 00E8D43C -> shared_ptr_emplace<FordCodingSetting, ..., RA28_Kc, MultipleChoiceInterpretation>
```

The VAG-side high-beam fog setting remains the separately recovered
`car_setting_turn_off_fogs_with_high_beam` mixed path. That path has read-only
candidates such as `220D01` / `220A58`, but no write seed without a positive
payload and runtime branch proof.

## Reconstructed Behavior Boundary

For the direct `car_setting_front_fogs_with_low_beams` key, the close
reconstruction is:

```text
FUN_00E314FE builds a FordUdsSetting-backed multiple-choice lighting setting.
One visible choice label is car_setting_low_beams.
The direct key path is not used by VagCanSettings::getSettings / FUN_0105F6C0.
```

Therefore the current VW/PQ25 state is:

```text
read method: none recovered for PQ25
write method: none recovered for PQ25
safety: do not write
```

## Next Recovery Step

The VW/PQ25 implementation, if Carista exposes an equivalent setting for this
BCM, must be recovered through a different path:

```text
ReadValuesOperation availability/value objects
VagCanSettings::getSettings alternate keys
dynamic phone trace while toggling the actual Carista setting, if it appears
```

Do not invent a `2E` write for `car_setting_front_fogs_with_low_beams` from the
Ford constructor evidence.