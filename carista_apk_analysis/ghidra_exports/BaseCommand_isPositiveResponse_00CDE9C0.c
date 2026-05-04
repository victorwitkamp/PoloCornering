/*
 * BaseCommand_isPositiveResponse
 * ELF symbol address: 0x00CCE9C0
 * Ghidra address: 0x00CDE9C0 (ELF + 0x10000 image delta)
 * ELF symbol size: 30 bytes
 * Symbol: _ZN11BaseCommand18isPositiveResponseERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_j
 * Program: libCarista.so
 * Resolved function: BaseCommand::isPositiveResponse @ 00cde9c0
 * Signature: undefined __stdcall isPositiveResponse(vector * param_1, vector * param_2, uint param_3)
 * Return type: undefined
 * Function body: [[00cde9c0, 00cde9dd] [013f7f5c, 013f7f67]]
 * Parameters:
 *   [0] vector * param_1
 *   [1] vector * param_2
 *   [2] uint param_3
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e1e50
 *   BaseCommand::isPositiveResponse @ 013fd5f0 -> COMPUTED_CALL from 013fd5f8
 * Direct callees/references:
 *   UNCONDITIONAL_CALL BaseCommand::isPositiveUSDTResponse @ 013fd640 from 00cde9c8
 *   CONDITIONAL_JUMP BaseCommand::isPositiveResponse @ 00cde9c0 from 00cde9cc
 *   DATA Stack[-0x8] from 00cde9d6
 *   UNCONDITIONAL_JUMP BaseCommand::isPositiveResponse @ 00cde9c0 from 00cde9da
 *   COMPUTED_JUMP 013fd650 from 013f7f66
 */

/* Ghidra function: BaseCommand::isPositiveResponse @ 00cde9c0 */

/* First instructions after recreation:
 * Memory bytes: b0b502af0c4605461ef33ae608b10120b0bd28462146bde8b04019f3bfb2
 * 00cde9c0: push {r4,r5,r7,lr}
 * 00cde9c2: add r7,sp,#0x8
 * 00cde9c4: mov r4,r1
 * 00cde9c6: mov r5,r0
 * 00cde9c8: blx 0x013fd640
 * 00cde9cc: cbz r0,0x00cde9d2
 * 00cde9ce: movs r0,#0x1
 * 00cde9d0: pop {r4,r5,r7,pc}
 * 00cde9d2: mov r0,r5
 * 00cde9d4: mov r1,r4
 * 00cde9d6: pop.w {r4,r5,r7,lr}
 * 00cde9da: b.w 0x013f7f5c
 * 00cde9e0: push {r4,r5,r6,r7,lr}
 * 00cde9e2: add r7,sp,#0xc
 * 00cde9e4: push.w r11
 * 00cde9e8: sub sp,#0x18
 * 00cde9ea: mov r4,r0
 * 00cde9ec: ldr r0,[0x00cdea38]
 * 00cde9ee: add r0,pc
 * 00cde9f0: ldr r0,[r0,#0x0]
 * 00cde9f2: ldr r0,[r0,#0x0]
 * 00cde9f4: str r0,[sp,#0x14]
 * 00cde9f6: movs r0,#0x0
 * 00cde9f8: strd r0,r0,[sp,#0xc]
 */


/* BaseCommand::isPositiveResponse(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, unsigned int) */

undefined4 BaseCommand::isPositiveResponse(vector *param_1,vector *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = isPositiveUSDTResponse(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = isPositiveUUDTResponse(param_1,param_2);
    return uVar2;
  }
  return 1;
}


