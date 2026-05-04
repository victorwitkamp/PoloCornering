/* VagUdsFreezeFrameSetting::toEventString @ 0118c510 */


/* VagUdsFreezeFrameSetting::toEventString() const */

undefined8 VagUdsFreezeFrameSetting::toEventString(void)

{
  undefined4 in_r0;
  int *in_r1;
  undefined4 uStack_20;
  int *piStack_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  uStack_20 = in_r0;
  piStack_1c = in_r1;
  FUN_00cb4d44((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
               &uStack_20,"VAGUDS_FFD_");
  (**(code **)(*in_r1 + 8))();
  FUN_00cbe80c();
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &uStack_20);
  if (__stack_chk_guard == local_14) {
    return CONCAT44(piStack_1c,uStack_20);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


