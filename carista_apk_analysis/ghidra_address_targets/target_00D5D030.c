/* Target address 00d5d030 */
/* Function itemMatches @ 00d5d030 */


/* StringWhitelist::itemMatches(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > const&, std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const&) const */

void __thiscall
StringWhitelist::itemMatches(StringWhitelist *this,basic_string *param_1,basic_string *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  basic_string *pbVar6;
  basic_string *pbVar7;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_00cb4d44(abStack_28,&DAT_00ad5a21);
  iVar3 = StringUtils::startsWith(param_1,(basic_string *)abStack_28);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_28);
  if (iVar3 == 0) {
    FUN_00cb4d44(abStack_28,&DAT_00ad5a21);
    iVar3 = StringUtils::endsWith(param_1,(basic_string *)abStack_28);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_28);
    if (iVar3 == 0) {
      iVar3 = std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::find
                        ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                          *)param_1,'.',0);
      if (iVar3 == -1) {
        FUN_00cbc7dc(param_2,param_1);
      }
      else {
        uVar4 = *(uint *)(param_1 + 4);
        cVar1 = (char)*param_1 * -0x80;
        if (cVar1 == '\0') {
          uVar4 = (uint)((byte)*param_1 >> 1);
        }
        uVar5 = *(uint *)(param_2 + 4);
        cVar2 = (char)*param_2 * -0x80;
        if (cVar2 == '\0') {
          uVar5 = (uint)((byte)*param_2 >> 1);
        }
        if (uVar4 == uVar5) {
          pbVar6 = *(basic_string **)(param_2 + 8);
          if (cVar2 == '\0') {
            pbVar6 = param_2 + 1;
          }
          pbVar7 = *(basic_string **)(param_1 + 8);
          if (cVar1 == '\0') {
            pbVar7 = param_1 + 1;
          }
          for (; (uVar4 != 0 && ((*pbVar7 == (basic_string)0x2e || (*pbVar7 == *pbVar6))));
              pbVar7 = pbVar7 + 1) {
            pbVar6 = pbVar6 + 1;
            uVar4 = uVar4 - 1;
          }
        }
      }
      goto LAB_00d5d0c6;
    }
    uVar4 = *(uint *)(param_1 + 4);
    if (((byte)*param_1 & 1) == 0) {
      uVar4 = (uint)((byte)*param_1 >> 1);
    }
    FUN_00cfe458(abStack_28,param_1,0,uVar4 - 1);
    StringUtils::startsWith(param_2,(basic_string *)abStack_28);
  }
  else {
    FUN_00cfe458(abStack_28,param_1,1,0xffffffff);
    StringUtils::endsWith(param_2,(basic_string *)abStack_28);
  }
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_28);
LAB_00d5d0c6:
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_1c);
}


