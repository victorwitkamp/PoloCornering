/* BmwEBatteryRegOperation::BmwEBatteryRegOperation @ 0128e024 */


/* BmwEBatteryRegOperation::BmwEBatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwEBatteryRegOperation::BmwEBatteryRegOperation
          (BmwEBatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3
          )

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           BatteryRegOperation::BatteryRegOperation
                     ((BatteryRegOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__BmwEBatteryRegOperation_014bb5a4;
  return;
}


