/*
 * BroadcastCommandResult_EmptyModel_extractCommandResult
 * ELF symbol address: 0x011DC234
 * Ghidra address: 0x011EC234 (ELF + 0x10000 image delta)
 * ELF symbol size: 132 bytes
 * Symbol: _ZNK22BroadcastCommandResultI10EmptyModelE20extractCommandResultEP3Ecu
 * Program: libCarista.so
 * Resolved function: BroadcastCommandResult<EmptyModel>::extractCommandResult @ 011ec234
 * Signature: undefined __stdcall extractCommandResult(Ecu * param_1)
 * Return type: undefined
 * Function body: [[011ec234, 011ec2a9]]
 * Parameters:
 *   [0] Ecu * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea854
 *   BroadcastCommandResult<EmptyModel>::extractCommandResult @ 0141fe00 -> COMPUTED_CALL from 0141fe08
 *   <no function> -> DATA from 014b6ef4
 * Direct callees/references:
 *   WRITE Stack[-0x18] from 011ec238
 *   READ 011ec2ac from 011ec23c
 *   READ 014da87c from 011ec242
 *   READ 015a7014 from 011ec244
 *   WRITE Stack[-0x14] from 011ec246
 *   UNCONDITIONAL_CALL Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>::isFail @ 0141fe90 from 011ec24a
 *   CONDITIONAL_JUMP BroadcastCommandResult<EmptyModel>::extractCommandResult @ 011ec234 from 011ec24e
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 013fd730 from 011ec256
 *   READ Stack[-0x14] from 011ec25a
 *   READ 011ec2b0 from 011ec25c
 *   READ 014da87c from 011ec260
 *   READ 015a7014 from 011ec262
 *   UNCONDITIONAL_JUMP BroadcastCommandResult<EmptyModel>::extractCommandResult @ 011ec234 from 011ec26a
 *   UNCONDITIONAL_CALL std::__ndk1::__hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>>>::__count_unique<Ecu*> @ 0141fea0 from 011ec272
 *   CONDITIONAL_JUMP BroadcastCommandResult<EmptyModel>::extractCommandResult @ 011ec234 from 011ec276
 *   UNCONDITIONAL_CALL FUN_011ede38 @ 011ede38 from 011ec27e
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 0141f540 from 011ec286
 *   UNCONDITIONAL_JUMP BroadcastCommandResult<EmptyModel>::extractCommandResult @ 011ec234 from 011ec28a
 *   PARAM fffffff5 from 011ec28e
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 013fd730 from 011ec292
 *   READ Stack[-0x14] from 011ec296
 *   READ 011ec2b4 from 011ec298
 *   READ 014da87c from 011ec29c
 *   READ 015a7014 from 011ec29e
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 011ec2a6
 */

/* Ghidra function: BroadcastCommandResult<EmptyModel>::extractCommandResult @ 011ec234 */

/* First instructions after recreation:
 * Memory bytes: bcb504af009204461b480d467844006800680190084633f222ee68b1a8690168
 * 011ec234: push {r2,r3,r4,r5,r7,lr}
 * 011ec236: add r7,sp,#0x10
 * 011ec238: str r2,[sp,#0x0]
 * 011ec23a: mov r4,r0
 * 011ec23c: ldr r0,[0x011ec2ac]
 * 011ec23e: mov r5,r1
 * 011ec240: add r0,pc
 * 011ec242: ldr r0,[r0,#0x0]
 * 011ec244: ldr r0,[r0,#0x0]
 * 011ec246: str r0,[sp,#0x4]
 * 011ec248: mov r0,r1
 * 011ec24a: blx 0x0141fe90
 * 011ec24e: cbz r0,0x011ec26c
 * 011ec250: ldr r0,[r5,#0x18]
 * 011ec252: ldr r1,[r0,#0x0]
 * 011ec254: mov r0,r4
 * 011ec256: blx 0x013fd730
 * 011ec25a: ldr r0,[sp,#0x4]
 * 011ec25c: ldr r1,[0x011ec2b0]
 * 011ec25e: add r1,pc
 * 011ec260: ldr r1,[r1,#0x0]
 * 011ec262: ldr r1,[r1,#0x0]
 * 011ec264: cmp r1,r0
 * 011ec266: it eq
 */


/* BroadcastCommandResult<EmptyModel>::extractCommandResult(Ecu*) const */

void BroadcastCommandResult<EmptyModel>::extractCommandResult(Ecu *param_1)

{
  int iVar1;
  uint uVar2;
  Result *pRVar3;
  Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
  *in_r1;
  undefined1 local_18 [4];
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
          ::isFail(in_r1);
  if (iVar1 == 0) {
    uVar2 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<EmptyModel,void>>>>
            ::__count_unique<Ecu*>((Ecu **)**(undefined4 **)(in_r1 + 0x1c));
    if (uVar2 == 0) {
      Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,-0xb);
    }
    else {
      pRVar3 = (Result *)FUN_011ede38(**(undefined4 **)(in_r1 + 0x1c),local_18);
      Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,pRVar3);
    }
    if (__stack_chk_guard == local_14) {
      return;
    }
  }
  else {
    Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,**(int **)(in_r1 + 0x18));
    if (__stack_chk_guard == local_14) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


