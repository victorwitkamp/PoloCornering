/* FUN_0127c9f4 @ 0127c9f4 */


void FUN_0127c9f4(int param_1)

{
  undefined4 *local_24;
  undefined1 *puStack_20;
  undefined4 local_1c;
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_24 = operator_new(0x60);
  local_1c = 1;
  puStack_20 = &uStack_15;
  *local_24 = &PTR_FUN_0127c9c4_1_014ba96c;
  FUN_0127d2ba(local_24 + 2,param_1 + 8);
  local_24 = (undefined4 *)0x0;
  FUN_0127d2a4(&local_24);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


