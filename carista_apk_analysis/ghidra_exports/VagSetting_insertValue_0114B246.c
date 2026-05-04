/*
 * VagSetting_insertValue
 * ELF symbol address: 0x0113B246
 * Ghidra address: 0x0114B246 (ELF + 0x10000 image delta)
 * ELF symbol size: 22 bytes
 * Symbol: _ZNK10VagSetting11insertValueERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_
 * Program: libCarista.so
 * Resolved function: VagSetting::insertValue @ 0114b246
 * Signature: undefined __stdcall insertValue(vector * param_1, vector * param_2)
 * Return type: undefined
 * Function body: [[0114b246, 0114b25b]]
 * Parameters:
 *   [0] vector * param_1
 *   [1] vector * param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e7ee4
 *   VagSetting::insertValue @ 01415840 -> COMPUTED_CALL from 01415848
 *   <no function> -> DATA from 014b48d4
 *   <no function> -> DATA from 014b49b4
 *   <no function> -> DATA from 014b4a34
 *   <no function> -> DATA from 014b4a8c
 *   <no function> -> DATA from 014b4af8
 *   <no function> -> DATA from 014b4b64
 *   <no function> -> DATA from 014b4c9c
 *   <no function> -> DATA from 014b4d4c
 *   <no function> -> DATA from 014b4fd4
 *   <no function> -> DATA from 014b54f8
 *   <no function> -> DATA from 014b55b8
 *   <no function> -> DATA from 014b5610
 *   <no function> -> DATA from 014b5668
 *   <no function> -> DATA from 014b56c0
 *   <no function> -> DATA from 014b57bc
 *   <no function> -> DATA from 014b58a8
 *   <no function> -> DATA from 014b59b0
 * Direct callees/references:
 *   WRITE Stack[-0x18] from 0114b24e
 *   UNCONDITIONAL_CALL ByteUtils::insertValue @ 0140de10 from 0114b256
 */

/* Ghidra function: VagSetting::insertValue @ 0114b246 */

/* First instructions after recreation:
 * Memory bytes: dcb504af14468a69009301f11c032146c2f2dceddcbd
 * 0114b246: push {r2,r3,r4,r6,r7,lr}
 * 0114b248: add r7,sp,#0x10
 * 0114b24a: mov r4,r2
 * 0114b24c: ldr r2,[r1,#0x18]
 * 0114b24e: str r3,[sp,#0x0]
 * 0114b250: add.w r3,r1,#0x1c
 * 0114b254: mov r1,r4
 * 0114b256: blx 0x0140de10
 * 0114b25a: pop {r2,r3,r4,r6,r7,pc}
 * 0114b25c: ldrb r0,[r0,#0xc]
 * 0114b25e: mov.w r1,#0x230
 * 0114b262: movs r2,#0x0
 * 0114b264: lsrs r1,r0
 * 0114b266: cmp r0,#0xa
 * 0114b268: it cc
 * 0114b26a: mov.cc r2,#0x1
 * 0114b26c: and.w r0,r2,r1
 * 0114b270: bx lr
 * 0114b274: push {r4,r5,r7,lr}
 * 0114b276: add r7,sp,#0x8
 * 0114b278: mov r4,r0
 * 0114b27a: ldr r0,[r0,#0x0]
 * 0114b27c: ldr r1,[r0,#0x14]
 * 0114b27e: mov r0,r4
 */


/* VagSetting::insertValue(std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > const&, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&)
   const */

void VagSetting::insertValue(vector *param_1,vector *param_2)

{
  vector *in_r2;
  vector *in_r3;
  
  ByteUtils::insertValue((ByteUtils *)param_1,in_r2,*(uint *)(param_2 + 0x18),param_2 + 0x1c,in_r3);
  return;
}


