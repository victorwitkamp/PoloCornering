/* FUN_0127caa0 @ 0127caa0 */


void FUN_0127caa0(int param_1,undefined4 *param_2,
                 Result<std::__ndk1::unordered_map<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>const,std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>>>,void>
                 *param_3)

{
  int *piVar1;
  VehicleProtocol *pVVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  basic_string abStack_1a8 [12];
  basic_string abStack_19c [12];
  StringUtils aSStack_190 [12];
  basic_string abStack_184 [12];
  StringUtils aSStack_178 [12];
  basic_string abStack_16c [12];
  basic_string abStack_160 [12];
  shared_ptr asStack_154 [12];
  shared_ptr asStack_148 [8];
  basic_string abStack_140 [12];
  basic_string abStack_134 [12];
  basic_string abStack_128 [12];
  StringUtils aSStack_11c [12];
  basic_string abStack_110 [12];
  VehicleProtocol aVStack_104 [12];
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  StringUtils aSStack_ec [12];
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  int *local_d4;
  Param aPStack_d0 [24];
  Param aPStack_b8 [24];
  Param aPStack_a0 [24];
  Param aPStack_88 [24];
  Param aPStack_70 [24];
  Param aPStack_58 [24];
  Param aPStack_40 [24];
  int local_28;
  
  piVar5 = (int *)App::ANALYTICS;
  local_28 = __stack_chk_guard;
  local_d4 = (int *)*param_2;
  piVar3 = *(int **)(param_1 + 8);
  FUN_00cb4d44(&local_e0,"trouble_codes_callback_status");
  FUN_00cb4d44(&uStack_f8,"protocol");
  pVVar2 = (VehicleProtocol *)(**(code **)(*piVar3 + 0x10))(piVar3);
  VehicleProtocol::toString(aVStack_104,pVVar2);
  Analytics::Event::Param::Param(aPStack_d0,(basic_string *)&uStack_f8,(basic_string *)aVStack_104);
  FUN_00cb4d44(abStack_110,"chassis_id");
  (**(code **)(*piVar3 + 0x34))(asStack_154,piVar3);
  StringUtils::toString(aSStack_11c,asStack_154);
  Analytics::Event::Param::Param(aPStack_b8,abStack_110,(basic_string *)aSStack_11c);
  FUN_00cb4d44(abStack_128,&DAT_0082cf19);
  (**(code **)(*local_d4 + 0x10))(abStack_134);
  Analytics::Event::Param::Param(aPStack_a0,abStack_128,abStack_134);
  FUN_00cb4d44(abStack_140,"state");
  Analytics::Event::Param::Param(aPStack_88,abStack_140,**(int **)(param_3 + 0x18));
  FUN_00ce429c(aSStack_ec,aPStack_d0,4);
  (**(code **)(*piVar5 + 8))(piVar5,&local_e0,aSStack_ec);
  FUN_00ce431c(aSStack_ec);
  iVar4 = 0x48;
  do {
    Analytics::Event::Param::~Param(aPStack_d0 + iVar4);
    iVar4 = iVar4 + -0x18;
  } while (iVar4 != -0x18);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_140);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_134);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_128);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                aSStack_11c);
  FUN_00cbba38(asStack_154);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_110);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                aVStack_104);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &uStack_f8);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_e0);
  local_d8 = 0;
  local_e0 = 0;
  uStack_dc = 0;
  if (*(basic_string **)(param_1 + 0x54) == (basic_string *)0x0) {
    FUN_00cb4d44(aSStack_ec,&DAT_0082cf5e);
  }
  else {
    VagVin::getPdx((VagVin *)aPStack_d0,*(basic_string **)(param_1 + 0x54));
    StringUtils::toString(aSStack_ec,(shared_ptr *)aPStack_d0);
    FUN_00cbd6dc(aPStack_d0);
  }
  iVar4 = Result<std::__ndk1::unordered_map<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::hash<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::equal_to<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>const,std::__ndk1::pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>>>,void>
          ::isFail(param_3);
  piVar5 = (int *)App::STRING_MANAGER;
  if (iVar4 == 0) {
    piVar5 = (int *)(**(int **)(param_3 + 0x1c) + 8);
    while( true ) {
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) break;
      iVar4 = FUN_00cdb2f0(piVar5 + 5);
      if ((iVar4 != 0) || (iVar4 = FUN_00cdb2f0(piVar5 + 8), iVar4 != 0)) {
        piVar1 = (int *)App::ANALYTICS;
        FUN_00cb4d44(&uStack_f8,"check_codes_callback_description_missing");
        FUN_00cb4d44(abStack_110,&DAT_0072ff31);
        Analytics::Event::Param::Param(aPStack_d0,abStack_110,(basic_string *)(piVar5 + 2));
        FUN_00cb4d44(aSStack_11c,&DAT_0082cf19);
        (**(code **)(*local_d4 + 0x10))(abStack_128);
        Analytics::Event::Param::Param(aPStack_b8,(basic_string *)aSStack_11c,abStack_128);
        FUN_00cb4d44(abStack_134,"asam_dataset");
        StringUtils::toString
                  ((StringUtils *)abStack_140,(shared_ptr *)(**(int **)(param_1 + 0x4c) + 0x44));
        Analytics::Event::Param::Param(aPStack_a0,abStack_134,abStack_140);
        FUN_00cb4d44(asStack_154,"asam_rev");
        StringUtils::toString
                  ((StringUtils *)abStack_160,(shared_ptr *)(**(int **)(param_1 + 0x4c) + 0x4c));
        Analytics::Event::Param::Param(aPStack_88,(basic_string *)asStack_154,abStack_160);
        FUN_00cb4d44(abStack_16c,&DAT_00bcd7db);
        Analytics::Event::Param::Param(aPStack_70,abStack_16c,(basic_string *)aSStack_ec);
        FUN_00ce429c(aVStack_104,aPStack_d0,5);
        (**(code **)(*piVar1 + 8))(piVar1,&uStack_f8,aVStack_104);
        FUN_00ce431c(aVStack_104);
        iVar4 = 0x60;
        do {
          Analytics::Event::Param::~Param(aPStack_d0 + iVar4);
          iVar4 = iVar4 + -0x18;
        } while (iVar4 != -0x18);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_16c);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_160);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)asStack_154);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_140);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_134);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_128);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)aSStack_11c);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_110);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&uStack_f8);
      }
      uVar6 = FUN_012405ec(piVar3 + 1,&local_d4);
      FUN_0124b388(aPStack_d0,uVar6,(basic_string *)(piVar5 + 2));
    }
    func_0x014284a0(aPStack_d0,piVar3,local_d4,*(undefined4 *)(param_1 + 0x4c),param_1 + 0xc);
    FUN_0124b3c4(&local_e0,aPStack_d0);
    FUN_00ce1dc4(aPStack_d0);
  }
  else {
    uStack_f8 = 0;
    uStack_f4 = 0;
    uStack_f0 = 0;
    if (**(int **)(param_3 + 0x18) != -8) {
      FUN_00cb4d44(aVStack_104,LibStr::no_code_description_available);
      (**(code **)(*piVar5 + 0xc))(aPStack_d0,piVar5,aVStack_104);
      FUN_00cbe908(&uStack_f8,
                   (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *
                   )aPStack_d0);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aPStack_d0);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aVStack_104);
      piVar5 = (int *)App::ANALYTICS;
      FUN_00cb4d44(aVStack_104,"check_codes_callback_description_missing");
      FUN_00cb4d44(aSStack_11c,"protocol");
      pVVar2 = (VehicleProtocol *)(**(code **)(*piVar3 + 0x10))();
      VehicleProtocol::toString((VehicleProtocol *)abStack_128,pVVar2);
      Analytics::Event::Param::Param(aPStack_d0,(basic_string *)aSStack_11c,abStack_128);
      FUN_00cb4d44(abStack_134,"chassis_id");
      (**(code **)(*piVar3 + 0x34))(asStack_148);
      StringUtils::toString((StringUtils *)abStack_140,asStack_148);
      Analytics::Event::Param::Param(aPStack_b8,abStack_134,abStack_140);
      FUN_00cb4d44(asStack_154,&DAT_0082cf19);
      (**(code **)(*local_d4 + 0x10))(abStack_160);
      Analytics::Event::Param::Param(aPStack_a0,(basic_string *)asStack_154,abStack_160);
      FUN_00cb4d44(abStack_16c,"asam_dataset");
      StringUtils::toString(aSStack_178,(shared_ptr *)(**(int **)(param_1 + 0x4c) + 0x44));
      Analytics::Event::Param::Param(aPStack_88,abStack_16c,(basic_string *)aSStack_178);
      FUN_00cb4d44(abStack_184,"asam_rev");
      StringUtils::toString(aSStack_190,(shared_ptr *)(**(int **)(param_1 + 0x4c) + 0x4c));
      Analytics::Event::Param::Param(aPStack_70,abStack_184,(basic_string *)aSStack_190);
      FUN_00cb4d44(abStack_19c,&DAT_00bcd7db);
      Analytics::Event::Param::Param(aPStack_58,abStack_19c,(basic_string *)aSStack_ec);
      FUN_00cb4d44(abStack_1a8,"processing_state");
      Analytics::Event::Param::Param(aPStack_40,abStack_1a8,**(int **)(param_3 + 0x18));
      FUN_00ce429c(abStack_110,aPStack_d0,7);
      (**(code **)(*piVar5 + 8))(piVar5,aVStack_104,abStack_110);
      FUN_00ce431c(abStack_110);
      iVar4 = 0x90;
      do {
        Analytics::Event::Param::~Param(aPStack_d0 + iVar4);
        iVar4 = iVar4 + -0x18;
      } while (iVar4 != -0x18);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_1a8);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_19c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aSStack_190);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_184);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aSStack_178);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_16c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_160);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)asStack_154);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_140);
      FUN_00cbba38(asStack_148);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_134);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_128);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aSStack_11c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aVStack_104);
    }
    OperationDelegate::updateWithErrorDescription
              ((OperationDelegate *)aPStack_d0,(vector *)(param_1 + 0xc),(basic_string *)&uStack_f8)
    ;
    FUN_0124b3c4(&local_e0,aPStack_d0);
    FUN_00ce1dc4(aPStack_d0);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &uStack_f8);
  }
  piVar5 = local_d4;
  uVar6 = **(undefined4 **)(param_3 + 0x18);
  FUN_00cf68dc(aPStack_d0,&local_e0);
  FUN_01249444(param_1 + 0x18,uVar6,piVar5,aPStack_d0);
  FUN_00ce1cf0(aPStack_d0);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                aSStack_ec);
  FUN_00ce1dc4(&local_e0);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


