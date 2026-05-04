/* FUN_010bcf8e @ 010bcf8e */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_010bcf8e(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  bool in_ZR;
  bool in_CY;
  uint uStack_20;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  
  if (!in_CY || in_ZR) {
    if (**(uint **)(param_2 + 0x10bd064) == param_1) {
      return CONCAT44(**(uint **)(param_2 + 0x10bd064),param_1);
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  iVar4 = param_1 << 1;
  if ((param_1 & 0x80000000) == 0 || iVar4 == 0) {
LAB_010bcfac:
    if (*(int *)(param_4 + 4) != -1) goto LAB_010bcfda;
  }
  else {
    iVar4 = param_1 * 2;
    local_18 = param_3;
    local_1c = iVar4;
    register0x00000054 = (BADSPACEBASE *)&uStack_20;
    uStack_20 = param_1;
    local_14 = **(undefined4 **)(FUN_010bcfee + 0x10bcfa2);
    if (iVar4 == 0) goto LAB_010bcfda;
    param_4 = *(int *)(iVar4 + 4);
    if (param_4 != 0) goto LAB_010bcfac;
  }
  uVar2 = *(uint *)(param_1 + 4);
  *(uint *)((int)register0x00000054 + 4) = param_3;
  *(uint *)((int)register0x00000054 + 8) = uVar2;
  if (uVar2 != 0) {
    piVar3 = (int *)(uVar2 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  _ZNSt6__ndk18weak_ptrI7SettingEaSIS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERS2_RKNS_10shared_ptrIS5_EE
            (iVar4,(uint *)((int)register0x00000054 + 4));
  FUN_00cc67b0((uint *)((int)register0x00000054 + 4));
LAB_010bcfda:
  if (**(uint **)(iRam010bcff4 + 0x10bcfe2) == *(uint *)((int)register0x00000054 + 0xc)) {
    return *(undefined8 *)register0x00000054;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


