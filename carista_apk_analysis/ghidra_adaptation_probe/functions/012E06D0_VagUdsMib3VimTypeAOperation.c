/* VagUdsMib3VimTypeAOperation::VagUdsMib3VimTypeAOperation @ 012e06d0 */


/* VagUdsMib3VimTypeAOperation::VagUdsMib3VimTypeAOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagUdsMib3VimTypeAOperation::VagUdsMib3VimTypeAOperation
          (VagUdsMib3VimTypeAOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           VagUdsMib3VimOperation::VagUdsMib3VimOperation
                     ((VagUdsMib3VimOperation *)this,param_1,param_2,param_3,
                      (vector *)DATA_SET_VALUE,(vector *)PROGRAMMING_RAW_PAYLOAD_PREFIX,
                      (vector *)PROGRAMMING_RAW_PAYLOAD_SUFFIX);
  *puVar1 = &PTR__VagUdsMib3VimTypeAOperation_014bfb9c;
  return;
}


