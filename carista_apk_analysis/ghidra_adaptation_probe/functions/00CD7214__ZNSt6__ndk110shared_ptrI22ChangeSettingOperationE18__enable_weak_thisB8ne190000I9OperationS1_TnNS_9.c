/* _ZNSt6__ndk110shared_ptrI22ChangeSettingOperationE18__enable_weak_thisB8ne190000I9OperationS1_TnNS_9enable_ifIXsr14is_convertibleIPT0_PKNS_23enable_shared_from_thisIT_EEEE5valueEiE4typeELi0EEEvSC_S7_ @ 00cd7214 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
_ZNSt6__ndk110shared_ptrI22ChangeSettingOperationE18__enable_weak_thisB8ne190000I9OperationS1_TnNS_9enable_ifIXsr14is_convertibleIPT0_PKNS_23enable_shared_from_thisIT_EEEE5valueEiE4typeELi0EEEvSC_S7_
          (int param_1,int param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int local_1c;
  int local_18;
  int local_14;
  
  local_14 = **(int **)(FUN_00cd726a + 0xcd721e);
  local_1c = param_2;
  local_18 = param_3;
  if ((param_2 != 0) &&
     ((*(int *)(param_2 + 4) == 0 || (*(int *)(*(int *)(param_2 + 4) + 4) == -1)))) {
    local_18 = *(int *)(param_1 + 4);
    if (local_18 != 0) {
      piVar2 = (int *)(local_18 + 4);
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = *piVar2 + 1;
    }
    local_1c = param_3;
    _ZNSt6__ndk18weak_ptrI9OperationEaSIS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERS2_RKNS_10shared_ptrIS5_EE
              (param_2,&local_1c);
    FUN_00cbfa28(&local_1c);
  }
  if (**(int **)(iRam00cd7270 + 0xcd725e) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return CONCAT44(local_1c,param_1);
}


