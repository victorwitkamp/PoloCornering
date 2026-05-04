/* VagOperationDelegate::isEcuPresent @ 0126bba8 */


/* VagOperationDelegate::isEcuPresent(Ecu*) */

void VagOperationDelegate::isEcuPresent(Ecu *param_1)

{
  int iVar1;
  Ecu *pEVar2;
  int *in_r1;
  Ecu *in_r2;
  undefined1 uStack_6d;
  Result<EcuList_const,void> local_6c [24];
  int *local_54;
  undefined4 *local_50;
  Result<VagEcuInfo,void> aRStack_48 [24];
  int *local_30;
  int local_24;
  
  local_24 = __stack_chk_guard;
  (**(code **)(*in_r1 + 0x1f8))(aRStack_48);
  iVar1 = Result<VagEcuInfo,void>::isVehicleResponse(aRStack_48);
  if (iVar1 == 0) {
    if (*local_30 == -5) {
      local_6c[0] = (Result<EcuList_const,void>)0x0;
      FUN_00d31274(param_1,local_6c);
    }
    else {
      if ((in_r2 == (Ecu *)0x0) || (pEVar2 = (Ecu *)__dynamic_cast(), pEVar2 == (Ecu *)0x0)) {
        pEVar2 = (Ecu *)VagEcu::getEquivalent(in_r2);
      }
      (**(code **)(*in_r1 + 0x14))(local_6c);
      if ((*local_54 == 1) && (iVar1 = EcuList::contains((EcuList *)*local_50,pEVar2), iVar1 == 0))
      {
        uStack_6d = 0;
        FUN_00d31274(param_1,&uStack_6d);
      }
      else {
        *(undefined4 *)param_1 = 0;
        *(undefined4 *)(param_1 + 4) = 0;
      }
      Result<EcuList_const,void>::~Result(local_6c);
    }
  }
  else {
    local_6c[0] = (Result<EcuList_const,void>)0x1;
    FUN_00d31274(param_1,local_6c);
  }
  Result<VagEcuInfo,void>::~Result(aRStack_48);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


