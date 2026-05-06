/* Target address 00cea35c */
/* Function FUN_00cea35c @ 00cea35c */


void FUN_00cea35c(pair *param_1,pair *param_2,int param_3)

{
  pair *local_24;
  undefined1 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  local_20 = 0;
  local_24 = param_1;
  if (param_3 != 0) {
    FUN_00cbe700(param_1,param_3);
    std::__ndk1::
    vector<std::__ndk1::pair<unsigned_long_long,char_const*>,std::__ndk1::allocator<std::__ndk1::pair<unsigned_long_long,char_const*>>>
    ::
    __construct_at_end<std::__ndk1::pair<unsigned_long_long,char_const*>const*,std::__ndk1::pair<unsigned_long_long,char_const*>const*>
              (param_1,param_2,(uint)(param_2 + param_3 * 0x10));
  }
  local_20 = 1;
  FUN_00cbe73c(&local_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


