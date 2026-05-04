/* Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c */


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


