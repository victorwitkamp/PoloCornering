/* BmwIBatteryRegOperation::BmwIBatteryRegOperation @ 01292668 */


/* BmwIBatteryRegOperation::BmwIBatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwIBatteryRegOperation::BmwIBatteryRegOperation
          (BmwIBatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3
          )

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           BatteryRegOperation::BatteryRegOperation
                     ((BatteryRegOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__BmwIBatteryRegOperation_014bbc0c;
  return;
}


