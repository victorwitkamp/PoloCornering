/* _ZNSt6__ndk120__shared_ptr_emplaceI19LiveDataUiComponentNS_9allocatorIS1_EEEC2B8ne190000IJRNS_10shared_ptrI23VagUdsAdaptationSettingEENS6_INS_6vectorIhNS2_IhEEEEEEbES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 012a7074 */


void _ZNSt6__ndk120__shared_ptr_emplaceI19LiveDataUiComponentNS_9allocatorIS1_EEEC2B8ne190000IJRNS_10shared_ptrI23VagUdsAdaptationSettingEENS6_INS_6vectorIhNS2_IhEEEEEEbES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (undefined4 *param_1,shared_ptr *param_2,shared_ptr *param_3,bool *param_4)

{
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  param_1[2] = 0;
  *param_1 = &PTR____shared_ptr_emplace_014bb394;
  param_1[1] = 0;
  uStack_18 = param_3;
  std::__ndk1::allocator<LiveDataUiComponent>::
  construct_abi_ne190000_<LiveDataUiComponent,std::__ndk1::shared_ptr<VagUdsAdaptationSetting>&,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>,bool>
            ((allocator<LiveDataUiComponent> *)((int)&uStack_18 + 3),
             (LiveDataUiComponent *)(param_1 + 3),param_2,param_3,param_4);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


