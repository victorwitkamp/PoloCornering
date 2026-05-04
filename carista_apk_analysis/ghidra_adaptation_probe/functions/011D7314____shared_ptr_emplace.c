/* std::__ndk1::__shared_ptr_emplace<VagUdsMirrorLinkVimCoding,std::__ndk1::allocator<VagUdsMirrorLinkVimCoding>>::~__shared_ptr_emplace @ 011d7314 */


/* std::__ndk1::__shared_ptr_emplace<VagUdsMirrorLinkVimCoding,
   std::__ndk1::allocator<VagUdsMirrorLinkVimCoding> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<VagUdsMirrorLinkVimCoding,std::__ndk1::allocator<VagUdsMirrorLinkVimCoding>>::
~__shared_ptr_emplace
          (__shared_ptr_emplace<VagUdsMirrorLinkVimCoding,std::__ndk1::allocator<VagUdsMirrorLinkVimCoding>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


