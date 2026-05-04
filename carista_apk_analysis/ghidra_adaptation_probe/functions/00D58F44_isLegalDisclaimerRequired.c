/* Setting::isLegalDisclaimerRequired @ 00d58f44 */


/* Setting::isLegalDisclaimerRequired() const */

void Setting::isLegalDisclaimerRequired(void)

{
  int *in_r0;
  undefined4 uVar1;
  basic_string abStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  uVar1 = (**(code **)(*in_r0 + 8))();
  FUN_00cb4d44(abStack_20,uVar1);
  ContainerUtils::
  contains<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            ((vector *)DISCLAIMER_SETTING_RES_IDS,abStack_20);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_20);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


