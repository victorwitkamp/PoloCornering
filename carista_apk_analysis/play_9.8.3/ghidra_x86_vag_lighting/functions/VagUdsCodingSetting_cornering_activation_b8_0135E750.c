/* Target VagUdsCodingSetting_cornering_activation_b8 @ 0135e750 (Ghidra 0136e750) */
/* Reason: D1D-adjacent B8 long-coding helper in the activation cluster */
/* Function: VagUdsCodingSetting_cornering_activation_b8 @ 0135e750 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0135e750: PUSH EBP
 * 0135e751: MOV EBP,ESP
 * 0135e753: PUSH EBX
 * 0135e754: PUSH EDI
 * 0135e755: PUSH ESI
 * 0135e756: SUB ESP,0x1c scalars: `0x1C`
 * 0135e759: CALL 0x0136e75e refs: `UNCONDITIONAL_JUMP -> 0135e75e` `sym=LAB_0136e75e`
 * 0135e75e: POP EBX
 * 0135e75f: ADD EBX,0x6d6eba scalars: `0x6D6EBA`
 * 0135e765: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135e76c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135e771: MOV EDI,EAX
 * 0135e773: MOV ESI,EAX
 * 0135e775: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135e778: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135e77c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135e77f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135e783: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135e787: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135e78c: MOV dword ptr [ESP],EDI
 * 0135e78f: CALL 0x0198db20 refs: `UNCONDITIONAL_CALL -> 0197db20` `sym=SUB_0198db20`
 * 0135e794: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135e797: ADD EDI,0xc scalars: `0xC`
 * 0135e79a: MOV dword ptr [EAX],EDI
 * 0135e79c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135e79f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135e7a2: TEST EDX,EDX
 * 0135e7a4: JZ 0x0136e7ca refs: `CONDITIONAL_JUMP -> 0135e7ca` `sym=LAB_0136e7ca`
 * 0135e7a6: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135e7a9: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135e7ac: JNZ 0x0136e7fa refs: `CONDITIONAL_JUMP -> 0135e7fa` `sym=LAB_0136e7fa`
 * 0135e7ae: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e7b2: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e7b6: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e7b9: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e7bc: MOV dword ptr [ESP],EDX
 * 0135e7bf: MOV EDI,EAX
 * 0135e7c1: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e7c6: MOV EAX,EDI
 * 0135e7c8: JMP 0x0136e7d8 refs: `UNCONDITIONAL_JUMP -> 0135e7d8` `sym=LAB_0136e7d8`
 * 0135e7ca: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e7ce: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e7d2: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e7d5: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e7d8: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135e7dd: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135e7e2: TEST ECX,ECX
 * 0135e7e4: JNZ 0x0136e7fa refs: `CONDITIONAL_JUMP -> 0135e7fa` `sym=LAB_0136e7fa`
 * 0135e7e6: MOV ECX,dword ptr [ESI]
 * 0135e7e8: MOV dword ptr [ESP],ESI
 * 0135e7eb: MOV EDI,EAX
 * 0135e7ed: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135e7f0: MOV dword ptr [ESP],ESI
 * 0135e7f3: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e7f8: MOV EAX,EDI
 * 0135e7fa: ADD ESP,0x1c scalars: `0x1C`
 * 0135e7fd: POP ESI
 * 0135e7fe: POP EDI
 * 0135e7ff: POP EBX
 * 0135e800: POP EBP
 * 0135e801: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0135e750: PUSH EBP
 * 0135e751: MOV EBP,ESP
 * 0135e753: PUSH EBX
 * 0135e754: PUSH EDI
 * 0135e755: PUSH ESI
 * 0135e756: SUB ESP,0x1c scalars: `0x1C`
 * 0135e759: CALL 0x0136e75e refs: `UNCONDITIONAL_JUMP -> 0135e75e` `sym=LAB_0136e75e`
 * 0135e75e: POP EBX
 * 0135e75f: ADD EBX,0x6d6eba scalars: `0x6D6EBA`
 * 0135e765: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135e76c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135e771: MOV EDI,EAX
 * 0135e773: MOV ESI,EAX
 * 0135e775: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135e778: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135e77c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135e77f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135e783: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135e787: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135e78c: MOV dword ptr [ESP],EDI
 * 0135e78f: CALL 0x0198db20 refs: `UNCONDITIONAL_CALL -> 0197db20` `sym=SUB_0198db20`
 * 0135e794: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135e797: ADD EDI,0xc scalars: `0xC`
 * 0135e79a: MOV dword ptr [EAX],EDI
 * 0135e79c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135e79f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135e7a2: TEST EDX,EDX
 * 0135e7a4: JZ 0x0136e7ca refs: `CONDITIONAL_JUMP -> 0135e7ca` `sym=LAB_0136e7ca`
 * 0135e7a6: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135e7a9: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135e7ac: JNZ 0x0136e7fa refs: `CONDITIONAL_JUMP -> 0135e7fa` `sym=LAB_0136e7fa`
 * 0135e7ae: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e7b2: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e7b6: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e7b9: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e7bc: MOV dword ptr [ESP],EDX
 * 0135e7bf: MOV EDI,EAX
 * 0135e7c1: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e7c6: MOV EAX,EDI
 * 0135e7c8: JMP 0x0136e7d8 refs: `UNCONDITIONAL_JUMP -> 0135e7d8` `sym=LAB_0136e7d8`
 * 0135e7ca: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e7ce: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e7d2: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e7d5: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e7d8: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135e7dd: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135e7e2: TEST ECX,ECX
 * 0135e7e4: JNZ 0x0136e7fa refs: `CONDITIONAL_JUMP -> 0135e7fa` `sym=LAB_0136e7fa`
 * 0135e7e6: MOV ECX,dword ptr [ESI]
 * 0135e7e8: MOV dword ptr [ESP],ESI
 * 0135e7eb: MOV EDI,EAX
 * 0135e7ed: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135e7f0: MOV dword ptr [ESP],ESI
 * 0135e7f3: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e7f8: MOV EAX,EDI
 * 0135e7fa: ADD ESP,0x1c scalars: `0x1C`
 * 0135e7fd: POP ESI
 * 0135e7fe: POP EDI
 * 0135e7ff: POP EBX
 * 0135e800: POP EBP
 * 0135e801: RET 0x4 scalars: `0x4`
 */
