/* Target VagUdsAdaptationSetting_left_fog_role_gateway @ 01356f90 (Ghidra 01366f90) */
/* Reason: x86 left-side same-key helper using gateway/MEB-style guards */
/* Function: VagUdsAdaptationSetting_left_fog_role_gateway @ 01356f90 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 01356f90: PUSH EBP
 * 01356f91: MOV EBP,ESP
 * 01356f93: PUSH EBX
 * 01356f94: PUSH EDI
 * 01356f95: PUSH ESI
 * 01356f96: SUB ESP,0x2c scalars: `0x2C`
 * 01356f99: CALL 0x01366f9e refs: `UNCONDITIONAL_JUMP -> 01356f9e` `sym=LAB_01366f9e`
 * 01356f9e: POP EBX
 * 01356f9f: ADD EBX,0x6de67a scalars: `0x6DE67A`
 * 01356fa5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 01356fac: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 01356fb1: MOV EDI,EAX
 * 01356fb3: MOV ESI,EAX
 * 01356fb5: MOV EAX,dword ptr [EBP + 0x28] scalars: `0x28`
 * 01356fb8: MOV dword ptr [ESP + 0x1c],EAX scalars: `0x1C`
 * 01356fbc: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 01356fbf: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 01356fc3: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 01356fc6: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 01356fca: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01356fce: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 01356fd3: MOV dword ptr [ESP],EDI
 * 01356fd6: CALL 0x0198d6f0 refs: `UNCONDITIONAL_CALL -> 0197d6f0` `sym=SUB_0198d6f0`
 * 01356fdb: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01356fde: ADD EDI,0xc scalars: `0xC`
 * 01356fe1: MOV dword ptr [EAX],EDI
 * 01356fe3: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 01356fe6: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 01356fe9: TEST EDX,EDX
 * 01356feb: JZ 0x01367011 refs: `CONDITIONAL_JUMP -> 01357011` `sym=LAB_01367011`
 * 01356fed: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01356ff0: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 01356ff3: JNZ 0x01367041 refs: `CONDITIONAL_JUMP -> 01357041` `sym=LAB_01367041`
 * 01356ff5: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01356ff9: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01356ffd: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01357000: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01357003: MOV dword ptr [ESP],EDX
 * 01357006: MOV EDI,EAX
 * 01357008: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135700d: MOV EAX,EDI
 * 0135700f: JMP 0x0136701f refs: `UNCONDITIONAL_JUMP -> 0135701f` `sym=LAB_0136701f`
 * 01357011: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01357015: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01357019: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135701c: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135701f: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01357024: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 01357029: TEST ECX,ECX
 * 0135702b: JNZ 0x01367041 refs: `CONDITIONAL_JUMP -> 01357041` `sym=LAB_01367041`
 * 0135702d: MOV ECX,dword ptr [ESI]
 * 0135702f: MOV dword ptr [ESP],ESI
 * 01357032: MOV EDI,EAX
 * 01357034: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 01357037: MOV dword ptr [ESP],ESI
 * 0135703a: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135703f: MOV EAX,EDI
 * 01357041: ADD ESP,0x2c scalars: `0x2C`
 * 01357044: POP ESI
 * 01357045: POP EDI
 * 01357046: POP EBX
 * 01357047: POP EBP
 * 01357048: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 01356f90: PUSH EBP
 * 01356f91: MOV EBP,ESP
 * 01356f93: PUSH EBX
 * 01356f94: PUSH EDI
 * 01356f95: PUSH ESI
 * 01356f96: SUB ESP,0x2c scalars: `0x2C`
 * 01356f99: CALL 0x01366f9e refs: `UNCONDITIONAL_JUMP -> 01356f9e` `sym=LAB_01366f9e`
 * 01356f9e: POP EBX
 * 01356f9f: ADD EBX,0x6de67a scalars: `0x6DE67A`
 * 01356fa5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 01356fac: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 01356fb1: MOV EDI,EAX
 * 01356fb3: MOV ESI,EAX
 * 01356fb5: MOV EAX,dword ptr [EBP + 0x28] scalars: `0x28`
 * 01356fb8: MOV dword ptr [ESP + 0x1c],EAX scalars: `0x1C`
 * 01356fbc: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 01356fbf: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 01356fc3: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 01356fc6: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 01356fca: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01356fce: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 01356fd3: MOV dword ptr [ESP],EDI
 * 01356fd6: CALL 0x0198d6f0 refs: `UNCONDITIONAL_CALL -> 0197d6f0` `sym=SUB_0198d6f0`
 * 01356fdb: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01356fde: ADD EDI,0xc scalars: `0xC`
 * 01356fe1: MOV dword ptr [EAX],EDI
 * 01356fe3: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 01356fe6: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 01356fe9: TEST EDX,EDX
 * 01356feb: JZ 0x01367011 refs: `CONDITIONAL_JUMP -> 01357011` `sym=LAB_01367011`
 * 01356fed: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01356ff0: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 01356ff3: JNZ 0x01367041 refs: `CONDITIONAL_JUMP -> 01357041` `sym=LAB_01367041`
 * 01356ff5: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01356ff9: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01356ffd: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01357000: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01357003: MOV dword ptr [ESP],EDX
 * 01357006: MOV EDI,EAX
 * 01357008: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135700d: MOV EAX,EDI
 * 0135700f: JMP 0x0136701f refs: `UNCONDITIONAL_JUMP -> 0135701f` `sym=LAB_0136701f`
 * 01357011: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01357015: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01357019: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0135701c: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135701f: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01357024: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 01357029: TEST ECX,ECX
 * 0135702b: JNZ 0x01367041 refs: `CONDITIONAL_JUMP -> 01357041` `sym=LAB_01367041`
 * 0135702d: MOV ECX,dword ptr [ESI]
 * 0135702f: MOV dword ptr [ESP],ESI
 * 01357032: MOV EDI,EAX
 * 01357034: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 01357037: MOV dword ptr [ESP],ESI
 * 0135703a: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0135703f: MOV EAX,EDI
 * 01357041: ADD ESP,0x2c scalars: `0x2C`
 * 01357044: POP ESI
 * 01357045: POP EDI
 * 01357046: POP EBX
 * 01357047: POP EBP
 * 01357048: RET 0x4 scalars: `0x4`
 */
