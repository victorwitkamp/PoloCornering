/* FUN_012148e0 @ 012148e0 */


void FUN_012148e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_01218650(param_1,&stack0xfffffff3,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


