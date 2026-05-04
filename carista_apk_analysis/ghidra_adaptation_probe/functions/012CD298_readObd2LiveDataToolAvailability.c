/* ReadValuesOperation::readObd2LiveDataToolAvailability @ 012cd298 */


/* ReadValuesOperation::readObd2LiveDataToolAvailability(std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > const&,
   std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
ReadValuesOperation::readObd2LiveDataToolAvailability
          (ReadValuesOperation *this,vector *param_1,shared_ptr *param_2)

{
  bool bVar1;
  int *piVar2;
  vector *pvVar3;
  IllegalArgumentException *this_00;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  shared_ptr asStack_3c [12];
  LiveDataTool *local_30;
  int iStack_2c;
  int local_28;
  
  iVar6 = 0;
  local_28 = __stack_chk_guard;
  iVar10 = *(int *)(param_1 + 4);
  for (iVar4 = *(int *)param_1; iVar4 != iVar10; iVar4 = iVar4 + 8) {
    FUN_012cd24c(&local_30,iVar4);
    if (local_30 == (LiveDataTool *)0x0) {
      this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(asStack_3c,"Passed non Obd2LiveDataTool to readObd2LiveDataAvailability method");
      IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)asStack_3c);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    piVar2 = (int *)LiveDataTool::getParams(local_30);
    iVar9 = *piVar2;
    iVar8 = piVar2[1];
    FUN_00ccc708(&local_30);
    iVar6 = iVar6 + (iVar8 - iVar9 >> 3);
  }
  (**(code **)(**(int **)param_2 + 0x24))(asStack_3c,*(int **)param_2,iVar6);
  puVar7 = *(undefined4 **)param_1;
  puVar5 = *(undefined4 **)(param_1 + 4);
  do {
    if (puVar7 == puVar5) break;
    local_30 = (LiveDataTool *)*puVar7;
    iStack_2c = puVar7[1];
    if (iStack_2c != 0) {
      piVar2 = (int *)(iStack_2c + 4);
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = *piVar2 + 1;
    }
    pvVar3 = (vector *)LiveDataTool::getParams(local_30);
    iVar4 = readObd2ParamAvailability(this,pvVar3,asStack_3c);
    FUN_00ccc814(&local_30);
    iVar4 = State::isFatalError(iVar4);
    puVar7 = puVar7 + 2;
  } while (iVar4 == 0);
  FUN_00d2b90c(asStack_3c);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}


