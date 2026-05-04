/* VagOperationDelegate::getSettingAvailabilityForEcu @ 0126fc58 */


/* VagOperationDelegate::getSettingAvailabilityForEcu(std::__ndk1::shared_ptr<Setting> const&,
   std::__ndk1::shared_ptr<std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>,
   std::__ndk1::allocator<char> > const> const&) */

void __thiscall
VagOperationDelegate::getSettingAvailabilityForEcu
          (VagOperationDelegate *this,shared_ptr *param_1,shared_ptr *param_2)

{
  bool bVar1;
  int iVar2;
  shared_ptr *psVar3;
  code *pcVar4;
  int iVar5;
  shared_ptr *local_1c;
  shared_ptr *psStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar2 = *(int *)param_2;
  local_1c = param_1;
  psStack_18 = param_2;
  if (iVar2 != 0) {
    local_1c = *(shared_ptr **)param_1;
    psStack_18 = *(shared_ptr **)(param_1 + 4);
    iVar5 = 0;
    if (psStack_18 != (shared_ptr *)0x0) {
      psVar3 = psStack_18 + 4;
      do {
        ExclusiveAccess(psVar3);
        iVar5 = *(int *)psVar3 + 1;
        bVar1 = (bool)hasExclusiveAccess(psVar3);
      } while (!bVar1);
      *(int *)psVar3 = iVar5;
      iVar2 = *(int *)param_2;
    }
    pcVar4 = *(code **)(**(int **)(local_1c + 0x54) + 0x10);
    (*pcVar4)(*(int **)(local_1c + 0x54),iVar2,pcVar4,iVar5,this);
    FUN_00d1756c(&local_1c);
  }
  if (__stack_chk_guard == local_14) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_14);
}


