/*
 * WriteDataByIdentifierCommand_getRequest
 * ELF symbol address: 0x00CF80B4
 * Ghidra address: 0x00D080B4 (ELF + 0x10000 image delta)
 * ELF symbol size: 120 bytes
 * Symbol: _ZNK28WriteDataByIdentifierCommand10getRequestEv
 * Program: libCarista.so
 * Resolved function: WriteDataByIdentifierCommand::getRequest @ 00d080b4
 * Signature: undefined __stdcall getRequest(void)
 * Return type: undefined
 * Function body: [[00d080b4, 00d08111]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 01439458
 *   <no function> -> DATA from 0143bcb0
 * Direct callees/references:
 *   READ 00d08124 from 00d080c0
 *   READ 014da87c from 00d080c6
 *   READ 015a7014 from 00d080c8
 *   WRITE Stack[-0x1c] from 00d080ca
 *   UNCONDITIONAL_CALL ByteUtils::getBytesFromShort @ 013fdc40 from 00d080d2
 *   UNCONDITIONAL_CALL _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_ @ 013fd4e0 from 00d080dc
 *   UNCONDITIONAL_CALL operator+ @ 013fd460 from 00d080e8
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d080ee
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d080f4
 *   READ Stack[-0x1c] from 00d080f8
 *   READ 00d08128 from 00d080fa
 *   READ 014da87c from 00d080fe
 *   READ 015a7014 from 00d08100
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d0810e
 */

/* Ghidra function: WriteDataByIdentifierCommand::getRequest @ 00d080b4 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd88b0044618480d467844006800680790098a01ae3046f5f2
 * 00d080b4: push {r4,r5,r6,r7,lr}
 * 00d080b6: add r7,sp,#0xc
 * 00d080b8: push.w r11
 * 00d080bc: sub sp,#0x20
 * 00d080be: mov r4,r0
 * 00d080c0: ldr r0,[0x00d08124]
 * 00d080c2: mov r5,r1
 * 00d080c4: add r0,pc
 * 00d080c6: ldr r0,[r0,#0x0]
 * 00d080c8: ldr r0,[r0,#0x0]
 * 00d080ca: str r0,[sp,#0x1c]
 * 00d080cc: ldrh r1,[r1,#0x10]
 * 00d080ce: add r6,sp,#0x4
 * 00d080d0: mov r0,r6
 * 00d080d2: blx 0x013fdc40
 * 00d080d6: add r0,sp,#0x10
 * 00d080d8: movs r1,#0x2e
 * 00d080da: mov r2,r6
 * 00d080dc: blx 0x013fd4e0
 * 00d080e0: add.w r2,r5,#0x14
 * 00d080e4: add r1,sp,#0x10
 * 00d080e6: mov r0,r4
 * 00d080e8: blx 0x013fd460
 * 00d080ec: add r0,sp,#0x10
 */


/* WriteDataByIdentifierCommand::getRequest() const */

void WriteDataByIdentifierCommand::getRequest(void)

{
  vector *in_r0;
  int in_r1;
  ByteUtils aBStack_34 [12];
  vector avStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  ByteUtils::getBytesFromShort(aBStack_34,*(ushort *)(in_r1 + 0x10));
  _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_
            (avStack_28,0x2e,aBStack_34);
  operator+(in_r0,avStack_28);
  FUN_00cb7f50(avStack_28);
  FUN_00cb7f50(aBStack_34);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


