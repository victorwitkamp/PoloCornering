/* PreReadVagCanAdaptationDataCommand::PreReadVagCanAdaptationDataCommand @ 00d121b0 */


/* PreReadVagCanAdaptationDataCommand::PreReadVagCanAdaptationDataCommand(VagCanEcu*, unsigned
   short, bool) */

void __thiscall
PreReadVagCanAdaptationDataCommand::PreReadVagCanAdaptationDataCommand
          (PreReadVagCanAdaptationDataCommand *this,VagCanEcu *param_1,ushort param_2,bool param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           SingleResponseCommand<EmptyModel>::SingleResponseCommand
                     ((SingleResponseCommand<EmptyModel> *)this,(Ecu *)param_1,4,(uint)param_3);
  *(ushort *)(puVar1 + 4) = param_2;
  *puVar1 = &PTR__PreReadVagCanAdaptationDataCommand_0143c2b8;
  return;
}


