/* Target VagUdsAdaptationSetting_cornering_activation @ 0133e9f0 (Ghidra 0134e9f0) */
/* Reason: D1D cornering activation helper reached from MK7_6C and MK7_NEW_MQBA0 variants */
/* Function: VagUdsAdaptationSetting_cornering_activation @ 0133e9f0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 0133e9f0: PUSH EBP
 * 0133e9f1: MOV EBP,ESP
 * 0133e9f3: PUSH EBX
 * 0133e9f4: PUSH EDI
 * 0133e9f5: PUSH ESI
 * 0133e9f6: SUB ESP,0x2c scalars: `0x2C`
 * 0133e9f9: CALL 0x0134e9fe refs: `UNCONDITIONAL_JUMP -> 0133e9fe` `sym=LAB_0134e9fe`
 * 0133e9fe: POP EBX
 * 0133e9ff: ADD EBX,0x6f6c1a scalars: `0x6F6C1A`
 * 0133ea05: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0133ea0c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0133ea11: MOV EDI,EAX
 * 0133ea13: MOV ESI,EAX
 * 0133ea15: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0133ea19: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0133ea1e: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0133ea22: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0133ea27: MOV dword ptr [ESP],EAX
 * 0133ea2a: CALL 0x0198c950 refs: `UNCONDITIONAL_CALL -> 0197c950` `sym=SUB_0198c950`
 * 0133ea2f: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0133ea32: ADD EDI,0xc scalars: `0xC`
 * 0133ea35: MOV dword ptr [EAX],EDI
 * 0133ea37: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0133ea3a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0133ea3d: TEST EDX,EDX
 * 0133ea3f: JZ 0x0134ea65 refs: `CONDITIONAL_JUMP -> 0133ea65` `sym=LAB_0134ea65`
 * 0133ea41: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0133ea44: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0133ea47: JNZ 0x0134ea95 refs: `CONDITIONAL_JUMP -> 0133ea95` `sym=LAB_0134ea95`
 * 0133ea49: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0133ea4d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0133ea51: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0133ea54: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0133ea57: MOV dword ptr [ESP],EDX
 * 0133ea5a: MOV EDI,EAX
 * 0133ea5c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0133ea61: MOV EAX,EDI
 * 0133ea63: JMP 0x0134ea73 refs: `UNCONDITIONAL_JUMP -> 0133ea73` `sym=LAB_0134ea73`
 * 0133ea65: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0133ea69: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0133ea6d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0133ea70: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0133ea73: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0133ea78: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0133ea7d: TEST ECX,ECX
 * 0133ea7f: JNZ 0x0134ea95 refs: `CONDITIONAL_JUMP -> 0133ea95` `sym=LAB_0134ea95`
 * 0133ea81: MOV ECX,dword ptr [ESI]
 * 0133ea83: MOV dword ptr [ESP],ESI
 * 0133ea86: MOV EDI,EAX
 * 0133ea88: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0133ea8b: MOV dword ptr [ESP],ESI
 * 0133ea8e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0133ea93: MOV EAX,EDI
 * 0133ea95: ADD ESP,0x2c scalars: `0x2C`
 * 0133ea98: POP ESI
 * 0133ea99: POP EDI
 * 0133ea9a: POP EBX
 * 0133ea9b: POP EBP
 * 0133ea9c: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 0133e9f0: PUSH EBP
 * 0133e9f1: MOV EBP,ESP
 * 0133e9f3: PUSH EBX
 * 0133e9f4: PUSH EDI
 * 0133e9f5: PUSH ESI
 * 0133e9f6: SUB ESP,0x2c scalars: `0x2C`
 * 0133e9f9: CALL 0x0134e9fe refs: `UNCONDITIONAL_JUMP -> 0133e9fe` `sym=LAB_0134e9fe`
 * 0133e9fe: POP EBX
 * 0133e9ff: ADD EBX,0x6f6c1a scalars: `0x6F6C1A`
 * 0133ea05: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0133ea0c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 0133ea11: MOV EDI,EAX
 * 0133ea13: MOV ESI,EAX
 * 0133ea15: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 0133ea19: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 0133ea1e: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 0133ea22: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0133ea27: MOV dword ptr [ESP],EAX
 * 0133ea2a: CALL 0x0198c950 refs: `UNCONDITIONAL_CALL -> 0197c950` `sym=SUB_0198c950`
 * 0133ea2f: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 0133ea32: ADD EDI,0xc scalars: `0xC`
 * 0133ea35: MOV dword ptr [EAX],EDI
 * 0133ea37: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0133ea3a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0133ea3d: TEST EDX,EDX
 * 0133ea3f: JZ 0x0134ea65 refs: `CONDITIONAL_JUMP -> 0133ea65` `sym=LAB_0134ea65`
 * 0133ea41: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 0133ea44: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0133ea47: JNZ 0x0134ea95 refs: `CONDITIONAL_JUMP -> 0133ea95` `sym=LAB_0134ea95`
 * 0133ea49: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0133ea4d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0133ea51: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0133ea54: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0133ea57: MOV dword ptr [ESP],EDX
 * 0133ea5a: MOV EDI,EAX
 * 0133ea5c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0133ea61: MOV EAX,EDI
 * 0133ea63: JMP 0x0134ea73 refs: `UNCONDITIONAL_JUMP -> 0133ea73` `sym=LAB_0134ea73`
 * 0133ea65: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0133ea69: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0133ea6d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 0133ea70: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0133ea73: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 0133ea78: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0133ea7d: TEST ECX,ECX
 * 0133ea7f: JNZ 0x0134ea95 refs: `CONDITIONAL_JUMP -> 0133ea95` `sym=LAB_0134ea95`
 * 0133ea81: MOV ECX,dword ptr [ESI]
 * 0133ea83: MOV dword ptr [ESP],ESI
 * 0133ea86: MOV EDI,EAX
 * 0133ea88: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0133ea8b: MOV dword ptr [ESP],ESI
 * 0133ea8e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 0133ea93: MOV EAX,EDI
 * 0133ea95: ADD ESP,0x2c scalars: `0x2C`
 * 0133ea98: POP ESI
 * 0133ea99: POP EDI
 * 0133ea9a: POP EBX
 * 0133ea9b: POP EBP
 * 0133ea9c: RET 0x4 scalars: `0x4`
 */
