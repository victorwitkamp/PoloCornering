/* Target VagEcuInfo_containsAll @ 013ca230 (Ghidra 013da230) */
/* Size: 131 bytes */
/* Reason: native VagEcuInfo capability-mask helper */
/* Function: _ZN10VagEcuInfo11containsAllEj @ 013ca230 */

/* Symbols at target:
 * Function _ZN10VagEcuInfo11containsAllEj
 */


bool _ZN10VagEcuInfo11containsAllEj(int param_1,uint param_2)

{
  if (((((((param_2 & 1) == 0) || (*(int *)(param_1 + 8) != 0)) &&
        (((param_2 & 2) == 0 || (*(int *)(param_1 + 0x24) != 0)))) &&
       (((param_2 & 4) == 0 || (*(int *)(param_1 + 0x34) != 0)))) &&
      (((param_2 & 8) == 0 || (*(int *)(param_1 + 0x2c) != 0)))) &&
     ((((((param_2 & 0x10) == 0 || (*(int *)(param_1 + 0x10) != 0)) &&
        (((param_2 & 0x20) == 0 || (*(int *)(param_1 + 0x3c) != 0)))) &&
       (((param_2 & 0x40) == 0 || (*(int *)(param_1 + 0x44) != 0)))) &&
      (((-1 < (char)param_2 || (*(int *)(param_1 + 0x4c) != 0)) &&
       (((param_2 & 0x100) == 0 || (*(int *)(param_1 + 0x54) != 0)))))))) {
    return *(int *)(param_1 + 0x5c) != 0 || (param_2 & 0x200) == 0;
  }
  return false;
}



/* Entry instruction preview:
 * 013ca230: MOV ECX,dword ptr [ESP + 0x8] scalars: `0x8`
 */
