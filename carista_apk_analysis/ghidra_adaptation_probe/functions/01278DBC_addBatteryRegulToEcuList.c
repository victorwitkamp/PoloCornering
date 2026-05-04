/* VagOperationDelegate::addBatteryRegulToEcuList @ 01278dbc */


/* VagOperationDelegate::addBatteryRegulToEcuList(Result<EcuListModel, void> const&) */

void VagOperationDelegate::addBatteryRegulToEcuList(Result *param_1)

{
  int iVar1;
  VagOperationDelegate *in_r1;
  Result<EcuListModel,void> *in_r2;
  vector avStack_7c [12];
  Result<VagEcuInfo,void> aRStack_70 [36];
  EcuList aEStack_4c [20];
  Ecu *local_38;
  EcuList aEStack_34 [16];
  int local_24;
  
  local_24 = __stack_chk_guard;
  iVar1 = Result<EcuListModel,void>::isFail(in_r2);
  if (((iVar1 == 0) &&
      (iVar1 = EcuList::contains((EcuList *)(**(int **)(in_r2 + 0x1c) + 4),VagEcu::BATTERY_REGULATOR
                                ), iVar1 == 0)) && (iVar1 = isUdsOnlyChassisId(in_r1), iVar1 == 0))
  {
    (**(code **)(*(int *)in_r1 + 0x194))(aRStack_70);
    iVar1 = Result<VagEcuInfo,void>::isFatalFail(aRStack_70);
    if (iVar1 == 0) {
      iVar1 = Result<VagEcuInfo,void>::isVehicleResponse(aRStack_70);
      if (iVar1 == 0) {
        Result<EcuListModel,void>::Result((Result<EcuListModel,void> *)param_1,(Result *)in_r2);
      }
      else {
        iVar1 = **(int **)(in_r2 + 0x1c);
        local_38 = VagEcu::BATTERY_REGULATOR;
        FUN_00db6cfc(avStack_7c,&local_38,1);
        EcuList::makeConfirmed(aEStack_4c,avStack_7c,true);
        EcuList::mergeUnique(aEStack_34,(EcuList *)(iVar1 + 4),aEStack_4c);
        FUN_00ce44e8(aEStack_4c);
        FUN_00cc8d6c(avStack_7c);
        EcuListModel::EcuListModel((EcuListModel *)aEStack_4c,aEStack_34);
        Result<EcuListModel,void>::done<EcuListModel>((type *)param_1);
        EcuListModel::~EcuListModel((EcuListModel *)aEStack_4c);
        FUN_00ce44e8(aEStack_34);
      }
    }
    else {
      Result<VagEcuInfo,void>::stateAs<EcuListModel,void>();
    }
    Result<VagEcuInfo,void>::~Result(aRStack_70);
  }
  else {
    Result<EcuListModel,void>::Result((Result<EcuListModel,void> *)param_1,(Result *)in_r2);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


