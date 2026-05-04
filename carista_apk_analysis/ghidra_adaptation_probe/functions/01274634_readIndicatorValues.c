/* VagOperationDelegate::readIndicatorValues @ 01274634 */


/* VagOperationDelegate::readIndicatorValues(std::__ndk1::shared_ptr<VagServiceIndicator> const&) */

void __thiscall
VagOperationDelegate::readIndicatorValues(VagOperationDelegate *this,shared_ptr *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  shared_ptr asStack_48 [28];
  int *local_2c;
  int local_24;
  
  local_24 = __stack_chk_guard;
  piVar3 = *(int **)(*(int *)param_1 + 0x48);
  piVar4 = *(int **)(*(int *)param_1 + 0x4c);
  do {
    if (piVar3 == piVar4) break;
    OperationDelegate::readSettingValueCached(asStack_48);
    iVar2 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)asStack_48);
    if (iVar2 == 0) {
      bVar1 = false;
      if ((uint)(*(int *)(*piVar3 + 0x20) - *(int *)(*piVar3 + 0x1c)) <=
          (uint)(*(int *)(*local_2c + 8) - *(int *)(*local_2c + 4))) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = false;
    }
    Result<BytesModel,void>::~Result((Result<BytesModel,void> *)asStack_48);
    piVar3 = piVar3 + 2;
  } while (bVar1);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_24);
}


