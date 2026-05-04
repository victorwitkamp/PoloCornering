/*
 * VagCanPacket_ctor_fields
 * ELF symbol address: 0x00D172E4
 * Ghidra address: 0x00D272E4 (ELF + 0x10000 image delta)
 * ELF symbol size: 44 bytes
 * Symbol: _ZN18VagCanCommunicator12VagCanPacketC1EtNS_6OpCodeEhRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::VagCanPacket::VagCanPacket @ 00d272e4
 * Signature: undefined __thiscall VagCanPacket(VagCanPacket * this, ushort param_1, OpCode param_2, uchar param_3, vector * param_4)
 * Return type: undefined
 * Function body: [[00d272e4, 00d2730b]]
 * Parameters:
 *   [0] VagCanPacket * this
 *   [1] ushort param_1
 *   [2] typedef OpCode undefined param_2
 *   [3] uchar param_3
 *   [4] vector * param_4
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3860
 *   VagCanCommunicator::VagCanPacket::VagCanPacket @ 01403e30 -> COMPUTED_CALL from 01403e38
 * Direct callees/references:
 *   READ 00d2730c from 00d272f2
 *   READ 014db558 from 00d272f6
 *   DATA 0143da70 from 00d272fa
 *   READ Stack[0x0] from 00d272fe
 *   UNCONDITIONAL_CALL FUN_00cd5ef0 @ 00cd5ef0 from 00d27304
 */

/* Ghidra function: VagCanCommunicator::VagCanPacket::VagCanPacket @ 00d272e4 */

/* First instructions after recreation:
 * Memory bytes: d0b502afc37204468272018101200649794409680831c4e90010b96804f10c00
 * 00d272e4: push {r4,r6,r7,lr}
 * 00d272e6: add r7,sp,#0x8
 * 00d272e8: strb r3,[r0,#0xb]
 * 00d272ea: mov r4,r0
 * 00d272ec: strb r2,[r0,#0xa]
 * 00d272ee: strh r1,[r0,#0x8]
 * 00d272f0: movs r0,#0x1
 * 00d272f2: ldr r1,[0x00d2730c]
 * 00d272f4: add r1,pc
 * 00d272f6: ldr r1,[r1,#0x0]
 * 00d272f8: adds r1,#0x8
 * 00d272fa: strd r1,r0,[r4,#0x0]
 * 00d272fe: ldr r1,[r7,#0x8]
 * 00d27300: add.w r0,r4,#0xc
 * 00d27304: bl 0x00cd5ef0
 * 00d27308: mov r0,r4
 * 00d2730a: pop {r4,r6,r7,pc}
 * 00d27310: movs r2,#0x0
 * 00d27312: movs r3,#0xff
 * 00d27314: str.w r2,[r0,#0xf]
 * 00d27318: str.w r2,[r0,#0xb]
 * 00d2731c: strb r3,[r0,#0xa]
 * 00d2731e: strh r2,[r0,#0x8]
 * 00d27320: str r2,[r0,#0x14]
 */


/* VagCanCommunicator::VagCanPacket::VagCanPacket(unsigned short, VagCanCommunicator::OpCode,
   unsigned char, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&)
    */

VagCanPacket * __thiscall
VagCanCommunicator::VagCanPacket::VagCanPacket
          (VagCanPacket *this,undefined2 param_1,VagCanPacket param_3,VagCanPacket param_4,
          undefined4 param_5)

{
  this[0xb] = param_4;
  this[10] = param_3;
  *(undefined2 *)(this + 8) = param_1;
  *(undefined ***)this = &PTR__VagCanPacket_0143da70;
  *(undefined4 *)(this + 4) = 1;
  FUN_00cd5ef0(this + 0xc,param_5);
  return this;
}


