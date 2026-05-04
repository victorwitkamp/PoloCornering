/* OperationDelegate::containsCachedRawValue @ 012412cc */


/* OperationDelegate::containsCachedRawValue(unsigned long long) */

void OperationDelegate::containsCachedRawValue(ulonglong param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __stack_chk_guard;
  uVar2 = std::__ndk1::
          __hash_table<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::__unordered_map_hasher<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::hash<unsigned_long_long>,std::__ndk1::equal_to<unsigned_long_long>,true>,std::__ndk1::__unordered_map_equal<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::equal_to<unsigned_long_long>,std::__ndk1::hash<unsigned_long_long>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>>>
          ::__count_unique<unsigned_long_long>
                    ((__hash_table<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::__unordered_map_hasher<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::hash<unsigned_long_long>,std::__ndk1::equal_to<unsigned_long_long>,true>,std::__ndk1::__unordered_map_equal<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::equal_to<unsigned_long_long>,std::__ndk1::hash<unsigned_long_long>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>>>
                      *)((int)param_1 + 0xe0),(ulonglong *)&stack0xffffffe8);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2 != 0);
  }
  return;
}


