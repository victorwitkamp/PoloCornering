/* Target StringWhitelist_itemMatches @ 00cd97b0 (Ghidra 00ce97b0) */
/* Reason: x86 StringWhitelist::itemMatches behavior recovered from Play 9.8.3 */
/* Function: _ZNK15StringWhitelist11itemMatchesERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_ @ 00cd97b0 */


undefined1
_ZNK15StringWhitelist11itemMatchesERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_
          (undefined4 param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  code *pcVar3;
  char cVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int in_GS_OFFSET;
  bool bVar10;
  undefined4 uStack_20;
  uint uStack_1c;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_20 = CONCAT13(uStack_20._3_1_,0x2a02);
  cVar4 = func_0x01982ad0(param_2,&uStack_20);
  if ((uStack_20 & 1) != 0) {
    func_0x0197e150(iStack_18);
  }
  if (cVar4 == '\0') {
    uStack_20 = CONCAT13(uStack_20._3_1_,0x2a02);
    cVar4 = func_0x01982b40(param_2,&uStack_20);
    if ((uStack_20 & 1) != 0) {
      func_0x0197e150(iStack_18);
    }
    if (cVar4 != '\0') {
      if ((*param_2 & 1) == 0) {
        uVar6 = (uint)(*param_2 >> 1);
        param_2 = param_2 + 1;
      }
      else {
        uVar6 = *(uint *)(param_2 + 4);
        param_2 = *(byte **)(param_2 + 8);
      }
      uVar9 = uVar6 - 1;
      if (uVar6 < uVar6 - 1) {
        uVar9 = uVar6;
      }
      if (0xfffffff7 < uVar9) {
LAB_00ce9ade:
        if (*(int *)(in_GS_OFFSET + 0x14) != iStack_14) goto LAB_00ce9b36;
        func_0x00bbc5e0(&uStack_20);
        goto LAB_00ce9af4;
      }
      if (uVar9 < 0xb) {
        uStack_20 = CONCAT31(uStack_20._1_3_,(char)uVar9 * '\x02');
        iVar7 = (int)&uStack_20 + 1;
        if (uVar9 != 0) goto LAB_00ce996e;
      }
      else {
        iVar7 = func_0x0197e0c0((uVar9 | 7) + 1);
        uStack_20 = (uVar9 | 7) + 2;
        uStack_1c = uVar9;
        iStack_18 = iVar7;
LAB_00ce996e:
        func_0x0197e0d0(iVar7,param_2,uVar9);
      }
      *(undefined1 *)(iVar7 + uVar9) = 0;
      uVar5 = func_0x01982ad0(param_3,&uStack_20);
      goto LAB_00ce999c;
    }
    iVar7 = func_0x01982b90(param_2,0x2e,0);
    if (iVar7 == -1) {
      bVar1 = *param_3;
      uVar6 = *(uint *)(param_3 + 4);
      if ((bVar1 & 1) == 0) {
        uVar6 = (uint)(bVar1 >> 1);
      }
      bVar2 = *param_2;
      if ((bVar2 & 1) == 0) {
        uVar9 = (uint)(bVar2 >> 1);
      }
      else {
        uVar9 = *(uint *)(param_2 + 4);
      }
      if (uVar6 != uVar9) goto LAB_00ce9a84;
      if ((bVar2 & 1) == 0) {
        param_2 = param_2 + 1;
      }
      else {
        param_2 = *(byte **)(param_2 + 8);
      }
      if ((bVar1 & 1) == 0) {
        uVar5 = 1;
        if (1 < bVar1) {
          iVar7 = 0;
          do {
            uVar5 = param_3[iVar7 + 1] == param_2[iVar7];
            if (!(bool)uVar5) break;
            bVar10 = (bVar1 >> 1) - 1 != iVar7;
            iVar7 = iVar7 + 1;
          } while (bVar10);
        }
      }
      else {
        iVar7 = func_0x0197e980(*(undefined4 *)(param_3 + 8),param_2,*(uint *)(param_3 + 4));
        uVar5 = iVar7 == 0;
      }
    }
    else {
      bVar1 = *param_2;
      if ((bVar1 & 1) == 0) {
        uVar6 = (uint)(bVar1 >> 1);
      }
      else {
        uVar6 = *(uint *)(param_2 + 4);
      }
      bVar2 = *param_3;
      if ((bVar2 & 1) == 0) {
        uVar9 = (uint)(bVar2 >> 1);
      }
      else {
        uVar9 = *(uint *)(param_3 + 4);
      }
      if (uVar6 == uVar9) {
        uVar5 = 1;
        if (uVar6 != 0) {
          if ((bVar1 & 1) == 0) {
            param_2 = param_2 + 1;
          }
          else {
            param_2 = *(byte **)(param_2 + 8);
          }
          if ((bVar2 & 1) == 0) {
            param_3 = param_3 + 1;
          }
          else {
            param_3 = *(byte **)(param_3 + 8);
          }
          uVar9 = 0;
          do {
            if ((param_2[uVar9] != 0x2e) && (param_2[uVar9] != param_3[uVar9])) goto LAB_00ce9a84;
            uVar9 = uVar9 + 1;
          } while (uVar6 != uVar9);
        }
      }
      else {
LAB_00ce9a84:
        uVar5 = 0;
      }
    }
  }
  else {
    bVar1 = *param_2;
    if ((bVar1 & 1) == 0) {
      uVar6 = (uint)(bVar1 >> 1);
    }
    else {
      uVar6 = *(uint *)(param_2 + 4);
    }
    if (uVar6 == 0) {
LAB_00ce9af4:
      if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
        uVar8 = func_0x00c6e900(&uStack_20);
        if ((uStack_20 & 1) != 0) {
          func_0x0197e150(iStack_18);
        }
        if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
          func_0x0197a750(uVar8);
        }
      }
      goto LAB_00ce9b36;
    }
    if ((bVar1 & 1) == 0) {
      param_2 = param_2 + 1;
    }
    else {
      param_2 = *(byte **)(param_2 + 8);
    }
    uVar9 = uVar6 - 1;
    if (0xfffffff7 < uVar9) goto LAB_00ce9ade;
    if (uVar6 < 0xc) {
      uStack_20 = CONCAT31(uStack_20._1_3_,(char)uVar9 * '\x02');
      iVar7 = (int)&uStack_20 + 1;
      if (uVar9 != 0) goto LAB_00ce98f6;
    }
    else {
      iVar7 = func_0x0197e0c0((uVar9 | 7) + 1);
      uStack_20 = (uVar9 | 7) + 2;
      uStack_1c = uVar9;
      iStack_18 = iVar7;
LAB_00ce98f6:
      func_0x0197e0d0(iVar7,param_2 + 1,uVar9);
    }
    *(undefined1 *)(iVar7 + uVar9) = 0;
    uVar5 = func_0x01982b40(param_3,&uStack_20);
LAB_00ce999c:
    if ((uStack_20 & 1) != 0) {
      func_0x0197e150(iStack_18);
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return uVar5;
  }
LAB_00ce9b36:
  func_0x0197e230();
  pcVar3 = (code *)swi(3);
  uVar5 = (*pcVar3)();
  return uVar5;
}



/* References from entry-window instructions:
 * 00cd97b0: PUSH EBP
 */
