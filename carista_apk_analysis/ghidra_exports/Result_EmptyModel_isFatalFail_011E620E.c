/*
 * Result_EmptyModel_isFatalFail
 * ELF symbol address: 0x011D620E
 * Ghidra address: 0x011E620E (ELF + 0x10000 image delta)
 * ELF symbol size: 8 bytes
 * Symbol: _ZNK6ResultI10EmptyModelvE11isFatalFailEv
 * Program: libCarista.so
 * Resolved function: Result<EmptyModel,void>::isFatalFail @ 011e620e
 * Signature: undefined __thiscall isFatalFail(Result<EmptyModel,void> * this)
 * Return type: undefined
 * Function body: [[011e620e, 011e6215]]
 * Parameters:
 *   [0] Result<EmptyModel,void> * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea6b8
 *   Result<EmptyModel,void>::isFatalFail @ 0141f790 -> COMPUTED_CALL from 0141f798
 * Direct callees/references:
 *   UNCONDITIONAL_JUMP Result<TpmsInfo,void>::isFatalFail @ 012e2bdc from 011e6212
 */

/* Ghidra function: Result<EmptyModel,void>::isFatalFail @ 011e620e */

/* First instructions after recreation:
 * Memory bytes: 8069006812f20db9
 * 011e620e: ldr r0,[r0,#0x18]
 * 011e6210: ldr r0,[r0,#0x0]
 * 011e6212: b.w 0x013f8430
 * 011e6216: push {r7,lr}
 * 011e6218: mov r7,sp
 * 011e621a: ldr r1,[r1,#0x18]
 * 011e621c: ldr r1,[r1,#0x0]
 * 011e621e: blx 0x013fd730
 * 011e6222: pop {r7,pc}
 * 011e6224: push {r5,r6,r7,lr}
 * 011e6226: add r7,sp,#0x8
 * 011e6228: mov r3,r2
 * 011e622a: mov r2,r1
 * 011e622c: ldr r1,[0x011e6250]
 * 011e622e: add r1,pc
 * 011e6230: ldr r1,[r1,#0x0]
 * 011e6232: ldr r1,[r1,#0x0]
 * 011e6234: str r1,[sp,#0x4]
 * 011e6236: subs r1,r7,#0x5
 * 011e6238: bl 0x011f1e18
 * 011e623c: ldr r0,[sp,#0x4]
 * 011e623e: ldr r1,[0x011e6254]
 * 011e6240: add r1,pc
 * 011e6242: ldr r1,[r1,#0x0]
 */


/* Result<EmptyModel, void>::isFatalFail() const */

void __thiscall Result<EmptyModel,void>::isFatalFail(Result<EmptyModel,void> *this)

{
  State::isFatalError(**(int **)(this + 0x18));
  return;
}


