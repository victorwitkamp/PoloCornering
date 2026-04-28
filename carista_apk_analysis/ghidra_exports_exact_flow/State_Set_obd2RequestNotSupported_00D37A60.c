/*
 * State_Set_obd2RequestNotSupported
 * ELF symbol address: 0x00D27A60
 * Ghidra address: 0x00D37A60 (ELF + 0x10000 image delta)
 * ELF symbol size: 164 bytes
 * Symbol: _ZN5State3Set23obd2RequestNotSupportedEv
 * Program: libCarista.so
 * Resolved function: State::Set::obd2RequestNotSupported @ 00d37a60
 * Signature: undefined __stdcall obd2RequestNotSupported(void)
 * Return type: undefined
 * Function body: [[00d37a60, 00d37ae3]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e275c
 *   State::Set::obd2RequestNotSupported @ 013ffa20 -> COMPUTED_CALL from 013ffa28
 * Direct callees/references:
 *   READ 00d37af0 from 00d37a6a
 *   READ 014da87c from 00d37a6e
 *   READ 015a7014 from 00d37a70
 *   WRITE Stack[-0x1c] from 00d37a72
 *   READ 00d37af4 from 00d37a74
 *   READ 014f1d80 from 00d37a78
 *   CONDITIONAL_JUMP State::Set::obd2RequestNotSupported @ 00d37a60 from 00d37a80
 *   READ Stack[-0x1c] from 00d37a82
 *   READ 00d37b00 from 00d37a84
 *   READ 014da87c from 00d37a88
 *   READ 015a7014 from 00d37a8a
 *   DATA 014f1dac from 00d37a90
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d37a9c
 *   PARAM 014f1d80 from 00d37aa4
 *   UNCONDITIONAL_CALL __cxa_guard_acquire @ 013fd340 from 00d37aa6
 *   CONDITIONAL_JUMP State::Set::obd2RequestNotSupported @ 00d37a60 from 00d37aac
 *   WRITE Stack[-0x20] from 00d37ab2
 *   WRITE Stack[-0x24] from 00d37ab8
 *   WRITE Stack[-0x28] from 00d37abe
 *   PARAM 014f1dac from 00d37ac8
 *   UNCONDITIONAL_CALL State::Set::Set @ 01402fe0 from 00d37aca
 *   READ 00d37af8 from 00d37ace
 *   PARAM 014f1dac from 00d37ad0
 *   READ 00d37afc from 00d37ad2
 *   PARAM 014371d0 from 00d37ad6
 *   UNCONDITIONAL_CALL <EXTERNAL>::__cxa_atexit @ 013fa330 from 00d37ad8
 *   PARAM 014f1d80 from 00d37adc
 *   UNCONDITIONAL_CALL __cxa_guard_release @ 013fd350 from 00d37ade
 *   UNCONDITIONAL_JUMP State::Set::obd2RequestNotSupported @ 00d37a60 from 00d37ae2
 */

/* Ghidra function: State::Set::obd2RequestNotSupported @ 00d37a60 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd84b0214878440068006803901f4e7e44307abff35b8fc007
 * 00d37a60: push {r4,r5,r6,r7,lr}
 * 00d37a62: add r7,sp,#0xc
 * 00d37a64: push.w r11
 * 00d37a68: sub sp,#0x10
 * 00d37a6a: ldr r0,[0x00d37af0]
 * 00d37a6c: add r0,pc
 * 00d37a6e: ldr r0,[r0,#0x0]
 * 00d37a70: ldr r0,[r0,#0x0]
 * 00d37a72: str r0,[sp,#0xc]
 * 00d37a74: ldr r6,[0x00d37af4]
 * 00d37a76: add r6,pc
 * 00d37a78: ldrb r0,[r6,#0x8]
 * 00d37a7a: dmb #0x1b
 * 00d37a7e: lsls r0,r0,#0x1f
 * 00d37a80: beq 0x00d37aa0
 * 00d37a82: ldr r0,[sp,#0xc]
 * 00d37a84: ldr r1,[0x00d37b00]
 * 00d37a86: add r1,pc
 * 00d37a88: ldr r1,[r1,#0x0]
 * 00d37a8a: ldr r1,[r1,#0x0]
 * 00d37a8c: cmp r1,r0
 * 00d37a8e: itttt eq
 * 00d37a90: add.eq.w r0,r6,#0x34
 * 00d37a94: add.eq sp,#0x10
 */


/* State::Set::obd2RequestNotSupported() */

void State::Set::obd2RequestNotSupported(void)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  DataMemoryBarrier(0x1b);
  if (((DAT_014f1d80 & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_014f1d80), iVar1 != 0)) {
    local_20 = 0xffffffd8;
    local_24 = 0xffffffd9;
    local_28 = 0xffffffda;
    Set((Set *)&DAT_014f1dac,&local_28,3);
    __cxa_atexit(0xd19aef,&DAT_014f1dac,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f1d80);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


