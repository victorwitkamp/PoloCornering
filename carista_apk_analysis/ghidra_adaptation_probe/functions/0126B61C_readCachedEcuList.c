/* VagOperationDelegate::readCachedEcuList @ 0126b61c */


/* VagOperationDelegate::readCachedEcuList(bool) */

void VagOperationDelegate::readCachedEcuList(bool param_1)

{
  Result<EcuList_const,void> *this;
  int iVar1;
  int *piVar2;
  int iVar3;
  int *in_r1;
  int in_r2;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  Result<EcuList_const,void> *this_00;
  VagEcu aVStack_98 [12];
  ContainerUtils aCStack_8c [12];
  type local_80;
  undefined1 auStack_7f [7];
  undefined1 *local_78;
  int local_5c;
  int iStack_58;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  int local_28;
  
  this = (Result<EcuList_const,void> *)(uint)param_1;
  this_00 = (Result<EcuList_const,void> *)(in_r1 + 0x42);
  local_28 = __stack_chk_guard;
  iVar1 = Result<EcuList_const,void>::isFinished(this_00);
  if (iVar1 == 0) {
LAB_0126b6b6:
    (**(code **)(*in_r1 + 500))((Result<EcuListModel,void> *)&local_5c);
    iVar1 = Result<EcuListModel,void>::isFatalFail((Result<EcuListModel,void> *)&local_5c);
    if (iVar1 == 0) {
      iVar1 = Result<EcuListModel,void>::isFail((Result<EcuListModel,void> *)&local_5c);
      if (iVar1 == 0) {
        piVar2 = (int *)EcuList::getEntries();
        local_30 = 0;
        local_38 = 0;
        uStack_34 = 0;
        FUN_00dd0d48(&local_38,piVar2[1] - *piVar2 >> 4);
        puVar6 = (undefined4 *)piVar2[1];
        for (puVar5 = (undefined4 *)*piVar2; puVar5 != puVar6; puVar5 = puVar5 + 4) {
          (**(code **)(*(int *)*puVar5 + 0x10))
                    ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      *)&local_80);
          if (((char *)puVar5[2] != (char *)0x0) && (*(char *)puVar5[2] != '\0')) {
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::append
                      ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                        *)&local_80," (has faults)");
          }
          FUN_00cd06ea(&local_38,
                       (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                        *)&local_80);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_80);
        }
        StringUtils::
        toString<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                  ((StringUtils *)&local_80,(vector *)&local_38);
        if (((byte)local_80 & 1) == 0) {
          local_78 = auStack_7f;
        }
        Log::d("The CAN gateway says the following ECUs exist: %s",local_78);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_80);
        (**(code **)(*in_r1 + 0x178))(&local_80);
        Result<EcuList_const,void>::operator=(this_00,(Result *)&local_80);
        Result<EcuList_const,void>::~Result((Result<EcuList_const,void> *)&local_80);
        Result<EcuList_const,void>::Result(this,(Result *)this_00);
        FUN_00cbe2dc(&local_38);
      }
      else {
        Log::w("The CAN gateway didn\'t tell us which ECUs exist; will try all.");
        VagEcu::values(aVStack_98);
        ContainerUtils::copy<Ecu*,VagEcu*>(aCStack_8c,(vector *)aVStack_98);
        EcuList::makeUnconfirmed((vector *)&local_38);
        Result<EcuList_const,void>::done<EcuList_const>(&local_80);
        Result<EcuList_const,void>::operator=(this_00,(Result *)&local_80);
        Result<EcuList_const,void>::~Result((Result<EcuList_const,void> *)&local_80);
        FUN_00ce44e8(&local_38);
        FUN_00cc8d6c(aCStack_8c);
        FUN_01114b98(aVStack_98);
        Result<EcuList_const,void>::Result(this,(Result *)this_00);
      }
    }
    else {
      Log::e("Failed to get list of supported ECUs due to fatal error. Bailing.");
      Result<EcuListModel,void>::stateAs<EcuList_const,void>();
    }
    Result<EcuListModel,void>::~Result((Result<EcuListModel,void> *)&local_5c);
  }
  else {
    if (in_r2 != 0) {
      iVar1 = EcuList::size(*(EcuList **)in_r1[0x49]);
      VagEcu::values((VagEcu *)&local_5c);
      if (iVar1 == iStack_58 - local_5c >> 2) {
        FUN_01114b98(&local_5c);
      }
      else {
        piVar2 = (int *)EcuList::getEntries();
        iVar1 = *piVar2;
        iVar3 = EcuList::getEntries();
        iVar3 = *(int *)(iVar3 + 4);
        do {
          iVar4 = iVar1;
          if (iVar4 == iVar3) {
            FUN_01114b98(&local_5c);
            goto LAB_0126b6b6;
          }
          iVar1 = iVar4 + 0x10;
        } while (*(int *)(iVar4 + 8) == 0);
        FUN_01114b98(&local_5c);
        if (iVar4 == iVar3) goto LAB_0126b6b6;
      }
    }
    Log::d("We already have VAG EcuList. Returning from the cache");
    Result<EcuList_const,void>::Result(this,(Result *)this_00);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


