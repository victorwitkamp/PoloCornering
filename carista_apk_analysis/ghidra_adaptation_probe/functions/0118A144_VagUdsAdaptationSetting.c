/* VagUdsAdaptationSetting::VagUdsAdaptationSetting @ 0118a144 */


/* VagUdsAdaptationSetting::VagUdsAdaptationSetting(VagUdsEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned short, int,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, Setting::Consistency, VagSetting::AvailBy) */

void __thiscall
VagUdsAdaptationSetting::VagUdsAdaptationSetting
          (VagUdsAdaptationSetting *this,undefined4 param_1,undefined4 param_2,undefined4 param_4_00
          ,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,
          undefined4 param_8,undefined4 param_10,undefined4 param_11)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           VagSetting::VagSetting
                     ((VagSetting *)this,param_2,7,param_1,param_4_00,param_4,param_5,param_6,
                      param_7,param_8,param_10,param_11);
  *puVar1 = &PTR__WhitelistBasedSetting_014b5630;
  return;
}


