/* OperationDelegate::putCachedRawValue @ 012413e4 */


/* OperationDelegate::putCachedRawValue(unsigned long long, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) */

void OperationDelegate::putCachedRawValue(ulonglong param_1,vector *param_2)

{
  undefined4 uVar1;
  undefined4 in_stack_00000000;
  undefined1 auStack_28 [8];
  vector *local_20 [3];
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_20[0] = param_2;
  FUN_01241444(auStack_28,in_stack_00000000);
  uVar1 = FUN_01241478((int)param_1 + 0xe0,local_20);
  FUN_01240350(uVar1,auStack_28);
  FUN_00cbcfda(auStack_28);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


