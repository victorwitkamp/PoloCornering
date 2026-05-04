/* VagOperationDelegate::isSfd2ProtectedSetting @ 0126ffe4 */


/* VagOperationDelegate::isSfd2ProtectedSetting(std::__ndk1::shared_ptr<Setting> const&,
   std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::isSfd2ProtectedSetting
          (VagOperationDelegate *this,shared_ptr *param_1,shared_ptr *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  IllegalStateException *this_00;
  basic_string abStack_c4 [12];
  basic_string abStack_b8 [12];
  basic_string abStack_ac [12];
  basic_string abStack_a0 [12];
  undefined1 auStack_94 [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_88 [12];
  Result<VagEcuInfo,void> aRStack_7c [24];
  int *local_64;
  int *local_60;
  Param local_58 [48];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((*(int *)(*(int *)param_2 + 0x10) == 0) ||
     (piVar2 = (int *)__dynamic_cast(*(int *)(*(int *)param_2 + 0x10),&Ecu::typeinfo,
                                     &VagUdsEcu::typeinfo,0), piVar2 == (int *)0x0)) {
    local_58[0] = (Param)0x0;
    Result<bool,void>::done<bool>((type *)this);
  }
  else {
    (**(code **)(*(int *)param_1 + 0x194))(aRStack_7c,param_1,piVar2,0x200,0);
    iVar3 = Result<VagEcuInfo,void>::isFail(aRStack_7c);
    piVar1 = (int *)App::ANALYTICS;
    if (iVar3 == 0) {
      if (*(__hash_table<unsigned_short,std::__ndk1::hash<unsigned_short>,std::__ndk1::equal_to<unsigned_short>,std::__ndk1::allocator<unsigned_short>>
            **)(*local_60 + 0x5c) ==
          (__hash_table<unsigned_short,std::__ndk1::hash<unsigned_short>,std::__ndk1::equal_to<unsigned_short>,std::__ndk1::allocator<unsigned_short>>
           *)0x0) {
        this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
        (**(code **)(*piVar2 + 0x10))(abStack_88,piVar2);
        FUN_00cbe7e4(local_58,
                     "sfd2ProtectedSettings is null despite successful ecuInfoResult for ECU: ",
                     abStack_88);
        IllegalStateException::IllegalStateException(this_00,(basic_string *)local_58);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(this_00,&IllegalStateException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      uVar4 = std::__ndk1::
              __hash_table<unsigned_short,std::__ndk1::hash<unsigned_short>,std::__ndk1::equal_to<unsigned_short>,std::__ndk1::allocator<unsigned_short>>
              ::__count_unique<unsigned_short>
                        (*(__hash_table<unsigned_short,std::__ndk1::hash<unsigned_short>,std::__ndk1::equal_to<unsigned_short>,std::__ndk1::allocator<unsigned_short>>
                           **)(*local_60 + 0x5c),(ushort *)(*(int *)param_2 + 0x14));
      piVar1 = (int *)App::ANALYTICS;
      if (uVar4 == 0) {
        local_58[0] = (Param)0x0;
        Result<bool,void>::done<bool>((type *)this);
      }
      else {
        if (param_1[0x141] != (shared_ptr)0x3) {
          FUN_00cb4d44(abStack_88,"vag_not_marked_as_sfd2");
          FUN_00cb4d44(abStack_a0,&DAT_0082cf19);
          (**(code **)(*piVar2 + 0x10))(abStack_ac,piVar2);
          iVar3 = Analytics::Event::Param::Param(local_58,abStack_a0,abStack_ac);
          FUN_00cb4d44(abStack_b8,"security_type");
          StringUtils::toString(abStack_c4,param_1[0x141]);
          Analytics::Event::Param::Param((Param *)(iVar3 + 0x18),abStack_b8,abStack_c4);
          FUN_00ce429c(auStack_94,local_58,2);
          (**(code **)(*piVar1 + 8))(piVar1,abStack_88,auStack_94);
          FUN_00ce431c(auStack_94);
          iVar3 = 0x18;
          do {
            Analytics::Event::Param::~Param(local_58 + iVar3);
            iVar3 = iVar3 + -0x18;
          } while (iVar3 != -0x18);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_c4);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_b8);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_ac);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_a0);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string(abStack_88);
          param_1[0x141] = (shared_ptr)0x3;
        }
        local_58[0] = (Param)0x1;
        Result<bool,void>::done<bool>((type *)this);
      }
    }
    else {
      FUN_00cb4d44(abStack_88,"vag_get_sfd2_settings_failed");
      FUN_00cb4d44(abStack_a0,&DAT_0082cf19);
      (**(code **)(*piVar2 + 0x10))(abStack_ac,piVar2);
      iVar3 = Analytics::Event::Param::Param(local_58,abStack_a0,abStack_ac);
      FUN_00cb4d44(abStack_b8,"state");
      Analytics::Event::Param::Param((Param *)(iVar3 + 0x18),abStack_b8,*local_64);
      FUN_00ce429c(auStack_94,local_58,2);
      (**(code **)(*piVar1 + 8))(piVar1,abStack_88,auStack_94);
      FUN_00ce431c(auStack_94);
      iVar3 = 0x18;
      do {
        Analytics::Event::Param::~Param(local_58 + iVar3);
        iVar3 = iVar3 + -0x18;
      } while (iVar3 != -0x18);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_b8);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_ac);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_a0);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string(abStack_88);
      Result<VagEcuInfo,void>::stateAs<bool,void>();
    }
    Result<VagEcuInfo,void>::~Result(aRStack_7c);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


