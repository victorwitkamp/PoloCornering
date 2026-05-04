/* GenericToolSavableOperation::GenericToolSavableOperation @ 012bb580 */


/* GenericToolSavableOperation::GenericToolSavableOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&, LibStr) */

void __thiscall
GenericToolSavableOperation::GenericToolSavableOperation
          (GenericToolSavableOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3,undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           GenericToolOperation::GenericToolOperation
                     ((GenericToolOperation *)this,param_1,param_2,param_3);
  puVar1[0x46] = param_5;
  *(undefined1 *)(puVar1 + 0x45) = 0;
  puVar1[0x43] = 0xffffffff;
  puVar1[0x44] = 0xffffffff;
  *puVar1 = &PTR__GenericToolOperation_014bd868;
  return;
}


