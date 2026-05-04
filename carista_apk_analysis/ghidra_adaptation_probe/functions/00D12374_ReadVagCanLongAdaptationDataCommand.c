/* ReadVagCanLongAdaptationDataCommand::ReadVagCanLongAdaptationDataCommand @ 00d12374 */


/* ReadVagCanLongAdaptationDataCommand::ReadVagCanLongAdaptationDataCommand(VagCanEcu*, bool) */

void __thiscall
ReadVagCanLongAdaptationDataCommand::ReadVagCanLongAdaptationDataCommand
          (ReadVagCanLongAdaptationDataCommand *this,VagCanEcu *param_1,bool param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ReadVagCanAdaptationDataCommand::ReadVagCanAdaptationDataCommand
                     ((ReadVagCanAdaptationDataCommand *)this,param_1,0x10a,param_2);
  *puVar1 = &PTR__ReadVagCanLongAdaptationDataCommand_0143c318;
  return;
}


