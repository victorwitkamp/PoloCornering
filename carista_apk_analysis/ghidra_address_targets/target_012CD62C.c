/* Target address 012cd62c */
/* Function hasSettingValue @ 012cd62c */


/* ReadValuesOperation::hasSettingValue(std::__ndk1::shared_ptr<Setting> const&) */

void __thiscall ReadValuesOperation::hasSettingValue(ReadValuesOperation *this,shared_ptr *param_1)

{
  int *local_24 [2];
  undefined4 local_1c [2];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x14))(local_24);
  (**(code **)(*local_24[0] + 0xa8))(local_1c,local_24[0],param_1);
  FUN_00cbcfda(local_1c);
  FUN_00d5a8a2(local_24);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


