/* VagOperationDelegate::insertValue @ 01271458 */


/* VagOperationDelegate::insertValue(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, std::__ndk1::shared_ptr<Setting> const&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::insertValue(vector *param_1,shared_ptr *param_2,vector *param_3)

{
  bool bVar1;
  undefined4 *in_r3;
  int *piVar2;
  undefined4 in_stack_00000000;
  int *local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24 = (int *)*in_r3;
  iStack_20 = in_r3[1];
  if (iStack_20 != 0) {
    piVar2 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  (**(code **)(*local_24 + 0x38))(param_1,local_24,param_3,in_stack_00000000);
  FUN_00d1756c(&local_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


