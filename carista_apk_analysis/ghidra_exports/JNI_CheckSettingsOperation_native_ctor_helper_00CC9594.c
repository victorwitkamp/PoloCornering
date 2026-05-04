/*
 * JNI_CheckSettingsOperation_native_ctor_helper
 * ELF symbol address: 0x00CB9594
 * Ghidra address: 0x00CC9594 (ELF + 0x10000 image delta)
 * ELF symbol size: 52 bytes
 * Symbol: local helper called by CheckSettingsOperation_initNative
 * Program: libCarista.so
 * Resolved function: FUN_00cc9594 @ 00cc9594
 * Signature: undefined FUN_00cc9594(void)
 * Return type: undefined
 * Function body: [[00cc9594, 00cc95bf]]
 * Parameters:
 * Direct callers:
 *   Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative @ 00cc93c8 -> UNCONDITIONAL_CALL from 00cc940c
 * Direct callees/references:
 *   READ 00cc95c0 from 00cc959c
 *   READ 014da87c from 00cc95a0
 *   READ 015a7014 from 00cc95a2
 *   WRITE Stack[-0xc] from 00cc95a4
 *   UNCONDITIONAL_CALL FUN_00cd8198 @ 00cd8198 from 00cc95a8
 *   READ Stack[-0xc] from 00cc95ac
 *   READ 00cc95c4 from 00cc95ae
 *   READ 014da87c from 00cc95b2
 *   READ 015a7014 from 00cc95b4
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cc95bc
 */

/* Ghidra function: FUN_00cc9594 @ 00cc9594 */

/* First instructions after recreation:
 * Memory bytes: e0b502af13460a4608497944096809680191791f0ef0f6fd0198054979440968
 * 00cc9594: push {r5,r6,r7,lr}
 * 00cc9596: add r7,sp,#0x8
 * 00cc9598: mov r3,r2
 * 00cc959a: mov r2,r1
 * 00cc959c: ldr r1,[0x00cc95c0]
 * 00cc959e: add r1,pc
 * 00cc95a0: ldr r1,[r1,#0x0]
 * 00cc95a2: ldr r1,[r1,#0x0]
 * 00cc95a4: str r1,[sp,#0x4]
 * 00cc95a6: subs r1,r7,#0x5
 * 00cc95a8: bl 0x00cd8198
 * 00cc95ac: ldr r0,[sp,#0x4]
 * 00cc95ae: ldr r1,[0x00cc95c4]
 * 00cc95b0: add r1,pc
 * 00cc95b2: ldr r1,[r1,#0x0]
 * 00cc95b4: ldr r1,[r1,#0x0]
 * 00cc95b6: cmp r1,r0
 * 00cc95b8: it eq
 * 00cc95ba: pop.eq {r2,r3,r7,pc}
 * 00cc95bc: blx 0x013fa400
 * 00cc95c8: push {r4,r6,r7,lr}
 * 00cc95ca: add r7,sp,#0x8
 * 00cc95cc: mov r4,r0
 * 00cc95ce: ldr r0,[r0,#0x4]
 */


void FUN_00cc9594(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_00cd8198(param_1,&stack0xfffffff3,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


