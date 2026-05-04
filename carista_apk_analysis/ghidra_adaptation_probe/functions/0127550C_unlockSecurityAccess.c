/* VagOperationDelegate::unlockSecurityAccess @ 0127550c */


/* VagOperationDelegate::unlockSecurityAccess(Ecu*, std::__ndk1::vector<unsigned long long,
   std::__ndk1::allocator<unsigned long long> > const&, std::__ndk1::shared_ptr<Progress> const&) */

void VagOperationDelegate::unlockSecurityAccess(Ecu *param_1,vector *param_2,shared_ptr *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 extraout_r1;
  int iVar5;
  __ndk1 a_Stack_10c [12];
  basic_string abStack_100 [12];
  basic_string abStack_f4 [12];
  shared_ptr asStack_e8 [12];
  shared_ptr asStack_dc [8];
  shared_ptr asStack_d4 [12];
  undefined4 local_c8;
  undefined4 uStack_c4;
  Progress aPStack_bc [12];
  int *local_b0;
  undefined4 uStack_ac;
  int *local_a4;
  undefined4 local_a0;
  undefined4 *local_98;
  undefined4 *puStack_94;
  undefined4 local_90;
  vector *local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  Param local_70 [4];
  int *local_6c;
  Param aPStack_58 [24];
  undefined *local_40;
  Ecu *local_3c;
  undefined4 *local_38;
  undefined **local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_90 = 0;
  local_98 = (undefined4 *)0x0;
  puStack_94 = (undefined4 *)0x0;
  local_8c = param_2;
  if (((VagCanEcu::INFOTAINMENT == param_2) || (VagCanEcu::CONTROL_HEAD == param_2)) &&
     (iVar2 = FUN_012759cc(param_3,(undefined4)VagAccessCode::DUMMY_INFOTAINMENT_2G_3G_B8),
     iVar2 != 0)) {
    FUN_012759ec(&local_b0,&local_8c);
    local_a4 = local_b0;
    local_a0 = uStack_ac;
    local_b0 = (int *)0x0;
    uStack_ac = 0;
    Progress::NUL(aPStack_bc);
    OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_88,(shared_ptr *)param_1);
    FUN_011e01a0(aPStack_bc);
    FUN_011e659c(&local_a4);
    FUN_01275a20(&local_b0);
    iVar2 = Result<StringModel,void>::isFail((Result<StringModel,void> *)&local_88);
    if (iVar2 == 0) {
      VagAccessCode::generateMediaCodes((VagAccessCode *)&local_a4,(basic_string *)(*local_6c + 4));
      if (*local_a4 != local_a4[1]) {
        FUN_01275a32(&local_98);
      }
      FUN_00d4dec4(&local_a4);
    }
    Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_88);
    if (iVar2 != 0) goto LAB_0127566a;
  }
  else if (local_8c == VagUdsEcu::INSTRUMENT_CLUSTER) {
    (**(code **)(*(int *)param_1 + 0x18))(asStack_d4);
    StringUtils::toString((StringUtils *)&local_88,asStack_d4);
    iVar2 = FUN_00cd2df8(&local_88,"5G1920741D");
    if (iVar2 == 0) {
      (**(code **)(*(int *)param_1 + 0x18))(asStack_e8,param_1,local_8c);
      StringUtils::toString((StringUtils *)&local_a4,asStack_e8);
      iVar2 = FUN_00cd2df8(&local_a4,"3G0920790E");
      if (iVar2 != 0) {
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_a4);
        FUN_00cbba38(asStack_e8);
        goto LAB_01275612;
      }
      (**(code **)(*(int *)param_1 + 0x18))(abStack_f4,param_1,local_8c);
      StringUtils::toString((StringUtils *)&local_b0,(shared_ptr *)abStack_f4);
      iVar2 = FUN_00cd2df8(&local_b0,"2G0920790A");
      if (iVar2 == 0) {
        (**(code **)(*(int *)param_1 + 0x18))(abStack_100,param_1,local_8c);
        StringUtils::toString((StringUtils *)aPStack_bc,(shared_ptr *)abStack_100);
        iVar2 = FUN_00cd2df8((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                              *)aPStack_bc,"83A920800B");
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)aPStack_bc);
        FUN_00cbba38(abStack_100);
      }
      else {
        iVar2 = 1;
      }
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_b0);
      FUN_00cbba38(abStack_f4);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_a4);
      FUN_00cbba38(asStack_e8);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_88);
      FUN_00cbba38(asStack_d4);
      if (iVar2 == 0) goto LAB_012755ba;
    }
    else {
LAB_01275612:
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_88);
      FUN_00cbba38(asStack_d4);
    }
    puVar3 = (undefined4 *)FUN_011fefc0((undefined4)VagAccessCode::INSTRUMENTS_MQB_ALL,1);
    local_88 = *puVar3;
    uStack_84 = puVar3[1];
    FUN_01275a4a(&local_98,&local_88,1);
  }
  else {
LAB_012755ba:
    FUN_01275a32(&local_98,param_3);
  }
  puVar3 = puStack_94;
  for (puVar4 = local_98; puVar4 != puVar3; puVar4 = puVar4 + 2) {
    local_c8 = *puVar4;
    uStack_c4 = puVar4[1];
    local_38 = &local_c8;
    local_40 = &DAT_014bad94;
    local_3c = param_1;
    local_30 = &local_40;
    iVar2 = (**(code **)(*(int *)param_1 + 0x174))
                      (param_1,local_8c,3,VAG_SECURITY_ACCESS_DATA_RECORD,&local_40);
    FUN_0120c8e6(&local_40);
    piVar1 = (int *)App::ANALYTICS;
    FUN_00cb4d44(&local_a4,"unlock_security_access_vag");
    FUN_00cb4d44(aPStack_bc,"ecu_tag");
    (**(code **)(*(int *)param_1 + 0x18))(asStack_dc,param_1,local_8c);
    StringUtils::toString((StringUtils *)asStack_d4,asStack_dc);
    Analytics::Event::Param::Param
              ((Param *)&local_88,(basic_string *)aPStack_bc,(basic_string *)asStack_d4);
    FUN_00cb4d44(asStack_e8,&DAT_0072ff31);
    std::__ndk1::to_string(CONCAT44(extraout_r1,abStack_f4));
    Analytics::Event::Param::Param(local_70,(basic_string *)asStack_e8,abStack_f4);
    FUN_00cb4d44(abStack_100,"state");
    std::__ndk1::to_string(a_Stack_10c,iVar2);
    Analytics::Event::Param::Param(aPStack_58,abStack_100,(basic_string *)a_Stack_10c);
    FUN_00ce429c(&local_b0,(Param *)&local_88,3);
    (**(code **)(*piVar1 + 8))(piVar1,&local_a4,&local_b0);
    FUN_00ce431c(&local_b0);
    iVar5 = 0x30;
    do {
      Analytics::Event::Param::~Param((Param *)&local_88 + iVar5);
      iVar5 = iVar5 + -0x18;
    } while (iVar5 != -0x18);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  a_Stack_10c);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  abStack_100);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  abStack_f4);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  asStack_e8);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  asStack_d4);
    FUN_00cbba38(asStack_dc);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  aPStack_bc);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_a4);
    iVar5 = State::isFatalError(iVar2);
    if ((iVar5 != 0) || (iVar2 == 1)) break;
  }
LAB_0127566a:
  FUN_00cced34(&local_98);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}


