/*
 * JNI_SettingRef_getInstruction
 * ELF symbol address: 0x00CC2298
 * Ghidra address: 0x00CD2298 (ELF + 0x10000 image delta)
 * ELF symbol size: 396 bytes
 * Symbol: Java_com_prizmos_carista_library_model_SettingRef_getInstruction
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_model_SettingRef_getInstruction @ 00cd2298
 * Signature: undefined Java_com_prizmos_carista_library_model_SettingRef_getInstruction(void)
 * Return type: undefined
 * Function body: [[00cd2298, 00cd22fb]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cd2400 from 00cd22a4
 *   READ 014da87c from 00cd22a8
 *   READ 015a7014 from 00cd22aa
 *   WRITE Stack[-0x1c] from 00cd22ac
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Setting> @ 013fb820 from 00cd22b0
 *   READ 00cd2404 from 00cd22c0
 *   PARAM 00ab26f7 from 00cd22c8
 *   UNCONDITIONAL_CALL FUN_013fab20 @ 013fab20 from 00cd22ca
 *   READ Stack[-0x20] from 00cd22d0
 *   WRITE Stack[-0x20] from 00cd22d2
 *   UNCONDITIONAL_CALL JniLocalRef<_jstring*>::~JniLocalRef @ 013fa570 from 00cd22d6
 *   UNCONDITIONAL_CALL FUN_00cbba38 @ 00cbba38 from 00cd22dc
 *   READ Stack[-0x1c] from 00cd22e0
 *   READ 00cd2420 from 00cd22e2
 *   READ 014da87c from 00cd22e6
 *   READ 015a7014 from 00cd22e8
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cd22f8
 */

/* Ghidra function: Java_com_prizmos_carista_library_model_SettingRef_getInstruction @ 00cd2298 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b0044656487844006800680790204629f3b6e201460868
 * 00cd2298: push {r4,r5,r6,r7,lr}
 * 00cd229a: add r7,sp,#0xc
 * 00cd229c: push.w r8
 * 00cd22a0: sub sp,#0x20
 * 00cd22a2: mov r4,r0
 * 00cd22a4: ldr r0,[0x00cd2400]
 * 00cd22a6: add r0,pc
 * 00cd22a8: ldr r0,[r0,#0x0]
 * 00cd22aa: ldr r0,[r0,#0x0]
 * 00cd22ac: str r0,[sp,#0x1c]
 * 00cd22ae: mov r0,r4
 * 00cd22b0: blx 0x013fb820
 * 00cd22b4: mov r1,r0
 * 00cd22b6: ldr r0,[r1,#0x0]
 * 00cd22b8: ldr r2,[r0,#0x24]
 * 00cd22ba: add r0,sp,#0x4
 * 00cd22bc: blx r2
 * 00cd22be: add r0,sp,#0x10
 * 00cd22c0: ldr r1,[0x00cd2404]
 * 00cd22c2: add r3,sp,#0x4
 * 00cd22c4: movw r2,#0xb7f
 * 00cd22c8: add r1,pc
 * 00cd22ca: blx 0x013fab20
 * 00cd22ce: movs r0,#0x0
 */


void Java_com_prizmos_carista_library_model_SettingRef_getInstruction
               (_JNIEnv *param_1,_jobject *param_2)

{
  Setting *pSVar1;
  undefined1 auStack_34 [12];
  JniLocalRef<_jstring*> aJStack_28 [8];
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = JniHelper::getNativePointer<Setting>(param_1,param_2);
  (**(code **)(*(int *)pSVar1 + 0x24))(auStack_34);
  FUN_013fab20(aJStack_28,
               "/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0xb7f,auStack_34);
  local_20 = 0;
  JniLocalRef<_jstring*>::~JniLocalRef(aJStack_28);
  FUN_00cbba38(auStack_34);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


