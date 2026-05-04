/* VagOperationDelegate::getUpdatedTroubleCodesWithCachedDescriptions @ 0127b630 */


/* VagOperationDelegate::getUpdatedTroubleCodesWithCachedDescriptions(Ecu*,
   std::__ndk1::shared_ptr<VagEcuInfo> const&,
   std::__ndk1::vector<std::__ndk1::shared_ptr<TroubleCode>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<TroubleCode> > > const&) */

void VagOperationDelegate::getUpdatedTroubleCodesWithCachedDescriptions
               (Ecu *param_1,shared_ptr *param_2,vector *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *in_r3;
  shared_ptr *psVar8;
  undefined4 *in_stack_00000000;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_7c [12];
  undefined1 auStack_70 [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_64 [12];
  undefined1 auStack_58 [8];
  undefined4 local_50;
  undefined4 uStack_4c;
  basic_string *local_48 [2];
  basic_string abStack_40 [12];
  int *local_34;
  int iStack_30;
  vector *local_2c;
  int local_28;
  
  psVar8 = param_2 + 4;
  local_28 = __stack_chk_guard;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  puVar7 = (undefined4 *)*in_stack_00000000;
  puVar3 = (undefined4 *)in_stack_00000000[1];
  local_2c = param_3;
  do {
    if (puVar7 == puVar3) {
      if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    local_34 = (int *)*puVar7;
    iStack_30 = puVar7[1];
    if (iStack_30 != 0) {
      piVar4 = (int *)(iStack_30 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar1 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar1);
      *piVar4 = *piVar4 + 1;
    }
    (**(code **)(*local_34 + 0x14))(abStack_40);
    uVar5 = FUN_012405ec(psVar8,&local_2c);
    FUN_011dbe3c(uVar5,abStack_40);
    iVar6 = FUN_00cdb2f0();
    if (iVar6 == 0) {
      uVar5 = FUN_012405ec(psVar8,&local_2c);
      iVar6 = FUN_011dbe3c(uVar5,abStack_40);
      iVar6 = FUN_00cdb2f0(iVar6 + 0xc);
      if (iVar6 != 0) goto LAB_0127b6d4;
      uVar5 = FUN_012405ec(psVar8,&local_2c);
      uVar5 = FUN_011dbe3c(uVar5,abStack_40);
      FUN_011dcc80(abStack_7c,uVar5);
      (**(code **)(*local_34 + 0x24))(abStack_64,local_34,auStack_70,abStack_7c);
      FUN_00ce1c2c(param_1,abStack_64);
      FUN_00ce1c54(abStack_64);
      std::__ndk1::
      pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
      ::~pair((pair<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
               *)abStack_7c);
    }
    else {
LAB_0127b6d4:
      (**(code **)(*(int *)param_2 + 0x20))(local_48,param_2);
      if (local_48[0] == (basic_string *)0x0) {
        local_50 = 0;
        uStack_4c = 0;
      }
      else {
        VagVin::getPdx((VagVin *)&local_50,local_48[0]);
      }
      OperationDelegate::logMissingCachedTroubleCodesInfo
                ((OperationDelegate *)param_2,(Ecu *)local_2c,(shared_ptr *)(*in_r3 + 0x44),
                 (shared_ptr *)(*in_r3 + 0x4c),(shared_ptr *)&local_50,abStack_40);
      piVar2 = local_34;
      piVar4 = (int *)App::STRING_MANAGER;
      FUN_00cb4d44(abStack_64,LibStr::no_code_description_available);
      (**(code **)(*piVar4 + 0xc))(abStack_7c,piVar4,abStack_64);
      (**(code **)(*piVar2 + 0x20))(auStack_58,piVar2,abStack_7c);
      FUN_00ce1c2c(param_1,auStack_58);
      FUN_00ce1c54(auStack_58);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string(abStack_7c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string(abStack_64);
      FUN_00cbd6dc(&local_50);
      FUN_00cbba38(local_48);
    }
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  abStack_40);
    FUN_0126ebba(&local_34);
    puVar7 = puVar7 + 2;
  } while( true );
}


