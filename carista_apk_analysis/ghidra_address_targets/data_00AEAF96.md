# Data Target `00aeaf96`

## Symbols
- `Label` `s_6RU937089*_00aeaf96`

## Memory Bytes
`3652553933373038392a00355130393337303834414300355130393337303836414b003551303933373038365300355130393337303834444a00344830393037`

## Direct References To This Address
- `PARAM` from `01168560` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `01168560`: `add r1,pc`

## Local Instruction Windows
### Around `01168560`
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
- `01168560`: `add r1,pc` refs: `PARAM -> 00aeaf96`
- `01168562`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168566`: `b 0x0116856c` refs: `UNCONDITIONAL_JUMP -> 0116856c`
- `0116856c`: `add.w r5,r6,#0x24`
- `01168570`: `ldr r1,[0x0116857c]` refs: `READ -> 0116857c`
- `01168572`: `mov r0,r5`
