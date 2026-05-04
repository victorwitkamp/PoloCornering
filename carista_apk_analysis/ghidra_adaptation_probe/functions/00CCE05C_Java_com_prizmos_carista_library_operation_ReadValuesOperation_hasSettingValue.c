/* Java_com_prizmos_carista_library_operation_ReadValuesOperation_hasSettingValue @ 00cce05c */


void Java_com_prizmos_carista_library_operation_ReadValuesOperation_hasSettingValue
               (_JNIEnv *param_1,_jobject *param_2,_jobject *param_3)

{
  Setting *pSVar1;
  ReadValuesOperation *pRVar2;
  undefined1 auStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = JniHelper::getNativePointer<Setting>(param_1,param_3);
  _ZNSt6__ndk110shared_ptrI7SettingEC2B8ne190000IS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERKNS_8weak_ptrIS5_EE
            (auStack_28,pSVar1 + 4);
  pRVar2 = JniHelper::getNativePointer<ReadValuesOperation>(param_1,param_2);
  (**(code **)(*(int *)pRVar2 + 0x88))(pRVar2,auStack_28);
  FUN_00cc67b0(auStack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


