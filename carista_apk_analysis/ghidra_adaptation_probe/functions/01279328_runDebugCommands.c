/* VagOperationDelegate::runDebugCommands @ 01279328 */


/* VagOperationDelegate::runDebugCommands(Ecu*, DebugData&, std::__ndk1::shared_ptr<Progress>
   const&) */

void __thiscall
VagOperationDelegate::runDebugCommands
          (VagOperationDelegate *this,Ecu *param_1,DebugData *param_2,shared_ptr *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  bool bVar8;
  Ecu *pEVar9;
  undefined4 uVar10;
  vector *pvVar11;
  int iVar12;
  char *pcVar13;
  undefined1 *puVar14;
  uchar *puVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int *piVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  bool bVar23;
  undefined8 uVar24;
  undefined4 local_f8 [3];
  undefined1 *local_ec;
  undefined1 *puStack_e8;
  undefined4 local_c8;
  undefined1 *local_c4;
  int local_c0;
  undefined4 local_a4 [3];
  undefined4 local_98;
  undefined1 *local_94;
  int local_90;
  int *local_7c;
  Result<BytesListModel,void> aRStack_74 [24];
  int *local_5c;
  int *local_58;
  int local_50 [3];
  int local_44;
  int iStack_40;
  Ecu *local_38;
  ByteUtils aBStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_38 = param_1;
  uVar10 = (**(code **)(*(int *)this + 0x4c))(this);
  FUN_00ce0728(&local_44,uVar10);
  pvVar11 = (vector *)(**(code **)(*(int *)this + 0x50))(this,param_1);
  ContainerUtils::addAll<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
            ((vector *)&local_44,pvVar11);
  if (local_38 == (Ecu *)0x0) {
    iVar12 = 0;
  }
  else {
    iVar12 = __dynamic_cast(local_38,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0);
  }
  bVar23 = iVar12 != 0;
  bVar8 = false;
  for (iVar12 = local_44; iVar12 != iStack_40; iVar12 = iVar12 + 0xc) {
    FUN_00cd5ef0((vector *)local_50);
    pcVar13 = (char *)FUN_00cdfbb0((vector *)local_50,0);
    cVar1 = *pcVar13;
    pcVar13 = (char *)FUN_00cdfbb0((vector *)local_50,0);
    cVar2 = *pcVar13;
    pcVar13 = (char *)FUN_00cdfbb0((vector *)local_50,0);
    cVar3 = *pcVar13;
    pcVar13 = (char *)FUN_00cdeb2c(ADAPT,0);
    cVar5 = *pcVar13;
    pcVar13 = (char *)FUN_00cdfbb0((vector *)local_50,0);
    cVar6 = *pcVar13;
    pcVar13 = (char *)FUN_00cdeb2c(LONGADAPT,0);
    if ((bool)(cVar1 == '\x1a' & bVar23)) {
      Result<BytesListModel,void>::Result(aRStack_74);
      bVar23 = true;
    }
    else {
      cVar7 = *pcVar13;
      Result<BytesListModel,void>::Result(aRStack_74);
      pEVar9 = local_38;
      if ((bool)(cVar2 == '\"' & bVar8)) {
        bVar8 = true;
      }
      else if (cVar3 == cVar5 || cVar6 == cVar7) {
        puVar14 = (undefined1 *)FUN_00cdfbb0((vector *)local_50,1);
        uVar24 = (**(code **)(*(int *)this + 0x17c))(this,cVar3 != cVar5,pEVar9,*puVar14);
        (**(code **)(*(int *)this + 0x1a4))
                  (&local_98,this,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
        if (cVar3 == cVar5) {
          puVar15 = (uchar *)FUN_00cdfbb0((vector *)local_50,1);
          ByteUtils::getHexString((ByteUtils *)&local_c8,*puVar15);
          FUN_00d55d84(local_a4,ADAPT_STR,(ByteUtils *)&local_c8);
        }
        else {
          puVar15 = (uchar *)FUN_00cdfbb0((vector *)local_50,1);
          ByteUtils::getHexString((ByteUtils *)&local_c8,*puVar15);
          FUN_00d55d84(local_a4,LONGADAPT_STR,(ByteUtils *)&local_c8);
        }
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_c8);
        iVar16 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
        if (iVar16 == 0) {
          Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
          ::Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                    *)&local_c8);
          iVar17 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_98);
          if (iVar17 == 0) {
            ByteUtils::getHexString(aBStack_34,(vector *)(*local_7c + 4));
            FUN_00d22d0c(local_f8,aBStack_34,1);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::
            done<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>>
                      ((type *)&local_ec);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::operator=((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                         *)&local_c8,(Result *)&local_ec);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::~Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                       *)&local_ec);
            FUN_00cbe2dc(local_f8);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)aBStack_34);
          }
          else {
            Result<BytesModel,void>::
            stateAs<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                      ();
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::operator=((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                         *)&local_c8,(Result *)&local_ec);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::~Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                       *)&local_ec);
          }
          DebugData::addResult(param_2,local_38,(basic_string *)local_a4,(Result *)&local_c8);
          Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
          ::~Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                     *)&local_c8);
        }
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)local_a4);
        Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_98);
        if (iVar16 != 0) {
LAB_012797a4:
          Result<BytesListModel,void>::~Result(aRStack_74);
          FUN_00cb7f50(local_50);
          goto LAB_01279b92;
        }
      }
      else {
        local_a4[0] = 1;
        if (cVar1 == '\x1a') {
          local_a4[0] = 5;
        }
        FUN_01279d30(&local_ec,&local_38,(vector *)local_50,local_a4);
        local_c8 = local_ec;
        local_c4 = puStack_e8;
        local_ec = (undefined1 *)0x0;
        puStack_e8 = (undefined1 *)0x0;
        OperationDelegate::runDebugCommand<BytesListModel>
                  ((shared_ptr *)&local_98,(DebugData *)this,(shared_ptr *)&local_c8);
        Result<BytesListModel,void>::operator=(aRStack_74,(Result *)&local_98);
        Result<BytesListModel,void>::~Result((Result<BytesListModel,void> *)&local_98);
        FUN_00d2b5d4((shared_ptr *)&local_c8);
        FUN_00d2b5e6(&local_ec);
        iVar16 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
        if (iVar16 != 0) goto LAB_012797a4;
        if (*local_5c == 1) {
          piVar20 = (int *)(*local_58 + 4);
          iVar16 = FUN_013f45d0(*(int *)(*local_58 + 8) - *piVar20,0xc);
          pvVar11 = (vector *)FUN_00d08400(piVar20,iVar16 + -1);
          iVar16 = BaseCommand::isPositiveResponse((vector *)local_50,pvVar11,1);
          if (iVar16 != 0) {
            bVar23 = (bool)(bVar23 | cVar2 == '\"');
            bVar8 = (bool)(bVar8 | cVar1 == '\x1a');
          }
        }
      }
    }
    Result<BytesListModel,void>::~Result(aRStack_74);
    FUN_00cb7f50((vector *)local_50);
  }
  if (!bVar8) {
    FUN_012784e8(&local_c8,&local_38);
    local_98 = local_c8;
    local_94 = local_c4;
    local_c8 = (undefined1 *)0x0;
    local_c4 = (undefined1 *)0x0;
    OperationDelegate::runDebugCommand<BytesModel>
              ((shared_ptr *)aRStack_74,(DebugData *)this,(shared_ptr *)&local_98);
    FUN_011e4f74(&local_98);
    FUN_01278562(&local_c8);
    iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
    if (iVar12 == 0) {
      iVar12 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)aRStack_74);
      if (iVar12 == 0) {
        FUN_00cd5ef0(&local_98,*local_58 + 4);
        puVar14 = local_94;
        puVar22 = local_98;
        do {
          puVar21 = puVar22;
          if (puVar21 == puVar14) {
            bVar23 = false;
            goto LAB_012797b4;
          }
          uVar4 = *puVar21;
          uVar10 = (**(code **)(*(int *)this + 0x1d0))(this,uVar4);
          uVar18 = (**(code **)(*(int *)this + 0x1d8))(this,uVar4);
          uVar19 = (**(code **)(*(int *)this + 0x1d4))(this,uVar4);
          (**(code **)(*(int *)this + 0x200))(this,local_38,uVar10,uVar18,uVar19,param_2,param_3);
          iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
          puVar22 = puVar21 + 1;
        } while (iVar12 == 0);
        bVar23 = true;
LAB_012797b4:
        FUN_00cb7f50(&local_98);
        if (puVar21 != puVar14) goto LAB_012798c8;
      }
      else {
        (**(code **)(*(int *)local_38 + 0x10))(&local_98);
        if (((uint)local_98 & 1) == 0) {
          local_90 = (int)&local_98 + 1;
        }
        Log::d("GetSubmoduleIdsCommand failed for ECU: %s",local_90);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_98);
      }
      FUN_0127851c(&local_ec,&local_38);
      local_c8 = local_ec;
      local_c4 = puStack_e8;
      local_ec = (undefined1 *)0x0;
      puStack_e8 = (undefined1 *)0x0;
      OperationDelegate::runDebugCommand<BytesModel>
                ((shared_ptr *)&local_98,(DebugData *)this,(shared_ptr *)&local_c8);
      FUN_011e4f74(&local_c8);
      FUN_01278550(&local_ec);
      iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
      if (iVar12 == 0) {
        iVar12 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_98);
        if (iVar12 == 0) {
          FUN_00cd5ef0(&local_c8,*local_7c + 4);
          puVar14 = local_c4;
          puVar22 = local_c8;
          do {
            if (puVar22 == puVar14) {
              bVar23 = false;
              goto LAB_012798ba;
            }
            uVar4 = *puVar22;
            uVar10 = (**(code **)(*(int *)this + 0x1dc))(this,uVar4);
            uVar18 = (**(code **)(*(int *)this + 0x1e4))(this,uVar4);
            uVar19 = (**(code **)(*(int *)this + 0x1e8))(this,uVar4);
            (**(code **)(*(int *)this + 0x200))(this,local_38,uVar10,uVar18,uVar19,param_2,param_3);
            iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
            puVar22 = puVar22 + 1;
          } while (iVar12 == 0);
          bVar23 = true;
LAB_012798ba:
          FUN_00cb7f50(&local_c8);
        }
        else {
          (**(code **)(*(int *)local_38 + 0x10))(&local_c8);
          if (((uint)local_c8 & 1) == 0) {
            local_c0 = (int)&local_c8 + 1;
          }
          Log::d("GetSubmoduleIdsOverUdsCommand failed for ECU: %s",local_c0);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_c8);
          bVar23 = false;
        }
      }
      else {
        bVar23 = true;
      }
      Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_98);
    }
    else {
      bVar23 = true;
    }
LAB_012798c8:
    Result<BytesModel,void>::~Result((Result<BytesModel,void> *)aRStack_74);
    if (bVar23) goto LAB_01279b92;
  }
  (**(code **)(*(int *)this + 0x204))(this,local_38,param_2,param_3);
  iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
  if (iVar12 != 0) goto LAB_01279b92;
  (**(code **)(*(int *)this + 0x20c))(this,local_38,param_2,param_3);
  iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
  if (iVar12 != 0) goto LAB_01279b92;
  (**(code **)(*(int *)this + 0x210))(this,local_38,param_2,param_3);
  iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
  if (iVar12 != 0) goto LAB_01279b92;
  if (local_38 == VagUdsEcu::INFOTAINMENT) {
    local_ec = (undefined1 *)CONCAT31(local_ec._1_3_,3);
    FUN_01213abc(&local_c8,&local_38,&local_ec);
    local_98 = local_c8;
    local_94 = local_c4;
    local_c8 = (undefined1 *)0x0;
    local_c4 = (undefined1 *)0x0;
    OperationDelegate::runCommand<EmptyModel>((shared_ptr *)aRStack_74,(shared_ptr *)this);
    FUN_011e4048(&local_98);
    FUN_011ff7b8(&local_c8);
    iVar12 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)aRStack_74);
    if (iVar12 == 0) {
      iVar12 = (**(code **)(*(int *)this + 0x128))
                         (this,local_38,(undefined4)VagAccessCode::INFOTAINMENT_MK7,param_3);
      iVar12 = State::isError(iVar12);
      if (iVar12 != 0) goto LAB_012799c0;
      local_50[0] = CONCAT31(local_50[0]._1_3_,0x40);
      FUN_01213abc(&local_ec,&local_38,local_50);
      local_c8 = local_ec;
      local_c4 = puStack_e8;
      local_ec = (undefined1 *)0x0;
      puStack_e8 = (undefined1 *)0x0;
      OperationDelegate::runCommand<EmptyModel>((shared_ptr *)&local_98,(shared_ptr *)this);
      Result<EmptyModel,void>::operator=((Result<EmptyModel,void> *)aRStack_74,(Result *)&local_98);
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_98);
      FUN_011e4048(&local_c8);
      FUN_011ff7b8(&local_ec);
      iVar12 = (**(code **)(*(int *)this + 0x128))
                         (this,local_38,(undefined4)VagAccessCode::INFOTAINMENT_MK7,param_3);
      iVar12 = State::isError(iVar12);
      bVar23 = false;
      if (iVar12 == 0) {
        OperationDelegate::runDebugReadEcuDataByMemoryAddress
                  ((Ecu *)this,(uint)local_38,3,0x240,0x1e,param_2,param_3);
        iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
        if (iVar12 == 0) {
          bVar23 = true;
        }
      }
    }
    else {
LAB_012799c0:
      bVar23 = false;
    }
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)aRStack_74);
    if (!bVar23) goto LAB_01279b92;
  }
  if ((local_38 != (Ecu *)0x0) &&
     (local_50[0] = __dynamic_cast(local_38,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0), local_50[0] != 0
     )) {
    FUN_0127624c(&local_c8,local_50);
    local_98 = local_c8;
    local_94 = local_c4;
    local_c8 = (undefined1 *)0x0;
    local_c4 = (undefined1 *)0x0;
    OperationDelegate::runCommand<UInt8Model>((shared_ptr *)aRStack_74,(shared_ptr *)this);
    FUN_0121d0ec(&local_98);
    FUN_01276280(&local_c8);
    iVar12 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
    if ((iVar12 == 0) && (*local_5c == 1)) {
      local_a4[0] = 1;
      local_f8[0] = 0xc008;
      operator____b((char *)&local_98,0x8d8d35);
      FUN_00cbd868(&local_ec,&local_98);
      FUN_01279d6c(&local_c8,local_50,local_a4,local_f8,&local_ec);
      FUN_00cbd77c(&local_ec);
      FUN_00cb7f50(&local_98);
      local_ec = local_c8;
      puStack_e8 = local_c4;
      if (local_c4 != (undefined1 *)0x0) {
        piVar20 = (int *)(local_c4 + 4);
        do {
          ExclusiveAccess(piVar20);
          bVar23 = (bool)hasExclusiveAccess(piVar20);
        } while (!bVar23);
        *piVar20 = *piVar20 + 1;
      }
      OperationDelegate::runDebugCommand<EmptyModel>
                ((shared_ptr *)&local_98,(DebugData *)this,(shared_ptr *)&local_ec);
      FUN_011e4048(&local_ec);
      State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
      Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)&local_98);
      FUN_011ff92c(&local_c8);
    }
    Result<UInt8Model,void>::~Result((Result<UInt8Model,void> *)aRStack_74);
  }
LAB_01279b92:
  FUN_00cded68(&local_44);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}


