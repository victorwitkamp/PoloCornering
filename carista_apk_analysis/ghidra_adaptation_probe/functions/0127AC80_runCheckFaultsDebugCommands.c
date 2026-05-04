/* VagOperationDelegate::runCheckFaultsDebugCommands @ 0127ac80 */


/* VagOperationDelegate::runCheckFaultsDebugCommands(Ecu*, DebugData&,
   std::__ndk1::shared_ptr<Progress> const&) */

void VagOperationDelegate::runCheckFaultsDebugCommands
               (Ecu *param_1,DebugData *param_2,shared_ptr *param_3)

{
  int iVar1;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  DebugData *local_78 [9];
  shared_ptr asStack_54 [36];
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (param_2 == (DebugData *)0x0) {
    local_28 = 0;
  }
  else {
    local_28 = __dynamic_cast(param_2,&Ecu::typeinfo,&VagCanEcu::typeinfo,0);
  }
  local_30 = 0;
  uStack_2c = 0;
  if (local_28 == 0) {
    local_78[0] = param_2;
    FUN_0127ae04(asStack_54,local_78);
    _ZNSt6__ndk110shared_ptrI7CommandI20GetTroubleCodesModelEEaSB8ne190000I28GetVagUdsTroubleCodesCommandTnNS_9enable_ifIXsr17__compatible_withIT_S3_EE5valueEiE4typeELi0EEERS4_ONS0_IS8_EE
              (&local_30,asStack_54);
    FUN_0126ec00(asStack_54);
  }
  else {
    FUN_0126eb2c(asStack_54,&local_28);
    _ZNSt6__ndk110shared_ptrI7CommandI20GetTroubleCodesModelEEaSB8ne190000I28GetVagCanTroubleCodesCommandTnNS_9enable_ifIXsr17__compatible_withIT_S3_EE5valueEiE4typeELi0EEERS4_ONS0_IS8_EE
              (&local_30,asStack_54);
    FUN_0126eb60(asStack_54);
  }
  OperationDelegate::runDebugCommand<GetTroubleCodesModel>
            (asStack_54,(DebugData *)param_1,(shared_ptr *)&local_30);
  iVar1 = Result<GetTroubleCodesModel,void>::isFail((Result<GetTroubleCodesModel,void> *)asStack_54)
  ;
  if ((iVar1 != 0) &&
     (iVar1 = isPowertrainCanEcu((VagOperationDelegate *)param_1,(Ecu *)param_2), iVar1 != 0)) {
    FUN_0126eae4(&local_88,&local_28);
    local_80 = local_88;
    local_7c = uStack_84;
    local_88 = 0;
    uStack_84 = 0;
    OperationDelegate::runDebugCommand<GetTroubleCodesModel>
              ((shared_ptr *)local_78,(DebugData *)param_1,(shared_ptr *)&local_80);
    Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)local_78);
    FUN_011e3ec8(&local_80);
    FUN_0126eb18(&local_88);
  }
  Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)asStack_54);
  FUN_011e3ec8(&local_30);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_24);
}


