/*
 * JNI_ReadValuesOperation_getSettingValue
 * ELF symbol address: 0x00CBE1DC
 * Ghidra address: 0x00CCE1DC (ELF + 0x10000 image delta)
 * ELF symbol size: 416 bytes
 * Symbol: Java_com_prizmos_carista_library_operation_ReadValuesOperation_getSettingValue
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_operation_ReadValuesOperation_getSettingValue @ 00cce1dc
 * Signature: undefined Java_com_prizmos_carista_library_operation_ReadValuesOperation_getSettingValue(void)
 * Return type: undefined
 * Function body: [[00cce1dc, 00cce24b]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cce35c from 00cce1e8
 *   READ 014da87c from 00cce1ee
 *   READ 015a7014 from 00cce1f0
 *   WRITE Stack[-0x1c] from 00cce1f2
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Setting> @ 013fb820 from 00cce1f8
 *   UNCONDITIONAL_CALL _ZNSt6__ndk110shared_ptrI7SettingEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE @ 013fb830 from 00cce200
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<ReadValuesOperation> @ 013fb840 from 00cce208
 *   UNCONDITIONAL_CALL JniHelper::convertVectorToArr @ 013faa80 from 00cce21e
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00cce226
 *   UNCONDITIONAL_CALL FUN_00cc67b0 @ 00cc67b0 from 00cce22c
 *   READ Stack[-0x1c] from 00cce230
 *   READ 00cce378 from 00cce232
 *   READ 014da87c from 00cce236
 *   READ 015a7014 from 00cce238
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cce248
 */

/* Ghidra function: Java_com_prizmos_carista_library_operation_ReadValuesOperation_getSettingValue @ 00cce1dc */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b004465c480d467844006800680790204611462df312e3
 * 00cce1dc: push {r4,r5,r6,r7,lr}
 * 00cce1de: add r7,sp,#0xc
 * 00cce1e0: push.w r8
 * 00cce1e4: sub sp,#0x20
 * 00cce1e6: mov r4,r0
 * 00cce1e8: ldr r0,[0x00cce35c]
 * 00cce1ea: mov r5,r1
 * 00cce1ec: add r0,pc
 * 00cce1ee: ldr r0,[r0,#0x0]
 * 00cce1f0: ldr r0,[r0,#0x0]
 * 00cce1f2: str r0,[sp,#0x1c]
 * 00cce1f4: mov r0,r4
 * 00cce1f6: mov r1,r2
 * 00cce1f8: blx 0x013fb820
 * 00cce1fc: adds r1,r0,#0x4
 * 00cce1fe: add r0,sp,#0x4
 * 00cce200: blx 0x013fb830
 * 00cce204: mov r0,r4
 * 00cce206: mov r1,r5
 * 00cce208: blx 0x013fb840
 * 00cce20c: mov r1,r0
 * 00cce20e: ldr r0,[r1,#0x0]
 * 00cce210: ldr.w r3,[r0,#0x8c]
 * 00cce214: add r0,sp,#0x10
 */


void Java_com_prizmos_carista_library_operation_ReadValuesOperation_getSettingValue
               (_JNIEnv *param_1,_jobject *param_2,_jobject *param_3)

{
  Setting *pSVar1;
  ReadValuesOperation *pRVar2;
  vector *extraout_r2;
  undefined1 auStack_34 [12];
  _JNIEnv a_Stack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = JniHelper::getNativePointer<Setting>(param_1,param_3);
  _ZNSt6__ndk110shared_ptrI7SettingEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
            (auStack_34,pSVar1 + 4);
  pRVar2 = JniHelper::getNativePointer<ReadValuesOperation>(param_1,param_2);
  (**(code **)(*(int *)pRVar2 + 0x8c))(a_Stack_28,pRVar2,auStack_34);
  JniHelper::convertVectorToArr((JniHelper *)param_1,a_Stack_28,extraout_r2);
  FUN_00cb7f50(a_Stack_28);
  FUN_00cc67b0(auStack_34);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


