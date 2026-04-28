/*
 * JNI_GetEcuInfoOperation_getCodingRawAddress
 * ELF symbol address: 0x00CBB40C
 * Ghidra address: 0x00CCB40C (ELF + 0x10000 image delta)
 * ELF symbol size: 340 bytes
 * Symbol: Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_getCodingRawAddress
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_getCodingRawAddress @ 00ccb40c
 * Signature: undefined Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_getCodingRawAddress(void)
 * Return type: undefined
 * Function body: [[00ccb40c, 00ccb44b]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00ccb540 from 00ccb418
 *   READ 014da87c from 00ccb41e
 *   READ 015a7014 from 00ccb420
 *   WRITE Stack[-0x1c] from 00ccb422
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<GetEcuInfoOperation> @ 013fb960 from 00ccb426
 *   READ Stack[-0x1c] from 00ccb432
 *   READ 00ccb55c from 00ccb434
 *   READ 014da87c from 00ccb438
 *   READ 015a7014 from 00ccb43a
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00ccb448
 */

/* Ghidra function: Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_getCodingRawAddress @ 00ccb40c */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b00446494815467844006800680790204630f39ce20168
 * 00ccb40c: push {r4,r5,r6,r7,lr}
 * 00ccb40e: add r7,sp,#0xc
 * 00ccb410: push.w r8
 * 00ccb414: sub sp,#0x20
 * 00ccb416: mov r4,r0
 * 00ccb418: ldr r0,[0x00ccb540]
 * 00ccb41a: mov r5,r2
 * 00ccb41c: add r0,pc
 * 00ccb41e: ldr r0,[r0,#0x0]
 * 00ccb420: ldr r0,[r0,#0x0]
 * 00ccb422: str r0,[sp,#0x1c]
 * 00ccb424: mov r0,r4
 * 00ccb426: blx 0x013fb960
 * 00ccb42a: ldr r1,[r0,#0x0]
 * 00ccb42c: ldr r2,[r1,#0x78]
 * 00ccb42e: uxth r1,r5
 * 00ccb430: blx r2
 * 00ccb432: ldr r2,[sp,#0x1c]
 * 00ccb434: ldr r3,[0x00ccb55c]
 * 00ccb436: add r3,pc
 * 00ccb438: ldr r3,[r3,#0x0]
 * 00ccb43a: ldr r3,[r3,#0x0]
 * 00ccb43c: cmp r3,r2
 * 00ccb43e: ittt eq
 */


void Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_getCodingRawAddress
               (_JNIEnv *param_1,_jobject *param_2,undefined2 param_3)

{
  int iVar1;
  GetEcuInfoOperation *pGVar2;
  
  iVar1 = __stack_chk_guard;
  pGVar2 = JniHelper::getNativePointer<GetEcuInfoOperation>(param_1,param_2);
  (**(code **)(*(int *)pGVar2 + 0x78))(pGVar2,param_3);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


