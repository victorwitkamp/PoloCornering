/* Target VagUdsCodingSetting_cornering_turn_signals @ 0135e920 (Ghidra 0136e920) */
/* Reason: callee reached by car_setting_cornering_lights_with_turn_signals 6R/PQ25 branch */
/* Function: VagUdsCodingSetting_cornering_turn_signals @ 0135e920 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0135e920: PUSH EBP
 * 0135e921: MOV EBP,ESP
 * 0135e923: PUSH EBX
 * 0135e924: PUSH EDI
 * 0135e925: PUSH ESI
 * 0135e926: SUB ESP,0x1c scalars: `0x1C`
 * 0135e929: CALL 0x0136e92e refs: `UNCONDITIONAL_JUMP -> 0135e92e` `sym=LAB_0136e92e`
 * 0135e92e: POP EBX
 * 0135e92f: ADD EBX,0x6d6cea scalars: `0x6D6CEA`
 * 0135e935: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135e93c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135e941: MOV EDI,EAX
 * 0135e943: MOV ESI,EAX
 * 0135e945: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135e948: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135e94c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135e94f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135e953: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135e957: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135e95c: MOV dword ptr [ESP],EDI
 * 0135e95f: CALL 0x0198db30 refs: `UNCONDITIONAL_CALL -> 0197db30` `sym=SUB_0198db30`
 * 0135e964: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135e967: ADD EDI,0xc scalars: `0xC`
 * 0135e96a: MOV dword ptr [EAX],EDI
 * 0135e96c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135e96f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135e972: TEST EDX,EDX
 * 0135e974: JZ 0x0136e99a refs: `CONDITIONAL_JUMP -> 0135e99a` `sym=LAB_0136e99a`
 * 0135e976: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135e979: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135e97c: JNZ 0x0136e9ca refs: `CONDITIONAL_JUMP -> 0135e9ca` `sym=LAB_0136e9ca`
 * 0135e97e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e982: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e986: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e989: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e98c: MOV dword ptr [ESP],EDX
 * 0135e98f: MOV EDI,EAX
 * 0135e991: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e996: MOV EAX,EDI
 * 0135e998: JMP 0x0136e9a8 refs: `UNCONDITIONAL_JUMP -> 0135e9a8` `sym=LAB_0136e9a8`
 * 0135e99a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e99e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e9a2: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e9a5: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e9a8: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135e9ad: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135e9b2: TEST ECX,ECX
 * 0135e9b4: JNZ 0x0136e9ca refs: `CONDITIONAL_JUMP -> 0135e9ca` `sym=LAB_0136e9ca`
 * 0135e9b6: MOV ECX,dword ptr [ESI]
 * 0135e9b8: MOV dword ptr [ESP],ESI
 * 0135e9bb: MOV EDI,EAX
 * 0135e9bd: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135e9c0: MOV dword ptr [ESP],ESI
 * 0135e9c3: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e9c8: MOV EAX,EDI
 * 0135e9ca: ADD ESP,0x1c scalars: `0x1C`
 * 0135e9cd: POP ESI
 * 0135e9ce: POP EDI
 * 0135e9cf: POP EBX
 * 0135e9d0: POP EBP
 * 0135e9d1: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0135e920: PUSH EBP
 * 0135e921: MOV EBP,ESP
 * 0135e923: PUSH EBX
 * 0135e924: PUSH EDI
 * 0135e925: PUSH ESI
 * 0135e926: SUB ESP,0x1c scalars: `0x1C`
 * 0135e929: CALL 0x0136e92e refs: `UNCONDITIONAL_JUMP -> 0135e92e` `sym=LAB_0136e92e`
 * 0135e92e: POP EBX
 * 0135e92f: ADD EBX,0x6d6cea scalars: `0x6D6CEA`
 * 0135e935: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135e93c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135e941: MOV EDI,EAX
 * 0135e943: MOV ESI,EAX
 * 0135e945: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135e948: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135e94c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135e94f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135e953: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135e957: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135e95c: MOV dword ptr [ESP],EDI
 * 0135e95f: CALL 0x0198db30 refs: `UNCONDITIONAL_CALL -> 0197db30` `sym=SUB_0198db30`
 * 0135e964: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135e967: ADD EDI,0xc scalars: `0xC`
 * 0135e96a: MOV dword ptr [EAX],EDI
 * 0135e96c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135e96f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135e972: TEST EDX,EDX
 * 0135e974: JZ 0x0136e99a refs: `CONDITIONAL_JUMP -> 0135e99a` `sym=LAB_0136e99a`
 * 0135e976: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135e979: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135e97c: JNZ 0x0136e9ca refs: `CONDITIONAL_JUMP -> 0135e9ca` `sym=LAB_0136e9ca`
 * 0135e97e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e982: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e986: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e989: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e98c: MOV dword ptr [ESP],EDX
 * 0135e98f: MOV EDI,EAX
 * 0135e991: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e996: MOV EAX,EDI
 * 0135e998: JMP 0x0136e9a8 refs: `UNCONDITIONAL_JUMP -> 0135e9a8` `sym=LAB_0136e9a8`
 * 0135e99a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e99e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e9a2: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e9a5: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e9a8: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135e9ad: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135e9b2: TEST ECX,ECX
 * 0135e9b4: JNZ 0x0136e9ca refs: `CONDITIONAL_JUMP -> 0135e9ca` `sym=LAB_0136e9ca`
 * 0135e9b6: MOV ECX,dword ptr [ESI]
 * 0135e9b8: MOV dword ptr [ESP],ESI
 * 0135e9bb: MOV EDI,EAX
 * 0135e9bd: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135e9c0: MOV dword ptr [ESP],ESI
 * 0135e9c3: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e9c8: MOV EAX,EDI
 * 0135e9ca: ADD ESP,0x1c scalars: `0x1C`
 * 0135e9cd: POP ESI
 * 0135e9ce: POP EDI
 * 0135e9cf: POP EBX
 * 0135e9d0: POP EBP
 * 0135e9d1: RET 0x4 scalars: `0x4`
 */
