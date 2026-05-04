/*
 * VagCanCommunicator_getTimeoutSpec
 * ELF symbol address: 0x00D18BD8
 * Ghidra address: 0x00D28BD8 (ELF + 0x10000 image delta)
 * ELF symbol size: 188 bytes
 * Symbol: _ZN18VagCanCommunicator14getTimeoutSpecEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::getTimeoutSpec @ 00d28bd8
 * Signature: undefined __stdcall getTimeoutSpec(void)
 * Return type: undefined
 * Function body: [[00d28bd8, 00d28c61]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143dac4
 * Direct callees/references:
 *   READ 00d28c78 from 00d28be2
 *   READ 014da87c from 00d28be6
 *   READ 015a7014 from 00d28be8
 *   WRITE Stack[-0x1c] from 00d28bea
 *   READ 00d28c7c from 00d28bec
 *   READ 014f1bcc from 00d28bf0
 *   CONDITIONAL_JUMP VagCanCommunicator::getTimeoutSpec @ 00d28bd8 from 00d28bf8
 *   READ Stack[-0x1c] from 00d28bfa
 *   READ 00d28c8c from 00d28bfc
 *   READ 014da87c from 00d28c00
 *   READ 015a7014 from 00d28c02
 *   DATA 014f1be8 from 00d28c08
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d28c14
 *   READ 00d28c80 from 00d28c18
 *   PARAM 014f1bcc from 00d28c1c
 *   UNCONDITIONAL_CALL __cxa_guard_acquire @ 013fd340 from 00d28c1e
 *   CONDITIONAL_JUMP VagCanCommunicator::getTimeoutSpec @ 00d28bd8 from 00d28c24
 *   WRITE Stack[-0x20] from 00d28c28
 *   UNCONDITIONAL_CALL FUN_00d18358 @ 00d18358 from 00d28c30
 *   PARAM 014f1be8 from 00d28c3e
 *   UNCONDITIONAL_CALL Communicator::TimeoutSpec::TimeoutSpec @ 01402980 from 00d28c40
 *   UNCONDITIONAL_CALL FUN_00d183d8 @ 00d183d8 from 00d28c46
 *   READ 00d28c84 from 00d28c4a
 *   PARAM 014f1be8 from 00d28c4c
 *   READ 00d28c88 from 00d28c4e
 *   PARAM 014371d0 from 00d28c52
 *   READ 014db3d4 from 00d28c54
 *   PARAM Communicator::TimeoutSpec::~TimeoutSpec @ 00d18410 from 00d28c54
 *   UNCONDITIONAL_CALL <EXTERNAL>::__cxa_atexit @ 013fa330 from 00d28c56
 *   PARAM 014f1bcc from 00d28c5a
 *   UNCONDITIONAL_CALL __cxa_guard_release @ 013fd350 from 00d28c5c
 *   UNCONDITIONAL_JUMP VagCanCommunicator::getTimeoutSpec @ 00d28bd8 from 00d28c60
 */

/* Ghidra function: VagCanCommunicator::getTimeoutSpec @ 00d28bd8 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd86b025487844006800680590234e7e443078bff35b8fc007
 * 00d28bd8: push {r4,r5,r6,r7,lr}
 * 00d28bda: add r7,sp,#0xc
 * 00d28bdc: push.w r11
 * 00d28be0: sub sp,#0x18
 * 00d28be2: ldr r0,[0x00d28c78]
 * 00d28be4: add r0,pc
 * 00d28be6: ldr r0,[r0,#0x0]
 * 00d28be8: ldr r0,[r0,#0x0]
 * 00d28bea: str r0,[sp,#0x14]
 * 00d28bec: ldr r6,[0x00d28c7c]
 * 00d28bee: add r6,pc
 * 00d28bf0: ldrb r0,[r6,#0x0]
 * 00d28bf2: dmb #0x1b
 * 00d28bf6: lsls r0,r0,#0x1f
 * 00d28bf8: beq 0x00d28c18
 * 00d28bfa: ldr r0,[sp,#0x14]
 * 00d28bfc: ldr r1,[0x00d28c8c]
 * 00d28bfe: add r1,pc
 * 00d28c00: ldr r1,[r1,#0x0]
 * 00d28c02: ldr r1,[r1,#0x0]
 * 00d28c04: cmp r1,r0
 * 00d28c06: itttt eq
 * 00d28c08: add.eq.w r0,r6,#0x1c
 * 00d28c0c: add.eq sp,#0x18
 */


/* VagCanCommunicator::getTimeoutSpec() */

void VagCanCommunicator::getTimeoutSpec(void)

{
  int iVar1;
  vector avStack_2c [12];
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  DataMemoryBarrier(0x1b);
  if (((DAT_014f1bcc & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_014f1bcc), iVar1 != 0)) {
    local_20 = 0;
    FUN_00d18358(avStack_2c,&local_20,1);
    Communicator::TimeoutSpec::TimeoutSpec((TimeoutSpec *)&DAT_014f1be8,0,avStack_2c,0);
    FUN_00d183d8(avStack_2c);
    __cxa_atexit(Communicator::TimeoutSpec::~TimeoutSpec,&DAT_014f1be8,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f1bcc);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


