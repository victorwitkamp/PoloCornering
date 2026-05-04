/* VagCanShortAdaptationSetting::VagCanShortAdaptationSetting @ 01100074 */


/* VagCanShortAdaptationSetting::VagCanShortAdaptationSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned char, int, unsigned char, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&) */

void __thiscall
VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
          (VagCanShortAdaptationSetting *this,VagCanEcu *param_1,shared_ptr *param_2,uchar param_3,
          int param_4,uchar param_5,char *param_6,shared_ptr *param_7,shared_ptr *param_8)

{
  undefined4 uVar1;
  undefined1 auStack_34 [15];
  uchar uStack_25;
  int local_24;
  
  local_24 = __stack_chk_guard;
  uStack_25 = param_5;
  uVar1 = FUN_00cdb87c(auStack_34,&uStack_25,1);
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,0,param_1,param_3,param_4,uVar1,param_6,param_7,param_8,1,2)
  ;
  FUN_00cb7f50(auStack_34);
  *(undefined ***)this = &PTR__VagCanShortAdaptationSetting_014b4f9c;
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_24);
  }
  return;
}


