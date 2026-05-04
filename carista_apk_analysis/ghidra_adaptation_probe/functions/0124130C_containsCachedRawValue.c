/* OperationDelegate::containsCachedRawValue @ 0124130c */


/* OperationDelegate::containsCachedRawValue(std::__ndk1::shared_ptr<Setting> const&) */

void OperationDelegate::containsCachedRawValue(shared_ptr *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(*(int *)param_1 + 0x148))(param_1);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
                    /* WARNING: Could not recover jumptable at 0x0124132c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)param_1 + 0x9c))(param_1,uVar1,(int)uVar2,uVar1);
  return;
}


