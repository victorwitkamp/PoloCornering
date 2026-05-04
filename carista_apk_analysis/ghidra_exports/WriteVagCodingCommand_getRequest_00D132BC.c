/*
 * WriteVagCodingCommand_getRequest
 * ELF symbol address: 0x00D032BC
 * Ghidra address: 0x00D132BC (ELF + 0x10000 image delta)
 * ELF symbol size: 300 bytes
 * Symbol: _ZNK21WriteVagCodingCommand10getRequestEv
 * Program: libCarista.so
 * Resolved function: WriteVagCodingCommand::getRequest @ 00d132bc
 * Signature: undefined __stdcall getRequest(void)
 * Return type: undefined
 * Function body: [[00d132bc, 00d13399]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143c560
 * Direct callees/references:
 *   READ 00d133d4 from 00d132c8
 *   READ 014da87c from 00d132ce
 *   READ 015a7014 from 00d132d0
 *   WRITE Stack[-0x1c] from 00d132d2
 *   CONDITIONAL_JUMP WriteVagCodingCommand::getRequest @ 00d132bc from 00d132d8
 *   READ 00d133d8 from 00d132da
 *   DATA 00c8dc75 from 00d132de
 *   UNCONDITIONAL_JUMP WriteVagCodingCommand::getRequest @ 00d132bc from 00d132e0
 *   READ 00d133dc from 00d132e6
 *   PARAM 008d8d6e from 00d132ea
 *   UNCONDITIONAL_CALL operator""__b @ 013fd3f0 from 00d132ee
 *   UNCONDITIONAL_CALL operator+ @ 013fd460 from 00d132fa
 *   UNCONDITIONAL_CALL operator+ @ 013fd460 from 00d13304
 *   CONDITIONAL_JUMP WriteVagCodingCommand::getRequest @ 00d132bc from 00d1330c
 *   UNCONDITIONAL_CALL _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_RKSA_ @ 013fd4d0 from 00d13314
 *   UNCONDITIONAL_JUMP WriteVagCodingCommand::getRequest @ 00d132bc from 00d13318
 *   UNCONDITIONAL_CALL Math::toExact<unsigned_char,unsigned_int> @ 013fd660 from 00d13328
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 00d13338
 *   UNCONDITIONAL_CALL operator+ @ 013fd460 from 00d13342
 *   UNCONDITIONAL_CALL _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEEOSA_S2_ @ 013fd4c0 from 00d1334c
 *   UNCONDITIONAL_CALL operator+ @ 013fd470 from 00d13356
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d1335c
 *   CONDITIONAL_JUMP WriteVagCodingCommand::getRequest @ 00d132bc from 00d13362
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d13366
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d1336c
 *   READ 00d133e0 from 00d13372
 *   COMPUTED_CALL FUN_00cb7f50 @ 00cb7f50 from 00d13376
 *   COMPUTED_CALL FUN_00cb7f50 @ 00cb7f50 from 00d1337a
 *   COMPUTED_CALL FUN_00cb7f50 @ 00cb7f50 from 00d1337e
 *   READ Stack[-0x1c] from 00d13380
 *   READ 00d133e4 from 00d13382
 *   READ 014da87c from 00d13386
 *   READ 015a7014 from 00d13388
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d13396
 */

/* Ghidra function: WriteVagCodingCommand::getRequest @ 00d132bc */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d94b0804642480d467844006800681390486a052803d83f49
 * 00d132bc: push {r4,r5,r6,r7,lr}
 * 00d132be: add r7,sp,#0xc
 * 00d132c0: push.w r8
 * 00d132c4: sub sp,#0x50
 * 00d132c6: mov r8,r0
 * 00d132c8: ldr r0,[0x00d133d4]
 * 00d132ca: mov r5,r1
 * 00d132cc: add r0,pc
 * 00d132ce: ldr r0,[r0,#0x0]
 * 00d132d0: ldr r0,[r0,#0x0]
 * 00d132d2: str r0,[sp,#0x4c]
 * 00d132d4: ldr r0,[r1,#0x24]
 * 00d132d6: cmp r0,#0x5
 * 00d132d8: bhi 0x00d132e2
 * 00d132da: ldr r1,[0x00d133d8]
 * 00d132dc: add r1,pc
 * 00d132de: ldrb r6,[r1,r0]
 * 00d132e0: b 0x00d132e4
 * 00d132e2: movs r6,#0x3
 * 00d132e4: add r4,sp,#0x24
 * 00d132e6: ldr r1,[0x00d133dc]
 * 00d132e8: movs r2,#0x4
 * 00d132ea: add r1,pc
 * 00d132ec: mov r0,r4
 */


/* WriteVagCodingCommand::getRequest() const */

void WriteVagCodingCommand::getRequest(void)

{
  vector *in_r0;
  int in_r1;
  int iVar1;
  undefined1 uVar2;
  vector avStack_68 [12];
  vector avStack_5c [12];
  undefined1 auStack_50 [12];
  vector avStack_44 [12];
  vector avStack_38 [12];
  vector avStack_2c [14];
  undefined1 uStack_1e;
  uchar uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (*(uint *)(in_r1 + 0x24) < 6) {
    uVar2 = (&DAT_00c8dc75)[*(uint *)(in_r1 + 0x24)];
  }
  else {
    uVar2 = 3;
  }
  operator____b((char *)avStack_44,0x8d8d6e);
  operator+(avStack_38,avStack_44);
  operator+(avStack_2c,avStack_38);
  iVar1 = *(int *)(in_r1 + 0x24);
  if (iVar1 == 2) {
    _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_RKSA_
              (auStack_50,uVar2,*(undefined4 *)(in_r1 + 0x28));
  }
  else {
    uStack_1e = uVar2;
    uStack_1d = Math::toExact<unsigned_char,unsigned_int>
                          (((*(int **)(in_r1 + 0x28))[1] - **(int **)(in_r1 + 0x28)) + 1);
    FUN_00cdb87c(avStack_68,&uStack_1e,2);
    operator+(avStack_5c,avStack_68);
    _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEEOSA_S2_
              (auStack_50,avStack_5c,0xff);
  }
  operator+(in_r0,avStack_2c);
  FUN_00cb7f50(auStack_50);
  if (iVar1 != 2) {
    FUN_00cb7f50(avStack_5c);
    FUN_00cb7f50(avStack_68);
  }
  FUN_00cb7f50(avStack_2c);
  FUN_00cb7f50(avStack_38);
  FUN_00cb7f50(avStack_44);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


