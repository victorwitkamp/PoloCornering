/* ReadValuesOperation::getConnectedChassisId @ 012cd7a4 */


/* ReadValuesOperation::getConnectedChassisId() const */

void ReadValuesOperation::getConnectedChassisId(void)

{
  int *piVar1;
  undefined4 *in_r0;
  int *in_r1;
  int *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  (**(code **)(*in_r1 + 0x14))(local_24);
  piVar1 = local_24[0];
  FUN_00d5a8a2(local_24);
  if (piVar1 == (int *)0x0) {
    *in_r0 = 0;
    in_r0[1] = 0;
  }
  else {
    (**(code **)(*in_r1 + 0x14))(local_24);
    (**(code **)(*local_24[0] + 0x34))();
    FUN_00d5a8a2(local_24);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


