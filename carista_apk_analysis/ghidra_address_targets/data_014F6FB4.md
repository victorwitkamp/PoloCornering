# Data Target `014f6fb4`

## Symbols
- `Label` `VagWhitelists::CENTRAL_ELEC_6RU`
- `Label` `_ZN13VagWhitelists16CENTRAL_ELEC_6RUE`

## Memory Bytes
<unreadable: MemoryAccessException: Unable to read bytes at ram:014f6fb4>

## Direct References To This Address
- `EXTERNAL` from `Entry Point` in `<no function>`
- `DATA` from `014df240` in `<no function>`
- `PARAM` from `0116861c` in `_INIT_138 @ 01156090`
- `PARAM` from `0116863a` in `_INIT_138 @ 01156090`
- `READ` from `011686ec` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `0116861c`: `mov r0,r9`
- `0116863a`: `mov r1,r9`
- `011686ec`: `ldrd r1,r0,[r9,#0x0]`

## Local Instruction Windows
### Around `0116861c`
- `011685c0`: `bne 0x011685b4` refs: `CONDITIONAL_JUMP -> 011685b4`
- `011685c2`: `ldr r0,[0x011685dc]` refs: `READ -> 011685dc`
- `011685c4`: `mov r1,r5` refs: `PARAM -> 014f6fac`
- `011685c6`: `ldr r2,[0x011685e0]` refs: `READ -> 011685e0`
- `011685c8`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `011685ca`: `add r2,pc` refs: `PARAM -> 014371d0`
- `011685cc`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `011685d0`: `ldrd r1,r0,[r9,#0x0]` refs: `READ -> 014f6fa4` `READ -> 014f6fa8`
- `011685d4`: `strd r1,r0,[sp,#0x174]` refs: `WRITE -> Stack[-0xf14]`
- `011685d8`: `cbz r0,0x011685f4` refs: `CONDITIONAL_JUMP -> 011685f4`
- `011685da`: `b 0x011685e4` refs: `UNCONDITIONAL_JUMP -> 011685e4`
- `011685e4`: `adds r0,#0x4`
- `011685e6`: `ldrex r1,[r0,#0x0]`
- `011685ea`: `adds r1,#0x1`
- `011685ec`: `strex r2,r1,[r0,#0x0]`
- `011685f0`: `cmp r2,#0x0`
- `011685f2`: `bne 0x011685e6` refs: `CONDITIONAL_JUMP -> 011685e6`
- `011685f4`: `ldrd r1,r0,[r5,#0x0]` refs: `READ -> 014f6fac` `READ -> 014f6fb0`
- `011685f8`: `strd r1,r0,[sp,#0x17c]` refs: `WRITE -> Stack[-0xf0c]`
- `011685fc`: `cbz r0,0x0116860e` refs: `CONDITIONAL_JUMP -> 0116860e`
- `011685fe`: `adds r0,#0x4`
- `01168600`: `ldrex r1,[r0,#0x0]`
- `01168604`: `adds r1,#0x1`
- `01168606`: `strex r2,r1,[r0,#0x0]`
- `0116860a`: `cmp r2,#0x0`
- `0116860c`: `bne 0x01168600` refs: `CONDITIONAL_JUMP -> 01168600`
- `0116860e`: `ldr r0,[0x01168624]` refs: `READ -> 01168624`
- `01168610`: `add r5,sp,#0x174`
- `01168612`: `movs r2,#0x2`
- `01168614`: `add r0,pc`
- `01168616`: `mov r1,r5`
- `01168618`: `ldr.w r9,[r0,#0x0]` refs: `READ -> 014df240`
- `0116861c`: `mov r0,r9` refs: `PARAM -> 014f6fb4`
- `0116861e`: `blx 0x014084d0` refs: `UNCONDITIONAL_CALL -> 014084d0`
- `01168622`: `b 0x01168628` refs: `UNCONDITIONAL_JUMP -> 01168628`
- `01168628`: `movs r4,#0x8`
- `0116862a`: `adds r0,r5,r4`
- `0116862c`: `bl 0x00d5d494` refs: `UNCONDITIONAL_CALL -> 00d5d494`
### Around `0116863a`
- `011685da`: `b 0x011685e4` refs: `UNCONDITIONAL_JUMP -> 011685e4`
- `011685e4`: `adds r0,#0x4`
- `011685e6`: `ldrex r1,[r0,#0x0]`
- `011685ea`: `adds r1,#0x1`
- `011685ec`: `strex r2,r1,[r0,#0x0]`
- `011685f0`: `cmp r2,#0x0`
- `011685f2`: `bne 0x011685e6` refs: `CONDITIONAL_JUMP -> 011685e6`
- `011685f4`: `ldrd r1,r0,[r5,#0x0]` refs: `READ -> 014f6fac` `READ -> 014f6fb0`
- `011685f8`: `strd r1,r0,[sp,#0x17c]` refs: `WRITE -> Stack[-0xf0c]`
- `011685fc`: `cbz r0,0x0116860e` refs: `CONDITIONAL_JUMP -> 0116860e`
- `011685fe`: `adds r0,#0x4`
- `01168600`: `ldrex r1,[r0,#0x0]`
- `01168604`: `adds r1,#0x1`
- `01168606`: `strex r2,r1,[r0,#0x0]`
- `0116860a`: `cmp r2,#0x0`
- `0116860c`: `bne 0x01168600` refs: `CONDITIONAL_JUMP -> 01168600`
- `0116860e`: `ldr r0,[0x01168624]` refs: `READ -> 01168624`
- `01168610`: `add r5,sp,#0x174`
- `01168612`: `movs r2,#0x2`
- `01168614`: `add r0,pc`
- `01168616`: `mov r1,r5`
- `01168618`: `ldr.w r9,[r0,#0x0]` refs: `READ -> 014df240`
- `0116861c`: `mov r0,r9` refs: `PARAM -> 014f6fb4`
- `0116861e`: `blx 0x014084d0` refs: `UNCONDITIONAL_CALL -> 014084d0`
- `01168622`: `b 0x01168628` refs: `UNCONDITIONAL_JUMP -> 01168628`
- `01168628`: `movs r4,#0x8`
- `0116862a`: `adds r0,r5,r4`
- `0116862c`: `bl 0x00d5d494` refs: `UNCONDITIONAL_CALL -> 00d5d494`
- `01168630`: `subs r4,#0x8`
- `01168632`: `adds.w r0,r4,#0x8`
- `01168636`: `bne 0x0116862a` refs: `CONDITIONAL_JUMP -> 0116862a`
- `01168638`: `ldr r0,[0x0116865c]` refs: `READ -> 0116865c`
- `0116863a`: `mov r1,r9` refs: `PARAM -> 014f6fb4`
- `0116863c`: `ldr r2,[0x01168660]` refs: `READ -> 01168660`
- `0116863e`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `01168640`: `add r2,pc` refs: `PARAM -> 014371d0`
- `01168642`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168646`: `movs r0,#0x30`
### Around `011686ec`
- `0116868e`: `movs r4,#0x0`
- `01168690`: `ldr r0,[0x011686a0]` refs: `READ -> 011686a0`
- `01168692`: `mov r1,r8`
- `01168694`: `add r0,pc`
- `01168696`: `ldr r5,[r0,#0x0]` refs: `READ -> 014de8b0`
- `01168698`: `mov r0,r5` refs: `PARAM -> 014f6fbc`
- `0116869a`: `blx 0x0140be90` refs: `UNCONDITIONAL_CALL -> 0140be90`
- `0116869e`: `b 0x011686a4` refs: `UNCONDITIONAL_JUMP -> 011686a4`
- `011686a4`: `add r0,sp,#0x48`
- `011686a6`: `bl 0x00cbe2dc` refs: `UNCONDITIONAL_CALL -> 00cbe2dc`
- `011686aa`: `movs r4,#0xc`
- `011686ac`: `adds r0,r6,r4`
- `011686ae`: `blx 0x013fa600` refs: `UNCONDITIONAL_CALL -> 013fa600`
- `011686b2`: `subs r4,#0xc`
- `011686b4`: `adds.w r0,r4,#0xc`
- `011686b8`: `bne 0x011686ac` refs: `CONDITIONAL_JUMP -> 011686ac`
- `011686ba`: `ldr r0,[0x011686d4]` refs: `READ -> 011686d4`
- `011686bc`: `mov r1,r5` refs: `PARAM -> 014f6fbc`
- `011686be`: `ldr r2,[0x011686d8]` refs: `READ -> 011686d8`
- `011686c0`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `011686c2`: `add r2,pc` refs: `PARAM -> 014371d0`
- `011686c4`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `011686c8`: `ldrd r1,r0,[r5,#0x0]` refs: `READ -> 014f6fbc` `READ -> 014f6fc0`
- `011686cc`: `strd r1,r0,[sp,#0x174]` refs: `WRITE -> Stack[-0xf14]`
- `011686d0`: `cbz r0,0x011686ec` refs: `CONDITIONAL_JUMP -> 011686ec`
- `011686d2`: `b 0x011686dc` refs: `UNCONDITIONAL_JUMP -> 011686dc`
- `011686dc`: `adds r0,#0x4`
- `011686de`: `ldrex r1,[r0,#0x0]`
- `011686e2`: `adds r1,#0x1`
- `011686e4`: `strex r2,r1,[r0,#0x0]`
- `011686e8`: `cmp r2,#0x0`
- `011686ea`: `bne 0x011686de` refs: `CONDITIONAL_JUMP -> 011686de`
- `011686ec`: `ldrd r1,r0,[r9,#0x0]` refs: `READ -> 014f6fb4` `READ -> 014f6fb8`
- `011686f0`: `strd r1,r0,[sp,#0x17c]` refs: `WRITE -> Stack[-0xf0c]`
- `011686f4`: `cbz r0,0x01168706` refs: `CONDITIONAL_JUMP -> 01168706`
- `011686f6`: `adds r0,#0x4`
- `011686f8`: `ldrex r1,[r0,#0x0]`
- `011686fc`: `adds r1,#0x1`
