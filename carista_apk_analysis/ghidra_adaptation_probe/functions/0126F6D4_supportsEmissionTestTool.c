/* VagOperationDelegate::supportsEmissionTestTool @ 0126f6d4 */


/* VagOperationDelegate::supportsEmissionTestTool() */

void __thiscall VagOperationDelegate::supportsEmissionTestTool(VagOperationDelegate *this)

{
  VagVin local_24 [8];
  basic_string *local_1c [2];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x20))(local_1c);
  if (local_1c[0] != (basic_string *)0x0) {
    VagVin::isElectricModel(local_24,local_1c[0]);
    FUN_00d092c6(local_24);
  }
  FUN_00cbba38(local_1c);
  if (__stack_chk_guard == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}


