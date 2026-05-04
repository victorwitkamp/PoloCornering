/* VagOperationDelegate::getVagCanSubmoduleId @ 01274030 */


/* VagOperationDelegate::getVagCanSubmoduleId(std::__ndk1::shared_ptr<VagCanSubmoduleCodingSetting>
   const&) */

void __thiscall
VagOperationDelegate::getVagCanSubmoduleId(VagOperationDelegate *this,shared_ptr *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  IllegalStateException *pIVar6;
  uint uVar7;
  undefined1 auStack_54 [12];
  undefined4 local_48;
  uint uStack_44;
  int local_40;
  int *local_2c;
  int *local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar2 = (**(code **)(**(int **)param_1 + 0x14))();
  (**(code **)(*(int *)this + 0x1f8))(&local_48,this,uVar2);
  local_24 = *(int **)(*local_2c + 0x10);
  iStack_20 = *(int *)(*local_2c + 0x14);
  if (iStack_20 != 0) {
    piVar3 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_48);
  if (local_24 == (int *)0x0) {
    (**(code **)(**(int **)param_1 + 0x18))(&local_48);
    if ((local_48 & 1) == 0) {
      local_40 = (int)&local_48 + 1;
    }
    Log::e("CAN submodules are null for setting: %s",local_40);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  &local_48);
    pIVar6 = (IllegalStateException *)__cxa_allocate_exception(8);
    (**(code **)(**(int **)param_1 + 0x18))(auStack_54);
    FUN_00cbe7e4(&local_48,"CAN submodules are null for setting ",auStack_54);
    IllegalStateException::IllegalStateException(pIVar6,(basic_string *)&local_48);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar6,&IllegalStateException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  uVar7 = 0;
  do {
    if ((uint)(local_24[1] - *local_24 >> 3) <= uVar7) {
      pIVar6 = (IllegalStateException *)__cxa_allocate_exception(8);
      (**(code **)(**(int **)param_1 + 0x18))(auStack_54);
      FUN_00cbe7e4(&local_48,"CAN submodule ID not found for setting ",auStack_54);
      IllegalStateException::IllegalStateException(pIVar6,(basic_string *)&local_48);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(pIVar6,&IllegalStateException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    puVar4 = (uint *)FUN_0111cba4(local_24,uVar7);
    local_48 = *puVar4;
    uStack_44 = puVar4[1];
    if (uStack_44 != 0) {
      piVar3 = (int *)(uStack_44 + 4);
      do {
        ExclusiveAccess(piVar3);
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = *piVar3 + 1;
    }
    iVar5 = (**(code **)(**(int **)(*(int *)param_1 + 0x54) + 0x10))
                      (*(int **)(*(int *)param_1 + 0x54),*(undefined4 *)(local_48 + 8));
    FUN_00d08540(&local_48);
    uVar7 = uVar7 + 1;
  } while (iVar5 == 0);
  FUN_00d08642(&local_24);
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_1c);
}


