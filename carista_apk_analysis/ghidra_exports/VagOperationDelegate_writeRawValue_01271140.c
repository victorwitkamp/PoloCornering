/*
 * VagOperationDelegate_writeRawValue
 * ELF symbol address: 0x01261140
 * Ghidra address: 0x01271140 (ELF + 0x10000 image delta)
 * ELF symbol size: 704 bytes
 * Symbol: _ZN20VagOperationDelegate13writeRawValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::writeRawValue @ 01271140
 * Signature: undefined __stdcall writeRawValue(ulonglong param_1, vector * param_2, shared_ptr * param_3)
 * Return type: undefined
 * Function body: [[01271140, 01271215] [01271220, 01271393]]
 * Parameters:
 *   [0] ulonglong param_1
 *   [1] vector * param_2
 *   [2] shared_ptr * param_3
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba724
 * Direct callees/references:
 *   READ 012713e8 from 0127114c
 *   READ 014da87c from 01271156
 *   READ 015a7014 from 01271158
 *   WRITE Stack[-0x28] from 0127115a
 *   WRITE Stack[-0xe8] from 01271174
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::isFail @ 01427da0 from 0127117e
 *   CONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 01271182
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::stateAs<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>> @ 01428060 from 01271188
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 0127118c
 *   READ Stack[0x4] from 0127118e
 *   WRITE Stack[-0x8c] from 01271196
 *   CONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 0127119a
 *   CONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 012711aa
 *   READ Stack[-0x88] from 012711ac
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 012711ae
 *   WRITE Stack[-0x5c] from 012711b2
 *   WRITE Stack[-0x50] from 012711b6
 *   READ 012713ec from 012711b8
 *   DATA 014baa84 from 012711be
 *   WRITE Stack[-0x60] from 012711be
 *   CONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 012711c0
 *   CONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 012711d0
 *   WRITE Stack[-0x50] from 012711d4
 *   UNCONDITIONAL_CALL RunOnScopeExit::RunOnScopeExit @ 014225c0 from 012711d8
 *   UNCONDITIONAL_CALL FUN_00d2682a @ 00d2682a from 012711de
 *   UNCONDITIONAL_CALL FUN_011e01a0 @ 011e01a0 from 012711e4
 *   CONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 012711f2
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 0141fee0 from 012711f6
 *   CONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 0127120a
 *   READ Stack[0x0] from 0127120e
 *   COMPUTED_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 01271212
 *   DATA 01271216 from 01271212
 *   UNCONDITIONAL_CALL FUN_00cd5ef0 @ 00cd5ef0 from 01271224
 *   WRITE Stack[-0xe8] from 0127122e
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0127123e
 *   READ Stack[-0xbc] from 01271242
 *   UNCONDITIONAL_CALL Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>::Result @ 01428070 from 0127124a
 *   UNCONDITIONAL_CALL Result<BytesModel,void>::~Result @ 013fdbf0 from 01271250
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 01271254
 *   READ 012713e4 from 01271256
 *   UNCONDITIONAL_CALL Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>::Result @ 0141f6c0 from 0127125a
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 0127125e
 *   WRITE Stack[-0xe8] from 01271266
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 01271274
 *   WRITE Stack[-0xe8] from 0127127c
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 0127128a
 *   WRITE Stack[-0xe8] from 012712be
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 012712ca
 *   WRITE Stack[-0xe8] from 012712d2
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeRawValue @ 01271140 from 012712e0
 *   WRITE Stack[-0xe8] from 01271314
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::operator= @ 0141fef0 from 01271326
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::~Result @ 013fd720 from 0127132c
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::stateAs<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>> @ 0141f6b0 from 01271334
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::~Result @ 013fd720 from 0127133a
 *   UNCONDITIONAL_CALL RunOnScopeExit::~RunOnScopeExit @ 01422610 from 01271340
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 01271346
 *   READ Stack[-0x28] from 0127134a
 *   READ 012713f0 from 0127134c
 *   READ 014da87c from 01271350
 *   READ 015a7014 from 01271352
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 01271360
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 01271366
 *   READ 012713f4 from 0127136e
 *   PARAM 00c043d9 from 01271370
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 01271372
 *   UNCONDITIONAL_CALL IllegalArgumentException::IllegalArgumentException @ 013fa5e0 from 0127137c
 *   READ 012713f8 from 01271382
 *   READ 014da89c from 01271386
 *   PARAM 01437dc8 from 01271386
 *   READ 012713fc from 01271388
 *   READ 014da8a0 from 0127138c
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 0127138c
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 01271390
 */

/* Ghidra function: VagOperationDelegate::writeRawValue @ 01271140 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000fb1b08046a6480d469b46784492460068006830900868d0f8
 * 01271140: push {r4,r5,r6,r7,lr}
 * 01271142: add r7,sp,#0xc
 * 01271144: push {r8,r9,r10,r11}
 * 01271148: sub sp,#0xc4
 * 0127114a: mov r8,r0
 * 0127114c: ldr r0,[0x012713e8]
 * 0127114e: mov r5,r1
 * 01271150: mov r11,r3
 * 01271152: add r0,pc
 * 01271154: mov r10,r2
 * 01271156: ldr r0,[r0,#0x0]
 * 01271158: ldr r0,[r0,#0x0]
 * 0127115a: str r0,[sp,#0xc0]
 * 0127115c: ldr r0,[r1,#0x0]
 * 0127115e: ldr.w r1,[r0,#0x154]
 * 01271162: mov r0,r5
 * 01271164: blx r1
 * 01271166: mov r2,r0
 * 01271168: ldr r0,[r5,#0x0]
 * 0127116a: mov r1,r5
 * 0127116c: movs r3,#0x2
 * 0127116e: ldr.w r4,[r0,#0x194]
 * 01271172: movs r0,#0x0
 * 01271174: str r0,[sp,#0x0]
 */


/* VagOperationDelegate::writeRawValue(unsigned long long, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, std::__ndk1::shared_ptr<Progress> const&) */

void VagOperationDelegate::writeRawValue(ulonglong param_1,vector *param_2,shared_ptr *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  IllegalArgumentException *this;
  int *piVar5;
  int *piVar6;
  undefined4 in_stack_00000000;
  undefined4 *in_stack_00000004;
  undefined1 auStack_e0 [12];
  Result<BytesModel,void> aRStack_d4 [24];
  int *local_bc;
  shared_ptr *psStack_b8;
  Result<EmptyModel,void> aRStack_b0 [36];
  undefined4 local_8c;
  int local_88;
  Result<VagEcuInfo,void> aRStack_84 [36];
  undefined **local_60;
  undefined4 local_5c;
  int iStack_58;
  undefined ***local_50;
  RunOnScopeExit aRStack_48 [32];
  int local_28;
  
  piVar5 = (int *)(param_1 >> 0x20);
  local_28 = __stack_chk_guard;
  uVar2 = (**(code **)(*piVar5 + 0x154))(piVar5);
  (**(code **)(*piVar5 + 0x194))(aRStack_84,piVar5,uVar2,2,0);
  iVar3 = Result<VagEcuInfo,void>::isFail(aRStack_84);
  if (iVar3 != 0) {
    Result<VagEcuInfo,void>::
    stateAs<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ();
    goto LAB_01271344;
  }
  local_8c = *in_stack_00000004;
  local_88 = in_stack_00000004[1];
  if (local_88 == 0) {
    iStack_58 = 0;
  }
  else {
    piVar6 = (int *)(local_88 + 4);
    do {
      ExclusiveAccess(piVar6);
      bVar1 = (bool)hasExclusiveAccess(piVar6);
    } while (!bVar1);
    *piVar6 = *piVar6 + 1;
    iStack_58 = local_88;
  }
  local_60 = &PTR_FUN_012805c4_1_014baa84;
  if (iStack_58 != 0) {
    piVar6 = (int *)(iStack_58 + 4);
    do {
      ExclusiveAccess(piVar6);
      bVar1 = (bool)hasExclusiveAccess(piVar6);
    } while (!bVar1);
    *piVar6 = *piVar6 + 1;
  }
  local_50 = &local_60;
  local_5c = local_8c;
  RunOnScopeExit::RunOnScopeExit(aRStack_48);
  FUN_00d2682a(&local_60);
  FUN_011e01a0(&local_8c);
  iVar3 = (**(code **)(*(int *)*in_stack_00000004 + 0xc))();
  if (iVar3 == 0) {
    Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
    ::Result((Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              *)param_1,-1000);
  }
  else {
    Result<EmptyModel,void>::Result(aRStack_b0);
    uVar2 = (**(code **)(*piVar5 + 0x15c))(piVar5,*(code **)(*piVar5 + 0x15c),param_2,param_3);
    switch(uVar2) {
    case 0:
    case 1:
      uVar2 = FUN_00cd5ef0(auStack_e0,in_stack_00000000);
      (**(code **)(*piVar5 + 0x1b8))(aRStack_d4,piVar5,param_2,param_3,uVar2,in_stack_00000004);
      FUN_00cb7f50(auStack_e0);
      Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
      ::Result((Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
                *)param_1,*local_bc,psStack_b8);
      Result<BytesModel,void>::~Result(aRStack_d4);
      goto LAB_01271338;
    case 2:
    case 3:
      (**(code **)(*piVar5 + 0x1c8))(aRStack_d4,piVar5,param_2,param_3,in_stack_00000000);
      break;
    case 4:
      (**(code **)(*piVar5 + 0x1cc))(aRStack_d4,piVar5,param_2,param_3,in_stack_00000000);
      break;
    case 5:
      uVar2 = (**(code **)(*piVar5 + 0x154))(piVar5,*(code **)(*piVar5 + 0x154),param_2,param_3);
      uVar4 = (**(code **)(*piVar5 + 0x180))(piVar5,*(code **)(*piVar5 + 0x180),param_2,param_3);
      uVar4 = (**(code **)(*piVar5 + 0x1e0))(piVar5,uVar4);
      (**(code **)(*piVar5 + 0x1c4))(aRStack_d4,piVar5,uVar2,uVar4,in_stack_00000000);
      break;
    default:
      this = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(aRStack_d4,"Invalid VAG setting type");
      IllegalArgumentException::IllegalArgumentException(this,(basic_string *)aRStack_d4);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    case 7:
    case 8:
      (**(code **)(*piVar5 + 0x1c0))(aRStack_d4,piVar5,param_2,param_3,in_stack_00000000);
      break;
    case 9:
      uVar2 = (**(code **)(*piVar5 + 0x154))(piVar5,*(code **)(*piVar5 + 0x154),param_2,param_3);
      uVar4 = (**(code **)(*piVar5 + 0x180))(piVar5,*(code **)(*piVar5 + 0x180),param_2,param_3);
      uVar4 = (**(code **)(*piVar5 + 0x1d4))(piVar5,uVar4);
      (**(code **)(*piVar5 + 0x1c4))(aRStack_d4,piVar5,uVar2,uVar4,in_stack_00000000);
    }
    Result<EmptyModel,void>::operator=(aRStack_b0,(Result *)aRStack_d4);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)aRStack_d4);
    Result<EmptyModel,void>::
    stateAs<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ();
LAB_01271338:
    Result<EmptyModel,void>::~Result(aRStack_b0);
  }
  RunOnScopeExit::~RunOnScopeExit(aRStack_48);
LAB_01271344:
  Result<VagEcuInfo,void>::~Result(aRStack_84);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


