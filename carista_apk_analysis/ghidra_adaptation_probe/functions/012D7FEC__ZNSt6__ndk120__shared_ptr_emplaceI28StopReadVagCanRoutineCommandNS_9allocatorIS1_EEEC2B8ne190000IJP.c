/* _ZNSt6__ndk120__shared_ptr_emplaceI28StopReadVagCanRoutineCommandNS_9allocatorIS1_EEEC2B8ne190000IJP9VagCanEcuRtbES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 012d7fec */


void _ZNSt6__ndk120__shared_ptr_emplaceI28StopReadVagCanRoutineCommandNS_9allocatorIS1_EEEC2B8ne190000IJP9VagCanEcuRtbES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (undefined4 *param_1,VagCanEcu **param_2,ushort *param_3,bool *param_4)

{
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  param_1[2] = 0;
  *param_1 = &PTR____shared_ptr_emplace_014bac14;
  param_1[1] = 0;
  uStack_18 = param_3;
  std::__ndk1::allocator<StopReadVagCanRoutineCommand>::
  construct_abi_ne190000_<StopReadVagCanRoutineCommand,VagCanEcu*,unsigned_short&,bool>
            ((allocator<StopReadVagCanRoutineCommand> *)((int)&uStack_18 + 3),
             (StopReadVagCanRoutineCommand *)(param_1 + 3),param_2,param_3,param_4);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


