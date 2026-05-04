/* VagOperationDelegate::checkHoodClosed @ 0126fa58 */


/* VagOperationDelegate::checkHoodClosed() */

void __thiscall VagOperationDelegate::checkHoodClosed(VagOperationDelegate *this)

{
  int iVar1;
  char *pcVar2;
  Progress aPStack_50 [8];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  shared_ptr asStack_38 [24];
  int *local_20;
  int *local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = isUdsOnlyChassisId(this);
  if (iVar1 == 0) goto LAB_0126fad4;
  Log::d("Checking if hood is closed");
  FUN_0126ff78(&local_48);
  local_40 = local_48;
  local_3c = uStack_44;
  local_48 = 0;
  uStack_44 = 0;
  Progress::NUL(aPStack_50);
  OperationDelegate::runCommand<DiagFilterModel>(asStack_38,(shared_ptr *)this);
  FUN_011e01a0(aPStack_50);
  FUN_0126ffa8(&local_40);
  FUN_0126ffba(&local_48);
  pcVar2 = "Hood command not supported";
  if ((*local_20 == -0x28) || (*local_20 == -0x20)) {
LAB_0126fac4:
    Log::w(pcVar2);
  }
  else {
    iVar1 = Result<DiagFilterModel,void>::isFail((Result<DiagFilterModel,void> *)asStack_38);
    if (iVar1 == 0) {
      if (*(int *)(*local_1c + 4) != 1) {
        pcVar2 = "Hood is open";
        goto LAB_0126fac4;
      }
      Log::w("Hood is closed");
    }
    else {
      Log::w("Failed to read hood status");
    }
  }
  Result<DiagFilterModel,void>::~Result((Result<DiagFilterModel,void> *)asStack_38);
LAB_0126fad4:
  if (__stack_chk_guard == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}


