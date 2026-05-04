/* std::__ndk1::shared_ptr<VagUdsAdaptationSetting>::__create_with_control_block[abi:ne190000]<VagUdsAdaptationSetting,std::__ndk1::__shared_ptr_emplace<VagUdsAdaptationSetting,std::__ndk1::allocator<VagUdsAdaptationSetting>>> @ 010bd434 */


/* std::__ndk1::shared_ptr<VagUdsAdaptationSetting>
   std::__ndk1::shared_ptr<VagUdsAdaptationSetting>::__create_with_control_block[abi:ne190000]<VagUdsAdaptationSetting,
   std::__ndk1::__shared_ptr_emplace<VagUdsAdaptationSetting,
   std::__ndk1::allocator<VagUdsAdaptationSetting> > >(VagUdsAdaptationSetting*,
   std::__ndk1::__shared_ptr_emplace<VagUdsAdaptationSetting,
   std::__ndk1::allocator<VagUdsAdaptationSetting> >*) */

void __thiscall
std::__ndk1::shared_ptr<VagUdsAdaptationSetting>::
__create_with_control_block_abi_ne190000_<VagUdsAdaptationSetting,std::__ndk1::__shared_ptr_emplace<VagUdsAdaptationSetting,std::__ndk1::allocator<VagUdsAdaptationSetting>>>
          (shared_ptr<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          __shared_ptr_emplace *param_2)

{
  VagUdsAdaptationSetting *pVVar1;
  
  *(VagUdsAdaptationSetting **)this = param_1;
  *(__shared_ptr_emplace **)(this + 4) = param_2;
  pVVar1 = param_1;
  if (param_1 != (VagUdsAdaptationSetting *)0x0) {
    pVVar1 = param_1 + 4;
  }
  FUN_01416270(this,pVVar1,param_1);
  return;
}


