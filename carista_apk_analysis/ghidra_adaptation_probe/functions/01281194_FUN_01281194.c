/* FUN_01281194 @ 01281194 */


void FUN_01281194(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<ReadVagCanLongAdaptationDataCommand,std::__ndk1::allocator<ReadVagCanLongAdaptationDataCommand>>>>
  a_Stack_28 [8];
  int local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  std::__ndk1::
  __allocation_guard<std::__ndk1::allocator<std::__ndk1::__shared_ptr_emplace<ReadVagCanLongAdaptationDataCommand,std::__ndk1::allocator<ReadVagCanLongAdaptationDataCommand>>>>
  ::__allocation_guard_abi_ne190000_<std::__ndk1::allocator<ReadVagCanLongAdaptationDataCommand>>
            (a_Stack_28,1);
  _ZNSt6__ndk120__shared_ptr_emplaceI35ReadVagCanLongAdaptationDataCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagCanEcubES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
            (local_20,param_3,param_4);
  *param_1 = local_20 + 0xc;
  param_1[1] = local_20;
  local_20 = 0;
  FUN_012812c0(a_Stack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


