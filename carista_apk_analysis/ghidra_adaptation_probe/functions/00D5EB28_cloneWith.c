/* TroubleCode::cloneWith @ 00d5eb28 */


/* TroubleCode::cloneWith(std::__ndk1::shared_ptr<FreezeFrameModel> const&) */

void TroubleCode::cloneWith(shared_ptr *param_1)

{
  IllegalArgumentException *this;
  shared_ptr *apsStack_20 [3];
  undefined4 local_14;
  
  local_14 = __stack_chk_guard;
  apsStack_20[0] = param_1;
  this = (IllegalArgumentException *)__cxa_allocate_exception(8);
  FUN_00cb4d44((basic_string *)apsStack_20,"Not implemented");
  IllegalArgumentException::IllegalArgumentException(this,(basic_string *)apsStack_20);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this,&IllegalArgumentException::typeinfo,IllegalStateException::~IllegalStateException
             );
}


