/* VagOperationDelegate::readSubmoduleInfoWithUdsCommands @ 0127818c */


/* VagOperationDelegate::readSubmoduleInfoWithUdsCommands(Ecu*) */

void VagOperationDelegate::readSubmoduleInfoWithUdsCommands(Ecu *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  shared_ptr *in_r1;
  int in_r2;
  byte *pbVar8;
  int *piVar9;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94 [2];
  undefined4 local_8c;
  undefined4 uStack_88;
  int local_84;
  undefined4 local_80;
  int *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 uStack_54;
  shared_ptr asStack_50 [28];
  int *local_34;
  undefined1 local_2c [4];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((in_r2 == 0) || (iVar3 = __dynamic_cast(), iVar3 == 0)) {
    FUN_0127851c(&local_58,local_2c);
    local_84 = local_58;
    local_80 = uStack_54;
    local_58 = 0;
    uStack_54 = 0;
    Progress::NUL((Progress *)&local_60);
    OperationDelegate::runCommand<BytesModel>(asStack_50,in_r1);
    FUN_011e01a0(&local_60);
    FUN_011e4f74(&local_84);
    FUN_01278550(&local_58);
    iVar3 = 0x1dc;
  }
  else {
    FUN_012784e8(&local_58,local_2c);
    local_84 = local_58;
    local_80 = uStack_54;
    local_58 = 0;
    uStack_54 = 0;
    Progress::NUL((Progress *)&local_60);
    OperationDelegate::runCommand<BytesModel>(asStack_50,in_r1);
    FUN_011e01a0(&local_60);
    FUN_011e4f74(&local_84);
    FUN_01278562(&local_58);
    iVar3 = 0x1d0;
  }
  iVar4 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)asStack_50);
  if (iVar4 != 0) {
    Result<BytesModel,void>::stateAs<VagEcuInfo,void>();
LAB_01278426:
    Result<BytesModel,void>::~Result((Result<BytesModel,void> *)asStack_50);
    if (__stack_chk_guard == local_28) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  FUN_00d08b44(&local_58);
  pbVar8 = *(byte **)(*local_34 + 4);
  pbVar5 = *(byte **)(*local_34 + 8);
  while (pbVar8 != pbVar5) {
    bVar1 = *pbVar8;
    uVar2 = (**(code **)(*(int *)in_r1 + iVar3))(in_r1,(uint)bVar1);
    local_98 = CONCAT22(local_98._2_2_,uVar2);
    FUN_01278574(&local_8c,local_2c,&local_98);
    local_60 = local_8c;
    local_5c = uStack_88;
    local_8c = 0;
    uStack_88 = 0;
    Progress::NUL((Progress *)local_94);
    OperationDelegate::runCommand<StringModel>((shared_ptr *)&local_84,in_r1);
    FUN_011e01a0((Progress *)local_94);
    FUN_011e659c(&local_60);
    FUN_01228564(&local_8c);
    iVar4 = Result<StringModel,void>::isFatalFail((Result<StringModel,void> *)&local_84);
    if (iVar4 == 0) {
      iVar6 = Result<StringModel,void>::isFail((Result<StringModel,void> *)&local_84);
      if (iVar6 == 0) {
        pbVar7 = (byte *)FUN_012785a8(local_58,*local_68 + 4);
        *pbVar7 = bVar1;
      }
      else {
        Log::e("Failed to read partNo for UDS submodule ID %d",(uint)bVar1);
      }
    }
    else {
      Result<StringModel,void>::stateAs<VagEcuInfo,void>();
    }
    Result<StringModel,void>::~Result((Result<StringModel,void> *)&local_84);
    pbVar8 = pbVar8 + 1;
    if (iVar4 != 0) goto LAB_01278420;
  }
  FUN_00d084e8(&local_84);
  piVar9 = (int *)(local_58 + 8);
  while (iVar3 = local_84, piVar9 = (int *)*piVar9, piVar9 != (int *)0x0) {
    local_94[0] = 2;
    FUN_00d25888(&local_8c,piVar9 + 2);
    local_9c = 0;
    local_98 = 0;
    local_a0 = 4;
    local_a8 = 0;
    uStack_a4 = 0;
    local_b0 = 0;
    uStack_ac = 0;
    local_b8 = 0;
    uStack_b4 = 0;
    local_c0 = 0;
    uStack_bc = 0;
    FUN_012785f8(&local_60,local_94,&local_8c,&local_98,&local_9c,&local_a0,&uStack_a4,&local_a8,
                 &uStack_ac,&local_b0,&uStack_b4,&local_b8,&uStack_bc,&local_c0);
    FUN_00d08518(iVar3,&local_60);
    FUN_00d08540(&local_60);
    FUN_00cbd6dc(&local_8c);
  }
  local_8c = 2;
  local_98 = 0;
  local_94[0] = 0;
  local_a0 = 0;
  local_9c = 0;
  local_a8 = 0;
  uStack_a4 = 0;
  local_b0 = 0;
  uStack_ac = 0;
  local_b8 = 0;
  uStack_b4 = 0;
  FUN_01278660(&local_60,&local_8c,local_94,&local_84,&local_58,&local_98,&local_9c,&local_a0,
               &uStack_a4,&local_a8,&uStack_ac,&local_b0,&uStack_b4,&local_b8);
  Result<VagEcuInfo,void>::done((Result<VagEcuInfo,void> *)param_1,(shared_ptr *)&local_60);
  FUN_00d08540(&local_60);
  FUN_00d08642(&local_84);
LAB_01278420:
  FUN_00d08b74(&local_58);
  goto LAB_01278426;
}


