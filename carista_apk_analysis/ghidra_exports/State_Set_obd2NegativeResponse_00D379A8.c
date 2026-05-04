/*
 * State_Set_obd2NegativeResponse
 * ELF symbol address: 0x00D279A8
 * Ghidra address: 0x00D379A8 (ELF + 0x10000 image delta)
 * ELF symbol size: 160 bytes
 * Symbol: _ZN5State3Set20obd2NegativeResponseEv
 * Program: libCarista.so
 * Resolved function: State::Set::obd2NegativeResponse @ 00d379a8
 * Signature: undefined __stdcall obd2NegativeResponse(void)
 * Return type: undefined
 * Function body: [[00d379a8, 00d37a25]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e166c
 *   State::Set::obd2NegativeResponse @ 013fb660 -> COMPUTED_CALL from 013fb668
 * Direct callees/references:
 *   READ 00d37a30 from 00d379b2
 *   READ 014da87c from 00d379b6
 *   READ 015a7014 from 00d379b8
 *   WRITE Stack[-0x1c] from 00d379ba
 *   READ 00d37a34 from 00d379bc
 *   READ 014f1d7c from 00d379c0
 *   CONDITIONAL_JUMP State::Set::obd2NegativeResponse @ 00d379a8 from 00d379c8
 *   READ Stack[-0x1c] from 00d379ca
 *   READ 00d37a44 from 00d379cc
 *   READ 014da87c from 00d379d0
 *   READ 015a7014 from 00d379d2
 *   DATA 014f1d98 from 00d379d8
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d379e4
 *   PARAM 014f1d7c from 00d379ea
 *   UNCONDITIONAL_CALL __cxa_guard_acquire @ 013fd340 from 00d379ec
 *   CONDITIONAL_JUMP State::Set::obd2NegativeResponse @ 00d379a8 from 00d379f2
 *   READ 00d37a38 from 00d379f4
 *   PARAM 00c8f720 from 00d379fc
 *   UNCONDITIONAL_CALL <EXTERNAL>::__aeabi_memcpy8 @ 013fc860 from 00d379fe
 *   PARAM 014f1d98 from 00d37a0a
 *   UNCONDITIONAL_CALL State::Set::Set @ 01402fe0 from 00d37a0c
 *   READ 00d37a3c from 00d37a10
 *   PARAM 014f1d98 from 00d37a12
 *   READ 00d37a40 from 00d37a14
 *   PARAM 014371d0 from 00d37a18
 *   UNCONDITIONAL_CALL <EXTERNAL>::__cxa_atexit @ 013fa330 from 00d37a1a
 *   PARAM 014f1d7c from 00d37a1e
 *   UNCONDITIONAL_CALL __cxa_guard_release @ 013fd350 from 00d37a20
 *   UNCONDITIONAL_JUMP State::Set::obd2NegativeResponse @ 00d379a8 from 00d37a24
 */

/* Ghidra function: State::Set::obd2NegativeResponse @ 00d379a8 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d92b01f4878440068006811901d4e7e443079bff35b8fc007
 * 00d379a8: push {r4,r5,r6,r7,lr}
 * 00d379aa: add r7,sp,#0xc
 * 00d379ac: push.w r8
 * 00d379b0: sub sp,#0x48
 * 00d379b2: ldr r0,[0x00d37a30]
 * 00d379b4: add r0,pc
 * 00d379b6: ldr r0,[r0,#0x0]
 * 00d379b8: ldr r0,[r0,#0x0]
 * 00d379ba: str r0,[sp,#0x44]
 * 00d379bc: ldr r6,[0x00d37a34]
 * 00d379be: add r6,pc
 * 00d379c0: ldrb r0,[r6,#0x4]
 * 00d379c2: dmb #0x1b
 * 00d379c6: lsls r0,r0,#0x1f
 * 00d379c8: beq 0x00d379e8
 * 00d379ca: ldr r0,[sp,#0x44]
 * 00d379cc: ldr r1,[0x00d37a44]
 * 00d379ce: add r1,pc
 * 00d379d0: ldr r1,[r1,#0x0]
 * 00d379d2: ldr r1,[r1,#0x0]
 * 00d379d4: cmp r1,r0
 * 00d379d6: itttt eq
 * 00d379d8: add.eq.w r0,r6,#0x20
 * 00d379dc: add.eq sp,#0x48
 */


/* State::Set::obd2NegativeResponse() */

void State::Set::obd2NegativeResponse(void)

{
  int iVar1;
  undefined1 auStack_60 [68];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  DataMemoryBarrier(0x1b);
  if (((DAT_014f1d7c & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_014f1d7c), iVar1 != 0)) {
    __aeabi_memcpy8(auStack_60,&DAT_00c8f720,0x44);
    Set((Set *)&DAT_014f1d98,auStack_60,0x11);
    __cxa_atexit(0xd19aef,&DAT_014f1d98,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f1d7c);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


