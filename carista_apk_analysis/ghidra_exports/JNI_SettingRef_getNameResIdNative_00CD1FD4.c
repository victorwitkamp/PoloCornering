/*
 * JNI_SettingRef_getNameResIdNative
 * ELF symbol address: 0x00CC1FD4
 * Ghidra address: 0x00CD1FD4 (ELF + 0x10000 image delta)
 * ELF symbol size: 372 bytes
 * Symbol: Java_com_prizmos_carista_library_model_SettingRef_getNameResIdNative
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_model_SettingRef_getNameResIdNative @ 00cd1fd4
 * Signature: undefined Java_com_prizmos_carista_library_model_SettingRef_getNameResIdNative(void)
 * Return type: undefined
 * Function body: [[00cd1fd4, 00cd202d]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cd2124 from 00cd1fe0
 *   READ 014da87c from 00cd1fe4
 *   READ 015a7014 from 00cd1fe6
 *   WRITE Stack[-0x1c] from 00cd1fe8
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Setting> @ 013fb820 from 00cd1fec
 *   READ 00cd2128 from 00cd1ffa
 *   PARAM 00ab26f7 from 00cd2000
 *   UNCONDITIONAL_CALL JniHelper::newJString @ 013fad50 from 00cd2002
 *   READ Stack[-0x20] from 00cd2008
 *   WRITE Stack[-0x20] from 00cd200a
 *   UNCONDITIONAL_CALL JniLocalRef<_jstring*>::~JniLocalRef @ 013fa570 from 00cd200e
 *   READ Stack[-0x1c] from 00cd2012
 *   READ 00cd2144 from 00cd2014
 *   READ 014da87c from 00cd2018
 *   READ 015a7014 from 00cd201a
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cd202a
 */

/* Ghidra function: Java_com_prizmos_carista_library_model_SettingRef_getNameResIdNative @ 00cd1fd4 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b0044650487844006800680790204629f318e401688968
 * 00cd1fd4: push {r4,r5,r6,r7,lr}
 * 00cd1fd6: add r7,sp,#0xc
 * 00cd1fd8: push.w r8
 * 00cd1fdc: sub sp,#0x20
 * 00cd1fde: mov r4,r0
 * 00cd1fe0: ldr r0,[0x00cd2124]
 * 00cd1fe2: add r0,pc
 * 00cd1fe4: ldr r0,[r0,#0x0]
 * 00cd1fe6: ldr r0,[r0,#0x0]
 * 00cd1fe8: str r0,[sp,#0x1c]
 * 00cd1fea: mov r0,r4
 * 00cd1fec: blx 0x013fb820
 * 00cd1ff0: ldr r1,[r0,#0x0]
 * 00cd1ff2: ldr r1,[r1,#0x8]
 * 00cd1ff4: blx r1
 * 00cd1ff6: mov r3,r0
 * 00cd1ff8: add r0,sp,#0x10
 * 00cd1ffa: ldr r1,[0x00cd2128]
 * 00cd1ffc: movw r2,#0xb6f
 * 00cd2000: add r1,pc
 * 00cd2002: blx 0x013fad50
 * 00cd2006: movs r0,#0x0
 * 00cd2008: ldr r4,[sp,#0x18]
 * 00cd200a: str r0,[sp,#0x18]
 */


void Java_com_prizmos_carista_library_model_SettingRef_getNameResIdNative
               (_JNIEnv *param_1,_jobject *param_2)

{
  Setting *pSVar1;
  JniLocalRef<_jstring*> aJStack_28 [8];
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = JniHelper::getNativePointer<Setting>(param_1,param_2);
  (**(code **)(*(int *)pSVar1 + 8))();
  JniHelper::newJString((char *)aJStack_28,0xab26f7,(char *)0xb6f);
  local_20 = 0;
  JniLocalRef<_jstring*>::~JniLocalRef(aJStack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


