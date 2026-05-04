/* FUN_0128070c @ 0128070c */


void FUN_0128070c(int param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined4 local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  puVar1 = operator_new(0x10);
  uVar2 = *(undefined8 *)(param_1 + 4);
  *puVar1 = &PTR_LAB_01280706_1_014baac4;
  puVar1[3] = *(undefined4 *)(param_1 + 0xc);
  local_1c = 1;
  local_20 = &uStack_15;
  *(undefined8 *)(puVar1 + 1) = uVar2;
  local_24 = 0;
  FUN_012807ec(&local_24);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


