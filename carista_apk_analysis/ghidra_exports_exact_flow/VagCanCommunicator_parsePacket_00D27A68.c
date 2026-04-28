/*
 * VagCanCommunicator_parsePacket
 * ELF symbol address: 0x00D17A68
 * Ghidra address: 0x00D27A68 (ELF + 0x10000 image delta)
 * ELF symbol size: 620 bytes
 * Symbol: _ZN18VagCanCommunicator11parsePacketERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEb
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::parsePacket @ 00d27a68
 * Signature: undefined __thiscall parsePacket(VagCanCommunicator * this, basic_string * param_1, bool param_2)
 * Return type: undefined
 * Function body: [[00d27a68, 00d27c41]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 *   [1] basic_string * param_1
 *   [2] bool param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3808
 *   VagCanCommunicator::parsePacket @ 01403cd0 -> COMPUTED_CALL from 01403cd8
 * Direct callees/references:
 *   READ 00d27cac from 00d27a74
 *   READ 014da87c from 00d27a80
 *   READ 015a7014 from 00d27a82
 *   WRITE Stack[-0x24] from 00d27a84
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27a8c
 *   UNCONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27aa4
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27ab8
 *   READ 00d27cb0 from 00d27ac2
 *   PARAM 00926977 from 00d27ac4
 *   UNCONDITIONAL_CALL Log::e @ 013fa760 from 00d27ac6
 *   READ 00d27cb4 from 00d27aca
 *   READ 014db40c from 00d27ace
 *   PARAM 00c8f6e4 from 00d27ace
 *   UNCONDITIONAL_CALL FUN_00d28c94 @ 00d28c94 from 00d27ad2
 *   UNCONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27ad6
 *   UNCONDITIONAL_CALL FUN_00cfe458 @ 00cfe458 from 00d27ae4
 *   UNCONDITIONAL_CALL StringUtils::parseUInt16 @ 013fdd00 from 00d27aec
 *   UNCONDITIONAL_CALL FUN_00cfe458 @ 00cfe458 from 00d27afc
 *   UNCONDITIONAL_CALL ByteUtils::getByte @ 01403710 from 00d27b06
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27b14
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27b24
 *   UNCONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27b32
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27b38
 *   WRITE Stack[-0x48] from 00d27b4a
 *   WRITE Stack[-0x50] from 00d27b4c
 *   UNCONDITIONAL_CALL FUN_00cfe458 @ 00cfe458 from 00d27b60
 *   UNCONDITIONAL_CALL ByteUtils::getBytes @ 013fd400 from 00d27b68
 *   UNCONDITIONAL_CALL FUN_00cda396 @ 00cda396 from 00d27b74
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d27b7a
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d27b80
 *   READ Stack[-0x50] from 00d27b84
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27b8a
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27b98
 *   READ 00d27cc4 from 00d27ba4
 *   PARAM 00c6da71 from 00d27ba6
 *   UNCONDITIONAL_CALL Log::e @ 013fa760 from 00d27ba8
 *   UNCONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27bac
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27bb2
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27bba
 *   CONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27bce
 *   READ 00d27cd0 from 00d27bd0
 *   READ 014db40c from 00d27bd4
 *   PARAM 00c8f6e4 from 00d27bd4
 *   UNCONDITIONAL_CALL FUN_00d28c94 @ 00d28c94 from 00d27bd8
 *   UNCONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27bdc
 *   WRITE Stack[-0x70] from 00d27bec
 *   UNCONDITIONAL_CALL FUN_00d28cc8 @ 00d28cc8 from 00d27bee
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d27bf4
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d27bfa
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d27c00
 *   READ Stack[-0x24] from 00d27c04
 *   READ 00d27cb8 from 00d27c06
 *   READ 014da87c from 00d27c0a
 *   READ 015a7014 from 00d27c0c
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d27c1a
 *   READ Stack[-0x40] from 00d27c1e
 *   READ Stack[-0x38] from 00d27c22
 *   READ 00d27cbc from 00d27c2c
 *   PARAM 0082d0b9 from 00d27c2e
 *   UNCONDITIONAL_CALL Log::e @ 013fa760 from 00d27c30
 *   READ 00d27cc0 from 00d27c34
 *   READ 014db40c from 00d27c38
 *   PARAM 00c8f6e4 from 00d27c38
 *   UNCONDITIONAL_CALL FUN_00d28c94 @ 00d28c94 from 00d27c3c
 *   UNCONDITIONAL_JUMP VagCanCommunicator::parsePacket @ 00d27a68 from 00d27c40
 */

/* Ghidra function: VagCanCommunicator::parsePacket @ 00d27a68 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000794b080468d4892460d467844baf1000f0068006813900a78
 * 00d27a68: push {r4,r5,r6,r7,lr}
 * 00d27a6a: add r7,sp,#0xc
 * 00d27a6c: push {r8,r9,r10}
 * 00d27a70: sub sp,#0x50
 * 00d27a72: mov r8,r0
 * 00d27a74: ldr r0,[0x00d27cac]
 * 00d27a76: mov r10,r2
 * 00d27a78: mov r5,r1
 * 00d27a7a: add r0,pc
 * 00d27a7c: cmp.w r10,#0x0
 * 00d27a80: ldr r0,[r0,#0x0]
 * 00d27a82: ldr r0,[r0,#0x0]
 * 00d27a84: str r0,[sp,#0x4c]
 * 00d27a86: ldrb r2,[r1,#0x0]
 * 00d27a88: and r0,r2,#0x1
 * 00d27a8c: beq 0x00d27aa6
 * 00d27a8e: ldr r1,[r5,#0x4]
 * 00d27a90: cmp r0,#0x0
 * 00d27a92: mov r3,r1
 * 00d27a94: it eq
 * 00d27a96: lsr.eq r3,r2,#0x1
 * 00d27a98: movs r4,#0x0
 * 00d27a9a: cmp r3,#0x6
 * 00d27a9c: it hi
 */


/* VagCanCommunicator::parsePacket(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > const&, bool) */

void __thiscall
VagCanCommunicator::parsePacket(VagCanCommunicator *this,basic_string *param_1,bool param_2)

{
  basic_string bVar1;
  byte bVar2;
  uint uVar3;
  basic_string *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  basic_string abStack_68 [12];
  ByteUtils aBStack_5c [12];
  uint local_50;
  uint uStack_4c;
  undefined4 local_48;
  byte bStack_42;
  byte bStack_41;
  basic_string local_40;
  undefined1 auStack_3f [7];
  undefined1 *local_38;
  undefined2 uStack_32;
  basic_string abStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  bVar1 = *param_1;
  if (param_2) {
    uVar3 = *(uint *)(param_1 + 4);
    uVar6 = uVar3;
    if (((byte)bVar1 & 1) == 0) {
      uVar6 = (uint)((byte)bVar1 >> 1);
    }
    uVar6 = (uint)(6 < uVar6) << 1;
  }
  else {
    uVar3 = *(uint *)(param_1 + 4);
    uVar6 = 0;
  }
  uVar7 = uVar6 | 5;
  uVar5 = (uint)((byte)bVar1 >> 1);
  if (((byte)bVar1 & 1) != 0) {
    uVar5 = uVar3;
  }
  if (uVar5 < uVar7) {
    pbVar4 = *(basic_string **)(param_1 + 8);
    if (((byte)bVar1 & 1) == 0) {
      pbVar4 = param_1 + 1;
    }
    Log::e("Line too short for packet: \"%s\"",pbVar4);
    FUN_00d28c94(this,&State::TRANSPORT_LAYER_ERROR);
    goto LAB_00d27c04;
  }
  FUN_00cfe458(abStack_30,param_1,0,3);
  uStack_32 = StringUtils::parseUInt16(abStack_30,0x10);
  FUN_00cfe458(&local_40,param_1,uVar6 + 3,2);
  uVar3 = ByteUtils::getByte(&local_40);
  uVar6 = (uVar3 + 0x70 & 0xff) >> 4;
  if (uVar6 < 0xb) {
    uVar6 = 1 << uVar6;
    bVar2 = (byte)uVar3;
    if ((uVar6 & 0x785) == 0) {
      if ((uVar6 & 0x1a) == 0) goto LAB_00d27c1e;
      bStack_42 = 0;
      bStack_41 = bVar2;
    }
    else {
      uVar3 = uVar3 & 0xf0;
      bStack_42 = bVar2 & 0xf;
      bStack_41 = (byte)uVar3;
    }
    local_48 = 0;
    local_50 = 0;
    uStack_4c = 0;
    uVar6 = *(uint *)(param_1 + 4);
    if (((byte)*param_1 & 1) == 0) {
      uVar6 = (uint)((byte)*param_1 >> 1);
    }
    FUN_00cfe458(abStack_68,param_1,uVar7,uVar6 - uVar7);
    ByteUtils::getBytes(aBStack_5c,abStack_68);
    FUN_00cda396(&local_50,aBStack_5c);
    FUN_00cb7f50(aBStack_5c);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  abStack_68);
    if ((local_50 == uStack_4c) && (((uVar3 << 4 | uVar3 >> 4) & 0xff) < 4)) {
      pbVar4 = *(basic_string **)(param_1 + 8);
      if (((byte)*param_1 & 1) == 0) {
        pbVar4 = param_1 + 1;
      }
      Log::e("Empty data string for packet: %s",pbVar4);
LAB_00d27bd0:
      FUN_00d28c94(this,&State::TRANSPORT_LAYER_ERROR);
    }
    else {
      if (param_2) {
        uVar3 = uVar3 - 0xd0;
        bVar9 = 7 < uVar3;
        if (uVar3 < 9) {
          bVar8 = (1 << (uVar3 & 0xff) & 0x1c1U) != 0;
          uVar3 = local_50;
          if (bVar8) {
            uVar3 = uStack_4c - local_50;
            bVar9 = 3 < uVar3;
          }
          if (bVar9 && (bVar8 && uVar3 != 4)) goto LAB_00d27bde;
        }
        goto LAB_00d27bd0;
      }
LAB_00d27bde:
      FUN_00d28cc8(this,&uStack_32,&bStack_41,&bStack_42,&local_50);
    }
    FUN_00cb7f50(&local_50);
  }
  else {
LAB_00d27c1e:
    if (((byte)local_40 & 1) == 0) {
      local_38 = auStack_3f;
    }
    Log::e("Invalid op code: %s",local_38);
    FUN_00d28c94(this,&State::TRANSPORT_LAYER_ERROR);
  }
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_40);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_30);
LAB_00d27c04:
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


