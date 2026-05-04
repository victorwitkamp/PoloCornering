/* FUN_010bcd16 @ 010bcd16 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_010bcd16(__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>
             *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  void *pvVar2;
  undefined4 extraout_r0;
  int *piVar3;
  undefined4 extraout_r1;
  __shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>
  *p_Var4;
  int iVar5;
  undefined4 unaff_r4;
  char in_NG;
  char in_OV;
  int local_1c;
  int local_18;
  int local_14;
  
  if (in_NG != in_OV) {
    pvVar2 = (void *)std::__ndk1::
                     __shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>
                     ::~__shared_ptr_emplace(param_1);
    operator_delete(pvVar2);
    return CONCAT44(extraout_r1,extraout_r0);
  }
  p_Var4 = (__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>
            *)((int)param_1 * 2);
  if ((int)p_Var4 < 0 == (bool)in_OV) {
    iVar5 = (int)param_1 * 2;
    local_14 = **(int **)(FUN_010bcd76 + 0x10bcd2a);
    local_1c = iVar5;
    local_18 = param_3;
    if ((iVar5 != 0) && ((*(int *)(iVar5 + 4) == 0 || (*(int *)(*(int *)(iVar5 + 4) + 4) == -1)))) {
      local_18 = *(int *)(param_1 + 4);
      if (local_18 != 0) {
        piVar3 = (int *)(local_18 + 4);
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = *piVar3 + 1;
      }
      local_1c = param_3;
      _ZNSt6__ndk18weak_ptrI7SettingEaSIS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERS2_RKNS_10shared_ptrIS5_EE
                (iVar5,&local_1c);
      FUN_00cc67b0(&local_1c);
    }
    if (**(int **)(iRam010bcd7c + 0x10bcd6a) == local_14) {
      return CONCAT44(local_1c,param_1);
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  if (p_Var4 == param_1) {
    return CONCAT44(p_Var4,unaff_r4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


