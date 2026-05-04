/* VagUdsMirrorLinkVimCoding::getSetting @ 011d6e18 */


/* VagUdsMirrorLinkVimCoding::getSetting() */

void __thiscall VagUdsMirrorLinkVimCoding::getSetting(VagUdsMirrorLinkVimCoding *this)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  DataMemoryBarrier(0x1b);
  if (((DAT_014f866c & 1) == 0) && (iVar3 = __cxa_guard_acquire(), iVar3 != 0)) {
    local_20 = 0x12;
    local_30 = 0xff;
    local_2c = 0;
    local_34 = 1;
    local_3c = 1;
    uStack_38 = 0;
    FUN_00cf5938(auStack_28,&local_2c,&local_30,&local_34,&Unit::NONE,&uStack_38,&local_3c);
    FUN_011d6f20(&DAT_014f8670,&VagWhitelists::INFOTAINMENT_MK7_B9,&local_20,"vim_over_mirrorlink",
                 auStack_28);
    FUN_00cba5b0(auStack_28);
    __cxa_atexit(0x11d6f61,&DAT_014f8670,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f866c);
  }
  iVar3 = DAT_014f8674;
  *(undefined4 *)this = DAT_014f8670;
  *(int *)(this + 4) = iVar3;
  if (iVar3 != 0) {
    piVar2 = (int *)(iVar3 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


