/* _ZNSt6__ndk120__shared_ptr_emplaceI31FullByteVagUdsAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagUdsEcuRKNS_10shared_ptrI15StringWhitelistEEiRA32_KcNS9_I23NumericalInterpretationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 010ec00c */


undefined4 *
_ZNSt6__ndk120__shared_ptr_emplaceI31FullByteVagUdsAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagUdsEcuRKNS_10shared_ptrI15StringWhitelistEEiRA32_KcNS9_I23NumericalInterpretationEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
          (undefined4 *param_1,VagUdsEcu **param_2,shared_ptr *param_3,int *param_4,char *param_5,
          shared_ptr *param_6)

{
  allocator<FullByteVagUdsAdaptationSetting> aStack_15;
  undefined4 *local_14;
  
  local_14 = __stack_chk_guard;
  param_1[2] = 0;
  *param_1 = &PTR____shared_ptr_emplace_014b4eac;
  param_1[1] = 0;
  std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>::
  construct_abi_ne190000_<FullByteVagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[32],std::__ndk1::shared_ptr<NumericalInterpretation>>
            (&aStack_15,(FullByteVagUdsAdaptationSetting *)(param_1 + 4),param_2,param_3,param_4,
             param_5,param_6);
  if (__stack_chk_guard == local_14) {
    local_14 = param_1;
  }
  return local_14;
}


