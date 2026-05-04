/* VagOperationDelegate::failedFatallyOrWhenRequired<StringModel> @ 01277b54 */


/* bool VagOperationDelegate::failedFatallyOrWhenRequired<StringModel>(Result<StringModel, void>
   const&, unsigned int, unsigned int) */

bool __thiscall
VagOperationDelegate::failedFatallyOrWhenRequired<StringModel>
          (VagOperationDelegate *this,Result *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = Result<StringModel,void>::isFatalFail((Result<StringModel,void> *)param_1);
  if ((iVar3 == 0) && (**(int **)(param_1 + 0x18) != -5)) {
    bVar1 = Result<StringModel,void>::isFail((Result<StringModel,void> *)param_1);
    bVar2 = (bool)(bVar1 & (param_3 & param_2) != 0);
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


