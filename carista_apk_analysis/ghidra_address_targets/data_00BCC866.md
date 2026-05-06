# Data Target `00bcc866`

## Symbols
- `Label` `s_6RU937088*_00bcc866`

## Memory Bytes
`3652553933373038382a00314b303930373533322a00355130393337303834414800355130393337303834450035513039333730383541430035513039333730`

## Direct References To This Address
- `PARAM` from `0116854c` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `0116854c`: `add r1,pc`

## Local Instruction Windows
### Around `0116854c`
- `011684e6`: `mov r1,r8`
- `011684e8`: `add r0,pc`
- `011684ea`: `ldr.w r9,[r0,#0x0]` refs: `READ -> 014de8b4`
- `011684ee`: `mov r0,r9` refs: `PARAM -> 014f6fa4`
- `011684f0`: `blx 0x0140be90` refs: `UNCONDITIONAL_CALL -> 0140be90`
- `011684f4`: `b 0x011684fc` refs: `UNCONDITIONAL_JUMP -> 011684fc`
- `011684fc`: `add r0,sp,#0x48`
- `011684fe`: `bl 0x00cbe2dc` refs: `UNCONDITIONAL_CALL -> 00cbe2dc`
- `01168502`: `movs r4,#0x18`
- `01168504`: `adds r0,r6,r4`
- `01168506`: `blx 0x013fa600` refs: `UNCONDITIONAL_CALL -> 013fa600`
- `0116850a`: `subs r4,#0xc`
- `0116850c`: `adds.w r0,r4,#0xc`
- `01168510`: `bne 0x01168504` refs: `CONDITIONAL_JUMP -> 01168504`
- `01168512`: `ldr r0,[0x01168538]` refs: `READ -> 01168538`
- `01168514`: `mov r1,r9` refs: `PARAM -> 014f6fa4`
- `01168516`: `ldr r2,[0x0116853c]` refs: `READ -> 0116853c`
- `01168518`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `0116851a`: `add r2,pc` refs: `PARAM -> 014371d0`
- `0116851c`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168520`: `movs r0,#0x30`
- `01168522`: `blx 0x013fa790` refs: `UNCONDITIONAL_CALL -> 013fa790`
- `01168526`: `mov r8,r0`
- `01168528`: `add r6,sp,#0x174`
- `0116852a`: `ldr r1,[0x01168540]` refs: `READ -> 01168540`
- `0116852c`: `add r1,pc` refs: `PARAM -> 00845f5b`
- `0116852e`: `mov r0,r6`
- `01168530`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168534`: `b 0x01168544` refs: `UNCONDITIONAL_JUMP -> 01168544`
- `01168544`: `add.w r5,r6,#0xc`
- `01168548`: `ldr r1,[0x01168554]` refs: `READ -> 01168554`
- `0116854a`: `mov r0,r5`
- `0116854c`: `add r1,pc` refs: `PARAM -> 00bcc866`
- `0116854e`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168552`: `b 0x01168558` refs: `UNCONDITIONAL_JUMP -> 01168558`
- `01168558`: `add.w r5,r6,#0x18`
- `0116855c`: `ldr r1,[0x01168568]` refs: `READ -> 01168568`
- `0116855e`: `mov r0,r5`
