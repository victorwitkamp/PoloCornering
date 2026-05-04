/* OperationDelegate::putCachedRawValue @ 012414c8 */


/* OperationDelegate::putCachedRawValue(unsigned long long,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > const> const&) */

void OperationDelegate::putCachedRawValue(ulonglong param_1,shared_ptr *param_2)

{
  undefined4 uVar1;
  int *in_stack_00000000;
  undefined4 local_28;
  undefined4 uStack_24;
  shared_ptr *local_20 [3];
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_20[0] = param_2;
  if (*in_stack_00000000 == 0) {
    local_28 = 0;
    uStack_24 = 0;
  }
  else {
    FUN_01241444(&local_28);
  }
  uVar1 = FUN_01241478((int)param_1 + 0xe0,local_20);
  FUN_01240350(uVar1,&local_28);
  FUN_00cbcfda(&local_28);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


