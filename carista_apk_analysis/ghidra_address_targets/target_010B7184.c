/* Target address 010b7184 */
/* Function FUN_010b7184 @ 010b7184 */


void FUN_010b7184(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  FUN_010dad6c(param_1,&uStack_15,param_2,param_3,param_4,param_5,param_6,param_7);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


