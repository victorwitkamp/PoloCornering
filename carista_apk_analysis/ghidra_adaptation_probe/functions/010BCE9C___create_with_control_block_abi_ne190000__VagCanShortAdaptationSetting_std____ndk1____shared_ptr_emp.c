/* std::__ndk1::shared_ptr<VagCanShortAdaptationSetting>::__create_with_control_block[abi:ne190000]<VagCanShortAdaptationSetting,std::__ndk1::__shared_ptr_emplace<VagCanShortAdaptationSetting,std::__ndk1::allocator<VagCanShortAdaptationSetting>>> @ 010bce9c */


/* std::__ndk1::shared_ptr<VagCanShortAdaptationSetting>
   std::__ndk1::shared_ptr<VagCanShortAdaptationSetting>::__create_with_control_block[abi:ne190000]<VagCanShortAdaptationSetting,
   std::__ndk1::__shared_ptr_emplace<VagCanShortAdaptationSetting,
   std::__ndk1::allocator<VagCanShortAdaptationSetting> > >(VagCanShortAdaptationSetting*,
   std::__ndk1::__shared_ptr_emplace<VagCanShortAdaptationSetting,
   std::__ndk1::allocator<VagCanShortAdaptationSetting> >*) */

void __thiscall
std::__ndk1::shared_ptr<VagCanShortAdaptationSetting>::
__create_with_control_block_abi_ne190000_<VagCanShortAdaptationSetting,std::__ndk1::__shared_ptr_emplace<VagCanShortAdaptationSetting,std::__ndk1::allocator<VagCanShortAdaptationSetting>>>
          (shared_ptr<VagCanShortAdaptationSetting> *this,VagCanShortAdaptationSetting *param_1,
          __shared_ptr_emplace *param_2)

{
  VagCanShortAdaptationSetting *pVVar1;
  
  *(VagCanShortAdaptationSetting **)this = param_1;
  *(__shared_ptr_emplace **)(this + 4) = param_2;
  pVVar1 = param_1;
  if (param_1 != (VagCanShortAdaptationSetting *)0x0) {
    pVVar1 = param_1 + 4;
  }
  FUN_014161c0(this,pVVar1,param_1);
  return;
}


