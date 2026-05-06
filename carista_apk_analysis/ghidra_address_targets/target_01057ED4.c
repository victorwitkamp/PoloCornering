/* Target address 01057ed4 */
/* Function VagBasicSettingTool @ 01057ed4 */


/* VagBasicSettingTool::VagBasicSettingTool(char const*, Ecu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, char const*, std::__ndk1::shared_ptr<LibStr>
   const&, std::__ndk1::shared_ptr<LibStr> const&,
   std::__ndk1::vector<std::__ndk1::shared_ptr<GenericToolAction>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<GenericToolAction> > > const&,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > const&,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > const&,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > const&, VagSetting::AvailBy) */

void __thiscall
VagBasicSettingTool::VagBasicSettingTool
          (VagBasicSettingTool *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_stack_0000001c;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_28 = __stack_chk_guard;
  local_2c = 0;
  local_34 = 0;
  uStack_30 = 0;
  local_3c = 0;
  uStack_38 = 0;
  local_44 = 0;
  uStack_40 = 0;
  VagSetting::VagSetting
            ((VagSetting *)this,param_3,10,param_2,0,0,&local_34,param_1,&local_3c,&local_44,1,
             in_stack_0000001c);
  FUN_00d4dec4(&local_44);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_3c);
}


