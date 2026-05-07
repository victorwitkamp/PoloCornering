/* Target VagUdsCodingSetting_drl_via_fogs @ 01361520 (Ghidra 01371520) */
/* Reason: callee reached by car_setting_drl_via_fogs 6R/PQ25 branch */
/* Function: VagUdsCodingSetting_drl_via_fogs @ 01361520 */

/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */
 * 01361520: PUSH EBP
 * 01361521: MOV EBP,ESP
 * 01361523: PUSH EBX
 * 01361524: PUSH EDI
 * 01361525: PUSH ESI
 * 01361526: SUB ESP,0x1c scalars: `0x1C`
 * 01361529: CALL 0x0137152e refs: `UNCONDITIONAL_JUMP -> 0136152e` `sym=LAB_0137152e`
 * 0136152e: POP EBX
 * 0136152f: ADD EBX,0x6d40ea scalars: `0x6D40EA`
 * 01361535: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136153c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 01361541: MOV EDI,EAX
 * 01361543: MOV ESI,EAX
 * 01361545: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 01361548: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0136154c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0136154f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 01361553: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01361557: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136155c: MOV dword ptr [ESP],EDI
 * 0136155f: CALL 0x0198dcb0 refs: `UNCONDITIONAL_CALL -> 0197dcb0` `sym=SUB_0198dcb0`
 * 01361564: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01361567: ADD EDI,0xc scalars: `0xC`
 * 0136156a: MOV dword ptr [EAX],EDI
 * 0136156c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136156f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 01361572: TEST EDX,EDX
 * 01361574: JZ 0x0137159a refs: `CONDITIONAL_JUMP -> 0136159a` `sym=LAB_0137159a`
 * 01361576: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01361579: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136157c: JNZ 0x013715ca refs: `CONDITIONAL_JUMP -> 013615ca` `sym=LAB_013715ca`
 * 0136157e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01361582: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01361586: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01361589: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136158c: MOV dword ptr [ESP],EDX
 * 0136158f: MOV EDI,EAX
 * 01361591: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01361596: MOV EAX,EDI
 * 01361598: JMP 0x013715a8 refs: `UNCONDITIONAL_JUMP -> 013615a8` `sym=LAB_013715a8`
 * 0136159a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136159e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 013615a2: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 013615a5: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 013615a8: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 013615ad: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 013615b2: TEST ECX,ECX
 * 013615b4: JNZ 0x013715ca refs: `CONDITIONAL_JUMP -> 013615ca` `sym=LAB_013715ca`
 * 013615b6: MOV ECX,dword ptr [ESI]
 * 013615b8: MOV dword ptr [ESP],ESI
 * 013615bb: MOV EDI,EAX
 * 013615bd: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 013615c0: MOV dword ptr [ESP],ESI
 * 013615c3: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 013615c8: MOV EAX,EDI
 * 013615ca: ADD ESP,0x1c scalars: `0x1C`
 * 013615cd: POP ESI
 * 013615ce: POP EDI
 * 013615cf: POP EBX
 * 013615d0: POP EBP
 * 013615d1: RET 0x4 scalars: `0x4`

/* References from entry-window instructions:
 * 01361520: PUSH EBP
 * 01361521: MOV EBP,ESP
 * 01361523: PUSH EBX
 * 01361524: PUSH EDI
 * 01361525: PUSH ESI
 * 01361526: SUB ESP,0x1c scalars: `0x1C`
 * 01361529: CALL 0x0137152e refs: `UNCONDITIONAL_JUMP -> 0136152e` `sym=LAB_0137152e`
 * 0136152e: POP EBX
 * 0136152f: ADD EBX,0x6d40ea scalars: `0x6D40EA`
 * 01361535: MOV dword ptr [ESP],0x6c scalars: `0x6C`
 * 0136153c: CALL 0x0197e0c0 refs: `UNCONDITIONAL_CALL -> 0196e0c0` `sym=SUB_0197e0c0`
 * 01361541: MOV EDI,EAX
 * 01361543: MOV ESI,EAX
 * 01361545: MOV EAX,dword ptr [EBP + 0x24] scalars: `0x24`
 * 01361548: MOV dword ptr [ESP + 0x18],EAX scalars: `0x18`
 * 0136154c: MOV EAX,dword ptr [EBP + 0x20] scalars: `0x20`
 * 0136154f: MOV dword ptr [ESP + 0x14],EAX scalars: `0x14`
 * 01361553: MOVUPS XMM0,xmmword ptr [EBP + 0x10] scalars: `0x10`
 * 01361557: MOVUPS xmmword ptr [ESP + 0x4],XMM0 scalars: `0x4`
 * 0136155c: MOV dword ptr [ESP],EDI
 * 0136155f: CALL 0x0198dcb0 refs: `UNCONDITIONAL_CALL -> 0197dcb0` `sym=SUB_0198dcb0`
 * 01361564: MOV EAX,dword ptr [EBP + 0x8] scalars: `0x8`
 * 01361567: ADD EDI,0xc scalars: `0xC`
 * 0136156a: MOV dword ptr [EAX],EDI
 * 0136156c: MOV dword ptr [EAX + 0x4],ESI scalars: `0x4`
 * 0136156f: MOV EDX,dword ptr [ESI + 0x14] scalars: `0x14`
 * 01361572: TEST EDX,EDX
 * 01361574: JZ 0x0137159a refs: `CONDITIONAL_JUMP -> 0136159a` `sym=LAB_0137159a`
 * 01361576: MOV ECX,dword ptr [EDX + 0x4] scalars: `0x4`
 * 01361579: CMP ECX,-0x1 scalars: `0xFFFFFFFF`
 * 0136157c: JNZ 0x013715ca refs: `CONDITIONAL_JUMP -> 013615ca` `sym=LAB_013715ca`
 * 0136157e: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 01361582: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 01361586: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 01361589: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 0136158c: MOV dword ptr [ESP],EDX
 * 0136158f: MOV EDI,EAX
 * 01361591: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 01361596: MOV EAX,EDI
 * 01361598: JMP 0x013715a8 refs: `UNCONDITIONAL_JUMP -> 013615a8` `sym=LAB_013715a8`
 * 0136159a: INC.LOCK dword ptr [ESI + 0x4] scalars: `0x4`
 * 0136159e: INC.LOCK dword ptr [ESI + 0x8] scalars: `0x8`
 * 013615a2: MOV dword ptr [ESI + 0x10],EDI scalars: `0x10`
 * 013615a5: MOV dword ptr [ESI + 0x14],ESI scalars: `0x14`
 * 013615a8: MOV ECX,0xffffffff scalars: `0xFFFFFFFF`
 * 013615ad: XADD.LOCK dword ptr [ESI + 0x4],ECX scalars: `0x4`
 * 013615b2: TEST ECX,ECX
 * 013615b4: JNZ 0x013715ca refs: `CONDITIONAL_JUMP -> 013615ca` `sym=LAB_013715ca`
 * 013615b6: MOV ECX,dword ptr [ESI]
 * 013615b8: MOV dword ptr [ESP],ESI
 * 013615bb: MOV EDI,EAX
 * 013615bd: CALL dword ptr [ECX + 0x8] scalars: `0x8`
 * 013615c0: MOV dword ptr [ESP],ESI
 * 013615c3: CALL 0x0197e1b0 refs: `UNCONDITIONAL_CALL -> 0196e1b0` `sym=SUB_0197e1b0`
 * 013615c8: MOV EAX,EDI
 * 013615ca: ADD ESP,0x1c scalars: `0x1C`
 * 013615cd: POP ESI
 * 013615ce: POP EDI
 * 013615cf: POP EBX
 * 013615d0: POP EBP
 * 013615d1: RET 0x4 scalars: `0x4`
 */
