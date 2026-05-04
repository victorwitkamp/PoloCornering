/* VagOperationDelegate::getCodingRawAddress @ 0126be08 */


/* VagOperationDelegate::getCodingRawAddress(Ecu*, unsigned short) */

void VagOperationDelegate::getCodingRawAddress(Ecu *param_1,ushort param_2)

{
  bool bVar1;
  Ecu *pEVar2;
  int iVar3;
  IllegalArgumentException *this;
  IllegalStateException *this_00;
  Ecu *pEVar4;
  int *piVar5;
  undefined4 uVar6;
  Ecu *pEVar7;
  Ecu *pEVar8;
  undefined4 local_58;
  int iStack_54;
  int local_50;
  basic_string abStack_4c [12];
  Result<VagEcuInfo,void> aRStack_40 [24];
  int *local_28;
  int *local_24;
  int local_1c;
  
  pEVar4 = (Ecu *)(uint)param_2;
  local_1c = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0x1f8))(aRStack_40,param_1,pEVar4);
  if (*local_28 != 1) {
    this = (IllegalArgumentException *)__cxa_allocate_exception(8);
    (**(code **)(*(int *)pEVar4 + 0x10))(&local_58,pEVar4);
    if (((byte)local_58 & 1) == 0) {
      local_50 = (int)&local_58 + 1;
    }
    StringUtils::format((char *)abStack_4c,"Non-connected ECU given for coding: %s",local_50);
    IllegalArgumentException::IllegalArgumentException(this,abStack_4c);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if ((pEVar4 == (Ecu *)0x0) ||
     (pEVar2 = (Ecu *)__dynamic_cast(pEVar4,&Ecu::typeinfo,&VagEcu::typeinfo,0),
     pEVar2 == (Ecu *)0x0)) {
    pEVar2 = (Ecu *)VagEcu::getEquivalent(pEVar4);
  }
  pEVar8 = *(Ecu **)(pEVar2 + 0x14);
  if (pEVar8 != pEVar4 && pEVar2 != pEVar4) {
    pEVar8 = (Ecu *)0x0;
  }
  pEVar7 = *(Ecu **)(pEVar2 + 0x18);
  if (pEVar7 != pEVar4 && pEVar2 != pEVar4) {
    pEVar7 = (Ecu *)0x0;
  }
  local_58 = *local_24;
  iStack_54 = local_24[1];
  if (iStack_54 != 0) {
    piVar5 = (int *)(iStack_54 + 4);
    do {
      ExclusiveAccess(piVar5);
      bVar1 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar1);
    *piVar5 = *piVar5 + 1;
  }
  if (*(int *)(local_58 + 4) == 1) {
    if (*(int *)(local_58 + 0x20) == 2) {
      uVar6 = 2;
    }
    else {
      if (*(int *)(local_58 + 0x20) != 3) {
        this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
        FUN_00cb4d44(abStack_4c,"Raw coding setting requested for ECU that doesn\'t have coding");
        IllegalStateException::IllegalStateException(this_00,abStack_4c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(this_00,&IllegalStateException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      uVar6 = 3;
    }
    (**(code **)(*(int *)param_1 + 0x17c))(param_1,uVar6,pEVar8,0);
  }
  else {
    if ((pEVar8 == (Ecu *)0x0) ||
       (iVar3 = (**(code **)(*(int *)param_1 + 0x184))(param_1,pEVar8), iVar3 == 0)) {
      pEVar8 = pEVar7;
    }
    (**(code **)(*(int *)param_1 + 0x17c))(param_1,8,pEVar8,0x600);
  }
  FUN_00d08540(&local_58);
  Result<VagEcuInfo,void>::~Result(aRStack_40);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c,__stack_chk_guard);
  }
  return;
}


