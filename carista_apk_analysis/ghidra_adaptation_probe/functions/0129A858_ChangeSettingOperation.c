/* ChangeSettingOperation::ChangeSettingOperation @ 0129a858 */


/* ChangeSettingOperation::ChangeSettingOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, std::__ndk1::shared_ptr<Operation> const&) */

void __thiscall
ChangeSettingOperation::ChangeSettingOperation
          (ChangeSettingOperation *this,shared_ptr *param_1,shared_ptr *param_2,vector *param_3,
          shared_ptr *param_4)

{
  vector avStack_3c [12];
  pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
  apStack_30 [20];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  _ZNSt6__ndk14pairINS_10shared_ptrI7SettingEENS_6vectorIhNS_9allocatorIhEEEEEC2B8ne190000ILb1ETnNS_9enable_ifIXclsr13_CheckArgsDepIXT_EEE23__is_pair_constructibleIRKS3_RKS7_EEEiE4typeELi0EEESC_SE_
            (apStack_30,param_2,param_3);
  FUN_01294640(avStack_3c,apStack_30,1);
  ChangeSettingOperation(this,param_1,avStack_3c,param_4);
  FUN_00cf8824(avStack_3c);
  std::__ndk1::
  pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
  ::~pair(apStack_30);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


