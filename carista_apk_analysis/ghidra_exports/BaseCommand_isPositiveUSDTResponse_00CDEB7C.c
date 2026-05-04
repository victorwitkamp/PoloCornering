/*
 * BaseCommand_isPositiveUSDTResponse
 * ELF symbol address: 0x00CCEB7C
 * Ghidra address: 0x00CDEB7C (ELF + 0x10000 image delta)
 * ELF symbol size: 140 bytes
 * Symbol: _ZN11BaseCommand22isPositiveUSDTResponseERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_j
 * Program: libCarista.so
 * Resolved function: BaseCommand::isPositiveUSDTResponse @ 00cdeb7c
 * Signature: undefined __stdcall isPositiveUSDTResponse(vector * param_1, vector * param_2, uint param_3)
 * Return type: undefined
 * Function body: [[00cdeb7c, 00cdebf1]]
 * Parameters:
 *   [0] vector * param_1
 *   [1] vector * param_2
 *   [2] uint param_3
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e1e64
 *   BaseCommand::isPositiveUSDTResponse @ 013fd640 -> COMPUTED_CALL from 013fd648
 * Direct callees/references:
 *   READ 00cdec00 from 00cdeb88
 *   READ 014da87c from 00cdeb92
 *   READ 015a7014 from 00cdeb94
 *   WRITE Stack[-0x1c] from 00cdeb96
 *   UNCONDITIONAL_CALL FUN_00cdeb2c @ 00cdeb2c from 00cdeb9a
 *   UNCONDITIONAL_CALL Math::toExact<unsigned_char,unsigned_int> @ 013fd660 from 00cdeba2
 *   UNCONDITIONAL_CALL ByteUtils::subrange @ 013fd600 from 00cdebb2
 *   UNCONDITIONAL_CALL _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_ @ 013fd4e0 from 00cdebbc
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00cdebc2
 *   UNCONDITIONAL_CALL ByteUtils::startsWith @ 013fd670 from 00cdebca
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00cdebd2
 *   READ Stack[-0x1c] from 00cdebd6
 *   READ 00cdec04 from 00cdebd8
 *   READ 014da87c from 00cdebdc
 *   READ 015a7014 from 00cdebde
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cdebee
 */

/* Ghidra function: BaseCommand::isPositiveUSDTResponse @ 00cdeb7c */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d88b006461d4888460021784415460068006807903046fff7
 * 00cdeb7c: push {r4,r5,r6,r7,lr}
 * 00cdeb7e: add r7,sp,#0xc
 * 00cdeb80: push.w r8
 * 00cdeb84: sub sp,#0x20
 * 00cdeb86: mov r6,r0
 * 00cdeb88: ldr r0,[0x00cdec00]
 * 00cdeb8a: mov r8,r1
 * 00cdeb8c: movs r1,#0x0
 * 00cdeb8e: add r0,pc
 * 00cdeb90: mov r5,r2
 * 00cdeb92: ldr r0,[r0,#0x0]
 * 00cdeb94: ldr r0,[r0,#0x0]
 * 00cdeb96: str r0,[sp,#0x1c]
 * 00cdeb98: mov r0,r6
 * 00cdeb9a: bl 0x00cdeb2c
 * 00cdeb9e: ldrb r0,[r0,#0x0]
 * 00cdeba0: adds r0,#0x40
 * 00cdeba2: blx 0x013fd660
 * 00cdeba6: subs r3,r5,#0x1
 * 00cdeba8: add r5,sp,#0x4
 * 00cdebaa: mov r4,r0
 * 00cdebac: mov r1,r6
 * 00cdebae: mov r0,r5
 * 00cdebb0: movs r2,#0x1
 */


/* BaseCommand::isPositiveUSDTResponse(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, unsigned int) */

void BaseCommand::isPositiveUSDTResponse(vector *param_1,vector *param_2,uint param_3)

{
  uchar uVar1;
  byte *pbVar2;
  vector *extraout_r2;
  ByteUtils aBStack_34 [12];
  vector avStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pbVar2 = (byte *)FUN_00cdeb2c(param_1,0);
  uVar1 = Math::toExact<unsigned_char,unsigned_int>(*pbVar2 + 0x40);
  ByteUtils::subrange(aBStack_34,param_1,1,param_3 - 1);
  _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_
            (avStack_28,uVar1,aBStack_34);
  FUN_00cb7f50(aBStack_34);
  ByteUtils::startsWith((ByteUtils *)param_2,avStack_28,extraout_r2);
  FUN_00cb7f50(avStack_28);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


