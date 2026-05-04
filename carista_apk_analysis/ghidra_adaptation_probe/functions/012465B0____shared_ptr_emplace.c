/* std::__ndk1::__shared_ptr_emplace<VagOperationDelegate,std::__ndk1::allocator<VagOperationDelegate>>::~__shared_ptr_emplace @ 012465b0 */


/* std::__ndk1::__shared_ptr_emplace<VagOperationDelegate,
   std::__ndk1::allocator<VagOperationDelegate> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::__shared_ptr_emplace<VagOperationDelegate,std::__ndk1::allocator<VagOperationDelegate>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<VagOperationDelegate,std::__ndk1::allocator<VagOperationDelegate>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


