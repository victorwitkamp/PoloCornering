/* CanEcu::toIdString @ 00d38b78 */


/* CanEcu::toIdString() const */

void CanEcu::toIdString(void)

{
  uint in_r0;
  int in_r1;
  ByteUtils aBStack_2c [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  CanAddr::Type::toString(in_r0);
  if (**(char **)(in_r1 + 0x14) != '\0') {
    ByteUtils::getHexString(aBStack_2c,*(uchar *)(in_r1 + 0x20));
    FUN_00cbe7e4(abStack_20,&DAT_0078c05f,aBStack_2c);
    FUN_00cdb814();
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_20);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  aBStack_2c);
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


