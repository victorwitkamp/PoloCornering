/*
 * JNI_ChangeSettingOperation_initNative
 * ELF symbol address: 0x00CB645C
 * Ghidra address: 0x00CC645C (ELF + 0x10000 image delta)
 * ELF symbol size: 520 bytes
 * Symbol: Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative @ 00cc645c
 * Signature: undefined Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative(void)
 * Return type: undefined
 * Function body: [[00cc645c, 00cc6511]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   WRITE Stack[-0x20] from 00cc6466
 *   READ 00cc663c from 00cc646a
 *   READ 014da87c from 00cc6472
 *   READ 015a7014 from 00cc6474
 *   WRITE Stack[-0x1c] from 00cc6476
 *   READ 00cc6640 from 00cc6478
 *   PARAM 00b7a9e9 from 00cc647a
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00cc647c
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<Setting> @ 013fb820 from 00cc6484
 *   UNCONDITIONAL_CALL _ZNSt6__ndk110shared_ptrI7SettingEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE @ 013fb830 from 00cc648c
 *   READ Stack[0x0] from 00cc6490
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<ReadValuesOperation> @ 013fb840 from 00cc6494
 *   UNCONDITIONAL_CALL ReadValuesOperation::shared_from_this @ 013fb850 from 00cc649e
 *   UNCONDITIONAL_CALL JniHelper::convertArrToVector @ 013faa30 from 00cc64a8
 *   WRITE Stack[-0x58] from 00cc64ac
 *   READ 00cc6644 from 00cc64b0
 *   PARAM 014f13e0 from 00cc64b6
 *   UNCONDITIONAL_CALL FUN_00cc674c @ 00cc674c from 00cc64b8
 *   READ Stack[-0x38] from 00cc64bc
 *   WRITE Stack[-0x30] from 00cc64c0
 *   WRITE Stack[-0x2c] from 00cc64c4
 *   WRITE Stack[-0x38] from 00cc64c6
 *   UNCONDITIONAL_CALL FUN_00cc678c @ 00cc678c from 00cc64cc
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00cc64d2
 *   UNCONDITIONAL_CALL JniOperations::put @ 013fb3f0 from 00cc64dc
 *   READ Stack[-0x30] from 00cc64e0
 *   UNCONDITIONAL_CALL FUN_00cbfa28 @ 00cbfa28 from 00cc64e4
 *   UNCONDITIONAL_CALL FUN_00cc679e @ 00cc679e from 00cc64ea
 *   UNCONDITIONAL_CALL FUN_00cc67b0 @ 00cc67b0 from 00cc64f0
 *   READ Stack[-0x1c] from 00cc64f6
 *   READ 00cc6660 from 00cc64f8
 *   READ 014da87c from 00cc64fc
 *   READ 015a7014 from 00cc64fe
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cc650e
 */

/* Ghidra function: Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative @ 00cc645c */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d90b00e930446744816460d467844006800680f9071487844
 * 00cc645c: push {r4,r5,r6,r7,lr}
 * 00cc645e: add r7,sp,#0xc
 * 00cc6460: push.w r8
 * 00cc6464: sub sp,#0x40
 * 00cc6466: str r3,[sp,#0x38]
 * 00cc6468: mov r4,r0
 * 00cc646a: ldr r0,[0x00cc663c]
 * 00cc646c: mov r6,r2
 * 00cc646e: mov r5,r1
 * 00cc6470: add r0,pc
 * 00cc6472: ldr r0,[r0,#0x0]
 * 00cc6474: ldr r0,[r0,#0x0]
 * 00cc6476: str r0,[sp,#0x3c]
 * 00cc6478: ldr r0,[0x00cc6640]
 * 00cc647a: add r0,pc
 * 00cc647c: blx 0x013fb5b0
 * 00cc6480: mov r0,r4
 * 00cc6482: mov r1,r6
 * 00cc6484: blx 0x013fb820
 * 00cc6488: adds r1,r0,#0x4
 * 00cc648a: add r0,sp,#0x8
 * 00cc648c: blx 0x013fb830
 * 00cc6490: ldr r1,[r7,#0x8]
 * 00cc6492: mov r0,r4
 */


void Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative
               (_JNIEnv *param_1,_jobject *param_2,_jobject *param_3,undefined4 param_4,
               _jobject *param_5)

{
  int iVar1;
  Setting *pSVar2;
  undefined1 auStack_50 [12];
  _JNIEnv a_Stack_44 [12];
  int local_38;
  undefined4 uStack_34;
  int local_30;
  undefined4 local_2c;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_20 = param_4;
  Log::d("Creating native ChangeSettingOperation");
  pSVar2 = JniHelper::getNativePointer<Setting>(param_1,param_3);
  _ZNSt6__ndk110shared_ptrI7SettingEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
            (auStack_50,pSVar2 + 4);
  JniHelper::getNativePointer<ReadValuesOperation>(param_1,param_5);
  ReadValuesOperation::shared_from_this();
  JniHelper::convertArrToVector(a_Stack_44,(_jbyteArray **)param_1);
  FUN_00cc674c(&local_38,&DAT_014f13e0,auStack_50,a_Stack_44,auStack_28);
  local_30 = local_38;
  local_2c = uStack_34;
  local_38 = 0;
  uStack_34 = 0;
  FUN_00cc678c(&local_38);
  FUN_00cb7f50(a_Stack_44);
  JniOperations::put(param_1,param_2,(shared_ptr *)&local_30);
  iVar1 = local_30;
  FUN_00cbfa28(&local_30);
  FUN_00cc679e(auStack_28);
  FUN_00cc67b0(auStack_50);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c,iVar1 >> 0x1f);
  }
  return;
}


