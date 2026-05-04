/* VagOperationDelegate::getSettingRawAddress @ 012720ec */


/* VagOperationDelegate::getSettingRawAddress(std::__ndk1::shared_ptr<Setting> const&) */

void __thiscall
VagOperationDelegate::getSettingRawAddress(VagOperationDelegate *this,shared_ptr *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  OperationDelegate::getSettingRawAddress((OperationDelegate *)this,param_1);
  iVar3 = *(int *)param_1;
  cVar1 = *(char *)(iVar3 + 0xc);
  if (cVar1 == '\t' || cVar1 == '\x05') {
    local_20 = *(int *)(param_1 + 4);
    if (local_20 != 0) {
      piVar4 = (int *)(local_20 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar2 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar2);
      *piVar4 = *piVar4 + 1;
    }
    local_24 = iVar3;
    (**(code **)(*(int *)this + 0x1f0))(this,&local_24);
    FUN_00d1756c(&local_24);
  }
  else if (cVar1 == '\x04') {
    local_20 = *(int *)(param_1 + 4);
    if (local_20 != 0) {
      piVar4 = (int *)(local_20 + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar2 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar2);
      *piVar4 = *piVar4 + 1;
    }
    local_24 = iVar3;
    (**(code **)(*(int *)this + 0x1ec))(this,&local_24);
    FUN_010bc068(&local_24);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c,__stack_chk_guard);
  }
  return;
}


