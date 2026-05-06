# Data Target `014f6fcc`

## Symbols
- `Label` `VagWhitelists::CENTRAL_ELEC_5C`
- `Label` `_ZN13VagWhitelists15CENTRAL_ELEC_5CE`

## Memory Bytes
<unreadable: MemoryAccessException: Unable to read bytes at ram:014f6fcc>

## Direct References To This Address
- `EXTERNAL` from `Entry Point` in `<no function>`
- `DATA` from `014df248` in `<no function>`
- `PARAM` from `01168796` in `_INIT_138 @ 01156090`
- `PARAM` from `011687bc` in `_INIT_138 @ 01156090`
- `READ` from `01168900` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `01168796`: `mov r0,r9`
- `011687bc`: `mov r1,r9`
- `01168900`: `ldrd r1,r0,[r9,#0x0]`

## Local Instruction Windows
### Around `01168796`
- `01168736`: `mov r1,r8` refs: `PARAM -> 014f6fc4`
- `01168738`: `ldr r2,[0x0116875c]` refs: `READ -> 0116875c`
- `0116873a`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `0116873c`: `add r2,pc` refs: `PARAM -> 014371d0`
- `0116873e`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168742`: `movs r0,#0x30`
- `01168744`: `blx 0x013fa790` refs: `UNCONDITIONAL_CALL -> 013fa790`
- `01168748`: `mov r10,r0`
- `0116874a`: `add r0,sp,#0x174`
- `0116874c`: `ldr r1,[0x01168760]` refs: `READ -> 01168760`
- `0116874e`: `add r1,pc` refs: `PARAM -> 009a357f`
- `01168750`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168754`: `b 0x01168764` refs: `UNCONDITIONAL_JUMP -> 01168764`
- `01168764`: `ldr r1,[0x01168770]` refs: `READ -> 01168770`
- `01168766`: `adds r0,#0xc`
- `01168768`: `add r1,pc` refs: `PARAM -> 007463b0`
- `0116876a`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `0116876e`: `b 0x01168774` refs: `UNCONDITIONAL_JUMP -> 01168774`
- `01168774`: `add r0,sp,#0x48`
- `01168776`: `add r6,sp,#0x174`
- `01168778`: `movs r2,#0x2`
- `0116877a`: `mov r1,r6`
- `0116877c`: `bl 0x00d22d0c` refs: `UNCONDITIONAL_CALL -> 00d22d0c`
- `01168780`: `movs r5,#0x1`
- `01168782`: `add r1,sp,#0x48`
- `01168784`: `mov r0,r10`
- `01168786`: `blx 0x014086e0` refs: `UNCONDITIONAL_CALL -> 014086e0`
- `0116878a`: `movs r5,#0x0`
- `0116878c`: `ldr r0,[0x011687a0]` refs: `READ -> 011687a0`
- `0116878e`: `mov r1,r10`
- `01168790`: `add r0,pc`
- `01168792`: `ldr.w r9,[r0,#0x0]` refs: `READ -> 014df248`
- `01168796`: `mov r0,r9` refs: `PARAM -> 014f6fcc`
- `01168798`: `blx 0x0140be90` refs: `UNCONDITIONAL_CALL -> 0140be90`
- `0116879c`: `b 0x011687a4` refs: `UNCONDITIONAL_JUMP -> 011687a4`
- `011687a4`: `add r0,sp,#0x48`
- `011687a6`: `bl 0x00cbe2dc` refs: `UNCONDITIONAL_CALL -> 00cbe2dc`
- `011687aa`: `movs r4,#0xc`
### Around `011687bc`
- `01168754`: `b 0x01168764` refs: `UNCONDITIONAL_JUMP -> 01168764`
- `01168764`: `ldr r1,[0x01168770]` refs: `READ -> 01168770`
- `01168766`: `adds r0,#0xc`
- `01168768`: `add r1,pc` refs: `PARAM -> 007463b0`
- `0116876a`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `0116876e`: `b 0x01168774` refs: `UNCONDITIONAL_JUMP -> 01168774`
- `01168774`: `add r0,sp,#0x48`
- `01168776`: `add r6,sp,#0x174`
- `01168778`: `movs r2,#0x2`
- `0116877a`: `mov r1,r6`
- `0116877c`: `bl 0x00d22d0c` refs: `UNCONDITIONAL_CALL -> 00d22d0c`
- `01168780`: `movs r5,#0x1`
- `01168782`: `add r1,sp,#0x48`
- `01168784`: `mov r0,r10`
- `01168786`: `blx 0x014086e0` refs: `UNCONDITIONAL_CALL -> 014086e0`
- `0116878a`: `movs r5,#0x0`
- `0116878c`: `ldr r0,[0x011687a0]` refs: `READ -> 011687a0`
- `0116878e`: `mov r1,r10`
- `01168790`: `add r0,pc`
- `01168792`: `ldr.w r9,[r0,#0x0]` refs: `READ -> 014df248`
- `01168796`: `mov r0,r9` refs: `PARAM -> 014f6fcc`
- `01168798`: `blx 0x0140be90` refs: `UNCONDITIONAL_CALL -> 0140be90`
- `0116879c`: `b 0x011687a4` refs: `UNCONDITIONAL_JUMP -> 011687a4`
- `011687a4`: `add r0,sp,#0x48`
- `011687a6`: `bl 0x00cbe2dc` refs: `UNCONDITIONAL_CALL -> 00cbe2dc`
- `011687aa`: `movs r4,#0xc`
- `011687ac`: `adds r0,r6,r4`
- `011687ae`: `blx 0x013fa600` refs: `UNCONDITIONAL_CALL -> 013fa600`
- `011687b2`: `subs r4,#0xc`
- `011687b4`: `adds.w r0,r4,#0xc`
- `011687b8`: `bne 0x011687ac` refs: `CONDITIONAL_JUMP -> 011687ac`
- `011687ba`: `ldr r0,[0x011687dc]` refs: `READ -> 011687dc`
- `011687bc`: `mov r1,r9` refs: `PARAM -> 014f6fcc`
- `011687be`: `ldr r2,[0x011687e0]` refs: `READ -> 011687e0`
- `011687c0`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `011687c2`: `add r2,pc` refs: `PARAM -> 014371d0`
- `011687c4`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `011687c8`: `movs r0,#0x30`
### Around `01168900`
- `011688aa`: `b 0x011688b0` refs: `UNCONDITIONAL_JUMP -> 011688b0`
- `011688b0`: `add r0,sp,#0x48`
- `011688b2`: `add r5,sp,#0x174`
- `011688b4`: `movs r2,#0x4`
- `011688b6`: `mov r1,r5`
- `011688b8`: `bl 0x00d22d0c` refs: `UNCONDITIONAL_CALL -> 00d22d0c`
- `011688bc`: `movs r6,#0x1`
- `011688be`: `add r1,sp,#0x48`
- `011688c0`: `mov r0,r10`
- `011688c2`: `blx 0x014086e0` refs: `UNCONDITIONAL_CALL -> 014086e0`
- `011688c6`: `movs r6,#0x0`
- `011688c8`: `ldr r0,[0x011688d8]` refs: `READ -> 011688d8`
- `011688ca`: `mov r1,r10`
- `011688cc`: `add r0,pc`
- `011688ce`: `ldr r4,[r0,#0x0]` refs: `READ -> 014de6d0`
- `011688d0`: `mov r0,r4` refs: `PARAM -> 014f6fdc`
- `011688d2`: `blx 0x0140be90` refs: `UNCONDITIONAL_CALL -> 0140be90`
- `011688d6`: `b 0x011688dc` refs: `UNCONDITIONAL_JUMP -> 011688dc`
- `011688dc`: `add r0,sp,#0x48`
- `011688de`: `bl 0x00cbe2dc` refs: `UNCONDITIONAL_CALL -> 00cbe2dc`
- `011688e2`: `movs r6,#0x24`
- `011688e4`: `adds r0,r5,r6`
- `011688e6`: `blx 0x013fa600` refs: `UNCONDITIONAL_CALL -> 013fa600`
- `011688ea`: `subs r6,#0xc`
- `011688ec`: `adds.w r0,r6,#0xc`
- `011688f0`: `bne 0x011688e4` refs: `CONDITIONAL_JUMP -> 011688e4`
- `011688f2`: `ldr r0,[0x0116890c]` refs: `READ -> 0116890c`
- `011688f4`: `mov r1,r4` refs: `PARAM -> 014f6fdc`
- `011688f6`: `ldr r2,[0x01168910]` refs: `READ -> 01168910`
- `011688f8`: `add r0,pc` refs: `PARAM -> 00d5d495`
- `011688fa`: `add r2,pc` refs: `PARAM -> 014371d0`
- `011688fc`: `blx 0x013fa330` refs: `UNCONDITIONAL_CALL -> 013fa330`
- `01168900`: `ldrd r1,r0,[r9,#0x0]` refs: `READ -> 014f6fcc` `READ -> 014f6fd0`
- `01168904`: `strd r1,r0,[sp,#0x174]` refs: `WRITE -> Stack[-0xf14]`
- `01168908`: `cbz r0,0x01168924` refs: `CONDITIONAL_JUMP -> 01168924`
- `0116890a`: `b 0x01168914` refs: `UNCONDITIONAL_JUMP -> 01168914`
- `01168914`: `adds r0,#0x4`
- `01168916`: `ldrex r1,[r0,#0x0]`
