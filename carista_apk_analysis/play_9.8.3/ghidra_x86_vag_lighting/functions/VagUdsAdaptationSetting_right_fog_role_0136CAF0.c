/* Target VagUdsAdaptationSetting_right_fog_role @ 0136caf0 (Ghidra 0137caf0) */
/* Reason: x86 right-side same-key helper using gateway/MEB-style guards */
/* Function: VagUdsAdaptationSetting_right_fog_role @ 0136caf0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0136caf0: PUSH EBP
 * 0136caf1: MOV EBP,ESP
 * 0136caf3: PUSH EBX
 * 0136caf4: PUSH EDI
 * 0136caf5: PUSH ESI
 * 0136caf6: SUB ESP,0x2c scalars: `0x2C`
 * 0136caf9: CALL 0x0137cafe refs: `UNCONDITIONAL_JUMP -> 0136cafe` `sym=LAB_0137cafe`
 * 0136cafe: POP EBX
 * 0136caff: ADD EBX,0x6c8b1a scalars: `0x6C8B1A`
 * 0136cb05: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136cb0c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136cb11: MOV EDI,EAX
 * 0136cb13: MOV ESI,EAX
 * 0136cb15: MOV EAX,dword ptr [EBP + 0x28] scalars: `0x28`
 * 0136cb18: MOV dword ptr [ESP + 0x1c],EAX scalars: `0x1C`
 * 0136cb1c: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0136cb1f: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0136cb23: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0136cb26: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0136cb2a: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136cb2e: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136cb33: MOV dword ptr [ESP],EDI
 * 0136cb36: CALL 0x0198e300 refs: `UNCONDITIONAL_CALL -> 0197e300` `sym=SUB_0198e300`
 * 0136cb3b: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136cb3e: ADD EDI,0xc scalars: `0xC`
 * 0136cb41: MOV dword ptr [EAX],EDI
 * 0136cb43: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136cb46: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136cb49: TEST EDX,EDX
 * 0136cb4b: JZ 0x0137cb71 refs: `CONDITIONAL_JUMP -> 0136cb71` `sym=LAB_0137cb71`
 * 0136cb4d: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136cb50: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136cb53: JNZ 0x0137cba1 refs: `CONDITIONAL_JUMP -> 0136cba1` `sym=LAB_0137cba1`
 * 0136cb55: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cb59: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cb5d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cb60: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cb63: MOV dword ptr [ESP],EDX
 * 0136cb66: MOV EDI,EAX
 * 0136cb68: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cb6d: MOV EAX,EDI
 * 0136cb6f: JMP 0x0137cb7f refs: `UNCONDITIONAL_JUMP -> 0136cb7f` `sym=LAB_0137cb7f`
 * 0136cb71: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cb75: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cb79: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cb7c: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cb7f: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136cb84: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136cb89: TEST ECX,ECX
 * 0136cb8b: JNZ 0x0137cba1 refs: `CONDITIONAL_JUMP -> 0136cba1` `sym=LAB_0137cba1`
 * 0136cb8d: MOV ECX,dword ptr [ESI]
 * 0136cb8f: MOV dword ptr [ESP],ESI
 * 0136cb92: MOV EDI,EAX
 * 0136cb94: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136cb97: MOV dword ptr [ESP],ESI
 * 0136cb9a: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cb9f: MOV EAX,EDI
 * 0136cba1: ADD ESP,0x2c scalars: `0x2C`
 * 0136cba4: POP ESI
 * 0136cba5: POP EDI
 * 0136cba6: POP EBX
 * 0136cba7: POP EBP
 * 0136cba8: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0136caf0: PUSH EBP
 * 0136caf1: MOV EBP,ESP
 * 0136caf3: PUSH EBX
 * 0136caf4: PUSH EDI
 * 0136caf5: PUSH ESI
 * 0136caf6: SUB ESP,0x2c scalars: `0x2C`
 * 0136caf9: CALL 0x0137cafe refs: `UNCONDITIONAL_JUMP -> 0136cafe` `sym=LAB_0137cafe`
 * 0136cafe: POP EBX
 * 0136caff: ADD EBX,0x6c8b1a scalars: `0x6C8B1A`
 * 0136cb05: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136cb0c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136cb11: MOV EDI,EAX
 * 0136cb13: MOV ESI,EAX
 * 0136cb15: MOV EAX,dword ptr [EBP + 0x28] scalars: `0x28`
 * 0136cb18: MOV dword ptr [ESP + 0x1c],EAX scalars: `0x1C`
 * 0136cb1c: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 0136cb1f: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0136cb23: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0136cb26: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 0136cb2a: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136cb2e: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136cb33: MOV dword ptr [ESP],EDI
 * 0136cb36: CALL 0x0198e300 refs: `UNCONDITIONAL_CALL -> 0197e300` `sym=SUB_0198e300`
 * 0136cb3b: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136cb3e: ADD EDI,0xc scalars: `0xC`
 * 0136cb41: MOV dword ptr [EAX],EDI
 * 0136cb43: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136cb46: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136cb49: TEST EDX,EDX
 * 0136cb4b: JZ 0x0137cb71 refs: `CONDITIONAL_JUMP -> 0136cb71` `sym=LAB_0137cb71`
 * 0136cb4d: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136cb50: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136cb53: JNZ 0x0137cba1 refs: `CONDITIONAL_JUMP -> 0136cba1` `sym=LAB_0137cba1`
 * 0136cb55: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cb59: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cb5d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cb60: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cb63: MOV dword ptr [ESP],EDX
 * 0136cb66: MOV EDI,EAX
 * 0136cb68: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cb6d: MOV EAX,EDI
 * 0136cb6f: JMP 0x0137cb7f refs: `UNCONDITIONAL_JUMP -> 0136cb7f` `sym=LAB_0137cb7f`
 * 0136cb71: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136cb75: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136cb79: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136cb7c: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136cb7f: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136cb84: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136cb89: TEST ECX,ECX
 * 0136cb8b: JNZ 0x0137cba1 refs: `CONDITIONAL_JUMP -> 0136cba1` `sym=LAB_0137cba1`
 * 0136cb8d: MOV ECX,dword ptr [ESI]
 * 0136cb8f: MOV dword ptr [ESP],ESI
 * 0136cb92: MOV EDI,EAX
 * 0136cb94: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136cb97: MOV dword ptr [ESP],ESI
 * 0136cb9a: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136cb9f: MOV EAX,EDI
 * 0136cba1: ADD ESP,0x2c scalars: `0x2C`
 * 0136cba4: POP ESI
 * 0136cba5: POP EDI
 * 0136cba6: POP EBX
 * 0136cba7: POP EBP
 * 0136cba8: RET 0x4 scalars: `0x4`
 */
