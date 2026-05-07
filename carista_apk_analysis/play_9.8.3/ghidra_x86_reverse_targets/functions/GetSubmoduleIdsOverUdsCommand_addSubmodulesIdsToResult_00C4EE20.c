/* Target GetSubmoduleIdsOverUdsCommand_addSubmodulesIdsToResult @ 00c4ee20 (Ghidra 00c5ee20) */
/* Size: 353 bytes */
/* Reason: helper that appends recovered submodule IDs to a result vector */
/* Function: _ZNK29GetSubmoduleIdsOverUdsCommand24addSubmodulesIdsToResultEPNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKS4_b @ 00c4ee20 */

/* Symbols at target:
 * Function _ZNK29GetSubmoduleIdsOverUdsCommand24addSubmodulesIdsToResultEPNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKS4_b
 */


void _ZNK29GetSubmoduleIdsOverUdsCommand24addSubmodulesIdsToResultEPNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKS4_b
               (undefined4 param_1,int *param_2,int *param_3,char param_4)

{
  code *pcVar1;
  undefined **ppuVar2;
  uint uVar3;
  int iVar4;
  byte bVar6;
  byte bVar7;
  uint uVar5;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  byte bStack_11;
  
  ppuVar2 = &__DT_PLTGOT;
  iVar8 = *param_3;
  iVar11 = param_3[1];
  uVar5 = iVar11 - iVar8;
  if ((uVar5 & 0x1fffffff) != 0) {
    uVar9 = 0;
    bStack_11 = 1;
    do {
      if (uVar5 <= uVar9 >> 3) {
        func_0x00c06490(param_3);
LAB_00c5ef73:
        func_0x00bce8c0(param_2);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar5 = CONCAT11(bStack_11 - 1,bStack_11 - 1) & 0xffffff07;
      if ((*(char *)(iVar8 + (uVar9 >> 3)) << (sbyte)uVar5 & 0x80U) != 0) {
        bVar6 = (byte)(uVar5 >> 8);
        bVar7 = bVar6 | 0x80;
        if (param_4 == '\0') {
          bVar7 = bVar6;
        }
        pbVar10 = (byte *)param_2[1];
        if (pbVar10 < (byte *)param_2[2]) {
          *pbVar10 = bVar7;
          pbVar10 = pbVar10 + 1;
        }
        else {
          iVar8 = *param_2;
          iVar11 = (int)pbVar10 - iVar8;
          uVar5 = iVar11 + 1;
          if ((int)uVar5 < 0) goto LAB_00c5ef73;
          uVar3 = param_2[2] - iVar8;
          uVar9 = uVar3 * 2;
          if (uVar5 < uVar9) {
            uVar5 = uVar9;
          }
          if (0x3ffffffe < uVar3) {
            uVar5 = 0x7fffffff;
          }
          if (uVar5 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = func_0x0197e0c0(uVar5);
          }
          iVar12 = uVar5 + iVar4;
          *(byte *)(iVar4 + iVar11) = bVar7;
          pbVar10 = (byte *)(iVar4 + 1 + iVar11);
          func_0x0197e310(iVar4,iVar8,iVar11,pbVar10,iVar4,ppuVar2);
          *param_2 = iVar4;
          param_2[1] = (int)pbVar10;
          param_2[2] = iVar12;
          if (iVar8 != 0) {
            func_0x0197e150(iVar8);
          }
        }
        param_2[1] = (int)pbVar10;
        iVar8 = *param_3;
        iVar11 = param_3[1];
      }
      uVar9 = (uint)bStack_11;
      uVar5 = iVar11 - iVar8;
      bStack_11 = bStack_11 + 1;
    } while (uVar9 <= uVar5 * 8 && uVar5 * 8 - uVar9 != 0);
  }
  return;
}



/* Entry instruction preview:
 * 00c4ee20: PUSH EBP
 */
