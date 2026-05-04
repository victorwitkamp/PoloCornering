/*
 * SingleResponseCommand_EmptyModel_processResponses
 * ELF symbol address: 0x00CD1078
 * Ghidra address: 0x00CE1078 (ELF + 0x10000 image delta)
 * ELF symbol size: 148 bytes
 * Symbol: _ZNK21SingleResponseCommandI10EmptyModelE16processResponsesERKNSt6__ndk16vectorINS3_IhNS2_9allocatorIhEEEENS4_IS6_EEEE
 * Program: libCarista.so
 * Resolved function: SingleResponseCommand<EmptyModel>::processResponses @ 00ce1078
 * Signature: undefined __thiscall processResponses(SingleResponseCommand<EmptyModel> * this, vector * param_1)
 * Return type: undefined
 * Function body: [[00ce1078, 00ce10f7]]
 * Parameters:
 *   [0] SingleResponseCommand<EmptyModel> * this
 *   [1] vector * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 01438b8c
 *   <no function> -> DATA from 01438bc8
 *   <no function> -> DATA from 01438bec
 *   <no function> -> DATA from 01438ecc
 *   <no function> -> DATA from 01438efc
 *   <no function> -> DATA from 01438f2c
 *   <no function> -> DATA from 01438f5c
 *   <no function> -> DATA from 01439404
 *   <no function> -> DATA from 01439434
 *   <no function> -> DATA from 01439464
 *   <no function> -> DATA from 01439494
 *   <no function> -> DATA from 0143969c
 *   <no function> -> DATA from 01439e38
 *   <no function> -> DATA from 01439e68
 *   <no function> -> DATA from 01439f94
 *   <no function> -> DATA from 01439fc4
 *   <no function> -> DATA from 0143ad0c
 *   <no function> -> DATA from 0143ad3c
 *   <no function> -> DATA from 0143ad6c
 *   <no function> -> DATA from 0143aeb4
 *   <no function> -> DATA from 0143aee4
 *   <no function> -> DATA from 0143af14
 *   <no function> -> DATA from 0143b4bc
 *   <no function> -> DATA from 0143b4ec
 *   <no function> -> DATA from 0143b648
 *   <no function> -> DATA from 0143b6d8
 *   <no function> -> DATA from 0143b708
 *   <no function> -> DATA from 0143b768
 *   <no function> -> DATA from 0143b798
 *   <no function> -> DATA from 0143b7c8
 *   <no function> -> DATA from 0143b7f8
 *   <no function> -> DATA from 0143b828
 *   <no function> -> DATA from 0143b8b8
 *   <no function> -> DATA from 0143badc
 *   <no function> -> DATA from 0143bb0c
 *   <no function> -> DATA from 0143bb3c
 *   <no function> -> DATA from 0143bb6c
 *   <no function> -> DATA from 0143bb9c
 *   <no function> -> DATA from 0143bbcc
 *   <no function> -> DATA from 0143bc2c
 *   <no function> -> DATA from 0143bc5c
 *   <no function> -> DATA from 0143bcbc
 *   <no function> -> DATA from 0143c2cc
 *   <no function> -> DATA from 0143c3ec
 *   <no function> -> DATA from 0143c41c
 *   <no function> -> DATA from 0143c44c
 *   <no function> -> DATA from 0143c47c
 *   <no function> -> DATA from 0143c4dc
 *   <no function> -> DATA from 0143c50c
 *   <no function> -> DATA from 0143c53c
 *   <no function> -> DATA from 0143c56c
 *   <no function> -> DATA from 0143c59c
 *   <no function> -> DATA from 0143c5cc
 *   <no function> -> DATA from 0143cbc0
 *   <no function> -> DATA from 0143cbf0
 *   <no function> -> DATA from 0143cc20
 *   <no function> -> DATA from 0143cc50
 *   <no function> -> DATA from 0143cc80
 *   <no function> -> DATA from 0143ccb0
 *   <no function> -> DATA from 0143cd40
 * Direct callees/references:
 *   READ 00ce1104 from 00ce1084
 *   READ 014da87c from 00ce108c
 *   READ 015a7014 from 00ce108e
 *   WRITE Stack[-0x1c] from 00ce1090
 *   UNCONDITIONAL_CALL Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>::isFail @ 013fd550 from 00ce109c
 *   CONDITIONAL_JUMP SingleResponseCommand<EmptyModel>::processResponses @ 00ce1078 from 00ce10a0
 *   UNCONDITIONAL_CALL Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>::stateAs<EmptyModel,void> @ 013fd710 from 00ce10a6
 *   UNCONDITIONAL_JUMP SingleResponseCommand<EmptyModel>::processResponses @ 00ce1078 from 00ce10aa
 *   READ Stack[-0x24] from 00ce10ac
 *   CONDITIONAL_JUMP SingleResponseCommand<EmptyModel>::processResponses @ 00ce1078 from 00ce10b8
 *   UNCONDITIONAL_CALL FUN_00cdf7a0 @ 00cdf7a0 from 00ce10bc
 *   UNCONDITIONAL_JUMP SingleResponseCommand<EmptyModel>::processResponses @ 00ce1078 from 00ce10cc
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 013fd730 from 00ce10d4
 *   UNCONDITIONAL_CALL Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>::~Result @ 013fd5a0 from 00ce10da
 *   READ Stack[-0x1c] from 00ce10de
 *   READ 00ce1108 from 00ce10e0
 *   READ 014da87c from 00ce10e4
 *   READ 015a7014 from 00ce10e6
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00ce10f4
 */

/* Ghidra function: SingleResponseCommand<EmptyModel>::processResponses @ 00ce1078 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd8ab004461f486e460d4678440068006809900868c3683046
 * 00ce1078: push {r4,r5,r6,r7,lr}
 * 00ce107a: add r7,sp,#0xc
 * 00ce107c: push.w r11
 * 00ce1080: sub sp,#0x28
 * 00ce1082: mov r4,r0
 * 00ce1084: ldr r0,[0x00ce1104]
 * 00ce1086: mov r6,sp
 * 00ce1088: mov r5,r1
 * 00ce108a: add r0,pc
 * 00ce108c: ldr r0,[r0,#0x0]
 * 00ce108e: ldr r0,[r0,#0x0]
 * 00ce1090: str r0,[sp,#0x24]
 * 00ce1092: ldr r0,[r1,#0x0]
 * 00ce1094: ldr r3,[r0,#0xc]
 * 00ce1096: mov r0,r6
 * 00ce1098: blx r3
 * 00ce109a: mov r0,r6
 * 00ce109c: blx 0x013fd550
 * 00ce10a0: cbz r0,0x00ce10ac
 * 00ce10a2: mov r1,sp
 * 00ce10a4: mov r0,r4
 * 00ce10a6: blx 0x013fd710
 * 00ce10aa: b 0x00ce10d8
 * 00ce10ac: ldr r0,[sp,#0x1c]
 */


/* SingleResponseCommand<EmptyModel>::processResponses(std::__ndk1::vector<std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> >,
   std::__ndk1::allocator<std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   > > const&) const */

void __thiscall
SingleResponseCommand<EmptyModel>::processResponses
          (SingleResponseCommand<EmptyModel> *this,vector *param_1)

{
  int iVar1;
  undefined4 uVar2;
  Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
  aRStack_40 [28];
  int *local_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0xc))(aRStack_40);
  iVar1 = Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
          ::isFail(aRStack_40);
  if (iVar1 == 0) {
    local_24 = (int *)*local_24;
    if (local_24[1] - *local_24 == 0xc) {
      uVar2 = FUN_00cdf7a0(local_24,0);
      (**(code **)(*(int *)param_1 + 0x18))(this,param_1,uVar2);
    }
    else {
      Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)this,-6);
    }
  }
  else {
    Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
    ::stateAs<EmptyModel,void>();
  }
  Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
  ::~Result(aRStack_40);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


