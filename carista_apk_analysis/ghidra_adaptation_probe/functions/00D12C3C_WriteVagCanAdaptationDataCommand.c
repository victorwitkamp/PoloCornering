/* WriteVagCanAdaptationDataCommand::WriteVagCanAdaptationDataCommand @ 00d12c3c */


/* WriteVagCanAdaptationDataCommand::WriteVagCanAdaptationDataCommand(VagCanEcu*, unsigned short,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&, bool) */

void __thiscall
WriteVagCanAdaptationDataCommand::WriteVagCanAdaptationDataCommand
          (WriteVagCanAdaptationDataCommand *this,VagCanEcu *param_1,ushort param_2,vector *param_3,
          vector *param_4,bool param_5)

{
  int iVar1;
  IllegalArgumentException *this_00;
  undefined3 in_stack_00000005;
  VagCanEcu *pVStack_3c;
  uint uStack_38;
  vector *pvStack_34;
  
  iVar1 = __stack_chk_guard;
  uStack_38 = (uint)param_2;
  pVStack_3c = param_1;
  pvStack_34 = param_3;
  SingleResponseCommand<EmptyModel>::SingleResponseCommand
            ((SingleResponseCommand<EmptyModel> *)this,(Ecu *)param_1,2,(uint)(_param_5 != 0));
  *(ushort *)(this + 0x10) = param_2;
  *(undefined ***)this = &PTR__WriteVagCanAdaptationDataCommand_0143c4c8;
  FUN_00cd5ef0(this + 0x14,param_3);
  FUN_00cd5ef0(this + 0x20,param_4);
  if (*(int *)(param_4 + 4) - *(int *)param_4 != 6) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    std::__ndk1::to_string((uint)&pVStack_3c);
    FUN_00cbe7e4(&stack0xffffffd0,"Workshop code must be exactly 6 bytes, but was ",&pVStack_3c);
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&stack0xffffffd0);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}


