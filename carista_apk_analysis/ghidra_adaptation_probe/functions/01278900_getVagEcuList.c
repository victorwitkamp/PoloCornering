/* VagOperationDelegate::getVagEcuList @ 01278900 */


/* VagOperationDelegate::getVagEcuList(bool) */

void VagOperationDelegate::getVagEcuList(bool param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  Result<EcuListModel,void> *this;
  int iVar3;
  int *piVar4;
  Set *pSVar5;
  int iVar6;
  uint uVar7;
  shared_ptr *in_r1;
  uint in_r2;
  Progress aPStack_108 [8];
  undefined4 local_100;
  int iStack_fc;
  undefined4 local_f8;
  int iStack_f4;
  Progress aPStack_f0 [8];
  uint local_e8;
  int iStack_e4;
  uint local_e0;
  int iStack_dc;
  uint local_bc;
  int local_b8;
  int *local_a0;
  uint local_98;
  int iStack_94;
  shared_ptr asStack_90 [28];
  int *local_74;
  Result<EcuListModel,void> aRStack_6c [28];
  int *local_50;
  undefined4 local_48;
  int iStack_44;
  int local_24;
  
  this = (Result<EcuListModel,void> *)(uint)param_1;
  local_24 = __stack_chk_guard;
  Result<EcuListModel,void>::Result(aRStack_6c);
  iVar3 = (**(code **)(*(int *)in_r1 + 0x184))();
  if (iVar3 != 0) {
    FUN_01278d34(&local_e0);
    local_bc = local_e0;
    local_b8 = iStack_dc;
    local_e0 = 0;
    iStack_dc = 0;
    Progress::NUL((Progress *)&local_48);
    OperationDelegate::runCommand<EcuListModel>(asStack_90,in_r1);
    Result<EcuListModel,void>::operator=(aRStack_6c,(Result *)asStack_90);
    Result<EcuListModel,void>::~Result((Result<EcuListModel,void> *)asStack_90);
    FUN_011e01a0(&local_48);
    FUN_011f7fa8(&local_bc);
    FUN_01278d64(&local_e0);
    iVar3 = Result<EcuListModel,void>::isFatalFail(aRStack_6c);
    if (iVar3 == 0) {
      pSVar5 = (Set *)State::Set::obd2RequestNotSupported();
      iVar3 = Result<EcuListModel,void>::isIn(aRStack_6c,pSVar5);
      if (iVar3 != 0) {
        FUN_01278d78(&local_e0);
        local_bc = local_e0;
        local_b8 = iStack_dc;
        local_e0 = 0;
        iStack_dc = 0;
        Progress::NUL((Progress *)&local_48);
        OperationDelegate::runCommand<EcuListModel>(asStack_90,in_r1);
        Result<EcuListModel,void>::operator=(aRStack_6c,(Result *)asStack_90);
        Result<EcuListModel,void>::~Result((Result<EcuListModel,void> *)asStack_90);
        FUN_011e01a0(&local_48);
        FUN_011f7fa8(&local_bc);
        FUN_01278da8(&local_e0);
      }
      addBatteryRegulToEcuList((Result *)asStack_90);
      Result<EcuListModel,void>::operator=(aRStack_6c,(Result *)asStack_90);
      Result<EcuListModel,void>::~Result((Result<EcuListModel,void> *)asStack_90);
    }
    Result<EcuListModel,void>::Result(this,(Result *)aRStack_6c);
    goto LAB_01278c3c;
  }
  (**(code **)(*(int *)in_r1 + 0x194))(asStack_90);
  iVar3 = Result<VagEcuInfo,void>::isFail((Result<VagEcuInfo,void> *)asStack_90);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*(int *)VagEcu::CAN_GATEWAY_MK8 + 0x10))
                      ((int *)VagEcu::CAN_GATEWAY_MK8,*(undefined4 *)(*local_74 + 8));
    local_bc = local_bc & 0xffffff00;
    FUN_01278f08(&local_98,&local_bc,*(undefined4 *)(*local_74 + 8));
    if (iVar3 == 0) {
      local_e0 = local_98;
      iStack_dc = iStack_94;
      if (iStack_94 != 0) {
        piVar4 = (int *)(iStack_94 + 4);
        do {
          ExclusiveAccess(piVar4);
          bVar1 = (bool)hasExclusiveAccess(piVar4);
        } while (!bVar1);
        *piVar4 = *piVar4 + 1;
      }
      Progress::NUL((Progress *)&local_e8);
      OperationDelegate::runCommand<EcuListModel>((shared_ptr *)&local_bc,in_r1);
    }
    else {
      local_e8 = local_98;
      iStack_e4 = iStack_94;
      if (iStack_94 != 0) {
        piVar4 = (int *)(iStack_94 + 4);
        do {
          ExclusiveAccess(piVar4);
          bVar1 = (bool)hasExclusiveAccess(piVar4);
        } while (!bVar1);
        *piVar4 = *piVar4 + 1;
      }
      Progress::NUL(aPStack_f0);
      OperationDelegate::runBroadcastCommand<EcuListModel>((shared_ptr *)&local_e0,in_r1);
      mergeMk8EcuList((BroadcastCommandResult *)&local_bc);
    }
    Result<EcuListModel,void>::operator=(aRStack_6c,(Result *)&local_bc);
    Result<EcuListModel,void>::~Result((Result<EcuListModel,void> *)&local_bc);
    if (iVar3 == 0) {
      FUN_011e01a0(&local_e8);
      puVar2 = &stack0x00000010;
    }
    else {
      Result<std::__ndk1::unordered_map<Ecu*,Result<EcuListModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EcuListModel,void>>>>,void>
      ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<EcuListModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EcuListModel,void>>>>,void>
                 *)&local_e0);
      FUN_011e01a0(aPStack_f0);
      puVar2 = &stack0x00000008;
    }
    FUN_011f7fa8(puVar2 + -0xf0);
    iVar6 = Result<EcuListModel,void>::isFail(aRStack_6c);
    if (iVar6 == 0) {
      addBatteryRegulToEcuList((Result *)&local_bc);
      Result<EcuListModel,void>::operator=(aRStack_6c,(Result *)&local_bc);
      Result<EcuListModel,void>::~Result((Result<EcuListModel,void> *)&local_bc);
      uVar7 = Result<EcuListModel,void>::isFail(aRStack_6c);
      if ((uVar7 | in_r2 ^ 1) == 1) goto LAB_01278b38;
      local_bc = CONCAT31(local_bc._1_3_,1);
      FUN_01278f08(&local_f8,&local_bc,*(undefined4 *)(*local_74 + 8));
      if (iVar3 == 0) {
        local_48 = local_f8;
        iStack_44 = iStack_f4;
        if (iStack_f4 != 0) {
          piVar4 = (int *)(iStack_f4 + 4);
          do {
            ExclusiveAccess(piVar4);
            bVar1 = (bool)hasExclusiveAccess(piVar4);
          } while (!bVar1);
          *piVar4 = *piVar4 + 1;
        }
        Progress::NUL((Progress *)&local_100);
        OperationDelegate::runCommand<EcuListModel>((shared_ptr *)&local_bc,in_r1);
        FUN_011e01a0(&local_100);
        puVar2 = &stack0x000000a8;
      }
      else {
        local_100 = local_f8;
        iStack_fc = iStack_f4;
        if (iStack_f4 != 0) {
          piVar4 = (int *)(iStack_f4 + 4);
          do {
            ExclusiveAccess(piVar4);
            bVar1 = (bool)hasExclusiveAccess(piVar4);
          } while (!bVar1);
          *piVar4 = *piVar4 + 1;
        }
        Progress::NUL(aPStack_108);
        OperationDelegate::runBroadcastCommand<EcuListModel>((shared_ptr *)&local_48,in_r1);
        mergeMk8EcuList((BroadcastCommandResult *)&local_bc);
        Result<std::__ndk1::unordered_map<Ecu*,Result<EcuListModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EcuListModel,void>>>>,void>
        ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<EcuListModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EcuListModel,void>>>>,void>
                   *)&local_48);
        FUN_011e01a0(aPStack_108);
        puVar2 = &stack0xfffffff0;
      }
      FUN_011f7fa8(puVar2 + -0xf0);
      iVar3 = Result<EcuListModel,void>::isFatalFail((Result<EcuListModel,void> *)&local_bc);
      if (iVar3 == 0) {
        iVar3 = Result<EcuListModel,void>::isFail((Result<EcuListModel,void> *)&local_bc);
        if (iVar3 != 0) {
          puVar2 = &stack0x00000084;
          goto LAB_01278bee;
        }
        EcuList::mergeUnique
                  ((EcuList *)&local_48,(EcuList *)(*local_50 + 4),(EcuList *)(*local_a0 + 4));
        FUN_00ce4398(&local_100,&local_48);
        Result<EcuListModel,void>::done(this,(shared_ptr *)&local_100);
        FUN_00ce43cc(&local_100);
        FUN_00ce44e8(&local_48);
      }
      else {
        puVar2 = &stack0x00000034;
LAB_01278bee:
        Result<EcuListModel,void>::Result(this,(Result *)(puVar2 + -0xf0));
      }
      Result<EcuListModel,void>::~Result((Result<EcuListModel,void> *)&local_bc);
      FUN_01279118(&local_f8);
    }
    else {
LAB_01278b38:
      Result<EcuListModel,void>::Result(this,(Result *)aRStack_6c);
    }
    FUN_01279118(&local_98);
  }
  else {
    Log::e("Failed to get UDS gateway part number, hence giving up on ECU list");
    Result<VagEcuInfo,void>::stateAs<EcuListModel,void>();
  }
  Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)asStack_90);
LAB_01278c3c:
  Result<EcuListModel,void>::~Result(aRStack_6c);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


