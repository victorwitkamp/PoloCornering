/* VagOperationDelegate::onCommandFailure @ 01279e50 */


/* VagOperationDelegate::onCommandFailure(Ecu*, int) */

void __thiscall
VagOperationDelegate::onCommandFailure(VagOperationDelegate *this,Ecu *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  Ecu *pEVar3;
  shared_ptr asStack_d0 [8];
  StringUtils aSStack_c8 [12];
  basic_string abStack_bc [12];
  shared_ptr asStack_b0 [8];
  Vin aVStack_a8 [12];
  basic_string abStack_9c [12];
  undefined1 auStack_90 [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_84 [12];
  int local_78;
  int iStack_74;
  undefined4 *local_5c;
  int local_54 [7];
  undefined4 *local_38;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if ((param_2 == -5) && (VagCanEcu::ENGINE == param_1)) {
    iVar2 = isUdsOnlyChassisId(this);
    if (iVar2 == 0) {
      (**(code **)(*(int *)this + 0x14))((Result<EcuList_const,void> *)local_54,this,0);
      iVar2 = Result<EcuList_const,void>::isFail((Result<EcuList_const,void> *)local_54);
      if (iVar2 == 0) {
        iVar2 = EcuList::size((EcuList *)*local_38);
        VagEcu::values((VagEcu *)&local_78);
        if (iVar2 == iStack_74 - local_78 >> 2) {
          FUN_01114b98(&local_78);
        }
        else {
          iVar2 = EcuList::contains((EcuList *)*local_38,VagEcu::ENGINE);
          FUN_01114b98(&local_78);
          if (iVar2 != 0) {
            Log::w("TP2.0 ENGINE not responding. Retrying...");
            ThreadUtils::sleep(2000);
          }
        }
      }
      Result<EcuList_const,void>::~Result((Result<EcuList_const,void> *)local_54);
    }
  }
  else if (param_2 == -0x1f) {
    (**(code **)(*(int *)this + 0xd4))((Result<bool,void> *)local_54,this,param_1);
    iVar2 = Result<bool,void>::isFail((Result<bool,void> *)local_54);
    if (((iVar2 == 0) && (*(char *)*local_38 != '\0')) &&
       (*(char *)(*(int *)(this + 0x18) + 0x60) != '\0')) {
      Progress::NUL((Progress *)&local_78);
      iVar2 = (**(code **)(*(int *)this + 300))(this,param_1,&local_78);
      FUN_011e01a0(&local_78);
      if (iVar2 == 1) {
        Log::d("SFD1 unlocked successfully. Retrying to read value");
      }
      else {
        Log::w("Failed unlocking SFD1.");
      }
    }
    else {
      Log::d("ECU is not SFD1 protected.");
    }
    Result<bool,void>::~Result((Result<bool,void> *)local_54);
  }
  else if (((param_2 == -0xb) && (VagUdsEcu::CAN_GATEWAY != param_1)) &&
          (VagCanEcu::CAN_GATEWAY != param_1)) {
    (**(code **)(*(int *)this + 0x14))(&local_78,this,0);
    pEVar3 = (Ecu *)VagEcu::getEquivalent(param_1);
    iVar2 = Result<EcuList_const,void>::isFail((Result<EcuList_const,void> *)&local_78);
    if (iVar2 == 0) {
      iVar2 = EcuList::size((EcuList *)*local_5c);
      VagEcu::values((VagEcu *)local_54);
      if (iVar2 == local_54[1] - local_54[0] >> 2) {
        FUN_01114b98(local_54);
      }
      else {
        iVar2 = EcuList::contains((EcuList *)*local_5c,pEVar3);
        FUN_01114b98(local_54);
        if (((iVar2 != 0) && (this[0x140] == (VagOperationDelegate)0x0)) &&
           (iVar2 = checkHoodClosed(this), iVar2 == -0x2a)) {
          Log::w("Ecu is not responding because hood is closed");
          piVar1 = (int *)App::ANALYTICS;
          FUN_00cb4d44(abStack_84,"vag_command_no_data_hood_closed");
          FUN_00cb4d44(abStack_9c,&DAT_00b60b81);
          (**(code **)(*(int *)this + 0x20))(asStack_b0,this);
          Vin::getObfuscatedVin(aVStack_a8,asStack_b0);
          iVar2 = Analytics::Event::Param::Param
                            ((Param *)local_54,abStack_9c,(basic_string *)aVStack_a8);
          FUN_00cb4d44(abStack_bc,"vehicle_name");
          (**(code **)(*(int *)this + 0x28))(asStack_d0,this);
          StringUtils::toString(aSStack_c8,asStack_d0);
          Analytics::Event::Param::Param
                    ((Param *)(iVar2 + 0x18),abStack_bc,(basic_string *)aSStack_c8);
          FUN_00ce429c(auStack_90,local_54,2);
          (**(code **)(*piVar1 + 8))(piVar1,abStack_84,auStack_90);
          FUN_00ce431c(auStack_90);
          iVar2 = 0x18;
          do {
            Analytics::Event::Param::~Param((Param *)((int)local_54 + iVar2));
            iVar2 = iVar2 + -0x18;
          } while (iVar2 != -0x18);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)aSStack_c8);
          FUN_00cbba38(asStack_d0);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_bc);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)aVStack_a8);
          FUN_00cbba38(asStack_b0);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_9c);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string(abStack_84);
          this[0x140] = (VagOperationDelegate)0x1;
        }
      }
    }
    Result<EcuList_const,void>::~Result((Result<EcuList_const,void> *)&local_78);
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_24);
}


