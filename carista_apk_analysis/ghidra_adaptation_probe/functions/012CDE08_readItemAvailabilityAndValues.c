/* ReadValuesOperation::readItemAvailabilityAndValues @ 012cde08 */


/* ReadValuesOperation::readItemAvailabilityAndValues(std::__ndk1::unordered_map<SettingCategory*,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > >, std::__ndk1::hash<SettingCategory*>,
   std::__ndk1::equal_to<SettingCategory*>,
   std::__ndk1::allocator<std::__ndk1::pair<SettingCategory* const,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > > > > const&,
   std::__ndk1::shared_ptr<Progress> const&) */

void ReadValuesOperation::readItemAvailabilityAndValues(unordered_map *param_1,shared_ptr *param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  shared_ptr *psVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  undefined4 *in_r3;
  int *piVar13;
  int *piVar14;
  undefined8 uVar15;
  undefined4 local_10c;
  undefined4 uStack_108;
  int *local_104 [2];
  undefined4 local_fc;
  int local_f4;
  int *local_e0;
  undefined4 local_d8;
  int local_d0;
  undefined4 *local_bc;
  int *local_b4 [6];
  int *local_9c;
  undefined4 *local_98;
  Ecu *local_90;
  undefined4 *local_8c;
  undefined4 *puStack_88;
  undefined1 auStack_80 [8];
  undefined4 local_78;
  __hash_table<std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
  a_Stack_74 [20];
  undefined **local_60;
  undefined1 *local_5c;
  undefined ***local_50;
  RunOnScopeExit aRStack_48 [32];
  int local_28;
  
  local_28 = __stack_chk_guard;
  (**(code **)(*(int *)param_2 + 0xb0))(&local_78);
  (**(code **)(*(int *)*in_r3 + 0x24))(auStack_80,(int *)*in_r3,local_78);
  (**(code **)(*(int *)param_2 + 0x14))(local_b4,param_2);
  (**(code **)(*local_b4[0] + 0x40))(&local_8c);
  FUN_00d5a8a2((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                *)local_b4);
  iVar3 = (int)&local_d8 + 1;
  iVar4 = (int)&local_fc + 1;
  psVar5 = param_2 + 0x7c;
  puVar6 = local_8c;
  do {
    if (puVar6 == puStack_88) {
      FUN_00cc8d6c(&local_8c);
      Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
      ::done((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              *)param_1);
LAB_012ce402:
      FUN_00d2b90c(auStack_80);
      FUN_012cef78(a_Stack_74);
      if (__stack_chk_guard == local_28) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    local_90 = (Ecu *)*puVar6;
    uVar7 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
            ::__count_unique<Ecu*>(a_Stack_74,&local_90);
    if (uVar7 != 0) {
      puVar8 = (undefined4 *)FUN_012ce530(a_Stack_74,&local_90);
      piVar13 = (int *)puVar8[1];
      bVar2 = false;
      for (piVar14 = (int *)*puVar8; piVar14 != piVar13; piVar14 = piVar14 + 2) {
        iVar9 = Operation::isCanceled((Operation *)param_2);
        if (iVar9 != 0) {
          Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
          ::Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                    *)param_1,-1000);
          goto LAB_012ce3fc;
        }
        local_5c = auStack_80;
        local_60 = &PTR_LAB_00d26764_1_014be6a4;
        local_50 = &local_60;
        RunOnScopeExit::RunOnScopeExit(aRStack_48,&local_60);
        FUN_00d2682a(&local_60);
        if ((param_2[0x95] == (shared_ptr)0x0) ||
           (iVar9 = (**(code **)(*(int *)*piVar14 + 0x2c))(), iVar9 == 0)) {
          (**(code **)(*(int *)param_2 + 0x14))
                    ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      *)&local_d8,param_2);
          (**(code **)(*local_d8 + 0xe0))
                    ((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                      *)local_b4,local_d8,piVar14);
          FUN_00d5a8a2((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                        *)&local_d8);
          iVar9 = Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                  ::isFatalFail((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                                 *)local_b4);
          if ((iVar9 != 0) || (*local_9c == -0x1a)) {
            uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
            (**(code **)(*(int *)*piVar14 + 0x18))(&local_d8);
            if (((byte)local_d8._0_1_ & 1) == 0) {
              local_d0 = (int)&local_d8 + 1;
            }
            Log::w("Item is not present in configuration (fatal error or ECU inconsistency getting availability): %s %s"
                   ,uVar10,local_d0);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_d8);
            Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ::Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                      *)param_1,(Result *)local_b4);
            Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ::~Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                       *)local_b4);
            RunOnScopeExit::~RunOnScopeExit(aRStack_48);
            goto LAB_012ce3fc;
          }
          iVar9 = Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                  ::isFail((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                            *)local_b4);
          if (iVar9 != 0) {
LAB_012cdf2a:
            uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
            (**(code **)(*(int *)*piVar14 + 0x18))
                      ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                        *)&local_d8);
            iVar9 = local_d0;
            if (((uint)local_d8 & 1) == 0) {
              iVar9 = iVar3;
            }
            Log::w("Item is not present in configuration: %s %s",uVar10,iVar9);
LAB_012cdfb2:
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_d8);
LAB_012cdfb8:
            Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ::~Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                       *)local_b4);
            goto LAB_012cdfbe;
          }
          iVar9 = *(int *)*local_98;
          if (iVar9 == 2) {
            iVar9 = (**(code **)(*(int *)*piVar14 + 0x2c))();
            if (iVar9 != 0) {
LAB_012cdf7c:
              param_2[0x95] = (shared_ptr)0x1;
              uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
              (**(code **)(*(int *)*piVar14 + 0x18))
                        ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                          *)&local_d8);
              iVar9 = local_d0;
              if (((uint)local_d8 & 1) == 0) {
                iVar9 = iVar3;
              }
              Log::w("Item is unavailable (experimental in prod): %s %s",uVar10,iVar9);
              goto LAB_012cdfb2;
            }
            iVar9 = *(int *)*local_98;
          }
          else {
            if (iVar9 == 1) goto LAB_012cdf7c;
            if (iVar9 == 0) goto LAB_012cdf2a;
          }
          piVar11 = (int *)FUN_012cd4cc(psVar5,piVar14);
          *piVar11 = iVar9;
          uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
          (**(code **)(*(int *)*piVar14 + 0x18))
                    ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      *)&local_d8);
          iVar9 = local_d0;
          if (((uint)local_d8 & 1) == 0) {
            iVar9 = iVar3;
          }
          Log::w("Item is present in configuration: %s %s",uVar10,iVar9);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_d8);
          (**(code **)(*(int *)param_2 + 0x14))
                    ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      *)&local_d8,param_2);
          iVar9 = (**(code **)(*local_d8 + 0xa0))(local_d8,piVar14);
          if (iVar9 == 0) {
            FUN_00d5a8a2((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                          *)&local_d8);
          }
          else {
            iVar9 = *(int *)(*piVar14 + 0x2c);
            FUN_00d5a8a2((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                          *)&local_d8);
            if (iVar9 != 0) {
              (**(code **)(*(int *)param_2 + 0x14))(&local_fc,param_2);
              (**(code **)(*local_fc + 0xa8))
                        ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                          *)&local_d8,local_fc,piVar14);
              piVar11 = local_d8;
              FUN_00cbcfda((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                            *)&local_d8);
              FUN_00d5a8a2(&local_fc);
              if (piVar11 != (int *)0x0) {
                uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
                (**(code **)(*(int *)*piVar14 + 0x18))
                          ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                            *)&local_d8);
                iVar9 = local_d0;
                if (((uint)local_d8 & 1) == 0) {
                  iVar9 = iVar3;
                }
                Log::w("Item is available: %s %s",uVar10,iVar9);
                goto LAB_012cdfb2;
              }
              uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
              (**(code **)(*(int *)*piVar14 + 0x18))
                        ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                          *)&local_d8);
              iVar9 = local_d0;
              if (((uint)local_d8 & 1) == 0) {
                iVar9 = iVar3;
              }
              Log::w("Item is unavailable (failed reading value): %s %s",uVar10,iVar9);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)&local_d8);
              puVar8 = (undefined4 *)FUN_012cd4cc(psVar5,piVar14);
              *puVar8 = 0;
              goto LAB_012cdfb8;
            }
          }
          (**(code **)(*(int *)param_2 + 0x14))(&local_fc,param_2);
          (**(code **)(*local_fc + 0xd0))
                    ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      *)&local_d8,local_fc,piVar14);
          FUN_00d5a8a2(&local_fc);
          iVar9 = Result<bool,void>::isFatalFail((Result<bool,void> *)&local_d8);
          if (iVar9 == 0) {
            iVar9 = Result<bool,void>::isFail((Result<bool,void> *)&local_d8);
            if (iVar9 == 0) {
              cVar1 = *(char *)*local_bc;
              if (cVar1 != '\0') {
                iVar9 = (**(code **)(*(int *)param_2 + 0xb4))(param_2);
                if (iVar9 == 0) goto LAB_012ce2a6;
                uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
                (**(code **)(*(int *)*piVar14 + 0x18))(&local_fc);
                iVar9 = local_f4;
                if (((uint)local_fc & 1) == 0) {
                  iVar9 = iVar4;
                }
                Log::w("Item is unavailable (skipping SFD item): %s %s",uVar10,iVar9);
                std::__ndk1::
                basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
                ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                               *)&local_fc);
                puVar8 = (undefined4 *)FUN_012cd4cc(psVar5,piVar14);
                goto LAB_012ce17a;
              }
              if (*(int *)(*piVar14 + 0x38) == 0 || bVar2) {
LAB_012ce2a6:
                (**(code **)(*(int *)param_2 + 0x14))((Result<BytesModel,void> *)&local_fc,param_2);
                uVar15 = (**(code **)(*local_fc + 0x148))(local_fc,piVar14);
                uVar10 = (undefined4)((ulonglong)uVar15 >> 0x20);
                FUN_00d5a8a2((Result<BytesModel,void> *)&local_fc);
                (**(code **)(*(int *)param_2 + 0x14))(local_104,param_2);
                (**(code **)(*local_104[0] + 0xe4))
                          ((Result<BytesModel,void> *)&local_fc,local_104[0],(int)uVar15,uVar10,0);
                FUN_00d5a8a2(local_104);
                iVar9 = Result<BytesModel,void>::isFatalFail((Result<BytesModel,void> *)&local_fc);
                if (iVar9 == 0) {
                  iVar9 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_fc);
                  if (iVar9 == 0) {
                    (**(code **)(*(int *)param_2 + 0x14))(local_104,param_2);
                    (**(code **)(*local_104[0] + 0xac))
                              (local_104[0],*(code **)(*local_104[0] + 0xac),(int)uVar15,uVar10,
                               *local_e0 + 4);
                  }
                  else {
                    (**(code **)(*(int *)param_2 + 0x14))(local_104,param_2);
                    local_10c = 0;
                    uStack_108 = 0;
                    (**(code **)(*local_104[0] + 0xb8))(local_104[0],piVar14,&local_10c);
                    FUN_00cbcfda(&local_10c);
                  }
                  FUN_00d5a8a2(local_104);
                  iVar9 = 0;
                  if ((cVar1 != '\0') && (param_2[0x94] == (shared_ptr)0x0)) {
                    param_2[0x94] = (shared_ptr)0x1;
                  }
                }
                else {
                  Result<BytesModel,void>::
                  stateAs<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                            ();
                  iVar9 = 1;
                }
                Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_fc);
                goto LAB_012ce36c;
              }
              (**(code **)(*(int *)param_2 + 0x14))(&local_fc,param_2);
              iVar9 = (**(code **)(*local_fc + 0x128))
                                (local_fc,local_90,*(undefined4 *)(*piVar14 + 0x38),param_2 + 0x2c);
              FUN_00d5a8a2(&local_fc);
              iVar9 = State::isError(iVar9);
              if (iVar9 == 0) {
                bVar2 = true;
                goto LAB_012ce2a6;
              }
              (**(code **)(*(int *)*piVar14 + 0x18))
                        ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                          *)&local_fc);
              iVar9 = local_f4;
              if (((uint)local_fc & 1) == 0) {
                iVar9 = iVar4;
              }
              Log::e("Failed to unlock security access for %s, so we can\'t read this value; skipping."
                     ,iVar9);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)&local_fc);
              uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
              (**(code **)(*(int *)*piVar14 + 0x18))(&local_fc);
              iVar9 = local_f4;
              if (((uint)local_fc & 1) == 0) {
                iVar9 = iVar4;
              }
              Log::w("Item is unavailable (failed security unlock): %s %s",uVar10,iVar9);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)&local_fc);
              puVar8 = (undefined4 *)FUN_012cd4cc(psVar5,piVar14);
              bVar2 = false;
              *puVar8 = 0;
            }
            else {
              uVar10 = (**(code **)(*(int *)*piVar14 + 8))();
              (**(code **)(*(int *)*piVar14 + 0x18))(&local_fc);
              iVar9 = local_f4;
              if (((uint)local_fc & 1) == 0) {
                iVar9 = iVar4;
              }
              Log::w("Item is unavailable (failed getting SFD1 protection): %s %s",uVar10,iVar9);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)&local_fc);
              puVar8 = (undefined4 *)FUN_012cd4cc(psVar5,piVar14);
LAB_012ce17a:
              *puVar8 = 0;
            }
            iVar9 = 5;
          }
          else {
            Log::e("A fatal error occurred while getting SFD1 info!");
            FUN_0142df30(param_1,(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                  *)&local_d8);
            iVar9 = 1;
          }
LAB_012ce36c:
          Result<bool,void>::~Result((Result<bool,void> *)&local_d8);
          Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
          ::~Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                     *)local_b4);
          RunOnScopeExit::~RunOnScopeExit(aRStack_48);
          if ((iVar9 != 5) && (iVar9 != 0)) goto LAB_012ce3fc;
        }
        else {
LAB_012cdfbe:
          RunOnScopeExit::~RunOnScopeExit(aRStack_48);
        }
      }
      iVar9 = (**(code **)(**(int **)(param_2 + 0x1c) + 0x28))();
      iVar12 = State::isFatalError(iVar9);
      if (iVar12 != 0) {
        Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
        ::Result((Result<Availability,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                  *)param_1,iVar9);
LAB_012ce3fc:
        FUN_00cc8d6c(&local_8c);
        goto LAB_012ce402;
      }
    }
    puVar6 = puVar6 + 1;
  } while( true );
}


