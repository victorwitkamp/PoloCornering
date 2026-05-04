/* VagOperationDelegate::getVagSettingAvailabilityForEcu @ 0127075c */


/* VagOperationDelegate::getVagSettingAvailabilityForEcu(std::__ndk1::shared_ptr<VagSetting> const&,
   std::__ndk1::shared_ptr<VagEcuInfo> const&) */

void __thiscall
VagOperationDelegate::getVagSettingAvailabilityForEcu
          (VagOperationDelegate *this,shared_ptr *param_1,shared_ptr *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  basic_string *pbVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  Ecu *pEVar9;
  undefined4 local_64;
  undefined4 uStack_60;
  basic_string *local_5c [3];
  int local_50;
  int iStack_4c;
  int local_48;
  int iStack_44;
  Result<VagEcuInfo,void> aRStack_40 [28];
  int *local_24;
  int *local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = (**(code **)(**(int **)param_1 + 0x3c))();
  if (iVar2 != 0) {
    piVar3 = local_1c;
    piVar6 = __stack_chk_guard;
    if (__stack_chk_guard == local_1c) {
      (*(code *)&LAB_01427fe0)(local_1c,param_1,param_2);
      return;
    }
    goto LAB_0127098e;
  }
  iVar2 = *(int *)param_1;
  uVar8 = (uint)*(byte *)(iVar2 + 0x5c);
  if (uVar8 < 6) {
    if ((1 << uVar8 & 0x1bU) == 0) {
      if (uVar8 != 5) goto LAB_0127087c;
      (**(code **)(*(int *)this + 0x20))(local_5c,this);
      if (local_5c[0] == (basic_string *)0x0) {
        Log::d("VIN is not available");
      }
      else {
        VagVin::getPdx((VagVin *)&local_48,local_5c[0]);
        local_50 = 0;
        iStack_4c = 0;
        local_64 = 0;
        uStack_60 = 0;
        VagVin::getVagFileIdentifier
                  ((VagVin *)aRStack_40,(shared_ptr *)&local_48,(shared_ptr *)&local_50,
                   (shared_ptr *)&local_64);
        FUN_00cbd6dc(&local_64);
        FUN_00cbd6dc(&local_50);
        (**(code **)(**(int **)(*(int *)param_1 + 0x54) + 0x10))
                  (*(int **)(*(int *)param_1 + 0x54),aRStack_40);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)aRStack_40);
        FUN_00cbd6dc(&local_48);
      }
      FUN_00cbba38(local_5c);
    }
    else {
      iVar4 = *(int *)param_2;
      if (*(int *)(iVar4 + 4) != 2) goto LAB_0127087e;
      pEVar9 = *(Ecu **)(iVar2 + 0x10);
      if ((pEVar9 == (Ecu *)0x0) ||
         (iVar2 = __dynamic_cast(pEVar9,&Ecu::typeinfo,&VagEcu::typeinfo,0), iVar2 == 0)) {
        pEVar9 = (Ecu *)VagEcu::getEquivalent(pEVar9);
        uVar8 = (uint)*(byte *)(*(int *)param_1 + 0x5c);
      }
      uVar7 = 0x40;
      if (uVar8 == 4) {
        uVar7 = 0xc0;
      }
      if (uVar8 == 1) {
        uVar7 = 0xc0;
      }
      (**(code **)(*(int *)this + 0x194))(aRStack_40,this,*(undefined4 *)(pEVar9 + 0x18),uVar7);
      iVar2 = Result<VagEcuInfo,void>::isFail(aRStack_40);
      if (iVar2 == 0) {
        local_48 = 0;
        iStack_44 = 0;
        if (*(char *)(*(int *)param_1 + 0x5c) == '\x04') {
          (**(code **)(*(int *)this + 0x20))(local_5c,this);
          if (local_5c[0] == (basic_string *)0x0) {
            Log::d("VIN is not available");
          }
          else {
            VagVin::getPdx((VagVin *)&local_50,local_5c[0]);
            FUN_00d30a9c(&local_48,&local_50);
            FUN_00cbd6dc(&local_50);
            if (local_48 != 0) {
              FUN_00cbba38(local_5c);
              if (iStack_44 != 0) {
                piVar3 = (int *)(iStack_44 + 4);
                do {
                  ExclusiveAccess(piVar3);
                  bVar1 = (bool)hasExclusiveAccess(piVar3);
                } while (!bVar1);
                *piVar3 = *piVar3 + 1;
              }
              goto LAB_01270902;
            }
            pbVar5 = *(basic_string **)(local_5c[0] + 8);
            if (((byte)*local_5c[0] & 1) == 0) {
              pbVar5 = local_5c[0] + 1;
            }
            Log::d("Vehicle missing from PDX mapping: %s",pbVar5);
          }
          FUN_00cbba38(local_5c);
        }
        else {
LAB_01270902:
          local_50 = local_48;
          iStack_4c = iStack_44;
          VagVin::getVagFileIdentifier
                    ((VagVin *)local_5c,(shared_ptr *)&local_50,(shared_ptr *)(*local_24 + 0x44),
                     (shared_ptr *)(*local_24 + 0x4c));
          FUN_00cbd6dc(&local_50);
          (**(code **)(**(int **)(*(int *)param_1 + 0x54) + 0x10))
                    (*(int **)(*(int *)param_1 + 0x54),local_5c);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)local_5c);
        }
        FUN_00cbd6dc(&local_48);
      }
      else {
        Log::d("Cannot get ASAM or Revision for vehicle");
      }
      Result<VagEcuInfo,void>::~Result(aRStack_40);
    }
    piVar3 = local_1c;
    piVar6 = __stack_chk_guard;
    if (__stack_chk_guard == local_1c) {
      return;
    }
  }
  else {
LAB_0127087c:
    iVar4 = *(int *)param_2;
LAB_0127087e:
    piVar3 = *(int **)(iVar2 + 0x54);
    piVar6 = *(int **)(iVar4 + 8);
    if (__stack_chk_guard == local_1c) {
                    /* WARNING: Could not recover jumptable at 0x0127089e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar3 + 0x10))(piVar3,*(int **)(iVar4 + 8));
      return;
    }
  }
LAB_0127098e:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(piVar3,piVar6);
}


