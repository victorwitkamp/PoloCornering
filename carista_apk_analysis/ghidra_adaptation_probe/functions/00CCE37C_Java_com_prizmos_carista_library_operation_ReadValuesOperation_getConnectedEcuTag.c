/* Java_com_prizmos_carista_library_operation_ReadValuesOperation_getConnectedEcuTag @ 00cce37c */


void Java_com_prizmos_carista_library_operation_ReadValuesOperation_getConnectedEcuTag
               (_JNIEnv *param_1,_jobject *param_2,_jobject *param_3)

{
  Setting *pSVar1;
  ReadValuesOperation *pRVar2;
  undefined1 auStack_3c [12];
  JniLocalRef<_jstring*> aJStack_30 [8];
  undefined4 local_28;
  int local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = JniHelper::getNativePointer<Setting>(param_1,param_3);
  _ZNSt6__ndk110shared_ptrI7SettingEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
            (auStack_3c,pSVar1 + 4);
  pRVar2 = JniHelper::getNativePointer<ReadValuesOperation>(param_1,param_2);
  (**(code **)(*(int *)pRVar2 + 0x90))(local_24,pRVar2,auStack_3c);
  if (local_24[0] != 0) {
    JniHelper::newJString((char *)aJStack_30,0xab26f7,(basic_string *)0x9ce);
    local_28 = 0;
    JniLocalRef<_jstring*>::~JniLocalRef(aJStack_30);
  }
  FUN_00cbba38(local_24);
  FUN_00cc67b0(auStack_3c);
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_1c);
}


