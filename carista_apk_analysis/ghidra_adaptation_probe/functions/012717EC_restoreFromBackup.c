/* VagOperationDelegate::restoreFromBackup @ 012717ec */


/* VagOperationDelegate::restoreFromBackup(std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const&,
   std::__ndk1::shared_ptr<Progress> const&) */

void VagOperationDelegate::restoreFromBackup(basic_string *param_1,shared_ptr *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  shared_ptr *in_r2;
  undefined4 *in_r3;
  char cVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined8 uVar10;
  undefined4 local_a4;
  int *local_a0;
  int iStack_9c;
  int *local_98;
  int local_94;
  Result<bool,void> aRStack_90 [24];
  int *local_78;
  undefined4 *local_74;
  int *local_6c;
  int iStack_68;
  VagOperationDelegate aVStack_64 [24];
  undefined4 *local_4c;
  undefined4 *local_48;
  VagRestoreData aVStack_40 [8];
  undefined4 *local_38;
  undefined4 *puStack_34;
  int local_28;
  
  local_28 = __stack_chk_guard;
  getRestoreData(aVStack_64,(basic_string *)param_2,in_r2);
  iVar2 = Result<VagRestoreData,void>::isFail((Result<VagRestoreData,void> *)aVStack_64);
  if (iVar2 == 0) {
    VagRestoreData::VagRestoreData(aVStack_40,(VagRestoreData *)*local_48);
    piVar6 = (int *)*in_r3;
    uVar3 = VagRestoreData::totalItemsCount(aVStack_40);
    (**(code **)(*piVar6 + 0x24))(&local_6c,piVar6,uVar3);
    for (puVar7 = local_38; puVar7 != puStack_34; puVar7 = puVar7 + 7) {
      iVar2 = VagRestoreData::EcuRecord::containsUdsAdaptation();
      if (iVar2 == 0) {
LAB_01271910:
        if (puVar7[1] != 0) {
          iVar2 = (**(code **)(*(int *)param_2 + 0x128))(param_2,*puVar7,puVar7[1],in_r3);
          iVar4 = State::isError(iVar2);
          if (iVar4 != 0) {
            Log::e("Failed to unlock UDS sec access before writing. Bailing.");
            Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ::Result((Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                      *)param_1,iVar2);
            goto LAB_01271aa6;
          }
        }
      }
      else {
        (**(code **)(*(int *)param_2 + 0xd4))(aRStack_90,param_2,*puVar7);
        iVar2 = Result<bool,void>::isFail(aRStack_90);
        if (iVar2 == 0) {
          cVar5 = *(char *)*local_74;
        }
        else {
          Log::e("Failed while checking for SFD1 protection, error state: %d",*local_78);
          Result<bool,void>::
          stateAs<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                    ();
          cVar5 = '\0';
        }
        Result<bool,void>::~Result(aRStack_90);
        if (iVar2 != 0) goto LAB_01271aa6;
        if (cVar5 == '\0') goto LAB_01271910;
        (**(code **)(**(int **)(param_2 + 0x18) + 0x40))(&local_98);
        if ((local_98 == (int *)0x0) || (*local_98 == 8 && local_98[1] == 0)) {
          OperationDelegate::readVinCached((OperationDelegate *)aRStack_90,param_2);
          iVar2 = Result<StringModel,void>::isFatalFail((Result<StringModel,void> *)aRStack_90);
          if (iVar2 == 0) {
            iVar2 = Result<StringModel,void>::isFail((Result<StringModel,void> *)aRStack_90);
            if (iVar2 != 0) {
              Log::e("Failed to read VIN. Bailing.");
              Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ::Result((Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                        *)param_1,-0x3e9);
              goto LAB_012719a4;
            }
            uVar3 = *puVar7;
            local_a0 = local_6c;
            iStack_9c = iStack_68;
            if (iStack_68 != 0) {
              piVar6 = (int *)(iStack_68 + 4);
              do {
                ExclusiveAccess(piVar6);
                bVar1 = (bool)hasExclusiveAccess(piVar6);
              } while (!bVar1);
              *piVar6 = *piVar6 + 1;
            }
            iVar2 = (**(code **)(*(int *)param_2 + 300))(param_2,uVar3,&local_a0);
            FUN_011e01a0(&local_a0);
            iVar4 = State::isError(iVar2);
            if (iVar4 != 0) {
              Log::e("Unlock SFD1 failed with state: %d",iVar2);
              Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ::Result((Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                        *)param_1,iVar2);
              goto LAB_012719a4;
            }
            bVar1 = false;
          }
          else {
            Log::e("Failed to read VIN fatally.");
            Result<StringModel,void>::
            stateAs<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                      ();
LAB_012719a4:
            bVar1 = true;
          }
          Result<StringModel,void>::~Result((Result<StringModel,void> *)aRStack_90);
        }
        else {
          Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
          ::Result((Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                    *)param_1,-9);
          bVar1 = true;
        }
        FUN_011e2ff4(&local_98);
        if (bVar1) goto LAB_01271aa6;
      }
      puVar8 = (undefined1 *)puVar7[4];
      for (puVar9 = (undefined1 *)puVar7[3]; puVar9 != puVar8; puVar9 = puVar9 + 0x10) {
        uVar10 = (**(code **)(*(int *)param_2 + 0x17c))
                           (param_2,*puVar9,*puVar7,*(undefined2 *)(puVar9 + 2));
        (**(code **)(*local_6c + 0x30))(&local_98,local_6c,1);
        (**(code **)(*(int *)param_2 + 0xf0))
                  ((Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                    *)aRStack_90,param_2,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20),puVar9 + 4,
                   &local_98);
        FUN_011e01a0(&local_98);
        iVar2 = Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                ::isFail((Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                          *)aRStack_90);
        if (iVar2 != 0) {
          Log::e("Failed writing raw value failed with: %d",*local_78);
          Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
          ::
          stateAs<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                    ();
          Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
          ::~Result((Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                     *)aRStack_90);
          goto LAB_01271aa6;
        }
        Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
        ::~Result((Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                   *)aRStack_90);
      }
      if (*(char *)(puVar7 + 6) != '\0') {
        local_a4 = 2;
        FUN_01271bd4(&local_a0,puVar7,&local_a4);
        local_98 = local_a0;
        local_94 = iStack_9c;
        local_a0 = (int *)0x0;
        iStack_9c = 0;
        OperationDelegate::runCommand<EmptyModel>((shared_ptr *)aRStack_90,param_2);
        iVar2 = *local_78;
        Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)aRStack_90);
        FUN_011e4048(&local_98);
        FUN_011e6258(&local_a0);
        iVar2 = State::isError(iVar2);
        if (iVar2 != 0) {
          Log::e("Failed to reset VAG UDS ECU");
        }
      }
    }
    Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
    ::done((Result<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            *)param_1);
LAB_01271aa6:
    FUN_00d2b90c(&local_6c);
    FUN_0114019c(&local_38);
  }
  else {
    Log::e("Getting restore data failed with state: %d",*local_4c);
    Result<VagRestoreData,void>::
    stateAs<EmptyModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ();
  }
  Result<VagRestoreData,void>::~Result((Result<VagRestoreData,void> *)aVStack_64);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


