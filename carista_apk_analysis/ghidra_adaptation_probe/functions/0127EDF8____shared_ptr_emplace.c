/* std::__ndk1::__shared_ptr_emplace<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>,std::__ndk1::allocator<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>>>::~__shared_ptr_emplace @ 0127edf8 */


/* std::__ndk1::__shared_ptr_emplace<std::__ndk1::unordered_map<Ecu*, Result<DiagFilterModel, void>,
   std::__ndk1::hash<Ecu*>, std::__ndk1::equal_to<Ecu*>,
   std::__ndk1::allocator<std::__ndk1::pair<Ecu* const, Result<DiagFilterModel, void> > > >,
   std::__ndk1::allocator<std::__ndk1::unordered_map<Ecu*, Result<DiagFilterModel, void>,
   std::__ndk1::hash<Ecu*>, std::__ndk1::equal_to<Ecu*>,
   std::__ndk1::allocator<std::__ndk1::pair<Ecu* const, Result<DiagFilterModel, void> > > > >
   >::~__shared_ptr_emplace() */

void __thiscall
std::__ndk1::
__shared_ptr_emplace<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>,std::__ndk1::allocator<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>>>
::~__shared_ptr_emplace
          (__shared_ptr_emplace<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>,std::__ndk1::allocator<std::__ndk1::unordered_map<Ecu*,Result<DiagFilterModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<DiagFilterModel,void>>>>>>
           *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~__shared_ptr_emplace(this);
  operator_delete(pvVar1);
  return;
}


