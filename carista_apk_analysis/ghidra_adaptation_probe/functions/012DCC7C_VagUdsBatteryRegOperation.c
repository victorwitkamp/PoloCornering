/* VagUdsBatteryRegOperation::VagUdsBatteryRegOperation @ 012dcc7c */


/* VagUdsBatteryRegOperation::VagUdsBatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagUdsBatteryRegOperation::VagUdsBatteryRegOperation
          (VagUdsBatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           VagBatteryRegOperation::VagBatteryRegOperation
                     ((VagBatteryRegOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__VagUdsBatteryRegOperation_014bf7dc;
  return;
}


