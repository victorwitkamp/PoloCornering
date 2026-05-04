/* FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting @ 01056a88 */


/* FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned char, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&, Setting::Consistency) */

void __thiscall
FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting
          (FullByteVagCanShortAdaptationSetting *this,undefined4 param_1,undefined4 param_2,
          undefined4 param_4_00,undefined4 param_4,undefined4 param_5,undefined4 param_7)

{
  undefined4 uVar1;
  undefined1 auStack_2c [14];
  undefined2 uStack_1e;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1e = 0xffff;
  uVar1 = FUN_00cdb87c(auStack_2c,&uStack_1e,2);
  VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
            ((VagCanShortAdaptationSetting *)this,param_1,param_2,param_4_00,0,uVar1,param_4,param_5
             ,param_7);
  FUN_00cb7f50(auStack_2c);
  *(undefined ***)this = &PTR__FullByteVagCanShortAdaptationSetting_014b489c;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


