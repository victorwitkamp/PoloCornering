/* ReadValuesOperation::isSfd1Protected @ 012cd5a8 */


/* ReadValuesOperation::isSfd1Protected(std::__ndk1::shared_ptr<Setting> const&) */

void __thiscall ReadValuesOperation::isSfd1Protected(ReadValuesOperation *this,shared_ptr *param_1)

{
  int *local_40 [2];
  Result<bool,void> aRStack_38 [36];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x14))(local_40);
  (**(code **)(*local_40[0] + 0xd0))(aRStack_38,local_40[0],param_1);
  FUN_00d5a8a2(local_40);
  Result<bool,void>::isFail(aRStack_38);
  Result<bool,void>::~Result(aRStack_38);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


