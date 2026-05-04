/* OperationDelegate::readTpmsInfo @ 01241998 */


/* OperationDelegate::readTpmsInfo(std::__ndk1::shared_ptr<Progress> const&, Ecu*) */

void __thiscall
OperationDelegate::readTpmsInfo(OperationDelegate *this,shared_ptr *param_1,Ecu *param_2)

{
  UnsupportedOperationException *this_00;
  OperationDelegate *pOStack_20;
  shared_ptr *psStack_1c;
  Ecu *pEStack_18;
  undefined4 local_14;
  
  local_14 = __stack_chk_guard;
  pOStack_20 = this;
  psStack_1c = param_1;
  pEStack_18 = param_2;
  this_00 = (UnsupportedOperationException *)__cxa_allocate_exception(8);
  FUN_00cb4d44((basic_string *)&pOStack_20,"not implemented");
  UnsupportedOperationException::UnsupportedOperationException(this_00,(basic_string *)&pOStack_20);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this_00,&UnsupportedOperationException::typeinfo,
              IllegalStateException::~IllegalStateException);
}


