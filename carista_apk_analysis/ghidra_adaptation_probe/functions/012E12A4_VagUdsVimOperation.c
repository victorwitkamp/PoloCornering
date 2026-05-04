/* VagUdsVimOperation::VagUdsVimOperation @ 012e12a4 */


/* VagUdsVimOperation::VagUdsVimOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<VagBasicSettingTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&, LibStr const&) */

void __thiscall
VagUdsVimOperation::VagUdsVimOperation
          (VagUdsVimOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3,
          LibStr *param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24 = *(undefined4 *)param_2;
  iStack_20 = *(int *)(param_2 + 4);
  if (iStack_20 != 0) {
    piVar2 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  VimOperation::VimOperation((VimOperation *)this,param_1,(shared_ptr *)&local_24,param_3,param_4);
  FUN_00cc67b0(&local_24);
  *(undefined ***)this = &PTR__VagUdsVimOperation_014bff2c;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


