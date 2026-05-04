/*
 * WriteDataByIdentifierCommand_processPayload
 * ELF symbol address: 0x00CF812C
 * Ghidra address: 0x00D0812C (ELF + 0x10000 image delta)
 * ELF symbol size: 10 bytes
 * Symbol: _ZNK28WriteDataByIdentifierCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: WriteDataByIdentifierCommand::processPayload @ 00d0812c
 * Signature: undefined __stdcall processPayload(vector * param_1)
 * Return type: undefined
 * Function body: [[00d0812c, 00d08135]]
 * Parameters:
 *   [0] vector * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 01439468
 *   <no function> -> DATA from 0143bcc0
 * Direct callees/references:
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::done @ 013fd6f0 from 00d08130
 */

/* Ghidra function: WriteDataByIdentifierCommand::processPayload @ 00d0812c */

/* First instructions after recreation:
 * Memory bytes: 80b56f46f5f2dee280bd
 * 00d0812c: push {r7,lr}
 * 00d0812e: mov r7,sp
 * 00d08130: blx 0x013fd6f0
 * 00d08134: pop {r7,pc}
 * 00d08138: push {r7,lr}
 * 00d0813a: mov r7,sp
 * 00d0813c: ldr r2,[0x00d08158]
 * 00d0813e: add r2,pc
 * 00d08140: ldr r2,[r2,#0x0]
 * 00d08142: ldr r3,[r2,#0x0]
 * 00d08144: movs r2,#0x2
 * 00d08146: blx 0x014012b0
 * 00d0814a: ldr r1,[0x00d0815c]
 * 00d0814c: add r1,pc
 * 00d0814e: ldr r1,[r1,#0x0]
 * 00d08150: adds r1,#0x8
 * 00d08152: str r1,[r0,#0x0]
 * 00d08154: pop {r7,pc}
 * 00d08160: push {r4,r5,r6,r7,lr}
 * 00d08162: add r7,sp,#0xc
 * 00d08164: push.w r11
 * 00d08168: sub sp,#0x10
 * 00d0816a: mov r4,r0
 * 00d0816c: ldr r0,[0x00d081fc]
 */


/* WriteDataByIdentifierCommand::processPayload(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) const */

void WriteDataByIdentifierCommand::processPayload(vector *param_1)

{
  Result<EmptyModel,void>::done((Result<EmptyModel,void> *)param_1);
  return;
}


