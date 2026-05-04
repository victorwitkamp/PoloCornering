/* std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>::~__shared_ptr_emplace @ 010bcc90 */


/* std::__ndk1::__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<FullByteVagCanShortAdaptationSetting,std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


