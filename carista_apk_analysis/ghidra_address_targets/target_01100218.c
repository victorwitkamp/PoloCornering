/* Target address 01100218 */
/* Function VagCanShortAdaptationSetting @ 01100218 */


/* VagCanShortAdaptationSetting::VagCanShortAdaptationSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned char, int, int, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&) */

void __thiscall
VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
          (VagCanShortAdaptationSetting *this,VagCanEcu *param_1,shared_ptr *param_2,uchar param_3,
          int param_4,int param_5,char *param_6,shared_ptr *param_7)

{
  undefined4 uVar1;
  IllegalArgumentException *pIVar2;
  undefined4 local_44;
  undefined4 uStack_40;
  basic_string abStack_38 [15];
  undefined1 uStack_29;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uStack_29 = generateBitmask(param_4,param_5);
  uVar1 = FUN_00cdb87c(abStack_38,&uStack_29,1);
  local_44 = 0;
  uStack_40 = 0;
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,0,param_1,param_3,
             1 - ((int)(param_4 + ((uint)(param_4 >> 0x1f) >> 0x1d)) >> 3),uVar1,param_6,param_7,
             &local_44,1,2);
  FUN_00d4dec4(&local_44);
  FUN_00cb7f50(abStack_38);
  *(undefined ***)this = &PTR__VagCanShortAdaptationSetting_014b4f9c;
  if ((param_4 < 0) || (0xf < (uint)param_4)) {
    pIVar2 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    std::__ndk1::to_string((__ndk1 *)&local_44,param_4);
    FUN_00cbe7e4(abStack_38,"Invalid start bit: ",&local_44);
    IllegalArgumentException::IllegalArgumentException(pIVar2,abStack_38);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar2,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (8 < (int)((param_4 & 7U) + param_5)) {
    pIVar2 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    std::__ndk1::to_string((__ndk1 *)&local_44,param_5);
    FUN_00cbe7e4(abStack_38,"Invalid numBits: ",&local_44);
    IllegalArgumentException::IllegalArgumentException(pIVar2,abStack_38);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar2,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


