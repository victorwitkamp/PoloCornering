/* VagOperationDelegate::getConnectedEcuTag @ 0126b880 */


/* VagOperationDelegate::getConnectedEcuTag(Ecu*) */

void __thiscall VagOperationDelegate::getConnectedEcuTag(VagOperationDelegate *this,Ecu *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_40;
  int iStack_3c;
  Result<VagEcuInfo,void> aRStack_38 [24];
  int *local_20;
  int *local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0x1f8))(aRStack_38);
  if (*local_20 == 1) {
    local_40 = *(undefined4 *)(*local_1c + 8);
    iStack_3c = *(int *)(*local_1c + 0xc);
    if (iStack_3c != 0) {
      piVar2 = (int *)(iStack_3c + 4);
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = *piVar2 + 1;
      *(undefined4 *)this = local_40;
      *(int *)(this + 4) = iStack_3c;
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = *piVar2 + 1;
      goto LAB_0126b8e2;
    }
  }
  else {
    local_40 = 0;
    iStack_3c = 0;
  }
  *(undefined4 *)this = local_40;
  *(undefined4 *)(this + 4) = 0;
LAB_0126b8e2:
  FUN_00cbd6dc(&local_40);
  Result<VagEcuInfo,void>::~Result(aRStack_38);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


