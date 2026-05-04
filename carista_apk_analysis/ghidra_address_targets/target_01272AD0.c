/* Target address 01272ad0 */
/* Function readVagUdsCodingValue @ 01272ad0 */


/* VagOperationDelegate::readVagUdsCodingValue(unsigned long long) */

void VagOperationDelegate::readVagUdsCodingValue(ulonglong param_1)

{
  Result<BytesModel,void> *this;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 local_80;
  shared_ptr asStack_7c [8];
  Result<VagEcuInfo,void> aRStack_74 [36];
  Result<VagEcuInfo,void> aRStack_50 [24];
  int *local_38;
  undefined4 *local_34;
  undefined4 local_2c;
  int local_28;
  
  piVar3 = (int *)(param_1 >> 0x20);
  this = (Result<BytesModel,void> *)param_1;
  local_28 = __stack_chk_guard;
  (**(code **)(*piVar3 + 0x1ac))(this);
  iVar1 = Result<BytesModel,void>::isVehicleResponse(this);
  if (iVar1 != 0) {
    uVar4 = 1;
    if (**(int **)(this + 0x18) == 1) {
      uVar4 = 3;
    }
    local_2c = uVar4;
    uVar2 = (**(code **)(*piVar3 + 0x154))(piVar3);
    (**(code **)(*piVar3 + 0x1f8))(aRStack_50,piVar3,uVar2);
    if (*local_38 == 1) {
      (**(code **)(*(int *)*local_34 + 0x18))(asStack_7c,(int *)*local_34,uVar4);
      Result<VagEcuInfo,void>::done(aRStack_74,asStack_7c);
      (**(code **)(*piVar3 + 0x18c))(piVar3,uVar2,aRStack_74);
    }
    else {
      local_80 = 2;
      local_84 = 0;
      local_8c = 0;
      uStack_88 = 0;
      local_94 = 0;
      uStack_90 = 0;
      local_9c = 0;
      uStack_98 = 0;
      local_a4 = 0;
      uStack_a0 = 0;
      local_ac = 0;
      uStack_a8 = 0;
      FUN_01272c78(asStack_7c,&local_80,&local_84,&uStack_88,&local_8c,&local_2c,&uStack_90,
                   &local_94,&uStack_98,&local_9c,&uStack_a0,&local_a4,&uStack_a8,&local_ac);
      Result<VagEcuInfo,void>::done(aRStack_74,asStack_7c);
      (**(code **)(*piVar3 + 0x18c))(piVar3,uVar2,aRStack_74);
    }
    Result<VagEcuInfo,void>::~Result(aRStack_74);
    FUN_00d08540(asStack_7c);
    Result<VagEcuInfo,void>::~Result(aRStack_50);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


