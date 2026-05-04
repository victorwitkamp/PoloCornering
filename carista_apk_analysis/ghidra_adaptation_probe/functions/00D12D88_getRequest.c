/* WriteVagCanAdaptationDataCommand::getRequest @ 00d12d88 */


/* WriteVagCanAdaptationDataCommand::getRequest() const */

void WriteVagCanAdaptationDataCommand::getRequest(void)

{
  vector *in_r0;
  int in_r1;
  ByteUtils aBStack_44 [12];
  vector avStack_38 [12];
  vector avStack_2c [12];
  vector avStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  operator____b((char *)avStack_38,0x7481eb);
  ByteUtils::getBytesFromShort(aBStack_44,*(ushort *)(in_r1 + 0x10));
  operator+(avStack_2c,avStack_38);
  operator+(avStack_20,avStack_2c);
  operator+(in_r0,avStack_20);
  FUN_00cb7f50(avStack_20);
  FUN_00cb7f50(avStack_2c);
  FUN_00cb7f50(aBStack_44);
  FUN_00cb7f50(avStack_38);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


