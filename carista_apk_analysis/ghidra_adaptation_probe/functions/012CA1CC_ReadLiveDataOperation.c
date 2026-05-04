/* ReadLiveDataOperation::ReadLiveDataOperation @ 012ca1cc */


/* ReadLiveDataOperation::ReadLiveDataOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<LiveDataTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
ReadLiveDataOperation::ReadLiveDataOperation
          (ReadLiveDataOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
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
  LiveDataOperation::LiveDataOperation
            ((LiveDataOperation *)this,param_1,(shared_ptr *)&local_24,param_3);
  FUN_00cc67b0(&local_24);
  *(undefined ***)this = &PTR__ReadLiveDataOperation_014be318;
  iVar3 = *(int *)(param_2 + 4);
  *(undefined4 *)(this + 0x90) = *(undefined4 *)param_2;
  *(int *)(this + 0x94) = iVar3;
  if (iVar3 != 0) {
    piVar2 = (int *)(iVar3 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  RichState::NONE((RichState *)(this + 0x98));
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


