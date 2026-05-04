/* Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative @ 00cc645c */


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


