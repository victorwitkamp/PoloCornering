/* std::__ndk1::__shared_ptr_emplace<VagUdsVimSetting,std::__ndk1::allocator<VagUdsVimSetting>>::~__shared_ptr_emplace @ 011d7154 */


/* std::__ndk1::__shared_ptr_emplace<VagUdsVimSetting, std::__ndk1::allocator<VagUdsVimSetting>
   >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::__shared_ptr_emplace<VagUdsVimSetting,std::__ndk1::allocator<VagUdsVimSetting>>::
~__shared_ptr_emplace
          (__shared_ptr_emplace<VagUdsVimSetting,std::__ndk1::allocator<VagUdsVimSetting>> *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


