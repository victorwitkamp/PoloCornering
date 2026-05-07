/* Target VagEcuInfo_ctor_full @ 013c95b0 (Ghidra 013d95b0) */
/* Size: 305 bytes */
/* Reason: full VagEcuInfo constructor overload that stores the submodule vector at +0x10/+0x14 */
/* Function: _ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_SB_SB_SB_RKNS2_IbEERKNS2_INS1_13unordered_setItNSK_ItEENSM_ItEENS6_ItEEEEEE @ 013c95b0 */

/* Symbols at target:
 * Function _ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_SB_SB_SB_RKNS2_IbEERKNS2_INS1_13unordered_setItNSK_ItEENSM_ItEENS6_ItEEEEEE
 * Label _ZN10VagEcuInfoC1ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_SB_SB_SB_RKNS2_IbEERKNS2_INS1_13unordered_setItNSK_ItEENSM_ItEENS6_ItEEEEEE
 */


void _ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_SB_SB_SB_RKNS2_IbEERKNS2_INS1_13unordered_setItNSK_ItEENSM_ItEENS6_ItEEEEEE
               (undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5,undefined4 param_6,undefined4 *param_7,undefined4 *param_8,
               undefined4 *param_9,undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,
               undefined4 *param_13,undefined4 *param_14)

{
  int iVar1;
  
  func_0x01984de0(param_1);
  *param_1 = 0x1a199fc;
  param_1[1] = param_2;
  param_1[2] = *param_3;
  iVar1 = param_3[1];
  param_1[3] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[4] = *param_4;
  iVar1 = param_4[1];
  param_1[5] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[6] = *param_5;
  iVar1 = param_5[1];
  param_1[7] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[8] = param_6;
  param_1[9] = *param_7;
  iVar1 = param_7[1];
  param_1[10] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[0xb] = *param_8;
  iVar1 = param_8[1];
  param_1[0xc] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[0xd] = *param_9;
  iVar1 = param_9[1];
  param_1[0xe] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[0xf] = *param_10;
  iVar1 = param_10[1];
  param_1[0x10] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[0x11] = *param_11;
  iVar1 = param_11[1];
  param_1[0x12] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[0x13] = *param_12;
  iVar1 = param_12[1];
  param_1[0x14] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[0x15] = *param_13;
  iVar1 = param_13[1];
  param_1[0x16] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  param_1[0x17] = *param_14;
  iVar1 = param_14[1];
  param_1[0x18] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  return;
}



/* Entry instruction preview:
 * 013c95b0: PUSH EBP
 */
