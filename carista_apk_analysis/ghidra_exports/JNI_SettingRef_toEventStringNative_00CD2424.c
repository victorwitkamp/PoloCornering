/*
 * JNI_SettingRef_toEventStringNative
 * ELF symbol address: 0x00CC2424
 * Ghidra address: 0x00CD2424 (ELF + 0x10000 image delta)
 * ELF symbol size: 396 bytes
 * Symbol: Java_com_prizmos_carista_library_model_SettingRef_toEventStringNative
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_model_SettingRef_toEventStringNative @ 00cd2424
 * Signature: undefined Java_com_prizmos_carista_library_model_SettingRef_toEventStringNative(void)
 * Return type: undefined
 * Function body: [[00cd2424, 00cd2487]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cd258c from 00cd2430
 *   READ 014da87c from 00cd2434
 *   READ 015a7014 from 00cd2436
 *   WRITE Stack[-0x1c] from 00cd2438
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Setting> @ 013fb820 from 00cd243c
 *   READ 00cd2590 from 00cd244c
 *   PARAM 00ab26f7 from 00cd2454
 *   UNCONDITIONAL_CALL JniHelper::newJString @ 013fa4f0 from 00cd2456
 *   READ Stack[-0x2c] from 00cd245c
 *   WRITE Stack[-0x2c] from 00cd245e
 *   UNCONDITIONAL_CALL JniLocalRef<_jstring*>::~JniLocalRef @ 013fa570 from 00cd2462
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00cd2468
 *   READ Stack[-0x1c] from 00cd246c
 *   READ 00cd25ac from 00cd246e
 *   READ 014da87c from 00cd2472
 *   READ 015a7014 from 00cd2474
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cd2484
 */

/* Ghidra function: Java_com_prizmos_carista_library_model_SettingRef_toEventStringNative @ 00cd2424 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b0044656487844006800680790204629f3f0e101460868
 * 00cd2424: push {r4,r5,r6,r7,lr}
 * 00cd2426: add r7,sp,#0xc
 * 00cd2428: push.w r8
 * 00cd242c: sub sp,#0x20
 * 00cd242e: mov r4,r0
 * 00cd2430: ldr r0,[0x00cd258c]
 * 00cd2432: add r0,pc
 * 00cd2434: ldr r0,[r0,#0x0]
 * 00cd2436: ldr r0,[r0,#0x0]
 * 00cd2438: str r0,[sp,#0x1c]
 * 00cd243a: mov r0,r4
 * 00cd243c: blx 0x013fb820
 * 00cd2440: mov r1,r0
 * 00cd2442: ldr r0,[r1,#0x0]
 * 00cd2444: ldr r2,[r0,#0x18]
 * 00cd2446: add r0,sp,#0x10
 * 00cd2448: blx r2
 * 00cd244a: add r0,sp,#0x4
 * 00cd244c: ldr r1,[0x00cd2590]
 * 00cd244e: add r3,sp,#0x10
 * 00cd2450: movw r2,#0xb87
 * 00cd2454: add r1,pc
 * 00cd2456: blx 0x013fa4f0
 * 00cd245a: movs r0,#0x0
 */


void Java_com_prizmos_carista_library_model_SettingRef_toEventStringNative
               (_JNIEnv *param_1,_jobject *param_2)

{
  Setting *pSVar1;
  JniLocalRef<_jstring*> aJStack_34 [8];
  undefined4 local_2c;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = JniHelper::getNativePointer<Setting>(param_1,param_2);
  (**(code **)(*(int *)pSVar1 + 0x18))(abStack_28);
  JniHelper::newJString((char *)aJStack_34,0xab26f7,(basic_string *)0xb87);
  local_2c = 0;
  JniLocalRef<_jstring*>::~JniLocalRef(aJStack_34);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


