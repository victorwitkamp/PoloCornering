/*
 * State_Set_fatalError
 * ELF symbol address: 0x00D2787C
 * Ghidra address: 0x00D3787C (ELF + 0x10000 image delta)
 * ELF symbol size: 184 bytes
 * Symbol: _ZN5State3Set10fatalErrorEv
 * Program: libCarista.so
 * Resolved function: State::Set::fatalError @ 00d3787c
 * Signature: undefined __stdcall fatalError(void)
 * Return type: undefined
 * Function body: [[00d3787c, 00d37905]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3b78
 *   State::Set::fatalError @ 01404a90 -> COMPUTED_CALL from 01404a98
 * Direct callees/references:
 *   READ 00d37914 from 00d37886
 *   READ 014da87c from 00d3788a
 *   READ 015a7014 from 00d3788c
 *   WRITE Stack[-0x1c] from 00d3788e
 *   READ 00d37918 from 00d37890
 *   READ 014f1d78 from 00d37894
 *   CONDITIONAL_JUMP State::Set::fatalError @ 00d3787c from 00d3789c
 *   READ Stack[-0x1c] from 00d3789e
 *   READ 00d3792c from 00d378a0
 *   READ 014da87c from 00d378a4
 *   READ 015a7014 from 00d378a6
 *   DATA 014f1d84 from 00d378ac
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d378b8
 *   READ 00d3791c from 00d378bc
 *   PARAM 014f1d78 from 00d378c0
 *   UNCONDITIONAL_CALL __cxa_guard_acquire @ 013fd340 from 00d378c2
 *   CONDITIONAL_JUMP State::Set::fatalError @ 00d3787c from 00d378c8
 *   READ 00d37920 from 00d378ca
 *   READ 00c8f700 from 00d378d4
 *   READ 00c8f708 from 00d378d4
 *   WRITE Stack[-0x38] from 00d378d8
 *   READ 00c8f70c from 00d378dc
 *   READ 00c8f714 from 00d378dc
 *   WRITE Stack[-0x2c] from 00d378e0
 *   PARAM 014f1d84 from 00d378ea
 *   UNCONDITIONAL_CALL State::Set::Set @ 01402fe0 from 00d378ec
 *   READ 00d37924 from 00d378f0
 *   PARAM 014f1d84 from 00d378f2
 *   READ 00d37928 from 00d378f4
 *   PARAM 014371d0 from 00d378f8
 *   UNCONDITIONAL_CALL <EXTERNAL>::__cxa_atexit @ 013fa330 from 00d378fa
 *   PARAM 014f1d78 from 00d378fe
 *   UNCONDITIONAL_CALL __cxa_guard_release @ 013fd350 from 00d37900
 *   UNCONDITIONAL_JUMP State::Set::fatalError @ 00d3787c from 00d37904
 */

/* Ghidra function: State::Set::fatalError @ 00d3787c */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd88b023487844006800680790214e7e443078bff35b8fc007
 * 00d3787c: push {r4,r5,r6,r7,lr}
 * 00d3787e: add r7,sp,#0xc
 * 00d37880: push.w r11
 * 00d37884: sub sp,#0x20
 * 00d37886: ldr r0,[0x00d37914]
 * 00d37888: add r0,pc
 * 00d3788a: ldr r0,[r0,#0x0]
 * 00d3788c: ldr r0,[r0,#0x0]
 * 00d3788e: str r0,[sp,#0x1c]
 * 00d37890: ldr r6,[0x00d37918]
 * 00d37892: add r6,pc
 * 00d37894: ldrb r0,[r6,#0x0]
 * 00d37896: dmb #0x1b
 * 00d3789a: lsls r0,r0,#0x1f
 * 00d3789c: beq 0x00d378bc
 * 00d3789e: ldr r0,[sp,#0x1c]
 * 00d378a0: ldr r1,[0x00d3792c]
 * 00d378a2: add r1,pc
 * 00d378a4: ldr r1,[r1,#0x0]
 * 00d378a6: ldr r1,[r1,#0x0]
 * 00d378a8: cmp r1,r0
 * 00d378aa: itttt eq
 * 00d378ac: add.eq.w r0,r6,#0xc
 * 00d378b0: add.eq sp,#0x20
 */


/* State::Set::fatalError() */

void State::Set::fatalError(void)

{
  int iVar1;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined8 uStack_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  DataMemoryBarrier(0x1b);
  if (((DAT_014f1d78 & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_014f1d78), iVar1 != 0)) {
    local_38 = 0xfffffffffffffff4;
    uStack_30 = 0xfffffff9;
    local_2c = 0xfffffffc;
    uStack_28 = 0xfffffff0;
    uStack_24 = 0xfffffc18ffffffcd;
    Set((Set *)&DAT_014f1d84,&local_38,7);
    __cxa_atexit(0xd19aef,&DAT_014f1d84,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f1d78);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


