/*
 * VagCanCommunicator_incrementSeqNum
 * ELF symbol address: 0x00D18A46
 * Ghidra address: 0x00D28A46 (ELF + 0x10000 image delta)
 * ELF symbol size: 8 bytes
 * Symbol: _ZN18VagCanCommunicator15incrementSeqNumEh
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::incrementSeqNum @ 00d28a46
 * Signature: undefined __stdcall incrementSeqNum(uchar param_1)
 * Return type: undefined
 * Function body: [[00d28a46, 00d28a4d]]
 * Parameters:
 *   [0] uchar param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   <none recorded>
 */

/* Ghidra function: VagCanCommunicator::incrementSeqNum @ 00d28a46 */

/* First instructions after recreation:
 * Memory bytes: 013000f00f007047
 * 00d28a46: adds r0,#0x1
 * 00d28a48: and r0,r0,#0xf
 * 00d28a4c: bx lr
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
 */


/* VagCanCommunicator::incrementSeqNum(unsigned char) */

byte VagCanCommunicator::incrementSeqNum(uchar param_1)

{
  return param_1 + 1 & 0xf;
}


