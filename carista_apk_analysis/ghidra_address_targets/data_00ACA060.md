# Data Target `00aca060`

## Symbols
- `Label` `s_6R793708*_00aca060`

## Memory Bytes
`36523739333730382a00355130393337303835500035513039333730383651003557413933373038362a003856313935353131392a003856323935353131392a`

## Direct References To This Address
- `PARAM` from `0116866c` in `_INIT_138 @ 01156090`

## Instructions At Direct Reference Sites
- `0116866c`: `add r1,pc`

## Local Instruction Windows
### Around `0116866c`
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
- `0116866e`: `bl 0x00cb4d44` refs: `UNCONDITIONAL_CALL -> 00cb4d44`
- `01168672`: `b 0x01168678` refs: `UNCONDITIONAL_JUMP -> 01168678`
- `01168678`: `add r0,sp,#0x48`
- `0116867a`: `add r6,sp,#0x174`
- `0116867c`: `movs r2,#0x2`
