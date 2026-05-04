/* VagOperationDelegate::isConnectedTo @ 01276920 */


/* VagOperationDelegate::isConnectedTo(Ecu*) */

void __thiscall VagOperationDelegate::isConnectedTo(VagOperationDelegate *this,Ecu *param_1)

{
  Result<VagEcuInfo,void> aRStack_38 [36];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x1f8))(aRStack_38,this,param_1);
  Result<VagEcuInfo,void>::isVehicleResponse(aRStack_38);
  Result<VagEcuInfo,void>::~Result(aRStack_38);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


