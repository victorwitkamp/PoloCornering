/* Target address 0105f484 */
/* Function VagCanLongCodingSetting @ 0105f484 */


/* VagCanLongCodingSetting::VagCanLongCodingSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&) */

void __thiscall
VagCanLongCodingSetting::VagCanLongCodingSetting
          (VagCanLongCodingSetting *this,VagCanEcu *param_1,shared_ptr *param_2,int param_3,
          vector *param_4,char *param_5,shared_ptr *param_6)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagCanCodingSetting::VagCanCodingSetting
            ((VagCanCodingSetting *)this,param_2,3,param_1,0,param_3,param_4,param_5,param_6,
             &local_1c,1);
  FUN_00d4dec4(&local_1c);
  *(undefined ***)this = &PTR__VagCanLongCodingSetting_014b4d14;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


