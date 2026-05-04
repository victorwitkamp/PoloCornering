/* VagOperationDelegate::settingTypeAppliesToEcuType @ 01270670 */


/* VagOperationDelegate::settingTypeAppliesToEcuType(std::__ndk1::shared_ptr<Setting> const&,
   std::__ndk1::shared_ptr<VagEcuInfo> const&) */

void __thiscall
VagOperationDelegate::settingTypeAppliesToEcuType
          (VagOperationDelegate *this,shared_ptr *param_1,shared_ptr *param_2)

{
  bool bVar1;
  int iVar2;
  int local_2c [2];
  int local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_01278784(local_24);
  iVar2 = local_24[0];
  FUN_0105f654(local_24);
  if (iVar2 == 0) {
    FUN_01278868(local_24,param_1);
    if (local_24[0] == 0) {
      FUN_012788b4(local_2c,param_1);
      FUN_010bc056(local_2c);
      FUN_010bc020(local_24);
      if (local_2c[0] == 0) goto LAB_01270734;
    }
    else {
      FUN_010bc020(local_24);
    }
    iVar2 = *(int *)(*(int *)param_2 + 4);
LAB_0127070e:
    iVar2 = iVar2 + -2;
LAB_01270710:
    bVar1 = iVar2 == 0;
  }
  else {
    if (*(int *)(*(int *)param_2 + 4) == 2) {
LAB_012706a4:
      bVar1 = false;
      goto LAB_01270736;
    }
    FUN_012787d0(local_24,param_1);
    iVar2 = local_24[0];
    FUN_010bc032(local_24);
    if (iVar2 == 0) {
      FUN_0127881c(local_24,param_1);
      FUN_010569e8(local_24);
      if (local_24[0] != 0) {
        iVar2 = *(int *)(*(int *)param_2 + 0x20);
        goto LAB_0127070e;
      }
    }
    else if (*(int *)(*(int *)param_2 + 0x20) != 3) {
      if (*(int *)(*(int *)param_1 + 0x10) != VagCanEcu::BATTERY_REGULATOR) goto LAB_012706a4;
      iVar2 = *(int *)(*(int *)param_2 + 0x20) + -1;
      goto LAB_01270710;
    }
LAB_01270734:
    bVar1 = true;
  }
LAB_01270736:
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}


