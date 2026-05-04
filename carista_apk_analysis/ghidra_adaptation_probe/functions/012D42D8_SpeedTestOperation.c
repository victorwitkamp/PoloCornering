/* SpeedTestOperation::SpeedTestOperation @ 012d42d8 */


/* SpeedTestOperation::SpeedTestOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Obd2GenericTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&) */

void __thiscall
SpeedTestOperation::SpeedTestOperation
          (SpeedTestOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  IllegalArgumentException *pIVar4;
  undefined4 local_28;
  int iStack_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_28 = *(undefined4 *)param_2;
  iStack_24 = *(int *)(param_2 + 4);
  if (iStack_24 != 0) {
    piVar2 = (int *)(iStack_24 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  GenericToolOperation::GenericToolOperation
            ((GenericToolOperation *)this,param_1,(shared_ptr *)&local_28,param_3);
  FUN_00cc67b0(&local_28);
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  this[0x132] = (SpeedTestOperation)0x0;
  *(undefined2 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined ***)this = &PTR__SpeedTestOperation_014beba8;
  piVar2 = *(int **)(*(int *)param_2 + 0x7c);
  if (*(int *)(*(int *)param_2 + 0x80) - (int)piVar2 != 8) {
    pIVar4 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_28,"Tool passed does not have the right number of live datas!");
    IllegalArgumentException::IllegalArgumentException(pIVar4,(basic_string *)&local_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar4,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  iVar3 = strcmp(*(char **)(*piVar2 + 0x28),"car_tool_vehicle_speed");
  if (iVar3 != 0) {
    pIVar4 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_28,"Wrong live data passed to tool!");
    IllegalArgumentException::IllegalArgumentException(pIVar4,(basic_string *)&local_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(pIVar4,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  FUN_00d5b5a0(this + 0x10c,piVar2);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c);
  }
  return;
}


