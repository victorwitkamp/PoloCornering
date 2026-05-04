/* DpfRegenGenericOperation::DpfRegenGenericOperation @ 012a43e8 */


/* DpfRegenGenericOperation::DpfRegenGenericOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&, double, double) */

void __thiscall
DpfRegenGenericOperation::DpfRegenGenericOperation
          (DpfRegenGenericOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3,double param_4,double param_5)

{
  undefined4 *puVar1;
  undefined8 in_stack_00000000;
  undefined8 in_stack_00000008;
  
  puVar1 = (undefined4 *)
           GenericToolOperation::GenericToolOperation
                     ((GenericToolOperation *)this,param_1,param_2,param_3);
  puVar1[0x4c] = 0;
  puVar1[0x4d] = 0;
  *(undefined8 *)(puVar1 + 0x46) = in_stack_00000008;
  *(undefined1 *)(puVar1 + 0x4b) = 1;
  puVar1[0x49] = 0;
  puVar1[0x4a] = 0;
  *(undefined8 *)(puVar1 + 0x44) = in_stack_00000000;
  *puVar1 = &PTR__DpfRegenGenericOperation_014bc5c0;
  return;
}


