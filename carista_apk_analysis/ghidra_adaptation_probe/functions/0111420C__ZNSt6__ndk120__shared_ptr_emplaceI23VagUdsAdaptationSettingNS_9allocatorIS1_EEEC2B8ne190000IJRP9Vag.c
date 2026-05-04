/* _ZNSt6__ndk120__shared_ptr_emplaceI23VagUdsAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagUdsEcuRKNS_10shared_ptrI15StringWhitelistEEsiNS_6vectorIhNS2_IhEEEERA33_KcNS9_I23NumericalInterpretationEEN7Setting11ConsistencyEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 0111420c */


void _ZNSt6__ndk120__shared_ptr_emplaceI23VagUdsAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagUdsEcuRKNS_10shared_ptrI15StringWhitelistEEsiNS_6vectorIhNS2_IhEEEERA33_KcNS9_I23NumericalInterpretationEEN7Setting11ConsistencyEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (undefined4 *param_1,VagUdsEcu **param_2,shared_ptr *param_3,short *param_4,
               int *param_5,vector *param_6,char *param_7,shared_ptr *param_8,Consistency *param_9)

{
  allocator<VagUdsAdaptationSetting> aStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  param_1[2] = 0;
  *param_1 = &PTR____shared_ptr_emplace_014b4de4;
  param_1[1] = 0;
  std::__ndk1::allocator<VagUdsAdaptationSetting>::
  construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,char_const(&)[33],std::__ndk1::shared_ptr<NumericalInterpretation>,Setting::Consistency>
            (&aStack_15,(VagUdsAdaptationSetting *)(param_1 + 4),param_2,param_3,param_4,param_5,
             param_6,param_7,param_8,param_9);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


