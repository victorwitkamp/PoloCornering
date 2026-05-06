/* Target address 012ce858 */
/* Function addAvailableLiveDataTool @ 012ce858 */


/* ReadValuesOperation::addAvailableLiveDataTool(SettingCategory*, std::__ndk1::shared_ptr<Setting>
   const&) */

void __thiscall
ReadValuesOperation::addAvailableLiveDataTool
          (ReadValuesOperation *this,SettingCategory *param_1,shared_ptr *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 local_44;
  int iStack_40;
  undefined4 local_3c;
  int iStack_38;
  int local_34;
  LiveDataTool *local_30;
  int iStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  FUN_011e3768(&local_30,param_2);
  iVar3 = (**(code **)(*(int *)local_30 + 0x2c))();
  if (iVar3 == 0) {
    puVar5 = (undefined4 *)LiveDataTool::getParams(local_30);
    puVar9 = (undefined4 *)puVar5[1];
    bVar2 = false;
    uVar8 = 0;
    for (puVar5 = (undefined4 *)*puVar5; puVar5 != puVar9; puVar5 = puVar5 + 2) {
      local_44 = *puVar5;
      iStack_40 = puVar5[1];
      if (iStack_40 != 0) {
        piVar6 = (int *)(iStack_40 + 4);
        do {
          ExclusiveAccess(piVar6);
          bVar1 = (bool)hasExclusiveAccess(piVar6);
        } while (!bVar1);
        *piVar6 = *piVar6 + 1;
      }
      iVar3 = (**(code **)(*(int *)this + 0x94))(this,&local_44);
      FUN_00cc67b0(&local_44);
      if (iVar3 != 0) {
        uVar7 = (**(code **)(*(int *)this + 0x84))(this,puVar5);
        uVar8 = uVar8 | uVar7;
        bVar2 = true;
      }
    }
    if (bVar2) {
      if (param_1 != (SettingCategory *)0x0) {
        local_3c = local_30;
        iStack_38 = iStack_2c;
        if (iStack_2c != 0) {
          piVar6 = (int *)(iStack_2c + 4);
          do {
            ExclusiveAccess(piVar6);
            bVar2 = (bool)hasExclusiveAccess(piVar6);
          } while (!bVar2);
          *piVar6 = *piVar6 + 1;
        }
        (**(code **)(*(int *)this + 0xac))(this,param_1,&local_3c);
        FUN_00cc67b0(&local_3c);
      }
      local_3c = local_30;
      iStack_38 = iStack_2c;
      if (iStack_2c != 0) {
        piVar6 = (int *)(iStack_2c + 4);
        do {
          ExclusiveAccess(piVar6);
          bVar2 = (bool)hasExclusiveAccess(piVar6);
        } while (!bVar2);
        *piVar6 = *piVar6 + 1;
      }
      puVar5 = (undefined4 *)FUN_012cea48(this + 0x7c,&local_3c);
      uVar4 = 2;
      if ((uVar8 & 1) != 0) {
        uVar4 = 1;
      }
      *puVar5 = uVar4;
      FUN_00cc67b0(&local_3c);
      uVar4 = (**(code **)(*(int *)local_30 + 8))();
      (**(code **)(*(int *)local_30 + 0x18))(&local_3c);
      if (((uint)local_3c & 1) == 0) {
        local_34 = (int)&local_3c + 1;
      }
      Log::w("LiveDataTool is available: %s %s",uVar4,local_34);
    }
    else {
      uVar4 = (**(code **)(*(int *)local_30 + 8))();
      (**(code **)(*(int *)local_30 + 0x18))(&local_3c);
      if (((uint)local_3c & 1) == 0) {
        local_34 = (int)&local_3c + 1;
      }
      Log::w("LiveDataTool is unavailable: %s %s",uVar4,local_34);
    }
  }
  else {
    uVar4 = (**(code **)(*(int *)local_30 + 8))();
    (**(code **)(*(int *)local_30 + 0x18))(&local_3c);
    if (((uint)local_3c & 1) == 0) {
      local_34 = (int)&local_3c + 1;
    }
    Log::w("LiveDataTool is unavailable (experimental in prod): %s %s",uVar4,local_34);
  }
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_3c);
  FUN_00ccc814(&local_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


