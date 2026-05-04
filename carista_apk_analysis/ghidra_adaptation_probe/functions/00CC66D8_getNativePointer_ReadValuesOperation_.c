/* JniHelper::getNativePointer<ReadValuesOperation> @ 00cc66d8 */


/* ReadValuesOperation* JniHelper::getNativePointer<ReadValuesOperation>(_JNIEnv*, _jobject*) */

ReadValuesOperation *
JniHelper::getNativePointer<ReadValuesOperation>(_JNIEnv *param_1,_jobject *param_2)

{
  undefined4 uVar1;
  int iVar2;
  ReadValuesOperation *pRVar3;
  
  uVar1 = (**(code **)(*(int *)param_1 + 0x7c))(param_1);
  uVar1 = (**(code **)(*(int *)param_1 + 0x178))(param_1,uVar1,"nativeId",&DAT_00b7a97d);
  iVar2 = catchException("/Users/erik/Documents/readonly/carista-release/Carista/jni/JniHelper.h",
                         0x51);
  if (iVar2 == 0) {
    pRVar3 = (ReadValuesOperation *)(**(code **)(*(int *)param_1 + 0x194))(param_1,param_2,uVar1);
    iVar2 = catchException("/Users/erik/Documents/readonly/carista-release/Carista/jni/JniHelper.h",
                           0x55);
    if (iVar2 != 0) {
      pRVar3 = (ReadValuesOperation *)0x0;
    }
  }
  else {
    pRVar3 = (ReadValuesOperation *)0x0;
  }
  return pRVar3;
}


