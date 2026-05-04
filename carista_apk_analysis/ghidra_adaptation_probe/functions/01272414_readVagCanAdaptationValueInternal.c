/* VagOperationDelegate::readVagCanAdaptationValueInternal @ 01272414 */


/* VagOperationDelegate::readVagCanAdaptationValueInternal(unsigned long long) */

void VagOperationDelegate::readVagCanAdaptationValueInternal(ulonglong param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  Set *pSVar4;
  shared_ptr *psVar5;
  undefined2 *puVar6;
  Progress local_d4 [11];
  undefined1 uStack_c9;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_78;
  undefined4 uStack_74;
  shared_ptr asStack_70 [38];
  undefined2 uStack_4a;
  Result<BytesModel,void> aRStack_48 [24];
  int *local_30;
  int *local_2c;
  byte bStack_21;
  undefined4 local_20;
  int local_1c;
  
  psVar5 = (shared_ptr *)(param_1 >> 0x20);
  local_1c = __stack_chk_guard;
  local_20 = (**(code **)(*(int *)psVar5 + 0x154))(psVar5);
  uVar1 = (**(code **)(*(int *)psVar5 + 0x158))(psVar5);
  bStack_21 = Math::toExact<unsigned_char,unsigned_short>(uVar1);
  Result<BytesModel,void>::Result(aRStack_48);
  iVar2 = (**(code **)(*(int *)psVar5 + 0x15c))(psVar5);
  puVar6 = &ReadVagCanShortAdaptationDataCommand::SHORT_ADAPTATION_BASIC_ID;
  if (iVar2 == 1) {
    puVar6 = &ReadVagCanLongAdaptationDataCommand::LONG_ADAPTATION_BASIC_ID;
  }
  uStack_4a = *puVar6;
  FUN_01272840(&local_c8,&local_20,&uStack_4a);
  local_9c = local_c8;
  local_98 = uStack_c4;
  local_c8 = 0;
  uStack_c4 = 0;
  Progress::NUL((Progress *)&local_78);
  OperationDelegate::runCommand<EmptyModel>(asStack_70,psVar5);
  FUN_011e01a0(&local_78);
  FUN_011e4048(&local_9c);
  FUN_01272874(&local_c8);
  iVar3 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)asStack_70);
  if (iVar3 != 0) {
    Log::w("Failed to start read routine for channel %d.",(uint)bStack_21);
    Result<EmptyModel,void>::stateAs<BytesModel,void>();
    goto LAB_01272744;
  }
  local_d4[0] = (Progress)0x0;
  FUN_01272888(&local_78,&local_20,&uStack_4a,local_d4);
  local_c8 = local_78;
  uStack_c4 = uStack_74;
  local_78 = 0;
  uStack_74 = 0;
  Progress::NUL((Progress *)&local_a4);
  OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_9c,psVar5);
  FUN_011e01a0(&local_a4);
  FUN_011e4048(&local_c8);
  FUN_012728c4(&local_78);
  iVar3 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)&local_9c);
  if (iVar3 == 0) {
    uStack_c9 = 0;
    FUN_012728d8(&local_a4,&local_20,&uStack_4a,&bStack_21,&uStack_c9);
    local_78 = local_a4;
    uStack_74 = uStack_a0;
    local_a4 = 0;
    uStack_a0 = 0;
    Progress::NUL(local_d4);
    OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_c8,psVar5);
    Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)asStack_70,(Result *)&local_c8);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_c8);
    FUN_011e01a0(local_d4);
    FUN_011e4048(&local_78);
    FUN_01272918(&local_a4);
    pSVar4 = (Set *)State::Set::obd2NegativeResponse();
    iVar3 = Result<EmptyModel,void>::isIn((Result<EmptyModel,void> *)asStack_70,pSVar4);
    if (iVar3 != 0) {
      Log::d("Channel %d is not supported; skipping.",(uint)bStack_21);
      Result<EmptyModel,void>::failAs<BytesModel>();
      Result<BytesModel,void>::operator=(aRStack_48,(Result *)&local_c8);
      Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_c8);
      goto LAB_012725c6;
    }
    iVar3 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)asStack_70);
    if (iVar3 != 0) {
      Log::e("Failed to set adaptation channel %d",(uint)bStack_21);
      goto LAB_01272656;
    }
    if (iVar2 == 0) {
      uStack_c9 = 0;
      FUN_0127293c(&local_a4,&local_20,&uStack_c9);
      local_78 = local_a4;
      uStack_74 = uStack_a0;
      local_a4 = 0;
      uStack_a0 = 0;
      Progress::NUL(local_d4);
      OperationDelegate::runCommand<BytesModel>((shared_ptr *)&local_c8,psVar5);
      Result<BytesModel,void>::operator=(aRStack_48,(Result *)&local_c8);
      Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_c8);
      FUN_011e01a0(local_d4);
      FUN_011e4f74(&local_78);
      FUN_01272970(&local_a4);
    }
    else {
      uStack_c9 = 0;
      FUN_01272984(&local_a4,&local_20,&uStack_c9);
      local_78 = local_a4;
      uStack_74 = uStack_a0;
      local_a4 = 0;
      uStack_a0 = 0;
      Progress::NUL(local_d4);
      OperationDelegate::runCommand<BytesModel>((shared_ptr *)&local_c8,psVar5);
      Result<BytesModel,void>::operator=(aRStack_48,(Result *)&local_c8);
      Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_c8);
      FUN_011e01a0(local_d4);
      FUN_011e4f74(&local_78);
      FUN_012729b8(&local_a4);
    }
    iVar2 = Result<BytesModel,void>::isFail(aRStack_48);
    if ((iVar2 == 0) && (*local_2c != 0)) {
LAB_012725c6:
      uStack_c9 = 0;
      FUN_012729cc(&local_a4,&local_20,&uStack_4a,&uStack_c9);
      local_78 = local_a4;
      uStack_74 = uStack_a0;
      local_a4 = 0;
      uStack_a0 = 0;
      Progress::NUL(local_d4);
      OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_c8,psVar5);
      Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)asStack_70,(Result *)&local_c8);
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_c8);
      FUN_011e01a0(local_d4);
      FUN_011e4048(&local_78);
      FUN_01272a08(&local_a4);
      iVar2 = Result<EmptyModel,void>::isFatalFail((Result<EmptyModel,void> *)asStack_70);
      if (iVar2 != 0) goto LAB_01272656;
      iVar2 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)asStack_70);
      if (iVar2 != 0) {
        Log::w("Could not close channel %d; continuing.",(uint)bStack_21);
      }
    }
    else {
      Log::w("Failed to read data for channel %d",(uint)bStack_21);
      iVar2 = State::isFatalError(*local_30);
      if ((iVar2 == 0) && (*local_30 != -0xb)) goto LAB_012725c6;
    }
    Result<BytesModel,void>::Result((Result<BytesModel,void> *)param_1,aRStack_48);
  }
  else {
    Log::w("Failed to do intermediate read for channel %d.",(uint)bStack_21);
LAB_01272656:
    Result<EmptyModel,void>::stateAs<BytesModel,void>();
  }
  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_9c);
LAB_01272744:
  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_70);
  Result<BytesModel,void>::~Result(aRStack_48);
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


