/* std::__ndk1::__shared_ptr_emplace<VagUdsAdaptationSetting,std::__ndk1::allocator<VagUdsAdaptationSetting>>::~__shared_ptr_emplace @ 010bd47c */


/* std::__ndk1::__shared_ptr_emplace<VagUdsAdaptationSetting,
   std::__ndk1::allocator<VagUdsAdaptationSetting> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<VagUdsAdaptationSetting,std::__ndk1::allocator<VagUdsAdaptationSetting>>::
~__shared_ptr_emplace
          (__shared_ptr_emplace<VagUdsAdaptationSetting,std::__ndk1::allocator<VagUdsAdaptationSetting>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


