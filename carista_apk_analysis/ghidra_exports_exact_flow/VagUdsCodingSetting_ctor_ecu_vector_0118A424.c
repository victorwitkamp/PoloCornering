/*
 * VagUdsCodingSetting_ctor_ecu_vector
 * ELF symbol address: 0x0117A424
 * Ghidra address: 0x0118A424 (ELF + 0x10000 image delta)
 * ELF symbol size: 140 bytes
 * Symbol: _ZN19VagUdsCodingSettingC1EP3EcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEiRKNS2_6vectorIhNS2_9allocatorIhEEEEPKcRKNS3_I14InterpretationEEN10VagSetting7AvailByE
 * Program: libCarista.so
 * Resolved function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a424
 * Signature: undefined __thiscall VagUdsCodingSetting(VagUdsCodingSetting * this, Ecu * param_1, shared_ptr * param_2, int param_3, vector * param_4, char * param_5, shared_ptr * param_6, AvailBy param_7)
 * Return type: undefined
 * Function body: [[0118a424, 0118a495]]
 * Parameters:
 *   [0] VagUdsCodingSetting * this
 *   [1] Ecu * param_1
 *   [2] shared_ptr * param_2
 *   [3] int param_3
 *   [4] vector * param_4
 *   [5] char * param_5
 *   [6] shared_ptr * param_6
 *   [7] typedef AvailBy undefined param_7
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e9e9c
 *   VagUdsCodingSetting::VagUdsCodingSetting @ 0141d720 -> COMPUTED_CALL from 0141d728
 * Direct callees/references:
 *   READ 0118a4a0 from 0118a42c
 *   READ 014da87c from 0118a432
 *   READ 015a7014 from 0118a434
 *   WRITE Stack[-0x14] from 0118a436
 *   WRITE Stack[-0x1c] from 0118a43a
 *   READ Stack[0xc] from 0118a43e
 *   WRITE Stack[-0x24] from 0118a442
 *   WRITE Stack[-0x28] from 0118a446
 *   WRITE Stack[-0x2c] from 0118a44a
 *   READ Stack[0x8] from 0118a44e
 *   WRITE Stack[-0x30] from 0118a450
 *   READ Stack[0x4] from 0118a452
 *   WRITE Stack[-0x34] from 0118a454
 *   READ Stack[0x0] from 0118a456
 *   WRITE Stack[-0x3c] from 0118a458
 *   READ 0118a4a4 from 0118a45e
 *   READ 014df1d4 from 0118a462
 *   READ 00c95e1a from 0118a464
 *   WRITE Stack[-0x40] from 0118a466
 *   UNCONDITIONAL_CALL VagSetting::VagSetting @ 01415930 from 0118a46a
 *   UNCONDITIONAL_CALL FUN_00d4dec4 @ 00d4dec4 from 0118a470
 *   READ 0118a4a8 from 0118a474
 *   READ 014df2f8 from 0118a478
 *   DATA 014b5688 from 0118a47c
 *   READ Stack[-0x14] from 0118a47e
 *   READ 0118a4ac from 0118a480
 *   READ 014da87c from 0118a484
 *   READ 015a7014 from 0118a486
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 0118a492
 */

/* Ghidra function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a424 */

/* First instructions after recreation:
 * Memory bytes: b0b502af8cb004461c480d467844006800680b900020cde90900786911460790
 * 0118a424: push {r4,r5,r7,lr}
 * 0118a426: add r7,sp,#0x8
 * 0118a428: sub sp,#0x30
 * 0118a42a: mov r4,r0
 * 0118a42c: ldr r0,[0x0118a4a0]
 * 0118a42e: mov r5,r1
 * 0118a430: add r0,pc
 * 0118a432: ldr r0,[r0,#0x0]
 * 0118a434: ldr r0,[r0,#0x0]
 * 0118a436: str r0,[sp,#0x2c]
 * 0118a438: movs r0,#0x0
 * 0118a43a: strd r0,r0,[sp,#0x24]
 * 0118a43e: ldr r0,[r7,#0x14]
 * 0118a440: mov r1,r2
 * 0118a442: str r0,[sp,#0x1c]
 * 0118a444: movs r0,#0x1
 * 0118a446: str r0,[sp,#0x18]
 * 0118a448: add r0,sp,#0x24
 * 0118a44a: str r0,[sp,#0x14]
 * 0118a44c: movs r2,#0x8
 * 0118a44e: ldr r0,[r7,#0x10]
 * 0118a450: str r0,[sp,#0x10]
 * 0118a452: ldr r0,[r7,#0xc]
 * 0118a454: str r0,[sp,#0xc]
 */


/* VagUdsCodingSetting::VagUdsCodingSetting(Ecu*, std::__ndk1::shared_ptr<StringWhitelist> const&,
   int, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&, char
   const*, std::__ndk1::shared_ptr<Interpretation> const&, VagSetting::AvailBy) */

void __thiscall
VagUdsCodingSetting::VagUdsCodingSetting
          (VagUdsCodingSetting *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,
          undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_8)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagSetting::VagSetting
            ((VagSetting *)this,param_2,8,param_1,0x600,param_3,param_4,param_5,param_6,&local_1c,1,
             param_8);
  FUN_00d4dec4(&local_1c);
  *(undefined ***)this = &PTR__WhitelistBasedSetting_014b5688;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


