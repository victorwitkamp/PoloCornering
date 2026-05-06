/* Target address 00d5cdbc */
/* Function StringWhitelist @ 00d5cdbc */


/* StringWhitelist::StringWhitelist(std::__ndk1::vector<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   std::__ndk1::allocator<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > > > const&, std::__ndk1::vector<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   std::__ndk1::allocator<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > > > const&, std::__ndk1::vector<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   std::__ndk1::allocator<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > > > const&) */

void __thiscall
StringWhitelist::StringWhitelist
          (StringWhitelist *this,vector *param_1,vector *param_2,vector *param_3)

{
  int iVar1;
  int iVar2;
  IllegalArgumentException *this_00;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *this_01;
  vector *pvStack_3c;
  vector *pvStack_38;
  vector *pvStack_34;
  
  iVar1 = __stack_chk_guard;
  pvStack_3c = param_1;
  pvStack_38 = param_2;
  pvStack_34 = param_3;
  ContainerUtils::
  unique<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ((ContainerUtils *)&stack0xffffffd0,param_1);
  ContainerUtils::
  unique<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ((ContainerUtils *)&pvStack_3c,param_2);
  Whitelist<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
  ::Whitelist((Whitelist<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
               *)this,(vector *)&stack0xffffffd0,(vector *)&pvStack_3c);
  FUN_00cbe2dc(&pvStack_3c);
  FUN_00cbe2dc(&stack0xffffffd0);
  *(undefined ***)this = &PTR__StringWhitelist_01447344;
  FUN_00d02264(this + 0x24,param_3);
  ContainerUtils::
  addAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ((vector *)&stack0xffffffd0,param_1);
  ContainerUtils::
  addAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ((vector *)&stack0xffffffd0,param_2);
  this_01 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)0x0;
  while( true ) {
    if (this_01 ==
        (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)0x0) {
      FUN_00cbe2dc(&stack0xffffffd0);
      if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(iVar1);
      }
      return;
    }
    iVar2 = std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::find
                      (this_01,'*',0);
    if ((iVar2 != -1) &&
       (iVar2 = std::__ndk1::
                basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::find
                          (this_01,'.',0), iVar2 != -1)) break;
    this_01 = this_01 + 0xc;
  }
  this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
  std::__ndk1::operator+
            ((__ndk1 *)&pvStack_3c,"Invalid whitelist entry - contains both wildcard and dot: ",
             (basic_string *)this_01);
  IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&pvStack_3c);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
              IllegalStateException::~IllegalStateException);
}


