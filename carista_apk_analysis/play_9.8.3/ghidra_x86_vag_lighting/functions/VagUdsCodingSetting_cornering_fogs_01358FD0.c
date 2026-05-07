/* Target VagUdsCodingSetting_cornering_fogs @ 01358fd0 (Ghidra 01368fd0) */
/* Reason: callee reached by car_setting_cornering_lights_via_fogs 6R/PQ25 branch */
/* Function: VagUdsCodingSetting_cornering_fogs @ 01358fd0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 01358fd0: PUSH EBP
 * 01358fd1: MOV EBP,ESP
 * 01358fd3: PUSH EBX
 * 01358fd4: PUSH EDI
 * 01358fd5: PUSH ESI
 * 01358fd6: SUB ESP,0x1c scalars: `0x1C`
 * 01358fd9: CALL 0x01368fde refs: `UNCONDITIONAL_JUMP -> 01358fde` `sym=LAB_01368fde`
 * 01358fde: POP EBX
 * 01358fdf: ADD EBX,0x6dc63a scalars: `0x6DC63A`
 * 01358fe5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 01358fec: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 01358ff1: MOV EDI,EAX
 * 01358ff3: MOV ESI,EAX
 * 01358ff5: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 01358ff8: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 01358ffc: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 01358fff: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 01359003: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01359007: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135900c: MOV dword ptr [ESP],EDI
 * 0135900f: CALL 0x0198d810 refs: `UNCONDITIONAL_CALL -> 0197d810` `sym=SUB_0198d810`
 * 01359014: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01359017: ADD EDI,0xc scalars: `0xC`
 * 0135901a: MOV dword ptr [EAX],EDI
 * 0135901c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135901f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 01359022: TEST EDX,EDX
 * 01359024: JZ 0x0136904a refs: `CONDITIONAL_JUMP -> 0135904a` `sym=LAB_0136904a`
 * 01359026: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01359029: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135902c: JNZ 0x0136907a refs: `CONDITIONAL_JUMP -> 0135907a` `sym=LAB_0136907a`
 * 0135902e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01359032: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01359036: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359039: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135903c: MOV dword ptr [ESP],EDX
 * 0135903f: MOV EDI,EAX
 * 01359041: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359046: MOV EAX,EDI
 * 01359048: JMP 0x01369058 refs: `UNCONDITIONAL_JUMP -> 01359058` `sym=LAB_01369058`
 * 0135904a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135904e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01359052: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359055: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01359058: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135905d: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 01359062: TEST ECX,ECX
 * 01359064: JNZ 0x0136907a refs: `CONDITIONAL_JUMP -> 0135907a` `sym=LAB_0136907a`
 * 01359066: MOV ECX,dword ptr [ESI]
 * 01359068: MOV dword ptr [ESP],ESI
 * 0135906b: MOV EDI,EAX
 * 0135906d: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 01359070: MOV dword ptr [ESP],ESI
 * 01359073: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359078: MOV EAX,EDI
 * 0135907a: ADD ESP,0x1c scalars: `0x1C`
 * 0135907d: POP ESI
 * 0135907e: POP EDI
 * 0135907f: POP EBX
 * 01359080: POP EBP
 * 01359081: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 01358fd0: PUSH EBP
 * 01358fd1: MOV EBP,ESP
 * 01358fd3: PUSH EBX
 * 01358fd4: PUSH EDI
 * 01358fd5: PUSH ESI
 * 01358fd6: SUB ESP,0x1c scalars: `0x1C`
 * 01358fd9: CALL 0x01368fde refs: `UNCONDITIONAL_JUMP -> 01358fde` `sym=LAB_01368fde`
 * 01358fde: POP EBX
 * 01358fdf: ADD EBX,0x6dc63a scalars: `0x6DC63A`
 * 01358fe5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 01358fec: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 01358ff1: MOV EDI,EAX
 * 01358ff3: MOV ESI,EAX
 * 01358ff5: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 01358ff8: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 01358ffc: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 01358fff: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 01359003: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01359007: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0135900c: MOV dword ptr [ESP],EDI
 * 0135900f: CALL 0x0198d810 refs: `UNCONDITIONAL_CALL -> 0197d810` `sym=SUB_0198d810`
 * 01359014: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01359017: ADD EDI,0xc scalars: `0xC`
 * 0135901a: MOV dword ptr [EAX],EDI
 * 0135901c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0135901f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 01359022: TEST EDX,EDX
 * 01359024: JZ 0x0136904a refs: `CONDITIONAL_JUMP -> 0135904a` `sym=LAB_0136904a`
 * 01359026: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01359029: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0135902c: JNZ 0x0136907a refs: `CONDITIONAL_JUMP -> 0135907a` `sym=LAB_0136907a`
 * 0135902e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01359032: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01359036: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359039: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0135903c: MOV dword ptr [ESP],EDX
 * 0135903f: MOV EDI,EAX
 * 01359041: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359046: MOV EAX,EDI
 * 01359048: JMP 0x01369058 refs: `UNCONDITIONAL_JUMP -> 01359058` `sym=LAB_01369058`
 * 0135904a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0135904e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01359052: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01359055: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01359058: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0135905d: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 01359062: TEST ECX,ECX
 * 01359064: JNZ 0x0136907a refs: `CONDITIONAL_JUMP -> 0135907a` `sym=LAB_0136907a`
 * 01359066: MOV ECX,dword ptr [ESI]
 * 01359068: MOV dword ptr [ESP],ESI
 * 0135906b: MOV EDI,EAX
 * 0135906d: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 01359070: MOV dword ptr [ESP],ESI
 * 01359073: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01359078: MOV EAX,EDI
 * 0135907a: ADD ESP,0x1c scalars: `0x1C`
 * 0135907d: POP ESI
 * 0135907e: POP EDI
 * 0135907f: POP EBX
 * 01359080: POP EBP
 * 01359081: RET 0x4 scalars: `0x4`
 */
