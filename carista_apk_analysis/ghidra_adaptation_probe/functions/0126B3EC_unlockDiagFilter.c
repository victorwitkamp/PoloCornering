/* VagOperationDelegate::unlockDiagFilter @ 0126b3ec */


/* VagOperationDelegate::unlockDiagFilter(std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::unlockDiagFilter(VagOperationDelegate *this,shared_ptr *param_1)

{
  int iVar1;
  shared_ptr asStack_70 [28];
  int *local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 auStack_40 [8];
  int *local_38;
  undefined4 uStack_34;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  Log::d("Unlocking VAG SFD2 diagnostic filter");
  DataMemoryBarrier(0x1b);
  if (((DAT_014f8f64 & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_014f8f64), iVar1 != 0)) {
    FUN_00cb4d44(abStack_30,&DAT_00ad5a21);
    FUN_00d22d0c(asStack_70,abStack_30,1);
    FUN_0110bf70(auStack_40,asStack_70);
    local_44 = 0x31d;
    local_48 = 0;
    local_4c = 1;
    FUN_010b4664(&local_38,&VagUdsEcu::CAN_GATEWAY,auStack_40,&local_44,&local_48,&local_4c,
                 "car_setting_diag_filter_temp_disable",&MultipleChoiceInterpretation::ON_OFF);
    DAT_014f8f6c = uStack_34;
    DAT_014f8f68 = local_38;
    local_38 = (int *)0x0;
    uStack_34 = 0;
    FUN_010bbffc(&local_38);
    FUN_00d5d494(auStack_40);
    FUN_00cbe2dc(asStack_70);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_30);
    __cxa_atexit(0xcc67b1,&DAT_014f8f68,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f8f64);
  }
  iVar1 = (**(code **)(**(int **)param_1 + 0x14))();
  if (iVar1 == 0) {
    Log::d("Reading VAG SFD2 diagnostic temporary filter status");
    OperationDelegate::readSettingValueCached(asStack_70);
    iVar1 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)asStack_70);
    if (iVar1 == 0) {
      (**(code **)(*DAT_014f8f68 + 0x1c))(abStack_30,DAT_014f8f68,*local_54 + 4);
      iVar1 = FUN_00cdbf64(abStack_30,SFD2_TEMP_DIAG_FILTER_OFF_VALUE);
      if (iVar1 == 0) {
        Log::d("SFD2 diagnostic filter is active. Disabling it.");
        OperationDelegate::changeSetting
                  ((OperationDelegate *)this,(shared_ptr *)&DAT_014f8f68,
                   (vector *)SFD2_TEMP_DIAG_FILTER_OFF_VALUE,param_1);
      }
      else {
        Log::d("Filter is already temporarily disabled!");
      }
      FUN_00cb7f50(abStack_30);
    }
    else {
      Log::e("Failed to read if filter is temporarily disabled!");
    }
    Result<BytesModel,void>::~Result((Result<BytesModel,void> *)asStack_70);
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_24);
}


