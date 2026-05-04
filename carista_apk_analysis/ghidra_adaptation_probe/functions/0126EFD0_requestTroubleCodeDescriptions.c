/* VagOperationDelegate::requestTroubleCodeDescriptions @ 0126efd0 */


/* VagOperationDelegate::requestTroubleCodeDescriptions(std::__ndk1::vector<std::__ndk1::shared_ptr<TroubleCode>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<TroubleCode> > > const&, Ecu*,
   std::__ndk1::function<void (int, Ecu*,
   std::__ndk1::shared_ptr<std::__ndk1::vector<std::__ndk1::shared_ptr<TroubleCode>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<TroubleCode> > > > const&)> const&) */

void __thiscall
VagOperationDelegate::requestTroubleCodeDescriptions
          (VagOperationDelegate *this,vector *param_1,Ecu *param_2,function *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  IllegalStateException *this_00;
  undefined4 local_fc;
  int iStack_f8;
  undefined4 local_f4;
  int iStack_f0;
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined4 local_e4;
  undefined4 uStack_e0;
  basic_string *local_dc;
  int iStack_d8;
  Result<VagEcuInfo,void> aRStack_d4 [28];
  int *local_b8;
  int *local_b0 [2];
  undefined4 *local_a8;
  undefined1 *puStack_a4;
  undefined4 local_a0;
  undefined1 uStack_99;
  VagOperationDelegate *local_98;
  undefined1 auStack_94 [12];
  undefined1 auStack_88 [24];
  Result<VagEcuInfo,void> aRStack_70 [36];
  basic_string *local_4c;
  int iStack_48;
  basic_string abStack_40 [16];
  undefined4 *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  OperationDelegate::getCachedTroubleCodesUntilFirstMissing((Ecu *)local_b0,(vector *)this);
  if (local_b0[0][1] - *local_b0[0] == *(int *)(param_1 + 4) - *(int *)param_1) {
    FUN_01249444(param_3,1,param_2,local_b0);
  }
  else {
    (**(code **)(*(int *)this + 0x1f8))(aRStack_d4,this,param_2);
    iVar3 = Result<VagEcuInfo,void>::isFail(aRStack_d4);
    if (iVar3 != 0) {
      this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(abStack_40,"Failed to get ecuInfo");
      IllegalStateException::IllegalStateException(this_00,abStack_40);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this_00,&IllegalStateException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    (**(code **)(*(int *)this + 0x20))(&local_dc,this);
    piVar2 = (int *)App::CARISTA_API_CLIENT;
    if (local_dc == (basic_string *)0x0) {
      uStack_e0 = 0;
      local_e4 = 0;
    }
    else {
      VagVin::getPdx((VagVin *)&local_ec,local_dc);
      local_e4 = local_ec;
      uStack_e0 = uStack_e8;
    }
    local_ec = 0;
    uStack_e8 = 0;
    iVar3 = *local_b8;
    local_f4 = *(undefined4 *)(iVar3 + 0x44);
    iStack_f0 = *(int *)(iVar3 + 0x48);
    if (iStack_f0 != 0) {
      piVar4 = (int *)(iStack_f0 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar1 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar1);
      *piVar4 = *piVar4 + 1;
      iVar3 = *local_b8;
    }
    local_fc = *(undefined4 *)(iVar3 + 0x4c);
    iStack_f8 = *(int *)(iVar3 + 0x50);
    if (iStack_f8 != 0) {
      piVar4 = (int *)(iStack_f8 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar1 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar1);
      *piVar4 = *piVar4 + 1;
    }
    uVar5 = (**(code **)(*(int *)this + 0x10))(this);
    local_98 = this;
    FUN_00cf6b54(auStack_94,param_1);
    FUN_0124aa9c(auStack_88,param_3);
    Result<VagEcuInfo,void>::Result(aRStack_70,(Result *)aRStack_d4);
    local_4c = local_dc;
    iStack_48 = iStack_d8;
    if (iStack_d8 != 0) {
      piVar4 = (int *)(iStack_d8 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar1 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar1);
      *piVar4 = *piVar4 + 1;
    }
    local_30 = (undefined4 *)0x0;
    puVar6 = operator_new(0x60);
    puVar6[2] = local_98;
    *puVar6 = &PTR_FUN_0127c9c4_1_014ba96c;
    local_a0 = 1;
    puStack_a4 = &uStack_99;
    local_a8 = puVar6;
    FUN_00cf6b54(puVar6 + 3,auStack_94);
    FUN_0124aa9c(puVar6 + 6,auStack_88);
    Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)(puVar6 + 0xc),(Result *)aRStack_70);
    local_30 = local_a8;
    puVar6[0x15] = local_4c;
    puVar6[0x16] = iStack_48;
    local_4c = (basic_string *)0x0;
    iStack_48 = 0;
    local_a8 = (undefined4 *)0x0;
    FUN_0127c9ac(&local_a8);
    (**(code **)(*piVar2 + 8))
              (piVar2,param_2,param_1,&local_e4,&local_f4,&local_fc,uVar5,abStack_40);
    FUN_011dc484(abStack_40);
    FUN_0126f2c8(&local_98);
    FUN_00cbba38(&local_fc);
    FUN_00cbba38(&local_f4);
    FUN_00cbba38(&local_e4);
    FUN_00cbd6dc(&local_ec);
    FUN_00cbba38(&local_dc);
    Result<VagEcuInfo,void>::~Result(aRStack_d4);
  }
  FUN_00ce1cf0(local_b0);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


