/* Target address 00d5cc58 */
/* Function mergeInternal<StringWhitelist> @ 00d5cc58 */


/* std::__ndk1::shared_ptr<StringWhitelist> Whitelist<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >, std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >
   >::mergeInternal<StringWhitelist>(std::initializer_list<std::__ndk1::shared_ptr<StringWhitelist>
   >, std::initializer_list<std::__ndk1::shared_ptr<StringWhitelist> >) */

void Whitelist<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
     ::mergeInternal<StringWhitelist>
               (undefined4 param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  
  iVar1 = __stack_chk_guard;
  local_38 = 0;
  local_40 = 0;
  uStack_3c = 0;
  for (param_3 = param_3 << 3; param_3 != 0; param_3 = param_3 + -8) {
    ContainerUtils::
    addAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ((vector *)&stack0xffffffcc,(vector *)(*param_2 + 0xc));
    ContainerUtils::
    addAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ((vector *)&local_40,(vector *)(*param_2 + 0x18));
    param_2 = param_2 + 2;
  }
  for (param_5 = param_5 << 3; param_5 != 0; param_5 = param_5 + -8) {
    ContainerUtils::
    addAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ((vector *)&local_40,(vector *)(*param_4 + 0xc));
    ContainerUtils::
    addAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ((vector *)&local_40,(vector *)(*param_4 + 0x18));
    param_4 = param_4 + 2;
  }
  FUN_00d5d6a8(param_1,&stack0xffffffcc,(vector *)&local_40);
  FUN_00cbe2dc((vector *)&local_40);
  FUN_00cbe2dc(&stack0xffffffcc);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


