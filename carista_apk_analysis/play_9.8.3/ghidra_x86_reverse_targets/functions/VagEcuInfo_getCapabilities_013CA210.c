/* Target VagEcuInfo_getCapabilities @ 013ca210 (Ghidra 013da210) */
/* Size: 21 bytes */
/* Reason: native VagEcuInfo capability accessor */
/* Function: _ZNK10VagEcuInfo15getCapabilitiesEv @ 013ca210 */

/* Symbols at target:
 * Function _ZNK10VagEcuInfo15getCapabilitiesEv
 */


char _ZNK10VagEcuInfo15getCapabilitiesEv(int param_1)

{
  return (1 < *(uint *)(param_1 + 0x20)) * '\x02' + '\t';
}



/* Entry instruction preview:
 * 013ca210: MOV EAX,dword ptr [ESP + 0x4] scalars: `0x4`
 */
