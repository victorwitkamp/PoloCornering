/* BmwECanEpbOperation::BmwECanEpbOperation @ 0128e304 */


/* BmwECanEpbOperation::BmwECanEpbOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<BmwEGenericTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwECanEpbOperation::BmwECanEpbOperation
          (BmwECanEpbOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

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
  GenericToolActionOperation::GenericToolActionOperation
            ((GenericToolActionOperation *)this,param_1,(shared_ptr *)&local_1c,param_3);
  FUN_00cc67b0((shared_ptr *)&local_1c);
  *(undefined ***)this = &PTR__BmwECanEpbOperation_014bb67c;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


