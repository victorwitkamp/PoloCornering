/*
 * WriteVagCodingCommand_ctor
 * ELF symbol address: 0x00D03048
 * Ghidra address: 0x00D13048 (ELF + 0x10000 image delta)
 * ELF symbol size: 552 bytes
 * Symbol: _ZN21WriteVagCodingCommandC1EP3EcuRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEERKNS2_10shared_ptrIS7_EEN10VagEcuInfo10CodingTypeESC_
 * Program: libCarista.so
 * Resolved function: WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048
 * Signature: undefined __thiscall WriteVagCodingCommand(WriteVagCodingCommand * this, Ecu * param_1, vector * param_2, shared_ptr * param_3, CodingType param_4, shared_ptr * param_5)
 * Return type: undefined
 * Function body: [[00d13048, 00d1311b] [00d1311e, 00d13175] [00d13178, 00d131b7] [00d131ba, 00d131e9]]
 * Parameters:
 *   [0] WriteVagCodingCommand * this
 *   [1] Ecu * param_1
 *   [2] vector * param_2
 *   [3] shared_ptr * param_3
 *   [4] /Demangler/VagEcuInfo/CodingType
pack(disabled)
Structure CodingType {
}
Length: 0 Alignment: 1
 param_4
 *   [5] shared_ptr * param_5
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3130
 *   WriteVagCodingCommand::WriteVagCodingCommand @ 01402170 -> COMPUTED_CALL from 01402178
 * Direct callees/references:
 *   READ 00d13230 from 00d13052
 *   READ 014da87c from 00d1305c
 *   READ 015a7014 from 00d1305e
 *   WRITE Stack[-0x28] from 00d13060
 *   READ 00d13234 from 00d13062
 *   READ 014dabb4 from 00d13066
 *   READ 00c89e4c from 00d13068
 *   UNCONDITIONAL_CALL SingleResponseCommand<EmptyModel>::SingleResponseCommand @ 013fdc10 from 00d1306c
 *   READ 00d13238 from 00d13070
 *   READ 014db2f4 from 00d13076
 *   DATA 0143c558 from 00d1307a
 *   UNCONDITIONAL_CALL FUN_00cd5ef0 @ 00cd5ef0 from 00d13082
 *   READ Stack[0x0] from 00d1308c
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d13098
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d130a8
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d130bc
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d130cc
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d130d6
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d130e2
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d130e6
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d130ea
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d130ee
 *   READ 00d13254 from 00d130f6
 *   PARAM 008f6dc3 from 00d130f8
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d130fa
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d13104
 *   READ 00d13258 from 00d1310a
 *   READ 014da89c from 00d1310e
 *   PARAM 01437dc8 from 00d1310e
 *   READ 00d1325c from 00d13110
 *   READ 014da8a0 from 00d13114
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d13114
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d13118
 *   CONDITIONAL_JUMP WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 from 00d13128
 *   READ Stack[-0x28] from 00d1312a
 *   READ 00d1326c from 00d1312c
 *   READ 014da87c from 00d13130
 *   READ 015a7014 from 00d13132
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d13142
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d13148
 *   READ 00d1323c from 00d13150
 *   PARAM 00ab28b6 from 00d13152
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d13154
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d1315e
 *   READ 00d13240 from 00d13164
 *   READ 014da89c from 00d13168
 *   PARAM 01437dc8 from 00d13168
 *   READ 00d13244 from 00d1316a
 *   READ 014da8a0 from 00d1316e
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d1316e
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d13172
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d1317a
 *   UNCONDITIONAL_CALL std::__ndk1::to_string @ 014020f0 from 00d1318a
 *   READ 00d13248 from 00d13190
 *   PARAM 0086af38 from 00d13194
 *   UNCONDITIONAL_CALL FUN_00cbe7e4 @ 00cbe7e4 from 00d13196
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d131a0
 *   READ 00d1324c from 00d131a6
 *   READ 014da89c from 00d131aa
 *   PARAM 01437dc8 from 00d131aa
 *   READ 00d13250 from 00d131ac
 *   READ 014da8a0 from 00d131b0
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d131b0
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d131b4
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d131bc
 *   READ 00d13260 from 00d131c4
 *   PARAM 00c30ac4 from 00d131c6
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d131c8
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 00d131d2
 *   READ 00d13264 from 00d131d8
 *   READ 014da89c from 00d131dc
 *   PARAM 01437dc8 from 00d131dc
 *   READ 00d13268 from 00d131de
 *   READ 014da8a0 from 00d131e2
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d131e2
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d131e6
 */

/* Ghidra function: WriteVagCodingCommand::WriteVagCodingCommand @ 00d13048 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9fe0f804677481e46154678440122006800680690744878440068
 * 00d13048: push {r4,r5,r6,r7,lr}
 * 00d1304a: add r7,sp,#0xc
 * 00d1304c: push {r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11}
 * 00d13050: mov r8,r0
 * 00d13052: ldr r0,[0x00d13230]
 * 00d13054: mov r6,r3
 * 00d13056: mov r5,r2
 * 00d13058: add r0,pc
 * 00d1305a: movs r2,#0x1
 * 00d1305c: ldr r0,[r0,#0x0]
 * 00d1305e: ldr r0,[r0,#0x0]
 * 00d13060: str r0,[sp,#0x18]
 * 00d13062: ldr r0,[0x00d13234]
 * 00d13064: add r0,pc
 * 00d13066: ldr r0,[r0,#0x0]
 * 00d13068: ldr r3,[r0,#0x0]
 * 00d1306a: mov r0,r8
 * 00d1306c: blx 0x013fdc10
 * 00d13070: ldr r0,[0x00d13238]
 * 00d13072: mov r9,r8
 * 00d13074: add r0,pc
 * 00d13076: ldr r0,[r0,#0x0]
 * 00d13078: adds r0,#0x8
 * 00d1307a: str.w r0,[r9],#0x10
 */


/* WriteVagCodingCommand::WriteVagCodingCommand(Ecu*, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > const> const&, VagEcuInfo::CodingType, std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> > const> const&) */

void __thiscall
WriteVagCodingCommand::WriteVagCodingCommand
          (WriteVagCodingCommand *this,Ecu *param_1,int *param_2,int *param_3,uint param_5,
          int *param_6)

{
  bool bVar1;
  int iVar2;
  IllegalArgumentException *pIVar3;
  int iVar4;
  int *piVar5;
  Ecu *pEStack_40;
  int *piStack_3c;
  int *piStack_38;
  
  iVar2 = __stack_chk_guard;
  pEStack_40 = param_1;
  piStack_3c = param_2;
  piStack_38 = param_3;
  SingleResponseCommand<EmptyModel>::SingleResponseCommand
            ((SingleResponseCommand<EmptyModel> *)this,param_1,1,1);
  *(undefined ***)this = &PTR__WriteVagCodingCommand_0143c558;
  FUN_00cd5ef0(this + 0x10,param_2);
  iVar4 = param_3[1];
  *(int *)(this + 0x1c) = *param_3;
  *(int *)(this + 0x20) = iVar4;
  if (iVar4 != 0) {
    piVar5 = (int *)(iVar4 + 4);
    do {
      ExclusiveAccess(piVar5);
      bVar1 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar1);
    *piVar5 = *piVar5 + 1;
  }
  iVar4 = param_6[1];
  *(int *)(this + 0x28) = *param_6;
  *(uint *)(this + 0x24) = param_5;
  *(int *)(this + 0x2c) = iVar4;
  if (iVar4 != 0) {
    piVar5 = (int *)(iVar4 + 4);
    do {
      ExclusiveAccess(piVar5);
      bVar1 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar1);
    *piVar5 = *piVar5 + 1;
  }
  if (param_2[1] - *param_2 != 6) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&stack0xffffffcc,"Workshop code must be exactly 6 bytes");
    IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&stack0xffffffcc);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (((int *)*param_3)[1] - *(int *)*param_3 != 4) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    std::__ndk1::to_string((uint)&pEStack_40);
    FUN_00cbe7e4(&stack0xffffffcc,"Component ID must be exactly 4 bytes but was: ",&pEStack_40);
    IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&stack0xffffffcc);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (param_5 == 2) {
    if (((int *)*param_6)[1] - *(int *)*param_6 != 3) {
      pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(&stack0xffffffcc,"Short coding value must be exactly 3 bytes");
      IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&stack0xffffffcc);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
  }
  else if (param_5 < 2) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&stack0xffffffcc,"Cannot write a coding value when type is NONE or UNKNOWN");
    IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&stack0xffffffcc);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (__stack_chk_guard != iVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}


