/* VagCanVimOperation::VagCanVimOperation @ 012d923c */


/* VagCanVimOperation::VagCanVimOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<VagBasicSettingTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
VagCanVimOperation::VagCanVimOperation
          (VagCanVimOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  shared_ptr *psVar4;
  IllegalArgumentException *this_00;
  shared_ptr *local_38;
  shared_ptr *psStack_34;
  
  iVar2 = __stack_chk_guard;
  if (*(int *)(param_2 + 4) != 0) {
    piVar3 = (int *)(*(int *)(param_2 + 4) + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  local_38 = param_2;
  psStack_34 = param_3;
  VimOperation::VimOperation
            ((VimOperation *)this,param_1,(shared_ptr *)&stack0xffffffd0,param_3,
             (LibStr *)&LibStr::enable_vim_disclaimer_msg);
  FUN_00cc67b0(&stack0xffffffd0);
  *(undefined ***)this = &PTR__VagCanVimOperation_014bf4fc;
  *(undefined8 *)(this + 300) = 0;
  *(undefined8 *)(this + 0x134) = 0;
  if (*(int *)(*(int *)param_2 + 0x90) == *(int *)(*(int *)param_2 + 0x94)) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&stack0xffffffd0,"Missing VIM setting");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&stack0xffffffd0);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  FUN_00d5b5a0(this + 300);
  (**(code **)(*(int *)this + 0x14))(&local_38,this);
  if (psStack_34 != (shared_ptr *)0x0) {
    psVar4 = psStack_34 + 4;
    do {
      ExclusiveAccess(psVar4);
      bVar1 = (bool)hasExclusiveAccess(psVar4);
    } while (!bVar1);
    *(int *)psVar4 = *(int *)psVar4 + 1;
  }
  FUN_012d9380(this + 0x134,&stack0xffffffd0);
  FUN_0124612c(&stack0xffffffd0);
  FUN_00d5a8a2(&local_38);
  if (__stack_chk_guard != iVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}


