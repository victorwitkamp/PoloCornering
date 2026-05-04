/* OperationDelegate::getCachedRawValue @ 01241330 */


/* OperationDelegate::getCachedRawValue(unsigned long long) */

ulonglong OperationDelegate::getCachedRawValue(ulonglong param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 in_r2;
  undefined4 in_r3;
  __hash_table<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::__unordered_map_hasher<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::hash<unsigned_long_long>,std::__ndk1::equal_to<unsigned_long_long>,true>,std::__ndk1::__unordered_map_equal<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::equal_to<unsigned_long_long>,std::__ndk1::hash<unsigned_long_long>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>>>
  *this;
  undefined8 local_20;
  int local_14;
  
  puVar2 = (undefined4 *)param_1;
  local_20 = CONCAT44(in_r3,in_r2);
  this = (__hash_table<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::__unordered_map_hasher<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::hash<unsigned_long_long>,std::__ndk1::equal_to<unsigned_long_long>,true>,std::__ndk1::__unordered_map_equal<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::equal_to<unsigned_long_long>,std::__ndk1::hash<unsigned_long_long>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>>>
          *)((int)(param_1 >> 0x20) + 0xe0);
  local_14 = __stack_chk_guard;
  uVar3 = std::__ndk1::
          __hash_table<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::__unordered_map_hasher<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::hash<unsigned_long_long>,std::__ndk1::equal_to<unsigned_long_long>,true>,std::__ndk1::__unordered_map_equal<unsigned_long_long,std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>,std::__ndk1::equal_to<unsigned_long_long>,std::__ndk1::hash<unsigned_long_long>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<unsigned_long_long,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const>>>>
          ::__count_unique<unsigned_long_long>(this,&local_20);
  if (uVar3 == 0) {
    *puVar2 = 0;
    puVar2[1] = 0;
  }
  else {
    puVar4 = (undefined4 *)FUN_01241398(this,&local_20);
    iVar5 = puVar4[1];
    *puVar2 = *puVar4;
    puVar2[1] = iVar5;
    if (iVar5 != 0) {
      piVar6 = (int *)(iVar5 + 4);
      do {
        ExclusiveAccess(piVar6);
        bVar1 = (bool)hasExclusiveAccess(piVar6);
      } while (!bVar1);
      *piVar6 = *piVar6 + 1;
    }
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_20;
}


