/* OperationDelegate::writeTpms @ 01241934 */


/* OperationDelegate::writeTpms(bool,
   std::__ndk1::shared_ptr<std::__ndk1::vector<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   std::__ndk1::allocator<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > > > > const&, Ecu*) */

void OperationDelegate::writeTpms(bool param_1,shared_ptr *param_2,Ecu *param_3)

{
  UnsupportedOperationException *this;
  uint uStack_20;
  shared_ptr *psStack_1c;
  Ecu *pEStack_18;
  undefined4 local_14;
  
  uStack_20 = (uint)param_1;
  local_14 = __stack_chk_guard;
  psStack_1c = param_2;
  pEStack_18 = param_3;
  this = (UnsupportedOperationException *)__cxa_allocate_exception(8);
  FUN_00cb4d44((basic_string *)&uStack_20,"not implemented");
  UnsupportedOperationException::UnsupportedOperationException(this,(basic_string *)&uStack_20);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this,&UnsupportedOperationException::typeinfo,
              IllegalStateException::~IllegalStateException);
}


