/* VagOperationDelegate::writeVagCanSubmoduleCodingValue @ 01273e8c */


/* VagOperationDelegate::writeVagCanSubmoduleCodingValue(unsigned long long,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::writeVagCanSubmoduleCodingValue(ulonglong param_1,vector *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  shared_ptr *psVar6;
  int *piVar7;
  undefined4 in_stack_00000000;
  Progress aPStack_78 [8];
  undefined1 auStack_70 [8];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 local_5c;
  Result<VagEcuInfo,void> aRStack_58 [28];
  int *local_3c;
  int *local_34;
  int iStack_30;
  undefined1 uStack_29;
  undefined4 local_28;
  int local_24;
  
  psVar6 = (shared_ptr *)(param_1 >> 0x20);
  local_24 = __stack_chk_guard;
  uVar2 = (**(code **)(*(int *)psVar6 + 0x154))(psVar6);
  local_28 = uVar2;
  iVar3 = (**(code **)(*(int *)psVar6 + 0x180))(psVar6,*(code **)(*(int *)psVar6 + 0x180),param_2);
  uStack_29 = (undefined1)iVar3;
  (**(code **)(*(int *)psVar6 + 0x1f8))(aRStack_58,psVar6,uVar2);
  puVar4 = (undefined4 *)FUN_0111cba4(*(undefined4 *)(*local_3c + 0x10),iVar3 + -1);
  piVar7 = (int *)*puVar4;
  iStack_30 = puVar4[1];
  if (iStack_30 != 0) {
    piVar5 = (int *)(iStack_30 + 4);
    do {
      ExclusiveAccess(piVar5);
      bVar1 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar1);
    *piVar5 = *piVar5 + 1;
  }
  local_34 = piVar7;
  Result<VagEcuInfo,void>::~Result(aRStack_58);
  (**(code **)(*piVar7 + 0x14))(aRStack_58,piVar7);
  FUN_01241444(auStack_70,in_stack_00000000);
  FUN_01273fd4(&local_68,&local_28,aRStack_58,piVar7 + 0xb,auStack_70,&uStack_29);
  local_60 = local_68;
  local_5c = uStack_64;
  local_68 = 0;
  uStack_64 = 0;
  Progress::NUL(aPStack_78);
  OperationDelegate::runCommand<EmptyModel>((shared_ptr *)param_1,psVar6);
  FUN_011e01a0(aPStack_78);
  FUN_011e4048(&local_60);
  FUN_0127401c(&local_68);
  FUN_00cbcfda(auStack_70);
  FUN_00cb7f50(aRStack_58);
  FUN_00d08540(&local_34);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


