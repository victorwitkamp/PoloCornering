/* _ZNSt6__ndk120__shared_ptr_emplaceI25BmwAirSuspensionOperationNS_9allocatorIS1_EEEC2B8ne190000IJRKNS_10shared_ptrI17ConnectionManagerEERNS6_I15BmwFGenericToolEERKNS6_I19ReadValuesOperationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 012b90fc */


void _ZNSt6__ndk120__shared_ptr_emplaceI25BmwAirSuspensionOperationNS_9allocatorIS1_EEEC2B8ne190000IJRKNS_10shared_ptrI17ConnectionManagerEERNS6_I15BmwFGenericToolEERKNS6_I19ReadValuesOperationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (undefined4 *param_1,shared_ptr *param_2,shared_ptr *param_3,shared_ptr *param_4)

{
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  param_1[2] = 0;
  *param_1 = &PTR____shared_ptr_emplace_014bd688;
  param_1[1] = 0;
  uStack_18 = param_3;
  std::__ndk1::allocator<BmwAirSuspensionOperation>::
  construct_abi_ne190000_<BmwAirSuspensionOperation,std::__ndk1::shared_ptr<ConnectionManager>const&,std::__ndk1::shared_ptr<BmwFGenericTool>&,std::__ndk1::shared_ptr<ReadValuesOperation>const&>
            ((allocator<BmwAirSuspensionOperation> *)((int)&uStack_18 + 3),
             (BmwAirSuspensionOperation *)(param_1 + 3),param_2,param_3,param_4);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


