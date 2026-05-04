/*
 * Communicator_internalExecuteCommand_EmptyModel
 * ELF symbol address: 0x011DD384
 * Ghidra address: 0x011ED384 (ELF + 0x10000 image delta)
 * ELF symbol size: 520 bytes
 * Symbol: _ZN12Communicator22internalExecuteCommandI10EmptyModelEE22BroadcastCommandResultIT_ERKNSt6__ndk110shared_ptrI7CommandIS3_EEEjb
 * Program: libCarista.so
 * Resolved function: Communicator::internalExecuteCommand<EmptyModel> @ 011ed384
 * Signature: BroadcastCommandResult __stdcall internalExecuteCommand<EmptyModel>(shared_ptr * param_1, uint param_2, bool param_3)
 * Return type: typedef BroadcastCommandResult undefined
 * Function body: [[011ed384, 011ed51b]]
 * Parameters:
 *   [0] shared_ptr * param_1
 *   [1] uint param_2
 *   [2] bool param_3
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea884
 *   Communicator::internalExecuteCommand<EmptyModel> @ 0141fec0 -> COMPUTED_CALL from 0141fec8
 * Direct callees/references:
 *   READ 011ed570 from 011ed390
 *   READ 014da87c from 011ed39a
 *   READ 015a7014 from 011ed39c
 *   WRITE Stack[-0x24] from 011ed39e
 *   READ Stack[0x0] from 011ed3b0
 *   WRITE Stack[-0x58] from 011ed3be
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 011ed3cc
 *   UNCONDITIONAL_CALL State::isError @ 013fa840 from 011ed3d2
 *   CONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed3d6
 *   UNCONDITIONAL_CALL ByteUtils::getHexString @ 013fd820 from 011ed3ec
 *   READ Stack[-0x3c] from 011ed3f0
 *   READ Stack[-0x34] from 011ed3f4
 *   READ 011ed574 from 011ed3fc
 *   PARAM 0072e347 from 011ed3fe
 *   UNCONDITIONAL_CALL Log::e @ 013fa760 from 011ed400
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 011ed406
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 011ed40c
 *   UNCONDITIONAL_CALL BroadcastCommandResult<EmptyModel>::BroadcastCommandResult @ 0141fe30 from 011ed414
 *   UNCONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed418
 *   DATA Stack[-0x3c] from 011ed426
 *   CONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed42c
 *   CONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed434
 *   UNCONDITIONAL_CALL ByteUtils::isValidHexString @ 01402d40 from 011ed438
 *   CONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed43e
 *   UNCONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed442
 *   UNCONDITIONAL_CALL Communicator::isEcuDeadlock @ 01402e30 from 011ed446
 *   CONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed44a
 *   READ 011ed578 from 011ed44c
 *   PARAM 00c4a701 from 011ed44e
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 011ed450
 *   UNCONDITIONAL_CALL BroadcastCommandResult<EmptyModel>::BroadcastCommandResult @ 0141fe30 from 011ed464
 *   UNCONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed468
 *   PARAM fffffff5 from 011ed46c
 *   UNCONDITIONAL_CALL Communicator::extractFirstError @ 01402e50 from 011ed470
 *   WRITE Stack[-0x30] from 011ed478
 *   UNCONDITIONAL_CALL FUN_00d1a6c4 @ 00d1a6c4 from 011ed480
 *   UNCONDITIONAL_CALL Communicator::filterByStatusInPlace @ 01402e40 from 011ed488
 *   READ Stack[-0x3c] from 011ed48c
 *   CONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed492
 *   UNCONDITIONAL_CALL Communicator::processResponses<EmptyModel> @ 0141ff70 from 011ed49c
 *   UNCONDITIONAL_JUMP Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 from 011ed4a0
 *   UNCONDITIONAL_CALL BroadcastCommandResult<EmptyModel>::BroadcastCommandResult @ 0141fe30 from 011ed4a6
 *   UNCONDITIONAL_CALL FUN_00d1a7c8 @ 00d1a7c8 from 011ed4ac
 *   UNCONDITIONAL_CALL FUN_00d1a800 @ 00d1a800 from 011ed4b2
 *   READ Stack[-0x24] from 011ed4b6
 *   READ 011ed588 from 011ed4b8
 *   READ 014da87c from 011ed4bc
 *   READ 015a7014 from 011ed4be
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 011ed4cc
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 011ed4d2
 *   READ 011ed57c from 011ed4e8
 *   PARAM 0082d048 from 011ed4ea
 *   UNCONDITIONAL_CALL FUN_00cbe830 @ 00cbe830 from 011ed4ec
 *   UNCONDITIONAL_CALL FUN_00cdb302 @ 00cdb302 from 011ed4fa
 *   UNCONDITIONAL_CALL IllegalStateException::IllegalStateException @ 013fadb0 from 011ed504
 *   READ 011ed580 from 011ed50a
 *   READ 014da944 from 011ed50e
 *   PARAM 01437dd4 from 011ed50e
 *   READ 011ed584 from 011ed510
 *   READ 014da948 from 011ed514
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 011ed514
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 011ed518
 */

/* Ghidra function: Communicator::internalExecuteCommand<EmptyModel> @ 011ed384 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de900078eb0804677488a46914678441c46006800680d9011680868
 * 011ed384: push {r4,r5,r6,r7,lr}
 * 011ed386: add r7,sp,#0xc
 * 011ed388: push {r8,r9,r10}
 * 011ed38c: sub sp,#0x38
 * 011ed38e: mov r8,r0
 * 011ed390: ldr r0,[0x011ed570]
 * 011ed392: mov r10,r1
 * 011ed394: mov r9,r2
 * 011ed396: add r0,pc
 * 011ed398: mov r4,r3
 * 011ed39a: ldr r0,[r0,#0x0]
 * 011ed39c: ldr r0,[r0,#0x0]
 * 011ed39e: str r0,[sp,#0x34]
 * 011ed3a0: ldr r1,[r2,#0x0]
 * 011ed3a2: ldr r0,[r1,#0x0]
 * 011ed3a4: ldr r2,[r0,#0x8]
 * 011ed3a6: add r6,sp,#0x1c
 * 011ed3a8: mov r0,r6
 * 011ed3aa: blx r2
 * 011ed3ac: ldr.w r0,[r9,#0x0]
 * 011ed3b0: ldr r1,[r7,#0x8]
 * 011ed3b2: ldrb r3,[r0,#0xc]
 * 011ed3b4: ldrb r0,[r0,#0xe]
 * 011ed3b6: ands r0,r1
 */


/* BroadcastCommandResult<EmptyModel>
   Communicator::internalExecuteCommand<EmptyModel>(std::__ndk1::shared_ptr<Command<EmptyModel> >
   const&, unsigned int, bool) */

void Communicator::internalExecuteCommand<EmptyModel>(shared_ptr *param_1,uint param_2,bool param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  IllegalStateException *this;
  int *piVar4;
  undefined1 auStack_54 [12];
  vector avStack_48 [12];
  undefined4 local_3c;
  int *piStack_38;
  int local_34;
  undefined4 local_30 [3];
  int local_24;
  
  local_24 = __stack_chk_guard;
  (**(code **)(**(int **)(uint)param_3 + 8))(&local_3c);
  iVar2 = (**(code **)(*(int *)param_2 + 0x20))(param_2,&local_3c);
  FUN_00cb7f50(&local_3c);
  iVar3 = State::isError(iVar2);
  if (iVar3 == 0) {
    (**(code **)(*(int *)param_2 + 0x24))(&local_3c,param_2);
    piVar1 = piStack_38;
    for (piVar4 = local_3c; piVar4 != piVar1; piVar4 = piVar4 + 2) {
      if ((*(int *)(*piVar4 + 4) == 1) &&
         (iVar2 = ByteUtils::isValidHexString((basic_string *)(*piVar4 + 0xc)), iVar2 == 0)) {
        this = (IllegalStateException *)__cxa_allocate_exception(8);
        (**(code **)(*(int *)param_2 + 8))(auStack_54,param_2);
        FUN_00cbe830(local_30,auStack_54," communicator has returned an invalid hex response: ");
        FUN_00cdb302(avStack_48,local_30,*piVar4 + 0xc);
        IllegalStateException::IllegalStateException(this,(basic_string *)avStack_48);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(this,&IllegalStateException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
    }
    iVar2 = isEcuDeadlock((vector *)&local_3c);
    if (iVar2 == 0) {
      iVar2 = extractFirstError((vector *)&local_3c,-0xb);
      local_30[0] = 1;
      FUN_00d1a6c4(avStack_48,local_30,1);
      filterByStatusInPlace((vector *)&local_3c,avStack_48);
      if (local_3c == piStack_38) {
        BroadcastCommandResult<EmptyModel>::BroadcastCommandResult
                  ((BroadcastCommandResult<EmptyModel> *)param_1,iVar2);
      }
      else {
        processResponses<EmptyModel>(param_1,(vector *)param_2);
      }
      FUN_00d1a7c8(avStack_48);
    }
    else {
      Log::d("Toyota K-line ECU deadlock detected: forcing reinit of bus...");
      (**(code **)(*(int *)param_2 + 0x38))(param_2);
      BroadcastCommandResult<EmptyModel>::BroadcastCommandResult
                ((BroadcastCommandResult<EmptyModel> *)param_1,-0x32);
    }
    FUN_00d1a800(&local_3c);
  }
  else {
    (**(code **)(**(int **)(uint)param_3 + 8))(avStack_48);
    ByteUtils::getHexString((ByteUtils *)&local_3c,avStack_48);
    if (((byte)local_3c._0_1_ & 1) == 0) {
      local_34 = (int)&local_3c + 1;
    }
    Log::e("Failed to send request %s",local_34);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_3c);
    FUN_00cb7f50(avStack_48);
    BroadcastCommandResult<EmptyModel>::BroadcastCommandResult
              ((BroadcastCommandResult<EmptyModel> *)param_1,iVar2);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


