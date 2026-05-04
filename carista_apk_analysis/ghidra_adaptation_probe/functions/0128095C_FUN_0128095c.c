/* FUN_0128095c @ 0128095c */


void FUN_0128095c(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  puVar1 = operator_new(8);
  uVar2 = *(undefined4 *)(param_1 + 4);
  *puVar1 = &PTR_LAB_00d26764_1_014bab0c;
  puVar1[1] = uVar2;
  local_1c = 1;
  local_20 = &uStack_15;
  local_24 = 0;
  FUN_01280a10(&local_24);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


