/* ReadValuesOperation::execute @ 012ccea4 */


/* ReadValuesOperation::execute() */

void __thiscall ReadValuesOperation::execute(ReadValuesOperation *this)

{
  vector *pvVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  int local_88 [2];
  int *local_80;
  int local_7c;
  undefined4 *local_78;
  undefined4 *puStack_74;
  undefined4 *local_60;
  int *local_58;
  __hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
  a_Stack_54 [12];
  int local_48;
  shared_ptr asStack_40 [8];
  undefined1 auStack_38 [8];
  int *local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  (**(code **)(**(int **)(this + 0x2c) + 0x20))(local_30,*(int **)(this + 0x2c),0,5);
  (**(code **)(**(int **)(this + 0x2c) + 0x20))(auStack_38,*(int **)(this + 0x2c),5,0x50);
  (**(code **)(**(int **)(this + 0x2c) + 0x20))(asStack_40,*(int **)(this + 0x2c),0x50,100);
  (**(code **)(*(int *)this + 0x74))(a_Stack_54,this);
  (**(code **)(*(int *)this + 0x14))(&local_78,this);
  iVar3 = local_48;
  if (local_78 == (undefined4 *)0x0) {
    FUN_00d5a8a2(&local_78);
    if (iVar3 != 0) goto LAB_012ccf12;
    uVar5 = 0xfffffffb;
  }
  else {
    FUN_00d5a8a2(&local_78);
LAB_012ccf12:
    (**(code **)(*(int *)this + 0x14))(&local_78,this);
    puVar8 = local_78;
    FUN_00d5a8a2(&local_78);
    if (puVar8 != (undefined4 *)0x0) {
      iVar3 = (**(code **)(*(int *)this + 0x78))(this);
      iVar4 = State::isError(iVar3);
      if (iVar4 != 0) {
        (**(code **)(*(int *)this + 0x5c))(this,iVar3);
        goto LAB_012cd168;
      }
      (**(code **)(*local_30[0] + 0x1c))(local_30[0],100);
      uVar5 = (**(code **)(*(int *)this + 0x70))(this);
      (**(code **)(*(int *)this + 0xa4))(&local_78,this,uVar5,auStack_38);
      iVar3 = Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ::isFail((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                        *)&local_78);
      if (iVar3 == 0) {
        (**(code **)(*(int *)this + 0xa8))(this,uVar5);
        (**(code **)(*(int *)this + 0x14))(&local_80,this);
        iVar3 = (**(code **)(*local_80 + 0x164))();
        FUN_00d5a8a2(&local_80);
        iVar4 = State::isFatalError(iVar3);
        if (iVar4 == 0) {
          Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
          ::~Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                     *)&local_78);
          goto LAB_012ccfdc;
        }
        (**(code **)(*(int *)this + 0x5c))(this,iVar3);
      }
      else {
        local_80 = (int *)*local_58;
        if (local_80 == (int *)0x0) {
          local_80 = (int *)0x0;
          local_7c = 0;
        }
        else {
          local_7c = local_58[1];
          if (local_7c != 0) {
            piVar6 = (int *)(local_7c + 4);
            do {
              ExclusiveAccess(piVar6);
              bVar2 = (bool)hasExclusiveAccess(piVar6);
            } while (!bVar2);
            *piVar6 = *piVar6 + 1;
          }
        }
        (**(code **)(*(int *)this + 0x14))(local_88,this);
        FUN_012066d0(local_88[0] + 0xf4,&local_80);
        FUN_00d5a8a2(local_88);
        FUN_00cbd6dc(&local_80);
        (**(code **)(*(int *)this + 0x5c))(this,*local_60);
      }
      Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
      ::~Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                 *)&local_78);
      goto LAB_012cd168;
    }
LAB_012ccfdc:
    iVar3 = Operation::isCanceled((Operation *)this);
    if (iVar3 == 0) {
      if ((local_48 != 0) &&
         (uVar7 = std::__ndk1::
                  __hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
                  ::__count_unique<SettingCategory*>
                            (a_Stack_54,(SettingCategory **)&SettingCategory::TOOLS), uVar7 != 0)) {
        uVar5 = FUN_00d5ad24(a_Stack_54,&SettingCategory::TOOLS);
        FUN_00cd9922(&local_78,uVar5);
        FUN_012cd24c(&local_80,local_78);
        piVar6 = local_80;
        FUN_00ccc708(&local_80);
        uVar5 = SettingCategory::TOOLS;
        if (piVar6 == (int *)0x0) {
          for (puVar8 = local_78; puVar8 != puStack_74; puVar8 = puVar8 + 2) {
            iVar3 = (**(code **)(*(int *)*puVar8 + 0x14))();
            iVar4 = Obd2Ecu::getInstance();
            if (iVar3 == iVar4) {
              iVar3 = Obd2System::checkSupport(*(Obd2System **)(this + 0x34));
              iVar4 = State::isFatalError(iVar3);
              if (iVar4 != 0) {
                (**(code **)(*(int *)this + 0x5c))(this,iVar3);
                goto LAB_012cd1a2;
              }
              iVar3 = State::isError(iVar3);
              if (iVar3 == 0) {
                FUN_012b6964(&local_80,puVar8);
                if (local_80 == (int *)0x0) {
LAB_012cd13c:
                  FUN_00d5c3f2(&local_80);
                  goto LAB_012cd0b0;
                }
                pvVar1 = (vector *)(local_80 + 0x1f);
                (**(code **)(**(int **)(this + 0x2c) + 0x24))
                          (local_88,*(int **)(this + 0x2c),local_80[0x20] - *(int *)pvVar1 >> 3);
                iVar3 = readObd2ParamAvailability(this,pvVar1,(shared_ptr *)local_88);
                FUN_00d2b90c(local_88);
                iVar4 = State::isFatalError(iVar3);
                if (iVar4 != 0) {
                  (**(code **)(*(int *)this + 0x5c))(this,iVar3);
                  FUN_00d5c3f2(&local_80);
                  FUN_00ccc71c(&local_78);
                  if (puVar8 == puStack_74) goto LAB_012cd154;
                  goto LAB_012cd168;
                }
                iVar3 = local_80[0x1f];
                iVar4 = local_80[0x20];
                do {
                  if (iVar3 == iVar4) goto LAB_012cd13c;
                  piVar6 = (int *)FUN_012cd4cc(this + 0x7c,iVar3);
                  iVar3 = iVar3 + 8;
                } while (*piVar6 == 2);
                FUN_00d5c3f2(&local_80);
              }
            }
            else {
LAB_012cd0b0:
              (**(code **)(*(int *)this + 0xac))(this,uVar5,puVar8);
            }
          }
        }
        else {
          iVar3 = readObd2LiveDataToolAvailability(this,(vector *)&local_78,asStack_40);
          iVar4 = State::isFatalError(iVar3);
          if (iVar4 != 0) {
            (**(code **)(*(int *)this + 0x5c))(this,iVar3);
LAB_012cd1a2:
            FUN_00ccc71c(&local_78);
            goto LAB_012cd168;
          }
          (**(code **)(*(int *)this + 0xa8))(this,a_Stack_54);
        }
        FUN_00ccc71c(&local_78);
      }
LAB_012cd154:
      uVar5 = (**(code **)(*(int *)this + 0xa0))(this);
      (**(code **)(*(int *)this + 0x5c))(this,uVar5);
      goto LAB_012cd168;
    }
    uVar5 = 0xfffffc18;
  }
  (**(code **)(*(int *)this + 0x5c))(this,uVar5);
LAB_012cd168:
  FUN_00cd944c(a_Stack_54);
  FUN_011e01a0(asStack_40);
  FUN_011e01a0(auStack_38);
  FUN_011e01a0(local_30);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


