/* VagOperationDelegate::readVagUdsValue @ 01272a1c */


/* VagOperationDelegate::readVagUdsValue(unsigned long long) */

void VagOperationDelegate::readVagUdsValue(ulonglong param_1)

{
  shared_ptr *psVar1;
  Progress aPStack_3c [10];
  undefined2 uStack_32;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  psVar1 = (shared_ptr *)(param_1 >> 0x20);
  local_1c = __stack_chk_guard;
  local_30 = (**(code **)(*(int *)psVar1 + 0x154))(psVar1);
  uStack_32 = (**(code **)(*(int *)psVar1 + 0x158))(psVar1);
  FUN_012148e0(&local_2c,&local_30,&uStack_32);
  local_24 = local_2c;
  local_20 = uStack_28;
  local_2c = 0;
  uStack_28 = 0;
  Progress::NUL(aPStack_3c);
  OperationDelegate::runCommand<BytesModel>((shared_ptr *)param_1,psVar1);
  FUN_011e01a0(aPStack_3c);
  FUN_011e4f74(&local_24);
  FUN_011e4f86(&local_2c);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


