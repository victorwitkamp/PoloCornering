/* Target address 011003d0 */
/* Function VagCanShortAdaptationSetting @ 011003d0 */


/* VagCanShortAdaptationSetting::VagCanShortAdaptationSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned char, int, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&) */

void __thiscall
VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
          (VagCanShortAdaptationSetting *this,VagCanEcu *param_1,shared_ptr *param_2,uchar param_3,
          int param_4,vector *param_5,char *param_6,shared_ptr *param_7,shared_ptr *param_8)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           VagSetting::VagSetting
                     ((VagSetting *)this,param_2,0,param_1,param_3,param_4,param_5,param_6,param_7,
                      param_8,1,2);
  *puVar1 = &PTR__VagCanShortAdaptationSetting_014b4f9c;
  return;
}


