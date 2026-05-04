/*
 * Result_EmptyModel_isFail
 * ELF symbol address: 0x011D63BA
 * Ghidra address: 0x011E63BA (ELF + 0x10000 image delta)
 * ELF symbol size: 8 bytes
 * Symbol: _ZNK6ResultI10EmptyModelvE6isFailEv
 * Program: libCarista.so
 * Resolved function: Result<EmptyModel,void>::isFail @ 011e63ba
 * Signature: undefined __thiscall isFail(Result<EmptyModel,void> * this)
 * Return type: undefined
 * Function body: [[011e63ba, 011e63c1]]
 * Parameters:
 *   [0] Result<EmptyModel,void> * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea670
 *   Result<EmptyModel,void>::isFail @ 0141f670 -> COMPUTED_CALL from 0141f678
 * Direct callees/references:
 *   UNCONDITIONAL_JUMP Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>::isFail @ 012dc204 from 011e63be
 */

/* Ghidra function: Result<EmptyModel,void>::isFail @ 011e63ba */

/* First instructions after recreation:
 * Memory bytes: 8069006811f2c7bd
 * 011e63ba: ldr r0,[r0,#0x18]
 * 011e63bc: ldr r0,[r0,#0x0]
 * 011e63be: b.w 0x013f7f50
 * 011e63c4: push {r4,r5,r6,r7,lr}
 * 011e63c6: add r7,sp,#0xc
 * 011e63c8: push.w r11
 * 011e63cc: mov r4,r0
 * 011e63ce: add.w r6,r0,#0x10
 * 011e63d2: adds r0,#0x8
 * 011e63d4: vmov.i32 q8,#0
 * 011e63d8: mov r5,r1
 * 011e63da: strd r0,r6,[r4,#0x1c]
 * 011e63de: mov r1,r0
 * 011e63e0: adds r2,r4,#0x4
 * 011e63e2: vst1.32 {d16,d17},[r1]!
 * 011e63e6: str r2,[r1,#0x0]
 * 011e63e8: ldr r1,[0x011e6410]
 * 011e63ea: add r1,pc
 * 011e63ec: ldr r1,[r1,#0x0]
 * 011e63ee: adds r1,#0x8
 * 011e63f0: str r1,[r4,#0x0]
 * 011e63f2: ldrd r2,r1,[r5,#0x18]
 * 011e63f6: ldr r2,[r2,#0x0]
 * 011e63f8: str r2,[r4,#0x4]
 */


/* Result<EmptyModel, void>::isFail() const */

void __thiscall Result<EmptyModel,void>::isFail(Result<EmptyModel,void> *this)

{
  State::isError(**(int **)(this + 0x18));
  return;
}


