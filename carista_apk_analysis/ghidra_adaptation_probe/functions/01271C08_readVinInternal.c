/* VagOperationDelegate::readVinInternal @ 01271c08 */


/* VagOperationDelegate::readVinInternal(std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::readVinInternal(VagOperationDelegate *this,shared_ptr *param_1)

{
  int iVar1;
  shared_ptr *psVar2;
  undefined1 *puVar3;
  int *piVar4;
  int *piVar5;
  int local_a0;
  undefined4 uStack_9c;
  int local_98;
  undefined4 local_94;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_90;
  undefined1 auStack_8f [7];
  undefined1 *local_88;
  int local_6c;
  undefined4 local_68;
  int local_64;
  undefined **local_60;
  VagOperationDelegate *local_5c;
  undefined ***local_50;
  RunOnScopeExit aRStack_48 [32];
  int local_28;
  
  local_28 = __stack_chk_guard;
  Result<StringModel,void>::Result((Result<StringModel,void> *)this);
  local_50 = &local_60;
  local_60 = &PTR_LAB_00d26764_1_014bab0c;
  local_5c = this;
  RunOnScopeExit::RunOnScopeExit(aRStack_48);
  FUN_00d2682a(&local_60);
  piVar5 = *(int **)(param_1 + 0xfc);
  piVar4 = *(int **)(param_1 + 0x100);
  do {
    if (piVar5 == piVar4) {
      FUN_01271fd8(&local_98,&VagCanEcu::CAN_GATEWAY);
      local_6c = local_98;
      local_68 = local_94;
      local_98 = 0;
      local_94 = 0;
      OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_90,param_1);
      Result<StringModel,void>::operator=((Result<StringModel,void> *)this,(Result *)&local_90);
      Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_90);
      FUN_011e659c(&local_6c);
      FUN_011fd0f4(&local_98);
      iVar1 = Result<StringModel,void>::isTerminal((Result<StringModel,void> *)this);
      if (iVar1 == 0) {
        Log::d("Trying to read VAG VIN from OBD2");
        OperationDelegate::readVinInternal((shared_ptr *)&local_90);
        Result<StringModel,void>::operator=((Result<StringModel,void> *)this,(Result *)&local_90);
        Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_90);
      }
LAB_01271dec:
      RunOnScopeExit::~RunOnScopeExit(aRStack_48);
      if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    local_64 = *piVar5;
    local_6c = 0;
    local_68 = 0;
    if ((local_64 == 0) ||
       (iVar1 = __dynamic_cast(local_64,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0), iVar1 == 0)) {
      iVar1 = isUdsOnlyChassisId((VagOperationDelegate *)param_1);
      if (iVar1 == 0) {
        FUN_01271f0c(&local_90,&local_64);
        _ZNSt6__ndk110shared_ptrI7CommandI11StringModelEEaSB8ne190000I16GetCanVinCommandTnNS_9enable_ifIXsr17__compatible_withIT_S3_EE5valueEiE4typeELi0EEERS4_ONS0_IS8_EE
                  (&local_6c,&local_90);
        FUN_0121ae40(&local_90);
        goto LAB_01271cc2;
      }
    }
    else {
      FUN_0124eb00(&local_90,&local_64);
      _ZNSt6__ndk110shared_ptrI7CommandI11StringModelEEaSB8ne190000I16GetUdsVinCommandTnNS_9enable_ifIXsr17__compatible_withIT_S3_EE5valueEiE4typeELi0EEERS4_ONS0_IS8_EE
                (&local_6c,&local_90);
      FUN_011fd0f4(&local_90);
LAB_01271cc2:
      (**(code **)(**(int **)(local_6c + 4) + 0x10))(&local_90);
      puVar3 = local_88;
      if (((byte)local_90 & 1) == 0) {
        puVar3 = auStack_8f;
      }
      Log::d("Trying to read VAG VIN from ECU: %s",puVar3);
      psVar2 = (shared_ptr *)
               std::__ndk1::
               basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
               ~basic_string(&local_90);
      OperationDelegate::runCommand<StringModel>(psVar2,param_1);
      Result<StringModel,void>::operator=((Result<StringModel,void> *)this,(Result *)&local_90);
      Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_90);
      iVar1 = Result<StringModel,void>::isTerminal((Result<StringModel,void> *)this);
      if (iVar1 != 0) {
LAB_01271de6:
        FUN_011e659c(&local_6c);
        goto LAB_01271dec;
      }
      iVar1 = Result<StringModel,void>::isVehicleResponse((Result<StringModel,void> *)this);
      if ((iVar1 != 0) && (local_64 == VagCanEcu::ENGINE)) {
        Log::d("Trying to read VIN from VAG CAN Engine with UDS command");
        FUN_0124eb00(&local_a0,&local_64);
        local_98 = local_a0;
        local_94 = uStack_9c;
        local_a0 = 0;
        uStack_9c = 0;
        OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_90,param_1);
        Result<StringModel,void>::operator=((Result<StringModel,void> *)this,(Result *)&local_90);
        Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_90);
        FUN_011e659c(&local_98);
        FUN_011fd0f4(&local_a0);
        iVar1 = Result<StringModel,void>::isTerminal((Result<StringModel,void> *)this);
        if (iVar1 != 0) goto LAB_01271de6;
      }
    }
    FUN_011e659c(&local_6c);
    piVar5 = piVar5 + 1;
  } while( true );
}


