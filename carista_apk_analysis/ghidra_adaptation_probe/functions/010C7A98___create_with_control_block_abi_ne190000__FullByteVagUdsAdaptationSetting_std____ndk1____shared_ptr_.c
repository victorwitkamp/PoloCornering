/* std::__ndk1::shared_ptr<FullByteVagUdsAdaptationSetting>::__create_with_control_block[abi:ne190000]<FullByteVagUdsAdaptationSetting,std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>> @ 010c7a98 */


/* std::__ndk1::shared_ptr<FullByteVagUdsAdaptationSetting>
   std::__ndk1::shared_ptr<FullByteVagUdsAdaptationSetting>::__create_with_control_block[abi:ne190000]<FullByteVagUdsAdaptationSetting,
   std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,
   std::__ndk1::allocator<FullByteVagUdsAdaptationSetting> > >(FullByteVagUdsAdaptationSetting*,
   std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,
   std::__ndk1::allocator<FullByteVagUdsAdaptationSetting> >*) */

void __thiscall
std::__ndk1::shared_ptr<FullByteVagUdsAdaptationSetting>::
__create_with_control_block_abi_ne190000_<FullByteVagUdsAdaptationSetting,std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>>
          (shared_ptr<FullByteVagUdsAdaptationSetting> *this,
          FullByteVagUdsAdaptationSetting *param_1,__shared_ptr_emplace *param_2)

{
  FullByteVagUdsAdaptationSetting *pFVar1;
  
  *(FullByteVagUdsAdaptationSetting **)this = param_1;
  *(__shared_ptr_emplace **)(this + 4) = param_2;
  pFVar1 = param_1;
  if (param_1 != (FullByteVagUdsAdaptationSetting *)0x0) {
    pFVar1 = param_1 + 4;
  }
  _ZNSt6__ndk110shared_ptrI31FullByteVagUdsAdaptationSettingE18__enable_weak_thisB8ne190000I7SettingS1_TnNS_9enable_ifIXsr14is_convertibleIPT0_PKNS_23enable_shared_from_thisIT_EEEE5valueEiE4typeELi0EEEvSC_S7_
            (this,pFVar1,param_1);
  return;
}


