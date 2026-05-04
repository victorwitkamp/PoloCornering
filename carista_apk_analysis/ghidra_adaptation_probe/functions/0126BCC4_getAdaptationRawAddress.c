/* VagOperationDelegate::getAdaptationRawAddress @ 0126bcc4 */


/* VagOperationDelegate::getAdaptationRawAddress(Ecu*, unsigned short) */

void VagOperationDelegate::getAdaptationRawAddress(Ecu *param_1,ushort param_2)

{
  int iVar1;
  Ecu *pEVar2;
  int iVar3;
  IllegalArgumentException *this;
  Ecu *pEVar4;
  undefined4 uVar5;
  int in_r3;
  Ecu *pEVar6;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_3c;
  int local_34;
  
  iVar1 = __stack_chk_guard;
  pEVar4 = (Ecu *)(uint)param_2;
  local_3c = pEVar4;
  local_34 = in_r3;
  if ((pEVar4 == (Ecu *)0x0) ||
     (pEVar2 = (Ecu *)__dynamic_cast(pEVar4,&Ecu::typeinfo,&VagEcu::typeinfo,0,param_1),
     pEVar2 == (Ecu *)0x0)) {
    pEVar2 = (Ecu *)VagEcu::getEquivalent(pEVar4);
  }
  pEVar6 = *(Ecu **)(pEVar2 + 0x14);
  if (((pEVar6 == pEVar4 || pEVar2 == pEVar4) && (pEVar6 != (Ecu *)0x0)) &&
     (iVar3 = (**(code **)(*(int *)param_1 + 0x184))(param_1,pEVar6), iVar3 != 0)) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)param_1 + 0x17c);
    if (__stack_chk_guard != iVar1) {
LAB_0126bdc4:
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    uVar5 = 0;
  }
  else {
    pEVar6 = *(Ecu **)(pEVar2 + 0x18);
    if (((pEVar6 != pEVar4 && pEVar2 != pEVar4) || (pEVar6 == (Ecu *)0x0)) ||
       (iVar3 = (**(code **)(*(int *)param_1 + 0x184))(param_1,pEVar6), iVar3 == 0)) {
      this = (IllegalArgumentException *)__cxa_allocate_exception(8);
      (**(code **)(*(int *)pEVar4 + 0x10))(&local_3c,pEVar4);
      if (((uint)local_3c & 1) == 0) {
        local_34 = (int)&local_3c + 1;
      }
      StringUtils::format(&stack0xffffffd0,"Non-connected ECU given for an adaptation: %s",local_34)
      ;
      IllegalArgumentException::IllegalArgumentException(this,(basic_string *)&stack0xffffffd0);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)param_1 + 0x17c);
    if (__stack_chk_guard != iVar1) goto LAB_0126bdc4;
    uVar5 = 7;
  }
                    /* WARNING: Could not recover jumptable at 0x0126bd7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar5,pEVar6);
  return;
}


