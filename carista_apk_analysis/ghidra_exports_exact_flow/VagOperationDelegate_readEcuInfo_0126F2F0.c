/*
 * VagOperationDelegate_readEcuInfo
 * ELF symbol address: 0x0125F2F0
 * Ghidra address: 0x0126F2F0 (ELF + 0x10000 image delta)
 * ELF symbol size: 444 bytes
 * Symbol: _ZN20VagOperationDelegate11readEcuInfoEP3Ecu
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::readEcuInfo @ 0126f2f0
 * Signature: undefined __stdcall readEcuInfo(Ecu * param_1)
 * Return type: undefined
 * Function body: [[0126f2f0, 0126f46d]]
 * Parameters:
 *   [0] Ecu * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba694
 * Direct callees/references:
 *   READ 0126f4a4 from 0126f2fc
 *   READ 014da87c from 0126f306
 *   READ 015a7014 from 0126f308
 *   WRITE Stack[-0x24] from 0126f30a
 *   WRITE Stack[-0xd8] from 0126f316
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::isFail @ 01427da0 from 0126f320
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f324
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::stateAs<EcuInfo,void> @ 01427f00 from 0126f32a
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f32e
 *   READ Stack[-0x2c] from 0126f330
 *   WRITE Stack[-0x50] from 0126f336
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f33a
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f34a
 *   WRITE Stack[-0x58] from 0126f352
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f358
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f35c
 *   READ Stack[-0x64] from 0126f37c
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f382
 *   READ Stack[-0x60] from 0126f384
 *   UNCONDITIONAL_CALL FUN_00cdf124 @ 00cdf124 from 0126f38c
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readEcuInfo @ 0126f2f0 from 0126f390
 *   WRITE Stack[-0xa0] from 0126f394
 *   UNCONDITIONAL_CALL FUN_00d089cc @ 00d089cc from 0126f39e
 *   UNCONDITIONAL_CALL FUN_00cbd77c @ 00cbd77c from 0126f3a4
 *   READ Stack[-0x84] from 0126f3b6
 *   UNCONDITIONAL_CALL FUN_0126f4bc @ 0126f4bc from 0126f3ba
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 0126f3c0
 *   UNCONDITIONAL_CALL Result<BytesModel,void>::~Result @ 013fdbf0 from 0126f3c6
 *   READ Stack[-0x50] from 0126f3ca
 *   WRITE Stack[-0xa4] from 0126f3cc
 *   WRITE Stack[-0xac] from 0126f3d0
 *   WRITE Stack[-0xb8] from 0126f3e2
 *   WRITE Stack[-0xb0] from 0126f3ea
 *   WRITE Stack[-0xc4] from 0126f3fa
 *   WRITE Stack[-0xd8] from 0126f406
 *   WRITE Stack[-0xcc] from 0126f410
 *   WRITE Stack[-0xbc] from 0126f414
 *   UNCONDITIONAL_CALL FUN_0126f514 @ 0126f514 from 0126f41c
 *   READ Stack[-0xa0] from 0126f420
 *   WRITE Stack[-0x7c] from 0126f424
 *   WRITE Stack[-0x78] from 0126f428
 *   WRITE Stack[-0xa0] from 0126f42a
 *   UNCONDITIONAL_CALL Result<EcuInfo,void>::done @ 01422660 from 0126f432
 *   UNCONDITIONAL_CALL FUN_00ccba0c @ 00ccba0c from 0126f438
 *   UNCONDITIONAL_CALL FUN_00d08630 @ 00d08630 from 0126f43e
 *   UNCONDITIONAL_CALL FUN_00cbd77c @ 00cbd77c from 0126f444
 *   UNCONDITIONAL_CALL FUN_00d08540 @ 00d08540 from 0126f44a
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 0126f450
 *   READ Stack[-0x24] from 0126f454
 *   READ 0126f4a8 from 0126f456
 *   READ 014da87c from 0126f45a
 *   READ 015a7014 from 0126f45c
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 0126f46a
 */

/* Ghidra function: VagOperationDelegate::readEcuInfo @ 0126f2f0 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de90007aeb0804669480023924678440e46006800682d900868d0f8
 * 0126f2f0: push {r4,r5,r6,r7,lr}
 * 0126f2f2: add r7,sp,#0xc
 * 0126f2f4: push {r8,r9,r10}
 * 0126f2f8: sub sp,#0xb8
 * 0126f2fa: mov r8,r0
 * 0126f2fc: ldr r0,[0x0126f4a4]
 * 0126f2fe: movs r3,#0x0
 * 0126f300: mov r10,r2
 * 0126f302: add r0,pc
 * 0126f304: mov r6,r1
 * 0126f306: ldr r0,[r0,#0x0]
 * 0126f308: ldr r0,[r0,#0x0]
 * 0126f30a: str r0,[sp,#0xb4]
 * 0126f30c: ldr r0,[r1,#0x0]
 * 0126f30e: ldr.w r5,[r0,#0x194]
 * 0126f312: movw r0,#0x365
 * 0126f316: str r0,[sp,#0x0]
 * 0126f318: add r4,sp,#0x90
 * 0126f31a: mov r0,r4
 * 0126f31c: blx r5
 * 0126f31e: mov r0,r4
 * 0126f320: blx 0x01427da0
 * 0126f324: cbz r0,0x0126f330
 * 0126f326: add r1,sp,#0x90
 */


/* VagOperationDelegate::readEcuInfo(Ecu*) */

void VagOperationDelegate::readEcuInfo(Ecu *param_1)

{
  bool bVar1;
  int iVar2;
  int *in_r1;
  int *piVar3;
  undefined4 in_r2;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_84;
  undefined4 local_7c;
  undefined4 local_78;
  int *local_64;
  int *local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  int local_50;
  int iStack_4c;
  Result<VagEcuInfo,void> aRStack_48 [28];
  int *local_2c;
  int local_24;
  
  local_24 = __stack_chk_guard;
  (**(code **)(*in_r1 + 0x194))(aRStack_48,in_r1,in_r2,0,0x365);
  iVar2 = Result<VagEcuInfo,void>::isFail(aRStack_48);
  if (iVar2 == 0) {
    local_50 = *local_2c;
    iStack_4c = local_2c[1];
    if (iStack_4c != 0) {
      piVar3 = (int *)(iStack_4c + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    local_58 = 0;
    uStack_54 = 0;
    if ((*(uint *)(local_50 + 0x20) < 4) && (*(uint *)(local_50 + 0x20) != 1)) {
      (**(code **)(*in_r1 + 0x144))();
      (**(code **)(*in_r1 + 0xec))(&local_7c);
      if (*local_64 == 1) {
        FUN_00cdf124(&local_a0,*local_60 + 4);
      }
      else {
        local_a0 = 0;
        uStack_9c = 0;
      }
      FUN_00d089cc(&local_58,&local_a0);
      FUN_00cbd77c(&local_a0);
      (**(code **)(*in_r1 + 0x1f8))(&local_a0);
      FUN_0126f4bc(&local_50,local_84);
      Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_a0);
      Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_7c);
    }
    local_a4 = 0;
    local_ac = 0;
    uStack_a8 = 0;
    FUN_0126f514(&local_a0,local_50 + 4,local_50 + 8,&local_a4,&uStack_a8,local_50 + 0x20,&local_58,
                 local_50 + 0x24,local_50 + 0x2c,local_50 + 0x34,local_50 + 0x3c,local_50 + 0x44,
                 &local_ac,local_50 + 0x54,local_50 + 0x5c);
    local_7c = local_a0;
    local_78 = uStack_9c;
    local_a0 = 0;
    uStack_9c = 0;
    Result<EcuInfo,void>::done((Result<EcuInfo,void> *)param_1,(shared_ptr *)&local_7c);
    FUN_00ccba0c(&local_7c);
    FUN_00d08630(&local_a0);
    FUN_00cbd77c(&local_58);
    FUN_00d08540(&local_50);
  }
  else {
    Result<VagEcuInfo,void>::stateAs<EcuInfo,void>();
  }
  Result<VagEcuInfo,void>::~Result(aRStack_48);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


