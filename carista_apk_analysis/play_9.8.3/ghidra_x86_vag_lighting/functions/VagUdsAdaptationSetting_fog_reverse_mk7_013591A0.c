/* Target VagUdsAdaptationSetting_fog_reverse_mk7 @ 013591a0 (Ghidra 013691a0) */
/* Reason: D1D fog-on-reverse helper reached from MK7/gateway variants */
/* Function: VagUdsAdaptationSetting_fog_reverse_mk7 @ 013591a0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 013591a0: PUSH EBP
 * 013591a1: MOV EBP,ESP
 * 013591a3: PUSH EBX
 * 013591a4: PUSH EDI
 * 013591a5: PUSH ESI
 * 013591a6: SUB ESP,0x2c scalars: `0x2C`
 * 013591a9: CALL 0x013691ae refs: `UNCONDITIONAL_JUMP -> 013591ae` `sym=LAB_013691ae`
 * 013591ae: POP EBX
 * 013591af: ADD EBX,0x6dc46a scalars: `0x6DC46A`
 * 013591b5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 013591bc: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 013591c1: MOV EDI,EAX
 * 013591c3: MOV ESI,EAX
 * 013591c5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 013591c9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 013591ce: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 013591d2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 013591d7: MOV dword ptr [ESP],EAX
 * 013591da: CALL 0x0198d820 refs: `UNCONDITIONAL_CALL -> 0197d820` `sym=SUB_0198d820`
 * 013591df: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 013591e2: ADD EDI,0xc scalars: `0xC`
 * 013591e5: MOV dword ptr [EAX],EDI
 * 013591e7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 013591ea: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 013591ed: TEST EDX,EDX
 * 013591ef: JZ 0x01369215 refs: `CONDITIONAL_JUMP -> 01359215` `sym=LAB_01369215`
 * 013591f1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 013591f4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 013591f7: JNZ 0x01369245 refs: `CONDITIONAL_JUMP -> 01359245` `sym=LAB_01369245`
 * 013591f9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 013591fd: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01359201: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359204: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01359207: MOV dword ptr [ESP],EDX
 * 0135920a: MOV EDI,EAX
 * 0135920c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359211: MOV EAX,EDI
 * 01359213: JMP 0x01369223 refs: `UNCONDITIONAL_JUMP -> 01359223` `sym=LAB_01369223`
 * 01359215: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01359219: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135921d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359220: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01359223: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01359228: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135922d: TEST ECX,ECX
 * 0135922f: JNZ 0x01369245 refs: `CONDITIONAL_JUMP -> 01359245` `sym=LAB_01369245`
 * 01359231: MOV ECX,dword ptr [ESI]
 * 01359233: MOV dword ptr [ESP],ESI
 * 01359236: MOV EDI,EAX
 * 01359238: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135923b: MOV dword ptr [ESP],ESI
 * 0135923e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359243: MOV EAX,EDI
 * 01359245: ADD ESP,0x2c scalars: `0x2C`
 * 01359248: POP ESI
 * 01359249: POP EDI
 * 0135924a: POP EBX
 * 0135924b: POP EBP
 * 0135924c: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 013591a0: PUSH EBP
 * 013591a1: MOV EBP,ESP
 * 013591a3: PUSH EBX
 * 013591a4: PUSH EDI
 * 013591a5: PUSH ESI
 * 013591a6: SUB ESP,0x2c scalars: `0x2C`
 * 013591a9: CALL 0x013691ae refs: `UNCONDITIONAL_JUMP -> 013591ae` `sym=LAB_013691ae`
 * 013591ae: POP EBX
 * 013591af: ADD EBX,0x6dc46a scalars: `0x6DC46A`
 * 013591b5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 013591bc: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 013591c1: MOV EDI,EAX
 * 013591c3: MOV ESI,EAX
 * 013591c5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 013591c9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 013591ce: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 013591d2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 013591d7: MOV dword ptr [ESP],EAX
 * 013591da: CALL 0x0198d820 refs: `UNCONDITIONAL_CALL -> 0197d820` `sym=SUB_0198d820`
 * 013591df: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 013591e2: ADD EDI,0xc scalars: `0xC`
 * 013591e5: MOV dword ptr [EAX],EDI
 * 013591e7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 013591ea: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 013591ed: TEST EDX,EDX
 * 013591ef: JZ 0x01369215 refs: `CONDITIONAL_JUMP -> 01359215` `sym=LAB_01369215`
 * 013591f1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 013591f4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 013591f7: JNZ 0x01369245 refs: `CONDITIONAL_JUMP -> 01359245` `sym=LAB_01369245`
 * 013591f9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 013591fd: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01359201: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359204: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01359207: MOV dword ptr [ESP],EDX
 * 0135920a: MOV EDI,EAX
 * 0135920c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359211: MOV EAX,EDI
 * 01359213: JMP 0x01369223 refs: `UNCONDITIONAL_JUMP -> 01359223` `sym=LAB_01369223`
 * 01359215: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01359219: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0135921d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359220: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01359223: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01359228: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0135922d: TEST ECX,ECX
 * 0135922f: JNZ 0x01369245 refs: `CONDITIONAL_JUMP -> 01359245` `sym=LAB_01369245`
 * 01359231: MOV ECX,dword ptr [ESI]
 * 01359233: MOV dword ptr [ESP],ESI
 * 01359236: MOV EDI,EAX
 * 01359238: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0135923b: MOV dword ptr [ESP],ESI
 * 0135923e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359243: MOV EAX,EDI
 * 01359245: ADD ESP,0x2c scalars: `0x2C`
 * 01359248: POP ESI
 * 01359249: POP EDI
 * 0135924a: POP EBX
 * 0135924b: POP EBP
 * 0135924c: RET 0x4 scalars: `0x4`
 */
