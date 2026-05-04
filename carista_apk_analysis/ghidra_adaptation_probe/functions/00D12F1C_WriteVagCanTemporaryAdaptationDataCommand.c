/* WriteVagCanTemporaryAdaptationDataCommand::WriteVagCanTemporaryAdaptationDataCommand @ 00d12f1c */


/* WriteVagCanTemporaryAdaptationDataCommand::WriteVagCanTemporaryAdaptationDataCommand(VagCanEcu*,
   unsigned short, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   const&, bool) */

WriteVagCanTemporaryAdaptationDataCommand * __thiscall
WriteVagCanTemporaryAdaptationDataCommand::WriteVagCanTemporaryAdaptationDataCommand
          (WriteVagCanTemporaryAdaptationDataCommand *this,VagCanEcu *param_1,ushort param_2,
          vector *param_3,bool param_4)

{
  undefined3 in_stack_00000001;
  
  SingleResponseCommand<EmptyModel>::SingleResponseCommand
            ((SingleResponseCommand<EmptyModel> *)this,(Ecu *)param_1,2,(uint)(_param_4 != 0));
  *(ushort *)(this + 0x10) = param_2;
  *(undefined ***)this = &PTR__WriteVagCanTemporaryAdaptationDataCommand_0143c528;
  FUN_00cd5ef0(this + 0x14,param_3);
  return this;
}


