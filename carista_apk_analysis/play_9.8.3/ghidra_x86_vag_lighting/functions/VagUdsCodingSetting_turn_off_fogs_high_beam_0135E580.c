/* Target VagUdsCodingSetting_turn_off_fogs_high_beam @ 0135e580 (Ghidra 0136e580) */
/* Reason: callee reached by car_setting_turn_off_fogs_with_high_beam 6R/PQ25 branch */
/* Function: VagUdsCodingSetting_turn_off_fogs_high_beam @ 0135e580 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0135e580: PUSH EBP
 * 0135e581: MOV EBP,ESP
 * 0135e583: PUSH EBX
 * 0135e584: PUSH EDI
 * 0135e585: PUSH ESI
 * 0135e586: SUB ESP,0x1c scalars: `0x1C`
 * 0135e589: CALL 0x0136e58e refs: `UNCONDITIONAL_JUMP -> 0135e58e` `sym=LAB_0136e58e`
 * 0135e58e: POP EBX
 * 0135e58f: ADD EBX,0x6d708a scalars: `0x6D708A`
 * 0135e595: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135e59c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135e5a1: MOV EDI,EAX
 * 0135e5a3: MOV ESI,EAX
 * 0135e5a5: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135e5a8: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135e5ac: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135e5af: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135e5b3: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135e5b7: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135e5bc: MOV dword ptr [ESP],EDI
 * 0135e5bf: CALL 0x0198db10 refs: `UNCONDITIONAL_CALL -> 0197db10` `sym=SUB_0198db10`
 * 0135e5c4: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135e5c7: ADD EDI,0xc scalars: `0xC`
 * 0135e5ca: MOV dword ptr [EAX],EDI
 * 0135e5cc: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135e5cf: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135e5d2: TEST EDX,EDX
 * 0135e5d4: JZ 0x0136e5fa refs: `CONDITIONAL_JUMP -> 0135e5fa` `sym=LAB_0136e5fa`
 * 0135e5d6: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135e5d9: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135e5dc: JNZ 0x0136e62a refs: `CONDITIONAL_JUMP -> 0135e62a` `sym=LAB_0136e62a`
 * 0135e5de: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e5e2: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e5e6: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e5e9: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e5ec: MOV dword ptr [ESP],EDX
 * 0135e5ef: MOV EDI,EAX
 * 0135e5f1: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e5f6: MOV EAX,EDI
 * 0135e5f8: JMP 0x0136e608 refs: `UNCONDITIONAL_JUMP -> 0135e608` `sym=LAB_0136e608`
 * 0135e5fa: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e5fe: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e602: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e605: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e608: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135e60d: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135e612: TEST ECX,ECX
 * 0135e614: JNZ 0x0136e62a refs: `CONDITIONAL_JUMP -> 0135e62a` `sym=LAB_0136e62a`
 * 0135e616: MOV ECX,dword ptr [ESI]
 * 0135e618: MOV dword ptr [ESP],ESI
 * 0135e61b: MOV EDI,EAX
 * 0135e61d: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135e620: MOV dword ptr [ESP],ESI
 * 0135e623: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e628: MOV EAX,EDI
 * 0135e62a: ADD ESP,0x1c scalars: `0x1C`
 * 0135e62d: POP ESI
 * 0135e62e: POP EDI
 * 0135e62f: POP EBX
 * 0135e630: POP EBP
 * 0135e631: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0135e580: PUSH EBP
 * 0135e581: MOV EBP,ESP
 * 0135e583: PUSH EBX
 * 0135e584: PUSH EDI
 * 0135e585: PUSH ESI
 * 0135e586: SUB ESP,0x1c scalars: `0x1C`
 * 0135e589: CALL 0x0136e58e refs: `UNCONDITIONAL_JUMP -> 0135e58e` `sym=LAB_0136e58e`
 * 0135e58e: POP EBX
 * 0135e58f: ADD EBX,0x6d708a scalars: `0x6D708A`
 * 0135e595: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0135e59c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0135e5a1: MOV EDI,EAX
 * 0135e5a3: MOV ESI,EAX
 * 0135e5a5: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0135e5a8: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0135e5ac: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0135e5af: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0135e5b3: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0135e5b7: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135e5bc: MOV dword ptr [ESP],EDI
 * 0135e5bf: CALL 0x0198db10 refs: `UNCONDITIONAL_CALL -> 0197db10` `sym=SUB_0198db10`
 * 0135e5c4: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0135e5c7: ADD EDI,0xc scalars: `0xC`
 * 0135e5ca: MOV dword ptr [EAX],EDI
 * 0135e5cc: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135e5cf: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0135e5d2: TEST EDX,EDX
 * 0135e5d4: JZ 0x0136e5fa refs: `CONDITIONAL_JUMP -> 0135e5fa` `sym=LAB_0136e5fa`
 * 0135e5d6: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0135e5d9: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135e5dc: JNZ 0x0136e62a refs: `CONDITIONAL_JUMP -> 0135e62a` `sym=LAB_0136e62a`
 * 0135e5de: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e5e2: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e5e6: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e5e9: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e5ec: MOV dword ptr [ESP],EDX
 * 0135e5ef: MOV EDI,EAX
 * 0135e5f1: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e5f6: MOV EAX,EDI
 * 0135e5f8: JMP 0x0136e608 refs: `UNCONDITIONAL_JUMP -> 0135e608` `sym=LAB_0136e608`
 * 0135e5fa: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135e5fe: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135e602: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135e605: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135e608: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135e60d: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135e612: TEST ECX,ECX
 * 0135e614: JNZ 0x0136e62a refs: `CONDITIONAL_JUMP -> 0135e62a` `sym=LAB_0136e62a`
 * 0135e616: MOV ECX,dword ptr [ESI]
 * 0135e618: MOV dword ptr [ESP],ESI
 * 0135e61b: MOV EDI,EAX
 * 0135e61d: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135e620: MOV dword ptr [ESP],ESI
 * 0135e623: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135e628: MOV EAX,EDI
 * 0135e62a: ADD ESP,0x1c scalars: `0x1C`
 * 0135e62d: POP ESI
 * 0135e62e: POP EDI
 * 0135e62f: POP EBX
 * 0135e630: POP EBP
 * 0135e631: RET 0x4 scalars: `0x4`
 */
