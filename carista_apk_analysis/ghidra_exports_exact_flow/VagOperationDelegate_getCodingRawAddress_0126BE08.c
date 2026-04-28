/*
 * VagOperationDelegate_getCodingRawAddress
 * ELF symbol address: 0x0125BE08
 * Ghidra address: 0x0126BE08 (ELF + 0x10000 image delta)
 * ELF symbol size: 492 bytes
 * Symbol: _ZN20VagOperationDelegate19getCodingRawAddressEP3Ecut
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::getCodingRawAddress @ 0126be08
 * Signature: undefined __stdcall getCodingRawAddress(Ecu * param_1, ushort param_2)
 * Return type: undefined
 * Function body: [[0126be08, 0126bf51] [0126bf54, 0126bf83]]
 * Parameters:
 *   [0] Ecu * param_1
 *   [1] ushort param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba778
 * Direct callees/references:
 *   READ 0126bfc8 from 0126be14
 *   READ 014da87c from 0126be1e
 *   READ 015a7014 from 0126be20
 *   WRITE Stack[-0x1c] from 0126be22
 *   READ Stack[-0x28] from 0126be30
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be36
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be38
 *   READ 0126bfd8 from 0126be3a
 *   READ 014db304 from 0126be40
 *   PARAM 0143e680 from 0126be40
 *   READ 0126bfdc from 0126be42
 *   READ 014deff0 from 0126be46
 *   PARAM 014b514c from 0126be46
 *   UNCONDITIONAL_CALL __dynamic_cast @ 013fadd0 from 0126be4a
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be4e
 *   UNCONDITIONAL_CALL VagEcu::getEquivalent @ 01415ac0 from 0126be52
 *   READ Stack[-0x24] from 0126be6a
 *   WRITE Stack[-0x58] from 0126be70
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be74
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be84
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be8a
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be90
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be94
 *   UNCONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be98
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126be9a
 *   CONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126beaa
 *   READ 0126bff0 from 0126beb6
 *   READ 014df1d4 from 0126bebe
 *   READ 00c95e1a from 0126bec0
 *   UNCONDITIONAL_JUMP VagOperationDelegate::getCodingRawAddress @ 0126be08 from 0126bec6
 *   UNCONDITIONAL_CALL FUN_00d08540 @ 00d08540 from 0126bee0
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 0126bee6
 *   READ Stack[-0x1c] from 0126beea
 *   READ 0126bfe0 from 0126beec
 *   READ 014da87c from 0126bef0
 *   READ 015a7014 from 0126bef2
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 0126bf06
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 0126bf0c
 *   READ Stack[-0x58] from 0126bf1e
 *   READ Stack[-0x50] from 0126bf22
 *   READ 0126bfcc from 0126bf2c
 *   PARAM 0077af23 from 0126bf2e
 *   UNCONDITIONAL_CALL StringUtils::format @ 013fd2a0 from 0126bf30
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 0126bf3a
 *   READ 0126bfd0 from 0126bf40
 *   READ 014da89c from 0126bf44
 *   PARAM 01437dc8 from 0126bf44
 *   READ 0126bfd4 from 0126bf46
 *   READ 014da8a0 from 0126bf4a
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 0126bf4a
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 0126bf4e
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 0126bf56
 *   READ 0126bfe4 from 0126bf5e
 *   PARAM 0077af4a from 0126bf60
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 0126bf62
 *   UNCONDITIONAL_CALL IllegalStateException::IllegalStateException @ 013fadb0 from 0126bf6c
 *   READ 0126bfe8 from 0126bf72
 *   READ 014da944 from 0126bf76
 *   PARAM 01437dd4 from 0126bf76
 *   READ 0126bfec from 0126bf78
 *   READ 014da948 from 0126bf7c
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 0126bf7c
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 0126bf80
 */

/* Ghidra function: VagOperationDelegate::getCodingRawAddress @ 0126be08 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048d90b080466c480e46414678443246006800680f90d8f80000
 * 0126be08: push {r4,r5,r6,r7,lr}
 * 0126be0a: add r7,sp,#0xc
 * 0126be0c: push.w r8
 * 0126be10: sub sp,#0x40
 * 0126be12: mov r8,r0
 * 0126be14: ldr r0,[0x0126bfc8]
 * 0126be16: mov r6,r1
 * 0126be18: mov r1,r8
 * 0126be1a: add r0,pc
 * 0126be1c: mov r2,r6
 * 0126be1e: ldr r0,[r0,#0x0]
 * 0126be20: ldr r0,[r0,#0x0]
 * 0126be22: str r0,[sp,#0x3c]
 * 0126be24: ldr.w r0,[r8,#0x0]
 * 0126be28: ldr.w r3,[r0,#0x1f8]
 * 0126be2c: add r0,sp,#0x18
 * 0126be2e: blx r3
 * 0126be30: ldr r0,[sp,#0x30]
 * 0126be32: ldr r0,[r0,#0x0]
 * 0126be34: cmp r0,#0x1
 * 0126be36: bne 0x0126bf0a
 * 0126be38: cbz r6,0x0126be50
 * 0126be3a: ldr r0,[0x0126bfd8]
 * 0126be3c: movs r3,#0x0
 */


/* VagOperationDelegate::getCodingRawAddress(Ecu*, unsigned short) */

void VagOperationDelegate::getCodingRawAddress(Ecu *param_1,ushort param_2)

{
  bool bVar1;
  Ecu *pEVar2;
  int iVar3;
  IllegalArgumentException *this;
  IllegalStateException *this_00;
  Ecu *pEVar4;
  int *piVar5;
  undefined4 uVar6;
  Ecu *pEVar7;
  Ecu *pEVar8;
  undefined4 local_58;
  int iStack_54;
  int local_50;
  basic_string abStack_4c [12];
  Result<VagEcuInfo,void> aRStack_40 [24];
  int *local_28;
  int *local_24;
  int local_1c;
  
  pEVar4 = (Ecu *)(uint)param_2;
  local_1c = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0x1f8))(aRStack_40,param_1,pEVar4);
  if (*local_28 != 1) {
    this = (IllegalArgumentException *)__cxa_allocate_exception(8);
    (**(code **)(*(int *)pEVar4 + 0x10))(&local_58,pEVar4);
    if (((byte)local_58 & 1) == 0) {
      local_50 = (int)&local_58 + 1;
    }
    StringUtils::format((char *)abStack_4c,"Non-connected ECU given for coding: %s",local_50);
    IllegalArgumentException::IllegalArgumentException(this,abStack_4c);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if ((pEVar4 == (Ecu *)0x0) ||
     (pEVar2 = (Ecu *)__dynamic_cast(pEVar4,&Ecu::typeinfo,&VagEcu::typeinfo,0),
     pEVar2 == (Ecu *)0x0)) {
    pEVar2 = (Ecu *)VagEcu::getEquivalent(pEVar4);
  }
  pEVar8 = *(Ecu **)(pEVar2 + 0x14);
  if (pEVar8 != pEVar4 && pEVar2 != pEVar4) {
    pEVar8 = (Ecu *)0x0;
  }
  pEVar7 = *(Ecu **)(pEVar2 + 0x18);
  if (pEVar7 != pEVar4 && pEVar2 != pEVar4) {
    pEVar7 = (Ecu *)0x0;
  }
  local_58 = *local_24;
  iStack_54 = local_24[1];
  if (iStack_54 != 0) {
    piVar5 = (int *)(iStack_54 + 4);
    do {
      ExclusiveAccess(piVar5);
      bVar1 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar1);
    *piVar5 = *piVar5 + 1;
  }
  if (*(int *)(local_58 + 4) == 1) {
    if (*(int *)(local_58 + 0x20) == 2) {
      uVar6 = 2;
    }
    else {
      if (*(int *)(local_58 + 0x20) != 3) {
        this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
        FUN_00cb4d44(abStack_4c,"Raw coding setting requested for ECU that doesn\'t have coding");
        IllegalStateException::IllegalStateException(this_00,abStack_4c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(this_00,&IllegalStateException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      uVar6 = 3;
    }
    (**(code **)(*(int *)param_1 + 0x17c))(param_1,uVar6,pEVar8,0);
  }
  else {
    if ((pEVar8 == (Ecu *)0x0) ||
       (iVar3 = (**(code **)(*(int *)param_1 + 0x184))(param_1,pEVar8), iVar3 == 0)) {
      pEVar8 = pEVar7;
    }
    (**(code **)(*(int *)param_1 + 0x17c))(param_1,8,pEVar8,0x600);
  }
  FUN_00d08540(&local_58);
  Result<VagEcuInfo,void>::~Result(aRStack_40);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c,__stack_chk_guard);
  }
  return;
}


