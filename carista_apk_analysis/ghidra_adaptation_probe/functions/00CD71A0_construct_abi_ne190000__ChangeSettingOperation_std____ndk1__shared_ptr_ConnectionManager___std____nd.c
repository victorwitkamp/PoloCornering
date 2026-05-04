/* std::__ndk1::allocator<ChangeSettingOperation>::construct[abi:ne190000]<ChangeSettingOperation,std::__ndk1::shared_ptr<ConnectionManager>&,std::__ndk1::shared_ptr<Setting>&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::shared_ptr<ReadValuesOperation>&> @ 00cd71a0 */


/* void 
   std::__ndk1::allocator<ChangeSettingOperation>::construct[abi:ne190000]<ChangeSettingOperation,
   std::__ndk1::shared_ptr<ConnectionManager>&, std::__ndk1::shared_ptr<Setting>&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >,
   std::__ndk1::shared_ptr<ReadValuesOperation>&>(ChangeSettingOperation*,
   std::__ndk1::shared_ptr<ConnectionManager>&, std::__ndk1::shared_ptr<Setting>&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >&&,
   std::__ndk1::shared_ptr<ReadValuesOperation>&) */

void __thiscall
std::__ndk1::allocator<ChangeSettingOperation>::
construct_abi_ne190000_<ChangeSettingOperation,std::__ndk1::shared_ptr<ConnectionManager>&,std::__ndk1::shared_ptr<Setting>&,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,std::__ndk1::shared_ptr<ReadValuesOperation>&>
          (allocator<ChangeSettingOperation> *this,ChangeSettingOperation *param_1,
          shared_ptr *param_2,shared_ptr *param_3,vector *param_4,shared_ptr *param_5)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24 = *(undefined4 *)param_5;
  iStack_20 = *(int *)(param_5 + 4);
  if (iStack_20 != 0) {
    piVar2 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  ChangeSettingOperation::ChangeSettingOperation
            (param_1,param_2,param_3,param_4,(shared_ptr *)&local_24);
  FUN_00cbfa28(&local_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


