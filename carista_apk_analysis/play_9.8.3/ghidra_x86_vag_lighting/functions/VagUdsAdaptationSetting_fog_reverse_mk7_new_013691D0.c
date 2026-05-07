/* Target VagUdsAdaptationSetting_fog_reverse_mk7_new @ 013691d0 (Ghidra 013791d0) */
/* Reason: D1D fog-on-reverse helper reached from MK7_NEW/MK8 variant */
/* Function: VagUdsAdaptationSetting_fog_reverse_mk7_new @ 013691d0 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 013691d0: PUSH EBP
 * 013691d1: MOV EBP,ESP
 * 013691d3: PUSH EBX
 * 013691d4: PUSH EDI
 * 013691d5: PUSH ESI
 * 013691d6: SUB ESP,0x2c scalars: `0x2C`
 * 013691d9: CALL 0x013791de refs: `UNCONDITIONAL_JUMP -> 013691de` `sym=LAB_013791de`
 * 013691de: POP EBX
 * 013691df: ADD EBX,0x6cc43a scalars: `0x6CC43A`
 * 013691e5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 013691ec: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 013691f1: MOV EDI,EAX
 * 013691f3: MOV ESI,EAX
 * 013691f5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 013691f9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 013691fe: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01369202: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 01369207: MOV dword ptr [ESP],EAX
 * 0136920a: CALL 0x0198e100 refs: `UNCONDITIONAL_CALL -> 0197e100` `sym=SUB_0198e100`
 * 0136920f: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01369212: ADD EDI,0xc scalars: `0xC`
 * 01369215: MOV dword ptr [EAX],EDI
 * 01369217: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136921a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136921d: TEST EDX,EDX
 * 0136921f: JZ 0x01379245 refs: `CONDITIONAL_JUMP -> 01369245` `sym=LAB_01379245`
 * 01369221: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01369224: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 01369227: JNZ 0x01379275 refs: `CONDITIONAL_JUMP -> 01369275` `sym=LAB_01379275`
 * 01369229: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136922d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01369231: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01369234: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01369237: MOV dword ptr [ESP],EDX
 * 0136923a: MOV EDI,EAX
 * 0136923c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01369241: MOV EAX,EDI
 * 01369243: JMP 0x01379253 refs: `UNCONDITIONAL_JUMP -> 01369253` `sym=LAB_01379253`
 * 01369245: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01369249: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136924d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01369250: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01369253: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01369258: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136925d: TEST ECX,ECX
 * 0136925f: JNZ 0x01379275 refs: `CONDITIONAL_JUMP -> 01369275` `sym=LAB_01379275`
 * 01369261: MOV ECX,dword ptr [ESI]
 * 01369263: MOV dword ptr [ESP],ESI
 * 01369266: MOV EDI,EAX
 * 01369268: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136926b: MOV dword ptr [ESP],ESI
 * 0136926e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01369273: MOV EAX,EDI
 * 01369275: ADD ESP,0x2c scalars: `0x2C`
 * 01369278: POP ESI
 * 01369279: POP EDI
 * 0136927a: POP EBX
 * 0136927b: POP EBP
 * 0136927c: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 013691d0: PUSH EBP
 * 013691d1: MOV EBP,ESP
 * 013691d3: PUSH EBX
 * 013691d4: PUSH EDI
 * 013691d5: PUSH ESI
 * 013691d6: SUB ESP,0x2c scalars: `0x2C`
 * 013691d9: CALL 0x013791de refs: `UNCONDITIONAL_JUMP -> 013691de` `sym=LAB_013791de`
 * 013691de: POP EBX
 * 013691df: ADD EBX,0x6cc43a scalars: `0x6CC43A`
 * 013691e5: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 013691ec: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 013691f1: MOV EDI,EAX
 * 013691f3: MOV ESI,EAX
 * 013691f5: MOVUPS XMM0,xmmword ptr [EBP + 0x20] scalars: `0x20`
 * 013691f9: MOVUPS xmmword ptr [ESP + 0x14],XMM0 scalars: `0x14`
 * 013691fe: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01369202: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 01369207: MOV dword ptr [ESP],EAX
 * 0136920a: CALL 0x0198e100 refs: `UNCONDITIONAL_CALL -> 0197e100` `sym=SUB_0198e100`
 * 0136920f: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01369212: ADD EDI,0xc scalars: `0xC`
 * 01369215: MOV dword ptr [EAX],EDI
 * 01369217: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136921a: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 0136921d: TEST EDX,EDX
 * 0136921f: JZ 0x01379245 refs: `CONDITIONAL_JUMP -> 01369245` `sym=LAB_01379245`
 * 01369221: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01369224: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 01369227: JNZ 0x01379275 refs: `CONDITIONAL_JUMP -> 01369275` `sym=LAB_01379275`
 * 01369229: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136922d: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01369231: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01369234: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01369237: MOV dword ptr [ESP],EDX
 * 0136923a: MOV EDI,EAX
 * 0136923c: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01369241: MOV EAX,EDI
 * 01369243: JMP 0x01379253 refs: `UNCONDITIONAL_JUMP -> 01369253` `sym=LAB_01379253`
 * 01369245: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01369249: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 0136924d: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01369250: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 01369253: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 01369258: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 0136925d: TEST ECX,ECX
 * 0136925f: JNZ 0x01379275 refs: `CONDITIONAL_JUMP -> 01369275` `sym=LAB_01379275`
 * 01369261: MOV ECX,dword ptr [ESI]
 * 01369263: MOV dword ptr [ESP],ESI
 * 01369266: MOV EDI,EAX
 * 01369268: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 0136926b: MOV dword ptr [ESP],ESI
 * 0136926e: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01369273: MOV EAX,EDI
 * 01369275: ADD ESP,0x2c scalars: `0x2C`
 * 01369278: POP ESI
 * 01369279: POP EDI
 * 0136927a: POP EBX
 * 0136927b: POP EBP
 * 0136927c: RET 0x4 scalars: `0x4`
 */
