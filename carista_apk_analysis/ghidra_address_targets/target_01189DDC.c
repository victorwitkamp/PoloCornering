/* Target address 01189ddc */
/* Function FullByteVagUdsAdaptationSetting @ 01189ddc */


/* FullByteVagUdsAdaptationSetting::FullByteVagUdsAdaptationSetting(VagUdsEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned short, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&, VagSetting::AvailBy) */

void __thiscall
FullByteVagUdsAdaptationSetting::FullByteVagUdsAdaptationSetting
          (FullByteVagUdsAdaptationSetting *this,undefined4 param_1,undefined4 param_2,
          undefined4 param_4_00,undefined4 param_4,undefined4 param_5,undefined4 param_7)

{
  undefined4 uVar1;
  undefined1 auStack_2c [15];
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1d = 0xff;
  uVar1 = FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            ((VagUdsAdaptationSetting *)this,param_1,param_2,param_4_00,0,uVar1,param_4,param_5,
             param_7);
  FUN_00cb7f50(auStack_2c);
  *(undefined ***)this = &PTR__WhitelistBasedSetting_014b55d8;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


