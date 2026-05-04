/* VagOperationDelegate::getVagSettingAvailabilityForSubmodule @ 012786c8 */


/* VagOperationDelegate::getVagSettingAvailabilityForSubmodule(std::__ndk1::shared_ptr<VagSetting>
   const&, std::__ndk1::shared_ptr<VagEcuInfo> const&) */

void __thiscall
VagOperationDelegate::getVagSettingAvailabilityForSubmodule
          (VagOperationDelegate *this,shared_ptr *param_1,shared_ptr *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  IllegalArgumentException *this_00;
  int *piVar3;
  int *piVar4;
  basic_string abStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = (**(code **)(**(int **)param_1 + 0x3c))();
  if (iVar1 == 0) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_28,"Non-submodule setting passed to getVagSettingAvailabilityForSubmodule")
    ;
    IllegalArgumentException::IllegalArgumentException(this_00,abStack_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  puVar2 = *(undefined4 **)(*(int *)param_2 + 0x10);
  if (puVar2 != (undefined4 *)0x0) {
    piVar3 = (int *)puVar2[1];
    for (piVar4 = (int *)*puVar2; piVar4 != piVar3; piVar4 = piVar4 + 2) {
      if (((*piVar4 != 0) && (*(int *)(*piVar4 + 8) != 0)) &&
         (iVar1 = (**(code **)(**(int **)(*(int *)param_1 + 0x54) + 0x10))(), iVar1 != 0))
      goto LAB_01278712;
    }
  }
  iVar1 = 0;
LAB_01278712:
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}


