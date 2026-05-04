# Carista Setting String References

Addresses are ELF addresses plus the known Ghidra image-base delta `0x10000`.

## `car_setting_fog_when`

- ELF address: `0x00B58D33`
- Ghidra address: `00b68d33`
- Direct references: `2`

  - `00e4e794` from `FUN_00e314fe`
    - context: `strd r3,r5,[sp,#0xc]`
  - `00e4e946` from `FUN_00e314fe`
    - context: `strd r0,r9,[sp,#0x8]`

## `car_setting_left_fog_light_as`

- ELF address: `0x007FD376`
- Ghidra address: `0080d376`
- Direct references: `2`

  - `00e4ebb0` from `FUN_00e314fe`
    - context: `strd r3,r5,[sp,#0xc]`
  - `00e4ed64` from `FUN_00e314fe`
    - context: `strd r0,r8,[sp,#0x8]`

## `car_setting_right_fog_light_as`

- ELF address: `0x00C28F62`
- Ghidra address: `00c38f62`
- Direct references: `2`

  - `00e4efa4` from `FUN_00e314fe`
    - context: `strd r3,r5,[sp,#0xc]`
  - `00e4f146` from `FUN_00e314fe`
    - context: `strd r0,r8,[sp,#0x8]`

## `car_setting_cornering_lights_via_fogs`

- ELF address: `0x00B3F397`
- Ghidra address: `00b4f397`
- Direct references: `8`

  - `01082764` from `FUN_0105f6c0`
    - context: `strd r0,r4,[sp,#0x0]`
  - `010827b0` from `FUN_0105f6c0`
    - context: `strd r0,r4,[sp,#0x0]`
  - `01082808` from `FUN_0105f6c0`
    - context: `strd r0,r4,[sp,#0x0]`
  - `0108285e` from `FUN_0105f6c0`
    - context: `strd r0,r4,[sp,#0x0]`
  - `00e4e01c` from `FUN_00e314fe`
    - context: `strd r0,r6,[sp,#0x8]`
  - `00e4e0a0` from `FUN_00e314fe`
    - context: `strd r0,r6,[sp,#0x8]`
  - `00e4e1d4` from `FUN_00e314fe`
    - context: `strd r0,r6,[sp,#0x8]`
  - `00e4e3d8` from `FUN_00e314fe`
    - context: `strd r0,r6,[sp,#0x8]`

## `car_setting_cornering_lights_via_fogs_experimental`

- ELF address: `0x008E06F6`
- Ghidra address: `008f06f6`
- Direct references: `1`

  - `010828ba` from `FUN_0105f6c0`
    - context: `strd r1,r0,[sp,#0x0]`

## `car_setting_use_cornering_lights`

- ELF address: `0x007FD355`
- Ghidra address: `0080d355`
- Direct references: `3`

  - `00e4e724` from `FUN_00e314fe`
    - context: `str r0,[sp,#0x20c]`
  - `00e4e726` from `FUN_00e314fe`
    - context: `str.w r0,[r10,#0x4e4]`
  - `00e4e902` from `FUN_00e314fe`
    - context: `str.w r0,[r10,#0x47c]`

## `car_setting_cornering_lights_with_turn_signals`

- ELF address: `0x00A1B8B1`
- Ghidra address: `00a2b8b1`
- Direct references: `0`

  - No direct Ghidra references found. This usually means the string is reached through a table, hash, or offset arithmetic rather than a plain pointer.

## `car_setting_cornerig_lights_with_turn_signal`

- ELF address: `0x006984AE`
- Ghidra address: `006a84ae`
- Direct references: `4`

  - `00e4ed0c` from `FUN_00e314fe`
    - context: `str r3,[sp,#0x20c]`
  - `00e4ed0e` from `FUN_00e314fe`
    - context: `str.w r3,[r10,#0x34c]`
  - `00e4ed04` from `FUN_00e314fe`
    - context: `add r3,pc`
  - `00e4f0e2` from `FUN_00e314fe`
    - context: `str.w r2,[r10,#0x20c]`

## `car_setting_cornering_lights_with_turn_signals_one_touch`

- ELF address: `0x0081