/* VagBatteryRegOperation::VagBatteryRegOperation @ 012d5b6c */


/* VagBatteryRegOperation::VagBatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<VagBasicSettingTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
VagBatteryRegOperation::VagBatteryRegOperation
          (VagBatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  IllegalArgumentException *pIVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_28;
  int iStack_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_28 = *(undefined4 *)param_2;
  iStack_24 = *(int *)(param_2 + 4);
  if (iStack_24 != 0) {
    piVar2 = (int *)(iStack_24 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  GenericToolSavableOperation::GenericToolSavableOperation
            ((GenericToolSavableOperation *)this,param_1,&local_28,param_3,
             LibStr::operation_status_not_started);
  FUN_00cc67b0(&local_28);
  *(VagBatteryRegOperation **)(this + 0x11c) = this + 0x120;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined ***)this = &PTR__VagBatteryRegOperation_014bede0;
  piVar4 = *(int **)(*(int *)param_2 + 0x90);
  piVar2 = *(int **)(*(int *)param_2 + 0x94);
  if (piVar4 == piVar2) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_28,"VagBatteryRegOperation with no settings");
    IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&local_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  piVar5 = piVar4;
  while (piVar5 != piVar2) {
    iVar6 = *piVar5;
    piVar5 = piVar5 + 2;
    if (*(short *)(iVar6 + 0x14) != *(short *)(*piVar4 + 0x14)) {
      pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(&local_28,"VagBatteryRegOperation settings are not within the same dataId");
      IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&local_28);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


