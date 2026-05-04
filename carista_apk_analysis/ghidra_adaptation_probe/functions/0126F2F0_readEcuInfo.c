/* VagOperationDelegate::readEcuInfo @ 0126f2f0 */


/* VagOperationDelegate::readEcuInfo(Ecu*) */

void VagOperationDelegate::readEcuInfo(Ecu *param_1)

{
  bool bVar1;
  int iVar2;
  int *in_r1;
  int *piVar3;
  undefined4 in_r2;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_84;
  undefined4 local_7c;
  undefined4 local_78;
  int *local_64;
  int *local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  int local_50;
  int iStack_4c;
  Result<VagEcuInfo,void> aRStack_48 [28];
  int *local_2c;
  int local_24;
  
  local_24 = __stack_chk_guard;
  (**(code **)(*in_r1 + 0x194))(aRStack_48,in_r1,in_r2,0,0x365);
  iVar2 = Result<VagEcuInfo,void>::isFail(aRStack_48);
  if (iVar2 == 0) {
    local_50 = *local_2c;
    iStack_4c = local_2c[1];
    if (iStack_4c != 0) {
      piVar3 = (int *)(iStack_4c + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    local_58 = 0;
    uStack_54 = 0;
    if ((*(uint *)(local_50 + 0x20) < 4) && (*(uint *)(local_50 + 0x20) != 1)) {
      (**(code **)(*in_r1 + 0x144))();
      (**(code **)(*in_r1 + 0xec))(&local_7c);
      if (*local_64 == 1) {
        FUN_00cdf124(&local_a0,*local_60 + 4);
      }
      else {
        local_a0 = 0;
        uStack_9c = 0;
      }
      FUN_00d089cc(&local_58,&local_a0);
      FUN_00cbd77c(&local_a0);
      (**(code **)(*in_r1 + 0x1f8))(&local_a0);
      FUN_0126f4bc(&local_50,local_84);
      Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_a0);
      Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_7c);
    }
    local_a4 = 0;
    local_ac = 0;
    uStack_a8 = 0;
    FUN_0126f514(&local_a0,local_50 + 4,local_50 + 8,&local_a4,&uStack_a8,local_50 + 0x20,&local_58,
                 local_50 + 0x24,local_50 + 0x2c,local_50 + 0x34,local_50 + 0x3c,local_50 + 0x44,
                 &local_ac,local_50 + 0x54,local_50 + 0x5c);
    local_7c = local_a0;
    local_78 = uStack_9c;
    local_a0 = 0;
    uStack_9c = 0;
    Result<EcuInfo,void>::done((Result<EcuInfo,void> *)param_1,(shared_ptr *)&local_7c);
    FUN_00ccba0c(&local_7c);
    FUN_00d08630(&local_a0);
    FUN_00cbd77c(&local_58);
    FUN_00d08540(&local_50);
  }
  else {
    Result<VagEcuInfo,void>::stateAs<EcuInfo,void>();
  }
  Result<VagEcuInfo,void>::~Result(aRStack_48);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


