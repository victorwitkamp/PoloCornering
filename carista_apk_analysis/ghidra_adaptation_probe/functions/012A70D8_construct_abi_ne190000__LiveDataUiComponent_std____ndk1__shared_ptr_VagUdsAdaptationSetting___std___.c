/* std::__ndk1::allocator<LiveDataUiComponent>::construct[abi:ne190000]<LiveDataUiComponent,std::__ndk1::shared_ptr<VagUdsAdaptationSetting>&,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>,bool> @ 012a70d8 */


/* void std::__ndk1::allocator<LiveDataUiComponent>::construct[abi:ne190000]<LiveDataUiComponent,
   std::__ndk1::shared_ptr<VagUdsAdaptationSetting>&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > >, bool>(LiveDataUiComponent*, std::__ndk1::shared_ptr<VagUdsAdaptationSetting>&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > >&&, bool&&) */

void __thiscall
std::__ndk1::allocator<LiveDataUiComponent>::
construct_abi_ne190000_<LiveDataUiComponent,std::__ndk1::shared_ptr<VagUdsAdaptationSetting>&,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>,bool>
          (allocator<LiveDataUiComponent> *this,LiveDataUiComponent *param_1,shared_ptr *param_2,
          shared_ptr *param_3,bool *param_4)

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
  LiveDataUiComponent::LiveDataUiComponent(param_1,(shared_ptr *)&local_1c,param_3,*param_4);
  FUN_00cc67b0((shared_ptr *)&local_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


