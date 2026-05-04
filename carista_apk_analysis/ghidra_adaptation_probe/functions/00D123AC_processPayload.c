/* ReadVagCanLongAdaptationDataCommand::processPayload @ 00d123ac */


/* ReadVagCanLongAdaptationDataCommand::processPayload(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) const */

void ReadVagCanLongAdaptationDataCommand::processPayload(vector *param_1)

{
  byte *pbVar1;
  vector *in_r2;
  BytesModel aBStack_38 [16];
  ByteUtils aBStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (2 < (uint)(*(int *)(in_r2 + 4) - *(int *)in_r2)) {
    pbVar1 = (byte *)FUN_00cdeb2c();
    if ((uint)*pbVar1 <= (*(int *)(in_r2 + 4) - *(int *)in_r2) - 3U) {
      ByteUtils::subrange(aBStack_28,in_r2,3,*pbVar1 - 1);
      BytesModel::BytesModel(aBStack_38,(vector *)aBStack_28);
      Result<BytesModel,void>::done<BytesModel>((type *)param_1);
      BytesModel::~BytesModel(aBStack_38);
      FUN_00cb7f50(aBStack_28);
      goto LAB_00d1241a;
    }
  }
  Result<BytesModel,void>::Result((Result<BytesModel,void> *)param_1,-6);
LAB_00d1241a:
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


