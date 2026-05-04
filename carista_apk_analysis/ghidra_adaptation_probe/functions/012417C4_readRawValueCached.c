/* OperationDelegate::readRawValueCached @ 012417c4 */


/* OperationDelegate::readRawValueCached(unsigned long long) */

void OperationDelegate::readRawValueCached(ulonglong param_1)

{
  int iVar1;
  type *ptVar2;
  int *piVar3;
  undefined4 in_r2;
  vector *unaff_r5;
  undefined8 local_40;
  undefined4 uStack_38;
  
  iVar1 = __stack_chk_guard;
  piVar3 = (int *)(param_1 >> 0x20);
  ptVar2 = (type *)param_1;
  local_40 = param_1;
  uStack_38 = in_r2;
  (**(code **)(*piVar3 + 0xa4))(&stack0xffffffd4);
  if (unaff_r5 == (vector *)0x0) {
    local_40 = local_40 & 0xffffffff00000000;
    (**(code **)(*piVar3 + 0xe4))(ptVar2,piVar3);
    if (**(int **)(ptVar2 + 0x18) == 1) {
      FUN_01241444((int)&local_40 + 4,**(int **)(ptVar2 + 0x1c) + 4);
    }
    else {
      local_40 = 0;
      uStack_38 = 0;
    }
    local_40 = CONCAT44(local_40._4_4_,(int)&local_40 + 4);
    (**(code **)(*piVar3 + 0xb0))(piVar3);
    FUN_00cbcfda((int)&local_40 + 4);
  }
  else {
    BytesModel::BytesModel((BytesModel *)((int)&local_40 + 4),unaff_r5);
    Result<BytesModel,void>::done<BytesModel>(ptVar2);
    BytesModel::~BytesModel((BytesModel *)((int)&local_40 + 4));
  }
  FUN_00cbcfda(&stack0xffffffd4);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


