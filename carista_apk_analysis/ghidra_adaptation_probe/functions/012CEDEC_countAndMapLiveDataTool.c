/* ReadValuesOperation::countAndMapLiveDataTool @ 012cedec */


/* ReadValuesOperation::countAndMapLiveDataTool(std::__ndk1::shared_ptr<LiveDataTool> const&,
   std::__ndk1::unordered_map<Ecu*, std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > >, std::__ndk1::hash<Ecu*>,
   std::__ndk1::equal_to<Ecu*>, std::__ndk1::allocator<std::__ndk1::pair<Ecu* const,
   std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > > > >&, unsigned int&) */

void __thiscall
ReadValuesOperation::countAndMapLiveDataTool
          (ReadValuesOperation *this,shared_ptr *param_1,unordered_map *param_2,uint *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *unaff_r5;
  int *piVar4;
  int *piVar5;
  uint *local_38;
  
  iVar1 = __stack_chk_guard;
  local_38 = param_3;
  puVar2 = (undefined4 *)LiveDataTool::getParams(*(LiveDataTool **)param_1);
  piVar5 = (int *)puVar2[1];
  for (piVar4 = (int *)*puVar2; piVar4 != piVar5; piVar4 = piVar4 + 2) {
    (**(code **)(*(int *)this + 0x14))(&local_38,this);
    (**(code **)(*local_38 + 0x48))(&stack0xffffffd0,local_38,*(undefined4 *)(*piVar4 + 0x10));
    FUN_00d5a8a2(&local_38);
    if ((unaff_r5 == (char *)0x0) || (*unaff_r5 != '\0')) {
      uVar3 = FUN_012cee98(param_2,*piVar4 + 0x10);
      FUN_00d6f39a(uVar3,piVar4);
      *param_3 = *param_3 + 1;
    }
    FUN_00d092c6(&stack0xffffffd0);
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


