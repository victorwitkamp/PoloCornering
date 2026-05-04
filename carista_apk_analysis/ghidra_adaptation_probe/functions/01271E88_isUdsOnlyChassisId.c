/* VagOperationDelegate::isUdsOnlyChassisId @ 01271e88 */


/* VagOperationDelegate::isUdsOnlyChassisId() */

void __thiscall VagOperationDelegate::isUdsOnlyChassisId(VagOperationDelegate *this)

{
  basic_string *local_24 [2];
  int local_1c [2];
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x34))(local_1c,this);
  if (local_1c[0] != 0) {
    (**(code **)(*(int *)this + 0x34))(local_24,this);
    std::__ndk1::
    __hash_table<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>
    ::
    __count_unique<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ((__hash_table<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>
                *)UDS_ONLY_CHASSIS_IDS,local_24[0]);
    FUN_00cbba38(local_24);
  }
  FUN_00cbba38(local_1c);
  if (__stack_chk_guard == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}


