/* VagUdsAdaptationSetting::VagUdsAdaptationSetting @ 0118a0ac */


/* VagUdsAdaptationSetting::VagUdsAdaptationSetting(VagUdsEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned short, int, unsigned char, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, Setting::Consistency, VagSetting::AvailBy) */

void __thiscall
VagUdsAdaptationSetting::VagUdsAdaptationSetting
          (VagUdsAdaptationSetting *this,undefined4 param_1,undefined4 param_2,undefined4 param_4_00
          ,undefined4 param_4,undefined1 param_5,undefined4 param_6,undefined4 param_7,
          undefined4 param_8,undefined4 param_10,undefined4 param_11)

{
  undefined4 uVar1;
  undefined1 auStack_2c [15];
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1d = param_5;
  uVar1 = FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,7,param_1,param_4_00,param_4,uVar1,param_6,param_7,param_8,
             param_10,param_11);
  FUN_00cb7f50(auStack_2c);
  *(undefined ***)this = &PTR__WhitelistBasedSetting_014b5630;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


