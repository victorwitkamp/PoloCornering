/* ChangeSettingOperation::ChangeSettingOperation @ 0129a79c */


/* ChangeSettingOperation::ChangeSettingOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::vector<std::__ndk1::pair<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > >,
   std::__ndk1::allocator<std::__ndk1::pair<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > > > > const&,
   std::__ndk1::shared_ptr<Operation> const&) */

void __thiscall
ChangeSettingOperation::ChangeSettingOperation
          (ChangeSettingOperation *this,shared_ptr *param_1,vector *param_2,shared_ptr *param_3)

{
  shared_ptr asStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  SimpleOperation::SimpleOperation((SimpleOperation *)this,param_1);
  *(undefined ***)this = &PTR__ChangeSettingOperation_014bc05c;
  FUN_00cf8e2c(this + 0x68,param_2);
  (**(code **)(**(int **)param_3 + 0x14))(asStack_24);
  Operation::setDelegate((Operation *)this,asStack_24);
  FUN_00d5a8a2(asStack_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


