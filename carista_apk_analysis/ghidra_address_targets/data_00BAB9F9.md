# Data Target `00bab9f9`

## Symbols
- `Label` `s_1S0937090*_00bab9f9`

## Memory Bytes
`3153303933373039302a00355130393337303837414c003551303933373038374a00355130393337303836424800355131393337303835410035513039353535`

## Direct References To This Address
- `PARAM` from `01168ac8` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `01168ac8`: `add r1,pc`

## Local Instruction Windows
### Around `01168ac8`
- `01168a64`: `add r0,sp,#0x48`
- `01168a66`: `bl 0x00cbe2dc` refs: `UNCONDITIONAL_CALL -> 00cbe2dc`
- `01168a6a`: `movs r4,#0xc`
- `01168a6c`: `adds r0,r5,r4`
- `01168a6e`: `blx 0x013fa600` refs: `UNCONDITIONAL_CALL -> 013fa600`
- `01168a72`: `subs r4,#0xc`
- `01168a74`: `adds.w r0,r4,#0xc`
- `01168a78`: `bne 0x01168a6c` refs: `CONDITIONAL_JUMP -> 01168a6c`
- `01168a7a`: `ldr r0,[0x01168aa0]` refs: `READ -> 01168aa0`
- `01168a7c`: `mov r1,r6` refs: `PARAM -> 014f6ff4`
- `01168a7e`: `ldr r2,[0x01168aa4]` refs: `READ -> 01168aa4`
- `01168a80`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `01168a82`: `add r2,pc` refs: `PARAM -> 014371d0`
- `01168a84`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168a88`: `movs r0,#0x30`
- `01168a8a`: `blx 0x013fa790` refs: `UNCONDITIONAL_CALL -> 013fa790`
- `01168a8e`: `mov r8,r0`
- `01168a90`: `add r5,sp,#0x174`
- `01168a92`: `ldr r1,[0x01168aa8]` refs: `READ -> 01168aa8`
- `01168a94`: `add r1,pc` refs: `PARAM -> 00845f66`
- `01168a96`: `mov r0,r5`
- `01168a98`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168a9c`: `b 0x01168aac` refs: `UNCONDITIONAL_JUMP -> 01168aac`
- `01168aac`: `add.w r6,r5,#0xc`
- `01168ab0`: `ldr r1,[0x01168abc]` refs: `READ -> 01168abc`
- `01168ab2`: `mov r0,r6`
- `01168ab4`: `add r1,pc` refs: `PARAM -> 006eb2a5`
- `01168ab6`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168aba`: `b 0x01168ac0` refs: `UNCONDITIONAL_JUMP -> 01168ac0`
- `01168ac0`: `add.w r6,r5,#0x18`
- `01168ac4`: `ldr r1,[0x01168ad0]` refs: `READ -> 01168ad0`
- `01168ac6`: `mov r0,r6`
- `01168ac8`: `add r1,pc` refs: `PARAM -> 00bab9f9`
- `01168aca`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168ace`: `b 0x01168ad4` refs: `UNCONDITIONAL_JUMP -> 01168ad4`
- `01168ad4`: `add r0,sp,#0x48`
- `01168ad6`: `add r5,sp,#0x174`
- `01168ad8`: `movs r2,#0x3`
