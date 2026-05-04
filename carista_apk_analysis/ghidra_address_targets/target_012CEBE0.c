/* Target address 012cebe0 */
/* Function countAndMapByPresentEcu @ 012cebe0 */


/* ReadValuesOperation::countAndMapByPresentEcu(std::__ndk1::unordered_map<SettingCategory*,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > >, std::__ndk1::hash<SettingCategory*>,
   std::__ndk1::equal_to<SettingCategory*>,
   std::__ndk1::allocator<std::__ndk1::pair<SettingCategory* const,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > > > > const&) */

void ReadValuesOperation::countAndMapByPresentEcu(unordered_map *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  ReadValuesOperation *in_r1;
  int in_r2;
  int *piVar5;
  int *piVar6;
  int *local_74 [2];
  char *local_6c [2];
  int *local_64 [2];
  int *local_5c;
  int *piStack_58;
  undefined4 local_54;
  int local_50 [2];
  int local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_2c = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0x3f800000;
  piVar2 = (int *)(in_r2 + 8);
  while (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0) {
    piVar5 = (int *)piVar2[3];
    piVar3 = (int *)piVar2[4];
    while( true ) {
      if (piVar5 == piVar3) break;
      FUN_011e3768((shared_ptr *)local_48,piVar5);
      if (local_48[0] == 0) {
        FUN_011e7154(local_50,piVar5);
        if (local_50[0] != 0) {
          local_54 = 0;
          local_5c = (int *)0x0;
          piStack_58 = (int *)0x0;
          ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>
                    ((vector *)&local_5c,(vector *)(local_50[0] + 0x24));
          ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>
                    ((vector *)&local_5c,(vector *)(local_50[0] + 0x30));
          ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>
                    ((vector *)&local_5c,(vector *)(local_50[0] + 0x3c));
          piVar1 = piStack_58;
          for (piVar6 = local_5c; piVar6 != piVar1; piVar6 = piVar6 + 2) {
            FUN_011e3768((shared_ptr *)local_64,piVar6);
            if (local_64[0] == (int *)0x0) {
              (**(code **)(*(int *)in_r1 + 0x14))(local_74);
              (**(code **)(*local_74[0] + 0x48))
                        (local_6c,local_74[0],*(undefined4 *)(*piVar6 + 0x10));
              FUN_00d5a8a2(local_74);
              if ((local_6c[0] == (char *)0x0) || (*local_6c[0] != '\0')) {
                uVar4 = FUN_012cee98((unordered_map *)&local_40,*piVar6 + 0x10);
                FUN_00d6f39a(uVar4,piVar6);
                local_2c = local_2c + 1;
              }
              FUN_00d092c6(local_6c);
            }
            else {
              countAndMapLiveDataTool
                        (in_r1,(shared_ptr *)local_64,(unordered_map *)&local_40,&local_2c);
            }
            FUN_00ccc814((shared_ptr *)local_64);
          }
          FUN_00ccc71c(&local_5c);
        }
        (**(code **)(*(int *)in_r1 + 0x14))((shared_ptr *)local_64);
        (**(code **)(*local_64[0] + 0x48))(&local_5c,local_64[0],*(undefined4 *)(*piVar5 + 0x10));
        FUN_00d5a8a2((shared_ptr *)local_64);
        if ((local_5c == (int *)0x0) || ((char)*local_5c != '\0')) {
          uVar4 = FUN_012cee98((unordered_map *)&local_40,*piVar5 + 0x10);
          FUN_00d6f39a(uVar4,piVar5);
          local_2c = local_2c + 1;
        }
        FUN_00d092c6(&local_5c);
        FUN_011e71a0(local_50);
      }
      else {
        countAndMapLiveDataTool(in_r1,(shared_ptr *)local_48,(unordered_map *)&local_40,&local_2c);
      }
      FUN_00ccc814((shared_ptr *)local_48);
      piVar5 = piVar5 + 2;
    }
  }
  *(uint *)param_1 = local_2c;
  FUN_012ceeee(param_1 + 4,&local_40);
  FUN_012cef78(&local_40);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


