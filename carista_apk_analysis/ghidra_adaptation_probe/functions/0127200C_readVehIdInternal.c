/* VagOperationDelegate::readVehIdInternal @ 0127200c */


/* VagOperationDelegate::readVehIdInternal() */

void VagOperationDelegate::readVehIdInternal(void)

{
  Result<StringModel,void> *in_r0;
  int iVar1;
  int *in_r1;
  StringModel aSStack_58 [16];
  Result<VagEcuInfo,void> aRStack_48 [28];
  int *local_2c;
  uint *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  (**(code **)(*(int *)in_r1[6] + 0x44))(local_24);
  if ((local_24[0] == (uint *)0x0) || ((*local_24[0] | 2) != 6)) {
    Log::e("VAG readVehId not applicable to vehicle");
    Result<StringModel,void>::Result(in_r0,-5);
  }
  else {
    (**(code **)(*in_r1 + 0x194))(aRStack_48);
    iVar1 = Result<VagEcuInfo,void>::isFail(aRStack_48);
    if (iVar1 == 0) {
      StringModel::StringModel(aSStack_58,*(basic_string **)(*local_2c + 8));
      Result<StringModel,void>::done<StringModel>((type *)in_r0);
      StringModel::~StringModel(aSStack_58);
    }
    else {
      Result<VagEcuInfo,void>::failAs<StringModel>();
    }
    Result<VagEcuInfo,void>::~Result(aRStack_48);
  }
  FUN_00d223c4(local_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


