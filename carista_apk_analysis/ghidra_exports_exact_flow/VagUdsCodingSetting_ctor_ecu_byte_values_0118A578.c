/*
 * VagUdsCodingSetting_ctor_ecu_byte_values
 * ELF symbol address: 0x0117A578
 * Ghidra address: 0x0118A578 (ELF + 0x10000 image delta)
 * ELF symbol size: 128 bytes
 * Symbol: _ZN19VagUdsCodingSettingC1EP3EcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEihPKcRKNS3_I14InterpretationEERKNS3_IKNS2_6vectorIyNS2_9allocatorIyEEEEEEN10VagSetting7AvailByE
 * Program: libCarista.so
 * Resolved function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a578
 * Signature: undefined __thiscall VagUdsCodingSetting(VagUdsCodingSetting * this, Ecu * param_1, shared_ptr * param_2, int param_3, uchar param_4, char * param_5, shared_ptr * param_6, shared_ptr * param_7, AvailBy param_8)
 * Return type: undefined
 * Function body: [[0118a578, 0118a5e5]]
 * Parameters:
 *   [0] VagUdsCodingSetting * this
 *   [1] Ecu * param_1
 *   [2] shared_ptr * param_2
 *   [3] int param_3
 *   [4] uchar param_4
 *   [5] char * param_5
 *   [6] shared_ptr * param_6
 *   [7] shared_ptr * param_7
 *   [8] typedef AvailBy undefined param_8
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e8238
 *   VagUdsCodingSetting::VagUdsCodingSetting @ 01416590 -> COMPUTED_CALL from 01416598
 * Direct callees/references:
 *   READ 0118a5f0 from 0118a584
 *   READ 014da87c from 0118a594
 *   READ 015a7014 from 0118a596
 *   WRITE Stack[-0x1c] from 0118a598
 *   READ Stack[0x0] from 0118a59a
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 0118a5a2
 *   READ Stack[0x10] from 0118a5a6
 *   WRITE Stack[-0x30] from 0118a5aa
 *   READ Stack[0xc] from 0118a5ae
 *   WRITE Stack[-0x34] from 0118a5b0
 *   READ Stack[0x8] from 0118a5b2
 *   WRITE Stack[-0x38] from 0118a5b4
 *   READ Stack[0x4] from 0118a5b6
 *   WRITE Stack[-0x40] from 0118a5b8
 *   UNCONDITIONAL_CALL VagUdsCodingSetting::VagUdsCodingSetting @ 0141d730 from 0118a5c0
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0118a5c6
 *   READ Stack[-0x1c] from 0118a5ca
 *   READ 0118a5f4 from 0118a5cc
 *   READ 014da87c from 0118a5d0
 *   READ 015a7014 from 0118a5d2
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 0118a5e2
 */

/* Ghidra function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a578 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d8ab004461a480d46a7f11501784416460122984600680068
 * 0118a578: push {r4,r5,r6,r7,lr}
 * 0118a57a: add r7,sp,#0xc
 * 0118a57c: push.w r8
 * 0118a580: sub sp,#0x28
 * 0118a582: mov r4,r0
 * 0118a584: ldr r0,[0x0118a5f0]
 * 0118a586: mov r5,r1
 * 0118a588: sub.w r1,r7,#0x15
 * 0118a58c: add r0,pc
 * 0118a58e: mov r6,r2
 * 0118a590: movs r2,#0x1
 * 0118a592: mov r8,r3
 * 0118a594: ldr r0,[r0,#0x0]
 * 0118a596: ldr r0,[r0,#0x0]
 * 0118a598: str r0,[sp,#0x24]
 * 0118a59a: ldr r0,[r7,#0x8]
 * 0118a59c: strb.w r0,[r7,#-0x15]
 * 0118a5a0: add r0,sp,#0x14
 * 0118a5a2: bl 0x00cdb87c
 * 0118a5a6: ldr r1,[r7,#0x18]
 * 0118a5a8: mov r2,r6
 * 0118a5aa: str r1,[sp,#0x10]
 * 0118a5ac: mov r3,r8
 * 0118a5ae: ldr r1,[r7,#0x14]
 */


/* VagUdsCodingSetting::VagUdsCodingSetting(Ecu*, std::__ndk1::shared_ptr<StringWhitelist> const&,
   int, unsigned char, char const*, std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, VagSetting::AvailBy) */

void __thiscall
VagUdsCodingSetting::VagUdsCodingSetting
          (VagUdsCodingSetting *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,
          undefined1 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,
          undefined4 param_9)

{
  undefined4 uVar1;
  undefined1 auStack_2c [15];
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1d = param_4;
  uVar1 = FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  VagUdsCodingSetting(this,param_1,param_2,param_3,uVar1,param_5,param_6,param_7,param_9);
  FUN_00cb7f50(auStack_2c);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


