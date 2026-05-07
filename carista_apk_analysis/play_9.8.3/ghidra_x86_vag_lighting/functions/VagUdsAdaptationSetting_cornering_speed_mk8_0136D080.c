/* Target VagUdsAdaptationSetting_cornering_speed_mk8 @ 0136d080 (Ghidra 0137d080) */
/* Reason: D1D max activation-speed helper reached from MK7_NEW/MK8-derived variant */
/* Function: VagUdsAdaptationSetting_cornering_speed_mk8 @ 0136d080 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0136d080: PUSH EBP
 * 0136d081: MOV EBP,ESP
 * 0136d083: PUSH EBX
 * 0136d084: PUSH EDI
 * 0136d085: PUSH ESI
 * 0136d086: SUB ESP,0x2c scalars: `0x2C`
 * 0136d089: CALL 0x0137d08e refs: `UNCONDITIONAL_JUMP -> 0136d08e` `sym=LAB_0137d08e`
 * 0136d08e: POP EBX
 * 0136d08f: ADD EBX,0x6c858a scalars: `0x6C858A`
 * 0136d095: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136d09c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136d0a1: MOV EDI,EAX
 * 0136d0a3: MOV ESI,EAX
 * 0136d0a5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136d0a9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136d0ae: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136d0b2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136d0b7: MOV dword ptr [ESP],EAX
 * 0136d0ba: CALL 0x0198e330 refs: `UNCONDITIONAL_CALL -> 0197e330` `sym=SUB_0198e330`
 * 0136d0bf: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136d0c2: ADD EDI,0xc scalars: `0xC`
 * 0136d0c5: MOV dword ptr [EAX],EDI
 * 0136d0c7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136d0ca: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136d0cd: TEST EDX,EDX
 * 0136d0cf: JZ 0x0137d0f5 refs: `CONDITIONAL_JUMP -> 0136d0f5` `sym=LAB_0137d0f5`
 * 0136d0d1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136d0d4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136d0d7: JNZ 0x0137d125 refs: `CONDITIONAL_JUMP -> 0136d125` `sym=LAB_0137d125`
 * 0136d0d9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136d0dd: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136d0e1: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136d0e4: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136d0e7: MOV dword ptr [ESP],EDX
 * 0136d0ea: MOV EDI,EAX
 * 0136d0ec: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136d0f1: MOV EAX,EDI
 * 0136d0f3: JMP 0x0137d103 refs: `UNCONDITIONAL_JUMP -> 0136d103` `sym=LAB_0137d103`
 * 0136d0f5: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136d0f9: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136d0fd: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136d100: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136d103: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136d108: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136d10d: TEST ECX,ECX
 * 0136d10f: JNZ 0x0137d125 refs: `CONDITIONAL_JUMP -> 0136d125` `sym=LAB_0137d125`
 * 0136d111: MOV ECX,dword ptr [ESI]
 * 0136d113: MOV dword ptr [ESP],ESI
 * 0136d116: MOV EDI,EAX
 * 0136d118: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136d11b: MOV dword ptr [ESP],ESI
 * 0136d11e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136d123: MOV EAX,EDI
 * 0136d125: ADD ESP,0x2c scalars: `0x2C`
 * 0136d128: POP ESI
 * 0136d129: POP EDI
 * 0136d12a: POP EBX
 * 0136d12b: POP EBP
 * 0136d12c: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0136d080: PUSH EBP
 * 0136d081: MOV EBP,ESP
 * 0136d083: PUSH EBX
 * 0136d084: PUSH EDI
 * 0136d085: PUSH ESI
 * 0136d086: SUB ESP,0x2c scalars: `0x2C`
 * 0136d089: CALL 0x0137d08e refs: `UNCONDITIONAL_JUMP -> 0136d08e` `sym=LAB_0137d08e`
 * 0136d08e: POP EBX
 * 0136d08f: ADD EBX,0x6c858a scalars: `0x6C858A`
 * 0136d095: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136d09c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136d0a1: MOV EDI,EAX
 * 0136d0a3: MOV ESI,EAX
 * 0136d0a5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136d0a9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136d0ae: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136d0b2: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136d0b7: MOV dword ptr [ESP],EAX
 * 0136d0ba: CALL 0x0198e330 refs: `UNCONDITIONAL_CALL -> 0197e330` `sym=SUB_0198e330`
 * 0136d0bf: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136d0c2: ADD EDI,0xc scalars: `0xC`
 * 0136d0c5: MOV dword ptr [EAX],EDI
 * 0136d0c7: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136d0ca: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136d0cd: TEST EDX,EDX
 * 0136d0cf: JZ 0x0137d0f5 refs: `CONDITIONAL_JUMP -> 0136d0f5` `sym=LAB_0137d0f5`
 * 0136d0d1: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136d0d4: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136d0d7: JNZ 0x0137d125 refs: `CONDITIONAL_JUMP -> 0136d125` `sym=LAB_0137d125`
 * 0136d0d9: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136d0dd: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136d0e1: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136d0e4: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136d0e7: MOV dword ptr [ESP],EDX
 * 0136d0ea: MOV EDI,EAX
 * 0136d0ec: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136d0f1: MOV EAX,EDI
 * 0136d0f3: JMP 0x0137d103 refs: `UNCONDITIONAL_JUMP -> 0136d103` `sym=LAB_0137d103`
 * 0136d0f5: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136d0f9: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136d0fd: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136d100: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136d103: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136d108: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136d10d: TEST ECX,ECX
 * 0136d10f: JNZ 0x0137d125 refs: `CONDITIONAL_JUMP -> 0136d125` `sym=LAB_0137d125`
 * 0136d111: MOV ECX,dword ptr [ESI]
 * 0136d113: MOV dword ptr [ESP],ESI
 * 0136d116: MOV EDI,EAX
 * 0136d118: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136d11b: MOV dword ptr [ESP],ESI
 * 0136d11e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136d123: MOV EAX,EDI
 * 0136d125: ADD ESP,0x2c scalars: `0x2C`
 * 0136d128: POP ESI
 * 0136d129: POP EDI
 * 0136d12a: POP EBX
 * 0136d12b: POP EBP
 * 0136d12c: RET 0x4 scalars: `0x4`
 */
