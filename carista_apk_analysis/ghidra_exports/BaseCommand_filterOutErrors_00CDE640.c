/*
 * BaseCommand_filterOutErrors
 * ELF symbol address: 0x00CCE640
 * Ghidra address: 0x00CDE640 (ELF + 0x10000 image delta)
 * ELF symbol size: 156 bytes
 * Symbol: _ZN11BaseCommand15filterOutErrorsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE
 * Program: libCarista.so
 * Resolved function: BaseCommand::filterOutErrors @ 00cde640
 * Signature: undefined __thiscall filterOutErrors(BaseCommand * this, vector * param_1)
 * Return type: undefined
 * Function body: [[00cde640, 00cde6c5]]
 * Parameters:
 *   [0] BaseCommand * this
 *   [1] vector * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e1e24
 *   BaseCommand::filterOutErrors @ 013fd540 -> COMPUTED_CALL from 013fd548
 * Direct callees/references:
 *   READ 00cde6d4 from 00cde64c
 *   READ 014da87c from 00cde652
 *   READ 015a7014 from 00cde654
 *   WRITE Stack[-0x1c] from 00cde656
 *   UNCONDITIONAL_CALL FUN_00cde6f4 @ 00cde6f4 from 00cde65a
 *   CONDITIONAL_JUMP BaseCommand::filterOutErrors @ 00cde640 from 00cde668
 *   UNCONDITIONAL_CALL BaseCommand::extractState @ 013fd5b0 from 00cde66c
 *   CONDITIONAL_JUMP BaseCommand::filterOutErrors @ 00cde640 from 00cde672
 *   READ Stack[-0x24] from 00cde674
 *   UNCONDITIONAL_CALL FUN_00cde724 @ 00cde724 from 00cde678
 *   UNCONDITIONAL_JUMP BaseCommand::filterOutErrors @ 00cde640 from 00cde67c
 *   UNCONDITIONAL_JUMP BaseCommand::filterOutErrors @ 00cde640 from 00cde688
 *   READ Stack[-0x24] from 00cde68a
 *   CONDITIONAL_JUMP BaseCommand::filterOutErrors @ 00cde640 from 00cde692
 *   UNCONDITIONAL_CALL Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>::done @ 013fd580 from 00cde698
 *   UNCONDITIONAL_JUMP BaseCommand::filterOutErrors @ 00cde640 from 00cde69c
 *   UNCONDITIONAL_CALL Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>::Result @ 013fd590 from 00cde6a2
 *   UNCONDITIONAL_CALL FUN_00cde818 @ 00cde818 from 00cde6a8
 *   READ Stack[-0x1c] from 00cde6ac
 *   READ 00cde6d8 from 00cde6ae
 *   READ 014da87c from 00cde6b2
 *   READ 015a7014 from 00cde6b4
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cde6c2
 */

/* Ghidra function: BaseCommand::filterOutErrors @ 00cde640 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d84b0804621480d46784400680068039001a800f04bf8d5e9
 * 00cde640: push {r4,r5,r6,r7,lr}
 * 00cde642: add r7,sp,#0xc
 * 00cde644: push.w r8
 * 00cde648: sub sp,#0x10
 * 00cde64a: mov r8,r0
 * 00cde64c: ldr r0,[0x00cde6d4]
 * 00cde64e: mov r5,r1
 * 00cde650: add r0,pc
 * 00cde652: ldr r0,[r0,#0x0]
 * 00cde654: ldr r0,[r0,#0x0]
 * 00cde656: str r0,[sp,#0xc]
 * 00cde658: add r0,sp,#0x4
 * 00cde65a: bl 0x00cde6f4
 * 00cde65e: ldrd r6,r4,[r5,#0x0]
 * 00cde662: mvn r5,#0x5
 * 00cde666: cmp r6,r4
 * 00cde668: beq 0x00cde68a
 * 00cde66a: mov r0,r6
 * 00cde66c: blx 0x013fd5b0
 * 00cde670: cmp r0,#0x1
 * 00cde672: bne 0x00cde67e
 * 00cde674: ldr r0,[sp,#0x4]
 * 00cde676: mov r1,r6
 * 00cde678: bl 0x00cde724
 */


/* BaseCommand::filterOutErrors(std::__ndk1::vector<std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> >, std::__ndk1::allocator<std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > > > const&) */

void __thiscall BaseCommand::filterOutErrors(BaseCommand *this,vector *param_1)

{
  int iVar1;
  vector *pvVar2;
  int iVar3;
  vector *pvVar4;
  int *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_00cde6f4(local_24);
  pvVar2 = *(vector **)(param_1 + 4);
  iVar3 = -6;
  for (pvVar4 = *(vector **)param_1; pvVar4 != pvVar2; pvVar4 = pvVar4 + 0xc) {
    iVar1 = extractState(pvVar4);
    if (iVar1 == 1) {
      FUN_00cde724(local_24[0],pvVar4);
    }
    else if (iVar3 != -0x16) {
      iVar3 = iVar1;
    }
  }
  if (*local_24[0] == local_24[0][1]) {
    Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
    ::Result((Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
              *)this,iVar3);
  }
  else {
    Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
    ::done((Result<std::__ndk1::vector<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::allocator<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>,void>
            *)this,(shared_ptr *)local_24);
  }
  FUN_00cde818(local_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


