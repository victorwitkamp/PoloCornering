/* Target address 010b0e40 */
/* Function FUN_010b0e40 @ 010b0e40 */


void FUN_010b0e40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  FUN_010bcd8c(param_1,&uStack_15,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


