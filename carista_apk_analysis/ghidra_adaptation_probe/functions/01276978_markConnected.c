/* VagOperationDelegate::markConnected @ 01276978 */


/* VagOperationDelegate::markConnected(Ecu*, int) */

void __thiscall
VagOperationDelegate::markConnected(VagOperationDelegate *this,Ecu *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_48;
  int iStack_44;
  Result<VagEcuInfo,void> aRStack_40 [36];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (param_2 == 1) {
    local_48 = (undefined4)VagEcuInfo::EMPTY;
    iStack_44 = VagEcuInfo::EMPTY._4_4_;
    if (VagEcuInfo::EMPTY._4_4_ != 0) {
      piVar2 = (int *)(VagEcuInfo::EMPTY._4_4_ + 4);
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = *piVar2 + 1;
    }
  }
  else {
    local_48 = 0;
    iStack_44 = 0;
  }
  Result<VagEcuInfo,void>::Result(aRStack_40,param_2,(shared_ptr *)&local_48);
  (**(code **)(*(int *)this + 0x18c))(this,param_1,aRStack_40);
  Result<VagEcuInfo,void>::~Result(aRStack_40);
  FUN_00d08540(&local_48);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


