/*
 * VagCanCommunicator_sendDisconnect
 * ELF symbol address: 0x00D17D4C
 * Ghidra address: 0x00D27D4C (ELF + 0x10000 image delta)
 * ELF symbol size: 140 bytes
 * Symbol: _ZN18VagCanCommunicator14sendDisconnectEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::sendDisconnect @ 00d27d4c
 * Signature: undefined __thiscall sendDisconnect(VagCanCommunicator * this)
 * Return type: undefined
 * Function body: [[00d27d4c, 00d27dc5]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3810
 *   VagCanCommunicator::sendDisconnect @ 01403cf0 -> COMPUTED_CALL from 01403cf8
 * Direct callees/references:
 *   READ 00d27dd0 from 00d27d58
 *   READ 014da87c from 00d27d5c
 *   READ 015a7014 from 00d27d5e
 *   WRITE Stack[-0x1c] from 00d27d60
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 00d27d80
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d27d94
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d27da8
 *   READ Stack[-0x1c] from 00d27dac
 *   READ 00d27dd4 from 00d27dae
 *   READ 014da87c from 00d27db2
 *   READ 015a7014 from 00d27db4
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d27dc2
 */

/* Ghidra function: VagCanCommunicator::sendDisconnect @ 00d27d4c */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd88b004461d48784400680068079060680168ca6d4ff40071
 * 00d27d4c: push {r4,r5,r6,r7,lr}
 * 00d27d4e: add r7,sp,#0xc
 * 00d27d50: push.w r11
 * 00d27d54: sub sp,#0x20
 * 00d27d56: mov r4,r0
 * 00d27d58: ldr r0,[0x00d27dd0]
 * 00d27d5a: add r0,pc
 * 00d27d5c: ldr r0,[r0,#0x0]
 * 00d27d5e: ldr r0,[r0,#0x0]
 * 00d27d60: str r0,[sp,#0x1c]
 * 00d27d62: ldr r0,[r4,#0x4]
 * 00d27d64: ldr r1,[r0,#0x0]
 * 00d27d66: ldr r2,[r1,#0x5c]
 * 00d27d68: mov.w r1,#0x200
 * 00d27d6c: blx r2
 * 00d27d6e: movs r0,#0xa8
 * 00d27d70: ldr r5,[r4,#0x4]
 * 00d27d72: strb.w r0,[r7,#-0x15]
 * 00d27d76: add r6,sp,#0xc
 * 00d27d78: sub.w r1,r7,#0x15
 * 00d27d7c: movs r2,#0x1
 * 00d27d7e: mov r0,r6
 * 00d27d80: bl 0x00cdb87c
 * 00d27d84: ldr r0,[r5,#0x0]
 */


/* VagCanCommunicator::sendDisconnect() */

void __thiscall VagCanCommunicator::sendDisconnect(VagCanCommunicator *this)

{
  int *piVar1;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_38 [12];
  undefined1 auStack_2c [15];
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  (**(code **)(**(int **)(this + 4) + 0x5c))(*(int **)(this + 4),0x200);
  piVar1 = *(int **)(this + 4);
  uStack_1d = 0xa8;
  FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  (**(code **)(*piVar1 + 0x16c))(piVar1,auStack_2c,1);
  FUN_00cb7f50(auStack_2c);
  (**(code **)(**(int **)(this + 4) + 0x170))(abStack_38);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_38);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


