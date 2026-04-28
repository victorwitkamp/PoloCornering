/*
 * State_isFatalError
 * ELF symbol address: 0x00D2785C
 * Ghidra address: 0x00D3785C (ELF + 0x10000 image delta)
 * ELF symbol size: 32 bytes
 * Symbol: _ZN5State12isFatalErrorEi
 * Program: libCarista.so
 * Resolved function: State::isFatalError @ 00d3785c
 * Signature: undefined __stdcall isFatalError(int param_1)
 * Return type: undefined
 * Function body: [[00d3785c, 00d37875]]
 * Parameters:
 *   [0] int param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e1674
 *   State::isFatalError @ 013fb680 -> COMPUTED_CALL from 013fb688
 * Direct callees/references:
 *   UNCONDITIONAL_CALL State::Set::fatalError @ 01404a90 from 00d37862
 *   READ 00d37878 from 00d37866
 *   DATA Stack[-0x8] from 00d3786e
 *   UNCONDITIONAL_JUMP Result<VagUdsRoutineStateModel,void>::isIn @ 012dc0b4 from 00d37872
 */

/* Ghidra function: State::isFatalError @ 00d3785c */

/* First instructions after recreation:
 * Memory bytes: d0b502af0446cdf216e10448214678440c30bde8d040c0f20fb400bf0aa57b00
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
 * 00d37896: dmb #0x1b
 * 00d3789a: lsls r0,r0,#0x1f
 */


/* State::isFatalError(int) */

void State::isFatalError(int param_1)

{
  Set::fatalError();
  Set::contains(0x14f1d84);
  return;
}


