/* ReadValuesOperation::getItemContentControl @ 012cdd4c */


/* ReadValuesOperation::getItemContentControl(std::__ndk1::shared_ptr<Setting> const&, bool) */

void __thiscall
ReadValuesOperation::getItemContentControl
          (ReadValuesOperation *this,shared_ptr *param_1,bool param_2)

{
  IllegalStateException *this_00;
  ReadValuesOperation *pRStack_20;
  shared_ptr *psStack_1c;
  uint uStack_18;
  undefined4 local_14;
  
  uStack_18 = (uint)param_2;
  local_14 = __stack_chk_guard;
  pRStack_20 = this;
  psStack_1c = param_1;
  this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
  FUN_00cb4d44((basic_string *)&pRStack_20,"Not implemented");
  IllegalStateException::IllegalStateException(this_00,(basic_string *)&pRStack_20);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this_00,&IllegalStateException::typeinfo,IllegalStateException::~IllegalStateException
             );
}


