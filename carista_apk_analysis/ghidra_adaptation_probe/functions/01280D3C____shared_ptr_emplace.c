/* std::__ndk1::__shared_ptr_emplace<StartReadVagCanRoutineCommand,std::__ndk1::allocator<StartReadVagCanRoutineCommand>>::~__shared_ptr_emplace @ 01280d3c */


/* std::__ndk1::__shared_ptr_emplace<StartReadVagCanRoutineCommand,
   std::__ndk1::allocator<StartReadVagCanRoutineCommand> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<StartReadVagCanRoutineCommand,std::__ndk1::allocator<StartReadVagCanRoutineCommand>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<StartReadVagCanRoutineCommand,std::__ndk1::allocator<StartReadVagCanRoutineCommand>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


