/* ReadValuesOperation::getSettingValue @ 012cd694 */


/* ReadValuesOperation::getSettingValue(std::__ndk1::shared_ptr<Setting> const&) */

void ReadValuesOperation::getSettingValue(shared_ptr *param_1)

{
  int *in_r1;
  undefined4 *in_r2;
  int *local_24 [2];
  undefined4 local_1c [2];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*in_r1 + 0x14))(local_24);
  (**(code **)(*local_24[0] + 0xa8))(local_1c);
  FUN_00d5a8a2(local_24);
  (**(code **)(*(int *)*in_r2 + 0x1c))(param_1,(int *)*in_r2,local_1c[0]);
  FUN_00cbcfda(local_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


