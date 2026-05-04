/* VagOperationDelegate::getConnectedEcuTag @ 0126b90c */


/* VagOperationDelegate::getConnectedEcuTag(std::__ndk1::shared_ptr<Setting> const&) */

void VagOperationDelegate::getConnectedEcuTag(shared_ptr *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_r1;
  undefined4 *in_r2;
  int *piVar5;
  Result<VagEcuInfo,void> aRStack_48 [24];
  int *local_30;
  int *local_2c;
  int *local_24;
  int local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  piVar5 = (int *)*in_r2;
  if (piVar5[4] == 0) {
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    local_20 = in_r2[1];
    if (local_20 != 0) {
      piVar2 = (int *)(local_20 + 4);
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = *piVar2 + 1;
    }
    local_24 = piVar5;
    iVar3 = (**(code **)(*piVar5 + 0x3c))(piVar5);
    if (iVar3 == 0) {
      (**(code **)(*in_r1 + 0x18))(param_1);
    }
    else {
      (**(code **)(*in_r1 + 0x1f8))(aRStack_48);
      if ((*local_30 == 1) &&
         (puVar4 = *(undefined4 **)(*local_2c + 0x10), puVar4 != (undefined4 *)0x0)) {
        piVar2 = (int *)puVar4[1];
        for (piVar5 = (int *)*puVar4; piVar5 != piVar2; piVar5 = piVar5 + 2) {
          if (((*piVar5 != 0) && (*(int *)(*piVar5 + 8) != 0)) &&
             (iVar3 = (**(code **)(*(int *)local_24[0x15] + 0x10))(), iVar3 != 0)) {
            iVar3 = *(int *)(*piVar5 + 0xc);
            *(undefined4 *)param_1 = *(undefined4 *)(*piVar5 + 8);
            *(int *)(param_1 + 4) = iVar3;
            if (iVar3 != 0) {
              piVar5 = (int *)(iVar3 + 4);
              do {
                ExclusiveAccess(piVar5);
                bVar1 = (bool)hasExclusiveAccess(piVar5);
              } while (!bVar1);
              *piVar5 = *piVar5 + 1;
            }
            goto LAB_0126b9aa;
          }
        }
      }
      *(undefined4 *)param_1 = 0;
      *(undefined4 *)(param_1 + 4) = 0;
LAB_0126b9aa:
      Result<VagEcuInfo,void>::~Result(aRStack_48);
    }
    FUN_00d1756c(&local_24);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


