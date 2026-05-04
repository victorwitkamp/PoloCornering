/*
 * VagSetting_ctor
 * ELF symbol address: 0x0113B1EC
 * Ghidra address: 0x0114B1EC (ELF + 0x10000 image delta)
 * ELF symbol size: 80 bytes
 * Symbol: _ZN10VagSettingC1ERKNSt6__ndk110shared_ptrI15StringWhitelistEENS_4TypeEP3EcutiRKNS0_6vectorIhNS0_9allocatorIhEEEEPKcRKNS1_I14InterpretationEERKNS1_IKNS9_IyNSA_IyEEEEEEN7Setting11ConsistencyENS_7AvailByE
 * Program: libCarista.so
 * Resolved function: VagSetting::VagSetting @ 0114b1ec
 * Signature: undefined __thiscall VagSetting(VagSetting * this, shared_ptr * param_1, Type param_2, Ecu * param_3, ushort param_4, int param_5, vector * param_6, char * param_7, shared_ptr * param_8, shared_ptr * param_9, Consistency param_10, AvailBy param_11)
 * Return type: undefined
 * Function body: [[0114b1ec, 0114b233]]
 * Parameters:
 *   [0] VagSetting * this
 *   [1] shared_ptr * param_1
 *   [2] typedef Type undefined param_2
 *   [3] Ecu * param_3
 *   [4] ushort param_4
 *   [5] int param_5
 *   [6] vector * param_6
 *   [7] char * param_7
 *   [8] shared_ptr * param_8
 *   [9] shared_ptr * param_9
 *   [10] typedef Consistency undefined param_10
 *   [11] typedef AvailBy undefined param_11
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e7f20
 *   VagSetting::VagSetting @ 01415930 -> COMPUTED_CALL from 01415938
 * Direct callees/references:
 *   READ Stack[0x18] from 0114b1f2
 *   WRITE Stack[-0x20] from 0114b1f4
 *   READ Stack[0x14] from 0114b1f6
 *   WRITE Stack[-0x24] from 0114b1f8
 *   READ Stack[0x10] from 0114b1fa
 *   WRITE Stack[-0x28] from 0114b1fc
 *   READ Stack[0xc] from 0114b1fe
 *   WRITE Stack[-0x2c] from 0114b200
 *   READ Stack[0x8] from 0114b202
 *   WRITE Stack[-0x30] from 0114b204
 *   READ Stack[0x4] from 0114b206
 *   WRITE Stack[-0x34] from 0114b208
 *   READ Stack[0x0] from 0114b20a
 *   WRITE Stack[-0x38] from 0114b20c
 *   READ 0114b234 from 0114b20e
 *   READ 014db5f0 from 0114b212
 *   READ 00c8f360 from 0114b214
 *   READ 00c8f364 from 0114b214
 *   WRITE Stack[-0x18] from 0114b218
 *   UNCONDITIONAL_CALL WhitelistBasedSetting<StringWhitelist>::WhitelistBasedSetting @ 0140ec70 from 0114b21c
 *   READ Stack[0x1c] from 0114b220
 *   READ 0114b238 from 0114b226
 *   READ 014df1f4 from 0114b22a
 *   DATA 014b54c0 from 0114b22e
 */

/* Ghidra function: VagSetting::VagSetting @ 0114b1ec */

/* First instructions after recreation:
 * Memory bytes: b0b502af8ab03c6a0694fc690594bc6904947c6903943c690294fc680194bc68
 * 0114b1ec: push {r4,r5,r7,lr}
 * 0114b1ee: add r7,sp,#0x8
 * 0114b1f0: sub sp,#0x28
 * 0114b1f2: ldr r4,[r7,#0x20]
 * 0114b1f4: str r4,[sp,#0x18]
 * 0114b1f6: ldr r4,[r7,#0x1c]
 * 0114b1f8: str r4,[sp,#0x14]
 * 0114b1fa: ldr r4,[r7,#0x18]
 * 0114b1fc: str r4,[sp,#0x10]
 * 0114b1fe: ldr r4,[r7,#0x14]
 * 0114b200: str r4,[sp,#0xc]
 * 0114b202: ldr r4,[r7,#0x10]
 * 0114b204: str r4,[sp,#0x8]
 * 0114b206: ldr r4,[r7,#0xc]
 * 0114b208: str r4,[sp,#0x4]
 * 0114b20a: ldr r4,[r7,#0x8]
 * 0114b20c: str r4,[sp,#0x0]
 * 0114b20e: ldr r4,[0x0114b234]
 * 0114b210: add r4,pc
 * 0114b212: ldr r4,[r4,#0x0]
 * 0114b214: ldrd r4,r5,[r4,#0x0]
 * 0114b218: strd r4,r5,[sp,#0x20]
 * 0114b21c: blx 0x0140ec70
 * 0114b220: ldr r1,[r7,#0x24]
 */


/* VagSetting::VagSetting(std::__ndk1::shared_ptr<StringWhitelist> const&, VagSetting::Type, Ecu*,
   unsigned short, int, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   const&, char const*, std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, Setting::Consistency, VagSetting::AvailBy) */

void __thiscall VagSetting::VagSetting(void)

{
  undefined4 *puVar1;
  undefined1 in_stack_0000001c;
  
  puVar1 = (undefined4 *)WhitelistBasedSetting<StringWhitelist>::WhitelistBasedSetting();
  *(undefined1 *)(puVar1 + 0x17) = in_stack_0000001c;
  *puVar1 = &PTR__WhitelistBasedSetting_014b54c0;
  return;
}


