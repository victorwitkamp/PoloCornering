/* std::__ndk1::allocator<SettingUiComponent>::construct[abi:ne190000]<SettingUiComponent,std::__ndk1::shared_ptr<VagUdsAdaptationSetting>const&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>> @ 012a6a70 */


/* void std::__ndk1::allocator<SettingUiComponent>::construct[abi:ne190000]<SettingUiComponent,
   std::__ndk1::shared_ptr<VagUdsAdaptationSetting> const&, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > >(SettingUiComponent*,
   std::__ndk1::shared_ptr<VagUdsAdaptationSetting> const&, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> >&&) */

void __thiscall
std::__ndk1::allocator<SettingUiComponent>::
construct_abi_ne190000_<SettingUiComponent,std::__ndk1::shared_ptr<VagUdsAdaptationSetting>const&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
          (allocator<SettingUiComponent> *this,SettingUiComponent *param_1,shared_ptr *param_2,
          vector *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_1c;
  int iStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = *(undefined4 *)param_2;
  iStack_18 = *(int *)(param_2 + 4);
  if (iStack_18 != 0) {
    piVar2 = (int *)(iStack_18 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  SettingUiComponent::SettingUiComponent(param_1,(shared_ptr *)&local_1c,param_3);
  FUN_00cc67b0((shared_ptr *)&local_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


