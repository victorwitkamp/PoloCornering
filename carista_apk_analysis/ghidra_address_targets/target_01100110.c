/* Target address 01100110 */
/* Function VagCanShortAdaptationSetting @ 01100110 */


/* VagCanShortAdaptationSetting::VagCanShortAdaptationSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned char, int, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&) */

void __thiscall
VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
          (VagCanShortAdaptationSetting *this,VagCanEcu *param_1,shared_ptr *param_2,uchar param_3,
          int param_4,vector *param_5,char *param_6,shared_ptr *param_7)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,0,param_1,param_3,param_4,param_5,param_6,param_7,&local_1c,
             1,2);
  FUN_00d4dec4(&local_1c);
  *(undefined ***)this = &PTR__VagCanShortAdaptationSetting_014b4f9c;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


