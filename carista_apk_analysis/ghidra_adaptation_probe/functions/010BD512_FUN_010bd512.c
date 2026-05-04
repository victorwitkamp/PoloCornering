/* FUN_010bd512 @ 010bd512 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_010bd512(VagUdsAdaptationSetting *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *unaff_r6;
  int unaff_r7;
  char in_CY;
  undefined8 uVar7;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  int in_stack_0000001c;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  
  if (in_CY == '\0') {
    uVar5 = *param_3;
    in_stack_00000014 = *unaff_r6;
    in_stack_00000018 = unaff_r6[1];
    *unaff_r6 = 0;
    unaff_r6[1] = 0;
    VagUdsAdaptationSetting::VagUdsAdaptationSetting(param_1,uVar5);
                    /* WARNING: Subroutine does not return */
    FUN_00cd2748(&stack0x00000014);
  }
  if (((uint)param_1 & 0x80000000) != 0) {
    puVar6 = (undefined4 *)((int)param_1 * 2);
    local_14 = **(int **)(FUN_010bd572 + 0x10bd526);
    local_1c = puVar6;
    local_18 = param_3;
    if ((puVar6 != (undefined4 *)0x0) && ((puVar6[1] == 0 || (*(int *)(puVar6[1] + 4) == -1)))) {
      local_18 = *(undefined4 **)(param_1 + 4);
      if (local_18 != (undefined4 *)0x0) {
        piVar2 = local_18 + 1;
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = *piVar2 + 1;
      }
      local_1c = param_3;
      _ZNSt6__ndk18weak_ptrI7SettingEaSIS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERS2_RKNS_10shared_ptrIS5_EE
                (puVar6,&local_1c);
      FUN_00cc67b0(&local_1c);
    }
    if (**(int **)(iRam010bd578 + 0x10bd566) == local_14) {
      return CONCAT44(local_1c,param_1);
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  if (-1 < (int)param_1 << 1) {
    piVar2 = (int *)(unaff_r7 >> 0x13);
    if (-1 < (int)piVar2 << 1) {
      iVar3 = (int)piVar2 * 2;
      *piVar2 = iVar3;
      piVar2[1] = (int)piVar2 << 1;
      iVar4 = iVar3;
      if (iVar3 != 0) {
        iVar4 = iVar3 + 4;
      }
      uVar7 = FUN_01416270(piVar2,iVar4,iVar3);
      return uVar7;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (**(int **)(FUN_010bd3a4 + 0x10bd388) == in_stack_0000001c) {
    return CONCAT44(**(int **)(FUN_010bd3a4 + 0x10bd388),in_stack_0000001c);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


