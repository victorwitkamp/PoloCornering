/* FUN_012728d8 @ 012728d8 */


undefined8
FUN_012728d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_01280ec0(param_1,&stack0xffffffeb,param_2,param_3,param_4,param_5,param_3);
  if (__stack_chk_guard == iVar1) {
    return CONCAT44(param_5,param_4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


