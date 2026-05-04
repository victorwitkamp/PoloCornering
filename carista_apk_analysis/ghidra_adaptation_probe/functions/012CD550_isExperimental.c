/* ReadValuesOperation::isExperimental @ 012cd550 */


/* ReadValuesOperation::isExperimental(std::__ndk1::shared_ptr<Setting> const&) */

bool __thiscall ReadValuesOperation::isExperimental(ReadValuesOperation *this,shared_ptr *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  iVar1 = (**(code **)(**(int **)param_1 + 0x2c))();
  if (iVar1 != 0) {
    return true;
  }
  uVar2 = std::__ndk1::
          __hash_table<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::__unordered_map_hasher<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::__unordered_map_equal<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>>>
          ::__count_unique<std::__ndk1::shared_ptr<Setting>>
                    ((__hash_table<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::__unordered_map_hasher<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::__unordered_map_equal<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>>>
                      *)(this + 0x7c),param_1);
  if (uVar2 != 0) {
    piVar3 = (int *)FUN_012cd58c((__hash_table<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::__unordered_map_hasher<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::__unordered_map_equal<std::__ndk1::shared_ptr<Setting>,std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>,std::__ndk1::equal_to<std::__ndk1::shared_ptr<Setting>>,std::__ndk1::hash<std::__ndk1::shared_ptr<Setting>>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<std::__ndk1::shared_ptr<Setting>,Availability>>>
                                  *)(this + 0x7c),param_1);
    return *piVar3 == 1;
  }
  return false;
}


