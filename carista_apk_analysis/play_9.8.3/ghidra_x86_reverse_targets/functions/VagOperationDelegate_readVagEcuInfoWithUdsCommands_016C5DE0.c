/* Target VagOperationDelegate_readVagEcuInfoWithUdsCommands @ 016c5de0 (Ghidra 016d5de0) */
/* Size: 9993 bytes */
/* Reason: large UDS ECU-info read orchestration around submodule commands */
/* Function: _ZN20VagOperationDelegate29readVagEcuInfoWithUdsCommandsEP3Ecujj @ 016c5de0 */

/* Symbols at target:
 * Function _ZN20VagOperationDelegate29readVagEcuInfoWithUdsCommandsEP3Ecujj
 */


undefined4 *
_ZN20VagOperationDelegate29readVagEcuInfoWithUdsCommandsEP3Ecujj
          (undefined4 *param_1,int *param_2,int param_3,uint param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  int **ppiVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  char cVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int ***pppiVar13;
  undefined4 *puVar14;
  int ****ppppiVar15;
  int ****ppppiVar16;
  int ***pppiVar17;
  int in_GS_OFFSET;
  int aiStack_29c [14];
  int ***apppiStack_264 [2];
  int **ppiStack_25c;
  int ***pppiStack_258;
  int ***pppiStack_254;
  int **ppiStack_218;
  int **ppiStack_214;
  int iStack_210;
  int **ppiStack_20c;
  int **ppiStack_208;
  int *piStack_204;
  int **ppiStack_200;
  int *piStack_1fc;
  int *piStack_1f8;
  undefined4 *puStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  int *piStack_1e0;
  int *piStack_1dc;
  int *piStack_1d8;
  int *piStack_1d4;
  int *piStack_1d0;
  int *piStack_1cc;
  int *piStack_1c8;
  int *piStack_1c4;
  int *piStack_1c0;
  int *piStack_1bc;
  int *piStack_1b8;
  int *piStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  int *piStack_1a8;
  undefined4 uStack_1a4;
  int iStack_1a0;
  int *piStack_19c;
  undefined4 uStack_198;
  int iStack_194;
  int *piStack_190;
  undefined8 uStack_18c;
  int **ppiStack_180;
  int **ppiStack_17c;
  int **ppiStack_178;
  int *piStack_174;
  int *piStack_16c;
  int *piStack_168;
  int iStack_164;
  int **ppiStack_15c;
  int *piStack_158;
  int iStack_154;
  int *piStack_150;
  undefined4 uStack_14c;
  int *piStack_148;
  int **ppiStack_144;
  int *piStack_140;
  undefined4 *puStack_13c;
  int **ppiStack_138;
  int *piStack_134;
  int *piStack_130;
  int *piStack_12c;
  undefined4 uStack_128;
  int *piStack_124;
  int **ppiStack_120;
  int **ppiStack_11c;
  undefined4 *puStack_118;
  int **ppiStack_114;
  int *piStack_110;
  int iStack_10c;
  int *piStack_108;
  undefined4 uStack_104;
  int *piStack_100;
  int **ppiStack_fc;
  int *piStack_f8;
  undefined4 *puStack_f4;
  int **ppiStack_f0;
  int *piStack_ec;
  undefined4 uStack_e8;
  int *piStack_e4;
  undefined4 uStack_e0;
  int *piStack_dc;
  int **ppiStack_d8;
  undefined4 *puStack_d4;
  undefined4 *puStack_d0;
  int **ppiStack_cc;
  int **ppiStack_c8;
  int iStack_c4;
  int *piStack_c0;
  undefined4 uStack_bc;
  int *piStack_b8;
  int ***pppiStack_b4;
  int *piStack_b0;
  undefined4 *puStack_ac;
  int **ppiStack_a8;
  int **ppiStack_a4;
  int iStack_a0;
  int *piStack_9c;
  undefined4 uStack_98;
  int *piStack_94;
  int ***pppiStack_90;
  int *piStack_8c;
  undefined4 *puStack_88;
  int **ppiStack_84;
  int **ppiStack_80;
  int iStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  int *piStack_70;
  int ***pppiStack_6c;
  int *piStack_68;
  undefined4 *puStack_64;
  int **ppiStack_60;
  int iStack_5c;
  int iStack_58;
  int **ppiStack_54;
  undefined4 uStack_50;
  int **ppiStack_4c;
  int *piStack_48;
  int *piStack_44;
  undefined4 *puStack_40;
  int **ppiStack_3c;
  int iStack_38;
  int iStack_34;
  int *piStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  int *piStack_24;
  int *piStack_20;
  undefined4 *puStack_1c;
  undefined1 uStack_15;
  int iStack_14;
  
  ppppiVar15 = apppiStack_264 + 2;
  apppiStack_264[1] = (int ***)&LAB_016d5df1;
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  ppiStack_200 = (int **)(_ZTV6ResultI11StringModelvE + 8);
  piStack_24 = &iStack_38;
  iStack_38 = 0;
  iStack_34 = 0;
  piStack_30 = (int *)0x0;
  uStack_2c = 0;
  piStack_28 = (int *)0x0;
  piStack_20 = &iStack_34;
  puStack_1c = &uStack_2c;
  piStack_204 = (int *)(param_5 | param_4);
  ppiStack_3c = ppiStack_200;
  if (((uint)piStack_204 & 1) != 0) {
    ppiStack_25c = (int **)0x20;
    apppiStack_264[1] = (int ***)0x16d5f63;
    pppiVar13 = (int ***)func_0x0197e0c0();
    pppiVar13[1] = (int **)0x0;
    pppiVar13[2] = (int **)0x0;
    *pppiVar13 = (int **)0x1a1ccd4;
    pppiStack_258 = (int ***)param_3;
    pppiStack_254 = (int ***)0xf187;
    apppiStack_264[1] = (int ***)0x16d5f9a;
    ppiStack_25c = (int **)(pppiVar13 + 3);
    func_0x019817e0();
    ppiStack_a8 = (int **)0x0;
    ppiStack_a4 = (int **)0x0;
    apppiStack_264[1] = (int ***)0x16d5fc2;
    ppiStack_25c = (int **)&ppiStack_cc;
    ppiStack_84 = (int **)(pppiVar13 + 3);
    ppiStack_80 = (int **)pppiVar13;
    func_0x019909b0();
    pppiStack_258 = &ppiStack_84;
    ppiStack_25c = (int **)param_2;
    apppiStack_264[0] = (int ***)0x16d5fe2;
    apppiStack_264[1] = &ppiStack_60;
    pppiStack_254 = &ppiStack_cc;
    func_0x01990cb0();
    ppppiVar15 = apppiStack_264;
    ppppiVar16 = apppiStack_264;
    apppiStack_264[0] = &ppiStack_3c;
    apppiStack_264[1] = &ppiStack_60;
    func_0x01991240();
    ppiVar4 = ppiStack_4c;
    ppiStack_60 = ppiStack_200;
    if ((int ***)ppiStack_4c != (int ***)0x0) {
      LOCK();
      pppiVar13 = (int ***)(ppiStack_4c + 1);
      ppiVar3 = *pppiVar13;
      *pppiVar13 = (int **)((int)*pppiVar13 + -1);
      UNLOCK();
      if (ppiVar3 == (int **)0x0) {
        apppiStack_264[0] = (int ***)ppiStack_4c;
        (*(code *)(*ppiStack_4c)[2])();
        apppiStack_264[0] = (int ***)ppiVar4;
        func_0x0197e1b0();
      }
    }
    ppiVar4 = ppiStack_54;
    if ((int ***)ppiStack_54 != (int ***)0x0) {
      LOCK();
      pppiVar13 = (int ***)(ppiStack_54 + 1);
      ppiVar3 = *pppiVar13;
      *pppiVar13 = (int **)((int)*pppiVar13 + -1);
      UNLOCK();
      if (ppiVar3 == (int **)0x0) {
        apppiStack_264[0] = (int ***)ppiStack_54;
        (*(code *)(*ppiStack_54)[2])();
        apppiStack_264[0] = (int ***)ppiVar4;
        func_0x0197e1b0();
      }
    }
    ppiVar4 = ppiStack_c8;
    if ((int ***)ppiStack_c8 != (int ***)0x0) {
      LOCK();
      pppiVar13 = (int ***)(ppiStack_c8 + 1);
      ppiVar3 = *pppiVar13;
      *pppiVar13 = (int **)((int)*pppiVar13 + -1);
      UNLOCK();
      if (ppiVar3 == (int **)0x0) {
        apppiStack_264[0] = (int ***)ppiStack_c8;
        (*(code *)(*ppiStack_c8)[2])();
        apppiStack_264[0] = (int ***)ppiVar4;
        func_0x0197e1b0();
      }
    }
    ppiVar4 = ppiStack_80;
    if ((int ***)ppiStack_80 != (int ***)0x0) {
      LOCK();
      pppiVar13 = (int ***)(ppiStack_80 + 1);
      ppiVar3 = *pppiVar13;
      *pppiVar13 = (int **)((int)*pppiVar13 + -1);
      UNLOCK();
      if (ppiVar3 == (int **)0x0) {
        apppiStack_264[0] = (int ***)ppiStack_80;
        (*(code *)(*ppiStack_80)[2])();
        apppiStack_264[0] = (int ***)ppiVar4;
        func_0x0197e1b0();
      }
    }
    ppiVar4 = ppiStack_a4;
    if ((int ***)ppiStack_a4 != (int ***)0x0) {
      LOCK();
      pppiVar13 = (int ***)(ppiStack_a4 + 1);
      ppiVar3 = *pppiVar13;
      *pppiVar13 = (int **)((int)*pppiVar13 + -1);
      UNLOCK();
      if (ppiVar3 == (int **)0x0) {
        apppiStack_264[0] = (int ***)ppiStack_a4;
        (*(code *)(*ppiStack_a4)[2])();
        apppiStack_264[0] = (int ***)ppiVar4;
        func_0x0197e1b0();
      }
    }
    apppiStack_264[0] = (int ***)*piStack_24;
    cVar9 = func_0x0197ecf0();
    if (((cVar9 != '\0') || ((int ***)*piStack_24 == (int ***)0xfffffffb)) ||
       (apppiStack_264[0] = (int ***)*piStack_24, cVar9 = func_0x0197e390(),
       cVar9 == '\x01' && (param_4 & 1) != 0)) {
      iVar2 = *piStack_24;
      *param_1 = 0x1a1eab0;
      param_1[1] = iVar2;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = param_1 + 1;
      param_1[7] = param_1 + 2;
      param_1[8] = param_1 + 4;
      goto LAB_016d7ea5;
    }
  }
  piStack_48 = &iStack_5c;
  piStack_44 = &iStack_58;
  puStack_40 = &uStack_50;
  iStack_5c = 0;
  iStack_58 = 0;
  ppiStack_54 = (int **)0x0;
  uStack_50 = 0;
  ppiStack_4c = (int **)0x0;
  piVar10 = (int *)ppppiVar15;
  ppiStack_60 = ppiStack_200;
  if (((uint)piStack_204 & 4) == 0) {
LAB_016d5e6f:
    pppiStack_6c = &ppiStack_80;
    piStack_68 = &iStack_7c;
    puStack_64 = &uStack_74;
    ppiStack_80 = (int **)0x0;
    iStack_7c = 0;
    piStack_78 = (int *)0x0;
    uStack_74 = 0;
    piStack_70 = (int *)0x0;
    piVar11 = piVar10;
    ppiStack_84 = ppiStack_200;
    if (((uint)piStack_204 & 0x20) == 0) {
LAB_016d5e9a:
      pppiStack_90 = &ppiStack_a4;
      piStack_8c = &iStack_a0;
      puStack_88 = &uStack_98;
      ppiStack_a4 = (int **)0x0;
      iStack_a0 = 0;
      piStack_9c = (int *)0x0;
      uStack_98 = 0;
      piStack_94 = (int *)0x0;
      piVar10 = piVar11;
      ppiStack_a8 = ppiStack_200;
      if (((uint)piStack_204 & 0x40) == 0) {
LAB_016d5edd:
        pppiStack_b4 = &ppiStack_c8;
        piStack_b0 = &iStack_c4;
        puStack_ac = &uStack_bc;
        ppiStack_c8 = (int **)0x0;
        iStack_c4 = 0;
        piStack_c0 = (int *)0x0;
        uStack_bc = 0;
        piStack_b8 = (int *)0x0;
        piVar11 = piVar10;
        ppiStack_cc = ppiStack_200;
        if ((char)piStack_204 < '\0') {
          *piVar10 = 0x20;
          piVar10[-1] = 0x16d6705;
          piVar11 = (int *)func_0x0197e0c0();
          piVar11[1] = 0;
          piVar11[2] = 0;
          *piVar11 = 0x1a1f218;
          piVar10[1] = param_3;
          *piVar10 = (int)(piVar11 + 3);
          piVar10[-1] = 0x16d6734;
          func_0x01982380();
          ppiStack_138 = (int **)0x0;
          piStack_134 = (int *)0x0;
          *piVar10 = (int)&ppiStack_15c;
          piVar10[-1] = 0x16d6762;
          ppiStack_114 = (int **)(piVar11 + 3);
          piStack_110 = piVar11;
          func_0x019909b0();
          piVar10[2] = (int)&ppiStack_15c;
          piVar10[1] = (int)&ppiStack_114;
          *piVar10 = (int)param_2;
          piVar10[-1] = (int)&ppiStack_f0;
          piVar10[-2] = 0x16d6788;
          func_0x01990cb0();
          piVar11 = piVar10 + -2;
          ppppiVar16 = (int ****)(piVar10 + -2);
          piVar10[-1] = (int)&ppiStack_f0;
          piVar10[-2] = (int)&ppiStack_cc;
          piVar10[-3] = 0x16d679d;
          func_0x01991240();
          piVar12 = piStack_dc;
          ppiStack_f0 = ppiStack_200;
          if (piStack_dc != (int *)0x0) {
            LOCK();
            piVar1 = piStack_dc + 1;
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 0) {
              iVar2 = *piStack_dc;
              piVar10[-2] = (int)piStack_dc;
              pcVar5 = *(code **)(iVar2 + 8);
              piVar10[-3] = 0x16d67c9;
              (*pcVar5)();
              piVar10[-2] = (int)piVar12;
              piVar10[-3] = (int)&LAB_016d67d1;
              func_0x0197e1b0();
            }
          }
          piVar12 = piStack_e4;
          if (piStack_e4 != (int *)0x0) {
            LOCK();
            piVar1 = piStack_e4 + 1;
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 0) {
              iVar2 = *piStack_e4;
              piVar10[-2] = (int)piStack_e4;
              pcVar5 = *(code **)(iVar2 + 8);
              piVar10[-3] = 0x16d67f1;
              (*pcVar5)();
              piVar10[-2] = (int)piVar12;
              piVar10[-3] = (int)&LAB_016d67f9;
              func_0x0197e1b0();
            }
          }
          piVar12 = piStack_158;
          if (piStack_158 != (int *)0x0) {
            LOCK();
            piVar1 = piStack_158 + 1;
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 0) {
              iVar2 = *piStack_158;
              piVar10[-2] = (int)piStack_158;
              pcVar5 = *(code **)(iVar2 + 8);
              piVar10[-3] = 0x16d6819;
              (*pcVar5)();
              piVar10[-2] = (int)piVar12;
              piVar10[-3] = (int)&LAB_016d6821;
              func_0x0197e1b0();
            }
          }
          piVar12 = piStack_110;
          if (piStack_110 != (int *)0x0) {
            LOCK();
            piVar1 = piStack_110 + 1;
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 0) {
              iVar2 = *piStack_110;
              piVar10[-2] = (int)piStack_110;
              pcVar5 = *(code **)(iVar2 + 8);
              piVar10[-3] = 0x16d6841;
              (*pcVar5)();
              piVar10[-2] = (int)piVar12;
              piVar10[-3] = (int)&LAB_016d6849;
              func_0x0197e1b0();
            }
          }
          piVar12 = piStack_134;
          if (piStack_134 != (int *)0x0) {
            LOCK();
            piVar1 = piStack_134 + 1;
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 0) {
              iVar2 = *piStack_134;
              piVar10[-2] = (int)piStack_134;
              pcVar5 = *(code **)(iVar2 + 8);
              piVar10[-3] = 0x16d6869;
              (*pcVar5)();
              piVar10[-2] = (int)piVar12;
              piVar10[-3] = (int)&LAB_016d6871;
              func_0x0197e1b0();
            }
          }
          piVar10[-2] = (int)*pppiStack_b4;
          piVar10[-3] = 0x16d6881;
          cVar9 = func_0x0197ecf0();
          if ((cVar9 == '\0') && (*pppiStack_b4 != (int **)0xfffffffb)) {
            piVar10[-2] = (int)*pppiStack_b4;
            piVar10[-3] = 0x16d689a;
            cVar9 = func_0x0197e390();
            if (cVar9 != '\x01' || -1 < (char)param_4) goto LAB_016d5f23;
          }
          ppiVar4 = *pppiStack_b4;
          *param_1 = 0x1a1eab0;
          param_1[1] = ppiVar4;
          param_1[2] = 0;
          param_1[3] = 0;
          param_1[4] = 0;
          param_1[5] = 0;
          param_1[6] = param_1 + 1;
          param_1[7] = param_1 + 2;
          param_1[8] = param_1 + 4;
        }
        else {
LAB_016d5f23:
          if (param_3 == 0) {
            iStack_210 = 0;
          }
          else {
            piVar11[2] = (int)&_ZTI9VagUdsEcu;
            piVar11[1] = (int)&_ZTI3Ecu;
            *piVar11 = param_3;
            piVar11[3] = 0;
            piVar11[-1] = 0x16d5f52;
            iStack_210 = func_0x0197e7e0();
          }
          ppiStack_218 = (int **)(_ZTV6ResultI10UInt8ModelvE + 8);
          ppiStack_d8 = &piStack_ec;
          piStack_ec = (int *)0x0;
          uStack_e8 = 0;
          piStack_e4 = (int *)0x0;
          uStack_e0 = 0;
          piStack_dc = (int *)0x0;
          puStack_d4 = &uStack_e8;
          puStack_d0 = &uStack_e0;
          piVar10 = piVar11;
          ppiStack_f0 = ppiStack_218;
          if ((iStack_210 != 0 & (byte)((uint)piStack_204 >> 8)) == 1) {
            *piVar11 = 0x20;
            piVar11[-1] = 0x16d6959;
            piVar10 = (int *)func_0x0197e0c0();
            piVar10[1] = 0;
            piVar10[2] = 0;
            *piVar10 = 0x1a1f020;
            piVar11[1] = iStack_210;
            *piVar11 = (int)(piVar10 + 3);
            piVar11[-1] = 0x16d698b;
            func_0x01982700();
            ppiStack_15c = (int **)0x0;
            piStack_158 = (int *)0x0;
            *piVar11 = (int)&ppiStack_180;
            piVar11[-1] = 0x16d69b9;
            ppiStack_138 = (int **)(piVar10 + 3);
            piStack_134 = piVar10;
            func_0x019909b0();
            piVar11[2] = (int)&ppiStack_180;
            piVar11[1] = (int)&ppiStack_138;
            *piVar11 = (int)param_2;
            piVar11[-1] = (int)&ppiStack_114;
            piVar11[-2] = 0x16d69df;
            func_0x01991eb0();
            piVar10 = piVar11 + -2;
            ppppiVar16 = (int ****)(piVar11 + -2);
            piVar11[-1] = (int)&ppiStack_114;
            piVar11[-2] = (int)&ppiStack_f0;
            piVar11[-3] = 0x16d69f4;
            func_0x01991fa0();
            piVar12 = piStack_100;
            ppiStack_114 = ppiStack_218;
            if (piStack_100 != (int *)0x0) {
              LOCK();
              piVar1 = piStack_100 + 1;
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar2 == 0) {
                iVar2 = *piStack_100;
                piVar11[-2] = (int)piStack_100;
                pcVar5 = *(code **)(iVar2 + 8);
                piVar11[-3] = 0x16d6a20;
                (*pcVar5)();
                piVar11[-2] = (int)piVar12;
                piVar11[-3] = (int)&LAB_016d6a28;
                func_0x0197e1b0();
              }
            }
            piVar12 = piStack_108;
            if (piStack_108 != (int *)0x0) {
              LOCK();
              piVar1 = piStack_108 + 1;
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar2 == 0) {
                iVar2 = *piStack_108;
                piVar11[-2] = (int)piStack_108;
                pcVar5 = *(code **)(iVar2 + 8);
                piVar11[-3] = 0x16d6a4b;
                (*pcVar5)();
                piVar11[-2] = (int)piVar12;
                piVar11[-3] = (int)&LAB_016d6a53;
                func_0x0197e1b0();
              }
            }
            ppiVar4 = ppiStack_17c;
            if ((int ***)ppiStack_17c != (int ***)0x0) {
              LOCK();
              pppiVar13 = (int ***)(ppiStack_17c + 1);
              ppiVar3 = *pppiVar13;
              *pppiVar13 = (int **)((int)*pppiVar13 + -1);
              UNLOCK();
              if (ppiVar3 == (int **)0x0) {
                ppiVar3 = (int **)*ppiStack_17c;
                piVar11[-2] = (int)ppiStack_17c;
                pcVar5 = (code *)ppiVar3[2];
                piVar11[-3] = 0x16d6a73;
                (*pcVar5)();
                piVar11[-2] = (int)ppiVar4;
                piVar11[-3] = (int)&LAB_016d6a7b;
                func_0x0197e1b0();
              }
            }
            piVar12 = piStack_134;
            if (piStack_134 != (int *)0x0) {
              LOCK();
              piVar1 = piStack_134 + 1;
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar2 == 0) {
                iVar2 = *piStack_134;
                piVar11[-2] = (int)piStack_134;
                pcVar5 = *(code **)(iVar2 + 8);
                piVar11[-3] = 0x16d6a9b;
                (*pcVar5)();
                piVar11[-2] = (int)piVar12;
                piVar11[-3] = (int)&LAB_016d6aa3;
                func_0x0197e1b0();
              }
            }
            piVar12 = piStack_158;
            if (piStack_158 != (int *)0x0) {
              LOCK();
              piVar1 = piStack_158 + 1;
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar2 == 0) {
                iVar2 = *piStack_158;
                piVar11[-2] = (int)piStack_158;
                pcVar5 = *(code **)(iVar2 + 8);
                piVar11[-3] = 0x16d6ac3;
                (*pcVar5)();
                piVar11[-2] = (int)piVar12;
                piVar11[-3] = (int)&LAB_016d6acb;
                func_0x0197e1b0();
              }
            }
            piVar11[-2] = (int)*ppiStack_d8;
            piVar11[-3] = 0x16d6adb;
            cVar9 = func_0x0197ecf0();
            piVar11 = *ppiStack_d8;
            if (((cVar9 == '\0') && (piVar11 != (int *)0xfffffffb)) &&
               (piVar11 != (int *)0xfffffff5)) goto LAB_016d6b20;
            *param_1 = 0x1a1eab0;
            param_1[1] = piVar11;
            param_1[2] = 0;
            param_1[3] = 0;
            param_1[4] = 0;
            param_1[5] = 0;
            param_1[6] = param_1 + 1;
            param_1[7] = param_1 + 2;
            param_1[8] = param_1 + 4;
          }
          else {
LAB_016d6b20:
            ppiStack_20c = (int **)(_ZTV6ResultI10BytesModelvE + 8);
            ppiStack_fc = &piStack_110;
            piStack_110 = (int *)0x0;
            iStack_10c = 0;
            piStack_108 = (int *)0x0;
            uStack_104 = 0;
            piStack_100 = (int *)0x0;
            piStack_f8 = &iStack_10c;
            puStack_f4 = &uStack_104;
            piVar11 = piVar10;
            ppiStack_114 = ppiStack_20c;
            if (((uint)piStack_204 & 2) == 0) {
LAB_016d6e9e:
              ppiStack_208 = (int **)(_ZTV6ResultI10VagEcuInfovE + 8);
              ppiStack_120 = &piStack_134;
              piStack_134 = (int *)0x0;
              piStack_130 = (int *)0x0;
              piStack_12c = (int *)0x0;
              uStack_128 = 0;
              piStack_124 = (int *)0x0;
              ppiStack_11c = &piStack_130;
              puStack_118 = &uStack_128;
              piVar10 = piVar11;
              ppiStack_138 = ppiStack_208;
              if (((uint)piStack_204 & 0x10) == 0) {
LAB_016d6ef4:
                ppiStack_214 = (int **)(_ZTV6ResultI14UInt16SetModelvE + 8);
                ppiStack_144 = &piStack_158;
                piStack_158 = (int *)0x0;
                iStack_154 = 0;
                piStack_150 = (int *)0x0;
                uStack_14c = 0;
                piStack_148 = (int *)0x0;
                piStack_140 = &iStack_154;
                puStack_13c = &uStack_14c;
                piVar11 = piVar10;
                ppiStack_15c = ppiStack_214;
                if (((byte)((uint)piStack_204 >> 9) & iStack_210 != 0) == 1) {
                  *piVar10 = 0x1c;
                  piVar10[-1] = 0x16d6f6b;
                  piVar11 = (int *)func_0x0197e0c0();
                  piVar11[1] = 0;
                  piVar11[2] = 0;
                  *piVar11 = 0x1a1f268;
                  piVar10[1] = iStack_210;
                  *piVar10 = (int)(piVar11 + 3);
                  piVar10[-1] = 0x16d6f9d;
                  func_0x01982490();
                  uStack_18c = 0;
                  *piVar10 = (int)&iStack_194;
                  piVar10[-1] = 0x16d6fcb;
                  piStack_1fc = piVar11 + 3;
                  piStack_1f8 = piVar11;
                  func_0x019909b0();
                  piVar10[2] = (int)&iStack_194;
                  piVar10[1] = (int)&piStack_1fc;
                  *piVar10 = (int)param_2;
                  piVar10[-1] = (int)&ppiStack_180;
                  piVar10[-2] = 0x16d6ff1;
                  func_0x01993870();
                  piVar11 = piVar10 + -2;
                  ppppiVar16 = (int ****)(piVar10 + -2);
                  piVar10[-1] = (int)&ppiStack_180;
                  piVar10[-2] = (int)&ppiStack_15c;
                  piVar10[-3] = 0x16d7006;
                  func_0x01993880();
                  piVar12 = piStack_16c;
                  ppiStack_180 = ppiStack_214;
                  if (piStack_16c != (int *)0x0) {
                    LOCK();
                    piVar1 = piStack_16c + 1;
                    iVar2 = *piVar1;
                    *piVar1 = *piVar1 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_16c;
                      piVar10[-2] = (int)piStack_16c;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar10[-3] = 0x16d7032;
                      (*pcVar5)();
                      piVar10[-2] = (int)piVar12;
                      piVar10[-3] = (int)&LAB_016d703a;
                      func_0x0197e1b0();
                    }
                  }
                  piVar12 = piStack_174;
                  if (piStack_174 != (int *)0x0) {
                    LOCK();
                    piVar1 = piStack_174 + 1;
                    iVar2 = *piVar1;
                    *piVar1 = *piVar1 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_174;
                      piVar10[-2] = (int)piStack_174;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar10[-3] = 0x16d705a;
                      (*pcVar5)();
                      piVar10[-2] = (int)piVar12;
                      piVar10[-3] = (int)&LAB_016d7062;
                      func_0x0197e1b0();
                    }
                  }
                  piVar12 = piStack_190;
                  if (piStack_190 != (int *)0x0) {
                    LOCK();
                    piVar1 = piStack_190 + 1;
                    iVar2 = *piVar1;
                    *piVar1 = *piVar1 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_190;
                      piVar10[-2] = (int)piStack_190;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar10[-3] = 0x16d7082;
                      (*pcVar5)();
                      piVar10[-2] = (int)piVar12;
                      piVar10[-3] = (int)&LAB_016d708a;
                      func_0x0197e1b0();
                    }
                  }
                  piVar12 = piStack_1f8;
                  if (piStack_1f8 != (int *)0x0) {
                    LOCK();
                    piVar1 = piStack_1f8 + 1;
                    iVar2 = *piVar1;
                    *piVar1 = *piVar1 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1f8;
                      piVar10[-2] = (int)piStack_1f8;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar10[-3] = 0x16d70aa;
                      (*pcVar5)();
                      piVar10[-2] = (int)piVar12;
                      piVar10[-3] = (int)&LAB_016d70b2;
                      func_0x0197e1b0();
                    }
                  }
                  piVar12 = uStack_18c._4_4_;
                  if (uStack_18c._4_4_ != (int *)0x0) {
                    LOCK();
                    piVar1 = uStack_18c._4_4_ + 1;
                    iVar2 = *piVar1;
                    *piVar1 = *piVar1 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *uStack_18c._4_4_;
                      piVar10[-2] = (int)uStack_18c._4_4_;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar10[-3] = 0x16d70d2;
                      (*pcVar5)();
                      piVar10[-2] = (int)piVar12;
                      piVar10[-3] = (int)&LAB_016d70da;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10[-2] = (int)*ppiStack_144;
                  piVar10[-3] = 0x16d70ea;
                  cVar9 = func_0x0197ecf0();
                  piVar10 = *ppiStack_144;
                  if (((cVar9 == '\0') && (piVar10 != (int *)0xfffffffb)) &&
                     (piVar10 != (int *)0xfffffff5)) goto LAB_016d7215;
                  *param_1 = ppiStack_208;
                  param_1[1] = piVar10;
                  param_1[2] = 0;
                  param_1[3] = 0;
                  param_1[4] = 0;
                  param_1[5] = 0;
                  param_1[6] = param_1 + 1;
                  param_1[7] = param_1 + 2;
                  param_1[8] = param_1 + 4;
                }
                else {
LAB_016d7215:
                  uStack_198 = 2;
                  if (*piStack_24 == 1) {
                    iVar2 = *piStack_20;
                    *piVar11 = 0x18;
                    piVar11[-1] = 0x16d723c;
                    pppiVar13 = (int ***)func_0x0197e0c0();
                    pppiVar13[1] = (int **)0x0;
                    pppiVar13[2] = (int **)0x0;
                    *pppiVar13 = (int **)0x199d0f8;
                    pppiVar17 = pppiVar13 + 3;
                    if ((*(byte *)(iVar2 + 4) & 1) == 0) {
                      pppiVar13[5] = *(int ***)(iVar2 + 0xc);
                      *(undefined8 *)pppiVar17 = *(undefined8 *)(iVar2 + 4);
                      ppiStack_180 = (int **)pppiVar17;
                      ppiStack_17c = (int **)pppiVar13;
                    }
                    else {
                      iVar6 = *(int *)(iVar2 + 0xc);
                      piVar11[2] = *(int *)(iVar2 + 8);
                      piVar11[1] = iVar6;
                      *piVar11 = (int)pppiVar17;
                      piVar11[-1] = (int)&LAB_016d7322;
                      func_0x00bbc560();
                      ppiStack_180 = (int **)pppiVar17;
                      ppiStack_17c = (int **)pppiVar13;
                    }
                  }
                  else {
                    ppiStack_180 = (int **)0x0;
                    ppiStack_17c = (int **)0x0;
                  }
                  if (*ppiStack_120 == (int *)0x1) {
                    iStack_194 = (*ppiStack_11c)[4];
                    piStack_190 = (int *)(*ppiStack_11c)[5];
                    if (piStack_190 != (int *)0x0) {
                      LOCK();
                      piStack_190[1] = piStack_190[1] + 1;
                      UNLOCK();
                      if (*ppiStack_120 != (int *)0x1) goto LAB_016d739e;
                    }
                    iStack_1a0 = (*ppiStack_11c)[6];
                    piStack_19c = (int *)(*ppiStack_11c)[7];
                    if (piStack_19c != (int *)0x0) {
                      LOCK();
                      piStack_19c[1] = piStack_19c[1] + 1;
                      UNLOCK();
                    }
                  }
                  else {
                    iStack_194 = 0;
                    piStack_190 = (int *)0x0;
LAB_016d739e:
                    iStack_1a0 = 0;
                    piStack_19c = (int *)0x0;
                  }
                  uStack_1a4 = 0;
                  if (*ppiStack_fc == (int *)0x1) {
                    piVar11[2] = *piStack_f8 + 4;
                    piVar11[1] = (int)&piStack_1fc;
                    *piVar11 = (int)&uStack_1ac;
                    piVar11[-1] = 0x16d73ee;
                    func_0x016fb6e0();
                    piVar11 = piVar11 + -1;
                  }
                  else {
                    uStack_1ac = 0;
                    piStack_1a8 = (int *)0x0;
                  }
                  uStack_1b0 = 0;
                  if (*piStack_48 == 1) {
                    iVar2 = *piStack_44;
                    *piVar11 = 0x18;
                    piVar11[-1] = 0x16d742a;
                    piStack_1b4 = (int *)func_0x0197e0c0();
                    piStack_1b4[1] = 0;
                    piStack_1b4[2] = 0;
                    *piStack_1b4 = 0x199d0f8;
                    piStack_1b8 = piStack_1b4 + 3;
                    if ((*(byte *)(iVar2 + 4) & 1) == 0) {
                      piStack_1b4[5] = *(int *)(iVar2 + 0xc);
                      *(undefined8 *)piStack_1b8 = *(undefined8 *)(iVar2 + 4);
                    }
                    else {
                      iVar6 = *(int *)(iVar2 + 0xc);
                      piVar11[2] = *(int *)(iVar2 + 8);
                      piVar11[1] = iVar6;
                      *piVar11 = (int)piStack_1b8;
                      piVar11[-1] = (int)&LAB_016d7490;
                      func_0x00bbc560();
                    }
                  }
                  else {
                    piStack_1b8 = (int *)0x0;
                    piStack_1b4 = (int *)0x0;
                  }
                  if (*pppiStack_6c == (int **)0x1) {
                    iVar2 = *piStack_68;
                    *piVar11 = 0x18;
                    piVar11[-1] = 0x16d74b5;
                    piStack_1bc = (int *)func_0x0197e0c0();
                    piStack_1bc[1] = 0;
                    piStack_1bc[2] = 0;
                    *piStack_1bc = 0x199d0f8;
                    piStack_1c0 = piStack_1bc + 3;
                    if ((*(byte *)(iVar2 + 4) & 1) == 0) {
                      piStack_1bc[5] = *(int *)(iVar2 + 0xc);
                      *(undefined8 *)piStack_1c0 = *(undefined8 *)(iVar2 + 4);
                    }
                    else {
                      iVar6 = *(int *)(iVar2 + 0xc);
                      piVar11[2] = *(int *)(iVar2 + 8);
                      piVar11[1] = iVar6;
                      *piVar11 = (int)piStack_1c0;
                      piVar11[-1] = (int)&LAB_016d751b;
                      func_0x00bbc560();
                    }
                  }
                  else {
                    piStack_1c0 = (int *)0x0;
                    piStack_1bc = (int *)0x0;
                  }
                  if (*pppiStack_90 == (int **)0x1) {
                    iVar2 = *piStack_8c;
                    *piVar11 = 0x18;
                    piVar11[-1] = 0x16d7546;
                    piStack_1c4 = (int *)func_0x0197e0c0();
                    piStack_1c4[1] = 0;
                    piStack_1c4[2] = 0;
                    *piStack_1c4 = 0x199d0f8;
                    piStack_1c8 = piStack_1c4 + 3;
                    if ((*(byte *)(iVar2 + 4) & 1) == 0) {
                      piStack_1c4[5] = *(int *)(iVar2 + 0xc);
                      *(undefined8 *)piStack_1c8 = *(undefined8 *)(iVar2 + 4);
                    }
                    else {
                      iVar6 = *(int *)(iVar2 + 0xc);
                      piVar11[2] = *(int *)(iVar2 + 8);
                      piVar11[1] = iVar6;
                      *piVar11 = (int)piStack_1c8;
                      piVar11[-1] = (int)&LAB_016d75ac;
                      func_0x00bbc560();
                    }
                  }
                  else {
                    piStack_1c8 = (int *)0x0;
                    piStack_1c4 = (int *)0x0;
                  }
                  if (*pppiStack_b4 == (int **)0x1) {
                    iVar2 = *piStack_b0;
                    *piVar11 = 0x18;
                    piVar11[-1] = 0x16d75d7;
                    piStack_1cc = (int *)func_0x0197e0c0();
                    piStack_1cc[1] = 0;
                    piStack_1cc[2] = 0;
                    *piStack_1cc = 0x199d0f8;
                    piStack_1d0 = piStack_1cc + 3;
                    if ((*(byte *)(iVar2 + 4) & 1) == 0) {
                      piStack_1cc[5] = *(int *)(iVar2 + 0xc);
                      *(undefined8 *)piStack_1d0 = *(undefined8 *)(iVar2 + 4);
                    }
                    else {
                      iVar6 = *(int *)(iVar2 + 0xc);
                      piVar11[2] = *(int *)(iVar2 + 8);
                      piVar11[1] = iVar6;
                      *piVar11 = (int)piStack_1d0;
                      piVar11[-1] = (int)&LAB_016d763d;
                      func_0x00bbc560();
                    }
                  }
                  else {
                    piStack_1d0 = (int *)0x0;
                    piStack_1cc = (int *)0x0;
                  }
                  piVar10 = *ppiStack_d8;
                  if (piVar10 == (int *)0x0) {
                    piStack_1d8 = (int *)0x0;
                    piStack_1d4 = (int *)0x0;
                  }
                  else {
                    *piVar11 = 0x10;
                    piVar11[-1] = 0x16d7661;
                    piStack_1d4 = (int *)func_0x0197e0c0();
                    piStack_1d8 = piStack_1d4 + 3;
                    piStack_1d4[1] = 0;
                    piStack_1d4[2] = 0;
                    *piStack_1d4 = 0x19a29c8;
                    *(bool *)(piStack_1d4 + 3) = piVar10 == (int *)0x1;
                  }
                  piStack_204 = *ppiStack_144;
                  if (piStack_204 == (int *)0x0) {
                    piStack_1e0 = (int *)0x0;
                    piStack_1dc = (int *)0x0;
                  }
                  else {
                    if (piStack_204 == (int *)0x1) {
                      piVar11[1] = *piStack_140 + 4;
                      *piVar11 = (int)&piStack_1fc;
                      piVar11[-1] = 0x16d76dc;
                      func_0x00c1a4e0();
                    }
                    else {
                      piStack_1fc = (int *)0x0;
                      piStack_1f8 = (int *)0x0;
                      puStack_1f4 = (undefined4 *)0x0;
                      uStack_1f0 = 0;
                      uStack_1ec = 0x3f800000;
                    }
                    *piVar11 = 0x20;
                    piVar11[-1] = 0x16d7714;
                    piVar10 = (int *)func_0x0197e0c0();
                    piVar10[1] = 0;
                    piVar10[2] = 0;
                    *piVar10 = 0x1a1f2f0;
                    piVar11[1] = (int)&piStack_1fc;
                    *piVar11 = (int)(piVar10 + 3);
                    piVar11[-1] = 0x16d7746;
                    func_0x00c1a4e0();
                    piStack_1e0 = piVar10 + 3;
                    piStack_1dc = piVar10;
                  }
                  *piVar11 = 0x70;
                  piVar11[-1] = 0x16d775e;
                  puVar14 = (undefined4 *)func_0x0197e0c0();
                  puVar14[1] = 0;
                  puVar14[2] = 0;
                  *puVar14 = 0x1a19a2c;
                  piVar11[0xe] = (int)&piStack_1e0;
                  piVar11[0xd] = (int)&piStack_1d8;
                  piVar11[0xc] = (int)&piStack_1d0;
                  piVar11[0xb] = (int)&piStack_1c8;
                  piVar11[10] = (int)&piStack_1c0;
                  piVar11[9] = (int)&piStack_1b8;
                  piVar11[8] = (int)&uStack_1b0;
                  piVar11[7] = (int)&uStack_1ac;
                  piVar11[6] = (int)&uStack_1a4;
                  piVar11[5] = (int)&iStack_1a0;
                  piVar11[4] = (int)&iStack_194;
                  piVar11[3] = (int)&ppiStack_180;
                  piVar11[2] = (int)&uStack_198;
                  piVar11[1] = (int)(puVar14 + 3);
                  *piVar11 = (int)&uStack_15;
                  piVar11[-1] = 0x16d780f;
                  func_0x019938a0();
                  piVar10 = piStack_1dc;
                  uStack_18c = CONCAT44(puVar14,puVar14 + 3);
                  if (piStack_1dc != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_1dc + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1dc;
                      *piVar11 = (int)piStack_1dc;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d783b;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d7843;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_1fc;
                  puVar14 = puStack_1f4;
                  if (piStack_204 != (int *)0x0) {
                    while (puVar14 != (undefined4 *)0x0) {
                      puVar7 = (undefined4 *)*puVar14;
                      *piVar11 = (int)puVar14;
                      piVar11[-1] = 0x16d7863;
                      piStack_1fc = piVar10;
                      func_0x0197e150();
                      piVar10 = piStack_1fc;
                      puVar14 = puVar7;
                    }
                    piStack_1fc = (int *)0x0;
                    if (piVar10 != (int *)0x0) {
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d7885;
                      func_0x0197e150();
                    }
                  }
                  piVar10 = piStack_1d4;
                  if (piStack_1d4 != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_1d4 + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1d4;
                      *piVar11 = (int)piStack_1d4;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d78a8;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d78b0;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_1cc;
                  if (piStack_1cc != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_1cc + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1cc;
                      *piVar11 = (int)piStack_1cc;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d78d0;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d78d8;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_1c4;
                  if (piStack_1c4 != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_1c4 + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1c4;
                      *piVar11 = (int)piStack_1c4;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d78f8;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d7900;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_1bc;
                  if (piStack_1bc != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_1bc + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1bc;
                      *piVar11 = (int)piStack_1bc;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d7920;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d7928;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_1b4;
                  if (piStack_1b4 != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_1b4 + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1b4;
                      *piVar11 = (int)piStack_1b4;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d7948;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d7950;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_1a8;
                  if (piStack_1a8 != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_1a8 + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_1a8;
                      *piVar11 = (int)piStack_1a8;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d7970;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d7978;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_19c;
                  if (piStack_19c != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_19c + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_19c;
                      *piVar11 = (int)piStack_19c;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d7998;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d79a0;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = piStack_190;
                  if (piStack_190 != (int *)0x0) {
                    LOCK();
                    piVar12 = piStack_190 + 1;
                    iVar2 = *piVar12;
                    *piVar12 = *piVar12 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_190;
                      *piVar11 = (int)piStack_190;
                      pcVar5 = *(code **)(iVar2 + 8);
                      piVar11[-1] = 0x16d79c0;
                      (*pcVar5)();
                      *piVar11 = (int)piVar10;
                      piVar11[-1] = (int)&LAB_016d79c8;
                      func_0x0197e1b0();
                    }
                  }
                  ppiVar4 = ppiStack_17c;
                  if ((int ***)ppiStack_17c != (int ***)0x0) {
                    LOCK();
                    pppiVar13 = (int ***)(ppiStack_17c + 1);
                    ppiVar3 = *pppiVar13;
                    *pppiVar13 = (int **)((int)*pppiVar13 + -1);
                    UNLOCK();
                    if (ppiVar3 == (int **)0x0) {
                      ppiVar3 = (int **)*ppiStack_17c;
                      *piVar11 = (int)ppiStack_17c;
                      pcVar5 = (code *)ppiVar3[2];
                      piVar11[-1] = 0x16d79e8;
                      (*pcVar5)();
                      *piVar11 = (int)ppiVar4;
                      piVar11[-1] = (int)&LAB_016d79f0;
                      func_0x0197e1b0();
                    }
                  }
                  pcVar5 = *(code **)(*param_2 + 0x1f8);
                  piVar11[2] = param_3;
                  piVar11[1] = (int)param_2;
                  *piVar11 = (int)&ppiStack_180;
                  piVar11[-1] = 0x16d7a0e;
                  (*pcVar5)();
                  ppppiVar16 = (int ****)(piVar11 + -1);
                  uVar8 = uStack_18c;
                  if (*piStack_168 == 1) {
                    piVar11[1] = iStack_164;
                    *piVar11 = (int)&uStack_18c;
                    piVar11[-1] = (int)&iStack_194;
                    piVar11[-2] = 0x16d7a42;
                    func_0x0198f540();
                    piVar10 = uStack_18c._4_4_;
                    uVar8 = CONCAT44(piStack_190,iStack_194);
                    iStack_194 = 0;
                    piStack_190 = (int *)0x0;
                    ppppiVar16 = (int ****)(piVar11 + -2);
                    if (uStack_18c._4_4_ != (int *)0x0) {
                      LOCK();
                      piVar12 = uStack_18c._4_4_ + 1;
                      iVar2 = *piVar12;
                      *piVar12 = *piVar12 + -1;
                      UNLOCK();
                      if (iVar2 == 0) {
                        iVar2 = *uStack_18c._4_4_;
                        piVar11[-2] = (int)uStack_18c._4_4_;
                        pcVar5 = *(code **)(iVar2 + 8);
                        piVar11[-3] = 0x16d7a89;
                        uStack_18c = uVar8;
                        (*pcVar5)();
                        piVar11[-2] = (int)piVar10;
                        piVar11[-3] = (int)&LAB_016d7a91;
                        func_0x0197e1b0();
                        uVar8 = uStack_18c;
                      }
                      uStack_18c = uVar8;
                      piVar10 = piStack_190;
                      ppppiVar16 = (int ****)(piVar11 + -2);
                      uVar8 = uStack_18c;
                      if (piStack_190 != (int *)0x0) {
                        LOCK();
                        piVar12 = piStack_190 + 1;
                        iVar2 = *piVar12;
                        *piVar12 = *piVar12 + -1;
                        UNLOCK();
                        ppppiVar16 = (int ****)(piVar11 + -2);
                        if (iVar2 == 0) {
                          iVar2 = *piStack_190;
                          piVar11[-2] = (int)piStack_190;
                          pcVar5 = *(code **)(iVar2 + 8);
                          piVar11[-3] = 0x16d7ab1;
                          (*pcVar5)();
                          piVar11[-2] = (int)piVar10;
                          piVar11[-3] = (int)&LAB_016d7ab9;
                          func_0x0197e1b0();
                          ppppiVar16 = (int ****)(piVar11 + -2);
                          uVar8 = uStack_18c;
                        }
                      }
                    }
                  }
                  uStack_18c = uVar8;
                  *param_1 = ppiStack_208;
                  param_1[1] = 1;
                  param_1[2] = (undefined4)uStack_18c;
                  param_1[3] = uStack_18c._4_4_;
                  if (uStack_18c._4_4_ != (int *)0x0) {
                    LOCK();
                    *(int *)((int)uStack_18c._4_4_ + 4) = *(int *)((int)uStack_18c._4_4_ + 4) + 1;
                    UNLOCK();
                  }
                  param_1[4] = 0;
                  param_1[5] = 0;
                  param_1[6] = param_1 + 1;
                  param_1[7] = param_1 + 2;
                  param_1[8] = param_1 + 4;
                  ppiStack_180 = ppiStack_208;
                  if (piStack_16c != (int *)0x0) {
                    LOCK();
                    piVar10 = piStack_16c + 1;
                    iVar2 = *piVar10;
                    *piVar10 = *piVar10 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_16c;
                      *ppppiVar16 = (int ***)piStack_16c;
                      pcVar5 = *(code **)(iVar2 + 8);
                      ppppiVar16[-1] = (int ***)0x16d7b31;
                      (*pcVar5)();
                      *ppppiVar16 = (int ***)piStack_16c;
                      ppppiVar16[-1] = (int ***)&LAB_016d7b39;
                      func_0x0197e1b0();
                    }
                  }
                  if (piStack_174 != (int *)0x0) {
                    LOCK();
                    piVar10 = piStack_174 + 1;
                    iVar2 = *piVar10;
                    *piVar10 = *piVar10 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *piStack_174;
                      *ppppiVar16 = (int ***)piStack_174;
                      pcVar5 = *(code **)(iVar2 + 8);
                      ppppiVar16[-1] = (int ***)0x16d7b59;
                      (*pcVar5)();
                      *ppppiVar16 = (int ***)piStack_174;
                      ppppiVar16[-1] = (int ***)&LAB_016d7b61;
                      func_0x0197e1b0();
                    }
                  }
                  piVar10 = uStack_18c._4_4_;
                  if (uStack_18c._4_4_ != (int *)0x0) {
                    LOCK();
                    piVar11 = uStack_18c._4_4_ + 1;
                    iVar2 = *piVar11;
                    *piVar11 = *piVar11 + -1;
                    UNLOCK();
                    if (iVar2 == 0) {
                      iVar2 = *uStack_18c._4_4_;
                      *ppppiVar16 = (int ***)uStack_18c._4_4_;
                      pcVar5 = *(code **)(iVar2 + 8);
                      ppppiVar16[-1] = (int ***)0x16d7b81;
                      (*pcVar5)();
                      *ppppiVar16 = (int ***)piVar10;
                      ppppiVar16[-1] = (int ***)&LAB_016d7b89;
                      func_0x0197e1b0();
                    }
                  }
                }
                piVar10 = piStack_148;
                ppiStack_15c = ppiStack_214;
                if (piStack_148 != (int *)0x0) {
                  LOCK();
                  piVar11 = piStack_148 + 1;
                  iVar2 = *piVar11;
                  *piVar11 = *piVar11 + -1;
                  UNLOCK();
                  if (iVar2 == 0) {
                    iVar2 = *piStack_148;
                    *ppppiVar16 = (int ***)piStack_148;
                    pcVar5 = *(code **)(iVar2 + 8);
                    ppppiVar16[-1] = (int ***)0x16d7bb5;
                    (*pcVar5)();
                    *ppppiVar16 = (int ***)piVar10;
                    ppppiVar16[-1] = (int ***)&LAB_016d7bbd;
                    func_0x0197e1b0();
                  }
                }
                piVar10 = piStack_150;
                if (piStack_150 != (int *)0x0) {
                  LOCK();
                  piVar11 = piStack_150 + 1;
                  iVar2 = *piVar11;
                  *piVar11 = *piVar11 + -1;
                  UNLOCK();
                  if (iVar2 == 0) {
                    iVar2 = *piStack_150;
                    *ppppiVar16 = (int ***)piStack_150;
                    pcVar5 = *(code **)(iVar2 + 8);
                    ppppiVar16[-1] = (int ***)0x16d7bdd;
                    (*pcVar5)();
                    *ppppiVar16 = (int ***)piVar10;
                    ppppiVar16[-1] = (int ***)&LAB_016d7be5;
                    func_0x0197e1b0();
                  }
                }
              }
              else {
                pcVar5 = *(code **)(*param_2 + 0x1a0);
                piVar11[2] = param_3;
                piVar11[1] = (int)param_2;
                *piVar11 = (int)&ppiStack_15c;
                piVar11[-1] = 0x16d714e;
                (*pcVar5)();
                piVar10 = piVar11 + -1;
                ppppiVar16 = (int ****)(piVar11 + -1);
                *piVar11 = (int)&ppiStack_15c;
                piVar11[-1] = (int)&ppiStack_138;
                piVar11[-2] = 0x16d7163;
                func_0x01993890();
                piVar12 = piStack_148;
                ppiStack_15c = ppiStack_208;
                if (piStack_148 != (int *)0x0) {
                  LOCK();
                  piVar1 = piStack_148 + 1;
                  iVar2 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar2 == 0) {
                    iVar2 = *piStack_148;
                    piVar11[-1] = (int)piStack_148;
                    pcVar5 = *(code **)(iVar2 + 8);
                    piVar11[-2] = 0x16d718f;
                    (*pcVar5)();
                    piVar11[-1] = (int)piVar12;
                    piVar11[-2] = (int)&LAB_016d7197;
                    func_0x0197e1b0();
                  }
                }
                piVar12 = piStack_150;
                if (piStack_150 != (int *)0x0) {
                  LOCK();
                  piVar1 = piStack_150 + 1;
                  iVar2 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar2 == 0) {
                    iVar2 = *piStack_150;
                    piVar11[-1] = (int)piStack_150;
                    pcVar5 = *(code **)(iVar2 + 8);
                    piVar11[-2] = 0x16d71b7;
                    (*pcVar5)();
                    piVar11[-1] = (int)piVar12;
                    piVar11[-2] = (int)&LAB_016d71bf;
                    func_0x0197e1b0();
                  }
                }
                piVar11[-1] = (int)*ppiStack_120;
                piVar11[-2] = 0x16d71cf;
                cVar9 = func_0x0197ecf0();
                if ((cVar9 == '\0') && (*ppiStack_120 != (int *)0xfffffffb)) {
                  piVar11[-1] = (int)*ppiStack_120;
                  piVar11[-2] = 0x16d71e8;
                  cVar9 = func_0x0197e390();
                  if (cVar9 != '\x01' || (param_4 & 0x10) == 0) goto LAB_016d6ef4;
                }
                *piVar11 = (int)&ppiStack_138;
                piVar11[-1] = (int)param_1;
                piVar11[-2] = 0x16d7210;
                func_0x01993640();
              }
              piVar10 = piStack_124;
              ppiStack_138 = ppiStack_208;
              if (piStack_124 != (int *)0x0) {
                LOCK();
                piVar11 = piStack_124 + 1;
                iVar2 = *piVar11;
                *piVar11 = *piVar11 + -1;
                UNLOCK();
                if (iVar2 == 0) {
                  iVar2 = *piStack_124;
                  *ppppiVar16 = (int ***)piStack_124;
                  pcVar5 = *(code **)(iVar2 + 8);
                  ppppiVar16[-1] = (int ***)0x16d7c11;
                  (*pcVar5)();
                  *ppppiVar16 = (int ***)piVar10;
                  ppppiVar16[-1] = (int ***)&LAB_016d7c19;
                  func_0x0197e1b0();
                }
              }
              piVar10 = piStack_12c;
              if (piStack_12c != (int *)0x0) {
                LOCK();
                piVar11 = piStack_12c + 1;
                iVar2 = *piVar11;
                *piVar11 = *piVar11 + -1;
                UNLOCK();
                if (iVar2 == 0) {
                  iVar2 = *piStack_12c;
                  *ppppiVar16 = (int ***)piStack_12c;
                  pcVar5 = *(code **)(iVar2 + 8);
                  ppppiVar16[-1] = (int ***)0x16d7c39;
                  (*pcVar5)();
                  *ppppiVar16 = (int ***)piVar10;
                  ppppiVar16[-1] = (int ***)&LAB_016d7c41;
                  func_0x0197e1b0();
                }
              }
            }
            else {
              *piVar10 = 0x20;
              piVar10[-1] = 0x16d6b88;
              piVar11 = (int *)func_0x0197e0c0();
              piVar11[1] = 0;
              piVar11[2] = 0;
              *piVar11 = 0x1a1f240;
              piVar10[1] = param_3;
              *piVar10 = (int)(piVar11 + 3);
              piVar10[-1] = 0x16d6bb7;
              func_0x01982400();
              ppiStack_180 = (int **)0x0;
              ppiStack_17c = (int **)0x0;
              *piVar10 = (int)&piStack_1fc;
              piVar10[-1] = 0x16d6be5;
              ppiStack_15c = (int **)(piVar11 + 3);
              piStack_158 = piVar11;
              func_0x019909b0();
              piVar10[2] = (int)&piStack_1fc;
              piVar10[1] = (int)&ppiStack_15c;
              *piVar10 = (int)param_2;
              piVar10[-1] = (int)&ppiStack_138;
              piVar10[-2] = 0x16d6c0b;
              func_0x01990c40();
              ppppiVar16 = (int ****)(piVar10 + -2);
              piVar10[-1] = (int)&ppiStack_138;
              piVar10[-2] = (int)&ppiStack_114;
              piVar10[-3] = 0x16d6c23;
              func_0x01990d70();
              piVar11 = piStack_124;
              ppiStack_138 = ppiStack_20c;
              if (piStack_124 != (int *)0x0) {
                LOCK();
                piVar12 = piStack_124 + 1;
                iVar2 = *piVar12;
                *piVar12 = *piVar12 + -1;
                UNLOCK();
                if (iVar2 == 0) {
                  iVar2 = *piStack_124;
                  piVar10[-2] = (int)piStack_124;
                  pcVar5 = *(code **)(iVar2 + 8);
                  piVar10[-3] = 0x16d6c4f;
                  (*pcVar5)();
                  piVar10[-2] = (int)piVar11;
                  piVar10[-3] = (int)&LAB_016d6c57;
                  func_0x0197e1b0();
                }
              }
              piVar11 = piStack_12c;
              if (piStack_12c != (int *)0x0) {
                LOCK();
                piVar12 = piStack_12c + 1;
                iVar2 = *piVar12;
                *piVar12 = *piVar12 + -1;
                UNLOCK();
                if (iVar2 == 0) {
                  iVar2 = *piStack_12c;
                  piVar10[-2] = (int)piStack_12c;
                  pcVar5 = *(code **)(iVar2 + 8);
                  piVar10[-3] = 0x16d6c77;
                  (*pcVar5)();
                  piVar10[-2] = (int)piVar11;
                  piVar10[-3] = (int)&LAB_016d6c7f;
                  func_0x0197e1b0();
                }
              }
              piVar11 = piStack_1f8;
              if (piStack_1f8 != (int *)0x0) {
                LOCK();
                piVar12 = piStack_1f8 + 1;
                iVar2 = *piVar12;
                *piVar12 = *piVar12 + -1;
                UNLOCK();
                if (iVar2 == 0) {
                  iVar2 = *piStack_1f8;
                  piVar10[-2] = (int)piStack_1f8;
                  pcVar5 = *(code **)(iVar2 + 8);
                  piVar10[-3] = 0x16d6c9f;
                  (*pcVar5)();
                  piVar10[-2] = (int)piVar11;
                  piVar10[-3] = (int)&LAB_016d6ca7;
                  func_0x0197e1b0();
                }
              }
              piVar11 = piStack_158;
              if (piStack_158 != (int *)0x0) {
                LOCK();
                piVar12 = piStack_158 + 1;
                iVar2 = *piVar12;
                *piVar12 = *piVar12 + -1;
                UNLOCK();
                if (iVar2 == 0) {
                  iVar2 = *piStack_158;
                  piVar10[-2] = (int)piStack_158;
                  pcVar5 = *(code **)(iVar2 + 8);
                  piVar10[-3] = 0x16d6cc7;
                  (*pcVar5)();
                  piVar10[-2] = (int)piVar11;
                  piVar10[-3] = (int)&LAB_016d6ccf;
                  func_0x0197e1b0();
                }
              }
              ppiVar4 = ppiStack_17c;
              if ((int ***)ppiStack_17c != (int ***)0x0) {
                LOCK();
                pppiVar13 = (int ***)(ppiStack_17c + 1);
                ppiVar3 = *pppiVar13;
                *pppiVar13 = (int **)((int)*pppiVar13 + -1);
                UNLOCK();
                if (ppiVar3 == (int **)0x0) {
                  ppiVar3 = (int **)*ppiStack_17c;
                  piVar10[-2] = (int)ppiStack_17c;
                  pcVar5 = (code *)ppiVar3[2];
                  piVar10[-3] = 0x16d6cef;
                  (*pcVar5)();
                  piVar10[-2] = (int)ppiVar4;
                  piVar10[-3] = (int)&LAB_016d6cf7;
                  func_0x0197e1b0();
                }
              }
              piVar10[-1] = (int)*ppiStack_fc;
              piVar10[-2] = (int)_ZN20VagOperationDelegate30UNSUPPORTED_ECU_FEATURE_STATESE;
              piVar10[-3] = 0x16d6d11;
              cVar9 = func_0x01980c90();
              if (cVar9 != '\0') {
                piVar10[-2] = 6;
                piVar10[-3] = 0x16d6d25;
                ppiStack_180 = (int **)func_0x0197e0c0();
                ppiStack_17c = (int **)((int)ppiStack_180 + 6);
                *(undefined2 *)(ppiStack_180 + 1) = 0x101;
                *ppiStack_180 = (int *)&UNK_01010101;
                piVar10[-1] = (int)&ppiStack_180;
                piVar10[-2] = (int)&ppiStack_15c;
                piVar10[-3] = 0x16d6d60;
                ppiStack_178 = ppiStack_17c;
                func_0x01980cf0();
                piVar10[-2] = 0x1c;
                piVar10[-3] = 0x16d6d6c;
                piVar12 = (int *)func_0x0197e0c0();
                piVar10[-1] = (int)&ppiStack_15c;
                piVar10[-2] = (int)piVar12;
                piVar10[-3] = 0x16d6d80;
                func_0x0197fc40();
                ppiVar4 = ppiStack_20c;
                piStack_130 = piVar12 + 3;
                ppiStack_138 = ppiStack_20c;
                ppiStack_120 = &piStack_134;
                piStack_134 = (int *)0x1;
                LOCK();
                piVar12[1] = piVar12[1] + 1;
                UNLOCK();
                ppiStack_11c = &piStack_130;
                puStack_118 = &uStack_128;
                uStack_128 = 0;
                piStack_124 = (int *)0x0;
                LOCK();
                piVar11 = piVar12 + 1;
                iVar2 = *piVar11;
                *piVar11 = *piVar11 + -1;
                UNLOCK();
                piStack_12c = piVar12;
                if (iVar2 == 0) {
                  iVar2 = *piVar12;
                  piVar10[-2] = (int)piVar12;
                  pcVar5 = *(code **)(iVar2 + 8);
                  piVar10[-3] = 0x16d6df9;
                  (*pcVar5)();
                  piVar10[-2] = (int)piVar12;
                  piVar10[-3] = (int)&LAB_016d6e01;
                  func_0x0197e1b0();
                }
                piVar10[-1] = (int)&ppiStack_138;
                piVar10[-2] = (int)&ppiStack_114;
                piVar10[-3] = 0x16d6e19;
                func_0x01990d70();
                piVar11 = piStack_124;
                ppiStack_138 = ppiVar4;
                if (piStack_124 != (int *)0x0) {
                  LOCK();
                  piVar12 = piStack_124 + 1;
                  iVar2 = *piVar12;
                  *piVar12 = *piVar12 + -1;
                  UNLOCK();
                  if (iVar2 == 0) {
                    iVar2 = *piStack_124;
                    piVar10[-2] = (int)piStack_124;
                    pcVar5 = *(code **)(iVar2 + 8);
                    piVar10[-3] = 0x16d6e3f;
                    (*pcVar5)();
                    piVar10[-2] = (int)piVar11;
                    piVar10[-3] = (int)&LAB_016d6e47;
                    func_0x0197e1b0();
                  }
                }
                piVar11 = piStack_12c;
                if (piStack_12c != (int *)0x0) {
                  LOCK();
                  piVar12 = piStack_12c + 1;
                  iVar2 = *piVar12;
                  *piVar12 = *piVar12 + -1;
                  UNLOCK();
                  if (iVar2 == 0) {
                    iVar2 = *piStack_12c;
                    piVar10[-2] = (int)piStack_12c;
                    pcVar5 = *(code **)(iVar2 + 8);
                    piVar10[-3] = 0x16d6e6a;
                    (*pcVar5)();
                    piVar10[-2] = (int)piVar11;
                    piVar10[-3] = (int)&LAB_016d6e72;
                    func_0x0197e1b0();
                  }
                }
                piVar10[-2] = (int)&ppiStack_15c;
                piVar10[-3] = 0x16d6e80;
                func_0x0197fc50();
                piVar11 = piVar10 + -2;
                if ((int ***)ppiStack_180 != (int ***)0x0) {
                  ppiStack_17c = ppiStack_180;
                  piVar10[-2] = (int)ppiStack_180;
                  piVar10[-3] = (int)&LAB_016d6e98;
                  func_0x0197e150();
                  piVar11 = piVar10 + -2;
                }
                goto LAB_016d6e9e;
              }
              piVar10[-2] = (int)*ppiStack_fc;
              piVar10[-3] = 0x16d728d;
              cVar9 = func_0x0197ecf0();
              if ((cVar9 == '\0') && (*ppiStack_fc != (int *)0xfffffffb)) {
                piVar10[-2] = (int)*ppiStack_fc;
                piVar10[-3] = 0x16d72a6;
                cVar9 = func_0x0197e390();
                piVar11 = piVar10 + -2;
                if (cVar9 != '\x01' || (param_4 & 2) == 0) goto LAB_016d6e9e;
              }
              piVar10 = *ppiStack_fc;
              *param_1 = 0x1a1eab0;
              param_1[1] = piVar10;
              param_1[2] = 0;
              param_1[3] = 0;
              param_1[4] = 0;
              param_1[5] = 0;
              param_1[6] = param_1 + 1;
              param_1[7] = param_1 + 2;
              param_1[8] = param_1 + 4;
            }
            piVar10 = piStack_100;
            ppiStack_114 = ppiStack_20c;
            if (piStack_100 != (int *)0x0) {
              LOCK();
              piVar11 = piStack_100 + 1;
              iVar2 = *piVar11;
              *piVar11 = *piVar11 + -1;
              UNLOCK();
              if (iVar2 == 0) {
                iVar2 = *piStack_100;
                *ppppiVar16 = (int ***)piStack_100;
                pcVar5 = *(code **)(iVar2 + 8);
                ppppiVar16[-1] = (int ***)0x16d7c6d;
                (*pcVar5)();
                *ppppiVar16 = (int ***)piVar10;
                ppppiVar16[-1] = (int ***)&LAB_016d7c75;
                func_0x0197e1b0();
              }
            }
            piVar10 = piStack_108;
            if (piStack_108 != (int *)0x0) {
              LOCK();
              piVar11 = piStack_108 + 1;
              iVar2 = *piVar11;
              *piVar11 = *piVar11 + -1;
              UNLOCK();
              if (iVar2 == 0) {
                iVar2 = *piStack_108;
                *ppppiVar16 = (int ***)piStack_108;
                pcVar5 = *(code **)(iVar2 + 8);
                ppppiVar16[-1] = (int ***)0x16d7c95;
                (*pcVar5)();
                *ppppiVar16 = (int ***)piVar10;
                ppppiVar16[-1] = (int ***)&LAB_016d7c9d;
                func_0x0197e1b0();
              }
            }
          }
          piVar10 = piStack_dc;
          ppiStack_f0 = ppiStack_218;
          if (piStack_dc != (int *)0x0) {
            LOCK();
            piVar11 = piStack_dc + 1;
            iVar2 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if (iVar2 == 0) {
              iVar2 = *piStack_dc;
              *ppppiVar16 = (int ***)piStack_dc;
              pcVar5 = *(code **)(iVar2 + 8);
              ppppiVar16[-1] = (int ***)0x16d7cc9;
              (*pcVar5)();
              *ppppiVar16 = (int ***)piVar10;
              ppppiVar16[-1] = (int ***)&LAB_016d7cd1;
              func_0x0197e1b0();
            }
          }
          piVar10 = piStack_e4;
          if (piStack_e4 != (int *)0x0) {
            LOCK();
            piVar11 = piStack_e4 + 1;
            iVar2 = *piVar11;
            *piVar11 = *piVar11 + -1;
            UNLOCK();
            if (iVar2 == 0) {
              iVar2 = *piStack_e4;
              *ppppiVar16 = (int ***)piStack_e4;
              pcVar5 = *(code **)(iVar2 + 8);
              ppppiVar16[-1] = (int ***)0x16d7cf1;
              (*pcVar5)();
              *ppppiVar16 = (int ***)piVar10;
              ppppiVar16[-1] = (int ***)&LAB_016d7cf9;
              func_0x0197e1b0();
            }
          }
        }
        piVar10 = piStack_b8;
        ppiStack_cc = ppiStack_200;
        if (piStack_b8 != (int *)0x0) {
          LOCK();
          piVar11 = piStack_b8 + 1;
          iVar2 = *piVar11;
          *piVar11 = *piVar11 + -1;
          UNLOCK();
          if (iVar2 == 0) {
            iVar2 = *piStack_b8;
            *ppppiVar16 = (int ***)piStack_b8;
            pcVar5 = *(code **)(iVar2 + 8);
            ppppiVar16[-1] = (int ***)0x16d7d2b;
            (*pcVar5)();
            *ppppiVar16 = (int ***)piVar10;
            ppppiVar16[-1] = (int ***)0x16d7d33;
            func_0x0197e1b0();
          }
        }
        piVar10 = piStack_c0;
        if (piStack_c0 != (int *)0x0) {
          LOCK();
          piVar11 = piStack_c0 + 1;
          iVar2 = *piVar11;
          *piVar11 = *piVar11 + -1;
          UNLOCK();
          if (iVar2 == 0) {
            iVar2 = *piStack_c0;
            *ppppiVar16 = (int ***)piStack_c0;
            pcVar5 = *(code **)(iVar2 + 8);
            ppppiVar16[-1] = (int ***)0x16d7d5f;
            (*pcVar5)();
            *ppppiVar16 = (int ***)piVar10;
            ppppiVar16[-1] = (int ***)&LAB_016d7d67;
            func_0x0197e1b0();
          }
        }
      }
      else {
        *piVar11 = 0x20;
        piVar11[-1] = 0x16d650e;
        piVar10 = (int *)func_0x0197e0c0();
        piVar10[1] = 0;
        piVar10[2] = 0;
        *piVar10 = 0x1a1f1f0;
        piVar11[1] = param_3;
        *piVar11 = (int)(piVar10 + 3);
        piVar11[-1] = 0x16d653d;
        func_0x01982360();
        ppiStack_114 = (int **)0x0;
        piStack_110 = (int *)0x0;
        *piVar11 = (int)&ppiStack_138;
        piVar11[-1] = 0x16d656b;
        ppiStack_f0 = (int **)(piVar10 + 3);
        piStack_ec = piVar10;
        func_0x019909b0();
        piVar11[2] = (int)&ppiStack_138;
        piVar11[1] = (int)&ppiStack_f0;
        *piVar11 = (int)param_2;
        piVar11[-1] = (int)&ppiStack_cc;
        piVar11[-2] = 0x16d6591;
        func_0x01990cb0();
        piVar10 = piVar11 + -2;
        ppppiVar16 = (int ****)(piVar11 + -2);
        piVar11[-1] = (int)&ppiStack_cc;
        piVar11[-2] = (int)&ppiStack_a8;
        piVar11[-3] = 0x16d65a6;
        func_0x01991240();
        piVar12 = piStack_b8;
        ppiStack_cc = ppiStack_200;
        if (piStack_b8 != (int *)0x0) {
          LOCK();
          piVar1 = piStack_b8 + 1;
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 0) {
            iVar2 = *piStack_b8;
            piVar11[-2] = (int)piStack_b8;
            pcVar5 = *(code **)(iVar2 + 8);
            piVar11[-3] = 0x16d65d2;
            (*pcVar5)();
            piVar11[-2] = (int)piVar12;
            piVar11[-3] = (int)&LAB_016d65da;
            func_0x0197e1b0();
          }
        }
        piVar12 = piStack_c0;
        if (piStack_c0 != (int *)0x0) {
          LOCK();
          piVar1 = piStack_c0 + 1;
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 0) {
            iVar2 = *piStack_c0;
            piVar11[-2] = (int)piStack_c0;
            pcVar5 = *(code **)(iVar2 + 8);
            piVar11[-3] = 0x16d65fa;
            (*pcVar5)();
            piVar11[-2] = (int)piVar12;
            piVar11[-3] = (int)&LAB_016d6602;
            func_0x0197e1b0();
          }
        }
        piVar12 = piStack_134;
        if (piStack_134 != (int *)0x0) {
          LOCK();
          piVar1 = piStack_134 + 1;
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 0) {
            iVar2 = *piStack_134;
            piVar11[-2] = (int)piStack_134;
            pcVar5 = *(code **)(iVar2 + 8);
            piVar11[-3] = 0x16d6622;
            (*pcVar5)();
            piVar11[-2] = (int)piVar12;
            piVar11[-3] = (int)&LAB_016d662a;
            func_0x0197e1b0();
          }
        }
        piVar12 = piStack_ec;
        if (piStack_ec != (int *)0x0) {
          LOCK();
          piVar1 = piStack_ec + 1;
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 0) {
            iVar2 = *piStack_ec;
            piVar11[-2] = (int)piStack_ec;
            pcVar5 = *(code **)(iVar2 + 8);
            piVar11[-3] = 0x16d664a;
            (*pcVar5)();
            piVar11[-2] = (int)piVar12;
            piVar11[-3] = (int)&LAB_016d6652;
            func_0x0197e1b0();
          }
        }
        piVar12 = piStack_110;
        if (piStack_110 != (int *)0x0) {
          LOCK();
          piVar1 = piStack_110 + 1;
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 0) {
            iVar2 = *piStack_110;
            piVar11[-2] = (int)piStack_110;
            pcVar5 = *(code **)(iVar2 + 8);
            piVar11[-3] = 0x16d6672;
            (*pcVar5)();
            piVar11[-2] = (int)piVar12;
            piVar11[-3] = (int)&LAB_016d667a;
            func_0x0197e1b0();
          }
        }
        piVar11[-2] = (int)*pppiStack_90;
        piVar11[-3] = 0x16d668a;
        cVar9 = func_0x0197ecf0();
        if ((cVar9 == '\0') && (*pppiStack_90 != (int **)0xfffffffb)) {
          piVar11[-2] = (int)*pppiStack_90;
          piVar11[-3] = 0x16d66a3;
          cVar9 = func_0x0197e390();
          if (cVar9 != '\x01' || (param_4 & 0x40) == 0) goto LAB_016d5edd;
        }
        ppiVar4 = *pppiStack_90;
        *param_1 = 0x1a1eab0;
        param_1[1] = ppiVar4;
        param_1[2] = 0;
        param_1[3] = 0;
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = param_1 + 1;
        param_1[7] = param_1 + 2;
        param_1[8] = param_1 + 4;
      }
      piVar10 = piStack_94;
      ppiStack_a8 = ppiStack_200;
      if (piStack_94 != (int *)0x0) {
        LOCK();
        piVar11 = piStack_94 + 1;
        iVar2 = *piVar11;
        *piVar11 = *piVar11 + -1;
        UNLOCK();
        if (iVar2 == 0) {
          iVar2 = *piStack_94;
          *ppppiVar16 = (int ***)piStack_94;
          pcVar5 = *(code **)(iVar2 + 8);
          ppppiVar16[-1] = (int ***)0x16d7d99;
          (*pcVar5)();
          *ppppiVar16 = (int ***)piVar10;
          ppppiVar16[-1] = (int ***)0x16d7da1;
          func_0x0197e1b0();
        }
      }
      piVar10 = piStack_9c;
      if (piStack_9c != (int *)0x0) {
        LOCK();
        piVar11 = piStack_9c + 1;
        iVar2 = *piVar11;
        *piVar11 = *piVar11 + -1;
        UNLOCK();
        if (iVar2 == 0) {
          iVar2 = *piStack_9c;
          *ppppiVar16 = (int ***)piStack_9c;
          pcVar5 = *(code **)(iVar2 + 8);
          ppppiVar16[-1] = (int ***)0x16d7dcd;
          (*pcVar5)();
          *ppppiVar16 = (int ***)piVar10;
          ppppiVar16[-1] = (int ***)&LAB_016d7dd5;
          func_0x0197e1b0();
        }
      }
    }
    else {
      *piVar10 = 0x20;
      piVar10[-1] = 0x16d6320;
      pppiVar13 = (int ***)func_0x0197e0c0();
      pppiVar13[1] = (int **)0x0;
      pppiVar13[2] = (int **)0x0;
      *pppiVar13 = (int **)0x1a1f1c8;
      piVar10[1] = param_3;
      *piVar10 = (int)(pppiVar13 + 3);
      piVar10[-1] = 0x16d634f;
      func_0x019823e0();
      ppiStack_f0 = (int **)0x0;
      piStack_ec = (int *)0x0;
      *piVar10 = (int)&ppiStack_114;
      piVar10[-1] = 0x16d637d;
      ppiStack_cc = (int **)(pppiVar13 + 3);
      ppiStack_c8 = (int **)pppiVar13;
      func_0x019909b0();
      piVar10[2] = (int)&ppiStack_114;
      piVar10[1] = (int)&ppiStack_cc;
      *piVar10 = (int)param_2;
      piVar10[-1] = (int)&ppiStack_a8;
      piVar10[-2] = 0x16d63a3;
      func_0x01990cb0();
      piVar11 = piVar10 + -2;
      ppppiVar16 = (int ****)(piVar10 + -2);
      piVar10[-1] = (int)&ppiStack_a8;
      piVar10[-2] = (int)&ppiStack_84;
      piVar10[-3] = 0x16d63b5;
      func_0x01991240();
      piVar12 = piStack_94;
      ppiStack_a8 = ppiStack_200;
      if (piStack_94 != (int *)0x0) {
        LOCK();
        piVar1 = piStack_94 + 1;
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 0) {
          iVar2 = *piStack_94;
          piVar10[-2] = (int)piStack_94;
          pcVar5 = *(code **)(iVar2 + 8);
          piVar10[-3] = 0x16d63e1;
          (*pcVar5)();
          piVar10[-2] = (int)piVar12;
          piVar10[-3] = (int)&LAB_016d63e9;
          func_0x0197e1b0();
        }
      }
      piVar12 = piStack_9c;
      if (piStack_9c != (int *)0x0) {
        LOCK();
        piVar1 = piStack_9c + 1;
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 0) {
          iVar2 = *piStack_9c;
          piVar10[-2] = (int)piStack_9c;
          pcVar5 = *(code **)(iVar2 + 8);
          piVar10[-3] = 0x16d6409;
          (*pcVar5)();
          piVar10[-2] = (int)piVar12;
          piVar10[-3] = (int)&LAB_016d6411;
          func_0x0197e1b0();
        }
      }
      piVar12 = piStack_110;
      if (piStack_110 != (int *)0x0) {
        LOCK();
        piVar1 = piStack_110 + 1;
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 0) {
          iVar2 = *piStack_110;
          piVar10[-2] = (int)piStack_110;
          pcVar5 = *(code **)(iVar2 + 8);
          piVar10[-3] = 0x16d6431;
          (*pcVar5)();
          piVar10[-2] = (int)piVar12;
          piVar10[-3] = (int)&LAB_016d6439;
          func_0x0197e1b0();
        }
      }
      ppiVar4 = ppiStack_c8;
      if ((int ***)ppiStack_c8 != (int ***)0x0) {
        LOCK();
        pppiVar13 = (int ***)(ppiStack_c8 + 1);
        ppiVar3 = *pppiVar13;
        *pppiVar13 = (int **)((int)*pppiVar13 + -1);
        UNLOCK();
        if (ppiVar3 == (int **)0x0) {
          ppiVar3 = (int **)*ppiStack_c8;
          piVar10[-2] = (int)ppiStack_c8;
          pcVar5 = (code *)ppiVar3[2];
          piVar10[-3] = 0x16d6459;
          (*pcVar5)();
          piVar10[-2] = (int)ppiVar4;
          piVar10[-3] = (int)&LAB_016d6461;
          func_0x0197e1b0();
        }
      }
      piVar12 = piStack_ec;
      if (piStack_ec != (int *)0x0) {
        LOCK();
        piVar1 = piStack_ec + 1;
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 0) {
          iVar2 = *piStack_ec;
          piVar10[-2] = (int)piStack_ec;
          pcVar5 = *(code **)(iVar2 + 8);
          piVar10[-3] = 0x16d6481;
          (*pcVar5)();
          piVar10[-2] = (int)piVar12;
          piVar10[-3] = (int)&LAB_016d6489;
          func_0x0197e1b0();
        }
      }
      piVar10[-2] = (int)*pppiStack_6c;
      piVar10[-3] = 0x16d6496;
      cVar9 = func_0x0197ecf0();
      if ((cVar9 == '\0') && (*pppiStack_6c != (int **)0xfffffffb)) {
        piVar10[-2] = (int)*pppiStack_6c;
        piVar10[-3] = 0x16d64ac;
        cVar9 = func_0x0197e390();
        if (cVar9 != '\x01' || (param_4 & 0x20) == 0) goto LAB_016d5e9a;
      }
      ppiVar4 = *pppiStack_6c;
      *param_1 = 0x1a1eab0;
      param_1[1] = ppiVar4;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = param_1 + 1;
      param_1[7] = param_1 + 2;
      param_1[8] = param_1 + 4;
    }
    piVar10 = piStack_70;
    ppiStack_84 = ppiStack_200;
    if (piStack_70 != (int *)0x0) {
      LOCK();
      piVar11 = piStack_70 + 1;
      iVar2 = *piVar11;
      *piVar11 = *piVar11 + -1;
      UNLOCK();
      if (iVar2 == 0) {
        iVar2 = *piStack_70;
        *ppppiVar16 = (int ***)piStack_70;
        pcVar5 = *(code **)(iVar2 + 8);
        ppppiVar16[-1] = (int ***)0x16d7e01;
        (*pcVar5)();
        *ppppiVar16 = (int ***)piVar10;
        ppppiVar16[-1] = (int ***)0x16d7e09;
        func_0x0197e1b0();
      }
    }
    piVar10 = piStack_78;
    if (piStack_78 != (int *)0x0) {
      LOCK();
      piVar11 = piStack_78 + 1;
      iVar2 = *piVar11;
      *piVar11 = *piVar11 + -1;
      UNLOCK();
      if (iVar2 == 0) {
        iVar2 = *piStack_78;
        *ppppiVar16 = (int ***)piStack_78;
        pcVar5 = *(code **)(iVar2 + 8);
        ppppiVar16[-1] = (int ***)0x16d7e32;
        (*pcVar5)();
        *ppppiVar16 = (int ***)piVar10;
        ppppiVar16[-1] = (int ***)&LAB_016d7e3a;
        func_0x0197e1b0();
      }
    }
  }
  else {
    *ppppiVar15 = (int ***)0x20;
    ppppiVar15[-1] = (int ***)0x16d6141;
    pppiVar13 = (int ***)func_0x0197e0c0();
    pppiVar13[1] = (int **)0x0;
    pppiVar13[2] = (int **)0x0;
    *pppiVar13 = (int **)0x1a1f1a0;
    ppppiVar15[1] = (int ***)param_3;
    *ppppiVar15 = pppiVar13 + 3;
    ppppiVar15[-1] = (int ***)0x16d6170;
    func_0x019823a0();
    ppiStack_cc = (int **)0x0;
    ppiStack_c8 = (int **)0x0;
    *ppppiVar15 = &ppiStack_f0;
    ppppiVar15[-1] = (int ***)0x16d619e;
    ppiStack_a8 = (int **)(pppiVar13 + 3);
    ppiStack_a4 = (int **)pppiVar13;
    func_0x019909b0();
    ppppiVar15[2] = &ppiStack_f0;
    ppppiVar15[1] = &ppiStack_a8;
    *ppppiVar15 = (int ***)param_2;
    ppppiVar15[-1] = &ppiStack_84;
    ppppiVar15[-2] = (int ***)0x16d61c1;
    func_0x01990cb0();
    piVar10 = (int *)(ppppiVar15 + -2);
    ppppiVar16 = ppppiVar15 + -2;
    ppppiVar15[-1] = &ppiStack_84;
    ppppiVar15[-2] = &ppiStack_60;
    ppppiVar15[-3] = (int ***)0x16d61d3;
    func_0x01991240();
    piVar11 = piStack_70;
    ppiStack_84 = ppiStack_200;
    if (piStack_70 != (int *)0x0) {
      LOCK();
      piVar12 = piStack_70 + 1;
      iVar2 = *piVar12;
      *piVar12 = *piVar12 + -1;
      UNLOCK();
      if (iVar2 == 0) {
        iVar2 = *piStack_70;
        ppppiVar15[-2] = (int ***)piStack_70;
        pcVar5 = *(code **)(iVar2 + 8);
        ppppiVar15[-3] = (int ***)0x16d61f9;
        (*pcVar5)();
        ppppiVar15[-2] = (int ***)piVar11;
        ppppiVar15[-3] = (int ***)&LAB_016d6201;
        func_0x0197e1b0();
      }
    }
    piVar11 = piStack_78;
    if (piStack_78 != (int *)0x0) {
      LOCK();
      piVar12 = piStack_78 + 1;
      iVar2 = *piVar12;
      *piVar12 = *piVar12 + -1;
      UNLOCK();
      if (iVar2 == 0) {
        iVar2 = *piStack_78;
        ppppiVar15[-2] = (int ***)piStack_78;
        pcVar5 = *(code **)(iVar2 + 8);
        ppppiVar15[-3] = (int ***)0x16d621e;
        (*pcVar5)();
        ppppiVar15[-2] = (int ***)piVar11;
        ppppiVar15[-3] = (int ***)&LAB_016d6226;
        func_0x0197e1b0();
      }
    }
    piVar11 = piStack_ec;
    if (piStack_ec != (int *)0x0) {
      LOCK();
      piVar12 = piStack_ec + 1;
      iVar2 = *piVar12;
      *piVar12 = *piVar12 + -1;
      UNLOCK();
      if (iVar2 == 0) {
        iVar2 = *piStack_ec;
        ppppiVar15[-2] = (int ***)piStack_ec;
        pcVar5 = *(code **)(iVar2 + 8);
        ppppiVar15[-3] = (int ***)0x16d6246;
        (*pcVar5)();
        ppppiVar15[-2] = (int ***)piVar11;
        ppppiVar15[-3] = (int ***)&LAB_016d624e;
        func_0x0197e1b0();
      }
    }
    ppiVar4 = ppiStack_a4;
    if ((int ***)ppiStack_a4 != (int ***)0x0) {
      LOCK();
      pppiVar13 = (int ***)(ppiStack_a4 + 1);
      ppiVar3 = *pppiVar13;
      *pppiVar13 = (int **)((int)*pppiVar13 + -1);
      UNLOCK();
      if (ppiVar3 == (int **)0x0) {
        ppiVar3 = (int **)*ppiStack_a4;
        ppppiVar15[-2] = (int ***)ppiStack_a4;
        pcVar5 = (code *)ppiVar3[2];
        ppppiVar15[-3] = (int ***)0x16d626e;
        (*pcVar5)();
        ppppiVar15[-2] = (int ***)ppiVar4;
        ppppiVar15[-3] = (int ***)&LAB_016d6276;
        func_0x0197e1b0();
      }
    }
    ppiVar4 = ppiStack_c8;
    if ((int ***)ppiStack_c8 != (int ***)0x0) {
      LOCK();
      pppiVar13 = (int ***)(ppiStack_c8 + 1);
      ppiVar3 = *pppiVar13;
      *pppiVar13 = (int **)((int)*pppiVar13 + -1);
      UNLOCK();
      if (ppiVar3 == (int **)0x0) {
        ppiVar3 = (int **)*ppiStack_c8;
        ppppiVar15[-2] = (int ***)ppiStack_c8;
        pcVar5 = (code *)ppiVar3[2];
        ppppiVar15[-3] = (int ***)0x16d6296;
        (*pcVar5)();
        ppppiVar15[-2] = (int ***)ppiVar4;
        ppppiVar15[-3] = (int ***)&LAB_016d629e;
        func_0x0197e1b0();
      }
    }
    ppppiVar15[-2] = (int ***)*piStack_48;
    ppppiVar15[-3] = (int ***)0x16d62ab;
    cVar9 = func_0x0197ecf0();
    if ((cVar9 == '\0') && (*piStack_48 != -5)) {
      ppppiVar15[-2] = (int ***)*piStack_48;
      ppppiVar15[-3] = (int ***)0x16d62c1;
      cVar9 = func_0x0197e390();
      if (cVar9 != '\x01' || (param_4 & 4) == 0) goto LAB_016d5e6f;
    }
    iVar2 = *piStack_48;
    *param_1 = 0x1a1eab0;
    param_1[1] = iVar2;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = param_1 + 1;
    param_1[7] = param_1 + 2;
    param_1[8] = param_1 + 4;
  }
  ppiVar4 = ppiStack_4c;
  ppiStack_60 = ppiStack_200;
  if ((int ***)ppiStack_4c != (int ***)0x0) {
    LOCK();
    pppiVar13 = (int ***)(ppiStack_4c + 1);
    ppiVar3 = *pppiVar13;
    *pppiVar13 = (int **)((int)*pppiVar13 + -1);
    UNLOCK();
    if (ppiVar3 == (int **)0x0) {
      ppiVar3 = (int **)*ppiStack_4c;
      *ppppiVar16 = (int ***)ppiStack_4c;
      pcVar5 = (code *)ppiVar3[2];
      ppppiVar16[-1] = (int ***)0x16d7e66;
      (*pcVar5)();
      *ppppiVar16 = (int ***)ppiVar4;
      ppppiVar16[-1] = (int ***)0x16d7e6e;
      func_0x0197e1b0();
    }
  }
  ppiVar4 = ppiStack_54;
  if ((int ***)ppiStack_54 != (int ***)0x0) {
    LOCK();
    pppiVar13 = (int ***)(ppiStack_54 + 1);
    ppiVar3 = *pppiVar13;
    *pppiVar13 = (int **)((int)*pppiVar13 + -1);
    UNLOCK();
    if (ppiVar3 == (int **)0x0) {
      ppiVar3 = (int **)*ppiStack_54;
      *ppppiVar16 = (int ***)ppiStack_54;
      pcVar5 = (code *)ppiVar3[2];
      ppppiVar16[-1] = (int ***)0x16d7e97;
      (*pcVar5)();
      *ppppiVar16 = (int ***)ppiVar4;
      ppppiVar16[-1] = (int ***)&LAB_016d7e9f;
      func_0x0197e1b0();
    }
  }
LAB_016d7ea5:
  piVar10 = piStack_28;
  ppiStack_3c = ppiStack_200;
  if (piStack_28 != (int *)0x0) {
    LOCK();
    piVar11 = piStack_28 + 1;
    iVar2 = *piVar11;
    *piVar11 = *piVar11 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      iVar2 = *piStack_28;
      *ppppiVar16 = (int ***)piStack_28;
      pcVar5 = *(code **)(iVar2 + 8);
      ppppiVar16[-1] = (int ***)0x16d7ec5;
      (*pcVar5)();
      *ppppiVar16 = (int ***)piVar10;
      ppppiVar16[-1] = (int ***)&LAB_016d7ecd;
      func_0x0197e1b0();
    }
  }
  piVar10 = piStack_30;
  if (piStack_30 != (int *)0x0) {
    LOCK();
    piVar11 = piStack_30 + 1;
    iVar2 = *piVar11;
    *piVar11 = *piVar11 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      iVar2 = *piStack_30;
      *ppppiVar16 = (int ***)piStack_30;
      pcVar5 = *(code **)(iVar2 + 8);
      ppppiVar16[-1] = (int ***)0x16d7eea;
      (*pcVar5)();
      *ppppiVar16 = (int ***)piVar10;
      ppppiVar16[-1] = (int ***)&LAB_016d7ef2;
      func_0x0197e1b0();
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
  ppppiVar16[-1] = (int ***)0x16d84e9;
  func_0x0197e230();
  pcVar5 = (code *)swi(3);
  puVar14 = (undefined4 *)(*pcVar5)();
  return puVar14;
}



/* Entry instruction preview:
 * 016c5de0: PUSH EBP
 */
