/* Target VagEcuInfo_cloneWith @ 013ca9f0 (Ghidra 013da9f0) */
/* Size: 240 bytes */
/* Reason: VagEcuInfo cloneWith(CodingType) overload */
/* Function: _ZN10VagEcuInfo9cloneWithENS_10CodingTypeE @ 013ca9f0 */

/* Symbols at target:
 * Function _ZN10VagEcuInfo9cloneWithENS_10CodingTypeE
 */


void _ZN10VagEcuInfo9cloneWithENS_10CodingTypeE(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)func_0x0197e0c0(0x70);
  puVar1[1] = 0;
  puVar1[2] = 0;
  *puVar1 = 0x1a19a2c;
  func_0x0198f550(puVar1 + 3,*(undefined4 *)(param_2 + 4),param_2 + 8,param_2 + 0x10,param_2 + 0x18,
                  param_3,param_2 + 0x24,param_2 + 0x2c,param_2 + 0x34,param_2 + 0x3c,param_2 + 0x44
                  ,param_2 + 0x4c,param_2 + 0x54,param_2 + 0x5c);
  *param_1 = puVar1 + 3;
  param_1[1] = puVar1;
  return;
}



/* Entry instruction preview:
 * 013ca9f0: PUSH EBP
 */
