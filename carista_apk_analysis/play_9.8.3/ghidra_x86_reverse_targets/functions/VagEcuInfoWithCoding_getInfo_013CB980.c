/* Target VagEcuInfoWithCoding_getInfo @ 013cb980 (Ghidra 013db980) */
/* Size: 1848 bytes */
/* Reason: VagEcuInfoWithCoding::getInfo accessor with coding metadata */
/* Function: _ZNK20VagEcuInfoWithCoding7getInfoEv @ 013cb980 */

/* Symbols at target:
 * Function _ZNK20VagEcuInfoWithCoding7getInfoEv
 */


/* WARNING: Type propagation algorithm not settling */

ulonglong * _ZNK20VagEcuInfoWithCoding7getInfoEv(ulonglong *param_1,ulonglong *param_2)

{
  uint *puVar1;
  code *pcVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  undefined8 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  ulonglong **ppuVar8;
  int *piVar9;
  int iVar10;
  int in_GS_OFFSET;
  ulonglong *puStack_84;
  ulonglong *puStack_80;
  ulonglong *puStack_7c;
  undefined8 uStack_78;
  undefined1 uStack_6d;
  ulonglong uStack_68;
  ulonglong *puStack_60;
  int *piStack_5c;
  int *piStack_58;
  uint uStack_54;
  undefined4 uStack_50;
  ulonglong *puStack_4c;
  byte bStack_48;
  undefined1 auStack_47 [11];
  undefined2 uStack_3c;
  undefined1 uStack_3a;
  ulonglong *puStack_34;
  undefined8 uStack_30;
  ulonglong *puStack_28;
  int *piStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  undefined3 uStack_18;
  int iStack_14;
  
  puVar1 = (uint *)_ZN3App14STRING_MANAGERE;
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  piStack_24 = (int *)0x0;
  piStack_20 = (int *)0x0;
  if ((int)param_2[4] == 2) {
    puStack_7c = *(ulonglong **)((int)param_2 + 100);
    if (puStack_7c != (ulonglong *)0x0) {
      puStack_80 = (ulonglong *)0x13dbaa8;
      uStack_78 = func_0x01980710();
      puStack_80 = (ulonglong *)0x13dbabb;
      puStack_7c = &uStack_30;
      func_0x0197f7b0();
      uStack_3c = 0x2002;
      puStack_7c = (ulonglong *)((int)&uStack_3c + 1);
      uStack_3a = 0;
      uStack_78._0_4_ = (uint *)0x1;
      puStack_84 = (ulonglong *)0x13dbadf;
      puStack_80 = &uStack_30;
      puVar4 = (ulonglong *)func_0x0197f300();
      puStack_60 = *(ulonglong **)(puVar4 + 1);
      uStack_68 = *puVar4;
      *puVar4 = 0;
      *(undefined4 *)(puVar4 + 1) = 0;
      puVar1 = (uint *)_ZN3App14STRING_MANAGERE;
      puStack_80 = (ulonglong *)0x18;
      puStack_84 = (ulonglong *)0x13dbb10;
      puStack_4c = (ulonglong *)func_0x0197e0c0();
      uStack_54 = 0x19;
      uStack_50 = 0x13;
      *(undefined4 *)puStack_4c = 0x69636564;
      *(undefined4 *)((int)puStack_4c + 4) = 0x5f6c616d;
      *(undefined4 *)(puStack_4c + 1) = 0x625f6e69;
      *(undefined4 *)((int)puStack_4c + 0xc) = 0x6b636172;
      *(undefined4 *)((int)puStack_4c + 0xf) = 0x7374656b;
      *(undefined1 *)((int)puStack_4c + 0x13) = 0;
      uStack_78._0_4_ = &uStack_54;
      puStack_80 = (ulonglong *)&bStack_48;
      puStack_84 = (ulonglong *)0x13dbb4e;
      puStack_7c = (ulonglong *)puVar1;
      (**(code **)(*puVar1 + 0xc))();
      puStack_80 = (ulonglong *)auStack_47._7_4_;
      if ((bStack_48 & 1) == 0) {
        auStack_47._3_4_ = ZEXT14(bStack_48 >> 1);
        puStack_80 = (ulonglong *)auStack_47;
      }
      puStack_84 = &uStack_68;
      puStack_7c = (ulonglong *)auStack_47._3_4_;
      puVar5 = (undefined8 *)func_0x0197f300();
      uStack_6d = *(undefined1 *)puVar5;
      uStack_18 = (undefined3)((uint)*(undefined4 *)((int)puVar5 + 4) >> 8);
      uStack_1c = *(undefined4 *)((int)puVar5 + 1);
      iVar10 = *(int *)(puVar5 + 1);
      *puVar5 = 0;
      *(undefined4 *)(puVar5 + 1) = 0;
      puStack_84 = (ulonglong *)0x18;
      piVar6 = (int *)func_0x0197e0c0();
LAB_013dbd8b:
      piVar6[1] = 0;
      piVar6[2] = 0;
      *piVar6 = 0x199d0f8;
      *(undefined1 *)(piVar6 + 3) = uStack_6d;
      *(undefined4 *)((int)piVar6 + 0xd) = uStack_1c;
      piVar6[4] = CONCAT31(uStack_18,uStack_1c._3_1_);
      piVar6[5] = iVar10;
      piVar9 = piVar6 + 3;
      uStack_18 = 0;
      uStack_1c = 0;
      puVar4 = puStack_84;
      puStack_84 = puStack_4c;
      piStack_24 = piVar9;
      piStack_20 = piVar6;
      if ((bStack_48 & 1) != 0) {
        puStack_84 = (ulonglong *)auStack_47._7_4_;
        func_0x0197e150();
        puVar4 = puStack_84;
        puStack_84 = puStack_4c;
      }
      puVar3 = puStack_60;
      puStack_4c = puStack_84;
      if ((uStack_54 & 1) != 0) {
        func_0x0197e150();
        puVar4 = puStack_84;
        puVar3 = puStack_60;
      }
      puStack_84 = puVar3;
      puStack_60 = puStack_84;
      puVar3 = puStack_34;
      if ((uStack_68 & 1) != 0) {
        func_0x0197e150();
        puVar4 = puStack_84;
        puVar3 = puStack_34;
      }
      puStack_84 = puVar3;
      if ((uStack_3c & 1) != 0) {
        func_0x0197e150();
        puVar4 = puStack_84;
      }
      ppuVar8 = &puStack_84;
      puStack_84 = puVar4;
      goto joined_r0x013dbe01;
    }
    puStack_7c = (ulonglong *)0x20;
    puStack_80 = (ulonglong *)0x13dbc54;
    puStack_28 = (ulonglong *)func_0x0197e0c0();
    uStack_30._0_4_ = 0x21;
    uStack_30._4_4_ = 0x18;
    puStack_28[2] = 0x646165725f6f745f;
    *(undefined4 *)puStack_28 = 0x6c6c7566;
    *(undefined4 *)((int)puStack_28 + 4) = 0x6163735f;
    *(undefined4 *)(puStack_28 + 1) = 0x61665f6e;
    *(undefined4 *)((int)puStack_28 + 0xc) = 0x64656c69;
    *(undefined1 *)(puStack_28 + 3) = 0;
    uStack_78._4_4_ = (uint *)&uStack_30;
    puStack_7c = &uStack_68;
    puStack_80 = (ulonglong *)0x13dbc98;
    uStack_78._0_4_ = puVar1;
    (**(code **)(*puVar1 + 0xc))();
    puStack_80 = (ulonglong *)0x18;
    puStack_84 = (ulonglong *)&LAB_013dbca7;
    piVar6 = (int *)func_0x0197e0c0();
  }
  else if ((int)param_2[4] == 3) {
    uStack_78._0_4_ = *(uint **)((int)param_2 + 100);
    if ((uint *)uStack_78 != (uint *)0x0) {
      puStack_80 = (ulonglong *)0x13db9de;
      puStack_7c = &uStack_30;
      func_0x0197fa90();
      uStack_3c = 0x2002;
      puStack_7c = (ulonglong *)((int)&uStack_3c + 1);
      uStack_3a = 0;
      uStack_78._0_4_ = (uint *)0x1;
      puStack_84 = (ulonglong *)0x13dba02;
      puStack_80 = &uStack_30;
      puVar4 = (ulonglong *)func_0x0197f300();
      puStack_60 = *(ulonglong **)(puVar4 + 1);
      uStack_68 = *puVar4;
      *puVar4 = 0;
      *(undefined4 *)(puVar4 + 1) = 0;
      puVar1 = (uint *)_ZN3App14STRING_MANAGERE;
      puStack_80 = (ulonglong *)0x10;
      puStack_84 = (ulonglong *)0x13dba33;
      puStack_4c = (ulonglong *)func_0x0197e0c0();
      uStack_54 = 0x11;
      uStack_50 = 0xf;
      *(undefined4 *)((int)puStack_4c + 0xb) = 0x7374656b;
      *(undefined4 *)(puStack_4c + 1) = 0x6b636172;
      *(undefined4 *)((int)puStack_4c + 4) = 0x625f6e69;
      *(undefined4 *)puStack_4c = 0x5f786568;
      *(undefined1 *)((int)puStack_4c + 0xf) = 0;
      uStack_78._0_4_ = &uStack_54;
      puStack_80 = (ulonglong *)&bStack_48;
      puStack_84 = (ulonglong *)0x13dba7b;
      puStack_7c = (ulonglong *)puVar1;
      (**(code **)(*puVar1 + 0xc))();
      puStack_80 = (ulonglong *)auStack_47._7_4_;
      if ((bStack_48 & 1) == 0) {
        auStack_47._3_4_ = ZEXT14(bStack_48 >> 1);
        puStack_80 = (ulonglong *)auStack_47;
      }
      puStack_84 = &uStack_68;
      puStack_7c = (ulonglong *)auStack_47._3_4_;
      puVar5 = (undefined8 *)func_0x0197f300();
      uStack_6d = *(undefined1 *)puVar5;
      uStack_18 = (undefined3)((uint)*(undefined4 *)((int)puVar5 + 4) >> 8);
      uStack_1c = *(undefined4 *)((int)puVar5 + 1);
      iVar10 = *(int *)(puVar5 + 1);
      *puVar5 = 0;
      *(undefined4 *)(puVar5 + 1) = 0;
      puStack_84 = (ulonglong *)0x18;
      piVar6 = (int *)func_0x0197e0c0();
      goto LAB_013dbd8b;
    }
    puStack_7c = (ulonglong *)0x20;
    puStack_80 = (ulonglong *)0x13dbbeb;
    puStack_28 = (ulonglong *)func_0x0197e0c0();
    uStack_30._0_4_ = 0x21;
    uStack_30._4_4_ = 0x18;
    puStack_28[2] = 0x646165725f6f745f;
    *(undefined4 *)puStack_28 = 0x6c6c7566;
    *(undefined4 *)((int)puStack_28 + 4) = 0x6163735f;
    *(undefined4 *)(puStack_28 + 1) = 0x61665f6e;
    *(undefined4 *)((int)puStack_28 + 0xc) = 0x64656c69;
    *(undefined1 *)(puStack_28 + 3) = 0;
    uStack_78._4_4_ = (uint *)&uStack_30;
    puStack_7c = &uStack_68;
    puStack_80 = (ulonglong *)0x13dbc2f;
    uStack_78._0_4_ = puVar1;
    (**(code **)(*puVar1 + 0xc))();
    puStack_80 = (ulonglong *)0x18;
    puStack_84 = (ulonglong *)0x13dbc3e;
    piVar6 = (int *)func_0x0197e0c0();
  }
  else {
    puStack_7c = (ulonglong *)0x10;
    puStack_80 = (ulonglong *)0x13dbb7c;
    puStack_28 = (ulonglong *)func_0x0197e0c0();
    uStack_30._0_4_ = 0x11;
    uStack_30._4_4_ = 0xe;
    *(undefined2 *)((int)puStack_28 + 0xc) = 0x656e;
    *(undefined4 *)(puStack_28 + 1) = 0x6f6e5f6e;
    *(undefined4 *)((int)puStack_28 + 4) = 0x6163735f;
    *(undefined4 *)puStack_28 = 0x6c6c7566;
    *(undefined1 *)((int)puStack_28 + 0xe) = 0;
    uStack_78._4_4_ = (uint *)&uStack_30;
    puStack_7c = &uStack_68;
    puStack_80 = (ulonglong *)0x13dbbc3;
    uStack_78._0_4_ = puVar1;
    (**(code **)(*puVar1 + 0xc))();
    puStack_80 = (ulonglong *)0x18;
    puStack_84 = (ulonglong *)0x13dbbd2;
    piVar6 = (int *)func_0x0197e0c0();
  }
  ppuVar8 = &puStack_80;
  piVar6[1] = 0;
  piVar6[2] = 0;
  *piVar6 = 0x199d0f8;
  piVar9 = piVar6 + 3;
  piVar6[5] = (int)puStack_60;
  *(ulonglong *)(piVar6 + 3) = uStack_68;
  uStack_68 = 0;
  puStack_60 = (ulonglong *)0x0;
  piStack_24 = piVar9;
  piStack_20 = piVar6;
joined_r0x013dbe01:
  if (((uint)uStack_30 & 1) != 0) {
    *ppuVar8 = puStack_28;
    ppuVar8[-1] = (ulonglong *)&LAB_013dbe0e;
    func_0x0197e150();
  }
  ppuVar8[1] = param_2;
  *ppuVar8 = param_1;
  ppuVar8[-1] = (ulonglong *)0x13dbe20;
  func_0x0198f5a0();
  ppuVar8[-1] = (ulonglong *)0x18;
  ppuVar8[-2] = (ulonglong *)0x13dbe2f;
  puStack_60 = (ulonglong *)func_0x0197e0c0();
  uStack_68 = 0x1000000019;
  *(undefined4 *)puStack_60 = 0x6c6c7566;
  *(undefined4 *)((int)puStack_60 + 4) = 0x6163735f;
  *(undefined4 *)((int)puStack_60 + 8) = 0x6f635f6e;
  *(undefined4 *)((int)puStack_60 + 0xc) = 0x676e6964;
  *(undefined1 *)((int)puStack_60 + 0x10) = 0;
  LOCK();
  piVar6[1] = piVar6[1] + 1;
  UNLOCK();
  puVar5 = *(undefined8 **)((int)param_1 + 4);
  if (puVar5 < *(undefined8 **)(param_1 + 1)) {
    *(ulonglong **)(puVar5 + 1) = puStack_60;
    *puVar5 = 0x1000000019;
    uStack_68 = 0;
    puStack_60 = (ulonglong *)0x0;
    *(int **)((int)puVar5 + 0xc) = piVar9;
    *(int **)(puVar5 + 2) = piVar6;
    piStack_5c = (int *)0x0;
    piStack_58 = (int *)0x0;
    *(int *)((int)param_1 + 4) = (int)puVar5 + 0x14;
  }
  else {
    *ppuVar8 = &uStack_68;
    ppuVar8[-1] = param_1;
    ppuVar8[-2] = (ulonglong *)0x13dbeae;
    piStack_5c = piVar9;
    piStack_58 = piVar6;
    uVar7 = func_0x019884c0();
    piVar6 = piStack_58;
    *(undefined4 *)((int)param_1 + 4) = uVar7;
    if (piStack_58 != (int *)0x0) {
      LOCK();
      piVar9 = piStack_58 + 1;
      iVar10 = *piVar9;
      *piVar9 = *piVar9 + -1;
      UNLOCK();
      if (iVar10 == 0) {
        iVar10 = *piStack_58;
        ppuVar8[-1] = (ulonglong *)piStack_58;
        pcVar2 = *(code **)(iVar10 + 8);
        ppuVar8[-2] = (ulonglong *)0x13dbece;
        (*pcVar2)();
        ppuVar8[-1] = (ulonglong *)piVar6;
        ppuVar8[-2] = (ulonglong *)&LAB_013dbed6;
        func_0x0197e1b0();
      }
    }
  }
  if ((uStack_68 & 1) != 0) {
    ppuVar8[-1] = puStack_60;
    ppuVar8[-2] = (ulonglong *)&LAB_013dbee7;
    func_0x0197e150();
  }
  piVar6 = piStack_20;
  if (piStack_20 != (int *)0x0) {
    LOCK();
    piVar9 = piStack_20 + 1;
    iVar10 = *piVar9;
    *piVar9 = *piVar9 + -1;
    UNLOCK();
    if (iVar10 == 0) {
      iVar10 = *piStack_20;
      ppuVar8[-1] = (ulonglong *)piStack_20;
      pcVar2 = *(code **)(iVar10 + 8);
      ppuVar8[-2] = (ulonglong *)0x13dbf04;
      (*pcVar2)();
      ppuVar8[-1] = (ulonglong *)piVar6;
      ppuVar8[-2] = (ulonglong *)&LAB_013dbf0c;
      func_0x0197e1b0();
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
  ppuVar8[-2] = (ulonglong *)0x13dc0b8;
  func_0x0197e230();
  pcVar2 = (code *)swi(3);
  puVar4 = (ulonglong *)(*pcVar2)();
  return puVar4;
}



/* Entry instruction preview:
 * 013cb980: PUSH EBP
 */
