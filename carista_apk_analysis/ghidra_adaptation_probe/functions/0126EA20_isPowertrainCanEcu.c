/* VagOperationDelegate::isPowertrainCanEcu @ 0126ea20 */


/* VagOperationDelegate::isPowertrainCanEcu(Ecu*) */

void __thiscall VagOperationDelegate::isPowertrainCanEcu(VagOperationDelegate *this,Ecu *param_1)

{
  Progress aPStack_54 [8];
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  shared_ptr asStack_3c [36];
  int local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  if ((param_1 != (Ecu *)0x0) &&
     (local_18 = __dynamic_cast(param_1,&Ecu::typeinfo,&VagCanEcu::typeinfo,0), local_18 != 0)) {
    FUN_0127a1f4(&local_4c,&local_18);
    local_44 = local_4c;
    uStack_40 = uStack_48;
    local_4c = 0;
    uStack_48 = 0;
    Progress::NUL(aPStack_54);
    OperationDelegate::runCommand<BoolModel>(asStack_3c,(shared_ptr *)this);
    FUN_011e01a0(aPStack_54);
    FUN_0122c6c2(&local_44);
    FUN_0127a228(&local_4c);
    Result<BoolModel,void>::~Result((Result<BoolModel,void> *)asStack_3c);
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  return;
}


