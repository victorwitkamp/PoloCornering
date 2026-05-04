# Carista Setting String References Only

No decompilation is attempted in this export.

## `car_setting_fog_when`

- ELF address: `0x00B58D33`
- Ghidra address: `00b68d33`
  - `00e4e794` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
  - `00e4e946` from `FUN_00e314fe` context `strd r0,r9,[sp,#0x8]`
- Direct references: `2`

## `car_setting_left_fog_light_as`

- ELF address: `0x007FD376`
- Ghidra address: `0080d376`
  - `00e4ebb0` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
  - `00e4ed64` from `FUN_00e314fe` context `strd r0,r8,[sp,#0x8]`
- Direct references: `2`

## `car_setting_right_fog_light_as`

- ELF address: `0x00C28F62`
- Ghidra address: `00c38f62`
  - `00e4efa4` from `FUN_00e314fe` context `strd r3,r5,[sp,#0xc]`
  - `00e4f146` from `FUN_00e314fe` context `strd r0,r8,[sp,#0x8]`
- Direct references: `2`

## `car_setting_cornering_lights_via_fogs`

- ELF address: `0x00B3F397`
- Ghidra address: `00b4f397`
  - `01082764` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
  - `010827b0` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
  - `01082808` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
  - `0108285e` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
  - `00e4e01c` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
  - `00e4e0a0` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
  - `00e4e1d4` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
  - `00e4e3d8` from `FUN_00e314fe` context `strd r0,r6,[sp,#0x8]`
- Direct references: `8`

## `car_setting_cornering_lights_via_fogs_experimental`

- ELF address: `0x008E06F6`
- Ghidra address: `008f06f6`
  - `010828ba` from `FUN_0105f6c0` context `strd r1,r0,[sp,#0x0]`
- Direct references: `1`

## `car_setting_use_cornering_lights`

- ELF address: `0x007FD355`
- Ghidra address: `0080d355`
  - `00e4e724` from `FUN_00e314fe` context `str r0,[sp,#0x20c]`
  - `00e4e726` from `FUN_00e314fe` context `str.w r0,[r10,#0x4e4]`
  - `00e4e902` from `FUN_00e314fe` context `str.w r0,[r10,#0x47c]`
- Direct references: `3`

## `car_setting_cornering_lights_with_turn_signals`

- ELF address: `0x00A1B8B1`
- Ghidra address: `00a2b8b1`
- Direct references: `0`

## `car_setting_cornerig_lights_with_turn_signal`

- ELF address: `0x006984AE`
- Ghidra address: `006a84ae`
  - `00e4ed0c` from `FUN_00e314fe` context `str r3,[sp,#0x20c]`
  - `00e4ed0e` from `FUN_00e314fe` context `str.w r3,[r10,#0x34c]`
  - `00e4ed04` from `FUN_00e314fe` context `add r3,pc`
  - `00e4f0e2` from `FUN_00e314fe` context `str.w r2,[r10,#0x20c]`
- Direct references: `4`

## `car_setting_cornering_lights_with_turn_signals_one_touch`

- ELF address: `0x0081F251`
- Ghidra address: `0082f251`
  - `00d94b6a` from `getSettings` context `str r5,[sp,#0x8]`
  - `00d94bb2` from `getSettings` context `str r5,[sp,#0x8]`
- Direct references: `2`

## `car_setting_cornering_lights_via_fogs_left`

- ELF address: `0x00ADA817`
- Ghidra address: `00aea817`
  - `01082988` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
  - `01082a4a` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
- Direct references: `2`

## `car_setting_cornering_lights_via_fogs_right`

- ELF address: `0x00ADA842`
- Ghidra address: `00aea842`
  - `01082b78` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
  - `01082c34` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
- Direct references: `2`

## `car_setting_cornering_lights_via`

- ELF address: `0x00A1B890`
- Ghidra address: `00a2b890`
- Direct references: `0`

## `car_setting_cornering_lights`

- ELF address: `0x008E8CBA`
- Ghidra address: `008f8cba`
  - `0102003a` from `getSettings` context `strd r1,r0,[sp,#0x0]`
  - `010825e2` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
  - `0108263c` from `FUN_0105f6c0` context `strd r0,r6,[sp,#0x0]`
  - `00e4e532` from `FUN_00e314fe` context `strd r0,r3,[sp,#0x8]`
  - `00e4e540` from `FUN_00e314fe` context `str r3,[sp,#0x244]`
  - `00e4eb42` from `FUN_00e314fe` context `str.w r0,[r10,#0x3cc]`
  - `00e4ed16` from `FUN_00e314fe` context `str.w r2,[r10,#0x33c]`
  - `00e4ef1e` from `FUN_00e314fe` context `str.w r0,[r10,#0x28c]`
  - `00e4f100` from `FUN_00e314fe` context `str.w r2,[r10,#0x1fc]`
  - `00d93dbc` from `getSettings` context `strd r0,r6,[sp,#0x8]`
- Direct references: `10`

## `car_setting_cornering_lights_activation`

- ELF address: `0x00BBC3CE`
- Ghidra address: `00bcc3ce`
  - `01082d7c` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
  - `01082e66` from `FUN_0105f6c0` context `strd r5,r4,[sp,#0x8]`
  - `01082eb6` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
- Direct references: `3`

## `car_setting_instr_needle_sweep`

- ELF address: `0x00B9AECC`
- Ghidra address: `00baaecc`
  - `0106830a` from `FUN_0105f6c0` context `strd r0,r4,[sp,#0x0]`
  - `0106839c` from `FUN_0105f6c0` context `strd r0,r5,[sp,#0x0]`
  - `01068406` from `FUN_0105f6c0` context `strd r0,r9,[sp,#0x0]`
  - `01068466` from `FUN_0105f6c0` context `strd r0,r9,[sp,#0x0]`
  - `010f498e` from `getSettings` context `str.w r0,[r10,#0x9d0]`
  - `012a2324` from `getPopularSettings` context `add r1,pc`
- Direct references: `6`

## `car_setting_instr_needle_sweep_method_b`

- ELF address: `0x00B4E8C7`
- Ghidra address: `00b5e8c7`
  - `010684b6` from `FUN_0105f6c0` context `str r0,[sp,#0x8]`
- Direct references: `1`

