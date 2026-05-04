/* VagOperationDelegate::runFreezeFrameDebugCommands @ 0127ae84 */


/* VagOperationDelegate::runFreezeFrameDebugCommands(Ecu*, DebugData&,
   std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::runFreezeFrameDebugCommands
          (VagOperationDelegate *this,Ecu *param_1,DebugData *param_2,shared_ptr *param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  vector *pvVar3;
  vector *pvVar4;
  undefined4 *puVar5;
  uint uVar6;
  vector *pvVar7;
  IllegalArgumentException *this_00;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  char acStack_f0 [12];
  ContainerUtils aCStack_e4 [12];
  vector avStack_d8 [12];
  vector avStack_cc [12];
  vector avStack_c0 [28];
  int *local_a4;
  int local_9c [3];
  vector *local_90;
  vector *pvStack_8c;
  undefined4 local_88;
  int *local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  char acStack_70 [12];
  char acStack_64 [12];
  VagTroubleCode *local_58;
  int iStack_54;
  undefined4 local_50;
  vector avStack_4c [12];
  vector avStack_40 [16];
  int *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  operator____b(acStack_64,0x762389);
  operator____b(acStack_70,0x8f6e21);
  local_78 = 0;
  uStack_74 = 0;
  local_80 = 0;
  uStack_7c = 0;
  local_88 = 0;
  local_84 = (int *)0x0;
  local_90 = (vector *)0x0;
  pvStack_8c = (vector *)0x0;
  if (param_1 != (Ecu *)0x0) {
    local_58 = (VagTroubleCode *)__dynamic_cast(param_1,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0);
    if (local_58 == (VagTroubleCode *)0x0) {
      local_9c[0] = __dynamic_cast(param_1,&Ecu::typeinfo,&VagCanEcu::typeinfo,0);
      if (local_9c[0] == 0) goto LAB_0127b212;
      iVar10 = isPowertrainCanEcu(this,param_1);
      if (iVar10 == 0) {
        FUN_00cdbb80(&uStack_7c,GET_CAN_FAULT_CODES_REQUEST);
        FUN_0126eb2c(avStack_4c,local_9c);
        _ZNSt6__ndk110shared_ptrI7CommandI20GetTroubleCodesModelEEaSB8ne190000I28GetVagCanTroubleCodesCommandTnNS_9enable_ifIXsr17__compatible_withIT_S3_EE5valueEiE4typeELi0EEERS4_ONS0_IS8_EE
                  (&local_84,avStack_4c);
        FUN_0126eb60(avStack_4c);
      }
      else {
        FUN_00cdbb80(&uStack_7c,GET_CAN_FAULT_CODES_POWERTRAIN_REQUEST);
        FUN_0126eae4(avStack_4c,local_9c);
        _ZNSt6__ndk110shared_ptrI7CommandI20GetTroubleCodesModelEEaSB8ne190000I38GetVagCanPowertrainTroubleCodesCommandTnNS_9enable_ifIXsr17__compatible_withIT_S3_EE5valueEiE4typeELi0EEERS4_ONS0_IS8_EE
                  (&local_84,avStack_4c);
        FUN_0126eb18(avStack_4c);
      }
      operator____b((char *)avStack_c0,0xb6056f);
      operator+(avStack_4c,avStack_c0);
      FUN_0127b388(&local_90,avStack_4c,1);
      puVar2 = &stack0x000000b8;
    }
    else {
      FUN_00cdbb80(&uStack_7c,GET_UDS_FAULT_CODES_REQUEST);
      FUN_0126ebcc(avStack_4c,&local_58);
      _ZNSt6__ndk110shared_ptrI7CommandI20GetTroubleCodesModelEEaSB8ne190000I28GetVagUdsTroubleCodesCommandTnNS_9enable_ifIXsr17__compatible_withIT_S3_EE5valueEiE4typeELi0EEERS4_ONS0_IS8_EE
                (&local_84,avStack_4c);
      FUN_0126ec00(avStack_4c);
      operator____b((char *)avStack_c0,0x8050ac);
      operator+(avStack_4c,avStack_c0);
      operator____b((char *)local_9c,0x8050ac);
      operator+(avStack_40,(vector *)local_9c);
      FUN_0127b388(&local_90,avStack_4c,2);
      iVar10 = 0xc;
      do {
        FUN_00cb7f50(avStack_4c + iVar10);
        iVar10 = iVar10 + -0xc;
      } while (iVar10 != -0xc);
      puVar2 = &stack0x00000068;
    }
    FUN_00cb7f50(puVar2 + -0x104);
    FUN_00cb7f50(avStack_c0);
    ByteUtils::getHexString((ByteUtils *)avStack_c0,(vector *)&uStack_7c);
    DebugData::get((Ecu *)avStack_4c,(basic_string *)param_2);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  avStack_c0);
    iVar10 = Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>const,void>
             ::isFail((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>const,void>
                       *)avStack_4c);
    piVar9 = local_84;
    if (iVar10 == 0) {
      ByteUtils::getBytes((ByteUtils *)&local_58,(basic_string *)(*(int *)(*local_30 + 4) + -0xc));
      FUN_00ce2398(local_9c,&local_58,1);
      (**(code **)(*piVar9 + 0x14))(avStack_c0,piVar9,local_9c);
      FUN_00cded68(local_9c);
      FUN_00cb7f50(&local_58);
      iVar10 = Result<GetTroubleCodesModel,void>::isFail
                         ((Result<GetTroubleCodesModel,void> *)avStack_c0);
      if (iVar10 == 0) {
        puVar8 = (undefined4 *)**(undefined4 **)(*local_a4 + 4);
        puVar5 = (undefined4 *)(*(undefined4 **)(*local_a4 + 4))[1];
        do {
          if (puVar8 == puVar5) break;
          local_58 = (VagTroubleCode *)*puVar8;
          iStack_54 = puVar8[1];
          if (iStack_54 != 0) {
            piVar9 = (int *)(iStack_54 + 4);
            do {
              ExclusiveAccess(piVar9);
              bVar1 = (bool)hasExclusiveAccess(piVar9);
            } while (!bVar1);
            *piVar9 = *piVar9 + 1;
          }
          uVar6 = VagTroubleCode::getCodeNum(local_58);
          ByteUtils::getBytesFromInt((ByteUtils *)local_9c,uVar6);
          FUN_0126ebba(&local_58);
          pvVar3 = pvStack_8c;
          pvVar4 = local_90;
          do {
            pvVar7 = pvVar4;
            if (pvVar7 == pvVar3) break;
            local_50 = 0;
            local_58 = (VagTroubleCode *)0x0;
            iStack_54 = 0;
            iVar10 = __dynamic_cast(param_1,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0);
            if (iVar10 == 0) {
              ContainerUtils::subrange<unsigned_char>
                        ((ContainerUtils *)avStack_d8,(vector *)local_9c,2,2);
              operator+(avStack_cc,pvVar7);
              FUN_00cda396(&local_58,avStack_cc);
              FUN_00cb7f50(avStack_cc);
              FUN_00cb7f50(avStack_d8);
            }
            else {
              ContainerUtils::subrange<unsigned_char>(aCStack_e4,(vector *)local_9c,1,3);
              operator+(avStack_d8,pvVar7);
              operator____b(acStack_f0,0x8d8d6b);
              operator+(avStack_cc,avStack_d8);
              FUN_00cda396(&local_58,avStack_cc);
              FUN_00cb7f50(avStack_cc);
              FUN_00cb7f50(acStack_f0);
              FUN_00cb7f50(avStack_d8);
              FUN_00cb7f50(aCStack_e4);
            }
            (**(code **)(*(int *)this + 0x170))(this,param_1,&local_58,1,param_2,param_3);
            iVar10 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
            FUN_00cb7f50(&local_58);
            pvVar4 = pvVar7 + 0xc;
          } while (iVar10 == 0);
          FUN_00cb7f50(local_9c);
          puVar8 = puVar8 + 2;
        } while (pvVar7 == pvVar3);
      }
      Result<GetTroubleCodesModel,void>::~Result((Result<GetTroubleCodesModel,void> *)avStack_c0);
    }
    Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>const,void>
    ::~Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>const,void>
               *)avStack_4c);
    FUN_00cded68(&local_90);
    FUN_011e3ec8(&local_84);
    FUN_00cb7f50(&uStack_7c);
    FUN_00cb7f50(acStack_70);
    FUN_00cb7f50(acStack_64);
    if (__stack_chk_guard == local_28) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  local_58 = (VagTroubleCode *)0x0;
  local_9c[0] = 0;
LAB_0127b212:
  this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
  FUN_00cb4d44(avStack_4c,"runFreezeFrameDebugCommands called with non VagCan or VagUds ECU");
  IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)avStack_4c);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
              IllegalStateException::~IllegalStateException);
}


