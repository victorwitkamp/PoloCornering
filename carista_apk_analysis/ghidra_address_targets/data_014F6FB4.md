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
- `01168648`: `blx 0x013fa790` refs: `UNCONDITIONAL_CALL -> 013fa790`
- `0116864c`: `mov r8,r0`
- `0116864e`: `add r0,sp,#0x174`
- `01168650`: `ldr r1,[0x01168664]` refs: `READ -> 01168664`
- `01168652`: `add r1,pc` refs: `PARAM -> 00a6c093`
- `01168654`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168658`: `b 0x01168668` refs: `UNCONDITIONAL_JUMP -> 01168668`
- `01168668`: `ldr r1,[0x01168674]` refs: `READ -> 01168674`
- `0116866a`: `adds r0,#0xc`
- `0116866c`: `add r1,pc` refs: `PARAM -> 00aca060`
### Around `0116863a`
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
- `01168648`: `blx 0x013fa790` refs: `UNCONDITIONAL_CALL -> 013fa790`
- `0116864c`: `mov r8,r0`
- `0116864e`: `add r0,sp,#0x174`
- `01168650`: `ldr r1,[0x01168664]` refs: `READ -> 01168664`
- `01168652`: `add r1,pc` refs: `PARAM -> 00a6c093`
- `01168654`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168658`: `b 0x01168668` refs: `UNCONDITIONAL_JUMP -> 01168668`
- `01168668`: `ldr r1,[0x01168674]` refs: `READ -> 01168674`
- `0116866a`: `adds r0,#0xc`
- `0116866c`: `add r1,pc` refs: `PARAM -> 00aca060`
- `0116866e`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168672`: `b 0x01168678` refs: `UNCONDITIONAL_JUMP -> 01168678`
- `01168678`: `add r0,sp,#0x48`
- `0116867a`: `add r6,sp,#0x174`
- `0116867c`: `movs r2,#0x2`
- `0116867e`: `mov r1,r6`
- `01168680`: `bl 0x00d22d0c` refs: `UNCONDITIONAL_CALL -> 00d22d0c`
- `01168684`: `movs r4,#0x1`
- `01168686`: `add r1,sp,#0x48`
- `01168688`: `mov r0,r8`
### Around `011686ec`
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
- `011686fe`: `strex r2,r1,[r0,#0x0]`
- `01168702`: `cmp r2,#0x0`
- `01168704`: `bne 0x011686f8` refs: `CONDITIONAL_JUMP -> 011686f8`
- `01168706`: `ldr r0,[0x0116871c]` refs: `READ -> 0116871c`
- `01168708`: `add r4,sp,#0x174`
- `0116870a`: `movs r2,#0x2`
- `0116870c`: `add r0,pc`
- `0116870e`: `mov r1,r4`
- `01168710`: `ldr.w r8,[r0,#0x0]` refs: `READ -> 014df244`
- `01168714`: `mov r0,r8` refs: `PARAM -> 014f6fc4`
- `01168716`: `blx 0x014084d0` refs: `UNCONDITIONAL_CALL -> 014084d0`
- `0116871a`: `b 0x01168720` refs: `UNCONDITIONAL_JUMP -> 01168720`
- `01168720`: `movs r5,#0x8`
- `01168722`: `str.w r10,[sp,#0x30]` refs: `DATA -> 014f6f94` `WRITE -> Stack[-0x1058]`
- `01168726`: `adds r0,r4,r5`
- `01168728`: `bl 0x00d5d494` refs: `UNCONDITIONAL_CALL -> 00d5d494`
- `0116872c`: `subs r5,#0x8`
- `0116872e`: `adds.w r0,r5,#0x8`
- `01168732`: `bne 0x01168726` refs: `CONDITIONAL_JUMP -> 01168726`
- `01168734`: `ldr r0,[0x01168758]` refs: `READ -> 01168758`
