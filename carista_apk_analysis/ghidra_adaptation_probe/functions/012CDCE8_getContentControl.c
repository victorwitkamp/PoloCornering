/* ReadValuesOperation::getContentControl @ 012cdce8 */


/* ReadValuesOperation::getContentControl(bool) */

void ReadValuesOperation::getContentControl(bool param_1)

{
  IllegalStateException *this;
  uint auStack_20 [3];
  undefined4 local_14;
  
  auStack_20[0] = (uint)param_1;
  local_14 = __stack_chk_guard;
  this = (IllegalStateException *)__cxa_allocate_exception(8);
  FUN_00cb4d44((basic_string *)auStack_20,"Not implemented");
  IllegalStateException::IllegalStateException(this,(basic_string *)auStack_20);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this,&IllegalStateException::typeinfo,IllegalStateException::~IllegalStateException);
}


