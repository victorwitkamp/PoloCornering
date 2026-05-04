/* VagOperationDelegate::readChassisIdInternal @ 0126f598 */


/* VagOperationDelegate::readChassisIdInternal() */

void VagOperationDelegate::readChassisIdInternal(void)

{
  bool bVar1;
  type *in_r0;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *in_r1;
  basic_string *pbVar5;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_60 [16];
  basic_string *local_50 [2];
  byte *local_48;
  int iStack_44;
  Result<VagEcuInfo,void> aRStack_40 [28];
  int *local_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  (**(code **)(*in_r1 + 0x194))(aRStack_40,in_r1,VagEcu::CENTRAL_ELEC,1,0);
  iVar2 = Result<VagEcuInfo,void>::isFail(aRStack_40);
  if (iVar2 != 0) {
    Result<VagEcuInfo,void>::failAs<StringModel>();
    goto LAB_0126f662;
  }
  local_48 = *(byte **)(*local_24 + 8);
  iStack_44 = *(int *)(*local_24 + 0xc);
  if (iStack_44 != 0) {
    piVar3 = (int *)(iStack_44 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  if (local_48 == (byte *)0x0) {
LAB_0126f652:
    Result<StringModel,void>::Result((Result<StringModel,void> *)in_r0,-6);
  }
  else {
    uVar4 = *(uint *)(local_48 + 4);
    if ((*local_48 & 1) == 0) {
      uVar4 = (uint)(*local_48 >> 1);
    }
    if (uVar4 < 3) goto LAB_0126f652;
    FUN_00cfe458(abStack_60,local_48,0,3);
    FUN_0124039c(local_50,abStack_60);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_60);
    pbVar5 = *(basic_string **)(local_50[0] + 8);
    if (((byte)*local_50[0] & 1) == 0) {
      pbVar5 = local_50[0] + 1;
    }
    Log::d("VAG chassis ID is %s",pbVar5);
    StringModel::StringModel((StringModel *)abStack_60,local_50[0]);
    Result<StringModel,void>::done<StringModel>(in_r0);
    StringModel::~StringModel((StringModel *)abStack_60);
    FUN_00cbba38(local_50);
  }
  FUN_00cbba38(&local_48);
LAB_0126f662:
  Result<VagEcuInfo,void>::~Result(aRStack_40);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


