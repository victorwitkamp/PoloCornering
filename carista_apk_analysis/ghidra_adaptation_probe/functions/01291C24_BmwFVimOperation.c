/* BmwFVimOperation::BmwFVimOperation @ 01291c24 */


/* BmwFVimOperation::BmwFVimOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<BmwFGenericTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

undefined8 __thiscall
BmwFVimOperation::BmwFVimOperation
          (BmwFVimOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  IllegalArgumentException *pIVar3;
  BmwFVimOperation *pBVar4;
  undefined4 uStack_58;
  char acStack_54 [12];
  undefined4 uStack_48;
  undefined4 uStack_44;
  RangeWhitelist aRStack_40 [8];
  undefined1 auStack_38 [8];
  undefined4 local_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  
  local_24 = __stack_chk_guard;
  local_30 = *(undefined4 *)param_2;
  iStack_2c = *(int *)(param_2 + 4);
  if (iStack_2c != 0) {
    piVar2 = (int *)(iStack_2c + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  VimOperation::VimOperation
            ((VimOperation *)this,param_1,(shared_ptr *)&local_30,param_3,
             (LibStr *)&LibStr::enable_vim_disclaimer_msg);
  FUN_00cc67b0(&local_30);
  pBVar4 = this + 300;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined8 *)pBVar4 = 0;
  *(undefined8 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined ***)this = &PTR__BmwFVimOperation_014bbb5c;
  if (*(int *)(*(int *)param_2 + 0x90) - *(int *)(*(int *)param_2 + 0x8c) != 0x10) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_30,"BmwFVimOperation created with wrong number of settings");
    IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&local_30);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  FUN_00d5b5a0(pBVar4);
  FUN_00d5b5a0(this + 0x134,*(int *)(*(int *)param_2 + 0x8c) + 8);
  if (*(short *)(*(int *)pBVar4 + 0x14) != *(short *)(*(int *)(this + 0x134) + 0x14)) {
    pIVar3 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_30,"Settings should have the same dataId");
    IllegalArgumentException::IllegalArgumentException(pIVar3,(basic_string *)&local_30);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar3,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  uStack_28 = 0;
  local_30 = 0;
  iStack_2c = 0;
  RangeWhitelist::from(aRStack_40,(vector *)&local_30,0,0);
  uStack_48 = 0;
  uStack_44 = 0x3000;
  operator____b(acStack_54,0xa6d24d);
  uStack_58 = 0;
  FUN_01291e44(auStack_38,&BmwCanEcu::INFOTAINMENT,aRStack_40,&uStack_44,&uStack_48,acStack_54,
               "car_tool_video_in_motion",&uStack_58);
  _ZNSt6__ndk110shared_ptrI7SettingEaSB8ne190000I11BmwFSettingTnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERS2_ONS0_IS6_EE
            (this + 0x13c,auStack_38);
  FUN_00dfebbc(auStack_38);
  FUN_00cb7f50(acStack_54);
  FUN_00cecb20(aRStack_40);
  FUN_00d183d8(&local_30);
  return CONCAT44(__stack_chk_guard,this);
}


