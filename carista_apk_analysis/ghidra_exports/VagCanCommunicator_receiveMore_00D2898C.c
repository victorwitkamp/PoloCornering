/*
 * VagCanCommunicator_receiveMore
 * ELF symbol address: 0x00D1898C
 * Ghidra address: 0x00D2898C (ELF + 0x10000 image delta)
 * ELF symbol size: 128 bytes
 * Symbol: _ZN18VagCanCommunicator11receiveMoreEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::receiveMore @ 00d2898c
 * Signature: undefined __thiscall receiveMore(VagCanCommunicator * this)
 * Return type: undefined
 * Function body: [[00d2898c, 00d289f7]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3828
 *   VagCanCommunicator::receiveMore @ 01403d50 -> COMPUTED_CALL from 01403d58
 * Direct callees/references:
 *   READ 00d28a04 from 00d28998
 *   READ 014da87c from 00d2899c
 *   READ 015a7014 from 00d2899e
 *   WRITE Stack[-0x1c] from 00d289a0
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 00d289c0
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d289d4
 *   UNCONDITIONAL_CALL VagCanCommunicator::receive @ 01403d30 from 00d289da
 *   READ Stack[-0x1c] from 00d289de
 *   READ 00d28a08 from 00d289e0
 *   READ 014da87c from 00d289e4
 *   READ 015a7014 from 00d289e6
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d289f4
 */

/* Ghidra function: VagCanCommunicator::receiveMore @ 00d2898c */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd86b004461a48784400680068059060680168ca6d4ff40071
 * 00d2898c: push {r4,r5,r6,r7,lr}
 * 00d2898e: add r7,sp,#0xc
 * 00d28990: push.w r11
 * 00d28994: sub sp,#0x18
 * 00d28996: mov r4,r0
 * 00d28998: ldr r0,[0x00d28a04]
 * 00d2899a: add r0,pc
 * 00d2899c: ldr r0,[r0,#0x0]
 * 00d2899e: ldr r0,[r0,#0x0]
 * 00d289a0: str r0,[sp,#0x14]
 * 00d289a2: ldr r0,[r4,#0x4]
 * 00d289a4: ldr r1,[r0,#0x0]
 * 00d289a6: ldr r2,[r1,#0x5c]
 * 00d289a8: mov.w r1,#0x200
 * 00d289ac: blx r2
 * 00d289ae: movs r0,#0xa3
 * 00d289b0: ldr r5,[r4,#0x4]
 * 00d289b2: strb.w r0,[r7,#-0x15]
 * 00d289b6: add r6,sp,#0x4
 * 00d289b8: sub.w r1,r7,#0x15
 * 00d289bc: movs r2,#0x1
 * 00d289be: mov r0,r6
 * 00d289c0: bl 0x00cdb87c
 * 00d289c4: ldr r0,[r5,#0x0]
 */


/* VagCanCommunicator::receiveMore() */

void __thiscall VagCanCommunicator::receiveMore(VagCanCommunicator *this)

{
  int *piVar1;
  undefined1 auStack_2c [15];
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  (**(code **)(**(int **)(this + 4) + 0x5c))(*(int **)(this + 4),0x200);
  piVar1 = *(int **)(this + 4);
  uStack_1d = 0xa3;
  FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  (**(code **)(*piVar1 + 0x16c))(piVar1,auStack_2c,2);
  FUN_00cb7f50(auStack_2c);
  receive();
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


