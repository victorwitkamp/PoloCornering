/* BatteryRegOperation::BatteryRegOperation @ 0128b330 */


/* BatteryRegOperation::BatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
BatteryRegOperation::BatteryRegOperation
          (BatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           GenericToolOperation::GenericToolOperation
                     ((GenericToolOperation *)this,param_1,param_2,param_3);
  puVar1[0x47] = 0;
  *(undefined8 *)(puVar1 + 0x48) = 0;
  *(undefined8 *)(puVar1 + 0x4a) = 0;
  puVar1[0x45] = puVar1 + 0x46;
  puVar1[0x46] = 0;
  *puVar1 = &PTR__BatteryRegOperation_014bb1bc;
  return;
}


