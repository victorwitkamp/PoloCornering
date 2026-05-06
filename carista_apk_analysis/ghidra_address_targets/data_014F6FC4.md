# Data Target `014f6fc4`

## Symbols
- `Label` `VagWhitelists::CENTRAL_ELEC_6R`
- `Label` `_ZN13VagWhitelists15CENTRAL_ELEC_6RE`

## Memory Bytes
<unreadable: MemoryAccessException: Unable to read bytes at ram:014f6fc4>

## Direct References To This Address
- `EXTERNAL` from `Entry Point` in `<no function>`
- `DATA` from `014df244` in `<no function>`
- `PARAM` from `01168714` in `_INIT_138 @ 01156090`
- `PARAM` from `01168736` in `_INIT_138 @ 01156090`
- `READ` from `0116898e` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `01168714`: `mov r0,r8`
- `01168736`: `mov r1,r8`
- `0116898e`: `ldrd r1,r0,[r8,#0x0]`

## Local Instruction Windows
### Around `01168714`
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
### Around `01168736`
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
- `01168736`: `mov r1,r8` refs: `PARAM -> 014f6fc4`
- `01168738`: `ldr r2,[0x0116875c]` refs: `READ -> 0116875c`
- `0116873a`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `0116873c`: `add r2,pc` refs: `PARAM -> 014371d0`
- `0116873e`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168742`: `movs r0,#0x30`
### Around `0116898e`
- `0116893a`: `cmp r2,#0x0`
- `0116893c`: `bne 0x01168930` refs: `CONDITIONAL_JUMP -> 01168930`
- `0116893e`: `ldrd r1,r0,[r4,#0x0]` refs: `READ -> 014f6fdc` `READ -> 014f6fe0`
- `01168942`: `strd r1,r0,[sp,#0x184]` refs: `WRITE -> Stack[-0xf04]`
- `01168946`: `cbz r0,0x01168958` refs: `CONDITIONAL_JUMP -> 01168958`
- `01168948`: `adds r0,#0x4`
- `0116894a`: `ldrex r1,[r0,#0x0]`
- `0116894e`: `adds r1,#0x1`
- `01168950`: `strex r2,r1,[r0,#0x0]`
- `01168954`: `cmp r2,#0x0`
- `01168956`: `bne 0x0116894a` refs: `CONDITIONAL_JUMP -> 0116894a`
- `01168958`: `ldr r0,[0x0116896c]` refs: `READ -> 0116896c`
- `0116895a`: `add r5,sp,#0x174`
- `0116895c`: `movs r2,#0x3`
- `0116895e`: `add r0,pc`
- `01168960`: `mov r1,r5`
- `01168962`: `ldr r4,[r0,#0x0]` refs: `READ -> 014de73c`
- `01168964`: `mov r0,r4` refs: `PARAM -> 014f6fe4`
- `01168966`: `blx 0x014084d0` refs: `UNCONDITIONAL_CALL -> 014084d0`
- `0116896a`: `b 0x01168970` refs: `UNCONDITIONAL_JUMP -> 01168970`
- `01168970`: `movs r6,#0x10`
- `01168972`: `adds r0,r5,r6`
- `01168974`: `bl 0x00d5d494` refs: `UNCONDITIONAL_CALL -> 00d5d494`
- `01168978`: `subs r6,#0x8`
- `0116897a`: `adds.w r0,r6,#0x8`
- `0116897e`: `bne 0x01168972` refs: `CONDITIONAL_JUMP -> 01168972`
- `01168980`: `ldr r0,[0x0116899c]` refs: `READ -> 0116899c`
- `01168982`: `mov r1,r4` refs: `PARAM -> 014f6fe4`
- `01168984`: `ldr r2,[0x011689a0]` refs: `READ -> 011689a0`
- `01168986`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `01168988`: `add r2,pc` refs: `PARAM -> 014371d0`
- `0116898a`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `0116898e`: `ldrd r1,r0,[r8,#0x0]` refs: `READ -> 014f6fc4` `READ -> 014f6fc8`
- `01168992`: `strd r1,r0,[sp,#0x174]` refs: `WRITE -> Stack[-0xf14]`
- `01168996`: `cbz r0,0x011689b4` refs: `CONDITIONAL_JUMP -> 011689b4`
- `01168998`: `b 0x011689a4` refs: `UNCONDITIONAL_JUMP -> 011689a4`
- `011689a4`: `adds r0,#0x4`
- `011689a6`: `ldrex r1,[r0,#0x0]`
