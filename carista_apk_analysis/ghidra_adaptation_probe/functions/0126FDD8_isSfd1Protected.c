/* VagOperationDelegate::isSfd1Protected @ 0126fdd8 */


/* VagOperationDelegate::isSfd1Protected(Ecu*) */

void VagOperationDelegate::isSfd1Protected(Ecu *param_1)

{
  int iVar1;
  int iVar2;
  int *in_r1;
  int in_r2;
  undefined8 uVar3;
  Result<VagEcuInfo,void> local_48 [36];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (in_r2 == 0) {
LAB_0126fe5c:
    local_48[0] = (Result<VagEcuInfo,void>)0x0;
    Result<bool,void>::done<bool>((type *)param_1);
  }
  else {
    iVar1 = __dynamic_cast();
    uVar3 = __dynamic_cast();
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 == 0) {
      if (iVar1 != 0) {
        iVar2 = *(int *)(iVar1 + 0x18);
      }
      if ((iVar1 == 0 || iVar2 == 0) || (iVar2 = (**(code **)(*in_r1 + 0x184))(), iVar2 == 0))
      goto LAB_0126fe5c;
    }
    (**(code **)(*in_r1 + 0x194))(local_48);
    iVar2 = Result<VagEcuInfo,void>::isFail(local_48);
    if (iVar2 == 0) {
      Result<bool,void>::done<bool>((type *)param_1);
    }
    else {
      Result<VagEcuInfo,void>::stateAs<bool,void>();
    }
    Result<VagEcuInfo,void>::~Result(local_48);
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


