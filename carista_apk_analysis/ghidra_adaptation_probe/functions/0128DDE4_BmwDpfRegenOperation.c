/* BmwDpfRegenOperation::BmwDpfRegenOperation @ 0128dde4 */


/* BmwDpfRegenOperation::BmwDpfRegenOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
BmwDpfRegenOperation::BmwDpfRegenOperation
          (BmwDpfRegenOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  undefined4 *puVar1;
  double in_d0;
  double in_d1;
  
  puVar1 = (undefined4 *)
           DpfRegenGenericOperation::DpfRegenGenericOperation
                     ((DpfRegenGenericOperation *)this,param_1,param_2,param_3,in_d0,in_d1);
  *puVar1 = &PTR__BmwDpfRegenOperation_014bb4fc;
  return;
}


