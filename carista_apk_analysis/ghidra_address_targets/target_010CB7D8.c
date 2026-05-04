/* Target address 010cb7d8 */
/* Function FUN_010cb7d8 @ 010cb7d8 */


void FUN_010cb7d8(shared_ptr<FullByteVagUdsAdaptationSetting> *param_1,undefined4 param_2,
                 undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,
                 undefined4 param_7)

{
  __shared_ptr_emplace *p_Var1;
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>>>
  a_Stack_28 [8];
  __shared_ptr_emplace *local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  std::__ndk1::
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>>>
  ::__allocation_guard_abi_ne190000_<std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>
            (a_Stack_28,1);
  _ZNSt6__ndk120__shared_ptr_emplaceI31FullByteVagUdsAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagUdsEcuRKNS_10shared_ptrI15StringWhitelistEEiRA31_KcNS9_I28MultipleChoiceInterpretationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
            (local_20,param_3,param_4,param_5,param_6,param_7);
  p_Var1 = local_20;
  local_20 = (__shared_ptr_emplace *)0x0;
  std::__ndk1::shared_ptr<FullByteVagUdsAdaptationSetting>::
  __create_with_control_block_abi_ne190000_<FullByteVagUdsAdaptationSetting,std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>>
            (param_1,(FullByteVagUdsAdaptationSetting *)(p_Var1 + 0x10),p_Var1);
  FUN_010c7bd0(a_Stack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


