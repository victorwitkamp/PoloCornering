/*
 * JNI_SettingRef_getEcu
 * ELF symbol address: 0x00CC1E64
 * Ghidra address: 0x00CD1E64 (ELF + 0x10000 image delta)
 * ELF symbol size: 368 bytes
 * Symbol: Java_com_prizmos_carista_library_model_SettingRef_getEcu
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_model_SettingRef_getEcu @ 00cd1e64
 * Signature: undefined Java_com_prizmos_carista_library_model_SettingRef_getEcu(void)
 * Return type: undefined
 * Function body: [[00cd1e64, 00cd1ebb]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cd1fb0 from 00cd1e70
 *   READ 014da87c from 00cd1e74
 *   READ 015a7014 from 00cd1e76
 *   WRITE Stack[-0x1c] from 00cd1e78
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Setting> @ 013fb820 from 00cd1e7c
 *   READ 00cd1fb4 from 00cd1e8a
 *   PARAM 0093fc38 from 00cd1e8e
 *   UNCONDITIONAL_CALL JniHelper::createJavaWrapper @ 013fad30 from 00cd1e90
 *   READ Stack[-0x20] from 00cd1e96
 *   WRITE Stack[-0x20] from 00cd1e98
 *   UNCONDITIONAL_CALL JniLocalRef<_jobject*>::~JniLocalRef @ 013fa560 from 00cd1e9c
 *   READ Stack[-0x1c] from 00cd1ea0
 *   READ 00cd1fd0 from 00cd1ea2
 *   READ 014da87c from 00cd1ea6
 *   READ 015a7014 from 00cd1ea8
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cd1eb8
 */

/* Ghidra function: Java_com_prizmos_carista_library_model_SettingRef_getEcu @ 00cd1e64 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b004464f487844006800680790204629f3d0e401684969
 * 00cd1e64: push {r4,r5,r6,r7,lr}
 * 00cd1e66: add r7,sp,#0xc
 * 00cd1e68: push.w r8
 * 00cd1e6c: sub sp,#0x20
 * 00cd1e6e: mov r4,r0
 * 00cd1e70: ldr r0,[0x00cd1fb0]
 * 00cd1e72: add r0,pc
 * 00cd1e74: ldr r0,[r0,#0x0]
 * 00cd1e76: ldr r0,[r0,#0x0]
 * 00cd1e78: str r0,[sp,#0x1c]
 * 00cd1e7a: mov r0,r4
 * 00cd1e7c: blx 0x013fb820
 * 00cd1e80: ldr r1,[r0,#0x0]
 * 00cd1e82: ldr r1,[r1,#0x14]
 * 00cd1e84: blx r1
 * 00cd1e86: mov r2,r0
 * 00cd1e88: add r0,sp,#0x10
 * 00cd1e8a: ldr r3,[0x00cd1fb4]
 * 00cd1e8c: mov r1,r4
 * 00cd1e8e: add r3,pc
 * 00cd1e90: blx 0x013fad30
 * 00cd1e94: movs r0,#0x0
 * 00cd1e96: ldr r4,[sp,#0x18]
 * 00cd1e98: str r0,[sp,#0x18]
 */


void Java_com_prizmos_carista_library_model_SettingRef_getEcu(_JNIEnv *param_1,_jobject *param_2)

{
  Setting *pSVar1;
  char *pcVar2;
  _JNIEnv a_Stack_28 [8];
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = JniHelper::getNativePointer<Setting>(param_1,param_2);
  pcVar2 = (char *)(**(code **)(*(int *)pSVar1 + 0x14))();
  JniHelper::createJavaWrapper(a_Stack_28,param_1,pcVar2);
  local_20 = 0;
  JniLocalRef<_jobject*>::~JniLocalRef((JniLocalRef<_jobject*> *)a_Stack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


