/* Target VagEcuInfoWithCoding_ctor_full @ 013cb870 (Ghidra 013db870) */
/* Size: 126 bytes */
/* Reason: full VagEcuInfoWithCoding constructor overload */
/* Function: _ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_SC_SC_SC_RKNS3_IbEERKNS3_INS2_13unordered_setItNSL_ItEENSN_ItEENS7_ItEEEEEE @ 013cb870 */

/* Symbols at target:
 * Function _ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_SC_SC_SC_RKNS3_IbEERKNS3_INS2_13unordered_setItNSL_ItEENSN_ItEENS7_ItEEEEEE
 * Label _ZN20VagEcuInfoWithCodingC1EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_SC_SC_SC_RKNS3_IbEERKNS3_INS2_13unordered_setItNSL_ItEENSN_ItEENS7_ItEEEEEE
 */


void _ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_SC_SC_SC_RKNS3_IbEERKNS3_INS2_13unordered_setItNSL_ItEENSN_ItEENS7_ItEEEEEE
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 *param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15)

{
  int iVar1;
  
  func_0x0198f560(param_1,param_2,param_3,param_4,param_5,param_6,param_8,param_9,param_10,param_11,
                  param_12,param_13,param_14,param_15);
  *param_1 = 0x1a19a54;
  param_1[0x19] = *param_7;
  iVar1 = param_7[1];
  param_1[0x1a] = iVar1;
  if (iVar1 != 0) {
    LOCK();
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    UNLOCK();
  }
  return;
}



/* Entry instruction preview:
 * 013cb870: PUSH EBP
 */
