/* Target address 01272ce0 */
/* Function readVagUdsSubmoduleValue @ 01272ce0 */


/* VagOperationDelegate::readVagUdsSubmoduleValue(unsigned long long, unsigned short) */

void VagOperationDelegate::readVagUdsSubmoduleValue(ulonglong param_1,ushort param_2)

{
  shared_ptr *psVar1;
  Progress aPStack_34 [8];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 auStack_16 [2];
  int local_14;
  
  psVar1 = (shared_ptr *)(param_1 >> 0x20);
  local_14 = __stack_chk_guard;
  local_2c = (**(code **)(*(int *)psVar1 + 0x154))
                       (psVar1,*(code **)(*(int *)psVar1 + 0x154),param_2);
  FUN_01272d7c(&local_28,&local_2c,auStack_16);
  local_20 = local_28;
  local_1c = uStack_24;
  local_28 = 0;
  uStack_24 = 0;
  Progress::NUL(aPStack_34);
  OperationDelegate::runCommand<BytesModel>((shared_ptr *)param_1,psVar1);
  FUN_011e01a0(aPStack_34);
  FUN_011e4f74(&local_20);
  FUN_011e4f86(&local_28);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


