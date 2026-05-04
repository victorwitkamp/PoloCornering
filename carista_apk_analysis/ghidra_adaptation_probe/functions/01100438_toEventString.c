/* VagCanShortAdaptationSetting::toEventString @ 01100438 */


/* VagCanShortAdaptationSetting::toEventString() const */

void __thiscall VagCanShortAdaptationSetting::toEventString(VagCanShortAdaptationSetting *this)

{
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_2c [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  FUN_00cb4d44(abStack_20,"MCAdapt_");
  VagSetting::toEventString();
  FUN_00d1fa20(this,abStack_20,abStack_2c);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_2c);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_20);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


