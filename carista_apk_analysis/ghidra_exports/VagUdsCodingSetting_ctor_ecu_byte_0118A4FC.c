/*
 * VagUdsCodingSetting_ctor_ecu_byte
 * ELF symbol address: 0x0117A4FC
 * Ghidra address: 0x0118A4FC (ELF + 0x10000 image delta)
 * ELF symbol size: 124 bytes
 * Symbol: _ZN19VagUdsCodingSettingC1EP3EcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEihPKcRKNS3_I14InterpretationEEN10VagSetting7AvailByE
 * Program: libCarista.so
 * Resolved function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a4fc
 * Signature: undefined __thiscall VagUdsCodingSetting(VagUdsCodingSetting * this, Ecu * param_1, shared_ptr * param_2, int param_3, uchar param_4, char * param_5, shared_ptr * param_6, AvailBy param_7)
 * Return type: undefined
 * Function body: [[0118a4fc, 0118a565]]
 * Parameters:
 *   [0] VagUdsCodingSetting * this
 *   [1] Ecu * param_1
 *   [2] shared_ptr * param_2
 *   [3] int param_3
 *   [4] uchar param_4
 *   [5] char * param_5
 *   [6] shared_ptr * param_6
 *   [7] typedef AvailBy undefined param_7
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e80f0
 *   VagUdsCodingSetting::VagUdsCodingSetting @ 01416070 -> COMPUTED_CALL from 01416078
 * Direct callees/references:
 *   READ 0118a570 from 0118a508
 *   READ 014da87c from 0118a518
 *   READ 015a7014 from 0118a51a
 *   WRITE Stack[-0x1c] from 0118a51c
 *   READ Stack[0x0] from 0118a51e
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 0118a526
 *   READ Stack[0xc] from 0118a52a
 *   WRITE Stack[-0x34] from 0118a52e
 *   READ Stack[0x8] from 0118a532
 *   WRITE Stack[-0x38] from 0118a534
 *   READ Stack[0x4] from 0118a536
 *   WRITE Stack[-0x40] from 0118a538
 *   UNCONDITIONAL_CALL VagUdsCodingSetting::VagUdsCodingSetting @ 0141d720 from 0118a540
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0118a546
 *   READ Stack[-0x1c] from 0118a54a
 *   READ 0118a574 from 0118a54c
 *   READ 014da87c from 0118a550
 *   READ 015a7014 from 0118a552
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 0118a562
 */

/* Ghidra function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a4fc */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d8ab0044619480d46a7f11501784416460122984600680068
 * 0118a4fc: push {r4,r5,r6,r7,lr}
 * 0118a4fe: add r7,sp,#0xc
 * 0118a500: push.w r8
 * 0118a504: sub sp,#0x28
 * 0118a506: mov r4,r0
 * 0118a508: ldr r0,[0x0118a570]
 * 0118a50a: mov r5,r1
 * 0118a50c: sub.w r1,r7,#0x15
 * 0118a510: add r0,pc
 * 0118a512: mov r6,r2
 * 0118a514: movs r2,#0x1
 * 0118a516: mov r8,r3
 * 0118a518: ldr r0,[r0,#0x0]
 * 0118a51a: ldr r0,[r0,#0x0]
 * 0118a51c: str r0,[sp,#0x24]
 * 0118a51e: ldr r0,[r7,#0x8]
 * 0118a520: strb.w r0,[r7,#-0x15]
 * 0118a524: add r0,sp,#0x14
 * 0118a526: bl 0x00cdb87c
 * 0118a52a: ldr r1,[r7,#0x14]
 * 0118a52c: mov r2,r6
 * 0118a52e: str r1,[sp,#0xc]
 * 0118a530: mov r3,r8
 * 0118a532: ldr r1,[r7,#0x10]
 */


/* VagUdsCodingSetting::VagUdsCodingSetting(Ecu*, std::__ndk1::shared_ptr<StringWhitelist> const&,
   int, unsigned char, char const*, std::__ndk1::shared_ptr<Interpretation> const&,
   VagSetting::AvailBy) */

void __thiscall
VagUdsCodingSetting::VagUdsCodingSetting
          (VagUdsCodingSetting *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,
          undefined1 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_8)

{
  undefined4 uVar1;
  undefined1 auStack_2c [15];
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1d = param_4;
  uVar1 = FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  VagUdsCodingSetting(this,param_1,param_2,param_3,uVar1,param_5,param_6,param_8);
  FUN_00cb7f50(auStack_2c);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


