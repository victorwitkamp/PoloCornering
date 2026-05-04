/* VagOperationDelegate::validateVagCanEcuInfo @ 01277194 */


/* VagOperationDelegate::validateVagCanEcuInfo(Ecu*, Result<VagEcuInfo, void> const&) */

void __thiscall
VagOperationDelegate::validateVagCanEcuInfo(VagOperationDelegate *this,Ecu *param_1,Result *param_2)

{
  bool bVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *local_48;
  int iStack_44;
  int *local_40;
  int iStack_3c;
  Result<VagEcuInfo,void> aRStack_38 [24];
  int *local_20;
  int *local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x1f8))(aRStack_38,this,param_1);
  if (*local_20 != 1) goto LAB_01277262;
  local_40 = *(int **)(*local_1c + 0x10);
  iStack_3c = *(int *)(*local_1c + 0x14);
  if (iStack_3c != 0) {
    piVar3 = (int *)(iStack_3c + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  local_48 = *(int **)(**(int **)(param_2 + 0x1c) + 0x10);
  iStack_44 = *(int *)(**(int **)(param_2 + 0x1c) + 0x14);
  if (iStack_44 != 0) {
    piVar3 = (int *)(iStack_44 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  if (local_40 != (int *)0x0) {
    if (local_48 == (int *)0x0) {
      pcVar2 = "The VAG CAN submodules are null, whereas cached ones are non-null";
    }
    else {
      iVar4 = *local_40;
      iVar5 = local_40[1];
      if (iVar5 - iVar4 == local_48[1] - *local_48) {
        for (uVar6 = 0; uVar6 < (uint)(iVar5 - iVar4 >> 3); uVar6 = uVar6 + 1) {
          piVar3 = (int *)FUN_0111cba4(local_40,uVar6);
          uVar7 = *(undefined4 *)(*piVar3 + 8);
          piVar3 = (int *)FUN_0111cba4(local_48,uVar6);
          iVar4 = FUN_00cfa744(uVar7,*(undefined4 *)(*piVar3 + 8));
          if (iVar4 != 0) {
            Log::e("Mismatch in VAG CAN submodule part no at position %zu",uVar6);
            break;
          }
          iVar4 = *local_40;
          iVar5 = local_40[1];
        }
        goto LAB_01277256;
      }
      pcVar2 = "The VAG CAN number of submodules does not match the cached ones";
    }
    Log::e(pcVar2);
  }
LAB_01277256:
  FUN_00d08642(&local_48);
  FUN_00d08642(&local_40);
LAB_01277262:
  Result<VagEcuInfo,void>::~Result(aRStack_38);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


