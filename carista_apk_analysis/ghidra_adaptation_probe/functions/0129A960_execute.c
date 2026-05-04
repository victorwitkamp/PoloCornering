/* ChangeSettingOperation::execute @ 0129a960 */


/* ChangeSettingOperation::execute() */

void __thiscall ChangeSettingOperation::execute(ChangeSettingOperation *this)

{
  bool bVar1;
  int iVar2;
  VehicleProtocol *pVVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  uint uVar10;
  int *piVar11;
  vector *pvVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  int local_284;
  uint local_280;
  int *local_254 [2];
  basic_string abStack_24c [12];
  basic_string abStack_240 [12];
  basic_string abStack_234 [12];
  basic_string abStack_228 [12];
  basic_string abStack_21c [12];
  basic_string abStack_210 [12];
  basic_string abStack_204 [12];
  basic_string abStack_1f8 [12];
  StringUtils aSStack_1ec [12];
  basic_string abStack_1e0 [12];
  basic_string abStack_1d4 [12];
  basic_string abStack_1c8 [12];
  basic_string abStack_1bc [12];
  basic_string abStack_1b0 [12];
  basic_string abStack_1a4 [12];
  undefined4 local_198 [3];
  int *local_18c;
  undefined4 uStack_188;
  int *local_180;
  undefined4 local_17c;
  undefined4 *local_164;
  shared_ptr asStack_15c [8];
  shared_ptr asStack_154 [8];
  int *local_14c;
  int iStack_148;
  int *local_144 [2];
  StringUtils aSStack_13c [12];
  StringUtils aSStack_130 [12];
  VehicleProtocol aVStack_124 [12];
  OperationDelegate *local_118 [6];
  Param aPStack_100 [24];
  Param aPStack_e8 [24];
  Param aPStack_d0 [24];
  Param aPStack_b8 [24];
  Param aPStack_a0 [24];
  Param aPStack_88 [24];
  Param aPStack_70 [24];
  Param aPStack_58 [24];
  Param aPStack_40 [24];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar2 = Operation::isCanceled((Operation *)this);
  if (iVar2 == 0) {
    (**(code **)(*(int *)this + 0x14))(local_118,this);
    pVVar3 = (VehicleProtocol *)(**(code **)(*(int *)local_118[0] + 0x10))();
    VehicleProtocol::toString(aVStack_124,pVVar3);
    FUN_00d5a8a2(local_118);
    (**(code **)(*(int *)this + 0x14))(&local_180,this);
    (**(code **)(*local_180 + 0x34))(local_118);
    StringUtils::toString(aSStack_130,(shared_ptr *)local_118);
    FUN_00cbba38(local_118);
    FUN_00d5a8a2(&local_180);
    (**(code **)(*(int *)this + 0x14))(&local_180,this);
    (**(code **)(*local_180 + 0x28))(local_118);
    StringUtils::toString(aSStack_13c,(shared_ptr *)local_118);
    FUN_00cbba38((Operation *)local_118);
    FUN_00d5a8a2(&local_180);
    piVar11 = *(int **)(this + 0x2c);
    uVar4 = FUN_013f45d0(*(int *)(this + 0x6c) - *(int *)(this + 0x68),0x14);
    (**(code **)(*piVar11 + 0x24))(local_144,piVar11,uVar4);
    iVar2 = VehicleProtocol::TOYOTA;
    puVar13 = *(undefined4 **)(this + 0x68);
    puVar5 = *(undefined4 **)(this + 0x6c);
    local_284 = 0;
    local_280 = 0;
    do {
      if (puVar13 == puVar5) {
        iVar2 = (**(code **)(**(int **)(this + 0x1c) + 0x28))();
        uVar10 = State::isFatalError(iVar2);
        if (uVar10 != 0) {
          local_284 = iVar2;
        }
        if (((uVar10 | ~local_280) & 1) == 0) {
          iVar2 = (**(code **)(*(int *)App::STORAGE + 0x30))
                            ((int *)App::STORAGE,NUM_SUCCESSFUL_SETTING_CHANGES_KEY);
          if (iVar2 == 0) {
            local_284 = 1;
            (**(code **)(*(int *)App::STORAGE + 0xc))
                      ((int *)App::STORAGE,NUM_SUCCESSFUL_SETTING_CHANGES_KEY,1);
          }
          else {
            iVar2 = (**(code **)(*(int *)App::STORAGE + 0x38))
                              ((int *)App::STORAGE,NUM_SUCCESSFUL_SETTING_CHANGES_KEY);
            (**(code **)(*(int *)App::STORAGE + 0xc))
                      ((int *)App::STORAGE,NUM_SUCCESSFUL_SETTING_CHANGES_KEY,iVar2 + 1);
            local_284 = 1;
          }
        }
        (**(code **)(*(int *)this + 0x5c))(this,local_284);
        break;
      }
      local_14c = (int *)*puVar13;
      iStack_148 = puVar13[1];
      if (iStack_148 != 0) {
        piVar11 = (int *)(iStack_148 + 4);
        do {
          ExclusiveAccess(piVar11);
          bVar1 = (bool)hasExclusiveAccess(piVar11);
        } while (!bVar1);
        *piVar11 = *piVar11 + 1;
      }
      (**(code **)(*local_144[0] + 0x30))(asStack_154,local_144[0],1);
      (**(code **)(*(int *)this + 0x14))((Operation *)local_118,this);
      (**(code **)(*(int *)local_118[0] + 0x1c))(asStack_15c,local_118[0],&local_14c);
      pvVar12 = (vector *)(puVar13 + 2);
      FUN_00d5a8a2((Operation *)local_118);
      piVar11 = (int *)local_14c[0xb];
      if ((piVar11 == (int *)0x0) ||
         (iVar6 = (**(code **)(*piVar11 + 8))(piVar11,pvVar12), iVar6 != 0)) {
        (**(code **)(*(int *)this + 0x14))((Operation *)local_118,this);
        iVar6 = OperationDelegate::changeSetting
                          (local_118[0],(shared_ptr *)&local_14c,pvVar12,asStack_154);
        FUN_00d5a8a2((Operation *)local_118);
        if (iVar6 == -6) {
          (**(code **)(*(int *)this + 0x14))((Operation *)local_118,this);
          iVar7 = (**(code **)(*(int *)local_118[0] + 0x10))();
          FUN_00d5a8a2((Operation *)local_118);
          iVar6 = -6;
          if (iVar7 == iVar2) {
            iVar7 = 3;
            do {
              iVar7 = iVar7 + -1;
              if (iVar7 == 0) {
                if (iVar6 != -6) goto LAB_0129ac6c;
                local_198[0] = 1;
                FUN_01271bd4(&local_18c,local_14c + 4,local_198);
                local_180 = local_18c;
                local_17c = uStack_188;
                local_18c = (int *)0x0;
                uStack_188 = 0;
                Operation::runCommand<EmptyModel>((Operation *)local_118,(shared_ptr *)this);
                FUN_011e4048(&local_180);
                FUN_011e6258(&local_18c);
                ThreadUtils::sleep(5000);
                (**(code **)(*(int *)this + 0x14))(&local_180,this);
                uVar14 = (**(code **)(*local_180 + 0x148))(local_180,&local_14c);
                FUN_00d5a8a2((Result<BytesModel,void> *)&local_180);
                (**(code **)(*(int *)this + 0x14))(&local_18c,this);
                (**(code **)(*local_18c + 0xe4))
                          ((Result<BytesModel,void> *)&local_180,local_18c,(int)uVar14,
                           (int)((ulonglong)uVar14 >> 0x20));
                FUN_00d5a8a2(&local_18c);
                iVar6 = Result<BytesModel,void>::isFatalFail((Result<BytesModel,void> *)&local_180);
                if (iVar6 != 0) {
                  Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_180);
                  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)local_118);
                  goto LAB_0129ab8c;
                }
                iVar6 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_180);
                if (iVar6 != 0) {
                  Log::e("Failed to read value after ECU reset.");
                }
                Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_180);
                Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)local_118);
                iVar6 = -6;
                goto LAB_0129ac6c;
              }
              ThreadUtils::sleep(2000);
              (**(code **)(*(int *)this + 0x14))((Operation *)local_118,this);
              iVar6 = OperationDelegate::changeSetting
                                (local_118[0],(shared_ptr *)&local_14c,pvVar12,asStack_154);
              FUN_00d5a8a2((Operation *)local_118);
            } while (iVar6 != 1);
            iVar6 = 1;
LAB_0129ac6c:
            FUN_00cb4d44((Operation *)local_118,"Retry setting change for Toyota.");
            Operation::sendAutoReport((Operation *)this,iVar6,(basic_string *)local_118);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)local_118);
          }
        }
        (**(code **)(*local_144[0] + 0x2c))();
        piVar11 = (int *)App::ANALYTICS;
        FUN_00cb4d44(&local_18c,"vehicle_setting_write");
        FUN_00cb4d44(abStack_1a4,"protocol");
        Analytics::Event::Param::Param((Param *)local_118,abStack_1a4,(basic_string *)aVStack_124);
        FUN_00cb4d44(abStack_1b0,"chassis_id");
        Analytics::Event::Param::Param(aPStack_100,abStack_1b0,(basic_string *)aSStack_130);
        FUN_00cb4d44(abStack_1bc,"vehicle_model");
        Analytics::Event::Param::Param(aPStack_e8,abStack_1bc,(basic_string *)aSStack_13c);
        FUN_00cb4d44(abStack_1c8,&DAT_0082cf19);
        piVar8 = (int *)(**(code **)(*local_14c + 0x14))();
        (**(code **)(*piVar8 + 0x10))(abStack_1d4);
        Analytics::Event::Param::Param(aPStack_d0,abStack_1c8,abStack_1d4);
        FUN_00cb4d44(abStack_1e0,"ecu_tag");
        StringUtils::toString(aSStack_1ec,asStack_15c);
        Analytics::Event::Param::Param(aPStack_b8,abStack_1e0,(basic_string *)aSStack_1ec);
        FUN_00cb4d44(abStack_1f8,"setting_name");
        pcVar9 = (char *)(**(code **)(*local_14c + 8))();
        Analytics::Event::Param::Param(aPStack_a0,abStack_1f8,pcVar9);
        FUN_00cb4d44(abStack_204,"setting_gist");
        (**(code **)(*local_14c + 0x18))(abStack_210);
        Analytics::Event::Param::Param(aPStack_88,abStack_204,abStack_210);
        FUN_00cb4d44(abStack_21c,"state");
        Analytics::Event::Param::Param(aPStack_70,abStack_21c,iVar6);
        FUN_00cb4d44(abStack_228,"is_experimental");
        uVar4 = (**(code **)(*local_14c + 0x2c))();
        _ZN11StringUtils8toStringIbTnPNSt6__ndk19enable_ifIXaaaaaasr13is_arithmeticIT_EE5valuentsr7is_sameIS3_hEE5valuentsr7is_sameIS3_dEE5valuentsr7is_sameIS3_cEE5valueEvE4typeELPv0EEENS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES3_
                  (abStack_234,uVar4);
        Analytics::Event::Param::Param(aPStack_58,abStack_228,abStack_234);
        FUN_00cb4d44(abStack_240,"is_sfd");
        (**(code **)(*(int *)this + 0x14))(local_254,this);
        (**(code **)(*local_254[0] + 0xd0))(&local_180,local_254[0],&local_14c);
        _ZN11StringUtils8toStringIbTnPNSt6__ndk19enable_ifIXaaaaaasr13is_arithmeticIT_EE5valuentsr7is_sameIS3_hEE5valuentsr7is_sameIS3_dEE5valuentsr7is_sameIS3_cEE5valueEvE4typeELPv0EEENS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES3_
                  (abStack_24c,*(undefined1 *)*local_164);
        Analytics::Event::Param::Param(aPStack_40,abStack_240,abStack_24c);
        FUN_00ce429c(local_198,(Operation *)local_118,10);
        (**(code **)(*piVar11 + 8))(piVar11,&local_18c,local_198);
        FUN_00ce431c(local_198);
        iVar7 = 0xd8;
        do {
          Analytics::Event::Param::~Param((Param *)((Operation *)local_118 + iVar7));
          iVar7 = iVar7 + -0x18;
        } while (iVar7 != -0x18);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_24c);
        Result<bool,void>::~Result((Result<bool,void> *)&local_180);
        FUN_00d5a8a2(local_254);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_240);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_234);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_228);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_21c);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_210);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_204);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_1f8);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)aSStack_1ec);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_1e0);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_1d4);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_1c8);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_1bc);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_1b0);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_1a4);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_18c);
        iVar7 = State::isError(iVar6);
        if (iVar7 == 0) {
          bVar1 = true;
          local_280 = 1;
        }
        else if (iVar6 == -0x18) {
          bVar1 = true;
          local_284 = -0x18;
        }
        else {
          (**(code **)(*(int *)this + 0x5c))(this,iVar6);
          bVar1 = false;
          local_284 = iVar6;
        }
      }
      else {
        (**(code **)(*(int *)this + 0x5c))(this,0xfffffc17);
LAB_0129ab8c:
        bVar1 = false;
      }
      FUN_00cbba38(asStack_15c);
      FUN_011e01a0(asStack_154);
      FUN_00cc67b0(&local_14c);
      puVar13 = puVar13 + 5;
    } while (bVar1);
    FUN_00d2b90c(local_144);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  aSStack_13c);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  aSStack_130);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  aVStack_124);
    if (__stack_chk_guard == local_28) {
      return;
    }
  }
  else if (__stack_chk_guard == local_28) {
                    /* WARNING: Could not recover jumptable at 0x0129a9aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)this + 0x5c))(this,0xfffffc18);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


