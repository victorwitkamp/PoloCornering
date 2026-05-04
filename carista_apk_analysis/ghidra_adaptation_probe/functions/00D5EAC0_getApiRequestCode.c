/* TroubleCode::getApiRequestCode @ 00d5eac0 */


/* TroubleCode::getApiRequestCode() const */

void TroubleCode::getApiRequestCode(void)

{
  IllegalArgumentException *this;
  basic_string abStack_20 [12];
  undefined4 local_14;
  
  local_14 = __stack_chk_guard;
  this = (IllegalArgumentException *)__cxa_allocate_exception(8);
  FUN_00cb4d44(abStack_20,"Not implemented");
  IllegalArgumentException::IllegalArgumentException(this,abStack_20);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this,&IllegalArgumentException::typeinfo,IllegalStateException::~IllegalStateException
             );
}


