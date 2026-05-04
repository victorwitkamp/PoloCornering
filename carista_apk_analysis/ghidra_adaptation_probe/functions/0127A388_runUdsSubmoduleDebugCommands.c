/* VagOperationDelegate::runUdsSubmoduleDebugCommands @ 0127a388 */


/* VagOperationDelegate::runUdsSubmoduleDebugCommands(Ecu*, unsigned short, unsigned short, unsigned
   short, DebugData&, std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::runUdsSubmoduleDebugCommands
          (VagOperationDelegate *this,Ecu *param_1,ushort param_2,ushort param_3,ushort param_4,
          DebugData *param_5,shared_ptr *param_6)

{
  int iVar1;
  ByteUtils aBStack_58 [12];
  ByteUtils aBStack_4c [12];
  ByteUtils aBStack_40 [12];
  undefined1 auStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  ByteUtils::getBytesFromShort(aBStack_40,param_2);
  _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_
            (auStack_34,0x22,aBStack_40);
  FUN_00cb7f50(aBStack_40);
  ByteUtils::getBytesFromShort(aBStack_4c,param_3);
  _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_
            (aBStack_40,0x22,aBStack_4c);
  FUN_00cb7f50(aBStack_4c);
  ByteUtils::getBytesFromShort(aBStack_58,param_4);
  _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_
            (aBStack_4c,0x22,aBStack_58);
  FUN_00cb7f50(aBStack_58);
  (**(code **)(*(int *)this + 0x170))(this,param_1,auStack_34,1,param_5,param_6);
  iVar1 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
  if (iVar1 == 0) {
    (**(code **)(*(int *)this + 0x170))(this,param_1,aBStack_40,1,param_5,param_6);
    iVar1 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
    if (iVar1 == 0) {
      (**(code **)(*(int *)this + 0x170))(this,param_1,aBStack_4c,1,param_5,param_6);
      iVar1 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
      if (iVar1 != 0) {
        Log::d("Failed to read VAG UDS submodule codingValue");
      }
    }
    else {
      Log::d("Failed to read VAG UDS submodule componentName");
    }
  }
  else {
    Log::d("Failed to read VAG UDS submodule partNo");
  }
  FUN_00cb7f50(aBStack_4c);
  FUN_00cb7f50(aBStack_40);
  FUN_00cb7f50(auStack_34);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}


