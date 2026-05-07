/* Target VagSetting_isSubmodule @ 01426dd0 (Ghidra 01436dd0) */
/* Reason: vtable slot +0x3C predicate target recovered from VagOperationDelegate availability routing */
/* Function: _ZNK10VagSetting11isSubmoduleEv @ 01426dd0 */


undefined4 _ZNK10VagSetting11isSubmoduleEv(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  return CONCAT31((int3)(uVar1 >> 8),(0x230U >> (uVar1 & 0x1f) & 1) != 0 && (byte)uVar1 < 10);
}



/* References from entry-window instructions:
 * 01426dd0: MOV EAX,dword ptr [ESP + 0x4] scalars: `0x4`
 */
