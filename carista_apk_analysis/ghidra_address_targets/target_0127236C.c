/* Target address 0127236c */
/* Function readVagCanAdaptationValue @ 0127236c */


/* VagOperationDelegate::readVagCanAdaptationValue(unsigned long long) */

void VagOperationDelegate::readVagCanAdaptationValue(ulonglong param_1)

{
  Result<BytesModel,void> *this;
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  Result<BytesModel,void> local_4c [36];
  int local_28;
  
  piVar2 = (int *)(param_1 >> 0x20);
  this = (Result<BytesModel,void> *)param_1;
  local_28 = __stack_chk_guard;
  Result<BytesModel,void>::Result(this);
  uVar3 = 0;
  do {
    if (uVar3 != 0) {
      uVar1 = (**(code **)(*piVar2 + 0x158))(piVar2);
      Log::w("Retrying to read adaptation channel %u...",uVar1);
    }
    (**(code **)(*piVar2 + 0x1a8))(local_4c,piVar2);
    Result<BytesModel,void>::operator=(this,(Result *)local_4c);
    Result<BytesModel,void>::~Result(local_4c);
  } while ((uVar3 < 2) && (uVar3 = uVar3 + 1, **(int **)(this + 0x18) == -0xb));
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


