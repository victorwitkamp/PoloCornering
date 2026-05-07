/* Target VagEcuInfo_equals @ 013c98f0 (Ghidra 013d98f0) */
/* Size: 1012 bytes */
/* Reason: VagEcuInfo equality comparison, useful for field layout */
/* Function: _ZNK10VagEcuInfoeqERKS_ @ 013c98f0 */

/* Symbols at target:
 * Function _ZNK10VagEcuInfoeqERKS_
 */


undefined4 _ZNK10VagEcuInfoeqERKS_(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  code *pcVar7;
  char cVar8;
  byte *pbVar9;
  undefined *puVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  
  if (*(int *)(param_1 + 4) != *(int *)(param_2 + 4)) {
    puVar10 = &UNK_00789c74;
    goto LAB_013d99b3;
  }
  pbVar3 = *(byte **)(param_1 + 8);
  pbVar9 = *(byte **)(param_2 + 8);
  if (pbVar3 == (byte *)0x0) {
LAB_013d99a9:
    if (pbVar9 == (byte *)0x0) {
LAB_013d99c7:
      piVar4 = *(int **)(param_1 + 0x10);
      piVar5 = *(int **)(param_2 + 0x10);
      if (piVar4 == (int *)0x0) {
        if (piVar5 == (int *)0x0) {
LAB_013d9a5a:
          iVar11 = *(int *)(param_2 + 0x18);
          if (*(int *)(param_1 + 0x18) == 0) {
            if (iVar11 == 0) goto LAB_013d9a8c;
          }
          else if ((iVar11 != 0) &&
                  (cVar8 = func_0x013daf40(*(int *)(param_1 + 0x18),iVar11), cVar8 != '\0')) {
LAB_013d9a8c:
            if (*(int *)(param_1 + 0x20) != *(int *)(param_2 + 0x20)) {
              puVar10 = &UNK_005a02a1;
              goto LAB_013d99b3;
            }
            iVar11 = *(int *)(param_2 + 0x24);
            if (*(int *)(param_1 + 0x24) == 0) {
              if (iVar11 == 0) goto LAB_013d9ac7;
            }
            else if ((iVar11 != 0) &&
                    (cVar8 = func_0x013d9da0(*(int *)(param_1 + 0x24),iVar11), cVar8 == '\0')) {
LAB_013d9ac7:
              iVar11 = *(int *)(param_2 + 0x2c);
              if (*(int *)(param_1 + 0x2c) == 0) {
                if (iVar11 == 0) goto LAB_013d9af6;
              }
              else if ((iVar11 != 0) &&
                      (cVar8 = func_0x013d9da0(*(int *)(param_1 + 0x2c),iVar11), cVar8 == '\0')) {
LAB_013d9af6:
                iVar11 = *(int *)(param_2 + 0x34);
                if (*(int *)(param_1 + 0x34) == 0) {
                  if (iVar11 == 0) goto LAB_013d9b25;
                }
                else if ((iVar11 != 0) &&
                        (cVar8 = func_0x013d9cf0(*(int *)(param_1 + 0x34),iVar11), cVar8 == '\0')) {
LAB_013d9b25:
                  iVar11 = *(int *)(param_2 + 0x3c);
                  if (*(int *)(param_1 + 0x3c) == 0) {
                    if (iVar11 == 0) goto LAB_013d9b51;
                  }
                  else if ((iVar11 != 0) &&
                          (cVar8 = func_0x013d9cf0(*(int *)(param_1 + 0x3c),iVar11), cVar8 == '\0'))
                  {
LAB_013d9b51:
                    iVar11 = *(int *)(param_2 + 0x44);
                    if (*(int *)(param_1 + 0x44) == 0) {
                      if (iVar11 == 0) goto LAB_013d9b80;
                    }
                    else if ((iVar11 != 0) &&
                            (cVar8 = func_0x013d9cf0(*(int *)(param_1 + 0x44),iVar11), cVar8 == '\0'
                            )) {
LAB_013d9b80:
                      iVar11 = *(int *)(param_2 + 0x4c);
                      if (*(int *)(param_1 + 0x4c) == 0) {
                        if (iVar11 == 0) goto LAB_013d9bb2;
                      }
                      else if ((iVar11 != 0) &&
                              (cVar8 = func_0x013d9cf0(*(int *)(param_1 + 0x4c),iVar11),
                              cVar8 == '\0')) {
LAB_013d9bb2:
                        pcVar6 = *(char **)(param_2 + 0x54);
                        if (*(char **)(param_1 + 0x54) == (char *)0x0) {
                          if (pcVar6 != (char *)0x0) goto LAB_013d9cb9;
                        }
                        else if ((pcVar6 == (char *)0x0) || (**(char **)(param_1 + 0x54) != *pcVar6)
                                ) {
LAB_013d9cb9:
                          puVar10 = &UNK_008487b1;
                          goto LAB_013d99b3;
                        }
                        iVar11 = *(int *)(param_2 + 0x5c);
                        if (*(int *)(param_1 + 0x5c) == 0) {
                          if (iVar11 == 0) {
                            return 1;
                          }
                        }
                        else if ((iVar11 != 0) &&
                                (cVar8 = func_0x013d9df0(*(int *)(param_1 + 0x5c),iVar11),
                                cVar8 == '\0')) {
                          return 1;
                        }
                        puVar10 = &UNK_0057906a;
                        goto LAB_013d99b3;
                      }
                      puVar10 = &UNK_009601d7;
                      goto LAB_013d99b3;
                    }
                    puVar10 = &UNK_005a02c0;
                    goto LAB_013d99b3;
                  }
                  puVar10 = &UNK_00617431;
                  goto LAB_013d99b3;
                }
                puVar10 = &UNK_0080abda;
                goto LAB_013d99b3;
              }
              puVar10 = &UNK_00931d63;
              goto LAB_013d99b3;
            }
            puVar10 = &UNK_0063d8d4;
            goto LAB_013d99b3;
          }
          puVar10 = &UNK_00848789;
          goto LAB_013d99b3;
        }
      }
      else if (piVar5 != (int *)0x0) {
        iVar11 = *piVar4;
        if (piVar4[1] - iVar11 == piVar5[1] - *piVar5) {
          if (piVar4[1] != iVar11) {
            uVar14 = 0;
            do {
              piVar4 = *(int **)(param_2 + 0x10);
              if ((uint)(piVar4[1] - *piVar4 >> 3) <= uVar14) {
                func_0x013daf20(piVar4);
                pcVar7 = (code *)swi(3);
                uVar12 = (*pcVar7)();
                return uVar12;
              }
              cVar8 = func_0x0198f590(*(undefined4 *)(iVar11 + uVar14 * 8),
                                      *(undefined4 *)(*piVar4 + uVar14 * 8));
              if (cVar8 == '\0') {
                puVar10 = &UNK_00789c94;
                goto LAB_013d99b3;
              }
              uVar14 = uVar14 + 1;
              iVar11 = **(int **)(param_1 + 0x10);
            } while (uVar14 < (uint)((*(int **)(param_1 + 0x10))[1] - iVar11 >> 3));
          }
          goto LAB_013d9a5a;
        }
      }
      puVar10 = &UNK_00a4460c;
      goto LAB_013d99b3;
    }
  }
  else if (pbVar9 != (byte *)0x0) {
    bVar1 = *pbVar3;
    uVar14 = *(uint *)(pbVar3 + 4);
    if ((bVar1 & 1) == 0) {
      uVar14 = (uint)(bVar1 >> 1);
    }
    bVar2 = *pbVar9;
    if ((bVar2 & 1) == 0) {
      uVar13 = (uint)(bVar2 >> 1);
    }
    else {
      uVar13 = *(uint *)(pbVar9 + 4);
    }
    if (uVar14 == uVar13) {
      if ((bVar2 & 1) == 0) {
        pbVar9 = pbVar9 + 1;
      }
      else {
        pbVar9 = *(byte **)(pbVar9 + 8);
      }
      if ((bVar1 & 1) != 0) {
        pbVar9 = (byte *)func_0x0197e980(*(undefined4 *)(pbVar3 + 8),pbVar9,*(uint *)(pbVar3 + 4));
        goto LAB_013d99a9;
      }
      if (1 < bVar1) {
        uVar14 = 0;
        do {
          if (pbVar3[uVar14 + 1] != pbVar9[uVar14]) goto LAB_013d99ad;
          uVar14 = uVar14 + 1;
        } while (bVar1 >> 1 != uVar14);
      }
      goto LAB_013d99c7;
    }
  }
LAB_013d99ad:
  puVar10 = &UNK_009601bc;
LAB_013d99b3:
  func_0x0197ec60(puVar10);
  return 0;
}



/* Entry instruction preview:
 * 013c98f0: PUSH EBP
 */
