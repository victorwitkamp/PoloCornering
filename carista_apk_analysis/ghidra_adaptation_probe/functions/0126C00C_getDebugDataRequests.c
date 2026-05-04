/* VagOperationDelegate::getDebugDataRequests @ 0126c00c */


/* VagOperationDelegate::getDebugDataRequests() */

void VagOperationDelegate::getDebugDataRequests(void)

{
  int iVar1;
  char acStack_1bc [12];
  char acStack_1b0 [12];
  char acStack_1a4 [12];
  char acStack_198 [12];
  char acStack_18c [12];
  char acStack_180 [12];
  char acStack_174 [12];
  char acStack_168 [12];
  char acStack_15c [12];
  char acStack_150 [12];
  char acStack_144 [12];
  char acStack_138 [12];
  char acStack_12c [12];
  char acStack_120 [12];
  char acStack_114 [12];
  char acStack_108 [12];
  char acStack_fc [12];
  char acStack_f0 [12];
  char acStack_e4 [12];
  char acStack_d8 [12];
  char acStack_cc [12];
  char acStack_c0 [12];
  char acStack_b4 [12];
  char acStack_a8 [12];
  char acStack_9c [12];
  char acStack_90 [12];
  char acStack_84 [12];
  char acStack_78 [12];
  char acStack_6c [12];
  char acStack_60 [12];
  char acStack_54 [12];
  char acStack_48 [12];
  char acStack_3c [12];
  char acStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  DataMemoryBarrier(0x1b);
  if (((DAT_014f8f48 & 1) == 0) && (iVar1 = __cxa_guard_acquire(), iVar1 != 0)) {
    operator____b(acStack_1bc,0xa14248);
    operator____b(acStack_1b0,0xa54ba7);
    operator____b(acStack_1a4,0xc04270);
    operator____b(acStack_198,0x7481e6);
    operator____b(acStack_18c,0x806cb9);
    operator____b(acStack_180,0xa007ff);
    operator____b(acStack_174,0x90fa34);
    operator____b(acStack_168,0xbaca73);
    operator____b(acStack_15c,0xbebf1a);
    operator____b(acStack_150,0xacb04c);
    operator____b(acStack_144,0xa86d9a);
    operator____b(acStack_138,0xc042e4);
    operator____b(acStack_12c,0x6d383d);
    operator____b(acStack_120,0xc30b15);
    operator____b(acStack_114,0xa00759);
    operator____b(acStack_108,0xacafd5);
    operator____b(acStack_fc,0xb933c4);
    operator____b(acStack_f0,0xc499ed);
    operator____b(acStack_e4,0xa6d0a1);
    operator____b(acStack_d8,0xb933cb);
    operator____b(acStack_cc,0xacb053);
    operator____b(acStack_c0,0xc49b90);
    operator____b(acStack_b4,0x93f411);
    operator____b(acStack_a8,0x77af88);
    operator____b(acStack_9c,0x6ec8f8);
    operator____b(acStack_90,0x9a485a);
    operator____b(acStack_84,0xbacc8a);
    operator____b(acStack_78,0x7a4e6e);
    operator____b(acStack_6c,0xbcda31);
    operator____b(acStack_60,0x6d2d59);
    operator____b(acStack_54,0x9e646e);
    operator____b(acStack_48,0xbacc91);
    operator____b(acStack_3c,0x93f418);
    operator____b(acStack_30,0x9e6475);
    FUN_00ce2398(&DAT_014f8f88,acStack_1bc,0x22);
    iVar1 = 0x18c;
    do {
      FUN_00cb7f50(acStack_1bc + iVar1);
      iVar1 = iVar1 + -0xc;
    } while (iVar1 != -0xc);
    __cxa_atexit(0xcded69,&DAT_014f8f88,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f8f48);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_24);
  }
  return;
}


