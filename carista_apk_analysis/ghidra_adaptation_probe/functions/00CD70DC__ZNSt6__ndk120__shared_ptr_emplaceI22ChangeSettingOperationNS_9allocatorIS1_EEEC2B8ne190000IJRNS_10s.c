/* _ZNSt6__ndk120__shared_ptr_emplaceI22ChangeSettingOperationNS_9allocatorIS1_EEEC2B8ne190000IJRNS_10shared_ptrI17ConnectionManagerEERNS6_I7SettingEENS_6vectorIhNS2_IhEEEERNS6_I19ReadValuesOperationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 00cd70dc */


void _ZNSt6__ndk120__shared_ptr_emplaceI22ChangeSettingOperationNS_9allocatorIS1_EEEC2B8ne190000IJRNS_10shared_ptrI17ConnectionManagerEERNS6_I7SettingEENS_6vectorIhNS2_IhEEEERNS6_I19ReadValuesOperationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (undefined4 *param_1,shared_ptr *param_2,shared_ptr *param_3,vector *param_4,
               shared_ptr *param_5)

{
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  param_1[2] = 0;
  *param_1 = &PTR____shared_ptr_emplace_01437910;
  param_1[1] = 0;
  uStack_18 = param_3;
  std::__ndk1::allocator<ChangeSettingOperation>::
  construct_abi_ne190000_<ChangeSettingOperation,std::__ndk1::shared_ptr<ConnectionManager>&,std::__ndk1::shared_ptr<Setting>&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::shared_ptr<ReadValuesOperation>&>
            ((allocator<ChangeSettingOperation> *)((int)&uStack_18 + 3),
             (ChangeSettingOperation *)(param_1 + 3),param_2,param_3,param_4,param_5);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


