/* VagAuxHeaterOperation::VagAuxHeaterOperation @ 012d58d4 */


/* VagAuxHeaterOperation::VagAuxHeaterOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<VagBasicSettingTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
VagAuxHeaterOperation::VagAuxHeaterOperation
          (VagAuxHeaterOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
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
  SingleButtonGenericOperation::SingleButtonGenericOperation
            ((SingleButtonGenericOperation *)this,param_1,(shared_ptr *)&local_28,param_3);
  FUN_00cc67b0(&local_28);
  *(undefined ***)this = &PTR__VagAuxHeaterOperation_014bed3c;
  if (*(int *)(*(int *)param_2 + 0x90) == *(int *)(*(int *)param_2 + 0x94)) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_28,"Tool passed to VagAuxHeaterOperation does not have settings!");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&local_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


