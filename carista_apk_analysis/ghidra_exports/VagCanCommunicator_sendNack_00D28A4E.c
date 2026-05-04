/*
 * VagCanCommunicator_sendNack
 * ELF symbol address: 0x00D18A4E
 * Ghidra address: 0x00D28A4E (ELF + 0x10000 image delta)
 * ELF symbol size: 10 bytes
 * Symbol: _ZN18VagCanCommunicator8sendNackEh
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::sendNack @ 00d28a4e
 * Signature: undefined __thiscall sendNack(VagCanCommunicator * this, uchar param_1)
 * Return type: undefined
 * Function body: [[00d28a4e, 00d28a57]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 *   [1] uchar param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3834
 *   VagCanCommunicator::sendNack @ 01403d80 -> COMPUTED_CALL from 01403d88
 * Direct callees/references:
 *   UNCONDITIONAL_JUMP VagCanCommunicator::sendAck @ 00d28a94 from 00d28a54
 */

/* Ghidra function: VagCanCommunicator::sendNack @ 00d28a4e */

/* First instructions after recreation:
 * Memory bytes: 0a4690210123cff2ceb4
 * 00d28a4e: mov r2,r1
 * 00d28a50: movs r1,#0x90
 * 00d28a52: movs r3,#0x1
 * 00d28a54: b.w 0x013f83f4
 * 00d28a58: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 00d28a5a: add r7,sp,#0x18
 * 00d28a5c: mov r4,r2
 * 00d28a5e: mov r2,r1
 * 00d28a60: ldr r1,[0x00d28a8c]
 * 00d28a62: add r1,pc
 * 00d28a64: ldr r1,[r1,#0x0]
 * 00d28a66: ldr r1,[r1,#0x0]
 * 00d28a68: str r1,[sp,#0xc]
 * 00d28a6a: sub.w r1,r7,#0xd
 * 00d28a6e: str r3,[sp,#0x0]
 * 00d28a70: mov r3,r4
 * 00d28a72: bl 0x00d28fa0
 * 00d28a76: ldr r0,[sp,#0xc]
 * 00d28a78: ldr r1,[0x00d28a90]
 * 00d28a7a: add r1,pc
 * 00d28a7c: ldr r1,[r1,#0x0]
 * 00d28a7e: ldr r1,[r1,#0x0]
 * 00d28a80: cmp r1,r0
 * 00d28a82: it eq
 */


/* VagCanCommunicator::sendNack(unsigned char) */

void __thiscall VagCanCommunicator::sendNack(VagCanCommunicator *this,uchar param_1)

{
  sendAck(this,0x90,param_1,1);
  return;
}


