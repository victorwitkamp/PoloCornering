/* VagOperationDelegate::calculateUdsSecurityAccessResponse @ 0127458c */


/* VagOperationDelegate::calculateUdsSecurityAccessResponse(unsigned long long,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::calculateUdsSecurityAccessResponse(ulonglong param_1,vector *param_2)

{
  undefined4 extraout_r1;
  int *in_stack_00000000;
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [4];
  int local_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((uint)(in_stack_00000000[1] - *in_stack_00000000) < 9) {
    _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE(in_stack_00000000);
    ByteUtils::getBytesFromLong(CONCAT44(extraout_r1,auStack_28));
    _ZNSt6__ndk16vectorIhNS_9allocatorIhEEEC2INS_11__wrap_iterIPhEETnNS_9enable_ifIXaasr31__has_forward_iterator_categoryIT_EE5valuesr16is_constructibleIhNS_15iterator_traitsIS9_E9referenceEEE5valueEiE4typeELi0EEES9_S9_
              (auStack_34,local_24 + (*in_stack_00000000 - in_stack_00000000[1]));
    Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>::
    done<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>
              ((type *)(Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                        *)param_1);
    FUN_00cb7f50(auStack_34);
    FUN_00cb7f50(auStack_28);
  }
  else {
    Log::e("UDS sec access challenge is larger than 8 bytes; bailing.");
    Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>::Result
              ((Result<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                *)param_1,-6);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


