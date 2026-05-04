/* OperationDelegate::runRawDebugCommand @ 0124287c */


/* OperationDelegate::runRawDebugCommand(Ecu*, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, unsigned int, DebugData&,
   std::__ndk1::shared_ptr<Progress> const&) */

void OperationDelegate::runRawDebugCommand
               (Ecu *param_1,vector *param_2,uint param_3,DebugData *param_4,shared_ptr *param_5)

{
  int iVar1;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 local_58;
  Ecu aEStack_50 [24];
  int *local_38;
  DebugData *local_2c;
  vector *local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_2c = param_4;
  local_28 = param_2;
  ByteUtils::getHexString((ByteUtils *)&local_5c,(vector *)param_3);
  DebugData::get(aEStack_50,(basic_string *)param_5);
  iVar1 = *local_38;
  Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>const,void>
  ::~Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>const,void>
             *)aEStack_50);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_5c);
  if (iVar1 == -5 || iVar1 == -0xb) {
    FUN_0124294c(&local_64,&local_28,param_3,&local_2c);
    local_5c = local_64;
    local_58 = uStack_60;
    local_64 = 0;
    uStack_60 = 0;
    runDebugCommand<BytesListModel>
              ((shared_ptr *)aEStack_50,(DebugData *)param_1,(shared_ptr *)&local_5c);
    Result<BytesListModel,void>::~Result((Result<BytesListModel,void> *)aEStack_50);
    FUN_00d2b5d4(&local_5c);
    FUN_00d2b5e6(&local_64);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_24);
  }
  return;
}


