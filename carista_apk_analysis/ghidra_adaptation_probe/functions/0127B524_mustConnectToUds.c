/* VagOperationDelegate::mustConnectToUds @ 0127b524 */


/* VagOperationDelegate::mustConnectToUds(Ecu*, int) */

void VagOperationDelegate::mustConnectToUds(Ecu *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  Result<VagEcuInfo,void> aRStack_4c [36];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((param_2 == 0) ||
     (iVar1 = __dynamic_cast(param_2,&Ecu::typeinfo,&VagEcu::typeinfo,0), iVar1 == 0)) {
    iVar1 = VagEcu::getEquivalent((Ecu *)param_2);
    piVar2 = (int *)(iVar1 + 0x18);
    if (*piVar2 == 0) goto LAB_0127b5fc;
    if (param_2 != 0) goto LAB_0127b570;
  }
  else {
    piVar2 = (int *)(param_2 + 0x18);
    if (*piVar2 == 0) goto LAB_0127b5fc;
LAB_0127b570:
    iVar1 = __dynamic_cast(param_2,&Ecu::typeinfo,&VagCanEcu::typeinfo,0);
    if (iVar1 != 0) goto LAB_0127b5fc;
    __dynamic_cast(param_2,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0);
  }
  (**(code **)(*(int *)param_1 + 0x214))(param_1,param_2);
  (**(code **)(*(int *)param_1 + 0x1f8))(aRStack_4c,param_1,*piVar2);
  Result<VagEcuInfo,void>::~Result(aRStack_4c);
LAB_0127b5fc:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


