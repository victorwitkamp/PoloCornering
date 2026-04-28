/*
 * VagCanCommunicator_sendAck_seq
 * ELF symbol address: 0x00D18A94
 * Ghidra address: 0x00D28A94 (ELF + 0x10000 image delta)
 * ELF symbol size: 14 bytes
 * Symbol: _ZN18VagCanCommunicator7sendAckEhb
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::sendAck @ 00d28a94
 * Signature: undefined __thiscall sendAck(VagCanCommunicator * this, uchar param_1, bool param_2)
 * Return type: undefined
 * Function body: [[00d28a94, 00d28aa1] [013f83f4, 013f83ff]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 *   [1] uchar param_1
 *   [2] bool param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3830
 *   VagCanCommunicator::sendAck @ 01403d70 -> COMPUTED_CALL from 01403d78
 * Direct callees/references:
 *   UNCONDITIONAL_JUMP VagCanCommunicator::sendAck @ 00d28a94 from 00d28a9e
 *   COMPUTED_JUMP 01403da0 from 013f83fe
 */

/* Ghidra function: VagCanCommunicator::sendAck @ 00d28a94 */

/* First instructions after recreation:
 * Memory bytes: 0131134601f00f02b021cff2a9b4
 * 00d28a94: adds r1,#0x1
 * 00d28a96: mov r3,r2
 * 00d28a98: and r2,r1,#0xf
 * 00d28a9c: movs r1,#0xb0
 * 00d28a9e: b.w 0x013f83f4
 * 00d28aa4: push {r5,r6,r7,lr}
 * 00d28aa6: add r7,sp,#0x8
 * 00d28aa8: mov r3,r2
 * 00d28aaa: mov r2,r1
 * 00d28aac: ldr r1,[0x00d28ad0]
 * 00d28aae: add r1,pc
 * 00d28ab0: ldr r1,[r1,#0x0]
 * 00d28ab2: ldr r1,[r1,#0x0]
 * 00d28ab4: str r1,[sp,#0x4]
 * 00d28ab6: subs r1,r7,#0x5
 * 00d28ab8: bl 0x00d2908c
 * 00d28abc: ldr r0,[sp,#0x4]
 * 00d28abe: ldr r1,[0x00d28ad4]
 * 00d28ac0: add r1,pc
 * 00d28ac2: ldr r1,[r1,#0x0]
 * 00d28ac4: ldr r1,[r1,#0x0]
 * 00d28ac6: cmp r1,r0
 * 00d28ac8: it eq
 * 00d28aca: pop.eq {r2,r3,r7,pc}
 */


/* VagCanCommunicator::sendAck(unsigned char, bool) */

void __thiscall VagCanCommunicator::sendAck(VagCanCommunicator *this,uchar param_1,bool param_2)

{
  sendAck(this,0xb0,param_1 + 1 & 0xf,param_2);
  return;
}


