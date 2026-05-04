/* std::__ndk1::shared_ptr<ChangeSettingOperation>::__create_with_control_block[abi:ne190000]<ChangeSettingOperation,std::__ndk1::__shared_ptr_emplace<ChangeSettingOperation,std::__ndk1::allocator<ChangeSettingOperation>>> @ 00cd7144 */


/* std::__ndk1::shared_ptr<ChangeSettingOperation>
   std::__ndk1::shared_ptr<ChangeSettingOperation>::__create_with_control_block[abi:ne190000]<ChangeSettingOperation,
   std::__ndk1::__shared_ptr_emplace<ChangeSettingOperation,
   std::__ndk1::allocator<ChangeSettingOperation> > >(ChangeSettingOperation*,
   std::__ndk1::__shared_ptr_emplace<ChangeSettingOperation,
   std::__ndk1::allocator<ChangeSettingOperation> >*) */

void __thiscall
std::__ndk1::shared_ptr<ChangeSettingOperation>::
__create_with_control_block_abi_ne190000_<ChangeSettingOperation,std::__ndk1::__shared_ptr_emplace<ChangeSettingOperation,std::__ndk1::allocator<ChangeSettingOperation>>>
          (shared_ptr<ChangeSettingOperation> *this,ChangeSettingOperation *param_1,
          __shared_ptr_emplace *param_2)

{
  ChangeSettingOperation *pCVar1;
  
  *(ChangeSettingOperation **)this = param_1;
  *(__shared_ptr_emplace **)(this + 4) = param_2;
  pCVar1 = param_1;
  if (param_1 != (ChangeSettingOperation *)0x0) {
    pCVar1 = param_1 + 4;
  }
  _ZNSt6__ndk110shared_ptrI22ChangeSettingOperationE18__enable_weak_thisB8ne190000I9OperationS1_TnNS_9enable_ifIXsr14is_convertibleIPT0_PKNS_23enable_shared_from_thisIT_EEEE5valueEiE4typeELi0EEEvSC_S7_
            (this,pCVar1,param_1);
  return;
}


