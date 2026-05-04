/* VagOperationDelegate::writeVagCanAdaptationValueInternal @ 01272f14 */


/* VagOperationDelegate::writeVagCanAdaptationValueInternal(unsigned long long,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >,
   std::__ndk1::shared_ptr<Progress> const&) */

void VagOperationDelegate::writeVagCanAdaptationValueInternal
               (Result<BytesModel,void> *param_1,shared_ptr *param_2,undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 *param_6)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  Set *pSVar5;
  undefined2 *puVar6;
  int *piVar7;
  undefined1 local_1b9;
  uint local_1b8;
  uint uStack_1b4;
  undefined4 *local_19c;
  uint local_194;
  uint uStack_190;
  int local_188;
  undefined4 uStack_184;
  int local_180;
  undefined4 uStack_17c;
  uint local_178;
  uint uStack_174;
  uint local_154;
  uint uStack_150;
  int *local_13c;
  uint local_130;
  uint uStack_12c;
  int *local_118;
  uint local_10c;
  undefined4 local_108;
  shared_ptr asStack_e8 [39];
  byte bStack_c1;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined2 uStack_b2;
  int *local_b0;
  int iStack_ac;
  Result<BytesModel,void> aRStack_a8 [28];
  uint *local_8c;
  Result<EmptyModel,void> aRStack_84 [24];
  int *local_6c;
  undefined **local_60;
  int *local_5c;
  int iStack_58;
  undefined ***local_50;
  RunOnScopeExit aRStack_48 [32];
  int local_28;
  
  local_28 = __stack_chk_guard;
  Result<EmptyModel,void>::Result(aRStack_84);
  Result<BytesModel,void>::Result(aRStack_a8);
  (**(code **)(*(int *)*param_6 + 0x24))(&local_b0,(int *)*param_6,8);
  iVar3 = (**(code **)(*(int *)param_2 + 0x15c))
                    (param_2,*(code **)(*(int *)param_2 + 0x15c),param_3,param_4);
  puVar6 = &ReadVagCanShortAdaptationDataCommand::SHORT_ADAPTATION_BASIC_ID;
  if (iVar3 == 1) {
    puVar6 = &ReadVagCanLongAdaptationDataCommand::LONG_ADAPTATION_BASIC_ID;
  }
  uStack_b2 = *puVar6;
  if (iStack_ac == 0) {
    iStack_ac = 0;
  }
  else {
    piVar7 = (int *)(iStack_ac + 4);
    do {
      ExclusiveAccess(piVar7);
      bVar1 = (bool)hasExclusiveAccess(piVar7);
    } while (!bVar1);
    *piVar7 = *piVar7 + 1;
  }
  local_5c = local_b0;
  local_bc = 0;
  local_b8 = 0;
  local_50 = &local_60;
  local_60 = &PTR_FUN_012817a0_1_014bac3c;
  iStack_58 = iStack_ac;
  RunOnScopeExit::RunOnScopeExit(aRStack_48);
  FUN_00d2682a(&local_60);
  FUN_00d2b90c(&local_bc);
  local_c0 = (**(code **)(*(int *)param_2 + 0x154))
                       (param_2,*(code **)(*(int *)param_2 + 0x154),param_3,param_4);
  uVar2 = (**(code **)(*(int *)param_2 + 0x158))
                    (param_2,*(code **)(*(int *)param_2 + 0x158),param_3,param_4);
  bStack_c1 = Math::toExact<unsigned_char,unsigned_short>(uVar2);
  FUN_01272840(&local_130,&local_c0,&uStack_b2);
  local_10c = local_130;
  local_108 = uStack_12c;
  local_130 = 0;
  uStack_12c = 0;
  OperationDelegate::runCommand<EmptyModel>(asStack_e8,param_2);
  FUN_011e4048(&local_10c);
  FUN_01272874(&local_130);
  (**(code **)(*local_b0 + 0x2c))();
  iVar4 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)asStack_e8);
  if (iVar4 != 0) {
    Log::e("Failed to start write routine for channel %d",(uint)bStack_c1);
    Result<EmptyModel,void>::stateAs<BytesModel,void>();
    goto LAB_012731a6;
  }
  local_178 = local_178 & 0xffffff00;
  FUN_01272888(&local_154,&local_c0,&uStack_b2,&local_178);
  local_130 = local_154;
  uStack_12c = uStack_150;
  local_154 = 0;
  uStack_150 = 0;
  OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_10c,param_2);
  FUN_011e4048(&local_130);
  FUN_012728c4(&local_154);
  (**(code **)(*local_b0 + 0x2c))();
  iVar4 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)&local_10c);
  if (iVar4 == 0) {
    local_1b8 = local_1b8 & 0xffffff00;
    FUN_012728d8(&local_178,&local_c0,&uStack_b2,&bStack_c1,&local_1b8);
    local_154 = local_178;
    uStack_150 = uStack_174;
    local_178 = 0;
    uStack_174 = 0;
    OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_130,param_2);
    Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)asStack_e8,(Result *)&local_130);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_130);
    FUN_011e4048(&local_154);
    FUN_01272918(&local_178);
    (**(code **)(*local_b0 + 0x2c))();
    pSVar5 = (Set *)State::Set::obd2NegativeResponse();
    iVar4 = Result<EmptyModel,void>::isIn((Result<EmptyModel,void> *)asStack_e8,pSVar5);
    if (iVar4 == 0) {
      iVar4 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)asStack_e8);
      if (iVar4 != 0) {
        Log::e("Failed to set adaptation channel %d",(uint)bStack_c1);
        goto LAB_0127319a;
      }
      Result<BytesModel,void>::Result((Result<BytesModel,void> *)&local_130);
      if (iVar3 == 0) {
        local_194 = (uint)local_194._1_3_ << 8;
        FUN_0127293c(&local_1b8,&local_c0,&local_194);
        local_178 = local_1b8;
        uStack_174 = uStack_1b4;
        local_1b8 = 0;
        uStack_1b4 = 0;
        OperationDelegate::runCommand<BytesModel>((shared_ptr *)&local_154,param_2);
        Result<BytesModel,void>::operator=
                  ((Result<BytesModel,void> *)&local_130,(Result *)&local_154);
        Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_154);
        FUN_011e4f74(&local_178);
        FUN_01272970(&local_1b8);
      }
      else {
        local_194 = (uint)local_194._1_3_ << 8;
        FUN_01272984(&local_1b8,&local_c0,&local_194);
        local_178 = local_1b8;
        uStack_174 = uStack_1b4;
        local_1b8 = 0;
        uStack_1b4 = 0;
        OperationDelegate::runCommand<BytesModel>((shared_ptr *)&local_154,param_2);
        Result<BytesModel,void>::operator=
                  ((Result<BytesModel,void> *)&local_130,(Result *)&local_154);
        Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_154);
        FUN_011e4f74(&local_178);
        FUN_012729b8(&local_1b8);
      }
      (**(code **)(*local_b0 + 0x2c))();
      iVar4 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_130);
      if (iVar4 == 0) {
        bVar1 = false;
        local_194 = local_194 & 0xffffff00;
        FUN_01273680(&local_1b8,&local_c0,&uStack_b2,param_5,&local_194);
        local_178 = local_1b8;
        uStack_174 = uStack_1b4;
        local_1b8 = 0;
        uStack_1b4 = 0;
        OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_154,param_2);
        FUN_011e4048(&local_178);
        FUN_012736c0(&local_1b8);
        (**(code **)(*local_b0 + 0x2c))();
        iVar4 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)&local_154);
        if (iVar4 == 0) {
          if (iVar3 == 0) {
            local_180 = (uint)local_180._1_3_ << 8;
            FUN_0127293c(&local_194,&local_c0,&local_180);
            local_1b8 = local_194;
            uStack_1b4 = uStack_190;
            local_194 = 0;
            uStack_190 = 0;
            OperationDelegate::runCommand<BytesModel>((shared_ptr *)&local_178,param_2);
            Result<BytesModel,void>::operator=(aRStack_a8,(Result *)&local_178);
            Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_178);
            FUN_011e4f74(&local_1b8);
            FUN_01272970(&local_194);
          }
          else {
            local_180 = (uint)local_180._1_3_ << 8;
            FUN_01272984(&local_194,&local_c0,&local_180);
            local_1b8 = local_194;
            uStack_1b4 = uStack_190;
            local_194 = 0;
            uStack_190 = 0;
            OperationDelegate::runCommand<BytesModel>((shared_ptr *)&local_178,param_2);
            Result<BytesModel,void>::operator=(aRStack_a8,(Result *)&local_178);
            Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_178);
            FUN_011e4f74(&local_1b8);
            FUN_012729b8(&local_194);
          }
          (**(code **)(*local_b0 + 0x2c))();
          iVar3 = Result<BytesModel,void>::isFail(aRStack_a8);
          if (iVar3 == 0) {
            (**(code **)(*(int *)param_2 + 0x1f8))(&local_1b8,param_2,local_c0);
            (**(code **)(*(int *)*local_19c + 0x14))(&local_194);
            local_1b9 = 0;
            FUN_012736e0(&local_188,&local_c0,&uStack_b2,param_5,&local_194,&local_1b9);
            local_180 = local_188;
            uStack_17c = uStack_184;
            local_188 = 0;
            uStack_184 = 0;
            OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_178,param_2);
            Result<EmptyModel,void>::operator=(aRStack_84,(Result *)&local_178);
            Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_178);
            FUN_011e4048(&local_180);
            FUN_01273728(&local_188);
            FUN_00cb7f50(&local_194);
            Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_1b8);
            (**(code **)(*local_b0 + 0x2c))();
            iVar3 = Result<EmptyModel,void>::isFail(aRStack_84);
            if (iVar3 != 0) {
              Log::w("Failed to write data for channel %d",(uint)bStack_c1);
              iVar3 = State::isFatalError(*local_6c);
              if (iVar3 != 0) {
LAB_01273394:
                Result<EmptyModel,void>::stateAs<BytesModel,void>();
                goto LAB_0127345a;
              }
              if (*local_6c == -0x11) {
                ThreadUtils::sleep(2000);
                EmptyModel::EmptyModel((EmptyModel *)&local_1b8);
                Result<EmptyModel,void>::done<EmptyModel>((type *)&local_178);
                Result<EmptyModel,void>::operator=(aRStack_84,(Result *)&local_178);
                Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_178);
                EmptyModel::~EmptyModel((EmptyModel *)&local_1b8);
              }
              else if (*local_6c == -0xb) goto LAB_01273394;
            }
            bVar1 = false;
          }
          else {
            Log::w("Failed to do intermediate read for channel %d",(uint)bStack_c1);
            Result<BytesModel,void>::stateAs<BytesModel,void>();
LAB_0127345a:
            bVar1 = true;
          }
        }
        else {
          Log::w("Failed to write data for channel %d",(uint)bStack_c1);
          iVar3 = State::isFatalError(*local_13c);
          if ((iVar3 != 0) || (*local_13c == -0xb)) goto LAB_01273394;
          Result<EmptyModel,void>::operator=(aRStack_84,(Result *)&local_154);
        }
        Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_154);
      }
      else {
        Log::w("Failed to do intermediate read for channel %d",(uint)bStack_c1);
        pSVar5 = (Set *)State::Set::obd2NegativeResponse();
        iVar3 = Result<BytesModel,void>::isIn((Result<BytesModel,void> *)&local_130,pSVar5);
        if (iVar3 == 0) {
          iVar3 = *local_118;
        }
        else {
          iVar3 = -0x18;
        }
        Result<BytesModel,void>::Result(param_1,iVar3);
        bVar1 = true;
      }
      Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_130);
      if (!bVar1) goto LAB_01273124;
    }
    else {
      Log::d("Channel %d is not supported.",(uint)bStack_c1);
      Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)&local_130,-0x18);
      Result<EmptyModel,void>::operator=(aRStack_84,(Result *)&local_130);
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_130);
LAB_01273124:
      local_1b8 = local_1b8 & 0xffffff00;
      FUN_012729cc(&local_178,&local_c0,&uStack_b2,&local_1b8);
      local_154 = local_178;
      uStack_150 = uStack_174;
      local_178 = 0;
      uStack_174 = 0;
      OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_130,param_2);
      Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)asStack_e8,(Result *)&local_130)
      ;
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_130);
      FUN_011e4048(&local_154);
      FUN_01272a08(&local_178);
      iVar3 = Result<EmptyModel,void>::isFatalFail((Result<EmptyModel,void> *)asStack_e8);
      if (iVar3 != 0) {
        Log::w("Could not close channel %d; fatal fail, bailing.",(uint)bStack_c1);
        goto LAB_0127319a;
      }
      iVar3 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)asStack_e8);
      if (iVar3 != 0) {
        Log::w("Could not close channel %d; continuing.",(uint)bStack_c1);
      }
      iVar4 = *local_6c;
      iVar3 = Result<EmptyModel,void>::isFail(aRStack_84);
      if (iVar3 == 0) {
        local_130 = *local_8c;
        uStack_12c = local_8c[1];
        if (uStack_12c != 0) {
          piVar7 = (int *)(uStack_12c + 4);
          do {
            ExclusiveAccess(piVar7);
            bVar1 = (bool)hasExclusiveAccess(piVar7);
          } while (!bVar1);
          *piVar7 = *piVar7 + 1;
        }
      }
      else {
        local_130 = 0;
        uStack_12c = 0;
      }
      Result<BytesModel,void>::Result(param_1,iVar4,(shared_ptr *)&local_130);
      FUN_00ce0c34((shared_ptr *)&local_130);
    }
  }
  else {
    Log::w("Failed to do intermediate read for channel %d",(uint)bStack_c1);
LAB_0127319a:
    Result<EmptyModel,void>::stateAs<BytesModel,void>();
  }
  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_10c);
LAB_012731a6:
  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_e8);
  RunOnScopeExit::~RunOnScopeExit(aRStack_48);
  FUN_00d2b90c(&local_b0);
  Result<BytesModel,void>::~Result(aRStack_a8);
  Result<EmptyModel,void>::~Result(aRStack_84);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


