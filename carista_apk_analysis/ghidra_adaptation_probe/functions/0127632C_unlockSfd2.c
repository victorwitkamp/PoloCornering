/* VagOperationDelegate::unlockSfd2 @ 0127632c */


/* VagOperationDelegate::unlockSfd2(std::__ndk1::vector<std::__ndk1::pair<std::__ndk1::shared_ptr<Setting>
   const, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > >,
   std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::shared_ptr<Setting> const,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > > > >,
   std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::unlockSfd2(VagOperationDelegate *this,int *param_2,shared_ptr *param_3)

{
  int iVar1;
  IllegalArgumentException *this_00;
  IllegalStateException *this_01;
  int *piVar2;
  int *piVar3;
  undefined1 local_139;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined4 local_12c;
  int local_128;
  int iStack_124;
  undefined4 local_11c;
  undefined4 *local_118;
  int local_114;
  int *local_104;
  int *local_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined **local_ec;
  undefined4 *local_e8;
  int *local_d0;
  shared_ptr local_c8;
  undefined1 auStack_c7 [7];
  undefined1 *local_c0;
  undefined2 *local_a4;
  undefined4 uStack_a0;
  Ecu *local_9c;
  int local_98 [2];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_90 [12];
  OperationDelegate aOStack_84 [28];
  int *local_68;
  undefined4 *local_60;
  undefined1 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined **local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  Result<BytesModel,void> *local_44;
  undefined ***pppuStack_40;
  int local_28;
  
  local_28 = __stack_chk_guard;
  Log::d("Unlocking SFD2...");
  if (param_2[1] == *param_2) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(aOStack_84,"No SFD2 settings to unlock!");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)aOStack_84);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  iVar1 = unlockDiagFilter(this,param_3);
  iVar1 = State::isError(iVar1);
  if (iVar1 != 0) {
    Log::e("Failed to unlock SFD2, cannot unlock diagnostic filter!");
    goto LAB_0127671c;
  }
  iVar1 = (**(code **)(**(int **)param_3 + 0x14))();
  if (iVar1 != 0) goto LAB_0127671c;
  OperationDelegate::readVinCached(aOStack_84,(shared_ptr *)this);
  iVar1 = Result<StringModel,void>::isFail((Result<StringModel,void> *)aOStack_84);
  if (iVar1 != 0) {
    this_01 = (IllegalStateException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_c8,"Cannot unlock SFD2 for vehicle without VIN");
    IllegalStateException::IllegalStateException(this_01,(basic_string *)&local_c8);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_01,&IllegalStateException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  iVar1 = (**(code **)(**(int **)param_3 + 0x14))();
  if (iVar1 == 0) {
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    basic_string(abStack_90,(basic_string *)(*local_68 + 4));
    VagVin::getBrandParameter((VagVin *)local_98,(basic_string *)abStack_90);
    if (local_98[0] == 0) {
      Log::w("Cannot recognize brand parameter, assuming brand is VW");
      FUN_011510fc(&local_c8,&DAT_009cdb36);
      FUN_00d30a9c(local_98,&local_c8);
      FUN_00cbd6dc(&local_c8);
    }
    local_9c = *(Ecu **)(*(int *)*param_2 + 0x10);
    iVar1 = VagEcu::getEquivalent(local_9c);
    if (iVar1 == 0) {
      local_a4 = (undefined2 *)0x0;
      uStack_a0 = 0;
LAB_0127645c:
      (**(code **)(*(int *)local_9c + 0x10))(&local_c8);
      if (((byte)local_c8 & 1) == 0) {
        local_c0 = auStack_c7;
      }
      Log::e("Failed to determine diagnostic address for ECU %s!",local_c0);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_c8);
    }
    else {
      iVar1 = VagEcu::getEquivalent(local_9c);
      FUN_00d2ff74(&local_a4,iVar1 + 0x12);
      if (local_a4 == (undefined2 *)0x0) goto LAB_0127645c;
      local_50 = (undefined **)CONCAT31(local_50._1_3_,3);
      FUN_01273c7c(&local_11c,&local_9c,&local_50);
      local_ec = local_11c;
      local_e8 = local_118;
      local_11c = (undefined **)0x0;
      local_118 = (undefined4 *)0x0;
      OperationDelegate::runCommand<EmptyModel>(&local_c8,(shared_ptr *)this);
      FUN_011e4048(&local_ec);
      FUN_011ff7b8(&local_11c);
      iVar1 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)&local_c8);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(**(int **)param_3 + 0x14))();
        if (iVar1 == 0) {
          local_f8 = CONCAT31(local_f8._1_3_,3);
          FUN_01276294(&local_50,&local_9c,&local_f8);
          local_11c = local_50;
          local_118 = local_4c;
          local_50 = (undefined **)0x0;
          local_4c = (undefined4 *)0x0;
          OperationDelegate::runCommand<BytesModel>((shared_ptr *)&local_ec,(shared_ptr *)this);
          FUN_011e4f74(&local_11c);
          FUN_012762c8(&local_50);
          iVar1 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_ec);
          if (iVar1 == 0) {
            iVar1 = (**(code **)(**(int **)param_3 + 0x14))();
            if (iVar1 == 0) {
              piVar2 = (int *)*param_2;
              piVar3 = (int *)param_2[1];
              local_f0 = 0;
              local_f8 = 0;
              uStack_f4 = 0;
              for (; piVar2 != piVar3; piVar2 = piVar2 + 5) {
                std::__ndk1::
                vector<std::__ndk1::pair<unsigned_short,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>,std::__ndk1::allocator<std::__ndk1::pair<unsigned_short,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>>
                ::
                emplace_back<unsigned_short_const&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>const&>
                          ((vector<std::__ndk1::pair<unsigned_short,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>,std::__ndk1::allocator<std::__ndk1::pair<unsigned_short,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>>
                            *)&local_f8,(ushort *)(*piVar2 + 0x14),(vector *)(piVar2 + 2));
              }
              local_58 = 0;
              uStack_54 = 0;
              Result<BytesModel,void>::Result((Result<BytesModel,void> *)&local_11c);
              local_50 = &PTR_LAB_0121909c_1_014bae8c;
              local_48 = &local_58;
              local_4c = &uStack_54;
              local_44 = (Result<BytesModel,void> *)&local_11c;
              pppuStack_40 = &local_50;
              (**(code **)(*(int *)App::CARISTA_API_CLIENT + 0x10))
                        ((int *)App::CARISTA_API_CLIENT,*local_d0 + 4,abStack_90,local_98[0],
                         *local_a4,
                         (vector<std::__ndk1::pair<unsigned_short,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>,std::__ndk1::allocator<std::__ndk1::pair<unsigned_short,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>>
                          *)&local_f8,&local_50);
              FUN_011dc4a4(&local_50);
              local_5c = 1;
              local_60 = &uStack_54;
              std::__ndk1::mutex::lock();
              while (*local_104 == 0) {
                std::__ndk1::condition_variable::wait
                          ((condition_variable *)&local_58,(unique_lock *)&local_60);
              }
              iVar1 = (**(code **)(**(int **)param_3 + 0x14))();
              if (iVar1 == 0) {
                iVar1 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_11c);
                if (iVar1 == 0) {
                  FUN_00cd5ef0(&local_128,*local_100 + 4);
                  if (local_128 == iStack_124) {
                    Log::e("Failed to unlock SFD2, token has invalid format!");
                  }
                  else {
                    local_139 = 3;
                    FUN_01273c7c(&local_138,&local_9c,&local_139);
                    local_130 = local_138;
                    local_12c = uStack_134;
                    local_138 = 0;
                    uStack_134 = 0;
                    OperationDelegate::runCommand<EmptyModel>
                              ((shared_ptr *)&local_50,(shared_ptr *)this);
                    Result<EmptyModel,void>::operator=
                              ((Result<EmptyModel,void> *)&local_c8,(Result *)&local_50);
                    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_50);
                    FUN_011e4048(&local_130);
                    FUN_011ff7b8(&local_138);
                    iVar1 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)&local_c8);
                    if (iVar1 == 0) {
                      iVar1 = (**(code **)(**(int **)param_3 + 0x14))();
                      if (iVar1 == 0) {
                        local_139 = 3;
                        FUN_012762dc(&local_138,&local_9c,&local_139,&local_128);
                        local_130 = local_138;
                        local_12c = uStack_134;
                        local_138 = 0;
                        uStack_134 = 0;
                        OperationDelegate::runCommand<EmptyModel>
                                  ((shared_ptr *)&local_50,(shared_ptr *)this);
                        FUN_011e4048(&local_130);
                        FUN_01276318(&local_138);
                        iVar1 = Result<EmptyModel,void>::isFail
                                          ((Result<EmptyModel,void> *)&local_50);
                        if (iVar1 != 0) {
                          Log::e("Failed to write SFD2 token!");
                        }
                        Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_50);
                      }
                    }
                    else {
                      Log::e("Failed to start extended diagnostic session!");
                    }
                  }
                  FUN_00cb7f50(&local_128);
                }
                else {
                  Log::e("Failed to receive SFD2 token from server!");
                }
              }
              FUN_00d2a548(&local_60);
              Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_11c);
              std::__ndk1::condition_variable::~condition_variable((condition_variable *)&local_58);
              std::__ndk1::mutex::~mutex((mutex *)&uStack_54);
              FUN_012768e8(&local_f8);
            }
          }
          else {
            (**(code **)(*(int *)local_9c + 0x10))(&local_11c);
            if (((uint)local_11c & 1) == 0) {
              local_114 = (int)&local_11c + 1;
            }
            Log::e("Failed to obtain SFD2 challenge from ECU %s!",local_114);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_11c);
          }
          Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_ec);
        }
      }
      else {
        Log::e("Failed to start extended diagnostic session!");
      }
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_c8);
    }
    FUN_00d1e42c(&local_a4);
    FUN_00cbd6dc(local_98);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_90);
  }
  Result<StringModel,void>::~Result((Result<StringModel,void> *)aOStack_84);
LAB_0127671c:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


