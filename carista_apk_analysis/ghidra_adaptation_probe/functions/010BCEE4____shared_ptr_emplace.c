/* std::__ndk1::__shared_ptr_emplace<VagCanShortAdaptationSetting,std::__ndk1::allocator<VagCanShortAdaptationSetting>>::~__shared_ptr_emplace @ 010bcee4 */


/* std::__ndk1::__shared_ptr_emplace<VagCanShortAdaptationSetting,
   std::__ndk1::allocator<VagCanShortAdaptationSetting> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<VagCanShortAdaptationSetting,std::__ndk1::allocator<VagCanShortAdaptationSetting>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<VagCanShortAdaptationSetting,std::__ndk1::allocator<VagCanShortAdaptationSetting>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


