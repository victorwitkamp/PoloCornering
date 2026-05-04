/*
 * VagOperationDelegate_makeWriteDataByIdentifier_target
 * ELF symbol address: 0x01263CB0
 * Ghidra address: 0x01273CB0 (ELF + 0x10000 image delta)
 * ELF symbol size: 60 bytes
 * Symbol: local helper used by writeVagUdsValue for final target DID
 * Program: libCarista.so
 * Resolved function: FUN_01273cb0 @ 01273cb0
 * Signature: undefined FUN_01273cb0(void)
 * Return type: undefined
 * Function body: [[01273cb0, 01273ce1]]
 * Parameters:
 * Direct callers:
 *   VagOperationDelegate::writeVagUdsValue @ 012737e0 -> UNCONDITIONAL_CALL from 01273a18
 * Direct callees/references:
 *   READ 01273ce4 from 01273cb8
 *   READ 014da87c from 01273cbc
 *   READ 015a7014 from 01273cbe
 *   WRITE Stack[-0x14] from 01273cc0
 *   WRITE Stack[-0x20] from 01273cc6
 *   UNCONDITIONAL_CALL FUN_01281f58 @ 01281f58 from 01273cca
 *   READ Stack[-0x14] from 01273cce
 *   READ 01273ce8 from 01273cd0
 *   READ 014da87c from 01273cd4
 *   READ 015a7014 from 01273cd6
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01273cde
 */

/* Ghidra function: FUN_01273cb0 @ 01273cb0 */

/* First instructions after recreation:
 * Memory bytes: dfb506af14460a460a497944096809680391a7f10d01009323460ef045f90398
 * 01273cb0: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 01273cb2: add r7,sp,#0x18
 * 01273cb4: mov r4,r2
 * 01273cb6: mov r2,r1
 * 01273cb8: ldr r1,[0x01273ce4]
 * 01273cba: add r1,pc
 * 01273cbc: ldr r1,[r1,#0x0]
 * 01273cbe: ldr r1,[r1,#0x0]
 * 01273cc0: str r1,[sp,#0xc]
 * 01273cc2: sub.w r1,r7,#0xd
 * 01273cc6: str r3,[sp,#0x0]
 * 01273cc8: mov r3,r4
 * 01273cca: bl 0x01281f58
 * 01273cce: ldr r0,[sp,#0xc]
 * 01273cd0: ldr r1,[0x01273ce8]
 * 01273cd2: add r1,pc
 * 01273cd4: ldr r1,[r1,#0x0]
 * 01273cd6: ldr r1,[r1,#0x0]
 * 01273cd8: cmp r1,r0
 * 01273cda: it eq
 * 01273cdc: pop.eq {r0,r1,r2,r3,r4,r6,r7,pc}
 * 01273cde: blx 0x013fa400
 * 01273cec: push {r4,r5,r6,r7,lr}
 * 01273cee: add r7,sp,#0xc
 */


undefined8 FUN_01273cb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_01281f58(param_1,&stack0xffffffeb,param_2,param_3,param_4,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return CONCAT44(param_2,param_4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


