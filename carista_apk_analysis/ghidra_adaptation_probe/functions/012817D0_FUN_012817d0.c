/* FUN_012817d0 @ 012817d0 */


void FUN_012817d0(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  puVar2 = operator_new(0xc);
  uVar5 = *(undefined4 *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 8);
  puVar2[2] = iVar3;
  *puVar2 = &PTR_FUN_012817a0_1_014bac3c;
  puVar2[1] = uVar5;
  local_1c = 1;
  local_20 = &uStack_15;
  if (iVar3 != 0) {
    piVar4 = (int *)(iVar3 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  local_24 = 0;
  FUN_012818bc(&local_24);
  if (__stack_chk_guard == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}


