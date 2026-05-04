/* VagOperationDelegate::mustConnectToCan @ 0127b3ec */


/* VagOperationDelegate::mustConnectToCan(Ecu*) */

void __thiscall VagOperationDelegate::mustConnectToCan(VagOperationDelegate *this,Ecu *param_1)

{
  int iVar1;
  Ecu *pEVar2;
  int iVar3;
  Ecu *pEVar4;
  Result<VagEcuInfo,void> aRStack_4c [36];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar1 = isUdsOnlyChassisId(this);
  if (iVar1 != 0) goto LAB_0127b40e;
  if ((param_1 == (Ecu *)0x0) ||
     (iVar1 = __dynamic_cast(param_1,&Ecu::typeinfo,&VagEcu::typeinfo,0), iVar1 == 0)) {
    pEVar2 = (Ecu *)VagEcu::getEquivalent(param_1);
    pEVar4 = pEVar2 + 0x14;
    iVar1 = *(int *)pEVar4;
    if (iVar1 == 0) goto LAB_0127b40e;
    if (param_1 != (Ecu *)0x0) goto LAB_0127b468;
  }
  else {
    pEVar4 = param_1 + 0x14;
    iVar1 = *(int *)pEVar4;
    pEVar2 = param_1;
    if (iVar1 == 0) goto LAB_0127b40e;
LAB_0127b468:
    iVar3 = __dynamic_cast(param_1,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0);
    if (iVar3 != 0) goto LAB_0127b40e;
    __dynamic_cast(param_1,&Ecu::typeinfo,&VagCanEcu::typeinfo,0);
  }
  iVar1 = (**(code **)(*(int *)this + 0x184))(this,iVar1);
  if ((iVar1 == 0) && (*(int *)(pEVar2 + 0x18) != 0)) {
    (**(code **)(*(int *)this + 0x184))(this);
  }
  (**(code **)(*(int *)this + 0x1f8))(aRStack_4c,this,*(undefined4 *)pEVar4);
  Result<VagEcuInfo,void>::~Result(aRStack_4c);
LAB_0127b40e:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


