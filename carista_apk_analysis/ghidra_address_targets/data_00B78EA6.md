# Data Target `00b78ea6`

## Symbols
- `Label` `s_7N0907532*_00b78ea6`

## Memory Bytes
`374e303930373533322a003551303933373038345300355130393337303836500035513039333730383741420035513039333730383444530035513039333730`

## Direct References To This Address
- `PARAM` from `01168a12` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `01168a12`: `add r1,pc`

## Local Instruction Windows
### Around `01168a12`
- `011689be`: `adds r0,#0x4`
- `011689c0`: `ldrex r1,[r0,#0x0]`
- `011689c4`: `adds r1,#0x1`
- `011689c6`: `strex r2,r1,[r0,#0x0]`
- `011689ca`: `cmp r2,#0x0`
- `011689cc`: `bne 0x011689c0` refs: `CONDITIONAL_JUMP -> 011689c0`
- `011689ce`: `ldr r0,[0x011689e4]` refs: `READ -> 011689e4`
- `011689d0`: `add r4,sp,#0x174`
- `011689d2`: `movs r2,#0x2`
- `011689d4`: `add r0,pc`
- `011689d6`: `mov r1,r4`
- `011689d8`: `ldr.w r10,[r0,#0x0]` refs: `READ -> 014de6e4`
- `011689dc`: `mov r0,r10` refs: `PARAM -> 014f6fec`
- `011689de`: `blx 0x014084d0` refs: `UNCONDITIONAL_CALL -> 014084d0`
- `011689e2`: `b 0x011689e8` refs: `UNCONDITIONAL_JUMP -> 011689e8`
- `011689e8`: `movs r5,#0x8`
- `011689ea`: `adds r0,r4,r5`
- `011689ec`: `bl 0x00d5d494` refs: `UNCONDITIONAL_CALL -> 00d5d494`
- `011689f0`: `subs r5,#0x8`
- `011689f2`: `adds.w r0,r5,#0x8`
- `011689f6`: `bne 0x011689ea` refs: `CONDITIONAL_JUMP -> 011689ea`
- `011689f8`: `ldr r0,[0x01168a1c]` refs: `READ -> 01168a1c`
- `011689fa`: `mov r1,r10` refs: `PARAM -> 014f6fec`
- `011689fc`: `ldr r2,[0x01168a20]` refs: `READ -> 01168a20`
- `011689fe`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `01168a00`: `add r2,pc` refs: `PARAM -> 014371d0`
- `01168a02`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168a06`: `movs r0,#0x30`
- `01168a08`: `blx 0x013fa790` refs: `UNCONDITIONAL_CALL -> 013fa790`
- `01168a0c`: `mov r8,r0`
- `01168a0e`: `add r0,sp,#0x174`
- `01168a10`: `ldr r1,[0x01168a24]` refs: `READ -> 01168a24`
- `01168a12`: `add r1,pc` refs: `PARAM -> 00b78ea6`
- `01168a14`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168a18`: `b 0x01168a28` refs: `UNCONDITIONAL_JUMP -> 01168a28`
- `01168a28`: `ldr r1,[0x01168a34]` refs: `READ -> 01168a34`
- `01168a2a`: `adds r0,#0xc`
- `01168a2c`: `add r1,pc` refs: `PARAM -> 00bcc871`
