/* Target GetVagUdsSubmoduleIdsCommand_processPayload @ 00c51ef0 (Ghidra 00c61ef0) */
/* Size: 748 bytes */
/* Reason: alternate VAG UDS submodule-ID payload parser */
/* Function: _ZNK28GetVagUdsSubmoduleIdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 00c51ef0 */

/* Symbols at target:
 * Function _ZNK28GetVagUdsSubmoduleIdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 */


undefined4 *
_ZNK28GetVagUdsSubmoduleIdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
          (undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  char cVar2;
  code *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined *puVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  int iVar15;
  char *pcVar16;
  int in_GS_OFFSET;
  undefined1 auStack_30 [16];
  char *pcStack_20;
  char *pcStack_1c;
  char *pcStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  iVar15 = *param_3;
  iVar11 = param_3[1];
  uVar10 = iVar11 - iVar15;
  if (uVar10 < 2) {
    puVar6 = &UNK_0091bd96;
  }
  else {
    if ((uVar10 & 1) == 0) {
      pcStack_20 = (char *)0x0;
      pcStack_1c = (char *)0x0;
      pcStack_18 = (char *)0x0;
      pcVar14 = (char *)0x0;
      uVar13 = 1;
      do {
        pcVar4 = pcStack_20;
        if (uVar10 <= uVar13) {
          if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
            func_0x00c06490(param_3);
LAB_00c62167:
            if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
              uVar8 = func_0x00bce8c0(&pcStack_20);
              func_0x0197e150(pcVar14);
              func_0x0197fc50(auStack_30);
              if (pcStack_20 != (char *)0x0) {
                pcStack_1c = pcStack_20;
                func_0x0197e150(pcStack_20);
              }
              if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
                func_0x0197a750(uVar8);
              }
            }
          }
          goto LAB_00c621d7;
        }
        cVar2 = *(char *)(iVar15 + uVar13);
        if (cVar2 != '\0' && *(char *)(iVar15 + -1 + uVar13) == '\0') {
          if (pcVar14 < pcStack_18) {
            *pcVar14 = cVar2;
            pcVar14 = pcVar14 + 1;
          }
          else {
            iVar15 = (int)pcVar14 - (int)pcStack_20;
            pcVar14 = (char *)(iVar15 + 1);
            if ((int)pcVar14 < 0) goto LAB_00c62167;
            pcVar5 = (char *)(((int)pcStack_18 - (int)pcStack_20) * 2);
            pcVar16 = pcVar14;
            if (pcVar14 < pcVar5) {
              pcVar16 = pcVar5;
            }
            if (0x3ffffffe < (uint)((int)pcStack_18 - (int)pcStack_20)) {
              pcVar16 = (char *)0x7fffffff;
            }
            if (pcVar16 == (char *)0x0) {
              pcVar5 = (char *)0x0;
            }
            else {
              pcVar5 = (char *)func_0x0197e0c0(pcVar16);
            }
            pcVar5[iVar15] = cVar2;
            pcVar14 = pcVar5 + iVar15 + 1;
            func_0x0197e310(pcVar5,pcVar4,iVar15);
            pcStack_20 = pcVar5;
            pcStack_18 = pcVar16 + (int)pcVar5;
            if (pcVar4 != (char *)0x0) {
              func_0x0197e150(pcVar4);
            }
          }
          iVar15 = *param_3;
          iVar11 = param_3[1];
          pcStack_1c = pcVar14;
        }
        uVar10 = iVar11 - iVar15;
        uVar12 = uVar13 + 1;
        uVar13 = uVar13 + 2;
      } while (uVar12 < uVar10);
      func_0x0197fc30(auStack_30,&pcStack_20);
      piVar7 = (int *)func_0x0197e0c0(0x1c);
      func_0x0197fc40(piVar7,auStack_30);
      *param_1 = 0x199df34;
      param_1[1] = 1;
      param_1[2] = piVar7 + 3;
      param_1[3] = piVar7;
      LOCK();
      piVar7[1] = piVar7[1] + 1;
      UNLOCK();
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = param_1 + 1;
      param_1[7] = param_1 + 2;
      param_1[8] = param_1 + 4;
      LOCK();
      piVar1 = piVar7 + 1;
      iVar15 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar15 == 0) {
        (**(code **)(*piVar7 + 8))(piVar7);
        func_0x0197e1b0(piVar7);
      }
      func_0x0197fc50(auStack_30);
      if (pcStack_20 != (char *)0x0) {
        pcStack_1c = pcStack_20;
        func_0x0197e150(pcStack_20);
      }
      goto LAB_00c62133;
    }
    puVar6 = &UNK_0094b054;
  }
  func_0x0197e300(puVar6);
  *param_1 = 0x199df34;
  param_1[1] = 0xfffffffa;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_1 + 1;
  param_1[7] = param_1 + 2;
  param_1[8] = param_1 + 4;
LAB_00c62133:
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
LAB_00c621d7:
  func_0x0197e230();
  pcVar3 = (code *)swi(3);
  puVar9 = (undefined4 *)(*pcVar3)();
  return puVar9;
}



/* Entry instruction preview:
 * 00c51ef0: PUSH EBP
 */
