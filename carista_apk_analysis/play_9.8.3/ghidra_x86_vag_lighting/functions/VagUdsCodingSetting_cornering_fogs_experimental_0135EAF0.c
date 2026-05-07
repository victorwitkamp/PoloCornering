/* Target VagUdsCodingSetting_cornering_fogs_experimental @ 0135eaf0 (Ghidra 0136eaf0) */
/* Reason: callee reached by car_setting_cornering_lights_via_fogs_experimental 6R/PQ25 branch */
/* Function: VagUdsCodingSetting_cornering_fogs_experimental @ 0135eaf0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0135eaf0: PUSH EBP
 * 0135eaf1: MOV EBP,ESP
 * 0135eaf3: PUSH EBX
 * 0135eaf4: PUSH EDI
 * 0135eaf5: PUSH ESI
 * 0135eaf6: SUB ESP,0x1c scalars: `0x1C`
 * 0135eaf9: CALL 0x0136eafe refs: `UNCONDITIONAL_JUMP -> 0135eafe` `sym=LAB_0136eafe`
 * 0135eafe: POP EBX
 * 0135eaff: ADD EBX,0x6d6b1a scalars: `0x6D6B1A`
 * 0135eb05: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135eb0c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135eb11: MOV EDI,EAX
 * 0135eb13: MOV ESI,EAX
 * 0135eb15: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135eb18: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135eb1c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135eb1f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135eb23: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135eb27: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135eb2c: MOV dword ptr [ESP],EDI
 * 0135eb2f: CALL 0x0198db40 refs: `UNCONDITIONAL_CALL -> 0197db40` `sym=SUB_0198db40`
 * 0135eb34: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135eb37: ADD EDI,0xc scalars: `0xC`
 * 0135eb3a: MOV dword ptr [EAX],EDI
 * 0135eb3c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135eb3f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135eb42: TEST EDX,EDX
 * 0135eb44: JZ 0x0136eb6a refs: `CONDITIONAL_JUMP -> 0135eb6a` `sym=LAB_0136eb6a`
 * 0135eb46: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135eb49: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135eb4c: JNZ 0x0136eb9a refs: `CONDITIONAL_JUMP -> 0135eb9a` `sym=LAB_0136eb9a`
 * 0135eb4e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135eb52: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135eb56: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135eb59: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135eb5c: MOV dword ptr [ESP],EDX
 * 0135eb5f: MOV EDI,EAX
 * 0135eb61: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135eb66: MOV EAX,EDI
 * 0135eb68: JMP 0x0136eb78 refs: `UNCONDITIONAL_JUMP -> 0135eb78` `sym=LAB_0136eb78`
 * 0135eb6a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135eb6e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135eb72: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135eb75: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135eb78: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135eb7d: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135eb82: TEST ECX,ECX
 * 0135eb84: JNZ 0x0136eb9a refs: `CONDITIONAL_JUMP -> 0135eb9a` `sym=LAB_0136eb9a`
 * 0135eb86: MOV ECX,dword ptr [ESI]
 * 0135eb88: MOV dword ptr [ESP],ESI
 * 0135eb8b: MOV EDI,EAX
 * 0135eb8d: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135eb90: MOV dword ptr [ESP],ESI
 * 0135eb93: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135eb98: MOV EAX,EDI
 * 0135eb9a: ADD ESP,0x1c scalars: `0x1C`
 * 0135eb9d: POP ESI
 * 0135eb9e: POP EDI
 * 0135eb9f: POP EBX
 * 0135eba0: POP EBP
 * 0135eba1: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0135eaf0: PUSH EBP
 * 0135eaf1: MOV EBP,ESP
 * 0135eaf3: PUSH EBX
 * 0135eaf4: PUSH EDI
 * 0135eaf5: PUSH ESI
 * 0135eaf6: SUB ESP,0x1c scalars: `0x1C`
 * 0135eaf9: CALL 0x0136eafe refs: `UNCONDITIONAL_JUMP -> 0135eafe` `sym=LAB_0136eafe`
 * 0135eafe: POP EBX
 * 0135eaff: ADD EBX,0x6d6b1a scalars: `0x6D6B1A`
 * 0135eb05: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135eb0c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135eb11: MOV EDI,EAX
 * 0135eb13: MOV ESI,EAX
 * 0135eb15: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135eb18: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135eb1c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135eb1f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135eb23: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135eb27: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135eb2c: MOV dword ptr [ESP],EDI
 * 0135eb2f: CALL 0x0198db40 refs: `UNCONDITIONAL_CALL -> 0197db40` `sym=SUB_0198db40`
 * 0135eb34: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135eb37: ADD EDI,0xc scalars: `0xC`
 * 0135eb3a: MOV dword ptr [EAX],EDI
 * 0135eb3c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135eb3f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135eb42: TEST EDX,EDX
 * 0135eb44: JZ 0x0136eb6a refs: `CONDITIONAL_JUMP -> 0135eb6a` `sym=LAB_0136eb6a`
 * 0135eb46: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135eb49: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135eb4c: JNZ 0x0136eb9a refs: `CONDITIONAL_JUMP -> 0135eb9a` `sym=LAB_0136eb9a`
 * 0135eb4e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135eb52: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135eb56: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135eb59: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135eb5c: MOV dword ptr [ESP],EDX
 * 0135eb5f: MOV EDI,EAX
 * 0135eb61: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135eb66: MOV EAX,EDI
 * 0135eb68: JMP 0x0136eb78 refs: `UNCONDITIONAL_JUMP -> 0135eb78` `sym=LAB_0136eb78`
 * 0135eb6a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135eb6e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135eb72: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135eb75: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135eb78: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135eb7d: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135eb82: TEST ECX,ECX
 * 0135eb84: JNZ 0x0136eb9a refs: `CONDITIONAL_JUMP -> 0135eb9a` `sym=LAB_0136eb9a`
 * 0135eb86: MOV ECX,dword ptr [ESI]
 * 0135eb88: MOV dword ptr [ESP],ESI
 * 0135eb8b: MOV EDI,EAX
 * 0135eb8d: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135eb90: MOV dword ptr [ESP],ESI
 * 0135eb93: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135eb98: MOV EAX,EDI
 * 0135eb9a: ADD ESP,0x1c scalars: `0x1C`
 * 0135eb9d: POP ESI
 * 0135eb9e: POP EDI
 * 0135eb9f: POP EBX
 * 0135eba0: POP EBP
 * 0135eba1: RET 0x4 scalars: `0x4`
 */
