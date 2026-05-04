/* VagUdsAdaptationSetting::VagUdsAdaptationSetting @ 0118a010 */


/* VagUdsAdaptationSetting::VagUdsAdaptationSetting(VagUdsEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned short, int, unsigned char, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, VagSetting::AvailBy) */

void __thiscall
VagUdsAdaptationSetting::VagUdsAdaptationSetting
          (VagUdsAdaptationSetting *this,undefined4 param_1,undefined4 param_2,undefined4 param_4_00
          ,undefined4 param_4,undefined1 param_5,undefined4 param_6,undefined4 param_7,
          undefined4 param_8,undefined4 param_10)

{
  undefined4 uVar1;
  undefined1 auStack_34 [15];
  undefined1 uStack_25;
  int local_24;
  
  local_24 = __stack_chk_guard;
  uStack_25 = param_5;
  uVar1 = FUN_00cdb87c(auStack_34,&uStack_25,1);
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,7,param_1,param_4_00,param_4,uVar1,param_6,param_7,param_8,1
             ,param_10);
  FUN_00cb7f50(auStack_34);
  *(undefined ***)this = &PTR__WhitelistBasedSetting_014b5630;
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_24);
  }
  return;
}


