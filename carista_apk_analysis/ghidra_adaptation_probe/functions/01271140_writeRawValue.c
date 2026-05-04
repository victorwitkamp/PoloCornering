/* VagOperationDelegate::writeRawValue @ 01271140 */


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


