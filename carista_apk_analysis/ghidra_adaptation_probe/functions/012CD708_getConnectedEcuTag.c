/* ReadValuesOperation::getConnectedEcuTag @ 012cd708 */


/* ReadValuesOperation::getConnectedEcuTag(std::__ndk1::shared_ptr<Setting> const&) */

void ReadValuesOperation::getConnectedEcuTag(shared_ptr *param_1)

{
  int iVar1;
  int *in_r1;
  int *in_r2;
  int iVar2;
  int *local_2c [2];
  int local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = *(int *)(*in_r2 + 0x10);
  iVar1 = Obd2Ecu::getInstance();
  if (iVar2 == iVar1) {
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    (**(code **)(*in_r1 + 0x14))(local_24);
    if (local_24[0] == 0) {
      *(undefined4 *)param_1 = 0;
      *(undefined4 *)(param_1 + 4) = 0;
    }
    else {
      (**(code **)(*in_r1 + 0x14))(local_2c);
      (**(code **)(*local_2c[0] + 0x1c))(param_1);
      FUN_00d5a8a2(local_2c);
    }
    FUN_00d5a8a2(local_24);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


