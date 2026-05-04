# Carista Native Lighting Setting Probe

String matches are found by exact UTF-8 text plus NUL terminator, then direct Ghidra references are exported.

## `car_setting_fog_when`

- String matches: `1`
  - address: `00b68d33`
    - ref `00e4e794` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
    - ref `00e4e946` from `FUN_00e314fe` context `strd r0,r9,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`

## `car_setting_left_fog_light_as`

- String matches: `1`
  - address: `0080d376`
    - ref `00e4ebb0` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
    - ref `00e4ed64` from `FUN_00e314fe` context `strd r0,r8,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`

## `car_setting_right_fog_light_as`

- String matches: `1`
  - address: `00c38f62`
    - ref `00e4efa4` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
    - ref `00e4f146` from `FUN_00e314fe` context `strd r0,r8,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`

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

## `car_setting_cornering_lights_activation`

- String matches: `1`
  - address: `00bcc3ce`
    - ref `01082d7c` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082e66` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082eb6` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
    - direct refs: `3`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`

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

## `car_setting_cornering_lights_via_fogs_experimental`

- String matches: `1`
  - address: `008f06f6`
    - ref `010828ba` from `FUN_0105f6c0` context `strd r1,r0,[sp,#0x0]`
    - direct refs: `1`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`

## `car_setting_cornering_lights_via_fogs_left`

- String matches: `1`
  - address: `00aea817`
    - ref `01082988` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082a4a` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`

## `car_setting_cornering_lights_via_fogs_right`

- String matches: `1`
  - address: `00aea842`
    - ref `01082b78` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - ref `01082c34` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
    - direct refs: `2`
- Referencing functions: `1`
  - `FUN_0105f6c0 @ 0105f6c0`

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

## `car_setting_use_cornering_lights`

- String matches: `1`
  - address: `0080d355`
    - ref `00e4e724` from `FUN_00e314fe` context `str r0,[sp,#0x20c]`
    - ref `00e4e726` from `FUN_00e314fe` context `str.w r0,[r10,#0x4e4]`
    - ref `00e4e902` from `FUN_00e314fe` context `str.w r0,[r10,#0x47c]`
    - direct refs: `3`
- Referencing functions: `1`
  - `FUN_00e314fe @ 00e314fe`

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
    - ref `00df26e2` from `getSettings` c