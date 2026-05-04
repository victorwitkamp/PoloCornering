/*
 * JNI_CheckSettingsOperation_initNative
 * ELF symbol address: 0x00CB93C8
 * Ghidra address: 0x00CC93C8 (ELF + 0x10000 image delta)
 * ELF symbol size: 460 bytes
 * Symbol: Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative @ 00cc93c8
 * Signature: undefined Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative(void)
 * Return type: undefined
 * Function body: [[00cc93c8, 00cc9459]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cc956c from 00cc93d4
 *   READ 014da87c from 00cc93dc
 *   READ 015a7014 from 00cc93de
 *   WRITE Stack[-0x1c] from 00cc93e0
 *   READ 00cc9570 from 00cc93e2
 *   PARAM 00804ed8 from 00cc93e4
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00cc93e6
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative @ 00cc93c8 from 00cc93ea
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Operation> @ 013fb7d0 from 00cc93f0
 *   UNCONDITIONAL_CALL _ZNSt6__ndk110shared_ptrI9OperationEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE @ 013fb860 from 00cc93f8
 *   UNCONDITIONAL_JUMP Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative @ 00cc93c8 from 00cc93fc
 *   WRITE Stack[-0x30] from 00cc9400
 *   READ 00cc9574 from 00cc9406
 *   PARAM 014f13e0 from 00cc940a
 *   UNCONDITIONAL_CALL FUN_00cc9594 @ 00cc9594 from 00cc940c
 *   READ Stack[-0x24] from 00cc9410
 *   WRITE Stack[-0x3c] from 00cc9414
 *   WRITE Stack[-0x38] from 00cc9418
 *   WRITE Stack[-0x24] from 00cc941a
 *   UNCONDITIONAL_CALL FUN_00cc95c8 @ 00cc95c8 from 00cc9420
 *   UNCONDITIONAL_CALL JniOperations::put @ 013fb3f0 from 00cc942a
 *   READ Stack[-0x3c] from 00cc942e
 *   UNCONDITIONAL_CALL FUN_00cbfa28 @ 00cbfa28 from 00cc9432
 *   UNCONDITIONAL_CALL FUN_00cbfa28 @ 00cbfa28 from 00cc9438
 *   READ Stack[-0x1c] from 00cc943e
 *   READ 00cc9590 from 00cc9440
 *   READ 014da87c from 00cc9444
 *   READ 015a7014 from 00cc9446
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cc9456
 */

/* Ghidra function: Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative @ 00cc93c8 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d8ab00446654816460d4678440068006809906348784432f3
 * 00cc93c8: push {r4,r5,r6,r7,lr}
 * 00cc93ca: add r7,sp,#0xc
 * 00cc93cc: push.w r8
 * 00cc93d0: sub sp,#0x28
 * 00cc93d2: mov r4,r0
 * 00cc93d4: ldr r0,[0x00cc956c]
 * 00cc93d6: mov r6,r2
 * 00cc93d8: mov r5,r1
 * 00cc93da: add r0,pc
 * 00cc93dc: ldr r0,[r0,#0x0]
 * 00cc93de: ldr r0,[r0,#0x0]
 * 00cc93e0: str r0,[sp,#0x24]
 * 00cc93e2: ldr r0,[0x00cc9570]
 * 00cc93e4: add r0,pc
 * 00cc93e6: blx 0x013fb5b0
 * 00cc93ea: cbz r6,0x00cc93fe
 * 00cc93ec: mov r0,r4
 * 00cc93ee: mov r1,r6
 * 00cc93f0: blx 0x013fb7d0
 * 00cc93f4: adds r1,r0,#0x4
 * 00cc93f6: add r0,sp,#0x10
 * 00cc93f8: blx 0x013fb860
 * 00cc93fc: b 0x00cc9404
 * 00cc93fe: movs r0,#0x0
 */


void Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative
               (_JNIEnv *param_1,_jobject *param_2,_jobject *param_3)

{
  int iVar1;
  Operation *pOVar2;
  int local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_24;
  undefined4 uStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  Log::d("Creating native CheckSettingsOperation");
  if (param_3 == (_jobject *)0x0) {
    local_30 = 0;
    uStack_2c = 0;
  }
  else {
    pOVar2 = JniHelper::getNativePointer<Operation>(param_1,param_3);
    _ZNSt6__ndk110shared_ptrI9OperationEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
              (&local_30,pOVar2 + 4);
  }
  FUN_00cc9594(&local_24,&DAT_014f13e0,&local_30);
  local_3c = local_24;
  local_38 = uStack_20;
  local_24 = 0;
  uStack_20 = 0;
  FUN_00cc95c8(&local_24);
  JniOperations::put(param_1,param_2,(shared_ptr *)&local_3c);
  iVar1 = local_3c;
  FUN_00cbfa28(&local_3c);
  FUN_00cbfa28(&local_30);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c,iVar1 >> 0x1f);
  }
  return;
}


