/*
 * VagOperationDelegate_getSettingRawAddress
 * ELF symbol address: 0x012620EC
 * Ghidra address: 0x012720EC (ELF + 0x10000 image delta)
 * ELF symbol size: 204 bytes
 * Symbol: _ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::getSettingRawAddress @ 012720ec
 * Signature: undefined __thiscall getSettingRawAddress(VagOperationDelegate * this, shared_ptr * param_1)
 * Return type: undefined
 * Function body: [[012720ec, 0127219b]]
 * Parameters:
 *   [0] VagOperationDelegate * this
 *   [1] shared_ptr * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba77c
 * Direct callees/references:
 *   READ 012721b0 from 012720f8
 *   READ 014da87c from 012720fe
 *   READ 015a7014 from 01272100
 *   WRITE Stack[-0x1c] from 01272102
 *   UNCONDITIONAL_CALL OperationDelegate::getSettingRawAddress @ 0141f940 from 01272106
 *   CONDITIONAL_JUMP VagOperationDelegate::getSettingRawAddress @ 012720ec from 01272118
 *   WRITE Stack[-0x24] from 0127211a
 *   WRITE Stack[-0x20] from 0127211e
 *   CONDITIONAL_JUMP VagOperationDelegate::getSettingRawAddress @ 012720ec from 01272120
 *   CONDITIONAL_JUMP VagOperationDelegate::getSettingRawAddress @ 012720ec from 01272130
 *   UNCONDITIONAL_CALL FUN_00d1756c @ 00d1756c from 01272142
 *   READ Stack[-0x1c] from 0127214a
 *   READ 012721b4 from 0127214c
 *   READ 014da87c from 01272150
 *   READ 015a7014 from 01272152
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01272166
 *   CONDITIONAL_JUMP VagOperationDelegate::getSettingRawAddress @ 012720ec from 0127216c
 *   WRITE Stack[-0x24] from 0127216e
 *   WRITE Stack[-0x20] from 01272172
 *   CONDITIONAL_JUMP VagOperationDelegate::getSettingRawAddress @ 012720ec from 01272174
 *   CONDITIONAL_JUMP VagOperationDelegate::getSettingRawAddress @ 012720ec from 01272184
 *   UNCONDITIONAL_CALL FUN_010bc068 @ 010bc068 from 01272196
 *   UNCONDITIONAL_JUMP VagOperationDelegate::getSettingRawAddress @ 012720ec from 0127219a
 */

/* Ghidra function: VagOperationDelegate::getSettingRawAddress @ 012720ec */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d84b006462d480c4678440068006803903046adf11cec8046
 * 012720ec: push {r4,r5,r6,r7,lr}
 * 012720ee: add r7,sp,#0xc
 * 012720f0: push.w r8
 * 012720f4: sub sp,#0x10
 * 012720f6: mov r6,r0
 * 012720f8: ldr r0,[0x012721b0]
 * 012720fa: mov r4,r1
 * 012720fc: add r0,pc
 * 012720fe: ldr r0,[r0,#0x0]
 * 01272100: ldr r0,[r0,#0x0]
 * 01272102: str r0,[sp,#0xc]
 * 01272104: mov r0,r6
 * 01272106: blx 0x0141f940
 * 0127210a: mov r8,r0
 * 0127210c: ldr r0,[r4,#0x0]
 * 0127210e: mov r5,r1
 * 01272110: ldrb r1,[r0,#0xc]
 * 01272112: cmp r1,#0x9
 * 01272114: it ne
 * 01272116: cmp.ne r1,#0x5
 * 01272118: bne 0x0127216a
 * 0127211a: str r0,[sp,#0x4]
 * 0127211c: ldr r0,[r4,#0x4]
 * 0127211e: str r0,[sp,#0x8]
 */


/* VagOperationDelegate::getSettingRawAddress(std::__ndk1::shared_ptr<Setting> const&) */

void __thiscall
VagOperationDelegate::getSettingRawAddress(VagOperationDelegate *this,shared_ptr *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  OperationDelegate::getSettingRawAddress((OperationDelegate *)this,param_1);
  iVar3 = *(int *)param_1;
  cVar1 = *(char *)(iVar3 + 0xc);
  if (cVar1 == '\t' || cVar1 == '\x05') {
    local_20 = *(int *)(param_1 + 4);
    if (local_20 != 0) {
      piVar4 = (int *)(local_20 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar2 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar2);
      *piVar4 = *piVar4 + 1;
    }
    local_24 = iVar3;
    (**(code **)(*(int *)this + 0x1f0))(this,&local_24);
    FUN_00d1756c(&local_24);
  }
  else if (cVar1 == '\x04') {
    local_20 = *(int *)(param_1 + 4);
    if (local_20 != 0) {
      piVar4 = (int *)(local_20 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar2 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar2);
      *piVar4 = *piVar4 + 1;
    }
    local_24 = iVar3;
    (**(code **)(*(int *)this + 0x1ec))(this,&local_24);
    FUN_010bc068(&local_24);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c,__stack_chk_guard);
  }
  return;
}


