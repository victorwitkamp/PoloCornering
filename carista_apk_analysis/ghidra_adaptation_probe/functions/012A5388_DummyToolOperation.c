/* DummyToolOperation::DummyToolOperation @ 012a5388 */


/* DummyToolOperation::DummyToolOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
DummyToolOperation::DummyToolOperation
          (DummyToolOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           GenericToolOperation::GenericToolOperation
                     ((GenericToolOperation *)this,param_1,param_2,param_3);
  puVar1[0x43] = 0;
  puVar1[0x44] = 0;
  *puVar1 = &PTR__DummyToolOperation_014bc6e4;
  return;
}


