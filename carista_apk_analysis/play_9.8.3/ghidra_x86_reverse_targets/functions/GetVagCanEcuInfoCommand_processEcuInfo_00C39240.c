/* Target GetVagCanEcuInfoCommand_processEcuInfo @ 00c39240 (Ghidra 00c49240) */
/* Size: 2741 bytes */
/* Reason: single-payload ECU-info parser for part/info string, coding type, rawAddress4, tail, initial coding, and optional suffix text */
/* Function: _ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 00c39240 */

/* Symbols at target:
 * Function _ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 */


undefined4 *
_ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
          (undefined4 *param_1,undefined4 param_2,ulonglong *param_3)

{
  int *piVar1;
  uint *puVar2;
  undefined8 uVar3;
  char cVar4;
  undefined8 *puVar5;
  code *pcVar6;
  ulonglong uVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  ulonglong *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  ulonglong **ppuVar16;
  ulonglong **ppuVar17;
  int in_GS_OFFSET;
  bool bVar18;
  int *piStack_e8;
  ulonglong *puStack_e4;
  ulonglong *puStack_e0;
  ulonglong *puStack_dc;
  ulonglong *puStack_d8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  ulonglong *puStack_80;
  uint *puStack_7c;
  int *piStack_78;
  int *piStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [4];
  int *piStack_60;
  ulonglong *puStack_5c;
  int *piStack_58;
  int *piStack_54;
  int *piStack_50;
  int *piStack_4c;
  int *piStack_48;
  int *piStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [4];
  int *piStack_38;
  ulonglong *puStack_34;
  undefined8 uStack_2c;
  ulonglong *puStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 uStack_15;
  int iStack_14;
  
  ppuVar17 = &puStack_dc;
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  puVar5 = *(undefined8 **)param_3;
  if (*(uint *)((int)param_3 + 4) - (int)puVar5 < 0x1a) {
    puStack_dc = (ulonglong *)&UNK_00a0e558;
    puStack_e0 = (ulonglong *)0xc49281;
    func_0x0197e300();
    *param_1 = 0x19a08d0;
    param_1[1] = 0xfffffffa;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = param_1 + 1;
    param_1[7] = param_1 + 2;
    param_1[8] = param_1 + 4;
    goto LAB_00c49a71;
  }
  puStack_dc = (ulonglong *)0x10;
  puStack_e0 = (ulonglong *)0xc492bd;
  puStack_24 = (ulonglong *)func_0x0197e0c0();
  uStack_2c = 0xc00000011;
  uVar3 = *puVar5;
  *(undefined4 *)(puStack_24 + 1) = *(undefined4 *)(puVar5 + 1);
  *puStack_24 = uVar3;
  *(undefined1 *)((int)puStack_24 + 0xc) = 0;
  puStack_e0 = (ulonglong *)0xc492f2;
  puStack_dc = (ulonglong *)auStack_3c;
  puStack_d8 = &uStack_2c;
  func_0x01980590();
  if ((uStack_2c & 1) != 0) {
    puStack_e0 = puStack_24;
    puStack_e4 = (ulonglong *)&LAB_00c49306;
    func_0x0197e150();
  }
  puStack_24 = puStack_34;
  uStack_2c = _auStack_3c;
  puStack_e4 = (ulonglong *)0xc49322;
  puStack_e0 = (ulonglong *)auStack_3c;
  puStack_dc = &uStack_2c;
  func_0x01980480();
  ppuVar16 = &puStack_e4;
  if ((uStack_2c & 1) != 0) {
    puStack_e4 = puStack_24;
    piStack_e8 = (int *)&LAB_00c49336;
    func_0x0197e150();
  }
  puStack_24 = puStack_34;
  uStack_2c = _auStack_3c;
  piStack_48 = (int *)0x0;
  piStack_44 = (int *)0x0;
  cVar4 = *(char *)((uint)*param_3 + 0x10);
  piVar9 = piStack_44;
  if (cVar4 == '\x10') {
    uStack_40 = 3;
  }
  else {
    if (cVar4 == '\x03') {
      uStack_40 = 2;
      puStack_e0 = param_3;
      puStack_d8 = (ulonglong *)0x3;
      puStack_dc = (ulonglong *)0x11;
      piStack_e8 = (int *)0xc4938d;
      puStack_e4 = (ulonglong *)auStack_3c;
      func_0x0197f9b0();
      piStack_e8 = (int *)0x18;
      piVar9 = (int *)func_0x0197e0c0();
    }
    else {
      if (0xe < (byte)(cVar4 - 0x21U)) {
        uStack_40 = 1;
        ppuVar16 = &puStack_e4;
        goto LAB_00c49472;
      }
      uStack_40 = 4;
      puStack_e0 = param_3;
      puStack_d8 = (ulonglong *)0x3;
      puStack_dc = (ulonglong *)0x11;
      piStack_e8 = (int *)0xc493da;
      puStack_e4 = (ulonglong *)auStack_3c;
      func_0x0197f9b0();
      piStack_e8 = (int *)0x18;
      piVar9 = (int *)func_0x0197e0c0();
    }
    piVar13 = piStack_44;
    piVar9[1] = 0;
    piVar9[2] = 0;
    *piVar9 = 0x199d1c0;
    piStack_48 = piVar9 + 3;
    *(ulonglong *)(piVar9 + 3) = _auStack_3c;
    piVar9[5] = (int)puStack_34;
    puStack_34 = (ulonglong *)0x0;
    _auStack_3c = 0;
    ppuVar16 = (ulonglong **)&piStack_e8;
    if (piStack_44 != (int *)0x0) {
      LOCK();
      piVar1 = piStack_44 + 1;
      iVar14 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar14 == 0) {
        iVar14 = *piStack_44;
        piStack_e8 = piStack_44;
        piStack_44 = piVar9;
        (**(code **)(iVar14 + 8))();
        piStack_e8 = piVar13;
        func_0x0197e1b0();
        piVar9 = piStack_44;
      }
      piStack_44 = piVar9;
      ppuVar16 = (ulonglong **)&piStack_e8;
      piVar9 = piStack_44;
      if (auStack_3c != (undefined1  [4])0x0) {
        _auStack_3c = CONCAT44(auStack_3c,auStack_3c);
        piStack_e8 = (int *)auStack_3c;
        func_0x0197e150();
        ppuVar16 = (ulonglong **)&piStack_e8;
        piVar9 = piStack_44;
      }
    }
  }
LAB_00c49472:
  piStack_44 = piVar9;
  ppuVar16[1] = param_3;
  *ppuVar16 = (ulonglong *)auStack_3c;
  ppuVar16[3] = (ulonglong *)0x6;
  ppuVar16[2] = (ulonglong *)0x14;
  ppuVar16[-1] = (ulonglong *)0xc49491;
  func_0x0197f9b0();
  ppuVar16[-1] = (ulonglong *)0x18;
  ppuVar16[-2] = (ulonglong *)0xc494a0;
  piStack_4c = (int *)func_0x0197e0c0();
  piStack_4c[1] = 0;
  piStack_4c[2] = 0;
  *piStack_4c = 0x199d1c0;
  piStack_50 = piStack_4c + 3;
  *(ulonglong *)(piStack_4c + 3) = _auStack_3c;
  piStack_4c[5] = (int)puStack_34;
  *ppuVar16 = param_3;
  ppuVar16[-1] = (ulonglong *)auStack_3c;
  ppuVar16[2] = (ulonglong *)0x4;
  ppuVar16[1] = (ulonglong *)0xc;
  ppuVar16[-2] = (ulonglong *)0xc494f3;
  func_0x0197f9b0();
  ppuVar16[-2] = (ulonglong *)0x18;
  ppuVar16[-3] = (ulonglong *)0xc49502;
  piStack_54 = (int *)func_0x0197e0c0();
  piStack_54[1] = 0;
  piStack_54[2] = 0;
  *piStack_54 = 0x199d1c0;
  piStack_58 = piStack_54 + 3;
  *(ulonglong *)(piStack_54 + 3) = _auStack_3c;
  piStack_54[5] = (int)puStack_34;
  _auStack_3c = 0;
  puStack_34 = (ulonglong *)0x0;
  uVar7 = *param_3;
  uVar10 = *(uint *)((int)param_3 + 4) - (uint)uVar7;
  ppuVar17 = ppuVar16 + -2;
  if (0x1a < uVar10) {
    uVar10 = uVar10 - 0x1a;
    uVar15 = 0x10;
    if (uVar10 < 0x10) {
      uVar15 = uVar10;
    }
    if (uVar10 < 0xb) {
      _auStack_64 = CONCAT71(stack0xffffff9d,(char)uVar15 * '\x02');
      puVar11 = (ulonglong *)(auStack_64 + 1);
    }
    else {
      iVar14 = (uVar15 | 7) + 1;
      ppuVar16[-2] = (ulonglong *)iVar14;
      ppuVar16[-3] = (ulonglong *)0xc49582;
      uStack_94 = uVar15;
      puVar11 = (ulonglong *)func_0x0197e0c0();
      _auStack_64 = CONCAT44(uStack_94,iVar14) | 1;
      uVar15 = uStack_94;
      puStack_5c = puVar11;
    }
    *ppuVar16 = (ulonglong *)uVar15;
    ppuVar16[-1] = (ulonglong *)((uint)uVar7 + 0x1a);
    ppuVar16[-2] = puVar11;
    ppuVar16[-3] = (ulonglong *)0xc495ab;
    func_0x0197e0d0();
    *(undefined1 *)((int)puVar11 + uVar15) = 0;
    _auStack_3c = _auStack_64;
    puStack_34 = puStack_5c;
    ppuVar16[-1] = (ulonglong *)auStack_3c;
    ppuVar16[-2] = (ulonglong *)auStack_64;
    ppuVar16[-3] = (ulonglong *)0xc495d3;
    func_0x01980480();
    if ((_auStack_3c & 1) != 0) {
      ppuVar16[-3] = puStack_34;
      ppuVar16[-4] = (ulonglong *)&LAB_00c495e7;
      func_0x0197e150();
    }
    puStack_34 = puStack_5c;
    _auStack_3c = _auStack_64;
    ppuVar16[-2] = (ulonglong *)auStack_3c;
    ppuVar16[-3] = (ulonglong *)auStack_64;
    ppuVar16[-4] = (ulonglong *)0xc49603;
    func_0x01980590();
    if ((_auStack_3c & 1) != 0) {
      ppuVar16[-4] = puStack_34;
      ppuVar16[-5] = (ulonglong *)&LAB_00c49617;
      func_0x0197e150();
    }
    puStack_34 = puStack_5c;
    _auStack_3c = _auStack_64;
    if (cRam01a4e370 == '\0') {
      uStack_98 = 0x1a4e370;
      ppuVar16[-4] = (ulonglong *)0x1a4e370;
      ppuVar16[-5] = (ulonglong *)0xc49aa3;
      iVar14 = func_0x0197f7e0();
      if (iVar14 != 0) {
        ppuVar16[-3] = (ulonglong *)&UNK_0068f01f;
        ppuVar16[-4] = (ulonglong *)0x1a4e348;
        ppuVar16[-2] = (ulonglong *)0x0;
        ppuVar16[-5] = (ulonglong *)0xc49acb;
        func_0x00c49d00();
        ppuVar16[-2] = (ulonglong *)&DAT_0199ccf0;
        ppuVar16[-3] = (ulonglong *)0x1a4e348;
        ppuVar16[-4] = (ulonglong *)_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEED2Ev;
        ppuVar16[-5] = (ulonglong *)0xc49ae7;
        func_0x0197e090();
        ppuVar16[-4] = (ulonglong *)uStack_98;
        ppuVar16[-5] = (ulonglong *)0xc49af5;
        func_0x0197f7f0();
      }
    }
    uStack_70 = (int *)CONCAT13(uStack_70._3_1_,0x2002);
    bVar18 = (_auStack_3c & 1) != 0;
    puStack_80 = (ulonglong *)(auStack_3c + 1);
    if (bVar18) {
      puStack_80 = puStack_34;
    }
    _auStack_64 = 0;
    piVar9 = (int *)(uint)(auStack_3c[0] >> 1);
    if (bVar18) {
      piVar9 = piStack_38;
    }
    puStack_5c = (ulonglong *)0x0;
    uStack_1c = (int)piVar9 + (int)puStack_80;
    ppuVar16[-1] = (ulonglong *)uStack_1c;
    ppuVar16[-2] = puStack_80;
    ppuVar16[-3] = (ulonglong *)auStack_64;
    ppuVar16[1] = (ulonglong *)((int)&uStack_70 + 1);
    *ppuVar16 = (ulonglong *)0x1a4e348;
    ppuVar16[-4] = (ulonglong *)&uStack_20;
    ppuVar16[2] = (ulonglong *)0x0;
    ppuVar16[-5] = (ulonglong *)0xc496a9;
    piStack_78 = (int *)auStack_64;
    func_0x00c52d40();
    if ((_auStack_3c & 1) != 0) {
      ppuVar16[-5] = puStack_34;
      ppuVar16[-6] = (ulonglong *)&LAB_00c496bd;
      func_0x0197e150();
    }
    puStack_34 = puStack_5c;
    _auStack_3c = _auStack_64;
    _auStack_64 = _auStack_64 & 0xffffffffffff0000;
    ppuVar17 = ppuVar16 + -5;
    if (((uint)uStack_70 & 1) != 0) {
      ppuVar16[-5] = (ulonglong *)uStack_68;
      ppuVar16[-6] = (ulonglong *)&LAB_00c496e4;
      func_0x0197e150();
      ppuVar17 = ppuVar16 + -5;
    }
  }
  uStack_1c = 1;
  *ppuVar17 = (ulonglong *)0x18;
  ppuVar17[-1] = (ulonglong *)0xc496f7;
  puVar12 = (undefined4 *)func_0x0197e0c0();
  puVar12[1] = 0;
  puVar12[2] = 0;
  uStack_94 = 0x199d0f8;
  *puVar12 = 0x199d0f8;
  puVar11 = (ulonglong *)(puVar12 + 3);
  if ((uStack_2c & 1) == 0) {
    puVar12[5] = puStack_24;
    *puVar11 = uStack_2c;
  }
  else {
    ppuVar17[2] = (ulonglong *)uStack_2c._4_4_;
    ppuVar17[1] = puStack_24;
    *ppuVar17 = puVar11;
    ppuVar17[-1] = (ulonglong *)&LAB_00c4974a;
    func_0x00bbc560();
  }
  _auStack_64 = CONCAT44(puVar12,puVar11);
  *ppuVar17 = (ulonglong *)0x18;
  ppuVar17[-1] = (ulonglong *)0xc4975c;
  piStack_6c = (int *)func_0x0197e0c0();
  piStack_6c[1] = 0;
  piStack_6c[2] = 0;
  piStack_6c[3] = 0;
  piStack_6c[4] = 0;
  *piStack_6c = 0x19a08e8;
  uStack_70 = piStack_6c + 3;
  piStack_6c[5] = 0;
  *ppuVar17 = (ulonglong *)0x20;
  ppuVar17[-1] = (ulonglong *)0xc4978c;
  piStack_74 = (int *)func_0x0197e0c0();
  piStack_74[1] = 0;
  piStack_74[2] = 0;
  *piStack_74 = 0x19a0cb0;
  piStack_78 = piStack_74 + 3;
  piStack_74[3] = 0;
  piStack_74[4] = 0;
  piStack_74[5] = 0;
  piStack_74[6] = 0;
  piStack_74[7] = 0x3f800000;
  *ppuVar17 = (ulonglong *)0x18;
  ppuVar17[-1] = (ulonglong *)0xc497ca;
  puStack_7c = (uint *)func_0x0197e0c0();
  puStack_7c[1] = 0;
  puStack_7c[2] = 0;
  *puStack_7c = uStack_94;
  puVar11 = (ulonglong *)(puStack_7c + 3);
  if ((_auStack_3c & 1) == 0) {
    puStack_7c[5] = (uint)puStack_34;
    *puVar11 = _auStack_3c;
  }
  else {
    ppuVar17[2] = (ulonglong *)piStack_38;
    ppuVar17[1] = puStack_34;
    *ppuVar17 = puVar11;
    ppuVar17[-1] = (ulonglong *)&LAB_00c49814;
    func_0x00bbc560();
  }
  uStack_20 = 0;
  uStack_84 = 0;
  uStack_88 = 0;
  uStack_8c = 0;
  uStack_90 = 0;
  *ppuVar17 = (ulonglong *)0x78;
  ppuVar17[-1] = (ulonglong *)0xc49852;
  puStack_80 = puVar11;
  piVar13 = (int *)func_0x0197e0c0();
  piVar13[1] = 0;
  piVar13[2] = 0;
  *piVar13 = 0x19a0910;
  ppuVar17[0xf] = (ulonglong *)&uStack_90;
  ppuVar17[0xe] = (ulonglong *)&uStack_8c;
  ppuVar17[0xd] = (ulonglong *)&uStack_88;
  ppuVar17[0xc] = (ulonglong *)&uStack_84;
  ppuVar17[0xb] = (ulonglong *)&uStack_20;
  ppuVar17[10] = (ulonglong *)&puStack_80;
  ppuVar17[9] = (ulonglong *)&piStack_58;
  ppuVar17[8] = (ulonglong *)&piStack_50;
  ppuVar17[7] = (ulonglong *)&piStack_48;
  ppuVar17[6] = (ulonglong *)&uStack_40;
  ppuVar17[5] = (ulonglong *)&piStack_78;
  ppuVar17[4] = (ulonglong *)&uStack_70;
  ppuVar17[3] = (ulonglong *)auStack_64;
  ppuVar17[2] = (ulonglong *)&uStack_1c;
  ppuVar17[1] = (ulonglong *)(piVar13 + 3);
  *ppuVar17 = (ulonglong *)&uStack_15;
  ppuVar17[-1] = (ulonglong *)0xc498ec;
  func_0x01981ac0();
  *param_1 = 0x19a08d0;
  param_1[1] = 1;
  param_1[2] = piVar13 + 3;
  param_1[3] = piVar13;
  LOCK();
  piVar13[1] = piVar13[1] + 1;
  UNLOCK();
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_1 + 1;
  param_1[7] = param_1 + 2;
  param_1[8] = param_1 + 4;
  LOCK();
  piVar9 = piVar13 + 1;
  iVar14 = *piVar9;
  *piVar9 = *piVar9 + -1;
  UNLOCK();
  if (iVar14 == 0) {
    iVar14 = *piVar13;
    *ppuVar17 = (ulonglong *)piVar13;
    pcVar6 = *(code **)(iVar14 + 8);
    ppuVar17[-1] = (ulonglong *)0xc49941;
    (*pcVar6)();
    *ppuVar17 = (ulonglong *)piVar13;
    ppuVar17[-1] = (ulonglong *)&LAB_00c49949;
    func_0x0197e1b0();
  }
  puVar8 = puStack_7c;
  if (puStack_7c != (uint *)0x0) {
    LOCK();
    puVar2 = puStack_7c + 1;
    uVar10 = *puVar2;
    *puVar2 = *puVar2 - 1;
    UNLOCK();
    if (uVar10 == 0) {
      uVar10 = *puStack_7c;
      *ppuVar17 = (ulonglong *)puStack_7c;
      pcVar6 = *(code **)(uVar10 + 8);
      ppuVar17[-1] = (ulonglong *)0xc49966;
      (*pcVar6)();
      *ppuVar17 = (ulonglong *)puVar8;
      ppuVar17[-1] = (ulonglong *)&LAB_00c4996e;
      func_0x0197e1b0();
    }
  }
  piVar9 = piStack_74;
  if (piStack_74 != (int *)0x0) {
    LOCK();
    piVar13 = piStack_74 + 1;
    iVar14 = *piVar13;
    *piVar13 = *piVar13 + -1;
    UNLOCK();
    if (iVar14 == 0) {
      iVar14 = *piStack_74;
      *ppuVar17 = (ulonglong *)piStack_74;
      pcVar6 = *(code **)(iVar14 + 8);
      ppuVar17[-1] = (ulonglong *)0xc4998e;
      (*pcVar6)();
      *ppuVar17 = (ulonglong *)piVar9;
      ppuVar17[-1] = (ulonglong *)&LAB_00c49996;
      func_0x0197e1b0();
    }
  }
  piVar9 = piStack_6c;
  if (piStack_6c != (int *)0x0) {
    LOCK();
    piVar13 = piStack_6c + 1;
    iVar14 = *piVar13;
    *piVar13 = *piVar13 + -1;
    UNLOCK();
    if (iVar14 == 0) {
      iVar14 = *piStack_6c;
      *ppuVar17 = (ulonglong *)piStack_6c;
      pcVar6 = *(code **)(iVar14 + 8);
      ppuVar17[-1] = (ulonglong *)0xc499b3;
      (*pcVar6)();
      *ppuVar17 = (ulonglong *)piVar9;
      ppuVar17[-1] = (ulonglong *)&LAB_00c499bb;
      func_0x0197e1b0();
    }
  }
  piVar9 = piStack_60;
  if (piStack_60 != (int *)0x0) {
    LOCK();
    piVar13 = piStack_60 + 1;
    iVar14 = *piVar13;
    *piVar13 = *piVar13 + -1;
    UNLOCK();
    if (iVar14 == 0) {
      iVar14 = *piStack_60;
      *ppuVar17 = (ulonglong *)piStack_60;
      pcVar6 = *(code **)(iVar14 + 8);
      ppuVar17[-1] = (ulonglong *)0xc499d8;
      (*pcVar6)();
      *ppuVar17 = (ulonglong *)piVar9;
      ppuVar17[-1] = (ulonglong *)&LAB_00c499e0;
      func_0x0197e1b0();
    }
  }
  if ((_auStack_3c & 1) != 0) {
    *ppuVar17 = puStack_34;
    ppuVar17[-1] = (ulonglong *)&LAB_00c499f1;
    func_0x0197e150();
  }
  piVar9 = piStack_54;
  if (piStack_54 != (int *)0x0) {
    LOCK();
    piVar13 = piStack_54 + 1;
    iVar14 = *piVar13;
    *piVar13 = *piVar13 + -1;
    UNLOCK();
    if (iVar14 == 0) {
      iVar14 = *piStack_54;
      *ppuVar17 = (ulonglong *)piStack_54;
      pcVar6 = *(code **)(iVar14 + 8);
      ppuVar17[-1] = (ulonglong *)0xc49a0e;
      (*pcVar6)();
      *ppuVar17 = (ulonglong *)piVar9;
      ppuVar17[-1] = (ulonglong *)&LAB_00c49a16;
      func_0x0197e1b0();
    }
  }
  piVar9 = piStack_4c;
  if (piStack_4c != (int *)0x0) {
    LOCK();
    piVar13 = piStack_4c + 1;
    iVar14 = *piVar13;
    *piVar13 = *piVar13 + -1;
    UNLOCK();
    if (iVar14 == 0) {
      iVar14 = *piStack_4c;
      *ppuVar17 = (ulonglong *)piStack_4c;
      pcVar6 = *(code **)(iVar14 + 8);
      ppuVar17[-1] = (ulonglong *)0xc49a33;
      (*pcVar6)();
      *ppuVar17 = (ulonglong *)piVar9;
      ppuVar17[-1] = (ulonglong *)&LAB_00c49a3b;
      func_0x0197e1b0();
    }
  }
  piVar9 = piStack_44;
  if (piStack_44 != (int *)0x0) {
    LOCK();
    piVar13 = piStack_44 + 1;
    iVar14 = *piVar13;
    *piVar13 = *piVar13 + -1;
    UNLOCK();
    if (iVar14 == 0) {
      iVar14 = *piStack_44;
      *ppuVar17 = (ulonglong *)piStack_44;
      pcVar6 = *(code **)(iVar14 + 8);
      ppuVar17[-1] = (ulonglong *)0xc49a58;
      (*pcVar6)();
      *ppuVar17 = (ulonglong *)piVar9;
      ppuVar17[-1] = (ulonglong *)&LAB_00c49a60;
      func_0x0197e1b0();
    }
  }
  if ((uStack_2c & 1) != 0) {
    *ppuVar17 = puStack_24;
    ppuVar17[-1] = (ulonglong *)&LAB_00c49a71;
    func_0x0197e150();
  }
LAB_00c49a71:
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
  do {
    ppuVar17[-1] = (ulonglong *)0xc49bd9;
    func_0x0197e230();
    *ppuVar17 = puStack_5c;
    ppuVar17[-1] = (ulonglong *)0xc49be4;
    func_0x0197e150();
    if (((uint)uStack_70 & 1) != 0) {
      *ppuVar17 = (ulonglong *)uStack_68;
      ppuVar17[-1] = (ulonglong *)0xc49bf5;
      func_0x0197e150();
    }
    if ((_auStack_3c & 1) != 0) {
      *ppuVar17 = puStack_34;
      ppuVar17[-1] = (ulonglong *)&LAB_00c49b89;
      func_0x0197e150();
    }
    *ppuVar17 = (ulonglong *)&piStack_58;
    ppuVar17[-1] = (ulonglong *)0xc49b94;
    func_0x00c18cb0();
    *ppuVar17 = (ulonglong *)&piStack_50;
    ppuVar17[-1] = (ulonglong *)0xc49b9f;
    func_0x00c18cb0();
    *ppuVar17 = (ulonglong *)&piStack_48;
    ppuVar17[-1] = (ulonglong *)0xc49baa;
    func_0x00c18cb0();
    if ((uStack_2c & 1) != 0) {
      *ppuVar17 = puStack_24;
      ppuVar17[-1] = (ulonglong *)&LAB_00c49bbb;
      func_0x0197e150();
    }
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      *ppuVar17 = (ulonglong *)uStack_94;
      ppuVar17[-1] = (ulonglong *)&LAB_00c49bd4;
      func_0x0197a750();
    }
  } while( true );
}



/* Entry instruction preview:
 * 00c39240: PUSH EBP
 */
