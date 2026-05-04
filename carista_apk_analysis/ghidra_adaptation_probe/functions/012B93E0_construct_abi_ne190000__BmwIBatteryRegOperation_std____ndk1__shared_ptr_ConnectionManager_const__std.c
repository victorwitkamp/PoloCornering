/* std::__ndk1::allocator<BmwIBatteryRegOperation>::construct[abi:ne190000]<BmwIBatteryRegOperation,std::__ndk1::shared_ptr<ConnectionManager>const&,std::__ndk1::shared_ptr<BmwFGenericTool>&,std::__ndk1::shared_ptr<ReadValuesOperation>const&> @ 012b93e0 */


/* void 
   std::__ndk1::allocator<BmwIBatteryRegOperation>::construct[abi:ne190000]<BmwIBatteryRegOperation,
   std::__ndk1::shared_ptr<ConnectionManager> const&, std::__ndk1::shared_ptr<BmwFGenericTool>&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&>(BmwIBatteryRegOperation*,
   std::__ndk1::shared_ptr<ConnectionManager> const&, std::__ndk1::shared_ptr<BmwFGenericTool>&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
std::__ndk1::allocator<BmwIBatteryRegOperation>::
construct_abi_ne190000_<BmwIBatteryRegOperation,std::__ndk1::shared_ptr<ConnectionManager>const&,std::__ndk1::shared_ptr<BmwFGenericTool>&,std::__ndk1::shared_ptr<ReadValuesOperation>const&>
          (allocator<BmwIBatteryRegOperation> *this,BmwIBatteryRegOperation *param_1,
          shared_ptr *param_2,shared_ptr *param_3,shared_ptr *param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_1c;
  int iStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = *(undefined4 *)param_3;
  iStack_18 = *(int *)(param_3 + 4);
  if (iStack_18 != 0) {
    piVar2 = (int *)(iStack_18 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  BmwIBatteryRegOperation::BmwIBatteryRegOperation(param_1,param_2,(shared_ptr *)&local_1c,param_4);
  FUN_00cc67b0((shared_ptr *)&local_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


