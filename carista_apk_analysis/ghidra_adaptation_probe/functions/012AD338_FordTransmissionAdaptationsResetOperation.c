/* FordTransmissionAdaptationsResetOperation::FordTransmissionAdaptationsResetOperation @ 012ad338 */


/* FordTransmissionAdaptationsResetOperation::FordTransmissionAdaptationsResetOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<FordGenericTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
FordTransmissionAdaptationsResetOperation::FordTransmissionAdaptationsResetOperation
          (FordTransmissionAdaptationsResetOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  IllegalArgumentException *this_00;
  basic_string abStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_0142b630(this);
  *(undefined ***)this = &PTR__FordTransmissionAdaptationsResetOperation_014bcd74;
  if (*(int *)(*(int *)param_2 + 0x78) == *(int *)(*(int *)param_2 + 0x7c)) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_28,
                 "Tool passed to FordTransmissionAdaptationsResetOperation doesn\'t have actions!");
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


