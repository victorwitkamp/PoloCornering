/* Target address 01270cf8 */
/* Function readRawValuesMulti @ 01270cf8 */


/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* VagOperationDelegate::readRawValuesMulti(std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > const&) */

void VagOperationDelegate::readRawValuesMulti(vector *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  shared_ptr *in_r1;
  int *piVar5;
  undefined4 *in_r2;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  Progress aPStack_7c [8];
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int iStack_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int *local_3c;
  int local_34;
  int iStack_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar7 = (undefined4 *)*in_r2;
  puVar8 = (undefined4 *)in_r2[1];
  local_2c = 0;
  local_34 = 0;
  iStack_30 = 0;
  do {
    if (puVar7 == puVar8) {
      DataMemoryBarrier(0x1b);
      if (((DAT_014f8f60 & 1) == 0) && (iVar2 = __cxa_guard_acquire(&DAT_014f8f60), iVar2 != 0)) {
        DAT_014f8f5c = 6;
        __cxa_guard_release(&DAT_014f8f60);
      }
      iVar9 = iStack_30;
      iVar2 = local_34;
      uVar3 = FUN_013f45d0(iStack_30 - local_34,0xc);
      if (DAT_014f8f5c < uVar3) {
        uVar3 = 0;
        local_5c = 0;
        local_64 = 0;
        iStack_60 = 0;
        goto LAB_01270de0;
      }
      FUN_01270fb0(&local_64,&local_34);
      local_58 = local_64;
      local_54 = iStack_60;
      local_64 = 0;
      iStack_60 = 0;
      Progress::NUL((Progress *)&local_6c);
      OperationDelegate::runCommand<DynamicDataModel>((shared_ptr *)param_1,in_r1);
      FUN_011e01a0(&local_6c);
      FUN_011e01b2(&local_58);
      FUN_01270fe4(&local_64);
      break;
    }
    OperationDelegate::readSettingValueCached((shared_ptr *)&local_58);
    iVar2 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_58);
    if (iVar2 == 0) {
      local_64 = *puVar7;
      iStack_60 = puVar7[1];
      if (iStack_60 == 0) {
        iStack_60 = 0;
      }
      else {
        piVar5 = (int *)(iStack_60 + 4);
        do {
          ExclusiveAccess(piVar5);
          bVar1 = (bool)hasExclusiveAccess(piVar5);
        } while (!bVar1);
        *piVar5 = *piVar5 + 1;
      }
      local_6c = 0;
      local_68 = 0;
      local_5c = *(int *)(*local_3c + 8) - *(int *)(*local_3c + 4);
      FUN_01270f8c(&local_34,&local_64);
      FUN_00d1756c(&local_64);
      FUN_00d1756c(&local_6c);
    }
    else {
      Result<DynamicDataModel,void>::Result((Result<DynamicDataModel,void> *)param_1,-6);
    }
    Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_58);
    puVar7 = puVar7 + 2;
  } while (iVar2 == 0);
  goto LAB_01270ec8;
LAB_01270de0:
  uVar6 = DAT_014f8f5c;
  uVar4 = FUN_013f45d0(iVar9 - iVar2,0xc);
  if (uVar4 <= uVar3) goto LAB_01270eac;
  if (uVar4 <= uVar6 + uVar3) {
    uVar6 = 0xffffffff;
  }
  ContainerUtils::subrange<std::__ndk1::pair<std::__ndk1::shared_ptr<VagSetting>,unsigned_int>>
            ((ContainerUtils *)&local_58,(vector *)&local_34,uVar3,uVar6);
  FUN_01270ff8(&local_74,(ContainerUtils *)&local_58);
  local_6c = local_74;
  local_68 = uStack_70;
  local_74 = 0;
  uStack_70 = 0;
  Progress::NUL(aPStack_7c);
  OperationDelegate::runCommand<DynamicDataModel>((shared_ptr *)param_1,in_r1);
  FUN_011e01a0(aPStack_7c);
  FUN_011e01b2(&local_6c);
  FUN_01270fe4(&local_74);
  FUN_00d170a8((ContainerUtils *)&local_58);
  iVar2 = Result<DynamicDataModel,void>::isFail((Result<DynamicDataModel,void> *)param_1);
  if (iVar2 != 0) goto LAB_01270ec2;
  ContainerUtils::
  addAll<std::__ndk1::pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>
            ((vector *)&local_64,(vector *)(**(int **)(param_1 + 0x1c) + 4));
  Result<DynamicDataModel,void>::~Result((Result<DynamicDataModel,void> *)param_1);
  uVar3 = uVar3 + DAT_014f8f5c;
  iVar2 = local_34;
  iVar9 = iStack_30;
  goto LAB_01270de0;
LAB_01270eac:
  DynamicDataModel::DynamicDataModel((DynamicDataModel *)&local_58,(vector *)&local_64);
  Result<DynamicDataModel,void>::done<DynamicDataModel>((type *)param_1);
  DynamicDataModel::~DynamicDataModel((DynamicDataModel *)&local_58);
LAB_01270ec2:
  FUN_00cf8824(&local_64);
LAB_01270ec8:
  FUN_00d170a8(&local_34);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


