/*
 * Result_EmptyModel_isIn
 * ELF symbol address: 0x011DDD30
 * Ghidra address: 0x011EDD30 (ELF + 0x10000 image delta)
 * ELF symbol size: 12 bytes
 * Symbol: _ZNK6ResultI10EmptyModelvE4isInERKN5State3SetE
 * Program: libCarista.so
 * Resolved function: Result<EmptyModel,void>::isIn @ 011edd30
 * Signature: undefined __thiscall isIn(Result<EmptyModel,void> * this, Set * param_1)
 * Return type: undefined
 * Function body: [[011edd30, 011edd3b]]
 * Parameters:
 *   [0] Result<EmptyModel,void> * this
 *   [1] Set * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea894
 *   Result<EmptyModel,void>::isIn @ 0141ff00 -> COMPUTED_CALL from 0141ff08
 * Direct callees/references:
 *   UNCONDITIONAL_JUMP Result<VagUdsRoutineStateModel,void>::isIn @ 012dc0b4 from 011edd38
 */

/* Ghidra function: Result<EmptyModel,void>::isIn @ 011edd30 */

/* First instructions after recreation:
 * Memory bytes: 80690a46016810460af2acb9
 * 011edd30: ldr r0,[r0,#0x18]
 * 011edd32: mov r2,r1
 * 011edd34: ldr r1,[r0,#0x0]
 * 011edd36: mov r0,r2
 * 011edd38: b.w 0x013f8094
 * 011edd3c: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 011edd3e: add r7,sp,#0x18
 * 011edd40: mov r4,r0
 * 011edd42: ldr r0,[0x011edd80]
 * 011edd44: movs r3,#0x0
 * 011edd46: add r0,pc
 * 011edd48: ldr r0,[r0,#0x0]
 * 011edd4a: ldr r0,[r0,#0x0]
 * 011edd4c: str r0,[sp,#0xc]
 * 011edd4e: ldrd r0,r2,[r1,#0x0]
 * 011edd52: strd r3,r3,[r1,#0x0]
 * 011edd56: ldrd r1,r3,[r4,#0x0]
 * 011edd5a: strd r0,r2,[r4,#0x0]
 * 011edd5e: strd r1,r3,[sp,#0x4]
 * 011edd62: add r0,sp,#0x4
 * 011edd64: bl 0x00cdf4d4
 * 011edd68: ldr r0,[sp,#0xc]
 * 011edd6a: ldr r1,[0x011edd84]
 * 011edd6c: add r1,pc
 */


/* Result<EmptyModel, void>::isIn(State::Set const&) const */

void __thiscall Result<EmptyModel,void>::isIn(Result<EmptyModel,void> *this,Set *param_1)

{
  State::Set::contains((int)param_1);
  return;
}


