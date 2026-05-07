/* Target VagOperationDelegate_getVagSettingAvailabilityForEcu @ 016b4180 (Ghidra 016c4180) */
/* Size: 1342 bytes */
/* Reason: availability router that calls VagSetting::isSubmodule before AvailBy handling */
/* Function: _ZN20VagOperationDelegate31getVagSettingAvailabilityForEcuERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE @ 016b4180 */

/* Symbols at target:
 * Function _ZN20VagOperationDelegate31getVagSettingAvailabilityForEcuERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE
 */


undefined4
_ZN20VagOperationDelegate31getVagSettingAvailabilityForEcuERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE
          (pointer_____offset_0x8___ param_1,int *param_2,int *param_3)

{
  pointer_____offset_0x8___ *ppuVar1;
  int *piVar2;
  code *pcVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  pointer_____offset_0x8___ puVar7;
  int iVar8;
  byte bVar9;
  pointer_____offset_0x8___ *ppuVar10;
  pointer_____offset_0x8___ *ppuVar11;
  uint uVar12;
  int in_GS_OFFSET;
  pointer_____offset_0x8___ *ppuStack_88;
  pointer_____offset_0x8___ puStack_84;
  pointer_____offset_0x8___ puStack_80;
  pointer_____offset_0x8___ puStack_7c;
  pointer_____offset_0x8___ puStack_78;
  pointer_____offset_0x8___ *ppuStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  pointer_____offset_0x8___ *ppuStack_60;
  undefined4 uStack_5c;
  pointer_____offset_0x8___ *ppuStack_58;
  pointer_____offset_0x8___ puStack_54;
  int *piStack_50;
  undefined4 uStack_4c;
  pointer_____offset_0x8___ puStack_48;
  pointer_____offset_0x8___ *ppuStack_44;
  pointer_____offset_0x8___ puStack_40;
  pointer_____offset_0x8___ *ppuStack_3c;
  pointer_____offset_0x8___ apuStack_38 [2];
  pointer_____offset_0x8___ *ppuStack_30;
  int *piStack_2c;
  int *piStack_24;
  undefined4 *puStack_20;
  int *piStack_1c;
  int iStack_14;
  
  ppuVar11 = &puStack_7c;
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  puStack_7c = (pointer_____offset_0x8___)*param_2;
  puStack_80 = (pointer_____offset_0x8___)0x16c41ae;
  cVar4 = (**(code **)(*(pointer_____offset_0x8___ *)puStack_7c + 0x3c))();
  if (cVar4 != '\0') {
    ppuVar11 = &puStack_7c;
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      ppuStack_74 = (pointer_____offset_0x8___ *)param_3;
      puStack_78 = (pointer_____offset_0x8___)param_2;
      puStack_80 = (pointer_____offset_0x8___)0x16c41ce;
      uVar5 = func_0x019936c0();
      return uVar5;
    }
    goto LAB_016c46b9;
  }
  iVar6 = *param_2;
  bVar9 = *(byte *)(iVar6 + 0x5c);
  uVar12 = (uint)bVar9;
  if (5 < uVar12) {
LAB_016c43da:
    iVar8 = *param_3;
LAB_016c43dc:
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      puStack_80 = (pointer_____offset_0x8___)0x16c4400;
      puStack_7c = *(pointer_____offset_0x8___ *)(iVar6 + 0x54);
      puStack_78 = (pointer_____offset_0x8___)*(undefined4 *)(iVar8 + 8);
      uVar5 = (**(code **)(*(int *)*(pointer_____offset_0x8___ *)(iVar6 + 0x54) + 0x10))();
      return uVar5;
    }
    goto LAB_016c46b9;
  }
  if ((0x1bU >> (uVar12 & 0x1f) & 1) == 0) {
    if (uVar12 != 5) goto LAB_016c43da;
    puStack_78 = param_1;
    puStack_7c = (pointer_____offset_0x8___)&puStack_54;
    puStack_80 = (pointer_____offset_0x8___)0x16c4256;
    (**(code **)(*(pointer_____offset_0x8___ *)param_1 + 0x20))();
    ppuVar11 = &puStack_80;
    if (puStack_54 == (pointer_____offset_0x8___)0x0) {
      uVar5 = 0;
      puStack_80 = &UNK_00961364;
      puStack_84 = &LAB_016c451a;
      func_0x0197ec60();
    }
    else {
      puStack_7c = puStack_54;
      puStack_84 = (pointer_____offset_0x8___)0x16c4273;
      puStack_80 = (pointer_____offset_0x8___)&puStack_40;
      func_0x0198fe80();
      puStack_48 = (pointer_____offset_0x8___)0x0;
      ppuStack_44 = (pointer_____offset_0x8___ *)0x0;
      uStack_5c = 0;
      ppuStack_58 = (pointer_____offset_0x8___ *)0x0;
      puStack_78 = (pointer_____offset_0x8___)&uStack_5c;
      puStack_7c = (pointer_____offset_0x8___)&puStack_48;
      puStack_84 = (pointer_____offset_0x8___)apuStack_38;
      ppuStack_88 = (pointer_____offset_0x8___ *)0x16c42af;
      puStack_80 = (pointer_____offset_0x8___)&puStack_40;
      func_0x0198fed0();
      ppuVar11 = ppuStack_58;
      if (ppuStack_58 != (pointer_____offset_0x8___ *)0x0) {
        LOCK();
        ppuVar10 = ppuStack_58 + 1;
        puVar7 = *ppuVar10;
        *ppuVar10 = *ppuVar10 + -1;
        UNLOCK();
        if (puVar7 == (pointer_____offset_0x8___)0x0) {
          ppuStack_88 = ppuStack_58;
          (**(code **)(*ppuStack_58 + 8))();
          ppuStack_88 = ppuVar11;
          func_0x0197e1b0();
        }
      }
      ppuVar11 = ppuStack_44;
      if (ppuStack_44 != (pointer_____offset_0x8___ *)0x0) {
        LOCK();
        ppuVar10 = ppuStack_44 + 1;
        puVar7 = *ppuVar10;
        *ppuVar10 = *ppuVar10 + -1;
        UNLOCK();
        if (puVar7 == (pointer_____offset_0x8___)0x0) {
          ppuStack_88 = ppuStack_44;
          (**(code **)(*ppuStack_44 + 8))();
          ppuStack_88 = ppuVar11;
          func_0x0197e1b0();
        }
      }
      ppuStack_88 = *(pointer_____offset_0x8___ **)(*param_2 + 0x54);
      puStack_84 = (pointer_____offset_0x8___)apuStack_38;
      uVar5 = (**(code **)(*ppuStack_88 + 0x10))();
      if (((uint)apuStack_38[0] & 1) != 0) {
        ppuStack_88 = ppuStack_30;
        func_0x0197e150();
      }
      ppuVar10 = ppuStack_3c;
      ppuVar11 = (pointer_____offset_0x8___ *)&ppuStack_88;
      if (ppuStack_3c != (pointer_____offset_0x8___ *)0x0) {
        LOCK();
        ppuVar11 = ppuStack_3c + 1;
        puVar7 = *ppuVar11;
        *ppuVar11 = *ppuVar11 + -1;
        UNLOCK();
        ppuVar11 = (pointer_____offset_0x8___ *)&ppuStack_88;
        if (puVar7 == (pointer_____offset_0x8___)0x0) {
          ppuStack_88 = ppuStack_3c;
          (**(code **)(*ppuStack_3c + 8))();
          ppuStack_88 = ppuVar10;
          func_0x0197e1b0();
          ppuVar11 = (pointer_____offset_0x8___ *)&ppuStack_88;
        }
      }
    }
  }
  else {
    iVar8 = *param_3;
    if (*(int *)(iVar8 + 4) != 2) goto LAB_016c43dc;
    puVar7 = *(pointer_____offset_0x8___ *)(iVar6 + 0x10);
    if (puVar7 == (pointer_____offset_0x8___)0x0) {
LAB_016c435d:
      puStack_80 = (pointer_____offset_0x8___)0x16c4365;
      puStack_7c = puVar7;
      puVar7 = (pointer_____offset_0x8___)func_0x0198c470();
      bVar9 = *(byte *)(*param_2 + 0x5c);
    }
    else {
      ppuStack_74 = &_ZTI6VagEcu;
      puStack_78 = (pointer_____offset_0x8___)&_ZTI3Ecu;
      uStack_70 = 0;
      puStack_80 = (pointer_____offset_0x8___)0x16c422a;
      puStack_7c = puVar7;
      iVar6 = func_0x0197e7e0();
      if (iVar6 == 0) goto LAB_016c435d;
    }
    ppuStack_74 = *(pointer_____offset_0x8___ **)(puVar7 + 0x18);
    uStack_70 = 0xc0;
    if (bVar9 != 1) {
      uStack_70 = (uint)(bVar9 == 4) << 7 | 0x40;
    }
    puStack_78 = param_1;
    puStack_7c = (pointer_____offset_0x8___)apuStack_38;
    uStack_6c = 0;
    puStack_80 = (pointer_____offset_0x8___)0x16c43b1;
    (**(code **)(*(pointer_____offset_0x8___ *)param_1 + 0x194))();
    ppuVar11 = &puStack_80;
    ppuVar10 = &puStack_80;
    puStack_80 = (pointer_____offset_0x8___)*puStack_20;
    puStack_84 = (pointer_____offset_0x8___)0x16c43c1;
    cVar4 = func_0x0197e390();
    if (cVar4 == '\0') {
      puStack_40 = (pointer_____offset_0x8___)0x0;
      ppuStack_3c = (pointer_____offset_0x8___ *)0x0;
      if (*(char *)(*param_2 + 0x5c) == '\x04') {
        puStack_7c = param_1;
        puStack_80 = (pointer_____offset_0x8___)&puStack_54;
        puStack_84 = (pointer_____offset_0x8___)0x16c442f;
        (**(code **)(*(pointer_____offset_0x8___ *)param_1 + 0x20))();
        ppuVar11 = &puStack_84;
        if (puStack_54 == (pointer_____offset_0x8___)0x0) {
          puStack_84 = &UNK_00961364;
          ppuStack_88 = (pointer_____offset_0x8___ *)0x16c4530;
          func_0x0197ec60();
        }
        else {
          puStack_80 = puStack_54;
          puStack_84 = (pointer_____offset_0x8___)&puStack_48;
          ppuStack_88 = (pointer_____offset_0x8___ *)0x16c444c;
          func_0x0198fe80();
          ppuVar11 = (pointer_____offset_0x8___ *)&ppuStack_88;
          puStack_40 = puStack_48;
          ppuStack_3c = ppuStack_44;
          if (puStack_48 != (pointer_____offset_0x8___)0x0) {
            ppuStack_60 = ppuStack_44;
            ppuStack_88 = &puStack_54;
            func_0x00bc8a00();
            ppuStack_44 = ppuStack_60;
            ppuVar10 = (pointer_____offset_0x8___ *)&ppuStack_88;
            if (ppuStack_60 != (pointer_____offset_0x8___ *)0x0) {
              LOCK();
              ppuStack_60[1] = ppuStack_60[1] + 1;
              UNLOCK();
              ppuVar10 = (pointer_____offset_0x8___ *)&ppuStack_88;
            }
            goto LAB_016c4492;
          }
          if ((*puStack_54 & 1) == 0) {
            puStack_84 = puStack_54 + 1;
          }
          else {
            puStack_84 = *(pointer_____offset_0x8___ *)(puStack_54 + 8);
          }
          ppuStack_88 = (pointer_____offset_0x8___ *)&UNK_00618925;
          func_0x0197ec60();
        }
        if (piStack_50 != (int *)0x0) {
          LOCK();
          piVar2 = piStack_50 + 1;
          iVar6 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar6 == 0) {
            iVar6 = *piStack_50;
            *ppuVar11 = (pointer_____offset_0x8___)piStack_50;
            pcVar3 = *(code **)(iVar6 + 8);
            ppuVar11[-1] = (pointer_____offset_0x8___)0x16c456f;
            (*pcVar3)();
            *ppuVar11 = (pointer_____offset_0x8___)piStack_50;
            ppuVar11[-1] = &LAB_016c4577;
            func_0x0197e1b0();
          }
        }
        uVar5 = 0;
      }
      else {
        puStack_48 = (pointer_____offset_0x8___)0x0;
        ppuStack_44 = (pointer_____offset_0x8___ *)0x0;
LAB_016c4492:
        iVar6 = *piStack_1c;
        ppuVar10[3] = (pointer_____offset_0x8___)(iVar6 + 0x4c);
        ppuVar10[2] = (pointer_____offset_0x8___)(iVar6 + 0x44);
        ppuVar10[1] = (pointer_____offset_0x8___)&puStack_48;
        *ppuVar10 = (pointer_____offset_0x8___)&puStack_54;
        ppuVar10[-1] = (pointer_____offset_0x8___)0x16c44b7;
        func_0x0198fed0();
        ppuVar11 = ppuStack_44;
        if (ppuStack_44 != (pointer_____offset_0x8___ *)0x0) {
          LOCK();
          ppuVar1 = ppuStack_44 + 1;
          puVar7 = *ppuVar1;
          *ppuVar1 = *ppuVar1 + -1;
          UNLOCK();
          if (puVar7 == (pointer_____offset_0x8___)0x0) {
            puVar7 = *ppuStack_44;
            ppuVar10[-1] = (pointer_____offset_0x8___)ppuStack_44;
            pcVar3 = *(code **)(puVar7 + 8);
            ppuVar10[-2] = (pointer_____offset_0x8___)0x16c44d7;
            (*pcVar3)();
            ppuVar10[-1] = (pointer_____offset_0x8___)ppuVar11;
            ppuVar10[-2] = &LAB_016c44df;
            func_0x0197e1b0();
          }
        }
        piVar2 = *(int **)(*param_2 + 0x54);
        pcVar3 = *(code **)(*piVar2 + 0x10);
        *ppuVar10 = (pointer_____offset_0x8___)&puStack_54;
        ppuVar10[-1] = (pointer_____offset_0x8___)piVar2;
        ppuVar10[-2] = (pointer_____offset_0x8___)0x16c44f5;
        uVar5 = (*pcVar3)();
        ppuVar11 = ppuVar10 + -1;
        if (((uint)puStack_54 & 1) != 0) {
          ppuVar10[-1] = (pointer_____offset_0x8___)uStack_4c;
          ppuVar10[-2] = (pointer_____offset_0x8___)0x16c4508;
          func_0x0197e150();
          ppuVar11 = ppuVar10 + -1;
        }
      }
      ppuVar10 = ppuStack_3c;
      if (ppuStack_3c != (pointer_____offset_0x8___ *)0x0) {
        LOCK();
        ppuVar1 = ppuStack_3c + 1;
        puVar7 = *ppuVar1;
        *ppuVar1 = *ppuVar1 + -1;
        UNLOCK();
        if (puVar7 == (pointer_____offset_0x8___)0x0) {
          puVar7 = *ppuStack_3c;
          *ppuVar11 = (pointer_____offset_0x8___)ppuStack_3c;
          pcVar3 = *(code **)(puVar7 + 8);
          ppuVar11[-1] = (pointer_____offset_0x8___)0x16c4596;
          (*pcVar3)();
          *ppuVar11 = (pointer_____offset_0x8___)ppuVar10;
          ppuVar11[-1] = &LAB_016c459e;
          func_0x0197e1b0();
        }
      }
    }
    else {
      uVar5 = 0;
      puStack_80 = &UNK_007e1b76;
      puStack_84 = (pointer_____offset_0x8___)0x16c43d5;
      func_0x0197ec60();
    }
    apuStack_38[0] = (pointer_____offset_0x8___)0x1a1eab0;
    piStack_50 = piStack_2c;
    if (piStack_24 != (int *)0x0) {
      LOCK();
      piVar2 = piStack_24 + 1;
      iVar6 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar6 == 0) {
        iVar6 = *piStack_24;
        *ppuVar11 = (pointer_____offset_0x8___)piStack_24;
        pcVar3 = *(code **)(iVar6 + 8);
        ppuVar11[-1] = (pointer_____offset_0x8___)0x16c45c7;
        (*pcVar3)();
        *ppuVar11 = (pointer_____offset_0x8___)piStack_24;
        ppuVar11[-1] = &LAB_016c45cf;
        func_0x0197e1b0();
        piStack_50 = piStack_2c;
      }
    }
  }
  if (piStack_50 != (int *)0x0) {
    LOCK();
    piVar2 = piStack_50 + 1;
    iVar6 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar6 == 0) {
      iVar6 = *piStack_50;
      *ppuVar11 = (pointer_____offset_0x8___)piStack_50;
      pcVar3 = *(code **)(iVar6 + 8);
      ppuVar11[-1] = (pointer_____offset_0x8___)0x16c45ec;
      (*pcVar3)();
      *ppuVar11 = (pointer_____offset_0x8___)piStack_50;
      ppuVar11[-1] = &LAB_016c45f4;
      func_0x0197e1b0();
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return uVar5;
  }
LAB_016c46b9:
  *(undefined4 *)((int)ppuVar11 + -4) = 0x16c46be;
  func_0x0197e230();
  pcVar3 = (code *)swi(3);
  uVar5 = (*pcVar3)();
  return uVar5;
}



/* Entry instruction preview:
 * 016b4180: PUSH EBP
 */
