/* GenericToolActionOperation::GenericToolActionOperation @ 012afc7c */


/* GenericToolActionOperation::GenericToolActionOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
GenericToolActionOperation::GenericToolActionOperation
          (GenericToolActionOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           GenericToolSavableOperation::GenericToolSavableOperation
                     ((GenericToolSavableOperation *)this);
  *(undefined8 *)(puVar1 + 0x4a) = 0;
  *(undefined8 *)(puVar1 + 0x4c) = 0;
  *(undefined2 *)(puVar1 + 0x4e) = 0;
  puVar1[0x49] = 0;
  *puVar1 = &PTR__GenericToolActionOperation_014bd06c;
  puVar1[0x47] = puVar1 + 0x48;
  puVar1[0x48] = 0;
  *(bool *)((int)puVar1 + 0x139) = puVar1[0x2a] != puVar1[0x2b];
  return;
}


