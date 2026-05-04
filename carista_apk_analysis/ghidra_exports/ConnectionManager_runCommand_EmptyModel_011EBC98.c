/*
 * ConnectionManager_runCommand_EmptyModel
 * ELF symbol address: 0x011DBC98
 * Ghidra address: 0x011EBC98 (ELF + 0x10000 image delta)
 * ELF symbol size: 240 bytes
 * Symbol: _ZN17ConnectionManager10runCommandI10EmptyModelEE6ResultIT_vERKNSt6__ndk110shared_ptrI7CommandIS3_EEERKNS6_IN5State21OnStateUpdateListenerEEE
 * Program: libCarista.so
 * Resolved function: ConnectionManager::runCommand<EmptyModel> @ 011ebc98
 * Signature: Result __stdcall runCommand<EmptyModel>(shared_ptr * param_1, shared_ptr * param_2)
 * Return type: /Demangler/CanProtocol/Result
pack(disabled)
Structure Result {
}
Length: 0 Alignment: 1

 * Function body: [[011ebc98, 011ebd65]]
 * Parameters:
 *   [0] shared_ptr * param_1
 *   [1] shared_ptr * param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea620
 *   ConnectionManager::runCommand<EmptyModel> @ 0141f530 -> COMPUTED_CALL from 0141f538
 * Direct callees/references:
 *   READ 011ebd7c from 011ebca4
 *   READ 014da87c from 011ebcae
 *   READ 015a7014 from 011ebcb0
 *   WRITE Stack[-0x1c] from 011ebcb2
 *   CONDITIONAL_JUMP ConnectionManager::runCommand<EmptyModel> @ 011ebc98 from 011ebcbc
 *   WRITE Stack[-0x48] from 011ebcc2
 *   CONDITIONAL_JUMP ConnectionManager::runCommand<EmptyModel> @ 011ebc98 from 011ebcc6
 *   CONDITIONAL_JUMP ConnectionManager::runCommand<EmptyModel> @ 011ebc98 from 011ebcd6
 *   WRITE Stack[-0x50] from 011ebcdc
 *   READ 011ebd80 from 011ebce0
 *   READ 014db834 from 011ebce4
 *   PARAM 0143e700 from 011ebce4
 *   UNCONDITIONAL_CALL FUN_00d2be22 @ 00d2be22 from 011ebcee
 *   READ Stack[-0x28] from 011ebcf2
 *   WRITE Stack[-0x48] from 011ebcfc
 *   CONDITIONAL_JUMP ConnectionManager::runCommand<EmptyModel> @ 011ebc98 from 011ebd00
 *   CONDITIONAL_JUMP ConnectionManager::runCommand<EmptyModel> @ 011ebc98 from 011ebd10
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 0141fde0 from 011ebd18
 *   UNCONDITIONAL_CALL FUN_00cdf4d4 @ 00cdf4d4 from 011ebd1e
 *   UNCONDITIONAL_CALL Result<Model,void>::~Result @ 014040a0 from 011ebd24
 *   UNCONDITIONAL_JUMP ConnectionManager::runCommand<EmptyModel> @ 011ebc98 from 011ebd28
 *   WRITE Stack[-0x50] from 011ebd2a
 *   UNCONDITIONAL_CALL ConnectionManager::internalRunCommand<EmptyModel> @ 0141fdf0 from 011ebd36
 *   UNCONDITIONAL_CALL BroadcastCommandResult<EmptyModel>::extractCommandResult @ 0141fe00 from 011ebd42
 *   UNCONDITIONAL_CALL Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>::~Result @ 0141fe10 from 011ebd48
 *   READ Stack[-0x1c] from 011ebd4c
 *   READ 011ebd84 from 011ebd4e
 *   READ 014da87c from 011ebd52
 *   READ 015a7014 from 011ebd54
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 011ebd62
 */

/* Ghidra function: ConnectionManager::runCommand<EmptyModel> @ 011ebc98 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d8eb0804635480d461e4678441446006800680d9008684169
 * 011ebc98: push {r4,r5,r6,r7,lr}
 * 011ebc9a: add r7,sp,#0xc
 * 011ebc9c: push.w r8
 * 011ebca0: sub sp,#0x38
 * 011ebca2: mov r8,r0
 * 011ebca4: ldr r0,[0x011ebd7c]
 * 011ebca6: mov r5,r1
 * 011ebca8: mov r6,r3
 * 011ebcaa: add r0,pc
 * 011ebcac: mov r4,r2
 * 011ebcae: ldr r0,[r0,#0x0]
 * 011ebcb0: ldr r0,[r0,#0x0]
 * 011ebcb2: str r0,[sp,#0x34]
 * 011ebcb4: ldr r0,[r1,#0x0]
 * 011ebcb6: ldr r1,[r0,#0x14]
 * 011ebcb8: mov r0,r5
 * 011ebcba: blx r1
 * 011ebcbc: cbz r0,0x011ebd2a
 * 011ebcbe: ldrd r1,r0,[r4,#0x0]
 * 011ebcc2: strd r1,r0,[sp,#0x8]
 * 011ebcc6: cbz r0,0x011ebcd8
 * 011ebcc8: adds r0,#0x4
 * 011ebcca: ldrex r1,[r0,#0x0]
 * 011ebcce: adds r1,#0x1
 */


/* Result<EmptyModel, void>
   ConnectionManager::runCommand<EmptyModel>(std::__ndk1::shared_ptr<Command<EmptyModel> > const&,
   std::__ndk1::shared_ptr<State::OnStateUpdateListener> const&) */

void ConnectionManager::runCommand<EmptyModel>(shared_ptr *param_1,shared_ptr *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  shared_ptr *in_r2;
  undefined4 local_48;
  int iStack_44;
  Result<Model,void> aRStack_40 [24];
  int *local_28;
  undefined4 *puStack_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = (**(code **)(*(int *)param_2 + 0x14))(param_2);
  if (iVar2 == 0) {
    internalRunCommand<EmptyModel>((shared_ptr *)aRStack_40,SUB41(param_2,0),in_r2);
    BroadcastCommandResult<EmptyModel>::extractCommandResult((Ecu *)param_1);
    Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
    ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
               *)aRStack_40);
  }
  else {
    local_48 = *(undefined4 *)in_r2;
    iStack_44 = *(int *)(in_r2 + 4);
    if (iStack_44 != 0) {
      piVar3 = (int *)(iStack_44 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    (**(code **)(*(int *)param_2 + 0x18))(aRStack_40,param_2,&local_48,&EmptyModel::typeinfo);
    FUN_00d2be22(&local_48);
    iVar2 = *local_28;
    local_48 = *puStack_24;
    iStack_44 = puStack_24[1];
    if (iStack_44 != 0) {
      piVar3 = (int *)(iStack_44 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    Result<EmptyModel,void>::Result
              ((Result<EmptyModel,void> *)param_1,iVar2,(shared_ptr *)&local_48);
    FUN_00cdf4d4((shared_ptr *)&local_48);
    Result<Model,void>::~Result(aRStack_40);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


