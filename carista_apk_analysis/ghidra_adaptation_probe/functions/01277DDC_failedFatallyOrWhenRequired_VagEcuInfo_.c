/* VagOperationDelegate::failedFatallyOrWhenRequired<VagEcuInfo> @ 01277ddc */


/* bool VagOperationDelegate::failedFatallyOrWhenRequired<VagEcuInfo>(Result<VagEcuInfo, void>
   const&, unsigned int, unsigned int) */

bool __thiscall
VagOperationDelegate::failedFatallyOrWhenRequired<VagEcuInfo>
          (VagOperationDelegate *this,Result *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = Result<VagEcuInfo,void>::isFatalFail((Result<VagEcuInfo,void> *)param_1);
  if ((iVar3 == 0) && (**(int **)(param_1 + 0x18) != -5)) {
    bVar1 = Result<VagEcuInfo,void>::isFail((Result<VagEcuInfo,void> *)param_1);
    bVar2 = (bool)(bVar1 & (param_3 & param_2) != 0);
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


