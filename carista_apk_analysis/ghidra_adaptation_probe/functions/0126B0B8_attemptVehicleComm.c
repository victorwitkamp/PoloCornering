/* VagOperationDelegate::attemptVehicleComm @ 0126b0b8 */


/* VagOperationDelegate::attemptVehicleComm(std::__ndk1::unordered_map<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >, std::__ndk1::shared_ptr<void>,
   std::__ndk1::hash<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > >, std::__ndk1::equal_to<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > >,
   std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::basic_string<char,
   std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> > const,
   std::__ndk1::shared_ptr<void> > > >&, std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::attemptVehicleComm
          (VagOperationDelegate *this,unordered_map *param_1,shared_ptr *param_2)

{
  int iVar1;
  IllegalStateException *this_00;
  Result<bool,void> local_ac [28];
  undefined4 *local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 *local_6c;
  undefined4 local_64;
  undefined4 local_60;
  shared_ptr asStack_40 [24];
  int *local_28;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_ac[0] = (Result<bool,void>)0x89;
  FUN_0126b2c4(&local_88,&VagCanEcu::CAN_GATEWAY,local_ac);
  local_64 = local_88;
  local_60 = uStack_84;
  local_88 = 0;
  uStack_84 = 0;
  OperationDelegate::runCommand<EmptyModel>(asStack_40,(shared_ptr *)this);
  FUN_011e4048(&local_64);
  FUN_011ff7b8(&local_88);
  (**(code **)(*(int *)this + 0x188))(this,VagCanEcu::CAN_GATEWAY,*local_28);
  if ((*local_28 == -5) && (iVar1 = (**(code **)(**(int **)param_2 + 0x14))(), iVar1 == 0)) {
    (**(code **)(*(int *)this + 0x194))(&local_64,this,VagUdsEcu::CAN_GATEWAY,1,0);
    iVar1 = Result<VagEcuInfo,void>::isFail((Result<VagEcuInfo,void> *)&local_64);
    if (iVar1 == 0) {
      isSfd2Protected((VagOperationDelegate *)&local_88,(shared_ptr *)this);
      iVar1 = Result<bool,void>::isFatalFail((Result<bool,void> *)&local_88);
      if (iVar1 == 0) {
        iVar1 = Result<bool,void>::isFail((Result<bool,void> *)&local_88);
        if ((iVar1 == 0) && (*(char *)*local_6c != '\0')) {
          ConnectionManager::requestAndWaitForSfdConfirmation
                    (*(ConnectionManager **)(this + 0x18),(shared_ptr *)(this + 0x20));
          iVar1 = (**(code **)(**(int **)param_2 + 0x14))();
          if (iVar1 == 0) {
            if (*(char *)(*(int *)(this + 0x18) + 0x60) == '\0') {
              this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
              FUN_00cb4d44(local_ac,"SFD not confirmed for SFD2 vehicle.");
              IllegalStateException::IllegalStateException(this_00,(basic_string *)local_ac);
                    /* WARNING: Subroutine does not return */
              __cxa_throw(this_00,&IllegalStateException::typeinfo,
                          IllegalStateException::~IllegalStateException);
            }
            unlockDiagFilter(this,param_2);
          }
        }
        else {
          (**(code **)(*(int *)this + 0xd4))(local_ac,this,VagUdsEcu::CENTRAL_ELEC);
          iVar1 = Result<bool,void>::isFatalFail(local_ac);
          if (iVar1 == 0) {
            iVar1 = Result<bool,void>::isFail(local_ac);
            if ((iVar1 == 0) && (*(char *)*local_90 != '\0')) {
              this[0x141] = (VagOperationDelegate)0x2;
            }
            else {
              this[0x141] = (VagOperationDelegate)0x1;
            }
          }
          Result<bool,void>::~Result(local_ac);
        }
      }
      Result<bool,void>::~Result((Result<bool,void> *)&local_88);
    }
    Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_64);
  }
  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_40);
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_1c);
}


