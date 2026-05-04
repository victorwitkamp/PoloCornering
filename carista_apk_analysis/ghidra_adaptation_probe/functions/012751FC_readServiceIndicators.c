/* VagOperationDelegate::readServiceIndicators @ 012751fc */


/* VagOperationDelegate::readServiceIndicators(Ecu*) */

undefined8 VagOperationDelegate::readServiceIndicators(Ecu *param_1)

{
  IllegalArgumentException *this;
  undefined4 in_r1;
  int in_r2;
  Ecu *pEStack_20;
  undefined4 uStack_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  pEStack_20 = param_1;
  uStack_1c = in_r1;
  if (VagCanEcu::INSTRUMENT_CLUSTER == in_r2) {
    readCanServiceIndicators();
    if (__stack_chk_guard == local_14) {
      return CONCAT44(uStack_1c,pEStack_20);
    }
  }
  else {
    if (VagUdsEcu::INSTRUMENT_CLUSTER != in_r2) {
      this = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44((basic_string *)&pEStack_20,"Unexpected ECU passed to readServiceIndicators()");
      IllegalArgumentException::IllegalArgumentException(this,(basic_string *)&pEStack_20);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    readUdsServiceIndicators();
    if (__stack_chk_guard == local_14) {
      return CONCAT44(uStack_1c,pEStack_20);
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


