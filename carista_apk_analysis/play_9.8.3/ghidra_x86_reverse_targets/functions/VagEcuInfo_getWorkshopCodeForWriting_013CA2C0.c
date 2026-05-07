/* Target VagEcuInfo_getWorkshopCodeForWriting @ 013ca2c0 (Ghidra 013da2c0) */
/* Size: 1258 bytes */
/* Reason: workshop-code construction used by UDS write sequences */
/* Function: _ZN10VagEcuInfo25getWorkshopCodeForWritingEv @ 013ca2c0 */

/* Symbols at target:
 * Function _ZN10VagEcuInfo25getWorkshopCodeForWritingEv
 */


uint ** _ZN10VagEcuInfo25getWorkshopCodeForWritingEv(uint **param_1,int param_2)

{
  int ***pppiVar1;
  int ***pppiVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  int ***pppiVar6;
  undefined8 *puVar7;
  uint ***pppuVar8;
  uint ***pppuVar9;
  uint *puVar10;
  int ***pppiVar11;
  undefined4 *puVar12;
  int in_GS_OFFSET;
  longlong lVar13;
  uint **ppuStack_cc;
  uint **ppuStack_c8;
  uint **ppuStack_c4;
  undefined4 uStack_c0;
  undefined4 *puStack_b0;
  undefined4 uStack_ac;
  uint **ppuStack_a8;
  int *piStack_a4;
  undefined4 uStack_a0;
  undefined2 *puStack_9c;
  undefined4 uStack_98;
  undefined2 *puStack_94;
  undefined4 uStack_90;
  uint **ppuStack_8c;
  undefined4 uStack_88;
  undefined8 uStack_84;
  int *piStack_7c;
  int iStack_78;
  int iStack_74;
  undefined2 uStack_6c;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  undefined4 uStack_68;
  int *piStack_64;
  undefined2 uStack_5e;
  int **ppiStack_5c;
  undefined1 auStack_58 [4];
  int **ppiStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int **ppiStack_40;
  int **ppiStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int **ppiStack_28;
  int **ppiStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  pppuVar9 = &ppuStack_cc;
  pppuVar8 = &ppuStack_cc;
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_84 = 0;
  piStack_7c = (int *)0x0;
  pppiVar6 = *(int ****)(param_2 + 0x24);
  if (pppiVar6 == (int ***)0x0) {
    ppuStack_c4 = (uint **)(auStack_58 + 2);
    auStack_58 = (undefined1  [4])((uint)auStack_58 & 0xffff0000);
    ppiStack_5c = (int **)0x0;
    ppuStack_c8 = (uint **)&ppiStack_5c;
    ppuStack_cc = (uint **)&uStack_84;
    uStack_c0 = 6;
    func_0x0198f5b0();
LAB_013da367:
    if (cRam01a5383c == '\0') {
      ppuStack_cc = (uint **)0x1a5383c;
      ppuStack_a8 = ppuStack_cc;
      iVar5 = func_0x0197f7e0();
      if (iVar5 != 0) {
        ppiStack_5c = (int **)0x0;
        ppuStack_cc = (uint **)auStack_58;
        uStack_6c = 0xffff;
        uStack_6a = 0xf8;
        ppuStack_c8 = (uint **)&uStack_6c;
        uStack_90 = 3;
        ppuStack_c4 = (uint **)0x3;
        puStack_94 = (undefined2 *)ppuStack_c8;
        func_0x00c19dd0();
        uStack_48 = 0;
        uStack_4c = 0x3039;
        uStack_44 = 2;
        ppuStack_cc = (uint **)&ppiStack_40;
        uStack_5e = 0xfe07;
        ppuStack_c8 = (uint **)&uStack_5e;
        uStack_98 = 2;
        ppuStack_c4 = (uint **)0x2;
        puStack_9c = (undefined2 *)ppuStack_c8;
        func_0x00c19dd0();
        uStack_30 = 0;
        uStack_34 = 0x7b;
        uStack_2c = 3;
        ppuStack_cc = (uint **)&ppiStack_28;
        iStack_78 = CONCAT13(iStack_78._3_1_,0xffff01);
        ppuStack_c8 = (uint **)&iStack_78;
        uStack_a0 = 3;
        ppuStack_c4 = (uint **)0x3;
        piStack_a4 = (int *)ppuStack_c8;
        func_0x00c19dd0();
        uStack_18 = 0;
        uStack_1c = 0x3039;
        ppuStack_cc = (uint **)&ppiStack_5c;
        uStack_88 = 3;
        ppuStack_c8 = (uint **)0x3;
        ppuStack_8c = ppuStack_cc;
        func_0x013da7b0();
        if ((uint **)ppiStack_28 != (uint **)0x0) {
          ppiStack_24 = ppiStack_28;
          ppuStack_cc = (uint **)ppiStack_28;
          func_0x0197e150();
        }
        if ((uint **)ppiStack_40 != (uint **)0x0) {
          ppiStack_3c = ppiStack_40;
          ppuStack_cc = (uint **)ppiStack_40;
          func_0x0197e150();
        }
        if (auStack_58 != (undefined1  [4])0x0) {
          ppiStack_54 = (int **)auStack_58;
          ppuStack_cc = (uint **)auStack_58;
          func_0x0197e150();
        }
        ppuStack_c4 = (uint **)&DAT_0199ccf0;
        ppuStack_c8 = (uint **)0x1a53830;
        ppuStack_cc = (uint **)&UNK_013da980;
        func_0x0197e090();
        ppuStack_cc = ppuStack_a8;
        func_0x0197f7f0();
      }
    }
    puStack_b0 = puRam01a53834;
    puVar12 = puRam01a53830;
    if (puRam01a53830 != puRam01a53834) {
      do {
        uVar3 = *puVar12;
        ppuStack_a8 = (uint **)(puVar12 + 1);
        pppuVar8[3] = ppuStack_a8;
        pppuVar8[2] = (uint **)uVar3;
        pppuVar8[1] = (uint **)&uStack_84;
        *pppuVar8 = (uint **)&ppiStack_5c;
        pppuVar8[-1] = (uint **)0x13da3d4;
        func_0x01981650();
        pppuVar8[-1] = (uint **)&ppiStack_5c;
        pppuVar8[-2] = (uint **)0x13da3df;
        lVar13 = func_0x01980710();
        pppuVar9 = pppuVar8 + -1;
        if (lVar13 == 0) {
          uStack_ac = *puVar12;
          uVar3 = puVar12[4];
          pppuVar8[1] = (uint **)puVar12[5];
          *pppuVar8 = (uint **)uVar3;
          pppuVar8[-1] = (uint **)&iStack_78;
          pppuVar8[-2] = (uint **)0x13da408;
          func_0x01981930();
          pppuVar8[1] = ppuStack_a8;
          pppuVar8[2] = (uint **)&iStack_78;
          *pppuVar8 = (uint **)uStack_ac;
          pppuVar8[-1] = (uint **)&uStack_84;
          pppuVar8[-2] = (uint **)&uStack_6c;
          pppuVar8[-3] = (uint **)0x13da435;
          func_0x019883d0();
          if ((int ***)uStack_84 != (int ***)0x0) {
            uStack_84 = CONCAT44((int ***)uStack_84,(int ***)uStack_84);
            pppuVar8[-3] = (uint **)(int ***)uStack_84;
            pppuVar8[-4] = (uint **)&LAB_013da44a;
            func_0x0197e150();
          }
          uStack_84 = CONCAT44(uStack_68,CONCAT13(uStack_69,CONCAT12(uStack_6a,uStack_6c)));
          piStack_7c = piStack_64;
          piStack_64 = (int *)0x0;
          uStack_68 = 0;
          uStack_6c = 0;
          uStack_6a = 0;
          uStack_69 = 0;
          pppuVar9 = pppuVar8 + -3;
          if (iStack_78 != 0) {
            iStack_74 = iStack_78;
            pppuVar8[-3] = (uint **)iStack_78;
            pppuVar8[-4] = (uint **)&LAB_013da481;
            func_0x0197e150();
            pppuVar9 = pppuVar8 + -3;
          }
        }
        if ((uint **)ppiStack_5c != (uint **)0x0) {
          auStack_58 = (undefined1  [4])ppiStack_5c;
          *pppuVar9 = (uint **)ppiStack_5c;
          pppuVar9[-1] = (uint **)0x13da497;
          func_0x0197e150();
        }
        puVar12 = puVar12 + 6;
        pppuVar8 = pppuVar9;
      } while (puVar12 != puStack_b0);
    }
    *(undefined8 *)param_1 = uStack_84;
    param_1[2] = (uint *)piStack_7c;
  }
  else {
    pppiVar1 = (int ***)*pppiVar6;
    pppiVar2 = (int ***)pppiVar6[1];
    pppiVar11 = (int ***)((int)pppiVar2 - (int)pppiVar1);
    if (pppiVar11 == (int ***)0x6) {
      if ((int ***)&uStack_84 != pppiVar6) {
        uStack_c0 = 6;
        ppuStack_cc = (uint **)&uStack_84;
        ppuStack_c8 = (uint **)pppiVar1;
        ppuStack_c4 = (uint **)pppiVar2;
        func_0x0197f3f0();
      }
      goto LAB_013da367;
    }
    *param_1 = (uint *)0x0;
    param_1[1] = (uint *)0x0;
    param_1[2] = (uint *)0x0;
    pppuVar9 = &ppuStack_cc;
    ppuStack_a8 = (uint **)pppiVar1;
    if (pppiVar2 != pppiVar1) {
      if ((int)pppiVar11 < 0) {
        pppuVar9 = &ppuStack_cc;
        if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
          ppuStack_cc = param_1;
          pppiVar6 = (int ***)func_0x00bce8c0();
          if ((uint **)ppiStack_28 != (uint **)0x0) {
            ppiStack_24 = ppiStack_28;
            ppuStack_cc = (uint **)ppiStack_28;
            func_0x0197e150();
          }
          if ((uint **)ppiStack_40 != (uint **)0x0) {
            ppiStack_3c = ppiStack_40;
            ppuStack_cc = (uint **)ppiStack_40;
            func_0x0197e150();
          }
          if (auStack_58 != (undefined1  [4])0x0) {
            ppiStack_54 = (int **)auStack_58;
            ppuStack_cc = (uint **)auStack_58;
            func_0x0197e150();
          }
          ppuStack_cc = ppuStack_a8;
          func_0x019801b0();
          if ((int ***)uStack_84 != (int ***)0x0) {
            uStack_84 = CONCAT44((int ***)uStack_84,(int ***)uStack_84);
            ppuStack_cc = (uint **)(int ***)uStack_84;
            func_0x0197e150();
          }
          pppuVar9 = &ppuStack_cc;
          if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
            ppuStack_cc = (uint **)pppiVar6;
            func_0x0197a750();
            pppuVar9 = &ppuStack_cc;
          }
        }
        goto LAB_013da7a5;
      }
      ppuStack_cc = (uint **)pppiVar11;
      ppuStack_cc = (uint **)func_0x0197e0c0();
      *param_1 = (uint *)ppuStack_cc;
      puVar10 = (uint *)((int)ppuStack_cc + (int)pppiVar11);
      param_1[2] = puVar10;
      ppuStack_c8 = ppuStack_a8;
      ppuStack_c4 = (uint **)pppiVar11;
      func_0x0197e310();
      param_1[1] = puVar10;
      pppuVar9 = &ppuStack_cc;
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
LAB_013da7a5:
  *(undefined4 *)((int)pppuVar9 + -4) = 0x13da7aa;
  func_0x0197e230();
  pcVar4 = (code *)swi(3);
  puVar7 = (undefined8 *)(*pcVar4)();
  return (uint **)puVar7;
}



/* Entry instruction preview:
 * 013ca2c0: PUSH EBP
 */
