/*
 * JNI_GetEcuInfoOperation_initNative
 * ELF symbol address: 0x00CBB01C
 * Ghidra address: 0x00CCB01C (ELF + 0x10000 image delta)
 * ELF symbol size: 472 bytes
 * Symbol: Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative @ 00ccb01c
 * Signature: undefined Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative(void)
 * Return type: undefined
 * Function body: [[00ccb01c, 00ccb0b1]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00ccb1cc from 00ccb028
 *   READ 014da87c from 00ccb032
 *   READ 015a7014 from 00ccb034
 *   WRITE Stack[-0x1c] from 00ccb036
 *   READ 00ccb1d0 from 00ccb038
 *   PARAM 0082ce45 from 00ccb03a
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00ccb03c
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Ecu> @ 013fb8d0 from 00ccb044
 *   WRITE Stack[-0x20] from 00ccb048
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Operation> @ 013fb7d0 from 00ccb04e
 *   UNCONDITIONAL_CALL _ZNSt6__ndk110shared_ptrI9OperationEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE @ 013fb860 from 00ccb056
 *   READ 00ccb1d4 from 00ccb05c
 *   PARAM 014f13e0 from 00ccb062
 *   UNCONDITIONAL_CALL FUN_00ccb1f4 @ 00ccb1f4 from 00ccb064
 *   READ Stack[-0x28] from 00ccb068
 *   WRITE Stack[-0x40] from 00ccb06c
 *   WRITE Stack[-0x3c] from 00ccb070
 *   WRITE Stack[-0x28] from 00ccb072
 *   UNCONDITIONAL_CALL FUN_00ccb230 @ 00ccb230 from 00ccb078
 *   UNCONDITIONAL_CALL JniOperations::put @ 013fb3f0 from 00ccb082
 *   READ Stack[-0x40] from 00ccb088
 *   UNCONDITIONAL_CALL FUN_00cbfa28 @ 00cbfa28 from 00ccb08a
 *   UNCONDITIONAL_CALL FUN_00cbfa28 @ 00cbfa28 from 00ccb090
 *   READ Stack[-0x1c] from 00ccb096
 *   READ 00ccb1f0 from 00ccb098
 *   READ 014da87c from 00ccb09c
 *   READ 015a7014 from 00ccb09e
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00ccb0ae
 */

/* Ghidra function: Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative @ 00ccb01c */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d8ab0804668481e46144678440d4600680068099065487844
 * 00ccb01c: push {r4,r5,r6,r7,lr}
 * 00ccb01e: add r7,sp,#0xc
 * 00ccb020: push.w r8
 * 00ccb024: sub sp,#0x28
 * 00ccb026: mov r8,r0
 * 00ccb028: ldr r0,[0x00ccb1cc]
 * 00ccb02a: mov r6,r3
 * 00ccb02c: mov r4,r2
 * 00ccb02e: add r0,pc
 * 00ccb030: mov r5,r1
 * 00ccb032: ldr r0,[r0,#0x0]
 * 00ccb034: ldr r0,[r0,#0x0]
 * 00ccb036: str r0,[sp,#0x24]
 * 00ccb038: ldr r0,[0x00ccb1d0]
 * 00ccb03a: add r0,pc
 * 00ccb03c: blx 0x013fb5b0
 * 00ccb040: mov r0,r8
 * 00ccb042: mov r1,r4
 * 00ccb044: blx 0x013fb8d0
 * 00ccb048: str r0,[sp,#0x20]
 * 00ccb04a: mov r0,r8
 * 00ccb04c: mov r1,r6
 * 00ccb04e: blx 0x013fb7d0
 * 00ccb052: adds r1,r0,#0x4
 */


void Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative
               (_JNIEnv *param_1,_jobject *param_2,_jobject *param_3,_jobject *param_4)

{
  int iVar1;
  Operation *pOVar2;
  int local_40;
  undefined4 local_3c;
  undefined1 auStack_34 [12];
  int local_28;
  undefined4 uStack_24;
  Ecu *local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  Log::d("Creating native GetEcuInfoOperation");
  local_20 = JniHelper::getNativePointer<Ecu>(param_1,param_3);
  pOVar2 = JniHelper::getNativePointer<Operation>(param_1,param_4);
  _ZNSt6__ndk110shared_ptrI9OperationEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
            (auStack_34,pOVar2 + 4);
  FUN_00ccb1f4(&local_28,&DAT_014f13e0,&local_20,auStack_34);
  local_40 = local_28;
  local_3c = uStack_24;
  local_28 = 0;
  uStack_24 = 0;
  FUN_00ccb230(&local_28);
  JniOperations::put(param_1,param_2,(shared_ptr *)&local_40);
  iVar1 = local_40;
  FUN_00cbfa28(&local_40);
  FUN_00cbfa28(auStack_34);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c,iVar1 >> 0x1f);
  }
  return;
}


