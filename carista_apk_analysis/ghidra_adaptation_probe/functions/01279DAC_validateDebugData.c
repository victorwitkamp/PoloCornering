/* VagOperationDelegate::validateDebugData @ 01279dac */


/* VagOperationDelegate::validateDebugData(DebugData const&) */

undefined4 __thiscall
VagOperationDelegate::validateDebugData(VagOperationDelegate *this,DebugData *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*(int *)this + 0x1fc))(this,param_1,VagEcu::CAN_GATEWAY);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)this + 0x1fc))(this,param_1,VagEcu::CENTRAL_ELEC);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)this + 0x1fc))(this,param_1,VagEcu::INSTRUMENT_CLUSTER);
      if ((iVar1 == 0) ||
         (iVar1 = (**(code **)(*(int *)this + 0x1fc))(this,param_1,VagEcu::CONTROL_HEAD_FRONT),
         iVar1 == 0)) {
        return 1;
      }
      uVar3 = 0xfffffff5;
      pcVar2 = "Could not connect to INSTRUMENT_CLUSTER collect debug data";
    }
    else {
      uVar3 = 0xffffffe5;
      pcVar2 = "Could not connect to CENTRAL_ELEC to collect debug data";
    }
  }
  else {
    uVar3 = 0xfffffff5;
    pcVar2 = "Could not connect to CAN_GATEWAY to collect debug data";
  }
  Log::e(pcVar2);
  return uVar3;
}


