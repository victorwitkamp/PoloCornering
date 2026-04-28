/*
 * ReadDataByIdentifierCommand_Bytes_getRequest
 * ELF symbol address: 0x00CD5234
 * Ghidra address: 0x00CE5234 (ELF + 0x10000 image delta)
 * ELF symbol size: 116 bytes
 * Symbol: _ZNK27ReadDataByIdentifierCommandI10BytesModelE10getRequestEv
 * Program: libCarista.so
 * Resolved function: ReadDataByIdentifierCommand<BytesModel>::getRequest @ 00ce5234
 * Signature: undefined __stdcall getRequest(void)
 * Return type: undefined
 * Function body: [[00ce5234, 00ce528d]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014392c8
 *   <no function> -> DATA from 01439304
 *   <no function> -> DATA from 0143b970
 *   <no function> -> DATA from 0143c620
 *   <no function> -> DATA from 0143c840
 *   <no function> -> DATA from 0143c96c
 * Direct callees/references:
 *   READ 00ce52a0 from 00ce523c
 *   READ 014da87c from 00ce5248
 *   READ 015a7014 from 00ce524a
 *   WRITE Stack[-0x14] from 00ce524c
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 00ce5256
 *   UNCONDITIONAL_CALL ByteUtils::getBytesFromShort @ 013fdc40 from 00ce525e
 *   UNCONDITIONAL_CALL operator+ @ 013fd470 from 00ce5268
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00ce526e
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00ce5274
 *   READ Stack[-0x14] from 00ce5278
 *   READ 00ce52a4 from 00ce527a
 *   READ 014da87c from 00ce527e
 *   READ 015a7014 from 00ce5280
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00ce528a
 */

/* Ghidra function: ReadDataByIdentifierCommand<BytesModel>::getRequest @ 00ce5234 */

/* First instructions after recreation:
 * Memory bytes: b0b502af88b0044618480d46a7f10d0178440122006800680790222007f80d0c
 * 00ce5234: push {r4,r5,r7,lr}
 * 00ce5236: add r7,sp,#0x8
 * 00ce5238: sub sp,#0x20
 * 00ce523a: mov r4,r0
 * 00ce523c: ldr r0,[0x00ce52a0]
 * 00ce523e: mov r5,r1
 * 00ce5240: sub.w r1,r7,#0xd
 * 00ce5244: add r0,pc
 * 00ce5246: movs r2,#0x1
 * 00ce5248: ldr r0,[r0,#0x0]
 * 00ce524a: ldr r0,[r0,#0x0]
 * 00ce524c: str r0,[sp,#0x1c]
 * 00ce524e: movs r0,#0x22
 * 00ce5250: strb.w r0,[r7,#-0xd]
 * 00ce5254: add r0,sp,#0xc
 * 00ce5256: bl 0x00cdb87c
 * 00ce525a: ldrh r1,[r5,#0x10]
 * 00ce525c: mov r0,sp
 * 00ce525e: blx 0x013fdc40
 * 00ce5262: add r1,sp,#0xc
 * 00ce5264: mov r2,sp
 * 00ce5266: mov r0,r4
 * 00ce5268: blx 0x013fd470
 * 00ce526c: mov r0,sp
 */


/* ReadDataByIdentifierCommand<BytesModel>::getRequest() const */

void ReadDataByIdentifierCommand<BytesModel>::getRequest(void)

{
  vector *in_r0;
  int in_r1;
  ByteUtils aBStack_30 [12];
  vector avStack_24 [15];
  undefined1 uStack_15;
  int local_14;
  
  local_14 = __stack_chk_guard;
  uStack_15 = 0x22;
  FUN_00cdb87c(avStack_24,&uStack_15,1);
  ByteUtils::getBytesFromShort(aBStack_30,*(ushort *)(in_r1 + 0x10));
  operator+(in_r0,avStack_24);
  FUN_00cb7f50(aBStack_30);
  FUN_00cb7f50(avStack_24);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


