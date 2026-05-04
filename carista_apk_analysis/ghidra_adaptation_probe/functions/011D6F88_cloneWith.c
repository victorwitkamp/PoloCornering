/* VagUdsMirrorLinkVimCoding::cloneWith @ 011d6f88 */


/* VagUdsMirrorLinkVimCoding::cloneWith(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) const */

undefined8 VagUdsMirrorLinkVimCoding::cloneWith(vector *param_1)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = in_r1;
  uStack_18 = in_r2;
  FUN_011d6fd4(&local_1c);
  *(undefined4 *)param_1 = local_1c;
  *(undefined4 *)(param_1 + 4) = uStack_18;
  local_1c = 0;
  uStack_18 = 0;
  FUN_011d7008(&local_1c);
  if (__stack_chk_guard == local_14) {
    return CONCAT44(local_1c,param_1);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


