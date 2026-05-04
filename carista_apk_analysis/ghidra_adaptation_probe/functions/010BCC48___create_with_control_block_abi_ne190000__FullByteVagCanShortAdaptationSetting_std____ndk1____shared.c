/* std::__ndk1::shared_ptr<FullByteVagCanShortAdaptationSetting>::__create_with_control_block[abi:ne190000]<FullByteVagCanShortAdaptationSetting,std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>> @ 010bcc48 */


/* std::__ndk1::shared_ptr<FullByteVagCanShortAdaptationSetting>
   std::__ndk1::shared_ptr<FullByteVagCanShortAdaptationSetting>::__create_with_control_block[abi:ne190000]<FullByteVagCanShortAdaptationSetting,
   std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting> >
   >(FullByteVagCanShortAdaptationSetting*,
   std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting> >*) */

void __thiscall
std::__ndk1::shared_ptr<FullByteVagCanShortAdaptationSetting>::
__create_with_control_block_abi_ne190000_<FullByteVagCanShortAdaptationSetting,std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>>
          (shared_ptr<FullByteVagCanShortAdaptationSetting> *this,
          FullByteVagCanShortAdaptationSetting *param_1,__shared_ptr_emplace *param_2)

{
  FullByteVagCanShortAdaptationSetting *pFVar1;
  
  *(FullByteVagCanShortAdaptationSetting **)this = param_1;
  *(__shared_ptr_emplace **)(this + 4) = param_2;
  pFVar1 = param_1;
  if (param_1 != (FullByteVagCanShortAdaptationSetting *)0x0) {
    pFVar1 = param_1 + 4;
  }
  FUN_01416160(this,pFVar1,param_1);
  return;
}


