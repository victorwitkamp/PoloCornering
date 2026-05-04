/* VagOperationDelegate::checkSettingsPrerequisites @ 0126f994 */


/* VagOperationDelegate::checkSettingsPrerequisites() */

void __thiscall VagOperationDelegate::checkSettingsPrerequisites(VagOperationDelegate *this)

{
  int iVar1;
  int iVar2;
  Result<VagEcuInfo,void> aRStack_5c [36];
  Result<EcuList_const,void> aRStack_38 [36];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x14))(aRStack_38,this,0);
  iVar1 = Result<EcuList_const,void>::isFatalFail(aRStack_38);
  if (iVar1 == 0) {
    iVar1 = checkHoodClosed(this);
    iVar2 = State::isFatalError(iVar1);
    if ((iVar2 == 0) && (iVar1 != -0x2a)) {
      (**(code **)(*(int *)this + 0x194))(aRStack_5c,this,VagEcu::CENTRAL_ELEC,1,0);
      Result<VagEcuInfo,void>::isTerminal(aRStack_5c);
      Result<VagEcuInfo,void>::~Result(aRStack_5c);
    }
  }
  Result<EcuList_const,void>::~Result(aRStack_38);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


