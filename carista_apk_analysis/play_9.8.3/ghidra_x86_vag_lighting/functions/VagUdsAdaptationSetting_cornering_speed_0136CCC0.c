/* Target VagUdsAdaptationSetting_cornering_speed @ 0136ccc0 (Ghidra 0137ccc0) */
/* Reason: D1D min/max activation-speed helper reached from MK7_ALL variants */
/* Function: VagUdsAdaptationSetting_cornering_speed @ 0136ccc0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0136ccc0: PUSH EBP
 * 0136ccc1: MOV EBP,ESP
 * 0136ccc3: PUSH EBX
 * 0136ccc4: PUSH EDI
 * 0136ccc5: PUSH ESI
 * 0136ccc6: SUB ESP,0x2c scalars: `0x2C`
 * 0136ccc9: CALL 0x0137ccce refs: `UNCONDITIONAL_JUMP -> 0136ccce` `sym=LAB_0137ccce`
 * 0136ccce: POP EBX
 * 0136cccf: ADD EBX,0x6c894a scalars: `0x6C894A`
 * 0136ccd5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136ccdc: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136cce1: MOV EDI,EAX
 * 0136cce3: MOV ESI,EAX
 * 0136cce5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136cce9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136ccee: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136ccf2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136ccf7: MOV dword ptr [ESP],EAX
 * 0136ccfa: CALL 0x0198e310 refs: `UNCONDITIONAL_CALL -> 0197e310` `sym=SUB_0198e310`
 * 0136ccff: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136cd02: ADD EDI,0xc scalars: `0xC`
 * 0136cd05: MOV dword ptr [EAX],EDI
 * 0136cd07: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136cd0a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136cd0d: TEST EDX,EDX
 * 0136cd0f: JZ 0x0137cd35 refs: `CONDITIONAL_JUMP -> 0136cd35` `sym=LAB_0137cd35`
 * 0136cd11: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136cd14: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136cd17: JNZ 0x0137cd65 refs: `CONDITIONAL_JUMP -> 0136cd65` `sym=LAB_0137cd65`
 * 0136cd19: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cd1d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cd21: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cd24: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cd27: MOV dword ptr [ESP],EDX
 * 0136cd2a: MOV EDI,EAX
 * 0136cd2c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cd31: MOV EAX,EDI
 * 0136cd33: JMP 0x0137cd43 refs: `UNCONDITIONAL_JUMP -> 0136cd43` `sym=LAB_0137cd43`
 * 0136cd35: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cd39: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cd3d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cd40: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cd43: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136cd48: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136cd4d: TEST ECX,ECX
 * 0136cd4f: JNZ 0x0137cd65 refs: `CONDITIONAL_JUMP -> 0136cd65` `sym=LAB_0137cd65`
 * 0136cd51: MOV ECX,dword ptr [ESI]
 * 0136cd53: MOV dword ptr [ESP],ESI
 * 0136cd56: MOV EDI,EAX
 * 0136cd58: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136cd5b: MOV dword ptr [ESP],ESI
 * 0136cd5e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cd63: MOV EAX,EDI
 * 0136cd65: ADD ESP,0x2c scalars: `0x2C`
 * 0136cd68: POP ESI
 * 0136cd69: POP EDI
 * 0136cd6a: POP EBX
 * 0136cd6b: POP EBP
 * 0136cd6c: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0136ccc0: PUSH EBP
 * 0136ccc1: MOV EBP,ESP
 * 0136ccc3: PUSH EBX
 * 0136ccc4: PUSH EDI
 * 0136ccc5: PUSH ESI
 * 0136ccc6: SUB ESP,0x2c scalars: `0x2C`
 * 0136ccc9: CALL 0x0137ccce refs: `UNCONDITIONAL_JUMP -> 0136ccce` `sym=LAB_0137ccce`
 * 0136ccce: POP EBX
 * 0136cccf: ADD EBX,0x6c894a scalars: `0x6C894A`
 * 0136ccd5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136ccdc: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136cce1: MOV EDI,EAX
 * 0136cce3: MOV ESI,EAX
 * 0136cce5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136cce9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136ccee: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136ccf2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136ccf7: MOV dword ptr [ESP],EAX
 * 0136ccfa: CALL 0x0198e310 refs: `UNCONDITIONAL_CALL -> 0197e310` `sym=SUB_0198e310`
 * 0136ccff: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136cd02: ADD EDI,0xc scalars: `0xC`
 * 0136cd05: MOV dword ptr [EAX],EDI
 * 0136cd07: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136cd0a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136cd0d: TEST EDX,EDX
 * 0136cd0f: JZ 0x0137cd35 refs: `CONDITIONAL_JUMP -> 0136cd35` `sym=LAB_0137cd35`
 * 0136cd11: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136cd14: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136cd17: JNZ 0x0137cd65 refs: `CONDITIONAL_JUMP -> 0136cd65` `sym=LAB_0137cd65`
 * 0136cd19: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cd1d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cd21: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cd24: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cd27: MOV dword ptr [ESP],EDX
 * 0136cd2a: MOV EDI,EAX
 * 0136cd2c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cd31: MOV EAX,EDI
 * 0136cd33: JMP 0x0137cd43 refs: `UNCONDITIONAL_JUMP -> 0136cd43` `sym=LAB_0137cd43`
 * 0136cd35: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cd39: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cd3d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cd40: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cd43: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136cd48: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136cd4d: TEST ECX,ECX
 * 0136cd4f: JNZ 0x0137cd65 refs: `CONDITIONAL_JUMP -> 0136cd65` `sym=LAB_0137cd65`
 * 0136cd51: MOV ECX,dword ptr [ESI]
 * 0136cd53: MOV dword ptr [ESP],ESI
 * 0136cd56: MOV EDI,EAX
 * 0136cd58: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136cd5b: MOV dword ptr [ESP],ESI
 * 0136cd5e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cd63: MOV EAX,EDI
 * 0136cd65: ADD ESP,0x2c scalars: `0x2C`
 * 0136cd68: POP ESI
 * 0136cd69: POP EDI
 * 0136cd6a: POP EBX
 * 0136cd6b: POP EBP
 * 0136cd6c: RET 0x4 scalars: `0x4`
 */
