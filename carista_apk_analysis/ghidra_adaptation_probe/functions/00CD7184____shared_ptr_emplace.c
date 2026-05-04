/* std::__ndk1::__shared_ptr_emplace<ChangeSettingOperation,std::__ndk1::allocator<ChangeSettingOperation>>::~__shared_ptr_emplace @ 00cd7184 */


/* std::__ndk1::__shared_ptr_emplace<ChangeSettingOperation,
   std::__ndk1::allocator<ChangeSettingOperation> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<ChangeSettingOperation,std::__ndk1::allocator<ChangeSettingOperation>>::
~__shared_ptr_emplace
          (__shared_ptr_emplace<ChangeSettingOperation,std::__ndk1::allocator<ChangeSettingOperation>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


