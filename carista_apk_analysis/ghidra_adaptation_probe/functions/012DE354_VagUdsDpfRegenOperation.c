/* VagUdsDpfRegenOperation::VagUdsDpfRegenOperation @ 012de354 */


/* VagUdsDpfRegenOperation::VagUdsDpfRegenOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagUdsDpfRegenOperation::VagUdsDpfRegenOperation
          (VagUdsDpfRegenOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3
          )

{
  bool bVar1;
  int *piVar2;
  double in_d0;
  double in_d1;
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
  DpfRegenGenericOperation::DpfRegenGenericOperation
            ((DpfRegenGenericOperation *)this,param_1,(shared_ptr *)&local_1c,param_3,in_d0,in_d1);
  FUN_00cc67b0(&local_1c);
  *(undefined2 *)(this + 0x138) = 0;
  *(undefined ***)this = &PTR__VagUdsDpfRegenOperation_014bf940;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


