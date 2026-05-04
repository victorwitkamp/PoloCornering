/* ReadValuesOperation::addAvailableGenericTool @ 012ce5bc */


/* ReadValuesOperation::addAvailableGenericTool(SettingCategory*, std::__ndk1::shared_ptr<Setting>
   const&) */

void __thiscall
ReadValuesOperation::addAvailableGenericTool
          (ReadValuesOperation *this,SettingCategory *param_1,shared_ptr *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 local_54;
  int iStack_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int iStack_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  FUN_011e7154(local_30,param_2);
  piVar2 = (int *)FUN_012cd4cc(this + 0x7c,param_2);
  if (*piVar2 != 0) {
    iVar3 = (**(code **)(*(int *)this + 0x84))(this,param_2);
    if (iVar3 == 0) {
      uVar8 = 0;
      puVar9 = *(undefined4 **)(local_30[0] + 0x34);
      for (puVar6 = *(undefined4 **)(local_30[0] + 0x30); puVar6 != puVar9; puVar6 = puVar6 + 2) {
        local_44 = *puVar6;
        iStack_40 = puVar6[1];
        if (iStack_40 != 0) {
          piVar2 = (int *)(iStack_40 + 4);
          do {
            ExclusiveAccess(piVar2);
            bVar1 = (bool)hasExclusiveAccess(piVar2);
          } while (!bVar1);
          *piVar2 = *piVar2 + 1;
        }
        iVar3 = (**(code **)(*(int *)this + 0x94))(this,&local_44);
        FUN_00cc67b0(&local_44);
        if (iVar3 == 0) {
          uVar4 = (**(code **)(**(int **)param_2 + 8))();
          (**(code **)(**(int **)param_2 + 0x18))(&local_3c);
          if (((byte)local_3c._0_1_ & 1) == 0) {
            local_34 = (int)&local_3c + 1;
          }
          Log::w("Generic tool is unavailable: %s %s",uVar4,local_34);
          goto LAB_012ce7da;
        }
        uVar5 = (**(code **)(*(int *)this + 0x84))(this,puVar6);
        uVar8 = uVar8 | uVar5;
      }
      iVar7 = *(int *)(local_30[0] + 0x28);
      for (iVar3 = *(int *)(local_30[0] + 0x24); iVar3 != iVar7; iVar3 = iVar3 + 8) {
        FUN_011e3768(&local_3c,iVar3);
        if (local_3c != 0) {
          local_4c = local_3c;
          local_48 = local_38;
          if (local_38 != 0) {
            piVar2 = (int *)(local_38 + 4);
            do {
              ExclusiveAccess(piVar2);
              bVar1 = (bool)hasExclusiveAccess(piVar2);
            } while (!bVar1);
            *piVar2 = *piVar2 + 1;
          }
          addAvailableLiveDataTool(this,(SettingCategory *)0x0,(shared_ptr *)&local_4c);
          FUN_00cc67b0((shared_ptr *)&local_4c);
        }
        FUN_00ccc814(&local_3c);
      }
      local_54 = *(undefined4 *)param_2;
      iStack_50 = *(int *)(param_2 + 4);
      if (iStack_50 != 0) {
        piVar2 = (int *)(iStack_50 + 4);
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = *piVar2 + 1;
      }
      iVar3 = (**(code **)(*(int *)this + 0x94))(this,&local_54);
      FUN_00cc67b0(&local_54);
      if (iVar3 == 0) {
        uVar4 = (**(code **)(**(int **)param_2 + 8))();
        (**(code **)(**(int **)param_2 + 0x18))(&local_3c);
        if (((byte)local_3c._0_1_ & 1) == 0) {
          local_34 = (int)&local_3c + 1;
        }
        Log::w("Generic tool is unavailable: %s %s",uVar4,local_34);
      }
      else {
        (**(code **)(*(int *)this + 0xac))(this,param_1,param_2);
        if ((uVar8 & 1) == 0) {
          iVar3 = (**(code **)(*(int *)this + 0x84))(this,param_2);
        }
        else {
          iVar3 = 1;
        }
        puVar6 = (undefined4 *)FUN_012cd4cc(this + 0x7c,param_2);
        uVar4 = 2;
        if (iVar3 != 0) {
          uVar4 = 1;
        }
        *puVar6 = uVar4;
        uVar4 = (**(code **)(**(int **)param_2 + 8))();
        (**(code **)(**(int **)param_2 + 0x18))(&local_3c);
        if (((byte)local_3c._0_1_ & 1) == 0) {
          local_34 = (int)&local_3c + 1;
        }
        Log::w("Generic tool is available: %s %s",uVar4,local_34);
      }
    }
    else {
      uVar4 = (**(code **)(**(int **)param_2 + 8))();
      (**(code **)(**(int **)param_2 + 0x18))(&local_3c);
      if (((byte)local_3c._0_1_ & 1) == 0) {
        local_34 = (int)&local_3c + 1;
      }
      Log::w("Generic tool is unavailable(experimental in prod): %s %s",uVar4,local_34);
    }
LAB_012ce7da:
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_3c);
  }
  FUN_011e71a0(local_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


