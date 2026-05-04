/* std::__ndk1::__shared_ptr_emplace<VagUdsFreezeFrameSetting,std::__ndk1::allocator<VagUdsFreezeFrameSetting>>::~__shared_ptr_emplace @ 011ca0b8 */


/* std::__ndk1::__shared_ptr_emplace<VagUdsFreezeFrameSetting,
   std::__ndk1::allocator<VagUdsFreezeFrameSetting> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<VagUdsFreezeFrameSetting,std::__ndk1::allocator<VagUdsFreezeFrameSetting>>::
~__shared_ptr_emplace
          (__shared_ptr_emplace<VagUdsFreezeFrameSetting,std::__ndk1::allocator<VagUdsFreezeFrameSetting>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


