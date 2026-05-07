/* Target VagUdsAdaptationSetting_cornering_speed_mk7_new @ 0136cea0 (Ghidra 0137cea0) */
/* Reason: D1D min/max activation-speed helper reached from MK7_6C and MK7_NEW_MQBA0 variants */
/* Function: VagUdsAdaptationSetting_cornering_speed_mk7_new @ 0136cea0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0136cea0: PUSH EBP
 * 0136cea1: MOV EBP,ESP
 * 0136cea3: PUSH EBX
 * 0136cea4: PUSH EDI
 * 0136cea5: PUSH ESI
 * 0136cea6: SUB ESP,0x2c scalars: `0x2C`
 * 0136cea9: CALL 0x0137ceae refs: `UNCONDITIONAL_JUMP -> 0136ceae` `sym=LAB_0137ceae`
 * 0136ceae: POP EBX
 * 0136ceaf: ADD EBX,0x6c876a scalars: `0x6C876A`
 * 0136ceb5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136cebc: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136cec1: MOV EDI,EAX
 * 0136cec3: MOV ESI,EAX
 * 0136cec5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136cec9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136cece: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136ced2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136ced7: MOV dword ptr [ESP],EAX
 * 0136ceda: CALL 0x0198e320 refs: `UNCONDITIONAL_CALL -> 0197e320` `sym=SUB_0198e320`
 * 0136cedf: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136cee2: ADD EDI,0xc scalars: `0xC`
 * 0136cee5: MOV dword ptr [EAX],EDI
 * 0136cee7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136ceea: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136ceed: TEST EDX,EDX
 * 0136ceef: JZ 0x0137cf15 refs: `CONDITIONAL_JUMP -> 0136cf15` `sym=LAB_0137cf15`
 * 0136cef1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136cef4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136cef7: JNZ 0x0137cf45 refs: `CONDITIONAL_JUMP -> 0136cf45` `sym=LAB_0137cf45`
 * 0136cef9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cefd: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cf01: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cf04: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cf07: MOV dword ptr [ESP],EDX
 * 0136cf0a: MOV EDI,EAX
 * 0136cf0c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cf11: MOV EAX,EDI
 * 0136cf13: JMP 0x0137cf23 refs: `UNCONDITIONAL_JUMP -> 0136cf23` `sym=LAB_0137cf23`
 * 0136cf15: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cf19: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cf1d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cf20: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cf23: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136cf28: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136cf2d: TEST ECX,ECX
 * 0136cf2f: JNZ 0x0137cf45 refs: `CONDITIONAL_JUMP -> 0136cf45` `sym=LAB_0137cf45`
 * 0136cf31: MOV ECX,dword ptr [ESI]
 * 0136cf33: MOV dword ptr [ESP],ESI
 * 0136cf36: MOV EDI,EAX
 * 0136cf38: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136cf3b: MOV dword ptr [ESP],ESI
 * 0136cf3e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cf43: MOV EAX,EDI
 * 0136cf45: ADD ESP,0x2c scalars: `0x2C`
 * 0136cf48: POP ESI
 * 0136cf49: POP EDI
 * 0136cf4a: POP EBX
 * 0136cf4b: POP EBP
 * 0136cf4c: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0136cea0: PUSH EBP
 * 0136cea1: MOV EBP,ESP
 * 0136cea3: PUSH EBX
 * 0136cea4: PUSH EDI
 * 0136cea5: PUSH ESI
 * 0136cea6: SUB ESP,0x2c scalars: `0x2C`
 * 0136cea9: CALL 0x0137ceae refs: `UNCONDITIONAL_JUMP -> 0136ceae` `sym=LAB_0137ceae`
 * 0136ceae: POP EBX
 * 0136ceaf: ADD EBX,0x6c876a scalars: `0x6C876A`
 * 0136ceb5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136cebc: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136cec1: MOV EDI,EAX
 * 0136cec3: MOV ESI,EAX
 * 0136cec5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136cec9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136cece: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136ced2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136ced7: MOV dword ptr [ESP],EAX
 * 0136ceda: CALL 0x0198e320 refs: `UNCONDITIONAL_CALL -> 0197e320` `sym=SUB_0198e320`
 * 0136cedf: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136cee2: ADD EDI,0xc scalars: `0xC`
 * 0136cee5: MOV dword ptr [EAX],EDI
 * 0136cee7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136ceea: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136ceed: TEST EDX,EDX
 * 0136ceef: JZ 0x0137cf15 refs: `CONDITIONAL_JUMP -> 0136cf15` `sym=LAB_0137cf15`
 * 0136cef1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136cef4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136cef7: JNZ 0x0137cf45 refs: `CONDITIONAL_JUMP -> 0136cf45` `sym=LAB_0137cf45`
 * 0136cef9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cefd: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cf01: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cf04: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cf07: MOV dword ptr [ESP],EDX
 * 0136cf0a: MOV EDI,EAX
 * 0136cf0c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cf11: MOV EAX,EDI
 * 0136cf13: JMP 0x0137cf23 refs: `UNCONDITIONAL_JUMP -> 0136cf23` `sym=LAB_0137cf23`
 * 0136cf15: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cf19: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cf1d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cf20: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cf23: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136cf28: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136cf2d: TEST ECX,ECX
 * 0136cf2f: JNZ 0x0137cf45 refs: `CONDITIONAL_JUMP -> 0136cf45` `sym=LAB_0137cf45`
 * 0136cf31: MOV ECX,dword ptr [ESI]
 * 0136cf33: MOV dword ptr [ESP],ESI
 * 0136cf36: MOV EDI,EAX
 * 0136cf38: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136cf3b: MOV dword ptr [ESP],ESI
 * 0136cf3e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cf43: MOV EAX,EDI
 * 0136cf45: ADD ESP,0x2c scalars: `0x2C`
 * 0136cf48: POP ESI
 * 0136cf49: POP EDI
 * 0136cf4a: POP EBX
 * 0136cf4b: POP EBP
 * 0136cf4c: RET 0x4 scalars: `0x4`
 */
