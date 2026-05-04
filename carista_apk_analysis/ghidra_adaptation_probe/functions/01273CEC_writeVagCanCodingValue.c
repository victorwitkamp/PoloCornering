/* VagOperationDelegate::writeVagCanCodingValue @ 01273cec */


/* VagOperationDelegate::writeVagCanCodingValue(unsigned long long, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::writeVagCanCodingValue(ulonglong param_1,vector *param_2)

{
  int iVar1;
  int iVar2;
  shared_ptr *psVar3;
  undefined4 in_stack_00000000;
  Progress aPStack_a0 [8];
  undefined1 auStack_98 [8];
  int local_90;
  Result<VagEcuInfo,void> aRStack_8c [28];
  int *local_70;
  Result<VagEcuInfo,void> aRStack_68 [28];
  undefined4 *local_4c;
  undefined1 auStack_44 [12];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  psVar3 = (shared_ptr *)(param_1 >> 0x20);
  local_24 = __stack_chk_guard;
  iVar1 = (**(code **)(*(int *)psVar3 + 0x154))(psVar3);
  local_28 = iVar1;
  iVar2 = (**(code **)(*(int *)psVar3 + 0x15c))(psVar3,*(code **)(*(int *)psVar3 + 0x15c),param_2);
  (**(code **)(*(int *)psVar3 + 0x1f8))(aRStack_68,psVar3,iVar1);
  if (iVar2 != 2) {
    iVar2 = 3;
  }
  (**(code **)(*(int *)*local_4c + 0x14))(auStack_44);
  (**(code **)(*(int *)psVar3 + 0x1f8))(aRStack_8c,psVar3,iVar1);
  if (iVar1 == VagCanEcu::BATTERY_REGULATOR) {
    iVar2 = 5;
  }
  iVar1 = *local_70;
  local_90 = iVar2;
  FUN_01241444(auStack_98,in_stack_00000000);
  FUN_01273e30(&local_38,&local_28,auStack_44,iVar1 + 0x2c,&local_90,auStack_98);
  local_30 = local_38;
  local_2c = uStack_34;
  local_38 = 0;
  uStack_34 = 0;
  Progress::NUL(aPStack_a0);
  OperationDelegate::runCommand<EmptyModel>((shared_ptr *)param_1,psVar3);
  FUN_011e01a0(aPStack_a0);
  FUN_011e4048(&local_30);
  FUN_01273e78(&local_38);
  FUN_00cbcfda(auStack_98);
  Result<VagEcuInfo,void>::~Result(aRStack_8c);
  FUN_00cb7f50(auStack_44);
  Result<VagEcuInfo,void>::~Result(aRStack_68);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


