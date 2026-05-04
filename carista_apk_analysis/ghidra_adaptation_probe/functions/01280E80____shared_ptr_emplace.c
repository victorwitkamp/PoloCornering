/* std::__ndk1::__shared_ptr_emplace<PreReadVagCanAdaptationDataCommand,std::__ndk1::allocator<PreReadVagCanAdaptationDataCommand>>::~__shared_ptr_emplace @ 01280e80 */


/* std::__ndk1::__shared_ptr_emplace<PreReadVagCanAdaptationDataCommand,
   std::__ndk1::allocator<PreReadVagCanAdaptationDataCommand> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<PreReadVagCanAdaptationDataCommand,std::__ndk1::allocator<PreReadVagCanAdaptationDataCommand>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<PreReadVagCanAdaptationDataCommand,std::__ndk1::allocator<PreReadVagCanAdaptationDataCommand>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


