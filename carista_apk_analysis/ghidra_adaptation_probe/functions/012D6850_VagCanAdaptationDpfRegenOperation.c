/* VagCanAdaptationDpfRegenOperation::VagCanAdaptationDpfRegenOperation @ 012d6850 */


/* VagCanAdaptationDpfRegenOperation::VagCanAdaptationDpfRegenOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagCanAdaptationDpfRegenOperation::VagCanAdaptationDpfRegenOperation
          (VagCanAdaptationDpfRegenOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           VagCanDpfRegenOperation::VagCanDpfRegenOperation
                     ((VagCanDpfRegenOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__VagCanAdaptationDpfRegenOperation_014bef10;
  return;
}


