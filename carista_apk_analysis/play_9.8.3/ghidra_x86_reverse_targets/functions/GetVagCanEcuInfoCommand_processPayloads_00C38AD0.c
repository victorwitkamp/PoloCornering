/* Target GetVagCanEcuInfoCommand_processPayloads @ 00c38ad0 (Ghidra 00c48ad0) */
/* Size: 1317 bytes */
/* Reason: multi-response ECU-info parser that builds the VagEcuInfo +0x10 submodule vector */
/* Function: _ZNK23GetVagCanEcuInfoCommand15processPayloadsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE @ 00c38ad0 */

/* Symbols at target:
 * Function _ZNK23GetVagCanEcuInfoCommand15processPayloadsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE
 */


int * _ZNK23GetVagCanEcuInfoCommand15processPayloadsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE
                (int *param_1,int *param_2,int **param_3)

{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int **ppiVar6;
  int **ppiVar7;
  int ***pppiVar8;
  int **ppiVar9;
  int *piVar10;
  int *piVar11;
  int in_GS_OFFSET;
  int aiStack_e8 [2];
  int *piStack_e0;
  int **ppiStack_dc;
  int *apiStack_d8 [16];
  int *piStack_98;
  int *piStack_94;
  int *piStack_90;
  int *piStack_8c;
  int *piStack_88;
  int **ppiStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  int *piStack_68;
  int *piStack_64;
  int *piStack_5c;
  int *piStack_54;
  int *piStack_50;
  undefined4 *puStack_4c;
  int *piStack_44;
  int *piStack_40;
  int *apiStack_3c [3];
  int *piStack_30;
  int *piStack_28;
  undefined4 *puStack_24;
  int *piStack_20;
  undefined1 uStack_15;
  int iStack_14;
  
  piStack_e0 = (int *)&LAB_00c48ae1;
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3[1] == *param_3) {
    pppiVar8 = &ppiStack_dc;
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      ppiStack_dc = param_3;
      piStack_e0 = (int *)0xc48f7f;
      ppiVar9 = (int **)func_0x00c49fe0();
      ppiVar7 = ppiStack_84;
      ppiStack_dc = ppiStack_84;
      piStack_e0 = (int *)0xc48f8c;
      func_0x0197e320();
      ppiStack_dc = ppiVar7;
      piStack_e0 = (int *)0xc48f94;
      func_0x0197e150();
      ppiStack_dc = &piStack_68;
      piStack_e0 = (int *)0xc48fa3;
      func_0x00c491a0();
      ppiStack_dc = &piStack_44;
      piStack_e0 = (int *)0xc48fd2;
      func_0x00c491f0();
      ppiStack_dc = apiStack_3c;
      piStack_e0 = (int *)0xc48fdd;
      func_0x01981ab0();
      pppiVar8 = &ppiStack_dc;
      if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
        piStack_e0 = (int *)&LAB_00c48ff0;
        ppiStack_dc = ppiVar9;
        func_0x0197a750();
        pppiVar8 = &ppiStack_dc;
      }
    }
  }
  else {
    apiStack_d8[0] = param_2;
    ppiStack_dc = apiStack_3c;
    piStack_e0 = (int *)0xc48b15;
    apiStack_d8[1] = *param_3;
    (**(code **)(*param_2 + 0x1c))();
    ppiVar7 = &piStack_e0;
    piStack_e0 = (int *)*puStack_24;
    cVar2 = func_0x0197e390();
    piVar11 = piStack_20;
    if (cVar2 == '\0') {
      if (*(int *)(*piStack_20 + 0x20) - 1U < 3) {
        piStack_e0 = (int *)0x18;
        piStack_40 = (int *)func_0x0197e0c0();
        piStack_40[1] = 0;
        piStack_40[2] = 0;
        piStack_40[3] = 0;
        piStack_40[4] = 0;
        *piStack_40 = 0x19a08e8;
        piStack_44 = piStack_40 + 3;
        piStack_40[5] = 0;
        piVar3 = *param_3;
        ppiVar7 = &piStack_e0;
        if (1 < (uint)(((int)param_3[1] - (int)piVar3 >> 2) * -0x55555555)) {
          ppiVar9 = (int **)0x1;
          piVar10 = (int *)0xc;
          piStack_88 = (int *)0x19a08d0;
          ppiVar6 = &piStack_e0;
          do {
            pcVar1 = *(code **)(*param_2 + 0x1c);
            ppiVar6[2] = (int *)((int)piVar3 + (int)piVar10);
            ppiVar6[1] = param_2;
            *ppiVar6 = (int *)&piStack_68;
            ppiVar6[-1] = (int *)0xc48bff;
            (*pcVar1)();
            piVar11 = piStack_44;
            ppiVar7 = ppiVar6 + -1;
            piStack_8c = piVar10;
            ppiStack_84 = ppiVar9;
            if (*piStack_50 == 1) {
              uStack_70 = *puStack_4c;
              piStack_6c = (int *)puStack_4c[1];
              if (piStack_6c != (int *)0x0) {
                LOCK();
                piStack_6c[1] = piStack_6c[1] + 1;
                UNLOCK();
              }
              puVar5 = (undefined4 *)piStack_44[1];
              if (puVar5 < (undefined4 *)piStack_44[2]) {
                *puVar5 = uStack_70;
                puVar5[1] = piStack_6c;
                piStack_44[1] = (int)(puVar5 + 2);
              }
              else {
                *ppiVar6 = &uStack_70;
                ppiVar6[-1] = piStack_44;
                ppiVar6[-2] = (int *)0xc48c5f;
                iVar4 = func_0x01981a90();
                piVar3 = piStack_6c;
                piVar11[1] = iVar4;
                if (piStack_6c != (int *)0x0) {
                  LOCK();
                  piVar11 = piStack_6c + 1;
                  iVar4 = *piVar11;
                  *piVar11 = *piVar11 + -1;
                  UNLOCK();
                  if (iVar4 == 0) {
                    iVar4 = *piStack_6c;
                    ppiVar6[-1] = piStack_6c;
                    pcVar1 = *(code **)(iVar4 + 8);
                    ppiVar6[-2] = (int *)0xc48c7f;
                    (*pcVar1)();
                    ppiVar6[-1] = piVar3;
                    ppiVar6[-2] = (int *)0xc48c87;
                    func_0x0197e1b0();
                  }
                }
              }
            }
            piVar11 = piStack_54;
            piStack_68 = piStack_88;
            if (piStack_54 != (int *)0x0) {
              LOCK();
              piVar3 = piStack_54 + 1;
              iVar4 = *piVar3;
              *piVar3 = *piVar3 + -1;
              UNLOCK();
              if (iVar4 == 0) {
                iVar4 = *piStack_54;
                ppiVar6[-1] = piStack_54;
                pcVar1 = *(code **)(iVar4 + 8);
                ppiVar6[-2] = (int *)0xc48cb6;
                (*pcVar1)();
                ppiVar6[-1] = piVar11;
                ppiVar6[-2] = (int *)&LAB_00c48cbe;
                func_0x0197e1b0();
              }
            }
            piVar11 = piStack_5c;
            ppiVar9 = ppiStack_84;
            if (piStack_5c != (int *)0x0) {
              LOCK();
              piVar3 = piStack_5c + 1;
              iVar4 = *piVar3;
              *piVar3 = *piVar3 + -1;
              UNLOCK();
              if (iVar4 == 0) {
                iVar4 = *piStack_5c;
                ppiVar6[-1] = piStack_5c;
                pcVar1 = *(code **)(iVar4 + 8);
                ppiVar6[-2] = (int *)0xc48ce6;
                (*pcVar1)();
                ppiVar6[-1] = piVar11;
                ppiVar6[-2] = (int *)0xc48cee;
                func_0x0197e1b0();
              }
            }
            ppiVar9 = (int **)((int)ppiVar9 + 1);
            piVar3 = *param_3;
            piVar10 = piStack_8c + 3;
            ppiVar6 = ppiVar6 + -1;
            piVar11 = piStack_20;
          } while (ppiVar9 < (int **)(((int)param_3[1] - (int)piVar3 >> 2) * -0x55555555));
        }
        piVar3 = (int *)*piVar11;
        piStack_64 = (int *)piVar11[1];
        if (piStack_64 != (int *)0x0) {
          LOCK();
          piStack_64[1] = piStack_64[1] + 1;
          UNLOCK();
        }
        uStack_70 = 0;
        uStack_74 = 0;
        uStack_78 = 0;
        uStack_7c = 0;
        uStack_80 = 0;
        piStack_68 = piVar3;
        *ppiVar7 = (int *)0x78;
        ppiVar7[-1] = (int *)0xc48d79;
        ppiStack_84 = (int **)func_0x0197e0c0();
        piStack_8c = piVar3 + 0xd;
        piStack_88 = piVar3 + 0xb;
        piStack_98 = piVar3 + 9;
        piStack_94 = piVar3 + 0x19;
        ppiStack_84[1] = (int *)0x0;
        ppiStack_84[2] = (int *)0x0;
        *ppiStack_84 = (int *)0x19a0910;
        piStack_90 = piVar3 + 2;
        ppiVar9 = ppiStack_84 + 3;
        ppiVar7[0xf] = &uStack_80;
        ppiVar7[0xe] = &uStack_7c;
        ppiVar7[0xd] = &uStack_78;
        ppiVar7[0xc] = &uStack_74;
        ppiVar7[0xb] = &uStack_70;
        ppiVar7[10] = piStack_8c;
        ppiVar7[9] = piStack_88;
        ppiVar7[8] = piStack_98;
        ppiVar7[7] = piStack_94;
        ppiVar7[6] = piVar3 + 8;
        ppiVar7[5] = piVar3 + 6;
        ppiVar7[4] = (int *)&piStack_44;
        ppiVar7[3] = piStack_90;
        ppiVar7[2] = piVar3 + 1;
        ppiVar7[1] = (int *)ppiVar9;
        *ppiVar7 = (int *)&uStack_15;
        ppiVar7[-1] = (int *)0xc48e47;
        func_0x01981aa0();
        ppiVar6 = ppiStack_84;
        *param_1 = 0x19a08d0;
        param_1[1] = 1;
        param_1[2] = (int)ppiVar9;
        param_1[3] = (int)ppiStack_84;
        LOCK();
        ppiStack_84[1] = (int *)((int)ppiStack_84[1] + 1);
        UNLOCK();
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = (int)(param_1 + 1);
        param_1[7] = (int)(param_1 + 2);
        param_1[8] = (int)(param_1 + 4);
        LOCK();
        ppiVar9 = ppiStack_84 + 1;
        piVar11 = *ppiVar9;
        *ppiVar9 = (int *)((int)*ppiVar9 + -1);
        UNLOCK();
        if (piVar11 == (int *)0x0) {
          piVar11 = *ppiStack_84;
          *ppiVar7 = (int *)ppiStack_84;
          pcVar1 = (code *)piVar11[2];
          ppiVar7[-1] = (int *)0xc48ea3;
          (*pcVar1)();
          *ppiVar7 = (int *)ppiVar6;
          ppiVar7[-1] = (int *)&LAB_00c48eab;
          func_0x0197e1b0();
        }
        piVar11 = piStack_64;
        if (piStack_64 != (int *)0x0) {
          LOCK();
          piVar3 = piStack_64 + 1;
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 == 0) {
            iVar4 = *piStack_64;
            *ppiVar7 = piStack_64;
            pcVar1 = *(code **)(iVar4 + 8);
            ppiVar7[-1] = (int *)0xc48ec8;
            (*pcVar1)();
            *ppiVar7 = piVar11;
            ppiVar7[-1] = (int *)&LAB_00c48ed0;
            func_0x0197e1b0();
          }
        }
        piVar11 = piStack_40;
        if (piStack_40 != (int *)0x0) {
          LOCK();
          piVar3 = piStack_40 + 1;
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 == 0) {
            iVar4 = *piStack_40;
            *ppiVar7 = piStack_40;
            pcVar1 = *(code **)(iVar4 + 8);
            ppiVar7[-1] = (int *)0xc48eed;
            (*pcVar1)();
            *ppiVar7 = piVar11;
            ppiVar7[-1] = (int *)&LAB_00c48ef5;
            func_0x0197e1b0();
          }
        }
      }
      else {
        piStack_e0 = (int *)&UNK_009b4d92;
        func_0x0197e300();
        *param_1 = 0x19a08d0;
        param_1[1] = -6;
        param_1[2] = 0;
        param_1[3] = 0;
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = (int)(param_1 + 1);
        param_1[7] = (int)(param_1 + 2);
        param_1[8] = (int)(param_1 + 4);
      }
    }
    else {
      ppiStack_dc = apiStack_3c;
      piStack_e0 = param_1;
      func_0x01981a80();
      ppiVar7 = &piStack_e0;
    }
    apiStack_3c[0] = (int *)0x19a08d0;
    if (piStack_28 != (int *)0x0) {
      LOCK();
      piVar11 = piStack_28 + 1;
      iVar4 = *piVar11;
      *piVar11 = *piVar11 + -1;
      UNLOCK();
      if (iVar4 == 0) {
        iVar4 = *piStack_28;
        *ppiVar7 = piStack_28;
        pcVar1 = *(code **)(iVar4 + 8);
        ppiVar7[-1] = (int *)0xc48f1e;
        (*pcVar1)();
        *ppiVar7 = piStack_28;
        ppiVar7[-1] = (int *)&LAB_00c48f26;
        func_0x0197e1b0();
      }
    }
    if (piStack_30 != (int *)0x0) {
      LOCK();
      piVar11 = piStack_30 + 1;
      iVar4 = *piVar11;
      *piVar11 = *piVar11 + -1;
      UNLOCK();
      if (iVar4 == 0) {
        iVar4 = *piStack_30;
        *ppiVar7 = piStack_30;
        pcVar1 = *(code **)(iVar4 + 8);
        ppiVar7[-1] = (int *)0xc48f43;
        (*pcVar1)();
        *ppiVar7 = piStack_30;
        ppiVar7[-1] = (int *)&LAB_00c48f4b;
        func_0x0197e1b0();
      }
    }
    pppiVar8 = (int ***)ppiVar7;
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      return param_1;
    }
  }
  pppiVar8[-1] = (int **)0xc48ff5;
  func_0x0197e230();
  pcVar1 = (code *)swi(3);
  puVar5 = (undefined4 *)(*pcVar1)();
  return puVar5;
}



/* Entry instruction preview:
 * 00c38ad0: PUSH EBP
 */
