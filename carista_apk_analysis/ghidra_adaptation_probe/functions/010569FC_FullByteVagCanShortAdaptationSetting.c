/* FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting @ 010569fc */


/* FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned char, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&) */

void __thiscall
FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting
          (FullByteVagCanShortAdaptationSetting *this,VagCanEcu *param_1,shared_ptr *param_2,
          uchar param_3,char *param_4,shared_ptr *param_5)

{
  vector *pvVar1;
  undefined1 auStack_2c [14];
  undefined2 uStack_1e;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1e = 0xffff;
  pvVar1 = (vector *)FUN_00cdb87c(auStack_2c,&uStack_1e,2);
  VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
            ((VagCanShortAdaptationSetting *)this,param_1,param_2,param_3,0,pvVar1,param_4,param_5);
  FUN_00cb7f50(auStack_2c);
  *(undefined ***)this = &PTR__FullByteVagCanShortAdaptationSetting_014b489c;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


