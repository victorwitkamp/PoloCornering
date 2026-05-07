/* Target VagOperationDelegate_validateVagCanEcuInfo @ 016c5b00 (Ghidra 016d5b00) */
/* Size: 725 bytes */
/* Reason: validates VAG CAN ECU-info results */
/* Function: _ZN20VagOperationDelegate21validateVagCanEcuInfoEP3EcuRK6ResultI10VagEcuInfovE @ 016c5b00 */

/* Symbols at target:
 * Function _ZN20VagOperationDelegate21validateVagCanEcuInfoEP3EcuRK6ResultI10VagEcuInfovE
 */


bool _ZN20VagOperationDelegate21validateVagCanEcuInfoEP3EcuRK6ResultI10VagEcuInfovE
               (int *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  code *pcVar10;
  undefined1 uVar11;
  int iVar12;
  uint uVar13;
  byte *pbVar14;
  undefined *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int in_GS_OFFSET;
  bool bVar19;
  undefined4 auStack_38 [3];
  int *piStack_2c;
  int *piStack_24;
  int *piStack_20;
  int *piStack_1c;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  (**(code **)(*param_1 + 0x1f8))(auStack_38,param_1,param_2);
  bVar19 = true;
  if (*piStack_20 != 1) goto LAB_016d5cef;
  piVar3 = *(int **)(*piStack_1c + 0x10);
  piVar4 = *(int **)(*piStack_1c + 0x14);
  if (piVar4 != (int *)0x0) {
    LOCK();
    piVar4[1] = piVar4[1] + 1;
    UNLOCK();
  }
  piVar5 = *(int **)(**(int **)(param_3 + 0x1c) + 0x10);
  piVar6 = *(int **)(**(int **)(param_3 + 0x1c) + 0x14);
  if (piVar6 != (int *)0x0) {
    LOCK();
    piVar6[1] = piVar6[1] + 1;
    UNLOCK();
  }
  bVar19 = true;
  if (piVar3 != (int *)0x0) {
    if (piVar5 == (int *)0x0) {
      puVar15 = &UNK_008c15f3;
    }
    else {
      iVar7 = *piVar3;
      iVar12 = piVar3[1] - iVar7;
      iVar8 = *piVar5;
      if (iVar12 == piVar5[1] - iVar8) {
        if (piVar3[1] != iVar7) {
          uVar13 = iVar12 >> 3;
          uVar18 = 0;
          do {
            pbVar9 = *(byte **)(*(int *)(iVar7 + uVar18 * 8) + 8);
            pbVar14 = *(byte **)(*(int *)(iVar8 + uVar18 * 8) + 8);
            bVar1 = *pbVar9;
            uVar17 = *(uint *)(pbVar9 + 4);
            if ((bVar1 & 1) == 0) {
              uVar17 = (uint)(bVar1 >> 1);
            }
            bVar2 = *pbVar14;
            if ((bVar2 & 1) == 0) {
              uVar16 = (uint)(bVar2 >> 1);
            }
            else {
              uVar16 = *(uint *)(pbVar14 + 4);
            }
            if (uVar17 != uVar16) {
LAB_016d5d62:
              func_0x0197e300(&UNK_0099690e,uVar18);
              bVar19 = false;
              goto LAB_016d5ca0;
            }
            if ((bVar2 & 1) == 0) {
              pbVar14 = pbVar14 + 1;
            }
            else {
              pbVar14 = *(byte **)(pbVar14 + 8);
            }
            if ((bVar1 & 1) == 0) {
              if (1 < bVar1) {
                uVar17 = 0;
                do {
                  if (pbVar9[uVar17 + 1] != pbVar14[uVar17]) goto LAB_016d5d62;
                  uVar17 = uVar17 + 1;
                } while (bVar1 >> 1 != uVar17);
              }
            }
            else {
              iVar12 = func_0x0197e980(*(undefined4 *)(pbVar9 + 8),pbVar14,*(uint *)(pbVar9 + 4));
              if (iVar12 != 0) goto LAB_016d5d62;
            }
            uVar18 = uVar18 + 1;
          } while (uVar18 != uVar13 + (uVar13 == 0));
          bVar19 = uVar13 <= uVar18;
        }
        goto LAB_016d5ca0;
      }
      puVar15 = &UNK_008497ef;
    }
    func_0x0197e300(puVar15);
    bVar19 = false;
  }
LAB_016d5ca0:
  if (piVar6 != (int *)0x0) {
    LOCK();
    piVar3 = piVar6 + 1;
    iVar7 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar7 == 0) {
      (**(code **)(*piVar6 + 8))(piVar6);
      func_0x0197e1b0(piVar6);
    }
  }
  if (piVar4 != (int *)0x0) {
    LOCK();
    piVar3 = piVar4 + 1;
    iVar7 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar7 == 0) {
      (**(code **)(*piVar4 + 8))(piVar4);
      func_0x0197e1b0(piVar4);
    }
  }
LAB_016d5cef:
  auStack_38[0] = 0x1a1eab0;
  if (piStack_24 != (int *)0x0) {
    LOCK();
    piVar3 = piStack_24 + 1;
    iVar7 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar7 == 0) {
      (**(code **)(*piStack_24 + 8))(piStack_24);
      func_0x0197e1b0(piStack_24);
    }
  }
  if (piStack_2c != (int *)0x0) {
    LOCK();
    piVar3 = piStack_2c + 1;
    iVar7 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar7 == 0) {
      (**(code **)(*piStack_2c + 8))(piStack_2c);
      func_0x0197e1b0(piStack_2c);
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) != iStack_14) {
    func_0x0197e230();
    pcVar10 = (code *)swi(3);
    uVar11 = (*pcVar10)();
    return (bool)uVar11;
  }
  return bVar19;
}



/* Entry instruction preview:
 * 016c5b00: PUSH EBP
 */
