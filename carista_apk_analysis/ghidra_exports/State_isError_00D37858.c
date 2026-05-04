/*
 * State_isError
 * ELF symbol address: 0x00D27858
 * Ghidra address: 0x00D37858 (ELF + 0x10000 image delta)
 * ELF symbol size: 4 bytes
 * Symbol: _ZN5State7isErrorEi
 * Program: libCarista.so
 * Resolved function: State::isError @ 00d37858
 * Signature: undefined __stdcall isError(int param_1)
 * Return type: undefined
 * Function body: [[00d37858, 00d3785b]]
 * Parameters:
 *   [0] int param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e12e4
 *   State::isError @ 013fa840 -> COMPUTED_CALL from 013fa848
 * Direct callees/references:
 *   <none recorded>
 */

/* Ghidra function: State::isError @ 00d37858 */

/* First instructions after recreation:
 * Memory bytes: c00f7047
 * 00d37858: lsrs r0,r0,#0x1f
 * 00d3785a: bx lr
 * 00d3785c: push {r4,r6,r7,lr}
 * 00d3785e: add r7,sp,#0x8
 * 00d37860: mov r4,r0
 * 00d37862: blx 0x01404a90
 * 00d37866: ldr r0,[0x00d37878]
 * 00d37868: mov r1,r4
 * 00d3786a: add r0,pc
 * 00d3786c: adds r0,#0xc
 * 00d3786e: pop.w {r4,r6,r7,lr}
 * 00d37872: b.w 0x013f8094
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
 */


/* State::isError(int) */

uint State::isError(int param_1)

{
  return (uint)param_1 >> 0x1f;
}


