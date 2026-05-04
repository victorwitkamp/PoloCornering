/* Java_com_prizmos_carista_library_operation_ReadValuesOperation_getConnectedChassisId @ 00cce6b8 */


void Java_com_prizmos_carista_library_operation_ReadValuesOperation_getConnectedChassisId
               (_JNIEnv *param_1,_jobject *param_2)

{
  int local_34 [3];
  JniLocalRef<_jstring*> aJStack_28 [8];
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  JniHelper::getNativePointer<ReadValuesOperation>(param_1,param_2);
  ReadValuesOperation::getConnectedChassisId();
  if (local_34[0] != 0) {
    JniHelper::newJString((char *)aJStack_28,0xab26f7,(basic_string *)0x9e4);
    local_20 = 0;
    JniLocalRef<_jstring*>::~JniLocalRef(aJStack_28);
  }
  FUN_00cbba38(local_34);
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_1c);
}


