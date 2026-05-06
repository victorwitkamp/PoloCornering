/* Target address 00cea328 */
/* Function FUN_00cea328 @ 00cea328 */


void FUN_00cea328(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_00ceaba0(param_1,&stack0xfffffff3,param_2);
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


