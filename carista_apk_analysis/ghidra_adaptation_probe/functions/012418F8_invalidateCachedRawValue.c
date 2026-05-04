/* OperationDelegate::invalidateCachedRawValue @ 012418f8 */


/* OperationDelegate::invalidateCachedRawValue(std::__ndk1::shared_ptr<Setting> const&) */

void OperationDelegate::invalidateCachedRawValue(shared_ptr *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(*(int *)param_1 + 0x148))(param_1);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
                    /* WARNING: Could not recover jumptable at 0x01241918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)param_1 + 0xf8))(param_1,uVar1,(int)uVar2,uVar1);
  return;
}


