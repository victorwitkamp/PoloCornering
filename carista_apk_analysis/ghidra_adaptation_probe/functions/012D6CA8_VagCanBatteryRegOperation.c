/* VagCanBatteryRegOperation::VagCanBatteryRegOperation @ 012d6ca8 */


/* VagCanBatteryRegOperation::VagCanBatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagCanBatteryRegOperation::VagCanBatteryRegOperation
          (VagCanBatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  IllegalArgumentException *this_00;
  basic_string abStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  VagBatteryRegOperation::VagBatteryRegOperation
            ((VagBatteryRegOperation *)this,param_1,param_2,param_3);
  *(undefined ***)this = &PTR__VagCanBatteryRegOperation_014befb4;
  if (*(int *)(*(int *)param_2 + 0x90) == *(int *)(*(int *)param_2 + 0x94)) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_28,"VagBasicSettingTool has no settings.");
    IllegalArgumentException::IllegalArgumentException(this_00,abStack_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


