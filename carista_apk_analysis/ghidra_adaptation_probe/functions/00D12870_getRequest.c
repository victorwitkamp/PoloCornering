/* StartReadVagCanRoutineCommand::getRequest @ 00d12870 */


/* StartReadVagCanRoutineCommand::getRequest() const */

void StartReadVagCanRoutineCommand::getRequest(void)

{
  vector *in_r0;
  int in_r1;
  ByteUtils aBStack_2c [12];
  vector avStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  operator____b((char *)avStack_20,0xc4a6a3);
  ByteUtils::getBytesFromShort(aBStack_2c,*(ushort *)(in_r1 + 0x10));
  operator+(in_r0,avStack_20);
  FUN_00cb7f50(aBStack_2c);
  FUN_00cb7f50(avStack_20);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


