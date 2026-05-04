/*
 * JNI_SettingCategory_valuesNative
 * ELF symbol address: 0x00CC1254
 * Ghidra address: 0x00CD1254 (ELF + 0x10000 image delta)
 * ELF symbol size: 568 bytes
 * Symbol: Java_com_prizmos_carista_library_model_SettingCategory_valuesNative
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_model_SettingCategory_valuesNative @ 00cd1254
 * Signature: undefined Java_com_prizmos_carista_library_model_SettingCategory_valuesNative(void)
 * Return type: undefined
 * Function body: [[00cd1254, 00cd132f] [00cd13fe, 00cd1419]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00cd1450 from 00cd1260
 *   READ 014da87c from 00cd1264
 *   READ 015a7014 from 00cd1266
 *   WRITE Stack[-0x28] from 00cd1268
 *   UNCONDITIONAL_CALL SettingCategory::values @ 013fbb40 from 00cd126a
 *   READ 00cd1454 from 00cd1276
 *   PARAM 00a548d9 from 00cd127a
 *   WRITE Stack[-0x44] from 00cd127e
 *   READ 00cd1458 from 00cd1280
 *   PARAM 00ab26f7 from 00cd1286
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00cd1288
 *   READ 00cd145c from 00cd1294
 *   READ 00cd1460 from 00cd1298
 *   READ Stack[-0x44] from 00cd129a
 *   PARAM 00ab25eb from 00cd129c
 *   PARAM 00a5478a from 00cd129e
 *   WRITE Stack[-0x4c] from 00cd12a2
 *   READ 00cd1464 from 00cd12a4
 *   PARAM 00ab26f7 from 00cd12aa
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00cd12ac
 *   READ Stack[-0x44] from 00cd12bc
 *   WRITE Stack[-0x48] from 00cd12c8
 *   READ 00cd1468 from 00cd12ca
 *   PARAM 00ab26f7 from 00cd12d0
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00cd12d2
 *   READ 00cd146c from 00cd12dc
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_model_SettingCategory_valuesNative @ 00cd1254 from 00cd12e2
 *   UNCONDITIONAL_CALL JniHelper::getAddress @ 013fa800 from 00cd12ea
 *   WRITE Stack[-0x58] from 00cd12ee
 *   READ Stack[-0x44] from 00cd12f4
 *   READ Stack[-0x4c] from 00cd12f6
 *   UNCONDITIONAL_CALL _JNIEnv::NewObject @ 013fa540 from 00cd12f8
 *   PARAM 00ab26f7 from 00cd12fe
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00cd1304
 *   READ Stack[-0x48] from 00cd1312
 *   PARAM 00ab26f7 from 00cd131c
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00cd1324
 *   UNCONDITIONAL_JUMP Java_com_prizmos_carista_library_model_SettingCategory_valuesNative @ 00cd1254 from 00cd132e
 *   READ Stack[-0x28] from 00cd13fe
 *   READ 00cd1488 from 00cd1400
 *   READ 014da87c from 00cd1404
 *   READ 015a7014 from 00cd1406
 *   READ Stack[-0x48] from 00cd140c
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cd1416
 */

/* Ghidra function: Java_com_prizmos_carista_library_model_SettingCategory_valuesNative @ 00cd1254 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000f8db081467b487844006800680c902af36ae40446d9f80000
 * 00cd1254: push {r4,r5,r6,r7,lr}
 * 00cd1256: add r7,sp,#0xc
 * 00cd1258: push {r8,r9,r10,r11}
 * 00cd125c: sub sp,#0x34
 * 00cd125e: mov r9,r0
 * 00cd1260: ldr r0,[0x00cd1450]
 * 00cd1262: add r0,pc
 * 00cd1264: ldr r0,[r0,#0x0]
 * 00cd1266: ldr r0,[r0,#0x0]
 * 00cd1268: str r0,[sp,#0x30]
 * 00cd126a: blx 0x013fbb40
 * 00cd126e: mov r4,r0
 * 00cd1270: ldr.w r0,[r9,#0x0]
 * 00cd1274: ldr r2,[r0,#0x18]
 * 00cd1276: ldr r1,[0x00cd1454]
 * 00cd1278: mov r0,r9
 * 00cd127a: add r1,pc
 * 00cd127c: blx r2
 * 00cd127e: str r0,[sp,#0x14]
 * 00cd1280: ldr r0,[0x00cd1458]
 * 00cd1282: movw r1,#0xb15
 * 00cd1286: add r0,pc
 * 00cd1288: blx 0x013fa3c0
 * 00cd128c: ldr.w r0,[r9,#0x0]
 */


void Java_com_prizmos_carista_library_model_SettingCategory_valuesNative(_jclass *param_1)

{
  int iVar1;
  int *piVar2;
  _jmethodID *p_Var3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  
  iVar1 = __stack_chk_guard;
  piVar2 = (int *)SettingCategory::values();
  p_Var3 = (_jmethodID *)
           (**(code **)(*(int *)param_1 + 0x18))
                     (param_1,"com/prizmos/carista/library/model/SettingCategory");
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0xb15);
  uVar4 = (**(code **)(*(int *)param_1 + 0x84))(param_1,p_Var3,"<init>",&DAT_00a5478a);
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0xb17);
  uVar5 = (**(code **)(*(int *)param_1 + 0x2b0))(param_1,piVar2[1] - *piVar2 >> 2,p_Var3,0);
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0xb1a);
  puVar8 = (undefined4 *)piVar2[1];
  iVar7 = 0;
  for (puVar9 = (undefined4 *)*piVar2; puVar9 != puVar8; puVar9 = puVar9 + 1) {
    uVar10 = JniHelper::getAddress((void *)*puVar9);
    uVar6 = _JNIEnv::NewObject(param_1,p_Var3,uVar4);
    JniHelper::catchAndRethrowException
              ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0xb20);
    (**(code **)(*(int *)param_1 + 0x2b8))(param_1,uVar5,iVar7,uVar6,uVar10);
    JniHelper::catchAndRethrowException
              ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0xb22);
    iVar7 = iVar7 + 1;
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}


