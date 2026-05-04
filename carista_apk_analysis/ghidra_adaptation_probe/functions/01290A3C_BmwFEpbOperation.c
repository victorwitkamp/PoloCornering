/* BmwFEpbOperation::BmwFEpbOperation @ 01290a3c */


/* BmwFEpbOperation::BmwFEpbOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<BmwFGenericTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwFEpbOperation::BmwFEpbOperation
          (BmwFEpbOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  char *__s1;
  int iVar3;
  int local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24 = *(int *)param_2;
  iStack_20 = *(int *)(param_2 + 4);
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
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined ***)this = &PTR__BmwFEpbOperation_014bbaa8;
  local_24 = *(int *)param_2;
  iStack_20 = *(int *)(param_2 + 4);
  if (iStack_20 != 0) {
    piVar2 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  __s1 = (char *)(**(code **)(*(int *)(local_24 + 0x5c) + 8))((int *)(local_24 + 0x5c));
  iVar3 = strcmp(__s1,"BmwFEpbTool_DSC_G20");
  FUN_00e0c59c(&local_24);
  if (iVar3 == 0) {
    this[0x143] = (BmwFEpbOperation)0x1;
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


