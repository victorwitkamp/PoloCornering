/* Target GetSubmoduleIdsOverUdsCommand_processPayload @ 00c4e9b0 (Ghidra 00c5e9b0) */
/* Size: 1129 bytes */
/* Reason: UDS submodule-ID payload parser */
/* Function: _ZNK29GetSubmoduleIdsOverUdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 00c4e9b0 */

/* Symbols at target:
 * Function _ZNK29GetSubmoduleIdsOverUdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 */


undefined4 *
_ZNK29GetSubmoduleIdsOverUdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
          (undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int in_GS_OFFSET;
  uint uStack_54;
  int iStack_4c;
  undefined1 auStack_48 [16];
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  iStack_4c = *param_3;
  if (param_3[1] - iStack_4c == 0xc) {
    iStack_20 = 0;
    iStack_1c = 0;
    uStack_18 = 0;
    puStack_2c = (undefined1 *)0x0;
    puStack_28 = (undefined1 *)0x0;
    puStack_24 = (undefined1 *)0x0;
    puStack_38 = (undefined1 *)0x0;
    puStack_34 = (undefined1 *)0x0;
    puStack_30 = (undefined1 *)0x0;
    uStack_54 = 0;
    do {
      puVar4 = puStack_2c;
      if (puStack_28 < puStack_24) {
        *puStack_28 = *(undefined1 *)(iStack_4c + uStack_54);
        puVar9 = puStack_28 + 1;
      }
      else {
        uVar12 = (int)puStack_28 - (int)puStack_2c;
        uVar11 = uVar12 + 1;
        if ((int)uVar11 < 0) {
          if (*(int *)(in_GS_OFFSET + 0x14) != iStack_14) goto LAB_00c5ee14;
          func_0x00bce8c0(&puStack_2c);
          goto LAB_00c5ed70;
        }
        uVar3 = ((int)puStack_24 - (int)puStack_2c) * 2;
        if (uVar11 < uVar3) {
          uVar11 = uVar3;
        }
        if (0x3ffffffe < (uint)((int)puStack_24 - (int)puStack_2c)) {
          uVar11 = 0x7fffffff;
        }
        if (uVar11 == 0) {
          puVar5 = (undefined1 *)0x0;
        }
        else {
          puVar5 = (undefined1 *)func_0x0197e0c0(uVar11);
        }
        puVar5[uVar12] = *(undefined1 *)(iStack_4c + uStack_54);
        puVar9 = puVar5 + uVar12 + 1;
        func_0x0197e310(puVar5,puVar4,uVar12);
        puStack_2c = puVar5;
        puStack_24 = puVar5 + uVar11;
        if (puVar4 != (undefined1 *)0x0) {
          func_0x0197e150(puVar4);
        }
      }
      uStack_54 = uStack_54 + 1;
      iStack_4c = *param_3;
      uVar11 = (uint)(param_3[1] - iStack_4c) >> 1;
      puStack_28 = puVar9;
    } while (uStack_54 < uVar11);
    if (uVar11 < (uint)(param_3[1] - iStack_4c)) {
      do {
        puVar4 = puStack_38;
        if (puStack_34 < puStack_30) {
          *puStack_34 = *(undefined1 *)(iStack_4c + uVar11);
          puVar9 = puStack_34 + 1;
        }
        else {
          iVar10 = (int)puStack_34 - (int)puStack_38;
          uVar12 = iVar10 + 1;
          if ((int)uVar12 < 0) goto LAB_00c5ed70;
          uVar3 = ((int)puStack_30 - (int)puStack_38) * 2;
          if (uVar12 < uVar3) {
            uVar12 = uVar3;
          }
          if (0x3ffffffe < (uint)((int)puStack_30 - (int)puStack_38)) {
            uVar12 = 0x7fffffff;
          }
          if (uVar12 == 0) {
            puVar5 = (undefined1 *)0x0;
          }
          else {
            puVar5 = (undefined1 *)func_0x0197e0c0(uVar12);
          }
          puVar5[iVar10] = *(undefined1 *)(iStack_4c + uVar11);
          puVar9 = puVar5 + iVar10 + 1;
          func_0x0197e310(puVar5,puVar4,iVar10);
          puStack_38 = puVar5;
          puStack_30 = puVar5 + uVar12;
          if (puVar4 != (undefined1 *)0x0) {
            func_0x0197e150(puVar4);
          }
        }
        uVar11 = uVar11 + 1;
        iStack_4c = *param_3;
        puStack_34 = puVar9;
      } while (uVar11 < (uint)(param_3[1] - iStack_4c));
    }
    (**(code **)(*param_2 + 0x1c))(param_2,&iStack_20,&puStack_2c,0);
    (**(code **)(*param_2 + 0x1c))(param_2,&iStack_20,&puStack_38,1);
    func_0x0197fc30(auStack_48,&iStack_20);
    piVar6 = (int *)func_0x0197e0c0(0x1c);
    func_0x0197fc40(piVar6,auStack_48);
    *param_1 = 0x199df34;
    param_1[1] = 1;
    param_1[2] = piVar6 + 3;
    param_1[3] = piVar6;
    LOCK();
    piVar6[1] = piVar6[1] + 1;
    UNLOCK();
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = param_1 + 1;
    param_1[7] = param_1 + 2;
    param_1[8] = param_1 + 4;
    LOCK();
    piVar1 = piVar6 + 1;
    iVar10 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar10 == 0) {
      (**(code **)(*piVar6 + 8))(piVar6);
      func_0x0197e1b0(piVar6);
    }
    func_0x0197fc50(auStack_48);
    if (puStack_38 != (undefined1 *)0x0) {
      puStack_34 = puStack_38;
      func_0x0197e150(puStack_38);
    }
    if (puStack_2c != (undefined1 *)0x0) {
      puStack_28 = puStack_2c;
      func_0x0197e150(puStack_2c);
    }
    if (iStack_20 != 0) {
      iStack_1c = iStack_20;
      func_0x0197e150(iStack_20);
    }
  }
  else {
    func_0x0197e300(&UNK_00714556);
    *param_1 = 0x199df34;
    param_1[1] = 0xfffffffa;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = param_1 + 1;
    param_1[7] = param_1 + 2;
    param_1[8] = param_1 + 4;
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
LAB_00c5ee14:
  func_0x0197e230();
  pcVar2 = (code *)swi(3);
  puVar8 = (undefined4 *)(*pcVar2)();
  return puVar8;
LAB_00c5ed70:
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    uVar7 = func_0x00bce8c0(&puStack_38);
    func_0x0197e150(uVar12);
    func_0x0197fc50(auStack_48);
    if (puStack_38 != (undefined1 *)0x0) {
      puStack_34 = puStack_38;
      func_0x0197e150(puStack_38);
    }
    if (puStack_2c != (undefined1 *)0x0) {
      puStack_28 = puStack_2c;
      func_0x0197e150(puStack_2c);
    }
    if (iStack_20 != 0) {
      iStack_1c = iStack_20;
      func_0x0197e150(iStack_20);
    }
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      func_0x0197a750(uVar7);
    }
  }
  goto LAB_00c5ee14;
}



/* Entry instruction preview:
 * 00c4e9b0: PUSH EBP
 */
