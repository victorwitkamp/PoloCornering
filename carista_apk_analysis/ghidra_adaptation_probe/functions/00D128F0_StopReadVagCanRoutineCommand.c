/* StopReadVagCanRoutineCommand::StopReadVagCanRoutineCommand @ 00d128f0 */


/* StopReadVagCanRoutineCommand::StopReadVagCanRoutineCommand(VagCanEcu*, unsigned short, bool) */

void __thiscall
StopReadVagCanRoutineCommand::StopReadVagCanRoutineCommand
          (StopReadVagCanRoutineCommand *this,VagCanEcu *param_1,ushort param_2,bool param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           SingleResponseCommand<EmptyModel>::SingleResponseCommand
                     ((SingleResponseCommand<EmptyModel> *)this,(Ecu *)param_1,1,(uint)param_3);
  *(ushort *)(puVar1 + 4) = param_2;
  *puVar1 = &PTR__StopReadVagCanRoutineCommand_0143c438;
  return;
}


