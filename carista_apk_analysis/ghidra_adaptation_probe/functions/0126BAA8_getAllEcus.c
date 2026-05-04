/* VagOperationDelegate::getAllEcus @ 0126baa8 */


/* VagOperationDelegate::getAllEcus() */

void __thiscall VagOperationDelegate::getAllEcus(VagOperationDelegate *this)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *puStack_30;
  undefined4 *local_28;
  undefined4 *puStack_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  uVar1 = VagCanEcu::values();
  FUN_0126bb5c(&local_28,uVar1);
  uVar1 = VagUdsEcu::values();
  FUN_0126bb7c(&local_34,uVar1);
  for (; puVar2 = local_34, local_28 != puStack_24; local_28 = local_28 + 1) {
    local_38 = *local_28;
    FUN_00cc8c48(this,&local_38);
  }
  for (; puVar2 != puStack_30; puVar2 = puVar2 + 1) {
    local_38 = *puVar2;
    FUN_00cc8c48(this,&local_38);
  }
  FUN_0118a6cc(&local_34);
  FUN_01058530(&local_28);
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


