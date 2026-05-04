/* ReadValuesOperation::addAvailableItem @ 012ceb94 */


/* ReadValuesOperation::addAvailableItem(SettingCategory*, std::__ndk1::shared_ptr<Setting> const&)
    */

void __thiscall
ReadValuesOperation::addAvailableItem
          (ReadValuesOperation *this,SettingCategory *param_1,shared_ptr *param_2)

{
  undefined4 uVar1;
  SettingCategory *local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = param_1;
  uVar1 = FUN_00d5ad5c(this + 0x68,&local_18);
  FUN_00d6f39a(uVar1,param_2);
  *(int *)(this + 0x90) = *(int *)(this + 0x90) + 1;
  if (__stack_chk_guard == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


