/* SetVagCanAdaptationChannelCommand::SetVagCanAdaptationChannelCommand @ 00d1274c */


/* SetVagCanAdaptationChannelCommand::SetVagCanAdaptationChannelCommand(VagCanEcu*, unsigned short,
   unsigned char, bool) */

void __thiscall
SetVagCanAdaptationChannelCommand::SetVagCanAdaptationChannelCommand
          (SetVagCanAdaptationChannelCommand *this,VagCanEcu *param_1,ushort param_2,uchar param_3,
          bool param_4)

{
  undefined4 *puVar1;
  undefined3 in_stack_00000001;
  
  puVar1 = (undefined4 *)
           SingleResponseCommand<EmptyModel>::SingleResponseCommand
                     ((SingleResponseCommand<EmptyModel> *)this,(Ecu *)param_1,2,_param_4);
  *(uchar *)((int)puVar1 + 0x12) = param_3;
  *(ushort *)(puVar1 + 4) = param_2;
  *puVar1 = &PTR__SetVagCanAdaptationChannelCommand_0143c3d8;
  return;
}


