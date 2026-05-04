/* BmwFBatteryRegOperation::BmwFBatteryRegOperation @ 0128fd88 */


/* BmwFBatteryRegOperation::BmwFBatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwFBatteryRegOperation::BmwFBatteryRegOperation
          (BmwFBatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3
          )

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           BatteryRegOperation::BatteryRegOperation
                     ((BatteryRegOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__BmwFBatteryRegOperation_014bb8d8;
  return;
}


