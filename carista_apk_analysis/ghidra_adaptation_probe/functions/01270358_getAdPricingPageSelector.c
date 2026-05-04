/* VagOperationDelegate::getAdPricingPageSelector @ 01270358 */


/* VagOperationDelegate::getAdPricingPageSelector(std::__ndk1::shared_ptr<Setting> const&) */

void __thiscall
VagOperationDelegate::getAdPricingPageSelector(VagOperationDelegate *this,shared_ptr *param_1)

{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  Result<bool,void> aRStack_38 [28];
  undefined4 *local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0xd0))(aRStack_38);
  iVar1 = Result<bool,void>::isFail(aRStack_38);
  if ((iVar1 == 0) && (*(char *)*local_1c != '\0')) {
    local_3c = 0;
    local_40 = 8;
    FUN_00d2a938(this,&local_40);
  }
  else {
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
  }
  Result<bool,void>::~Result(aRStack_38);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


