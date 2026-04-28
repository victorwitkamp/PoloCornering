/*
 * VagCanCommunicator_isOldSeqNum
 * ELF symbol address: 0x00D18A0C
 * Ghidra address: 0x00D28A0C (ELF + 0x10000 image delta)
 * ELF symbol size: 20 bytes
 * Symbol: _ZN18VagCanCommunicator11isOldSeqNumEhh
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::isOldSeqNum @ 00d28a0c
 * Signature: undefined __stdcall isOldSeqNum(uchar param_1, uchar param_2)
 * Return type: undefined
 * Function body: [[00d28a0c, 00d28a1f]]
 * Parameters:
 *   [0] uchar param_1
 *   [1] uchar param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   <none recorded>
 */

/* Ghidra function: VagCanCommunicator::isOldSeqNum @ 00d28a0c */

/* First instructions after recreation:
 * Memory bytes: 884298bf0f30c0b2411a0020072988bf01207047
 * 00d28a0c: cmp r0,r1
 * 00d28a0e: it ls
 * 00d28a10: add.ls r0,#0xf
 * 00d28a12: uxtb r0,r0
 * 00d28a14: subs r1,r0,r1
 * 00d28a16: movs r0,#0x0
 * 00d28a18: cmp r1,#0x7
 * 00d28a1a: it hi
 * 00d28a1c: mov.hi r0,#0x1
 * 00d28a1e: bx lr
 * 00d28a20: ldrd r0,r1,[r1,#0x0]
 * 00d28a24: subs r1,r1,r0
 * 00d28a26: cmp r1,#0x5
 * 00d28a28: bcc 0x00d28a36
 * 00d28a2a: ldrb r1,[r0,#0x1]
 * 00d28a2c: cmp r1,#0x3
 * 00d28a2e: itt eq
 * 00d28a30: ldrb.eq r1,[r0,#0x2]
 * 00d28a32: cmp.eq r1,#0x7f
 * 00d28a34: beq 0x00d28a3a
 * 00d28a36: movs r0,#0x0
 * 00d28a38: bx lr
 * 00d28a3a: ldrb r0,[r0,#0x4]
 * 00d28a3c: subs r0,#0x78
 */


/* VagCanCommunicator::isOldSeqNum(unsigned char, unsigned char) */

bool VagCanCommunicator::isOldSeqNum(uchar param_1,uchar param_2)

{
  if ((uint)param_1 <= (uint)param_2) {
    param_1 = param_1 + 0xf;
  }
  return 7 < (uint)param_1 - (uint)param_2;
}


