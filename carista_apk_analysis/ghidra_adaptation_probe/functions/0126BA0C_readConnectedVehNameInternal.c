/* VagOperationDelegate::readConnectedVehNameInternal @ 0126ba0c */


/* VagOperationDelegate::readConnectedVehNameInternal() */

void VagOperationDelegate::readConnectedVehNameInternal(void)

{
  type *in_r0;
  int *in_r1;
  StringModel aSStack_34 [16];
  basic_string *local_24 [2];
  basic_string *local_1c [2];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*in_r1 + 0x20))(local_1c);
  if (local_1c[0] == (basic_string *)0x0) {
    Result<StringModel,void>::Result((Result<StringModel,void> *)in_r0,-6);
  }
  else {
    VagVin::getCarModel((VagVin *)local_24,local_1c[0]);
    if (local_24[0] == (basic_string *)0x0) {
      Result<StringModel,void>::Result((Result<StringModel,void> *)in_r0,-6);
    }
    else {
      StringModel::StringModel(aSStack_34,local_24[0]);
      Result<StringModel,void>::done<StringModel>(in_r0);
      StringModel::~StringModel(aSStack_34);
    }
    FUN_00cbd6dc(local_24);
  }
  FUN_00cbba38(local_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


