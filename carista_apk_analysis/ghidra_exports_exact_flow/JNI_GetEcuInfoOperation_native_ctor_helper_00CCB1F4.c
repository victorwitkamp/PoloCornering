/*
 * JNI_GetEcuInfoOperation_native_ctor_helper
 * ELF symbol address: 0x00CBB1F4
 * Ghidra address: 0x00CCB1F4 (ELF + 0x10000 image delta)
 * ELF symbol size: 60 bytes
 * Symbol: local helper called by GetEcuInfoOperation_initNative
 * Program: libCarista.so
 * Resolved function: FUN_00ccb1f4 @ 00ccb1f4
 * Signature: undefined FUN_00ccb1f4(void)
 * Return type: undefined
 * Function body: [[00ccb1f4, 00ccb225]]
 * Parameters:
 * Direct callers:
 *   Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative @ 00ccb01c -> UNCONDITIONAL_CALL from 00ccb064
 * Direct callees/references:
 *   READ 00ccb228 from 00ccb1fc
 *   READ 014da87c from 00ccb200
 *   READ 015a7014 from 00ccb202
 *   WRITE Stack[-0x14] from 00ccb204
 *   WRITE Stack[-0x20] from 00ccb20a
 *   UNCONDITIONAL_CALL FUN_00cd87a8 @ 00cd87a8 from 00ccb20e
 *   READ Stack[-0x14] from 00ccb212
 *   READ 00ccb22c from 00ccb214
 *   READ 014da87c from 00ccb218
 *   READ 015a7014 from 00ccb21a
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00ccb222
 */

/* Ghidra function: FUN_00ccb1f4 @ 00ccb1f4 */

/* First instructions after recreation:
 * Memory bytes: dfb506af14460a460a497944096809680391a7f10d01009323460df0cbfa0398
 * 00ccb1f4: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 00ccb1f6: add r7,sp,#0x18
 * 00ccb1f8: mov r4,r2
 * 00ccb1fa: mov r2,r1
 * 00ccb1fc: ldr r1,[0x00ccb228]
 * 00ccb1fe: add r1,pc
 * 00ccb200: ldr r1,[r1,#0x0]
 * 00ccb202: ldr r1,[r1,#0x0]
 * 00ccb204: str r1,[sp,#0xc]
 * 00ccb206: sub.w r1,r7,#0xd
 * 00ccb20a: str r3,[sp,#0x0]
 * 00ccb20c: mov r3,r4
 * 00ccb20e: bl 0x00cd87a8
 * 00ccb212: ldr r0,[sp,#0xc]
 * 00ccb214: ldr r1,[0x00ccb22c]
 * 00ccb216: add r1,pc
 * 00ccb218: ldr r1,[r1,#0x0]
 * 00ccb21a: ldr r1,[r1,#0x0]
 * 00ccb21c: cmp r1,r0
 * 00ccb21e: it eq
 * 00ccb220: pop.eq {r0,r1,r2,r3,r4,r6,r7,pc}
 * 00ccb222: blx 0x013fa400
 * 00ccb230: push {r4,r6,r7,lr}
 * 00ccb232: add r7,sp,#0x8
 */


undefined8 FUN_00ccb1f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_00cd87a8(param_1,&stack0xffffffeb,param_2,param_3,param_4,param_2,param_3);
  if (__stack_chk_guard == iVar1) {
    return CONCAT44(param_2,param_4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


