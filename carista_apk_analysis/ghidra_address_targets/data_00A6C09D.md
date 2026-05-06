# Data Target `00a6c09d`

## Symbols
- `Label` `s_7E093708*_00a6c09d`

## Memory Bytes
`37453039333730382a00355130393337303834415100355130393337303834434b00355130393337303835414800355130393337303836414500355130393337`

## Direct References To This Address
- `PARAM` from `0116885c` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `0116885c`: `add r1,pc`

## Local Instruction Windows
### Around `0116885c`
- `01168804`: `bl 0x00d22d0c` refs: `UNCONDITIONAL_CALL -> 00d22d0c`
- `01168808`: `movs r6,#0x1`
- `0116880a`: `add r1,sp,#0x48`
- `0116880c`: `mov r0,r10`
- `0116880e`: `blx 0x014086e0` refs: `UNCONDITIONAL_CALL -> 014086e0`
- `01168812`: `movs r6,#0x0`
- `01168814`: `ldr r0,[0x01168828]` refs: `READ -> 01168828`
- `01168816`: `mov r1,r10`
- `01168818`: `add r0,pc`
- `0116881a`: `ldr.w r11,[r0,#0x0]` refs: `READ -> 014de768`
- `0116881e`: `mov r0,r11` refs: `PARAM -> 014f6fd4`
- `01168820`: `blx 0x0140be90` refs: `UNCONDITIONAL_CALL -> 0140be90`
- `01168824`: `b 0x0116882c` refs: `UNCONDITIONAL_JUMP -> 0116882c`
- `0116882c`: `add r0,sp,#0x48`
- `0116882e`: `bl 0x00cbe2dc` refs: `UNCONDITIONAL_CALL -> 00cbe2dc`
- `01168832`: `movs r4,#0xc`
- `01168834`: `adds r0,r5,r4`
- `01168836`: `blx 0x013fa600` refs: `UNCONDITIONAL_CALL -> 013fa600`
- `0116883a`: `subs r4,#0xc`
- `0116883c`: `adds.w r0,r4,#0xc`
- `01168840`: `bne 0x01168834` refs: `CONDITIONAL_JUMP -> 01168834`
- `01168842`: `ldr r0,[0x01168868]` refs: `READ -> 01168868`
- `01168844`: `mov r1,r11` refs: `PARAM -> 014f6fd4`
- `01168846`: `ldr r2,[0x0116886c]` refs: `READ -> 0116886c`
- `01168848`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `0116884a`: `add r2,pc` refs: `PARAM -> 014371d0`
- `0116884c`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168850`: `movs r0,#0x30`
- `01168852`: `blx 0x013fa790` refs: `UNCONDITIONAL_CALL -> 013fa790`
- `01168856`: `mov r10,r0`
- `01168858`: `add r4,sp,#0x174`
- `0116885a`: `ldr r1,[0x01168870]` refs: `READ -> 01168870`
- `0116885c`: `add r1,pc` refs: `PARAM -> 00a6c09d`
- `0116885e`: `mov r0,r4`
- `01168860`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168864`: `b 0x01168874` refs: `UNCONDITIONAL_JUMP -> 01168874`
- `01168874`: `add.w r5,r4,#0xc`
- `01168878`: `ldr r1,[0x01168884]` refs: `READ -> 01168884`
