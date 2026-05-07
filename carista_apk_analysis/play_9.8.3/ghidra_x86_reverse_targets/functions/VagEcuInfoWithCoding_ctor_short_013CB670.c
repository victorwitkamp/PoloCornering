/* Target VagEcuInfoWithCoding_ctor_short @ 013cb670 (Ghidra 013db670) */
/* Size: 499 bytes */
/* Reason: short VagEcuInfoWithCoding constructor overload */
/* Function: _ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_ @ 013cb670 */

/* Symbols at target:
 * Function _ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_
 * Label _ZN20VagEcuInfoWithCodingC1EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_
 */


void _ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 *param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  int in_GS_OFFSET;
  undefined4 uStack_3c;
  int *piStack_38;
  undefined4 uStack_34;
  int *piStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_1c = 0;
  piStack_18 = (int *)0x0;
  uStack_24 = 0;
  piStack_20 = (int *)0x0;
  uStack_2c = 0;
  piStack_28 = (int *)0x0;
  uStack_34 = 0;
  piStack_30 = (int *)0x0;
  uStack_3c = 0;
  piStack_38 = (int *)0x0;
  func_0x0198f560(param_1,param_2,param_3,param_4,param_5,param_6,param_8,param_9,param_10,
                  &uStack_1c,&uStack_24,&uStack_2c,&uStack_34,&uStack_3c);
  piVar4 = piStack_38;
  *param_1 = 0x1a19a54;
  param_1[0x19] = *param_7;
  iVar2 = param_7[1];
  param_1[0x1a] = iVar2;
  if (iVar2 != 0) {
    LOCK();
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
    UNLOCK();
  }
  if (piStack_38 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_38 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_38 + 8))(piStack_38);
      func_0x0197e1b0(piVar4);
    }
  }
  piVar4 = piStack_30;
  if (piStack_30 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_30 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_30 + 8))(piStack_30);
      func_0x0197e1b0(piVar4);
    }
  }
  piVar4 = piStack_28;
  if (piStack_28 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_28 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_28 + 8))(piStack_28);
      func_0x0197e1b0(piVar4);
    }
  }
  piVar4 = piStack_20;
  if (piStack_20 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_20 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_20 + 8))(piStack_20);
      func_0x0197e1b0(piVar4);
    }
  }
  piVar4 = piStack_18;
  if (piStack_18 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_18 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_18 + 8))(piStack_18);
      func_0x0197e1b0(piVar4);
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return;
  }
  func_0x0197e230();
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



/* Entry instruction preview:
 * 013cb670: PUSH EBP
 */
