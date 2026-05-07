/* Target VagEcuInfo_ctor_short @ 013c94a0 (Ghidra 013d94a0) */
/* Size: 263 bytes */
/* Reason: short VagEcuInfo constructor overload */
/* Function: _ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_ @ 013c94a0 */

/* Symbols at target:
 * Function _ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_
 * Label _ZN10VagEcuInfoC1ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_
 */


void _ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  code *pcVar1;
  int in_GS_OFFSET;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  func_0x0198f560(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,&uStack_1c
                  ,&uStack_24,&uStack_2c,&uStack_34,&uStack_3c);
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return;
  }
  func_0x0197e230();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* Entry instruction preview:
 * 013c94a0: PUSH EBP
 */
