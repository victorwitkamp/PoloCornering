/* BmwEVimOperation::BmwEVimOperation @ 0128f50c */


/* BmwEVimOperation::BmwEVimOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<BmwEGenericTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwEVimOperation::BmwEVimOperation
          (BmwEVimOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  char *__s1;
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
  VimOperation::VimOperation
            ((VimOperation *)this,param_1,(shared_ptr *)&local_28,param_3,
             (LibStr *)&LibStr::enable_vim_disclaimer_msg);
  FUN_00cc67b0(&local_28);
  *(undefined4 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined ***)this = &PTR__BmwEVimOperation_014bb828;
  FUN_011e01d6(this + 0x130,*(int *)param_2 + 0x90);
  if (*(int *)(this + 0x130) == *(int *)(this + 0x134)) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_28,"Vim operation is created without settings");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&local_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  __s1 = (char *)(**(code **)(*(int *)(*(int *)param_2 + 0x60) + 8))
                           ((int *)(*(int *)param_2 + 0x60));
  iVar3 = strcmp(__s1,"BmwEVimToolCIC");
  *(uint *)(this + 300) = (uint)(iVar3 == 0);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


