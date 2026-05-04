/* VagUdsMib2VimOperation::VagUdsMib2VimOperation @ 012deb70 */


/* VagUdsMib2VimOperation::VagUdsMib2VimOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<VagBasicSettingTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&, std::__ndk1::shared_ptr<VagUdsVimCoding> const&, LibStr const&) */

void __thiscall
VagUdsMib2VimOperation::VagUdsMib2VimOperation
          (VagUdsMib2VimOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3,
          shared_ptr *param_4,LibStr *param_5)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  puVar2 = (undefined4 *)
           VagUdsVimOperation::VagUdsVimOperation
                     ((VagUdsVimOperation *)this,param_1,param_2,param_3,param_5);
  puVar2[0x4b] = puVar2 + 0x4c;
  puVar2[0x4c] = 0;
  puVar2[0x4d] = 0;
  *puVar2 = &PTR__VagUdsMib2VimOperation_014bfa0c;
  iVar3 = *(int *)(param_4 + 4);
  puVar2[0x4e] = *(undefined4 *)param_4;
  puVar2[0x4f] = iVar3;
  if (iVar3 != 0) {
    piVar4 = (int *)(iVar3 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  return;
}


