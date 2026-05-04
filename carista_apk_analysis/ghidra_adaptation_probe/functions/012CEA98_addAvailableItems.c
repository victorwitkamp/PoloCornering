/* ReadValuesOperation::addAvailableItems @ 012cea98 */


/* ReadValuesOperation::addAvailableItems(std::__ndk1::unordered_map<SettingCategory*,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > >, std::__ndk1::hash<SettingCategory*>,
   std::__ndk1::equal_to<SettingCategory*>,
   std::__ndk1::allocator<std::__ndk1::pair<SettingCategory* const,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > > > > const&) */

void ReadValuesOperation::addAvailableItems(unordered_map *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_r1;
  int in_r2;
  int in_r3;
  int unaff_r5;
  shared_ptr *psVar5;
  shared_ptr *psVar6;
  int *piVar7;
  int local_40;
  int iStack_3c;
  int local_38;
  
  iVar2 = __stack_chk_guard;
  piVar7 = (int *)(in_r1 + 8);
  local_40 = in_r1;
  iStack_3c = in_r2;
  local_38 = in_r3;
  while (piVar7 = (int *)*piVar7, piVar7 != (int *)0x0) {
    psVar6 = (shared_ptr *)piVar7[4];
    for (psVar5 = (shared_ptr *)piVar7[3]; psVar5 != psVar6; psVar5 = psVar5 + 8) {
      FUN_011e3768(&stack0xffffffd0,psVar5);
      if (unaff_r5 == 0) {
        FUN_011e7154(&local_38,psVar5);
        if (local_38 == 0) {
          local_40 = *(int *)psVar5;
          iStack_3c = *(int *)(psVar5 + 4);
          if (iStack_3c != 0) {
            piVar3 = (int *)(iStack_3c + 4);
            do {
              ExclusiveAccess(piVar3);
              bVar1 = (bool)hasExclusiveAccess(piVar3);
            } while (!bVar1);
            *piVar3 = *piVar3 + 1;
          }
          iVar4 = (**(code **)(*(int *)param_1 + 0x94))(param_1,&local_40);
          FUN_00cc67b0(&local_40);
          if (iVar4 != 0) {
            (**(code **)(*(int *)param_1 + 0xac))(param_1,piVar7[2],psVar5);
          }
        }
        else {
          addAvailableGenericTool
                    ((ReadValuesOperation *)param_1,(SettingCategory *)piVar7[2],psVar5);
        }
        FUN_011e71a0(&local_38);
      }
      else {
        addAvailableLiveDataTool((ReadValuesOperation *)param_1,(SettingCategory *)piVar7[2],psVar5)
        ;
      }
      FUN_00ccc814(&stack0xffffffd0);
    }
  }
  if (__stack_chk_guard != iVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


