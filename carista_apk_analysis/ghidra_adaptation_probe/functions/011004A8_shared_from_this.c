/* VagCanShortAdaptationSetting::shared_from_this @ 011004a8 */


/* VagCanShortAdaptationSetting::shared_from_this() */

undefined8 VagCanShortAdaptationSetting::shared_from_this(void)

{
  bool bVar1;
  undefined4 *in_r0;
  int *piVar2;
  undefined4 in_r1;
  int in_r2;
  undefined4 local_1c;
  int iStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = in_r1;
  iStack_18 = in_r2;
  VagSetting::shared_from_this();
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
  FUN_00d1756c(&local_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return CONCAT44(local_1c,in_r0);
}


