/* ReadVagCanShortAdaptationDataCommand::ReadVagCanShortAdaptationDataCommand @ 00d1266c */


/* ReadVagCanShortAdaptationDataCommand::ReadVagCanShortAdaptationDataCommand(VagCanEcu*, bool) */

void __thiscall
ReadVagCanShortAdaptationDataCommand::ReadVagCanShortAdaptationDataCommand
          (ReadVagCanShortAdaptationDataCommand *this,VagCanEcu *param_1,bool param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ReadVagCanAdaptationDataCommand::ReadVagCanAdaptationDataCommand
                     ((ReadVagCanAdaptationDataCommand *)this,param_1,0x103,param_2);
  *puVar1 = &PTR__ReadVagCanShortAdaptationDataCommand_0143c3a8;
  return;
}


