/* VagOperationDelegate::readVagEcuInfoWithUdsCommands @ 012772bc */


/* VagOperationDelegate::readVagEcuInfoWithUdsCommands(Ecu*, unsigned int, unsigned int) */

void VagOperationDelegate::readVagEcuInfoWithUdsCommands(Ecu *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint in_r3;
  uint uVar4;
  uint in_stack_00000000;
  undefined4 local_1f4;
  undefined4 uStack_1f0;
  undefined1 local_1e9;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined4 local_1e0;
  undefined4 uStack_1dc;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined4 local_1c8;
  undefined4 uStack_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 uStack_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  int iStack_1a8;
  undefined *local_1a4;
  int iStack_1a0;
  undefined4 local_19c;
  undefined4 uStack_198;
  int *local_184;
  shared_ptr *local_180;
  undefined4 local_178;
  undefined4 local_174;
  int *local_160;
  int *local_15c;
  undefined4 local_154;
  undefined4 local_150;
  int *local_13c;
  int *local_138;
  undefined4 local_130;
  undefined4 local_12c;
  int *local_118;
  int *local_114;
  int local_10c;
  undefined4 local_108;
  undefined4 local_104;
  int *local_f0;
  undefined4 local_e4;
  undefined4 local_e0;
  int *local_cc;
  int *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  int *local_a8;
  int *local_a4;
  undefined4 local_9c;
  undefined4 local_98;
  int *local_84;
  int *local_80;
  shared_ptr asStack_78 [24];
  int *local_60;
  int *local_5c;
  Result<StringModel,void> aRStack_54 [24];
  int *local_3c;
  int *local_38;
  uint local_30;
  undefined *local_2c;
  int local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_30 = param_3;
  Result<StringModel,void>::Result(aRStack_54,0);
  uVar4 = in_stack_00000000 | in_r3;
  if ((uVar4 & 1) != 0) {
    local_108 = CONCAT22(local_108._2_2_,0xf187);
    FUN_01277b20(&local_c0,&local_30,&local_108);
    local_9c = local_c0;
    local_98 = local_bc;
    local_c0 = 0;
    local_bc = 0;
    Progress::NUL((Progress *)&local_e4);
    OperationDelegate::runCommand<StringModel>(asStack_78,(shared_ptr *)param_2);
    Result<StringModel,void>::operator=(aRStack_54,(Result *)asStack_78);
    Result<StringModel,void>::~Result((Result<StringModel,void> *)asStack_78);
    FUN_011e01a0(&local_e4);
    FUN_011e659c(&local_9c);
    FUN_01228564(&local_c0);
    bVar1 = failedFatallyOrWhenRequired<StringModel>
                      ((VagOperationDelegate *)param_2,(Result *)aRStack_54,in_r3,1);
    if (bVar1) {
      Result<StringModel,void>::stateAs<VagEcuInfo,void>();
      goto LAB_01277968;
    }
  }
  Result<StringModel,void>::Result((Result<StringModel,void> *)asStack_78,0);
  if ((int)(uVar4 << 0x1d) < 0) {
    FUN_01277b98(&local_e4,&local_30);
    local_c0 = local_e4;
    local_bc = local_e0;
    local_e4 = 0;
    local_e0 = 0;
    Progress::NUL((Progress *)&local_108);
    OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_9c,(shared_ptr *)param_2);
    Result<StringModel,void>::operator=((Result<StringModel,void> *)asStack_78,(Result *)&local_9c);
    Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_9c);
    FUN_011e01a0(&local_108);
    FUN_011e659c(&local_c0);
    FUN_01277bcc(&local_e4);
    bVar1 = failedFatallyOrWhenRequired<StringModel>
                      ((VagOperationDelegate *)param_2,(Result *)asStack_78,in_r3,4);
    if (!bVar1) goto LAB_012773cc;
    Result<StringModel,void>::stateAs<VagEcuInfo,void>();
  }
  else {
LAB_012773cc:
    Result<StringModel,void>::Result((Result<StringModel,void> *)&local_9c,0);
    if ((int)(uVar4 << 0x1a) < 0) {
      FUN_01277be0(&local_108,&local_30);
      local_e4 = local_108;
      local_e0 = local_104;
      local_108 = 0;
      local_104 = 0;
      Progress::NUL((Progress *)&local_130);
      OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_c0,(shared_ptr *)param_2);
      Result<StringModel,void>::operator=((Result<StringModel,void> *)&local_9c,(Result *)&local_c0)
      ;
      Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_c0);
      FUN_011e01a0(&local_130);
      FUN_011e659c(&local_e4);
      FUN_01277c14(&local_108);
      bVar1 = failedFatallyOrWhenRequired<StringModel>
                        ((VagOperationDelegate *)param_2,(Result *)&local_9c,in_r3,0x20);
      if (!bVar1) goto LAB_0127743c;
      Result<StringModel,void>::stateAs<VagEcuInfo,void>();
    }
    else {
LAB_0127743c:
      Result<StringModel,void>::Result((Result<StringModel,void> *)&local_c0,0);
      if ((int)(uVar4 << 0x19) < 0) {
        FUN_01277c28(&local_130,&local_30);
        local_108 = local_130;
        local_104 = local_12c;
        local_130 = 0;
        local_12c = 0;
        Progress::NUL((Progress *)&local_154);
        OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_e4,(shared_ptr *)param_2);
        Result<StringModel,void>::operator=
                  ((Result<StringModel,void> *)&local_c0,(Result *)&local_e4);
        Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_e4);
        FUN_011e01a0(&local_154);
        FUN_011e659c(&local_108);
        FUN_01277c5c(&local_130);
        bVar1 = failedFatallyOrWhenRequired<StringModel>
                          ((VagOperationDelegate *)param_2,(Result *)&local_c0,in_r3,0x40);
        if (!bVar1) goto LAB_012774ac;
        Result<StringModel,void>::stateAs<VagEcuInfo,void>();
      }
      else {
LAB_012774ac:
        Result<StringModel,void>::Result((Result<StringModel,void> *)&local_e4,0);
        if ((int)(uVar4 << 0x18) < 0) {
          FUN_01277c70(&local_154,&local_30);
          local_130 = local_154;
          local_12c = local_150;
          local_154 = 0;
          local_150 = 0;
          Progress::NUL((Progress *)&local_178);
          OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_108,(shared_ptr *)param_2)
          ;
          Result<StringModel,void>::operator=
                    ((Result<StringModel,void> *)&local_e4,(Result *)&local_108);
          Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_108);
          FUN_011e01a0(&local_178);
          FUN_011e659c(&local_130);
          FUN_01277ca4(&local_154);
          bVar1 = failedFatallyOrWhenRequired<StringModel>
                            ((VagOperationDelegate *)param_2,(Result *)&local_e4,in_r3,0x80);
          if (!bVar1) goto LAB_0127751c;
          Result<StringModel,void>::stateAs<VagEcuInfo,void>();
        }
        else {
LAB_0127751c:
          if (local_30 == 0) {
            local_10c = 0;
          }
          else {
            local_10c = __dynamic_cast(local_30,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0);
          }
          Result<UInt8Model,void>::Result((Result<UInt8Model,void> *)&local_108,0);
          if (((int)(uVar4 << 0x17) < 0) && (local_10c != 0)) {
            FUN_0127624c(&local_178,&local_10c);
            local_154 = local_178;
            local_150 = local_174;
            local_178 = 0;
            local_174 = 0;
            Progress::NUL((Progress *)&local_19c);
            OperationDelegate::runCommand<UInt8Model>
                      ((shared_ptr *)&local_130,(shared_ptr *)param_2);
            Result<UInt8Model,void>::operator=
                      ((Result<UInt8Model,void> *)&local_108,(Result *)&local_130);
            Result<UInt8Model,void>::~Result((Result<UInt8Model,void> *)&local_130);
            FUN_011e01a0(&local_19c);
            FUN_0121d0ec(&local_154);
            FUN_01276280(&local_178);
            iVar2 = Result<UInt8Model,void>::isFatalFail((Result<UInt8Model,void> *)&local_108);
            if ((iVar2 == 0) && ((*local_f0 != -5 && (*local_f0 != -0xb)))) goto LAB_012775b2;
            Result<UInt8Model,void>::stateAs<VagEcuInfo,void>();
          }
          else {
LAB_012775b2:
            Result<BytesModel,void>::Result((Result<BytesModel,void> *)&local_130,0);
            if ((int)(uVar4 << 0x1e) < 0) {
              FUN_01277cc4(&local_19c,&local_30);
              local_178 = local_19c;
              local_174 = uStack_198;
              local_19c = 0;
              uStack_198 = 0;
              Progress::NUL((Progress *)&local_2c);
              OperationDelegate::runCommand<BytesModel>
                        ((shared_ptr *)&local_154,(shared_ptr *)param_2);
              Result<BytesModel,void>::operator=
                        ((Result<BytesModel,void> *)&local_130,(Result *)&local_154);
              Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_154);
              FUN_011e01a0(&local_2c);
              FUN_011e4f74(&local_178);
              FUN_01277cf8(&local_19c);
              iVar2 = Result<BytesModel,void>::isIn
                                ((Result<BytesModel,void> *)&local_130,
                                 (Set *)UNSUPPORTED_ECU_FEATURE_STATES);
              if (iVar2 != 0) {
                local_28 = CONCAT22(local_28._2_2_,0x101);
                local_2c = &DAT_01010101;
                FUN_00cdb87c(&local_19c,&local_2c,6);
                BytesModel::BytesModel((BytesModel *)&local_178,(vector *)&local_19c);
                Result<BytesModel,void>::done<BytesModel>((type *)&local_154);
                Result<BytesModel,void>::operator=
                          ((Result<BytesModel,void> *)&local_130,(Result *)&local_154);
                Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_154);
                BytesModel::~BytesModel((BytesModel *)&local_178);
                FUN_00cb7f50(&local_19c);
                goto LAB_01277676;
              }
              bVar1 = failedFatallyOrWhenRequired<BytesModel>
                                ((VagOperationDelegate *)param_2,(Result *)&local_130,in_r3,2);
              if (!bVar1) goto LAB_01277676;
              Result<BytesModel,void>::stateAs<VagEcuInfo,void>();
            }
            else {
LAB_01277676:
              Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)&local_154,0);
              if ((int)(uVar4 << 0x1b) < 0) {
                (**(code **)(*(int *)param_2 + 0x1a0))(&local_178,param_2,local_30);
                Result<VagEcuInfo,void>::operator=
                          ((Result<VagEcuInfo,void> *)&local_154,(Result *)&local_178);
                Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_178);
                bVar1 = failedFatallyOrWhenRequired<VagEcuInfo>
                                  ((VagOperationDelegate *)param_2,(Result *)&local_154,in_r3,0x10);
                if (!bVar1) goto LAB_012776bc;
                Result<VagEcuInfo,void>::Result
                          ((Result<VagEcuInfo,void> *)param_1,(Result *)&local_154);
              }
              else {
LAB_012776bc:
                Result<UInt16SetModel,void>::Result((Result<UInt16SetModel,void> *)&local_178);
                if (((int)(uVar4 << 0x16) < 0) && (local_10c != 0)) {
                  FUN_01277f14(&local_1a4,&local_10c);
                  local_2c = local_1a4;
                  local_28 = iStack_1a0;
                  local_1a4 = (undefined *)0x0;
                  iStack_1a0 = 0;
                  Progress::NUL((Progress *)&local_1ac);
                  OperationDelegate::runCommand<UInt16SetModel>
                            ((shared_ptr *)&local_19c,(shared_ptr *)param_2);
                  Result<UInt16SetModel,void>::operator=
                            ((Result<UInt16SetModel,void> *)&local_178,(Result *)&local_19c);
                  Result<UInt16SetModel,void>::~Result((Result<UInt16SetModel,void> *)&local_19c);
                  FUN_011e01a0(&local_1ac);
                  FUN_01277fd4(&local_2c);
                  FUN_01277fe6(&local_1a4);
                  bVar1 = failedFatallyOrWhenRequired<UInt16SetModel>
                                    ((VagOperationDelegate *)param_2,(Result *)&local_178,in_r3,
                                     0x200);
                  if (!bVar1) goto LAB_01277730;
                  Result<UInt16SetModel,void>::stateAs<VagEcuInfo,void>();
                }
                else {
LAB_01277730:
                  local_1b0 = 2;
                  if (*local_3c == 1) {
                    FUN_012780a4(&local_19c,*local_38 + 4);
                  }
                  else {
                    local_19c = 0;
                    uStack_198 = 0;
                  }
                  if (*local_13c == 1) {
                    local_1a4 = *(undefined **)(*local_138 + 0x10);
                    iStack_1a0 = *(int *)(*local_138 + 0x14);
                    if (iStack_1a0 != 0) {
                      piVar3 = (int *)(iStack_1a0 + 4);
                      do {
                        ExclusiveAccess(piVar3);
                        bVar1 = (bool)hasExclusiveAccess(piVar3);
                      } while (!bVar1);
                      *piVar3 = *piVar3 + 1;
                      if (*local_13c != 1) goto LAB_012777a4;
                    }
                    local_1ac = *(undefined4 *)(*local_138 + 0x18);
                    iStack_1a8 = *(int *)(*local_138 + 0x1c);
                    if (iStack_1a8 != 0) {
                      piVar3 = (int *)(iStack_1a8 + 4);
                      do {
                        ExclusiveAccess(piVar3);
                        bVar1 = (bool)hasExclusiveAccess(piVar3);
                      } while (!bVar1);
                      *piVar3 = *piVar3 + 1;
                    }
                  }
                  else {
                    local_1a4 = (undefined *)0x0;
                    iStack_1a0 = 0;
LAB_012777a4:
                    local_1ac = 0;
                    iStack_1a8 = 0;
                  }
                  local_1b4 = 0;
                  if (*local_118 == 1) {
                    FUN_012780d8(&local_1bc,*local_114 + 4);
                  }
                  else {
                    local_1bc = 0;
                    uStack_1b8 = 0;
                  }
                  local_1c0 = 0;
                  if (*local_60 == 1) {
                    FUN_012780a4(&local_1c8,*local_5c + 4);
                  }
                  else {
                    local_1c8 = 0;
                    uStack_1c4 = 0;
                  }
                  if (*local_84 == 1) {
                    FUN_012780a4(&local_1d0,*local_80 + 4);
                  }
                  else {
                    local_1d0 = 0;
                    uStack_1cc = 0;
                  }
                  if (*local_a8 == 1) {
                    FUN_012780a4(&local_1d8,*local_a4 + 4);
                  }
                  else {
                    local_1d8 = 0;
                    uStack_1d4 = 0;
                  }
                  if (*local_cc == 1) {
                    FUN_012780a4(&local_1e0,*local_c8 + 4);
                  }
                  else {
                    local_1e0 = 0;
                    uStack_1dc = 0;
                  }
                  if (*local_f0 == 0) {
                    local_1e8 = 0;
                    uStack_1e4 = 0;
                  }
                  else {
                    local_1e9 = *local_f0 == 1;
                    FUN_00d31274(&local_1e8,&local_1e9);
                  }
                  if (*local_160 == 1) {
                    FUN_0127810c(&local_1f4,*local_15c + 4);
                  }
                  else {
                    local_1f4 = 0;
                    uStack_1f0 = 0;
                  }
                  FUN_0127803c(&local_2c,&local_1b0,&local_19c,&local_1a4,&local_1ac,&local_1b4,
                               &local_1bc,&local_1c0,&local_1c8,&local_1d0,&local_1d8,&local_1e0,
                               &local_1e8,&local_1f4);
                  FUN_00d092b4(&local_1f4);
                  FUN_00d092c6(&local_1e8);
                  FUN_00cbd6dc(&local_1e0);
                  FUN_00cbd6dc(&local_1d8);
                  FUN_00cbd6dc(&local_1d0);
                  FUN_00cbd6dc(&local_1c8);
                  FUN_00cbd77c(&local_1bc);
                  FUN_00d08b74(&local_1ac);
                  FUN_00d08642(&local_1a4);
                  FUN_00cbd6dc(&local_19c);
                  (**(code **)(*(int *)param_2 + 0x1f8))(&local_19c,param_2,local_30);
                  if (*local_184 == 1) {
                    VagEcuInfo::merge((VagEcuInfo *)&local_1a4,(shared_ptr *)&local_2c,local_180);
                    FUN_01278140(&local_2c,&local_1a4);
                    FUN_00d08540(&local_1a4);
                  }
                  Result<VagEcuInfo,void>::done
                            ((Result<VagEcuInfo,void> *)param_1,(shared_ptr *)&local_2c);
                  Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_19c);
                  FUN_00d08540(&local_2c);
                }
                Result<UInt16SetModel,void>::~Result((Result<UInt16SetModel,void> *)&local_178);
              }
              Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_154);
            }
            Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_130);
          }
          Result<UInt8Model,void>::~Result((Result<UInt8Model,void> *)&local_108);
        }
        Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_e4);
      }
      Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_c0);
    }
    Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_9c);
  }
  Result<StringModel,void>::~Result((Result<StringModel,void> *)asStack_78);
LAB_01277968:
  Result<StringModel,void>::~Result(aRStack_54);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


