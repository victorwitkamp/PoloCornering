/* Target address 0105f500 */
/* Function VagCanLongCodingSetting @ 0105f500 */


/* VagCanLongCodingSetting::VagCanLongCodingSetting(VagCanEcu*,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int, unsigned char, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&) */

void __thiscall
VagCanLongCodingSetting::VagCanLongCodingSetting
          (VagCanLongCodingSetting *this,VagCanEcu *param_1,shared_ptr *param_2,int param_3,
          uchar param_4,char *param_5,shared_ptr *param_6)

{
  vector *pvVar1;
  undefined1 auStack_2c [15];
  uchar uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1d = param_4;
  pvVar1 = (vector *)FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  VagCanLongCodingSetting(this,param_1,param_2,param_3,pvVar1,param_5,param_6);
  FUN_00cb7f50(auStack_2c);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


