/* VagOperationDelegate::readEcuInfoCached @ 01276bd0 */


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


