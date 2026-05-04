/* ReadValuesOperation::getAvailableItemsForEcuCount @ 012cd52a */


/* ReadValuesOperation::getAvailableItemsForEcuCount(Ecu*) */

int __thiscall
ReadValuesOperation::getAvailableItemsForEcuCount(ReadValuesOperation *this,Ecu *param_1)

{
  int iVar1;
  ReadValuesOperation *pRVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  pRVar2 = this + 0x70;
  iVar1 = 0;
  while (pRVar2 = *(ReadValuesOperation **)pRVar2, pRVar2 != (ReadValuesOperation *)0x0) {
    piVar3 = *(int **)(pRVar2 + 0xc);
    while (piVar3 != *(int **)(pRVar2 + 0x10)) {
      piVar4 = piVar3 + 2;
      iVar5 = *piVar3;
      piVar3 = piVar4;
      if (*(Ecu **)(iVar5 + 0x10) == param_1) {
        iVar1 = iVar1 + 1;
      }
    }
  }
  return iVar1;
}


