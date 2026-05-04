/* VagOperationDelegate::readVagCanEcuInfo @ 01276e30 */


/* VagOperationDelegate::readVagCanEcuInfo(VagCanEcu*) */

void VagOperationDelegate::readVagCanEcuInfo(VagCanEcu *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  IllegalStateException *this;
  VagOperationDelegate *in_r1;
  int iVar4;
  Ecu *in_r2;
  uint uVar5;
  int local_84;
  int local_80;
  Progress aPStack_60 [8];
  int local_58;
  int iStack_54;
  shared_ptr asStack_50 [24];
  int *local_38;
  int *local_34;
  Ecu *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_2c = in_r2;
  FUN_0127713c(&local_58,&local_2c);
  local_84 = local_58;
  local_80 = iStack_54;
  local_58 = 0;
  iStack_54 = 0;
  Progress::NUL(aPStack_60);
  OperationDelegate::runCommand<VagEcuInfoWithCoding>(asStack_50,(shared_ptr *)in_r1);
  FUN_011e01a0(aPStack_60);
  FUN_01277170(&local_84);
  FUN_01277182(&local_58);
  iVar2 = Result<VagEcuInfoWithCoding,void>::isFail((Result<VagEcuInfoWithCoding,void> *)asStack_50)
  ;
  if (iVar2 == 0) {
    iVar2 = *local_38;
    local_58 = *local_34;
    iStack_54 = local_34[1];
    if (iStack_54 != 0) {
      piVar3 = (int *)(iStack_54 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    Result<VagEcuInfo,void>::Result
              ((Result<VagEcuInfo,void> *)&local_84,iVar2,(shared_ptr *)&local_58);
    iVar2 = validateVagCanEcuInfo(in_r1,local_2c,(Result *)&local_84);
    Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_84);
    FUN_00d08540(&local_58);
    if (iVar2 == 0) {
      Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,-6);
      goto LAB_01276fe6;
    }
    if (*(int *)(*local_34 + 0x20) == 2) {
      (**(code **)(*(int *)in_r1 + 0x17c))();
      (**(code **)(*(int *)in_r1 + 0xb0))();
    }
    (**(code **)(*(int *)in_r1 + 0x17c))();
    iVar2 = *local_34;
    piVar3 = *(int **)(iVar2 + 0x10);
    if (piVar3 == (int *)0x0) {
      this = (IllegalStateException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(&local_84,"VAG CAN ECU info should always contain submodules");
      IllegalStateException::IllegalStateException(this,(basic_string *)&local_84);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this,&IllegalStateException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    uVar5 = 0;
    while (uVar5 < (uint)(piVar3[1] - *piVar3 >> 3)) {
      piVar3 = (int *)FUN_0111cba4(piVar3,uVar5);
      local_84 = *piVar3;
      local_80 = piVar3[1];
      if (local_80 != 0) {
        piVar3 = (int *)(local_80 + 4);
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = *piVar3 + 1;
      }
      uVar5 = uVar5 + 1;
      Math::toExact<unsigned_char,unsigned_int>(uVar5);
      (**(code **)(*(int *)in_r1 + 0xb0))();
      FUN_00d08630(&local_84);
      iVar2 = *local_34;
      piVar3 = *(int **)(iVar2 + 0x10);
    }
    iVar4 = *local_38;
    local_80 = local_34[1];
    local_84 = iVar2;
    if (local_80 != 0) {
      piVar3 = (int *)(local_80 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
  }
  else {
    iVar4 = *local_38;
    local_84 = *local_34;
    local_80 = local_34[1];
    if (local_80 != 0) {
      piVar3 = (int *)(local_80 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
  }
  Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,iVar4,(shared_ptr *)&local_84);
  FUN_00d08540((shared_ptr *)&local_84);
LAB_01276fe6:
  Result<VagEcuInfoWithCoding,void>::~Result((Result<VagEcuInfoWithCoding,void> *)asStack_50);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


