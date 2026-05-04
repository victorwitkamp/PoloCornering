/* Target address 012703d0 */
/* Function getSettingAvailability @ 012703d0 */


/* VagOperationDelegate::getSettingAvailability(std::__ndk1::shared_ptr<Setting> const&) */

void VagOperationDelegate::getSettingAvailability(shared_ptr *param_1)

{
  Ecu *pEVar1;
  int iVar2;
  VagOperationDelegate *in_r1;
  byte *pbVar3;
  shared_ptr *in_r2;
  byte *pbVar4;
  undefined4 uVar5;
  undefined4 local_9c;
  int local_94;
  int *local_84;
  undefined4 local_78;
  int local_70;
  shared_ptr *local_5c;
  int *local_54 [2];
  Result<EcuList_const,void> aRStack_4c [28];
  undefined4 *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pEVar1 = (Ecu *)(**(code **)(**(int **)in_r2 + 0x14))();
  pEVar1 = (Ecu *)VagEcu::getEquivalent(pEVar1);
  (**(code **)(*(int *)in_r1 + 0x14))(aRStack_4c);
  iVar2 = Result<EcuList_const,void>::isFail(aRStack_4c);
  if (iVar2 != 0) {
    Result<EcuList_const,void>::
    stateAs<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ();
    goto LAB_012705c0;
  }
  iVar2 = EcuList::contains((EcuList *)*local_30,pEVar1);
  if (iVar2 == 0) {
    local_78 = 0;
    Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
    ::done<Availability>((type *)param_1);
    goto LAB_012705c0;
  }
  FUN_0126fd84(local_54);
  iVar2 = (**(code **)(*local_54[0] + 0x3c))();
  uVar5 = 1;
  if (iVar2 != 0) {
    uVar5 = 0x10;
  }
  (**(code **)(**(int **)in_r2 + 0x18))(&local_78);
  if ((local_78 & 1) == 0) {
    local_70 = (int)&local_78 + 1;
  }
  Log::d("Getting setting availability for %s, ECU info mask=%d",local_70,uVar5);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_78);
  (**(code **)(*(int *)in_r1 + 0x194))(&local_78);
  iVar2 = Result<VagEcuInfo,void>::isFail((Result<VagEcuInfo,void> *)&local_78);
  if (iVar2 == 0) {
    iVar2 = settingTypeAppliesToEcuType((VagOperationDelegate *)0x0,in_r2,local_5c);
    if (iVar2 == 0) {
      Log::d("Setting type doesn\'t match ECU type");
      local_9c = 0;
      Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
      ::done<Availability>((type *)param_1);
    }
    else {
      iVar2 = (**(code **)(*local_54[0] + 0x40))();
      if (iVar2 != 0) {
        (**(code **)(*(int *)in_r1 + 0x194))(&local_9c);
        iVar2 = Result<VagEcuInfo,void>::isFatalFail((Result<VagEcuInfo,void> *)&local_9c);
        if (((iVar2 != 0) || (*local_84 == -5)) || (*local_84 == -0xb)) {
          Result<VagEcuInfo,void>::
          stateAs<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                    ();
          Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_9c);
          goto LAB_012705b4;
        }
        Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_9c);
      }
      iVar2 = getVagSettingAvailabilityForEcu(in_r1,(shared_ptr *)local_54,local_5c);
      pbVar3 = *(byte **)(*(int *)local_5c + 8);
      if (pbVar3 == (byte *)0x0) {
        pbVar4 = &DAT_0082cf5e;
      }
      else {
        pbVar4 = *(byte **)(pbVar3 + 8);
        if ((*pbVar3 & 1) == 0) {
          pbVar4 = pbVar3 + 1;
        }
      }
      if (iVar2 == 2) {
        (**(code **)(**(int **)in_r2 + 0x18))(&local_9c);
        if ((local_9c & 1) == 0) {
          local_94 = (int)&local_9c + 1;
        }
        Log::d("%s is available for ECU w/ tag %s",local_94,pbVar4);
      }
      else {
        (**(code **)(**(int **)in_r2 + 0x18))(&local_9c);
        if ((local_9c & 1) == 0) {
          local_94 = (int)&local_9c + 1;
        }
        Log::d("%s is unavailable for ECU w/ tag %s",local_94,pbVar4);
      }
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_9c);
      Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
      ::done<Availability>((type *)param_1);
    }
  }
  else {
    (**(code **)(**(int **)in_r2 + 0x18))(&local_9c);
    if ((local_9c & 1) == 0) {
      local_94 = (int)&local_9c + 1;
    }
    Log::d("Setting %s does not apply because ECU is not present or we can\'t read its data",
           local_94);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_9c);
    Result<VagEcuInfo,void>::
    stateAs<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ();
  }
LAB_012705b4:
  Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_78);
  FUN_00d1756c(local_54);
LAB_012705c0:
  Result<EcuList_const,void>::~Result(aRStack_4c);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


