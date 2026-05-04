/*
 * GetVagCanEcuInfoCommand_processPayloads
 * ELF symbol address: 0x00CF8244
 * Ghidra address: 0x00D08244 (ELF + 0x10000 image delta)
 * ELF symbol size: 444 bytes
 * Symbol: _ZNK23GetVagCanEcuInfoCommand15processPayloadsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE
 * Program: libCarista.so
 * Resolved function: GetVagCanEcuInfoCommand::processPayloads @ 00d08244
 * Signature: undefined __stdcall processPayloads(vector * param_1)
 * Return type: undefined
 * Function body: [[00d08244, 00d083c1]]
 * Parameters:
 *   [0] vector * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143bcf0
 * Direct callees/references:
 *   READ 00d083f4 from 00d08250
 *   READ 014da87c from 00d0825a
 *   READ 015a7014 from 00d0825c
 *   WRITE Stack[-0x24] from 00d0825e
 *   UNCONDITIONAL_CALL FUN_00d08400 @ 00d08400 from 00d08262
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::isFail @ 014012e0 from 00d08276
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d0827a
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::Result @ 014012f0 from 00d08280
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d08284
 *   READ Stack[-0x2c] from 00d08286
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d08290
 *   UNCONDITIONAL_CALL FUN_00d084e8 @ 00d084e8 from 00d08294
 *   UNCONDITIONAL_CALL FUN_013f45d0 @ 013f45d0 from 00d082aa
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d082b0
 *   UNCONDITIONAL_CALL FUN_00d08400 @ 00d08400 from 00d082b6
 *   READ Stack[-0x5c] from 00d082c6
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d082cc
 *   READ Stack[-0x58] from 00d082ce
 *   READ Stack[-0x50] from 00d082d0
 *   WRITE Stack[-0x7c] from 00d082d6
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d082da
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d082ea
 *   UNCONDITIONAL_CALL FUN_00d08518 @ 00d08518 from 00d082ee
 *   UNCONDITIONAL_CALL FUN_00d08540 @ 00d08540 from 00d082f4
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::~Result @ 01401300 from 00d082fa
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d08300
 *   READ 00d083f8 from 00d08302
 *   PARAM 00bebef5 from 00d08304
 *   UNCONDITIONAL_CALL Log::e @ 013fa760 from 00d08306
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::Result @ 01401310 from 00d08310
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d08314
 *   READ Stack[-0x2c] from 00d08316
 *   WRITE Stack[-0x74] from 00d0831c
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d08320
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processPayloads @ 00d08244 from 00d08330
 *   WRITE Stack[-0x80] from 00d08334
 *   WRITE Stack[-0x88] from 00d08336
 *   WRITE Stack[-0x90] from 00d0833a
 *   WRITE Stack[-0x98] from 00d08344
 *   WRITE Stack[-0xa0] from 00d08346
 *   WRITE Stack[-0xc0] from 00d08366
 *   WRITE Stack[-0xb8] from 00d0836e
 *   WRITE Stack[-0xb0] from 00d08374
 *   WRITE Stack[-0xa8] from 00d0837c
 *   UNCONDITIONAL_CALL FUN_00d085c4 @ 00d085c4 from 00d08384
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::done @ 01401320 from 00d0838c
 *   UNCONDITIONAL_CALL FUN_00d08630 @ 00d08630 from 00d08392
 *   UNCONDITIONAL_CALL FUN_00d08630 @ 00d08630 from 00d08398
 *   UNCONDITIONAL_CALL FUN_00d08642 @ 00d08642 from 00d0839e
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::~Result @ 01401300 from 00d083a4
 *   READ Stack[-0x24] from 00d083a8
 *   READ 00d083fc from 00d083aa
 *   READ 014da87c from 00d083ae
 *   READ 015a7014 from 00d083b0
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d083be
 */

/* Ghidra function: GetVagCanEcuInfoCommand::processPayloads @ 00d08244 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de90007a8b0804668480e46002178441546006800682790104600f0
 * 00d08244: push {r4,r5,r6,r7,lr}
 * 00d08246: add r7,sp,#0xc
 * 00d08248: push {r8,r9,r10}
 * 00d0824c: sub sp,#0xa0
 * 00d0824e: mov r8,r0
 * 00d08250: ldr r0,[0x00d083f4]
 * 00d08252: mov r6,r1
 * 00d08254: movs r1,#0x0
 * 00d08256: add r0,pc
 * 00d08258: mov r5,r2
 * 00d0825a: ldr r0,[r0,#0x0]
 * 00d0825c: ldr r0,[r0,#0x0]
 * 00d0825e: str r0,[sp,#0x9c]
 * 00d08260: mov r0,r2
 * 00d08262: bl 0x00d08400
 * 00d08266: mov r2,r0
 * 00d08268: ldr r0,[r6,#0x0]
 * 00d0826a: mov r1,r6
 * 00d0826c: ldr r3,[r0,#0x1c]
 * 00d0826e: add r4,sp,#0x78
 * 00d08270: mov r0,r4
 * 00d08272: blx r3
 * 00d08274: mov r0,r4
 * 00d08276: blx 0x014012e0
 */


/* GetVagCanEcuInfoCommand::processPayloads(std::__ndk1::vector<std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> >, std::__ndk1::allocator<std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > > > const&) const */

void GetVagCanEcuInfoCommand::processPayloads(vector *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *in_r1;
  int *piVar4;
  int *in_r2;
  uint uVar5;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  int iStack_78;
  int local_74;
  int iStack_70;
  int *local_5c;
  undefined4 *local_58;
  undefined4 local_50 [2];
  Result<VagEcuInfoWithCoding,void> aRStack_48 [28];
  int *local_2c;
  int local_24;
  
  local_24 = __stack_chk_guard;
  FUN_00d08400();
  (**(code **)(*in_r1 + 0x1c))(aRStack_48);
  iVar2 = Result<VagEcuInfoWithCoding,void>::isFail(aRStack_48);
  if (iVar2 == 0) {
    if (*(int *)(*local_2c + 0x20) - 1U < 3) {
      FUN_00d084e8(local_50);
      for (uVar5 = 1; uVar3 = FUN_013f45d0(in_r2[1] - *in_r2,0xc), uVar5 < uVar3; uVar5 = uVar5 + 1)
      {
        FUN_00d08400();
        (**(code **)(*in_r1 + 0x1c))((Result<VagEcuInfoWithCoding,void> *)&local_74);
        if (*local_5c == 1) {
          local_7c = *local_58;
          iStack_78 = local_58[1];
          if (iStack_78 != 0) {
            piVar4 = (int *)(iStack_78 + 4);
            do {
              ExclusiveAccess(piVar4);
              bVar1 = (bool)hasExclusiveAccess(piVar4);
            } while (!bVar1);
            *piVar4 = *piVar4 + 1;
          }
          FUN_00d08518(local_50[0],&local_7c);
          FUN_00d08540(&local_7c);
        }
        Result<VagEcuInfoWithCoding,void>::~Result((Result<VagEcuInfoWithCoding,void> *)&local_74);
      }
      local_74 = *local_2c;
      iStack_70 = local_2c[1];
      if (iStack_70 != 0) {
        piVar4 = (int *)(iStack_70 + 4);
        do {
          ExclusiveAccess(piVar4);
          bVar1 = (bool)hasExclusiveAccess(piVar4);
        } while (!bVar1);
        *piVar4 = *piVar4 + 1;
      }
      local_80 = 0;
      local_88 = 0;
      uStack_84 = 0;
      local_90 = 0;
      uStack_8c = 0;
      FUN_00d085c4(&local_7c,local_74 + 4,local_74 + 8,local_50,local_74 + 0x18,local_74 + 0x20,
                   local_74 + 100,local_74 + 0x24,local_74 + 0x2c,local_74 + 0x34,&local_80,
                   &uStack_84,&local_88,&uStack_8c,&local_90);
      Result<VagEcuInfoWithCoding,void>::done
                ((Result<VagEcuInfoWithCoding,void> *)param_1,(shared_ptr *)&local_7c);
      FUN_00d08630(&local_7c);
      FUN_00d08630(&local_74);
      FUN_00d08642(local_50);
    }
    else {
      Log::e("ECU info is missing main module info");
      Result<VagEcuInfoWithCoding,void>::Result((Result<VagEcuInfoWithCoding,void> *)param_1,-6);
    }
  }
  else {
    Result<VagEcuInfoWithCoding,void>::Result
              ((Result<VagEcuInfoWithCoding,void> *)param_1,aRStack_48);
  }
  Result<VagEcuInfoWithCoding,void>::~Result(aRStack_48);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


