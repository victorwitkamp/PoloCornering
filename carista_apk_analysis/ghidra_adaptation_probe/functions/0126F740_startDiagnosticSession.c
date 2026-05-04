/* VagOperationDelegate::startDiagnosticSession @ 0126f740 */


/* VagOperationDelegate::startDiagnosticSession(Ecu*, std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::startDiagnosticSession
          (VagOperationDelegate *this,Ecu *param_1,shared_ptr *param_2)

{
  int iVar1;
  int iVar2;
  shared_ptr *psVar3;
  undefined1 uStack_59;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  shared_ptr asStack_48 [36];
  int local_24;
  
  local_24 = __stack_chk_guard;
  Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)this,-5);
  iVar1 = (**(code **)(*(int *)param_1 + 0x214))(param_1,param_2);
  if ((param_2 == (shared_ptr *)0x0) ||
     (iVar2 = __dynamic_cast(param_2,&Ecu::typeinfo,&VagEcu::typeinfo,0), psVar3 = param_2,
     iVar2 == 0)) {
    psVar3 = (shared_ptr *)VagEcu::getEquivalent((Ecu *)param_2);
  }
  if (iVar1 != 0) {
    uStack_59 = 0x89;
    FUN_0126f8f4(&local_58,psVar3 + 0x14,&uStack_59);
    local_50 = local_58;
    local_4c = uStack_54;
    local_58 = 0;
    uStack_54 = 0;
    OperationDelegate::runCommand<EmptyModel>(asStack_48,(shared_ptr *)param_1);
    Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)this,(Result *)asStack_48);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_48);
    FUN_011e4048(&local_50);
    FUN_011ff7b8(&local_58);
  }
  iVar1 = (**(code **)(*(int *)param_1 + 0x218))(param_1,param_2,**(undefined4 **)(this + 0x18));
  if (iVar1 != 0) {
    psVar3 = psVar3 + 0x18;
    if (*(int *)psVar3 == VagUdsEcu::ABS) {
      uStack_59 = 1;
      FUN_0126f928(&local_58,psVar3,&uStack_59);
      local_50 = local_58;
      local_4c = uStack_54;
      local_58 = 0;
      uStack_54 = 0;
      OperationDelegate::runCommand<EmptyModel>(asStack_48,(shared_ptr *)param_1);
      Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)this,(Result *)asStack_48);
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_48);
      FUN_011e4048(&local_50);
      FUN_011ff7b8(&local_58);
      iVar1 = Result<EmptyModel,void>::isFatalFail((Result<EmptyModel,void> *)this);
      if (iVar1 != 0) goto LAB_0126f8a0;
    }
    uStack_59 = 3;
    FUN_0126f928(&local_58,psVar3,&uStack_59);
    local_50 = local_58;
    local_4c = uStack_54;
    local_58 = 0;
    uStack_54 = 0;
    OperationDelegate::runCommand<EmptyModel>(asStack_48,(shared_ptr *)param_1);
    Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)this,(Result *)asStack_48);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_48);
    FUN_011e4048(&local_50);
    FUN_011ff7b8(&local_58);
  }
LAB_0126f8a0:
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


