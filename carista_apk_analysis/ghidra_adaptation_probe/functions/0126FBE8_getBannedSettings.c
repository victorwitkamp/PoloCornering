/* VagOperationDelegate::getBannedSettings @ 0126fbe8 */


/* VagOperationDelegate::getBannedSettings() */

undefined * VagOperationDelegate::getBannedSettings(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DataMemoryBarrier(0x1b);
  if (((DAT_014f8f58 & 1) == 0) && (iVar1 = __cxa_guard_acquire(&DAT_014f8f58), iVar1 != 0)) {
    uVar2 = VagCanSettingsBanned::getSettings();
    FUN_00cce028(&DAT_014f8f30,uVar2);
    __cxa_atexit(&LAB_00d80c10_1,&DAT_014f8f30,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f8f58);
  }
  return &DAT_014f8f30;
}


