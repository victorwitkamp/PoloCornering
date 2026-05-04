/* VagOperationDelegate::isSfd1Protected @ 0126fcc8 */


/* VagOperationDelegate::isSfd1Protected(std::__ndk1::shared_ptr<Setting> const&) */

void VagOperationDelegate::isSfd1Protected(shared_ptr *param_1)

{
  uint uVar1;
  int iVar2;
  int *in_r1;
  undefined4 *in_r2;
  basic_string local_30 [12];
  int *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_0126fd84(local_24);
  (**(code **)(*(int *)*in_r2 + 0x18))(local_30);
  uVar1 = std::__ndk1::
          __hash_table<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>
          ::
          __count_unique<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                    ((__hash_table<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>
                      *)NON_SFD_PROTECTED_SETTINGS,local_30);
  if ((uVar1 == 0) && (local_24[0] != (int *)0x0)) {
    iVar2 = (**(code **)(*local_24[0] + 0x40))();
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  local_30);
    if (iVar2 != 0) {
      (**(code **)(*in_r1 + 0xd4))(param_1);
      goto LAB_0126fd16;
    }
  }
  else {
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  local_30);
  }
  local_30[0] = (basic_string)0x0;
  Result<bool,void>::done<bool>((type *)param_1);
LAB_0126fd16:
  FUN_00d1756c(local_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


