/* Target address 010bcb48 */
/* Function FUN_010bcb48 @ 010bcb48 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010bcb48(shared_ptr<FullByteVagCanShortAdaptationSetting> *param_1,undefined4 param_2,
                 undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,
                 undefined4 param_7,undefined4 param_8)

{
  __shared_ptr_emplace *p_Var1;
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>>>
  a_Stack_28 [8];
  __shared_ptr_emplace *local_20;
  int local_1c;
  
  local_1c = **(int **)(_FUN_010bcbbc + 0x10bcb5e);
  std::__ndk1::
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>>>
  ::__allocation_guard_abi_ne190000_<std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>
            (a_Stack_28,1);
  _ZNSt6__ndk120__shared_ptr_emplaceI36FullByteVagCanShortAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagCanEcuRKNS_10shared_ptrI15StringWhitelistEEiRA36_KcNS9_I23NumericalInterpretationEERKNS9_IKNS_6vectorIyNS2_IyEEEEEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
            (local_20,param_3,param_4,param_5,param_6,param_7,param_8);
  p_Var1 = local_20;
  local_20 = (__shared_ptr_emplace *)0x0;
  std::__ndk1::shared_ptr<FullByteVagCanShortAdaptationSetting>::
  __create_with_control_block_abi_ne190000_<FullByteVagCanShortAdaptationSetting,std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>>
            (param_1,(FullByteVagCanShortAdaptationSetting *)(p_Var1 + 0x10),p_Var1);
  FUN_010bcd80(a_Stack_28);
  if (**(int **)(iRam010bcbc0 + 0x10bcba0) != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


