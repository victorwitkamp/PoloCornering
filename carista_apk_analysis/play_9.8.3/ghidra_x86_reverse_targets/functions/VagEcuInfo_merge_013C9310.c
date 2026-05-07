/* Target VagEcuInfo_merge @ 013c9310 (Ghidra 013d9310) */
/* Size: 386 bytes */
/* Reason: shared_ptr<VagEcuInfo> merge helper */
/* Function: _ZN10VagEcuInfo5mergeERKNSt6__ndk110shared_ptrIS_EES4_ @ 013c9310 */

/* Symbols at target:
 * Function _ZN10VagEcuInfo5mergeERKNSt6__ndk110shared_ptrIS_EES4_
 */


void _ZN10VagEcuInfo5mergeERKNSt6__ndk110shared_ptrIS_EES4_
               (undefined4 *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar7 = *param_2;
  iVar1 = *param_3;
  iVar9 = iVar7;
  if (*(int *)(iVar7 + 4) == 0) {
    iVar9 = iVar1;
  }
  iVar10 = iVar7;
  if (*(int *)(iVar7 + 8) == 0) {
    iVar10 = iVar1;
  }
  iVar2 = iVar7;
  if (*(int *)(iVar7 + 0x10) == 0) {
    iVar2 = iVar1;
  }
  iVar3 = iVar7;
  if (*(int *)(iVar7 + 0x18) == 0) {
    iVar3 = iVar1;
  }
  iVar15 = iVar7;
  if (*(int *)(iVar7 + 0x20) == 0) {
    iVar15 = iVar1;
  }
  iVar4 = iVar7;
  if (*(int *)(iVar7 + 0x24) == 0) {
    iVar4 = iVar1;
  }
  iVar5 = iVar7;
  if (*(int *)(iVar7 + 0x2c) == 0) {
    iVar5 = iVar1;
  }
  iVar6 = iVar7;
  if (*(int *)(iVar7 + 0x34) == 0) {
    iVar6 = iVar1;
  }
  iVar13 = iVar7;
  if (*(int *)(iVar7 + 0x3c) == 0) {
    iVar13 = iVar1;
  }
  iVar12 = iVar7;
  if (*(int *)(iVar7 + 0x44) == 0) {
    iVar12 = iVar1;
  }
  iVar14 = iVar7;
  if (*(int *)(iVar7 + 0x4c) == 0) {
    iVar14 = iVar1;
  }
  iVar11 = iVar7;
  if (*(int *)(iVar7 + 0x54) == 0) {
    iVar11 = iVar1;
  }
  if (*(int *)(iVar7 + 0x5c) == 0) {
    iVar7 = iVar1;
  }
  puVar8 = (undefined4 *)func_0x0197e0c0(0x70);
  puVar8[1] = 0;
  puVar8[2] = 0;
  *puVar8 = 0x1a19a2c;
  func_0x0198f550(puVar8 + 3,*(undefined4 *)(iVar9 + 4),iVar10 + 8,iVar2 + 0x10,iVar3 + 0x18,
                  *(undefined4 *)(iVar15 + 0x20),iVar4 + 0x24,iVar5 + 0x2c,iVar6 + 0x34,
                  iVar13 + 0x3c,iVar12 + 0x44,iVar14 + 0x4c,iVar11 + 0x54,iVar7 + 0x5c);
  *param_1 = puVar8 + 3;
  param_1[1] = puVar8;
  return;
}



/* Entry instruction preview:
 * 013c9310: PUSH EBP
 */
