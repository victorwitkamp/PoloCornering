# Carista Native Lighting Setting Probe

String matches are found by exact UTF-8 text plus NUL terminator, then direct Ghidra references are exported.
Decompilation is skipped by default; pass --decompile after the output directory to export at most 2 functions per key with 10s timeout each.

## `car_setting_fog_when`

- String matches: `1`
  - address: `00b68d33`
    - ref `00e4e794` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
    - ref `00e4e946` from `FUN_00e314fe` context `strd r0,r9,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_left_fog_light_as`

- String matches: `1`
  - address: `0080d376`
    - ref `00e4ebb0` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
    - ref `00e4ed64` from `FUN_00e314fe` context `strd r0,r8,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_right_fog_light_as`

- String matches: `1`
  - address: `00c38f62`
    - ref `00e4efa4` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
    - ref `00e4f146` from `FUN_00e314fe` context `strd r0,r8,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_cornering_lights`

- String matches: `1`
  - address: `008f8cba`
    - ref `0102003a` from `getSettings` context `strd r1,r0,[sp,#0x0]`
    - ref `010825e2` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `0108263c` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `00e4e532` from `FUN_00e314fe` context `strd r0,r3,[sp,#0x8]`
    - ref `00e4e540` from `FUN_00e314fe` context `str r3,[sp,#0x244]`
    - ref `00e4eb42` from `FUN_00e314fe` context `str.w r0,[r10,#0x3cc]`
    - ref `00e4ed16` from `FUN_00e314fe` context `str.w r2,[r10,#0x33c]`
    - ref `00e4ef1e` from `FUN_00e314fe` context `str.w r0,[r10,#0x28c]`
    - ref `00e4f100` from `FUN_00e314fe` context `str.w r2,[r10,#0x1fc]`
    - ref `00d93dbc` from `getSettings` context `strd r0,r6,[sp,#0x8]`
    - direct refs: `10`
- Referencing functions: `4`
  - `getSettings @ 01018578`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `FUN_00e314fe @ 00e314fe`
  - `getSettings @ 00d8cc4c`
  - decompilation skipped in default refs-only mode

## `car_setting_cornering_lights_activation`

- String matches: `1`
  - address: `00bcc3ce`
    - ref `01082d7c` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082e66` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082eb6` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
    - direct refs: `3`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_cornering_lights_via`

- String matches: `1`
  - address: `00a2b890`
    - direct refs: `0`
- Referencing functions: `0`

## `car_setting_cornering_lights_via_fogs`

- String matches: `1`
  - address: `00b4f397`
    - ref `01082764` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `010827b0` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `01082808` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `0108285e` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `00e4e01c` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
    - ref `00e4e0a0` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
    - ref `00e4e1d4` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
    - ref `00e4e3d8` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
    - direct refs: `8`
- Referencing functions: `2`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_cornering_lights_via_fogs_experimental`

- String matches: `1`
  - address: `008f06f6`
    - ref `010828ba` from `FUN_0105f6c0` context `strd r1,r0,[sp,#0x0]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_cornering_lights_via_fogs_left`

- String matches: `1`
  - address: `00aea817`
    - ref `01082988` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082a4a` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_cornering_lights_via_fogs_right`

- String matches: `1`
  - address: `00aea842`
    - ref `01082b78` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082c34` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_cornering_lights_with_turn_signals`

- String matches: `1`
  - address: `00a2b8b1`
    - direct refs: `0`
- Referencing functions: `0`

## `car_setting_cornering_lights_with_turn_signals_one_touch`

- String matches: `1`
  - address: `0082f251`
    - ref `00d94b6a` from `getSettings` context `str r5,[sp,#0x8]`
    - ref `00d94bb2` from `getSettings` context `str r5,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `getSettings @ 00d8cc4c`
  - decompilation skipped in default refs-only mode

## `car_setting_cornerig_lights_with_turn_signal`

- String matches: `1`
  - address: `006a84ae`
    - ref `00e4ed0c` from `FUN_00e314fe` context `str r3,[sp,#0x20c]`
    - ref `00e4ed0e` from `FUN_00e314fe` context `str.w r3,[r10,#0x34c]`
    - ref `00e4ed04` from `FUN_00e314fe` context `add r3,pc`
    - ref `00e4f0e2` from `FUN_00e314fe` context `str.w r2,[r10,#0x20c]`
    - direct refs: `4`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_use_cornering_lights`

- String matches: `1`
  - address: `0080d355`
    - ref `00e4e724` from `FUN_00e314fe` context `str r0,[sp,#0x20c]`
    - ref `00e4e726` from `FUN_00e314fe` context `str.w r0,[r10,#0x4e4]`
    - ref `00e4e902` from `FUN_00e314fe` context `str.w r0,[r10,#0x47c]`
    - direct refs: `3`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_drl`

- String matches: `1`
  - address: `00c32f79`
    - ref `0102101c` from `getSettings` context `strd r0,r4,[sp,#0x0]`
    - ref `0102106a` from `getSettings` context `strd r0,r4,[sp,#0x0]`
    - ref `010210b6` from `getSettings` context `strd r0,r4,[sp,#0x0]`
    - ref `01021100` from `getSettings` context `strd r0,r4,[sp,#0x0]`
    - ref `0107966c` from `FUN_0105f6c0` context `str r1,[sp,#0x1b0]`
    - ref `0107966e` from `FUN_0105f6c0` context `strd r0,r1,[sp,#0x0]`
    - ref `01079734` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x4]`
    - ref `0107977e` from `FUN_0105f6c0` context `str r0,[sp,#0x4]`
    - ref `010798ec` from `FUN_0105f6c0` context `str r0,[sp,#0x8]`
    - ref `01079946` from `FUN_0105f6c0` context `str r0,[sp,#0x8]`
    - ref `0107999e` from `FUN_0105f6c0` context `str r0,[sp,#0x4]`
    - ref `01079a30` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x4]`
    - ref `0107dd9a` from `FUN_0105f6c0` context `str.w r0,[r4,#0x6d8]`
    - ref `0107de7e` from `FUN_0105f6c0` context `str.w r0,[r4,#0x6a8]`
    - ref `0107fe7c` from `FUN_0105f6c0` context `str.w r0,[r4,#0x2c8]`
    - ref `00f1618c` from `getSettings` context `strd r0,r5,[sp,#0x8]`
    - ref `00f161e6` from `getSettings` context `strd r0,r5,[sp,#0x8]`
    - ref `00f16232` from `getSettings` context `strd r5,r0,[sp,#0x0]`
    - ref `00e4786a` from `FUN_00e314fe` context `strd r0,r3,[sp,#0x8]`
    - ref `00e47878` from `FUN_00e314fe` context `str r3,[sp,#0x280]`
    - ref `00e47914` from `FUN_00e314fe` context `str r0,[sp,#0xc]`
    - ref `00e47adc` from `FUN_00e314fe` context `strd r0,r5,[sp,#0xc]`
    - ref `00e47c6a` from `FUN_00e314fe` context `strd r0,r5,[sp,#0xc]`
    - ref `00e47d28` from `FUN_00e314fe` context `strd r0,r5,[sp,#0xc]`
    - ref `00e47f9a` from `FUN_00e314fe` context `strd r0,r5,[sp,#0xc]`
    - ref `00e4811e` from `FUN_00e314fe` context `str r0,[sp,#0xc]`
    - ref `00e4eb5c` from `FUN_00e314fe` context `str.w r0,[r10,#0x3bc]`
    - ref `00e4ed1a` from `FUN_00e314fe` context `str.w r0,[r10,#0x32c]`
    - ref `00e4ef5a` from `FUN_00e314fe` context `str.w r0,[r10,#0x27c]`
    - ref `00e4f104` from `FUN_00e314fe` context `str.w r0,[r10,#0x1ec]`
    - ref `00d98c6c` from `getSettings` context `str r5,[sp,#0x8]`
    - ref `00d98cc0` from `getSettings` context `str r5,[sp,#0x8]`
    - direct refs: `32`
- Referencing functions: `5`
  - `getSettings @ 01018578`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00f121ec`
  - `FUN_00e314fe @ 00e314fe`
  - `getSettings @ 00d8cc4c`
  - decompilation skipped in default refs-only mode

## `car_setting_drl_via`

- String matches: `1`
  - address: `00b7c8a7`
    - ref `01079888` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x8]`
    - ref `00f162d2` from `getSettings` context `str r3,[sp,#0x5c]`
    - ref `00f162d6` from `getSettings` context `stmia r1!,{r0,r3,r5}`
    - ref `00f16382` from `getSettings` context `strd r0,r5,[sp,#0xc]`
    - ref `00f164d0` from `getSettings` context `strd r0,r5,[sp,#0xc]`
    - ref `00f165ac` from `getSettings` context `strd r0,r5,[sp,#0xc]`
    - ref `00f16694` from `getSettings` context `strd r0,r5,[sp,#0x0]`
    - ref `00e4a9dc` from `FUN_00e314fe` context `strd r1,r0,[sp,#0x8]`
    - ref `00d99182` from `getSettings` context `strd r2,r4,[sp,#0x8]`
    - ref `00d99254` from `getSettings` context `strd r9,r4,[sp,#0x8]`
    - ref `00d99320` from `getSettings` context `strd r9,r4,[sp,#0x8]`
    - ref `00df26e2` from `getSettings` context `strd r2,r4,[sp,#0x8]`
    - ref `00df27c2` from `getSettings` context `strd r8,r5,[sp,#0x8]`
    - ref `00df2882` from `getSettings` context `strd r8,r5,[sp,#0x8]`
    - ref `00df2928` from `getSettings` context `strd r8,r5,[sp,#0x8]`
    - direct refs: `15`
- Referencing functions: `5`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00f121ec`
  - `FUN_00e314fe @ 00e314fe`
  - `getSettings @ 00d8cc4c`
  - `getSettings @ 00dee0d8`
  - decompilation skipped in default refs-only mode

## `car_setting_drl_via_fogs`

- String matches: `1`
  - address: `00942056`
    - ref `0107aa66` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `0107aaac` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `0107ab04` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `0107ab60` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `0107abf4` from `FUN_0105f6c0` context `strd r6,r5,[sp,#0x8]`
    - ref `0107ac84` from `FUN_0105f6c0` context `strd r6,r5,[sp,#0x8]`
    - ref `00d9982c` from `getSettings` context `str r4,[sp,#0x8]`
    - ref `00d99890` from `getSettings` context `str r4,[sp,#0x8]`
    - ref `00d998f0` from `getSettings` context `str r4,[sp,#0x8]`
    - direct refs: `9`
- Referencing functions: `2`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00d8cc4c`
  - decompilation skipped in default refs-only mode

## `car_setting_scandinavian_drl`

- String matches: `1`
  - address: `00a5d10d`
    - ref `010797c2` from `FUN_0105f6c0` context `str r1,[sp,#0x198]`
    - ref `010797c4` from `FUN_0105f6c0` context `strd r0,r1,[sp,#0x0]`
    - ref `0107b1ac` from `FUN_0105f6c0` context `str r0,[sp,#0x8]`
    - ref `0107b20e` from `FUN_0105f6c0` context `str r0,[sp,#0x8]`
    - ref `0107b262` from `FUN_0105f6c0` context `str r0,[sp,#0x8]`
    - ref `0107b2be` from `FUN_0105f6c0` context `str r0,[sp,#0x8]`
    - ref `0107b30e` from `FUN_0105f6c0` context `str r0,[sp,#0x4]`
    - ref `00e49a3e` from `FUN_00e314fe` context `str r3,[sp,#0xc]`
    - ref `00e49b92` from `FUN_00e314fe` context `strd r0,r11,[sp,#0x8]`
    - ref `00e49da4` from `FUN_00e314fe` context `strd r0,r11,[sp,#0x8]`
    - ref `00e49ede` from `FUN_00e314fe` context `strd r0,r11,[sp,#0x8]`
    - ref `00e49f68` from `FUN_00e314fe` context `strd r0,r11,[sp,#0x8]`
    - ref `00e49fe0` from `FUN_00e314fe` context `strd r0,r11,[sp,#0x8]`
    - direct refs: `13`
- Referencing functions: `2`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_assist_dr_lights`

- String matches: `1`
  - address: `00b788d9`
    - ref `0108252c` from `FUN_0105f6c0` context `strd r1,r0,[sp,#0x0]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_turn_off_drl_with_parking_brake`

- String matches: `1`
  - address: `0084588e`
    - ref `0107b3aa` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
    - ref `0107b3fa` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
    - ref `0107b452` from `FUN_0105f6c0` context `str r5,[sp,#0x8]`
    - ref `0107b4ae` from `FUN_0105f6c0` context `str r5,[sp,#0x8]`
    - ref `0107b50e` from `FUN_0105f6c0` context `str r5,[sp,#0x8]`
    - ref `0107b560` from `FUN_0105f6c0` context `str r5,[sp,#0x8]`
    - ref `0107b5aa` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
    - ref `0107b5f4` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
    - direct refs: `8`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_turn_off_drl_with_turn_signal`

- String matches: `1`
  - address: `00c80682`
    - ref `0107b804` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `0107b85e` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `0107b8aa` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `00f1690c` from `getSettings` context `strd r0,r1,[sp,#0x0]`
    - direct refs: `4`
- Referencing functions: `2`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00f121ec`
  - decompilation skipped in default refs-only mode

## `car_setting_front_fogs_with_low_beams`

- String matches: `1`
  - address: `00a5d168`
    - ref `00e4bcfa` from `FUN_00e314fe` context `str.w r0,[r10,#0xbbc]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_pl_via_front_fog_lights`

- String matches: `1`
  - address: `0078dc15`
    - ref `00d9d3a4` from `getSettings` context `str r0,[sp,#0x8]`
    - direct refs: `1`
- Referencing functions: `1`
  - `getSettings @ 00d8cc4c`
  - decompilation skipped in default refs-only mode

## `car_setting_fogs_with_high_beam_restriction`

- String matches: `1`
  - address: `0076a97e`
    - ref `00e4de8a` from `FUN_00e314fe` context `str.w r2,[r10,#0x644]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_turn_off_fogs_with_high_beam`

- String matches: `1`
  - address: `00c32f89`
    - ref `0107f15a` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `0107f1b4` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `0107f20a` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `0107f26c` from `FUN_0105f6c0` context `str r4,[sp,#0x8]`
    - ref `0107f2d6` from `FUN_0105f6c0` context `str r4,[sp,#0x8]`
    - ref `0107f330` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `010f7c58` from `getSettings` context `strd r1,r0,[sp,#0x0]`
    - ref `00d9ae72` from `getSettings` context `str r4,[sp,#0x8]`
    - ref `00d9aed0` from `getSettings` context `str r4,[sp,#0x8]`
    - ref `00d9af2a` from `getSettings` context `str r4,[sp,#0x8]`
    - direct refs: `10`
- Referencing functions: `3`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 010f272c`
  - `getSettings @ 00d8cc4c`
  - decompilation skipped in default refs-only mode

## `car_setting_turn_on_fogs_with_high_beam`

- String matches: `1`
  - address: `00a5d1ba`
    - ref `00e4de9a` from `FUN_00e314fe` context `str.w r2,[r10,#0x634]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`
  - decompilation skipped in default refs-only mode

## `car_setting_coming_home`

- String matches: `1`
  - address: `009535c8`
    - ref `010218c8` from `getSettings` context `strd r1,r0,[sp,#0x0]`
    - ref `01076860` from `FUN_0105f6c0` context `str r4,[sp,#0x8]`
    - ref `010768ba` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `01076910` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `00f15cba` from `getSettings` context `strd r0,r5,[sp,#0x8]`
    - ref `00f15d08` from `getSettings` context `strd r5,r0,[sp,#0x0]`
    - direct refs: `6`
- Referencing functions: `3`
  - `getSettings @ 01018578`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00f121ec`
  - decompilation skipped in default refs-only mode

## `car_setting_coming_home_duration`

- String matches: `1`
  - address: `00c70e01`
    - ref `01021876` from `getSettings` context `strd r0,r6,[sp,#0x0]`
    - ref `0102197e` from `getSettings` context `strd r0,r6,[sp,#0x0]`
    - ref `01021a4e` from `getSettings` context `strd r0,r6,[sp,#0x0]`
    - ref `01021af0` from `getSettings` context `strd r10,r6,[sp,#0x0]`
    - ref `01021ba2` from `getSettings` context `strd r0,r6,[sp,#0x0]`
    - ref `0107813e` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x0]`
    - ref `010781e4` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `010782f2` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x0]`
    - ref `010783e0` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x0]`
    - ref `0107847e` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `01078526` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `01078618` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x0]`
    - ref `010786ba` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `01078752` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `00f15e2a` from `getSettings` context `str r3,[sp,#0x5c]`
    - ref `00f15e2e` from `getSettings` context `stmia r1!,{r0,r3,r4}`
    - ref `00f15f0c` from `getSettings` context `strd r0,r4,[sp,#0x0]`
    - ref `00e4665c` from `FUN_00e314fe` context `str r3,[sp,#0x28c]`
    - ref `00e46660` from `FUN_00e314fe` context `stmia r1!,{r0,r3,r4}`
    - ref `00e46786` from `FUN_00e314fe` context `strd r0,r4,[sp,#0xc]`
    - ref `00df0a0e` from `getSettings` context `strd r0,r4,[sp,#0x8]`
    - direct refs: `21`
- Referencing functions: `5`
  - `getSettings @ 01018578`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00f121ec`
  - `FUN_00e314fe @ 00e314fe`
  - `getSettings @ 00dee0d8`
  - decompilation skipped in default refs-only mode

## `car_setting_coming_home_mode`

- String matches: `1`
  - address: `00bc8202`
    - ref `01076ab4` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `01076b5e` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `01076bf4` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `01076d10` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `01076dd0` from `FUN_0105f6c0` context `strd r6,r4,[sp,#0x8]`
    - ref `01076e68` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
    - ref `00f160b8` from `getSettings` context `strd r1,r0,[sp,#0x8]`
    - direct refs: `7`
- Referencing functions: `2`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00f121ec`
  - decompilation skipped in default refs-only mode

## `car_setting_coming_home_req_rls`

- String matches: `1`
  - address: `0081c9c6`
    - ref `0107671a` from `FUN_0105f6c0` context `str r2,[sp,#0x8]`
    - ref `01076772` from `FUN_0105f6c0` context `strd r0,r8,[sp,#0x0]`
    - ref `010767e0` from `FUN_0105f6c0` context `strd r0,r8,[sp,#0x0]`
    - ref `01076964` from `FUN_0105f6c0` context `strd r0,r8,[sp,#0x0]`
    - direct refs: `4`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_coming_home_via_fogs`

- String matches: `1`
  - address: `0090e458`
    - ref `01077c50` from `FUN_0105f6c0` context `strd r1,r0,[sp,#0x0]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_coming_home_via_low_beams`

- String matches: `1`
  - address: `006eac1e`
    - ref `010776d8` from `FUN_0105f6c0` context `strd r1,r0,[sp,#0x0]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_coming_leaving_home_output`

- String matches: `1`
  - address: `009a2e80`
    - ref `010775ee` from `FUN_0105f6c0` context `str r2,[sp,#0xf0]`
    - ref `010775f0` from `FUN_0105f6c0` context `strd r2,r4,[sp,#0x8]`
    - ref `01077694` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x8]`
    - ref `01079282` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x4]`
    - ref `01079316` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x4]`
    - direct refs: `5`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_leaving_home_duration`

- String matches: `1`
  - address: `00765c9b`
    - ref `01078c66` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `01078d08` from `FUN_0105f6c0` context `strd r8,r4,[sp,#0x8]`
    - ref `01078e12` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `01078f08` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
    - ref `01078fac` from `FUN_0105f6c0` context `strd r8,r4,[sp,#0x8]`
    - ref `0107905a` from `FUN_0105f6c0` context `strd r8,r4,[sp,#0x8]`
    - ref `01079100` from `FUN_0105f6c0` context `strd r8,r4,[sp,#0x8]`
    - ref `01079196` from `FUN_0105f6c0` context `strd r8,r4,[sp,#0x8]`
    - ref `00df12f4` from `getSettings` context `strd r6,r4,[sp,#0x8]`
    - ref `00df1394` from `getSettings` context `strd r6,r4,[sp,#0x8]`
    - ref `00df1428` from `getSettings` context `strd r6,r4,[sp,#0x8]`
    - direct refs: `11`
- Referencing functions: `2`
  - `FUN_0105f6c0 @ 0105f6c0`
  - `getSettings @ 00dee0d8`
  - decompilation skipped in default refs-only mode

## `car_setting_leaving_home_req_rls`

- String matches: `1`
  - address: `008f0535`
    - ref `0107879a` from `FUN_0105f6c0` context `str r1,[sp,#0x4]`
    - ref `01078896` from `FUN_0105f6c0` context `strd r0,r8,[sp,#0x0]`
    - ref `010789bc` from `FUN_0105f6c0` context `strd r0,r8,[sp,#0x0]`
    - ref `01078a14` from `FUN_0105f6c0` context `str.w r8,[sp,#0x8]`
    - direct refs: `4`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

## `car_setting_enabled_coming_home_or_leaving_home`

- String matches: `1`
  - address: `008f05d8`
    - ref `0107e0f2` from `FUN_0105f6c0` context `str r1,[sp,#0x1c4]`
    - ref `0107e0f4` from `FUN_0105f6c0` context `str.w r1,[r2,#0x698]`
    - ref `0107e200` from `FUN_0105f6c0` context `str.w r4,[r3,#0x638]`
    - ref `0107fdae` from `FUN_0105f6c0` context `str.w r3,[r4,#0x308]`
    - ref `0108292a` from `FUN_0105f6c0` context `str.w r1,[r3,#0xe2c]`
    - ref `010829ec` from `FUN_0105f6c0` context `str.w r0,[r3,#0xdfc]`
    - ref `01082b1a` from `FUN_0105f6c0` context `str.w r1,[r3,#0xda4]`
    - ref `01082bd4` from `FUN_0105f6c0` context `str.w r0,[r3,#0xd74]`
    - direct refs: `8`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`
  - decompilation skipped in default refs-only mode

