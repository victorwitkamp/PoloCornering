/* _ZNSt6__ndk120__shared_ptr_emplaceI23VagUdsAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagUdsEcuRKNS_10shared_ptrI15StringWhitelistEEiiiRA42_KcNS9_I23NumericalInterpretationEERKNS9_IKNS_6vectorIyNS2_IyEEEEEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 010e02a8 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ZNSt6__ndk120__shared_ptr_emplaceI23VagUdsAdaptationSettingNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagUdsEcuRKNS_10shared_ptrI15StringWhitelistEEiiiRA42_KcNS9_I23NumericalInterpretationEERKNS9_IKNS_6vectorIyNS2_IyEEEEEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (int *param_1,VagUdsEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,
               int *param_6,char *param_7,shared_ptr *param_8,shared_ptr *param_9)

{
  int iVar1;
  allocator<VagUdsAdaptationSetting> aStack_15;
  int local_14;
  
  iVar1 = iRam010e0318;
  local_14 = **(int **)(_FUN_010e0314 + 0x10e02ba);
  param_1[2] = 0;
  *param_1 = *(int *)(iVar1 + 0x10e02c8) + 8;
  param_1[1] = 0;
  std::__ndk1::allocator<VagUdsAdaptationSetting>::
  construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[42],std::__ndk1::shared_ptr<NumericalInterpretation>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&>
            (&aStack_15,(VagUdsAdaptationSetting *)(param_1 + 4),param_2,param_3,param_4,param_5,
             param_6,param_7,param_8,param_9);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


