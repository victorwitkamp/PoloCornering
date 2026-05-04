/* VagOperationDelegate::VagOperationDelegate @ 0126af10 */


/* VagOperationDelegate::VagOperationDelegate(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<State::OnStateUpdateListener> const&) */

void __thiscall
VagOperationDelegate::VagOperationDelegate
          (VagOperationDelegate *this,shared_ptr *param_1,shared_ptr *param_2)

{
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  OperationDelegate::OperationDelegate((OperationDelegate *)this,param_1,param_2);
  *(undefined ***)this = &PTR__VagOperationDelegate_014ba634;
  local_3c = VagCanEcu::ENGINE;
  local_38 = VagCanEcu::HVAC;
  local_34 = VagCanEcu::IMMOBILIZER;
  local_30 = VagCanEcu::STEERING_ASSIST;
  local_2c = VagUdsEcu::ENGINE;
  local_28 = VagUdsEcu::ENGINE_29_BIT;
  local_24 = VagUdsEcu::CAN_GATEWAY;
  local_20 = VagUdsEcu::INSTRUMENT_CLUSTER;
  FUN_00db6cfc(this + 0xfc,&local_3c,8);
  local_3c = 0;
  local_38 = 0;
  Result<EcuList_const,void>::Result
            ((Result<EcuList_const,void> *)(this + 0x108),0,(shared_ptr *)&local_3c);
  FUN_011e0474(&local_3c);
  *(undefined2 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 300) = 0;
  *(undefined8 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x13c) = 0x3f800000;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


