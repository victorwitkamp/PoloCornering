/* WriteVagCanTemporaryAdaptationDataCommand::getRequest @ 00d12fac */


/* WriteVagCanTemporaryAdaptationDataCommand::getRequest() const */

void WriteVagCanTemporaryAdaptationDataCommand::getRequest(void)

{
  vector *in_r0;
  int in_r1;
  ByteUtils aBStack_38 [12];
  vector avStack_2c [12];
  vector avStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  operator____b((char *)avStack_2c,0xb93cf1);
  ByteUtils::getBytesFromShort(aBStack_38,*(ushort *)(in_r1 + 0x10));
  operator+(avStack_20,avStack_2c);
  operator+(in_r0,avStack_20);
  FUN_00cb7f50(avStack_20);
  FUN_00cb7f50(aBStack_38);
  FUN_00cb7f50(avStack_2c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


