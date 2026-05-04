/* _ZNSt6__ndk120__shared_ptr_emplaceI32WriteVagCanAdaptationDataCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagCanEcuRtRNS_6vectorIhNS2_IhEEEESC_bES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 01281ac0 */


void _ZNSt6__ndk120__shared_ptr_emplaceI32WriteVagCanAdaptationDataCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagCanEcuRtRNS_6vectorIhNS2_IhEEEESC_bES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (undefined4 *param_1,VagCanEcu **param_2,ushort *param_3,vector *param_4,
               vector *param_5,bool *param_6)

{
  allocator<WriteVagCanAdaptationDataCommand> aStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  param_1[2] = 0;
  *param_1 = &PTR____shared_ptr_emplace_014baca4;
  param_1[1] = 0;
  std::__ndk1::allocator<WriteVagCanAdaptationDataCommand>::
  construct_abi_ne190000_<WriteVagCanAdaptationDataCommand,VagCanEcu*&,unsigned_short&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,bool>
            (&aStack_15,(WriteVagCanAdaptationDataCommand *)(param_1 + 3),param_2,param_3,param_4,
             param_5,param_6);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


