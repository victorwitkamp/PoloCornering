/*
 * JNI_ChangeSettingOperation_native_ctor_helper
 * ELF symbol address: 0x00CB674C
 * Ghidra address: 0x00CC674C (ELF + 0x10000 image delta)
 * ELF symbol size: 64 bytes
 * Symbol: local helper called by ChangeSettingOperation_initNative
 * Program: libCarista.so
 * Resolved function: FUN_00cc674c @ 00cc674c
 * Signature: undefined FUN_00cc674c(void)
 * Return type: undefined
 * Function body: [[00cc674c, 00cc6781]]
 * Parameters:
 * Direct callers:
 *   Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative @ 00cc645c -> UNCONDITIONAL_CALL from 00cc64b8
 * Direct callees/references:
 *   READ 00cc6784 from 00cc6754
 *   READ 014da87c from 00cc6758
 *   READ 015a7014 from 00cc675a
 *   WRITE Stack[-0x14] from 00cc675c
 *   READ Stack[0x0] from 00cc675e
 *   WRITE Stack[-0x20] from 00cc6760
 *   UNCONDITIONAL_CALL FUN_00cd7054 @ 00cd7054 from 00cc676a
 *   READ Stack[-0x14] from 00cc676e
 *   READ 00cc6788 from 00cc6770
 *   READ 014da87c from 00cc6774
 *   READ 015a7014 from 00cc6776
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00cc677e
 */

/* Ghidra function: FUN_00cc674c @ 00cc674c */

/* First instructions after recreation:
 * Memory bytes: dfb506af14460a460b497944096809680391b968cde90031a7f10d01234610f0
 * 00cc674c: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 00cc674e: add r7,sp,#0x18
 * 00cc6750: mov r4,r2
 * 00cc6752: mov r2,r1
 * 00cc6754: ldr r1,[0x00cc6784]
 * 00cc6756: add r1,pc
 * 00cc6758: ldr r1,[r1,#0x0]
 * 00cc675a: ldr r1,[r1,#0x0]
 * 00cc675c: str r1,[sp,#0xc]
 * 00cc675e: ldr r1,[r7,#0x8]
 * 00cc6760: strd r3,r1,[sp,#0x0]
 * 00cc6764: sub.w r1,r7,#0xd
 * 00cc6768: mov r3,r4
 * 00cc676a: bl 0x00cd7054
 * 00cc676e: ldr r0,[sp,#0xc]
 * 00cc6770: ldr r1,[0x00cc6788]
 * 00cc6772: add r1,pc
 * 00cc6774: ldr r1,[r1,#0x0]
 * 00cc6776: ldr r1,[r1,#0x0]
 * 00cc6778: cmp r1,r0
 * 00cc677a: it eq
 * 00cc677c: pop.eq {r0,r1,r2,r3,r4,r6,r7,pc}
 * 00cc677e: blx 0x013fa400
 * 00cc678c: push {r4,r6,r7,lr}
 */


undefined8
FUN_00cc674c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_00cd7054(param_1,&stack0xffffffeb,param_2,param_3,param_4,param_5,param_3);
  if (__stack_chk_guard == iVar1) {
    return CONCAT44(param_5,param_4);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


