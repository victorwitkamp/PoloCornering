/* std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>::~__shared_ptr_emplace @ 010c7ae0 */


/* std::__ndk1::__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,
   std::__ndk1::allocator<FullByteVagUdsAdaptationSetting> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<FullByteVagUdsAdaptationSetting,std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


