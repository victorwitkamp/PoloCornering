/*
 * VagCanPacket_isData
 * ELF symbol address: 0x00D173E8
 * Ghidra address: 0x00D273E8 (ELF + 0x10000 image delta)
 * ELF symbol size: 34 bytes
 * Symbol: _ZN18VagCanCommunicator12VagCanPacket6isDataEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::VagCanPacket::isData @ 00d273e8
 * Signature: undefined __thiscall isData(VagCanPacket * this)
 * Return type: undefined
 * Function body: [[00d273e8, 00d27409]]
 * Parameters:
 *   [0] VagCanPacket * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143da80
 * Direct callees/references:
 *   CONDITIONAL_JUMP VagCanCommunicator::VagCanPacket::isData @ 00d273e8 from 00d273fa
 */

/* Ghidra function: VagCanCommunicator::VagCanPacket::isData @ 00d273e8 */

/* First instructions after recreation:
 * Memory bytes: d0b502af044600688168204688470146002029b1a17a4fea3111042938bf0120
 * 00d273e8: push {r4,r6,r7,lr}
 * 00d273ea: add r7,sp,#0x8
 * 00d273ec: mov r4,r0
 * 00d273ee: ldr r0,[r0,#0x0]
 * 00d273f0: ldr r1,[r0,#0x8]
 * 00d273f2: mov r0,r4
 * 00d273f4: blx r1
 * 00d273f6: mov r1,r0
 * 00d273f8: movs r0,#0x0
 * 00d273fa: cbz r1,0x00d27408
 * 00d273fc: ldrb r1,[r4,#0xa]
 * 00d273fe: ror r1,r1, ror #0x4
 * 00d27402: cmp r1,#0x4
 * 00d27404: it cc
 * 00d27406: mov.cc r0,#0x1
 * 00d27408: pop {r4,r6,r7,pc}
 * 00d2740c: push {r4,r5,r7,lr}
 * 00d2740e: add r7,sp,#0x8
 * 00d27410: sub sp,#0x20
 * 00d27412: mov r4,r0
 * 00d27414: ldr r0,[0x00d274ac]
 * 00d27416: mov r5,r1
 * 00d27418: add r0,pc
 * 00d2741a: ldr r0,[r0,#0x0]
 */


/* VagCanCommunicator::VagCanPacket::isData() */

undefined4 __thiscall VagCanCommunicator::VagCanPacket::isData(VagCanPacket *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)this + 8))(this);
  uVar2 = 0;
  if ((iVar1 != 0) && (((uint)((byte)this[10] >> 4) | (uint)(byte)this[10] << 0x1c) < 4)) {
    uVar2 = 1;
  }
  return uVar2;
}


