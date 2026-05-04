/* VagOperationDelegate::resetServiceIndicator @ 012752b4 */


/* VagOperationDelegate::resetServiceIndicator(std::__ndk1::shared_ptr<ServiceIndicator>) */

void VagOperationDelegate::resetServiceIndicator
               (OperationDelegate *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  IllegalArgumentException *this;
  int unaff_r5;
  shared_ptr *psVar3;
  shared_ptr *psVar4;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  iVar1 = __stack_chk_guard;
  uStack_38 = param_3;
  uStack_34 = param_4;
  FUN_0127539c(&stack0xffffffd4);
  if (unaff_r5 == 0) {
    this = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44((Progress *)&uStack_38,"Requested service identifier for reset is unknown!");
    IllegalArgumentException::IllegalArgumentException(this,(basic_string *)&uStack_38);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  psVar3 = *(shared_ptr **)(unaff_r5 + 0x48);
  psVar4 = *(shared_ptr **)(unaff_r5 + 0x4c);
  do {
    if (psVar3 == psVar4) break;
    Progress::NUL((Progress *)&uStack_38);
    iVar2 = OperationDelegate::changeSetting
                      (param_1,psVar3,(vector *)GENERAL_SERVICE_RESET_VALUE,(shared_ptr *)&uStack_38
                      );
    FUN_011e01a0((Progress *)&uStack_38);
    iVar2 = State::isError(iVar2);
    psVar3 = psVar3 + 8;
  } while (iVar2 == 0);
  FUN_01274bf8(&stack0xffffffd4);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}


