/* Setting::setInstruction @ 00d58fdc */


/* Setting::setInstruction(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > const&) */

void Setting::setInstruction(basic_string *param_1)

{
  int in_r1;
  undefined1 auStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_00d25888(auStack_24);
  _ZNSt6__ndk110shared_ptrIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEaSB8ne190000IS6_TnNS_9enable_ifIXsr17__compatible_withIT_S7_EE5valueEiE4typeELi0EEERS8_ONS0_ISB_EE
            (in_r1 + 0x4c,auStack_24);
  FUN_00cbd6dc(auStack_24);
  _ZNSt6__ndk110shared_ptrI7SettingEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
            (param_1,in_r1 + 4);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


