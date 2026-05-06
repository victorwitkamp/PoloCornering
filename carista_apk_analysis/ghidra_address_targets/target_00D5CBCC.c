/* Target address 00d5cbcc */
/* Function from @ 00d5cbcc */


/* StringWhitelist::from(std::__ndk1::vector<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   std::__ndk1::allocator<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > > > const&) */

undefined4 __thiscall StringWhitelist::from(StringWhitelist *this,vector *param_1)

{
  int iVar1;
  undefined4 local_18;
  
  iVar1 = __stack_chk_guard;
  local_18 = 0;
  FUN_00d5cc14(this,param_1,&local_18);
  FUN_00cbe2dc(&local_18);
  if (__stack_chk_guard == iVar1) {
    return local_18;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


