/*
 * JNI_SettingRef_getInterpretation
 * ELF symbol address: 0x00CC25B0
 * Ghidra address: 0x00CD25B0 (ELF + 0x10000 image delta)
 * ELF symbol size: 408 bytes
 * Symbol: Java_com_prizmos_carista_library_model_SettingRef_getInterpretation
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_model_SettingRef_getInterpretation @ 00cd25b0
 * Signature: undefined Java_com_prizmos_carista_library_model_SettingRef_getInterpretation(void)
 * Return type: undefined
 * Function body: [[00cd25b0, 00cd2607]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cd2728 from 00cd25bc
 *   READ 014da87c from 00cd25c0
 *   READ 015a7014 from 00cd25c2
 *   WRITE Stack[-0x1c] from 00cd25c4
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Setting> @ 013fb820 from 00cd25c8
 *   WRITE Stack[-0x34] from 00cd25d0
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_model_SettingRef_getInterpretation @ 00cd25b0 from 00cd25d4
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_model_SettingRef_getInterpretation @ 00cd25b0 from 00cd25e4
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_model_SettingRef_getInterpretation @ 00cd25b0 from 00cd25e6
 *   UNCONDITIONAL_CALL JniHelper::toJava @ 013fada0 from 00cd25ee
 *   READ Stack[-0x20] from 00cd25f4
 *   WRITE Stack[-0x20] from 00cd25f6
 *   UNCONDITIONAL_CALL JniLocalRef<_jobject*>::~JniLocalRef @ 013fa560 from 00cd25fa
 *   UNCONDITIONAL_JUMP Java_com_prizmos_carista_library_model_SettingRef_getInterpretation @ 00cd25b0 from 00cd25fe
 *   UNCONDITIONAL_CALL FUN_00cd2748 @ 00cd2748 from 00cd2604
 */

/* Ghidra function: Java_com_prizmos_carista_library_model_SettingRef_getInterpretation @ 00cd25b0 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b004465a487844006800680790204629f32ae1d0e90b01
 * 00cd25b0: push {r4,r5,r6,r7,lr}
 * 00cd25b2: add r7,sp,#0xc
 * 00cd25b4: push.w r8
 * 00cd25b8: sub sp,#0x20
 * 00cd25ba: mov r4,r0
 * 00cd25bc: ldr r0,[0x00cd2728]
 * 00cd25be: add r0,pc
 * 00cd25c0: ldr r0,[r0,#0x0]
 * 00cd25c2: ldr r0,[r0,#0x0]
 * 00cd25c4: str r0,[sp,#0x1c]
 * 00cd25c6: mov r0,r4
 * 00cd25c8: blx 0x013fb820
 * 00cd25cc: ldrd r0,r1,[r0,#0x2c]
 * 00cd25d0: strd r0,r1,[sp,#0x4]
 * 00cd25d4: cbz r1,0x00cd25e6
 * 00cd25d6: adds r1,#0x4
 * 00cd25d8: ldrex r2,[r1,#0x0]
 * 00cd25dc: adds r2,#0x1
 * 00cd25de: strex r3,r2,[r1,#0x0]
 * 00cd25e2: cmp r3,#0x0
 * 00cd25e4: bne 0x00cd25d8
 * 00cd25e6: cbz r0,0x00cd2600
 * 00cd25e8: add r0,sp,#0x10
 * 00cd25ea: add r2,sp,#0x4
 */


void Java_com_prizmos_carista_library_model_SettingRef_getInterpretation
               (_JNIEnv *param_1,_jobject *param_2)

{
  bool bVar1;
  Setting *pSVar2;
  int *piVar3;
  int local_34;
  int iStack_30;
  JniHelper aJStack_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar2 = JniHelper::getNativePointer<Setting>(param_1,param_2);
  local_34 = *(int *)(pSVar2 + 0x2c);
  iStack_30 = *(int *)(pSVar2 + 0x30);
  if (iStack_30 != 0) {
    piVar3 = (int *)(iStack_30 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  if (local_34 != 0) {
    JniHelper::toJava(aJStack_28,param_1,(shared_ptr *)&local_34);
    local_20 = 0;
    JniLocalRef<_jobject*>::~JniLocalRef((JniLocalRef<_jobject*> *)aJStack_28);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_34);
}


