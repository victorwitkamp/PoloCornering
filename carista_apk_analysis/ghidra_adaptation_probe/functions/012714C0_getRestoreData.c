/* VagOperationDelegate::getRestoreData @ 012714c0 */


/* VagOperationDelegate::getRestoreData(std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const&,
   std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::getRestoreData
          (VagOperationDelegate *this,basic_string *param_1,shared_ptr *param_2)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  int *local_54;
  undefined4 local_48;
  undefined *puStack_44;
  undefined **local_40;
  undefined **local_3c;
  VagOperationDelegate *local_38;
  undefined4 *puStack_34;
  undefined ***local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar6 = FUN_00cdb2f0(param_2);
  uVar5 = (uint)((ulonglong)uVar6 >> 0x20);
  if ((int)uVar6 == 0) {
    FUN_00cb4d44((basic_string *)&local_70,&DAT_006d2d75);
    iVar2 = StringUtils::startsWith((basic_string *)param_2,(basic_string *)&local_70);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_70);
    if (iVar2 == 0) {
      Log::d("Restoring data from VagRestoreDataBase.");
      StringUtils::parseUInt64((basic_string *)param_2,10);
      local_70 = 0;
      uStack_68 = 0;
      local_60 = 0;
      VagRestoreDataBase::VagRestoreDataBase((VagRestoreDataBase *)&local_70);
      VagRestoreDataBaseSystem::get
                (CONCAT44((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_70,&local_40));
      VagRestoreDataBaseSystem::~VagRestoreDataBaseSystem((VagRestoreDataBaseSystem *)&local_70);
      if (local_40 == (undefined **)0x0) {
        Result<VagRestoreData,void>::Result((Result<VagRestoreData,void> *)this,-0x3e9);
      }
      else {
        Result<VagRestoreData,void>::done
                  ((Result<VagRestoreData,void> *)this,(shared_ptr *)&local_40);
      }
      FUN_01140188(&local_40);
      goto LAB_012715b8;
    }
    Log::d("Restoring data from history api.");
    FUN_00cfe458(&local_70,param_2,1,0xffffffff);
    uVar6 = StringUtils::parseUInt64((basic_string *)&local_70,10);
    uVar4 = (uint)((ulonglong)uVar6 >> 0x20);
    uVar3 = (uint)uVar6;
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_70);
    uVar6 = TimeUtils::getCurrentTimeMiliseconds();
    uVar5 = (uint)((ulonglong)uVar6 >> 0x20);
    if ((uVar4 < uVar5 || uVar5 - uVar4 < (uint)(uVar3 <= (uint)uVar6)) &&
       (uVar5 = 0xe888e3ff - uVar3, 0x189 < uVar4 && (uint)(uVar3 < 0xe888e400) <= 0x18a - uVar4)) {
      OperationDelegate::readVinCached((OperationDelegate *)&local_70,(shared_ptr *)param_1);
      iVar2 = Result<StringModel,void>::isFatalFail((Result<StringModel,void> *)&local_70);
      if (iVar2 == 0) {
        iVar2 = Result<StringModel,void>::isFail((Result<StringModel,void> *)&local_70);
        if (iVar2 == 0) {
          local_48 = 0;
          puStack_44 = (undefined *)0x0;
          Result<VagRestoreData,void>::Result((Result<VagRestoreData,void> *)this);
          local_40 = &PTR_LAB_01280706_1_014baac4;
          local_30 = &local_40;
          puStack_34 = &local_48;
          local_3c = &puStack_44;
          local_38 = this;
          (**(code **)(*(int *)App::CARISTA_API_CLIENT + 0x1c))
                    ((int *)App::CARISTA_API_CLIENT,*local_54 + 4,uVar3,uVar4,local_30);
          FUN_011dc4c4(&local_40);
          local_3c = (undefined **)CONCAT31(local_3c._1_3_,1);
          local_40 = &puStack_44;
          std::__ndk1::mutex::lock();
          while (**(int **)(this + 0x18) == 0) {
            std::__ndk1::condition_variable::wait
                      ((condition_variable *)&local_48,(unique_lock *)&local_40);
          }
          FUN_00d2a548(&local_40);
          std::__ndk1::condition_variable::~condition_variable((condition_variable *)&local_48);
          std::__ndk1::mutex::~mutex((mutex *)&puStack_44);
        }
        else {
          Log::e("Failed to read VIN. Bailing.");
          Result<VagRestoreData,void>::Result((Result<VagRestoreData,void> *)this,-0x3e9);
        }
      }
      else {
        Log::e("Failed to read VIN fatally.");
        Result<StringModel,void>::stateAs<VagRestoreData,void>();
      }
      Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_70);
      goto LAB_012715b8;
    }
    pcVar1 = "Timestamp is in the future or too far in the past. Bailing.";
  }
  else {
    pcVar1 = "Empty backupSelector. Bailing.";
  }
  Log::e(pcVar1,uVar5);
  Result<VagRestoreData,void>::Result((Result<VagRestoreData,void> *)this,-0x3e9);
LAB_012715b8:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


