/* VagOperationDelegate::readCanServiceIndicators @ 012746d4 */


/* VagOperationDelegate::readCanServiceIndicators() */

void VagOperationDelegate::readCanServiceIndicators(void)

{
  bool bVar1;
  Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
  *in_r0;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  VagOperationDelegate *in_r1;
  int iVar5;
  undefined1 uStack_a1;
  uint local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int iStack_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  int iStack_78;
  undefined1 auStack_74 [12];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int iStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  int local_40 [4];
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_44 = 0;
  local_4c = 0;
  uStack_48 = 0;
  local_9c = 0;
  local_5c = 0;
  local_58 = 0;
  local_64 = 0;
  local_60 = 0;
  local_68 = 2;
  VagCanTools::getCanServiceIndicator((VagCanTools *)local_40);
  local_84 = 0;
  local_80 = 0x28;
  FUN_01274a7c(&local_7c,&VagCanEcu::INSTRUMENT_CLUSTER,&VagWhitelists::INSTRUMENTS_VAG_CAN,
               &local_80,"car_tool_oil_service_distance_since_service",&local_84);
  local_40[2] = local_7c;
  local_40[3] = iStack_78;
  local_7c = 0;
  iStack_78 = 0;
  local_94 = 0;
  local_90 = 0x29;
  FUN_01274ac4(&local_8c,&VagCanEcu::INSTRUMENT_CLUSTER,&VagWhitelists::INSTRUMENTS_VAG_CAN,
               &local_90,"car_tool_oil_service_time_since_service",&local_94);
  local_30 = local_8c;
  uStack_2c = iStack_88;
  local_8c = 0;
  iStack_88 = 0;
  uVar2 = FUN_00ccc640(auStack_74,local_40,3);
  local_a0 = local_a0 & 0xffffff00;
  FUN_01274a20(&local_54,&VagCanEcu::INSTRUMENT_CLUSTER,"car_tool_oil_service_due_indicator",
               &local_9c,&local_58,&local_5c,&local_60,&local_64,&local_68,uVar2,&local_a0);
  FUN_00ccc71c(auStack_74);
  iVar5 = 0x10;
  do {
    FUN_00cc67b0((int)local_40 + iVar5);
    iVar5 = iVar5 + -8;
  } while (iVar5 != -8);
  FUN_010bc00e(&local_8c);
  FUN_010bc00e(&local_7c);
  iVar5 = readIndicatorValues(in_r1,(shared_ptr *)&local_54);
  iVar3 = State::isError(iVar5);
  if (iVar3 == 0) {
    local_40[0] = local_54;
    local_40[1] = iStack_50;
    if (iStack_50 != 0) {
      piVar4 = (int *)(iStack_50 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar1 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar1);
      *piVar4 = *piVar4 + 1;
    }
    FUN_00cec6f2(&local_4c,local_40);
    FUN_00cec774(local_40);
    local_80 = 2;
    local_58 = 0;
    local_60 = 0;
    local_5c = 0;
    local_68 = 0;
    local_64 = 0;
    local_84 = 0x35;
    local_90 = 0;
    FUN_01274b68(&local_8c,&VagCanEcu::INSTRUMENT_CLUSTER,&VagWhitelists::INSTRUMENTS_VAG_CAN,
                 &local_84,"car_tool_oil_service_distance_since_insp",&local_90);
    local_40[0] = local_8c;
    local_40[1] = iStack_88;
    local_8c = 0;
    iStack_88 = 0;
    local_94 = 0x37;
    local_a0 = 0;
    FUN_01274bb0(&local_9c,&VagCanEcu::INSTRUMENT_CLUSTER,&VagWhitelists::INSTRUMENTS_VAG_CAN,
                 &local_94,"car_tool_oil_service_time_since_insp",&local_a0);
    local_40[2] = local_9c;
    local_40[3] = uStack_98;
    local_9c = 0;
    uStack_98 = 0;
    uVar2 = FUN_00ccc640(auStack_74,local_40,2);
    uStack_a1 = 0;
    FUN_01274b0c(&local_7c,&VagCanEcu::INSTRUMENT_CLUSTER,"car_tool_inspection_reset",&local_58,
                 &local_5c,&local_60,&local_64,&local_68,&local_80,uVar2,&uStack_a1);
    FUN_00ccc71c(auStack_74);
    iVar5 = 8;
    do {
      FUN_00cc67b0((int)local_40 + iVar5);
      iVar5 = iVar5 + -8;
    } while (iVar5 != -8);
    FUN_010bc00e(&local_9c);
    FUN_010bc00e(&local_8c);
    iVar5 = readIndicatorValues(in_r1,(shared_ptr *)&local_7c);
    iVar3 = State::isFatalError(iVar5);
    if (iVar3 == 0) {
      iVar5 = State::isError(iVar5);
      if (iVar5 == 0) {
        local_40[0] = local_7c;
        local_40[1] = iStack_78;
        if (iStack_78 != 0) {
          piVar4 = (int *)(iStack_78 + 4);
          do {
            ExclusiveAccess(piVar4);
            bVar1 = (bool)hasExclusiveAccess(piVar4);
          } while (!bVar1);
          *piVar4 = *piVar4 + 1;
        }
        FUN_00cec6f2(&local_4c,local_40);
        FUN_00cec774(local_40);
      }
      Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
      ::
      done<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>>
                ((type *)in_r0);
    }
    else {
      Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
      ::Result(in_r0,iVar5);
    }
    FUN_01274bf8(&local_7c);
  }
  else {
    Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
    ::Result(in_r0,iVar5);
  }
  FUN_01274bf8(&local_54);
  FUN_00cec824(&local_4c);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


