/* std::__ndk1::__shared_ptr_emplace<StopReadVagCanRoutineCommand,std::__ndk1::allocator<StopReadVagCanRoutineCommand>>::~__shared_ptr_emplace @ 012813dc */


/* std::__ndk1::__shared_ptr_emplace<StopReadVagCanRoutineCommand,
   std::__ndk1::allocator<StopReadVagCanRoutineCommand> >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<StopReadVagCanRoutineCommand,std::__ndk1::allocator<StopReadVagCanRoutineCommand>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<StopReadVagCanRoutineCommand,std::__ndk1::allocator<StopReadVagCanRoutineCommand>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


