/* VagOperationDelegate::updateEcuInfo @ 01276a64 */


/* VagOperationDelegate::updateEcuInfo(Ecu*, Result<VagEcuInfo, void> const&) */

void __thiscall
VagOperationDelegate::updateEcuInfo(VagOperationDelegate *this,Ecu *param_1,Result *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  Result<VagEcuInfo,void> *this_00;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_58;
  undefined1 auStack_57 [7];
  undefined1 *local_50;
  Result<VagEcuInfo,void> aRStack_4c [24];
  int *local_34;
  Ecu *local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_28 = param_1;
  iVar3 = Result<VagEcuInfo,void>::isFatalFail((Result<VagEcuInfo,void> *)param_2);
  if (iVar3 == 0) {
    bVar2 = **(int **)(param_2 + 0x18) == 0;
  }
  else {
    bVar2 = true;
  }
  (**(code **)(*(int *)this + 0x1f8))(aRStack_4c,this,param_1);
  iVar3 = Result<VagEcuInfo,void>::isVehicleResponse(aRStack_4c);
  if (iVar3 == 0) {
    bVar1 = *local_34 == -5;
  }
  else {
    bVar1 = true;
  }
  if (**(int **)(param_2 + 0x18) == 1 || !bVar1 && !bVar2) {
    (**(code **)(*(int *)param_1 + 0x10))(&local_58,param_1);
    if (((byte)local_58 & 1) == 0) {
      local_50 = auStack_57;
    }
    Log::d("updateEcuInfo for %s from %d to %d",local_50,*local_34,**(undefined4 **)(param_2 + 0x18)
          );
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(&local_58);
    this_00 = (Result<VagEcuInfo,void> *)FUN_01276b54(this + 300,&local_28);
    Result<VagEcuInfo,void>::operator=(this_00,param_2);
  }
  Result<VagEcuInfo,void>::~Result(aRStack_4c);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


