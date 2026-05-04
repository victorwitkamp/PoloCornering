/* PreReadVagCanAdaptationDataCommand::processPayload @ 00d1225c */


/* PreReadVagCanAdaptationDataCommand::processPayload(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) const */

void PreReadVagCanAdaptationDataCommand::processPayload(vector *param_1)

{
  int iVar1;
  undefined1 auStack_2c [15];
  undefined1 uStack_1d;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uStack_1d = 0x81;
  FUN_00cdb87c(auStack_2c,&uStack_1d,1);
  iVar1 = FUN_00cdbf64();
  FUN_00cb7f50(auStack_2c);
  if (iVar1 == 0) {
    Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,-6);
  }
  else {
    Result<EmptyModel,void>::done((Result<EmptyModel,void> *)param_1);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


