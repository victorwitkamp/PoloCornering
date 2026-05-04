/* VagOperationDelegate::isSfd2Protected @ 0126b300 */


/* VagOperationDelegate::isSfd2Protected(std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::isSfd2Protected(VagOperationDelegate *this,shared_ptr *param_1)

{
  int iVar1;
  uint local_50;
  undefined4 uStack_4c;
  uint local_48;
  undefined4 local_44;
  shared_ptr asStack_40 [24];
  int *local_28;
  int *local_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  FUN_0126ff78(&local_50);
  local_48 = local_50;
  local_44 = uStack_4c;
  local_50 = 0;
  uStack_4c = 0;
  OperationDelegate::runCommand<DiagFilterModel>(asStack_40,param_1);
  FUN_0126ffa8(&local_48);
  FUN_0126ffba(&local_50);
  if ((*local_28 == -0x20) || (*local_28 == -0x28)) {
    local_48 = local_48 & 0xffffff00;
    Result<bool,void>::done<bool>((type *)this);
  }
  else {
    iVar1 = Result<DiagFilterModel,void>::isFail((Result<DiagFilterModel,void> *)asStack_40);
    if (iVar1 == 0) {
      if (*(int *)(*local_24 + 4) == 4) {
        param_1[0x141] = (shared_ptr)0x3;
        local_48 = CONCAT31(local_48._1_3_,1);
        Result<bool,void>::done<bool>((type *)this);
      }
      else {
        local_48 = (uint)local_48._1_3_ << 8;
        Result<bool,void>::done<bool>((type *)this);
      }
    }
    else {
      Result<DiagFilterModel,void>::stateAs<bool,void>();
    }
  }
  Result<DiagFilterModel,void>::~Result((Result<DiagFilterModel,void> *)asStack_40);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


