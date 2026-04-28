/*
 * Setting_ctor
 * ELF symbol address: 0x00D48AB0
 * Ghidra address: 0x00D58AB0 (ELF + 0x10000 image delta)
 * ELF symbol size: 1052 bytes
 * Symbol: _ZN7SettingC1EhP3EcutiRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEPKcRKNS2_10shared_ptrI14InterpretationEERKNSB_IKNS3_IyNS4_IyEEEEEENS_11ConsistencyEy
 * Program: libCarista.so
 * Resolved function: Setting::Setting @ 00d58ab0
 * Signature: undefined __thiscall Setting(Setting * this, uchar param_1, Ecu * param_2, ushort param_3, int param_4, vector * param_5, char * param_6, shared_ptr * param_7, shared_ptr * param_8, Consistency param_9, ulonglong param_10)
 * Return type: undefined
 * Function body: [[00d58ab0, 00d58b8d] [00d58b9e, 00d58be1] [00d58be4, 00d58c23] [00d58c26, 00d58c69] [00d58c6c, 00d58cab] [00d58cae, 00d58d2d] [00d58d30, 00d58d5f] [00d58d62, 00d58d91] [00d58d94, 00d58dc3] [00d58dc6, 00d58df5]]
 * Parameters:
 *   [0] Setting * this
 *   [1] uchar param_1
 *   [2] Ecu * param_2
 *   [3] ushort param_3
 *   [4] int param_4
 *   [5] vector * param_5
 *   [6] char * param_6
 *   [7] shared_ptr * param_7
 *   [8] shared_ptr * param_8
 *   [9] typedef Consistency undefined param_9
 *   [10] ulonglong param_10
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e44f0
 *   Setting::Setting @ 01407070 -> COMPUTED_CALL from 01407078
 * Direct callees/references:
 *   READ 00d58e54 from 00d58abc
 *   READ Stack[0x0] from 00d58ac0
 *   READ Stack[0x4] from 00d58ac4
 *   READ 014da87c from 00d58ac6
 *   READ 015a7014 from 00d58ac8
 *   WRITE Stack[-0x28] from 00d58aca
 *   READ 00d58e58 from 00d58ad8
 *   READ 014db924 from 00d58adc
 *   DATA 014471f4 from 00d58ae0
 *   WRITE Stack[-0x40] from 00d58aec
 *   UNCONDITIONAL_CALL FUN_00cd5ef0 @ 00cd5ef0 from 00d58af0
 *   READ Stack[0x8] from 00d58af4
 *   WRITE Stack[-0x44] from 00d58afa
 *   READ Stack[0x10] from 00d58b00
 *   WRITE Stack[-0x48] from 00d58b08
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58b10
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58b20
 *   READ Stack[0x18] from 00d58b28
 *   WRITE Stack[-0x4c] from 00d58b30
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58b38
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58b48
 *   UNCONDITIONAL_CALL FUN_00cba564 @ 00cba564 from 00d58b5e
 *   READ Stack[-0x30] from 00d58b62
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58b66
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58b72
 *   UNCONDITIONAL_CALL _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 013ff0d0 from 00d58b78
 *   READ Stack[-0x30] from 00d58b7c
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58b86
 *   COMPUTED_JUMP Setting::Setting @ 00d58ab0 from 00d58b8a
 *   DATA 00d58b8e from 00d58b8a
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58bae
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d58bb4
 *   READ 00d58e5c from 00d58bbc
 *   PARAM 00b7c4d9 from 00d58bbe
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d58bc0
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d58bca
 *   READ 00d58e60 from 00d58bd0
 *   READ 014da89c from 00d58bd4
 *   PARAM 01437dc8 from 00d58bd4
 *   READ 00d58e64 from 00d58bd6
 *   READ 014da8a0 from 00d58bda
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d58bda
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d58bde
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58bf2
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d58bf6
 *   READ 00d58e8c from 00d58bfe
 *   PARAM 00b7c4d9 from 00d58c00
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d58c02
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d58c0c
 *   READ 00d58e90 from 00d58c12
 *   READ 014da89c from 00d58c16
 *   PARAM 01437dc8 from 00d58c16
 *   READ 00d58e94 from 00d58c18
 *   READ 014da8a0 from 00d58c1c
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d58c1c
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d58c20
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58c38
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d58c3c
 *   READ 00d58e74 from 00d58c44
 *   PARAM 00b7c4d9 from 00d58c46
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d58c48
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d58c52
 *   READ 00d58e78 from 00d58c58
 *   READ 014da89c from 00d58c5c
 *   PARAM 01437dc8 from 00d58c5c
 *   READ 00d58e7c from 00d58c5e
 *   READ 014da8a0 from 00d58c62
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d58c62
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d58c66
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58c70
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58c7a
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d58c7e
 *   READ 00d58e80 from 00d58c86
 *   PARAM 00b7c4d9 from 00d58c88
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d58c8a
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d58c94
 *   READ 00d58e84 from 00d58c9a
 *   READ 014da89c from 00d58c9e
 *   PARAM 01437dc8 from 00d58c9e
 *   READ 00d58e88 from 00d58ca0
 *   READ 014da8a0 from 00d58ca4
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d58ca4
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d58ca8
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58cc0
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58cc6
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58ccc
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58cd4
 *   CONDITIONAL_JUMP Setting::Setting @ 00d58ab0 from 00d58cda
 *   UNCONDITIONAL_CALL FUN_00cba5b0 @ 00cba5b0 from 00d58cde
 *   READ Stack[-0x28] from 00d58ce2
 *   READ 00d58ec8 from 00d58ce4
 *   READ 014da87c from 00d58ce8
 *   READ 015a7014 from 00d58cea
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d58cfa
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d58d00
 *   READ 00d58ea4 from 00d58d08
 *   PARAM 00bedcc7 from 00d58d0a
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d58d0c
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d58d16
 *   READ 00d58ea8 from 00d58d1c
 *   READ 014da89c from 00d58d20
 *   PARAM 01437dc8 from 00d58d20
 *   READ 00d58eac from 00d58d22
 *   READ 014da8a0 from 00d58d26
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d58d26
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d58d2a
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d58d32
 *   READ 00d58ebc from 00d58d3a
 *   PARAM 00a5677b from 00d58d3c
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d58d3e
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d58d48
 *   READ 00d58ec0 from 00d58d4e
 *   READ 014da89c from 00d58d52
 *   PARAM 01437dc8 from 00d58d52
 *   READ 00d58ec4 from 00d58d54
 *   READ 014da8a0 from 00d58d58
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d58d58
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d58d5c
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d58d64
 *   READ 00d58eb0 from 00d58d6c
 */

/* Ghidra function: Setting::Setting @ 00d58ab0 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000f8bb00646dff89403bc687844fd68006800680a900020b060
 * 00d58ab0: push {r4,r5,r6,r7,lr}
 * 00d58ab2: add r7,sp,#0xc
 * 00d58ab4: push {r8,r9,r10,r11}
 * 00d58ab8: sub sp,#0x2c
 * 00d58aba: mov r6,r0
 * 00d58abc: ldr.w r0,[0x00d58e54]
 * 00d58ac0: ldr r4,[r7,#0x8]
 * 00d58ac2: add r0,pc
 * 00d58ac4: ldr r5,[r7,#0xc]
 * 00d58ac6: ldr r0,[r0,#0x0]
 * 00d58ac8: ldr r0,[r0,#0x0]
 * 00d58aca: str r0,[sp,#0x28]
 * 00d58acc: movs r0,#0x0
 * 00d58ace: str r0,[r6,#0x8]
 * 00d58ad0: str r4,[r6,#0x18]
 * 00d58ad2: strh r3,[r6,#0x14]
 * 00d58ad4: str r2,[r6,#0x10]
 * 00d58ad6: strb r1,[r6,#0xc]
 * 00d58ad8: ldr r1,[0x00d58e58]
 * 00d58ada: add r1,pc
 * 00d58adc: ldr r1,[r1,#0x0]
 * 00d58ade: adds r1,#0x8
 * 00d58ae0: str r1,[r6,#0x0]
 * 00d58ae2: mov r1,r6
 */


/* Setting::Setting(unsigned char, Ecu*, unsigned short, int, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, Setting::Consistency, unsigned long long) */

void __thiscall
Setting::Setting(Setting *this,Setting param_1,undefined4 param_2,undefined2 param_3,
                undefined4 param_4,int *param_5,int param_6,undefined4 *param_7,int *param_8,
                undefined4 param_10,int param_11,int param_12)

{
  uint uVar1;
  uint uVar2;
  IllegalArgumentException *pIVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  longlong lVar7;
  basic_string abStack_3c [12];
  int local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x18) = param_4;
  *(undefined2 *)(this + 0x14) = param_3;
  *(undefined4 *)(this + 0x10) = param_2;
  this[0xc] = param_1;
  *(undefined ***)this = &PTR__Setting_014471f4;
  *(undefined4 *)(this + 4) = 0;
  FUN_00cd5ef0(this + 0x1c,param_5);
  iVar4 = param_7[1];
  *(undefined4 *)(this + 0x2c) = *param_7;
  *(int *)(this + 0x28) = param_6;
  *(int *)(this + 0x30) = iVar4;
  if (iVar4 != 0) {
    piVar5 = (int *)(iVar4 + 4);
    do {
      ExclusiveAccess(piVar5);
      bVar6 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar6);
    *piVar5 = *piVar5 + 1;
  }
  iVar4 = param_8[1];
  *(int *)(this + 0x38) = *param_8;
  *(undefined4 *)(this + 0x34) = param_10;
  *(int *)(this + 0x3c) = iVar4;
  if (iVar4 != 0) {
    piVar5 = (int *)(iVar4 + 4);
    do {
      ExclusiveAccess(piVar5);
      bVar6 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar6);
    *piVar5 = *piVar5 + 1;
  }
  *(undefined4 *)(this + 0x4c) = 0;
  *(int *)(this + 0x40) = param_11;
  *(int *)(this + 0x44) = param_12;
  *(undefined4 *)(this + 0x50) = 0;
  this[0x48] = (Setting)0x0;
  FUN_00cba564(local_30);
  if ((local_30[0] != 0) && (*(int *)(local_30[0] + 0x38) == 4 || *(int *)(local_30[0] + 0x38) == 2)
     ) {
    lVar7 = _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE(param_5);
    uVar2 = (uint)((ulonglong)lVar7 >> 0x20);
    uVar1 = (uint)lVar7;
    switch(*(undefined1 *)(local_30[0] + 0x3c)) {
    case 1:
      uVar2 = uVar1 ^ 0xff | uVar2;
      bVar6 = uVar2 == 0;
      if (bVar6) {
        uVar2 = param_5[1] - *param_5;
      }
      if (!bVar6 || uVar2 != 1) {
        pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
        FUN_00cb4d44(abStack_3c,"Bitmask length or value are incorrect.");
        IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      break;
    case 2:
      uVar2 = uVar1 ^ 0xffff | uVar2;
      bVar6 = uVar2 != 0;
      if (!bVar6) {
        uVar2 = param_5[1] - *param_5;
      }
      if (bVar6 || uVar2 != 2) {
        pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
        FUN_00cb4d44(abStack_3c,"Bitmask length or value are incorrect.");
        IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      break;
    case 3:
      uVar2 = uVar1 ^ 0xffffff | uVar2;
      bVar6 = uVar2 == 0;
      if (bVar6) {
        uVar2 = param_5[1] - *param_5;
      }
      if (!bVar6 || uVar2 != 3) {
        pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
        FUN_00cb4d44(abStack_3c,"Bitmask length or value are incorrect.");
        IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      break;
    case 4:
      if ((lVar7 != 0xffffffff) || (param_5[1] - *param_5 != 4)) {
        pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
        FUN_00cb4d44(abStack_3c,"Bitmask length or value are incorrect.");
        IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
      break;
    default:
      pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(abStack_3c,
                   "Invalid bitmask for signed value it should be either 1, 2, 3, 4 or 8 bytes.");
      IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    case 8:
      iVar4 = (uVar1 & uVar2) + 1;
      bVar6 = iVar4 == 0;
      if (bVar6) {
        iVar4 = param_5[1] - *param_5;
      }
      if (!bVar6 || iVar4 != 8) {
        pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
        FUN_00cb4d44(abStack_3c,"Bitmask length or value are incorrect.");
        IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                    IllegalStateException::~IllegalStateException);
      }
    }
  }
  if (param_6 == 0) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_3c,"Setting created with null nameResId");
    IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  param_8 = (int *)*param_8;
  if ((param_8 != (int *)0x0) && (*param_8 == param_8[1])) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_3c,"Setting created with an empty vector of access codes");
    IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (param_11 == 0 && param_12 == 0) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_3c,"Setting must be available for at least one adapter");
    IllegalArgumentException::IllegalArgumentException(pIVar3,abStack_3c);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  FUN_00cba5b0(local_30);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}


