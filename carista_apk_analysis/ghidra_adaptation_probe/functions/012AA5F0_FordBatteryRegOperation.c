/* FordBatteryRegOperation::FordBatteryRegOperation @ 012aa5f0 */


/* FordBatteryRegOperation::FordBatteryRegOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
FordBatteryRegOperation::FordBatteryRegOperation
          (FordBatteryRegOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3
          )

{
  IllegalArgumentException *this_00;
  basic_string abStack_30 [12];
  int local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  BatteryRegOperation::BatteryRegOperation((BatteryRegOperation *)this,param_1,param_2,param_3);
  *(undefined ***)this = &PTR__FordBatteryRegOperation_014bca0c;
  FUN_011e7154(local_24,param_2);
  if (*(int *)(local_24[0] + 0x1c) - *(int *)(local_24[0] + 0x18) != 0x10) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_30,"Tool passed to genericTool without two actions");
    IllegalArgumentException::IllegalArgumentException(this_00,abStack_30);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  FUN_011e71a0(local_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


