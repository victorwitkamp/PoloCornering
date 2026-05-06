/* Target address 00d5cd6c */
/* Function StringWhitelist @ 00d5cd6c */


/* StringWhitelist::StringWhitelist(std::__ndk1::vector<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   std::__ndk1::allocator<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > > > const&, std::__ndk1::vector<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   std::__ndk1::allocator<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > > > const&) */

void __thiscall
StringWhitelist::StringWhitelist(StringWhitelist *this,vector *param_1,vector *param_2)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = 0;
  local_20 = 0;
  uStack_1c = 0;
  StringWhitelist(this,param_1,param_2,(vector *)&local_20);
  FUN_00cbe2dc((vector *)&local_20);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


