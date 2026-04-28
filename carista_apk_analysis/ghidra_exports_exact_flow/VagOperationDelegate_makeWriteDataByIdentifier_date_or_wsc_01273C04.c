/*
 * VagOperationDelegate_makeWriteDataByIdentifier_date_or_wsc
 * ELF symbol address: 0x01263C04
 * Ghidra address: 0x01273C04 (ELF + 0x10000 image delta)
 * ELF symbol size: 60 bytes
 * Symbol: local helper used by writeVagUdsValue for DATE/WORKSHOP_CODE DIDs
 * Program: libCarista.so
 * Resolved function: FUN_01273c04 @ 01273c04
 * Signature: undefined FUN_01273c04(void)
 * Return type: undefined
 * Function body: [[01273c04, 01273c35]]
 * Parameters:
 * Direct callers:
 *   VagOperationDelegate::writeVagUdsValue @ 012737e0 -> UNCONDITIONAL_CALL from 01273882
 *   VagOperationDelegate::writeVagUdsValue @ 012737e0 -> UNCONDITIONAL_CALL from 012739a4
 *   BmwEDpfRegenOperation::getStartDpfCommands @ 0128eab8 -> UNCONDITIONAL_CALL from 0128eb64
 * Direct callees/references:
 *   READ 01273c38 from 01273c0c
 *   READ 014da87c from 01273c10
 *   READ 015a7014 from 01273c12
 *   WRITE Stack[-0x14] from 01273c14
 *   WRITE Stack[-0x20] from 01273c1a
 *   UNCONDITIONAL_CALL FUN_01281ca0 @ 01281ca0 from 01273c1e
 *   READ Stack[-0x14] from 01273c22
 *   READ 01273c3c from 01273c24
 *   READ 014da87c from 01273c28
 *   READ 015a7014 from 01273c2a
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01273c32
 */

/* Ghidra function: FUN_01273c04 @ 01273c04 */

/* First instructions after recreation:
 * Memory bytes: dfb506af14460a460a497944096809680391a7f10d01009323460ef03ff80398
 * 01273c04: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 01273c06: add r7,sp,#0x18
 * 01273c08: mov r4,r2
 * 01273c0a: mov r2,r1
 * 01273c0c: ldr r1,[0x01273c38]
 * 01273c0e: add r1,pc
 * 01273c10: ldr r1,[r1,#0x0]
 * 01273c12: ldr r1,[r1,#0x0]
 * 01273c14: str r1,[sp,#0xc]
 * 01273c16: sub.w r1,r7,#0xd
 * 01273c1a: str r3,[sp,#0x0]
 * 01273c1c: mov r3,r4
 * 01273c1e: bl 0x01281ca0
 * 01273c22: ldr r0,[sp,#0xc]
 * 01273c24: ldr r1,[0x01273c3c]
 * 01273c26: add r1,pc
 * 01273c28: ldr r1,[r1,#0x0]
 * 01273c2a: ldr r1,[r1,#0x0]
 * 01273c2c: cmp r1,r0
 * 01273c2e: it eq
 * 01273c30: pop.eq {r0,r1,r2,r3,r4,r6,r7,pc}
 * 01273c32: blx 0x013fa400
 * 01273c40: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 01273c42: add r7,sp,#0x18
 */


undefined8 FUN_01273c04(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_01281ca0(param_1,&stack0xffffffeb,param_2,param_3,param_4,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return CONCAT44(param_2,param_4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


