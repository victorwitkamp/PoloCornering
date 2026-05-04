/* VagOperationDelegate::readUdsServiceIndicators @ 01274c0c */


/* VagOperationDelegate::readUdsServiceIndicators() */

void VagOperationDelegate::readUdsServiceIndicators(void)

{
  bool bVar1;
  Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
  *in_r0;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  VagOperationDelegate *in_r1;
  undefined1 uStack_ad;
  undefined4 local_ac;
  undefined4 local_a8 [3];
  undefined4 local_9c;
  undefined2 uStack_96;
  int local_94;
  int iStack_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  int local_7c;
  int iStack_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  int iStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 uStack_4e;
  undefined4 local_4c;
  int iStack_48;
  int local_44 [4];
  int local_34;
  int iStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_58 = 0;
  local_60 = 0;
  uStack_5c = 0;
  local_a8[0] = 0;
  local_74 = 0;
  local_7c = 0;
  local_94 = 0;
  local_4c = 0;
  local_6c = 2;
  VagCanTools::getUdsServiceIndicator((VagCanTools *)&local_34);
  uVar2 = FUN_00ccc640(local_44,&local_34,1);
  local_80 = local_80 & 0xffffff00;
  FUN_012750a4(&local_68,&VagUdsEcu::INSTRUMENT_CLUSTER,"car_tool_oil_service_due_indicator",
               local_a8,&local_74,&local_7c,&local_94,&local_4c,&local_6c,uVar2,&local_80);
  FUN_00ccc71c(local_44);
  FUN_00cc67b0(&local_34);
  iVar3 = readIndicatorValues(in_r1,(shared_ptr *)&local_68);
  iVar4 = State::isError(iVar3);
  if (iVar4 == 0) {
    local_44[0] = local_68;
    local_44[1] = iStack_64;
    if (iStack_64 != 0) {
      piVar5 = (int *)(iStack_64 + 4);
      do {
        ExclusiveAccess(piVar5);
        bVar1 = (bool)hasExclusiveAccess(piVar5);
      } while (!bVar1);
      *piVar5 = *piVar5 + 1;
    }
    FUN_00cec6f2(&local_60,local_44);
    FUN_00cec774(local_44);
    local_94 = CONCAT22(local_94._2_2_,0x22a7);
    local_a8[0] = 0;
    local_4c = CONCAT22(local_4c._2_2_,0xffff);
    uVar2 = FUN_00cdb87c(local_44,&local_4c,2);
    local_7c = 0;
    FUN_01275100(&local_34,&VagUdsEcu::INSTRUMENT_CLUSTER,&VagWhitelists::INSTRUMENTS_VAG_UDS,
                 &local_94,local_a8,uVar2,"car_tool_oil_service_time_since_insp",&local_7c);
    local_74 = local_34;
    local_70 = iStack_30;
    local_34 = 0;
    iStack_30 = 0;
    FUN_010bbffc(&local_34);
    FUN_00cb7f50(local_44);
    local_4c = 0;
    local_8c = 2;
    local_44[0] = local_74;
    local_6c = 0;
    local_80 = 0;
    local_88 = 0;
    local_84 = 0;
    local_44[1] = local_70;
    if (local_70 != 0) {
      piVar5 = (int *)(local_70 + 4);
      do {
        ExclusiveAccess(piVar5);
        bVar1 = (bool)hasExclusiveAccess(piVar5);
      } while (!bVar1);
      *piVar5 = *piVar5 + 1;
    }
    uStack_96 = 0x22a6;
    local_54 = CONCAT13(local_54._3_1_,0xff0000);
    local_9c = 0;
    local_54 = CONCAT22(local_54._2_2_,0xffff);
    uVar2 = FUN_00cdb87c(local_a8,&local_54,3);
    local_ac = 0;
    FUN_012751ac(&local_94,&VagUdsEcu::INSTRUMENT_CLUSTER,&VagWhitelists::INSTRUMENTS_VAG_UDS,
                 &uStack_96,&local_9c,uVar2,"car_tool_oil_service_distance_since_insp",&local_ac);
    local_44[2] = local_94;
    local_44[3] = iStack_90;
    local_94 = 0;
    iStack_90 = 0;
    uVar2 = FUN_00ccc640(&local_34,local_44,2);
    uStack_4e = (ushort)uStack_4e._1_1_ << 8;
    FUN_01275150(&local_7c,&VagUdsEcu::INSTRUMENT_CLUSTER,"car_tool_inspection_reset",&local_4c,
                 &local_6c,&local_80,&local_84,&local_88,&local_8c,uVar2,&uStack_4e);
    FUN_00ccc71c(&local_34);
    iVar3 = 8;
    do {
      FUN_00cc67b0((int)local_44 + iVar3);
      iVar3 = iVar3 + -8;
    } while (iVar3 != -8);
    FUN_010bbffc(&local_94);
    FUN_00cb7f50(local_a8);
    iVar3 = readIndicatorValues(in_r1,(shared_ptr *)&local_7c);
    iVar4 = State::isFatalError(iVar3);
    if (iVar4 == 0) {
      if (iVar3 == 1) {
        local_44[0] = local_7c;
        local_44[1] = iStack_78;
        if (iStack_78 != 0) {
          piVar5 = (int *)(iStack_78 + 4);
          do {
            ExclusiveAccess(piVar5);
            bVar1 = (bool)hasExclusiveAccess(piVar5);
          } while (!bVar1);
          *piVar5 = *piVar5 + 1;
        }
        FUN_00cec6f2(&local_60,local_44);
        FUN_00cec774(local_44);
        Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
        ::
        done<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>>
                  ((type *)in_r0);
      }
      else {
        local_9c = 2;
        local_6c = 0;
        local_84 = 0;
        local_80 = 0;
        local_8c = 0;
        local_88 = 0;
        local_44[0] = local_74;
        local_44[1] = local_70;
        if (local_70 != 0) {
          piVar5 = (int *)(local_70 + 4);
          do {
            ExclusiveAccess(piVar5);
            bVar1 = (bool)hasExclusiveAccess(piVar5);
          } while (!bVar1);
          *piVar5 = *piVar5 + 1;
        }
        local_ac = 0;
        uStack_96 = 0x22a6;
        uStack_4e = -1;
        uVar2 = FUN_00cdb87c(local_a8,&uStack_4e,2);
        local_54 = 0;
        FUN_012751ac(&local_4c,&VagUdsEcu::INSTRUMENT_CLUSTER,&VagWhitelists::INSTRUMENTS_VAG_UDS,
                     &uStack_96,&local_ac,uVar2,"car_tool_oil_service_distance_since_insp",&local_54
                    );
        local_44[2] = local_4c;
        local_44[3] = iStack_48;
        local_4c = 0;
        iStack_48 = 0;
        uVar2 = FUN_00ccc640(&local_34,local_44,2);
        uStack_ad = 0;
        FUN_01275150(&local_94,&VagUdsEcu::INSTRUMENT_CLUSTER,"car_tool_inspection_reset",&local_6c,
                     &local_80,&local_84,&local_88,&local_8c,&local_9c,uVar2,&uStack_ad);
        FUN_00ccc71c(&local_34);
        iVar3 = 8;
        do {
          FUN_00cc67b0((int)local_44 + iVar3);
          iVar3 = iVar3 + -8;
        } while (iVar3 != -8);
        FUN_010bbffc(&local_4c);
        FUN_00cb7f50(local_a8);
        iVar3 = readIndicatorValues(in_r1,(shared_ptr *)&local_94);
        iVar4 = State::isFatalError(iVar3);
        if (iVar4 == 0) {
          if (iVar3 == 1) {
            local_44[0] = local_94;
            local_44[1] = iStack_90;
            if (iStack_90 != 0) {
              piVar5 = (int *)(iStack_90 + 4);
              do {
                ExclusiveAccess(piVar5);
                bVar1 = (bool)hasExclusiveAccess(piVar5);
              } while (!bVar1);
              *piVar5 = *piVar5 + 1;
            }
            FUN_00cec6f2(&local_60,local_44);
            FUN_00cec774(local_44);
          }
          Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
          ::
          done<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>>
                    ((type *)in_r0);
        }
        else {
          Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
          ::Result(in_r0,iVar3);
        }
        FUN_01274bf8(&local_94);
      }
    }
    else {
      Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
      ::Result(in_r0,iVar3);
    }
    FUN_01274bf8(&local_7c);
    FUN_00cc67b0(&local_74);
  }
  else {
    Result<std::__ndk1::vector<std::__ndk1::shared_ptr<ServiceIndicator>,std::__ndk1::allocator<std::__ndk1::shared_ptr<ServiceIndicator>>>,void>
    ::Result(in_r0,iVar3);
  }
  FUN_01274bf8(&local_68);
  FUN_00cec824(&local_60);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


