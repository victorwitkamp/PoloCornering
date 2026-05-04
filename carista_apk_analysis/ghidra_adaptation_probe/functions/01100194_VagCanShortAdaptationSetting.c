/* VagCanShortAdaptationSetting::VagCanShortAdaptationSetting @ 01100194 */


/* VagCanShortAdaptationSetting::VagCanShortAdaptationSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned char, int, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&, Setting::Consistency) */

void __thiscall
VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
          (VagCanShortAdaptationSetting *this,undefined4 param_1,undefined4 param_2,
          undefined4 param_4_00,undefined4 param_4,undefined4 param_5,undefined4 param_6,
          undefined4 param_7,undefined4 param_9)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,0,param_1,param_4_00,param_4,param_5,param_6,param_7,
             &local_1c,param_9,2);
  FUN_00d4dec4(&local_1c);
  *(undefined ***)this = &PTR__VagCanShortAdaptationSetting_014b4f9c;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


