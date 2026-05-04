/* OperationDelegate::unlockSecurityAccessInternal @ 01242990 */


/* OperationDelegate::unlockSecurityAccessInternal(Ecu*, unsigned char, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > const&,
   std::__ndk1::function<Result<std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned
   char> >, void> (std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   const&)>) */

void __thiscall
OperationDelegate::unlockSecurityAccessInternal
          (OperationDelegate *this,undefined4 param_1,byte param_2,undefined4 param_4,
          undefined4 param_5)

{
  int iVar1;
  int local_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 *local_48;
  shared_ptr asStack_40 [24];
  int *local_28;
  int *local_24;
  byte bStack_19;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  bStack_19 = param_2;
  local_18 = param_1;
  FUN_01242bb0(&local_88,&local_18,&bStack_19);
  local_64 = local_88;
  local_60 = uStack_84;
  local_88 = 0;
  uStack_84 = 0;
  runCommand<BytesModel>(asStack_40,(int)this,(Set *)&local_64);
  FUN_011e4f74(&local_64);
  FUN_01242bec(&local_88);
  if (*local_28 == -0x19) {
    Log::d("ECU security access is already activated; proceeding.");
  }
  else {
    iVar1 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)asStack_40);
    if (iVar1 == 0) {
      FUN_012456c4(&local_64,param_5,*local_24 + 4);
      iVar1 = Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
              ::isFail((Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                        *)&local_64);
      if (iVar1 == 0) {
        local_9c = bStack_19 + 1;
        FUN_01242c00(&local_98,&local_18,&local_9c,*local_48);
        local_90 = local_98;
        local_8c = uStack_94;
        local_98 = 0;
        uStack_94 = 0;
        runCommand<EmptyModel>((shared_ptr *)&local_88,(int)this,(Set *)&local_90);
        FUN_011e4048(&local_90);
        FUN_01242c3c(&local_98);
        Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_88);
      }
      Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>::~Result
                ((Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                  *)&local_64);
    }
  }
  Result<BytesModel,void>::~Result((Result<BytesModel,void> *)asStack_40);
  if (__stack_chk_guard == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}


