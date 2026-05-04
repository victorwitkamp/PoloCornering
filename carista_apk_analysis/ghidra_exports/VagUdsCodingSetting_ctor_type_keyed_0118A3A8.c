/*
 * VagUdsCodingSetting_ctor_type_keyed
 * ELF symbol address: 0x0117A3A8
 * Ghidra address: 0x0118A3A8 (ELF + 0x10000 image delta)
 * ELF symbol size: 124 bytes
 * Symbol: _ZN19VagUdsCodingSettingC1ERKNSt6__ndk110shared_ptrI15StringWhitelistEEN10VagSetting4TypeEP3EcutiRKNS0_6vectorIhNS0_9allocatorIhEEEEPKcRKNS1_I14InterpretationEENS6_7AvailByE
 * Program: libCarista.so
 * Resolved function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a3a8
 * Signature: undefined __thiscall VagUdsCodingSetting(VagUdsCodingSetting * this, shared_ptr * param_1, Type param_2, Ecu * param_3, ushort param_4, int param_5, vector * param_6, char * param_7, shared_ptr * param_8, AvailBy param_9)
 * Return type: undefined
 * Function body: [[0118a3a8, 0118a40d]]
 * Parameters:
 *   [0] VagUdsCodingSetting * this
 *   [1] shared_ptr * param_1
 *   [2] typedef Type undefined param_2
 *   [3] Ecu * param_3
 *   [4] ushort param_4
 *   [5] int param_5
 *   [6] vector * param_6
 *   [7] char * param_7
 *   [8] shared_ptr * param_8
 *   [9] typedef AvailBy undefined param_9
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e9e98
 *   VagUdsCodingSetting::VagUdsCodingSetting @ 0141d710 -> COMPUTED_CALL from 0141d718
 * Direct callees/references:
 *   READ 0118a418 from 0118a3b0
 *   READ 014da87c from 0118a3b4
 *   READ 015a7014 from 0118a3b6
 *   WRITE Stack[-0x14] from 0118a3b8
 *   WRITE Stack[-0x1c] from 0118a3bc
 *   READ Stack[0x14] from 0118a3c0
 *   WRITE Stack[-0x24] from 0118a3c2
 *   WRITE Stack[-0x28] from 0118a3c6
 *   WRITE Stack[-0x2c] from 0118a3ca
 *   READ Stack[0x10] from 0118a3cc
 *   WRITE Stack[-0x30] from 0118a3ce
 *   READ Stack[0xc] from 0118a3d0
 *   WRITE Stack[-0x34] from 0118a3d2
 *   READ Stack[0x8] from 0118a3d4
 *   WRITE Stack[-0x38] from 0118a3d6
 *   READ Stack[0x4] from 0118a3d8
 *   WRITE Stack[-0x3c] from 0118a3da
 *   READ Stack[0x0] from 0118a3dc
 *   WRITE Stack[-0x40] from 0118a3de
 *   UNCONDITIONAL_CALL VagSetting::VagSetting @ 01415930 from 0118a3e2
 *   UNCONDITIONAL_CALL FUN_00d4dec4 @ 00d4dec4 from 0118a3e8
 *   READ 0118a41c from 0118a3ec
 *   READ 014df2f8 from 0118a3f0
 *   DATA 014b5688 from 0118a3f4
 *   READ Stack[-0x14] from 0118a3f6
 *   READ 0118a420 from 0118a3f8
 *   READ 014da87c from 0118a3fc
 *   READ 015a7014 from 0118a3fe
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 0118a40a
 */

/* Ghidra function: VagUdsCodingSetting::VagUdsCodingSetting @ 0118a3a8 */

/* First instructions after recreation:
 * Memory bytes: d0b502af8cb0044619487844006800680b900020cde90900f869079001200690
 * 0118a3a8: push {r4,r6,r7,lr}
 * 0118a3aa: add r7,sp,#0x8
 * 0118a3ac: sub sp,#0x30
 * 0118a3ae: mov r4,r0
 * 0118a3b0: ldr r0,[0x0118a418]
 * 0118a3b2: add r0,pc
 * 0118a3b4: ldr r0,[r0,#0x0]
 * 0118a3b6: ldr r0,[r0,#0x0]
 * 0118a3b8: str r0,[sp,#0x2c]
 * 0118a3ba: movs r0,#0x0
 * 0118a3bc: strd r0,r0,[sp,#0x24]
 * 0118a3c0: ldr r0,[r7,#0x1c]
 * 0118a3c2: str r0,[sp,#0x1c]
 * 0118a3c4: movs r0,#0x1
 * 0118a3c6: str r0,[sp,#0x18]
 * 0118a3c8: add r0,sp,#0x24
 * 0118a3ca: str r0,[sp,#0x14]
 * 0118a3cc: ldr r0,[r7,#0x18]
 * 0118a3ce: str r0,[sp,#0x10]
 * 0118a3d0: ldr r0,[r7,#0x14]
 * 0118a3d2: str r0,[sp,#0xc]
 * 0118a3d4: ldr r0,[r7,#0x10]
 * 0118a3d6: str r0,[sp,#0x8]
 * 0118a3d8: ldr r0,[r7,#0xc]
 */


/* VagUdsCodingSetting::VagUdsCodingSetting(std::__ndk1::shared_ptr<StringWhitelist> const&,
   VagSetting::Type, Ecu*, unsigned short, int, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&, VagSetting::AvailBy) */

void __thiscall VagUdsCodingSetting::VagUdsCodingSetting(VagUdsCodingSetting *this)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagSetting::VagSetting((VagSetting *)this);
  FUN_00d4dec4(&local_1c);
  *(undefined ***)this = &PTR__WhitelistBasedSetting_014b5688;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


