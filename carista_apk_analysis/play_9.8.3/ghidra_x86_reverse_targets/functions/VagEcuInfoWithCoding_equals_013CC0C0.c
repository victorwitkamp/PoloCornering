/* Target VagEcuInfoWithCoding_equals @ 013cc0c0 (Ghidra 013dc0c0) */
/* Size: 805 bytes */
/* Reason: VagEcuInfoWithCoding equality comparison, useful for field layout */
/* Function: _ZNK20VagEcuInfoWithCodingeqERKS_ @ 013cc0c0 */

/* Symbols at target:
 * Function _ZNK20VagEcuInfoWithCodingeqERKS_
 */


undefined4 _ZNK20VagEcuInfoWithCodingeqERKS_(int param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  int iStack_d0;
  undefined4 uStack_cc;
  int iStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  int iStack_b4;
  undefined4 uStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  int iStack_a4;
  undefined4 uStack_a0;
  int iStack_9c;
  undefined4 uStack_98;
  int iStack_94;
  undefined4 uStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  int iStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = *(int **)(param_1 + 100);
  piVar3 = *(int **)(param_2 + 100);
  if (piVar1 == (int *)0x0) {
joined_r0x013dc384:
    if (piVar3 == (int *)0x0) {
      uStack_dc = 0x1a199fc;
      uStack_74 = *(undefined4 *)(param_1 + 4);
      uStack_70 = *(undefined4 *)(param_1 + 8);
      iStack_6c = *(int *)(param_1 + 0xc);
      if (iStack_6c != 0) {
        LOCK();
        *(int *)(iStack_6c + 4) = *(int *)(iStack_6c + 4) + 1;
        UNLOCK();
      }
      uStack_68 = *(undefined4 *)(param_1 + 0x10);
      iStack_64 = *(int *)(param_1 + 0x14);
      if (iStack_64 != 0) {
        LOCK();
        *(int *)(iStack_64 + 4) = *(int *)(iStack_64 + 4) + 1;
        UNLOCK();
      }
      uStack_60 = *(undefined4 *)(param_1 + 0x18);
      iStack_5c = *(int *)(param_1 + 0x1c);
      if (iStack_5c != 0) {
        LOCK();
        *(int *)(iStack_5c + 4) = *(int *)(iStack_5c + 4) + 1;
        UNLOCK();
      }
      uStack_58 = *(undefined4 *)(param_1 + 0x20);
      uStack_54 = *(undefined4 *)(param_1 + 0x24);
      iStack_50 = *(int *)(param_1 + 0x28);
      if (iStack_50 != 0) {
        LOCK();
        *(int *)(iStack_50 + 4) = *(int *)(iStack_50 + 4) + 1;
        UNLOCK();
      }
      uStack_4c = *(undefined4 *)(param_1 + 0x2c);
      iStack_48 = *(int *)(param_1 + 0x30);
      if (iStack_48 != 0) {
        LOCK();
        *(int *)(iStack_48 + 4) = *(int *)(iStack_48 + 4) + 1;
        UNLOCK();
      }
      uStack_44 = *(undefined4 *)(param_1 + 0x34);
      iStack_40 = *(int *)(param_1 + 0x38);
      if (iStack_40 != 0) {
        LOCK();
        *(int *)(iStack_40 + 4) = *(int *)(iStack_40 + 4) + 1;
        UNLOCK();
      }
      uStack_3c = *(undefined4 *)(param_1 + 0x3c);
      iStack_38 = *(int *)(param_1 + 0x40);
      if (iStack_38 != 0) {
        LOCK();
        *(int *)(iStack_38 + 4) = *(int *)(iStack_38 + 4) + 1;
        UNLOCK();
      }
      uStack_34 = *(undefined4 *)(param_1 + 0x44);
      iStack_30 = *(int *)(param_1 + 0x48);
      if (iStack_30 != 0) {
        LOCK();
        *(int *)(iStack_30 + 4) = *(int *)(iStack_30 + 4) + 1;
        UNLOCK();
      }
      uStack_2c = *(undefined4 *)(param_1 + 0x4c);
      iStack_28 = *(int *)(param_1 + 0x50);
      if (iStack_28 != 0) {
        LOCK();
        *(int *)(iStack_28 + 4) = *(int *)(iStack_28 + 4) + 1;
        UNLOCK();
      }
      uStack_24 = *(undefined4 *)(param_1 + 0x54);
      iStack_20 = *(int *)(param_1 + 0x58);
      if (iStack_20 != 0) {
        LOCK();
        *(int *)(iStack_20 + 4) = *(int *)(iStack_20 + 4) + 1;
        UNLOCK();
      }
      uStack_1c = *(undefined4 *)(param_1 + 0x5c);
      iStack_18 = *(int *)(param_1 + 0x60);
      if (iStack_18 != 0) {
        LOCK();
        *(int *)(iStack_18 + 4) = *(int *)(iStack_18 + 4) + 1;
        UNLOCK();
      }
      uStack_d8 = *(undefined4 *)(param_2 + 4);
      uStack_d4 = *(undefined4 *)(param_2 + 8);
      iStack_d0 = *(int *)(param_2 + 0xc);
      if (iStack_d0 != 0) {
        LOCK();
        *(int *)(iStack_d0 + 4) = *(int *)(iStack_d0 + 4) + 1;
        UNLOCK();
      }
      uStack_cc = *(undefined4 *)(param_2 + 0x10);
      iStack_c8 = *(int *)(param_2 + 0x14);
      if (iStack_c8 != 0) {
        LOCK();
        *(int *)(iStack_c8 + 4) = *(int *)(iStack_c8 + 4) + 1;
        UNLOCK();
      }
      uStack_c4 = *(undefined4 *)(param_2 + 0x18);
      iStack_c0 = *(int *)(param_2 + 0x1c);
      if (iStack_c0 != 0) {
        LOCK();
        *(int *)(iStack_c0 + 4) = *(int *)(iStack_c0 + 4) + 1;
        UNLOCK();
      }
      uStack_bc = *(undefined4 *)(param_2 + 0x20);
      uStack_b8 = *(undefined4 *)(param_2 + 0x24);
      iStack_b4 = *(int *)(param_2 + 0x28);
      if (iStack_b4 != 0) {
        LOCK();
        *(int *)(iStack_b4 + 4) = *(int *)(iStack_b4 + 4) + 1;
        UNLOCK();
      }
      uStack_b0 = *(undefined4 *)(param_2 + 0x2c);
      iStack_ac = *(int *)(param_2 + 0x30);
      if (iStack_ac != 0) {
        LOCK();
        *(int *)(iStack_ac + 4) = *(int *)(iStack_ac + 4) + 1;
        UNLOCK();
      }
      uStack_a8 = *(undefined4 *)(param_2 + 0x34);
      iStack_a4 = *(int *)(param_2 + 0x38);
      if (iStack_a4 != 0) {
        LOCK();
        *(int *)(iStack_a4 + 4) = *(int *)(iStack_a4 + 4) + 1;
        UNLOCK();
      }
      uStack_a0 = *(undefined4 *)(param_2 + 0x3c);
      iStack_9c = *(int *)(param_2 + 0x40);
      if (iStack_9c != 0) {
        LOCK();
        *(int *)(iStack_9c + 4) = *(int *)(iStack_9c + 4) + 1;
        UNLOCK();
      }
      uStack_98 = *(undefined4 *)(param_2 + 0x44);
      iStack_94 = *(int *)(param_2 + 0x48);
      if (iStack_94 != 0) {
        LOCK();
        *(int *)(iStack_94 + 4) = *(int *)(iStack_94 + 4) + 1;
        UNLOCK();
      }
      uStack_90 = *(undefined4 *)(param_2 + 0x4c);
      iStack_8c = *(int *)(param_2 + 0x50);
      if (iStack_8c != 0) {
        LOCK();
        *(int *)(iStack_8c + 4) = *(int *)(iStack_8c + 4) + 1;
        UNLOCK();
      }
      uStack_88 = *(undefined4 *)(param_2 + 0x54);
      iStack_84 = *(int *)(param_2 + 0x58);
      if (iStack_84 != 0) {
        LOCK();
        *(int *)(iStack_84 + 4) = *(int *)(iStack_84 + 4) + 1;
        UNLOCK();
      }
      uStack_80 = *(undefined4 *)(param_2 + 0x5c);
      iStack_7c = *(int *)(param_2 + 0x60);
      if (iStack_7c != 0) {
        LOCK();
        *(int *)(iStack_7c + 4) = *(int *)(iStack_7c + 4) + 1;
        UNLOCK();
      }
      uStack_78 = uStack_dc;
      uVar4 = func_0x0198f590(&uStack_78,&uStack_dc);
      func_0x0198f580(&uStack_dc);
      func_0x0198f580(&uStack_78);
      goto LAB_013dc39a;
    }
  }
  else if (piVar3 != (int *)0x0) {
    iVar5 = piVar1[1] - *piVar1;
    if (iVar5 == piVar3[1] - *piVar3) {
      piVar3 = (int *)func_0x0197e980(*piVar1,*piVar3,iVar5);
      goto joined_r0x013dc384;
    }
  }
  func_0x0197ec60(&UNK_007c9361);
  uVar4 = 0;
LAB_013dc39a:
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return uVar4;
  }
  func_0x0197e230();
  pcVar2 = (code *)swi(3);
  uVar4 = (*pcVar2)();
  return uVar4;
}



/* Entry instruction preview:
 * 013cc0c0: PUSH EBP
 */
