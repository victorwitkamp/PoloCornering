/*
 * VagOperationDelegate_makeReadDataByIdentifier
 * ELF symbol address: 0x01263C40
 * Ghidra address: 0x01273C40 (ELF + 0x10000 image delta)
 * ELF symbol size: 60 bytes
 * Symbol: local helper used by writeVagUdsValue optional read-back
 * Program: libCarista.so
 * Resolved function: FUN_01273c40 @ 01273c40
 * Signature: undefined FUN_01273c40(void)
 * Return type: undefined
 * Function body: [[01273c40, 01273c71]]
 * Parameters:
 * Direct callers:
 *   VagOperationDelegate::writeVagUdsValue @ 012737e0 -> UNCONDITIONAL_CALL from 01273924
 * Direct callees/references:
 *   READ 01273c74 from 01273c48
 *   READ 014da87c from 01273c4c
 *   READ 015a7014 from 01273c4e
 *   WRITE Stack[-0x14] from 01273c50
 *   WRITE Stack[-0x20] from 01273c56
 *   UNCONDITIONAL_CALL FUN_01281d98 @ 01281d98 from 01273c5a
 *   READ Stack[-0x14] from 01273c5e
 *   READ 01273c78 from 01273c60
 *   READ 014da87c from 01273c64
 *   READ 015a7014 from 01273c66
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01273c6e
 */

/* Ghidra function: FUN_01273c40 @ 01273c40 */

/* First instructions after recreation:
 * Memory bytes: dfb506af14460a460a497944096809680391a7f10d01009323460ef09df80398
 * 01273c40: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 01273c42: add r7,sp,#0x18
 * 01273c44: mov r4,r2
 * 01273c46: mov r2,r1
 * 01273c48: ldr r1,[0x01273c74]
 * 01273c4a: add r1,pc
 * 01273c4c: ldr r1,[r1,#0x0]
 * 01273c4e: ldr r1,[r1,#0x0]
 * 01273c50: str r1,[sp,#0xc]
 * 01273c52: sub.w r1,r7,#0xd
 * 01273c56: str r3,[sp,#0x0]
 * 01273c58: mov r3,r4
 * 01273c5a: bl 0x01281d98
 * 01273c5e: ldr r0,[sp,#0xc]
 * 01273c60: ldr r1,[0x01273c78]
 * 01273c62: add r1,pc
 * 01273c64: ldr r1,[r1,#0x0]
 * 01273c66: ldr r1,[r1,#0x0]
 * 01273c68: cmp r1,r0
 * 01273c6a: it eq
 * 01273c6c: pop.eq {r0,r1,r2,r3,r4,r6,r7,pc}
 * 01273c6e: blx 0x013fa400
 * 01273c7c: push {r5,r6,r7,lr}
 * 01273c7e: add r7,sp,#0x8
 */


undefined8 FUN_01273c40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_01281d98(param_1,&stack0xffffffeb,param_2,param_3,param_4,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return CONCAT44(param_2,param_4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


