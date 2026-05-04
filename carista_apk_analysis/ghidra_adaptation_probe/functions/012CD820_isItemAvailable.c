/* ReadValuesOperation::isItemAvailable @ 012cd820 */


/* ReadValuesOperation::isItemAvailable(std::__ndk1::shared_ptr<Setting>) */

void __thiscall ReadValuesOperation::isItemAvailable(ReadValuesOperation *this,shared_ptr *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  VehicleProtocol *pVVar5;
  ByteUtils aBStack_14c [12];
  basic_string abStack_140 [12];
  basic_string abStack_134 [12];
  basic_string abStack_128 [12];
  StringUtils aSStack_11c [12];
  basic_string abStack_110 [12];
  basic_string abStack_104 [12];
  basic_string abStack_f8 [12];
  undefined1 auStack_ec [12];
  int *local_e0 [3];
  shared_ptr asStack_d4 [8];
  StringUtils aSStack_cc [12];
  ByteUtils local_c0;
  undefined1 auStack_bf [7];
  undefined1 *local_b8;
  vector avStack_b4 [12];
  int *local_a8 [2];
  undefined4 local_a0;
  int local_98;
  Param aPStack_88 [24];
  Param aPStack_70 [24];
  Param aPStack_58 [24];
  Param aPStack_40 [24];
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar1 = std::__ndk1::
          __hash_table<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::__unordered_map_hasher<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::__unordered_map_equal<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>>>
          ::__count_unique<std::__ndk1::shared_ptr<Setting>>
                    ((__hash_table<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::__unordered_map_hasher<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::__unordered_map_equal<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>>>
                      *)(this + 0x7c),param_2);
  if ((uVar1 == 0) ||
     (piVar2 = (int *)FUN_012cd58c((__hash_table<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::__unordered_map_hasher<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::__unordered_map_equal<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>>>
                                    *)(this + 0x7c),param_2), *piVar2 == 0)) goto LAB_012cd86c;
  FUN_012bf2cc(&local_a0,param_2);
  piVar2 = local_a0;
  FUN_00cfbac8(&local_a0);
  if ((piVar2 != (int *)0x0) || (*(int *)(*(int *)param_2 + 0x2c) == 0)) goto LAB_012cd86c;
  (**(code **)(*(int *)this + 0x14))(&local_a0,this);
  (**(code **)(*local_a0 + 0xa8))(local_a8,local_a0,param_2);
  FUN_00d5a8a2(&local_a0);
  piVar2 = *(int **)param_2;
  if (local_a8[0] == (int *)0x0) {
    uVar4 = (**(code **)(*piVar2 + 8))();
    (**(code **)(**(int **)param_2 + 0x18))(&local_a0);
    if (((byte)local_a0._0_1_ & 1) == 0) {
      local_98 = (int)&local_a0 + 1;
    }
    Log::w("Item is unavailable (cannot read value): %s %s",uVar4,local_98);
LAB_012cd982:
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_a0);
  }
  else {
    iVar3 = (**(code **)(*piVar2 + 0xc))(piVar2,local_a8[0][1] - *local_a8[0]);
    if (iVar3 == 0) {
      uVar4 = (**(code **)(**(int **)param_2 + 8))();
      (**(code **)(**(int **)param_2 + 0x18))(&local_a0);
      if (((byte)local_a0._0_1_ & 1) == 0) {
        local_98 = (int)&local_a0 + 1;
      }
      Log::w("Item is unavailable (value wrong length): %s %s",uVar4,local_98);
      goto LAB_012cd982;
    }
    (**(code **)(**(int **)param_2 + 0x1c))(avStack_b4,*(int **)param_2,local_a8[0]);
    iVar3 = (**(code **)(**(int **)(*(int *)param_2 + 0x2c) + 8))
                      (*(int **)(*(int *)param_2 + 0x2c),avStack_b4);
    if (iVar3 == 0) {
      (**(code **)(**(int **)param_2 + 0x18))(&local_a0);
      iVar3 = local_98;
      piVar2 = local_a0;
      ByteUtils::getHexString(&local_c0,avStack_b4);
      if (((uint)piVar2 & 1) == 0) {
        iVar3 = (int)&local_a0 + 1;
      }
      if (((byte)local_c0 & 1) == 0) {
        local_b8 = auStack_bf;
      }
      Log::e("Setting %s has unrecognized value: %s",iVar3,local_b8);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_c0);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_a0);
      (**(code **)(*(int *)this + 0x14))(&local_a0,this);
      pVVar5 = (VehicleProtocol *)(**(code **)(*local_a0 + 0x10))();
      VehicleProtocol::toString((VehicleProtocol *)&local_c0,pVVar5);
      FUN_00d5a8a2(&local_a0);
      (**(code **)(*(int *)this + 0x14))(local_e0,this);
      (**(code **)(*local_e0[0] + 0x34))(&local_a0);
      StringUtils::toString(aSStack_cc,(shared_ptr *)&local_a0);
      FUN_00cbba38(&local_a0);
      FUN_00d5a8a2(local_e0);
      (**(code **)(*(int *)this + 0x14))(&local_a0,this);
      (**(code **)(*local_a0 + 0x1c))(asStack_d4,local_a0,param_2);
      FUN_00d5a8a2(&local_a0);
      piVar2 = (int *)App::ANALYTICS;
      FUN_00cb4d44(local_e0,"vehicle_setting_value_unknown");
      FUN_00cb4d44(abStack_f8,"protocol");
      Analytics::Event::Param::Param((Param *)&local_a0,abStack_f8,(basic_string *)&local_c0);
      FUN_00cb4d44(abStack_104,"chassis_id");
      Analytics::Event::Param::Param(aPStack_88,abStack_104,(basic_string *)aSStack_cc);
      FUN_00cb4d44(abStack_110,"ecu_tag");
      StringUtils::toString(aSStack_11c,asStack_d4);
      Analytics::Event::Param::Param(aPStack_70,abStack_110,(basic_string *)aSStack_11c);
      FUN_00cb4d44(abStack_128,&DAT_00a14123);
      (**(code **)(**(int **)param_2 + 0x18))(abStack_134);
      Analytics::Event::Param::Param(aPStack_58,abStack_128,abStack_134);
      FUN_00cb4d44(abStack_140,"extracted_value");
      ByteUtils::getHexString(aBStack_14c,avStack_b4);
      Analytics::Event::Param::Param(aPStack_40,abStack_140,(basic_string *)aBStack_14c);
      FUN_00ce429c(auStack_ec,&local_a0,5);
      (**(code **)(*piVar2 + 8))(piVar2,local_e0,auStack_ec);
      FUN_00ce431c(auStack_ec);
      iVar3 = 0x60;
      do {
        Analytics::Event::Param::~Param((Param *)((int)&local_a0 + iVar3));
        iVar3 = iVar3 + -0x18;
      } while (iVar3 != -0x18);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aBStack_14c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_140);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_134);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_128);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aSStack_11c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_110);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_104);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_f8);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)local_e0);
      uVar4 = (**(code **)(**(int **)param_2 + 8))();
      (**(code **)(**(int **)param_2 + 0x18))(&local_a0);
      if (((byte)local_a0._0_1_ & 1) == 0) {
        local_98 = (int)&local_a0 + 1;
      }
      Log::w("Item is unavailable (unrecognized value): %s %s",uVar4,local_98);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_a0);
      FUN_00cbba38(asStack_d4);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aSStack_cc);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_c0);
    }
    else {
      uVar4 = (**(code **)(**(int **)param_2 + 8))();
      (**(code **)(**(int **)param_2 + 0x18))(&local_a0);
      if (((byte)local_a0._0_1_ & 1) == 0) {
        local_98 = (int)&local_a0 + 1;
      }
      Log::w("Item is available: %s %s",uVar4,local_98);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_a0);
    }
    FUN_00cb7f50(avStack_b4);
  }
  FUN_00cbcfda(local_a8);
LAB_012cd86c:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}


