/*
 * VagCanCommunicator_sendAck_opcode
 * ELF symbol address: 0x00D18AD8
 * Ghidra address: 0x00D28AD8 (ELF + 0x10000 image delta)
 * ELF symbol size: 192 bytes
 * Symbol: _ZN18VagCanCommunicator7sendAckENS_6OpCodeEhb
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::sendAck @ 00d28ad8
 * Signature: undefined __thiscall sendAck(VagCanCommunicator * this, OpCode param_1, uchar param_2, bool param_3)
 * Return type: undefined
 * Function body: [[00d28ad8, 00d28b6f]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 *   [1] typedef OpCode undefined param_1
 *   [2] uchar param_2
 *   [3] bool param_3
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e383c
 *   <no function> -> COMPUTED_JUMP from 01403da8
 * Direct callees/references:
 *   READ 00d28b90 from 00d28ae8
 *   READ 014da87c from 00d28aee
 *   READ 015a7014 from 00d28af0
 *   WRITE Stack[-0x1c] from 00d28af2
 *   WRITE Stack[-0x30] from 00d28afa
 *   WRITE Stack[-0x38] from 00d28afe
 *   WRITE Stack[-0x40] from 00d28b04
 *   UNCONDITIONAL_CALL FUN_00d28b98 @ 00d28b98 from 00d28b12
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d28b18
 *   CONDITIONAL_JUMP VagCanCommunicator::sendAck @ 00d28ad8 from 00d28b1c
 *   READ Stack[-0x28] from 00d28b2a
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d28b46
 *   UNCONDITIONAL_CALL VagCanCommunicator::receive @ 01403d30 from 00d28b4c
 *   UNCONDITIONAL_CALL FUN_00d27d2c @ 00d27d2c from 00d28b52
 *   READ Stack[-0x1c] from 00d28b56
 *   READ 00d28b94 from 00d28b58
 *   READ 014da87c from 00d28b5c
 *   READ 015a7014 from 00d28b5e
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d28b6c
 */

/* Ghidra function: VagCanCommunicator::sendAck @ 00d28ad8 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd8ab007f8151c044629481d467844006800680990002007f8
 * 00d28ad8: push {r4,r5,r6,r7,lr}
 * 00d28ada: add r7,sp,#0xc
 * 00d28adc: push.w r11
 * 00d28ae0: sub sp,#0x28
 * 00d28ae2: strb.w r1,[r7,#-0x15]
 * 00d28ae6: mov r4,r0
 * 00d28ae8: ldr r0,[0x00d28b90]
 * 00d28aea: mov r5,r3
 * 00d28aec: add r0,pc
 * 00d28aee: ldr r0,[r0,#0x0]
 * 00d28af0: ldr r0,[r0,#0x0]
 * 00d28af2: str r0,[sp,#0x24]
 * 00d28af4: movs r0,#0x0
 * 00d28af6: strb.w r2,[r7,#-0x16]
 * 00d28afa: strd r0,r0,[sp,#0x10]
 * 00d28afe: strd r0,r0,[sp,#0x8]
 * 00d28b02: add r0,sp,#0x8
 * 00d28b04: str r0,[sp,#0x0]
 * 00d28b06: add r0,sp,#0x18
 * 00d28b08: add r1,sp,#0x14
 * 00d28b0a: sub.w r2,r7,#0x15
 * 00d28b0e: sub.w r3,r7,#0x16
 * 00d28b12: bl 0x00d28b98
 * 00d28b16: add r0,sp,#0x8
 */


/* VagCanCommunicator::sendAck(VagCanCommunicator::OpCode, unsigned char, bool) */

void __thiscall
VagCanCommunicator::sendAck
          (VagCanCommunicator *this,undefined1 param_2,undefined1 param_3,int param_4)

{
  int *piVar1;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int *local_28 [2];
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_30 = 0;
  uStack_2c = 0;
  local_38 = 0;
  uStack_34 = 0;
  uStack_1e = param_3;
  uStack_1d = param_2;
  FUN_00d28b98(local_28,&uStack_2c,&uStack_1d,&uStack_1e,&local_38);
  FUN_00cb7f50(&local_38);
  if (param_4 != 0) {
    (**(code **)(**(int **)(this + 4) + 0x5c))(*(int **)(this + 4),0x200);
  }
  piVar1 = *(int **)(this + 4);
  (**(code **)(*local_28[0] + 0x14))(&local_38);
  (**(code **)(*piVar1 + 0x16c))(piVar1,&local_38,param_4);
  FUN_00cb7f50(&local_38);
  receive();
  FUN_00d27d2c(local_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


