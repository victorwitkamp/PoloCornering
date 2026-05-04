/* ReadValuesOperation::ReadValuesOperation @ 012ccda4 */


/* ReadValuesOperation::ReadValuesOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Operation> const&) */

void __thiscall
ReadValuesOperation::ReadValuesOperation
          (ReadValuesOperation *this,shared_ptr *param_1,shared_ptr *param_2)

{
  int iVar1;
  int unaff_r5;
  
  iVar1 = __stack_chk_guard;
  SimpleOperation::SimpleOperation((SimpleOperation *)this,param_1);
  *(undefined ***)this = &PTR__ReadValuesOperation_014be5d8;
  *(undefined2 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x78) = 0x3f800000;
  *(undefined8 *)(this + 0x7c) = 0;
  *(undefined8 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x8c) = 0x3f800000;
  if (*(int **)param_2 != (int *)0x0) {
    (**(code **)(**(int **)param_2 + 0x14))(&stack0xffffffd4);
    FUN_00d5a8a2(&stack0xffffffd4);
    if (unaff_r5 != 0) {
      (**(code **)(**(int **)param_2 + 0x14))(&stack0xffffffd4);
      Operation::setDelegate((Operation *)this,(shared_ptr *)&stack0xffffffd4);
      FUN_00d5a8a2(&stack0xffffffd4);
    }
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}


