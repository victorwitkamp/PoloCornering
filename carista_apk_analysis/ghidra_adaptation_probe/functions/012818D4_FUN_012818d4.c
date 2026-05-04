/* FUN_012818d4 @ 012818d4 */


void FUN_012818d4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<WriteVagCanTemporaryAdaptationDataCommand,std::__ndk1::allocator<WriteVagCanTemporaryAdaptationDataCommand>>>>
  a_Stack_28 [8];
  int local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  std::__ndk1::
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<WriteVagCanTemporaryAdaptationDataCommand,std::__ndk1::allocator<WriteVagCanTemporaryAdaptationDataCommand>>>>
  ::
  __allocation_guard_abi_ne190000_<std::__ndk1::allocator<WriteVagCanTemporaryAdaptationDataCommand>>
            (a_Stack_28,1);
  _ZNSt6__ndk120__shared_ptr_emplaceI41WriteVagCanTemporaryAdaptationDataCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagCanEcuRtRNS_6vectorIhNS2_IhEEEEbES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
            (local_20,param_3,param_4,param_5,param_6);
  *param_1 = local_20 + 0xc;
  param_1[1] = local_20;
  local_20 = 0;
  FUN_01281a2a(a_Stack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


