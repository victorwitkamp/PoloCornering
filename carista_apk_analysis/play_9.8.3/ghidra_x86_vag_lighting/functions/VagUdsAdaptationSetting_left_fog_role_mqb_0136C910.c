/* Target VagUdsAdaptationSetting_left_fog_role_mqb @ 0136c910 (Ghidra 0137c910) */
/* Reason: x86 left-side same-key helper using MQB/MK8-style guards */
/* Function: VagUdsAdaptationSetting_left_fog_role_mqb @ 0136c910 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0136c910: PUSH EBP
 * 0136c911: MOV EBP,ESP
 * 0136c913: PUSH EBX
 * 0136c914: PUSH EDI
 * 0136c915: PUSH ESI
 * 0136c916: SUB ESP,0x2c scalars: `0x2C`
 * 0136c919: CALL 0x0137c91e refs: `UNCONDITIONAL_JUMP -> 0136c91e` `sym=LAB_0137c91e`
 * 0136c91e: POP EBX
 * 0136c91f: ADD EBX,0x6c8cfa scalars: `0x6C8CFA`
 * 0136c925: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136c92c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136c931: MOV EDI,EAX
 * 0136c933: MOV ESI,EAX
 * 0136c935: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136c939: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136c93e: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136c942: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136c947: MOV dword ptr [ESP],EAX
 * 0136c94a: CALL 0x0198e2f0 refs: `UNCONDITIONAL_CALL -> 0197e2f0` `sym=SUB_0198e2f0`
 * 0136c94f: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136c952: ADD EDI,0xc scalars: `0xC`
 * 0136c955: MOV dword ptr [EAX],EDI
 * 0136c957: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136c95a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136c95d: TEST EDX,EDX
 * 0136c95f: JZ 0x0137c985 refs: `CONDITIONAL_JUMP -> 0136c985` `sym=LAB_0137c985`
 * 0136c961: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136c964: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136c967: JNZ 0x0137c9b5 refs: `CONDITIONAL_JUMP -> 0136c9b5` `sym=LAB_0137c9b5`
 * 0136c969: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136c96d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136c971: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136c974: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136c977: MOV dword ptr [ESP],EDX
 * 0136c97a: MOV EDI,EAX
 * 0136c97c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136c981: MOV EAX,EDI
 * 0136c983: JMP 0x0137c993 refs: `UNCONDITIONAL_JUMP -> 0136c993` `sym=LAB_0137c993`
 * 0136c985: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136c989: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136c98d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136c990: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136c993: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136c998: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136c99d: TEST ECX,ECX
 * 0136c99f: JNZ 0x0137c9b5 refs: `CONDITIONAL_JUMP -> 0136c9b5` `sym=LAB_0137c9b5`
 * 0136c9a1: MOV ECX,dword ptr [ESI]
 * 0136c9a3: MOV dword ptr [ESP],ESI
 * 0136c9a6: MOV EDI,EAX
 * 0136c9a8: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136c9ab: MOV dword ptr [ESP],ESI
 * 0136c9ae: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136c9b3: MOV EAX,EDI
 * 0136c9b5: ADD ESP,0x2c scalars: `0x2C`
 * 0136c9b8: POP ESI
 * 0136c9b9: POP EDI
 * 0136c9ba: POP EBX
 * 0136c9bb: POP EBP
 * 0136c9bc: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0136c910: PUSH EBP
 * 0136c911: MOV EBP,ESP
 * 0136c913: PUSH EBX
 * 0136c914: PUSH EDI
 * 0136c915: PUSH ESI
 * 0136c916: SUB ESP,0x2c scalars: `0x2C`
 * 0136c919: CALL 0x0137c91e refs: `UNCONDITIONAL_JUMP -> 0136c91e` `sym=LAB_0137c91e`
 * 0136c91e: POP EBX
 * 0136c91f: ADD EBX,0x6c8cfa scalars: `0x6C8CFA`
 * 0136c925: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136c92c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0136c931: MOV EDI,EAX
 * 0136c933: MOV ESI,EAX
 * 0136c935: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0136c939: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0136c93e: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0136c942: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136c947: MOV dword ptr [ESP],EAX
 * 0136c94a: CALL 0x0198e2f0 refs: `UNCONDITIONAL_CALL -> 0197e2f0` `sym=SUB_0198e2f0`
 * 0136c94f: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0136c952: ADD EDI,0xc scalars: `0xC`
 * 0136c955: MOV dword ptr [EAX],EDI
 * 0136c957: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136c95a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136c95d: TEST EDX,EDX
 * 0136c95f: JZ 0x0137c985 refs: `CONDITIONAL_JUMP -> 0136c985` `sym=LAB_0137c985`
 * 0136c961: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0136c964: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136c967: JNZ 0x0137c9b5 refs: `CONDITIONAL_JUMP -> 0136c9b5` `sym=LAB_0137c9b5`
 * 0136c969: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136c96d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136c971: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136c974: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136c977: MOV dword ptr [ESP],EDX
 * 0136c97a: MOV EDI,EAX
 * 0136c97c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136c981: MOV EAX,EDI
 * 0136c983: JMP 0x0137c993 refs: `UNCONDITIONAL_JUMP -> 0136c993` `sym=LAB_0137c993`
 * 0136c985: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136c989: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136c98d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0136c990: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136c993: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0136c998: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136c99d: TEST ECX,ECX
 * 0136c99f: JNZ 0x0137c9b5 refs: `CONDITIONAL_JUMP -> 0136c9b5` `sym=LAB_0137c9b5`
 * 0136c9a1: MOV ECX,dword ptr [ESI]
 * 0136c9a3: MOV dword ptr [ESP],ESI
 * 0136c9a6: MOV EDI,EAX
 * 0136c9a8: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136c9ab: MOV dword ptr [ESP],ESI
 * 0136c9ae: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0136c9b3: MOV EAX,EDI
 * 0136c9b5: ADD ESP,0x2c scalars: `0x2C`
 * 0136c9b8: POP ESI
 * 0136c9b9: POP EDI
 * 0136c9ba: POP EBX
 * 0136c9bb: POP EBP
 * 0136c9bc: RET 0x4 scalars: `0x4`
 */
