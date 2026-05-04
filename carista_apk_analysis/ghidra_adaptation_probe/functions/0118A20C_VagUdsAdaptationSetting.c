/* VagUdsAdaptationSetting::VagUdsAdaptationSetting @ 0118a20c */


/* VagUdsAdaptationSetting::VagUdsAdaptationSetting(VagUdsEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned short, int,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&, Setting::Consistency, VagSetting::AvailBy) */

void __thiscall
VagUdsAdaptationSetting::VagUdsAdaptationSetting
          (VagUdsAdaptationSetting *this,undefined4 param_1,undefined4 param_2,undefined4 param_4_00
          ,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,
          undefined4 param_9,undefined4 param_10)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,7,param_1,param_4_00,param_4,param_5,param_6,param_7,
             &local_1c,param_9,param_10);
  FUN_00d4dec4(&local_1c);
  *(undefined ***)this = &PTR__WhitelistBasedSetting_014b5630;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


