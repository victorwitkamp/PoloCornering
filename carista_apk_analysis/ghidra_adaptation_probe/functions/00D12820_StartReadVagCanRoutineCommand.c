/* StartReadVagCanRoutineCommand::StartReadVagCanRoutineCommand @ 00d12820 */


/* StartReadVagCanRoutineCommand::StartReadVagCanRoutineCommand(VagCanEcu*, unsigned short, bool) */

void __thiscall
StartReadVagCanRoutineCommand::StartReadVagCanRoutineCommand
          (StartReadVagCanRoutineCommand *this,VagCanEcu *param_1,ushort param_2,bool param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           SingleResponseCommand<EmptyModel>::SingleResponseCommand
                     ((SingleResponseCommand<EmptyModel> *)this,(Ecu *)param_1,2,(uint)param_3);
  *(ushort *)(puVar1 + 4) = param_2;
  *puVar1 = &PTR__StartReadVagCanRoutineCommand_0143c408;
  return;
}


