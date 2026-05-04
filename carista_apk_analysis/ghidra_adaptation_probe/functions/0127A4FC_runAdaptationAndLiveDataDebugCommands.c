/* VagOperationDelegate::runAdaptationAndLiveDataDebugCommands @ 0127a4fc */


/* VagOperationDelegate::runAdaptationAndLiveDataDebugCommands(Ecu*, DebugData&,
   std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::runAdaptationAndLiveDataDebugCommands
          (VagOperationDelegate *this,Ecu *param_1,DebugData *param_2,shared_ptr *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  vector *pvVar3;
  vector *pvVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 local_e0;
  int iStack_dc;
  undefined4 local_d8;
  int iStack_d4;
  undefined4 *local_d0;
  undefined4 *puStack_cc;
  undefined4 local_c8;
  int local_c4 [2];
  undefined4 local_bc;
  int iStack_b8;
  LiveDataTool *local_b4 [2];
  SettingCategory *local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined1 auStack_64 [20];
  undefined1 auStack_50 [20];
  __hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
  a_Stack_3c [20];
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar2 = VagCanSettings::getSettings();
  FUN_00cce028(a_Stack_3c,uVar2);
  uVar2 = VagCanTools::getTools();
  FUN_00cce028(auStack_50,uVar2);
  uVar2 = VagLiveData::getTools();
  FUN_00cce028(auStack_64,uVar2);
  pvVar3 = (vector *)FUN_00d5ad5c(a_Stack_3c,&SettingCategory::OTHER);
  pvVar4 = (vector *)FUN_00d5ad24(auStack_50,&SettingCategory::TOOLS);
  ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>(pvVar3,pvVar4);
  pvVar3 = (vector *)FUN_00d5ad5c(a_Stack_3c,&SettingCategory::OTHER);
  pvVar4 = (vector *)FUN_00d5ad24(auStack_64,&SettingCategory::TOOLS);
  ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>(pvVar3,pvVar4);
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0x3f800000;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0x3f800000;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0x3f800000;
  puVar5 = (undefined4 *)SettingCategory::values();
  puVar12 = (undefined4 *)*puVar5;
  puVar5 = (undefined4 *)puVar5[1];
  do {
    if (puVar12 == puVar5) {
LAB_0127a794:
      FUN_00ce2ba8(&local_a8);
      FUN_00d112bc(&local_90);
      FUN_00d112bc(&local_78);
      FUN_00cd944c(auStack_64);
      FUN_00cd944c(auStack_50);
      FUN_00cd944c(a_Stack_3c);
      if (__stack_chk_guard == local_28) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(local_28);
    }
    local_ac = (SettingCategory *)*puVar12;
    uVar6 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
            ::__count_unique<SettingCategory*>(a_Stack_3c,&local_ac);
    if (uVar6 != 0) {
      puVar7 = (undefined4 *)FUN_00d5ad24(a_Stack_3c,&local_ac);
      puVar8 = (undefined4 *)puVar7[1];
      for (puVar7 = (undefined4 *)*puVar7; puVar7 != puVar8; puVar7 = puVar7 + 2) {
        FUN_011e3768(local_b4,puVar7);
        if (local_b4[0] == (LiveDataTool *)0x0) {
          FUN_011e7154(local_c4,puVar7);
          if (local_c4[0] == 0) {
            iVar11 = 0;
          }
          else {
            local_c8 = 0;
            local_d0 = (undefined4 *)0x0;
            puStack_cc = (undefined4 *)0x0;
            ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>
                      ((vector *)&local_d0,(vector *)(local_c4[0] + 0x24));
            ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>
                      ((vector *)&local_d0,(vector *)(local_c4[0] + 0x30));
            puVar9 = puStack_cc;
            puVar13 = local_d0;
            do {
              if (puVar13 == puVar9) {
                iVar11 = 5;
                goto LAB_0127a6f4;
              }
              local_d8 = *puVar13;
              iStack_d4 = puVar13[1];
              if (iStack_d4 != 0) {
                piVar10 = (int *)(iStack_d4 + 4);
                do {
                  ExclusiveAccess(piVar10);
                  bVar1 = (bool)hasExclusiveAccess(piVar10);
                } while (!bVar1);
                *piVar10 = *piVar10 + 1;
              }
              (**(code **)(*(int *)this + 0x208))
                        (this,&local_d8,param_1,&local_78,&local_90,&local_a8,param_2,param_3);
              FUN_00cc67b0(&local_d8);
              iVar11 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
              puVar13 = puVar13 + 2;
            } while (iVar11 == 0);
            iVar11 = 1;
LAB_0127a6f4:
            FUN_00ccc71c(&local_d0);
          }
          FUN_011e71a0(local_c4);
          if (iVar11 == 0) {
            local_e0 = *puVar7;
            iStack_dc = puVar7[1];
            if (iStack_dc != 0) {
              piVar10 = (int *)(iStack_dc + 4);
              do {
                ExclusiveAccess(piVar10);
                bVar1 = (bool)hasExclusiveAccess(piVar10);
              } while (!bVar1);
              *piVar10 = *piVar10 + 1;
            }
            (**(code **)(*(int *)this + 0x208))
                      (this,&local_e0,param_1,&local_78,&local_90,&local_a8,param_2,param_3);
            FUN_00cc67b0(&local_e0);
            iVar11 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
            if (iVar11 == 0) goto LAB_0127a770;
LAB_0127a78e:
            FUN_00ccc814(local_b4);
            goto LAB_0127a794;
          }
          FUN_00ccc814(local_b4);
          if (iVar11 != 5) goto LAB_0127a794;
        }
        else {
          puVar9 = (undefined4 *)LiveDataTool::getParams(local_b4[0]);
          puVar13 = (undefined4 *)*puVar9;
          puVar9 = (undefined4 *)puVar9[1];
          while (puVar13 != puVar9) {
            local_bc = *puVar13;
            iStack_b8 = puVar13[1];
            if (iStack_b8 != 0) {
              piVar10 = (int *)(iStack_b8 + 4);
              do {
                ExclusiveAccess(piVar10);
                bVar1 = (bool)hasExclusiveAccess(piVar10);
              } while (!bVar1);
              *piVar10 = *piVar10 + 1;
            }
            (**(code **)(*(int *)this + 0x208))
                      (this,&local_bc,param_1,&local_78,&local_90,&local_a8,param_2,param_3);
            FUN_00cc67b0(&local_bc);
            iVar11 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
            puVar13 = puVar13 + 2;
            if (iVar11 != 0) goto LAB_0127a78e;
          }
LAB_0127a770:
          FUN_00ccc814(local_b4);
        }
      }
    }
    puVar12 = puVar12 + 1;
  } while( true );
}


