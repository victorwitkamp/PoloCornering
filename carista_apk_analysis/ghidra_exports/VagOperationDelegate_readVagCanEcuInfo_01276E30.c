/*
 * VagOperationDelegate_readVagCanEcuInfo
 * ELF symbol address: 0x01266E30
 * Ghidra address: 0x01276E30 (ELF + 0x10000 image delta)
 * ELF symbol size: 620 bytes
 * Symbol: _ZN20VagOperationDelegate17readVagCanEcuInfoEP9VagCanEcu
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::readVagCanEcuInfo @ 01276e30
 * Signature: undefined __stdcall readVagCanEcuInfo(VagCanEcu * param_1)
 * Return type: undefined
 * Function body: [[01276e30, 01277035]]
 * Parameters:
 *   [0] VagCanEcu * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba7cc
 * Direct callees/references:
 *   WRITE Stack[-0x2c] from 01276e3a
 *   READ 01277088 from 01276e3e
 *   READ 014da87c from 01276e44
 *   READ 015a7014 from 01276e46
 *   WRITE Stack[-0x28] from 01276e48
 *   UNCONDITIONAL_CALL FUN_0127713c @ 0127713c from 01276e4e
 *   READ Stack[-0x58] from 01276e52
 *   WRITE Stack[-0x84] from 01276e56
 *   WRITE Stack[-0x80] from 01276e5a
 *   WRITE Stack[-0x58] from 01276e5c
 *   UNCONDITIONAL_CALL Progress::NUL @ 0141f070 from 01276e62
 *   UNCONDITIONAL_CALL OperationDelegate::runCommand<VagEcuInfoWithCoding> @ 01428290 from 01276e6e
 *   UNCONDITIONAL_CALL FUN_011e01a0 @ 011e01a0 from 01276e74
 *   UNCONDITIONAL_CALL FUN_01277170 @ 01277170 from 01276e7a
 *   UNCONDITIONAL_CALL FUN_01277182 @ 01277182 from 01276e80
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::isFail @ 014012e0 from 01276e86
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276e8a
 *   READ Stack[-0x38] from 01276e8c
 *   WRITE Stack[-0x84] from 01276e98
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276e9c
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276eae
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276eb0
 *   READ Stack[-0x38] from 01276eb2
 *   READ Stack[-0x2c] from 01276eb6
 *   WRITE Stack[-0x58] from 01276ebe
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276ec2
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276ed2
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::Result @ 01428240 from 01276eda
 *   UNCONDITIONAL_CALL VagOperationDelegate::validateVagCanEcuInfo @ 014282a0 from 01276ee4
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 01276eec
 *   UNCONDITIONAL_CALL FUN_00d08540 @ 00d08540 from 01276ef2
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276ef8
 *   READ Stack[-0x34] from 01276efa
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276f02
 *   READ Stack[-0x2c] from 01276f08
 *   READ Stack[-0x34] from 01276f20
 *   WRITE Stack[-0x88] from 01276f26
 *   READ Stack[-0x2c] from 01276f32
 *   READ Stack[-0x34] from 01276f40
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276f4a
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276f5e
 *   UNCONDITIONAL_CALL FUN_0111cba4 @ 0111cba4 from 01276f62
 *   WRITE Stack[-0x84] from 01276f6a
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276f6e
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276f7e
 *   UNCONDITIONAL_CALL Math::toExact<unsigned_char,unsigned_int> @ 013fd660 from 01276f84
 *   READ Stack[-0x84] from 01276f8c
 *   WRITE Stack[-0x88] from 01276f98
 *   UNCONDITIONAL_CALL FUN_00d08630 @ 00d08630 from 01276fa2
 *   READ Stack[-0x34] from 01276fa6
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276fac
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::Result @ 01428280 from 01276fb4
 *   UNCONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276fb8
 *   READ Stack[-0x38] from 01276fba
 *   WRITE Stack[-0x84] from 01276fc0
 *   WRITE Stack[-0x80] from 01276fc2
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276fc4
 *   CONDITIONAL_JUMP VagOperationDelegate::readVagCanEcuInfo @ 01276e30 from 01276fd4
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::Result @ 01428240 from 01276fdc
 *   UNCONDITIONAL_CALL FUN_00d08540 @ 00d08540 from 01276fe2
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::~Result @ 01401300 from 01276fe8
 *   READ Stack[-0x28] from 01276fec
 *   READ 0127708c from 01276fee
 *   READ 014da87c from 01276ff2
 *   READ 015a7014 from 01276ff4
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01277002
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 01277008
 *   READ 01277090 from 01277010
 *   PARAM 006ec961 from 01277012
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 01277014
 *   UNCONDITIONAL_CALL IllegalStateException::IllegalStateException @ 013fadb0 from 0127701e
 *   READ 01277094 from 01277024
 *   READ 014da944 from 01277028
 *   PARAM 01437dd4 from 01277028
 *   READ 01277098 from 0127702a
 *   READ 014da948 from 0127702e
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 0127702e
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 01277032
 */

/* Ghidra function: VagOperationDelegate::readVagCanEcuInfo @ 01276e30 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000f99b0179280469248894678440068006818900ca817a900f0
 * 01276e30: push {r4,r5,r6,r7,lr}
 * 01276e32: add r7,sp,#0xc
 * 01276e34: push {r8,r9,r10,r11}
 * 01276e38: sub sp,#0x64
 * 01276e3a: str r2,[sp,#0x5c]
 * 01276e3c: mov r8,r0
 * 01276e3e: ldr r0,[0x01277088]
 * 01276e40: mov r9,r1
 * 01276e42: add r0,pc
 * 01276e44: ldr r0,[r0,#0x0]
 * 01276e46: ldr r0,[r0,#0x0]
 * 01276e48: str r0,[sp,#0x60]
 * 01276e4a: add r0,sp,#0x30
 * 01276e4c: add r1,sp,#0x5c
 * 01276e4e: bl 0x0127713c
 * 01276e52: ldrd r0,r1,[sp,#0x30]
 * 01276e56: str r0,[sp,#0x4]
 * 01276e58: movs r0,#0x0
 * 01276e5a: str r1,[sp,#0x8]
 * 01276e5c: strd r0,r0,[sp,#0x30]
 * 01276e60: add r0,sp,#0x28
 * 01276e62: blx 0x0141f070
 * 01276e66: add r0,sp,#0x38
 * 01276e68: add r2,sp,#0x4
 */


/* VagOperationDelegate::readVagCanEcuInfo(VagCanEcu*) */

void VagOperationDelegate::readVagCanEcuInfo(VagCanEcu *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  IllegalStateException *this;
  VagOperationDelegate *in_r1;
  int iVar4;
  Ecu *in_r2;
  uint uVar5;
  int local_84;
  int local_80;
  Progress aPStack_60 [8];
  int local_58;
  int iStack_54;
  shared_ptr asStack_50 [24];
  int *local_38;
  int *local_34;
  Ecu *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_2c = in_r2;
  FUN_0127713c(&local_58,&local_2c);
  local_84 = local_58;
  local_80 = iStack_54;
  local_58 = 0;
  iStack_54 = 0;
  Progress::NUL(aPStack_60);
  OperationDelegate::runCommand<VagEcuInfoWithCoding>(asStack_50,(shared_ptr *)in_r1);
  FUN_011e01a0(aPStack_60);
  FUN_01277170(&local_84);
  FUN_01277182(&local_58);
  iVar2 = Result<VagEcuInfoWithCoding,void>::isFail((Result<VagEcuInfoWithCoding,void> *)asStack_50)
  ;
  if (iVar2 == 0) {
    iVar2 = *local_38;
    local_58 = *local_34;
    iStack_54 = local_34[1];
    if (iStack_54 != 0) {
      piVar3 = (int *)(iStack_54 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    Result<VagEcuInfo,void>::Result
              ((Result<VagEcuInfo,void> *)&local_84,iVar2,(shared_ptr *)&local_58);
    iVar2 = validateVagCanEcuInfo(in_r1,local_2c,(Result *)&local_84);
    Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_84);
    FUN_00d08540(&local_58);
    if (iVar2 == 0) {
      Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,-6);
      goto LAB_01276fe6;
    }
    if (*(int *)(*local_34 + 0x20) == 2) {
      (**(code **)(*(int *)in_r1 + 0x17c))();
      (**(code **)(*(int *)in_r1 + 0xb0))();
    }
    (**(code **)(*(int *)in_r1 + 0x17c))();
    iVar2 = *local_34;
    piVar3 = *(int **)(iVar2 + 0x10);
    if (piVar3 == (int *)0x0) {
      this = (IllegalStateException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(&local_84,"VAG CAN ECU info should always contain submodules");
      IllegalStateException::IllegalStateException(this,(basic_string *)&local_84);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this,&IllegalStateException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    uVar5 = 0;
    while (uVar5 < (uint)(piVar3[1] - *piVar3 >> 3)) {
      piVar3 = (int *)FUN_0111cba4(piVar3,uVar5);
      local_84 = *piVar3;
      local_80 = piVar3[1];
      if (local_80 != 0) {
        piVar3 = (int *)(local_80 + 4);
        do {
          ExclusiveAccess(piVar3);
          bVar1 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar1);
        *piVar3 = *piVar3 + 1;
      }
      uVar5 = uVar5 + 1;
      Math::toExact<unsigned_char,unsigned_int>(uVar5);
      (**(code **)(*(int *)in_r1 + 0xb0))();
      FUN_00d08630(&local_84);
      iVar2 = *local_34;
      piVar3 = *(int **)(iVar2 + 0x10);
    }
    iVar4 = *local_38;
    local_80 = local_34[1];
    local_84 = iVar2;
    if (local_80 != 0) {
      piVar3 = (int *)(local_80 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
  }
  else {
    iVar4 = *local_38;
    local_84 = *local_34;
    local_80 = local_34[1];
    if (local_80 != 0) {
      piVar3 = (int *)(local_80 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
  }
  Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,iVar4,(shared_ptr *)&local_84);
  FUN_00d08540((shared_ptr *)&local_84);
LAB_01276fe6:
  Result<VagEcuInfoWithCoding,void>::~Result((Result<VagEcuInfoWithCoding,void> *)asStack_50);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


