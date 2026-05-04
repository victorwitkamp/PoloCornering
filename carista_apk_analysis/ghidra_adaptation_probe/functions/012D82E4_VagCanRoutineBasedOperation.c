/* VagCanRoutineBasedOperation::VagCanRoutineBasedOperation @ 012d82e4 */


/* VagCanRoutineBasedOperation::VagCanRoutineBasedOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagCanRoutineBasedOperation::VagCanRoutineBasedOperation
          (VagCanRoutineBasedOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  IllegalArgumentException *this_00;
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
  GenericToolActionOperation::GenericToolActionOperation
            ((GenericToolActionOperation *)this,param_1,(shared_ptr *)&local_28,param_3);
  FUN_00cc67b0(&local_28);
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined ***)this = &PTR__VagCanRoutineBasedOperation_014bf294;
  if ((*(int *)(*(int *)param_2 + 0x10) != 0) &&
     (iVar3 = __dynamic_cast(*(int *)(*(int *)param_2 + 0x10),&Ecu::typeinfo,&VagCanEcu::typeinfo,0)
     , iVar3 != 0)) {
    if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(local_1c);
    }
    return;
  }
  this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
  FUN_00cb4d44(&local_28,"Tool\'s ecu is not VagCanEcu");
  IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&local_28);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
              IllegalStateException::~IllegalStateException);
}


