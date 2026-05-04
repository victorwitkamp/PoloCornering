/* ChangeSettingOperation::shared_from_this @ 0129b198 */


/* ChangeSettingOperation::shared_from_this() */

undefined8 ChangeSettingOperation::shared_from_this(void)

{
  bool bVar1;
  int *in_r0;
  int *piVar2;
  int in_r1;
  int in_r2;
  int local_1c;
  int iStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = in_r1;
  iStack_18 = in_r2;
  _ZNSt6__ndk110shared_ptrI9OperationEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
            (&local_1c,in_r1 + 4);
  *in_r0 = local_1c;
  in_r0[1] = iStack_18;
  if (iStack_18 != 0) {
    piVar2 = (int *)(iStack_18 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  FUN_00cbfa28(&local_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return CONCAT44(local_1c,in_r0);
}


