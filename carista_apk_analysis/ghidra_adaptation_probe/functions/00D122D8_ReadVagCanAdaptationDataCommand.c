/* ReadVagCanAdaptationDataCommand::ReadVagCanAdaptationDataCommand @ 00d122d8 */


/* ReadVagCanAdaptationDataCommand::ReadVagCanAdaptationDataCommand(VagCanEcu*, unsigned short,
   bool) */

void __thiscall
ReadVagCanAdaptationDataCommand::ReadVagCanAdaptationDataCommand
          (ReadVagCanAdaptationDataCommand *this,VagCanEcu *param_1,ushort param_2,bool param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           SingleResponseCommand<BytesModel>::SingleResponseCommand
                     ((SingleResponseCommand<BytesModel> *)this,(Ecu *)param_1,4,(uint)param_3);
  *(ushort *)(puVar1 + 4) = param_2;
  *puVar1 = &PTR__ReadVagCanAdaptationDataCommand_0143c2e8;
  return;
}


