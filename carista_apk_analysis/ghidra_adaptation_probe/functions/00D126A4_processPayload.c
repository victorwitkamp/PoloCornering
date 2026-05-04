/* ReadVagCanShortAdaptationDataCommand::processPayload @ 00d126a4 */


/* ReadVagCanShortAdaptationDataCommand::processPayload(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) const */

void ReadVagCanShortAdaptationDataCommand::processPayload(vector *param_1)

{
  char *pcVar1;
  vector *in_r2;
  BytesModel aBStack_38 [16];
  ByteUtils aBStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (((uint)(*(int *)(in_r2 + 4) - *(int *)in_r2) < 4) ||
     ((pcVar1 = (char *)FUN_00cdeb2c(), *pcVar1 != -0x7e &&
      (pcVar1 = (char *)FUN_00cdeb2c(), *pcVar1 != '\x05')))) {
    Result<BytesModel,void>::Result((Result<BytesModel,void> *)param_1,-6);
  }
  else {
    ByteUtils::subrange(aBStack_28,in_r2,2,2);
    BytesModel::BytesModel(aBStack_38,(vector *)aBStack_28);
    Result<BytesModel,void>::done<BytesModel>((type *)param_1);
    BytesModel::~BytesModel(aBStack_38);
    FUN_00cb7f50(aBStack_28);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


