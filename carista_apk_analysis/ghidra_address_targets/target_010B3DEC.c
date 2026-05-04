/* Target address 010b3dec */
/* Function FUN_010b3dec @ 010b3dec */


void FUN_010b3dec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  FUN_010cb7d8(param_1,&uStack_15,param_2,param_3,param_4,param_5,param_6);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


