/* Target address 00d5cfd4 */
/* Function combinedItems @ 00d5cfd4 */


/* StringWhitelist::combinedItems() */

void StringWhitelist::combinedItems(void)

{
  vector *in_r0;
  vector *pvVar1;
  int in_r1;
  
  pvVar1 = (vector *)FUN_00d02264();
  ContainerUtils::
  addAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            (pvVar1,(vector *)(in_r1 + 0x18));
  ContainerUtils::
  removeAll<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
            (in_r0,(vector *)(in_r1 + 0x24));
  return;
}


