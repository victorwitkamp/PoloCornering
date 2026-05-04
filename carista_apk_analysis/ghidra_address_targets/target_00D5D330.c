/* Target address 00d5d330 */
/* Function match @ 00d5d330 */


/* StringWhitelist::match(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > const&) const */

undefined4 __thiscall StringWhitelist::match(StringWhitelist *this,basic_string *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(this + 0x24);
  iVar3 = *(int *)(this + 0x28);
  do {
    if (iVar4 == iVar3) {
      uVar2 = Whitelist<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ::match((Whitelist<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                       *)this,param_1);
      return uVar2;
    }
    iVar1 = (**(code **)(*(int *)this + 0xc))(this,iVar4,param_1);
    iVar4 = iVar4 + 0xc;
  } while (iVar1 == 0);
  return 0;
}


