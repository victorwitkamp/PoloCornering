/* VagOperationDelegate::unlockSfd1 @ 01275a60 */


/* VagOperationDelegate::unlockSfd1(Ecu*, std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::unlockSfd1(VagOperationDelegate *this,Ecu *param_1,shared_ptr *param_2)

{
  vector *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  IllegalStateException *this_00;
  Result<BytesModel,void> *pRVar5;
  undefined4 uVar6;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  longlong lVar7;
  longlong lVar8;
  undefined4 local_194;
  undefined4 local_190;
  undefined **local_170;
  undefined4 *puStack_16c;
  int *local_158;
  int *local_154;
  undefined2 *local_14c;
  undefined4 uStack_148;
  shared_ptr asStack_144 [28];
  int *local_128;
  int local_120 [2];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_118 [12];
  undefined **local_10c;
  undefined4 *puStack_108;
  int *local_f0;
  shared_ptr asStack_e8 [28];
  int *local_cc;
  Ecu *local_c4;
  Ecu *local_c0;
  basic_string abStack_bc [12];
  basic_string abStack_b0 [12];
  __ndk1 local_a4 [12];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 *local_80;
  undefined1 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 *local_6c;
  Result<BytesModel,void> *local_68;
  undefined4 *puStack_64;
  undefined4 *local_60;
  Param local_58 [28];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  local_c4 = param_1;
  local_c0 = param_1;
  FUN_0127624c(&local_10c,&local_c4);
  local_70 = local_10c;
  local_6c = puStack_108;
  local_10c = (undefined **)0x0;
  puStack_108 = (undefined4 *)0x0;
  OperationDelegate::runCommand<UInt8Model>(asStack_e8,(shared_ptr *)this);
  FUN_0121d0ec(&local_70);
  FUN_01276280(&local_10c);
  iVar3 = Result<UInt8Model,void>::isFail((Result<UInt8Model,void> *)asStack_e8);
  if (iVar3 != 0) {
    Log::e("Failed to read SFD1 timer");
    goto LAB_01276010;
  }
  if ((*(char *)(*local_cc + 4) != '\0') ||
     (iVar3 = (**(code **)(**(int **)param_2 + 0x14))(), iVar3 != 0)) goto LAB_01276010;
  iVar3 = checkHoodClosed(this);
  iVar4 = State::isFatalError(iVar3);
  if ((iVar4 != 0) || (iVar3 == -0x2a)) goto LAB_01276010;
  OperationDelegate::readVinCached((OperationDelegate *)&local_10c,(shared_ptr *)this);
  iVar3 = Result<StringModel,void>::isFail((Result<StringModel,void> *)&local_10c);
  if (iVar3 != 0) {
    this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_70,"Cannot unlock SFD1 for vehicle without VIN");
    IllegalStateException::IllegalStateException(this_00,(basic_string *)&local_70);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalStateException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  basic_string(abStack_118,(basic_string *)(*local_f0 + 4));
  VagVin::getBrandParameter((VagVin *)local_120,(basic_string *)abStack_118);
  if (local_120[0] == 0) {
    Log::e("Cannot unlock SFD1 for vehicle without brand parameter, assuming brand is VW");
    FUN_011510fc(&local_70,&DAT_009cdb36);
    FUN_00d30a9c(local_120,&local_70);
    FUN_00cbd6dc(&local_70);
  }
  local_194 = CONCAT31(local_194._1_3_,2);
  FUN_01276294(&local_170,&local_c4,&local_194);
  local_70 = local_170;
  local_6c = puStack_16c;
  local_170 = (undefined **)0x0;
  puStack_16c = (undefined4 *)0x0;
  OperationDelegate::runCommand<BytesModel>(asStack_144,(shared_ptr *)this);
  FUN_011e4f74(&local_70);
  FUN_012762c8(&local_170);
  iVar3 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)asStack_144);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(**(int **)param_2 + 0x14))();
    if (iVar3 == 0) {
      iVar3 = VagEcu::getEquivalent(local_c4);
      if (iVar3 == 0) {
        local_14c = (undefined2 *)0x0;
        uStack_148 = 0;
      }
      else {
        iVar3 = VagEcu::getEquivalent(local_c4);
        FUN_00d2ff74(&local_14c,iVar3 + 0x12);
        if (local_14c != (undefined2 *)0x0) {
          local_78 = 0;
          uStack_74 = 0;
          Result<BytesModel,void>::Result((Result<BytesModel,void> *)&local_170);
          lVar7 = TimeUtils::getCurrentTimeMiliseconds();
          local_70 = &PTR_LAB_0121909c_1_014bae24;
          puStack_64 = &local_78;
          local_6c = &uStack_74;
          local_68 = (Result<BytesModel,void> *)&local_170;
          local_60 = &local_70;
          (**(code **)(*(int *)App::CARISTA_API_CLIENT + 0xc))
                    ((int *)App::CARISTA_API_CLIENT,*local_128 + 4,abStack_118,local_120[0],
                     *local_14c,&local_70);
          FUN_011dc4a4(&local_70);
          local_7c = 1;
          local_80 = &uStack_74;
          std::__ndk1::mutex::lock();
          do {
            if (*local_158 != 0) {
              lVar8 = TimeUtils::getCurrentTimeMiliseconds();
              FUN_013f4888((int)(lVar8 - lVar7),(int)((ulonglong)(lVar8 - lVar7) >> 0x20));
              piVar2 = (int *)App::ANALYTICS;
              FUN_00cb4d44(&local_194,"vag_sfd_unlock_response_time");
              FUN_00cb4d44(&local_98,"state");
              std::__ndk1::to_string(local_a4,*local_158);
              Analytics::Event::Param::Param
                        ((Param *)&local_70,(basic_string *)&local_98,(basic_string *)local_a4);
              uVar6 = FUN_00cb4d44(abStack_b0,"time_to_resp");
              round((double)CONCAT44(extraout_s1,uVar6));
              _ZN11StringUtils8toStringIdTnPNSt6__ndk19enable_ifIXsr7is_sameIT_dEE5valueES3_E4typeELPd0EEENS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES3_
                        (abStack_bc);
              Analytics::Event::Param::Param(local_58,abStack_b0,abStack_bc);
              FUN_00ce429c(&local_8c,&local_70,2);
              (**(code **)(*piVar2 + 8))(piVar2,&local_194,&local_8c);
              FUN_00ce431c(&local_8c);
              iVar3 = 0x18;
              do {
                Analytics::Event::Param::~Param((Param *)((int)&local_70 + iVar3));
                iVar3 = iVar3 + -0x18;
              } while (iVar3 != -0x18);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)abStack_bc);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)abStack_b0);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)local_a4);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)&local_98);
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                             *)&local_194);
              if (*local_158 != 0) goto LAB_01275d44;
            }
            std::__ndk1::condition_variable::wait
                      ((condition_variable *)&local_78,(unique_lock *)&local_80);
          } while( true );
        }
      }
      (**(code **)(*(int *)local_c4 + 0x10))(&local_70);
      pRVar5 = local_68;
      if (((uint)local_70 & 1) == 0) {
        pRVar5 = (Result<BytesModel,void> *)((int)&local_70 + 1);
      }
      Log::e("Failed to determine diagnostic address for ECU %s!",pRVar5);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_70);
      goto LAB_01275ff0;
    }
  }
  else {
    Log::e("Cannot unlock SFD1 for vehicle without sfd1ChallengeResult");
  }
  goto LAB_01275ff8;
LAB_01275d44:
  iVar3 = (**(code **)(**(int **)param_2 + 0x14))();
  if (iVar3 == 0) {
    if (*local_158 == 0) {
      Log::e("Unlocking SFD1 timed out without response.");
    }
    else {
      lVar8 = TimeUtils::getCurrentTimeMiliseconds();
      FUN_013f4888((int)(lVar8 - lVar7),(int)((ulonglong)(lVar8 - lVar7) >> 0x20));
      piVar2 = (int *)App::ANALYTICS;
      FUN_00cb4d44(&local_194,"vag_sfd_unlock_response_time");
      FUN_00cb4d44(&local_98,"state");
      std::__ndk1::to_string(local_a4,*local_158);
      iVar3 = Analytics::Event::Param::Param
                        ((Param *)&local_70,(basic_string *)&local_98,(basic_string *)local_a4);
      uVar6 = FUN_00cb4d44(abStack_b0,"time_to_resp");
      round((double)CONCAT44(extraout_s1_00,uVar6));
      _ZN11StringUtils8toStringIdTnPNSt6__ndk19enable_ifIXsr7is_sameIT_dEE5valueES3_E4typeELPd0EEENS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES3_
                (abStack_bc);
      Analytics::Event::Param::Param((Param *)(iVar3 + 0x18),abStack_b0,abStack_bc);
      FUN_00ce429c(&local_8c,&local_70,2);
      (**(code **)(*piVar2 + 8))(piVar2,&local_194,&local_8c);
      FUN_00ce431c(&local_8c);
      iVar3 = 0x18;
      do {
        Analytics::Event::Param::~Param((Param *)((int)&local_70 + iVar3));
        iVar3 = iVar3 + -0x18;
      } while (iVar3 != -0x18);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_bc);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_b0);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)local_a4);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_98);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_194);
      iVar3 = (**(code **)(**(int **)param_2 + 0x14))();
      if (iVar3 == 0) {
        iVar3 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_170);
        if (iVar3 == 0) {
          pvVar1 = (vector *)(*local_154 + 4);
          iVar3 = *(int *)(*local_154 + 8) - *(int *)pvVar1;
          if (iVar3 == 0x93 || iVar3 == 0x1d6) {
            local_98 = CONCAT31(local_98._1_3_,3);
            FUN_01213abc(&local_8c,&local_c0,&local_98);
            local_194 = local_8c;
            local_190 = local_88;
            local_8c = 0;
            local_88 = 0;
            OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_70,(shared_ptr *)this);
            FUN_011e4048(&local_194);
            FUN_011ff7b8(&local_8c);
            iVar3 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)&local_70);
            if (iVar3 == 0) {
              local_a4[0] = (__ndk1)0x2;
              FUN_012762dc(&local_98,&local_c4,local_a4,*local_154 + 4);
              local_8c = local_98;
              local_88 = uStack_94;
              local_98 = 0;
              uStack_94 = 0;
              OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_194,(shared_ptr *)this)
              ;
              FUN_011e4048(&local_8c);
              FUN_01276318(&local_98);
              iVar3 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)&local_194);
              if (iVar3 != 0) {
                Log::e("Failed to unlock SFD1");
              }
              Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_194);
            }
            else {
              Log::e("Failed to start diagnostic session");
            }
            Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_70);
          }
          else {
            ByteUtils::getHexString((ByteUtils *)&local_70,pvVar1);
            pRVar5 = local_68;
            if (((uint)local_70 & 1) == 0) {
              pRVar5 = (Result<BytesModel,void> *)((int)&local_70 + 1);
            }
            Log::e("SFD1 token is in the wrong format %s",pRVar5);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_70);
            FUN_00cb4d44(&local_70,"SFD token is in the wrong format");
            OperationDelegate::sendAutoReport
                      ((OperationDelegate *)this,-6,(basic_string *)&local_70);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_70);
          }
        }
        else {
          Log::e("Cannot unlock SFD1 for vehicle without token");
        }
      }
    }
  }
  FUN_00d2a548(&local_80);
  Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_170);
  std::__ndk1::condition_variable::~condition_variable((condition_variable *)&local_78);
  std::__ndk1::mutex::~mutex((mutex *)&uStack_74);
LAB_01275ff0:
  FUN_00d1e42c(&local_14c);
LAB_01275ff8:
  Result<BytesModel,void>::~Result((Result<BytesModel,void> *)asStack_144);
  FUN_00cbd6dc(local_120);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_118);
  Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_10c);
LAB_01276010:
  Result<UInt8Model,void>::~Result((Result<UInt8Model,void> *)asStack_e8);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_3c);
  }
  return;
}


