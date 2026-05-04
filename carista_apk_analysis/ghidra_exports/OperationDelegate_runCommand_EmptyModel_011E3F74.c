/*
 * OperationDelegate_runCommand_EmptyModel
 * ELF symbol address: 0x011D3F74
 * Ghidra address: 0x011E3F74 (ELF + 0x10000 image delta)
 * ELF symbol size: 160 bytes
 * Symbol: _ZN17OperationDelegate10runCommandI10EmptyModelEE6ResultIT_vERKNSt6__ndk110shared_ptrI7CommandIS3_EEERKNS6_I8ProgressEE
 * Program: libCarista.so
 * Resolved function: OperationDelegate::runCommand<EmptyModel> @ 011e3f74
 * Signature: Result __stdcall runCommand<EmptyModel>(shared_ptr * param_1, shared_ptr * param_2)
 * Return type: /Demangler/CanProtocol/Result
pack(disabled)
Structure Result {
}
Length: 0 Alignment: 1

 * Function body: [[011e3f74, 011e3ffb]]
 * Parameters:
 *   [0] shared_ptr * param_1
 *   [1] shared_ptr * param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea61c
 *   OperationDelegate::runCommand<EmptyModel> @ 0141f520 -> COMPUTED_CALL from 0141f528
 * Direct callees/references:
 *   READ 011e400c from 011e3f80
 *   READ 014da87c from 011e3f88
 *   READ 015a7014 from 011e3f8a
 *   WRITE Stack[-0x1c] from 011e3f8c
 *   CONDITIONAL_JUMP OperationDelegate::runCommand<EmptyModel> @ 011e3f74 from 011e3f96
 *   READ 011e4008 from 011e3f98
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 013fd730 from 011e3f9c
 *   UNCONDITIONAL_JUMP OperationDelegate::runCommand<EmptyModel> @ 011e3f74 from 011e3fa0
 *   UNCONDITIONAL_CALL ConnectionManager::runCommand<EmptyModel> @ 0141f530 from 011e3fae
 *   READ Stack[-0x28] from 011e3fb8
 *   CONDITIONAL_JUMP OperationDelegate::runCommand<EmptyModel> @ 011e3f74 from 011e3fc4
 *   UNCONDITIONAL_CALL ConnectionManager::runCommand<EmptyModel> @ 0141f530 from 011e3fce
 *   UNCONDITIONAL_JUMP OperationDelegate::runCommand<EmptyModel> @ 011e3f74 from 011e3fd2
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 0141f540 from 011e3fd8
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::~Result @ 013fd720 from 011e3fde
 *   READ Stack[-0x1c] from 011e3fe2
 *   READ 011e4010 from 011e3fe4
 *   READ 014da87c from 011e3fe8
 *   READ 015a7014 from 011e3fea
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 011e3ff8
 */

/* Ghidra function: OperationDelegate::runCommand<EmptyModel> @ 011e3f74 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d8ab0044622480e4615467844006800680990186801684969
 * 011e3f74: push {r4,r5,r6,r7,lr}
 * 011e3f76: add r7,sp,#0xc
 * 011e3f78: push.w r8
 * 011e3f7c: sub sp,#0x28
 * 011e3f7e: mov r4,r0
 * 011e3f80: ldr r0,[0x011e400c]
 * 011e3f82: mov r6,r1
 * 011e3f84: mov r5,r2
 * 011e3f86: add r0,pc
 * 011e3f88: ldr r0,[r0,#0x0]
 * 011e3f8a: ldr r0,[r0,#0x0]
 * 011e3f8c: str r0,[sp,#0x24]
 * 011e3f8e: ldr r0,[r3,#0x0]
 * 011e3f90: ldr r1,[r0,#0x0]
 * 011e3f92: ldr r1,[r1,#0x14]
 * 011e3f94: blx r1
 * 011e3f96: cbz r0,0x011e3fa2
 * 011e3f98: ldr r1,[0x011e4008]
 * 011e3f9a: mov r0,r4
 * 011e3f9c: blx 0x013fd730
 * 011e3fa0: b 0x011e3fe2
 * 011e3fa2: add.w r8,r6,#0x20
 * 011e3fa6: ldr r1,[r6,#0x18]
 * 011e3fa8: mov r0,sp
 */


/* Result<EmptyModel, void>
   OperationDelegate::runCommand<EmptyModel>(std::__ndk1::shared_ptr<Command<EmptyModel> > const&,
   std::__ndk1::shared_ptr<Progress> const&) */

void OperationDelegate::runCommand<EmptyModel>(shared_ptr *param_1,shared_ptr *param_2)

{
  int iVar1;
  int *in_r2;
  undefined4 *in_r3;
  shared_ptr asStack_40 [24];
  undefined4 *local_28;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = (**(code **)(*(int *)*in_r3 + 0x14))();
  if (iVar1 == 0) {
    ConnectionManager::runCommand<EmptyModel>(asStack_40,*(shared_ptr **)(param_2 + 0x18));
    iVar1 = (**(code **)(*(int *)param_2 + 0x16c))(param_2,*(undefined4 *)(*in_r2 + 4),*local_28);
    if (iVar1 == 0) {
      Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,(Result *)asStack_40);
    }
    else {
      ConnectionManager::runCommand<EmptyModel>(param_1,*(shared_ptr **)(param_2 + 0x18));
    }
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_40);
  }
  else {
    Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,-1000);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


