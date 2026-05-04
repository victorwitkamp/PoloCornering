/* VagOperationDelegate::failedFatallyOrWhenRequired<BytesModel> @ 01277d0a */


/* bool VagOperationDelegate::failedFatallyOrWhenRequired<BytesModel>(Result<BytesModel, void>
   const&, unsigned int, unsigned int) */

bool __thiscall
VagOperationDelegate::failedFatallyOrWhenRequired<BytesModel>
          (VagOperationDelegate *this,Result *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = Result<BytesModel,void>::isFatalFail((Result<BytesModel,void> *)param_1);
  if ((iVar3 == 0) && (**(int **)(param_1 + 0x18) != -5)) {
    bVar1 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)param_1);
    bVar2 = (bool)(bVar1 & (param_3 & param_2) != 0);
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


