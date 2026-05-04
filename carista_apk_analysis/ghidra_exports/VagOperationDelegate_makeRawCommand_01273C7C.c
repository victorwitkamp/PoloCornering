/*
 * VagOperationDelegate_makeRawCommand
 * ELF symbol address: 0x01263C7C
 * Ghidra address: 0x01273C7C (ELF + 0x10000 image delta)
 * ELF symbol size: 52 bytes
 * Symbol: local helper used by writeVagUdsValue optional raw command
 * Program: libCarista.so
 * Resolved function: FUN_01273c7c @ 01273c7c
 * Signature: undefined FUN_01273c7c(void)
 * Return type: undefined
 * Function body: [[01273c7c, 01273ca7]]
 * Parameters:
 * Direct callers:
 *   VagOperationDelegate::writeVagUdsValue @ 012737e0 -> UNCONDITIONAL_CALL from 01273a70
 *   VagOperationDelegate::unlockSfd2 @ 0127632c -> UNCONDITIONAL_CALL from 01276416
 *   VagOperationDelegate::unlockSfd2 @ 0127632c -> UNCONDITIONAL_CALL from 012765f4
 * Direct callees/references:
 *   READ 01273ca8 from 01273c84
 *   READ 014da87c from 01273c88
 *   READ 015a7014 from 01273c8a
 *   WRITE Stack[-0xc] from 01273c8c
 *   UNCONDITIONAL_CALL FUN_01281e84 @ 01281e84 from 01273c90
 *   READ Stack[-0xc] from 01273c94
 *   READ 01273cac from 01273c96
 *   READ 014da87c from 01273c9a
 *   READ 015a7014 from 01273c9c
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01273ca4
 */

/* Ghidra function: FUN_01273c7c @ 01273c7c */

/* First instructions after recreation:
 * Memory bytes: e0b502af13460a4608497944096809680191791f0ef0f8f80198054979440968
 * 01273c7c: push {r5,r6,r7,lr}
 * 01273c7e: add r7,sp,#0x8
 * 01273c80: mov r3,r2
 * 01273c82: mov r2,r1
 * 01273c84: ldr r1,[0x01273ca8]
 * 01273c86: add r1,pc
 * 01273c88: ldr r1,[r1,#0x0]
 * 01273c8a: ldr r1,[r1,#0x0]
 * 01273c8c: str r1,[sp,#0x4]
 * 01273c8e: subs r1,r7,#0x5
 * 01273c90: bl 0x01281e84
 * 01273c94: ldr r0,[sp,#0x4]
 * 01273c96: ldr r1,[0x01273cac]
 * 01273c98: add r1,pc
 * 01273c9a: ldr r1,[r1,#0x0]
 * 01273c9c: ldr r1,[r1,#0x0]
 * 01273c9e: cmp r1,r0
 * 01273ca0: it eq
 * 01273ca2: pop.eq {r2,r3,r7,pc}
 * 01273ca4: blx 0x013fa400
 * 01273cb0: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 01273cb2: add r7,sp,#0x18
 * 01273cb4: mov r4,r2
 * 01273cb6: mov r2,r1
 */


void FUN_01273c7c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_01281e84(param_1,&stack0xfffffff3,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


