/* FUN_01272888 @ 01272888 */


undefined8 FUN_01272888(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_01280d70(param_1,&stack0xffffffeb,param_2,param_3,param_4,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return CONCAT44(param_2,param_4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


