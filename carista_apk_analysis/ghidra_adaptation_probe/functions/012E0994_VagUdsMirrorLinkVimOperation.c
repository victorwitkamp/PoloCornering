/* VagUdsMirrorLinkVimOperation::VagUdsMirrorLinkVimOperation @ 012e0994 */


/* VagUdsMirrorLinkVimOperation::VagUdsMirrorLinkVimOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagUdsMirrorLinkVimOperation::VagUdsMirrorLinkVimOperation
          (VagUdsMirrorLinkVimOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_012e0a30(&local_2c);
  local_24 = local_2c;
  local_20 = uStack_28;
  local_2c = 0;
  uStack_28 = 0;
  VagUdsMib2VimOperation::VagUdsMib2VimOperation
            ((VagUdsMib2VimOperation *)this,param_1,param_2,param_3,(shared_ptr *)&local_24,
             (LibStr *)&LibStr::enable_mirrorlink_motion_disclaimer_msg);
  FUN_012debe8(&local_24);
  FUN_011d7008(&local_2c);
  *(undefined ***)this = &PTR__VagUdsMirrorLinkVimOperation_014bfd04;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


