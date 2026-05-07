/* Target VagUdsAdaptationSetting_right_fog_role_mqb @ 01368690 (Ghidra 01378690) */
/* Reason: x86 right-side same-key helper using MQB/MK8-style guards */
/* Function: VagUdsAdaptationSetting_right_fog_role_mqb @ 01368690 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 01368690: PUSH EBP
 * 01368691: MOV EBP,ESP
 * 01368693: PUSH EBX
 * 01368694: PUSH EDI
 * 01368695: PUSH ESI
 * 01368696: SUB ESP,0x2c scalars: `0x2C`
 * 01368699: CALL 0x0137869e refs: `UNCONDITIONAL_JUMP -> 0136869e` `sym=LAB_0137869e`
 * 0136869e: POP EBX
 * 0136869f: ADD EBX,0x6ccf7a scalars: `0x6CCF7A`
 * 013686a5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 013686ac: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 013686b1: MOV EDI,EAX
 * 013686b3: MOV ESI,EAX
 * 013686b5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 013686b9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 013686be: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 013686c2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 013686c7: MOV dword ptr [ESP],EAX
 * 013686ca: CALL 0x0198e0a0 refs: `UNCONDITIONAL_CALL -> 0197e0a0` `sym=SUB_0198e0a0`
 * 013686cf: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 013686d2: ADD EDI,0xc scalars: `0xC`
 * 013686d5: MOV dword ptr [EAX],EDI
 * 013686d7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 013686da: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 013686dd: TEST EDX,EDX
 * 013686df: JZ 0x01378705 refs: `CONDITIONAL_JUMP -> 01368705` `sym=LAB_01378705`
 * 013686e1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 013686e4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 013686e7: JNZ 0x01378735 refs: `CONDITIONAL_JUMP -> 01368735` `sym=LAB_01378735`
 * 013686e9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 013686ed: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 013686f1: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 013686f4: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 013686f7: MOV dword ptr [ESP],EDX
 * 013686fa: MOV EDI,EAX
 * 013686fc: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01368701: MOV EAX,EDI
 * 01368703: JMP 0x01378713 refs: `UNCONDITIONAL_JUMP -> 01368713` `sym=LAB_01378713`
 * 01368705: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01368709: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136870d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01368710: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01368713: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01368718: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136871d: TEST ECX,ECX
 * 0136871f: JNZ 0x01378735 refs: `CONDITIONAL_JUMP -> 01368735` `sym=LAB_01378735`
 * 01368721: MOV ECX,dword ptr [ESI]
 * 01368723: MOV dword ptr [ESP],ESI
 * 01368726: MOV EDI,EAX
 * 01368728: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136872b: MOV dword ptr [ESP],ESI
 * 0136872e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01368733: MOV EAX,EDI
 * 01368735: ADD ESP,0x2c scalars: `0x2C`
 * 01368738: POP ESI
 * 01368739: POP EDI
 * 0136873a: POP EBX
 * 0136873b: POP EBP
 * 0136873c: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 01368690: PUSH EBP
 * 01368691: MOV EBP,ESP
 * 01368693: PUSH EBX
 * 01368694: PUSH EDI
 * 01368695: PUSH ESI
 * 01368696: SUB ESP,0x2c scalars: `0x2C`
 * 01368699: CALL 0x0137869e refs: `UNCONDITIONAL_JUMP -> 0136869e` `sym=LAB_0137869e`
 * 0136869e: POP EBX
 * 0136869f: ADD EBX,0x6ccf7a scalars: `0x6CCF7A`
 * 013686a5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 013686ac: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 013686b1: MOV EDI,EAX
 * 013686b3: MOV ESI,EAX
 * 013686b5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 013686b9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 013686be: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 013686c2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 013686c7: MOV dword ptr [ESP],EAX
 * 013686ca: CALL 0x0198e0a0 refs: `UNCONDITIONAL_CALL -> 0197e0a0` `sym=SUB_0198e0a0`
 * 013686cf: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 013686d2: ADD EDI,0xc scalars: `0xC`
 * 013686d5: MOV dword ptr [EAX],EDI
 * 013686d7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 013686da: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 013686dd: TEST EDX,EDX
 * 013686df: JZ 0x01378705 refs: `CONDITIONAL_JUMP -> 01368705` `sym=LAB_01378705`
 * 013686e1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 013686e4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 013686e7: JNZ 0x01378735 refs: `CONDITIONAL_JUMP -> 01368735` `sym=LAB_01378735`
 * 013686e9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 013686ed: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 013686f1: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 013686f4: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 013686f7: MOV dword ptr [ESP],EDX
 * 013686fa: MOV EDI,EAX
 * 013686fc: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01368701: MOV EAX,EDI
 * 01368703: JMP 0x01378713 refs: `UNCONDITIONAL_JUMP -> 01368713` `sym=LAB_01378713`
 * 01368705: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01368709: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136870d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01368710: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01368713: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01368718: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136871d: TEST ECX,ECX
 * 0136871f: JNZ 0x01378735 refs: `CONDITIONAL_JUMP -> 01368735` `sym=LAB_01378735`
 * 01368721: MOV ECX,dword ptr [ESI]
 * 01368723: MOV dword ptr [ESP],ESI
 * 01368726: MOV EDI,EAX
 * 01368728: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136872b: MOV dword ptr [ESP],ESI
 * 0136872e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01368733: MOV EAX,EDI
 * 01368735: ADD ESP,0x2c scalars: `0x2C`
 * 01368738: POP ESI
 * 01368739: POP EDI
 * 0136873a: POP EBX
 * 0136873b: POP EBP
 * 0136873c: RET 0x4 scalars: `0x4`
 */
