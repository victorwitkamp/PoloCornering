/*
 * GetVagCanEcuInfoCommand_getRequest
 * ELF symbol address: 0x00CF8230
 * Ghidra address: 0x00D08230 (ELF + 0x10000 image delta)
 * ELF symbol size: 20 bytes
 * Symbol: _ZNK23GetVagCanEcuInfoCommand10getRequestEv
 * Program: libCarista.so
 * Resolved function: GetVagCanEcuInfoCommand::getRequest @ 00d08230
 * Signature: undefined __thiscall getRequest(GetVagCanEcuInfoCommand * this)
 * Return type: undefined
 * Function body: [[00d08230, 00d0823f]]
 * Parameters:
 *   [0] GetVagCanEcuInfoCommand * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143bce0
 * Direct callees/references:
 *   READ 00d08240 from 00d08234
 *   PARAM 00a54ba7 from 00d08238
 *   UNCONDITIONAL_CALL operator""__b @ 013fd3f0 from 00d0823a
 */

/* Ghidra function: GetVagCanEcuInfoCommand::getRequest @ 00d08230 */

/* First instructions after recreation:
 * Memory bytes: 80b56f46024904227944f5f2dae080bd6bc9d4ff
 * 00d08230: push {r7,lr}
 * 00d08232: mov r7,sp
 * 00d08234: ldr r1,[0x00d08240]
 * 00d08236: movs r2,#0x4
 * 00d08238: add r1,pc
 * 00d0823a: blx 0x013fd3f0
 * 00d0823e: pop {r7,pc}
 * 00d08244: push {r4,r5,r6,r7,lr}
 * 00d08246: add r7,sp,#0xc
 * 00d08248: push {r8,r9,r10}
 * 00d0824c: sub sp,#0xa0
 * 00d0824e: mov r8,r0
 * 00d08250: ldr r0,[0x00d083f4]
 * 00d08252: mov r6,r1
 * 00d08254: movs r1,#0x0
 * 00d08256: add r0,pc
 * 00d08258: mov r5,r2
 * 00d0825a: ldr r0,[r0,#0x0]
 * 00d0825c: ldr r0,[r0,#0x0]
 * 00d0825e: str r0,[sp,#0x9c]
 * 00d08260: mov r0,r2
 * 00d08262: bl 0x00d08400
 * 00d08266: mov r2,r0
 * 00d08268: ldr r0,[r6,#0x0]
 */


/* GetVagCanEcuInfoCommand::getRequest() const */

void __thiscall GetVagCanEcuInfoCommand::getRequest(GetVagCanEcuInfoCommand *this)

{
  operator____b((char *)this,0xa54ba7);
  return;
}


