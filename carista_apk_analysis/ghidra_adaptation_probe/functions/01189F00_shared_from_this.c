/* FullByteVagUdsAdaptationSetting::shared_from_this @ 01189f00 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* FullByteVagUdsAdaptationSetting::shared_from_this() */

undefined8 FullByteVagUdsAdaptationSetting::shared_from_this(void)

{
  bool bVar1;
  undefined4 *in_r0;
  int *piVar2;
  undefined4 in_r1;
  int in_r2;
  undefined4 local_1c;
  int iStack_18;
  int local_14;
  
  local_14 = **(int **)(FUN_01189f4a + 0x1189f0c);
  local_1c = in_r1;
  iStack_18 = in_r2;
  VagUdsAdaptationSetting::shared_from_this();
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
  FUN_010bbffc(&local_1c);
  if (**(int **)(iRam01189f50 + 0x1189f3e) != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return CONCAT44(local_1c,in_r0);
}


