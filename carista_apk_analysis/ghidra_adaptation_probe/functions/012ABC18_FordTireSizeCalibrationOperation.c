/* FordTireSizeCalibrationOperation::FordTireSizeCalibrationOperation @ 012abc18 */


/* FordTireSizeCalibrationOperation::FordTireSizeCalibrationOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<FordGenericTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
FordTireSizeCalibrationOperation::FordTireSizeCalibrationOperation
          (FordTireSizeCalibrationOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_1c;
  int iStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = *(undefined4 *)param_2;
  iStack_18 = *(int *)(param_2 + 4);
  if (iStack_18 != 0) {
    piVar2 = (int *)(iStack_18 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  GenericToolSavableOperation::GenericToolSavableOperation
            ((GenericToolSavableOperation *)this,param_1,&local_1c,param_3,
             LibStr::operation_status_not_started);
  FUN_00cc67b0(&local_1c);
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x128) = 0;
  *(undefined4 *)(this + 300) = 0;
  this[0x11c] = (FordTireSizeCalibrationOperation)0x0;
  *(undefined ***)this = &PTR__FordTireSizeCalibrationOperation_014bcc4c;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


