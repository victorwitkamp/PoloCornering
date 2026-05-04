/* _ZNSt6__ndk120__shared_ptr_emplaceI41WriteVagCanTemporaryAdaptationDataCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagCanEcuRtRNS_6vectorIhNS2_IhEEEEbES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_ @ 0128195c */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ZNSt6__ndk120__shared_ptr_emplaceI41WriteVagCanTemporaryAdaptationDataCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP9VagCanEcuRtRNS_6vectorIhNS2_IhEEEEbES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_
               (int *param_1,VagCanEcu **param_2,ushort *param_3,vector *param_4,bool *param_5)

{
  int iVar1;
  undefined4 uStack_18;
  int local_14;
  
  iVar1 = iRam012819bc;
  local_14 = **(int **)(FUN_012819b6 + 0x128196c);
  param_1[2] = 0;
  *param_1 = *(int *)(iVar1 + 0x128197a) + 8;
  param_1[1] = 0;
  uStack_18 = param_3;
  std::__ndk1::allocator<WriteVagCanTemporaryAdaptationDataCommand>::
  construct_abi_ne190000_<WriteVagCanTemporaryAdaptationDataCommand,VagCanEcu*&,unsigned_short&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>&,bool>
            ((allocator<WriteVagCanTemporaryAdaptationDataCommand> *)((int)&uStack_18 + 3),
             (WriteVagCanTemporaryAdaptationDataCommand *)(param_1 + 3),param_2,param_3,param_4,
             param_5);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


