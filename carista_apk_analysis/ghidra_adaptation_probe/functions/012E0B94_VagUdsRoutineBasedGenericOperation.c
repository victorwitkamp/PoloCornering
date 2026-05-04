/* VagUdsRoutineBasedGenericOperation::VagUdsRoutineBasedGenericOperation @ 012e0b94 */


/* VagUdsRoutineBasedGenericOperation::VagUdsRoutineBasedGenericOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&, TextUiComponent::Type, LibStr const&) */

void __thiscall
VagUdsRoutineBasedGenericOperation::VagUdsRoutineBasedGenericOperation
          (VagUdsRoutineBasedGenericOperation *this,shared_ptr *param_1,undefined4 *param_2,
          shared_ptr *param_3,VagUdsRoutineBasedGenericOperation param_5,undefined4 *param_6)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24 = *param_2;
  iStack_20 = param_2[1];
  if (iStack_20 != 0) {
    piVar2 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  GenericToolActionOperation::GenericToolActionOperation
            ((GenericToolActionOperation *)this,param_1,(shared_ptr *)&local_24,param_3);
  FUN_00cc67b0(&local_24);
  this[0x13a] = param_5;
  *(undefined4 *)(this + 0x13c) = *param_6;
  *(undefined ***)this = &PTR__VagUdsRoutineBasedGenericOperation_014bfdb8;
  this[0x140] = (VagUdsRoutineBasedGenericOperation)0x0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


