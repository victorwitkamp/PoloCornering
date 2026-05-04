/* SingleButtonGenericOperation::SingleButtonGenericOperation @ 012d3ca4 */


/* SingleButtonGenericOperation::SingleButtonGenericOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
SingleButtonGenericOperation::SingleButtonGenericOperation
          (SingleButtonGenericOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           GenericToolOperation::GenericToolOperation
                     ((GenericToolOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__SingleButtonGenericOperation_014bea84;
  return;
}


