/* VagOperationDelegate::resetCodes @ 0126ecac */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* VagOperationDelegate::resetCodes(Ecu*) */

void VagOperationDelegate::resetCodes(Ecu *param_1)

{
  int iVar1;
  shared_ptr *in_r1;
  Ecu *in_r2;
  undefined4 local_80;
  undefined4 local_7c;
  Progress aPStack_5c [8];
  undefined4 local_54;
  undefined4 uStack_50;
  shared_ptr asStack_4c [36];
  int local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,-5);
  if ((in_r2 == (Ecu *)0x0) || (iVar1 = __dynamic_cast(), iVar1 == 0)) {
    in_r2 = (Ecu *)VagEcu::getEquivalent(in_r2);
  }
  iVar1 = (**(code **)(*(int *)in_r1 + 0x214))();
  if (iVar1 != 0) {
    local_28 = *(int *)(in_r2 + 0x14);
    FUN_0126eed4(&local_54,&local_28);
    local_80 = local_54;
    local_7c = uStack_50;
    local_54 = 0;
    uStack_50 = 0;
    Progress::NUL(aPStack_5c);
    OperationDelegate::runCommand<EmptyModel>(asStack_4c,in_r1);
    Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)param_1,(Result *)asStack_4c);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_4c);
    FUN_011e01a0(aPStack_5c);
    FUN_011e4048(&local_80);
    FUN_012129f8(&local_54);
    iVar1 = State::isFatalError(**(int **)(param_1 + 0x18));
    if (iVar1 != 0) goto LAB_0126ee40;
  }
  iVar1 = (**(code **)(*(int *)in_r1 + 0x218))();
  if (iVar1 != 0) {
    local_28 = *(int *)(in_r2 + 0x18);
    if ((local_28 == VagUdsEcu::ENGINE) || (local_28 == VagUdsEcu::TRANSMISSION)) {
      FUN_0126ef48(&local_54,&local_28);
      local_80 = local_54;
      local_7c = uStack_50;
      local_54 = 0;
      uStack_50 = 0;
      Progress::NUL(aPStack_5c);
      OperationDelegate::runBroadcastCommand<EmptyModel>(asStack_4c,in_r1);
      FUN_011e01a0(aPStack_5c);
      FUN_011e4048(&local_80);
      FUN_0126ef7c(&local_54);
      Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
      ::stateAs<EmptyModel,void>();
      Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)param_1,(Result *)&local_80);
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_80);
      Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
      ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
                 *)asStack_4c);
    }
    else {
      FUN_0126ef9c(&local_54,&local_28);
      local_80 = local_54;
      local_7c = uStack_50;
      local_54 = 0;
      uStack_50 = 0;
      Progress::NUL(aPStack_5c);
      OperationDelegate::runCommand<EmptyModel>(asStack_4c,in_r1);
      Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)param_1,(Result *)asStack_4c);
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_4c);
      FUN_011e01a0(aPStack_5c);
      FUN_011e4048(&local_80);
      FUN_011f9c20(&local_54);
    }
    State::isFatalError(**(int **)(param_1 + 0x18));
  }
LAB_0126ee40:
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


