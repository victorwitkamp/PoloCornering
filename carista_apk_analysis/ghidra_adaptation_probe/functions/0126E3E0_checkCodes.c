/* VagOperationDelegate::checkCodes @ 0126e3e0 */


/* VagOperationDelegate::checkCodes(Ecu*, std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::checkCodes(VagOperationDelegate *this,Ecu *param_1,shared_ptr *param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  VagTroubleCode *pVVar3;
  int iVar4;
  int iVar5;
  shared_ptr *psVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  Ecu *pEVar11;
  undefined4 uVar12;
  VagTroubleCode *local_c4;
  int local_c0;
  undefined4 local_a8;
  undefined4 local_a0;
  VagTroubleCode *local_9c;
  int local_98;
  VagTroubleCode *local_90;
  int iStack_8c;
  Ecu *local_84 [2];
  undefined4 local_7c;
  VagTroubleCode *local_78;
  int iStack_74;
  shared_ptr asStack_70 [28];
  int *local_54;
  Result<GetTroubleCodesModel,void> aRStack_4c [24];
  int *local_34;
  int *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  Result<GetTroubleCodesModel,void>::Result(aRStack_4c,-5);
  iVar4 = (**(code **)(*(int *)param_1 + 0x214))(param_1,param_2);
  if ((param_2 == (shared_ptr *)0x0) ||
     (iVar5 = __dynamic_cast(param_2,&Ecu::typeinfo,&VagEcu::typeinfo,0), psVar6 = param_2,
     iVar5 == 0)) {
    psVar6 = (shared_ptr *)VagEcu::getEquivalent((Ecu *)param_2);
  }
  if (iVar4 == 0) {
LAB_0126e64a:
    iVar4 = (**(code **)(*(int *)param_1 + 0x218))(param_1,param_2,*local_34);
    if (iVar4 != 0) {
      uVar12 = *(undefined4 *)(psVar6 + 0x18);
      local_7c = uVar12;
      FUN_0126ebcc(&local_90,&local_7c);
      local_c4 = local_90;
      local_c0 = iStack_8c;
      local_90 = (VagTroubleCode *)0x0;
      iStack_8c = 0;
      OperationDelegate::runCommand<GetTroubleCodesModel>(asStack_70,(shared_ptr *)param_1);
      Result<GetTroubleCodesModel,void>::operator=(aRStack_4c,(Result *)asStack_70);
      Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)asStack_70);
      FUN_011e3ec8(&local_c4);
      FUN_0126ec00(&local_90);
      iVar4 = Result<GetTroubleCodesModel,void>::isFatalFail(aRStack_4c);
      if (iVar4 == 0) {
        iVar4 = *local_34;
        if (iVar4 == 1) {
          if (**(int **)(*local_30 + 4) == (*(int **)(*local_30 + 4))[1]) {
            iVar4 = 1;
          }
          else {
            OperationDelegate::deduplicateTroubleCodes((vector *)&local_90);
            FUN_00cf68a8(&local_c4,&local_90);
            Result<GetTroubleCodesModel,void>::done
                      ((Result<GetTroubleCodesModel,void> *)asStack_70,(shared_ptr *)&local_c4);
            Result<GetTroubleCodesModel,void>::operator=(aRStack_4c,(Result *)asStack_70);
            Result<GetTroubleCodesModel,void>::~Result
                      ((Result<GetTroubleCodesModel,void> *)asStack_70);
            FUN_00cdf834(&local_c4);
            FUN_00ce1cf0(&local_90);
            iVar4 = *local_34;
          }
        }
        (**(code **)(*(int *)param_1 + 0x188))(param_1,uVar12,iVar4);
        FUN_00ce1bc8(&local_78);
        if ((*local_34 == 1) && (**(int **)(*local_30 + 4) != (*(int **)(*local_30 + 4))[1])) {
          (**(code **)(*(int *)param_1 + 0x194))(asStack_70,param_1,local_7c,0xc0,0);
          iVar4 = Result<VagEcuInfo,void>::isFatalFail((Result<VagEcuInfo,void> *)asStack_70);
          if (iVar4 == 0) {
            iVar4 = Result<VagEcuInfo,void>::isFail((Result<VagEcuInfo,void> *)asStack_70);
            if (iVar4 != 0) {
              Result<GetTroubleCodesModel,void>::Result
                        ((Result<GetTroubleCodesModel,void> *)this,(Result *)aRStack_4c);
              goto LAB_0126e772;
            }
            FUN_00cbe830(&local_90,*(undefined4 *)(*local_54 + 0x44),&DAT_009e8888);
            FUN_00cfe458(&local_9c,*(undefined4 *)(*local_54 + 0x4c),0,3);
            FUN_00d1fa20(&local_c4,&local_90,&local_9c);
            FUN_00cbc8b8(local_84,&local_c4);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_c4);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_9c);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_90);
            puVar10 = (undefined4 *)(*(int **)(*local_30 + 4))[1];
            puVar7 = (undefined4 *)**(int **)(*local_30 + 4);
            do {
              puVar8 = puVar7;
              if (puVar8 == puVar10) {
                FUN_00ce1cbc(&local_90,&local_78);
                Result<GetTroubleCodesModel,void>::done
                          ((Result<GetTroubleCodesModel,void> *)&local_c4,(shared_ptr *)&local_90);
                Result<GetTroubleCodesModel,void>::operator=(aRStack_4c,(Result *)&local_c4);
                Result<GetTroubleCodesModel,void>::~Result
                          ((Result<GetTroubleCodesModel,void> *)&local_c4);
                FUN_00cdf834(&local_90);
                break;
              }
              local_c4 = (VagTroubleCode *)*puVar8;
              local_c0 = puVar8[1];
              if (local_c0 != 0) {
                piVar9 = (int *)(local_c0 + 4);
                do {
                  ExclusiveAccess(piVar9);
                  bVar1 = (bool)hasExclusiveAccess(piVar9);
                } while (!bVar1);
                *piVar9 = *piVar9 + 1;
              }
              uVar12 = VagTroubleCode::getCodeNum(local_c4);
              FUN_0126ebba((shared_ptr *)&local_c4);
              local_a0 = uVar12;
              FUN_0126ec28((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                            *)&local_9c,&local_7c,&local_a0,local_84);
              local_90 = local_9c;
              iStack_8c = local_98;
              local_9c = (VagTroubleCode *)0x0;
              local_98 = 0;
              OperationDelegate::runCommand<FreezeFrameModel>
                        ((shared_ptr *)&local_c4,(shared_ptr *)param_1);
              FUN_011f9140((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                            *)&local_90);
              FUN_0126ec64((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                            *)&local_9c);
              iVar4 = Result<FreezeFrameModel,void>::isFatalFail
                                ((Result<FreezeFrameModel,void> *)&local_c4);
              if (iVar4 == 0) {
                FUN_0126ec78((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                              *)&local_90,&local_a0,local_a8);
                local_9c = local_90;
                local_98 = iStack_8c;
                if (iStack_8c != 0) {
                  piVar9 = (int *)(iStack_8c + 4);
                  do {
                    ExclusiveAccess(piVar9);
                    bVar1 = (bool)hasExclusiveAccess(piVar9);
                  } while (!bVar1);
                  *piVar9 = *piVar9 + 1;
                }
                FUN_00ce1c2c(local_78,(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                       *)&local_9c);
                FUN_00ce1c54((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                              *)&local_9c);
                FUN_00d15b78((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                              *)&local_90);
              }
              else {
                Result<FreezeFrameModel,void>::stateAs<GetTroubleCodesModel,void>();
              }
              Result<FreezeFrameModel,void>::~Result((Result<FreezeFrameModel,void> *)&local_c4);
              puVar7 = puVar8 + 2;
            } while (iVar4 == 0);
            FUN_00cbd6dc(local_84);
            Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)asStack_70);
            if (puVar8 == puVar10) goto LAB_0126e8e8;
          }
          else {
            Result<VagEcuInfo,void>::stateAs<GetTroubleCodesModel,void>();
LAB_0126e772:
            Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)asStack_70);
          }
          puVar2 = &stack0x00000044;
          goto LAB_0126e77a;
        }
LAB_0126e8e8:
        FUN_00ce1cf0(&local_78);
      }
    }
LAB_0126e8ee:
    Result<GetTroubleCodesModel,void>::Result
              ((Result<GetTroubleCodesModel,void> *)this,(Result *)aRStack_4c);
  }
  else {
    pEVar11 = *(Ecu **)(psVar6 + 0x14);
    local_84[0] = pEVar11;
    iVar4 = isPowertrainCanEcu((VagOperationDelegate *)param_1,pEVar11);
    if (iVar4 == 0) {
      FUN_0126eb2c(&local_90,local_84);
      local_c4 = local_90;
      local_c0 = iStack_8c;
      local_90 = (VagTroubleCode *)0x0;
      iStack_8c = 0;
      OperationDelegate::runCommand<GetTroubleCodesModel>(asStack_70,(shared_ptr *)param_1);
      Result<GetTroubleCodesModel,void>::operator=(aRStack_4c,(Result *)asStack_70);
      Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)asStack_70);
      FUN_011e3ec8(&local_c4);
      FUN_0126eb60(&local_90);
    }
    else {
      FUN_0126eae4(&local_90,local_84);
      local_c4 = local_90;
      local_c0 = iStack_8c;
      local_90 = (VagTroubleCode *)0x0;
      iStack_8c = 0;
      OperationDelegate::runCommand<GetTroubleCodesModel>(asStack_70,(shared_ptr *)param_1);
      Result<GetTroubleCodesModel,void>::operator=(aRStack_4c,(Result *)asStack_70);
      Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)asStack_70);
      FUN_011e3ec8(&local_c4);
      FUN_0126eb18(&local_90);
    }
    iVar4 = Result<GetTroubleCodesModel,void>::isFatalFail(aRStack_4c);
    if (iVar4 != 0) goto LAB_0126e8ee;
    iVar4 = *local_34;
    if (iVar4 == 1) {
      if (**(int **)(*local_30 + 4) == (*(int **)(*local_30 + 4))[1]) {
        iVar4 = 1;
      }
      else {
        OperationDelegate::deduplicateTroubleCodes((vector *)&local_90);
        FUN_00cf68a8(&local_c4,&local_90);
        Result<GetTroubleCodesModel,void>::done
                  ((Result<GetTroubleCodesModel,void> *)asStack_70,(shared_ptr *)&local_c4);
        Result<GetTroubleCodesModel,void>::operator=(aRStack_4c,(Result *)asStack_70);
        Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)asStack_70);
        FUN_00cdf834(&local_c4);
        FUN_00ce1cf0(&local_90);
        iVar4 = *local_34;
      }
    }
    (**(code **)(*(int *)param_1 + 0x188))(param_1,pEVar11,iVar4);
    FUN_00ce1bc8(&local_c4);
    if (*local_34 != 1) {
LAB_0126e642:
      FUN_00ce1cf0(&local_c4);
      goto LAB_0126e64a;
    }
    puVar10 = (undefined4 *)**(undefined4 **)(*local_30 + 4);
    puVar7 = (undefined4 *)(*(undefined4 **)(*local_30 + 4))[1];
    if (puVar10 == puVar7) goto LAB_0126e642;
    do {
      if (puVar10 == puVar7) {
        FUN_00ce1cbc(&local_90,&local_c4);
        Result<GetTroubleCodesModel,void>::done
                  ((Result<GetTroubleCodesModel,void> *)asStack_70,(shared_ptr *)&local_90);
        Result<GetTroubleCodesModel,void>::operator=(aRStack_4c,(Result *)asStack_70);
        Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)asStack_70);
        FUN_00cdf834(&local_90);
        goto LAB_0126e642;
      }
      local_90 = (VagTroubleCode *)*puVar10;
      iStack_8c = puVar10[1];
      if (iStack_8c != 0) {
        piVar9 = (int *)(iStack_8c + 4);
        do {
          ExclusiveAccess(piVar9);
          bVar1 = (bool)hasExclusiveAccess(piVar9);
        } while (!bVar1);
        *piVar9 = *piVar9 + 1;
      }
      local_7c = VagTroubleCode::getCodeNum(local_90);
      FUN_0126eb74(&local_78,local_84,&local_7c);
      local_9c = local_78;
      local_98 = iStack_74;
      local_78 = (VagTroubleCode *)0x0;
      iStack_74 = 0;
      OperationDelegate::runCommand<FreezeFrameModel>(asStack_70,(shared_ptr *)param_1);
      FUN_011f9140(&local_9c);
      FUN_0126eba8(&local_78);
      iVar4 = Result<FreezeFrameModel,void>::isFatalFail
                        ((Result<FreezeFrameModel,void> *)asStack_70);
      pVVar3 = local_c4;
      if (iVar4 == 0) {
        (**(code **)(*(int *)local_90 + 0x1c))(&local_9c,local_90,local_54);
        FUN_00ce1c2c(pVVar3,&local_9c);
        FUN_00ce1c54(&local_9c);
      }
      else {
        Result<FreezeFrameModel,void>::stateAs<GetTroubleCodesModel,void>();
      }
      Result<FreezeFrameModel,void>::~Result((Result<FreezeFrameModel,void> *)asStack_70);
      FUN_0126ebba(&local_90);
      puVar10 = puVar10 + 2;
    } while (iVar4 == 0);
    puVar2 = &stack0xfffffff8;
LAB_0126e77a:
    FUN_00ce1cf0(puVar2 + -0xbc);
  }
  Result<GetTroubleCodesModel,void>::~Result(aRStack_4c);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


