/* BmwEGaugeConfigOperation::BmwEGaugeConfigOperation @ 012928dc */


/* BmwEGaugeConfigOperation::BmwEGaugeConfigOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwEGaugeConfigOperation::BmwEGaugeConfigOperation
          (BmwEGaugeConfigOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  char acStack_1ec [12];
  undefined8 local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined1 auStack_1c8 [8];
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined1 auStack_1b4 [8];
  char acStack_1ac [12];
  undefined8 local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 uStack_18c;
  undefined1 auStack_188 [8];
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined1 auStack_174 [8];
  char acStack_16c [12];
  undefined8 local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [8];
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined1 auStack_134 [8];
  char acStack_12c [12];
  undefined8 local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined1 auStack_108 [8];
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined1 auStack_f4 [8];
  char acStack_ec [12];
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined1 auStack_c8 [8];
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined1 auStack_b4 [8];
  pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
  *local_ac;
  undefined4 uStack_a8;
  undefined1 auStack_a4 [8];
  undefined4 local_9c;
  pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
  apStack_98 [20];
  undefined1 auStack_84 [20];
  undefined1 auStack_70 [20];
  undefined1 auStack_5c [20];
  undefined1 auStack_48 [20];
  int local_34;
  
  local_34 = __stack_chk_guard;
  puVar1 = (undefined4 *)
           GenericToolSavableOperation::GenericToolSavableOperation
                     ((GenericToolSavableOperation *)this,param_1,param_2,param_3,
                      LibStr::not_saved_yet);
  *puVar1 = &PTR__BmwEGaugeConfigOperation_014bbce4;
  puVar4 = (undefined8 *)(puVar1 + 0x47);
  *puVar4 = 0;
  *(undefined8 *)(puVar1 + 0x49) = 0;
  *(undefined8 *)(puVar1 + 0x4b) = 0;
  *(undefined8 *)(puVar1 + 0x4d) = 0;
  puVar1[0x4f] = 0;
  iVar2 = (**(code **)(**(int **)param_3 + 0x54))();
  puVar3 = &BmwKLineEcu::INSTRUMENT_CLUSTER;
  if (iVar2 == VehicleProtocol::BMW_CAN) {
    puVar3 = &BmwCanEcu::INSTRUMENT_CLUSTER;
  }
  local_9c = *puVar3;
  local_b8 = 0x3105;
  local_bc = 3;
  local_c0 = 0xff;
  local_d0 = 0xff;
  uStack_cc = 0;
  local_d8 = 0;
  uStack_d4 = 1;
  local_e0 = 0x3fb999999999999a;
  FUN_00cea23c(auStack_c8,&uStack_cc,&local_d0,&uStack_d4,&Unit::L_KM,&local_d8,&local_e0);
  FUN_012931e8(auStack_b4,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_b8,&local_bc,&local_c0,
               "car_setting_fuel_consumption_position_0",auStack_c8,puVar4);
  operator____b(acStack_ec,0x98b2b2);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (apStack_98,auStack_b4,acStack_ec);
  local_f8 = 0x3105;
  local_fc = 5;
  local_100 = 0xff;
  local_110 = 0xff;
  uStack_10c = 0;
  local_114 = 1;
  local_118 = 0;
  local_120 = 0x3fb999999999999a;
  FUN_00cea23c(auStack_108,&uStack_10c,&local_110,&local_114,&Unit::L_KM,&local_118,&local_120);
  FUN_012931e8(auStack_f4,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_f8,&local_fc,&local_100,
               "car_setting_fuel_consumption_position_1",auStack_108);
  operator____b(acStack_12c,0x760059);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_84,auStack_f4,acStack_12c);
  local_138 = 0x3105;
  local_13c = 7;
  local_140 = 0xff;
  local_150 = 0xff;
  uStack_14c = 0;
  local_158 = 0;
  local_154 = 1;
  local_160 = 0x3fb999999999999a;
  FUN_00cea23c(auStack_148,&uStack_14c,&local_150,&local_154,&Unit::L_KM,&local_158,&local_160);
  FUN_012931e8(auStack_134,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_138,&local_13c,
               &local_140,"car_setting_fuel_consumption_position_2",auStack_148);
  operator____b(acStack_16c,0x90fc9c);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_70,auStack_134,acStack_16c);
  local_178 = 0x3105;
  local_17c = 9;
  local_180 = 0xff;
  local_190 = 0xff;
  uStack_18c = 0;
  local_198 = 0;
  local_194 = 1;
  local_1a0 = 0x3fb999999999999a;
  FUN_00cea23c(auStack_188,&uStack_18c,&local_190,&local_194,&Unit::L_KM,&local_198,&local_1a0);
  FUN_012931e8(auStack_174,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_178,&local_17c,
               &local_180,"car_setting_fuel_consumption_position_3",auStack_188);
  operator____b(acStack_1ac,0x8d8e71);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_5c,auStack_174,acStack_1ac);
  local_1b8 = 0x3105;
  local_1bc = 0xb;
  local_1c0 = 0xff;
  local_1d0 = 0xff;
  uStack_1cc = 0;
  local_1d4 = 1;
  local_1d8 = 0;
  local_1e0 = 0x3fb999999999999a;
  FUN_00cea23c(auStack_1c8,&uStack_1cc,&local_1d0,&local_1d4,&Unit::L_KM,&local_1d8,&local_1e0);
  FUN_012931e8(auStack_1b4,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_1b8,&local_1bc,
               &local_1c0,"car_setting_fuel_consumption_position_4",auStack_1c8);
  operator____b(acStack_1ec,0xa00905);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_48,auStack_1b4,acStack_1ec);
  uStack_a8 = 5;
  local_ac = apStack_98;
  FUN_012931b4(auStack_a4,&local_ac);
  FUN_0129325c(puVar1 + 0x4a,auStack_a4);
  FUN_012932a8(auStack_a4);
  iVar2 = 0x50;
  do {
    std::__ndk1::
    pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
    ::~pair(apStack_98 + iVar2);
    iVar2 = iVar2 + -0x14;
  } while (iVar2 != -0x14);
  FUN_00cb7f50(acStack_1ec);
  FUN_00cebf28(auStack_1b4);
  FUN_00cba5b0(auStack_1c8);
  FUN_00cb7f50(acStack_1ac);
  FUN_00cebf28(auStack_174);
  FUN_00cba5b0(auStack_188);
  FUN_00cb7f50(acStack_16c);
  FUN_00cebf28(auStack_134);
  FUN_00cba5b0(auStack_148);
  FUN_00cb7f50(acStack_12c);
  FUN_00cebf28(auStack_f4);
  FUN_00cba5b0(auStack_108);
  FUN_00cb7f50(acStack_ec);
  FUN_00cebf28(auStack_b4);
  FUN_00cba5b0(auStack_c8);
  local_b8 = 0x3105;
  local_bc = 3;
  local_c0 = 0xff;
  local_d0 = 0xff;
  uStack_cc = 0;
  local_d8 = 0;
  uStack_d4 = 1;
  local_e0 = 0x3ff0000000000000;
  FUN_00cea23c(auStack_c8,&uStack_cc,&local_d0,&uStack_d4,&Unit::DEGREES_CELSIUS,&local_d8,&local_e0
              );
  FUN_012932bc(auStack_b4,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_b8,&local_bc,&local_c0,
               "car_setting_oil_temp_position_0",auStack_c8);
  operator____b(acStack_ec,0x98b2b2);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (apStack_98,auStack_b4,acStack_ec);
  local_f8 = 0x3105;
  local_fc = 5;
  local_100 = 0xff;
  local_110 = 0xff;
  uStack_10c = 0x30;
  local_114 = 1;
  local_118 = 0xffffffd0;
  local_120 = 0x3ff0000000000000;
  FUN_00cea23c(auStack_108,&uStack_10c,&local_110,&local_114,&Unit::DEGREES_CELSIUS,&local_118,
               &local_120);
  FUN_012932bc(auStack_f4,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_f8,&local_fc,&local_100,
               "car_setting_oil_temp_position_1",auStack_108);
  operator____b(acStack_12c,0xb79fb1);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_84,auStack_f4,acStack_12c);
  local_138 = 0x3105;
  local_13c = 7;
  local_140 = 0xff;
  local_150 = 0xff;
  uStack_14c = 0x30;
  local_154 = 1;
  local_158 = 0xffffffd0;
  local_160 = 0x3ff0000000000000;
  FUN_00cea23c(auStack_148,&uStack_14c,&local_150,&local_154,&Unit::DEGREES_CELSIUS,&local_158,
               &local_160);
  FUN_012932bc(auStack_134,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_138,&local_13c,
               &local_140,"car_setting_oil_temp_position_2",auStack_148);
  operator____b(acStack_16c,0xacb16e);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_70,auStack_134,acStack_16c);
  local_178 = 0x3105;
  local_17c = 9;
  local_180 = 0xff;
  local_190 = 0xff;
  uStack_18c = 0x30;
  local_194 = 1;
  local_198 = 0xffffffd0;
  local_1a0 = 0x3ff0000000000000;
  FUN_00cea23c(auStack_188,&uStack_18c,&local_190,&local_194,&Unit::DEGREES_CELSIUS,&local_198,
               &local_1a0);
  FUN_012932bc(auStack_174,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_178,&local_17c,
               &local_180,"car_setting_oil_temp_position_3",auStack_188);
  operator____b(acStack_1ac,0x747852);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_5c,auStack_174,acStack_1ac);
  local_1b8 = 0x3105;
  local_1bc = 0xb;
  local_1c0 = 0xff;
  local_1d0 = 0xff;
  uStack_1cc = 0x30;
  local_1d4 = 1;
  local_1d8 = 0xffffffd0;
  local_1e0 = 0x3ff0000000000000;
  FUN_00cea23c(auStack_1c8,&uStack_1cc,&local_1d0,&local_1d4,&Unit::DEGREES_CELSIUS,&local_1d8,
               &local_1e0);
  FUN_012932bc(auStack_1b4,&local_9c,&BmwESettings::KMBI_PL2_E60_E70,&local_1b8,&local_1bc,
               &local_1c0,"car_setting_oil_temp_position_4",auStack_1c8);
  operator____b(acStack_1ec,0xbcdb1c);
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000INS1_I11BmwESettingEES7_TnNS_9enable_ifIXclsr10_CheckArgsE23__is_pair_constructibleIT_T0_EEEiE4typeELi0EEEOSD_OSE_
            (auStack_48,auStack_1b4,acStack_1ec);
  uStack_a8 = 5;
  local_ac = apStack_98;
  FUN_012931b4(auStack_a4,&local_ac);
  FUN_0129325c(puVar1 + 0x4c,auStack_a4);
  FUN_012932a8(auStack_a4);
  iVar2 = 0x50;
  do {
    std::__ndk1::
    pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
    ::~pair(apStack_98 + iVar2);
    iVar2 = iVar2 + -0x14;
  } while (iVar2 != -0x14);
  FUN_00cb7f50(acStack_1ec);
  FUN_00cebf28(auStack_1b4);
  FUN_00cba5b0(auStack_1c8);
  FUN_00cb7f50(acStack_1ac);
  FUN_00cebf28(auStack_174);
  FUN_00cba5b0(auStack_188);
  FUN_00cb7f50(acStack_16c);
  FUN_00cebf28(auStack_134);
  FUN_00cba5b0(auStack_148);
  FUN_00cb7f50(acStack_12c);
  FUN_00cebf28(auStack_f4);
  FUN_00cba5b0(auStack_108);
  FUN_00cb7f50(acStack_ec);
  FUN_00cebf28(auStack_b4);
  FUN_00cba5b0(auStack_c8);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_34);
  }
  return;
}


