/*
 * VagCanCommunicator_getSeqNum
 * ELF symbol address: 0x00D18DB0
 * Ghidra address: 0x00D28DB0 (ELF + 0x10000 image delta)
 * ELF symbol size: 18 bytes
 * Symbol: _ZN18VagCanCommunicator9getSeqNumEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::getSeqNum @ 00d28db0
 * Signature: undefined __thiscall getSeqNum(VagCanCommunicator * this)
 * Return type: undefined
 * Function body: [[00d28db0, 00d28dc1]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   <none recorded>
 */

/* Ghidra function: VagCanCommunicator::getSeqNum @ 00d28db0 */

/* First instructions after recreation:
 * Memory bytes: 90f829104a1c02f00f0280f8292008467047
 * 00d28db0: ldrb.w r1,[r0,#0x29]
 * 00d28db4: adds r2,r1,#0x1
 * 00d28db6: and r2,r2,#0xf
 * 00d28dba: strb.w r2,[r0,#0x29]
 * 00d28dbe: mov r0,r1
 * 00d28dc0: bx lr
 * 00d28dc4: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 00d28dc6: add r7,sp,#0x18
 * 00d28dc8: mov r4,r0
 * 00d28dca: ldr r0,[0x00d28e08]
 * 00d28dcc: movs r3,#0x0
 * 00d28dce: add r0,pc
 * 00d28dd0: ldr r0,[r0,#0x0]
 * 00d28dd2: ldr r0,[r0,#0x0]
 * 00d28dd4: str r0,[sp,#0xc]
 * 00d28dd6: ldrd r0,r2,[r1,#0x0]
 * 00d28dda: strd r3,r3,[r1,#0x0]
 * 00d28dde: ldrd r1,r3,[r4,#0x0]
 * 00d28de2: strd r0,r2,[r4,#0x0]
 * 00d28de6: strd r1,r3,[sp,#0x4]
 * 00d28dea: add r0,sp,#0x4
 * 00d28dec: bl 0x00d27d2c
 * 00d28df0: ldr r0,[sp,#0xc]
 * 00d28df2: ldr r1,[0x00d28e0c]
 */


/* VagCanCommunicator::getSeqNum() */

VagCanCommunicator __thiscall VagCanCommunicator::getSeqNum(VagCanCommunicator *this)

{
  VagCanCommunicator VVar1;
  
  VVar1 = this[0x29];
  this[0x29] = (VagCanCommunicator)((char)VVar1 + 1U & 0xf);
  return VVar1;
}


