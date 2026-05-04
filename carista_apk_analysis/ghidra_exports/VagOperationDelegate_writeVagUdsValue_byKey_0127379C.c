/*
 * VagOperationDelegate_writeVagUdsValue_byKey
 * ELF symbol address: 0x0126379C
 * Ghidra address: 0x0127379C (ELF + 0x10000 image delta)
 * ELF symbol size: 68 bytes
 * Symbol: _ZN20VagOperationDelegate16writeVagUdsValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::writeVagUdsValue @ 0127379c
 * Signature: undefined __stdcall writeVagUdsValue(ulonglong param_1, vector * param_2)
 * Return type: undefined
 * Function body: [[0127379c, 012737df]]
 * Parameters:
 *   [0] ulonglong param_1
 *   [1] vector * param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba7f4
 * Direct callees/references:
 *   READ Stack[0x0] from 012737d2
 *   WRITE Stack[-0x28] from 012737d4
 */

/* Ghidra function: VagOperationDelegate::writeVagUdsValue @ 0127379c */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9c00b804608680c461d461646d0f8541120468847814620683246
 * 0127379c: push {r4,r5,r6,r7,lr}
 * 0127379e: add r7,sp,#0xc
 * 012737a0: push {r6,r7,r8,r9,r11}
 * 012737a4: mov r8,r0
 * 012737a6: ldr r0,[r1,#0x0]
 * 012737a8: mov r4,r1
 * 012737aa: mov r5,r3
 * 012737ac: mov r6,r2
 * 012737ae: ldr.w r1,[r0,#0x154]
 * 012737b2: mov r0,r4
 * 012737b4: blx r1
 * 012737b6: mov r9,r0
 * 012737b8: ldr r0,[r4,#0x0]
 * 012737ba: mov r2,r6
 * 012737bc: mov r3,r5
 * 012737be: ldr.w r1,[r0,#0x158]
 * 012737c2: mov r0,r4
 * 012737c4: blx r1
 * 012737c6: mov r3,r0
 * 012737c8: ldr r0,[r4,#0x0]
 * 012737ca: mov r1,r4
 * 012737cc: mov r2,r9
 * 012737ce: ldr.w r5,[r0,#0x1c4]
 * 012737d2: ldr r0,[r7,#0x8]
 */


/* VagOperationDelegate::writeVagUdsValue(unsigned long long, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::writeVagUdsValue(ulonglong param_1,vector *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 in_stack_00000000;
  undefined1 *puVar4;
  
  piVar3 = (int *)(param_1 >> 0x20);
  puVar4 = &stack0xfffffff8;
  uVar1 = (**(code **)(*piVar3 + 0x154))(piVar3);
  uVar2 = (**(code **)(*piVar3 + 0x158))(piVar3,*(code **)(*piVar3 + 0x158),param_2);
  (**(code **)(*piVar3 + 0x1c4))((int)param_1,piVar3,uVar1,uVar2,in_stack_00000000,puVar4);
  return;
}


