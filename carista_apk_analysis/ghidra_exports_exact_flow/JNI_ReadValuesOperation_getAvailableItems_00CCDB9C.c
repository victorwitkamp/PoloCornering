/*
 * JNI_ReadValuesOperation_getAvailableItems
 * ELF symbol address: 0x00CBDB9C
 * Ghidra address: 0x00CCDB9C (ELF + 0x10000 image delta)
 * ELF symbol size: 1164 bytes
 * Symbol: Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems
 * Program: libCarista.so
 * Resolved function: Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c
 * Signature: undefined Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems(void)
 * Return type: undefined
 * Function body: [[00ccdb9c, 00ccde3d]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 * Direct callees/references:
 *   READ 00ccdfc0 from 00ccdba6
 *   READ 014da87c from 00ccdbac
 *   READ 015a7014 from 00ccdbae
 *   WRITE Stack[-0x28] from 00ccdbb0
 *   WRITE Stack[-0x90] from 00ccdbb2
 *   UNCONDITIONAL_CALL JniHelper::getNativePointer<ReadValuesOperation> @ 013fb840 from 00ccdbb4
 *   UNCONDITIONAL_CALL FUN_00cce028 @ 00cce028 from 00ccdbc4
 *   READ Stack[-0x90] from 00ccdbc8
 *   READ 00ccdf80 from 00ccdbce
 *   PARAM 00804fd0 from 00ccdbd0
 *   UNCONDITIONAL_CALL JniLocalRef<_jclass*>::JniLocalRef @ 013fa3b0 from 00ccdbd8
 *   READ 00ccdf84 from 00ccdbdc
 *   PARAM 00ab26f7 from 00ccdbe2
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdbe4
 *   READ Stack[-0x90] from 00ccdbe8
 *   READ Stack[-0x58] from 00ccdbf0
 *   READ 00ccdf88 from 00ccdbf2
 *   READ 00ccdf8c from 00ccdbf4
 *   PARAM 00ab25eb from 00ccdbf6
 *   PARAM 00747fa0 from 00ccdbf8
 *   READ 00ccdf90 from 00ccdbfe
 *   PARAM 00ab26f7 from 00ccdc04
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdc06
 *   READ Stack[-0x58] from 00ccdc0a
 *   READ Stack[-0x90] from 00ccdc0c
 *   UNCONDITIONAL_CALL _JNIEnv::NewObject @ 013fa540 from 00ccdc10
 *   WRITE Stack[-0x9c] from 00ccdc14
 *   READ 00ccdfc4 from 00ccdc16
 *   PARAM 00ab26f7 from 00ccdc1c
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdc1e
 *   READ Stack[-0x90] from 00ccdc22
 *   READ Stack[-0x58] from 00ccdc2a
 *   READ 00ccdfc8 from 00ccdc2c
 *   READ 00ccdfcc from 00ccdc2e
 *   PARAM 009e6e98 from 00ccdc30
 *   PARAM 00bebd6d from 00ccdc32
 *   WRITE Stack[-0xb0] from 00ccdc36
 *   READ 00ccdfd0 from 00ccdc38
 *   PARAM 00ab26f7 from 00ccdc3e
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdc40
 *   READ Stack[-0x90] from 00ccdc44
 *   READ 00ccdfd4 from 00ccdc4a
 *   PARAM 00a548d9 from 00ccdc4c
 *   UNCONDITIONAL_CALL JniLocalRef<_jclass*>::JniLocalRef @ 013fa3b0 from 00ccdc54
 *   READ 00ccdfd8 from 00ccdc58
 *   PARAM 00ab26f7 from 00ccdc5e
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdc60
 *   READ Stack[-0x90] from 00ccdc64
 *   READ Stack[-0x64] from 00ccdc6c
 *   READ 00ccdfdc from 00ccdc6e
 *   READ 00ccdfe0 from 00ccdc70
 *   PARAM 00ab25eb from 00ccdc72
 *   PARAM 00a5478a from 00ccdc74
 *   WRITE Stack[-0xac] from 00ccdc78
 *   READ 00ccdfe4 from 00ccdc7a
 *   PARAM 00ab26f7 from 00ccdc80
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdc82
 *   READ 00ccdfe8 from 00ccdc86
 *   DATA 00747ff6 from 00ccdc8e
 *   WRITE Stack[-0xa0] from 00ccdc8e
 *   READ 00ccdfec from 00ccdc92
 *   DATA 00ab26f7 from 00ccdc96
 *   WRITE Stack[-0x94] from 00ccdc96
 *   READ 00ccdff0 from 00ccdc98
 *   DATA 00ab25eb from 00ccdc9c
 *   WRITE Stack[-0xa4] from 00ccdc9c
 *   READ 00ccdff4 from 00ccdc9e
 *   DATA 00a5478a from 00ccdca2
 *   WRITE Stack[-0xa8] from 00ccdca2
 *   DATA Stack[-0x84] from 00ccdca4
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c from 00ccdca8
 *   READ Stack[-0x90] from 00ccdcac
 *   PARAM 00747ff6 from 00ccdcb2
 *   READ Stack[-0xa0] from 00ccdcb2
 *   UNCONDITIONAL_CALL JniLocalRef<_jclass*>::JniLocalRef @ 013fa3b0 from 00ccdcba
 *   PARAM 00ab26f7 from 00ccdcbe
 *   READ Stack[-0x94] from 00ccdcbe
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdcc4
 *   READ Stack[-0x90] from 00ccdcc8
 *   READ Stack[-0x2c] from 00ccdcd0
 *   PARAM 00ab25eb from 00ccdcd2
 *   PARAM 00a5478a from 00ccdcd2
 *   READ Stack[-0xa8] from 00ccdcd2
 *   PARAM 00ab26f7 from 00ccdcda
 *   READ Stack[-0x94] from 00ccdcda
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdce0
 *   READ Stack[-0x90] from 00ccdce4
 *   READ Stack[-0x2c] from 00ccdce6
 *   PARAM 00ab26f7 from 00ccdcfc
 *   READ Stack[-0x94] from 00ccdcfc
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdd02
 *   WRITE Stack[-0x98] from 00ccdd0a
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c from 00ccdd10
 *   WRITE Stack[-0x3c] from 00ccdd16
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c from 00ccdd1a
 *   CONDITIONAL_JUMP Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c from 00ccdd2a
 *   UNCONDITIONAL_CALL JniHelper::getAddress @ 013fa800 from 00ccdd2c
 *   READ 00ccdff8 from 00ccdd32
 *   PARAM 00ab26f7 from 00ccdd3a
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdd3c
 *   UNCONDITIONAL_CALL FUN_013facc0 @ 013facc0 from 00ccdd42
 *   READ Stack[-0x2c] from 00ccdd46
 *   READ Stack[-0x90] from 00ccdd48
 *   WRITE Stack[-0xb8] from 00ccdd4c
 *   UNCONDITIONAL_CALL _JNIEnv::NewObject @ 013fa540 from 00ccdd50
 *   UNCONDITIONAL_CALL JniLocalRef<_jobject*>::JniLocalRef @ 013fa520 from 00ccdd5a
 *   UNCONDITIONAL_CALL _ZN11JniLocalRefIP8_jobjectEaSEOS2_ @ 013fa550 from 00ccdd62
 *   UNCONDITIONAL_CALL JniLocalRef<_jobject*>::~JniLocalRef @ 013fa560 from 00ccdd68
 *   READ 00ccdffc from 00ccdd6c
 *   PARAM 00ab26f7 from 00ccdd72
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdd74
 *   READ Stack[-0x90] from 00ccdd78
 *   READ Stack[-0x40] from 00ccdd7a
 *   READ 00cce000 from 00ccdd88
 *   PARAM 00ab26f7 from 00ccdd8e
 *   UNCONDITIONAL_CALL JniHelper::catchAndRethrowException @ 013fa3c0 from 00ccdd90
 *   UNCONDITIONAL_CALL JniLocalRef<_jobject*>::~JniLocalRef @ 013fa560 from 00ccdd96
 *   UNCONDITIONAL_CALL FUN_00cc67b0 @ 00cc67b0 from 00ccdd9c
 *   UNCONDITIONAL_JUMP Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c from 00ccdda6
 *   UNCONDITIONAL_CALL JniLocalRef<_jclass*>::~JniLocalRef @ 013fa3f0 from 00ccddac
 */

/* Ghidra function: Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000fa5b0dff818247a441268126824920a902df344e60168c96f
 * 00ccdb9c: push {r4,r5,r6,r7,lr}
 * 00ccdb9e: add r7,sp,#0xc
 * 00ccdba0: push {r8,r9,r10,r11}
 * 00ccdba4: sub sp,#0x94
 * 00ccdba6: ldr.w r2,[0x00ccdfc0]
 * 00ccdbaa: add r2,pc
 * 00ccdbac: ldr r2,[r2,#0x0]
 * 00ccdbae: ldr r2,[r2,#0x0]
 * 00ccdbb0: str r2,[sp,#0x90]
 * 00ccdbb2: str r0,[sp,#0x28]
 * 00ccdbb4: blx 0x013fb840
 * 00ccdbb8: ldr r1,[r0,#0x0]
 * 00ccdbba: ldr r1,[r1,#0x7c]
 * 00ccdbbc: blx r1
 * 00ccdbbe: mov r1,r0
 * 00ccdbc0: add r5,sp,#0x2c
 * 00ccdbc2: mov r0,r5
 * 00ccdbc4: bl 0x00cce028
 * 00ccdbc8: ldr r0,[sp,#0x28]
 * 00ccdbca: ldr r1,[r0,#0x0]
 * 00ccdbcc: ldr r2,[r1,#0x18]
 * 00ccdbce: ldr r1,[0x00ccdf80]
 * 00ccdbd0: add r1,pc
 * 00ccdbd2: blx r2
 */


void Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems
               (_JNIEnv *param_1,_jobject *param_2)

{
  bool bVar1;
  _jmethodID *p_Var2;
  ReadValuesOperation *pRVar3;
  undefined4 uVar4;
  _jmethodID *p_Var5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 extraout_r1;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined1 auStack_8c [8];
  int local_84 [3];
  _jobject a_Stack_78 [12];
  _jclass a_Stack_6c [8];
  _jmethodID *local_64;
  _jclass a_Stack_60 [8];
  _jmethodID *local_58;
  _jobject a_Stack_54 [12];
  JniLocalRef<_jobject*> aJStack_48 [8];
  undefined4 local_40;
  void *local_3c;
  int iStack_38;
  _jclass a_Stack_34 [8];
  _jmethodID *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pRVar3 = JniHelper::getNativePointer<ReadValuesOperation>(param_1,param_2);
  uVar4 = (**(code **)(*(int *)pRVar3 + 0x7c))();
  FUN_00cce028(auStack_8c,uVar4);
  (**(code **)(*(int *)param_1 + 0x18))(param_1,"java/util/HashMap");
  JniLocalRef<_jclass*>::JniLocalRef(a_Stack_60);
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0x219);
  uVar4 = (**(code **)(*(int *)param_1 + 0x84))(param_1,local_58,"<init>",&DAT_00747fa0);
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0x21b);
  p_Var5 = (_jmethodID *)_JNIEnv::NewObject((_jclass *)param_1,local_58,uVar4);
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0x21d);
  uVar4 = (**(code **)(*(int *)param_1 + 0x84))
                    (param_1,local_58,&DAT_009e6e98,
                     "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0x222);
  (**(code **)(*(int *)param_1 + 0x18))(param_1,"com/prizmos/carista/library/model/SettingCategory")
  ;
  JniLocalRef<_jclass*>::JniLocalRef(a_Stack_6c);
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0x224);
  uVar6 = (**(code **)(*(int *)param_1 + 0x84))(param_1,local_64,"<init>",&DAT_00a5478a);
  JniHelper::catchAndRethrowException
            ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
             0x226);
  piVar10 = local_84;
  while( true ) {
    piVar10 = (int *)*piVar10;
    if (piVar10 == (int *)0x0) break;
    (**(code **)(*(int *)param_1 + 0x18))(param_1,"com/prizmos/carista/library/model/SettingRef");
    JniLocalRef<_jclass*>::JniLocalRef(a_Stack_34);
    JniHelper::catchAndRethrowException
              ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0x1f8);
    uVar7 = (**(code **)(*(int *)param_1 + 0x84))(param_1,local_2c,"<init>",&DAT_00a5478a);
    JniHelper::catchAndRethrowException
              ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0x1fa);
    uVar8 = (**(code **)(*(int *)param_1 + 0x2b0))(param_1,piVar10[4] - piVar10[3] >> 3,local_2c,0);
    JniHelper::catchAndRethrowException
              ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0x1fe);
    puVar12 = (undefined4 *)piVar10[4];
    iVar11 = 0;
    for (puVar13 = (undefined4 *)piVar10[3]; puVar13 != puVar12; puVar13 = puVar13 + 2) {
      local_3c = (void *)*puVar13;
      iStack_38 = puVar13[1];
      if (iStack_38 != 0) {
        piVar9 = (int *)(iStack_38 + 4);
        do {
          ExclusiveAccess(piVar9);
          bVar1 = (bool)hasExclusiveAccess(piVar9);
        } while (!bVar1);
        *piVar9 = *piVar9 + 1;
      }
      JniHelper::getAddress(local_3c);
      JniHelper::catchAndRethrowException
                ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp"
                 ,0x203);
      FUN_013facc0(aJStack_48);
      _JNIEnv::NewObject((_jclass *)param_1,local_2c,uVar7);
      JniLocalRef<_jobject*>::JniLocalRef(a_Stack_54);
      _ZN11JniLocalRefIP8_jobjectEaSEOS2_(aJStack_48,a_Stack_54);
      JniLocalRef<_jobject*>::~JniLocalRef((JniLocalRef<_jobject*> *)a_Stack_54);
      JniHelper::catchAndRethrowException
                ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp"
                 ,0x209);
      (**(code **)(*(int *)param_1 + 0x2b8))(param_1,uVar8,iVar11,local_40);
      JniHelper::catchAndRethrowException
                ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp"
                 ,0x20c);
      JniLocalRef<_jobject*>::~JniLocalRef(aJStack_48);
      FUN_00cc67b0(&local_3c);
      iVar11 = iVar11 + 1;
    }
    JniLocalRef<_jclass*>::~JniLocalRef((JniLocalRef<_jclass*> *)a_Stack_34);
    p_Var2 = local_64;
    JniHelper::getAddress((void *)piVar10[2]);
    uVar7 = extraout_r1;
    _JNIEnv::NewObject((_jclass *)param_1,p_Var2,uVar6);
    JniLocalRef<_jobject*>::JniLocalRef((_jobject *)a_Stack_34);
    JniHelper::catchAndRethrowException
              ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0x22f);
    _JNIEnv::CallObjectMethod((_jobject *)param_1,p_Var5,uVar4,local_2c,uVar8,uVar7);
    JniLocalRef<_jobject*>::JniLocalRef(a_Stack_78);
    JniLocalRef<_jobject*>::~JniLocalRef((JniLocalRef<_jobject*> *)a_Stack_78);
    JniHelper::catchAndRethrowException
              ("/Users/erik/Documents/readonly/carista-release/Carista/jni/carista_library_jni.cpp",
               0x232);
    JniLocalRef<_jobject*>::~JniLocalRef((JniLocalRef<_jobject*> *)a_Stack_34);
  }
  JniLocalRef<_jclass*>::~JniLocalRef((JniLocalRef<_jclass*> *)a_Stack_6c);
  JniLocalRef<_jclass*>::~JniLocalRef((JniLocalRef<_jclass*> *)a_Stack_60);
  FUN_00cd944c(auStack_8c);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


