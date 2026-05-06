/* Target address 011e7154 */
/* Function FUN_011e7154 @ 011e7154 */


void FUN_011e7154(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if ((*param_2 != 0) &&
     (iVar2 = __dynamic_cast(*param_2,&Setting::typeinfo,&GenericTool::typeinfo,0xfffffffe),
     iVar2 != 0)) {
    iVar4 = param_2[1];
    *param_1 = iVar2;
    param_1[1] = iVar4;
    if (iVar4 != 0) {
      piVar3 = (int *)(iVar4 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    return;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


