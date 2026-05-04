/*
 * VagOperationDelegate_readEcuInfoCached
 * ELF symbol address: 0x01266BD0
 * Ghidra address: 0x01276BD0 (ELF + 0x10000 image delta)
 * ELF symbol size: 500 bytes
 * Symbol: _ZN20VagOperationDelegate17readEcuInfoCachedEP3Ecujj
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::readEcuInfoCached @ 01276bd0
 * Signature: undefined __stdcall readEcuInfoCached(Ecu * param_1, uint param_2, uint param_3)
 * Return type: undefined
 * Function body: [[01276bd0, 01276d7f]]
 * Parameters:
 *   [0] Ecu * param_1
 *   [1] uint param_2
 *   [2] uint param_3
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba7c8
 * Direct callees/references:
 *   READ 01276da8 from 01276bdc
 *   READ 014da87c from 01276be8
 *   READ 015a7014 from 01276bea
 *   WRITE Stack[-0x28] from 01276bec
 *   READ Stack[-0x4c] from 01276bf8
 *   READ Stack[0x0] from 01276bfc
 *   READ Stack[-0x44] from 01276c02
 *   READ 01276dac from 01276c08
 *   PARAM 00c49933 from 01276c0e
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 01276c10
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 01276c16
 *   READ Stack[-0x34] from 01276c28
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c2e
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c32
 *   READ 01276db0 from 01276c34
 *   PARAM 0090f9e2 from 01276c36
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 01276c38
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c3c
 *   READ Stack[-0x30] from 01276c3e
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c4c
 *   READ 01276db4 from 01276c4e
 *   PARAM 00b79f48 from 01276c50
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 01276c52
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::Result @ 01427ef0 from 01276c5a
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c5e
 *   READ 01276db8 from 01276c60
 *   READ 014db304 from 01276c66
 *   PARAM 0143e680 from 01276c66
 *   READ 01276dbc from 01276c68
 *   READ 014deff0 from 01276c6c
 *   PARAM 014b514c from 01276c6c
 *   UNCONDITIONAL_CALL __dynamic_cast @ 013fadd0 from 01276c70
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c76
 *   UNCONDITIONAL_CALL VagEcu::getEquivalent @ 01415ac0 from 01276c7a
 *   READ Stack[-0x34] from 01276c80
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c86
 *   READ Stack[-0x30] from 01276c88
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276c96
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276cac
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::isFatalFail @ 01427ea0 from 01276cc0
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276cc6
 *   UNCONDITIONAL_CALL State::Set::obd2NegativeResponse @ 013fb660 from 01276cd8
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::isIn @ 01428270 from 01276ce0
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276ce4
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276cf8
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 01276cfc
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276d0c
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276d10
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276d22
 *   WRITE Stack[-0x50] from 01276d38
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::isFatalFail @ 01427ea0 from 01276d40
 *   CONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276d44
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readEcuInfoCached @ 01276bd0 from 01276d54
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::Result @ 01428280 from 01276d5c
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 01276d62
 *   READ Stack[-0x28] from 01276d66
 *   READ 01276dc0 from 01276d68
 *   READ 014da87c from 01276d6c
 *   READ 015a7014 from 01276d6e
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01276d7c
 */

/* Ghidra function: VagOperationDelegate::readEcuInfoCached @ 01276bd0 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000f8bb08146724814460d46784421469a46006800680a901068
 * 01276bd0: push {r4,r5,r6,r7,lr}
 * 01276bd2: add r7,sp,#0xc
 * 01276bd4: push {r8,r9,r10,r11}
 * 01276bd8: sub sp,#0x2c
 * 01276bda: mov r9,r0
 * 01276bdc: ldr r0,[0x01276da8]
 * 01276bde: mov r4,r2
 * 01276be0: mov r5,r1
 * 01276be2: add r0,pc
 * 01276be4: mov r1,r4
 * 01276be6: mov r10,r3
 * 01276be8: ldr r0,[r0,#0x0]
 * 01276bea: ldr r0,[r0,#0x0]
 * 01276bec: str r0,[sp,#0x28]
 * 01276bee: ldr r0,[r2,#0x0]
 * 01276bf0: ldr r2,[r0,#0x10]
 * 01276bf2: add r6,sp,#0x4
 * 01276bf4: mov r0,r6
 * 01276bf6: blx r2
 * 01276bf8: ldrb.w r0,[sp,#0x4]
 * 01276bfc: ldr.w r8,[r7,#0x8]
 * 01276c00: lsls r0,r0,#0x1f
 * 01276c02: ldr r1,[sp,#0xc]
 * 01276c04: it eq
 */


/* VagOperationDelegate::readEcuInfoCached(Ecu*, unsigned int, unsigned int) */

void VagOperationDelegate::readEcuInfoCached(Ecu *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  Set *pSVar4;
  uint in_r3;
  undefined4 uVar5;
  uint in_stack_00000000;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_4c;
  undefined1 auStack_4b [7];
  undefined1 *local_44;
  int *local_34;
  int *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  (**(code **)(*(int *)param_3 + 0x10))(&local_4c,param_3);
  if (((byte)local_4c & 1) == 0) {
    local_44 = auStack_4b;
  }
  Log::d("readEcuInfoCached for %s requiredMask=%u, optionalMask=%u",local_44);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(&local_4c);
  (**(code **)(*(int *)param_2 + 0x1f8))(&local_4c,param_2,param_3);
  if (*local_34 == 1) {
    iVar2 = (**(code **)(*(int *)*local_30 + 0x10))((int *)*local_30,in_stack_00000000 | in_r3);
    if (iVar2 == 0) goto LAB_01276c60;
    Log::d("readEcuInfoCached: we already have all requested data");
  }
  else {
    if (*local_34 != -5) {
LAB_01276c60:
      iVar2 = __dynamic_cast(param_3,&Ecu::typeinfo,&VagEcu::typeinfo,0);
      if (iVar2 == 0) {
        iVar2 = VagEcu::getEquivalent((Ecu *)param_3);
      }
      if (*local_34 == 1) {
        bVar1 = *(int *)(*local_30 + 4) == 2;
      }
      else {
        bVar1 = false;
      }
      iVar3 = (**(code **)(*(int *)param_2 + 0x214))(param_2,param_3);
      if (iVar3 == 1 && !bVar1) {
        (**(code **)(*(int *)param_2 + 0x198))(param_1,param_2,*(undefined4 *)(iVar2 + 0x14));
        iVar3 = Result<VagEcuInfo,void>::isFatalFail((Result<VagEcuInfo,void> *)param_1);
        if (iVar3 != 0) goto LAB_01276d60;
        (**(code **)(*(int *)param_2 + 0x18c))(param_2,*(undefined4 *)(iVar2 + 0x14),param_1);
        pSVar4 = (Set *)State::Set::obd2NegativeResponse();
        iVar3 = Result<VagEcuInfo,void>::isIn((Result<VagEcuInfo,void> *)param_1,pSVar4);
        if ((iVar3 == 0) &&
           (iVar3 = (**(code **)(*(int *)param_2 + 0x218))
                              (param_2,param_3,**(undefined4 **)(param_1 + 0x18)), iVar3 == 0))
        goto LAB_01276d60;
        Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)param_1);
      }
      iVar3 = (**(code **)(*(int *)param_2 + 0x214))(param_2,param_3);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*(int *)param_2 + 0x218))(param_2,param_3,0xfffffffb);
        if (iVar3 == 0) {
          Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,-5);
          goto LAB_01276d60;
        }
        iVar3 = 0x18;
      }
      else {
        iVar3 = 0x14;
      }
      uVar5 = *(undefined4 *)(iVar2 + iVar3);
      (**(code **)(*(int *)param_2 + 0x19c))(param_1,param_2,uVar5);
      iVar2 = Result<VagEcuInfo,void>::isFatalFail((Result<VagEcuInfo,void> *)param_1);
      if (iVar2 == 0) {
        (**(code **)(*(int *)param_2 + 0x18c))
                  (param_2,uVar5,param_1,*(code **)(*(int *)param_2 + 0x18c),in_stack_00000000);
      }
      goto LAB_01276d60;
    }
    Log::d("readEcuInfoCached: we\'ve already tried this ECU and failed to connect; returning.");
  }
  Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,(Result *)&local_4c);
LAB_01276d60:
  Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_4c);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


