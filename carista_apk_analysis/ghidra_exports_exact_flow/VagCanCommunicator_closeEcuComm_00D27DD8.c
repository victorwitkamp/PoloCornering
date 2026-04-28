/*
 * VagCanCommunicator_closeEcuComm
 * ELF symbol address: 0x00D17DD8
 * Ghidra address: 0x00D27DD8 (ELF + 0x10000 image delta)
 * ELF symbol size: 34 bytes
 * Symbol: _ZN18VagCanCommunicator12closeEcuCommEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::closeEcuComm @ 00d27dd8
 * Signature: undefined __thiscall closeEcuComm(VagCanCommunicator * this)
 * Return type: undefined
 * Function body: [[00d27dd8, 00d27df9] [013f8364, 013f836f]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143dac8
 * Direct callees/references:
 *   CONDITIONAL_JUMP VagCanCommunicator::closeEcuComm @ 00d27dd8 from 00d27de0
 *   UNCONDITIONAL_CALL VagCanCommunicator::sendDisconnect @ 01403cf0 from 00d27de4
 *   UNCONDITIONAL_CALL FUN_00d28e2a @ 00d28e2a from 00d27dec
 *   DATA Stack[-0x8] from 00d27df2
 *   UNCONDITIONAL_JUMP VagCanCommunicator::closeEcuComm @ 00d27dd8 from 00d27df6
 *   COMPUTED_JUMP 014029b0 from 013f836e
 */

/* Ghidra function: VagCanCommunicator::closeEcuComm @ 00d27dd8 */

/* First instructions after recreation:
 * Memory bytes: d0b502af0446006910b12046dbf284e704f11c0001f01df82046bde8d040d0f2
 * 00d27dd8: push {r4,r6,r7,lr}
 * 00d27dda: add r7,sp,#0x8
 * 00d27ddc: mov r4,r0
 * 00d27dde: ldr r0,[r0,#0x10]
 * 00d27de0: cbz r0,0x00d27de8
 * 00d27de2: mov r0,r4
 * 00d27de4: blx 0x01403cf0
 * 00d27de8: add.w r0,r4,#0x1c
 * 00d27dec: bl 0x00d28e2a
 * 00d27df0: mov r0,r4
 * 00d27df2: pop.w {r4,r6,r7,lr}
 * 00d27df6: b.w 0x013f8364
 * 00d27dfc: push {r4,r5,r6,r7,lr}
 * 00d27dfe: add r7,sp,#0xc
 * 00d27e00: push {r8,r9,r10,r11}
 * 00d27e04: sub sp,#0x64
 * 00d27e06: mov r11,r0
 * 00d27e08: ldr r0,[0x00d280f0]
 * 00d27e0a: mov r5,r1
 * 00d27e0c: add r0,pc
 * 00d27e0e: ldr r0,[r0,#0x0]
 * 00d27e10: ldr r0,[r0,#0x0]
 * 00d27e12: str r0,[sp,#0x60]
 * 00d27e14: ldrb.w r0,[r11,#0x28]
 */


/* VagCanCommunicator::closeEcuComm() */

void __thiscall VagCanCommunicator::closeEcuComm(VagCanCommunicator *this)

{
  if (*(int *)(this + 0x10) != 0) {
    sendDisconnect(this);
  }
  FUN_00d28e2a(this + 0x1c);
  Communicator::closeEcuComm((Communicator *)this);
  return;
}


