/* VagOperationDelegate::getEcuById @ 012721ec */


/* VagOperationDelegate::getEcuById(unsigned short) */

void VagOperationDelegate::getEcuById(ushort param_1)

{
  int iVar1;
  IllegalArgumentException *this;
  ushort in_r1;
  uint auStack_20 [3];
  int local_14;
  
  auStack_20[0] = (uint)param_1;
  local_14 = __stack_chk_guard;
  iVar1 = VagEcu::getByVagId(in_r1);
  if (iVar1 == 0) {
    this = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44((basic_string *)auStack_20,
                 "VagOperationDelegate::getEcuById must be called with a VagEcu id!");
    IllegalArgumentException::IllegalArgumentException(this,(basic_string *)auStack_20);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


