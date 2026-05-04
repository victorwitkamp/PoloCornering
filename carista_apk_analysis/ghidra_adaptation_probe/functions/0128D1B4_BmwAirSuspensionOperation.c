/* BmwAirSuspensionOperation::BmwAirSuspensionOperation @ 0128d1b4 */


/* BmwAirSuspensionOperation::BmwAirSuspensionOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
BmwAirSuspensionOperation::BmwAirSuspensionOperation
          (BmwAirSuspensionOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           GenericToolActionOperation::GenericToolActionOperation
                     ((GenericToolActionOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__BmwAirSuspensionOperation_014bb40c;
  *(undefined8 *)(puVar1 + 0x4f) = 0;
  *(undefined8 *)(puVar1 + 0x51) = 0;
  puVar1[0x53] = 0;
  return;
}


