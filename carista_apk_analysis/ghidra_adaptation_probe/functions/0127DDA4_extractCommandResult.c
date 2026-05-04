/* BroadcastCommandResult<DiagFilterModel>::extractCommandResult @ 0127dda4 */


/* BroadcastCommandResult<DiagFilterModel>::extractCommandResult(Ecu*) const */

void BroadcastCommandResult<DiagFilterModel>::extractCommandResult(Ecu *param_1)

{
  int iVar1;
  uint uVar2;
  Result *pRVar3;
  Result<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>,void>
  *in_r1;
  Ecu *local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = Result<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>,void>
          ::isFail(in_r1);
  if (iVar1 == 0) {
    uVar2 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>>>
            ::__count_unique<Ecu*>
                      ((__hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<DiagFilterModel,void>>>>
                        *)**(undefined4 **)(in_r1 + 0x1c),&local_18);
    if (uVar2 == 0) {
      Result<DiagFilterModel,void>::Result((Result<DiagFilterModel,void> *)param_1,-0xb);
    }
    else {
      pRVar3 = (Result *)FUN_0127f9a8(**(undefined4 **)(in_r1 + 0x1c),&local_18);
      Result<DiagFilterModel,void>::Result((Result<DiagFilterModel,void> *)param_1,pRVar3);
    }
    if (__stack_chk_guard == local_14) {
      return;
    }
  }
  else {
    Result<DiagFilterModel,void>::Result
              ((Result<DiagFilterModel,void> *)param_1,**(int **)(in_r1 + 0x18));
    if (__stack_chk_guard == local_14) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


