/* VagOperationDelegate::getVagUdsSubmoduleId @ 012741fc */


/* VagOperationDelegate::getVagUdsSubmoduleId(std::__ndk1::shared_ptr<VagSetting> const&) */

void __thiscall
VagOperationDelegate::getVagUdsSubmoduleId(VagOperationDelegate *this,shared_ptr *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  IllegalStateException *pIVar5;
  IllegalArgumentException *this_00;
  int *piVar6;
  int local_7c;
  int iStack_78;
  undefined4 *local_70;
  int iStack_6c;
  int local_64;
  int local_60;
  undefined1 auStack_58 [12];
  basic_string abStack_4c [12];
  Result<VagEcuInfo,void> aRStack_40 [24];
  int *local_28;
  int *local_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar2 = (**(code **)(**(int **)param_1 + 0x14))();
  (**(code **)(*(int *)this + 0x1f8))(aRStack_40,this,uVar2);
  iVar3 = Result<VagEcuInfo,void>::isFail(aRStack_40);
  if ((iVar3 != 0) || (local_64 = *local_24, local_64 == 0)) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    (**(code **)(**(int **)param_1 + 0x18))(&local_70);
    FUN_00cbe7e4(&local_64,"getVagUdsSubmoduleId couldn\'t find ECU info for setting ",&local_70);
    FUN_00cbe80c(auStack_58,&local_64,", result state = ");
    std::__ndk1::to_string((__ndk1 *)&local_7c,*local_28);
    FUN_00d1fa20(abStack_4c,auStack_58,&local_7c);
    IllegalArgumentException::IllegalArgumentException(this_00,abStack_4c);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  local_60 = local_24[1];
  if (local_60 != 0) {
    piVar4 = (int *)(local_60 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  local_70 = *(undefined4 **)(local_64 + 0x10);
  iStack_6c = *(int *)(local_64 + 0x14);
  if (iStack_6c != 0) {
    piVar4 = (int *)(iStack_6c + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  local_7c = *(int *)(local_64 + 0x18);
  iStack_78 = *(int *)(local_64 + 0x1c);
  if (iStack_78 != 0) {
    piVar4 = (int *)(iStack_78 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  if (local_70 != (undefined4 *)0x0) {
    if (local_7c == 0) {
      pIVar5 = (IllegalStateException *)__cxa_allocate_exception(8);
      (**(code **)(**(int **)param_1 + 0x18))(auStack_58);
      FUN_00cbe7e4(abStack_4c,"UDS submoduleToPartNoId is null for setting ",auStack_58);
      IllegalStateException::IllegalStateException(pIVar5,abStack_4c);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(pIVar5,&IllegalStateException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    piVar4 = (int *)*local_70;
    piVar6 = (int *)local_70[1];
    while( true ) {
      if (piVar4 == piVar6) {
        pIVar5 = (IllegalStateException *)__cxa_allocate_exception(8);
        (**(code **)(**(int **)param_1 + 0x18))(auStack_58);
        FUN_00cbe7e4(abStack_4c,"UDS submodule ID not found for setting ",auStack_58);
        IllegalStateException::IllegalStateException(pIVar5,abStack_4c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar5,&IllegalStateException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      if (*piVar4 == 0) {
        pIVar5 = (IllegalStateException *)__cxa_allocate_exception(8);
        (**(code **)(**(int **)param_1 + 0x18))(auStack_58);
        FUN_00cbe7e4(abStack_4c,"UDS submoduleInfo is null for setting ",auStack_58);
        IllegalStateException::IllegalStateException(pIVar5,abStack_4c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar5,&IllegalStateException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      if (*(int *)(*piVar4 + 8) == 0) {
        pIVar5 = (IllegalStateException *)__cxa_allocate_exception(8);
        (**(code **)(**(int **)param_1 + 0x18))(auStack_58);
        FUN_00cbe7e4(abStack_4c,"UDS submoduleInfo has null partNo for setting ",auStack_58);
        IllegalStateException::IllegalStateException(pIVar5,abStack_4c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar5,&IllegalStateException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      iVar3 = (**(code **)(**(int **)(*(int *)param_1 + 0x54) + 0x10))();
      if (iVar3 != 0) break;
      piVar4 = piVar4 + 2;
    }
    FUN_01274570(local_7c,*(undefined4 *)(*piVar4 + 8));
    FUN_00d08b74(&local_7c);
    FUN_00d08642(&local_70);
    FUN_00d08540(&local_64);
    Result<VagEcuInfo,void>::~Result(aRStack_40);
    if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(local_1c);
    }
    return;
  }
  pIVar5 = (IllegalStateException *)__cxa_allocate_exception(8);
  (**(code **)(**(int **)param_1 + 0x18))(auStack_58);
  FUN_00cbe7e4(abStack_4c,"UDS submodules are null for setting ",auStack_58);
  IllegalStateException::IllegalStateException(pIVar5,abStack_4c);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(pIVar5,&IllegalStateException::typeinfo,IllegalStateException::~IllegalStateException)
  ;
}


