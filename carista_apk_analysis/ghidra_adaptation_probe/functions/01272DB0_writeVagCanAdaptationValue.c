/* VagOperationDelegate::writeVagCanAdaptationValue @ 01272db0 */


/* VagOperationDelegate::writeVagCanAdaptationValue(unsigned long long, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> >, std::__ndk1::shared_ptr<Progress> const&) */

void VagOperationDelegate::writeVagCanAdaptationValue
               (Result<BytesModel,void> *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 *param_6)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 auStack_60 [12];
  Progress aPStack_54 [36];
  undefined4 local_30;
  int iStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_30 = *param_6;
  iStack_2c = param_6[1];
  if (iStack_2c != 0) {
    piVar2 = (int *)(iStack_2c + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  Result<BytesModel,void>::Result(param_1);
  uVar4 = 0;
  do {
    if (uVar4 != 0) {
      uVar3 = (**(code **)(*param_2 + 0x158))(param_2,*(code **)(*param_2 + 0x158),param_3,param_4);
      Log::w("Retrying to write adaptation channel %d...",uVar3);
      Progress::NUL(aPStack_54);
      FUN_01272ebc(&local_30,aPStack_54);
      FUN_011e01a0(aPStack_54);
    }
    FUN_00cd5ef0(auStack_60,param_5);
    (**(code **)(*param_2 + 0x1bc))(aPStack_54,param_2,param_3,param_4,auStack_60,&local_30);
    Result<BytesModel,void>::operator=(param_1,(Result *)aPStack_54);
    Result<BytesModel,void>::~Result((Result<BytesModel,void> *)aPStack_54);
    FUN_00cb7f50(auStack_60);
  } while ((uVar4 < 2) && (uVar4 = uVar4 + 1, **(int **)(param_1 + 0x18) == -0xb));
  FUN_011e01a0(&local_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


