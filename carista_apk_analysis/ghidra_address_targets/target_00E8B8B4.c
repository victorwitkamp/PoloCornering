/* Target address 00e8b8b4 */
/* Function FUN_00e8b8b4 @ 00e8b8b4 */


void FUN_00e8b8b4(shared_ptr<FordUdsSetting> *param_1,undefined4 param_2,undefined4 param_3,
                 undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,
                 undefined4 param_8,undefined4 param_9,undefined4 param_10)

{
  __shared_ptr_emplace *p_Var1;
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<FordUdsSetting,std::__ndk1::allocator<FordUdsSetting>>>>
  a_Stack_28 [8];
  __shared_ptr_emplace *local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  std::__ndk1::
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<FordUdsSetting,std::__ndk1::allocator<FordUdsSetting>>>>
  ::__allocation_guard_abi_ne190000_<std::__ndk1::allocator<FordUdsSetting>>(a_Stack_28,1);
  _ZNSt6__ndk120__shared_ptr_emplaceI14FordUdsSettingNS_9allocatorIS1_EEEC2B8ne190000IJNS_10shared_ptrI15StringWhitelistEEN11FordSetting7AvailByERP7FordEcuiiiRA30_KcNS6_I28MultipleChoiceInterpretationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
            (local_20,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  p_Var1 = local_20;
  local_20 = (__shared_ptr_emplace *)0x0;
  std::__ndk1::shared_ptr<FordUdsSetting>::
  __create_with_control_block_abi_ne190000_<FordUdsSetting,std::__ndk1::__shared_ptr_emplace<FordUdsSetting,std::__ndk1::allocator<FordUdsSetting>>>
            (param_1,(FordUdsSetting *)(p_Var1 + 0x10),p_Var1);
  FUN_00e840e4(a_Stack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


