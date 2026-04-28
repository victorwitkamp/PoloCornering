/*
 * VagOperationDelegate_writeVagCanCodingValue
 * ELF symbol address: 0x01263CEC
 * Ghidra address: 0x01273CEC (ELF + 0x10000 image delta)
 * ELF symbol size: 324 bytes
 * Symbol: _ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::writeVagCanCodingValue @ 01273cec
 * Signature: undefined __stdcall writeVagCanCodingValue(ulonglong param_1, vector * param_2)
 * Return type: undefined
 * Function body: [[01273cec, 01273de9]]
 * Parameters:
 *   [0] ulonglong param_1
 *   [1] vector * param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba7fc
 * Direct callees/references:
 *   READ 01273e24 from 01273cf8
 *   READ 014da87c from 01273d02
 *   READ 015a7014 from 01273d04
 *   WRITE Stack[-0x24] from 01273d06
 *   WRITE Stack[-0x28] from 01273d14
 *   READ Stack[-0x4c] from 01273d3a
 *   READ 01273e28 from 01273d54
 *   READ Stack[0x0] from 01273d56
 *   READ 014db2b4 from 01273d5a
 *   READ 014f63cc from 01273d5c
 *   READ Stack[-0x70] from 01273d64
 *   WRITE Stack[-0x90] from 01273d66
 *   UNCONDITIONAL_CALL FUN_01241444 @ 01241444 from 01273d6e
 *   WRITE Stack[-0xa8] from 01273d74
 *   UNCONDITIONAL_CALL FUN_01273e30 @ 01273e30 from 01273d82
 *   READ Stack[-0x38] from 01273d86
 *   WRITE Stack[-0x30] from 01273d8a
 *   WRITE Stack[-0x2c] from 01273d8e
 *   WRITE Stack[-0x38] from 01273d90
 *   UNCONDITIONAL_CALL Progress::NUL @ 0141f070 from 01273d96
 *   UNCONDITIONAL_CALL OperationDelegate::runCommand<EmptyModel> @ 0141f520 from 01273da2
 *   UNCONDITIONAL_CALL FUN_011e01a0 @ 011e01a0 from 01273da8
 *   UNCONDITIONAL_CALL FUN_011e4048 @ 011e4048 from 01273dae
 *   UNCONDITIONAL_CALL FUN_01273e78 @ 01273e78 from 01273db4
 *   UNCONDITIONAL_CALL FUN_00cbcfda @ 00cbcfda from 01273dba
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 01273dc0
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 01273dc6
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 01273dcc
 *   READ Stack[-0x24] from 01273dd0
 *   READ 01273e2c from 01273dd2
 *   READ 014da87c from 01273dd6
 *   READ 015a7014 from 01273dd8
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01273de6
 */

/* Ghidra function: VagOperationDelegate::writeVagCanCodingValue @ 01273cec */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000ba2b080464a480c461d46784416460068006821900868d0f8
 * 01273cec: push {r4,r5,r6,r7,lr}
 * 01273cee: add r7,sp,#0xc
 * 01273cf0: push {r8,r9,r11}
 * 01273cf4: sub sp,#0x88
 * 01273cf6: mov r8,r0
 * 01273cf8: ldr r0,[0x01273e24]
 * 01273cfa: mov r4,r1
 * 01273cfc: mov r5,r3
 * 01273cfe: add r0,pc
 * 01273d00: mov r6,r2
 * 01273d02: ldr r0,[r0,#0x0]
 * 01273d04: ldr r0,[r0,#0x0]
 * 01273d06: str r0,[sp,#0x84]
 * 01273d08: ldr r0,[r1,#0x0]
 * 01273d0a: ldr.w r1,[r0,#0x154]
 * 01273d0e: mov r0,r4
 * 01273d10: blx r1
 * 01273d12: mov r9,r0
 * 01273d14: str r0,[sp,#0x80]
 * 01273d16: ldr r0,[r4,#0x0]
 * 01273d18: mov r2,r6
 * 01273d1a: mov r3,r5
 * 01273d1c: ldr.w r1,[r0,#0x15c]
 * 01273d20: mov r0,r4
 */


/* VagOperationDelegate::writeVagCanCodingValue(unsigned long long, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::writeVagCanCodingValue(ulonglong param_1,vector *param_2)

{
  int iVar1;
  int iVar2;
  shared_ptr *psVar3;
  undefined4 in_stack_00000000;
  Progress aPStack_a0 [8];
  undefined1 auStack_98 [8];
  int local_90;
  Result<VagEcuInfo,void> aRStack_8c [28];
  int *local_70;
  Result<VagEcuInfo,void> aRStack_68 [28];
  undefined4 *local_4c;
  undefined1 auStack_44 [12];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  psVar3 = (shared_ptr *)(param_1 >> 0x20);
  local_24 = __stack_chk_guard;
  iVar1 = (**(code **)(*(int *)psVar3 + 0x154))(psVar3);
  local_28 = iVar1;
  iVar2 = (**(code **)(*(int *)psVar3 + 0x15c))(psVar3,*(code **)(*(int *)psVar3 + 0x15c),param_2);
  (**(code **)(*(int *)psVar3 + 0x1f8))(aRStack_68,psVar3,iVar1);
  if (iVar2 != 2) {
    iVar2 = 3;
  }
  (**(code **)(*(int *)*local_4c + 0x14))(auStack_44);
  (**(code **)(*(int *)psVar3 + 0x1f8))(aRStack_8c,psVar3,iVar1);
  if (iVar1 == VagCanEcu::BATTERY_REGULATOR) {
    iVar2 = 5;
  }
  iVar1 = *local_70;
  local_90 = iVar2;
  FUN_01241444(auStack_98,in_stack_00000000);
  FUN_01273e30(&local_38,&local_28,auStack_44,iVar1 + 0x2c,&local_90,auStack_98);
  local_30 = local_38;
  local_2c = uStack_34;
  local_38 = 0;
  uStack_34 = 0;
  Progress::NUL(aPStack_a0);
  OperationDelegate::runCommand<EmptyModel>((shared_ptr *)param_1,psVar3);
  FUN_011e01a0(aPStack_a0);
  FUN_011e4048(&local_30);
  FUN_01273e78(&local_38);
  FUN_00cbcfda(auStack_98);
  Result<VagEcuInfo,void>::~Result(aRStack_8c);
  FUN_00cb7f50(auStack_44);
  Result<VagEcuInfo,void>::~Result(aRStack_68);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


